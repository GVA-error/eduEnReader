#include "bindmaker.h"

BindMaker::BindMaker(TextStore::PTR textStore, SoundStore::PTR soundStore, Logic::PTR logic)
{
    /*char* ostype = getenv("OSTYPE");
    if (ostype == "linux")
        _asr = new ASRLinuxKaldi();
    else
    {
        qCritical() << "Your OS is not support";
        exit(1);
    }*/
     _asr = new ASRLinuxKaldi();
    _textStore = textStore;
    _soundStore = soundStore;
    _logic = logic;
    _splitSize = -1;

    //connect(_asr, SIGNAL(recognizeFinished(QString)), this, SLOT(someRecognized(QString)));
}

void BindMaker::clear()
{
    _preparator.clearDefaultSplitDir();
    //_asr->; там мало инфы но возможно тоже стоит чистить
    _fileBeginOffset.clear();
    _fileEndOffset.clear();
    _recognizedStrings.clear();
    _processList.clear();
    _fileParts.clear();
    _localMin.clear();
    _textLength.clear();
    _textList.clear();
    _textPos.clear();
}

void BindMaker::preparetion()
{
    auto recognizedStrings = _logic->getRecognizedStrings();
    if (recognizedStrings.empty())
        preparetion(_splitSize, _diff);
    else
        preparetion(recognizedStrings);
}

void BindMaker::preparetion(const QStringList& recognizedStrings)
{
    clear();
    _logic->clear(false);
    qreal curStringNumber = 0;
    QList <QStringList> fileStrings;

    for (auto string : recognizedStrings)
    {
        QStringList splitedString = string.split(" ");
        fileStrings.push_back(splitedString);
    }

    for (auto recognizedString : fileStrings) // Всё нормально, нам важен только порядок
    {
        QString ID = QString().number(curStringNumber);
        _fileParts.push_back(ID);
        qreal begin = _logic->getRecognizedStringBegin(curStringNumber);
        qreal end = _logic->getRecognizedStringEnd(curStringNumber);
        _fileBeginOffset[ID] = begin;
        _fileEndOffset[ID] = end;
        curStringNumber++;
        _recognizedStrings[ID] = recognizedString;
    }

    for (auto name : _fileParts)
        _processList[name] = false;

    QString text = _textStore->getString();
    fillInTextData(text);
}

void BindMaker::preparetion(qreal splitSize, qreal diff)
{
    clear();
    _logic->clear(true);
    assert(splitSize - diff > 0);
    QUrl url = _soundStore->fileUrl();
    QString videoFile = url.toLocalFile();
    QString wavFile = _preparator.prepeareWav(videoFile);
    if (diff == 0.0f)
        _preparator.splitFile(wavFile, splitSize);
    else
    {
        qreal max = splitSize + diff;
        qreal min = splitSize - diff;
        _preparator.splitFile(wavFile, min, max);
    }
    _fileParts = _preparator.getFileNameList();


    for (auto file : _fileParts)
        _asr->recognize(file);

    // TODO Стоит возвращать мап сразу
    for (auto name = _fileParts.begin(); name != _fileParts.end(); name++)
    {
        _fileBeginOffset[*name] = _preparator.getFileBegin(*name);
        _fileEndOffset[*name] = _preparator.getFileEnd(*name);
        _recognizedStrings[*name] = _asr->getRecognized(*name);
    }

    for (auto name : _fileParts)
        _processList[name] = false;

    QString text = _textStore->getString();
    fillInTextData(text);
}

void BindMaker::fillInTextData(const QString& text)
{
    int curWordLength = 0;
    int beginPos = 0;
    for (qint64 i = 0; i<text.length(); i++)
    {
        char curSimbol = text.at(i).toLatin1();
        if (isalpha(curSimbol) || curSimbol == '\'') // Апострофы считаем частью слова
        {
            if (curWordLength == 0)
                beginPos = i;
            curWordLength++;
        }
        else if (curWordLength != 0)
        {
            QString nextWord = text.mid(beginPos, curWordLength);
            nextWord = nextWord.toLower();
            deleteNotAlpha(nextWord);
            //qint64 curNumber = _textList.size();
            _textList.push_back(nextWord);
            _textPos.push_back(beginPos);
            //_posInText[curNumber] = i;
            curWordLength = 0;
        }
    }
}

void BindMaker::run()
{
    preparetion();
    if (_processList.empty())
    {
        qDebug() << "U not have prepeared data" << "\n";
        return;
    }

    if (_textList.empty())
        return;
    qDebug() << "******* Recognizing *******";
    // Тут можно парралелить
    for (auto nextPart : _fileParts)
    {
        QStringList recognizedString;
        qDebug() << "\nHandle file: " << nextPart;
        recognizedString = _recognizedStrings[nextPart];
        handleRecognized(nextPart, recognizedString);
    }
    useLocalMinToFind_bind();
}

void BindMaker::handleRecognized(const QString& fileName, const QStringList& recognizedString)
{
    _processList[fileName] = true;
    qreal progress = calcProgress();
    emit SIGNAL(process(progress));

    calcLocalMin(fileName);

    if (recognizeIsFinished())
        emit SIGNAL(bindingIsFinished(_bind));
}

void BindMaker::useLocalMinToFind_bind()
{
    qDebug() << "******* Binding *******";
    _logic->clear(true);
    qint64 curLastTextPos = -1;
    for (auto partFileName : _fileParts)
    {
        qreal beginSound = _fileBeginOffset[partFileName];
        qreal endSound = _fileEndOffset[partFileName];
        auto soundFragment = SoundFragment::factoryMethod(beginSound, endSound, _soundStore);
        qint64 beginText = curLastTextPos;
        qint64 endText = beginText;
        for (auto localMim : _localMin[partFileName])
        {
            if (localMim <= curLastTextPos)
                continue;
            beginText = localMim;
            qint64 lengthText = _textLength[partFileName];
            endText = beginText + lengthText;
            auto textFragment = TextFragment::factoryMethod(beginText, endText, _textStore);
            QStringList recognized = _recognizedStrings[partFileName];
            QString recognizedString = recognized.join(" "); // TODO проверить делелние
            _logic->makeBind(textFragment, soundFragment, recognizedString);
            break;
        }
        curLastTextPos = beginText;
    }
    addEdgeBinds();
}

void BindMaker::addEdgeBinds()
{
    qint64 n = _logic->getBindNumber();

    TextFragment::PTR firstText = _logic->getText(0);
    TextFragment::PTR lastText = _logic->getText(n-1);
    SoundFragment::PTR firstSound = _logic->getSound(0);
    SoundFragment::PTR lastSound = _logic->getSound(n-1);

    qint64 textLength = _textStore->length();
    qreal soundDuration = _soundStore->fullDuration();

    qreal beginSound = firstSound->begin();
    qreal beginText = firstText->begin();
    qreal endSound = lastSound->end();
    qreal endText = lastText->end();

    auto preText = TextFragment::factoryMethod(0, beginText, _textStore);
    auto preSound = SoundFragment::factoryMethod(0, beginSound, _soundStore);
    auto postText = TextFragment::factoryMethod(endText, textLength, _textStore);
    auto postSound = SoundFragment::factoryMethod(endSound, soundDuration, _soundStore);

    _logic->makeBind(preText, preSound, "", 0);
    _logic->makeBind(postText, postSound, "", n-1);
}

QList <qint64> BindMaker::getCorelationFunc(const QStringList &recognizedString) const
{
    assert(_textList.size() > recognizedString.size());
    QList <qint64> korelationFunc;
    if (recognizedString.size() == 0)
        return korelationFunc;
    QStringList curPartSourceText;
    auto curWord = _textList.begin();
    // Чтобы решить проблему конечности в начале добавляем бесмысленный текст
    for (qint64 i = 0; i<recognizedString.size() - 1; i++)
        curPartSourceText.push_back("-its_mean_nothing-");
    curPartSourceText.push_back(*curWord);
    curWord++;

    auto folowedByLastWord = curWord;
    // считаем значения функции кореляции
    korelationFunc.reserve(_textList.size());
    korelationFunc.push_back(recognizedString.size() + 1);
    for (qint64 i = -curPartSourceText.size()+1;; i++)
    {
        qint64 k = Metrics::getLevenshteinDistance(recognizedString, curPartSourceText);
        if (i <= 0)
            *(korelationFunc.begin()) = qMin(korelationFunc.front(), k);
        else
            korelationFunc.push_back(k);
        if (folowedByLastWord == _textList.end())
            break;
        // Сдвигаем кореляционное окно
        QString nextWord = *folowedByLastWord;
        curPartSourceText.push_back(nextWord);
        folowedByLastWord++;
        curPartSourceText.pop_front();
    }
    return korelationFunc;
}

void BindMaker::calcLocalMin(const QString &partFileName, qreal maxWrongPersent)
{
    assert(maxWrongPersent >= 0 && maxWrongPersent < 1.0f); // Иначе не имеет смысла
    auto recognizedString = _recognizedStrings[partFileName];
    QList <qint64> korelationFunc = getCorelationFunc(recognizedString);
    qint64 realMaxWrongValue = recognizedString.size();
    qint64 maxWrongValue = realMaxWrongValue * maxWrongPersent;
    // Вычисляем инфинум
    auto lastEl = korelationFunc.begin();
    auto curEl = korelationFunc.begin();
    auto nextEl = curEl + 1;
    assert(nextEl != korelationFunc.end());
    auto curTextPos = _textPos.begin();
    for (qint64 i=0; i<korelationFunc.size(); i++)
    {
        qint64 lastValue;
        qint64 nextValue;
        qint64 curValue = *curEl;
        lastValue = *lastEl;
        if (nextEl != korelationFunc.end())
            nextValue = *nextEl;
        else
            nextValue = korelationFunc.back();
        if (lastValue > maxWrongValue)
            lastValue = maxWrongValue;
        if (nextValue > maxWrongValue)
            nextValue = maxWrongValue;

        // Условие локального минимума
        if ((lastValue > curValue && nextValue >= curValue)
         || (lastValue >= curValue && nextValue > curValue))
        {
            qint64 realTextPos = *curTextPos;
            _localMin[partFileName].push_back(realTextPos);
        }

        lastEl = curEl;
        curEl++;
        nextEl++;
        curTextPos++;
    }
    // Для большей эфективности стоит использовать getRecognizedStringEnd
    QString joinedRecognizedString = recognizedString.join(" ");
    _textLength[partFileName] = joinedRecognizedString.size();

    if (_localMin[partFileName].size() > 1)
    {
        qint32 firstPos = _localMin[partFileName].front();
        qint32 lastPos = _localMin[partFileName].back();
        qDebug() << "\nFind two local minimum for file: " << partFileName << " \n    on word positions:";
        for (auto pos : _localMin[partFileName])
            qDebug() << " " << pos;
        qint32 diff = lastPos - firstPos;
        qDebug() << "\n    Max difference: "  << diff;
        if (diff > recognizedString.size())
            qDebug() << "\n    WARNING!!! It have two infinum"
            << "\nFirts local minimum have " << firstPos << "/" << realMaxWrongValue
            << "\nLast local minimum have " << lastPos << "/" << realMaxWrongValue;
    } else if (_localMin[partFileName].size() == 0)
        qDebug() << "Don\'t find korelation for file: " << partFileName
                 << "\n Recognized string is :\"" << recognizedString << "\"";
    else if (recognizedString.length() > 0)
        qDebug() << "Ok. " << partFileName << " recognized";
    else
        qDebug() << "Something wrong.";
    return;
}



qreal BindMaker::calcProgress() const
{
    qreal progress = 1.0f;
    qint64 successPart = 0;
    qint64 full = _processList.size();
    for (auto isRecognized : _processList.values())
        if (isRecognized == true)
            successPart++;
    progress = (qreal)successPart/(qreal)full;
    return progress;
}

bool BindMaker::recognizeIsFinished()
{
    for (auto isRecognized : _processList.values())
        if (isRecognized == false)
            return false;
    return true;
}

qint64 BindMaker::getDistance(const QStringList& firstSeqence, const QStringList& secondSeqence) const
{
    return Metrics::getLevenshteinDistance(firstSeqence, secondSeqence);
}

void BindMaker::deleteNotAlpha(QString& str)
{
    for (int i=0; i<str.length();)
    {
        char curSimbol = str[i].toLatin1();
        if (!isalpha(curSimbol) )
            str.remove(i, 1);
        else
            i++;
    }
}

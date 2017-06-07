#include "bindmaker.h"

BindMaker::BindMaker(TextStore::PTR textStore, SoundStore::PTR soundStore, Logic::PTR logic)
{
     _asr = new ASRScripter();
    _textStore = textStore;
    _soundStore = soundStore;
    _logic = logic;
    _splitSize = -1;
    _curState = _baseState.arg(0, 0, 0);
    clear();
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
    qDebug() << "******* Preparetion *******";
    _curState = _baseState.arg(0).arg(0).arg(0);
    emit process();
    clear();
    _curState = _baseState.arg(10).arg(0).arg(0);
    emit process();
    if (_logic->haveRecognizedString())
    {
        _logic->clear(false);
        soundPreparetion();
    }
    else
    {
        _logic->clear(true); // Если занимались деление файла - старые распознаные данные считаем устаревшими
        soundPreparetion(_splitSize, _diff);
    }

    _curState = _baseState.arg(70).arg(0).arg(0);
    emit process();
    sortFileParts();

    for (auto name : _fileParts)
        _processList[name] = false;

    QString text = _textStore->getString();
    textPreparetion(text);
    _curState = _baseState.arg(100).arg(0).arg(0);
    emit process();
}

void BindMaker::soundPreparetion()
{
    _recognizedStrings = _logic->getRecognizedStrings();

    _fileBeginOffset = _logic->getRecognizedStringBeginList();
    _fileEndOffset = _logic->getRecognizedStringEndList();
    _fileParts = _recognizedStrings.keys();
}

void BindMaker::sortFileParts()
{
    QMap <qreal, QString> mids;
    QList <qreal> midKeys;
    for (auto str : _fileParts)
    {
        qreal begin = _fileBeginOffset[str];
        qreal end = _fileBeginOffset[str];
        qreal mid = (begin + end) / 2;
        mids[mid] = str;
        midKeys.push_back(mid);
    }
    qSort(midKeys);
    _fileParts.clear();
    for (auto midKey : midKeys)
    {
        QString nextString = mids[midKey];
        _fileParts.push_back(nextString);
    }
}

void BindMaker::soundPreparetion(qreal splitSize, qreal diff)
{
    assert(splitSize - diff > 0);
    QUrl url = _soundStore->fileUrl();
    QString videoFile = url.toLocalFile();
    QString wavFile = _preparator.prepeareWav(videoFile);
    _curState = _baseState.arg(40).arg(0).arg(0);
    emit process();
    if (diff == 0.0f)
        _preparator.splitFile(wavFile, splitSize);
    else
    {
        qreal max = splitSize + diff;
        qreal min = splitSize - diff;
        _preparator.splitFile(wavFile, min, max);
    }
    _fileParts = _preparator.getFileNameList();
    _fileBeginOffset = _preparator.getFileBeginList();
    _fileEndOffset = _preparator.getFileEndList();
}

void BindMaker::textPreparetion(const QString& text)
{
    int curWordLength = 0;
    int beginPos = 0;
    for (qint64 i = 0; i<text.length(); i++)
    {
        char curSimbol = text.at(i).toLatin1(); // TODO использовать регулярку
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
            _textList.push_back(nextWord);
            _textPos.push_back(beginPos);
            curWordLength = 0;
        }
    }
}

void BindMaker::recognizing()
{
    if (_recognizedStrings.empty())
    {
        qDebug() << "******* Recognizing *******";
        qint32 handled = 0;
        for (auto file : _fileParts)
        {
            _asr->recognize(file);
            QStringList recognized = _asr->getRecognized(file);
            _recognizedStrings[file] = recognized;
            qreal begin = _fileBeginOffset[file];
            qreal end = _fileEndOffset[file];
            _logic->addRecognizedString(recognized, begin, end, file);
            handled++;
            qreal processPersent = 100 * (qreal)handled/_fileParts.size();
            _curState = _baseState.arg(100).arg(processPersent).arg(0);
            emit process();
        }
    }
}

void BindMaker::binding()
{
    qDebug() << "******* Calculate local mins *******";
    qint32 handled = 0;
    for (auto nextPart : _fileParts)
    {
        qDebug() << "\nHandle file: " << nextPart;
        _processList[nextPart] = true;
        emit SIGNAL(process(progress));
        calcLocalMin(nextPart);
        handled++;
        qreal processPersent = 50*(qreal)handled/_fileParts.size();
        _curState = _baseState.arg(100).arg(100).arg(processPersent);
        emit process();
    }
    qDebug() << "******* Binding *******";
    useLocalMinToFind_bind();
    _curState = _baseState.arg(100).arg(100).arg(100);
    emit process();
    qDebug() << "******* Complete *******";
}

void BindMaker::run()
{
    preparetion();
    if (recognizeIsFinished())
    {
        qDebug() << "U have not prepeared sound data" << "\n";
        return;
    }
    recognizing();
    if (_textList.empty())
    {
        qDebug() << "U have not text data" << "\n";
        return;
    }
    binding();
}

void BindMaker::fillInGraph(Graph &g)
{
    qint32 curID = 0;
    for (auto curFile = _fileParts.begin(); curFile != _fileParts.end(); curFile++)
        for (auto localMin : _localMin[*curFile])
        {
            _localMinToID[*curFile][localMin] = curID;
            _IDToFileName[curID] = *curFile;
            _IDToLoacalMin[curID] = localMin;
            curID++;
        }

    for (auto curFile = _fileParts.begin(); curFile+1 != _fileParts.end(); curFile++)
        for (qint32 i = 1; curFile+i !=_fileParts.end(); i++)
           // for (auto localMin : _localMin[*curFile])
            {
                if (_localMin[*curFile].empty())
                    continue;
                auto localMin = _localMin[*curFile].front();
                auto nextFile = curFile + i;
                qint32 beginID = _localMinToID[*curFile][localMin];
                qint32 endID = getLocalMinEnd(*curFile, localMin, *nextFile);
                assert(beginID < curID && endID < curID);
                assert(*curFile != *nextFile);
                assert(beginID != endID);
                if (endID != -1 && beginID != -1)
                    g.addEdge(beginID, endID);
            }
}

// Локальный минимум конца, если данный локальный минимум соответствует реальной позиции в тексте
qint64 BindMaker::getLocalMinEnd(const QString& fileName, qint32 localMinBegin, const QString& nextFileName) const
{
    QStringList recognizedStringWordList = _recognizedStrings.value(fileName);
    QString recognizedString = recognizedStringWordList.join(" ");
    qint64 recSize = recognizedString.size();
    qint64 minOffset = recSize * 2 / 3;

    qint64 rezLocalMin=-1;
    for (auto localMin : _localMin.value(nextFileName))
        if (localMin > localMinBegin + minOffset)
        {
            rezLocalMin = localMin;
            break;
        }

    if (rezLocalMin == -1)
        return -1;
    qint32 rezID = _localMinToID.value(nextFileName).value(rezLocalMin);
    return rezID;
}

void BindMaker::addBinsFromList(const QList<qint32> &localMinsIDlist) const
{
    for (auto curID = localMinsIDlist.begin(); curID+1 != localMinsIDlist.end(); curID++)
    {
        QString fileStringBegin = _IDToFileName[*curID];
        QString fileStringEnd = _IDToFileName[*(curID+1)];
        qreal beginSound = _fileBeginOffset[fileStringBegin];
        qreal endSound = _fileBeginOffset[fileStringEnd]; // Начало следующего считаем концом предыдущего
        auto soundFragment = SoundFragment::factoryMethod(beginSound, endSound, _soundStore);

        qint64 beginText = _IDToLoacalMin[*curID];
        qint64 endText = _IDToLoacalMin[*(curID+1)];
        auto textFragment = TextFragment::factoryMethod(beginText, endText, _textStore);

        _logic->makeBind(textFragment, soundFragment);
    }
}

qint32 BindMaker::getLocalMinNumber() const
{
    qint32 rezNumber = 0;
    for (QString file : _fileParts)
        rezNumber += _localMin[file].size();
    return rezNumber;
}

void BindMaker::processLongestPath(qreal curPersent)
{
    _curState = _baseState.arg(100).arg(100).arg(50 + curPersent * 50);
    emit process();
}

void BindMaker::useLocalMinToFind_bind()
{
    qint32 localMinNumber = getLocalMinNumber();
    Graph g(localMinNumber+1);
    connect(&g, SIGNAL(process(qreal)), this, SLOT(processLongestPath(qreal)));
    fillInGraph(g);
    QList <qint32> fatherList; // Какие вершины могут быть первыми
    for (auto file : _fileParts)
    {
        if (_localMin[file].empty())
            continue;
        qint64 firstLocalMin = _localMin[file].front();
        qint32 firstLocalMinId = _localMinToID[file][firstLocalMin];
        fatherList.push_back(firstLocalMinId);
    }

    auto IDPath = g.longestPath(fatherList);
    addBinsFromList(IDPath);

    //_logic->clear(false);
   /* qint64 curLastTextPos = -1;
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
            endText = beginText + lengthText * 2 / 3; // TODO деление пополам проверить
            auto textFragment = TextFragment::factoryMethod(beginText, endText, _textStore);
            _logic->makeBind(textFragment, soundFragment);
            break;
        }
        curLastTextPos = beginText;
    }*/
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

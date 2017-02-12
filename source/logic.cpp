#include "logic.h"
#include "ASR/bindmaker.h"

Logic::Logic()
{
    zeroBind.sound = SoundFragment::factoryMethod(-1.0f, -1.0f, SoundStore::PTR());
    zeroBind.text = TextFragment::factoryMethod(-1, -1, TextStore::PTR());
    tempBind.sound = SoundFragment::factoryMethod(-1.0f, -1.0f, SoundStore::PTR());
    tempBind.text = TextFragment::factoryMethod(-1, -1, TextStore::PTR());
    _lastTempMarkPos = -1;
}

void Logic::bindLogicHanding()
{
    Bind lastBind = tempBind;
    // Обрабатываем конци биндов
    for (auto& bind : _bindVector)
    {
        auto curText = bind.text;
        auto lastText = lastBind.text;
        qint64 curBegin = curText->begin();
        lastText->setEnd(curBegin);
        lastBind = bind;
    }
}

qint64 Logic::posInWavToPosInText(qreal soundPos)
{
    Bind sellectedBind = getBindFromSoundPos(soundPos);
    auto sellectedText = sellectedBind.text;
    qint64 posInText = sellectedText->begin();
    return posInText;
}

qreal Logic::posInTxtToPosInWav(qint64 textPos)
{
    Bind sellectedBind = getBindFromTextPos(textPos);
    auto sellectedSound = sellectedBind.sound;
    qreal posInSound = sellectedSound->begin();
    return posInSound;
}

void Logic::markBindFromSoundPos(qreal soundPos)
{
    Bind markableBind = getBindFromSoundPos(soundPos);
    if (isEquils(markableBind, zeroBind))
        return;
    auto markableText = markableBind.text;
    markableText->mark();
}

void Logic::markBindFromTextPos(qint64 textPos)
{
    Bind markableBind = getBindFromTextPos(textPos);
    if (isEquils(markableBind, zeroBind))
        return;
    auto markableText = markableBind.text;
    markableText->mark();
}

void Logic::unMarkBindFromSoundPos(qreal soundPos)
{
    Bind markableBind = getBindFromSoundPos(soundPos);
    if (isEquils(markableBind, zeroBind))
        return;
    auto markableText = markableBind.text;
    markableText->unmark();
}

void Logic::unMarkBindFromTextPos(qint64 textPos)
{
    Bind markableBind = getBindFromTextPos(textPos);
    if (isEquils(markableBind, zeroBind))
        return;
    auto markableText = markableBind.text;
    markableText->unmark();
}

Logic::Bind Logic::getBindFromSoundOrTextPos(qreal soundPos, qint64 textPos)
{
    if (_bindVector.empty())
        return zeroBind;
    for (auto bind = _bindVector.end()-1;;bind--)
    {
        auto curSound = (*bind).sound;
        auto curText = (*bind).text;
        if (curSound->isBelongs(soundPos) || curText->isBelongs(textPos))
            return *bind;
        if (bind == _bindVector.begin())
            break;

    }
    return zeroBind;
}

Logic::Bind Logic::getBindFromSoundPos(qreal soundPos)
{
    return getBindFromSoundOrTextPos(soundPos, -1);
}

Logic::Bind Logic::getBindFromTextPos(qint64 textPos)
{
    return getBindFromSoundOrTextPos(-1, textPos);
}

qint64 Logic::roundToBindTextPos(qint64 textPos)
{
    auto bind = getBindFromTextPos(textPos);
    auto text = bind.text;
    qint64 rez = text->begin();
    return rez;
}

qreal Logic::roundToBindSoundPos(qreal soundPos)
{
    auto bind = getBindFromSoundPos(soundPos);
    auto sound = bind.sound;
    qint64 rez = sound->begin();
    return rez;
}

Logic::FileTypes Logic::getFileType(const QString&) const
{

    // TODO важно допилить типизацию
    return FileTypes::undefined;
}

void Logic::clear()
{
    _bindVector.clear();
    _recognizedStringPosBegin.clear();
    _recognizedStringPosEnd.clear();
    _recognizedStrings.clear();
    curSoundFileName.clear();
    curTextFileName.clear();
}

void Logic::tempMarkBindInTextPos(qint64 pos)
{
    unMarkBindFromTextPos(_lastTempMarkPos);
    markBindFromTextPos(pos);
    _lastTempMarkPos = pos;
}

void Logic::markAllBindedText()
{
    for (auto bind : _bindVector)
        markBind(bind);
}

void Logic::makeBind(TextFragment::PTR text, SoundFragment::PTR sound, const QString &recognizedText)
{
    Bind b;
    b.text = text;
    b.sound = sound;

    qreal soundBegin = sound->begin();
    qreal soundEnd = sound->end();

    addInBindList(b);
    addInRecognizedList(recognizedText, soundBegin, soundEnd);
}

void Logic::addInBindList(const Bind& bind)
{
    // TODO надо сохранять порядок
    _bindVector.push_back(bind);
    // TODO Добавить проверку последней ссылки на store'ы

    //assert(false);
}

void Logic::addInRecognizedList(const QString& recognizedString, qreal beginSound, qreal endSound)
{
    qint64 posInRecStrings = _recognizedStrings.size();
    _recognizedStrings.push_back(recognizedString);
    _recognizedStringPosBegin[posInRecStrings] = beginSound;
    _recognizedStringPosEnd[posInRecStrings] = endSound;
}

bool Logic::haveIntersaption(const Bind &A, const Bind &B) const
{
    if (A.text->begin() >= B.text->begin() && A.text->end() <= B.text->end())
        return true;
    if (A.sound->begin() >= B.sound->begin() && A.sound->end() <= B.sound->end())
        return true;
    return false;
}

bool Logic::haveIntersaption(const Bind& newBind) const
{
    for (auto bind : _bindVector)
        if (haveIntersaption(bind, newBind))
            return true;
    return false;
}

QVector <Logic::Bind>::iterator Logic::getBindOnTextPos(qint64 textPos)
{
    for (auto bind = _bindVector.begin(); bind != _bindVector.end(); bind++)
    {
        auto curBind = *bind;
        auto curText = curBind.text;
        if (curText->begin() <= textPos && curText->end() >= textPos)
            return bind;
    }
    //auto defaultSound = _staticBindList.front().sound;
    return _bindVector.begin();
}

void Logic::markBind(const Bind& bind)
{
    auto text = bind.text;
    text->mark();
}

void Logic::createFromNewSoundFile(const QString& fileName, TextStore::PTR text, SoundStore::PTR sound)
{
    QFileInfo fileInfo(fileName);
    assert(fileInfo.exists());
    QString base = fileInfo.path() + "/" + fileInfo.completeBaseName();
    QString textFileName = base + ".html";
    QUrl soundUrl = QUrl::fromLocalFile(fileName);
    sound->setFileUrl(soundUrl);
    QFile textTmp(textFileName);
    textTmp.resize(0);
    textTmp.close();
    QUrl textUrl = QUrl::fromLocalFile(textFileName);
    text->setFileUrl(textUrl);
    text->setText("");
    QString bndFileName = base + ".bnd";

    writeInFile(bndFileName, text, sound);
}

void Logic::writeInFile(const QString& fileName, TextStore::PTR textStore, SoundStore::PTR soundStore)
{
    QString textStoreString;
    QString soundStoreString;
    QString textHashString;
    QString soundHashString;
    FileTypes type = getFileType(fileName);
    if (type != FileTypes::binds)
    {
        qDebug() << "Incorrect output file name";
    }

    _curBndFileName = fileName;
    QFileInfo info(fileName);
    QString textFileName = info.path() + "/" + info.baseName() + ".html";
    QUrl textUrl = QUrl::fromLocalFile(textFileName);
    textStore->saveAs(textUrl, ".html");
    soundStoreString = soundStore->toString();
    textStoreString = textStore->toString();

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly))
    {
        qDebug() << "File not open";
        return;
    }
    QTextStream fileStream(&file);
    textHashString = textStore->getHash();
    soundHashString = soundStore->getHash();
    fileStream << par_TextStore << " " << textStoreString << "\n";
    fileStream << par_TextStoreHash << " " << textHashString << "\n";
    fileStream << par_SoundStore << " " << soundStoreString << "\n";
    fileStream << par_SoundStoreHash << " " << soundHashString << "\n";
    for (auto bind : _bindVector)
    {
        QString curStringBind = toString(bind);
        fileStream << par_Bind << " " << curStringBind << "\n";
    }
    qint64 i = 0;
    for (auto str : _recognizedStrings)
    {
        qreal posBegin = _recognizedStringPosBegin[i];
        qreal posEnd = _recognizedStringPosEnd[i];
        QString stringTrimmed = str.trimmed();
        fileStream << par_RecognizedString << " " << stringTrimmed << " "
                   << posBegin << " " << posEnd <<  "\n";
        i++;
    }
    file.close();
}

void Logic::readFromFile(const QString &fileName, TextStore::PTR textStore, SoundStore::PTR soundStore)
{
    QString textStoreString;
    QString soundStoreString;
    QString textHashString;
    QString soundHashString;
    QStringList bindListString;
    QStringList recognizedStrings;
    FileTypes type = getFileType(fileName);
    clear();

    if (type != FileTypes::binds)
    {
        qDebug() << "Incorrect output file name" << "\n";
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "File is not open" << "\n";
        return;
    }
    _curBndFileName = fileName;
    QTextStream fileStream(&file);
    QString par_buff;
    QString value_buff;
    while (!fileStream.atEnd())
    {
        fileStream >> par_buff;
        value_buff = fileStream.readLine();
        if (par_buff == par_Bind)
            bindListString.push_back(value_buff);
        else if (par_buff == par_RecognizedString)
            recognizedStrings.push_back(value_buff);
        else if (par_buff == par_SoundStore)
            soundStoreString = value_buff.trimmed();
        else if (par_buff == par_SoundStoreHash)
            soundHashString = value_buff.trimmed();
        else if (par_buff == par_TextStore)
            textStoreString = value_buff.trimmed();
        else if (par_buff == par_TextStoreHash)
            textHashString = value_buff.trimmed();
    }

    textStore->fromString(textStoreString);
    soundStore->fromString(soundStoreString);

    QString realHashText = textStore->getHash();
    QString realHashSound = soundStore->getHash();

    if (realHashText != textHashString || realHashSound != soundHashString)
        qDebug() << "FileReading: IncorrectHash" << "\n";

    for (auto bindString : bindListString)
    {
        Bind nextBind;
        fromString(nextBind, bindString, soundStore, textStore);
        addInBindList(nextBind);
    }

    qint64 i = 0;
    for (auto recognizedStr : recognizedStrings)
    {
        QString rec;
        qreal begin;
        qreal end;
        fromString(rec, begin, end, recognizedStr);
        _recognizedStrings.push_back(rec);
        _recognizedStringPosBegin[i] = begin;
        _recognizedStringPosEnd[i] = end;
        i++;
    }
    file.close();
}

QString Logic::toString(const Bind& bind) const
{
    auto bindText = bind.text;
    qint64 textBegin = bindText->begin();
    qint64 textEnd = bindText->end();
    auto bindSound = bind.sound;
    qreal soundBegin = bindSound->begin();
    qreal soundEnd = bindSound->end();

    QString rez;
    QTextStream outStream(&rez);
    outStream << textBegin << " " << textEnd << " "
              << soundBegin << " " << soundEnd;
    return rez;
}

void Logic::fromString(Bind& bind, QString bindString, SoundStore::PTR sound, TextStore::PTR text) const
{
    QTextStream sourceString(&bindString);
    qint64 textBegin, textEnd;
    qreal soundBegin, soundEnd;
    sourceString >> textBegin >> textEnd >> soundBegin >> soundEnd;

    auto soundFragment = SoundFragment::factoryMethod(soundBegin, soundEnd, sound);
    auto textFragment = TextFragment::factoryMethod(textBegin, textEnd, text);

    bind.sound = soundFragment;
    bind.text = textFragment;
}

void Logic::fromString(QString& str, qreal& posBegin, qreal& posEnd, QString source) const
{
    QStringList splitedStr = source.split(" ", QString::SplitBehavior::SkipEmptyParts);
    QString stringBegin = *(splitedStr.end() - 2);
    QString stringEnd = *(splitedStr.end() - 1);
    posBegin = stringBegin.toDouble();
    posEnd = stringEnd.toDouble();
    splitedStr.pop_back();
    splitedStr.pop_back();
    str = splitedStr.join(" ");
}
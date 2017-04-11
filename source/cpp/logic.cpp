#include "logic.h"
#include "ASR/bindmaker.h"

Logic::Logic()
{
    zeroBind.sound = SoundFragment::factoryMethod(-1.0f, -1.0f, SoundStore::PTR());
    zeroBind.text = TextFragment::factoryMethod(-1, -1, TextStore::PTR());
    tempBind.sound = SoundFragment::factoryMethod(-1.0f, -1.0f, SoundStore::PTR());
    tempBind.text = TextFragment::factoryMethod(-1, -1, TextStore::PTR());
    _lastTempMarkPos = zeroBind;
    //for (qint32 i = 0; i<_lastTempMarkListSize; i++)
    //    _lastTempMarkPos.append(zeroBind);
    synchPatterns();
}

void Logic::synchPatterns()
{
    QFile confFile(_sourceConfigFile);
    if (!confFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Config file is not open" << "\n";
        return;
    }
    QTextStream confStream(&confFile);
    QString buff = "";
    while (!confStream.atEnd())
    {
        Pattern curPattern;
        confStream >> buff;
        if (buff == par_Title)
        {
            curPattern._title = confStream.readLine();
            confStream >> buff;
            if (buff != par_Type)
                qCritical("Error pattern type");
            QString buff = confStream.readLine();
            if (buff == "file")
                curPattern._type = patternTypes::file;
            else if (buff == "net+")
                curPattern._type = patternTypes::webPlus;
            else
                qCritical() << "Incorrect pattern type";
            if (buff != par_Pattern)
                qCritical() << "Error source pattern";
            curPattern._pattern = confStream.readLine();
            _patternList.push_back(curPattern);
        }
    }
}

QString Logic::getUrlFromPattern(const Pattern &p, QString str) const
{
    str = str.trimmed();
    if (p._type == Logic::webPlus)
    {
        QStringList buff = str.split(" ");
        str = buff.join("+");
    }
    QString rezStr = p._pattern;
    QStringList buff = rezStr.split("SEEKIT");
    rezStr = buff.join(str);

    return rezStr;
}

Logic::Bind Logic::summ(const Bind& left, const Bind& right) const
{
    if (isEquils(left, zeroBind))
        return right;
    if (isEquils(right, zeroBind))
        return left;

    Bind summBind;
    TextFragment::PTR summText;
    SoundFragment::PTR summSound;
    TextFragment::PTR leftText = left.text;
    TextFragment::PTR rightText = right.text;
    SoundFragment::PTR leftSound = left.sound;
    SoundFragment::PTR rightSound = right.sound;

    summText = TextFragment::summ(leftText, rightText);
    summSound = SoundFragment::summ(leftSound, rightSound);

    summBind.sound = summSound;
    summBind.text = summText;

    return summBind;
}

QString Logic::getTitle(const QUrl& bindFileName) const
{
    //QFileInfo fileInfo(bindFileName);
    QString stringName = bindFileName.toLocalFile();
    QFile bindFile(stringName);
    if (!bindFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "File is not open" << "\n";
        return "";
    }
    QTextStream bindStream(&bindFile);
    QString buff = "";
    QString title;
    while (!bindStream.atEnd())
    {
        bindStream >> buff;
        if (buff == par_Title)
            title = bindStream.readLine();
    }
    return title;
}

TextFragment::PTR Logic::getText(qint64 pos) const
{
    if (pos == 0)
        return _bindVector.front().text;
    else if (pos == _bindVector.length() - 1)
        return _bindVector.back().text;
    else
        qCritical() << "It version can\'t get u mid text";
    assert(false);
    return nullptr;
}

SoundFragment::PTR Logic::getSound(qint64 pos) const
{
    if (pos == 0)
        return _bindVector.front().sound;
    else if (pos == _bindVector.length())
        return _bindVector.back().sound;
    else
        qCritical() << "It version can\'t get u mid text";
    assert(false);
    return nullptr;
}

qint64 Logic::getBindNumber() const
{
    return _bindVector.size();
}

QList <Logic::Example> Logic::getExamples(const QString& seakablePhrase, qreal minDuration, qreal maxDuration, bool findInThisFile) const
{
    QList <Logic::Example> rezList;
    QDir curDir;
    QStringList bindFiles = curDir.entryList(QStringList("*.bnd"));
    TextStore::PTR tmp_textStore = TextStore::factoryMethod();
    SoundStore::PTR tmp_soundStore = SoundStore::factoryMethod();
    Logic tmp_logic;
    for (QString bnd : bindFiles)
    {
        if (!findInThisFile && bnd == _curBndFileName)
            continue;
        tmp_logic.readFromFile(bnd, tmp_textStore, tmp_soundStore);
        auto bndExamples = tmp_logic.getExamplesInThis(seakablePhrase, minDuration, maxDuration);
        rezList += bndExamples;
    }
    return rezList;
}

QList <Logic::Example> Logic::getExamplesInThis(const QString& seekablePhrase, qreal minDuration, qreal maxDuration)
{
    QList <Logic::Example> rezList;

    auto bindsWithSeekablePhrase = getBindsWithPhrase(seekablePhrase);

    for (auto bind : bindsWithSeekablePhrase)
    {
        Example newExample;
        auto soundFragment = bind.sound;
        qreal duration = soundFragment->size();
        if (duration < minDuration || duration > maxDuration)
            continue;
        auto sound = soundFragment->getSource();
        auto text = bind.text;
        newExample.FileName = sound->toString();
        newExample.start = soundFragment->begin();
        newExample.end = soundFragment->end();
        newExample.realUrl = sound->fileUrl();
        newExample.text = "... " + text->getString() + " ...";
        newExample.exampableWord = seekablePhrase;
        rezList.push_back(newExample);
    }

    return rezList;
}

void Logic::addWhileNotFindSentenceEnd(QVector <Logic::Bind>::iterator firstAdd, Logic::Bind& curBind, const QString& seekablePhrase, qint32 step) const
{
    assert(step == -1 || step == 1);
    if (_findInSequence == false)
        return;

    for (auto curAdd = firstAdd; curAdd != _bindVector.end() ; curAdd += step)
    {
        auto text = curBind.text;
        if (step == -1 && text->haveSentanceEndPrev(seekablePhrase))
            break;
        if (step == 1 && text->haveSentanceEndPost(seekablePhrase))
            break;
        if (text->isPhraseInMidSentance(seekablePhrase))
            break;

        if (step == 1)
            curBind = summ(curBind, *curAdd);
        else
            curBind = summ(*curAdd, curBind);

        if (curAdd == _bindVector.begin())
            break;
        if (curAdd + step == _bindVector.end())
            break;
    }

}

QList <Logic::Bind> Logic::getBindsWithPhrase(const QString& seekablePhrase)
{
    QList <Logic::Bind> rezList;

    _bindVector.push_front(zeroBind);
    _bindVector.push_back(zeroBind);

    auto curBind = _bindVector.begin() + 1;
    qint32 curnumber = 0; // TODO для дебага

    for (;curBind != _bindVector.end() - 1; curBind++)
    {
        curnumber++;
        if (curnumber > 76)
            curnumber += 10;
        Bind next = *(curBind+1);
        Bind prev = *(curBind-1);
        TextFragment::PTR cutTextFragmend = (*curBind).text;
        Bind summBind = *curBind;
        if (cutTextFragmend->havePhraseOnMid(seekablePhrase))
        {
            addWhileNotFindSentenceEnd(curBind-1, summBind, seekablePhrase, -1);
            addWhileNotFindSentenceEnd(curBind+1, summBind, seekablePhrase, 1);
        }
        else if (cutTextFragmend->havePhraseOnBegin(seekablePhrase))
        {
            summBind = summ(prev, summBind);
            if (curBind-1 != _bindVector.begin())
                addWhileNotFindSentenceEnd(curBind-2, summBind, seekablePhrase, -1);
            addWhileNotFindSentenceEnd(curBind+1, summBind, seekablePhrase, 1);
        } else if (cutTextFragmend->havePhraseOnEnd(seekablePhrase))
        {
            summBind = summ(summBind, next);
            addWhileNotFindSentenceEnd(curBind-1, summBind, seekablePhrase, -1);
            if (curBind+1 != _bindVector.end())
                addWhileNotFindSentenceEnd(curBind+2, summBind, seekablePhrase, 1);
        }
        else
            continue;
        if (rezList.empty() ||
                isEquils(rezList.back(), summBind) == false) // TODO Возможно стоит проверять все бинды на эквивалентность
            rezList.push_back(summBind);
    }

    _bindVector.pop_front();
    _bindVector.pop_back();

    return rezList;
}

void Logic::bindLogicHanding()
{
    Bind lastBind = tempBind;
    // Обрабатываем текстовые конци биндов
    for (auto& bind : _bindVector)
    {
        auto curText = bind.text;
        auto lastText = lastBind.text;
        qint64 curBegin = curText->begin();
        lastText->setEnd(curBegin);
        lastBind = bind;
    }
    lastBind = tempBind;
    // Обрабатываем текстовые конци биндов
    for (auto& bind : _bindVector)
    {
        auto curSound = bind.sound;
        auto lastSound = lastBind.sound;
        qreal curBegin = curSound->begin();
        lastSound->setEnd(curBegin);
        lastBind = bind;
    }
}

QList <QString> Logic::getCommentNamesonTextPos(qint64 pos) const
{
    QList <QString> rezList;
    qint64 begin, end;
    begin = end = pos;
    Bind b = getBindFromTextPos(pos);
    if (!isEquils(b, zeroBind))
    {
        auto text = b.text;
        begin = text->begin();
        end = text->end();
    }
    rezList = getCommentNamesonTextPos(begin, end);
    return rezList;
}
QList <QString> Logic::getCommentNamesonTextPos(qint64 begin, qint64 end) const
{
    QList <QString> rezList;
    for (Comment comment : _commentsVector)
    {
        auto commented = comment.commented;
        if (commented.isNull())
            continue;
        if (commented->haveIntersaption(begin, end))
        {
            QString name = comment.name;
            rezList.push_back(name);
        }
    }
    return rezList;
}

QUrl Logic::getCommentUrlsonName(const QString& name) const
{
    for (Comment comment : _commentsVector)
        if (comment.name == name)
            return comment.commentUrl;
    assert(true);
    return QUrl();
}


qint64 Logic::posInWavToPosInText(qreal soundPos) const
{
    Bind sellectedBind = getBindFromSoundPos(soundPos);
    auto sellectedText = sellectedBind.text;
    qint64 posInText = sellectedText->begin();
    if (posInText < 0)
        return 0;
    return posInText;
}

qreal Logic::posInTxtToPosInWav(qint64 textPos) const
{
    Bind sellectedBind = getBindFromTextPos(textPos);
    auto sellectedSound = sellectedBind.sound;
    qreal posInSound = sellectedSound->begin();
    return posInSound;
}

qint32 Logic::getTextBeginPosCurBind() const
{
    auto curBind = _lastTempMarkPos;
    auto text = curBind.text;
    qint32 begin = text->begin();
    return begin;
}

qint32 Logic::getTextEndPosCurBind() const
{
    auto curBind = _lastTempMarkPos;
    auto text = curBind.text;
    qint32 end = text->end();
    return end;
}

qint32 Logic::getTextMidPosCurBind() const
{
    auto curBind = _lastTempMarkPos;
    auto text = curBind.text;
    qint32 mid = text->mid();
    return mid;
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

Logic::Bind Logic::getBindFromSoundOrTextPos(qreal soundPos, qint64 textPos) const
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

Logic::Bind Logic::getBindFromSoundPos(qreal soundPos) const
{
    return getBindFromSoundOrTextPos(soundPos, -1);
}

Logic::Bind Logic::getBindFromTextPos(qint64 textPos) const
{
    return getBindFromSoundOrTextPos(-1, textPos);
}

qint64 Logic::roundToBindTextPos(qint64 textPos) const
{
    auto bind = getBindFromTextPos(textPos);
    auto text = bind.text;
    qint64 rez = text->begin();
    return rez;
}

qreal Logic::roundToBindSoundPos(qreal soundPos) const
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

void Logic::clear(bool clearRecognized)
{
    _bindVector.clear();
    _commentsVector.clear();
    if (clearRecognized)
    {
        _recognizedStringPosBegin.clear();
        _recognizedStringPosEnd.clear();
        _recognizedStrings.clear();
    }
    //curSoundFileName.clear();
   // curTextFileName.clear();
}

void Logic::tempMarkBindInTextPos(qint64 pos)
{
    //unMarkAllBindedText();
    unmarkLastBind();
    auto curBind = getBindFromTextPos(pos);
    markBind(curBind);
    _lastTempMarkPos = curBind;
    //_lastTempMarkPos.push_back(curBind);
    //_lastTempMarkPos.pop_front();
}

void Logic::markLastBind()
{
    markBind(_lastTempMarkPos);
}

void Logic::unmarkLastBind()
{
    unmarkBind(_lastTempMarkPos);
}

void Logic::markAllBindedText()
{
    for (auto bind : _bindVector)
        markBind(bind);
}

void Logic::unMarkAllBindedText()
{
    for (auto bind : _bindVector)
        unmarkBind(bind);
}

void Logic::makeBind(TextFragment::PTR text, SoundFragment::PTR sound, qint64 pos)
{
    Bind b;
    b.text = text;
    b.sound = sound;
    addInBindList(b, pos);
}

void Logic::addInBindList(const Bind& bind, qint64 pos)
{
    // TODO Добавить возможность вставки в середину

    // TODO надо сохранять порядок
    if (pos == -1)
        _bindVector.push_back(bind);
    else if (pos == 0)
        _bindVector.push_front(bind);
    else
        qCritical() << "We can\'t add bind in mid";

    // TODO Добавить проверку последней ссылки на store'ы

    //assert(false);
}

void Logic::makeComment(TextFragment::PTR text, QUrl url, const QString& name)
{
    Comment c;
    c.name = name;
    c.commented = text;
    c.commentUrl = url;
    addInCommentList(c);
}

void Logic::addInCommentList(const Comment& comment)
{
    _commentsVector.push_back(comment);
}

void Logic::addRecognizedString(const QStringList& recognizedString, SoundFragment::PTR sound, QString fileName)
{
    qreal soundBegin = sound->begin();
    qreal soundEnd = sound->end();
    addRecognizedString(recognizedString, soundBegin, soundEnd, fileName);
}

void Logic::addRecognizedString(const QStringList& recognizedString, qreal beginSound, qreal endSound, QString fileName)
{
    if (fileName.length() == 0)
    {
        qint64 ID = _recognizedStrings.size();
        fileName = QString().number(ID);
    }
    _recognizedStrings[fileName] = recognizedString;
    _recognizedStringPosBegin[fileName] = beginSound;
    _recognizedStringPosEnd[fileName] = endSound;
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
    if (text.isNull())
        return;
    text->mark();
}

void Logic::unmarkBind(const Bind& bind)
{
    auto text = bind.text;
    if (text.isNull())
        return;
    text->unmark();
}

void Logic::markBind(const QList<Bind>& bindList)
{
    for (auto bind : bindList)
        markBind(bind);
}

void Logic::unmarkBind(const QList<Bind>& bindList)
{
    for (auto bind : bindList)
        unmarkBind(bind);
}

void Logic::createFromNewSoundFile(const QString& fileName, TextStore::PTR text, SoundStore::PTR sound)
{
    QFileInfo fileInfo(fileName);
    assert(fileInfo.exists());
    QString base = fileInfo.path() + "/" + fileInfo.completeBaseName();
    QString textFileName = base + ".html";
    QUrl soundUrl = QUrl::fromLocalFile(fileName);
    sound->setFileUrl(soundUrl);
    //QFile textTmp(textFileName);
    //textTmp.resize(0);
    //textTmp.close();
    QUrl textUrl = QUrl::fromLocalFile(textFileName);
    text->setFileUrl(textUrl);
    //text->setText("");
    QString bndFileName = base + ".bnd";

    writeInFile(bndFileName, text, sound);
}
void Logic::writeInFile(TextStore::PTR textStore, SoundStore::PTR soundStore)
{
    writeInFile(_curBndFileName, textStore, soundStore);
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

    for (auto id : _recognizedStrings.keys())
    {
        QStringList str = _recognizedStrings[id];
        qreal posBegin = _recognizedStringPosBegin[id];
        qreal posEnd = _recognizedStringPosEnd[id];
        fileStream << par_RecognizedString << " ";
        for (auto word : str)
            fileStream << word << " ";
        fileStream << posBegin << " " << posEnd <<  "\n";
    }
    for (auto comment : _commentsVector)
    {
        QString curStringBind = toString(comment);
        fileStream << par_Comment << " " << curStringBind << "\n";
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
    QStringList commentListString;
    QStringList recognizedStrings;
    FileTypes type = getFileType(fileName);
    clear(true);

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
        if (par_buff == par_Comment)
            commentListString.push_back(value_buff);
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

    QString realHashText;
    QString realHashSound;
    QString curPath = QFileInfo(fileName).absolutePath();
    textStoreString = curPath + "/" + textStoreString;
    soundStoreString = curPath + "/" + soundStoreString;
    if (!textStore.isNull())
    {
        textStore->fromString(textStoreString);
        realHashText = textStore->getHash();
    }
    if (!soundStore.isNull())
    {
        soundStore->fromString(soundStoreString);
        realHashSound = soundStore->getHash();
    }

    if (!soundStore.isNull() || !soundStore.isNull())
        if (realHashText != textHashString || realHashSound != soundHashString)
            qDebug() << "FileReading: IncorrectHash" << "\n";

    for (auto bindString : bindListString)
    {
        Bind nextBind;
        fromString(nextBind, bindString, soundStore, textStore);
        addInBindList(nextBind);
    }

    for (auto commentString : commentListString)
    {
        Comment nextComment;
        fromString(nextComment, commentString, textStore);
        addInCommentList(nextComment);
    }

    for (auto recognizedStr : recognizedStrings)
    {
        QStringList rec;
        qreal begin;
        qreal end;
        fromString(rec, begin, end, recognizedStr);
        addRecognizedString(rec, begin, end);
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

QString Logic::toString(const Comment & comment) const{
    QUrl url = comment.commentUrl;
    QString stringUrl = url.toString();
    auto commented = comment.commented;
    qint64 textBegin = commented->begin();
    qint64 textEnd = commented->end();
    QString stringName = comment.name;

    QString rez;
    QTextStream outStream(&rez);
    outStream << stringUrl << " " << stringName << " "
              << textBegin << " " << textEnd;

    return rez;
}

void Logic::fromString(Comment&, QString stringComment, TextStore::PTR text)
{
    QUrl url;
    QString name;
    qint64 begin;
    qint64 end;
    QString stringUrl;
    QTextStream sourceString(&stringComment);
    sourceString >> stringUrl >> name >> begin >> end;
    url = QUrl::fromLocalFile(stringUrl);

    auto commented = TextFragment::factoryMethod(begin, end, text);

    Comment newComment;
    newComment.commented = commented;
    newComment.commentUrl = url;
    newComment.name = name;

    addInCommentList(newComment);
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

void Logic::fromString(QStringList& str, qreal& posBegin, qreal& posEnd, QString source) const
{
    str = source.split(" ", QString::SplitBehavior::SkipEmptyParts);
    QString stringBegin = *(str.end() - 2);
    QString stringEnd = *(str.end() - 1);
    posBegin = stringBegin.toDouble();
    posEnd = stringEnd.toDouble();
    str.pop_back();
    str.pop_back();
}

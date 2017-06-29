#include "logic.h"
#include "Binding/bindmaker.h"

Logic::Logic()
{
    zeroBind.sound = SoundFragment::factoryMethod(-1.0f, -1.0f, SoundStore::PTR());
    zeroBind.text = TextFragment::factoryMethod(-1, -1, TextStore::PTR());
    tempBind.sound = SoundFragment::factoryMethod(-1.0f, -1.0f, SoundStore::PTR());
    tempBind.text = TextFragment::factoryMethod(-1, -1, TextStore::PTR());
    _lastBindIterator = _bindVector.constEnd();
    _f_notMarkBinds = false;
    //for (qint32 i = 0; i<_lastTempMarkListSize; i++)
    //    _lastTempMarkPos.append(zeroBind);
    synchPatterns();
}

void Logic::createAutoComments(qint32 autoCommentsNumber)
{
    assert(autoCommentsNumber >= 1);
    deleteAllComments();
    Bind summBind = zeroBind;
    qint32 curBindNumber = 0;
    for (auto curBind : _bindVector)
    {
        summBind = summ(summBind, curBind);
        curBindNumber++;
        if (curBindNumber == autoCommentsNumber)
        {
            makeComment(summBind);
            summBind = zeroBind;
            curBindNumber = 0;
        }
    }
    if (_bindVector.empty() == false)
        makeComment(summBind);
    save();
}

void Logic::setCurBindEnd(qint64 pos)
{
    if (isNormalBind(_lastBindIterator) == false)
        return;
    TextFragment::PTR curText = _lastBindIterator->text;
    qint64 minPos = curText->begin();
    qint64 maxPos;
    auto next = _lastBindIterator+1;
    if (isNormalBind(next))
    {
        TextFragment::PTR nextText = next->text;
        maxPos = nextText->end();
    }
    else
        maxPos = _lastOpenedTextStore->length();

    if (pos < minPos)
        pos = minPos + 1;
    else if (pos > maxPos)
        pos = maxPos - 1;
    //curText->setEnd(pos);
    setCurBindEnd(pos, _lastBindIterator);
    setCurBindBegin(pos, next);
}

void Logic::setCurBindBegin(qint64 pos)
{
    if (isNormalBind(_lastBindIterator) == false)
        return;
    TextFragment::PTR curText = _lastBindIterator->text;
    qint64 maxPos = curText->end();
    qint64 minPos;

    QVector<Bind>::const_iterator prev;
    bool havePrev = _lastBindIterator != _bindVector.begin();
    if (havePrev)
        prev = _lastBindIterator - 1;
    if (havePrev && isNormalBind(prev))
    {
        TextFragment::PTR prevText = prev->text;
        minPos = prevText->begin();
    }
    else
        minPos = -1;

    if (pos < minPos)
        pos = minPos + 1;
    else if (pos > maxPos)
        pos = maxPos - 1;
    //curText->setEnd(pos);
    setCurBindBegin(pos, _lastBindIterator);
    if (havePrev)
        setCurBindEnd(pos, prev);
}

void Logic::setCurBindEnd(qint64 pos, QVector<Bind>::const_iterator cur)
{
    if (isNormalBind(cur) == false)
        return;
    TextFragment::PTR curText = cur->text;
    curText->setEnd(pos);
}

void Logic::setCurBindBegin(qint64 pos, QVector<Bind>::const_iterator cur)
{
    if (isNormalBind(cur) == false)
        return;
    TextFragment::PTR curText = cur->text;
    curText->setBegin(pos);
}

//void Logic::addWordInCurBindEnd(QVector<Bind>::const_iterator cur)
//{
//    assert(false); // не тестилось
//    if (isNormalBind(cur) == false)
//        return;
//    TextFragment::PTR text = cur->text;
//    qint64 end = text->end();
//    qint64 newEnd = getWordEnd(end, false);
//    if (newEnd < 0)
//        return;
//    text->setEnd(newEnd);
//}

//void Logic::addWordInCurBindBegin(QVector<Bind>::const_iterator cur)
//{
//    assert(false); // не тестилось
//    if (isNormalBind(cur) == false)
//        return;
//    TextFragment::PTR text = cur->text;
//    qint64 begin = text->begin();
//    qint64 newBegin = getWordEnd(begin, true);
//    if (newBegin < 0)
//        return;
//    text->setBegin(newBegin);
//}

//void Logic::deleteWordFromCurBindEnd(QVector<Bind>::const_iterator cur)
//{
//    assert(false); // не тестилось
//    if (isNormalBind(cur) == false)
//        return;
//    TextFragment::PTR text = cur->text;
//    qint64 end = text->end();
//    qint64 newEnd = getWordEnd(end, true);
//    if (newEnd < 0)
//        return;
//    text->setEnd(newEnd);
//}

//void Logic::deleteWordFromCurBindBegin(QVector<Bind>::const_iterator cur)
//{
//    assert(false); // не тестилось
//    if (isNormalBind(cur) == false)
//        return;
//    TextFragment::PTR text = cur->text;
//    qint64 begin = text->begin();
//    qint64 newBegin = getWordEnd(begin, false);
//    if (newBegin < 0)
//        return;
//    text->setBegin(newBegin);
//}

//void Logic::addWordInCurBindEnd()
//{
//    if (isNormalBind(_lastBindIterator) == false)
//        return;
//    addWordInCurBindEnd(_lastBindIterator);
//    auto next = _lastBindIterator+1;
//    if (isNormalBind(next) == false)
//        return;
//    deleteWordFromCurBindBegin(next);
//}

//void Logic::addWordInCurBindBegin()
//{
//    if (isNormalBind(_lastBindIterator) == false)
//        return;
//    addWordInCurBindBegin(_lastBindIterator);
//    if (_lastBindIterator == _bindVector.begin())
//        return;
//    auto prev = _lastBindIterator - 1;
//    if (isNormalBind(prev) == false)
//        return;
//    deleteWordFromCurBindEnd(prev);
//}

//void Logic::deleteWordFromCurBindEnd()
//{
//    if (isNormalBind(_lastBindIterator) == false)
//        return;
//    deleteWordFromCurBindEnd(_lastBindIterator);
//    auto next = _lastBindIterator + 1;
//    if (isNormalBind(next) == false)
//        return;
//    addWordInCurBindBegin(next);
//}

//void Logic::deleteWordFromCurBindBegin()
//{
//    if (isNormalBind(_lastBindIterator) == false)
//        return;
//    deleteWordFromCurBindBegin(_lastBindIterator);
//    if (_lastBindIterator == _bindVector.begin())
//        return;
//    auto prev = _lastBindIterator - 1;
//    if (isNormalBind(prev) == false)
//        return;
//    addWordInCurBindEnd(prev);
//}

//qint64 Logic::getWordEnd(qint64 curPos, bool reversDirrection)
//{
//    if (_lastOpenedTextStore.isNull())
//        return -1;
//    return _lastOpenedTextStore->getWordEnd(curPos, reversDirrection);
//}

bool Logic::posIsCorrect(qint64 curPos) const
{
    if (_lastOpenedTextStore.isNull())
        return false;
    return _lastOpenedTextStore->posIsCorrect(curPos);
}

QString Logic::getUniqCommentName()
{
    QString curDir = getCurBndUrl();
    for (int uniqID = 0; uniqID<100000; uniqID++)
    {
        QString ID = QString().number(uniqID);
        QString newUniqName = curDir + "/comment" + ID + ".html";
        if (QFile::exists(newUniqName) == false)
            return newUniqName;
    }
    return QString("If you see it file then you have more 100000 files in one directory... It\'s bad");
}

QString Logic::getCurBndUrl()
{
     QFileInfo bndFileInfo(_curBndFileName);
     QString curBndUrl = bndFileInfo.absolutePath();
     return curBndUrl;
}

void Logic::deleteAllFiles()
{
    for (Comment comment : _commentsVector)
    {
        QUrl commentUrl = comment.commentUrl;
        QString commentStringUrl = commentUrl.toLocalFile();
        QFile::remove(commentStringUrl);
    }
    auto bindInfo = QFileInfo(_curBndFileName);
    auto baseName = bindInfo.baseName();
    auto curPath = bindInfo.absolutePath();
    QString soundString = curPath + "/" + _soundStoreString;
    QString textString = curPath + "/" + _textStoreString;
    if (SoundStore::isRemoteSource(soundString) == false)
        QFile::remove(soundString);
    if (TextStore::isRemoteSource(textString) == false)
        QFile::remove(textString);

    QStringList deleteMask = QStringList(baseName + ".*");
    auto allSimalarNameFiles = QDir(curPath).entryInfoList(deleteMask);
    for (auto fileInfo : allSimalarNameFiles)
    {
        QString filePath = fileInfo.absoluteFilePath();
        QFile::remove(filePath);
    }
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
            buff = buff.trimmed();
            if (buff != par_Type)
                qCritical("Error pattern type");
            QString buff = confStream.readLine().trimmed();
            if (buff == "file")
                curPattern._type = patternTypes::file;
            else if (buff == "net+")
                curPattern._type = patternTypes::webPlus;
            else
            {
                qCritical() << "Incorrect pattern type";
                continue;
            }
            confStream >> buff;
            buff = buff.trimmed();
            if (buff != par_Pattern)
                qCritical() << "Error source pattern";
            curPattern._pattern = confStream.readLine().trimmed();
            if (curPattern._type == patternTypes::file)
            {
                QString curDir = QDir::currentPath();
                curPattern._pattern = curDir + curPattern._pattern;
            }

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

    return rezStr.trimmed();
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

QString Logic::getText() const
{
    QString text = _lastOpenedTextStore->getString();
    return text;
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

void Logic::getAllFiles(QStringList& rezList, QDir curDir, const QStringList mask)
{
    QFileInfoList fileInfoList = curDir.entryInfoList(mask);
    for (auto fileInfo : fileInfoList)
    {
        QString addingFile = fileInfo.absoluteFilePath();
        rezList.push_back(addingFile);
    }
    QStringList allDirs = curDir.entryList(QDir::Dirs);
    for (auto dirString : allDirs)
    {
        if (dirString == "." || dirString == "..")
            continue;
        QDir nextDir = curDir.absolutePath() + "/" + dirString;
        getAllFiles(rezList, nextDir, mask);
    }
}

QList <Logic::Example> Logic::getExamples(const QString& seekablePhrase, qreal minDuration, qreal maxDuration, bool findInThisFile)
{
    QList <Logic::Example> rezList;

    QMap <qint32, QUrl> soundFileUrls;
    auto bindsWithSeekablePhrase = getBindsWithPhrase(seekablePhrase, soundFileUrls);

    qint32 curBindNumber = 0;
    for (auto bind : bindsWithSeekablePhrase)
    {
        Example newExample;
        auto soundFragment = bind.sound;
        qreal duration = soundFragment->size();
        if (duration < minDuration || duration > maxDuration)
            continue;
        //auto sound = soundFragment->getSource();
        auto text = bind.text;
        if (text->getSource() == nullptr)
            continue;
        QUrl curUrl = soundFileUrls[curBindNumber];
        newExample.FileName = curUrl.fileName();
        newExample.start = soundFragment->begin();
        newExample.end = soundFragment->end();
        newExample.realUrl = curUrl;
        newExample.text = "... " + text->getString() + " ...";
        newExample.exampableWord = seekablePhrase;
        rezList.push_back(newExample);
        curBindNumber++;
    }

    return rezList;
}

//QList <Logic::Example> Logic::getExamplesInThis(const QString& seekablePhrase, qreal minDuration, qreal maxDuration)
//{
//    QList <Logic::Example> rezList;

//    auto bindsWithSeekablePhrase = getBindsWithPhrase(seekablePhrase);

//    for (auto bind : bindsWithSeekablePhrase)
//    {
//        Example newExample;
//        auto soundFragment = bind.sound;
//        qreal duration = soundFragment->size();
//        if (duration < minDuration || duration > maxDuration)
//            continue;
//        auto sound = soundFragment->getSource();
//        auto text = bind.text;
//        if (sound == nullptr || text->getSource() == nullptr)
//            continue;
//        newExample.FileName = sound->getFileName();
//        newExample.start = soundFragment->begin();
//        newExample.end = soundFragment->end();
//        newExample.realUrl = sound->fileUrl();
//        newExample.text = "... " + text->getString() + " ...";
//        newExample.exampableWord = seekablePhrase;
//        rezList.push_back(newExample);
//    }

//    return rezList;
//}

//void Logic::addWhileNotFindSentenceEnd(QVector <Logic::Bind>::iterator firstAdd, Logic::Bind& curBind, const QString& seekablePhrase, qint32 step) const
//{
//    assert(step == -1 || step == 1);
//    if (_findInSequence == false)
//        return;

//    for (auto curAdd = firstAdd; curAdd != _bindVector.constEnd() ; curAdd += step)
//    {
//        auto text = curBind.text;
//        if (step == -1 && text->haveSentanceEndPrev(seekablePhrase))
//            break;
//        if (step == 1 && text->haveSentanceEndPost(seekablePhrase))
//            break;
//        if (text->isPhraseInMidSentance(seekablePhrase))
//            break;

//        if (step == 1)
//            curBind = summ(curBind, *curAdd);
//        else
//            curBind = summ(*curAdd, curBind);

//        if (curAdd == _bindVector.begin())
//            break;
//        if (curAdd + step == _bindVector.constEnd())
//            break;
//    }
//}


Logic::Bind Logic::addBindToPoints(qint64 findedBegin, qint64 findedEnd, QVector <Bind>::const_iterator begin, QVector <Bind>::const_iterator end)
{
    Bind rez = addBindToLeftPoint(*begin, findedBegin, begin);
    rez = addBindToRightPoint(rez, findedEnd, end);
    return rez;
}

Logic::Bind Logic::addBindToLeftPoint(Bind cur, qint64 findedBegin, QVector <Bind>::const_iterator begin)
{
    Bind rez = cur;
    if (begin == _bindVector.constBegin())
        return rez;
    auto beginIterator = begin - 1;
    while (true)
    {
        if (rez.text->havePointBeforePos(findedBegin))
        {
            qint64 leftOffset = findedBegin - rez.text->begin();
            qint64 fragmentSize = rez.text->size();
            if (leftOffset > fragmentSize * 0.25)
                break;
        }
        if (isNormalBind(beginIterator) == false)
            break;
        rez = summ(*beginIterator, rez);
        if (beginIterator == _bindVector.constBegin())
            break;
        beginIterator--;
    }
    return rez;
}

Logic::Bind Logic::addBindToRightPoint(Bind cur, qint64 findedEnd, QVector <Bind>::const_iterator end)
{
    Bind rez = cur;
    if (end + 1 == _bindVector.constEnd())
        return rez;
    auto endIterator = end + 1;
    while (true)
    {
        if (rez.text->havePointAfterPos(findedEnd))
        {
            qint64 rightOffset = rez.text->end() - findedEnd;
            qint64 fragmentSize = rez.text->size();
            if (rightOffset > fragmentSize * 0.25)
                break;
        }
        if (isNormalBind(endIterator) == false)
            break;
        rez = summ(rez, *endIterator);
        endIterator++;
        if (endIterator == _bindVector.constEnd())
            break;
    }
    return rez;
}

QList <Logic::Bind> Logic::getBindsWithPhrase(const QString& seekablePhrase, QMap <qint32, QUrl>& soundFileUrls)
{
    QList <Logic::Bind> rezList;
    // Искать только в текущем и следующем
    QString firstWord = seekablePhrase.split(QRegExp("\\W"), QString::SkipEmptyParts).front();
    QList <QSharedPointer<Logic::Cash>> cashes = _cashMap[firstWord];
    for (QSharedPointer<Cash> cash : cashes)
    {
        cash->_binds.push_back(zeroBind);
        cash->_binds.push_front(zeroBind);
        QSet <qint64> findedBegins;
        for (qint32 wordPos : cash->_wordPos[firstWord])
        {
            auto cur = cash->_binds.begin() + wordPos + 1;
            auto next = cur + 1;
            Bind bindWithPhrase = getBindWithPhrase(seekablePhrase, cur, next, findedBegins);
            if (isEquils(bindWithPhrase, zeroBind) == false)
            {
                soundFileUrls[rezList.size()] = cash->_soundFileUrl;
                rezList.push_back(bindWithPhrase);
            }
        }
        cash->_binds.pop_back();
        cash->_binds.pop_front();
    }
    return rezList;
}

Logic::Bind Logic::getBindWithPhrase(const QString& seekablePhrase, QVector <Bind>::const_iterator cur, QVector <Bind>::const_iterator next, QSet <qint64>& findedBegins)
{
    Bind curBind = *cur;
    Bind nextBind = *(cur+1);
    TextFragment::PTR curText = curBind.text;
    TextFragment::PTR nextText = nextBind.text;
    if (isNormalBind(cur) == false && isNormalBind(cur+1) == false)
        return zeroBind;
    TextFragment::PTR fullText = TextFragment::summ(curText, nextText);
    QString fullString = fullText->getString();
    fullString = fullString.toLower();
    qint64 beginPos = -1;
    qint64 realBeginPos = -1;
    while (true)
    {
        QRegExp wordRX = TextStore::getRegXFor(seekablePhrase);
        beginPos = fullString.indexOf(wordRX, beginPos+1);
        realBeginPos = beginPos + fullText->begin();
        if (beginPos == -1 || findedBegins.contains(realBeginPos) == false)
            break;
    }
    if (beginPos == -1 || findedBegins.contains(realBeginPos))
        return zeroBind;
    findedBegins.insert(realBeginPos);
    qint64 realEndPos = realBeginPos + seekablePhrase.length();
    auto beginBind = cur;
    auto endBind = cur;
    if (curText->isBelongs(realEndPos) == false)
        endBind = cur + 1;
    if (isNormalBind(beginBind) == false || isNormalBind(endBind) == false)
        return zeroBind;
    auto rezBind = addBindToPoints(realBeginPos, realEndPos, beginBind, endBind);
    return rezBind;
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
    auto b = getBindFromTextPos(pos);
    if (b != _bindVector.constEnd())
    {
        auto text = (*b).text;
        begin = text->begin();
        end = text->end();
    }
    rezList = getCommentNamesonTextPos(begin, end);
    return rezList;
}

Logic::Comment Logic::getCommentWithName(const QString& name) const
{
    auto rezComment = *find_if(_commentsVector.begin(), _commentsVector.end(), [name](const Comment& el){
        return el.name == name;
    });
    return rezComment;
}

QList <QString> Logic::getCommentNamesonTextPos(TextFragment::PTR text) const
{
    qint64 begin = text->begin();
    qint64 end = text->end();
    auto rezList = getCommentNamesonTextPos(begin, end);
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
        if (commented->haveIntersaption(begin + 1, end - 1)) // + 1 - чтобы не выводить смежные камментарии
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
    assert(false);
    return QUrl();
}


qint64 Logic::posInWavToPosInText(qreal soundPos) const
{
    auto sellectedBind = getBindFromSoundPos(soundPos);
    if (sellectedBind == _bindVector.constEnd())
        return 0;
    auto sellectedText = (*sellectedBind).text;
    qint64 posInText = sellectedText->begin();
    return posInText;
}

qreal Logic::posInTxtToPosInWav(qint64 textPos) const
{
    auto sellectedBind = getBindFromTextPos(textPos);
    if (sellectedBind == _bindVector.constEnd())
        return 0;
    auto sellectedSound = (*sellectedBind).sound;
    qreal posInSound = sellectedSound->begin();
    return posInSound;
}

qint32 Logic::getTextBeginPosCurBind() const
{
    auto curBind = _lastBindIterator;
    if (curBind == _bindVector.constEnd())
        return 0;
    auto text = (*curBind).text;
    qint32 begin = text->begin();
    return begin;
}

qint32 Logic::getTextEndPosCurBind() const
{
    auto curBind = _lastBindIterator;
    if (curBind == _bindVector.constEnd())
        return 0;
    auto text = (*curBind).text;
    qint32 end = text->end();
    return end;
}

qint32 Logic::getTextMidPosCurBind() const
{
    auto curBind = _lastBindIterator;
    if (curBind == _bindVector.constEnd())
        return 0;
    auto text = (*curBind).text;
    if (text.isNull())
        return 0;
    qint32 mid = text->mid();
    return mid;
}

void Logic::markBindFromSoundPos(qreal soundPos)
{
    auto markableBind = getBindFromSoundPos(soundPos);
    if (markableBind == _bindVector.constEnd())
        return;
    auto markableText = (*markableBind).text;
    markableText->mark();
}

void Logic::markBindFromTextPos(qint64 textPos)
{
    auto markableBind = getBindFromTextPos(textPos);
    if (markableBind == _bindVector.constEnd())
        return;
    auto markableText = (*markableBind).text;
    markableText->mark();
}

void Logic::unMarkBindFromSoundPos(qreal soundPos)
{
    auto markableBind = getBindFromSoundPos(soundPos);
    if (markableBind == _bindVector.constEnd())
        return;
    auto markableText = (*markableBind).text;
    markableText->unmark();
}

void Logic::unMarkBindFromTextPos(qint64 textPos)
{
    auto markableBind = getBindFromTextPos(textPos);
    if (markableBind == _bindVector.constEnd())
        return;
    auto markableText = (*markableBind).text;
    markableText->unmark();
}

qint32 Logic::moreOrLess(Bind bind, qreal soundPos, qint64 textPos) const
{
    SoundFragment::PTR soundFragment = bind.sound;
    TextFragment::PTR textFragment = bind.text;

    assert(isEquils(bind, zeroBind) == false);

    if (soundFragment->isBelongs(soundPos) || textFragment->isBelongs(textPos))
        return 0;

    // так как sound или text позиции могут быть трицательными используем это неравенство
    if (soundFragment->end() < soundPos || textFragment->end() < textPos)
        return -1;

    return 1;
}

bool Logic::isNormalBind(const QVector <Logic::Bind>::const_iterator bindIterator) const
{
    if (bindIterator == _bindVector.constEnd())
        return false;
    Bind bind = *bindIterator;
    auto bind_sound = bind.sound;
    auto bind_text = bind.text;
    if (bind_sound.isNull() || bind_text.isNull())
        return false;
    if (isEquils(bind, zeroBind))
        return false;
    return true;
}

QVector <Logic::Bind>::const_iterator Logic::getBindFromSoundOrTextPos(qreal soundPos, qint64 textPos) const
{
    if (_bindVector.empty())
        return _bindVector.constEnd();
    if (isNormalBind(_lastBindIterator) == false)
        return _bindVector.begin();

    assert (soundPos < 0 || textPos < 0);
    //auto cur = qLowerBound(data.begin(), data.end(), 3);

    // Проверяем последний и следующий за ним
    if (_lastBindIterator != _bindVector.constEnd())
    {
        Bind lastBind = (*_lastBindIterator);
        if (moreOrLess(lastBind, soundPos, textPos) == 0)
            return _lastBindIterator;
        auto nextBind = _lastBindIterator+1;
        if (isNormalBind(nextBind))
            if (moreOrLess(*nextBind, soundPos, textPos) == 0)
                return nextBind;
    }

    // Поведение за пределами размеченной облости
    qint32 endTextPos = _bindVector.back().text->end();
    if (textPos >= endTextPos)
        return _bindVector.constEnd()-1;
    qint32 endSoundPos = _bindVector.back().sound->end();
    if (soundPos >= endSoundPos)
        return _bindVector.constEnd()-1;

    // Ищем во всех
    auto lamdaLessThen = [soundPos, textPos, this](const Logic::Bind& left, const Logic::Bind& right)
    { // для понимания как работает лямда лучше взглянуть на реализацию qLowerBound
        auto realLeft = left;
        if (isEquils(realLeft, zeroBind))
            realLeft = right;
        else
            assert(isEquils(left, zeroBind) == false);;

        bool rez = false;
        if (moreOrLess(realLeft, soundPos, textPos) == -1)
            rez = true;
        else
            rez = false;

        if (isEquils(left, zeroBind))
            rez = !rez; // так как мы меняли левый с правым
        return rez;
    };
    auto founded = qLowerBound(_bindVector.constBegin(), _bindVector.constEnd(), zeroBind, lamdaLessThen);
    if (founded != _bindVector.constEnd())
        if (moreOrLess(*founded, soundPos, textPos) == 0)
            return founded;
    return _bindVector.constEnd();
}

QVector <Logic::Bind>::const_iterator Logic::getBindFromSoundPos(qreal soundPos) const
{
    return getBindFromSoundOrTextPos(soundPos, -1);
}

QVector <Logic::Bind>::const_iterator Logic::getBindFromTextPos(qint64 textPos) const
{
    // TODO проверить только при клике?
    return getBindFromSoundOrTextPos(-1, textPos);
}

qint64 Logic::roundToBindTextPos(qint64 textPos) const
{
    auto bind = getBindFromTextPos(textPos);
    if (bind == _bindVector.constEnd())
        return 0;
    auto text = (*bind).text;
    qint64 rez = text->begin();
    return rez;
}

qreal Logic::roundToBindSoundPos(qreal soundPos) const
{
    auto bind = getBindFromSoundPos(soundPos);
    if (bind == _bindVector.constEnd())
        return 0;
    auto sound = (*bind).sound;
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
    _title.clear();
    //curSoundFileName.clear();
   // curTextFileName.clear();
}

void Logic::tempMarkBindInTextPos(qint64 pos)
{
    //unMarkAllBindedText();
    unmarkLastBind();
    auto curBindIterator = getBindFromTextPos(pos);

    Bind curBind;
    if (curBindIterator == _bindVector.constEnd())
        if (_bindVector.empty())
            return;
        else
            curBindIterator = _bindVector.begin();
    curBind = *curBindIterator;
    if (curBind.sound.isNull() || curBind.text.isNull())
        return;
    _lastBindIterator = curBindIterator;
    markBind(curBind);
}

void Logic::markLastBind()
{
    if (_lastBindIterator != _bindVector.constEnd())
        markBind(*_lastBindIterator);
}

void Logic::unmarkLastBind()
{
    if (_lastBindIterator != _bindVector.constEnd() && _bindVector.empty() == false)
        unmarkBind(*_lastBindIterator);
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

void Logic::sortCommentName()
{
    sort(_commentsVector.begin(), _commentsVector.end(), [](const Comment& left, const Comment& right){
        auto leftText = left.commented;
        auto rightText = right.commented;
        return leftText->begin() < rightText->begin();
    });

    qint64 ID = 0;
    for (Comment& comment : _commentsVector)
    {
        QString stringID = QString().number(ID);
        comment.name = "comment_" + stringID;
        ID++;
    }
}

QUrl Logic::makeComment(Bind commentBind)
{
    auto text = commentBind.text;
    return makeComment(text);
}

QUrl Logic::makeComment(TextFragment::PTR text)
{
    QString uniqName = getUniqCommentName();
    QUrl commentUrl = QUrl::fromLocalFile(uniqName);
    Comment c;
    c.name = uniqName;
    c.commented = text;
    c.commentUrl = commentUrl;
    TextStore::PTR commentStore = TextStore::factoryMethod();
    commentStore->setFileUrl(commentUrl);
    commentStore->save();
    addInCommentList(c);
    sortCommentName();
    return commentUrl;
}

void Logic::save()
{
    writeInFile(_curBndFileName, _lastOpenedTextStore, _lastOpenedSoundStore);
}

void Logic::deleteAllComments()
{
    QStringList deleteList;
    for (Comment comment : _commentsVector)
        deleteList.push_back(comment.name);
    for (auto commentName : deleteList)
        deleteComment(commentName);
}

void Logic::deleteComment(const QString& name)
{
    auto deleted = find_if(_commentsVector.begin(), _commentsVector.end() , [name](const Comment& cur) {
        return cur.name == name;
    });
    assert(deleted != _commentsVector.end());
    QUrl deletedUrl = deleted->commentUrl;
    QFile::remove(deletedUrl.toLocalFile());
    _commentsVector.erase(deleted);
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

void Logic::markCommentWithName(const QString& name)
{
    //_lastOpenedTextStore->setTempFlag(true);
    unmarkBind(_commentBind);
    Comment curComment = getCommentWithName(name);
    auto commentText = curComment.commented;
    qint64 commentBegin = commentText->begin();
    qint64 commentEnd = commentText->end();
    auto beginBind = getBindFromTextPos(commentBegin);
    auto endBind = getBindFromTextPos(commentEnd);
    if (isNormalBind(beginBind) == false || isNormalBind(endBind) == false)
        return;
    auto beginText = beginBind->text;
    auto endText = endBind->text;
    auto beginSound = beginBind->sound;
    auto endSound = endBind->sound;

    qint64 textBegin = beginText->begin();
    qint64 textEnd = endText->end();
    qint64 soundBegin = beginSound->begin();
    qint64 soundEnd = endSound->end();

    TextFragment::PTR textMark = TextFragment::factoryMethod(textBegin, textEnd, _lastOpenedTextStore);
    SoundFragment::PTR soundMark = SoundFragment::factoryMethod(soundBegin, soundEnd, _lastOpenedSoundStore);
    Bind bindMark;
    bindMark.text = textMark;
    bindMark.sound = soundMark;
    QColor curMarkColor = _lastOpenedTextStore->getMarkColor();
    _lastOpenedTextStore->setMarkCalor(_commentMarkColor);
    _commentBind = bindMark;
    markBind(bindMark);
    _lastOpenedTextStore->setMarkCalor(curMarkColor);
    notAllowMarkBinds();
}

void Logic::unmarkCommentWithName(const QString& name)
{
    allowMarkBinds();
    unmarkBind(_commentBind);
 //   _lastOpenedTextStore->setTempFlag(false);
}

QVector <Logic::Bind>::const_iterator Logic::getBindOnTextPos(qint64 textPos)
{
    qint32 endPos = _bindVector.back().text->end();
    if (textPos >= endPos)
        return _bindVector.end() - 1;
    for (auto bind = _bindVector.begin(); bind != _bindVector.constEnd(); bind++)
    {
        auto curBind = *bind;
        auto curText = curBind.text;
        if (curText->begin() <= textPos && curText->end() >= textPos)
            return bind;
    }
    //auto defaultSound = _staticBindList.front().sound;
    return _bindVector.begin();
}

void Logic::markBind(const QList<Bind>& bindList)
{
    for (auto bind : bindList)
        markBind(bind);
}

void Logic::markBind(const Bind& bind)
{
    if (_f_notMarkBinds)
        return;
    auto text = bind.text;
    if (text.isNull())
        return;
    text->mark();
}

void Logic::unmarkBind(const Bind& bind)
{
    if (_f_notMarkBinds)
        return;
    auto text = bind.text;
    if (text.isNull())
        return;
    text->unmark();
}

void Logic::unmarkBind(const QList<Bind>& bindList)
{
    for (auto bind : bindList)
        unmarkBind(bind);
}

void Logic::createFromNewSoundFile(const QString& fileName, TextStore::PTR text, SoundStore::PTR sound)
{
    this->clear(true);
    QFileInfo fileInfo(fileName);
    assert(fileInfo.exists());
    QString base = fileInfo.path() + "/" + fileInfo.completeBaseName();
    QString htmlFileName = base + ".html";
    QString textFileName = base + ".txt";
    QString textSourceName;
    if (QFile::exists(textFileName))
        textSourceName = textFileName;
    else
        textSourceName = htmlFileName;

    QUrl soundUrl = QUrl::fromLocalFile(fileName);
    sound->setFileUrl(soundUrl);
    //QFile textTmp(textFileName);
    //textTmp.resize(0);
    //textTmp.close();
    QUrl textUrl = QUrl::fromLocalFile(textSourceName);
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
    unMarkAllBindedText(); // чтобы не сохранять выделения
    _lastBindIterator = _bindVector.constEnd();
    QString textStoreString;
    QString soundStoreString;
    QString textHashString;
    QString soundHashString;
    FileTypes type = getFileType(fileName);
    QString curPath = QFileInfo(fileName).absolutePath();
    if (type != FileTypes::binds)
    {
        qDebug() << "Incorrect output file name";
    }

    _curBndFileName = fileName;
    QFileInfo info(fileName);
    QString textFileName = info.path() + "/" + info.baseName() + ".html";
    QUrl textUrl = QUrl::fromLocalFile(textFileName);
    if (textStore.isNull() == false)
    {
        textStore->saveAs(textUrl, ".html");
        textStoreString = textStore->toString(curPath);
        textHashString = textStore->getHash();
        _lastOpenedTextStore = textStore;
    }
    if (soundStore.isNull() == false)
    {
        soundStoreString = soundStore->toString(curPath);
        soundHashString = soundStore->getHash();
        _lastOpenedSoundStore = soundStore;
    }

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly))
    {
        qDebug() << "File not open";
        return;
    }
    QTextStream fileStream(&file);
    _title = _title.trimmed();
    if (_title.length() == 0)
        _title = fileName;
    fileStream << par_Title << " " << _title << "\n";
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
        QString curStringBind = toString(curPath, comment);
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
    _title = QFileInfo(fileName).baseName();
    QTextStream fileStream(&file);
    QString par_buff;
    QString value_buff;
    while (!fileStream.atEnd())
    {
        fileStream >> par_buff;
        value_buff = fileStream.readLine();
        value_buff = value_buff.trimmed();
        if (par_buff == par_Bind)
            bindListString.push_back(value_buff);
        if (par_buff == par_Comment)
            commentListString.push_back(value_buff);
        else if (par_buff == par_RecognizedString)
            recognizedStrings.push_back(value_buff);
        else if (par_buff == par_SoundStore)
            soundStoreString = value_buff;
        else if (par_buff == par_SoundStoreHash)
            soundHashString = value_buff;
        else if (par_buff == par_TextStore)
            textStoreString = value_buff;
        else if (par_buff == par_TextStoreHash)
            textHashString = value_buff;
        else if (par_buff == par_Title)
            _title = value_buff;
    }
    _soundStoreString = soundStoreString;
    _textStoreString = textStoreString;

    QString realHashText;
    QString realHashSound;
    QString curPath = QFileInfo(fileName).absolutePath();
    if (textStore.isNull() == false)
    {
        textStore->setText("");
        textStore->fromString(textStoreString, curPath);
        realHashText = textStore->getHash();
    }
    _lastOpenedTextStore = textStore;
    if (soundStore.isNull() == false)
    {
        soundStore->fromString(soundStoreString, curPath);
        realHashSound = soundStore->getHash();
    }
    else
        soundStore = SoundStore::factoryMethod();
    _lastOpenedSoundStore = soundStore;
    if (SoundStore::isRemoteSource(soundStoreString))
        _curSoundStoreUrl = soundStoreString;
    else
    {
        QString curDir = QFileInfo(fileName).absolutePath();
        _curSoundStoreUrl = QUrl::fromLocalFile(curDir + "/" + soundStoreString);
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
        fromString(curPath, nextComment, commentString, textStore);
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

    if (_bindVector.empty())
        _lastBindIterator = _bindVector.constEnd();
    else
        _lastBindIterator = _bindVector.begin();
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

QString Logic::toString(QString curPath, const Comment& comment) const{
    QUrl url = comment.commentUrl;
    QString stringFileName = url.toLocalFile();
    QDir curDir = QDir(curPath);
    QString localUrlString = curDir.relativeFilePath(stringFileName);  //

    auto commented = comment.commented;
    qint64 textBegin = commented->begin();
    qint64 textEnd = commented->end();
    QString stringName = comment.name;

    QString rez;
    QTextStream outStream(&rez);
    outStream << localUrlString << " " << stringName << " "
              << textBegin << " " << textEnd;

    return rez;
}

void Logic::fromString(QString curPath, Comment& newComment, QString stringComment, TextStore::PTR text)
{
    QUrl url;
    QString name;
    qint64 begin;
    qint64 end;
    QString stringUrl;
    QTextStream sourceString(&stringComment);
    sourceString >> stringUrl >> name >> begin >> end;
    url = QUrl::fromLocalFile(curPath + "/" + stringUrl);

    auto commented = TextFragment::factoryMethod(begin, end, text);

    newComment.commented = commented;
    newComment.commentUrl = url;
    newComment.name = name;
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

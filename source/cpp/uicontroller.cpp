#include "uicontroller.h"

UIController::UIController(QObject *parent) : QObject(parent)
{
    _logic = Logic::factoryMethod();
    _f_reconizing = false;
    _f_home = true;
    QML_Settings s; // TODO Заменить на сигнальную архитектуру
    _examplesSize = s.exampleSize();
    _diffSize = s.exampleDiff();

    _sellectTimer.start();
    _curDir = QDir("eduEnReaderBase");
    _opening = false;    
    _someOpen = false;
    _curExampleWord = "Example";
}

void UIController::createAutoComments(qint32 autoCommentsNumber)
{
    _logic->createAutoComments(autoCommentsNumber);
}

QString UIController::curExampleWord() const
{
    return _curExampleWord;
}

void UIController::setCurExampleWord(const QString& newWord)
{
    _curExampleWord = newWord;
    emit curExampleWordChanged();
}

void UIController::setDocument(TextStore* TS) {
    _textStore =  TextStore::PTR(TS);
    QObject::connect(_textStore.data(), SIGNAL(cursorPositionChanged()), this, SLOT(cursorPosChanged()));
    // По скольку последовательность вызовов setDocument и setSoundStore заранее неизвестна
    if (_textStore.isNull() == false && _soundStore.isNull() == false)
        initAllProcesses();
}

void UIController::setSoundStore(SoundStore* TS) {
    _soundStore =  SoundStore::PTR(TS);
    QObject::connect(_soundStore.data(), SIGNAL(posChanged()), this, SLOT(setCursorPosInTimePos()));
    // По скольку последовательность вызовов setDocument и setSoundStore заранее неизвестна
    if (_textStore.isNull() == false && _soundStore.isNull() == false)
        initAllProcesses();
}

void UIController::stopAllThreads()
{
    _bindMaker->quit();
    if(!_bindMaker->wait(3000)) //Wait until it actually has terminated (max. 3 sec)
    {
        _bindMaker->terminate(); //Thread didn't exit in time, probably deadlocked, terminate it!
        _bindMaker->wait(); //We have to wait again here!
    }
    //_bindMaker->exit();
}

void UIController::save()
{
    _logic->save();
}

bool UIController::someOpen()
{
    return _someOpen;
}

void UIController::addTextInComment(const QString& commentName, const QString& text, const QColor& textColor)
{
    QUrl commentUrl = _logic->getCommentUrlsonName(commentName);
    TextStore::PTR tmpTextStore = TextStore::factoryMethod();
    tmpTextStore->setFileUrl(commentUrl);
    tmpTextStore->addTextForComment(text, textColor);
    tmpTextStore.clear();
}

QString UIController::title() const
{
    QString title = _logic->getTitle();
    return title;
}

void UIController::setTitle(const QString& newTitle)
{
    _logic->setTitle(newTitle);
}

QUrl UIController::curCommentUrl()
{
    return _curCommentUrl;
}

void UIController::setCurCommentUrl(const QUrl& newUrl)
{
    _curCommentUrl = newUrl;
    emit curCommentUrlChanged();
}

bool UIController::isDir(const QString& name) const
{
    if (_dirs.contains(name))
        return true;
    return false;
}

QDir UIController::getDir(const QString& name) const
{
    return _dirs.value(name);
}

void UIController::setCurDir(const QString& name)
{
    _curDir = _dirs.value(name);
    synchBndFileList();
}

void UIController::startSellectTimer()
{
    QString sellectedString = _textStore->getSellectedStreing();
    if (sellectedString.length()>0)
        _sellectTimer.start();
}

TextStore* UIController::getDocument()
{
    return _textStore.data();
}

SoundStore* UIController::getSoundStore()
{
    return _soundStore.data();
}

void UIController::saveHome(bool push)
{
    if (!_f_home && push == false)
        return;
    _soundStore->saveHome();
    _textStore->saveHome();
    _f_home = true;
}

void UIController::home(){
    _soundStore->home();
    _textStore->home();
    _f_home = true;
}


bool UIController::getMouseIsPressed() const
{
    return _mouseIsPressed;
}

void UIController::setMouseIsPressed(bool& newValue)
{
    _mouseIsPressed = newValue;
}

void UIController::synchTitle(const QString& bindFileName)
{
    QUrl url = _bindFile[bindFileName];
    QString title = _logic->getTitle(url);
    _bindTitles[bindFileName] = title.trimmed();
}

QString UIController::soundSource() const
{
    if (_soundStore.isNull())
        return QString("");
    QString curSource = _soundStore->fileUrl().toString();
    return curSource;
}

void UIController::setSoundSource(const QString& source)
{
   // QString curPath = QUrl::fromLocalFile(QDir::currentPath() + "/").toString();
    QString newSource = source;
    //if (source.indexOf(curPath) == 0)
    //    newSource = source.mid(curPath.length(), source.length() - curPath.length());
    //else
    //    newSource = source;
    QUrl newSourceUrl;
    if (SoundStore::isRemoteSource(newSource))
        newSourceUrl = QUrl(newSource);
    else
        newSourceUrl = QUrl::fromLocalFile(newSource);
    _soundStore->setFileUrl(QUrl(source));
}

void UIController::setPreviewForCurLecture(const QUrl& url)
{
    QString stringSourceUrl = url.toLocalFile();
    QString curBind = _logic->getCurBndFileName();
    QFileInfo sourceFileInfo = QFileInfo(stringSourceUrl);
    QString curExtention = sourceFileInfo.suffix();
    assert(curExtention=="jpeg");
    QFileInfo curBindInfo(curBind);
    QString newPeviewStringUrl = curBindInfo.absolutePath() + "/" + curBindInfo.baseName() + ".jpeg";
    QFile::copy(stringSourceUrl, newPeviewStringUrl);
}

// TODO Хранить в логике картинку?
QUrl UIController::getImageUrl(const QString& bindFile) const
{
    if (bindFile == ".")
        return _defaultUpDirPicture;
    QUrl bindUrl = _bindFile.value(bindFile);
    QString base = bindUrl.toLocalFile();
    QStringList splited = base.split('.');
    splited.pop_back();
    splited.push_back("jpeg");
    QString stringImageUrl = splited.join('.');
    if (QFile::exists(stringImageUrl) == false)
        if (isDir(bindFile))
            return _defaultDirPicture;
        else
            return _defaultLecturePicture;
    QUrl rezUrl = QUrl::fromLocalFile(stringImageUrl);
    return rezUrl;
}

QString UIController::getTitle(const QString &bindFile) const
{
    QString title = _bindTitles.value(bindFile);
    if (title == "")
        title = QFileInfo(bindFile).baseName();
    return title;
}

void UIController::synchBndFileList()
{
    //QDir curDir;
    QList <QFileInfo> bindInfoList;
    _bindFilesList.clear();
    _bindFilesList.clear();
    bindInfoList = _curDir.entryInfoList(QStringList("*.bnd"));
    for (auto bindInfo : bindInfoList)
    {
        QString filePath = bindInfo.absoluteFilePath();
        QUrl bindUrl = QUrl::fromLocalFile(filePath);
        QString name = bindInfo.baseName();
        _bindFile[name] = bindUrl;
        _bindFilesList.push_back(name);
        synchTitle(name);
    }
    auto lstDirs = _curDir.entryList(QDir::Dirs);
    for (auto dirString : lstDirs)
    {
        if (dirString == "." || dirString == "..")
            continue;
        dirString = _curDir.absolutePath() + "/" + dirString;
        QFileInfo dirInfo = QFileInfo(dirString);
        QString name = dirInfo.baseName();
        QDir dir = QDir(dirInfo.absoluteFilePath());
        _dirs[name] = dir;
        _bindFilesList.push_back(name);
    }
    QString backName = ".";
    QStringList buff = _curDir.absolutePath().split("/");
    buff.pop_back();
    QString rezPath = buff.join("/");
    if (rezPath != QDir().currentPath())
    {
        _dirs[backName] = rezPath;
        _bindFilesList.push_back(backName);
    }

    emit bindFilesListChanged();
}

QString UIController::curState() const
{
    return _curState;
}

void UIController::setCurState(const QString& newState)
{
    _curState = newState;
    emit curStateChanged();
}

QStringList UIController::getbindFilesList() const
{
    return _bindFilesList;
}

void UIController::setbindFilesList(const QStringList& newBindFiles)
{
    _bindFilesList = newBindFiles;
    emit bindFilesListChanged();
}

QStringList UIController::getMatirealsList() const
{
    return _matirealsList;
}

void UIController::setMatirealsList(const QStringList& newMatireals)
{
    _matirealsList = newMatireals;
    emit matirealsListChanged();
}

QStringList UIController::getExampleList() const
{
    return _exampleList;
}

void UIController::setExampleList(const QStringList& newExamples)
{
    _exampleList = newExamples;
    emit exampleListChanged();
}

QStringList UIController::getCommentList() const
{
    return _commentList;
}

void UIController::setCommentList(QStringList newComments)
{
    if (newComments.size() > 1)
    {
        QStringList doubleList;
        for (auto cur = newComments.begin() + 1; cur != newComments.end() ; cur++)
            for (auto prev = newComments.begin(); prev != cur; prev++)
                if (*prev == *cur)
                    doubleList.push_back(*prev);
        for (auto d : doubleList)
            newComments.removeOne(d);
    }
    _commentList = newComments;
    QString curCommentName;
    if (_commentList.empty() == false)
    {
        curCommentName = _commentList.front(); // TODO Возможно стоит оптимизировать
        setCurCommentUrl(_logic->getCommentUrlsonName(curCommentName));
    }
    else
        setCurCommentUrl(QUrl(""));
    emit commentListChanged();
}

TextFragment::PTR UIController::getSellectedText()
{
    qint64 begin = _textStore->selectionStart();
    qint64 end = _textStore->selectionEnd();
    auto rezFragment = TextFragment::factoryMethod(begin, end, _textStore);
    return rezFragment;
}

QUrl UIController::addComment()
{
    auto sellectedFragment = getSellectedText();
    auto commentUrl = _logic->makeComment(sellectedFragment);
    return commentUrl;
}

QUrl UIController::getMatirealUrlWithName(const QString& name) const
{
    QUrl matirealUrl = _matirealUrl.value(name.trimmed());
    return matirealUrl;
}

QUrl UIController::getBindFileUrlWithName(const QString& name) const
{
    QUrl bindFileUrl = _bindFile.value(name);
    return bindFileUrl;
}

void UIController::markComment(const QString& name)
{
    _logic->markCommentWithName(name);
}

void UIController::unmarkComment(const QString& name)
{
    _logic->unmarkCommentWithName(name);
}

QUrl UIController::getCommentUrlWithName(const QString &name) const
{
    QUrl commentUrl = _logic->getCommentUrlsonName(name);
    return commentUrl;
}

void UIController::deleteCommentWithName(const QString& name)
{
    _logic->deleteComment(name);
    synchCommentList();
}

void UIController::deleteBindWithName(const QString& name)
{
    QString bindName = getBindFileUrlWithName(name).toLocalFile();
    if (bindName.length() == 0)
        bindName = _dirs.value(name).absolutePath();
    assert(bindName.length() != 0);
    deleteBind(bindName);
}

void UIController::deleteBind(const QString& fileName)
{
    if (fileName.indexOf(".bnd") != -1)
    {
        assert(QFile().exists(fileName));
        Logic::PTR deletedLogic = Logic::factoryMethod();
        deletedLogic->readFromFile(fileName, nullptr, nullptr);
        deletedLogic->deleteAllFiles();
    }
    else
    {
        if (QDir(fileName).exists() == false)
        {
            if (QFile::exists(fileName))
                QFile::remove(fileName);
            return;
        }
        // Это директория
        auto allDirFiles = QDir(fileName).entryInfoList();
        for (auto file : allDirFiles)
        {
            QString baseName = file.baseName();
            if (baseName != "")
                deleteBind(file.absoluteFilePath());
        }
        QDir(fileName).removeRecursively();
    }
}

qint32 UIController::getMidMarkable() const
{
    qint32 rezPos = -1;
    if (_logic.isNull() == false)
        rezPos = _logic->getTextMidPosCurBind();
    if (rezPos < 0)
        return 0;
    return rezPos;
}

qint32 UIController::getBeginMarkable() const
{
    qint32 rezPos = _logic->getTextBeginPosCurBind();
    if (rezPos < 0)
        return 0;
    return rezPos;
}

qint32 UIController::getEndMarkable() const
{
    qint32 rezPos = _logic->getTextEndPosCurBind();
    if (rezPos < 0)
        return 0;
    return rezPos;
}

void UIController::playExample(QString ID)
{
    auto example = _example[ID];
    qreal begin = example.start;
    qreal end = example.end;
    QUrl url = example.realUrl;
    QString text = example.text;
    QString word = example.exampableWord;

    if (_f_home)
        saveHome();
    goOutHome();

    _soundStore->setFileUrl(url, begin, end);
    _soundStore->stop();
    _soundStore->start();
    _textStore->setText(text);
    _textStore->setWorldMark(word);
}

void UIController::getMatireals()
{
    QString sellectedString = _textStore->getSellectedStreing();
    getMatirealsFor(sellectedString);
}

void UIController::getMatirealsFor(QString seekablePhrase)
{
    _matirealsList.clear();
    seekablePhrase = seekablePhrase.toLower();
    auto patterns = _logic->getPatterns();
    for (Logic::Pattern p : patterns)
    {
        QUrl rezUrl;
        QString matirealString = _logic->getUrlFromPattern(p, seekablePhrase);
        if (p._type == Logic::file)
        {
            if (QFile::exists(matirealString) == false)
                continue;
            rezUrl = QUrl::fromLocalFile(matirealString);
        }
        if (p._type == Logic::webPlus)
            rezUrl = QUrl(matirealString);
        QString title = p._title.trimmed();
        _matirealsList.push_back(title);
        _matirealUrl[title] = rezUrl;
    }
    setMatirealsList(_matirealsList);
}

void UIController::getExample()
{
    QString sellectedString = _textStore->getSellectedStreing();
    getExamplesFor(sellectedString);
}

void UIController::getExamplesFor(const QString& seekablePhrase)
{
    if (seekablePhrase.length() == 0)
        return;
    _example.clear();
    _exampleList.clear();
    emit exampleListChanged();
    qreal minDuration = _examplesSize - _diffSize;
    qreal maxDuration = _examplesSize + _diffSize;
    auto exampleList = _logic->getExamples(seekablePhrase, minDuration, maxDuration, true);
    for (auto example : exampleList)
    {
        qreal begin = example.start;
        qreal end = example.end;
        qint32 minBegin = (qint32)begin/60;
        qint32 minEnd = (qint32)end/60;
        qint32 secBegin = (qint32)begin%60;
        qint32 secEnd = (qint32)end%60;
        QString beginString = QString().number(minBegin) + ":" + QString().number(secBegin);
        QString endString = QString().number(minEnd) + ":" + QString().number(secEnd);
        example.text = beginString + " " + example.text + " " + endString;
        QString newExampleName = QString().number(_exampleList.size()+1) + ":" + example.FileName;
                //+ " " + beginString;
                //+ "-" + endString;
        _exampleList .push_back(newExampleName);
        _example[newExampleName] = example;
    }
    setExampleList(_exampleList);
    if (_exampleList.empty() == false)
        setCurExampleWord(seekablePhrase);
}

void UIController::initAllProcesses()
{
    initBindMaker();
    initScripterProcess();
    initLogicReader();
}

void UIController::initScripterProcess()
{
    _scripterProcess = ScriptProcess::factoryMethod(_textStore, _soundStore, _logic);
    connect(_scripterProcess.data(), SIGNAL(stateChanged(QString)), this, SLOT(setCurState(QString)));
}

void UIController::initBindMaker()
{
    _bindMaker = TsBindingProcess::factoryMethod(_textStore, _soundStore, _logic);
    connect(_bindMaker.data(), SIGNAL(finished()), this, SLOT(handleNextOrFinish()));
    connect(_bindMaker.data(), SIGNAL(stateChanged(QString)), this, SLOT(setCurState(QString)));
}

void UIController::initLogicReader()
{
    _logicReader = BindOpenProcess::factoryMethod(_textStore, _soundStore, _logic);
   // connect(_logicReader.data(), SIGNAL(finished()), this, SLOT(openingFinished()));
}

void UIController::recognizeIsFinished()
{
    QString fileName = _logic->getCurBndFileName();
    _logic->bindLogicHanding();
    _logic->writeInFile(fileName, _textStore, _soundStore);
    _f_reconizing = false;
}

void UIController::openingFinished()
{
    saveHome(true);
    _opening = false;
    emit titleChanged();
    emit soundSourceChanged();
}

void UIController::setCursorPosInTimePos()
{
    if (_f_home == false)
        return;

    qreal timePos = _soundStore->getTimePos();
    qint64 textPos = _logic->posInWavToPosInText(timePos);
    if (textPos >= 0)
        _textStore->setCursorPosition(textPos+1);
}

void UIController::setTimePosInCursorPos()
{
    if (_f_home == false || canNotSync() || _mouseIsPressed)
        return;

    qint64 textPos = _textStore->cursorPosition();
    qreal newSoundPos = _logic->posInTxtToPosInWav(textPos);

    qreal curSoundPos = _soundStore->getTimePos();
    qreal roundedCurSoundPos = _logic->roundToBindSoundPos(curSoundPos);
    qreal roundedNewSoundPos = _logic->roundToBindSoundPos(newSoundPos);
    if (abs(roundedCurSoundPos - roundedNewSoundPos) < 0.1 || roundedNewSoundPos == -1)
        return;
    if (newSoundPos >= 0)
        _soundStore->setPosReal(newSoundPos);
}

// TODO Добавить работу с выделением
void UIController::synchCommentList()
{
    qint64 cursorPos = _textStore->cursorPosition();
    auto sellection = getSellectedText();
    QList <QString> newComments;
    if (sellection->size()!=0)
        newComments = _logic->getCommentNamesonTextPos(sellection);
    else
        newComments = _logic->getCommentNamesonTextPos(cursorPos);
    setCommentList(newComments);
}

void UIController::cursorPosChanged()
{
    if (_f_home == false)
        return;
    markCurText();
    synchCommentList();
}

void UIController::markCurText()
{
    if (_f_home == false)
        return;
    qint64 cursorPos = _textStore->cursorPosition();
    if (cursorPos < 0)
        return;
    //_textStore->setAllUnMarkText(); // Костыль от глюка старого TextArea с не всегда устанвливаемым фоном, если возникнет вновь вернуть
    if (_logic.isNull())
        return;
    _logic->tempMarkBindInTextPos(cursorPos);
}

void UIController::markLastText()
{
    _logic->markLastBind();
}

void UIController::unmarkLastText()
{
    _logic->unmarkLastBind();
}

void UIController::createBindFile(const QUrl &soundFileName)
{
    QString fileName = soundFileName.toLocalFile();
    _logic->createFromNewSoundFile(fileName, _textStore, _soundStore);
}

void UIController::openBindFile(const QUrl &arg)
{
    if (_opening)
        return;
    _opening = true;
    setCurCommentUrl(QUrl(""));
    QString fileName = arg.toLocalFile();
    qDebug() << fileName;
    _logic->readFromFile(fileName, _textStore, _soundStore);
    saveHome(true);
    _logic->unMarkAllBindedText();
    _opening = false;
    emit titleChanged();
    emit soundSourceChanged();
    //_waitToOpen = "";
}

void UIController::saveBindFile(const QUrl &arg)
{
    QString fileName = arg.toLocalFile();
    _logic->writeInFile(fileName, _textStore, _soundStore);
}

QString UIController::formUrlToTranslateSellected()
{
    QString rezUrl = _baseTranslateURL;
    QString sellectedString = _textStore->getSellectedStreing();
    auto splitedSellectedString = sellectedString.split(" ", QString::SkipEmptyParts);
    QString handledSellectedString = splitedSellectedString.join("+");
    rezUrl += handledSellectedString;
    return rezUrl;
}

void UIController::handleNextOrFinish()
{
    _f_bindSequnceProcess[_curBinding] = true;
    QStringList::Iterator nextVideoIterator = find_if(_bindSiqence.begin(), _bindSiqence.end(), [this](const QString& curFile){
        if (_f_bindSequnceProcess.value(curFile) == false)
            return true;
    });
    if (nextVideoIterator == _bindSiqence.end())
    {
        QString endState = _bindMaker->endState;
        setCurState(endState);
        if (_bindSiqence.size() == 1)
        {
            QString fileName = _bindSiqence.front();
            _logic->readFromFile(fileName, _textStore, _soundStore);
        }
        return;
    }
    QString nextVideoString = *nextVideoIterator;
    _curBinding = nextVideoString;
    _bindMaker->setFileName(nextVideoString);
    _bindMaker->start();
    emit curStateChanged();
}

QString UIController::getCurStateBindSequnce()
{
    QString curState;
    QTextStream rezState(&curState);
    qint32 compliteNumber = count_if(_bindSiqence.begin(), _bindSiqence.end(), [this](const QString& cur){
        if (_f_bindSequnceProcess.value(cur) == true)
            return true;
        return false;
    });
    qint32 allNumber = _bindSiqence.size();
    if (allNumber == 0)
        allNumber = 1;
    qreal complitePersen = (qreal)compliteNumber / (qreal)allNumber;
    if (allNumber == compliteNumber)
        return _bindMaker->endState;
    rezState << "Full complite persent : " << complitePersen;
    return curState;
}

void UIController::initBindingSequence(bool forAll)
{
    _bindSiqence.clear();
    _f_bindSequnceProcess.clear();
    if (forAll == false)
    {
        QString curLogic = _logic->getCurBndFileName();
        assert(QFile::exists(curLogic));
        _bindSiqence.push_back(curLogic);
        _f_bindSequnceProcess[curLogic] = false;
        return;
    }
    QString stringBindLocation = Settings::get(Settings::BindLocation, Settings::Location).toString();
    QDir dirBindLocation = QDir(stringBindLocation);
    QStringList videos;
    _logic->getAllFiles(videos, dirBindLocation, QStringList("*.mp4"));
    for (auto videoFileString : videos)
    {
        QFileInfo videoFileInfo = QFileInfo(videoFileString);
        QString outBindName = videoFileInfo.absolutePath() + "/" + videoFileInfo.baseName() + ".bnd";
        if (QFile::exists(outBindName))
            continue;
        QString bindPretendent = videoFileInfo.absoluteFilePath();
        _bindSiqence.push_back(bindPretendent);
        _f_bindSequnceProcess[bindPretendent] = false;
    }
}

void UIController::downloadBase()
{
    _scripterProcess->setExecuteScript(Scripter::_downloadBaseScript);
    _scripterProcess->start();
}

void UIController::uploadBase()
{
    _scripterProcess->setExecuteScript(Scripter::_uploadBaseScript);
    _scripterProcess->start();
}

void UIController::tsBinding(bool forAll)
{
    QString curState = getCurStateBindSequnce();
    setCurState(curState);
    initBindingSequence(forAll);
    startTsBinging();
}

void UIController::curTsBinding()
{
    _bindMaker->useCurLogic(true);
    tsBinding(false);
}

void UIController::allTsBinding()
{
    _bindMaker->useCurLogic(false);
    tsBinding(true);
}

void UIController::startTsBinging()
{
    if (_bindSiqence.empty())
    {
        handleNextOrFinish();
        return;
    }
    QString firstFile = _bindSiqence.front();
    _bindMaker->setFileName(firstFile);
    _curBinding = firstFile;
    _bindMaker->start();
}

void UIController::allStBinding()
{

}

void UIController::curUserStBinding(){

}

void UIController::makeBind()
{
    //QUrl soundUrl = QUrl::fromLocalFile("/home/gva-error/eduEnReader/eduEnReader/tests/test.wav");
    //QUrl textUrl = QUrl::fromLocalFile("/home/gva-error/eduEnReader/eduEnReader/tests/test.txt");
    //_textStore->setFileUrl(textUrl);
    //_soundStore->setFileUrl(soundUrl);

//    _bindMaker->runInThisThread();
//    _logic->bindLogicHanding();
//    _logic->writeInFile(_textStore, _soundStore);

//    return;

//    if (_f_reconizing)
//        return;

//    QFile file("Log.txt");

//    file.open(QFile::WriteOnly);
//    QTextStream fileStream(&file);
//    QTime curTime;
//    fileStream << "Begin binding time: " << curTime.toString();

//    _f_reconizing = true;
//    QDir curDir;
//    QStringList bindFiles = curDir.entryList(QStringList("*.mp4"));
//    for (QString mp4 : bindFiles)
//    {
//        QUrl url = QUrl::fromLocalFile(mp4);
//        fileStream << "File " << url.toString() << " begin: " << curTime.toString();
//        createBindFile(url);
//        //BindMaker bm(_textStore, _soundStore, _logic);
//        _bindMaker->setSplitSize(5.0f, 3.0f);
//        _bindMaker->runInThisThread();
//       // _logic->bindLogicHanding();
//        _logic->writeInFile(_textStore, _soundStore);
//        fileStream << "File " << url.toString() << " end: " << curTime.toString();
//       // break;
//    }

//    _f_reconizing = false;
//    fileStream << "End binding time: " << curTime.toString();

assert(false);
    //_transliter.loadTranslation("");

//    _logic->bindLogicHanding();
//    _logic->markAllBindedText();
//    _logic->writeInFile("test.bnd", _textStore, _soundStore);

    //_logic->readFromFile("/home/gva-error/eduEnReader/eduEnReader/tests/1.bnd", _textStore, _soundStore);
   // _logic->markAllBindedText();
/*
    QDir testDir = QDir("/home/gva-error/eduEnReader/eduEnReader/tests");
    QStringList wavs = testDir.entryList(QStringList("*.wav"));
    for (auto wav : wavs)
    {
        wav = "/home/gva-error/eduEnReader/eduEnReader/tests/" + wav;
        QUrl soundUrl = QUrl::fromLocalFile(wav);
        QString txt = wav;
        int l = txt.length();
        txt[l-3] = 't';
        txt[l-2] = 'x';
        txt[l-1] = 't';
        QUrl textUrl = QUrl::fromLocalFile(txt);
        _textStore->setFileUrl(textUrl);
        _soundStore->setFileUrl(soundUrl);
        BindMaker bm(_textStore, _soundStore, _logic);
        bm.preparetion(5.0f);
        bm.binding();

        QString bnd = txt;
        bnd[l-3] = 'b';
        bnd[l-2] = 'n';
        bnd[l-1] = 'd';
        _logic->writeInFile(bnd.toLatin1(), _textStore, _soundStore);
    }

    _logic->readFromFile("outTest.bnd", _textStore, _soundStore);
  */  //auto recognizedStrings = _logic->getRecognizedStrings();
  /*  BindMaker bm(_textStore, _soundStore, _logic);
    bm.preparetion(5.0f);
    bm.binding();
*/
   //_logic->markAllBindedText();

   // _logic->writeInFile("outTest.bnd", _textStore, _soundStore);

    //  QUrl soundUrl = QUrl::fromLocalFile("/home/gva-error/eduEnReader/eduEnReader/test.wav");
  // QString str = soundUrl.toString();
   //QUrl newUrl = QUrl(str);
   //_soundStore->setFileUrl(newUrl);


//
//    BindMaker bm(_textStore, _soundStore, _logic);
//    bm.preparetion(7);
//    bm.binding();
}

void UIController::openSoundFile(const QString &fileName)
{
    _soundStore->setFileUrl(fileName);
}

void UIController::setSellectionText(TextFragment::PTR t)
{
    if (_f_home == false)
        return;
    setSellectionText(t->begin(), t->end());
}

void UIController::setSellectionText(qint64 begin, qint64 end)
{
    if (_f_home == false)
        return;
    _textStore->setSelectionEnd(end);
    _textStore->setSelectionStart(begin);
}

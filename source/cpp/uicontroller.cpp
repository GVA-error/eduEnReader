#include "uicontroller.h"

UIController::UIController(QObject *parent) : QObject(parent)
{
    _logic = Logic::factoryMethod();
    _f_reconizing = false;
    _f_home = true;
    _examplesSize = 30;
    _diffSize = 30;
   // _exampleList.push_back("1");
   // _exampleList.push_back("2");

    //connect(this, SIGNAL(textSellectionChanged()), this, SLOT(startSellectTimer()));
    _sellectTimer.start();
}

void UIController::setDocument(TextStore* TS) {
    _textStore =  TextStore::PTR(TS);
    QObject::connect(_textStore.data(), SIGNAL(cursorPositionChanged()), this, SLOT(cursorPosChanged()));
    // По скольку последовательность вызовов setDocument и setSoundStore пишу так
    if (_textStore.isNull() == false && _soundStore.isNull() == false)
        initBindMaker(_textStore, _soundStore, _logic);
}

void UIController::setSoundStore(SoundStore* TS) {
    _soundStore =  SoundStore::PTR(TS);
    QObject::connect(_soundStore.data(), SIGNAL(posChanged()), this, SLOT(setCursorPosInTimePos()));
    // По скольку последовательность вызовов setDocument и setSoundStore пишу так
    if (_textStore.isNull() == false && _soundStore.isNull() == false)
        initBindMaker(_textStore, _soundStore, _logic);
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

void UIController::saveHome()
{
    if (!_f_home)
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
    return mouseIsPressed;
}

void UIController::setMouseIsPressed(bool& newValue)
{
    mouseIsPressed = newValue;
}

void UIController::synchBndFileList()
{
    QDir curDir;
    QList <QFileInfo> bindInfoList;
    _bindFilesList.clear();
    _bindFilesList.clear();
    bindInfoList = curDir.entryInfoList(QStringList("*.bnd"));
    for (auto bindInfo : bindInfoList)
    {
        QString filePath = bindInfo.absoluteFilePath();
        QUrl bindUrl = QUrl::fromLocalFile(filePath);
        QString name = bindInfo.baseName();
        _bindFile[name] = bindUrl;
        _bindFilesList.push_back(name);
    }
    emit bindFilesListChanged();
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
    emit commentListChanged();
}

TextFragment::PTR UIController::getSellectedText()
{
    qint64 begin = _textStore->selectionStart();
    qint64 end = _textStore->selectionEnd();
    auto rezFragment = TextFragment::factoryMethod(begin, end, _textStore);
    return rezFragment;
}

void UIController::addComment(const QUrl& commentUrl, const QString &name)
{
    auto sellectedFragment = getSellectedText();
    _logic->makeComment(sellectedFragment, commentUrl, name);
}

QUrl UIController::getBindFileUrlWithName(const QString& name) const
{
    QUrl bindFileUrl = _bindFile.value(name);
    return bindFileUrl;
}

QUrl UIController::getCommentUrlWithName(const QString &name) const
{
    QUrl commentUrl = _logic->getCommentUrlsonName(name);
    return commentUrl;
}

qint32 UIController::getMidMarkable() const
{
    qint32 rezPos = _logic->getTextMidPosCurBind();
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
    _soundStore->start();
    _textStore->setText(text);
    _textStore->setWorldMark(word);
}

void UIController::getExample()
{
    QString sellectedString = _textStore->getSellectedStreing();
    getExamplesFor(sellectedString);
}

void UIController::getExamplesFor(const QString& seekablePhrase)
{
    // TODO УБРАТЬ!!!
    //makeBind();

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
}

void UIController::initBindMaker(TextStore::PTR text, SoundStore::PTR sound, Logic::PTR logic)
{
    _bindMaker = BindMaker::factoryMethod(text, sound, logic);
    connect(_bindMaker.data(), SIGNAL(finished()), this, SLOT(recognizeIsFinished()));
}

void UIController::recognizeIsFinished()
{
    QString fileName = _logic->getCurBndFileName();
    _logic->bindLogicHanding();
    _logic->writeInFile(fileName, _textStore, _soundStore);
    _f_reconizing = false;
}

void UIController::setCursorPosInTimePos()
{
    if (_f_home == false)
        return;

    qreal timePos = _soundStore->getTimePos();
    qint64 textPos = _logic->posInWavToPosInText(timePos);
    if (textPos >= 0)
        _textStore->setCursorPosition(textPos);
}

void UIController::setTimePosInCursorPos()
{
    if (_f_home == false || canNotSync())
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

void UIController::cursorPosChanged()
{
    if (_f_home == false)
        return;
    qint64 cursorPos = _textStore->cursorPosition();
    markCurText();
    auto newComments = _logic->getCommentNamesonTextPos(cursorPos);
    setCommentList(newComments);
    setTimePosInCursorPos();
}

void UIController::markCurText()
{
    if (_f_home == false)
        return;
    qint64 cursorPos = _textStore->cursorPosition();
    if (cursorPos <= 0)
        return;
    _textStore->setAllUnMarkText(); // Костыль от глюка TextArea с не всегда устанвливаемым фоном
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
    QString fileName = arg.toLocalFile();
    qDebug() << fileName;
    _logic->readFromFile(fileName, _textStore, _soundStore);
    saveHome();
    _logic->unMarkAllBindedText();
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

void UIController::makeBind()
{
    //QUrl soundUrl = QUrl::fromLocalFile("/home/gva-error/eduEnReader/eduEnReader/tests/test.wav");
    //QUrl textUrl = QUrl::fromLocalFile("/home/gva-error/eduEnReader/eduEnReader/tests/test.txt");
    //_textStore->setFileUrl(textUrl);
    //_soundStore->setFileUrl(soundUrl);

    //auto examples = _logic->getExamples(QString("swi"), true);
    //_bindMaker->start();
    //_logic->bindLogicHanding();
 //  _bindMaker->setSplitSize(5.0f, 3.0f);
  //  _bindMaker->runInThisThread();
  //  _logic->bindLogicHanding();
    _logic->writeInFile(_textStore, _soundStore);
    return;

//    DataPreparation p;
//    p.extractAudio("A2.mp4");
//    p.noiseReduse("A2.wav");

//    return;

    if (_f_reconizing)
        return;

    QFile file("Log.txt");

    file.open(QFile::WriteOnly);
    QTextStream fileStream(&file);
    QTime curTime;
    fileStream << "Begin binding time: " << curTime.toString();

    _f_reconizing = true;
    QDir curDir;
    QStringList bindFiles = curDir.entryList(QStringList("*.mp4"));
    for (QString mp4 : bindFiles)
    {
        QUrl url = QUrl::fromLocalFile(mp4);
        fileStream << "File " << url.toString() << " begin: " << curTime.toString();
        createBindFile(url);
        //BindMaker bm(_textStore, _soundStore, _logic);
        _bindMaker->setSplitSize(5.0f, 3.0f);
        _bindMaker->start();
        fileStream << "File " << url.toString() << " end: " << curTime.toString();
        break;
    }

    fileStream << "End binding time: " << curTime.toString();


    return;


    if (_f_reconizing)
        return;
    //BindMaker bm(_textStore, _soundStore, _logic);
    _bindMaker->setSplitSize(5.0f, 3.0f);
    _bindMaker->start();
    _f_reconizing = true;

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

#include "uicontroller.h"

UIController::UIController(QObject *parent) : QObject(parent)
{
    _logic = Logic::factoryMethod();
    _f_reconizing = false;
    _f_home = true;
   // _exampleList.push_back("1");
   // _exampleList.push_back("2");
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
    _soundStore->saveHome();
    _textStore->saveHome();
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

void UIController::addComment(const QUrl& commentUrl)
{
    auto sellectedFragment = getSellectedText();
    _logic->makeComment(sellectedFragment, commentUrl);
}

QUrl UIController::getCommentUrlWithName(const QString &name) const
{
    QUrl commentUrl = _logic->getCommentUrlsonName(name);
    return commentUrl;
}

void UIController::playExample(QString ID)
{
    auto example = _example[ID];
    qreal begin = example.start;
    qreal end = example.end;
    QUrl url = example.realUrl;
    QString text = example.text;

    if (_f_home)
        saveHome();

    _f_home = false;
    _soundStore->setFileUrl(url, begin, end);
    _soundStore->start();
    _textStore->setText(text);
}

void UIController::getExamplesFor(const QString& seekablePhrase)
{
    _example.clear();
    _exampleList.clear();
    emit exampleListChanged();
    auto exampleList = _logic->getExamples(seekablePhrase, true);
    for (auto example : exampleList)
    {
        qreal begin = example.start;
        qreal end = example.end;
        QString newExampleName = example.FileName
                + " " + QString().number(begin)
                + " " + QString().number(end);
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
        _textStore->setCursorPosition(textPos + 1); // Чтобы не сбивалось окно при округлении
}

void UIController::setTimePosInCursorPos()
{
    if (_f_home == false)
        return;
    qint64 textPos = _textStore->getCursorPos();
    qreal newSoundPos = _logic->posInTxtToPosInWav(textPos);

    qreal curSoundPos = _soundStore->getTimePos();
    qreal roundedCurSoundPos = _logic->roundToBindSoundPos(curSoundPos);
    qreal roundedNewSoundPos = _logic->roundToBindSoundPos(newSoundPos);
    if (abs(roundedCurSoundPos - roundedNewSoundPos) < 0.1 || roundedNewSoundPos == -1)
        return;
    _soundStore->setPosReal(newSoundPos);
}

void UIController::cursorPosChanged()
{
    if (_f_home == false)
        return;
    qint64 cursorPos = _textStore->getCursorPos();
    if (cursorPos <= 0)
        return;
    _logic->tempMarkBindInTextPos(cursorPos);
    auto newComments = _logic->getCommentNamesonTextPos(cursorPos);
    setCommentList(newComments);
    setTimePosInCursorPos();
}

void UIController::createBindFile(const QUrl &soundFileName)
{
    QString fileName = soundFileName.toLocalFile();
    _logic->createFromNewSoundFile(fileName, _textStore, _soundStore);
}

void UIController::openBindFile(const QUrl &arg)
{
    QString fileName = arg.toLocalFile();
    _logic->readFromFile(fileName, _textStore, _soundStore);
    saveHome();
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

void UIController::getExample()
{
    QString sellectedString = _textStore->getSellectedStreing();
    getExamplesFor(sellectedString);
}

void UIController::makeBind()
{
    //QUrl soundUrl = QUrl::fromLocalFile("/home/gva-error/eduEnReader/eduEnReader/tests/test.wav");
    //QUrl textUrl = QUrl::fromLocalFile("/home/gva-error/eduEnReader/eduEnReader/tests/test.txt");
    //_textStore->setFileUrl(textUrl);
    //_soundStore->setFileUrl(soundUrl);

    //auto examples = _logic->getExamples(QString("swi"), true);

    //_logic->bindLogicHanding();
   // return;

//    DataPreparation p;
//    p.extractAudio("A2.mp4");
//    p.noiseReduse("A2.wav");

//    return;


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
    _textStore->setSelectionStart(begin);
    _textStore->setSelectionEnd(end);
}

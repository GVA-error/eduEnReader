#include "uicontroller.h"

UIController::UIController(QObject *parent) : QObject(parent)
{
    _logic = Logic::factoryMethod();
    _f_reconizing = false;
   // _exampleList.push_back("1");
   // _exampleList.push_back("2");
}

void UIController::playExample(QString ID)
{
    auto example = _example[ID];
    qreal begin = example.start;
    qreal end = example.end;
    QUrl url = example.realUrl;
    _soundStore->setFileUrl(url, begin, end);
    _soundStore->start();
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
    qreal timePos = _soundStore->getTimePos();
    qint64 textPos = _logic->posInWavToPosInText(timePos);
    if (textPos >= 0)
        _textStore->setCursorPosition(textPos + 1); // Чтобы не сбивалось окно при округлении
}

void UIController::setTimePosInCursorPos()
{
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
    qint64 cursorPos = _textStore->getCursorPos();
    if (cursorPos <= 0)
        return;
    _logic->tempMarkBindInTextPos(cursorPos);
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
    _soundStore->saveCurState();
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

void UIController::openSoundFile(QString fileName)
{
    _soundStore->setFileUrl(fileName);
}

void UIController::setSellectionText(TextFragment::PTR t)
{
    setSellectionText(t->begin(), t->end());
}

void UIController::setSellectionText(qint64 begin, qint64 end)
{
    _textStore->setSelectionStart(begin);
    _textStore->setSelectionEnd(end);
}

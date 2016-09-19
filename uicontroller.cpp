#include "uicontroller.h"

UIController::UIController(QObject *parent) : QObject(parent)
{
    _logic = Logic::factoryMethod();
    _soundStore = SoundStore::factoryMethod();
    newXSoundPos = oldXSoundPos = 0;
   // _textStore = TextStore::factoryMethod();
}

void UIController::makeBind()
{
    auto textFragment = getSellectedText();
    auto soundFragment = getSellectedSound();
    QString curText = textFragment->getString();
    _logic->bind(textFragment, soundFragment);
}

void UIController::openSoundFile(QString fileName)
{
    _soundStore->readFile(fileName);
}

void UIController::clickedOnText()
{
    qint64 cursorPos = _textStore->selectionStart();
    if (cursorPos <= 0)
        return;
    auto sound = _logic->getBindedSound(cursorPos);
    //if (sound->getSampleNumber() > 0)
        setSellectionSound(sound);
}

SoundFragment::PTR UIController::getSellectedSound()
{
    auto xLeft = oldXSoundPos < newXSoundPos ? oldXSoundPos : newXSoundPos;
    auto xRight = oldXSoundPos >= newXSoundPos ? oldXSoundPos : newXSoundPos;

    auto rezFragment = SoundFragment::factoryMethod(xLeft, xRight, _soundStore);
    return rezFragment;
}

TextFragment::PTR UIController::getSellectedText()
{
    auto sellectionTextBegin = _textStore->selectionStart();
    auto sellectionTextEnd = _textStore->selectionEnd();
    auto xLeft = sellectionTextBegin < sellectionTextEnd ? sellectionTextBegin : sellectionTextEnd;
    auto xRight = sellectionTextBegin >= sellectionTextEnd ? sellectionTextBegin : sellectionTextEnd;

    auto rezFragment = TextFragment::factoryMethod(xLeft, xRight, _textStore);
    return rezFragment;
}

void UIController::setSellectionSound(SoundFragment::PTR s)
{
    setSellectionSound(s->begin(), s->end());
}

void UIController::setSellectionText(TextFragment::PTR t)
{
    setSellectionText(t->begin(), t->end());
}

void UIController::setSellectionSound(qint32 begin, qint32 end)
{
    setNewXSoundPos(end);
    setOldXSoundPos(begin);
}

void UIController::setSellectionText(qint64 begin, qint64 end)
{
    _textStore->setSelectionStart(begin);
    _textStore->setSelectionEnd(end);
}

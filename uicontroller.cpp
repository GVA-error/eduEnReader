#include "uicontroller.h"

UIController::UIController(QObject *parent) : QObject(parent)
{
    _logic = Logic::factoryMethod();
    _soundStore = SoundStore::factoryMethod();
    _textStore = TextStore::factoryMethod();
}

void UIController::makeBind()
{
    auto textFragment = getSellectedText();
    auto soundFragment = getSellectedSound();
    _logic->bind(textFragment, soundFragment);
}

void UIController::openSoundFile(QString fileName)
{
    _soundStore->readFile(fileName);
}

void UIController::clickedOnText()
{

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
    auto xLeft = oldXTextPos < newXTextPos ? oldXTextPos : newXTextPos;
    auto xRight = oldXTextPos >= newXTextPos ? oldXTextPos : newXTextPos;

    auto rezFragment = TextFragment::factoryMethod(xLeft, xRight, _textStore);
    return rezFragment;
}

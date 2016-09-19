#include "uicontroller.h"

UIController::UIController(QObject *parent) : QObject(parent)
{
    _logic = Logic::factoryMethod();
    _soundStore = SoundStore::factoryMethod();
}

void UIController::binding()
{
//    auto xLeftText = oldXTextPos < newXTextPos ? oldXTextPos : newXTextPos;
//    auto xRightText = oldXTextPos >= newXTextPos ? oldXTextPos : newXTextPos;

//    auto xLeftSound = oldXSoundPos < newXSoundPos ? oldXSoundPos : newXSoundPos;
//    auto xRightSound = oldXSoundPos >= newXSoundPos ? oldXSoundPos : newXSoundPos;

//    auto sound = SoundFragment::factoryMethod(_soundStore, xLeftSound, xRightSound);
//    auto text = TextFragment::factoryMethod(_textStore, xLeftText, xRightText);


}

void UIController::openSoundFile(QString fileName)
{
    _soundStore->readFile(fileName);
}

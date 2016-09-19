#ifndef UIController_H
#define UIController_H

#include <QObject>
#include "logic.h"
#include "soundstore.h"
#include "textstore.h"
#include "soundfragment.h"
#include "textfragment.h"

class UIController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 oldXSoundPos READ getOldXSoundPos WRITE setOldXSoundPos)
    Q_PROPERTY(qint32 newXSoundPos READ getNewXSoundPos WRITE setNewXSoundPos)
    Q_PROPERTY(qint32 oldXTextPos READ getOldXTextPos WRITE setOldXTextdPos)
    Q_PROPERTY(qint32 newXTextPos READ getNewXTextPos WRITE setNewXTextPos)
    Q_PROPERTY(bool mouseIsPressed READ getMouseIsPressed WRITE setMouseIsPressed)
public:
    explicit UIController(QObject *parent = 0);

    qint32 newXSoundPos;
    qint32 getNewXSoundPos() const {return newXSoundPos;}
    qint32 setNewXSoundPos(qint32& newValue) { newXSoundPos = newValue;}
    qint32 oldXSoundPos;
    qint32 getOldXSoundPos() const { return oldXSoundPos; }
    qint32 setOldXSoundPos(qint32& newValue) { oldXSoundPos = newValue;}

    qint32 newXTextPos;
    qint32 getNewXTextPos() const {return newXTextPos;}
    qint32 setNewXTextPos(qint32& newValue) { newXTextPos = newValue;}
    qint32 oldXTextPos;
    qint32 getOldXTextPos() const { return oldXTextPos; }
    qint32 setOldXTextdPos(qint32& newValue) { oldXTextPos = newValue;}

    bool mouseIsPressed;
    bool getMouseIsPressed() const {return mouseIsPressed;}
    bool setMouseIsPressed(bool& newValue) { mouseIsPressed = newValue;}

signals:

public slots:

    void binding();
    void openSoundFile(QString fileName);
private:

    Logic::PTR _logic;
    SoundStore::PTR _soundStore;

};

#endif // UIController_H

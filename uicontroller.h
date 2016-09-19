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
    Q_PROPERTY(qint32 oldXSoundPos READ getOldXSoundPos WRITE setOldXSoundPos NOTIFY soundSellectionChanged)
    Q_PROPERTY(qint32 newXSoundPos READ getNewXSoundPos WRITE setNewXSoundPos NOTIFY soundSellectionChanged)
    //Q_PROPERTY(qint32 oldXTextPos READ getOldXTextPos WRITE setOldXTextdPos NOTIFY textSellectionChanged)
    //Q_PROPERTY(qint32 newXTextPos READ getNewXTextPos WRITE setNewXTextPos NOTIFY textSellectionChanged)
    Q_PROPERTY(TextStore* document WRITE setDocument)
    Q_PROPERTY(bool mouseIsPressed READ getMouseIsPressed WRITE setMouseIsPressed)
public:
    explicit UIController(QObject *parent = 0);

    qint32 newXSoundPos;
    qint32 getNewXSoundPos() const {return newXSoundPos;}
    void setNewXSoundPos(qint32& newValue) {
        newXSoundPos = newValue;
        emit soundSellectionChanged();
    }
    qint32 oldXSoundPos;
    qint32 getOldXSoundPos() const { return oldXSoundPos; }
    void setOldXSoundPos(qint32& newValue) {
        oldXSoundPos = newValue;
        emit soundSellectionChanged();
    }

 /*
  * qint32 newXTextPos;
    qint32 getNewXTextPos() const {return newXTextPos;}
    void setNewXTextPos(qint32& newValue) { newXTextPos = newValue;}
    qint32 oldXTextPos;
    qint32 getOldXTextPos() const { return oldXTextPos; }
    void setOldXTextdPos(qint32& newValue) { oldXTextPos = newValue;}
*/
    bool mouseIsPressed;
    bool getMouseIsPressed() const {return mouseIsPressed;}
    bool setMouseIsPressed(bool& newValue) { mouseIsPressed = newValue;}

    void setDocument(TextStore* TS) {
        _textStore =  TextStore::PTR(TS);
        QObject::connect(&(*_textStore), SIGNAL(cursorPositionChanged()), this, SLOT(clickedOnText()));
    }
signals:
    void soundSellectionChanged();
    void textSellectionChanged();
public slots:

    void makeBind();
    void openSoundFile(QString fileName);
    void clickedOnText();
private:

    Logic::PTR _logic;
    SoundStore::PTR _soundStore;
    TextStore::PTR _textStore;
    //TextStore document;

    SoundFragment::PTR getSellectedSound();
    TextFragment::PTR getSellectedText();

    void setSellectionSound(SoundFragment::PTR);
    void setSellectionText(TextFragment::PTR);
    void setSellectionSound(qint32 begin, qint32 end); // тут будет глюк с большими файлами
    void setSellectionText(qint64 begin, qint64 end);
};

#endif // UIController_H

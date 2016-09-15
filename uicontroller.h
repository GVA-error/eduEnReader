#ifndef UIController_H
#define UIController_H

#include <QObject>

class UIController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 oldXPos READ getOldXPos WRITE setOldXPos)
    Q_PROPERTY(qint32 newXPos READ getNewXPos WRITE setNewXPos)
    Q_PROPERTY(bool mouseIsPressed READ getMouseIsPressed WRITE setMouseIsPressed)
public:
    explicit UIController(QObject *parent = 0);
    qint64 newXPos;
    qint32 getNewXPos() {return newXPos;}
    qint32 setNewXPos(qint32& newValue) { newXPos = newValue;}
    qint64 oldXPos;
    qint32 getOldXPos() {return oldXPos;}
    qint32 setOldXPos(qint32& newValue) { oldXPos = newValue;}
    bool mouseIsPressed;
    bool getMouseIsPressed() {return mouseIsPressed;}
    bool setMouseIsPressed(bool& newValue) { mouseIsPressed = newValue;}

signals:

public slots:
};

#endif // UIController_H

#ifndef PROCESS_H
#define PROCESS_H
#include <QSharedPointer>
#include "cpp/logic.h"
#include "cpp/soundstore.h"
#include "cpp/textstore.h"

template <class ThisType>
class LogicProcess
{
public:
    const QString endState = QString("end");
    typedef QSharedPointer <ThisType> PTR;
    static QSharedPointer <ThisType> factoryMethod(TextStore::PTR textStore, SoundStore::PTR soundStore, Logic::PTR logic)
    {
        PTR rezPtr = QSharedPointer <ThisType> (new ThisType(textStore, soundStore, logic));
        return rezPtr;
    }
    QString getCurState() { return _curState; }
    void finishSlot(){ _curState = endState; }
    virtual ~LogicProcess(){}
protected:
    QString _curState;
    Logic::PTR _logic;
    TextStore::PTR _textStore;
    SoundStore::PTR _soundStore;

    LogicProcess() = delete;
    LogicProcess(TextStore::PTR textStore, SoundStore::PTR soundStore, Logic::PTR logic)
    {
        _textStore = textStore;
        _soundStore = soundStore;
        _logic = logic;
        _curState = endState;
    }
};




#endif // PROCESS_H

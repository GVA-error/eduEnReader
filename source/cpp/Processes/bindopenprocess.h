#ifndef BINDOPENPROCESS_H
#define BINDOPENPROCESS_H
#include <QTypeInfo>
#include <QSharedPointer>
#include "cpp/Processes/process.h"

class BindOpenProcess : public LogicProcess <BindOpenProcess>//, public QThread
{
public:
    void setFileName(const QString& fileName){
        _fileName = fileName;
    }
    virtual ~BindOpenProcess() {}
    void start() { runInThisThread(); } // так как при открытии гонка за документ

    void runInThisThread() {
        run();
        finishSlot();
      //  emit finished();
    }
protected:
    void run() {
        _curState = "Opening" + _fileName + "...";
        _logic->readFromFile(_fileName, _textStore, _soundStore);
        //_logic->unMarkAllBindedText(); // тяжеловестная часть
        //emit finished();
        //_curOpenState = "end";
    }
private:
    friend class LogicProcess <BindOpenProcess>;
    BindOpenProcess() = delete;
    BindOpenProcess(TextStore::PTR textStore, SoundStore::PTR soundStore, Logic::PTR logic)
        : LogicProcess(textStore, soundStore, logic) { }

    QString _fileName;
};

#endif // BINDOPENPROCESS_H

#ifndef SCRIPTPROCESS_H
#define SCRIPTPROCESS_H
#include <QThread>
#include "cpp/Processes/process.h"
#include "cpp/Binding/scripter.h"

// TODO выделить класс тред лоджик процесса
class ScriptProcess : public QThread, public LogicProcess <ScriptProcess>
{
    Q_OBJECT
public:
    void setExecuteScript(const QString& script) {
        _script = script;
    }

    virtual ~ScriptProcess() {}
signals:
    void stateChanged(const QString& newState);
protected slots:

protected:
    friend class LogicProcess <ScriptProcess>;
    ScriptProcess() = delete;
    ScriptProcess(TextStore::PTR textStore, SoundStore::PTR soundStore, Logic::PTR logic)
        : LogicProcess(textStore, soundStore, logic) {

    }
    void setNewState(const QString& newState){
        _curState = newState;
        emit stateChanged(newState);
    }

    void run()
    {
        if (_script == Scripter::_downloadBaseScript)
        {
            setNewState("downloading...");
            _scripter.downloadBase();
        }
        else if (_script == Scripter::_uploadBaseScript)
        {
            setNewState("uploading...");
            _scripter.uploadBase();
        }
        else
            assert(false);
        QString output = _scripter.getLastError();
        QStringList lineOutput = output.split(QRegExp("\n"));
        QString error;
        for (QString line : lineOutput)
            if (line.indexOf("fatal:") != -1 || line.indexOf("error:") != -1)
            {
                error = line;
                break;
            }
        if (error.length() == 0)
            setNewState(LogicProcess::endState);
        else
            setNewState(error);
    }

private:
    Scripter _scripter;
    QString _script;
};

#endif // SCRIPTPROCESS_H

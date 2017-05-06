#ifndef TSBINDINGPROCESS_H
#define TSBINDINGPROCESS_H
#include <QThread>
#include "process.h"
#include "cpp/Binding/bindmaker.h"

class TsBindingProcess : public QThread, public LogicProcess <TsBindingProcess>
{
    Q_OBJECT
public:
    virtual ~TsBindingProcess() {}
    void setFileName(const QString& fileName) {
        _fileName = fileName;
    }
    void setSplitSize(qreal splitSize = 4.0f, qreal diffSize = 2.0f){
        _splitSize = splitSize;
        _diffSplitSize = diffSize;
    }
    void quit(){
        if (_curState != endState)
        {
            QFileInfo curFileInfo(_fileName);
            QString curBnd = curFileInfo.absolutePath() + "/" + curFileInfo.baseName() + ".bnd";
            QFile::remove(curBnd);
        }
        QThread::quit();
    }
signals:
    void stateChanged(const QString& newState);
protected:
    void run(){
        // Для решения проблем многопоточности textStore просто создадим временный аналог в текущем потоке
        TextStore::PTR tmpTextstore = TextStore::factoryMethod();
        SoundStore::PTR tmpSoundstore = SoundStore::factoryMethod();
        Logic::PTR tmpLogic = Logic::factoryMethod();
        //bool curAutoplayFlag = _tmpSoundstore->autoplay();
        tmpSoundstore->setAutoplay(false);
       // _bindMaker.data()->disconnect();
        _bindMaker = BindMaker::factoryMethod(tmpTextstore, tmpSoundstore, tmpLogic);
        connect(_bindMaker.data(), SIGNAL(process()), this, SLOT(generateNewState()));
        tmpLogic->createFromNewSoundFile(_fileName, tmpTextstore, tmpSoundstore);
        _bindMaker->setSplitSize(_splitSize, _diffSplitSize);
        _bindMaker->runInThisThread();
        tmpLogic->writeInFile(tmpTextstore, tmpSoundstore);
        //tmpTextstore-
        //_soundStore->setAutoplay(curAutoplayFlag);
        finishSlot();
    }
protected slots:
    void generateNewState()
    {
        QString bindState = _bindMaker->getCurState();
        QFileInfo fileInfo(_fileName);
        _curState = "Handing file: " + fileInfo.fileName() + "\n" + bindState;
        emit stateChanged(_curState);
    }

protected:
    QString _fileName;
    qreal _splitSize;
    qreal _diffSplitSize;
    BindMaker::PTR _bindMaker;
    friend class LogicProcess <TsBindingProcess>;
    TsBindingProcess() = delete;
    TsBindingProcess(TextStore::PTR textStore, SoundStore::PTR soundStore, Logic::PTR logic)
        : LogicProcess(textStore, soundStore, logic) {
        _splitSize = 4.0f;
        _diffSplitSize = 2.0f;
    }
};

#endif // TSBINDINGPROCESS_H

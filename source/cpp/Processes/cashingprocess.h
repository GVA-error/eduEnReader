#ifndef CASHINGPROCESS_H
#define CASHINGPROCESS_H
#include <QThread>
#include "cpp/Processes/process.h"
#include "cpp/Utilits/wordcash.h"

class CashingProcess : public QThread, public LogicProcess <CashingProcess>
{
    Q_OBJECT
public:

signals:
    void stateChanged(const QString& newState);

protected slots:
    void calcNewState(){
        qint32 curCashedPersent = _cashMaker.getCurCashedPersent();
        QString newState;
        if (curCashedPersent == 100)
            newState = LogicProcess::endState;
        else
            newState = "Cashed persent: " + QString().number(curCashedPersent);
        emit stateChanged(newState);
    }
protected:
    void run(){
        _cashMaker.cashAllFiles();
        auto cashMap = _cashMaker.getCashMap();
        _logic->setCash(cashMap);
        emit stateChanged(LogicProcess::endState);
    }
    friend class LogicProcess <CashingProcess>;
    CashingProcess() = delete;
    CashingProcess(TextStore::PTR textStore, SoundStore::PTR soundStore, Logic::PTR logic)
        : LogicProcess(textStore, soundStore, logic) {
        connect(&_cashMaker, SIGNAL(newFileCashed()), this, SLOT(calcNewState()));
    }

private:
    WordCash _cashMaker;
};

#endif // CASHINGPROCESS_H

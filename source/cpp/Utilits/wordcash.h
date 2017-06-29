#ifndef WORDCASH_H
#define WORDCASH_H

#include "cpp/logic.h"
#include <QList>
#include <QSet>
#include <QMap>

class WordCash : public QObject
{
    Q_OBJECT
public:
    WordCash();

    void cashAllFiles();
    Logic::CashMap getCashMap();
    qint32 getCurCashedPersent() { return _curCashedPersent; }

signals:
    void newFileCashed();

private:
    Logic::CashMap _cashMap;
    QList <Logic::PTR> _logicList;
    qint32 _curCashedPersent;


    void cashLogic(Logic::PTR);
};

#endif // WORDCASH_H

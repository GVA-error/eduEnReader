#ifndef METRICS_H
#define METRICS_H

#include <QString>
#include <QVector>
#include <QStringList>

// Статический класс реализующий метрики
class Metrics
{
public:
    Metrics() = delete;
    static qint64 getLevenshteinDistance(const QStringList& s1, const QStringList& sr2);
    // Используеться в getDistance, проверяет равенство слов
    static bool isEqils(const QString& string1, const QString& string2);


private:

};

#endif // METRICS_H

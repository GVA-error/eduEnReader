#include "metrics.h"


// Используеться в getDistance, проверяет равенство слов
bool Metrics::isEqils(const QString& string1, const QString& string2)
{
    // Убираем не буквы
    //deleteNotAlpha(lstr1);
    //deleteNotAlpha(lstr2);
    if (string1 == string2)
        return true;
    return false;
}

qint64 Metrics::getLevenshteinDistance(const QStringList& s1, const QStringList& s2)
{
    QVector <QVector<qint64>> mxD; // TODO стоит использовать указатели для лучшего быстродействия
    qint32 stringNumber = s1.size();
    qint32 columnNumber = s2.size();

    mxD.resize(stringNumber);
    for (auto& str : mxD)
        str.resize(columnNumber);

    auto curString = mxD.begin();
    for (int i = 0; i<mxD.size(); i++)
    {
        (*curString)[0] = i;
        curString++;
    }

    auto curColumn = mxD[0].begin();
    for (int j = 0; j<mxD[0].size(); j++)
    {
        *curColumn = j;
        curColumn++;
    }

    auto curStringEl = s1.begin();
    for (int i = 1; i<stringNumber; i++)
    {
        auto curColumnEl = s2.begin();
        for (int j = 1; j<columnNumber; j++)
        {
            qint64 _90_min = qMin(mxD[i-1][j] + 1, mxD[i][j-1] + 1);
            qint64 mFunc = *curColumnEl != *curStringEl;
            qint64 _45_min = mxD[i-1][j-1] + mFunc;
            qint64 D = qMin(_90_min, _45_min);
            mxD[i][j] = D;
            curColumnEl++;
        }
        curStringEl++;
    }
    return mxD[stringNumber-1][columnNumber-1];
}

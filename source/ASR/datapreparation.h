#ifndef DATAPREPARATION_H
#define DATAPREPARATION_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <assert.h>
#include <math.h>
#include "wavworker.h"

// Нужна чтобы хранить части звуковой дорожки // Атоматически не чиститься
const QDir SPLIT_DIR = QDir("./split");

// wav utils c++ - https://github.com/nicolamontecchio
//

class DataPreparation : public QObject
{
    Q_OBJECT
    // Нужно для соблюдения фиксированной частоты дискретизации
    const qint32 _16k = 16000;
public:
    explicit DataPreparation(QObject *parent = 0);

    // Делит файл на несколько маленьких
    // splitSize - время в секундах, определяет размер
    void splitFile(const QString& fileName, qreal splitSize, const QDir& outDirrectory = SPLIT_DIR);
    void splitFile(const QString& fileName, qreal minSplitSize, qreal maxSplitSize, const QDir& outDirrectory = SPLIT_DIR);

    // Методы возвращающие результат операций подготовки
    QStringList getFileNameList() { return _rezFileNameList; }
    qreal getFileBegin(const QString& fileName) { return _rezFileBeginOffset.take(fileName); }
    qreal getFileEnd(const QString& fileName) { return _rezFileEndOffset.take(fileName); }

    // Нужно для соблюдения дискретизации
   // bool fileIsCorrect(const QString& fileName);
    bool clearDir(const QDir& dir);
    void clearDefaultSplitDir();

signals:

public slots:

private:
    WavWorker _wav;
    QStringList _rezFileNameList;
    QMap <QString, qreal> _rezFileBeginOffset;
    QMap <QString, qreal> _rezFileEndOffset;

    // Нужна для сохронения и подготовки
    // В ауте нумерация с нуля
    //void getNormalized(double*& out, const SoundFileRead* file, qint64 beginPos, qint64 endPos);
    // Нужна для нормализации
    //qint32 getMaxAmplitude(const SoundFileRead* file, qint64 beginPos, qint64 endPos);

    // Нужна для разбиения файла на части
    QString formNPurtName(const QString& sourceName, const QString& ID);

    void writePreparation(WavWorker::Settings&, const QDir& outDirrectory = SPLIT_DIR);
    // Для разбиения фала на части
  //  void savePartFile(const SoundFileRead*, const QString& partName, qint64 begin, qint64 end);

    qint64 getEnergyMin(double* data, qint64 dataSize, qint64 windowSize = 1600);
    qreal getEnergy(double* data, qint64 begin, qint64 end);

    qreal getStadyComponent(double* data, qint64 dataSize);
    void deleteStadyComponent(double* data, qint64 dataSize);
    void deleteNoise(double* data, qint64 dataSize); // Удаляет лишнее
    void useMultyWindow(double* data, qint64 dataSize);

    // выделяет новый массив вида [prefix[0], .. , prefix[prefixSize-1], data[0], .. , data[dataSize-1]]
    // при этом исходные data и prefix не удаляетсья
    double* join(double* prefix, qint64 prefixSize, double* data, qint64 dataSize) const;
    // выделяет новый массив вида [source[splitSize] .. source[sourceSize-1]]
    // при этом source не удаляеться
    double* splitBegin(double* source, qint64 sourceSize, qint64 splitSize) const;
};

#endif // DATAPREPARATION_H

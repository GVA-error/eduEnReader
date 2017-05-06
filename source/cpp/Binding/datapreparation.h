#ifndef DATAPREPARATION_H
#define DATAPREPARATION_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <assert.h>
#include <math.h>
#include "cpp/Binding/scripter.h"
#include "cpp/Binding/wavworker.h"

// Нужна чтобы хранить части звуковой дорожки // Атоматически не чиститься
const QDir SPLIT_DIR = QDir(QDir::currentPath() + "/split");

// wav utils c++ - https://github.com/nicolamontecchio
//

class DataPreparation : public QObject
{
    Q_OBJECT
    // Нужно для соблюдения фиксированной частоты дискретизации
    const qint32 _16k = 16000;
public:
    explicit DataPreparation(QObject *parent = 0);

    QString prepeareWav(const QString& videoFile);

    void generateNoise_wav(const QString& fileName, const QString& noiseWav, qint64 begin, qint64 end); // генерим noiseWav с примером шума из файла

    // Делит файл на несколько маленьких
    // splitSize - время в секундах, определяет размер
    void splitFile(const QString& fileName, qreal splitSize, const QDir& outDirrectory = SPLIT_DIR);
    void splitFile(const QString& fileName, qreal minSplitSize, qreal maxSplitSize, const QDir& outDirrectory = SPLIT_DIR);

    // Методы возвращающие результат операций подготовки
    QStringList getFileNameList() const { return _rezFileNameList; }
    QMap <QString, qreal> getFileBeginList() const { return _rezFileBeginOffset; }
    QMap <QString, qreal> getFileEndList() const { return _rezFileEndOffset; }

    // Нужно для соблюдения дискретизации
   // bool fileIsCorrect(const QString& fileName);
    static bool clearDir(const QDir& dir);
    static bool copy(const QDir& originalDir, const QDir& copyDir, const QStringList& mask = QStringList("*.*"));
    static void clearTrash(); // Чистит от мусора папке с программой от временных вав файлов

    void clearDefaultSplitDir();

signals:

public slots:

private:
    WavWorker _wav;
    Scripter _scripter;
    QStringList _rezFileNameList;
    QMap <QString, qreal> _rezFileBeginOffset;
    QMap <QString, qreal> _rezFileEndOffset;
    const qint64 _noiseFileSize = 8000; // размер файла с шумом, для построения модели шума, должно быть кратно четырём
    // Позиции в которых ищем шум
    const qint64 _noiseWindowBegin = 30 * _16k;
    const qint64 _noiseWindowEnd = 60 * _16k; // Считаем что файл хотябы 60 секунд

    const QString _noise_wav = QDir::currentPath() + "/Scripts/noise.wav";

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
    void useMultyWindow(double* data, qint64 dataSize);

    // выделяет новый массив вида [prefix[0], .. , prefix[prefixSize-1], data[0], .. , data[dataSize-1]]
    // при этом исходные data и prefix не удаляетсья
    double* join(double* prefix, qint64 prefixSize, double* data, qint64 dataSize) const;
    // выделяет новый массив вида [source[splitSize] .. source[sourceSize-1]]
    // при этом source не удаляеться
    double* splitBegin(double* source, qint64 sourceSize, qint64 splitSize) const;
};

#endif // DATAPREPARATION_H

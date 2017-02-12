#ifndef WAVWORKER_H
#define WAVWORKER_H

#include <QString>
#include <QDebug>
#include <sndfile.h>

const qint64 _16k = 16000;

// Нужен для чтения и разбивки файлов
// В данный моммент однопоточный
// одновременно 1 входной файл 1 выходной
class WavWorker
{
public:
    struct Settings
    {
        int samplesPerSecond; // Нужна для передескритизации
        int bitRate;
    };

    WavWorker();
    ~WavWorker();

    // Начинаем читать файл сначала
    // при этом закрываем старый, и открываем новый
    void openInFile(const QString& fileName);
    void openOutFile(const QString& fileName, const Settings&);

    // Нужен для чтения следующей части файла, при разбивке
    // buffSize - сколько читать
    bool read(double* data, int buffSize);
    // Записываем прочитанную инфу в открытый файл
    bool write(double* data, int dataSize);
private:

    SNDFILE	*_in;
    SNDFILE	*_out;

    void initFSInfo(SF_INFO&sfinfo, const Settings&);
    void defaultInitFSInfo(SF_INFO&sfinfo);

};

#endif // WAVWORKER_H

#ifndef WAVWORKER_H
#define WAVWORKER_H

#include <QString>
#include <QDebug>
#ifndef Q_OS_WIN
#include <sndfile.h>
#endif
#include <assert.h>

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

    // Вырезает часть из _in в _out
    void copyPart(qint64 pos, qint64 size);

    void setReadPos(qint64 pos);
    void setWritePos(qint64 pos);

    // Нужен для чтения следующей части файла, при разбивке
    // buffSize - сколько читать
    bool read(double* data, int buffSize);
    // Записываем прочитанную инфу в открытый файл
    bool write(double* data, int dataSize);

    qint64 sizeIn(); // TODO найти способ узнать длинну?
private:

#ifndef Q_OS_WIN
    SNDFILE	*_in;
    SNDFILE	*_out;

    void initFSInfo(SF_INFO&sfinfo, const Settings&);
    void defaultInitFSInfo(SF_INFO&sfinfo);
#endif
};

#endif // WAVWORKER_H

#ifndef SOUNDREADER_H
#define SOUNDREADER_H

#include <QTypeInfo>
#include <QSharedPointer>
#include <QObject>
#include <QFile>
#include "riff/riff.h"

class SoundReader
{
public:
    typedef QSharedPointer <SoundReader> PTR;
    static QSharedPointer <SoundReader> factoryMethod()
    {
        PTR rezPtr = QSharedPointer <SoundReader> (new SoundReader());
        return rezPtr;
    }

    qint64 getSample(qint64 sample);
    qint64 getDiscret();

    qint64 readFile(QString fileName);
    SoundReader();
    ~SoundReader();

private:
    const qint32 buffSize = 0;
    riffwave_reader* wavriff;
};

#endif // SOUNDREADER_H

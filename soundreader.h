#ifndef SOUNDREADER_H
#define SOUNDREADER_H

#include <QTypeInfo>
#include <QSharedPointer>
#include <QObject>
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

    qint64 readFile(QString fileName);
    SoundReader();
    ~SoundReader();

private:
    riffwave_reader* wavriff;
};

#endif // SOUNDREADER_H

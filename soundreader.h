#ifndef SOUNDREADER_H
#define SOUNDREADER_H

#include <QTypeInfo>
#include <QObject>
#include "factory.h"
#include "riff/riff.h"

class SoundReader : public Factory <SoundReader>
{
public:
    qint64 getSample(qint64 sample);

    SoundReader();
};

#endif // SOUNDREADER_H

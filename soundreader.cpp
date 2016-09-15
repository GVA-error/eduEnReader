#include "soundreader.h"

SoundReader::SoundReader()
{
    wavriff = nullptr;
}

SoundReader::~SoundReader()
{
    delete wavriff;
}

qint64 SoundReader::getSample(qint64 sample)
{
    return rand() - RAND_MAX/2;
}

qint64 SoundReader::readFile(QString fileName)
{
    if (wavriff)
    {
        delete wavriff;
    }

    wavriff = new riffwave_reader(fileName.toStdString().c_str());
}

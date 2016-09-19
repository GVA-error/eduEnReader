#include "soundreader.h"

SoundReader::SoundReader()
{
    wavriff = nullptr;
}

SoundReader::~SoundReader()
{
    delete wavriff;
}

qint64 SoundReader::getDiscret()
{
    Q_ASSERT(wavriff);
    return wavriff->samplespersec();
}

qint64 SoundReader::getSample(qint64 sample)
{
    // Для оптимизации можно использовать буфер
    qreal sampleValue;
    Q_ASSERT(wavriff);
    wavriff->seek(sample);
    sampleValue = wavriff->operator ()(sample);
    return sampleValue;
}

qint64 SoundReader::readFile(QString fileName)
{
    Q_ASSERT(QFile(fileName).exists());
    if (wavriff)
    {
        delete wavriff;
    }

    wavriff = new riffwave_reader(fileName.toStdString().c_str(), buffSize);
}

#include "soundstore.h"

SoundStore::SoundStore(QObject *parent) : QObject(parent)
{
    _soundPlayer = SoundPlayer::factoryMethod();
    _soundReader = SoundReader::factoryMethod();
}

qint64 SoundStore::getSample(qint64 pos) const
{
    qint64 sample = _soundReader->getSample(pos);
    return sample;
}

void SoundStore::play(qint64 begin, qint64 end)
{
    _soundPlayer->play(begin, end);
}

void SoundStore::readFile(QString fileName)
{
    _soundReader->readFile(fileName);
    _soundPlayer->openFile(fileName);
}

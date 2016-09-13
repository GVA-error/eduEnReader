#include "soundstore.h"

SoundStore::SoundStore(QObject *parent) : QObject(parent)
{
    _soundPlayer = SoundPlayer::createPointer();
    _soundReader = SoundReader::createPointer();
}

qint64 SoundStore::getSample(qint64 pos)
{
    qint64 sample = _soundReader->getSample(pos);
    return sample;
}

void SoundStore::play(qint64 begin, qint64 end)
{
    _soundPlayer->play(begin, end);
}

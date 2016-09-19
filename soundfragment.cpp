#include "soundfragment.h"

SoundFragment::SoundFragment(qint64 begin, qint64 end, SoundStore::PTR source)
{
    _source = source;
    _begin = begin;
    _end = end;
}

void SoundFragment::play()
{
    _source->play(_begin, _end);
}

SoundFragment::SoundFragment(qint64 begin, qint64 end, SoundFragment::PTR source)
{
    qint64 globalShift = source->begin();
    _begin = begin + globalShift;
    _end = end + globalShift;
    _source = source->_source;
}

char SoundFragment::getSample(qint64 i)
{
    // TODO работа с документом
    return -1;
}

qint64 SoundFragment::getSampleNumber()
{
    // TODO работа с документом
    return -1;
}

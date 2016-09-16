#include "soundfragment.h"

SoundFragment::SoundFragment(SoundStore::PTR source, qint64 begin, qint64 end)
{
    _soundSource = source;
    _begin = begin;
    _end = end;
}

void SoundFragment::play()
{
    _soundSource->play(_begin, _end);
}

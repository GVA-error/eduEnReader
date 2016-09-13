#ifndef SOUNDFRAGMENT_H
#define SOUNDFRAGMENT_H

#include "soundplayer.h"

class SoundFragment
{
    SoundFragment() = delete;
    explicit SoundFragment(SoundPlayer* source, qint64 begin, qint64 end);

signals:

public slots:

    void play();
private:
    qint64 _begin;
    qint64 _end;

    SoundPlayer* _soundSource;
};

#endif // SOUNDFRAGMENT_H

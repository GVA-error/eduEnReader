#ifndef SOUNDFRAGMENT_H
#define SOUNDFRAGMENT_H

#include "soundstore.h"

// служит для обмена звуком

class SoundFragment
{

public:
    typedef QSharedPointer <SoundFragment> PTR;
    static QSharedPointer <SoundFragment> factoryMethod(SoundStore::PTR source, qint64 begin, qint64 end)
    {
        PTR rezPtr = QSharedPointer <SoundFragment> (new SoundFragment(source, begin, end));
        return rezPtr;
    }
signals:

public slots:

    void play();
private:
    qint64 _begin;
    qint64 _end;

    SoundStore::PTR _soundSource;

    SoundFragment() = delete;
    explicit SoundFragment(SoundStore::PTR source, qint64 begin, qint64 end);
};

#endif // SOUNDFRAGMENT_H

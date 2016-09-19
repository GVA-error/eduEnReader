#ifndef SOUNDFRAGMENT_H
#define SOUNDFRAGMENT_H

#include "soundstore.h"

// служит для обмена звуком

class SoundFragment
{

public:
    typedef QSharedPointer <SoundFragment> PTR;
    static QSharedPointer <SoundFragment> factoryMethod(qint64 begin, qint64 end, SoundStore::PTR source)
    {
        PTR rezPtr = QSharedPointer <SoundFragment> (new SoundFragment(begin, end, source));
        return rezPtr;
    }
    static QSharedPointer <SoundFragment> factoryMethod(qint64 begin, qint64 end, SoundFragment::PTR source)
    {
        PTR rezPtr = QSharedPointer <SoundFragment> (new SoundFragment(begin, end, source));
        return rezPtr;
    }

    // Методы в глобальных координатах
    qint64 begin() { return _begin; }
    qint64 end() { return _end; }

    // Метод в локальных координатах
    char getSample(qint64 i);

    qint64 getSampleNumber();
signals:

public slots:

    void play();
private:
    qint64 _begin;
    qint64 _end;

    SoundStore::PTR _source;

    SoundFragment() = delete;
    // В глобальных координатах
    SoundFragment(qint64 begin, qint64 end, SoundStore::PTR source);
    // В координатах фрагмента источника
    SoundFragment(qint64 begin, qint64 end, SoundFragment::PTR source);
};

#endif // SOUNDFRAGMENT_H

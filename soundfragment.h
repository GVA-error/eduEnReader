#ifndef SOUNDFRAGMENT_H
#define SOUNDFRAGMENT_H

#include "fragment.h"
#include "soundstore.h"

// служит для обмена звуком
class SoundFragment : public Fragment <SoundFragment, SoundStore::PTR, qreal>
{
public:

    virtual ~SoundFragment() {
       // qDebug() << "~SoundFragment()";
    }
signals:

public slots:

    void play();
protected:

    friend class Fragment;
    SoundFragment() = delete;
    // В глобальных координатах
    SoundFragment(qreal begin, qreal end, SoundStore::PTR source)
        : Fragment(begin, end, source) {


      //  qDebug() << "SoundFragment()";
    }
};

#endif // SOUNDFRAGMENT_H

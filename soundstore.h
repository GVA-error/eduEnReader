#ifndef SOUNDSTORE_H
#define SOUNDSTORE_H

#include <QObject>
#include "soundreader.h"
#include "soundplayer.h"

class SoundStore : public QObject
{
    Q_OBJECT
public:
    explicit SoundStore(QObject *parent = 0);

signals:

public slots:

    void play(qint64 begin, qint64 end);
    qint64 getSample(qint64 pos);

private:

    SoundReader::PTR _soundReader;
    SoundPlayer::PTR _soundPlayer;
};

#endif // SOUNDSTORE_H

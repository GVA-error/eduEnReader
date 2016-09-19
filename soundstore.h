#ifndef SOUNDSTORE_H
#define SOUNDSTORE_H

#include <QObject>
#include "soundreader.h"
#include "soundplayer.h"

class SoundStore : public QObject
{
    Q_OBJECT
public:
    typedef QSharedPointer <SoundStore> PTR;
    static QSharedPointer <SoundStore> factoryMethod()
    {
        PTR rezPtr = QSharedPointer <SoundStore> (new SoundStore());
        return rezPtr;
    }
    SoundStore(QObject *parent = 0);

    qint64 getSample(qint64 pos) const;
    qint64 getSampleNumber() const;
    void readFile(QString fileName);

signals:

public slots:

    void play(qint64 begin, qint64 end);

private:

    SoundReader::PTR _soundReader;
    SoundPlayer::PTR _soundPlayer;
};

#endif // SOUNDSTORE_H

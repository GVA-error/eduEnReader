#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QObject>
#include <QtMultimedia/QMediaPlayer>
#include "factory.h"

class SoundPlayer : public QObject, public Factory <SoundPlayer>
{
    Q_OBJECT
public:
    explicit SoundPlayer(QObject *parent = 0);

signals:

public slots:
    void play(qint64 begin, qint64 end);

    void setPos(qint64);
    void start();
    void stop();
};

#endif // SOUNDPLAYER_H

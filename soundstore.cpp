#include "soundstore.h"

SoundStore::SoundStore(QObject *parent)
    : QObject(parent), Store()
{
   // qDebug() << "SoundStore()";
    connect(&_player, SIGNAL(positionChanged(qint64)), this, SIGNAL(posChanged()));
}
/*
void SoundStore::posChanched(qint64 newPos)
{
    //emit SIGNAL(posChanged);
    qint64 duration = _player.duration();
    if (duration >= newPos)
        return;
    _player.setPosition(newPos);
}*/

void SoundStore::setPosPersent(qreal pos)
{
    qint64 fullDuretion = _player.duration();
    qint64 realPos = fullDuretion * pos;
    _player.setPosition(realPos);
}

void SoundStore::setPosReal(qreal p)
{
    qint64 realPos = p * 1000; // переводим в милисекунды
    _player.setPosition(realPos);
}

void SoundStore::start()
{
    _player.play();
}

void SoundStore::stop()
{
    _player.pause();
}

void SoundStore::playReal(qreal begin, qreal end)
{
    setPosReal(begin);
    _player.play();
}

qreal SoundStore::getTimePos() const
{
    qreal curTimePos = (qreal)_player.position() / 1000;
    return curTimePos;
}

qreal SoundStore::getPersentPos() const
{
    qint64 fullDuretion = _player.duration();
    qint64 curDuration = _player.position();
    qreal posPersent = (qreal)curDuration / (qreal)fullDuretion;
    return posPersent;
}

void SoundStore::setFileUrl(const QUrl& url)
{
    _player.setMedia(url);
    _lastOpenedUrl = url;
    _player.setVolume(50);
}

QUrl SoundStore::fileUrl() const
{
    return _lastOpenedUrl;
}

#include "soundstore.h"

SoundStore::SoundStore(QObject *parent, Flags flags)
    :  QMediaPlayer(parent, flags), Store()
{
   // qDebug() << "SoundStore()";
    connect(this, SIGNAL(positionChanged(qint64)), this, SIGNAL(posChanged())); // Монжно удалить?
    setMedia(QUrl("file:///home/gva-error/projects/eduEnReader/Bield/1.mp4"));//url);
    setVolume(50);
}

void SoundStore::setVideoSurface(QAbstractVideoSurface* surface)
{
    qDebug() << "Changing surface";
    m_surface = surface;
    setVideoOutput(m_surface);
}

QAbstractVideoSurface* SoundStore::getVideoSurface()
{
    return m_surface;
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
    qint64 fullDuretion = duration();
    qint64 realPos = fullDuretion * pos;
    setPosition(realPos);
}

void SoundStore::setPosReal(qreal p)
{
    qint64 realPos = p * 1000; // переводим в милисекунды
    setPosition(realPos);
}

void SoundStore::start()
{
    play();
}

void SoundStore::stop()
{
    pause();
}

void SoundStore::playReal(qreal begin, qreal end)
{
    setPosReal(begin);
    play();
}

qreal SoundStore::getTimePos() const
{
    qreal curTimePos = (qreal)position() / 1000;
    return curTimePos;
}

qreal SoundStore::getPersentPos() const
{
    qint64 fullDuretion = duration();
    qint64 curDuration = position();
    qreal posPersent = (qreal)curDuration / (qreal)fullDuretion;
    return posPersent;
}

void SoundStore::setFileUrl(const QUrl& url)
{
    setMedia(QUrl(url));
    _lastOpenedUrl = url;
    setVolume(50);
}

QUrl SoundStore::fileUrl() const
{
    return _lastOpenedUrl;
}

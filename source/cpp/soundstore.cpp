#include "soundstore.h"

SoundStore::SoundStore(QObject *parent, Flags flags)
    :  QMediaPlayer(parent, flags), Store()
{
   // qDebug() << "SoundStore()";
    connect(this, SIGNAL(positionChanged(qint64)), this, SIGNAL(posChanged())); // Монжно удалить?

    _startPos = _finishPos = -1;
    //setFileUrl(QUrl::fromLocalFile("/home/gva/eduEnReader/source/Release/B.mp4"), 0, 10);//url);
    saveHome();
    connect(&_timerToStop, SIGNAL(timeout()), this, SLOT(stopStopTimer()));

    setVolume(50);
}

void SoundStore::setVideoSurface(QAbstractVideoSurface* surface)
{
    qDebug() << "Changing surface";
    m_surface = surface;
    setVideoOutput(m_surface);
}

QAbstractVideoSurface* SoundStore::getVideoSurface() const
{
    return m_surface;
}

void SoundStore::saveHome()
{
    _saved_startPos = _startPos;
    _saved_finishPos = _finishPos;
    _saved_lastOpenedUrl = _lastOpenedUrl;
    _saved_curPos = position();
}

void SoundStore::home()
{
    if (_saved_lastOpenedUrl == _lastOpenedUrl
            && _saved_startPos == _startPos
            && _saved_finishPos == _finishPos) // Мы и так дома
        return;
    setFileUrl(_saved_lastOpenedUrl, _saved_startPos, _saved_finishPos);
    setPosition(_saved_curPos);
    //start();
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
    qreal start = _startPos;
    if (start < 0)
        start = 0;

    qint64 realPos = fullDuretion * pos + start * 1000;
    setPosition(realPos);
    //emit posChanged(); // Походу уже вызывается
}

void SoundStore::setPosReal(qreal p)
{
    qint64 realPos = p * 1000; // переводим в милисекунды
    setPosition(realPos);
    emit posChanged();
}

void SoundStore::start()
{
    qint64 curRealPos = position();
    qint64 finishPos = _finishPos * 1000;
    qint64 duration = finishPos - curRealPos;
    if (duration < _epsilonTime && _startPos > 0)
        return;
    _timerToStop.stop();
    if (duration >= _epsilonTime)
        _timerToStop.start(duration);
    play();
}

void SoundStore::stop()
{
    pause();
    _timerToStop.stop();
}

void SoundStore::stopStopTimer()
{
    qint64 curTime = position();
    qint64 finishTime = _finishPos * 1000;
    qint64 timeToStop = finishTime - curTime;
    if (timeToStop >= _epsilonTime)
    {
        _timerToStop.stop();
        _timerToStop.start(timeToStop);
    }
    else
        stop();
}

qreal SoundStore::getTimePos() const
{
    qreal curTimePos = (qreal)position() / 1000;
    return curTimePos;
}

qint64 SoundStore::duration() const
{
    qint32 fullDeduraton = QMediaPlayer::duration();
    qint32 realDuration = (_finishPos - _startPos) * 1000;
    assert((_startPos >= 0 && _finishPos >= 0) || (_startPos < 0 && _finishPos < 0));
    assert(_startPos <= _finishPos);
    if (_startPos < 0)
        return fullDeduraton;
    return realDuration;

}

qreal SoundStore::getPersentPos() const
{
    qint64 fullDuretion = duration();
    if (fullDuretion <= 0)
        fullDuretion = 1;
    qreal start = _startPos;
    if (start < 0)
        start = 0;
    qint64 curDuration = position() - start * 1000;
    if (curDuration < 0)
        curDuration = 0;
    qreal posPersent = (qreal)curDuration / (qreal)fullDuretion;
    if (posPersent > 1)// && !_timerToStop->isActive())
    {
        //_timerToStop->start(1);
        //_temerToStopIsActive = true;
        posPersent = 1;
    }
    return posPersent;
}

void SoundStore::setFileUrl(const QUrl& url, qreal start, qreal finish)
{
    setFileUrl(url);
    _startPos = start;
    _finishPos = finish;
    setPosReal(_startPos);
}


void SoundStore::setFileUrl(const QUrl& url)
{
    setMedia(QUrl(url));
    _lastOpenedUrl = url;
    setVolume(50);
    _finishPos = -1;
    _startPos = -1;
}

QUrl SoundStore::fileUrl() const
{
    return _lastOpenedUrl;
}

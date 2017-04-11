#include "soundstore.h"

SoundStore::SoundStore(QObject *parent)
    : Store() // Вызывать конструктор Vlc не нужно - фича
{
   // qDebug() << "SoundStore()";
    connect(this, SIGNAL(positionChanged()), this, SIGNAL(posChanged())); // Монжно удалить?

    _startPos = _finishPos = -1;
    //setFileUrl(QUrl::fromLocalFile("/home/gva/eduEnReader/source/Release/B.mp4"), 0, 10);//url);
    saveHome();
    connect(&_timerToStop, SIGNAL(timeout()), this, SLOT(stopStopTimer()));

    setVolume(50);
    setAutoplay(false);
}
/*
void SoundStore::setVideoSurface(QAbstractVideoSurface* surface)
{
    qDebug() << "Changing surface";
    m_surface = surface;
    this->setVideoSurface(m_surface);
}

QAbstractVideoSurface* SoundStore::getVideoSurface() const
{
    return m_surface;
}
*/
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
    setPosPersent(_saved_curPos);
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
    qreal curPos = pos;
    if (_startPos > 0)
        curPos += _startPos;
    VlcQmlVideoPlayer::setPosition(curPos);
    //emit posChanged(); // Походу уже вызывается
}

void SoundStore::setPosReal(qreal p)
{
    qint32 curDuration = duration();
    qreal realPos = p * 1000.0 / curDuration; // переводим в милисекунды
    setPosPersent(realPos);
    //emit posChanged();
}

void SoundStore::start()
{
    // Так как мы не можем гарантировать что знаем длинну видео до того как можем его воспроизвести
    if (_tmpTimeStartFinish.empty() == false)
    {
        qint32 curDuration = duration();
        if (curDuration > 0) // проверяем знаем ли мы длинну видео
        {
            _startPos = _tmpTimeStartFinish.front() * 1000 / curDuration;
            _finishPos = _tmpTimeStartFinish.back() * 1000 / curDuration;
            _tmpTimeStartFinish.clear();
        }
        else{
            VlcQmlVideoPlayer::pause();
            return;
        }
    }

    qreal curPosition = position();
    qint32 timeToEnd = (_finishPos - curPosition) * duration();
    if (timeToEnd < _epsilonTime && _startPos > 0)
    {
        VlcQmlVideoPlayer::pause();
        return;
    }
    if (curPosition < _startPos)
        setPosPersent(0);
    _timerToStop.stop();
    _timerToStop.start(timeToEnd);
    VlcQmlVideoPlayer::play();
}

void SoundStore::stop()
{
    VlcQmlVideoPlayer::pause();
    _timerToStop.stop();
}

void SoundStore::stopStopTimer()
{
    qint32 timeToEnd = (_finishPos - position()) * duration() ;
    if (timeToEnd >= _epsilonTime)
    {
        _timerToStop.stop();
        _timerToStop.start(timeToEnd);
    }
    else
        stop();
}

qreal SoundStore::getTimePos() const
{
    qreal curTimePos = position() * duration() / 1000;
    return curTimePos;
}

qint64 SoundStore::duration() const
{
    qint32 fullDeduraton = VlcQmlVideoPlayer::length();
    qint32 realDuration = (_finishPos - _startPos) * fullDeduraton;
    assert((_startPos >= 0 && _finishPos >= 0) || (_startPos < 0 && _finishPos < 0));
    assert(_startPos <= _finishPos);
    if (_startPos < 0)
        return fullDeduraton;
    return realDuration;

}

qreal SoundStore::getPersentPos()
{
    qreal realPersent = VlcQmlVideoPlayer::position();
    if (_tmpTimeStartFinish.empty() == false)
        start();

    if (_startPos > 0)
        realPersent -= _startPos;
    if (realPersent<0)
        realPersent=0;

    if (realPersent < 0 || realPersent > 1)
    {
        //VlcQmlVideoPlayer::pause();
        setPosPersent(0);
        return 0;
    }
    return realPersent;
}

void SoundStore::setFileUrl(const QUrl& url, qreal start, qreal finish)
{
    setFileUrl(url);
    //qint32 cur_duration = duration();

    // Пока мы не вызывали play duration не посчитать, правда гарантировать что посчитаеться сразу мы всёравно не можем
    play();
    //pause();
    //setAutoplay(false);

    _tmpTimeStartFinish.clear();
    _tmpTimeStartFinish.push_back(start);
    _tmpTimeStartFinish.push_back(finish);
    _startPos = _finishPos = -1;
    setPosition(0);

}


void SoundStore::setFileUrl(const QUrl& url)
{
    VlcQmlVideoPlayer::setUrl(url);
    _lastOpenedUrl = url;
    VlcQmlVideoPlayer::setVolume(50);
    VlcQmlVideoPlayer::pause();
    _finishPos = -1;
    _startPos = -1;
}

QUrl SoundStore::fileUrl() const
{
    return _lastOpenedUrl;
}

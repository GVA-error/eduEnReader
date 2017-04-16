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

    setVolume(100);
    setAutoplay(false);
    setPosition(0);
    _isExample = false;
    _saved_payed = false;
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
    if (_startPos >= 0)
        return;
    //if (! home)
    //_saved_startPos = _startPos;
    //_saved_finishPos = _finishPos;
    _saved_lastOpenedUrl = _lastOpenedUrl;
    _saved_curPos = position();
    if (state() == playingState())
        _saved_payed = true;
    else
        _saved_payed = false;
}

void SoundStore::home()
{
    //if (_saved_lastOpenedUrl == _lastOpenedUrl
    //        && _saved_startPos == _startPos
    //        && _saved_finishPos == _finishPos) // Мы и так дома
    //    return;
    setFileUrl(_saved_lastOpenedUrl);
    //if (_saved_payed)"Если "Если бы я был бы я был
        start();
    if (_saved_curPos > 0)
    {
        setPosition(_saved_curPos);
    }
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
    qreal maxPersent = _finishPos - _startPos;
    if (maxPersent > 0 && _isExample)
        curPos = maxPersent * pos + _startPos;
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
    if (VlcQmlVideoPlayer::state() == 6) // Переходим к началу видео по завершению
    {
        QUrl last = _lastOpenedUrl;
        VlcQmlVideoPlayer::setUrl(QUrl::fromLocalFile(""));
        VlcQmlVideoPlayer::setUrl(last);
        qDebug() << "Video reloaded";
    }

    // Так как мы не можем гарантировать что знаем длинну видео до того как можем его воспроизвести
    if (_tmpTimeStartFinish.empty() == false)
    {
        qint32 curDuration = duration();
        if (curDuration > 0) // проверяем знаем ли мы длинну видео
        {
            _startPos = _tmpTimeStartFinish.front() * 1000 / curDuration;
            _finishPos = _tmpTimeStartFinish.back() * 1000 / curDuration;
            setPosPersent(0);
            _tmpTimeStartFinish.clear();
        }
        else{
            stop();
            return;
        }
    }

    float curPosition = position();
    qint64 timeToEnd = (_finishPos - curPosition) * duration();
    //if (curPosition < _startPos)
    //    setPosPersent(0);
    _timerToStop.stop();
    _timerToStop.start(timeToEnd);
    VlcQmlVideoPlayer::play();
    emit playingStateChanged();
}

void SoundStore::stop()
{
    VlcQmlVideoPlayer::pause();
    _timerToStop.stop();
    emit playingStateChanged();
}

void SoundStore::stopStopTimer()
{
    qint32 timeToEnd = (1 - getPersentPos()) * duration();
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

    qreal maxPersent = _finishPos - _startPos;
    if (maxPersent > 0 && _isExample)
        realPersent = realPersent / maxPersent;

    if (_isExample)
        if (realPersent < 0 || realPersent > 1)
        {
            VlcQmlVideoPlayer::pause();
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
    //u
    play();
    //pause();
    //setAutoplay(false);
    //setTime(start*1000);
    //qint64 l = length();

    _tmpTimeStartFinish.clear();
    _tmpTimeStartFinish.push_back(start);
    _tmpTimeStartFinish.push_back(finish);
    _isExample = start > 0 || finish > 0;
    _startPos = _finishPos = -1;
    //setPosition(0.5);
    emit isExampleStateChanged();
}


void SoundStore::setFileUrl(const QUrl& url)
{
    VlcQmlVideoPlayer::setUrl(url);
    _lastOpenedUrl = url;
    VlcQmlVideoPlayer::setVolume(100);
    VlcQmlVideoPlayer::pause();
    _finishPos = -1;
    _startPos = -1;
    _isExample = false;
}

QUrl SoundStore::fileUrl() const
{
    return _lastOpenedUrl;
}

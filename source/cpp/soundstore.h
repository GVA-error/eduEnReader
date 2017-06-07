#ifndef SOUNDSTORE_H
#define SOUNDSTORE_H

#include <QObject>
#include <QMediaPlayer>
#include <QSharedPointer>
#include <QTimer>

#include <VLCQtCore/Common.h>
#include <VLCQtQml/QmlVideoPlayer.h>

#include <assert.h>
#include "store.h"

class SoundStore : public VlcQmlVideoPlayer, public Store <SoundStore>
{
    Q_OBJECT
    Q_PROPERTY(qreal position READ getPersentPos WRITE setPosPersent NOTIFY posChanged)
    Q_PROPERTY(bool isExample READ isExample NOTIFY isExampleStateChanged)
    //Q_PROPERTY(const int PlayingState READ PlayingState NOTIFY isNeverSignal)
    //Q_PROPERTY(const int BufferingState READ BufferingState NOTIFY isNeverSignal)
  //  Q_PROPERTY(QAbstractVideoSurface* videoSurface READ getVideoSurface WRITE setVideoSurface)
public:

    SoundStore(QObject * parent = 0);
    virtual ~SoundStore() {
       // qDebug() << "~SoundStore()";
    }
    void setFileUrl(const QUrl& url, qreal start, qreal finish);
    void setFileUrl(const QUrl& url) override; // TODO Добавить потдержку относительных путей
    QUrl fileUrl() const override;

    qreal fullDuration() { return (qreal)duration() / 1000; }

signals:
    void posChanged();
    void isExampleStateChanged();
    void playingStateChanged();
    void openingError();
public slots:

    void clear(){
        setFileUrl(QUrl("http//"));
    }

    // Так как константы vlc не перенесены в qml код
    qint32 playingState() { return Vlc::Playing; }
    qint32 bufferingState() { return Vlc::Buffering; }
    bool isExample() { return _isExample; }

    void setPosReal(qreal); // позиция устанавливается в секундах
    void setPosPersent(qreal); // позиция устанавливаеться в проентах
    qreal getPersentPos(); // Процент воспроизведёного
    qreal getTimePos() const;
    void start(); // Использовать вместо play TODO - Перегрузить
    void stop();
    void stopStopTimer(); // Нужна для синхронизации завершения

    void saveHome();
    void home();

    bool isCorrectLocalFile(){
        if (isRemoteSource(_lastOpenedUrl.toString()) == false)
            if (QFile::exists(_lastOpenedUrl.toLocalFile()) == true)
                return true;
        return false;
    }
protected:
    friend class Store <SoundStore>;
    bool _isExample;
    QUrl _lastOpenedUrl;
    QAbstractVideoSurface* m_surface; // Для потдержки Qml MediaPlayer
    QTimer _timerToStop;
    // Моменты начала и конца воспроизведения файла.
    float _startPos;
    float _finishPos;
    QList <qreal> _tmpTimeStartFinish; // по скольку втдео воспроизводиться в другом потоке, храним тут просьбу пользователя о установке start и finish

    // Сохраненное состояние
  //  qreal _saved_startPos;
  //  qreal _saved_finishPos;
    qreal _saved_curPos;
    QUrl _saved_lastOpenedUrl;
    bool _saved_payed;

    // Нужно чтобы таймер не запускался на 0 - 1, что моэет вызвать притормаживание
    // Допустимая погрешность по времени в милисекундах при остановке видео
    const qint32 _epsilonTime = 50;

    qint64 duration() const ;//override;
};

#endif // SOUNDSTORE_H

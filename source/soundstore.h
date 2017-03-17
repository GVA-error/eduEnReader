#ifndef SOUNDSTORE_H
#define SOUNDSTORE_H

#include <QObject>
#include <QMediaPlayer>
#include <QSharedPointer>
#include <QTimer>
#include <assert.h>
#include "store.h"

class SoundStore : public QMediaPlayer, public Store <SoundStore>
{
    Q_OBJECT
    Q_PROPERTY(qreal position READ getPersentPos WRITE setPosPersent NOTIFY posChanged)
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ getVideoSurface WRITE setVideoSurface) // Для потдержки Qml MediaPlayer
public:
    virtual ~SoundStore() {
       // qDebug() << "~SoundStore()";
    }
    void setFileUrl(const QUrl& url, qreal start, qreal finish);
    void setFileUrl(const QUrl& url) override; // TODO Добавить потдержку относительных путей
    QUrl fileUrl() const override;
signals:
    void posChanged();
public slots:
    void setPosReal(qreal); // позиция устанавливается в секундах
    void setPosPersent(qreal); // позиция устанавливаеться в проентах
    qreal getPersentPos() const; // Процент воспроизведёного
    qreal getTimePos() const;
    void start(); // Использовать вместо play TODO - Перегрузить
    void stop();
    void stopStopTimer(); // Нужна для синхронизации завершения

    void saveHome();
    void home();

    // Для потдержки Qml MediaPlayer
    void setVideoSurface(QAbstractVideoSurface* surface);
    QAbstractVideoSurface* getVideoSurface();

protected:
    friend class Store <SoundStore>;
    QUrl _lastOpenedUrl;
    QAbstractVideoSurface* m_surface; // Для потдержки Qml MediaPlayer
    QTimer *_timerToStop;
    // Моменты начала и конца воспроизведения файла.
    qreal _startPos;
    qreal _finishPos;

    // Сохраненное состояние
    qreal _saved_startPos;
    qreal _saved_finishPos;
    qint64 _saved_curPos;
    QUrl _saved_lastOpenedUrl;

    // Нужно чтобы таймер не запускался на 0 - 1, что моэет вызвать притормаживание
    // Допустимая погрешность по времени в милисекундах при остановке видео
    const qint32 _epsilonTime = 5;

    SoundStore(QObject * parent = 0, Flags flags = 0);

    qint64 duration() const ;//override;
};

#endif // SOUNDSTORE_H

#ifndef SOUNDSTORE_H
#define SOUNDSTORE_H

#include <QObject>
#include <QMediaPlayer>
#include <QSharedPointer>
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

    void setFileUrl(const QUrl& url) override; // TODO Добавить потдержку относительных путей
    QUrl fileUrl() const override;
signals:
    void posChanged();

public slots:
    void playReal(qreal begin, qreal end = -1); // указывается в секундах

    void setPosReal(qreal); // позиция устанавливается в секундах
    void setPosPersent(qreal); // позиция устанавливаеться в проентах
    qreal getPersentPos() const;
    qreal getTimePos() const;
    void start();
    void stop();

    // Для потдержки Qml MediaPlayer
    void setVideoSurface(QAbstractVideoSurface* surface);
    QAbstractVideoSurface* getVideoSurface();

  //  void posChanched(qint64 newPos);
protected:
    friend class Store <SoundStore>;
    QUrl _lastOpenedUrl;
    QAbstractVideoSurface* m_surface; // Для потдержки Qml MediaPlayer
    SoundStore(QObject * parent = 0, Flags flags = 0);
};

#endif // SOUNDSTORE_H

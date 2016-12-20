#ifndef SOUNDSTORE_H
#define SOUNDSTORE_H

#include <QObject>
#include <QMediaPlayer>
#include <QSharedPointer>
#include "store.h"

class SoundStore : public QObject, public Store <SoundStore>
{
    Q_OBJECT
    Q_PROPERTY(qreal position READ getPersentPos WRITE setPosPersent NOTIFY posChanged)
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

  //  void posChanched(qint64 newPos);
protected:
    friend class Store;

    QMediaPlayer _player;
    QUrl _lastOpenedUrl;
    SoundStore(QObject *parent = 0);
};

#endif // SOUNDSTORE_H

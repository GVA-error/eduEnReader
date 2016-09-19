#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QObject>
#include <QtMultimedia/QMediaPlayer>

class SoundPlayer : public QObject
{
    Q_OBJECT
public:
    typedef QSharedPointer <SoundPlayer> PTR;
    static QSharedPointer <SoundPlayer> factoryMethod()
    {
        PTR rezPtr = QSharedPointer <SoundPlayer> (new SoundPlayer());
        return rezPtr;
    }

    SoundPlayer(QObject *parent = 0);
    void openFile(QString FileName);
signals:

public slots:
    void play(qint64 begin, qint64 end);

    void setPos(qint64);
    void start();
    void stop();
};

#endif // SOUNDPLAYER_H

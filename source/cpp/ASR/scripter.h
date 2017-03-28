#ifndef SCRIPTER_H
#define SCRIPTER_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QProcess>
#include <QTextStream>
#include <assert.h>

// Выполнение определённых скриптов
class Scripter : public QObject
{
    Q_OBJECT
public:
    explicit Scripter(QObject *parent = 0);

    // Извлекает аудиодорожку из *.mp4 файла
    // Возвращает имя получившевася файла
    QString extractAudio(const QString& videoFile);
    void noiseReduse(const QString& wavFile, const QString& noiseFile);
    void normalise(const QString& wavFile);

    // Выполнить скрипт c параметрами А
    void execute(const QStringList& A);
    void setExecutingScript(const QString& script){ _script = script; }

signals:
    // Возвращает вывод консоли
    void getConsoleOutput(const QString&);


public slots:
    void finished(int);
    void checkConsol();

private:
    QProcess *_console;
    QString _script;

    const QString _noiseReduseScrit = "/home/gva/eduEnReader/source/Scripts/noiseReduse.sh";
    const QString _normaliseScrit = "/home/gva/eduEnReader/source/Scripts/normalise.sh";
    const QString _extractSoundScrit = "/home/gva/eduEnReader/source/Scripts/extractSound.sh";

    const QString _tmp_wav = "/home/gva/eduEnReader/source/Scripts/tmp.wav";


};

#endif // SCRIPTER_H
#ifndef SCRIPTER_H
#define SCRIPTER_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QProcess>
#include <QTextStream>
#include <QDir>
#include <assert.h>

// Выполнение скриптов не требующих обратной связи
class Scripter : public QObject
{
    Q_OBJECT
public:
    static const QString _noiseReduseScrit;// = QDir::currentPath() + "/Scripts/noiseReduse.sh";
    static const QString _normaliseScrit;// = QDir::currentPath() + "/Scripts/normalise.sh";
    static const QString _extractSoundScrit;// = QDir::currentPath() + "/Scripts/extractSound.sh";
    static const QString _downloadBaseScript;// = QDir::currentPath() + "/Scripts/downloadBase.sh";
    static const QString _uploadBaseScript;// = QDir::currentPath() + "/Scripts/uploadBase.sh";
    static const QString _createPreviewScript; // = QDir::currentPath() + "/Scripts/createPreview.sh";
    static const QString _tmp_wav;// = QDir::currentPath() + "/Scripts/tmp.wav";

    explicit Scripter(QObject *parent = 0);

    // Извлекает аудиодорожку из *.mp4 файла
    // Возвращает имя получившевася файла
    QString extractAudio(const QString& videoFile);
    void noiseReduse(const QString& wavFile, const QString& noiseFile);
    void normalise(const QString& wavFile);
    void downloadBase();
    void uploadBase();
    void createPreview(const QString& videoFile, qreal duration);

    // Выполнить скрипт c параметрами А
    void execute(const QStringList& A);
    void setExecutingScript(const QString& script){ _script = script; }
    QString getLastOutput() { return _console->readAllStandardOutput(); }
    QString getLastError() { return _console->readAllStandardError(); }

signals:
    // Возвращает вывод консоли
    void getConsoleOutput(const QString&);


public slots:
    void finished(int);
    void checkConsol();

private:
    QProcess *_console;
    QString _script;

};

#endif // SCRIPTER_H

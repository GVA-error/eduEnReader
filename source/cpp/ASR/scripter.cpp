#include "scripter.h"

Scripter::Scripter(QObject *parent) : QObject(parent)
{
    _console = new QProcess();
    QObject::connect(_console, SIGNAL(finished(int)),
                     this, SLOT(finished(int)));
    QObject::connect(_console, SIGNAL(readyReadStandardOutput()),
                     this, SLOT(checkConsol()));
}

QString Scripter::extractAudio(const QString& videoFile)
{
    QFileInfo sourceInfo = QFileInfo(videoFile);
    QString rezFileName = sourceInfo.baseName() + ".wav";
    if (QFile::exists(rezFileName))
        QFile::remove(rezFileName);

    setExecutingScript(_extractSoundScrit);
    execute(QStringList() << videoFile << rezFileName);
    return rezFileName;
}

void Scripter::normalise(const QString& wavFile)
{
    setExecutingScript(_normaliseScrit);
    execute(QStringList() << wavFile << _tmp_wav);
    QFile::remove(wavFile);
    QFile::rename(_tmp_wav, wavFile);
}

void Scripter::noiseReduse(const QString& wavFile, const QString &noiseFile)
{
    setExecutingScript(_noiseReduseScrit);
    execute(QStringList() << wavFile << _tmp_wav << noiseFile);
    QFile::remove(wavFile);
    QFile::rename(_tmp_wav, wavFile);
}

void Scripter::execute(const QStringList& A)
{
   // _console->kill();
    _console->setWorkingDirectory("./");
    _console->start(_script, A);
    _console->waitForFinished(-1);
}

void Scripter::checkConsol()
{
    QString consoleOutput = _console->readAllStandardOutput();
    emit getConsoleOutput(consoleOutput);
}

void Scripter::finished(int succes)
{
    switch(succes)
    {
    case 0:
        qDebug()<< "generator script ok: " << succes;
        break;
    default:
    case -1:
    case -2:
        qCritical()<< "generator script failed:" << succes;
        assert(false);
        break;
    };
}

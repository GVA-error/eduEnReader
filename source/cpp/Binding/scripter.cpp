#include "scripter.h"

const QString Scripter::_noiseReduseScrit = QDir::currentPath() + "/Scripts/noiseReduse.sh";
const QString Scripter::_normaliseScrit = QDir::currentPath() + "/Scripts/normalise.sh";
const QString Scripter::_extractSoundScrit = QDir::currentPath() + "/Scripts/extractSound.sh";
const QString Scripter::_downloadBaseScript = QDir::currentPath() + "/Scripts/downloadBase.sh";
const QString Scripter::_initBaseScript = QDir::currentPath() + "/Scripts/initBase.sh";
const QString Scripter::_uploadBaseScript = QDir::currentPath() + "/Scripts/uploadBase.sh";
const QString Scripter::_createPreviewScript = QDir::currentPath() + "/Scripts/createPreview.sh";
const QString Scripter::_tmp_wav = QDir::currentPath() + "/Scripts/tmp.wav";

const QString Scripter::_baseDir = QDir::currentPath() + "/eduEnReaderBase";

Scripter::Scripter(QObject *parent) : QObject(parent)
{
    _console = new QProcess();
    QObject::connect(_console, SIGNAL(finished(int)),
                     this, SLOT(finished(int)));
    QObject::connect(_console, SIGNAL(readyReadStandardOutput()),
                     this, SLOT(checkConsol()));
}

void Scripter::createPreview(const QString &videoFile, qreal duration)
{
    setExecutingScript(_createPreviewScript);
    qint32 randomPersent = rand() % 100;
    QString time = "00:00:" + QString::number(duration*0.25 + randomPersent/100*0.5*duration);
    QFileInfo inputinfo(videoFile);
    QString previewFile = inputinfo.absolutePath() + "/" + inputinfo.baseName() + ".jpeg";
    if (QFile::exists(previewFile))
        QFile::remove(previewFile);
    execute(QStringList() << videoFile << time << previewFile);
}

void Scripter::downloadBase()
{
    if (QDir(_baseDir).exists()) // TODO заменить на константу из настроек
        setExecutingScript(_downloadBaseScript);
    else
        setExecutingScript(_initBaseScript);
    qDebug() << _script;
    execute(QStringList());
}

void Scripter::uploadBase()
{
    setExecutingScript(_uploadBaseScript);
    execute(QStringList());
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
    if (A.empty())
        _console->start(_script);
    else
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

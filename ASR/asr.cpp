#include "asr.h"

// для дебага
#include <QFile>

ASRLinuxKaldi::ASRLinuxKaldi()
{
    _console = new QProcess();
    QObject::connect(_console, SIGNAL(readyReadStandardOutput()),
                     this, SLOT(stringRecognized()));
    QObject::connect(_console, SIGNAL(finished(int)),
                     this, SLOT(allStringRecognized(int)));
}

QStringList ASRLinuxKaldi::getRecognized(const QString& fileName) const
{
    QStringList recognized = _fileSpeach.value(fileName);
    return recognized;
}

void ASRLinuxKaldi::recognize(const QString& fileName)
{
    QStringList args;
    args.push_back(fileName);
    startRecognizeScript(args);
}

void ASRLinuxKaldi::recognize(const QStringList& fileNames)
{
    QStringList args;
    for (auto fileName : fileNames)
        args.push_back(fileName);
    startRecognizeScript(args);
}

void ASRLinuxKaldi::stringRecognized()
{
    QString consoleOutput = _console->readAllStandardOutput();
    int exp_index = consoleOutput.indexOf(".wav");
    if (exp_index < 0)
    {
        qDebug() << consoleOutput << " incorrect consol out";
        return;
    }
    QStringList outputList = consoleOutput.split(" ", QString::SkipEmptyParts);
    _file_name = outputList[0];

    if (QFile(_file_name).exists()==false)
        _file_name = "wtf";

    outputList.pop_front();
    for (auto word : outputList)
    {
        word = word.toLower();
        _fileSpeach[_file_name].push_back(word);
    }
}

void ASRLinuxKaldi::allStringRecognized(int exitCode)
{
    switch(exitCode)
    {
    case 0:
        qDebug()<< "generator script ok:" << exitCode;
        break;
    default:
    case -1:
    case -2:
        qCritical()<< "generator script failed:" << exitCode;
        qDebug() << "ERR" << _console->readAllStandardError();
        qDebug() << "OUT" << _console->readAllStandardOutput();
        break;
    }
    emit SIGNAL(recognizeFinished(_file_name));
}

void ASRLinuxKaldi::startRecognizeScript(const QStringList &args)
{
    QString script;
    QString base = KALDI_PATH; //QApplication::applicationDirPath()+"/SSL";

    script = base + "wav_to_string.sh";

    //qDebug() << base << script << args;

    //QProcess proc;
    _console->setWorkingDirectory(base);
    _console->start(script, args);

    emit SIGNAL(recognizeBegan);

    // TODO для гуи не обязательно
    qint32 exitCode = -3;
    if(_console->waitForFinished(-1))
    {
       exitCode = _console->exitCode();

    }
}


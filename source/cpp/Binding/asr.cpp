#include "asr.h"

// для дебага
#include <QFile>

ASRScripter::ASRScripter()
{
    _console = new QProcess();
}

QStringList ASRScripter::getRecognized(const QString& fileName) const
{
    QStringList recognized = _fileSpeach.value(fileName);
    return recognized;
}

void ASRScripter::recognize(const QString& fileName)
{
    QStringList args;
    args.push_back(fileName);
    startRecognizeScript(args);
}

void ASRScripter::recognize(const QStringList& fileNames)
{
    QStringList args;
    for (auto fileName : fileNames)
        args.push_back(fileName);
    startRecognizeScript(args);
}

void ASRScripter::handleRecognizedString()
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
    for (QString word : outputList)
    {
        word = word.toLower();
        if (word.length() == 0 || word == "\n")
            continue;
        _fileSpeach[_file_name].push_back(word);
    }
    qDebug() << "recognized " << _fileSpeach[_file_name];
}

void ASRScripter::allStringRecognized(int exitCode)
{
    switch(exitCode)
    {
    case 0:
        qDebug()<< "generator script ok:" << exitCode
                << _fileSpeach[_file_name];
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

void ASRScripter::startRecognizeScript(const QStringList &args)
{
    _console->setWorkingDirectory(SCRIPT_PATH);
    _console->start(RECOGNIZE_SCRIPT, args);

    emit SIGNAL(recognizeBegan);

    // TODO для гуи не обязательно
    qint32 exitCode = -3;
    if(_console->waitForFinished(-1))
    {
        exitCode = _console->exitCode();
        handleRecognizedString();
    }
}


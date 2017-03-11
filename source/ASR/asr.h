#ifndef ASR_H
#define ASR_H

#include <QObject>
#include <QProcess>
#include <QString>
#include <QDebug>
#include <QList>
#include <QMap>

// TODO Выделить ScriptRecognize

// Интерфейс распознователя речи
class IASR : public QObject
{
    Q_OBJECT
public:
    // Синхронные методы
    virtual void recognize(const QStringList& fileNames) = 0;
    virtual void recognize(const QString& fileName) = 0;

    virtual QStringList getRecognized(const QString& fileName) const = 0;

signals:
    // Для взаимодействия с GUI, сигналы для вывода виджета ожидания
    void recognizeBegan();
    void recognizeFinished(const QString& fileName);
};

// Класс для распознования речи в wav файлах, на Linux, при помощи Kaldi
// Ограничения на wav:
// 1) Частота дискретизации 16000 Гц
// 2) Битрейд: 16 бит
// 3) Должны оканчиваться на *.wav
// Желательно длительность <= 7 секунд.
class ASRLinuxKaldi : public IASR
{
    Q_OBJECT
public:

    void recognize(const QStringList& fileNames) override;
    void recognize(const QString& fileName)  override;

    QStringList getRecognized(const QString& fileName) const  override;

    ASRLinuxKaldi();
signals:
   // void recognizeBegan();
   // void recognizeFinished(const QString& fileName);
public slots:
    void stringRecognized();
    void allStringRecognized(int exitCode);
private:
    // Путь до скрипта распознования
    const QString KALDI_PATH = "/home/gva/kaldi/egs/apiai_decode/s5/";
    // Скрипт распознования
    const QString RECOGNIZE_SCRIPT = KALDI_PATH + "wav_to_string.sh";

    QString _file_name;
    QMap <QString, QStringList> _fileSpeach;
    QProcess *_console;
    void startRecognizeScript(const QStringList& args);
};

#endif // ASR_H

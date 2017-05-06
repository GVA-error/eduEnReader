#ifndef BINDMAKER_H
#define BINDMAKER_H

#include <QObject>
#include <QMap>
#include <QThread>
#include <QtAlgorithms>
#include <QSet>
#include <QStringList>
#include "graph.h"
#include "metrics.h"
#include "cpp/textstore.h"
#include "cpp/soundstore.h"
#include "cpp/logic.h"
#include "cpp/Binding/datapreparation.h"
#include "cpp/Binding/asr.h"

#include <QFile>

// Даёт gui сигналы для привязки текста к звуку
class BindMaker : public QThread
{
    Q_OBJECT
public:
    typedef QSharedPointer <BindMaker> PTR;
    static QSharedPointer <BindMaker> factoryMethod(TextStore::PTR textStore, SoundStore::PTR soundStore, Logic::PTR logic)
    {
        PTR rezPtr = QSharedPointer <BindMaker> (new BindMaker(textStore, soundStore, logic));
        return rezPtr;
    }
    void setSplitSize(qreal splitSize, qreal diff = 0)
    {
        _splitSize = splitSize;
        _diff = diff;
    }
    explicit BindMaker(TextStore::PTR textStore, SoundStore::PTR soundStore, Logic::PTR logic);
    BindMaker() = delete;

    QString getCurState() { return _curState; }
    // Подготавливает звуковой файл к распознанию
signals:
    void process(); // Нужна для обновления индикатора процесса в GUI.
public slots:
    void runInThisThread(){ run(); }
protected:
    void run(); // запускает процесс биндинга
protected slots:
    void processLongestPath(qreal);
private:
    TextStore::PTR _textStore;
    SoundStore::PTR _soundStore;
    Logic::PTR _logic;

    QString _baseState = QString("Preparetion: %1\%\n") +
                         QString("Recognizing: %2\%\n") +
                         QString("Binding: %3\%\n");
    QString _curState;
    qreal _splitSize;
    qreal _diff;
    DataPreparation _preparator; // делит данные на куски и подготавливает их к распознованию
    IASR* _asr; // нужен для распознования речи, выделяется в конструкторе
    QMap <QString, qreal> _fileBeginOffset; // Нужен для поиска начала части файла, в распозновамом файле
    QMap <QString, qreal> _fileEndOffset; // Нужен для поиска конца части файла, в распозновамом файле
    QMap <QString, QStringList> _recognizedStrings; // Нужны для биндинга после подготовки
    //QStringList _preparad_recognizedStrings;

    QMap <QString, bool> _processList;
    QStringList _fileParts;
    // Неплохим вариантом было бы искать промежуточные бинды по функции энергии
    // Более продвинутым ариантом будет посчитать скорость произношения
    // или сколько раз сменилась частота
    // Однако для этого всего придётся считать кареляцию в обратную сторону

    QMap <QString, QList<qint64>> _localMin; // Локальные минимумы кореляционной функции частей файла (слов) к исходному тексту (в словах)
    QMap <QString, qint64> _textLength; // Количество символов в каждой распознаной строке

    // Описание кореляционной таблици
    /*QMap <QString, qint32> _tableStringToFileName;
    QMap <qint32, QString> _fileNameToTableString;
    QMap <qint32, qint32> _tableColumnToLocalMin;
    QMap <qint32, qint32> _localMinToTableColumn;
    QVector<QVector, QVector<bool>> _localMinsTable;
    */
    // ID для графа
    QMap <qint32, qint32> _IDToLoacalMin;
    QMap <QString, QMap <qint32, qint32>> _localMinToID;
    QMap <qint32, QString> _IDToFileName;

    // Список слов текста и их позции в исходном тексте
    QStringList _textList;
    QList <qint64> _textPos; // сопостовляет позицию в _textList с настоящей позицией в тексте

    // Заполняет мапы для графа и сам граф
    void fillInGraph(Graph& g);
    // ID локальный минимум конца, если данный локальный минимум соответствует реальной позиции в тексте
    qint64 getLocalMinEnd(const QString& fileName, qint32 localMinBegin, const QString& nextFileName) const;
    // Добавляет бинды  соответствующие списку ID
    void addBinsFromList(const QList<qint32> &localMinsIDlist) const;

    // Общее количество локальных минимумов - нужно для формирования графа
    qint32 getLocalMinNumber() const;

    // QMap <qint64, qint64> _posInText; // Узнаём по позиции в _textList позицию в тексте
    void textPreparetion(const QString& text); // заполняет _textList и _posInText

    void soundPreparetion(qreal splitSize, qreal diff = 0.0f); // В случаи фиксированного разбиения
    void soundPreparetion(); // В случаи известного разбиения // Из _logic
    void preparetion();
    void recognizing();
    void binding();

    void sortFileParts();

    qreal calcProgress() const;
    bool recognizeIsFinished();
    // Используя локальные минимумы функции кореляции,посчитанные при распозновании
    // Cчитаем привязку распознанных фраз к исходному тексту
    // Считаем только файлы из _processList
    void useLocalMinToFind_bind();

    // Добавляет бинд в начало и конец
    void addEdgeBinds(); // TODO Не работает, на и ненужна пока

    // Вычисляем точки локальных минимумов
    // maxWrongPersent = [0..1.0f] - максимально допустимая степень непохожести.
    // При 0.75 достаточно 1 правильного слова из 4 на своём месте.
    // При 0.25 - допускаеться только 4 неверно распознаных слова из 16.
    void calcLocalMin(const QString& partFileName, qreal maxWrongPersent = 0.85);

    // Сейчас считаеться кореляция распознонова к тексту
    // Берутся части из текста размером с распознаные
    // Возможно стоит делать наоборот, по скольку часть текста может быть не распознано
    // При этом маловероятно что после очистки от шума будет распознано что то лишнее
    // однако на данном этапе мы не избавляемся от звуков не являющихся голосом
    // Плюс так мы можем добавлять лишнее в тексте, оно будет проигнорировано
    QList <qint64> getCorelationFunc(const QStringList &recognizedString) const;

    // Нужна для поиска локального минимума кореляии текстов
    qint64 getDistance(const QStringList& firstSeqence, const QStringList& secondSeqence) const;
    void deleteNotAlpha(QString& str);

    void clear();
};

#endif // BINDMAKER_H

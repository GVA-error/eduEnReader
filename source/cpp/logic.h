#ifndef LOGIC_H
#define LOGIC_H

#include <QSharedPointer>
#include <QList>
#include <QVector>
#include <QTextStream>
#include "soundfragment.h"
#include "textfragment.h"

class Logic
{
public:
    const qint64 MAX_WORD_LEN = 1000;

    typedef QSharedPointer <Logic> PTR;
    static QSharedPointer <Logic> factoryMethod()
    {
        PTR rezPtr = QSharedPointer <Logic> (new Logic());
        return rezPtr;
    }

    struct Bind{
        TextFragment::PTR text;
        SoundFragment::PTR sound;
    };
    struct Comment{
        QString name;
        TextFragment::PTR commented;
        QUrl commentUrl;
    };
    struct Example{
        QUrl realUrl;
        QString FileName;
        QString text;
        QString exampableWord; // Слово для которого даём пример
        qreal start;
        qreal end;
    };
    enum patternTypes{ file, webPlus };
    struct Pattern{
        QString _title;
        QString _pattern;
        patternTypes _type;
    };

    qint32 moreOrLess(Bind bind, qreal soundPos, qint64 textPos) const;

    // Формирование списка примеров по искомой фразе
    // findInThisFile - искать ли в текущем файле
    QList <Example> getExamples(const QString& seakablePhrase, qreal minDuration, qreal maxDuration, bool findInThisFile = false) const;
    QList <Example> getExamplesInThis(const QString& seakablePhrase, qreal minDuration, qreal maxDuration); // Ищет только в текущем файле

    QString getUrlFromPattern(const Pattern&, QString str) const;
    QList <Pattern> getPatterns() { return _patternList; }

    QString getCurBndFileName() const { return _curBndFileName; }

    // Логически обрабатывает бинлы
    void bindLogicHanding();

    // Методы отвечающие за сохранение/чтение файлов
    // В файл биндов помимо названия файлов и самих биндов сохраняется MD5
    // Файлы должны хранится в одной директории, используются относительные пути
    // TODO копировать в новую директорию сохроняемые файлы
    // TODO Архивировать файлы
    void writeInFile(TextStore::PTR , SoundStore::PTR);
    void writeInFile(const QString& fileName, TextStore::PTR , SoundStore::PTR);
    void readFromFile(const QString& fileName, TextStore::PTR, SoundStore::PTR);
    // TODO проверять на пересоздание
    void createFromNewSoundFile(const QString& fileName, TextStore::PTR, SoundStore::PTR);

    // pos - номер бинда перед которым будет вставлен бинд
    void makeBind(TextFragment::PTR text, SoundFragment::PTR sound, qint64 pos = -1);
    void addRecognizedString(const QStringList& recognizedString, SoundFragment::PTR sound, QString fileName = QString());
    void addRecognizedString(const QStringList& recognizedString, qreal beginSound, qreal endSound, QString fileName = QString());
    bool haveRecognizedString() { _recognizedStrings.empty() == false; }

    void makeComment(TextFragment::PTR text, QUrl url, const QString &name);

    QMap <QString, QStringList> getRecognizedStrings() const { return _recognizedStrings; }
    QMap <QString, qreal> getRecognizedStringBeginList() const { return _recognizedStringPosBegin; }
    QMap <QString, qreal> getRecognizedStringEndList() const { return _recognizedStringPosEnd; }

    // Нужны для динамического позиционирования
    qint64 posInWavToPosInText(qreal) const; // по позиции в секундах, узнаёт позицию в интерпретированнном тексте
    qreal posInTxtToPosInWav(qint64) const; // по позиции в интерпретированном тексте узнаёт позицию в wav файле в секундах
    QList <QString> getCommentNamesonTextPos(qint64 begin, qint64 end) const; // по позиции в интерпритированном тексте возвращает url комментария
    QList <QString> getCommentNamesonTextPos(qint64 pos) const; // Если позиция принадлежит бинду, возвращает все комментарии пересекающие бинд
    QUrl getCommentUrlsonName(const QString &name) const;
    TextFragment::PTR getText(qint64 pos) const;
    SoundFragment::PTR getSound(qint64 pos) const;
    qint64 getBindNumber() const;

    // Для динамической подсветки
    void markBindFromSoundPos(qreal);
    void markBindFromTextPos(qint64);
    void unMarkBindFromSoundPos(qreal);
    void unMarkBindFromTextPos(qint64);
    void tempMarkBindInTextPos(qint64);
    void markAllBindedText(); // Ненужна
    void unMarkAllBindedText();
    void markLastBind();
    void unmarkLastBind();

    qint32 getTextMidPosCurBind() const; // Нужно для позиционирования на середину бинда
    qint32 getTextBeginPosCurBind() const; // .. начала
    qint32 getTextEndPosCurBind() const; // .. конец
    // Округляют до позиции в ближайшем бинде
    qint64 roundToBindTextPos(qint64) const;
    qreal roundToBindSoundPos(qreal) const;

    QString getTitle(const QUrl& bindFile) const;

    void clear(bool clearRecognized);
private:
    Logic();
    enum FileTypes{ sound, text, binds, undefined };

    const bool _findInSequence = true; // Поиск только целыми предложениями

    // Конфиг с патернами для поиска переводов
    const QString _sourceConfigFile = "./configs/sources.conf";
    QList <Pattern> _patternList;

    // Расширения потдерживаемых форматов файлов
    // Нужны для утановления типа открываемого файла или коректности охраняемого url
    const QStringList textFileExtension = {".txt", ""};
    const QStringList soundFileExtension = {".wav", ""};
    const QStringList bindFileExtension = {".bind", ""};
    // Константы для записи и парсинга файлов
    const QString par_Title = QString("title");
    const QString par_Pattern = QString("pattern");
    const QString par_Type = QString("type");
    const QString par_SoundStore = QString("soundStore");
    const QString par_TextStore = QString("textStore");
    const QString par_TextStoreHash = QString("MD5TextStore");
    const QString par_SoundStoreHash = QString("MD5SoundStore");
    const QString par_Bind = QString("Bind");
    const QString par_Comment = QString("Comment");
    const QString par_RecognizedString = QString("RecognizedString");
    const QString par_RecognizedStringPos = QString("RecognizedStringPos");

    // Возвращается если не нашли подходящего бинда
    // Иницилизирован в конструкторе
    Bind zeroBind; // Не стоит модифицировать, нейтрален отнасительно суммирования + используеться в лямдах
    Bind tempBind; // служит как временная переменная которую можно поменять, но она не на что не повличет

    QString _curBndFileName;

    //const qint32 _lastTempMarkListSize = 7;
   // Bind _lastTempMarkPos;
    QVector<Bind>::const_iterator _lastBindIterator;

    // Упорядоченное множество биндов
    // Нужно для подсветки и дихотомического поиска соответствующего выделения
    QVector <Bind> _bindVector;
    // Кеш, середин биндов
    QVector <qint32> _bindMid;

    QVector <Comment> _commentsVector; // Комментарии к тексту
    QMap <QString, QStringList> _recognizedStrings; // Распознаные строки из файла, нужны для быстрого перепросчёта
    QMap <QString, qreal> _recognizedStringPosBegin; // позициия в звуковом файле для каждого элемента _recognizedStrings
    QMap <QString, qreal> _recognizedStringPosEnd;

    // Добавление с сохранением порядка
    // Так же гарантирует что одновременно в списке биндов не будет ссылок на разные источники
    // pos - номер бинда перед которым будет вставлен бинд
    void addInBindList(const Bind&, qint64 pos = -1);
    void addInCommentList(const Comment&);

    QVector <Bind>::iterator getBindOnTextPos(qint64 pos); // Поиск бинда сответствующего позиции тексте

    // Нужен для установления типа файла при открытии
    FileTypes getFileType(const QString&) const;

    void synchPatterns();

    // Нужно переписать для динамических биндов
    bool haveIntersaption(const Bind&) const;
    bool haveIntersaption(const Bind& A, const Bind& B) const;

    void markBind(const Bind&);
    void unmarkBind(const Bind&);
    void markBind(const QList<Bind>&);
    void unmarkBind(const QList<Bind>&);

    QString toString(const Bind &) const;
    QString toString(const Comment &) const;
    void fromString(Comment&, QString stringComment, TextStore::PTR text);
    void fromString(Bind&, QString bindString, SoundStore::PTR sound, TextStore::PTR text) const;
    void fromString(QStringList& str, qreal& posBigin, qreal &posEnd, QString source) const; // нужна для чтения распозноного текста

    // Нужно для подсветки текущего фрагмента
    QVector <Bind>::const_iterator getBindFromSoundPos(qreal) const;
    QVector <Bind>::const_iterator getBindFromTextPos(qint64) const;
    // так как никогда не ищем одновременно по звуку и тексту используем "Or"
    QVector <Bind>::const_iterator getBindFromSoundOrTextPos(qreal soundPos, qint64 textPos) const;

    // Нужно для нахождения примеров
    QList<Bind> getBindsWithPhrase(const QString& seekablePhrase);

    void addWhileNotFindSentenceEnd(QVector <Logic::Bind>::iterator firstAdd, Logic::Bind& curBind, const QString& seekablePhrase, qint32 step) const;

    bool isEquils(const Bind& left, const Bind& right) const {
        auto l_sound = left.sound;
        auto l_text = left.text;
        auto r_sound = right.sound;
        auto r_text = right.text;
        return l_text->begin() == r_text->begin() && l_text->end() == r_text->end() &&
               l_sound->begin() == r_sound->begin() && l_sound->end() == r_sound->end();
    }

    Bind summ(const Bind& left, const Bind& right) const;
};

#endif // LOGIC_H

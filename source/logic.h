#ifndef LOGIC_H
#define LOGIC_H

#include <QSharedPointer>
#include <QList>
#include <QVector>
#include <QTextStream>
#include <soundfragment.h>
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

    struct Example{
        QUrl realUrl;
        QString FileName;
        QString text;
        qreal start;
        qreal end;
    };

    // Формирование списка примеров по искомой фразе
    // findInThisFile - искать ли в текущем файле
    QList <Example> getExamples(const QString& seakablePhrase, bool findInThisFile = false) const;
    QList <Example> getExamplesInThis(const QString& seakablePhrase) const; // Ищет только в текущем файле

    QString getCurBndFileName() const { return _curBndFileName; }

    // Логически обрабатывает бинлы
    void bindLogicHanding();

    // Методы отвечающие за сохранение/чтение файлов
    // В файл биндов помимо названия файлов и самих биндов сохраняется MD5
    // Файлы должны хранится в одной директории, используются относительные пути
    // TODO копировать в новую директорию сохроняемые файлы
    // TODO Архивировать файлы
    void writeInFile(const QString& fileName, TextStore::PTR , SoundStore::PTR );
    void readFromFile(const QString& fileName, TextStore::PTR, SoundStore::PTR);
    // TODO проверять на пересоздание
    void createFromNewSoundFile(const QString& fileName, TextStore::PTR, SoundStore::PTR);

    void makeBind(TextFragment::PTR text, SoundFragment::PTR sound, const QString& recognizedText);
    void makeComment(TextFragment::PTR text, QUrl url);

    QStringList getRecognizedStrings() const { return _recognizedStrings; }
    qreal getRecognizedStringBegin(qint64 stringNumber) const { return _recognizedStringPosBegin.value(stringNumber);}
    qreal getRecognizedStringEnd(qint64 stringNumber) const { return _recognizedStringPosEnd.value(stringNumber);}

    // Нужны для динамического позиционирования
    qint64 posInWavToPosInText(qreal) const; // по позиции в секундах, узнаёт позицию в интерпретированнном тексте
    qreal posInTxtToPosInWav(qint64) const; // по позиции в интерпретированном тексте узнаёт позицию в wav файле в секундах
    QList <QString> getCommentNamesonTextPos(qint64 begin, qint64 end) const; // по позиции в интерпритированном тексте возвращает url комментария
    QList <QString> getCommentNamesonTextPos(qint64 pos) const; // Если позиция принадлежит бинду, возвращает все комментарии пересекающие бинд
    QUrl getCommentUrlsonName(const QString &name) const;

    // Для динамической подсветки
    void markBindFromSoundPos(qreal);
    void markBindFromTextPos(qint64);
    void unMarkBindFromSoundPos(qreal);
    void unMarkBindFromTextPos(qint64);
    void tempMarkBindInTextPos(qint64);
    void markAllBindedText(); // Ненужна
    void unMarkAllBindedText();
    // Округляют до позиции в ближайшем бинде
    qint64 roundToBindTextPos(qint64) const;
    qreal roundToBindSoundPos(qreal) const;

    void clear(bool clearRecognized);
private:
    Logic();
    enum FileTypes{ sound, text, binds, undefined };

    // Расширения потдерживаемых форматов файлов
    // Нужны для утановления типа открываемого файла или коректности охраняемого url
    const QStringList textFileExtension = {".txt", ""};
    const QStringList soundFileExtension = {".wav", ""};
    const QStringList bindFileExtension = {".bind", ""};
    // Константы для записи и парсинга файлов
    const QString par_SoundStore = QString("soundStore");
    const QString par_TextStore = QString("textStore");
    const QString par_TextStoreHash = QString("MD5TextStore");
    const QString par_SoundStoreHash = QString("MD5SoundStore");
    const QString par_Bind = QString("Bind");
    const QString par_Comment = QString("Comment");
    const QString par_RecognizedString = QString("RecognizedString");
    const QString par_RecognizedStringPos = QString("RecognizedStringPos");

    // Нужен для установления типа файла при открытии
    FileTypes getFileType(const QString&) const;

    struct Bind{
        TextFragment::PTR text;
        SoundFragment::PTR sound;
    };
    struct Comment{
        QString name;
        TextFragment::PTR commented;
        QUrl commentUrl;
    };

    // Возвращается если не нашли подходящего бинда
    // Иницилизирован в конструкторе
    Bind zeroBind; // Не стоит модифицировать
    Bind tempBind; // служит как временная переменная которую можно поменять, но она не на что не повличет

    QString _curBndFileName;
    qint64 _lastTempMarkPos;

    // Упорядоченное множество биндов
    // Нужно для подсветки и дихотомического поиска соответствующего выделения
    QVector <Bind> _bindVector;
    QVector <Comment> _commentsVector; // Комментарии к тексту
    QStringList _recognizedStrings; // Распознаные строки из файла, нужны для быстрого перепросчёта
    QMap <qint64, qreal> _recognizedStringPosBegin; // позициия в звуковом файле для каждого элемента _recognizedStrings
    QMap <qint64, qreal> _recognizedStringPosEnd;

    // Добавление с сохранением порядка
    // Так же гарантирует что одновременно в списке биндов не будет ссылок на разные источники
    void addInBindList(const Bind&);
    void addInRecognizedList(const QString& recognizedString, qreal beginSound, qreal endSound);
    void addInCommentList(const Comment&);

    QVector <Bind>::iterator getBindOnTextPos(qint64 pos); // Поиск бинда сответствующего позиции тексте

    // Нужно переписать для динамических биндов
    bool haveIntersaption(const Bind&) const;
    bool haveIntersaption(const Bind& A, const Bind& B) const;

    void markBind(const Bind&);

    QString toString(const Bind &) const;
    QString toString(const Comment &) const;
    void fromString(Comment&, QString stringComment, TextStore::PTR text);
    void fromString(Bind&, QString bindString, SoundStore::PTR sound, TextStore::PTR text) const;
    void fromString(QString& str, qreal& posBigin, qreal &posEnd, QString source) const; // нужна для чтения распозноного текста

    // Нужно для подсветки текущего фрагмента
    Bind getBindFromSoundPos(qreal) const;
    Bind getBindFromTextPos(qint64) const;
    Bind getBindFromSoundOrTextPos(qreal soundPos, qint64 textPos) const;

    // Нужно для нахождения примеров
    QList<Bind> getBindsWithPhrase(const QString& seekablePhrase) const;

    bool isEquils(const Bind& left, const Bind& right) const {
        auto l_sound = left.sound;
        auto l_text = left.text;
        auto r_sound = right.sound;
        auto r_text = right.text;
        return l_text->begin() == r_text->begin() && l_text->end() == r_text->end() &&
               l_sound->begin() == r_sound->begin() && l_sound->end() == r_sound->end();
    }
};

#endif // LOGIC_H

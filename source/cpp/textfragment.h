#ifndef TEXTFRAGMENT_H
#define TEXTFRAGMENT_H

#include <QTypeInfo>
#include <QSharedPointer>
#include "textstore.h"
#include "fragment.h"

// служит для обмена текстом
class TextFragment : public Fragment <TextFragment, TextStore::PTR, qint64>
{
public:
    // Метод в локальных координатах
    QChar getSymbol(qint64 i) const;
    QString getString() const;

    qint64 getFragmentLength() const;

    // Нужно для подсвечивания текста
    void mark();
    void unmark();

    QColor getRandomMarkColor(); // Случайный цвет подсветки текста

    // Нужна для поиска примеров и подсветки синтаксиса
    // Ищет индекс искомой фразы с учётом регулярок
    qint64 indexOf(const QString& seekablePhrase) const;
    // Сравнивает по регулярке сравнения из настроек слова
    static bool isEquils(QString left, QString right);
    static QString getRoot(QString word);

    bool havePointBeforePos(qint64 pos);
    bool havePointAfterPos(qint64 pos);

    // Немного гавнокода...
//    bool isPhraseInMidSentance(const QString& phrase) const; // Проверяет обрамлена ли хотя бы одна фраза символами конца строки
//    bool haveSentanceEndPrev(const QString& phrase) const;// Проверет есть ли знак конца строки перед фразой
//    bool haveSentanceEndPost(const QString& phrase) const;// .. После

//    // TODO заменить на простой поиск
//    // egeOffset - какую часть фрагмента считаем не верно распознаной
//    bool havePhraseOnMid(const QString& phrase, qreal egeOffset = 0.25) const;
//    bool havePhraseOnBegin(const QString& phrase, qreal egeOffset = 0.25) const;
//    bool havePhraseOnEnd(const QString& phrase, qreal egeOffset = 0.25) const;

    virtual ~TextFragment() {}
private:
    const QRegExp _sentenceEndSymbols = QRegExp("[.!?]"); // Символы конца строки
    //const QRegularExpression _sentenceBeginSymbols = QRegularExpression("^(A-Z)"); // .. Начала

    friend class Fragment <TextFragment, TextStore::PTR, qint64>;
    TextFragment() = delete;
    // В глобальных координатах
    TextFragment(qint64 begin, qint64 end, TextStore::PTR source)
        : Fragment(begin, end, source) { }
};

#endif // TEXTFRAGMENT_H

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
    void mark(); // Подсветка случайным цвета
    void mark(const QColor&); // .. конкретным цветом
    void unmark();

    QColor getRandomMarkColor(); // Случайный цвет подсветки текста

    bool havePhrase(const QString& phrase) const;

    virtual ~TextFragment() {}
private:
    friend class Fragment <TextFragment, TextStore::PTR, qint64>;
    TextFragment() = delete;
    // В глобальных координатах
    TextFragment(qint64 begin, qint64 end, TextStore::PTR source)
        : Fragment(begin, end, source) { }
};

#endif // TEXTFRAGMENT_H

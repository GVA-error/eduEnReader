#ifndef TEXTFRAGMENT_H
#define TEXTFRAGMENT_H

#include <QTypeInfo>
#include <QSharedPointer>
#include "textstore.h"

// служит для обмена текстом
class TextFragment
{
public:
    typedef QSharedPointer <TextFragment> PTR;
    static QSharedPointer <TextFragment> factoryMethod(qint64 begin, qint64 end, TextStore::PTR source)
    {
        PTR rezPtr = QSharedPointer <TextFragment> (new TextFragment(begin, end, source));
        return rezPtr;
    }
    static QSharedPointer <TextFragment> factoryMethod(qint64 begin, qint64 end, TextFragment::PTR source)
    {
        PTR rezPtr = QSharedPointer <TextFragment> (new TextFragment(begin, end, source));
        return rezPtr;
    }

    // Глобальные Begin End
    qint64 begin() const { return _begin; }
    qint64 end() const { return _end; }

    // Метод в локальных координатах
    QChar getSymbol(qint64 i) const;
    QString getString() const;

    qint64 getFragmentLength() const;

private:
    TextFragment() = delete;
    // В глобальных координатах
    TextFragment(qint64 begin, qint64 end, TextStore::PTR);
    // В координатах фрагмента источника
    TextFragment(qint64 begin, qint64 end, TextFragment::PTR);

    qint64 _begin;
    qint64 _end;
    TextStore::PTR _source;
};

#endif // TEXTFRAGMENT_H

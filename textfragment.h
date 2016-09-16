#ifndef TEXTFRAGMENT_H
#define TEXTFRAGMENT_H

#include <QTypeInfo>
#include <QSharedPointer>
#include "textstore.h"

class TextFragment
{
public:
    typedef QSharedPointer <TextFragment> PTR;
    static QSharedPointer <TextFragment> factoryMethod(qint64 begin, qint64 end)
    {
        PTR rezPtr = QSharedPointer <TextFragment> (new TextFragment(begin, end));
        return rezPtr;
    }

private:
    TextFragment() = delete;
    TextFragment(qint64 begin, qint64 end);

    qint64 _begin;
    qint64 _end;
};

#endif // TEXTFRAGMENT_H

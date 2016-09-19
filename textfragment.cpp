#include "textfragment.h"

TextFragment::TextFragment(qint64 begin, qint64 end, TextStore::PTR source)
{
    _begin = begin;
    _end = end;
    _source = source;
}

TextFragment::TextFragment(qint64 begin, qint64 end, TextFragment::PTR source)
{
    qint64 globalShift = source->begin();
    _begin = begin + globalShift;
    _end = end + globalShift;
    _source = source->_source;
}

QString TextFragment::getString() const
{
    QString rezString = _source->getString(_begin, _end);
    return rezString;
}

QChar TextFragment::getSymbol(qint64 i) const
{
    QChar rezChar = getString()[0];
    return rezChar;
}

qint64 TextFragment::getFragmentLength() const
{
    return _end-_begin;
}


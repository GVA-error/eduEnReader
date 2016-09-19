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

char TextFragment::getSymbol(qint64 i)
{
    // TODO работа с документом
    return -1;
}

qint64 TextFragment::getFragmentLength()
{
    // TODO работа с документом
    return -1;
}

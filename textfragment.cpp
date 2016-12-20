#include "textfragment.h"

QString TextFragment::getString() const
{
    QString rezString = _source->getString(_begin, _end);
    return rezString;
}

QChar TextFragment::getSymbol(qint64 i) const
{
    QChar rezChar = getString().at(i);
    return rezChar;
}

qint64 TextFragment::getFragmentLength() const
{
    return _end-_begin;
}

void TextFragment::unmark()
{
    mark(Qt::GlobalColor::white);
}

void TextFragment::mark()
{
    QColor mColor = getRandomMarkColor();
    mark(mColor);
}

void TextFragment::mark(const QColor& color)
{
    qint64 oldSellectionStart = _source->selectionStart();
    qint64 oldSellectionEnd = _source->selectionEnd();

    _source->setSelectionStart(_begin);
    _source->setSelectionEnd(_end);
    _source->setTextBackground(color);

    _source->setSelectionStart(oldSellectionStart);
    _source->setSelectionEnd(oldSellectionEnd);
}

QColor TextFragment::getRandomMarkColor()
{
    // Покаа берём любой цвет
    QColor rColor;
    qint32 r = 0;
    qint32 g = 0;
    qint32 b = 255;
    qint32 a = 150;
    QRgb rRGBA = qRgba(r, g, b, a);
    rColor.setRgba(rRGBA);
    return rColor;
}

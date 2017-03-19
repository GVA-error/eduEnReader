#include "textfragment.h"

bool TextFragment::havePhrase(const QString& phrase, qreal egeOffset) const
{
    assert(egeOffset > 0 && egeOffset < 0.5);
    QString fragmentString = getString();
    qint32 l = fragmentString.length();
    qint32 newl = l * (1-egeOffset*2);
    qint32 offset = l * egeOffset;
    fragmentString = fragmentString.mid(offset, newl);
    // Допустимые варианты
    QStringList vars;
    vars.push_back(" " + phrase + " ");
    vars.push_back(" " + phrase + ",");
    vars.push_back(" " + phrase + ":");
    vars.push_back(" " + phrase + ".");
    vars.push_back(" " + phrase + "?");
    vars.push_back(" " + phrase + "!");
    vars.push_back(" " + phrase + ".");

    for (auto var : vars)
        if (fragmentString.contains(var))
            return true;
    return false;
}


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
    if (_source.isNull()) // Случай нулевого бинда
        return;
    qint64 oldSellectionStart = _source->selectionStart();
    qint64 oldSellectionEnd = _source->selectionEnd();

    _source->setSelectionStart(_begin);
    _source->setSelectionEnd(_end);
    _source->setUnMarkText();

    _source->setSelectionStart(oldSellectionStart);
    _source->setSelectionEnd(oldSellectionEnd);
}


void TextFragment::mark()
{
    if (_source.isNull()) // Случай нулевого бинда
        return;
    qint64 oldSellectionStart = _source->selectionStart();
    qint64 oldSellectionEnd = _source->selectionEnd();

    _source->setSelectionStart(_begin);
    _source->setSelectionEnd(_end);
    _source->setMarkText();

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

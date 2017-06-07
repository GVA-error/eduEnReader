#include "textfragment.h"



bool TextFragment::havePointBeforePos(qint64 pos)
{
    if (pos < begin())
        return false;
    if (begin() > 1) // TODO Не тестилось
        setBegin(begin()-2); // чтобы учесть точку сразу перед фрагментом
    QString str = getString();
    if (begin() > 1)
        setBegin(begin()+2); // Если имеються бинды на более ранних позициях будет захвачено больше чем надо - маловероятно
    qint64 localPos = pos - begin();
    if (localPos >= size())
        localPos = -1;

    if (str.lastIndexOf(QRegExp("[.?!]"), localPos) == -1)
        return false;
    return true;
}

bool TextFragment::havePointAfterPos(qint64 pos)
{
    if (pos > end())
        return false;
    QString str = getString();
    qint64 localPos = pos - begin();
    if (localPos < 0)
        localPos = 0;
    if (str.indexOf(QRegExp("[.?!]"), localPos) == -1)
        return false;
    return true;
}

qint64 TextFragment::indexOf(const QString& seekablePhrase) const
{
    QString string = getString();
    QStringList stringList = string.split(QRegExp("\\W"), QString::SkipEmptyParts);
    QStringList seekableStringList = seekablePhrase.split(QRegExp("\\W"), QString::SkipEmptyParts);
    QStringList rootStringList;
    QStringList rootSeekableStringList;
    for (auto str : stringList)
    {
        QString root = getRoot(str);
        rootStringList.push_back(root);
    }
    for (auto str : seekableStringList)
    {
        QString root = getRoot(str);
        rootSeekableStringList.push_back(root);
    }
    qint64 splitIndex = -1;
    //for (auto string : rootStringList)
    //    if (string == )

    // TODO стоит ли?
    assert(false);
    //rootStringList.indexOf(rootSeekableStringList);


    if (splitIndex == -1)
        return -1;
    qint64 length = 0;
    auto cur = stringList.begin();
    for (qint64 i = 0; i<splitIndex; i++)
    {
        QString curString = *cur;
        length += curString.length();
        cur++;
    }
    return length;
}

QString TextFragment::getRoot(QString word)
{
    QString postFix = Settings::get(Settings::postfix, Settings::Examples).toString();
    QRegExp withPostFixReg("(\\w+)(" + postFix + ")$");

    int pos = withPostFixReg.indexIn(word, 0);
    if (pos == -1)
        return word;
    return withPostFixReg.cap(1);
}

bool TextFragment::isEquils(QString left, QString right)
{
    left = left.toLower();
    right = right.toLower();

    QString leftRoot = getRoot(left);
    QString rightRoot = getRoot(right);

    return leftRoot == rightRoot;
}
//bool TextFragment::isPhraseInMidSentance(const QString& phrase) const
//{
//    QString curString = getString();
//    auto endIndexBegin = curString.indexOf(_sentenceEndSymbols);
//    auto endIndexEnd = curString.lastIndexOf(_sentenceEndSymbols);

//    auto phraseIndex = curString.indexOf(phrase, endIndexBegin);
//    if (endIndexEnd < 0 || endIndexBegin < 0 || phraseIndex < 0)
//        return false;
//    if (phraseIndex <= endIndexEnd)
//        return true;
//    return false;
//}

//bool TextFragment::haveSentanceEndPrev(const QString& phrase) const
//{
//    QString curString = getString();
//    auto endIndex = curString.indexOf(_sentenceEndSymbols);
//    if (endIndex == -1)
//        return false;
//    auto phraseIndex = curString.indexOf(phrase);
//    if (phraseIndex < 0)
//        return false;
//    if (phraseIndex >= endIndex)
//        return true;
//    return false;
//}

//bool TextFragment::haveSentanceEndPost(const QString& phrase) const
//{
//    QString curString = getString();
//    auto endIndex = curString.lastIndexOf(_sentenceEndSymbols);
//    if (endIndex == -1)
//        return false;
//    auto phraseIndex = curString.lastIndexOf(phrase);
//    if (phraseIndex < 0)
//        return false;
//    if (phraseIndex <= endIndex)
//        return true;
//    return false;
//}

//bool TextFragment::havePhraseOnMid(const QString& phrase, qreal egeOffset) const
//{
//    assert(egeOffset > 0 && egeOffset < 0.5);
//    QString fragmentString = getString();
//    qint32 l = fragmentString.length();
//    qint32 offset = l * egeOffset;
//    QStringList textList = fragmentString.split(QRegExp("\\b"));
//    qint64 begin = 0;
//    for (auto str : textList)
//    {
//        qint64 end = begin + str.length();
//        if (str == phrase)
//            if (end > offset && begin < l - offset)
//                return true;
//        begin = end;
//    }
//    return false;
//}

//bool TextFragment::havePhraseOnBegin(const QString& phrase, qreal egeOffset) const
//{
//    assert(egeOffset > 0 && egeOffset < 0.5);
//    QString fragmentString = getString();
//    qint32 l = fragmentString.length();
//    qint32 offset = l * egeOffset;
//    QStringList textList = fragmentString.split(QRegExp("\\b"));
//    qint64 begin = 0;
//    for (auto str : textList)
//    {
//        qint64 end = begin + str.length();
//        if (str == phrase)
//            if (end < offset)
//                return true;
//        begin = end;
//    }
//    return false;
//}

//bool TextFragment::havePhraseOnEnd(const QString& phrase, qreal egeOffset) const
//{
//    assert(egeOffset > 0 && egeOffset < 0.5);
//    QString fragmentString = getString();
//    qint32 l = fragmentString.length();
//    qint32 offset = l * egeOffset;
//    QStringList textList = fragmentString.split(QRegExp("\\b"));
//    qint64 begin = 0;
//    for (auto str : textList)
//    {
//        qint64 end = begin + str.length();
//        if (str == phrase)
//            if (begin > l - offset)
//                return true;
//        begin = end;
//    }
//    return false;
//}

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

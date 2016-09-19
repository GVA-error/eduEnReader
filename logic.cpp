#include "logic.h"

Logic::Logic()
{

}

void Logic::clear()
{
    _bindList.clear();
    _bindVector.clear();
}

void Logic::setReadRegim()
{
    _readRegim = true;
}

// При смене режимов необходимо чистить все списки
void Logic::setWriteRegim()
{
    _readRegim = false;
}

void Logic::bind(qint64 beginTextPos, qint64 endTextPos, qint64 beginSoundPos, qint64 endSoundPos)
{
    Bind b;
    b.beginSoundPos = beginSoundPos;
    b.endSoundPos = endSoundPos;
    b.beginTextPos = beginTextPos;
    b.endTextPos = endTextPos;

    Q_ASSERT(!haveIntersaption(b)); // TO DO заменить на затирание бинда
    _bindList.push_back(b);
}

void Logic::autoBinding(const SoundStore::PTR soundReader)
{
    QList <qint64> begin_End_TextPos;
    for (auto bind : _bindList)
    {
        begin_End_TextPos.push_back(bind.beginTextPos);
        begin_End_TextPos.push_back(bind.endTextPos);
    }
    autoBinding(begin_End_TextPos, soundReader);
}

void Logic::autoBinding(QList <qint64> begin_End_TextPos, const SoundStore::PTR soundReader)
{
    qint64 lastSoundEnd = 0;
    for (auto begin = begin_End_TextPos.begin(); begin+2 != begin_End_TextPos.end(); begin += 2)
    {
        qint64 beginSoundRange = lastSoundEnd;
        qint64 endSoundRange = lastSoundEnd + 10; // считаем что не выделенно фраз больше 10 секунд
        qint64 beginText = *begin;
        qint64 endText = *(begin+1);
        autoBind(beginText, endText, beginSoundRange, endSoundRange, soundReader);
    }
}

bool Logic::haveIntersaption(const Bind& A, const Bind& B) const
{
    if (A.beginTextPos >= B.beginTextPos && A.beginTextPos <= B.endTextPos)
        return true;
    if (A.endTextPos >= B.beginTextPos && A.endTextPos <= B.endTextPos)
        return true;
    return false;
}

bool Logic::haveIntersaption(const Bind& newBind) const
{
    for (auto bind : _bindList)
        if (haveIntersaption(bind, newBind))
            return true;
    return false;
}

void Logic::autoBind(qint64 beginText, qint64 endText, qint64 beginSoundRange, qint64 endSoundRange, const SoundStore::PTR soundReader)
{
    Bind newBind = getAutoBind(beginText, endText, beginSoundRange, endSoundRange, soundReader);
    Q_ASSERT(!haveIntersaption(newBind));
    _bindList.push_back(newBind);
}

// Желательно искать начало и конец фразы
Logic::Bind Logic::getAutoBind(qint64 beginText, qint64 endText, qint64 beginSoundRange, qint64 endSoundRange, const SoundStore::PTR soundReader) const
{

}

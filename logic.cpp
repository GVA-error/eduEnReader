#include "logic.h"

Logic::Logic()
{

}

void Logic::clear()
{
    _staticBindList.clear();
    _staticBindVector.clear();
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

void Logic::bind(TextFragment::PTR text, SoundFragment::PTR sound)
{
    staticBind b;
    b.text = text;
    b.sound = sound;

    Q_ASSERT(!haveIntersaption(b)); // TO DO заменить на затирание бинда
    _staticBindList.push_back(b);
}

void Logic::autoBinding()
{
    const qint64 maxSintanceSize = 100000; // Можно вычислить для каждой фразы исходя из её длинны
    auto firstSound = _staticBindList.front();
    auto lastSound = SoundFragment::factoryMethod(0, 0, firstSound.sound);
    for (auto bind : _staticBindList)
    {
        qint64 lastPos = bind.text->getFragmentLength();
        auto curTextFragment = TextFragment::factoryMethod(0, lastPos, bind.text);
        qint64 beginSoundRange = lastSound->getSampleNumber();
        qint64 endSoundRange = beginSoundRange + maxSintanceSize;
        auto curSoundFragment = SoundFragment::factoryMethod(beginSoundRange, endSoundRange, lastSound);

        autoBind(curTextFragment, curSoundFragment);
        lastSound = bind.sound;
    }
}

bool Logic::haveIntersaption(const staticBind &A, const staticBind &B) const
{
    if (A.text->begin() >= B.text->begin() && A.text->end() <= B.text->end())
        return true;
    if (A.sound->begin() >= B.sound->begin() && A.sound->end() <= B.sound->end())
        return true;
    return false;
}

bool Logic::haveIntersaption(const staticBind& newBind) const
{
    for (auto bind : _staticBindList)
        if (haveIntersaption(bind, newBind))
            return true;
    return false;
}

void Logic::autoBind(TextFragment::PTR text, SoundFragment::PTR sound)
{
    staticBind newBind = getAutoBind(text, sound);
    Q_ASSERT(!haveIntersaption(newBind));
    _staticBindList.push_back(newBind);
}

SoundFragment::PTR Logic::getBindedSound(qint64 textPos)
{
    for (auto bind : _staticBindList)
    {
        if (bind.text->begin() <= textPos && bind.text->end() >= textPos)
            return bind.sound;
    }
    //auto defaultSound = _staticBindList.front().sound;
    return SoundFragment::factoryMethod(0, 0, SoundStore::PTR());
}

// Желательно искать начало и конец фразы
Logic::staticBind Logic::getAutoBind(TextFragment::PTR text, SoundFragment::PTR sound) const
{

}

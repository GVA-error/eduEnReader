#ifndef LOGIC_H
#define LOGIC_H

#include <QSharedPointer>
#include <QList>
#include <QVector>
#include <soundfragment.h>
#include "soundfragment.h"
#include "textfragment.h"

class Logic
{
public:
    typedef QSharedPointer <Logic> PTR;
    static QSharedPointer <Logic> factoryMethod()
    {
        PTR rezPtr = QSharedPointer <Logic> (new Logic());
        return rezPtr;
    }

    void autoBinding();
    void bind(TextFragment::PTR, SoundFragment::PTR);

    void setReadRegim();
    void setWriteRegim();

    void clear();
    Logic();

private:
    struct Bind{
        TextFragment::PTR text;
        SoundFragment::PTR sound;
    };
    bool _readRegim = false; // глобальный режим

    QVector <Bind> _bindVector;
    QList <Bind> _bindList;

    bool haveIntersaption(const Bind&) const;
    bool haveIntersaption(const Bind& A, const Bind& B) const;

    void autoBind(TextFragment::PTR, SoundFragment::PTR);
    Bind getAutoBind(TextFragment::PTR text, SoundFragment::PTR sound) const;
};

#endif // LOGIC_H

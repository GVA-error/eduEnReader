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

    SoundFragment::PTR getBindedSound(qint64 textPos);

    void autoBinding();
    void bind(TextFragment::PTR, SoundFragment::PTR);

    void setReadRegim();
    void setWriteRegim();

    void clear();
    Logic();

private:
    struct dinamicBind
    {
        qint64 distanceToLast;
        SoundFragment::PTR sound;
    };

    struct staticBind{
        TextFragment::PTR text;
        SoundFragment::PTR sound;
    };
    bool _readRegim = false; // глобальный режим

    QVector <staticBind> _staticBindVector; // В данный моммент работаем со статичным текстом
    QList <staticBind> _staticBindList;

    // Нужно переписать для динамических биндов
    bool haveIntersaption(const staticBind &) const;
    bool haveIntersaption(const staticBind& A, const staticBind& B) const;

    void autoBind(TextFragment::PTR, SoundFragment::PTR);
    staticBind getAutoBind(TextFragment::PTR text, SoundFragment::PTR sound) const;
};

#endif // LOGIC_H

#ifndef LOGIC_H
#define LOGIC_H

#include <QSharedPointer>
#include <QList>
#include <QVector>
#include <soundfragment.h>

class Logic
{
public:
    typedef QSharedPointer <Logic> PTR;
    static QSharedPointer <Logic> factoryMethod()
    {
        PTR rezPtr = QSharedPointer <Logic> (new Logic());
        return rezPtr;
    }

    void autoBinding(const SoundStore::PTR soundReader);
    void bind(qint64 beginTextPos, qint64 endTextPos, qint64 beginSoundPos, qint64 endSoundPos);

    void setReadRegim();
    void setWriteRegim();

    void clear();
    Logic();

private:
    struct Bind{
        qint64 beginTextPos;
        qint64 endTextPos;
        qint64 beginSoundPos;
        qint64 endSoundPos;
    };
    bool _readRegim = false; // глобальный режим

    QVector <Bind> _bindVector;
    QList <Bind> _bindList;

    bool haveIntersaption(const Bind&) const;
    bool haveIntersaption(const Bind& A, const Bind& B) const;

    void autoBind(qint64 beginText, qint64 endText, qint64 beginSoundRange, qint64 endSoundRange, const SoundStore::PTR soundReader);
    Bind getAutoBind(qint64 beginText, qint64 endText, qint64 beginSoundRange, qint64 endSoundRange, const SoundStore::PTR soundReader) const;

    void autoBinding(QList <qint64> begin_End_TextPos, const SoundStore::PTR);
};

#endif // LOGIC_H

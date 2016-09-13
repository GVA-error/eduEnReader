#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>

template <class C>
class Factory
{
public:
    typedef QSharedPointer <C> PTR;
    static PTR createPointer()
    {
        Factory::PTR rezPtr = QSharedPointer <C> (new C());
        return rezPtr;
    }

};

#endif // FACTORY_H

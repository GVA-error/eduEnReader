#ifndef LOGIC_H
#define LOGIC_H

#include <QSharedPointer>

class Logic
{
public:
    typedef QSharedPointer <Logic> PTR;
    static QSharedPointer <Logic> factoryMethod()
    {
        PTR rezPtr = QSharedPointer <Logic> (new Logic());
        return rezPtr;
    }

    Logic();

private:

};

#endif // LOGIC_H

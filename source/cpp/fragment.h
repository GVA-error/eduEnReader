#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <QDebug>
#include <assert.h>

// Базовый класс для различных фрагментов
// По сути фабрика, реализует пару protected конструкторов но использует для фабричных методов конструкторы наследника,
// Поэтому данный класс должен быть добавлен в друзья
//

template <class ThisType, class PTRSourceType, class IndexType>
class Fragment
{
public:
    typedef QSharedPointer <ThisType> PTR;
    static QSharedPointer <ThisType> factoryMethod(IndexType begin, IndexType end, PTRSourceType source)
    {
        if (begin > end)
            qCritical("Incorrect feagments");
        PTR rezPtr = QSharedPointer <ThisType> (new ThisType(begin, end, source));
        return rezPtr;
    }
    static PTR summ(PTR left, PTR right)
    {
        IndexType rezBegin = left->begin();
        IndexType rezEnd = right->end();
        PTRSourceType leftSource = left->getSource();
        PTRSourceType rightSource = right->getSource();
        if (leftSource.data() == nullptr)
            return right;
        if (rightSource.data() == nullptr)
            return left;
        assert(leftSource.data() == rightSource.data()); // разные источники не складываем
        PTRSourceType rezSourse = leftSource;
        PTR rezPtr = QSharedPointer <ThisType> (new ThisType(rezBegin, rezEnd, rezSourse));;
        return rezPtr;
    }

    void setEnd(IndexType newEnd) { _end = newEnd; }
    void setBegin(IndexType newBegin) { _begin = newBegin; }
    // Методы в глобальных координатах
    IndexType begin() const { return _begin; }
    IndexType end() const { return _end; }

    IndexType mid() const { return (_begin + _end) / 2; }

    IndexType size() const { return _end - _begin; }

    bool isBelongs(IndexType pos) const { return pos >= _begin && pos <= _end; }
    bool haveIntersaption(IndexType posBegin, IndexType posEnd) const {
        return isBelongs(posBegin) || isBelongs(posEnd)
                || (posBegin <= _begin && posEnd >= _end);
    }

    PTRSourceType getSource() { return _source; }

    virtual ~Fragment() {
       // qDebug() << "~Fragment()";
    }
protected:
    IndexType _begin;
    IndexType _end;
    PTRSourceType _source;
    Fragment() = delete;
    Fragment(IndexType begin, IndexType end, PTRSourceType source)
    {
        _begin = begin;
        _end = end;
        _source = source;
      //  qDebug() << "Fragment()";
    }
};

#endif // FRAGMENT_H

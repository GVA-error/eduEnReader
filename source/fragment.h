#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <QDebug>

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
        PTR rezPtr = QSharedPointer <ThisType> (new ThisType(begin, end, source));
        return rezPtr;
    }
    void setEnd(IndexType newEnd) { _end = newEnd; }
    // Методы в глобальных координатах
    IndexType begin() const { return _begin; }
    IndexType end() const { return _end; }

    IndexType mid() const { return (_begin + _end) / 2; }

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

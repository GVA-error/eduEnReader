/****************************************************************************
** Meta object code from reading C++ file 'soundstore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../soundstore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundstore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SoundStore_t {
    QByteArrayData data[13];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SoundStore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SoundStore_t qt_meta_stringdata_SoundStore = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SoundStore"
QT_MOC_LITERAL(1, 11, 10), // "posChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "playReal"
QT_MOC_LITERAL(4, 32, 5), // "begin"
QT_MOC_LITERAL(5, 38, 3), // "end"
QT_MOC_LITERAL(6, 42, 10), // "setPosReal"
QT_MOC_LITERAL(7, 53, 13), // "setPosPersent"
QT_MOC_LITERAL(8, 67, 13), // "getPersentPos"
QT_MOC_LITERAL(9, 81, 10), // "getTimePos"
QT_MOC_LITERAL(10, 92, 5), // "start"
QT_MOC_LITERAL(11, 98, 4), // "stop"
QT_MOC_LITERAL(12, 103, 8) // "position"

    },
    "SoundStore\0posChanged\0\0playReal\0begin\0"
    "end\0setPosReal\0setPosPersent\0getPersentPos\0"
    "getTimePos\0start\0stop\0position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoundStore[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   60,    2, 0x0a /* Public */,
       3,    1,   65,    2, 0x2a /* Public | MethodCloned */,
       6,    1,   68,    2, 0x0a /* Public */,
       7,    1,   71,    2, 0x0a /* Public */,
       8,    0,   74,    2, 0x0a /* Public */,
       9,    0,   75,    2, 0x0a /* Public */,
      10,    0,   76,    2, 0x0a /* Public */,
      11,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    4,    5,
    QMetaType::Void, QMetaType::QReal,    4,
    QMetaType::Void, QMetaType::QReal,    2,
    QMetaType::Void, QMetaType::QReal,    2,
    QMetaType::QReal,
    QMetaType::QReal,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::QReal, 0x00495003,

 // properties: notify_signal_id
       0,

       0        // eod
};

void SoundStore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SoundStore *_t = static_cast<SoundStore *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->posChanged(); break;
        case 1: _t->playReal((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 2: _t->playReal((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 3: _t->setPosReal((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 4: _t->setPosPersent((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: { qreal _r = _t->getPersentPos();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 6: { qreal _r = _t->getTimePos();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 7: _t->start(); break;
        case 8: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SoundStore::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SoundStore::posChanged)) {
                *result = 0;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        SoundStore *_t = static_cast<SoundStore *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getPersentPos(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        SoundStore *_t = static_cast<SoundStore *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPosPersent(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject SoundStore::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SoundStore.data,
      qt_meta_data_SoundStore,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SoundStore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoundStore::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SoundStore.stringdata0))
        return static_cast<void*>(const_cast< SoundStore*>(this));
    if (!strcmp(_clname, "Store<SoundStore>"))
        return static_cast< Store<SoundStore>*>(const_cast< SoundStore*>(this));
    return QObject::qt_metacast(_clname);
}

int SoundStore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SoundStore::posChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

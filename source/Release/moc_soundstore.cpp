/****************************************************************************
** Meta object code from reading C++ file 'soundstore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../soundstore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundstore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SoundStore_t {
    QByteArrayData data[21];
    char stringdata0[232];
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
QT_MOC_LITERAL(12, 103, 13), // "stopStopTimer"
QT_MOC_LITERAL(13, 117, 12), // "saveCurState"
QT_MOC_LITERAL(14, 130, 16), // "backToSavedState"
QT_MOC_LITERAL(15, 147, 15), // "setVideoSurface"
QT_MOC_LITERAL(16, 163, 22), // "QAbstractVideoSurface*"
QT_MOC_LITERAL(17, 186, 7), // "surface"
QT_MOC_LITERAL(18, 194, 15), // "getVideoSurface"
QT_MOC_LITERAL(19, 210, 8), // "position"
QT_MOC_LITERAL(20, 219, 12) // "videoSurface"

    },
    "SoundStore\0posChanged\0\0playReal\0begin\0"
    "end\0setPosReal\0setPosPersent\0getPersentPos\0"
    "getTimePos\0start\0stop\0stopStopTimer\0"
    "saveCurState\0backToSavedState\0"
    "setVideoSurface\0QAbstractVideoSurface*\0"
    "surface\0getVideoSurface\0position\0"
    "videoSurface"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoundStore[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       2,  110, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   85,    2, 0x0a /* Public */,
       3,    1,   90,    2, 0x2a /* Public | MethodCloned */,
       6,    1,   93,    2, 0x0a /* Public */,
       7,    1,   96,    2, 0x0a /* Public */,
       8,    0,   99,    2, 0x0a /* Public */,
       9,    0,  100,    2, 0x0a /* Public */,
      10,    0,  101,    2, 0x0a /* Public */,
      11,    0,  102,    2, 0x0a /* Public */,
      12,    0,  103,    2, 0x0a /* Public */,
      13,    0,  104,    2, 0x0a /* Public */,
      14,    0,  105,    2, 0x0a /* Public */,
      15,    1,  106,    2, 0x0a /* Public */,
      18,    0,  109,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    0x80000000 | 16,

 // properties: name, type, flags
      19, QMetaType::QReal, 0x00495003,
      20, 0x80000000 | 16, 0x0009510b,

 // properties: notify_signal_id
       0,
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
        case 9: _t->stopStopTimer(); break;
        case 10: _t->saveCurState(); break;
        case 11: _t->backToSavedState(); break;
        case 12: _t->setVideoSurface((*reinterpret_cast< QAbstractVideoSurface*(*)>(_a[1]))); break;
        case 13: { QAbstractVideoSurface* _r = _t->getVideoSurface();
            if (_a[0]) *reinterpret_cast< QAbstractVideoSurface**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SoundStore::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SoundStore::posChanged)) {
                *result = 0;
                return;
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
        case 1: *reinterpret_cast< QAbstractVideoSurface**>(_v) = _t->getVideoSurface(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        SoundStore *_t = static_cast<SoundStore *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPosPersent(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setVideoSurface(*reinterpret_cast< QAbstractVideoSurface**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject SoundStore::staticMetaObject = {
    { &QMediaPlayer::staticMetaObject, qt_meta_stringdata_SoundStore.data,
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
    return QMediaPlayer::qt_metacast(_clname);
}

int SoundStore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMediaPlayer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SoundStore::posChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

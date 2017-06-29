/****************************************************************************
** Meta object code from reading C++ file 'soundstore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cpp/soundstore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundstore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SoundStore_t {
    QByteArrayData data[23];
    char stringdata0[265];
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
QT_MOC_LITERAL(3, 23, 21), // "isExampleStateChanged"
QT_MOC_LITERAL(4, 45, 19), // "playingStateChanged"
QT_MOC_LITERAL(5, 65, 12), // "openingError"
QT_MOC_LITERAL(6, 78, 5), // "clear"
QT_MOC_LITERAL(7, 84, 12), // "playingState"
QT_MOC_LITERAL(8, 97, 14), // "bufferingState"
QT_MOC_LITERAL(9, 112, 9), // "isExample"
QT_MOC_LITERAL(10, 122, 10), // "setPosReal"
QT_MOC_LITERAL(11, 133, 13), // "setPosPersent"
QT_MOC_LITERAL(12, 147, 13), // "getPersentPos"
QT_MOC_LITERAL(13, 161, 10), // "getTimePos"
QT_MOC_LITERAL(14, 172, 16), // "getStartPosition"
QT_MOC_LITERAL(15, 189, 8), // "duration"
QT_MOC_LITERAL(16, 198, 5), // "start"
QT_MOC_LITERAL(17, 204, 4), // "stop"
QT_MOC_LITERAL(18, 209, 13), // "stopStopTimer"
QT_MOC_LITERAL(19, 223, 8), // "saveHome"
QT_MOC_LITERAL(20, 232, 4), // "home"
QT_MOC_LITERAL(21, 237, 18), // "isCorrectLocalFile"
QT_MOC_LITERAL(22, 256, 8) // "position"

    },
    "SoundStore\0posChanged\0\0isExampleStateChanged\0"
    "playingStateChanged\0openingError\0clear\0"
    "playingState\0bufferingState\0isExample\0"
    "setPosReal\0setPosPersent\0getPersentPos\0"
    "getTimePos\0getStartPosition\0duration\0"
    "start\0stop\0stopStopTimer\0saveHome\0"
    "home\0isCorrectLocalFile\0position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoundStore[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       2,  138, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    0,  115,    2, 0x06 /* Public */,
       4,    0,  116,    2, 0x06 /* Public */,
       5,    0,  117,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  118,    2, 0x0a /* Public */,
       7,    0,  119,    2, 0x0a /* Public */,
       8,    0,  120,    2, 0x0a /* Public */,
       9,    0,  121,    2, 0x0a /* Public */,
      10,    1,  122,    2, 0x0a /* Public */,
      11,    1,  125,    2, 0x0a /* Public */,
      12,    0,  128,    2, 0x0a /* Public */,
      13,    0,  129,    2, 0x0a /* Public */,
      14,    0,  130,    2, 0x0a /* Public */,
      15,    0,  131,    2, 0x0a /* Public */,
      16,    0,  132,    2, 0x0a /* Public */,
      17,    0,  133,    2, 0x0a /* Public */,
      18,    0,  134,    2, 0x0a /* Public */,
      19,    0,  135,    2, 0x0a /* Public */,
      20,    0,  136,    2, 0x0a /* Public */,
      21,    0,  137,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QReal,    2,
    QMetaType::Void, QMetaType::QReal,    2,
    QMetaType::QReal,
    QMetaType::QReal,
    QMetaType::QReal,
    QMetaType::LongLong,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

 // properties: name, type, flags
      22, QMetaType::QReal, 0x00495003,
       9, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void SoundStore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SoundStore *_t = static_cast<SoundStore *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->posChanged(); break;
        case 1: _t->isExampleStateChanged(); break;
        case 2: _t->playingStateChanged(); break;
        case 3: _t->openingError(); break;
        case 4: _t->clear(); break;
        case 5: { qint32 _r = _t->playingState();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 6: { qint32 _r = _t->bufferingState();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->isExample();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setPosReal((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 9: _t->setPosPersent((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 10: { qreal _r = _t->getPersentPos();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 11: { qreal _r = _t->getTimePos();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 12: { qreal _r = _t->getStartPosition();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 13: { qint64 _r = _t->duration();
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->start(); break;
        case 15: _t->stop(); break;
        case 16: _t->stopStopTimer(); break;
        case 17: _t->saveHome(); break;
        case 18: _t->home(); break;
        case 19: { bool _r = _t->isCorrectLocalFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
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
        {
            typedef void (SoundStore::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SoundStore::isExampleStateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SoundStore::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SoundStore::playingStateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SoundStore::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SoundStore::openingError)) {
                *result = 3;
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
        case 1: *reinterpret_cast< bool*>(_v) = _t->isExample(); break;
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
    { &VlcQmlVideoPlayer::staticMetaObject, qt_meta_stringdata_SoundStore.data,
      qt_meta_data_SoundStore,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SoundStore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoundStore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SoundStore.stringdata0))
        return static_cast<void*>(const_cast< SoundStore*>(this));
    if (!strcmp(_clname, "Store<SoundStore>"))
        return static_cast< Store<SoundStore>*>(const_cast< SoundStore*>(this));
    return VlcQmlVideoPlayer::qt_metacast(_clname);
}

int SoundStore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VlcQmlVideoPlayer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
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
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SoundStore::isExampleStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SoundStore::playingStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SoundStore::openingError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

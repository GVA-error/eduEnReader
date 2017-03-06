/****************************************************************************
** Meta object code from reading C++ file 'bindmaker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ASR/bindmaker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bindmaker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BindMaker_t {
    QByteArrayData data[7];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BindMaker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BindMaker_t qt_meta_stringdata_BindMaker = {
    {
QT_MOC_LITERAL(0, 0, 9), // "BindMaker"
QT_MOC_LITERAL(1, 10, 7), // "process"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 6), // "qreal&"
QT_MOC_LITERAL(4, 26, 7), // "persent"
QT_MOC_LITERAL(5, 34, 16), // "handleRecognized"
QT_MOC_LITERAL(6, 51, 8) // "fileName"

    },
    "BindMaker\0process\0\0qreal&\0persent\0"
    "handleRecognized\0fileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BindMaker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    6,    2,

       0        // eod
};

void BindMaker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BindMaker *_t = static_cast<BindMaker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->process((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->handleRecognized((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BindMaker::*_t)(qreal & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BindMaker::process)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BindMaker::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_BindMaker.data,
      qt_meta_data_BindMaker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BindMaker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BindMaker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BindMaker.stringdata0))
        return static_cast<void*>(const_cast< BindMaker*>(this));
    return QThread::qt_metacast(_clname);
}

int BindMaker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void BindMaker::process(qreal & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

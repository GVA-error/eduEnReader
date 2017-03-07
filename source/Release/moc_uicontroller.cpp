/****************************************************************************
** Meta object code from reading C++ file 'uicontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../uicontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uicontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UIController_t {
    QByteArrayData data[28];
    char stringdata0[407];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UIController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UIController_t qt_meta_stringdata_UIController = {
    {
QT_MOC_LITERAL(0, 0, 12), // "UIController"
QT_MOC_LITERAL(1, 13, 22), // "soundSellectionChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "textSellectionChanged"
QT_MOC_LITERAL(4, 59, 18), // "exampleListChanged"
QT_MOC_LITERAL(5, 78, 12), // "openBindFile"
QT_MOC_LITERAL(6, 91, 12), // "bindFileName"
QT_MOC_LITERAL(7, 104, 12), // "saveBindFile"
QT_MOC_LITERAL(8, 117, 14), // "createBindFile"
QT_MOC_LITERAL(9, 132, 13), // "soundFileName"
QT_MOC_LITERAL(10, 146, 8), // "makeBind"
QT_MOC_LITERAL(11, 155, 13), // "openSoundFile"
QT_MOC_LITERAL(12, 169, 8), // "fileName"
QT_MOC_LITERAL(13, 178, 16), // "cursorPosChanged"
QT_MOC_LITERAL(14, 195, 21), // "setCursorPosInTimePos"
QT_MOC_LITERAL(15, 217, 21), // "setTimePosInCursorPos"
QT_MOC_LITERAL(16, 239, 27), // "formUrlToTranslateSellected"
QT_MOC_LITERAL(17, 267, 14), // "getExamplesFor"
QT_MOC_LITERAL(18, 282, 14), // "seekablePhrase"
QT_MOC_LITERAL(19, 297, 11), // "playExample"
QT_MOC_LITERAL(20, 309, 2), // "ID"
QT_MOC_LITERAL(21, 312, 19), // "recognizeIsFinished"
QT_MOC_LITERAL(22, 332, 8), // "document"
QT_MOC_LITERAL(23, 341, 10), // "TextStore*"
QT_MOC_LITERAL(24, 352, 10), // "soundStore"
QT_MOC_LITERAL(25, 363, 11), // "SoundStore*"
QT_MOC_LITERAL(26, 375, 16), // "exampleListModel"
QT_MOC_LITERAL(27, 392, 14) // "mouseIsPressed"

    },
    "UIController\0soundSellectionChanged\0"
    "\0textSellectionChanged\0exampleListChanged\0"
    "openBindFile\0bindFileName\0saveBindFile\0"
    "createBindFile\0soundFileName\0makeBind\0"
    "openSoundFile\0fileName\0cursorPosChanged\0"
    "setCursorPosInTimePos\0setTimePosInCursorPos\0"
    "formUrlToTranslateSellected\0getExamplesFor\0"
    "seekablePhrase\0playExample\0ID\0"
    "recognizeIsFinished\0document\0TextStore*\0"
    "soundStore\0SoundStore*\0exampleListModel\0"
    "mouseIsPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       4,  116, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   92,    2, 0x0a /* Public */,
       7,    1,   95,    2, 0x0a /* Public */,
       8,    1,   98,    2, 0x0a /* Public */,
      10,    0,  101,    2, 0x0a /* Public */,
      11,    1,  102,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    1,  109,    2, 0x0a /* Public */,
      19,    1,  112,    2, 0x0a /* Public */,
      21,    0,  115,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QUrl,    6,
    QMetaType::Void, QMetaType::QUrl,    6,
    QMetaType::Void, QMetaType::QUrl,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,

 // properties: name, type, flags
      22, 0x80000000 | 23, 0x0009510b,
      24, 0x80000000 | 25, 0x0009510b,
      26, QMetaType::QStringList, 0x00495003,
      27, QMetaType::Bool, 0x00095103,

 // properties: notify_signal_id
       0,
       0,
       2,
       0,

       0        // eod
};

void UIController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UIController *_t = static_cast<UIController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->soundSellectionChanged(); break;
        case 1: _t->textSellectionChanged(); break;
        case 2: _t->exampleListChanged(); break;
        case 3: _t->openBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 4: _t->saveBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 5: _t->createBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 6: _t->makeBind(); break;
        case 7: _t->openSoundFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->cursorPosChanged(); break;
        case 9: _t->setCursorPosInTimePos(); break;
        case 10: _t->setTimePosInCursorPos(); break;
        case 11: { QString _r = _t->formUrlToTranslateSellected();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: _t->getExamplesFor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->playExample((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->recognizeIsFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::soundSellectionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::textSellectionChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::exampleListChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SoundStore* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TextStore* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        UIController *_t = static_cast<UIController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< TextStore**>(_v) = _t->getDocument(); break;
        case 1: *reinterpret_cast< SoundStore**>(_v) = _t->getSoundStore(); break;
        case 2: *reinterpret_cast< QStringList*>(_v) = _t->getExampleList(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->getMouseIsPressed(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        UIController *_t = static_cast<UIController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDocument(*reinterpret_cast< TextStore**>(_v)); break;
        case 1: _t->setSoundStore(*reinterpret_cast< SoundStore**>(_v)); break;
        case 2: _t->setExampleList(*reinterpret_cast< QStringList*>(_v)); break;
        case 3: _t->setMouseIsPressed(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject UIController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UIController.data,
      qt_meta_data_UIController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UIController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UIController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UIController.stringdata0))
        return static_cast<void*>(const_cast< UIController*>(this));
    return QObject::qt_metacast(_clname);
}

int UIController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UIController::soundSellectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void UIController::textSellectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void UIController::exampleListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

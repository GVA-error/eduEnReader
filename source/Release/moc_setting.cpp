/****************************************************************************
** Meta object code from reading C++ file 'setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cpp/Utilits/setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_t {
    QByteArrayData data[11];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Settings_t qt_meta_stringdata_Settings = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Settings"
QT_MOC_LITERAL(1, 9, 7), // "Section"
QT_MOC_LITERAL(2, 17, 5), // "Video"
QT_MOC_LITERAL(3, 23, 10), // "TextViewer"
QT_MOC_LITERAL(4, 34, 3), // "Key"
QT_MOC_LITERAL(5, 38, 10), // "DpiScaling"
QT_MOC_LITERAL(6, 49, 15), // "ShowLectureText"
QT_MOC_LITERAL(7, 65, 15), // "ShowExampleText"
QT_MOC_LITERAL(8, 81, 13), // "TextMarkColor"
QT_MOC_LITERAL(9, 95, 11), // "ExampleSize"
QT_MOC_LITERAL(10, 107, 11) // "ExampleDiff"

    },
    "Settings\0Section\0Video\0TextViewer\0Key\0"
    "DpiScaling\0ShowLectureText\0ShowExampleText\0"
    "TextMarkColor\0ExampleSize\0ExampleDiff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    2,   22,
       4, 0x0,    6,   26,

 // enum data: key, value
       2, uint(Settings::Video),
       3, uint(Settings::TextViewer),
       5, uint(Settings::DpiScaling),
       6, uint(Settings::ShowLectureText),
       7, uint(Settings::ShowExampleText),
       8, uint(Settings::TextMarkColor),
       9, uint(Settings::ExampleSize),
      10, uint(Settings::ExampleDiff),

       0        // eod
};

const QMetaObject Settings::staticMetaObject = {
    { Q_NULLPTR, qt_meta_stringdata_Settings.data,
      qt_meta_data_Settings,  Q_NULLPTR, Q_NULLPTR, Q_NULLPTR}
};

struct qt_meta_stringdata_QML_Settings_t {
    QByteArrayData data[18];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QML_Settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QML_Settings_t qt_meta_stringdata_QML_Settings = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QML_Settings"
QT_MOC_LITERAL(1, 13, 22), // "showLectureTextChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 22), // "showExampleTextChanged"
QT_MOC_LITERAL(4, 60, 20), // "textMarkColorChanged"
QT_MOC_LITERAL(5, 81, 18), // "exampleSizeChanged"
QT_MOC_LITERAL(6, 100, 18), // "exampleDiffChanged"
QT_MOC_LITERAL(7, 119, 15), // "showLectureText"
QT_MOC_LITERAL(8, 135, 18), // "setShowLectureText"
QT_MOC_LITERAL(9, 154, 8), // "newValue"
QT_MOC_LITERAL(10, 163, 15), // "showExampleText"
QT_MOC_LITERAL(11, 179, 18), // "setShowExampleText"
QT_MOC_LITERAL(12, 198, 13), // "textMarkColor"
QT_MOC_LITERAL(13, 212, 16), // "setTextMarkColor"
QT_MOC_LITERAL(14, 229, 11), // "exampleSize"
QT_MOC_LITERAL(15, 241, 14), // "setExampleSize"
QT_MOC_LITERAL(16, 256, 11), // "exampleDiff"
QT_MOC_LITERAL(17, 268, 14) // "setExampleDiff"

    },
    "QML_Settings\0showLectureTextChanged\0"
    "\0showExampleTextChanged\0textMarkColorChanged\0"
    "exampleSizeChanged\0exampleDiffChanged\0"
    "showLectureText\0setShowLectureText\0"
    "newValue\0showExampleText\0setShowExampleText\0"
    "textMarkColor\0setTextMarkColor\0"
    "exampleSize\0setExampleSize\0exampleDiff\0"
    "setExampleDiff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QML_Settings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       5,  114, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   94,    2, 0x0a /* Public */,
       8,    1,   95,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    1,   99,    2, 0x0a /* Public */,
      12,    0,  102,    2, 0x0a /* Public */,
      13,    1,  103,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    1,  107,    2, 0x0a /* Public */,
      16,    0,  110,    2, 0x0a /* Public */,
      17,    1,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::QColor,
    QMetaType::Void, QMetaType::QColor,    9,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    9,

 // properties: name, type, flags
       7, QMetaType::Bool, 0x00495103,
      10, QMetaType::Bool, 0x00495103,
      14, QMetaType::Int, 0x00495103,
      16, QMetaType::Int, 0x00495103,
      12, QMetaType::QColor, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       3,
       4,
       2,

       0        // eod
};

void QML_Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QML_Settings *_t = static_cast<QML_Settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showLectureTextChanged(); break;
        case 1: _t->showExampleTextChanged(); break;
        case 2: _t->textMarkColorChanged(); break;
        case 3: _t->exampleSizeChanged(); break;
        case 4: _t->exampleDiffChanged(); break;
        case 5: { bool _r = _t->showLectureText();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->setShowLectureText((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 7: { bool _r = _t->showExampleText();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->setShowExampleText((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 9: { QColor _r = _t->textMarkColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 10: _t->setTextMarkColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 11: { qint32 _r = _t->exampleSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 12: _t->setExampleSize((*reinterpret_cast< const qint32(*)>(_a[1]))); break;
        case 13: { qint32 _r = _t->exampleDiff();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 14: _t->setExampleDiff((*reinterpret_cast< const qint32(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QML_Settings::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QML_Settings::showLectureTextChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QML_Settings::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QML_Settings::showExampleTextChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QML_Settings::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QML_Settings::textMarkColorChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QML_Settings::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QML_Settings::exampleSizeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QML_Settings::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QML_Settings::exampleDiffChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QML_Settings *_t = static_cast<QML_Settings *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->showLectureText(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->showExampleText(); break;
        case 2: *reinterpret_cast< qint32*>(_v) = _t->exampleSize(); break;
        case 3: *reinterpret_cast< qint32*>(_v) = _t->exampleDiff(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->textMarkColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QML_Settings *_t = static_cast<QML_Settings *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShowLectureText(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setShowExampleText(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setExampleSize(*reinterpret_cast< qint32*>(_v)); break;
        case 3: _t->setExampleDiff(*reinterpret_cast< qint32*>(_v)); break;
        case 4: _t->setTextMarkColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QML_Settings::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QML_Settings.data,
      qt_meta_data_QML_Settings,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QML_Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QML_Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QML_Settings.stringdata0))
        return static_cast<void*>(const_cast< QML_Settings*>(this));
    return QObject::qt_metacast(_clname);
}

int QML_Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QML_Settings::showLectureTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QML_Settings::showExampleTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QML_Settings::textMarkColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void QML_Settings::exampleSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void QML_Settings::exampleDiffChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

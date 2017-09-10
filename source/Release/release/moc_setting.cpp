/****************************************************************************
** Meta object code from reading C++ file 'setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cpp/Utilits/setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_t {
    QByteArrayData data[21];
    char stringdata0[261];
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
QT_MOC_LITERAL(4, 34, 8), // "Location"
QT_MOC_LITERAL(5, 43, 8), // "Behavior"
QT_MOC_LITERAL(6, 52, 8), // "Examples"
QT_MOC_LITERAL(7, 61, 14), // "CrationOptions"
QT_MOC_LITERAL(8, 76, 3), // "Key"
QT_MOC_LITERAL(9, 80, 10), // "DpiScaling"
QT_MOC_LITERAL(10, 91, 15), // "ShowLectureText"
QT_MOC_LITERAL(11, 107, 15), // "ShowExampleText"
QT_MOC_LITERAL(12, 123, 13), // "TextMarkColor"
QT_MOC_LITERAL(13, 137, 11), // "ExampleSize"
QT_MOC_LITERAL(14, 149, 11), // "ExampleDiff"
QT_MOC_LITERAL(15, 161, 12), // "BindLocation"
QT_MOC_LITERAL(16, 174, 19), // "ShowTranslateDialog"
QT_MOC_LITERAL(17, 194, 7), // "postfix"
QT_MOC_LITERAL(18, 202, 20), // "showUserLikeComments"
QT_MOC_LITERAL(19, 223, 17), // "AutoCommentNumber"
QT_MOC_LITERAL(20, 241, 19) // "DefaultRemoteSource"

    },
    "Settings\0Section\0Video\0TextViewer\0"
    "Location\0Behavior\0Examples\0CrationOptions\0"
    "Key\0DpiScaling\0ShowLectureText\0"
    "ShowExampleText\0TextMarkColor\0ExampleSize\0"
    "ExampleDiff\0BindLocation\0ShowTranslateDialog\0"
    "postfix\0showUserLikeComments\0"
    "AutoCommentNumber\0DefaultRemoteSource"
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
       1, 0x0,    6,   22,
       8, 0x0,   12,   34,

 // enum data: key, value
       2, uint(Settings::Video),
       3, uint(Settings::TextViewer),
       4, uint(Settings::Location),
       5, uint(Settings::Behavior),
       6, uint(Settings::Examples),
       7, uint(Settings::CrationOptions),
       9, uint(Settings::DpiScaling),
      10, uint(Settings::ShowLectureText),
      11, uint(Settings::ShowExampleText),
      12, uint(Settings::TextMarkColor),
      13, uint(Settings::ExampleSize),
      14, uint(Settings::ExampleDiff),
      15, uint(Settings::BindLocation),
      16, uint(Settings::ShowTranslateDialog),
      17, uint(Settings::postfix),
      18, uint(Settings::showUserLikeComments),
      19, uint(Settings::AutoCommentNumber),
      20, uint(Settings::DefaultRemoteSource),

       0        // eod
};

const QMetaObject Settings::staticMetaObject = {
    { nullptr, qt_meta_stringdata_Settings.data,
      qt_meta_data_Settings,  nullptr, nullptr, nullptr}
};

struct qt_meta_stringdata_QML_Settings_t {
    QByteArrayData data[27];
    char stringdata0[490];
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
QT_MOC_LITERAL(7, 119, 26), // "showTranslateDialogChanged"
QT_MOC_LITERAL(8, 146, 27), // "showUserLikeCommentsChanged"
QT_MOC_LITERAL(9, 174, 24), // "autoCommentNumberChanged"
QT_MOC_LITERAL(10, 199, 15), // "showLectureText"
QT_MOC_LITERAL(11, 215, 18), // "setShowLectureText"
QT_MOC_LITERAL(12, 234, 8), // "newValue"
QT_MOC_LITERAL(13, 243, 15), // "showExampleText"
QT_MOC_LITERAL(14, 259, 18), // "setShowExampleText"
QT_MOC_LITERAL(15, 278, 13), // "textMarkColor"
QT_MOC_LITERAL(16, 292, 16), // "setTextMarkColor"
QT_MOC_LITERAL(17, 309, 11), // "exampleSize"
QT_MOC_LITERAL(18, 321, 14), // "setExampleSize"
QT_MOC_LITERAL(19, 336, 11), // "exampleDiff"
QT_MOC_LITERAL(20, 348, 14), // "setExampleDiff"
QT_MOC_LITERAL(21, 363, 19), // "showTranslateDialog"
QT_MOC_LITERAL(22, 383, 22), // "setShowTranslateDialog"
QT_MOC_LITERAL(23, 406, 20), // "showUserLikeComments"
QT_MOC_LITERAL(24, 427, 23), // "setShowUserLikeComments"
QT_MOC_LITERAL(25, 451, 17), // "autoCommentNumber"
QT_MOC_LITERAL(26, 469, 20) // "setAutoCommentNumber"

    },
    "QML_Settings\0showLectureTextChanged\0"
    "\0showExampleTextChanged\0textMarkColorChanged\0"
    "exampleSizeChanged\0exampleDiffChanged\0"
    "showTranslateDialogChanged\0"
    "showUserLikeCommentsChanged\0"
    "autoCommentNumberChanged\0showLectureText\0"
    "setShowLectureText\0newValue\0showExampleText\0"
    "setShowExampleText\0textMarkColor\0"
    "setTextMarkColor\0exampleSize\0"
    "setExampleSize\0exampleDiff\0setExampleDiff\0"
    "showTranslateDialog\0setShowTranslateDialog\0"
    "showUserLikeComments\0setShowUserLikeComments\0"
    "autoCommentNumber\0setAutoCommentNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QML_Settings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       8,  174, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  134,    2, 0x06 /* Public */,
       3,    0,  135,    2, 0x06 /* Public */,
       4,    0,  136,    2, 0x06 /* Public */,
       5,    0,  137,    2, 0x06 /* Public */,
       6,    0,  138,    2, 0x06 /* Public */,
       7,    0,  139,    2, 0x06 /* Public */,
       8,    0,  140,    2, 0x06 /* Public */,
       9,    0,  141,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  142,    2, 0x0a /* Public */,
      11,    1,  143,    2, 0x0a /* Public */,
      13,    0,  146,    2, 0x0a /* Public */,
      14,    1,  147,    2, 0x0a /* Public */,
      15,    0,  150,    2, 0x0a /* Public */,
      16,    1,  151,    2, 0x0a /* Public */,
      17,    0,  154,    2, 0x0a /* Public */,
      18,    1,  155,    2, 0x0a /* Public */,
      19,    0,  158,    2, 0x0a /* Public */,
      20,    1,  159,    2, 0x0a /* Public */,
      21,    0,  162,    2, 0x0a /* Public */,
      22,    1,  163,    2, 0x0a /* Public */,
      23,    0,  166,    2, 0x0a /* Public */,
      24,    1,  167,    2, 0x0a /* Public */,
      25,    0,  170,    2, 0x0a /* Public */,
      26,    1,  171,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::QColor,
    QMetaType::Void, QMetaType::QColor,   12,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   12,

 // properties: name, type, flags
      10, QMetaType::Bool, 0x00495103,
      13, QMetaType::Bool, 0x00495103,
      17, QMetaType::Int, 0x00495103,
      19, QMetaType::Int, 0x00495103,
      15, QMetaType::QColor, 0x00495103,
      21, QMetaType::Bool, 0x00495103,
      23, QMetaType::Bool, 0x00495103,
      25, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       3,
       4,
       2,
       5,
       6,
       7,

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
        case 5: _t->showTranslateDialogChanged(); break;
        case 6: _t->showUserLikeCommentsChanged(); break;
        case 7: _t->autoCommentNumberChanged(); break;
        case 8: { bool _r = _t->showLectureText();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setShowLectureText((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 10: { bool _r = _t->showExampleText();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setShowExampleText((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 12: { QColor _r = _t->textMarkColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setTextMarkColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 14: { qint32 _r = _t->exampleSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->setExampleSize((*reinterpret_cast< const qint32(*)>(_a[1]))); break;
        case 16: { qint32 _r = _t->exampleDiff();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->setExampleDiff((*reinterpret_cast< const qint32(*)>(_a[1]))); break;
        case 18: { bool _r = _t->showTranslateDialog();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->setShowTranslateDialog((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: { bool _r = _t->showUserLikeComments();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->setShowUserLikeComments((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: { qint32 _r = _t->autoCommentNumber();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->setAutoCommentNumber((*reinterpret_cast< qint32(*)>(_a[1]))); break;
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
        {
            typedef void (QML_Settings::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QML_Settings::showTranslateDialogChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (QML_Settings::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QML_Settings::showUserLikeCommentsChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (QML_Settings::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QML_Settings::autoCommentNumberChanged)) {
                *result = 7;
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
        case 5: *reinterpret_cast< bool*>(_v) = _t->showTranslateDialog(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->showUserLikeComments(); break;
        case 7: *reinterpret_cast< qint32*>(_v) = _t->autoCommentNumber(); break;
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
        case 5: _t->setShowTranslateDialog(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setShowUserLikeComments(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setAutoCommentNumber(*reinterpret_cast< qint32*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QML_Settings::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QML_Settings.data,
      qt_meta_data_QML_Settings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QML_Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QML_Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QML_Settings::showLectureTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QML_Settings::showExampleTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QML_Settings::textMarkColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QML_Settings::exampleSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QML_Settings::exampleDiffChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QML_Settings::showTranslateDialogChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QML_Settings::showUserLikeCommentsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QML_Settings::autoCommentNumberChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

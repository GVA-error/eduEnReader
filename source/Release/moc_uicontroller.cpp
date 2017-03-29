/****************************************************************************
** Meta object code from reading C++ file 'uicontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cpp/uicontroller.h"
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
    QByteArrayData data[59];
    char stringdata0[842];
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
QT_MOC_LITERAL(4, 59, 20), // "bindFilesListChanged"
QT_MOC_LITERAL(5, 80, 18), // "exampleListChanged"
QT_MOC_LITERAL(6, 99, 18), // "commentListChanged"
QT_MOC_LITERAL(7, 118, 19), // "examplesSizeChanged"
QT_MOC_LITERAL(8, 138, 15), // "diffSizeChanged"
QT_MOC_LITERAL(9, 154, 8), // "saveHome"
QT_MOC_LITERAL(10, 163, 4), // "home"
QT_MOC_LITERAL(11, 168, 16), // "synchBndFileList"
QT_MOC_LITERAL(12, 185, 12), // "openBindFile"
QT_MOC_LITERAL(13, 198, 12), // "bindFileName"
QT_MOC_LITERAL(14, 211, 12), // "saveBindFile"
QT_MOC_LITERAL(15, 224, 14), // "createBindFile"
QT_MOC_LITERAL(16, 239, 13), // "soundFileName"
QT_MOC_LITERAL(17, 253, 8), // "makeBind"
QT_MOC_LITERAL(18, 262, 10), // "addComment"
QT_MOC_LITERAL(19, 273, 4), // "name"
QT_MOC_LITERAL(20, 278, 13), // "openSoundFile"
QT_MOC_LITERAL(21, 292, 8), // "fileName"
QT_MOC_LITERAL(22, 301, 16), // "cursorPosChanged"
QT_MOC_LITERAL(23, 318, 21), // "setCursorPosInTimePos"
QT_MOC_LITERAL(24, 340, 21), // "setTimePosInCursorPos"
QT_MOC_LITERAL(25, 362, 11), // "markCurText"
QT_MOC_LITERAL(26, 374, 12), // "markLastText"
QT_MOC_LITERAL(27, 387, 14), // "unmarkLastText"
QT_MOC_LITERAL(28, 402, 17), // "startSellectTimer"
QT_MOC_LITERAL(29, 420, 15), // "setExamplesSize"
QT_MOC_LITERAL(30, 436, 7), // "newSize"
QT_MOC_LITERAL(31, 444, 15), // "getExamplesSize"
QT_MOC_LITERAL(32, 460, 11), // "setDiffSize"
QT_MOC_LITERAL(33, 472, 7), // "newDiff"
QT_MOC_LITERAL(34, 480, 11), // "getDiffSize"
QT_MOC_LITERAL(35, 492, 27), // "formUrlToTranslateSellected"
QT_MOC_LITERAL(36, 520, 11), // "playExample"
QT_MOC_LITERAL(37, 532, 2), // "ID"
QT_MOC_LITERAL(38, 535, 10), // "getExample"
QT_MOC_LITERAL(39, 546, 14), // "getExamplesFor"
QT_MOC_LITERAL(40, 561, 14), // "seekablePhrase"
QT_MOC_LITERAL(41, 576, 9), // "goOutHome"
QT_MOC_LITERAL(42, 586, 21), // "getCommentUrlWithName"
QT_MOC_LITERAL(43, 608, 22), // "getBindFileUrlWithName"
QT_MOC_LITERAL(44, 631, 14), // "getMidMarkable"
QT_MOC_LITERAL(45, 646, 16), // "getBeginMarkable"
QT_MOC_LITERAL(46, 663, 14), // "getEndMarkable"
QT_MOC_LITERAL(47, 678, 10), // "canNotSync"
QT_MOC_LITERAL(48, 689, 19), // "recognizeIsFinished"
QT_MOC_LITERAL(49, 709, 8), // "document"
QT_MOC_LITERAL(50, 718, 10), // "TextStore*"
QT_MOC_LITERAL(51, 729, 10), // "soundStore"
QT_MOC_LITERAL(52, 740, 11), // "SoundStore*"
QT_MOC_LITERAL(53, 752, 18), // "bindFilesListModel"
QT_MOC_LITERAL(54, 771, 16), // "exampleListModel"
QT_MOC_LITERAL(55, 788, 16), // "commentListModel"
QT_MOC_LITERAL(56, 805, 14), // "mouseIsPressed"
QT_MOC_LITERAL(57, 820, 12), // "examplesSize"
QT_MOC_LITERAL(58, 833, 8) // "diffSize"

    },
    "UIController\0soundSellectionChanged\0"
    "\0textSellectionChanged\0bindFilesListChanged\0"
    "exampleListChanged\0commentListChanged\0"
    "examplesSizeChanged\0diffSizeChanged\0"
    "saveHome\0home\0synchBndFileList\0"
    "openBindFile\0bindFileName\0saveBindFile\0"
    "createBindFile\0soundFileName\0makeBind\0"
    "addComment\0name\0openSoundFile\0fileName\0"
    "cursorPosChanged\0setCursorPosInTimePos\0"
    "setTimePosInCursorPos\0markCurText\0"
    "markLastText\0unmarkLastText\0"
    "startSellectTimer\0setExamplesSize\0"
    "newSize\0getExamplesSize\0setDiffSize\0"
    "newDiff\0getDiffSize\0formUrlToTranslateSellected\0"
    "playExample\0ID\0getExample\0getExamplesFor\0"
    "seekablePhrase\0goOutHome\0getCommentUrlWithName\0"
    "getBindFileUrlWithName\0getMidMarkable\0"
    "getBeginMarkable\0getEndMarkable\0"
    "canNotSync\0recognizeIsFinished\0document\0"
    "TextStore*\0soundStore\0SoundStore*\0"
    "bindFilesListModel\0exampleListModel\0"
    "commentListModel\0mouseIsPressed\0"
    "examplesSize\0diffSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       8,  272, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  209,    2, 0x06 /* Public */,
       3,    0,  210,    2, 0x06 /* Public */,
       4,    0,  211,    2, 0x06 /* Public */,
       5,    0,  212,    2, 0x06 /* Public */,
       6,    0,  213,    2, 0x06 /* Public */,
       7,    0,  214,    2, 0x06 /* Public */,
       8,    0,  215,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  216,    2, 0x0a /* Public */,
      10,    0,  217,    2, 0x0a /* Public */,
      11,    0,  218,    2, 0x0a /* Public */,
      12,    1,  219,    2, 0x0a /* Public */,
      14,    1,  222,    2, 0x0a /* Public */,
      15,    1,  225,    2, 0x0a /* Public */,
      17,    0,  228,    2, 0x0a /* Public */,
      18,    2,  229,    2, 0x0a /* Public */,
      20,    1,  234,    2, 0x0a /* Public */,
      22,    0,  237,    2, 0x0a /* Public */,
      23,    0,  238,    2, 0x0a /* Public */,
      24,    0,  239,    2, 0x0a /* Public */,
      25,    0,  240,    2, 0x0a /* Public */,
      26,    0,  241,    2, 0x0a /* Public */,
      27,    0,  242,    2, 0x0a /* Public */,
      28,    0,  243,    2, 0x0a /* Public */,
      29,    1,  244,    2, 0x0a /* Public */,
      31,    0,  247,    2, 0x0a /* Public */,
      32,    1,  248,    2, 0x0a /* Public */,
      34,    0,  251,    2, 0x0a /* Public */,
      35,    0,  252,    2, 0x0a /* Public */,
      36,    1,  253,    2, 0x0a /* Public */,
      38,    0,  256,    2, 0x0a /* Public */,
      39,    1,  257,    2, 0x0a /* Public */,
      41,    0,  260,    2, 0x0a /* Public */,
      42,    1,  261,    2, 0x0a /* Public */,
      43,    1,  264,    2, 0x0a /* Public */,
      44,    0,  267,    2, 0x0a /* Public */,
      45,    0,  268,    2, 0x0a /* Public */,
      46,    0,  269,    2, 0x0a /* Public */,
      47,    0,  270,    2, 0x0a /* Public */,
      48,    0,  271,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   13,
    QMetaType::Void, QMetaType::QUrl,   13,
    QMetaType::Void, QMetaType::QUrl,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,    2,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void,
    QMetaType::QUrl, QMetaType::QString,   19,
    QMetaType::QUrl, QMetaType::QString,   19,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Void,

 // properties: name, type, flags
      49, 0x80000000 | 50, 0x0009510b,
      51, 0x80000000 | 52, 0x0009510b,
      53, QMetaType::QStringList, 0x00495003,
      54, QMetaType::QStringList, 0x00495003,
      55, QMetaType::QStringList, 0x00495003,
      56, QMetaType::Bool, 0x00095102,
      57, QMetaType::Int, 0x00495103,
      58, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       2,
       3,
       4,
       0,
       5,
       6,

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
        case 2: _t->bindFilesListChanged(); break;
        case 3: _t->exampleListChanged(); break;
        case 4: _t->commentListChanged(); break;
        case 5: _t->examplesSizeChanged(); break;
        case 6: _t->diffSizeChanged(); break;
        case 7: _t->saveHome(); break;
        case 8: _t->home(); break;
        case 9: _t->synchBndFileList(); break;
        case 10: _t->openBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 11: _t->saveBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 12: _t->createBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 13: _t->makeBind(); break;
        case 14: _t->addComment((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 15: _t->openSoundFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->cursorPosChanged(); break;
        case 17: _t->setCursorPosInTimePos(); break;
        case 18: _t->setTimePosInCursorPos(); break;
        case 19: _t->markCurText(); break;
        case 20: _t->markLastText(); break;
        case 21: _t->unmarkLastText(); break;
        case 22: _t->startSellectTimer(); break;
        case 23: _t->setExamplesSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 24: { qint32 _r = _t->getExamplesSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 25: _t->setDiffSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 26: { qint32 _r = _t->getDiffSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 27: { QString _r = _t->formUrlToTranslateSellected();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 28: _t->playExample((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->getExample(); break;
        case 30: _t->getExamplesFor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->goOutHome(); break;
        case 32: { QUrl _r = _t->getCommentUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 33: { QUrl _r = _t->getBindFileUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 34: { qint32 _r = _t->getMidMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 35: { qint32 _r = _t->getBeginMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 36: { qint32 _r = _t->getEndMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 37: { bool _r = _t->canNotSync();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 38: _t->recognizeIsFinished(); break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::bindFilesListChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::exampleListChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::commentListChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::examplesSizeChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::diffSizeChanged)) {
                *result = 6;
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
        case 2: *reinterpret_cast< QStringList*>(_v) = _t->getbindFilesList(); break;
        case 3: *reinterpret_cast< QStringList*>(_v) = _t->getExampleList(); break;
        case 4: *reinterpret_cast< QStringList*>(_v) = _t->getCommentList(); break;
        case 6: *reinterpret_cast< qint32*>(_v) = _t->getExamplesSize(); break;
        case 7: *reinterpret_cast< qint32*>(_v) = _t->getDiffSize(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        UIController *_t = static_cast<UIController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDocument(*reinterpret_cast< TextStore**>(_v)); break;
        case 1: _t->setSoundStore(*reinterpret_cast< SoundStore**>(_v)); break;
        case 2: _t->setbindFilesList(*reinterpret_cast< QStringList*>(_v)); break;
        case 3: _t->setExampleList(*reinterpret_cast< QStringList*>(_v)); break;
        case 4: _t->setCommentList(*reinterpret_cast< QStringList*>(_v)); break;
        case 5: _t->setMouseIsPressed(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setExamplesSize(*reinterpret_cast< qint32*>(_v)); break;
        case 7: _t->setDiffSize(*reinterpret_cast< qint32*>(_v)); break;
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
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 39;
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
void UIController::bindFilesListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void UIController::exampleListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void UIController::commentListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void UIController::examplesSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void UIController::diffSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

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
    QByteArrayData data[78];
    char stringdata0[1119];
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
QT_MOC_LITERAL(8, 138, 20), // "matirealsListChanged"
QT_MOC_LITERAL(9, 159, 15), // "diffSizeChanged"
QT_MOC_LITERAL(10, 175, 16), // "getbindFilesList"
QT_MOC_LITERAL(11, 192, 16), // "setbindFilesList"
QT_MOC_LITERAL(12, 209, 12), // "newBindFiles"
QT_MOC_LITERAL(13, 222, 14), // "getExampleList"
QT_MOC_LITERAL(14, 237, 14), // "setExampleList"
QT_MOC_LITERAL(15, 252, 11), // "newExamples"
QT_MOC_LITERAL(16, 264, 14), // "getCommentList"
QT_MOC_LITERAL(17, 279, 14), // "setCommentList"
QT_MOC_LITERAL(18, 294, 11), // "newComments"
QT_MOC_LITERAL(19, 306, 16), // "getMatirealsList"
QT_MOC_LITERAL(20, 323, 16), // "setMatirealsList"
QT_MOC_LITERAL(21, 340, 12), // "newMatireals"
QT_MOC_LITERAL(22, 353, 8), // "saveHome"
QT_MOC_LITERAL(23, 362, 4), // "home"
QT_MOC_LITERAL(24, 367, 11), // "getImageUrl"
QT_MOC_LITERAL(25, 379, 8), // "bindFile"
QT_MOC_LITERAL(26, 388, 8), // "getTitle"
QT_MOC_LITERAL(27, 397, 16), // "synchBndFileList"
QT_MOC_LITERAL(28, 414, 12), // "openBindFile"
QT_MOC_LITERAL(29, 427, 12), // "bindFileName"
QT_MOC_LITERAL(30, 440, 12), // "saveBindFile"
QT_MOC_LITERAL(31, 453, 14), // "createBindFile"
QT_MOC_LITERAL(32, 468, 13), // "soundFileName"
QT_MOC_LITERAL(33, 482, 8), // "makeBind"
QT_MOC_LITERAL(34, 491, 10), // "addComment"
QT_MOC_LITERAL(35, 502, 4), // "name"
QT_MOC_LITERAL(36, 507, 13), // "openSoundFile"
QT_MOC_LITERAL(37, 521, 8), // "fileName"
QT_MOC_LITERAL(38, 530, 16), // "cursorPosChanged"
QT_MOC_LITERAL(39, 547, 21), // "setCursorPosInTimePos"
QT_MOC_LITERAL(40, 569, 21), // "setTimePosInCursorPos"
QT_MOC_LITERAL(41, 591, 11), // "markCurText"
QT_MOC_LITERAL(42, 603, 12), // "markLastText"
QT_MOC_LITERAL(43, 616, 14), // "unmarkLastText"
QT_MOC_LITERAL(44, 631, 17), // "startSellectTimer"
QT_MOC_LITERAL(45, 649, 15), // "setExamplesSize"
QT_MOC_LITERAL(46, 665, 7), // "newSize"
QT_MOC_LITERAL(47, 673, 15), // "getExamplesSize"
QT_MOC_LITERAL(48, 689, 11), // "setDiffSize"
QT_MOC_LITERAL(49, 701, 7), // "newDiff"
QT_MOC_LITERAL(50, 709, 11), // "getDiffSize"
QT_MOC_LITERAL(51, 721, 27), // "formUrlToTranslateSellected"
QT_MOC_LITERAL(52, 749, 11), // "playExample"
QT_MOC_LITERAL(53, 761, 2), // "ID"
QT_MOC_LITERAL(54, 764, 10), // "getExample"
QT_MOC_LITERAL(55, 775, 14), // "getExamplesFor"
QT_MOC_LITERAL(56, 790, 14), // "seekablePhrase"
QT_MOC_LITERAL(57, 805, 12), // "getMatireals"
QT_MOC_LITERAL(58, 818, 15), // "getMatirealsFor"
QT_MOC_LITERAL(59, 834, 9), // "goOutHome"
QT_MOC_LITERAL(60, 844, 21), // "getCommentUrlWithName"
QT_MOC_LITERAL(61, 866, 22), // "getBindFileUrlWithName"
QT_MOC_LITERAL(62, 889, 14), // "getMidMarkable"
QT_MOC_LITERAL(63, 904, 16), // "getBeginMarkable"
QT_MOC_LITERAL(64, 921, 14), // "getEndMarkable"
QT_MOC_LITERAL(65, 936, 10), // "canNotSync"
QT_MOC_LITERAL(66, 947, 19), // "recognizeIsFinished"
QT_MOC_LITERAL(67, 967, 8), // "document"
QT_MOC_LITERAL(68, 976, 10), // "TextStore*"
QT_MOC_LITERAL(69, 987, 10), // "soundStore"
QT_MOC_LITERAL(70, 998, 11), // "SoundStore*"
QT_MOC_LITERAL(71, 1010, 18), // "bindFilesListModel"
QT_MOC_LITERAL(72, 1029, 16), // "exampleListModel"
QT_MOC_LITERAL(73, 1046, 18), // "matirealsListModel"
QT_MOC_LITERAL(74, 1065, 16), // "commentListModel"
QT_MOC_LITERAL(75, 1082, 14), // "mouseIsPressed"
QT_MOC_LITERAL(76, 1097, 12), // "examplesSize"
QT_MOC_LITERAL(77, 1110, 8) // "diffSize"

    },
    "UIController\0soundSellectionChanged\0"
    "\0textSellectionChanged\0bindFilesListChanged\0"
    "exampleListChanged\0commentListChanged\0"
    "examplesSizeChanged\0matirealsListChanged\0"
    "diffSizeChanged\0getbindFilesList\0"
    "setbindFilesList\0newBindFiles\0"
    "getExampleList\0setExampleList\0newExamples\0"
    "getCommentList\0setCommentList\0newComments\0"
    "getMatirealsList\0setMatirealsList\0"
    "newMatireals\0saveHome\0home\0getImageUrl\0"
    "bindFile\0getTitle\0synchBndFileList\0"
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
    "seekablePhrase\0getMatireals\0getMatirealsFor\0"
    "goOutHome\0getCommentUrlWithName\0"
    "getBindFileUrlWithName\0getMidMarkable\0"
    "getBeginMarkable\0getEndMarkable\0"
    "canNotSync\0recognizeIsFinished\0document\0"
    "TextStore*\0soundStore\0SoundStore*\0"
    "bindFilesListModel\0exampleListModel\0"
    "matirealsListModel\0commentListModel\0"
    "mouseIsPressed\0examplesSize\0diffSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      52,   14, // methods
       9,  364, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  274,    2, 0x06 /* Public */,
       3,    0,  275,    2, 0x06 /* Public */,
       4,    0,  276,    2, 0x06 /* Public */,
       5,    0,  277,    2, 0x06 /* Public */,
       6,    0,  278,    2, 0x06 /* Public */,
       7,    0,  279,    2, 0x06 /* Public */,
       8,    0,  280,    2, 0x06 /* Public */,
       9,    0,  281,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  282,    2, 0x0a /* Public */,
      11,    1,  283,    2, 0x0a /* Public */,
      13,    0,  286,    2, 0x0a /* Public */,
      14,    1,  287,    2, 0x0a /* Public */,
      16,    0,  290,    2, 0x0a /* Public */,
      17,    1,  291,    2, 0x0a /* Public */,
      19,    0,  294,    2, 0x0a /* Public */,
      20,    1,  295,    2, 0x0a /* Public */,
      22,    0,  298,    2, 0x0a /* Public */,
      23,    0,  299,    2, 0x0a /* Public */,
      24,    1,  300,    2, 0x0a /* Public */,
      26,    1,  303,    2, 0x0a /* Public */,
      27,    0,  306,    2, 0x0a /* Public */,
      28,    1,  307,    2, 0x0a /* Public */,
      30,    1,  310,    2, 0x0a /* Public */,
      31,    1,  313,    2, 0x0a /* Public */,
      33,    0,  316,    2, 0x0a /* Public */,
      34,    2,  317,    2, 0x0a /* Public */,
      36,    1,  322,    2, 0x0a /* Public */,
      38,    0,  325,    2, 0x0a /* Public */,
      39,    0,  326,    2, 0x0a /* Public */,
      40,    0,  327,    2, 0x0a /* Public */,
      41,    0,  328,    2, 0x0a /* Public */,
      42,    0,  329,    2, 0x0a /* Public */,
      43,    0,  330,    2, 0x0a /* Public */,
      44,    0,  331,    2, 0x0a /* Public */,
      45,    1,  332,    2, 0x0a /* Public */,
      47,    0,  335,    2, 0x0a /* Public */,
      48,    1,  336,    2, 0x0a /* Public */,
      50,    0,  339,    2, 0x0a /* Public */,
      51,    0,  340,    2, 0x0a /* Public */,
      52,    1,  341,    2, 0x0a /* Public */,
      54,    0,  344,    2, 0x0a /* Public */,
      55,    1,  345,    2, 0x0a /* Public */,
      57,    0,  348,    2, 0x0a /* Public */,
      58,    1,  349,    2, 0x0a /* Public */,
      59,    0,  352,    2, 0x0a /* Public */,
      60,    1,  353,    2, 0x0a /* Public */,
      61,    1,  356,    2, 0x0a /* Public */,
      62,    0,  359,    2, 0x0a /* Public */,
      63,    0,  360,    2, 0x0a /* Public */,
      64,    0,  361,    2, 0x0a /* Public */,
      65,    0,  362,    2, 0x0a /* Public */,
      66,    0,  363,    2, 0x09 /* Protected */,

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
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   12,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   18,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QUrl, QMetaType::QString,   25,
    QMetaType::QString, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   29,
    QMetaType::Void, QMetaType::QUrl,   29,
    QMetaType::Void, QMetaType::QUrl,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,    2,   35,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   53,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void,
    QMetaType::QUrl, QMetaType::QString,   35,
    QMetaType::QUrl, QMetaType::QString,   35,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Void,

 // properties: name, type, flags
      67, 0x80000000 | 68, 0x0009510b,
      69, 0x80000000 | 70, 0x0009510b,
      71, QMetaType::QStringList, 0x00495003,
      72, QMetaType::QStringList, 0x00495003,
      73, QMetaType::QStringList, 0x00495003,
      74, QMetaType::QStringList, 0x00495003,
      75, QMetaType::Bool, 0x00095102,
      76, QMetaType::Int, 0x00495103,
      77, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       2,
       3,
       6,
       4,
       0,
       5,
       7,

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
        case 6: _t->matirealsListChanged(); break;
        case 7: _t->diffSizeChanged(); break;
        case 8: { QStringList _r = _t->getbindFilesList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 9: _t->setbindFilesList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 10: { QStringList _r = _t->getExampleList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 11: _t->setExampleList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 12: { QStringList _r = _t->getCommentList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 13: _t->setCommentList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 14: { QStringList _r = _t->getMatirealsList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 15: _t->setMatirealsList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 16: _t->saveHome(); break;
        case 17: _t->home(); break;
        case 18: { QUrl _r = _t->getImageUrl((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 19: { QString _r = _t->getTitle((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 20: _t->synchBndFileList(); break;
        case 21: _t->openBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 22: _t->saveBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 23: _t->createBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 24: _t->makeBind(); break;
        case 25: _t->addComment((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 26: _t->openSoundFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->cursorPosChanged(); break;
        case 28: _t->setCursorPosInTimePos(); break;
        case 29: _t->setTimePosInCursorPos(); break;
        case 30: _t->markCurText(); break;
        case 31: _t->markLastText(); break;
        case 32: _t->unmarkLastText(); break;
        case 33: _t->startSellectTimer(); break;
        case 34: _t->setExamplesSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 35: { qint32 _r = _t->getExamplesSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 36: _t->setDiffSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 37: { qint32 _r = _t->getDiffSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 38: { QString _r = _t->formUrlToTranslateSellected();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 39: _t->playExample((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 40: _t->getExample(); break;
        case 41: _t->getExamplesFor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->getMatireals(); break;
        case 43: _t->getMatirealsFor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 44: _t->goOutHome(); break;
        case 45: { QUrl _r = _t->getCommentUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 46: { QUrl _r = _t->getBindFileUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 47: { qint32 _r = _t->getMidMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 48: { qint32 _r = _t->getBeginMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 49: { qint32 _r = _t->getEndMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 50: { bool _r = _t->canNotSync();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 51: _t->recognizeIsFinished(); break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::matirealsListChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::diffSizeChanged)) {
                *result = 7;
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
        case 4: *reinterpret_cast< QStringList*>(_v) = _t->getMatirealsList(); break;
        case 5: *reinterpret_cast< QStringList*>(_v) = _t->getCommentList(); break;
        case 7: *reinterpret_cast< qint32*>(_v) = _t->getExamplesSize(); break;
        case 8: *reinterpret_cast< qint32*>(_v) = _t->getDiffSize(); break;
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
        case 4: _t->setMatirealsList(*reinterpret_cast< QStringList*>(_v)); break;
        case 5: _t->setCommentList(*reinterpret_cast< QStringList*>(_v)); break;
        case 6: _t->setMouseIsPressed(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setExamplesSize(*reinterpret_cast< qint32*>(_v)); break;
        case 8: _t->setDiffSize(*reinterpret_cast< qint32*>(_v)); break;
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
        if (_id < 52)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 52;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 52)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 52;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
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
void UIController::matirealsListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void UIController::diffSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

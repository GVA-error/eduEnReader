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
    QByteArrayData data[87];
    char stringdata0[1227];
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
QT_MOC_LITERAL(10, 175, 20), // "curCommentUrlChanged"
QT_MOC_LITERAL(11, 196, 16), // "getbindFilesList"
QT_MOC_LITERAL(12, 213, 16), // "setbindFilesList"
QT_MOC_LITERAL(13, 230, 12), // "newBindFiles"
QT_MOC_LITERAL(14, 243, 14), // "getExampleList"
QT_MOC_LITERAL(15, 258, 14), // "setExampleList"
QT_MOC_LITERAL(16, 273, 11), // "newExamples"
QT_MOC_LITERAL(17, 285, 14), // "getCommentList"
QT_MOC_LITERAL(18, 300, 14), // "setCommentList"
QT_MOC_LITERAL(19, 315, 11), // "newComments"
QT_MOC_LITERAL(20, 327, 13), // "curCommentUrl"
QT_MOC_LITERAL(21, 341, 16), // "setCurCommentUrl"
QT_MOC_LITERAL(22, 358, 16), // "getMatirealsList"
QT_MOC_LITERAL(23, 375, 16), // "setMatirealsList"
QT_MOC_LITERAL(24, 392, 12), // "newMatireals"
QT_MOC_LITERAL(25, 405, 8), // "saveHome"
QT_MOC_LITERAL(26, 414, 4), // "push"
QT_MOC_LITERAL(27, 419, 4), // "home"
QT_MOC_LITERAL(28, 424, 11), // "getImageUrl"
QT_MOC_LITERAL(29, 436, 8), // "bindFile"
QT_MOC_LITERAL(30, 445, 8), // "getTitle"
QT_MOC_LITERAL(31, 454, 16), // "synchBndFileList"
QT_MOC_LITERAL(32, 471, 12), // "openBindFile"
QT_MOC_LITERAL(33, 484, 12), // "bindFileName"
QT_MOC_LITERAL(34, 497, 12), // "saveBindFile"
QT_MOC_LITERAL(35, 510, 14), // "createBindFile"
QT_MOC_LITERAL(36, 525, 13), // "soundFileName"
QT_MOC_LITERAL(37, 539, 8), // "makeBind"
QT_MOC_LITERAL(38, 548, 10), // "addComment"
QT_MOC_LITERAL(39, 559, 4), // "name"
QT_MOC_LITERAL(40, 564, 13), // "openSoundFile"
QT_MOC_LITERAL(41, 578, 8), // "fileName"
QT_MOC_LITERAL(42, 587, 16), // "cursorPosChanged"
QT_MOC_LITERAL(43, 604, 21), // "setCursorPosInTimePos"
QT_MOC_LITERAL(44, 626, 21), // "setTimePosInCursorPos"
QT_MOC_LITERAL(45, 648, 11), // "markCurText"
QT_MOC_LITERAL(46, 660, 12), // "markLastText"
QT_MOC_LITERAL(47, 673, 14), // "unmarkLastText"
QT_MOC_LITERAL(48, 688, 17), // "startSellectTimer"
QT_MOC_LITERAL(49, 706, 15), // "setExamplesSize"
QT_MOC_LITERAL(50, 722, 7), // "newSize"
QT_MOC_LITERAL(51, 730, 15), // "getExamplesSize"
QT_MOC_LITERAL(52, 746, 11), // "setDiffSize"
QT_MOC_LITERAL(53, 758, 7), // "newDiff"
QT_MOC_LITERAL(54, 766, 11), // "getDiffSize"
QT_MOC_LITERAL(55, 778, 27), // "formUrlToTranslateSellected"
QT_MOC_LITERAL(56, 806, 11), // "playExample"
QT_MOC_LITERAL(57, 818, 2), // "ID"
QT_MOC_LITERAL(58, 821, 10), // "getExample"
QT_MOC_LITERAL(59, 832, 14), // "getExamplesFor"
QT_MOC_LITERAL(60, 847, 14), // "seekablePhrase"
QT_MOC_LITERAL(61, 862, 12), // "getMatireals"
QT_MOC_LITERAL(62, 875, 15), // "getMatirealsFor"
QT_MOC_LITERAL(63, 891, 9), // "goOutHome"
QT_MOC_LITERAL(64, 901, 21), // "getCommentUrlWithName"
QT_MOC_LITERAL(65, 923, 22), // "getBindFileUrlWithName"
QT_MOC_LITERAL(66, 946, 22), // "getMatirealUrlWithName"
QT_MOC_LITERAL(67, 969, 5), // "isDir"
QT_MOC_LITERAL(68, 975, 9), // "setCurDir"
QT_MOC_LITERAL(69, 985, 6), // "getDir"
QT_MOC_LITERAL(70, 992, 4), // "QDir"
QT_MOC_LITERAL(71, 997, 14), // "getMidMarkable"
QT_MOC_LITERAL(72, 1012, 16), // "getBeginMarkable"
QT_MOC_LITERAL(73, 1029, 14), // "getEndMarkable"
QT_MOC_LITERAL(74, 1044, 10), // "canNotSync"
QT_MOC_LITERAL(75, 1055, 19), // "recognizeIsFinished"
QT_MOC_LITERAL(76, 1075, 8), // "document"
QT_MOC_LITERAL(77, 1084, 10), // "TextStore*"
QT_MOC_LITERAL(78, 1095, 10), // "soundStore"
QT_MOC_LITERAL(79, 1106, 11), // "SoundStore*"
QT_MOC_LITERAL(80, 1118, 18), // "bindFilesListModel"
QT_MOC_LITERAL(81, 1137, 16), // "exampleListModel"
QT_MOC_LITERAL(82, 1154, 18), // "matirealsListModel"
QT_MOC_LITERAL(83, 1173, 16), // "commentListModel"
QT_MOC_LITERAL(84, 1190, 14), // "mouseIsPressed"
QT_MOC_LITERAL(85, 1205, 12), // "examplesSize"
QT_MOC_LITERAL(86, 1218, 8) // "diffSize"

    },
    "UIController\0soundSellectionChanged\0"
    "\0textSellectionChanged\0bindFilesListChanged\0"
    "exampleListChanged\0commentListChanged\0"
    "examplesSizeChanged\0matirealsListChanged\0"
    "diffSizeChanged\0curCommentUrlChanged\0"
    "getbindFilesList\0setbindFilesList\0"
    "newBindFiles\0getExampleList\0setExampleList\0"
    "newExamples\0getCommentList\0setCommentList\0"
    "newComments\0curCommentUrl\0setCurCommentUrl\0"
    "getMatirealsList\0setMatirealsList\0"
    "newMatireals\0saveHome\0push\0home\0"
    "getImageUrl\0bindFile\0getTitle\0"
    "synchBndFileList\0openBindFile\0"
    "bindFileName\0saveBindFile\0createBindFile\0"
    "soundFileName\0makeBind\0addComment\0"
    "name\0openSoundFile\0fileName\0"
    "cursorPosChanged\0setCursorPosInTimePos\0"
    "setTimePosInCursorPos\0markCurText\0"
    "markLastText\0unmarkLastText\0"
    "startSellectTimer\0setExamplesSize\0"
    "newSize\0getExamplesSize\0setDiffSize\0"
    "newDiff\0getDiffSize\0formUrlToTranslateSellected\0"
    "playExample\0ID\0getExample\0getExamplesFor\0"
    "seekablePhrase\0getMatireals\0getMatirealsFor\0"
    "goOutHome\0getCommentUrlWithName\0"
    "getBindFileUrlWithName\0getMatirealUrlWithName\0"
    "isDir\0setCurDir\0getDir\0QDir\0getMidMarkable\0"
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
      60,   14, // methods
      10,  424, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  314,    2, 0x06 /* Public */,
       3,    0,  315,    2, 0x06 /* Public */,
       4,    0,  316,    2, 0x06 /* Public */,
       5,    0,  317,    2, 0x06 /* Public */,
       6,    0,  318,    2, 0x06 /* Public */,
       7,    0,  319,    2, 0x06 /* Public */,
       8,    0,  320,    2, 0x06 /* Public */,
       9,    0,  321,    2, 0x06 /* Public */,
      10,    0,  322,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  323,    2, 0x0a /* Public */,
      12,    1,  324,    2, 0x0a /* Public */,
      14,    0,  327,    2, 0x0a /* Public */,
      15,    1,  328,    2, 0x0a /* Public */,
      17,    0,  331,    2, 0x0a /* Public */,
      18,    1,  332,    2, 0x0a /* Public */,
      20,    0,  335,    2, 0x0a /* Public */,
      21,    1,  336,    2, 0x0a /* Public */,
      22,    0,  339,    2, 0x0a /* Public */,
      23,    1,  340,    2, 0x0a /* Public */,
      25,    1,  343,    2, 0x0a /* Public */,
      25,    0,  346,    2, 0x2a /* Public | MethodCloned */,
      27,    0,  347,    2, 0x0a /* Public */,
      28,    1,  348,    2, 0x0a /* Public */,
      30,    1,  351,    2, 0x0a /* Public */,
      31,    0,  354,    2, 0x0a /* Public */,
      32,    1,  355,    2, 0x0a /* Public */,
      34,    1,  358,    2, 0x0a /* Public */,
      35,    1,  361,    2, 0x0a /* Public */,
      37,    0,  364,    2, 0x0a /* Public */,
      38,    2,  365,    2, 0x0a /* Public */,
      40,    1,  370,    2, 0x0a /* Public */,
      42,    0,  373,    2, 0x0a /* Public */,
      43,    0,  374,    2, 0x0a /* Public */,
      44,    0,  375,    2, 0x0a /* Public */,
      45,    0,  376,    2, 0x0a /* Public */,
      46,    0,  377,    2, 0x0a /* Public */,
      47,    0,  378,    2, 0x0a /* Public */,
      48,    0,  379,    2, 0x0a /* Public */,
      49,    1,  380,    2, 0x0a /* Public */,
      51,    0,  383,    2, 0x0a /* Public */,
      52,    1,  384,    2, 0x0a /* Public */,
      54,    0,  387,    2, 0x0a /* Public */,
      55,    0,  388,    2, 0x0a /* Public */,
      56,    1,  389,    2, 0x0a /* Public */,
      58,    0,  392,    2, 0x0a /* Public */,
      59,    1,  393,    2, 0x0a /* Public */,
      61,    0,  396,    2, 0x0a /* Public */,
      62,    1,  397,    2, 0x0a /* Public */,
      63,    0,  400,    2, 0x0a /* Public */,
      64,    1,  401,    2, 0x0a /* Public */,
      65,    1,  404,    2, 0x0a /* Public */,
      66,    1,  407,    2, 0x0a /* Public */,
      67,    1,  410,    2, 0x0a /* Public */,
      68,    1,  413,    2, 0x0a /* Public */,
      69,    1,  416,    2, 0x0a /* Public */,
      71,    0,  419,    2, 0x0a /* Public */,
      72,    0,  420,    2, 0x0a /* Public */,
      73,    0,  421,    2, 0x0a /* Public */,
      74,    0,  422,    2, 0x0a /* Public */,
      75,    0,  423,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
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
    QMetaType::Void, QMetaType::QStringList,   13,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   16,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   19,
    QMetaType::QUrl,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   24,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QUrl, QMetaType::QString,   29,
    QMetaType::QString, QMetaType::QString,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   33,
    QMetaType::Void, QMetaType::QUrl,   33,
    QMetaType::Void, QMetaType::QUrl,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,    2,   39,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   50,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   53,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   57,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   60,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   60,
    QMetaType::Void,
    QMetaType::QUrl, QMetaType::QString,   39,
    QMetaType::QUrl, QMetaType::QString,   39,
    QMetaType::QUrl, QMetaType::QString,   39,
    QMetaType::Bool, QMetaType::QString,   39,
    QMetaType::Void, QMetaType::QString,   39,
    0x80000000 | 70, QMetaType::QString,   39,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Void,

 // properties: name, type, flags
      76, 0x80000000 | 77, 0x0009510b,
      78, 0x80000000 | 79, 0x0009510b,
      80, QMetaType::QStringList, 0x00495003,
      81, QMetaType::QStringList, 0x00495003,
      82, QMetaType::QStringList, 0x00495003,
      83, QMetaType::QStringList, 0x00495003,
      84, QMetaType::Bool, 0x00095102,
      85, QMetaType::Int, 0x00495103,
      86, QMetaType::Int, 0x00495103,
      20, QMetaType::QUrl, 0x00495103,

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
       8,

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
        case 8: _t->curCommentUrlChanged(); break;
        case 9: { QStringList _r = _t->getbindFilesList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 10: _t->setbindFilesList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 11: { QStringList _r = _t->getExampleList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 12: _t->setExampleList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 13: { QStringList _r = _t->getCommentList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 14: _t->setCommentList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 15: { QUrl _r = _t->curCommentUrl();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 16: _t->setCurCommentUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 17: { QStringList _r = _t->getMatirealsList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 18: _t->setMatirealsList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 19: _t->saveHome((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->saveHome(); break;
        case 21: _t->home(); break;
        case 22: { QUrl _r = _t->getImageUrl((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 23: { QString _r = _t->getTitle((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 24: _t->synchBndFileList(); break;
        case 25: _t->openBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 26: _t->saveBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 27: _t->createBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 28: _t->makeBind(); break;
        case 29: _t->addComment((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 30: _t->openSoundFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->cursorPosChanged(); break;
        case 32: _t->setCursorPosInTimePos(); break;
        case 33: _t->setTimePosInCursorPos(); break;
        case 34: _t->markCurText(); break;
        case 35: _t->markLastText(); break;
        case 36: _t->unmarkLastText(); break;
        case 37: _t->startSellectTimer(); break;
        case 38: _t->setExamplesSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 39: { qint32 _r = _t->getExamplesSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 40: _t->setDiffSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 41: { qint32 _r = _t->getDiffSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 42: { QString _r = _t->formUrlToTranslateSellected();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 43: _t->playExample((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 44: _t->getExample(); break;
        case 45: _t->getExamplesFor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 46: _t->getMatireals(); break;
        case 47: _t->getMatirealsFor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 48: _t->goOutHome(); break;
        case 49: { QUrl _r = _t->getCommentUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 50: { QUrl _r = _t->getBindFileUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 51: { QUrl _r = _t->getMatirealUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 52: { bool _r = _t->isDir((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 53: _t->setCurDir((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 54: { QDir _r = _t->getDir((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDir*>(_a[0]) = _r; }  break;
        case 55: { qint32 _r = _t->getMidMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 56: { qint32 _r = _t->getBeginMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 57: { qint32 _r = _t->getEndMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 58: { bool _r = _t->canNotSync();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 59: _t->recognizeIsFinished(); break;
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
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::curCommentUrlChanged)) {
                *result = 8;
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
        case 9: *reinterpret_cast< QUrl*>(_v) = _t->curCommentUrl(); break;
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
        case 9: _t->setCurCommentUrl(*reinterpret_cast< QUrl*>(_v)); break;
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
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 60)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 60;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
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

// SIGNAL 8
void UIController::curCommentUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

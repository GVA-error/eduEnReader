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
    QByteArrayData data[140];
    char stringdata0[1960];
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
QT_MOC_LITERAL(11, 196, 12), // "titleChanged"
QT_MOC_LITERAL(12, 209, 15), // "curStateChanged"
QT_MOC_LITERAL(13, 225, 18), // "soundSourceChanged"
QT_MOC_LITERAL(14, 244, 21), // "curExampleWordChanged"
QT_MOC_LITERAL(15, 266, 15), // "someOpenChanged"
QT_MOC_LITERAL(16, 282, 5), // "title"
QT_MOC_LITERAL(17, 288, 8), // "setTitle"
QT_MOC_LITERAL(18, 297, 16), // "getbindFilesList"
QT_MOC_LITERAL(19, 314, 16), // "setbindFilesList"
QT_MOC_LITERAL(20, 331, 12), // "newBindFiles"
QT_MOC_LITERAL(21, 344, 14), // "getExampleList"
QT_MOC_LITERAL(22, 359, 14), // "setExampleList"
QT_MOC_LITERAL(23, 374, 11), // "newExamples"
QT_MOC_LITERAL(24, 386, 14), // "getCommentList"
QT_MOC_LITERAL(25, 401, 14), // "setCommentList"
QT_MOC_LITERAL(26, 416, 11), // "newComments"
QT_MOC_LITERAL(27, 428, 13), // "curCommentUrl"
QT_MOC_LITERAL(28, 442, 16), // "setCurCommentUrl"
QT_MOC_LITERAL(29, 459, 16), // "getMatirealsList"
QT_MOC_LITERAL(30, 476, 16), // "setMatirealsList"
QT_MOC_LITERAL(31, 493, 12), // "newMatireals"
QT_MOC_LITERAL(32, 506, 8), // "curState"
QT_MOC_LITERAL(33, 515, 11), // "setCurState"
QT_MOC_LITERAL(34, 527, 8), // "newState"
QT_MOC_LITERAL(35, 536, 14), // "curExampleWord"
QT_MOC_LITERAL(36, 551, 17), // "setCurExampleWord"
QT_MOC_LITERAL(37, 569, 8), // "saveHome"
QT_MOC_LITERAL(38, 578, 4), // "push"
QT_MOC_LITERAL(39, 583, 4), // "home"
QT_MOC_LITERAL(40, 588, 4), // "save"
QT_MOC_LITERAL(41, 593, 8), // "someOpen"
QT_MOC_LITERAL(42, 602, 11), // "setSomeOpen"
QT_MOC_LITERAL(43, 614, 8), // "newValue"
QT_MOC_LITERAL(44, 623, 14), // "setSoundSource"
QT_MOC_LITERAL(45, 638, 6), // "source"
QT_MOC_LITERAL(46, 645, 11), // "soundSource"
QT_MOC_LITERAL(47, 657, 23), // "setPreviewForCurLecture"
QT_MOC_LITERAL(48, 681, 3), // "url"
QT_MOC_LITERAL(49, 685, 11), // "getImageUrl"
QT_MOC_LITERAL(50, 697, 8), // "bindFile"
QT_MOC_LITERAL(51, 706, 8), // "getTitle"
QT_MOC_LITERAL(52, 715, 16), // "synchBndFileList"
QT_MOC_LITERAL(53, 732, 16), // "synchCommentList"
QT_MOC_LITERAL(54, 749, 12), // "openBindFile"
QT_MOC_LITERAL(55, 762, 12), // "bindFileName"
QT_MOC_LITERAL(56, 775, 12), // "saveBindFile"
QT_MOC_LITERAL(57, 788, 14), // "createBindFile"
QT_MOC_LITERAL(58, 803, 13), // "soundFileName"
QT_MOC_LITERAL(59, 817, 8), // "makeBind"
QT_MOC_LITERAL(60, 826, 12), // "allTsBinding"
QT_MOC_LITERAL(61, 839, 12), // "allStBinding"
QT_MOC_LITERAL(62, 852, 16), // "curUserStBinding"
QT_MOC_LITERAL(63, 869, 12), // "curTsBinding"
QT_MOC_LITERAL(64, 882, 12), // "downloadBase"
QT_MOC_LITERAL(65, 895, 10), // "uploadBase"
QT_MOC_LITERAL(66, 906, 18), // "createAutoComments"
QT_MOC_LITERAL(67, 925, 18), // "autoCommentsNumber"
QT_MOC_LITERAL(68, 944, 10), // "addComment"
QT_MOC_LITERAL(69, 955, 13), // "openSoundFile"
QT_MOC_LITERAL(70, 969, 8), // "fileName"
QT_MOC_LITERAL(71, 978, 16), // "cursorPosChanged"
QT_MOC_LITERAL(72, 995, 21), // "setCursorPosInTimePos"
QT_MOC_LITERAL(73, 1017, 21), // "setTimePosInCursorPos"
QT_MOC_LITERAL(74, 1039, 11), // "markCurText"
QT_MOC_LITERAL(75, 1051, 12), // "markLastText"
QT_MOC_LITERAL(76, 1064, 14), // "unmarkLastText"
QT_MOC_LITERAL(77, 1079, 17), // "startSellectTimer"
QT_MOC_LITERAL(78, 1097, 11), // "markComment"
QT_MOC_LITERAL(79, 1109, 4), // "name"
QT_MOC_LITERAL(80, 1114, 13), // "unmarkComment"
QT_MOC_LITERAL(81, 1128, 15), // "setExamplesSize"
QT_MOC_LITERAL(82, 1144, 7), // "newSize"
QT_MOC_LITERAL(83, 1152, 15), // "getExamplesSize"
QT_MOC_LITERAL(84, 1168, 11), // "setDiffSize"
QT_MOC_LITERAL(85, 1180, 7), // "newDiff"
QT_MOC_LITERAL(86, 1188, 11), // "getDiffSize"
QT_MOC_LITERAL(87, 1200, 18), // "getCommentListSize"
QT_MOC_LITERAL(88, 1219, 15), // "getFirstComment"
QT_MOC_LITERAL(89, 1235, 27), // "formUrlToTranslateSellected"
QT_MOC_LITERAL(90, 1263, 11), // "playExample"
QT_MOC_LITERAL(91, 1275, 2), // "ID"
QT_MOC_LITERAL(92, 1278, 10), // "getExample"
QT_MOC_LITERAL(93, 1289, 14), // "getExamplesFor"
QT_MOC_LITERAL(94, 1304, 14), // "seekablePhrase"
QT_MOC_LITERAL(95, 1319, 12), // "getMatireals"
QT_MOC_LITERAL(96, 1332, 15), // "getMatirealsFor"
QT_MOC_LITERAL(97, 1348, 9), // "goOutHome"
QT_MOC_LITERAL(98, 1358, 13), // "setForOpening"
QT_MOC_LITERAL(99, 1372, 10), // "newOpening"
QT_MOC_LITERAL(100, 1383, 10), // "openWaited"
QT_MOC_LITERAL(101, 1394, 9), // "openState"
QT_MOC_LITERAL(102, 1404, 21), // "getCommentUrlWithName"
QT_MOC_LITERAL(103, 1426, 22), // "getBindFileUrlWithName"
QT_MOC_LITERAL(104, 1449, 22), // "getMatirealUrlWithName"
QT_MOC_LITERAL(105, 1472, 18), // "deleteBindWithName"
QT_MOC_LITERAL(106, 1491, 10), // "deleteBind"
QT_MOC_LITERAL(107, 1502, 21), // "deleteCommentWithName"
QT_MOC_LITERAL(108, 1524, 5), // "isDir"
QT_MOC_LITERAL(109, 1530, 9), // "setCurDir"
QT_MOC_LITERAL(110, 1540, 6), // "getDir"
QT_MOC_LITERAL(111, 1547, 4), // "QDir"
QT_MOC_LITERAL(112, 1552, 14), // "getMidMarkable"
QT_MOC_LITERAL(113, 1567, 16), // "getBeginMarkable"
QT_MOC_LITERAL(114, 1584, 14), // "getEndMarkable"
QT_MOC_LITERAL(115, 1599, 10), // "canNotSync"
QT_MOC_LITERAL(116, 1610, 25), // "haveCommentInThisPosition"
QT_MOC_LITERAL(117, 1636, 22), // "soundSourceIsLocalFile"
QT_MOC_LITERAL(118, 1659, 14), // "stopAllThreads"
QT_MOC_LITERAL(119, 1674, 13), // "setCurBindEnd"
QT_MOC_LITERAL(120, 1688, 3), // "pos"
QT_MOC_LITERAL(121, 1692, 15), // "setCurBindBegin"
QT_MOC_LITERAL(122, 1708, 16), // "addTextInComment"
QT_MOC_LITERAL(123, 1725, 11), // "commentName"
QT_MOC_LITERAL(124, 1737, 9), // "textColor"
QT_MOC_LITERAL(125, 1747, 5), // "clear"
QT_MOC_LITERAL(126, 1753, 19), // "recognizeIsFinished"
QT_MOC_LITERAL(127, 1773, 15), // "openingFinished"
QT_MOC_LITERAL(128, 1789, 18), // "handleNextOrFinish"
QT_MOC_LITERAL(129, 1808, 8), // "document"
QT_MOC_LITERAL(130, 1817, 10), // "TextStore*"
QT_MOC_LITERAL(131, 1828, 10), // "soundStore"
QT_MOC_LITERAL(132, 1839, 11), // "SoundStore*"
QT_MOC_LITERAL(133, 1851, 18), // "bindFilesListModel"
QT_MOC_LITERAL(134, 1870, 16), // "exampleListModel"
QT_MOC_LITERAL(135, 1887, 18), // "matirealsListModel"
QT_MOC_LITERAL(136, 1906, 16), // "commentListModel"
QT_MOC_LITERAL(137, 1923, 14), // "mouseIsPressed"
QT_MOC_LITERAL(138, 1938, 12), // "examplesSize"
QT_MOC_LITERAL(139, 1951, 8) // "diffSize"

    },
    "UIController\0soundSellectionChanged\0"
    "\0textSellectionChanged\0bindFilesListChanged\0"
    "exampleListChanged\0commentListChanged\0"
    "examplesSizeChanged\0matirealsListChanged\0"
    "diffSizeChanged\0curCommentUrlChanged\0"
    "titleChanged\0curStateChanged\0"
    "soundSourceChanged\0curExampleWordChanged\0"
    "someOpenChanged\0title\0setTitle\0"
    "getbindFilesList\0setbindFilesList\0"
    "newBindFiles\0getExampleList\0setExampleList\0"
    "newExamples\0getCommentList\0setCommentList\0"
    "newComments\0curCommentUrl\0setCurCommentUrl\0"
    "getMatirealsList\0setMatirealsList\0"
    "newMatireals\0curState\0setCurState\0"
    "newState\0curExampleWord\0setCurExampleWord\0"
    "saveHome\0push\0home\0save\0someOpen\0"
    "setSomeOpen\0newValue\0setSoundSource\0"
    "source\0soundSource\0setPreviewForCurLecture\0"
    "url\0getImageUrl\0bindFile\0getTitle\0"
    "synchBndFileList\0synchCommentList\0"
    "openBindFile\0bindFileName\0saveBindFile\0"
    "createBindFile\0soundFileName\0makeBind\0"
    "allTsBinding\0allStBinding\0curUserStBinding\0"
    "curTsBinding\0downloadBase\0uploadBase\0"
    "createAutoComments\0autoCommentsNumber\0"
    "addComment\0openSoundFile\0fileName\0"
    "cursorPosChanged\0setCursorPosInTimePos\0"
    "setTimePosInCursorPos\0markCurText\0"
    "markLastText\0unmarkLastText\0"
    "startSellectTimer\0markComment\0name\0"
    "unmarkComment\0setExamplesSize\0newSize\0"
    "getExamplesSize\0setDiffSize\0newDiff\0"
    "getDiffSize\0getCommentListSize\0"
    "getFirstComment\0formUrlToTranslateSellected\0"
    "playExample\0ID\0getExample\0getExamplesFor\0"
    "seekablePhrase\0getMatireals\0getMatirealsFor\0"
    "goOutHome\0setForOpening\0newOpening\0"
    "openWaited\0openState\0getCommentUrlWithName\0"
    "getBindFileUrlWithName\0getMatirealUrlWithName\0"
    "deleteBindWithName\0deleteBind\0"
    "deleteCommentWithName\0isDir\0setCurDir\0"
    "getDir\0QDir\0getMidMarkable\0getBeginMarkable\0"
    "getEndMarkable\0canNotSync\0"
    "haveCommentInThisPosition\0"
    "soundSourceIsLocalFile\0stopAllThreads\0"
    "setCurBindEnd\0pos\0setCurBindBegin\0"
    "addTextInComment\0commentName\0textColor\0"
    "clear\0recognizeIsFinished\0openingFinished\0"
    "handleNextOrFinish\0document\0TextStore*\0"
    "soundStore\0SoundStore*\0bindFilesListModel\0"
    "exampleListModel\0matirealsListModel\0"
    "commentListModel\0mouseIsPressed\0"
    "examplesSize\0diffSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     105,   14, // methods
      15,  730, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  539,    2, 0x06 /* Public */,
       3,    0,  540,    2, 0x06 /* Public */,
       4,    0,  541,    2, 0x06 /* Public */,
       5,    0,  542,    2, 0x06 /* Public */,
       6,    0,  543,    2, 0x06 /* Public */,
       7,    0,  544,    2, 0x06 /* Public */,
       8,    0,  545,    2, 0x06 /* Public */,
       9,    0,  546,    2, 0x06 /* Public */,
      10,    0,  547,    2, 0x06 /* Public */,
      11,    0,  548,    2, 0x06 /* Public */,
      12,    0,  549,    2, 0x06 /* Public */,
      13,    0,  550,    2, 0x06 /* Public */,
      14,    0,  551,    2, 0x06 /* Public */,
      15,    0,  552,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  553,    2, 0x0a /* Public */,
      17,    1,  554,    2, 0x0a /* Public */,
      18,    0,  557,    2, 0x0a /* Public */,
      19,    1,  558,    2, 0x0a /* Public */,
      21,    0,  561,    2, 0x0a /* Public */,
      22,    1,  562,    2, 0x0a /* Public */,
      24,    0,  565,    2, 0x0a /* Public */,
      25,    1,  566,    2, 0x0a /* Public */,
      27,    0,  569,    2, 0x0a /* Public */,
      28,    1,  570,    2, 0x0a /* Public */,
      29,    0,  573,    2, 0x0a /* Public */,
      30,    1,  574,    2, 0x0a /* Public */,
      32,    0,  577,    2, 0x0a /* Public */,
      33,    1,  578,    2, 0x0a /* Public */,
      35,    0,  581,    2, 0x0a /* Public */,
      36,    1,  582,    2, 0x0a /* Public */,
      37,    1,  585,    2, 0x0a /* Public */,
      37,    0,  588,    2, 0x2a /* Public | MethodCloned */,
      39,    0,  589,    2, 0x0a /* Public */,
      40,    0,  590,    2, 0x0a /* Public */,
      41,    0,  591,    2, 0x0a /* Public */,
      42,    1,  592,    2, 0x0a /* Public */,
      44,    1,  595,    2, 0x0a /* Public */,
      46,    0,  598,    2, 0x0a /* Public */,
      47,    1,  599,    2, 0x0a /* Public */,
      49,    1,  602,    2, 0x0a /* Public */,
      51,    1,  605,    2, 0x0a /* Public */,
      52,    0,  608,    2, 0x0a /* Public */,
      53,    0,  609,    2, 0x0a /* Public */,
      54,    1,  610,    2, 0x0a /* Public */,
      56,    1,  613,    2, 0x0a /* Public */,
      57,    1,  616,    2, 0x0a /* Public */,
      59,    0,  619,    2, 0x0a /* Public */,
      60,    0,  620,    2, 0x0a /* Public */,
      61,    0,  621,    2, 0x0a /* Public */,
      62,    0,  622,    2, 0x0a /* Public */,
      63,    0,  623,    2, 0x0a /* Public */,
      64,    0,  624,    2, 0x0a /* Public */,
      65,    0,  625,    2, 0x0a /* Public */,
      66,    1,  626,    2, 0x0a /* Public */,
      68,    0,  629,    2, 0x0a /* Public */,
      69,    1,  630,    2, 0x0a /* Public */,
      71,    0,  633,    2, 0x0a /* Public */,
      72,    0,  634,    2, 0x0a /* Public */,
      73,    0,  635,    2, 0x0a /* Public */,
      74,    0,  636,    2, 0x0a /* Public */,
      75,    0,  637,    2, 0x0a /* Public */,
      76,    0,  638,    2, 0x0a /* Public */,
      77,    0,  639,    2, 0x0a /* Public */,
      78,    1,  640,    2, 0x0a /* Public */,
      80,    1,  643,    2, 0x0a /* Public */,
      81,    1,  646,    2, 0x0a /* Public */,
      83,    0,  649,    2, 0x0a /* Public */,
      84,    1,  650,    2, 0x0a /* Public */,
      86,    0,  653,    2, 0x0a /* Public */,
      87,    0,  654,    2, 0x0a /* Public */,
      88,    0,  655,    2, 0x0a /* Public */,
      89,    0,  656,    2, 0x0a /* Public */,
      90,    1,  657,    2, 0x0a /* Public */,
      92,    0,  660,    2, 0x0a /* Public */,
      93,    1,  661,    2, 0x0a /* Public */,
      95,    0,  664,    2, 0x0a /* Public */,
      96,    1,  665,    2, 0x0a /* Public */,
      97,    0,  668,    2, 0x0a /* Public */,
      98,    1,  669,    2, 0x0a /* Public */,
     100,    0,  672,    2, 0x0a /* Public */,
     101,    0,  673,    2, 0x0a /* Public */,
     102,    1,  674,    2, 0x0a /* Public */,
     103,    1,  677,    2, 0x0a /* Public */,
     104,    1,  680,    2, 0x0a /* Public */,
     105,    1,  683,    2, 0x0a /* Public */,
     106,    1,  686,    2, 0x0a /* Public */,
     107,    1,  689,    2, 0x0a /* Public */,
     108,    1,  692,    2, 0x0a /* Public */,
     109,    1,  695,    2, 0x0a /* Public */,
     110,    1,  698,    2, 0x0a /* Public */,
     112,    0,  701,    2, 0x0a /* Public */,
     113,    0,  702,    2, 0x0a /* Public */,
     114,    0,  703,    2, 0x0a /* Public */,
     115,    0,  704,    2, 0x0a /* Public */,
     116,    0,  705,    2, 0x0a /* Public */,
     117,    0,  706,    2, 0x0a /* Public */,
     118,    0,  707,    2, 0x0a /* Public */,
     119,    1,  708,    2, 0x0a /* Public */,
     121,    1,  711,    2, 0x0a /* Public */,
     122,    3,  714,    2, 0x0a /* Public */,
     122,    2,  721,    2, 0x2a /* Public | MethodCloned */,
     125,    0,  726,    2, 0x0a /* Public */,
     126,    0,  727,    2, 0x09 /* Protected */,
     127,    0,  728,    2, 0x09 /* Protected */,
     128,    0,  729,    2, 0x09 /* Protected */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   20,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   23,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   26,
    QMetaType::QUrl,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   31,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   43,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QUrl,   48,
    QMetaType::QUrl, QMetaType::QString,   50,
    QMetaType::QString, QMetaType::QString,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   55,
    QMetaType::Void, QMetaType::QUrl,   55,
    QMetaType::Void, QMetaType::QUrl,   58,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   67,
    QMetaType::QUrl,
    QMetaType::Void, QMetaType::QString,   70,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   79,
    QMetaType::Void, QMetaType::QString,   79,
    QMetaType::Void, QMetaType::Int,   82,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   85,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   91,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   94,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   94,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   99,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QUrl, QMetaType::QString,   79,
    QMetaType::QUrl, QMetaType::QString,   79,
    QMetaType::QUrl, QMetaType::QString,   79,
    QMetaType::Void, QMetaType::QString,   79,
    QMetaType::Void, QMetaType::QString,   70,
    QMetaType::Void, QMetaType::QString,   79,
    QMetaType::Bool, QMetaType::QString,   79,
    QMetaType::Void, QMetaType::QString,   79,
    0x80000000 | 111, QMetaType::QString,   79,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,  120,
    QMetaType::Void, QMetaType::LongLong,  120,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,  123,    2,  124,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  123,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
     129, 0x80000000 | 130, 0x0009510b,
     131, 0x80000000 | 132, 0x0009510b,
     133, QMetaType::QStringList, 0x00495003,
     134, QMetaType::QStringList, 0x00495003,
     135, QMetaType::QStringList, 0x00495003,
     136, QMetaType::QStringList, 0x00495003,
     137, QMetaType::Bool, 0x00095102,
     138, QMetaType::Int, 0x00495103,
     139, QMetaType::Int, 0x00495103,
      27, QMetaType::QUrl, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      32, QMetaType::QString, 0x00495001,
      46, QMetaType::QString, 0x00495103,
      35, QMetaType::QString, 0x00495103,
      41, QMetaType::Bool, 0x00495103,

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
       9,
      10,
      11,
      12,
      13,

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
        case 9: _t->titleChanged(); break;
        case 10: _t->curStateChanged(); break;
        case 11: _t->soundSourceChanged(); break;
        case 12: _t->curExampleWordChanged(); break;
        case 13: _t->someOpenChanged(); break;
        case 14: { QString _r = _t->title();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: { QStringList _r = _t->getbindFilesList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 17: _t->setbindFilesList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 18: { QStringList _r = _t->getExampleList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 19: _t->setExampleList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 20: { QStringList _r = _t->getCommentList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 21: _t->setCommentList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 22: { QUrl _r = _t->curCommentUrl();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 23: _t->setCurCommentUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 24: { QStringList _r = _t->getMatirealsList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 25: _t->setMatirealsList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 26: { QString _r = _t->curState();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 27: _t->setCurState((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: { QString _r = _t->curExampleWord();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 29: _t->setCurExampleWord((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->saveHome((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->saveHome(); break;
        case 32: _t->home(); break;
        case 33: _t->save(); break;
        case 34: { bool _r = _t->someOpen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 35: _t->setSomeOpen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->setSoundSource((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 37: { QString _r = _t->soundSource();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 38: _t->setPreviewForCurLecture((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 39: { QUrl _r = _t->getImageUrl((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 40: { QString _r = _t->getTitle((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 41: _t->synchBndFileList(); break;
        case 42: _t->synchCommentList(); break;
        case 43: _t->openBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 44: _t->saveBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 45: _t->createBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 46: _t->makeBind(); break;
        case 47: _t->allTsBinding(); break;
        case 48: _t->allStBinding(); break;
        case 49: _t->curUserStBinding(); break;
        case 50: _t->curTsBinding(); break;
        case 51: _t->downloadBase(); break;
        case 52: _t->uploadBase(); break;
        case 53: _t->createAutoComments((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 54: { QUrl _r = _t->addComment();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 55: _t->openSoundFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 56: _t->cursorPosChanged(); break;
        case 57: _t->setCursorPosInTimePos(); break;
        case 58: _t->setTimePosInCursorPos(); break;
        case 59: _t->markCurText(); break;
        case 60: _t->markLastText(); break;
        case 61: _t->unmarkLastText(); break;
        case 62: _t->startSellectTimer(); break;
        case 63: _t->markComment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 64: _t->unmarkComment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 65: _t->setExamplesSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 66: { qint32 _r = _t->getExamplesSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 67: _t->setDiffSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 68: { qint32 _r = _t->getDiffSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 69: { qint32 _r = _t->getCommentListSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 70: { QString _r = _t->getFirstComment();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 71: { QString _r = _t->formUrlToTranslateSellected();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 72: _t->playExample((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 73: _t->getExample(); break;
        case 74: _t->getExamplesFor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 75: _t->getMatireals(); break;
        case 76: _t->getMatirealsFor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 77: _t->goOutHome(); break;
        case 78: _t->setForOpening((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 79: _t->openWaited(); break;
        case 80: { QString _r = _t->openState();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 81: { QUrl _r = _t->getCommentUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 82: { QUrl _r = _t->getBindFileUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 83: { QUrl _r = _t->getMatirealUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 84: _t->deleteBindWithName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 85: _t->deleteBind((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 86: _t->deleteCommentWithName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 87: { bool _r = _t->isDir((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 88: _t->setCurDir((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 89: { QDir _r = _t->getDir((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDir*>(_a[0]) = _r; }  break;
        case 90: { qint32 _r = _t->getMidMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 91: { qint32 _r = _t->getBeginMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 92: { qint32 _r = _t->getEndMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 93: { bool _r = _t->canNotSync();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 94: { bool _r = _t->haveCommentInThisPosition();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 95: { bool _r = _t->soundSourceIsLocalFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 96: _t->stopAllThreads(); break;
        case 97: _t->setCurBindEnd((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 98: _t->setCurBindBegin((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 99: _t->addTextInComment((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3]))); break;
        case 100: _t->addTextInComment((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 101: _t->clear(); break;
        case 102: _t->recognizeIsFinished(); break;
        case 103: _t->openingFinished(); break;
        case 104: _t->handleNextOrFinish(); break;
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
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::titleChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::curStateChanged)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::soundSourceChanged)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::curExampleWordChanged)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (UIController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UIController::someOpenChanged)) {
                *result = 13;
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
        case 10: *reinterpret_cast< QString*>(_v) = _t->title(); break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->curState(); break;
        case 12: *reinterpret_cast< QString*>(_v) = _t->soundSource(); break;
        case 13: *reinterpret_cast< QString*>(_v) = _t->curExampleWord(); break;
        case 14: *reinterpret_cast< bool*>(_v) = _t->someOpen(); break;
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
        case 10: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 12: _t->setSoundSource(*reinterpret_cast< QString*>(_v)); break;
        case 13: _t->setCurExampleWord(*reinterpret_cast< QString*>(_v)); break;
        case 14: _t->setSomeOpen(*reinterpret_cast< bool*>(_v)); break;
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
        if (_id < 105)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 105;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 105)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 105;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 15;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 15;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 15;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 15;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 15;
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

// SIGNAL 9
void UIController::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void UIController::curStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void UIController::soundSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void UIController::curExampleWordChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void UIController::someOpenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

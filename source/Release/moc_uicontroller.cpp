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
    QByteArrayData data[131];
    char stringdata0[1854];
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
QT_MOC_LITERAL(14, 244, 5), // "title"
QT_MOC_LITERAL(15, 250, 8), // "setTitle"
QT_MOC_LITERAL(16, 259, 16), // "getbindFilesList"
QT_MOC_LITERAL(17, 276, 16), // "setbindFilesList"
QT_MOC_LITERAL(18, 293, 12), // "newBindFiles"
QT_MOC_LITERAL(19, 306, 14), // "getExampleList"
QT_MOC_LITERAL(20, 321, 14), // "setExampleList"
QT_MOC_LITERAL(21, 336, 11), // "newExamples"
QT_MOC_LITERAL(22, 348, 14), // "getCommentList"
QT_MOC_LITERAL(23, 363, 14), // "setCommentList"
QT_MOC_LITERAL(24, 378, 11), // "newComments"
QT_MOC_LITERAL(25, 390, 13), // "curCommentUrl"
QT_MOC_LITERAL(26, 404, 16), // "setCurCommentUrl"
QT_MOC_LITERAL(27, 421, 16), // "getMatirealsList"
QT_MOC_LITERAL(28, 438, 16), // "setMatirealsList"
QT_MOC_LITERAL(29, 455, 12), // "newMatireals"
QT_MOC_LITERAL(30, 468, 8), // "curState"
QT_MOC_LITERAL(31, 477, 11), // "setCurState"
QT_MOC_LITERAL(32, 489, 8), // "newState"
QT_MOC_LITERAL(33, 498, 8), // "saveHome"
QT_MOC_LITERAL(34, 507, 4), // "push"
QT_MOC_LITERAL(35, 512, 4), // "home"
QT_MOC_LITERAL(36, 517, 4), // "save"
QT_MOC_LITERAL(37, 522, 14), // "setSoundSource"
QT_MOC_LITERAL(38, 537, 6), // "source"
QT_MOC_LITERAL(39, 544, 11), // "soundSource"
QT_MOC_LITERAL(40, 556, 23), // "setPreviewForCurLecture"
QT_MOC_LITERAL(41, 580, 3), // "url"
QT_MOC_LITERAL(42, 584, 11), // "getImageUrl"
QT_MOC_LITERAL(43, 596, 8), // "bindFile"
QT_MOC_LITERAL(44, 605, 8), // "getTitle"
QT_MOC_LITERAL(45, 614, 16), // "synchBndFileList"
QT_MOC_LITERAL(46, 631, 16), // "synchCommentList"
QT_MOC_LITERAL(47, 648, 12), // "openBindFile"
QT_MOC_LITERAL(48, 661, 12), // "bindFileName"
QT_MOC_LITERAL(49, 674, 12), // "saveBindFile"
QT_MOC_LITERAL(50, 687, 14), // "createBindFile"
QT_MOC_LITERAL(51, 702, 13), // "soundFileName"
QT_MOC_LITERAL(52, 716, 8), // "makeBind"
QT_MOC_LITERAL(53, 725, 12), // "allTsBinding"
QT_MOC_LITERAL(54, 738, 12), // "allStBinding"
QT_MOC_LITERAL(55, 751, 16), // "curUserStBinding"
QT_MOC_LITERAL(56, 768, 10), // "addComment"
QT_MOC_LITERAL(57, 779, 4), // "path"
QT_MOC_LITERAL(58, 784, 13), // "openSoundFile"
QT_MOC_LITERAL(59, 798, 8), // "fileName"
QT_MOC_LITERAL(60, 807, 16), // "cursorPosChanged"
QT_MOC_LITERAL(61, 824, 21), // "setCursorPosInTimePos"
QT_MOC_LITERAL(62, 846, 21), // "setTimePosInCursorPos"
QT_MOC_LITERAL(63, 868, 11), // "markCurText"
QT_MOC_LITERAL(64, 880, 12), // "markLastText"
QT_MOC_LITERAL(65, 893, 14), // "unmarkLastText"
QT_MOC_LITERAL(66, 908, 17), // "startSellectTimer"
QT_MOC_LITERAL(67, 926, 11), // "markComment"
QT_MOC_LITERAL(68, 938, 4), // "name"
QT_MOC_LITERAL(69, 943, 13), // "unmarkComment"
QT_MOC_LITERAL(70, 957, 15), // "setExamplesSize"
QT_MOC_LITERAL(71, 973, 7), // "newSize"
QT_MOC_LITERAL(72, 981, 15), // "getExamplesSize"
QT_MOC_LITERAL(73, 997, 11), // "setDiffSize"
QT_MOC_LITERAL(74, 1009, 7), // "newDiff"
QT_MOC_LITERAL(75, 1017, 11), // "getDiffSize"
QT_MOC_LITERAL(76, 1029, 18), // "getCommentListSize"
QT_MOC_LITERAL(77, 1048, 15), // "getFirstComment"
QT_MOC_LITERAL(78, 1064, 27), // "formUrlToTranslateSellected"
QT_MOC_LITERAL(79, 1092, 11), // "playExample"
QT_MOC_LITERAL(80, 1104, 2), // "ID"
QT_MOC_LITERAL(81, 1107, 10), // "getExample"
QT_MOC_LITERAL(82, 1118, 14), // "getExamplesFor"
QT_MOC_LITERAL(83, 1133, 14), // "seekablePhrase"
QT_MOC_LITERAL(84, 1148, 12), // "getMatireals"
QT_MOC_LITERAL(85, 1161, 15), // "getMatirealsFor"
QT_MOC_LITERAL(86, 1177, 9), // "goOutHome"
QT_MOC_LITERAL(87, 1187, 13), // "setForOpening"
QT_MOC_LITERAL(88, 1201, 10), // "newOpening"
QT_MOC_LITERAL(89, 1212, 10), // "openWaited"
QT_MOC_LITERAL(90, 1223, 9), // "openState"
QT_MOC_LITERAL(91, 1233, 21), // "getCommentUrlWithName"
QT_MOC_LITERAL(92, 1255, 22), // "getBindFileUrlWithName"
QT_MOC_LITERAL(93, 1278, 22), // "getMatirealUrlWithName"
QT_MOC_LITERAL(94, 1301, 18), // "deleteBindWithName"
QT_MOC_LITERAL(95, 1320, 10), // "deleteBind"
QT_MOC_LITERAL(96, 1331, 21), // "deleteCommentWithName"
QT_MOC_LITERAL(97, 1353, 5), // "isDir"
QT_MOC_LITERAL(98, 1359, 9), // "setCurDir"
QT_MOC_LITERAL(99, 1369, 6), // "getDir"
QT_MOC_LITERAL(100, 1376, 4), // "QDir"
QT_MOC_LITERAL(101, 1381, 14), // "getMidMarkable"
QT_MOC_LITERAL(102, 1396, 16), // "getBeginMarkable"
QT_MOC_LITERAL(103, 1413, 14), // "getEndMarkable"
QT_MOC_LITERAL(104, 1428, 10), // "canNotSync"
QT_MOC_LITERAL(105, 1439, 25), // "haveCommentInThisPosition"
QT_MOC_LITERAL(106, 1465, 14), // "stopAllThreads"
QT_MOC_LITERAL(107, 1480, 19), // "addWordInCurBindEnd"
QT_MOC_LITERAL(108, 1500, 21), // "addWordInCurBindBegin"
QT_MOC_LITERAL(109, 1522, 24), // "deleteWordFromCurBindEnd"
QT_MOC_LITERAL(110, 1547, 26), // "deleteWordFromCurBindBegin"
QT_MOC_LITERAL(111, 1574, 13), // "setCurBindEnd"
QT_MOC_LITERAL(112, 1588, 3), // "pos"
QT_MOC_LITERAL(113, 1592, 15), // "setCurBindBegin"
QT_MOC_LITERAL(114, 1608, 16), // "addTextInComment"
QT_MOC_LITERAL(115, 1625, 11), // "commentName"
QT_MOC_LITERAL(116, 1637, 9), // "textColor"
QT_MOC_LITERAL(117, 1647, 19), // "recognizeIsFinished"
QT_MOC_LITERAL(118, 1667, 15), // "openingFinished"
QT_MOC_LITERAL(119, 1683, 18), // "handleNextOrFinish"
QT_MOC_LITERAL(120, 1702, 8), // "document"
QT_MOC_LITERAL(121, 1711, 10), // "TextStore*"
QT_MOC_LITERAL(122, 1722, 10), // "soundStore"
QT_MOC_LITERAL(123, 1733, 11), // "SoundStore*"
QT_MOC_LITERAL(124, 1745, 18), // "bindFilesListModel"
QT_MOC_LITERAL(125, 1764, 16), // "exampleListModel"
QT_MOC_LITERAL(126, 1781, 18), // "matirealsListModel"
QT_MOC_LITERAL(127, 1800, 16), // "commentListModel"
QT_MOC_LITERAL(128, 1817, 14), // "mouseIsPressed"
QT_MOC_LITERAL(129, 1832, 12), // "examplesSize"
QT_MOC_LITERAL(130, 1845, 8) // "diffSize"

    },
    "UIController\0soundSellectionChanged\0"
    "\0textSellectionChanged\0bindFilesListChanged\0"
    "exampleListChanged\0commentListChanged\0"
    "examplesSizeChanged\0matirealsListChanged\0"
    "diffSizeChanged\0curCommentUrlChanged\0"
    "titleChanged\0curStateChanged\0"
    "soundSourceChanged\0title\0setTitle\0"
    "getbindFilesList\0setbindFilesList\0"
    "newBindFiles\0getExampleList\0setExampleList\0"
    "newExamples\0getCommentList\0setCommentList\0"
    "newComments\0curCommentUrl\0setCurCommentUrl\0"
    "getMatirealsList\0setMatirealsList\0"
    "newMatireals\0curState\0setCurState\0"
    "newState\0saveHome\0push\0home\0save\0"
    "setSoundSource\0source\0soundSource\0"
    "setPreviewForCurLecture\0url\0getImageUrl\0"
    "bindFile\0getTitle\0synchBndFileList\0"
    "synchCommentList\0openBindFile\0"
    "bindFileName\0saveBindFile\0createBindFile\0"
    "soundFileName\0makeBind\0allTsBinding\0"
    "allStBinding\0curUserStBinding\0addComment\0"
    "path\0openSoundFile\0fileName\0"
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
    "haveCommentInThisPosition\0stopAllThreads\0"
    "addWordInCurBindEnd\0addWordInCurBindBegin\0"
    "deleteWordFromCurBindEnd\0"
    "deleteWordFromCurBindBegin\0setCurBindEnd\0"
    "pos\0setCurBindBegin\0addTextInComment\0"
    "commentName\0textColor\0recognizeIsFinished\0"
    "openingFinished\0handleNextOrFinish\0"
    "document\0TextStore*\0soundStore\0"
    "SoundStore*\0bindFilesListModel\0"
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
      98,   14, // methods
      13,  684, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  504,    2, 0x06 /* Public */,
       3,    0,  505,    2, 0x06 /* Public */,
       4,    0,  506,    2, 0x06 /* Public */,
       5,    0,  507,    2, 0x06 /* Public */,
       6,    0,  508,    2, 0x06 /* Public */,
       7,    0,  509,    2, 0x06 /* Public */,
       8,    0,  510,    2, 0x06 /* Public */,
       9,    0,  511,    2, 0x06 /* Public */,
      10,    0,  512,    2, 0x06 /* Public */,
      11,    0,  513,    2, 0x06 /* Public */,
      12,    0,  514,    2, 0x06 /* Public */,
      13,    0,  515,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  516,    2, 0x0a /* Public */,
      15,    1,  517,    2, 0x0a /* Public */,
      16,    0,  520,    2, 0x0a /* Public */,
      17,    1,  521,    2, 0x0a /* Public */,
      19,    0,  524,    2, 0x0a /* Public */,
      20,    1,  525,    2, 0x0a /* Public */,
      22,    0,  528,    2, 0x0a /* Public */,
      23,    1,  529,    2, 0x0a /* Public */,
      25,    0,  532,    2, 0x0a /* Public */,
      26,    1,  533,    2, 0x0a /* Public */,
      27,    0,  536,    2, 0x0a /* Public */,
      28,    1,  537,    2, 0x0a /* Public */,
      30,    0,  540,    2, 0x0a /* Public */,
      31,    1,  541,    2, 0x0a /* Public */,
      33,    1,  544,    2, 0x0a /* Public */,
      33,    0,  547,    2, 0x2a /* Public | MethodCloned */,
      35,    0,  548,    2, 0x0a /* Public */,
      36,    0,  549,    2, 0x0a /* Public */,
      37,    1,  550,    2, 0x0a /* Public */,
      39,    0,  553,    2, 0x0a /* Public */,
      40,    1,  554,    2, 0x0a /* Public */,
      42,    1,  557,    2, 0x0a /* Public */,
      44,    1,  560,    2, 0x0a /* Public */,
      45,    0,  563,    2, 0x0a /* Public */,
      46,    0,  564,    2, 0x0a /* Public */,
      47,    1,  565,    2, 0x0a /* Public */,
      49,    1,  568,    2, 0x0a /* Public */,
      50,    1,  571,    2, 0x0a /* Public */,
      52,    0,  574,    2, 0x0a /* Public */,
      53,    0,  575,    2, 0x0a /* Public */,
      54,    0,  576,    2, 0x0a /* Public */,
      55,    0,  577,    2, 0x0a /* Public */,
      56,    0,  578,    2, 0x0a /* Public */,
      56,    1,  579,    2, 0x0a /* Public */,
      58,    1,  582,    2, 0x0a /* Public */,
      60,    0,  585,    2, 0x0a /* Public */,
      61,    0,  586,    2, 0x0a /* Public */,
      62,    0,  587,    2, 0x0a /* Public */,
      63,    0,  588,    2, 0x0a /* Public */,
      64,    0,  589,    2, 0x0a /* Public */,
      65,    0,  590,    2, 0x0a /* Public */,
      66,    0,  591,    2, 0x0a /* Public */,
      67,    1,  592,    2, 0x0a /* Public */,
      69,    1,  595,    2, 0x0a /* Public */,
      70,    1,  598,    2, 0x0a /* Public */,
      72,    0,  601,    2, 0x0a /* Public */,
      73,    1,  602,    2, 0x0a /* Public */,
      75,    0,  605,    2, 0x0a /* Public */,
      76,    0,  606,    2, 0x0a /* Public */,
      77,    0,  607,    2, 0x0a /* Public */,
      78,    0,  608,    2, 0x0a /* Public */,
      79,    1,  609,    2, 0x0a /* Public */,
      81,    0,  612,    2, 0x0a /* Public */,
      82,    1,  613,    2, 0x0a /* Public */,
      84,    0,  616,    2, 0x0a /* Public */,
      85,    1,  617,    2, 0x0a /* Public */,
      86,    0,  620,    2, 0x0a /* Public */,
      87,    1,  621,    2, 0x0a /* Public */,
      89,    0,  624,    2, 0x0a /* Public */,
      90,    0,  625,    2, 0x0a /* Public */,
      91,    1,  626,    2, 0x0a /* Public */,
      92,    1,  629,    2, 0x0a /* Public */,
      93,    1,  632,    2, 0x0a /* Public */,
      94,    1,  635,    2, 0x0a /* Public */,
      95,    1,  638,    2, 0x0a /* Public */,
      96,    1,  641,    2, 0x0a /* Public */,
      97,    1,  644,    2, 0x0a /* Public */,
      98,    1,  647,    2, 0x0a /* Public */,
      99,    1,  650,    2, 0x0a /* Public */,
     101,    0,  653,    2, 0x0a /* Public */,
     102,    0,  654,    2, 0x0a /* Public */,
     103,    0,  655,    2, 0x0a /* Public */,
     104,    0,  656,    2, 0x0a /* Public */,
     105,    0,  657,    2, 0x0a /* Public */,
     106,    0,  658,    2, 0x0a /* Public */,
     107,    0,  659,    2, 0x0a /* Public */,
     108,    0,  660,    2, 0x0a /* Public */,
     109,    0,  661,    2, 0x0a /* Public */,
     110,    0,  662,    2, 0x0a /* Public */,
     111,    1,  663,    2, 0x0a /* Public */,
     113,    1,  666,    2, 0x0a /* Public */,
     114,    3,  669,    2, 0x0a /* Public */,
     114,    2,  676,    2, 0x2a /* Public | MethodCloned */,
     117,    0,  681,    2, 0x09 /* Protected */,
     118,    0,  682,    2, 0x09 /* Protected */,
     119,    0,  683,    2, 0x09 /* Protected */,

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

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   18,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   21,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   24,
    QMetaType::QUrl,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   29,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   38,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QUrl,   41,
    QMetaType::QUrl, QMetaType::QString,   43,
    QMetaType::QString, QMetaType::QString,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   48,
    QMetaType::Void, QMetaType::QUrl,   48,
    QMetaType::Void, QMetaType::QUrl,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QUrl,
    QMetaType::Void, QMetaType::QUrl,   57,
    QMetaType::Void, QMetaType::QString,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   68,
    QMetaType::Void, QMetaType::QString,   68,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   74,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   80,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   83,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   83,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   88,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QUrl, QMetaType::QString,   68,
    QMetaType::QUrl, QMetaType::QString,   68,
    QMetaType::QUrl, QMetaType::QString,   68,
    QMetaType::Void, QMetaType::QString,   68,
    QMetaType::Void, QMetaType::QString,   59,
    QMetaType::Void, QMetaType::QString,   68,
    QMetaType::Bool, QMetaType::QString,   68,
    QMetaType::Void, QMetaType::QString,   68,
    0x80000000 | 100, QMetaType::QString,   68,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,  112,
    QMetaType::Void, QMetaType::LongLong,  112,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,  115,    2,  116,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  115,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
     120, 0x80000000 | 121, 0x0009510b,
     122, 0x80000000 | 123, 0x0009510b,
     124, QMetaType::QStringList, 0x00495003,
     125, QMetaType::QStringList, 0x00495003,
     126, QMetaType::QStringList, 0x00495003,
     127, QMetaType::QStringList, 0x00495003,
     128, QMetaType::Bool, 0x00095102,
     129, QMetaType::Int, 0x00495103,
     130, QMetaType::Int, 0x00495103,
      25, QMetaType::QUrl, 0x00495103,
      14, QMetaType::QString, 0x00495103,
      30, QMetaType::QString, 0x00495001,
      39, QMetaType::QString, 0x00495103,

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
        case 12: { QString _r = _t->title();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: { QStringList _r = _t->getbindFilesList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 15: _t->setbindFilesList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 16: { QStringList _r = _t->getExampleList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 17: _t->setExampleList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 18: { QStringList _r = _t->getCommentList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 19: _t->setCommentList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 20: { QUrl _r = _t->curCommentUrl();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 21: _t->setCurCommentUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 22: { QStringList _r = _t->getMatirealsList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 23: _t->setMatirealsList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 24: { QString _r = _t->curState();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 25: _t->setCurState((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: _t->saveHome((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->saveHome(); break;
        case 28: _t->home(); break;
        case 29: _t->save(); break;
        case 30: _t->setSoundSource((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: { QString _r = _t->soundSource();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 32: _t->setPreviewForCurLecture((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 33: { QUrl _r = _t->getImageUrl((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 34: { QString _r = _t->getTitle((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 35: _t->synchBndFileList(); break;
        case 36: _t->synchCommentList(); break;
        case 37: _t->openBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 38: _t->saveBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 39: _t->createBindFile((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 40: _t->makeBind(); break;
        case 41: _t->allTsBinding(); break;
        case 42: _t->allStBinding(); break;
        case 43: _t->curUserStBinding(); break;
        case 44: { QUrl _r = _t->addComment();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 45: _t->addComment((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 46: _t->openSoundFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 47: _t->cursorPosChanged(); break;
        case 48: _t->setCursorPosInTimePos(); break;
        case 49: _t->setTimePosInCursorPos(); break;
        case 50: _t->markCurText(); break;
        case 51: _t->markLastText(); break;
        case 52: _t->unmarkLastText(); break;
        case 53: _t->startSellectTimer(); break;
        case 54: _t->markComment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 55: _t->unmarkComment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 56: _t->setExamplesSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 57: { qint32 _r = _t->getExamplesSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 58: _t->setDiffSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 59: { qint32 _r = _t->getDiffSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 60: { qint32 _r = _t->getCommentListSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 61: { QString _r = _t->getFirstComment();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 62: { QString _r = _t->formUrlToTranslateSellected();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 63: _t->playExample((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 64: _t->getExample(); break;
        case 65: _t->getExamplesFor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 66: _t->getMatireals(); break;
        case 67: _t->getMatirealsFor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 68: _t->goOutHome(); break;
        case 69: _t->setForOpening((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 70: _t->openWaited(); break;
        case 71: { QString _r = _t->openState();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 72: { QUrl _r = _t->getCommentUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 73: { QUrl _r = _t->getBindFileUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 74: { QUrl _r = _t->getMatirealUrlWithName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        case 75: _t->deleteBindWithName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 76: _t->deleteBind((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 77: _t->deleteCommentWithName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 78: { bool _r = _t->isDir((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 79: _t->setCurDir((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 80: { QDir _r = _t->getDir((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDir*>(_a[0]) = _r; }  break;
        case 81: { qint32 _r = _t->getMidMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 82: { qint32 _r = _t->getBeginMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 83: { qint32 _r = _t->getEndMarkable();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 84: { bool _r = _t->canNotSync();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 85: { bool _r = _t->haveCommentInThisPosition();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 86: _t->stopAllThreads(); break;
        case 87: _t->addWordInCurBindEnd(); break;
        case 88: _t->addWordInCurBindBegin(); break;
        case 89: _t->deleteWordFromCurBindEnd(); break;
        case 90: _t->deleteWordFromCurBindBegin(); break;
        case 91: _t->setCurBindEnd((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 92: _t->setCurBindBegin((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 93: _t->addTextInComment((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3]))); break;
        case 94: _t->addTextInComment((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 95: _t->recognizeIsFinished(); break;
        case 96: _t->openingFinished(); break;
        case 97: _t->handleNextOrFinish(); break;
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
        if (_id < 98)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 98;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 98)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 98;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 13;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 13;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 13;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 13;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 13;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

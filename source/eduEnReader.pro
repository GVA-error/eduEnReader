TEMPLATE = app

QT += qml quick
CONFIG += c++11
CONFIG += qt plugin #
LIBS += -lsndfile
QT += multimedia multimediawidgets
QT += webengine
QT += webenginewidgets

SOURCES += main.cpp \
    soundstore.cpp \
    logic.cpp \
    soundfragment.cpp \
    textfragment.cpp \
    textstore.cpp \
    uicontroller.cpp \
    ASR/asr.cpp \
    ASR/bindmaker.cpp \
    ASR/datapreparation.cpp \
    ASR/metrics.cpp \
    ASR/wavworker.cpp \
    store.cpp \
    fragment.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

QML_DESIGNER_IMPORT_PATH =
# Default rules for deployment.
#include(deployment.pri)

HEADERS += \
    soundstore.h \
    logic.h \
    soundfragment.h \
    textfragment.h \
    textstore.h \
    uicontroller.h \
    ASR/asr.h \
    ASR/bindmaker.h \
    ASR/datapreparation.h \
    ASR/metrics.h \
    ASR/wavworker.h \
    store.h \
    fragment.h \
    webtranslator.h

DISTFILES += \
    images/editcopy.png \
    images/editcut.png \
    images/editpaste.png \
    images/editredo.png \
    images/editundo.png \
    images/exportpdf.png \
    images/filenew.png \
    images/fileopen.png \
    images/fileprint.png \
    images/filesave.png \
    images/qt-logo.png \
    images/textbold.png \
    images/textcenter.png \
    images/textitalic.png \
    images/textjustify.png \
    images/textleft.png \
    images/textright.png \
    images/textunder.png \
    images/zoomin.png \
    images/zoomout.png

DEFINES += QT_DEPRECATED_WARNINGS

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

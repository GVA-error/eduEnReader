TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11
CONFIG += qt plugin

SOURCES += main.cpp \
    soundstore.cpp \
    logic.cpp \
    soundfragment.cpp \
    textfragment.cpp \
    textstore.cpp \
    soundplayer.cpp \
    riff/riff.cc \
    soundreader.cpp \
    uicontroller.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    soundstore.h \
    logic.h \
    soundfragment.h \
    textfragment.h \
    textstore.h \
    soundplayer.h \
    riff/cdefs.h \
    riff/riff.h \
    soundreader.h \
    uicontroller.h

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

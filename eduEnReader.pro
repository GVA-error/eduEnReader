TEMPLATE = app

QT += qml quick
QT += multimedia multimediawidgets
CONFIG += c++11

SOURCES += main.cpp \
    soundstore.cpp \
    logic.cpp \
    soundfragment.cpp \
    textfragment.cpp \
    textstore.cpp \
    soundplayer.cpp \
    riff/riff.cc \
    soundreader.cpp \
    factory.cpp \
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
    factory.h \
    uicontroller.h

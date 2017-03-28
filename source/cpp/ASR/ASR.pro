QT += core
QT -= gui

TARGET = ASR
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

LIBS += -lsndfile

TEMPLATE = app

SOURCES += main.cpp \
    asr.cpp \
    datapreparation.cpp \
    wavworker.cpp \
    bindmaker.cpp \
    metrics.cpp

HEADERS += \
    asr.h \
    datapreparation.h \
    wavworker.h \
    bindmaker.h \
    metrics.h


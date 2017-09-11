
qtHaveModule(widgets): QT += widgets
QT += qml quick quickcontrols2
QT += multimedia multimediawidgets
QT += webengine
QT += webenginewidgets

CONFIG += c++11
CONFIG += qt plugin

#manjaro
#LIBS += -lsndfile
#LIBS += -L/usr/local/lib64/ -lVLCQtCore -lVLCQtQml

#suse
LIBS += -lsndfile
LIBS += -lVLCQtCore -lVLCQtQml

#windows
#INCLUDEPATH += C:\vlcqt\include
#LIBS += -lC:\vlcqt\lib\VLCQtCore -lC:\vlcqt\lib\VLCQtQml

SOURCES += main.cpp \
    cpp/fragment.cpp \
    cpp/logic.cpp \
    cpp/soundfragment.cpp \
    cpp/soundstore.cpp \
    cpp/store.cpp \
    cpp/textfragment.cpp \
    cpp/textstore.cpp \
    cpp/uicontroller.cpp \
    cpp/Binding/asr.cpp \
    cpp/Binding/bindmaker.cpp \
    cpp/Binding/datapreparation.cpp \
    cpp/Binding/metrics.cpp \
    cpp/Binding/scripter.cpp \
    cpp/Binding/wavworker.cpp \
    cpp/Binding/graph.cpp \
    cpp/Utilits/setting.cpp \
    cpp/Processes/process.cpp \
    cpp/Processes/bindopenprocess.cpp \
    cpp/Processes/tsbindingprocess.cpp \
    cpp/Processes/scriptprocess.cpp \
    cpp/Utilits/wordcash.cpp \
    cpp/Processes/cashingprocess.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    cpp/fragment.h \
    cpp/logic.h \
    cpp/soundfragment.h \
    cpp/soundstore.h \
    cpp/store.h \
    cpp/textfragment.h \
    cpp/textstore.h \
    cpp/uicontroller.h \
    cpp/Binding/asr.h \
    cpp/Binding/bindmaker.h \
    cpp/Binding/datapreparation.h \
    cpp/Binding/metrics.h \
    cpp/Binding/scripter.h \
    cpp/Binding/wavworker.h \
    cpp/Binding/graph.h \
    cpp/Utilits/setting.h \
    cpp/Processes/process.h \
    cpp/Processes/bindopenprocess.h \
    cpp/Processes/tsbindingprocess.h \
    cpp/Processes/scriptprocess.h \
    cpp/Utilits/wordcash.h \
    cpp/Processes/cashingprocess.h


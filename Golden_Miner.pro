#-------------------------------------------------
#
# Project created by QtCreator 2019-07-02T20:12:22
#
#-------------------------------------------------

QT       += core gui
RC_ICONS = myico.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Golden_Miner
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
        cuishi_hook.cpp \
        defeat.cpp \
        finish.cpp \
        help.cpp \
        jiqi_hook.cpp \
        main.cpp \
        gm.cpp \
        mode_choose.cpp \
        play_double.cpp \
        play_double_item.cpp \
        play_double_view.cpp \
        play_single.cpp \
        play_single_view.cpp \
        play_single_view_item.cpp \
        store.cpp \
        victory.cpp

HEADERS += \
        cuishi_hook.h \
        defeat.h \
        finish.h \
        gm.h \
        help.h \
        jiqi_hook.h \
        judge.h \
        mode_choose.h \
        play_double.h \
        play_double_item.h \
        play_double_view.h \
        play_single.h \
        play_single_view.h \
        play_single_view_item.h \
        store.h \
        victory.h

FORMS += \
        defeat.ui \
        finish.ui \
        gm.ui \
        help.ui \
        mode_choose.ui \
        play_double.ui \
        play_single.ui \
        store.ui \
        victory.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

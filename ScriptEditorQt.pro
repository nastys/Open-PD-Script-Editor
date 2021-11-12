QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DSC.cpp \
    command.cpp \
    diag/diag_addcommand.cpp \
    diag/diag_addcommand2.cpp \
    diag/diag_find2.cpp \
    diag/diag_format.cpp \
    diag/diag_lipsync.cpp \
    diag/diag_lipsync_vsqx.cpp \
    diag/diag_merge.cpp \
    diag/diag_merge2.cpp \
    diag/diag_pvslot.cpp \
    diag/diag_time.cpp \
    lipsync/lipsync_midiseq.cpp \
    lipsync/lipsync_v1_0.cpp \
    helper/logger.cpp \
    helper/lyrics.cpp \
    main.cpp \
    mainwindow/mainwindow.cpp \
    mainwindow/mainwindow_convert.cpp \
    mainwindow/mainwindow_touchbar.cpp \
    helper/pdtime.cpp \
    helper/qstring_helper.cpp

HEADERS += \
    DoubleDigitQSpinBox.h \
    DSC.h \
    helper/EditWidgets.h \
    command.h \
    helper/debug.h \
    diag/diag_addcommand.h \
    diag/diag_addcommand2.h \
    diag/diag_find2.h \
    diag/diag_format.h \
    diag/diag_lipsync.h \
    diag/diag_lipsync_vsqx.h \
    diag/diag_merge.h \
    diag/diag_merge2.h \
    diag/diag_pvslot.h \
    diag/diag_time.h \
    lipsync/lipsync.h \
    lipsync/lipsync_midiseq.h \
    lipsync/lipsync_settings.h \
    helper/logger.h \
    helper/lyrics.h \
    mainwindow/mainwindow.h \
    helper/pdtime.h \
    helper/qstring_helper.h

macx {
SOURCES += \
    KDMacTouchBar/kdmactouchbar.mm \

HEADERS += \
    KDMacTouchBar/kdmactouchbar.h \
    KDMacTouchBar/kdmactouchbar_global.h \
}

FORMS += \
    diag/diag_addcommand.ui \
    diag/diag_addcommand2.ui \
    diag/diag_find2.ui \
    diag/diag_format.ui \
    diag/diag_lipsync.ui \
    diag/diag_lipsync_vsqx.ui \
    diag/diag_merge.ui \
    diag/diag_merge2.ui \
    diag/diag_pvslot.ui \
    diag/diag_time.ui \
    mainwindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    db.qrc \
    res.qrc

QMAKE_CXXFLAGS_RELEASE -= -O
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE *= -O3
QMAKE_LFLAGS_RELEASE -= -O1
QMAKE_LFLAGS_RELEASE -= -O2
QMAKE_LFLAGS_RELEASE *= -O3

SUBDIRS += \
    KDMacTouchBar/src.pro

DISTFILES += \
    KDMacTouchBar/CMakeLists.txt \
    KDMacTouchBar/LICENSE.LGPL.txt \
    KDMacTouchBar/README.md

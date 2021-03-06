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
    diag_addcommand.cpp \
    diag_addcommand2.cpp \
    diag_find2.cpp \
    diag_format.cpp \
    diag_lipsync.cpp \
    diag_lipsync_vsqx.cpp \
    diag_merge.cpp \
    diag_merge2.cpp \
    diag_pvslot.cpp \
    diag_time.cpp \
    lipsync_midiseq.cpp \
    lipsync_v1_0.cpp \
    logger.cpp \
    lyrics.cpp \
    main.cpp \
    mainwindow.cpp \
    pdtime.cpp \
    qstring_helper.cpp

HEADERS += \
    DoubleDigitQSpinBox.h \
    DSC.h \
    EditWidgets.h \
    command.h \
    debug.h \
    diag_addcommand.h \
    diag_addcommand2.h \
    diag_find2.h \
    diag_format.h \
    diag_lipsync.h \
    diag_lipsync_vsqx.h \
    diag_merge.h \
    diag_merge2.h \
    diag_pvslot.h \
    diag_time.h \
    lipsync.h \
    lipsync_midiseq.h \
    lipsync_settings.h \
    logger.h \
    lyrics.h \
    mainwindow.h \
    pdtime.h \
    qstring_helper.h

macx {
SOURCES += \
    KDMacTouchBar/kdmactouchbar.mm \

HEADERS += \
    KDMacTouchBar/kdmactouchbar.h \
    KDMacTouchBar/kdmactouchbar_global.h \
}

FORMS += \
    diag_addcommand.ui \
    diag_addcommand2.ui \
    diag_find2.ui \
    diag_format.ui \
    diag_lipsync.ui \
    diag_lipsync_vsqx.ui \
    diag_merge.ui \
    diag_merge2.ui \
    diag_pvslot.ui \
    diag_time.ui \
    mainwindow.ui

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

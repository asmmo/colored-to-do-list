#include(target_platform.pro)
#include(dest_path.pro)

#DESTDIR_TARGET = $$PWD/../binaries/$$dest_path
#RCC_DIR = $$PWD/shadow-builds/$$dest_path/.RCC
#MOC_DIR = $$PWD/shadow-builds/$$dest_path/.MOC
#OBJECTS_DIR = $$PWD/shadow-builds/$$dest_path/.OBJECTS
#UI_DIR = $$PWD/shadow-builds/$$dest_path/.UI

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++20
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    task.cpp

HEADERS += \
    mainwindow.h \
    task.h

FORMS += \
    mainwindow.ui \
    task.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

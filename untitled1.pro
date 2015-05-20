#-------------------------------------------------
#
# Project created by QtCreator 2015-05-18T15:34:55
#
#-------------------------------------------------

QT       += core gui
QT       += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glscene.cpp \
    vaomanager.cpp \
    camera.cpp

HEADERS  += mainwindow.h \
    glscene.h \
    vaomanager.h \
    camera.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    explain.txt

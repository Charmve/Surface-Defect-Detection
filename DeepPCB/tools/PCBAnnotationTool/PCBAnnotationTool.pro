#-------------------------------------------------
#
# Project created by QtCreator 2018-06-25T22:46:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PCBAnnotationTool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagewidget.cpp \
    drawwidget.cpp \
    utils.cpp

HEADERS  += mainwindow.h \
    imagewidget.h \
    drawwidget.h \
    datadef.h \
    utils.h

FORMS    += mainwindow.ui

RESOURCES += \
    src.qrc

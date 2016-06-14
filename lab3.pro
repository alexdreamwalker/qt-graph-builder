#-------------------------------------------------
#
# Project created by QtCreator 2012-11-23T23:34:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    relation.cpp \
    graph.cpp \
    structtable.cpp \
    timetable.cpp

HEADERS  += mainwindow.h \
    node.h \
    relation.h \
    graph.h \
    structtable.h \
    timetable.h

FORMS    += mainwindow.ui \
    structtable.ui

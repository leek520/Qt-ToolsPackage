#-------------------------------------------------
#
# Project created by QtCreator 2018-12-14T13:41:51
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qcanpool
TEMPLATE = app


include(./qcanpool/qcanpool-lib.pri)

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

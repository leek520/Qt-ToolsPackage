#-------------------------------------------------
#
# Project created by QtCreator 2019-12-23T21:15:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CustomWidgets
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui



include(./MultiComboBox/MultiComboBox.pri)

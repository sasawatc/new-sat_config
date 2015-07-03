#-------------------------------------------------
#
# Project created by QtCreator 2015-06-23T15:44:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sat_config
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    satconfigsys.cpp \
    parampushbutton.cpp \
    parameditdialog.cpp \
    station.cpp \
    stationeditdialog.cpp \
    satellite.cpp

HEADERS  += mainwindow.h \
    satconfigsys.h \
    ui_mainwindow.h \
    globalcontext.h \
    parampushbutton.h \
    parameditdialog.h \
    ui_parameditdialog.h \
    station.h \
    stationeditdialog.h \
    ui_stationeditdialog.h \
    satellite.h


FORMS    += mainwindow.ui \
    parameditdialog.ui \
    stationeditdialog.ui

#CONFIG   += console
#CONFIG   -= app_bundle

#-------------------------------------------------
#
# Project created by QtCreator 2017-06-05T07:24:10
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = USRoasterStudio
TEMPLATE = app
RC_FILE = usrstudio.rc

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    coffeeroastingprofile.cpp \
    clouddialog.cpp \
    controlroomdialog.cpp \
    graphicalcreatordialog.cpp \
    directorysettingsdialog.cpp

HEADERS  += mainwindow.h \
    coffeeroastingprofile.h \
    clouddialog.h \
    controlroomdialog.h \
    graphicalcreatordialog.h \
    directorysettingsdialog.h

FORMS    += mainwindow.ui \
    clouddialog.ui \
    controlroomdialog.ui \
    graphicalcreatordialog.ui \
    directorysettingsdialog.ui

#-------------------------------------------------
#
# Project created by QtCreator 2016-08-15T16:58:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JugendControlPanel-1-0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    licht.cpp \
    einstellung.cpp \
    einstellunglicht.cpp \
    einstellunghauptlicht.cpp \
    thread.cpp \
    rgbwand.cpp \
    mythread.cpp \
    pca_9635.cpp

HEADERS  += mainwindow.h \
    einstellung.h \
    einstellunglicht.h \
    licht.h \
    einstellunghauptlicht.h \
    thread.h \
    rgbwand.h \
    mythread.h \
    pca_9635.h

FORMS    += mainwindow.ui \
    licht.ui \
    einstellunglicht.ui \
    einstellung.ui \
    einstellunghauptlicht.ui \
    rgbwand.ui

RESOURCES += \
    bilder.qrc

LIBS +=-L/usr/local/lib -lwiringPi

INCLUDEPATH    += /usr/local/include

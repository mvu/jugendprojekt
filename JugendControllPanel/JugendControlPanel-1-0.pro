#-------------------------------------------------
#
# Project created by QtCreator 2016-08-15T16:58:46
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JugendControlPanel-1-0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    licht.cpp \
    einstellung.cpp \
    einstellunghauptlicht.cpp \
    rgbwand.cpp \
    mythread.cpp \
    pca_9635.cpp \
    passwort.cpp \
    mainconfig.cpp \
    maincontroll.cpp \
    modelthreadlicht.cpp \
    steuerungthreadlicht.cpp \
    rgb_decke.cpp \
    thread_ueberwachung.cpp \
    sliderarduino.cpp \
    thread_slider.cpp \
    menue_einstellung.cpp \
    theke.cpp \
    palette.cpp \
    application.cpp \
    audio.cpp \
    medien_auswahl.cpp \
    arduinocommunication.cpp

HEADERS  += mainwindow.h \
    licht.h \
    einstellunghauptlicht.h \
    rgbwand.h \
    mythread.h \
    pca_9635.h \
    mainconfig.h \
    passwort.h \
    modelthreadlicht.h \
    steuerungthreadlicht.h \
    maincontroll.h \
    rgb_decke.h \
    thread_ueberwachung.h \
    sliderarduino.h \
    thread_slider.h \
    menue_einstellung.h \
    theke.h \
    einstellung.h \
    palette.h \
    application.h \
    audio.h \
    medien_auswahl.h \
    arduinocommunication.h

FORMS    += mainwindow.ui \
    licht.ui \
    einstellung.ui \
    einstellunghauptlicht.ui \
    rgbwand.ui \
    passwort.ui \
    rgb_decke.ui \
    menue_einstellung.ui \
    theke.ui \
    palette.ui \
    audio.ui \
    medien_auswahl.ui

RESOURCES += \
    bilder.qrc

LIBS +=-L/usr/lib -lwiringPi

INCLUDEPATH    += /usr/local/include

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
    mainconfig.cpp \
    thread_ueberwachung.cpp \
    application.cpp \
    Steuer_arduinocommunication.cpp \
    Steuer_steuerungthreadlicht.cpp \
    Steuer_maincontroll.cpp \
    MainVisu_rgb_decke.cpp \
    MainVisu_rgbwand.cpp \
    MainVisu_palette.cpp \
    MainVisu_passwort.cpp \
    MainVisu_menue_einstellung.cpp \
    MainVisu_licht.cpp \
    MainVisu_einstellunghauptlicht.cpp \
    MainVisu_audio.cpp \
    MainVisu_einstellung.cpp \
    MainVisu_medien_auswahl.cpp \
    MainVisu_mainwindow.cpp \
    MainVisu_theke.cpp \
    Data_modelthreadlicht.cpp \
    MainVisu_config.cpp \
    mainvisu_infoboard.cpp

HEADERS  += \
    mainconfig.h \
    thread_ueberwachung.h \
    application.h \
    Steuer_arduinocommunication.h \
    Steuer_steuerungthreadlicht.h \
    Steuer_maincontroll.h \
    MainVisu_audio.h \
    MainVisu_config.h \
    MainVisu_einstellung.h \
    MainVisu_einstellunghauptlicht.h \
    MainVisu_licht.h \
    MainVisu_mainwindow.h \
    MainVisu_medien_auswahl.h \
    MainVisu_menue_einstellung.h \
    MainVisu_palette.h \
    MainVisu_passwort.h \
    MainVisu_rgbwand.h \
    MainVisu_rgb_decke.h \
    Data_modelthreadlicht.h \
    MainVisu_theke.h \
    mainvisu_infoboard.h

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
    medien_auswahl.ui \
    config.ui \
    mainvisu_infoboard.ui

RESOURCES += \
    bilder.qrc

LIBS +=-L/usr/lib -lwiringPi

INCLUDEPATH    += /usr/local/include

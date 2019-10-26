#-------------------------------------------------
#
# Project created by QtCreator 2019-01-14T20:10:33
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ControlPanel-3-0
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    src/gui/einstellung_audio.cpp \
    src/gui/einstellung_hauptlicht.cpp \
    src/gui/einstellung_rgb_decke.cpp \
    src/gui/einstellung_rgb_wand.cpp \
    src/gui/einstellung_theke.cpp \
    src/gui/menue_licht.cpp \
    src/gui/menue_medien.cpp \
    src/gui/menue_speichern.cpp \
    src/gui/passwort.cpp \
    src/gui/startseite.cpp \
    src/gui/system_status.cpp \
    src/model/application.cpp \
    src/model/hardware.cpp \
    src/model/hauptlicht_streifen.cpp \
    src/model/i2cdevice.cpp \
    src/model/j_element.cpp \
    src/model/j_slider.cpp \
    src/model/jugendraum.cpp \
    src/model/main.cpp \
    src/model/paletten_licht.cpp \
    src/model/rgb_element.cpp \
    src/model/rgb_streifen.cpp
    src/model/theken_licht.cpp \
    src/model/wand_rgb.cpp \

HEADERS += \
    inc/gui/einstellung_audio.h \
    inc/gui/einstellung_hauptlicht.h \
    inc/gui/einstellung_rgb_decke.h \
    inc/gui/einstellung_rgb_wand.h \
    inc/gui/einstellung_theke.h \
    inc/gui/menue_licht.h \
    inc/gui/menue_medien.h \
    inc/gui/menue_speichern.h \
    inc/gui/passwort.h \
    inc/gui/startseite.h \
    inc/gui/system_status.h \
    inc/model/application.h \
    inc/model/file_handler.h \
    inc/model/hardware.h \
    inc/model/hardware_config.h \
    inc/model/hardware_register.h \
    inc/model/hauptlicht_streifen.h \
    inc/model/i2cdevice.h \
    inc/model/j_element.h \
    inc/model/j_slider.h \
    inc/model/jugendraum.h \
    inc/model/paletten_licht.h \
    inc/model/rgb_element.h \
    inc/model/rgb_streifen.h
    inc/model/theken_licht.h \
    inc/model/wand_rgb.h \

FORMS += \
    ui/einstellung_audio.ui \
    ui/einstellung_hauptlicht.ui \
    ui/einstellung_theke.ui \
    ui/einstellung_rgb_decke.ui \
    ui/einstellung_rgb_wand.ui \
    ui/menue_licht.ui \
    ui/menue_medien.ui \
    ui/menue_speichern.ui
    ui/passwort.ui \
    ui/system_status.ui \
    ui/startseite.ui \

RESOURCES += \
    ui/backgrounds.qrc \
    ui/icons.qrc

# rules for deployment.
target.path = /home/pi
INSTALLS += target

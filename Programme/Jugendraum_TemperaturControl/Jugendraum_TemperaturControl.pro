QT += core
QT -= gui
QT += network

CONFIG += c++11

TARGET = Jugendraum_TemperaturControl
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    src/main.cpp \
    src/hardware.cpp \
    src/j_temperature_controller.cpp \
    src/temperature_manager.cpp \
    src/temperature_controller_pi.cpp

HEADERS += \
    inc/hardware.h \
    inc/hardware_config.h \
    inc/hardware_register.h \
    inc/j_temperature_controller.h \
    inc/file_handler.h \
    inc/temperature_manager.h \
    inc/temperature_controller_pi.h

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# rules for deployment.
target.path = /home/pi
INSTALLS += target

#ifndef MAINCONFIG_H
#define MAINCONFIG_H

//hardware
#include <wiringPi.h>
#include <wiringPiI2C.h>


//threads
#include "Steuer_steuerungthreadlicht.h"
#include "Data_modelthreadlicht.h"
#include "thread_ueberwachung.h"
#include "thread_slider.h"

//special libs
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

//for debugging
#include <iostream>

//Qt specific
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDateTime>
#include <QTimer>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QProcess>
#include <QThread>
#include <QObject>
#include <QtCore>
#include <QList>
#include <QByteArray>

//Event Filter
#include "application.h"
#include "Steuer_arduinocommunication.h"

// Programm Definierung
#define Slider_I2c          0x00    // umstellen zwischen I2c oder Ethernet Slider
#define useWiringPi         0x00    // zum Arbeiten an PC ohne  WiringPi
#define PortExpanderIOA     0x00    // Ein und Ausgäng vom PortExpander Definieren Kanal A
#define PortExpanderIOB     0x00    // Ein und Ausgäng vom PortExpander Definieren Kanal B
#define NotaPi              0x01    // Eins wenn es kein Pi ist um Programm auf ein Pc zu testen

// PCA REGISTER ALLE
#define PCA9635_MODE1       0x00
#define PCA9635_MODE2       0x01
#define PCA9635_PWM0        0x02
#define PCA9635_PWM1        0x03
#define PCA9635_PWM2        0x04
#define PCA9635_PWM3        0x05
#define PCA9635_PWM4        0x06
#define PCA9635_PWM5        0x07
#define PCA9635_PWM6        0x08
#define PCA9635_PWM7        0x09
#define PCA9635_PWM8        0x0A
#define PCA9635_PWM9        0x0B
#define PCA9635_PWM10       0x0C
#define PCA9635_PWM11       0x0D
#define PCA9635_PWM12       0x0E
#define PCA9635_PWM13       0x0F
#define PCA9635_PWM14       0x10
#define PCA9635_PWM15       0x11
#define PCA9635_PWM16       0x12
#define PCA9635_GRPPWM      0x12
#define PCA9635_GRPFREQ     0x13
#define PCA9635_LEDOUT0     0x14
#define PCA9635_LEDOUT1     0x15
#define PCA9635_LEDOUT2     0x16
#define PCA9635_LEDOUT3     0x17
#define PCA9635_SUBADR1     0x18
#define PCA9635_SUBADR2     0x19
#define PCA9635_SUBADR3     0x1A
#define PCA9635_ALLCALLADR  0x1B


#define PCAHL               0x5d
#define PCARGB              0x4f
#define ARDUINOSLIDERi2c    0x0e
#define PORTEXPANDER        0x22
#define LUEFTERTOP          0x04
#define LUEFTERNETZEIL      0x03
#define LUEFTERHAUPTLICHT   0x02
#define LUEFTERONKYO        0x08
#define RGBFENSTERGRUEN     0x0d
#define RGBFENSTERBLAU      0x0c
#define RGBFENSTERROT       0x0b
#define RGBTHEKEROT         0x0e
#define RGBTHEKEGREUN       0x0f
#define RGBTHEKEBLAU        0x10

// Slider Defines


#define SLIDERARdUINOI2C    0x0e
#define SLIDERSETONE        "A"
#define SLIDERSETTWO        "B"
#define SLIDERSETTHREE      "C"
#define SLIDERSETFOUR       "D"
#define SLIDERGETONE        "A0"
#define SLIDERGETTWO        "B0"
#define SLIDERGETTHREE      "C0"
#define SLIDERGETFOUR       "D0"

// Relais steuerung mit GPIO

#define NETZTEIL48V         0x80
#define THEKE               0x02
#define PALETTE             0x04
#define BEAMER              0x08
#define NETZTEIL12V         0x01
#define PC                  0x02    // <-- GPIOB !!!!!!
#define LeeresRelais1       0x10
#define LeeresRelais2       0x20
#define LeeresRelais3       0x40


// 5V Eingänge vom PortExpander
#define TasterEingang       0x10

// PortExpander
#define IODIRA              0x00
#define IODIRB              0x01
#define GPIOA               0x12
#define GPIOB               0x13


//Temperaturschwellwerte
#define THRESHOLD 30.0
#define HYSTERESE 3.0
#define LuefterMin 0.2 //minimalwert in dezimal für Lüfter(ausreichend zum Anluafen)
#define LuefterTopMin 0.5 //großer deckenluefter läuft sonst nicht an

#define TempPi_High 50.0
#define TempPi_Crit 70.0
#define TempNetz_High 40.0
#define TempNetz_Crit 60.0
#define TempPlat_High 40.0
#define TempPlat_Crit 50.0
#define TempRaum_High 30.0
#define TempRaum_Crit 35.0
#define TempPc_High 45.0
#define TempPc_Crit 60.0
#define TempOnkyo_High 40.0
#define TempOnkyo_Crit 50.0

// Array Definition in Model Thread

// ar = array Temp = Temperatur alle float werte der Temperaturen
#define arTempController1   0
#define arTempController2   1
#define arTempNetzteil      2
#define arTempDecke         3
#define arTempRaspberry     4

// ar = array Re = Relais  Schaltstatus von den Relais
#define arReNetzteil48V     1
#define arReTheke           2
#define arRePalette         3
#define arReBeamer          4
#define arReNetzteil12V     5
#define arRePC              6
#define arReSpare1          7
#define arReSpare2          8
#define arReSpare3          9

// Array Hauptlicht ist nach der folge wie das Array 0 - 7 - 0 = Hauptlicht 1

// ar = array St = Status   Alle status werte
#define arStComSlider       1
#define arStComTemp         2
#define arStI2c             3
#define arStTemp            4
#define arStUart            5



// Arduino Ethernet Einstellung

#define ARDUINOTEMP     0x00
#define ARDUINOSLIDER   0x01
#define IP_Slider       ipSlider
#define PORT_Slider     portSlider
#define IP_Temp         ip_Temp
#define PORT_Temp       port_Temp
#define AktualisierungsZeit 10;     // Zeit in msec, danach wird 1 Slider ausgelesen

const QString ipSlider      = "192.168.188.249";
const quint16 portSlider    = 9999;
const QString ip_Temp       = "192.168.188.250";
const quint16 port_Temp     = 8888;

// Init
void init();
extern int pcaRGB;
extern int pcaHL;
extern int expander;
extern int slider;
extern int UART;

#endif // MAINCONFIG_H

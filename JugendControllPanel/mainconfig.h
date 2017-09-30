#ifndef MAINCONFIG_H
#define MAINCONFIG_H

//hardware
#include <wiringPi.h>
#include <wiringPiI2C.h>

//threads
#include "steuerungthreadlicht.h"
#include "modelthreadlicht.h"
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

//Event Filter
#include "application.h"

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
#define ARDUINOSLIDER       0x0e
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

#define SLIDERARDUINO       0x0e
#define SLIDERSETONE        0x00
#define SLIDERSETTWO        0x01
#define SLIDERSETTHREE      0x02
#define SLIDERSETFOUR       0x03
#define SLIDERGETONE        0x00
#define SLIDERGETTWO        0x01
#define SLIDERGETTHREE      0x02
#define SLIDERGETFOUR       0x03

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

// Init
void init();
extern int pcaRGB;
extern int pcaHL;
extern int expander;
extern int slider;
extern int UART;



#endif // MAINCONFIG_H

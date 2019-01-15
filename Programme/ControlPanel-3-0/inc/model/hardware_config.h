/*! \file hardware_config.h
 * \brief Definiert die Pinbelegung im Schaltschrank
 */

#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

// I2C Adressen
#define PCA_LIGHT           0x5d
#define PORTEXPANDER        0x22

// Ausgänge von PCA_LIGHT
#define RGB_FENSTER_ROT     0x0b
#define RGB_FENSTER_GRUEN   0x0d
#define RGB_FENSTER_BLAU    0x0c
#define RGB_THEKE_ROT       0x0e
#define RGB_THEKE_GREUN     0x0f
#define RGB_THEKE_BLAU      0x10

// Ausgänge von PORTEXPANDER
// GPIOA
#define NETZTEIL_12V        0x01
#define THEKE               0x02
#define PALETTE             0x04
#define BEAMER              0x08
#define RELAIS_1            0x10
#define RELAIS_2            0x20
#define RELAIS_3            0x40
#define NETZTEIL48V         0x80
//GPIOB
#define PC                  0x02    // <-- GPIOB !!!!!!

// Eingänge von Portexpander
#define TasterEingang       0x10

// Direkte Verbindung zum Pi, Nummerierung nach wiringPi
#define SWITCH_INTERRUPT_PI 7


#endif // HARDWARE_CONFIG_H

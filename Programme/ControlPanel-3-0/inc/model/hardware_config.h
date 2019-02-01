/*! \file hardware_config.h
 * \brief Definiert die Pinbelegung im Schaltschrank
 */
#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

#include "inc/model/hardware_register.h"

// UDP Verbindung für slider
#define SLIDER_UDP                  QHostAddress("192.168.1.111"), 8888
#define SLIDER_IP                   "192.168.1.111"
#define SLIDER_PORT                 8888
#define SLIDER_UPDATE_CYCLE_MS      50
#define SLIDER_NOISE_THRESHOLD      1

// update Zyklus für die gesamte Hardware
#define HW_UPDATE_INTERVAL_MS       5000

// I2C Adressen
#define PCA_LICHT                   0x5d
#define PORTEXPANDER                0x22

// Ausgänge von PCA_LIGHT
#define RGB_WAND_ROT                0x0b
#define RGB_WAND_GRUEN              0x0d
#define RGB_WAND_BLAU               0x0c
#define RGB_THEKE_ROT               0x0e
#define RGB_THEKE_GRUEN             0x0f
#define RGB_THEKE_BLAU              0x10

// Ausgänge von PORTEXPANDER
#define NETZTEIL_12V                GPIOA, 0x01
#define THEKE                       GPIOA, 0x02
#define PALETTE                     GPIOA, 0x04
#define BEAMER                      GPIOA, 0x08
#define RELAIS_1                    GPIOA, 0x10
#define RELAIS_2                    GPIOA, 0x20
#define RELAIS_3                    GPIOA, 0x40
#define NETZTEIL48V                 GPIOA, 0x80
#define PC                          GPIOB, 0x02

// Eingänge von Portexpander
#define TasterEingang               0x10

// Direkte Verbindung zum Pi, Nummerierung nach wiringPi
#define SWITCH_INTERRUPT_PI         7


#endif // HARDWARE_CONFIG_H

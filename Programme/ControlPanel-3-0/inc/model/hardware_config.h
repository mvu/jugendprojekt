/*! \file hardware_config.h
 * \brief Definiert die Pinbelegung im Schaltschrank
 */
#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

#include "inc/model/hardware_register.h"

// UDP Verbindung für slider
#define SLIDER_IP                   "192.168.1.111"
#define SLIDER_PORT                 8888
#define SLIDER_UDP                  QHostAddress(SLIDER_IP), SLIDER_PORT
#define SLIDER_UPDATE_CYCLE_MS      50
#define SLIDER_NOISE_THRESHOLD      1

// update Zyklus für die gesamte Hardware
#define HW_UPDATE_INTERVAL_MS       5000

// I2C Adressen
#define PCA_LICHT                   0x5d
#define PORTEXPANDER                0x22

// Ausgänge von PCA_LICHT
#define RGB_WAND_ROT                0x0b
#define RGB_WAND_GRUEN              0x0d
#define RGB_WAND_BLAU               0x0c
#define RGB_THEKE_ROT               0x0e
#define RGB_THEKE_GRUEN             0x0f
#define RGB_THEKE_BLAU              0x10

/*!
 * \brief Die Nummerierung der Streifen beginnt oben links (in der GUI) bei 1 
 * und geht dann gegen den Uhrzeigersinn bis 8. Für weitere
 * Erklärungen siehe den Kommentar zu Jugendraum::hauptlicht
 */
#define HL_STREIFEN_1               0x02
#define HL_STREIFEN_2               0x03
#define HL_STREIFEN_3               0x04
#define HL_STREIFEN_4               0x05
#define HL_STREIFEN_5               0x06
#define HL_STREIFEN_6               0x07
#define HL_STREIFEN_7               0x08
#define HL_STREIFEN_8               0x09

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

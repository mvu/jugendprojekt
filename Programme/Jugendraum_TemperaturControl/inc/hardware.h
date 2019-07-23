#ifndef HARDWARE_H
#define HARDWARE_H

#include <QtCore>
#include <QList>
#include <QByteArray>
#include <QtNetwork>
#include <QDebug>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#include "inc/hardware_config.h"
#include "inc/hardware_register.h"

/*!
 *  \brief Bietet high-level Zugriff auf Hardwarefunktionen
 */
namespace hw {

    /*!
     * \brief Initialisiert die Hardware
     */
    void init();

    /*!
     * \brief sendet einen PWM-Wert an einen Lüfter
     * \param reg Das Register; verwende die macros aus hardware_config.h
     * \param value PWM-Wert zwischen 0 und 100
     */
    void writePWMValue(uint8_t reg, double value);

    /*!
     * \brief liest den PWM-Wert eines Registers aus
     * \param reg Das Register; verwende die macros aus hardware_config.h
     * \return PWM-Wert zwischen 0 und 100
     */
    double readPWMValue(uint8_t reg);

    /*!
     * \brief Liefert das Register, das den Sensorwert enthält
     * \param sensor Der zu Lesende Sensor; Verwende Macros aus hardware_config.h
     * \return Register als high- und low-byte
     */
    QByteArray getSensorRegister(int sensor);

    /*!
     * \brief Sende ein Datenpaket
     * \param data Daten zum Versenden
     * \param ip IP des Empfängers
     * \param port Port des Empfängers
     * \todo Verhalten bei Schreibfehler implementieren
     */
    void writeUDP(QByteArray data, QHostAddress ip, quint16 port);

    /*!
    * \brief Liest Temperatur über UDP von einem entfernten Register, \\
    *   verwendet dazu SENSORS_UDP
    * \param ptr Pointer auf entferntes Register
    * \return Temperatur in °C; bei Lesefehler 100.000 °C
    * \todo Verhalten bei Lesefehler implementieren
    */
    double readTemperatureUDP(QByteArray ptr);
}

#endif // HARDWARE_H

#ifndef HARDWARE_H
#define HARDWARE_H

#include <QtCore>
#include <QList>
#include <QByteArray>
#include <QtNetwork>
#include <QDebug>

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
    void writePWMValue(uint8_t reg, uint8_t value);

    /*!
     * \brief liest den PWM-Wert eines Registers aus
     * \param reg Das Register; verwende die macros aus hardware_config.h
     * \return PWM-Wert zwischen 0 und 100
     */
    int readPWMValue(uint8_t reg);

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
    * \brief Liest einen uint16_t über UDP aus einem entfernten Register
    * \param reg Das zu lesende Register
    * \param ip IP des Empfängers, verwende zusammen mit port im Macro
    * \param port Port des Empfängers, verwende zusammen mit ip im Macro
    * \return Wert des Registers als int
    * \todo Verhalten bei Lesefehler implementieren
    * \todo auf float umbauen; Arduino liefert float
    */
    int readUDP(QByteArray reg, QHostAddress ip, quint16 port);
}

#endif // HARDWARE_H

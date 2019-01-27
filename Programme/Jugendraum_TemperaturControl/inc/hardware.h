#ifndef HARDWARE_H
#define HARDWARE_H

#include <QtCore>
#include <QList>
#include <QtNetwork/QUdpSocket>

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
     * \brief Holt sich die neuen Temperaturen vom Arduino
     * \todo Versuche erneut bei Lesefehler
     * \todo Prüfe Datenintegrität
     */
    void updateTemperatures();
    /*!
     * \brief sendet einen PWM-Wert an einen Lüfter
     * \param reg Das Register; verwende die macros aus hardware_config.h
     * \param value PWM-Wert zwischen 0 und 100
     */
    void writePWMValue(uint8_t, reg, uint8_t value);

    /*!
     * \brief liest den PWM-Wert eines Registers aus
     * \param reg Das Register; verwende die macros aus hardware_config.h
     * \return PWM-Wert zwischen 0 und 100
     */
    int readPWMValue(uint8_t reg);

    /*!
     * \brief Liest die Temperatur eines Sensors aus
     * \param sensor Der zu Lesende Sensor; Verwende Macros aus hardware_config.h
     * \return
     */
    float getTemperature(int sensor);

    int pca9635_fd;
    QList<float> temperatures;
    QUdpSocket* udp_sensors;
}

#endif // HARDWARE_H

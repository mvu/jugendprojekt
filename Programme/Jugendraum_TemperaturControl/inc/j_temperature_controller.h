/*!
 * \file j_temperature_controller.h
 * \brief Header der JTemperatureController Klasse
 */
#ifndef J_TEMPERATUR_CONTROLLER_H
#define J_TEMPERATUR_CONTROLLER_H

#include <QDebug>
#include <QString>
#include <QtMath>

#include "inc/hardware.h"

/*!
 * \brief Basisklasse für Temperatureregler
 * \todo Was passiert, wenn die kritische Temperatur (dauerhaft) überschritten wird?
 */
class JTemperatureController
{
public:
    /*!
     * \brief Constructor der JTemperatureController Klasse
     * \param sensor_id Sensor_id des Geräts; siehe hardware_config.h
     * \param fan_reg Register des PCAs, das den Lüfter steuert; siehe hardware_config.h
     * \param device_name Name des Geräts
     * \todo Min-/Max-/Threshold-/Hysterese- Werte aus Datei lesen
     */
    JTemperatureController(int sensor_id, int fan_reg, QString device_name);

    /*!
     * \brief Destructor
     */
    virtual ~JTemperatureController();

    /*!
     * \brief Liefert die Temperatur des kontrollierten Geräts
     * \return Die Temperatur des kontrollierten Geräts in °C
     */
    float getTemperature();

    /*!
     * \brief Liefert die Lüftergeschwindigkeit von 0 bis 100
     * \return Lüftergeschwindigkeit von 0 bis 100
     */
    float getFanSpeed();

    /*!
     * \brief Gibt dem Controller die neue Temperatur, der dann automatisch die
     *      Lüftergeschwindigkeit anpasst.
     * \param temperatur aktuelle Temperatur in °C
     */
    void updateTemperature(float temperatur);

protected:
    void readAllFromFile();
    void writeAllToFile(QString filename);

    /*!
     * \brief Liest die Temperatur des kontrollierten Gerätes aus
     * \return Temperatur in °C
     * \note Keine Anpassung für Standard-Temperatursensoren (UDP -> Arduino) nötig
     */
    virtual float readTemperatur();

    /*!
     * \brief Sendet PWM-Wert an Hardware
     * \param value PWM-Wert zwischen 0 und 100
     */
    virtual void writeFanSpeed(int value);

    /*!
     * \brief Berechnet Lüftergeschwindigkeit ausgehend von Temperatur,
     *      Min-/Max-Werten für Lüftergeschwindigkeiten und High-/Critical-Werten der
     *      Temperatur
     * \param temperatur Temperatur in °C
     * \return erforderliche Lüftergeschwindigkeit
     */
    int calculateFanSpeed(float temperatur);


    int sensor_id_, fan_reg_;
    QString device_name_;

    float temperatur_;
    float temp_high_, temp_crit_;
    float temp_threshold_, temp_hysteresis_;

    int fan_speed_;
    int fan_min_;

};

#endif // J_TEMPERATUR_CONTROLLER_H

/*!
 * \file j_temperature_controller.h
 * \brief Header der JTemperatureController Klasse
 */
#ifndef J_TEMPERATUR_CONTROLLER_H
#define J_TEMPERATUR_CONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QtMath>
#include <QTimer>

#include "inc/hardware.h"

/*!
 * \brief Basisklasse für Temperatureregler
 * \todo Was passiert, wenn die kritische Temperatur (dauerhaft) überschritten wird?
 */
class JTemperatureController : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Constructor der JTemperatureController Klasse
     * \param parent Erzeugendes QObject
     * \param sensor_id Sensor_id des Geräts; siehe hardware_config.h
     * \param fan_reg Register des PCAs, das den Lüfter steuert; siehe hardware_config.h
     * \param device_name Name des Geräts
     * \todo Min-/Max-/Threshold-/Hysterese- Werte aus Datei lesen
     */
    explicit JTemperatureController(QObject *parent = nullptr, int sensor_id = 1, int fan_reg = 0x00, QString device_name = "null");
    ~JTemperatureController();

    /*!
     * \brief Liefert die Temperatur des kontrollierten Geräts
     * \return Die Temperatur des kontrollierten Geräts in °C
     */
    float getTemperature();

    /*!
     * \brief Liefert die Lüftergeschwindigkeit von 0 bis 100
     * \return Lüftergeschwindigkeit von 0 (aus) bis 100 (voll an)
     */
    int getFanSpeed();

    /*!
     * \brief Setzt eine neue Lüftergeschwindigkeit
     * \param val Geschwindigkeit von 0 (aus) bis 100 (voll an)
     */
    void setFanSpeed(int val);
    /*!
     * \brief Liest alle Konfigutaionsdateien aus einer Datei
     * \param Datei, aus der alles gelesen werden soll
     */
    void readAllFromFile(QString filename);

    /*!
     * \brief Schreibt alle Konfigurationen in eine Datei
     * \param Die Datei, in der alles gespeichert werden soll
     */
    void writeAllToFile(QString filename);

private slots:
    /*!
     * \brief Holt sich die neue Temperatur und passt die Lüftergeschwindigkeit an
     */
    void update();

private:
    /*!
     * \brief Berechnet Lüftergeschwindigkeit ausgehend von Temperatur,
     *      Min-/Max-Werten für Lüftergeschwindigkeiten und High-/Critical-Werten der
     *      Temperatur
     * \param temperatur Temperatur in °C
     * \return erforderliche Lüftergeschwindigkeit von 0 (aus) bis 100 (voll an)
     */
    int calculateFanSpeed(float temperature);

    int sensor_id_, fan_reg_;
    QByteArray sensor_reg_;
    QString device_name_;

    float temperature_;
    float temp_high_, temp_crit_;
    float temp_threshold_, temp_hysteresis_;

    int fan_speed_;
    int fan_min_;

    QTimer * update_timer_;
};

#endif // J_TEMPERATUR_CONTROLLER_H

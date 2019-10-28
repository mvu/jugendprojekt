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
#include <QFileInfo>

#include "inc/hardware.h"
#include "inc/file_handler.h"
#include "inc/log.h"

/*!
 * \brief Basisklasse für Temperatureregler
 * \todo Was passiert, wenn die kritische Temperatur (dauerhaft) überschritten wird?
 */
class JTemperatureController : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Constructor der JTemperatureController Klasse für Gerät <b>mit</b> Lüfter
     * \param parent Erzeugendes QObject
     * \param sensor_id Sensor_id des Geräts; siehe hardware_config.h
     * \param fan_reg Register des PCAs, das den Lüfter steuert; siehe hardware_config.h.
     *      Für lüfterlose Controller verwende fan_reg = -1
     * \param device_name Name des Geräts
     */
    explicit JTemperatureController(QObject *parent = nullptr, int sensor_id = 1, int fan_reg = 0x00, QString device_name = "null");

    ~JTemperatureController();

    /*!
     * \brief Liefert die Temperatur des kontrollierten Geräts
     * \return Die Temperatur des kontrollierten Geräts in °C
     */
    double getTemperature() {return temperature_;}

    /*!
     * \brief Liefert die Lüftergeschwindigkeit von 0 bis 100; wenn kein Lüfter
     *      zum Gerät dazu gehört, -1
     * \return Lüftergeschwindigkeit von 0 (aus) bis 100 (voll an); -1 ohne Lüfter
     */
    int getFanSpeed() {return (has_fan_) ? fan_speed_ : -1;}

    /*!
     * \brief Liefert den Namen des Gerätes
     * \return Name des Gerätes
     */
    QString getName() {return device_name_;}

    /*!
     * \brief Liefert die Temperatur, bei der der Lüfter auf 100 % läuft
     * \return Temperatur in °C
     */
    double getTempHigh() {return temp_high_;}

    /*!
     * \brief Liefert die Temperatur, die als kritisch angesehen wird
     * \return Temperatur in °C
     */
    double getTempCritical() {return temp_crit_;}

    /*!
     * \brief Setzt eine neue Lüftergeschwindigkeit
     * \param val Geschwindigkeit von 0 (aus) bis 100 (voll an)
     * \details Die neue Geschwindigkeit wird nur dann an die hardware weiter
     *      geleitet, wenn sie verschieden von der aktuellen ist.
     */
    void setFanSpeed(int val);

    /*!
     * \brief Liest alle Konfigutaionsdateien aus einer Datei
     * \param Datei, aus der alles gelesen werden soll
     * \details Wenn die Nicht existiert, werden default-Werte aus hardware_config.h
     *      verwendet und diese anschließend in die Datei gespeichert.
     */
    void readConfigFromFile(QString filename);

    /*!
     * \brief Schreibt alle Konfigurationen in eine Datei
     * \param Die Datei, in der alles gespeichert werden soll
     */
    void saveConfigToFile(QString filename);

    /*!
     * \brief Startet den JTemperaturController. Es wird einmal pro Sekunde die neue
     *      Temperatur eingelesen und der Lüfter entsprechend nachgeregelt.
     */
    void start();

private slots:
    /*!
     * \brief Holt sich die neue Temperatur und passt die Lüftergeschwindigkeit an
     * \todo Prüfen, ob Zustand der Varaiblen mit Zustand des Systems übereinstimmt
     *      und gegebenenfalls korrigieren (+loggen)
     */
    void update();

protected:
    /*!
     * \brief Berechnet Lüftergeschwindigkeit ausgehend von Temperatur,
     *      Min-/Max-Werten für Lüftergeschwindigkeiten und High-/Critical-Werten der
     *      Temperatur
     * \param temperatur Temperatur in °C
     * \return erforderliche Lüftergeschwindigkeit von 0 (aus) bis 100 (voll an)
     */
    int calculateFanSpeed(double temperature);

    /*!
     * \brief Initialisiert den Controller
     */
    virtual void init();

    /*!
     * \brief Holt die aktuelle Temperatur von der Hardware
     * \return aktuelle Temperatur
     */
    virtual double readTemperature();

    bool has_fan_;
    int sensor_id_, fan_reg_;
    QByteArray sensor_reg_;
    QString device_name_;

    double temperature_ = 0.;
    double temp_high_, temp_crit_;
    double temp_threshold_, temp_hysteresis_;

    int fan_speed_ = 0;
    int fan_min_;

    QTimer * update_timer_;
};

#endif // J_TEMPERATUR_CONTROLLER_H

/*!
 * \file temperature_manager.h
 * \brief Header der TemperatureManager Klasse
 */
#ifndef TEMPERATUR_MANAGER_H
#define TEMPERATUR_MANAGER_H

#include <QObject>
#include <QTimer>
#include <QtNetwork>
#include <QTimer>
#include <QJsonObject>
#include <QDateTime>

#include "inc/j_temperature_controller.h"
#include "inc/temperature_controller_pi.h"
#include "inc/log.h"

/*!
 * \brief Klasse, die alle Sensoren und Lüfter verteilt und die einzelnen
 *      Geräte verwaltet. Kommuniziert mit ControlPanel über localhost
 */
class TemperatureManager : public QObject
{
    Q_OBJECT
public:
    explicit TemperatureManager(QObject *parent = nullptr);
    ~TemperatureManager();

    /*!
     * \brief Speichert die Konfigurationen aller JTemperaturController
     * \param filename Dateiname zum Speichern
     */
    void saveAllToFile(QString filename);

    /*!
     * \brief Veranlasst alle JTemperaturController dazu, ihre Konfigurationen
     *      neu einzulesen
     * \param filename Dateiname zum Lesen
     */
    void readAllFromFile(QString filename);

private:
    QUdpSocket * udp_control_;
    JTemperatureController *tc_onkyo_, *tc_cabin_, *tc_pwr_supply_, *tc_pc_, *tc_pcb_;
    JTemperatureController *tc_test_;
    TemperatureControllerPi *tc_pi_;

    QString conf_file_, log_file_;

private slots:
    void controlRequest();     //!< called by udp_control's ReadyRead() signal
};

#endif // TEMPERATUR_MANAGER_H
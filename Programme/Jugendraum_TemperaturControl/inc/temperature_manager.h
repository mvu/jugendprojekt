/*!
 * \file temperature_manager.h
 * \brief Header der TemperatureManager Klasse
 */
#ifndef TEMPERATUR_MANAGER_H
#define TEMPERATUR_MANAGER_H

#include <QObject>
#include <QTimer>
#include <QtNetwork/QUdpSocket>

#include "inc/j_temperature_controller.h"

/*!
 * \brief Klasse, die alle Sensoren und Lüfter verteilt und die einzelnen
 *      Geräte verwaltet. Kommuniziert mit ControlPanel über localhost
 */
class TemperatureManager : public QObject
{
    Q_OBJECT
public:
    explicit TemperatureManager(QObject *parent = nullptr);

private:
    QTimer* update_timer_;
    QUdpSocket* udp_control_panel_;
    JTemperatureController* pwr_supply_;    //!< testweise

signals:

public slots:

private slots:
    void update();                  //!< called by update_timer
    void controlPanelRequest();     //!< called by udp_control_panel's ReadyRead() signal
};

#endif // TEMPERATUR_MANAGER_H

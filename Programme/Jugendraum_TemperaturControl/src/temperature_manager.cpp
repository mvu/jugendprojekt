/*!
 * \file temperature_manager.h
 * \brief Header der TemperatureManager Klasse
 */
#include "inc/temperature_manager.h"

TemperatureManager::TemperatureManager(QObject *parent) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;

    // setup udo connection to control panel via udp on localhost
    udp_control_panel_ = new QUdpSocket(this);
    udp_sensors_->bind(QHostAddress::LocalHost, CONTROL_PANEL_PORT);
    connect(udp_sensors_, SIGNAL(readyRead()), this, SLOT(sensorsReadyRead()));

    // initialize controllers
    pwr_supply_ = new JTemperatureController(SENSOR_PWR_SUPPLY, FAN_PWR_SUPPLY, "Netzteile");
}

void TemperatureManager::update()
{
    qDebug() << Q_FUNC_INFO;
}

void TemperatureManager::controlPanelRequest()
{
    qDebug() << Q_FUNC_INFO;
}

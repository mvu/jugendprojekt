/*!
 * \file temperature_manager.h
 * \brief Header der TemperatureManager Klasse
 */
#include "inc/temperature_manager.h"

TemperatureManager::TemperatureManager(QObject *parent) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;

    // initialize the hardware
    hw::init();

    // setup udo connection to control panel via udp on localhost
    udp_control_panel_ = new QUdpSocket(this);
    udp_control_panel_->bind(CONTROL_PANEL_UDP);
    connect(udp_control_panel_, SIGNAL(readyRead()), this, SLOT(controlPanelRequest()));

    // initialize controllers
    tc_onkyo_ = new JTemperatureController(this, SENSOR_ONKYO, FAN_ONKYO, "Onkyo");
    tc_cabin_ = new JTemperatureController(this, SENSOR_CABIN, FAN_CABIN, "Schaltschrank");
    tc_pwr_supply_ = new JTemperatureController(this, SENSOR_PWR_SUPPLY, FAN_PWR_SUPPLY, "Netzteile");
}

TemperatureManager::~TemperatureManager()
{
    qDebug() << Q_FUNC_INFO;

    delete tc_cabin_;
    delete tc_onkyo_;
    delete tc_pwr_supply_;
}

void TemperatureManager::operate()
{
    qDebug() << Q_FUNC_INFO;

    // do nothing; timers are doing all the work
    QThread::sleep(1023);
}

void TemperatureManager::controlPanelRequest()
{
    qDebug() << Q_FUNC_INFO;
}

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

    // setup connection to control panel via udp on localhost
    udp_control_panel_ = new QUdpSocket(this);
    udp_control_panel_->bind(CONTROL_PANEL_UDP);
    connect(udp_control_panel_, SIGNAL(readyRead()), this, SLOT(controlPanelRequest()));

    // initialize controllers
    tc_onkyo_ = new JTemperatureController(this, SENSOR_ONKYO, FAN_ONKYO, "Onkyo");
    tc_cabin_ = new JTemperatureController(this, SENSOR_CABIN, FAN_CABIN, "Schaltschrank");
    tc_pwr_supply_ = new JTemperatureController(this, SENSOR_PWR_SUPPLY, FAN_PWR_SUPPLY, "Netzteile");
    tc_pc_ = new JTemperatureController(this, SENSOR_PC, "PC");
}

TemperatureManager::~TemperatureManager()
{
    qDebug() << Q_FUNC_INFO;

    delete tc_cabin_;
    delete tc_onkyo_;
    delete tc_pwr_supply_;
    delete tc_pc_;
    delete udp_control_panel_;
}

void TemperatureManager::saveAllToFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;

    for (JTemperatureController* tc : {tc_onkyo_, tc_cabin_, tc_pwr_supply_, tc_pc_})
        tc->saveConfigToFile(filename);
}

void TemperatureManager::readAllFromFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;

    for (JTemperatureController* tc : {tc_onkyo_, tc_cabin_, tc_pwr_supply_, tc_pc_})
        tc->readConfigFromFile(filename);
}

void TemperatureManager::controlPanelRequest()
{
    qDebug() << Q_FUNC_INFO;

    // read the request to empty out the buffer
    while (udp_control_panel_->hasPendingDatagrams())
    {
        QNetworkDatagram d = udp_control_panel_->receiveDatagram();

        // create answer
        // put all temps and fan speed into one JSON file
        QJsonObject jo;

        for (JTemperatureController* tc : {tc_onkyo_, tc_cabin_, tc_pwr_supply_, tc_pc_})
        {
            QJsonObject tmp;
            tmp.insert("Temperature", tc->getTemperature());
            tmp.insert("TempHigh", tc->getTempHigh());
            tmp.insert("TempCritical", tc->getTempCritical());
            tmp.insert("FanSpeed", tc->getFanSpeed());
            jo.insert(tc->getName(), tmp);
        }

        // send the JSON file
        udp_control_panel_->writeDatagram(QJsonDocument(jo).toJson(), d.senderAddress(), d.senderPort());
        //qDebug() << QJsonDocument(jo);
    }
}

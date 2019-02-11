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

    // create controllers
    tc_onkyo_ = new JTemperatureController(this, SENSOR_ONKYO, FAN_ONKYO, "Onkyo");
    tc_cabin_ = new JTemperatureController(this, SENSOR_CABIN, FAN_CABIN, "Schaltschrank");
    tc_pwr_supply_ = new JTemperatureController(this, SENSOR_PWR_SUPPLY, FAN_PWR_SUPPLY, "Netzteile");
    tc_pc_ = new JTemperatureController(this, SENSOR_PC, -1, "PC");
    tc_pcb_ = new JTemperatureController(this, SENSOR_PCB, -1,  "PCB");
    tc_pi_ = new TemperatureControllerPi(this, "Pi");

    // initialize controllers
    readAllFromFile("/home/pi/conf/temperature_manager.cfg");

    // start controllers
    for (JTemperatureController* tc : {tc_onkyo_, tc_cabin_, tc_pwr_supply_, tc_pc_, tc_pcb_})
        tc->start();
    tc_pi_->start();
}

TemperatureManager::~TemperatureManager()
{
    qDebug() << Q_FUNC_INFO;

    delete tc_cabin_;
    delete tc_onkyo_;
    delete tc_pwr_supply_;
    delete tc_pc_;
    delete tc_pi_;
    delete udp_control_panel_;
}

void TemperatureManager::saveAllToFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;

    for (JTemperatureController* tc : {tc_onkyo_, tc_cabin_, tc_pwr_supply_, tc_pc_, tc_pcb_})
        tc->saveConfigToFile(filename);
    tc_pi_->saveConfigToFile(filename);
}

void TemperatureManager::readAllFromFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;

    for (JTemperatureController* tc : {tc_onkyo_, tc_cabin_, tc_pwr_supply_, tc_pc_, tc_pcb_})
        tc->readConfigFromFile(filename);
    tc_pi_->readConfigFromFile(filename);
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
        for (JTemperatureController* tc : {tc_onkyo_, tc_cabin_, tc_pwr_supply_, tc_pc_, tc_pcb_})
        {
            QJsonObject tmp;
            tmp.insert("Temperature", tc->getTemperature());
            tmp.insert("TempHigh", tc->getTempHigh());
            tmp.insert("TempCritical", tc->getTempCritical());
            tmp.insert("FanSpeed", tc->getFanSpeed());
            jo.insert(tc->getName(), tmp);
        }
        // extrawurst für pi
        QJsonObject tmp;
        tmp.insert("Temperature", tc_pi_->getTemperature());
        tmp.insert("TempHigh", tc_pi_->getTempHigh());
        tmp.insert("TempCritical", tc_pi_->getTempCritical());
        tmp.insert("FanSpeed", tc_pi_->getFanSpeed());
        jo.insert(tc_pi_->getName(), tmp);

        // send the JSON file
        udp_control_panel_->writeDatagram(QJsonDocument(jo).toJson(), d.senderAddress(), d.senderPort());
        //qDebug() << QJsonDocument(jo);
    }
}

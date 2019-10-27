/*!
 * \file temperature_manager.h
 * \brief Source der TemperatureManager Klasse
 */
#include "inc/temperature_manager.h"

TemperatureManager::TemperatureManager(QObject *parent) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;

    conf_file_ = "/home/pi/conf/temperature_manager.cfg";

    // initialize the hardware
    hw::init();

    // Create interface on localhost for other programms to get the data
    udp_control_ = new QUdpSocket(this);
    udp_control_->bind(CONTROL_UDP);
    connect(udp_control_, SIGNAL(readyRead()), this, SLOT(controlRequest()));

    // create controllers
    tc_onkyo_ = new JTemperatureController(this, SENSOR_ONKYO, FAN_ONKYO, "Onkyo");
    tc_cabin_ = new JTemperatureController(this, SENSOR_CABIN, FAN_CABIN, "Schaltschrank");
    tc_pwr_supply_ = new JTemperatureController(this, SENSOR_PWR_SUPPLY, FAN_PWR_SUPPLY, "Netzteile");
    tc_pc_ = new JTemperatureController(this, SENSOR_PC, -1, "PC");
    tc_pcb_ = new JTemperatureController(this, SENSOR_PCB, -1,  "PCB");
    tc_pi_ = new TemperatureControllerPi(this, "Pi");
    tc_test_ = new JTemperatureController(this, SENSOR_TEST, FAN_TEST, "TEST");

    // initialize controllers
    readAllFromFile(conf_file_);

    // start controllers
    //tc_onkyo_->start();
    //tc_cabin_->start();
    //tc_pwr_supply_->start();
    tc_pi_->start();
    //tc_pc_->start();
    //tc_pcb_->start();
    //tc_test_->start();

    // log start
    log(LOGFILE, "[ STATUS ] Temperaturüberwachung gestartet");
}

TemperatureManager::~TemperatureManager()
{
    qDebug() << Q_FUNC_INFO;

    delete tc_cabin_;
    delete tc_onkyo_;
    delete tc_pwr_supply_;
    delete tc_pc_;
    delete tc_pi_;
    delete udp_control_;

    delete tc_test_;

    log(LOGFILE, "[ STATUS ] Temperaturüberwachung geschlossen");
}

void TemperatureManager::saveAllToFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;

    for (JTemperatureController* tc : {tc_onkyo_, tc_cabin_, tc_pwr_supply_, tc_pc_, tc_pcb_, tc_test_})
        tc->saveConfigToFile(filename);
    tc_pi_->saveConfigToFile(filename);
}

void TemperatureManager::readAllFromFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;

    for (JTemperatureController* tc : {tc_onkyo_, tc_cabin_, tc_pwr_supply_, tc_pc_, tc_pcb_, tc_test_})
        tc->readConfigFromFile(filename);
    tc_pi_->readConfigFromFile(filename);
}

void TemperatureManager::controlRequest()
{
    qDebug() << Q_FUNC_INFO;

    // read the request to empty out the buffer
    while (udp_control_->hasPendingDatagrams())
    {
        // QNetworkDatagram d = udp_control_->receiveDatagram();
        QByteArray buffer;
        QHostAddress sender;
        quint16 sender_port;

        buffer.resize(int(udp_control_->pendingDatagramSize()));
        udp_control_->readDatagram(buffer.data(), buffer.size(), &sender, &sender_port);

        // create answer
        // put all temps and fan speed into one JSON file
        QJsonObject jo;
        for (JTemperatureController* tc : {tc_onkyo_, tc_cabin_, tc_pwr_supply_, tc_pc_, tc_pcb_, tc_test_})
        {
            QJsonObject tmp;
            tmp.insert("TempCritical", tc->getTempCritical());
            tmp.insert("TempHigh", tc->getTempHigh());
            tmp.insert("FanSpeed", tc->getFanSpeed());
            tmp.insert("Temperature", floor(tc->getTemperature() * 10 + 0.5)/10);   // <- supid way in C++ to round to 1 decimal place :/
            jo.insert(tc->getName(), tmp);
        }
        // extrawurst für pi
        QJsonObject tmp;
        tmp.insert("TempCritical", tc_pi_->getTempCritical());
        tmp.insert("TempHigh", tc_pi_->getTempHigh());
        tmp.insert("FanSpeed", tc_pi_->getFanSpeed());
        tmp.insert("Temperature", tc_pi_->getTemperature());
        jo.insert(tc_pi_->getName(), tmp);

        // send the JSON file
        udp_control_->writeDatagram(QJsonDocument(jo).toJson(), sender, sender_port);
        //qDebug() << QJsonDocument(jo);
    }
}

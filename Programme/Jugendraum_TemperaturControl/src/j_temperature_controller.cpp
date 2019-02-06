/*!
 * \file j_temperature_controller.cpp
 * \brief Source der JTemperatureController Klasse
 */
#include "inc/j_temperature_controller.h"

JTemperatureController::JTemperatureController(QObject *parent, int sensor_id, int fan_reg, QString device_name) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;

    // move parameters to private variables
    sensor_id_ = sensor_id;
    fan_reg_ = fan_reg;
    device_name_ = device_name;
    has_fan_ = true;

    // get some configuration parameters from a file
    readAllFromFile("file");

    // get the register from the arduino
    sensor_reg_= hw::getSensorRegister(sensor_id_);

    // setup a timer for updating
    update_timer_ = new QTimer(this);
    connect(update_timer_, SIGNAL(timeout()), this, SLOT(update()));
    //update_timer_->start(UPDATE_CYCLE_S);
}

JTemperatureController::JTemperatureController(QObject *parent, int sensor_id, QString device_name) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;

    // move parameters to private variables
    sensor_id_ = sensor_id;
    device_name_ = device_name;
    has_fan_ = false;

    // get some configuration parameters from a file
    readAllFromFile("file");

    // get the register from the arduino
    sensor_reg_= hw::getSensorRegister(sensor_id_);

    // setup a timer for updating
    update_timer_ = new QTimer(this);
    connect(update_timer_, SIGNAL(timeout()), this, SLOT(update()));
    //update_timer_->start(UPDATE_CYCLE_S);
}

JTemperatureController::~JTemperatureController()
{
    qDebug() << Q_FUNC_INFO;

    delete update_timer_;
}

double JTemperatureController::getTemperature()
{
    qDebug() << Q_FUNC_INFO;

    return temperature_;
}

int JTemperatureController::getFanSpeed()
{
    qDebug() << Q_FUNC_INFO;

    return (has_fan_) ? fan_speed_ : -1;
}

QString JTemperatureController::getName()
{
    qDebug() << Q_FUNC_INFO;

    return device_name_;
}

void JTemperatureController::setFanSpeed(int val)
{
    qDebug() << Q_FUNC_INFO;

    if (val != fan_speed_) {
        fan_speed_ = val;
        hw::writePWMValue(fan_reg_, static_cast<uint8_t>(fan_speed_));
    }
}

void JTemperatureController::update()
{
    qDebug() << Q_FUNC_INFO;
    // get the new temperature
    // hw::readUDP will return float, then conversion is not necassary
    float new_temperature = float(hw::readUDP(sensor_reg_, SENSORS_UDP));

    // set a new fan speed if necassary
    if (abs(new_temperature - temperature_) > 0.1)
    {
        temperature_ = new_temperature;
        if (has_fan_) setFanSpeed(calculateFanSpeed(temperature_));
    }
}

int JTemperatureController::calculateFanSpeed(double temperature)
{
    qDebug() << Q_FUNC_INFO;

    // Fan off when temperature lower than temp_threshold,
    // then quaratic ramp-up from fan_min @ temp_threshold to 100 @ temp_high
    int pwm;

    if (temperature < temp_threshold_ - temp_hysteresis_){
        pwm = 0;
    }
    else if ((temperature >= temperature - temp_hysteresis_) && (temperature <= temp_threshold_ + temp_hysteresis_)){
        (fan_speed_ != 0) ? pwm = fan_min_ : pwm = 0;
    }
    else if ((temperature > temp_threshold_ + temp_hysteresis_) && (temperature < temp_high_)){
        pwm = int((100 - fan_min_)/qPow((temp_high_ - temp_threshold_), 2) * qPow((temperature - temp_threshold_), 2) + fan_min_);
    }
    else if (temperature >= temp_high_){
        pwm = 1;
    }

    return int(pwm);
}

void JTemperatureController::writeAllToFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;

    // do stuff using filehandler
}

void JTemperatureController::readAllFromFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;

    // do stuff using filehandler
    temp_high_ = 70;
    temp_crit_ = 90;
    temp_threshold_ = 35;
    temp_hysteresis_ = 5;

    fan_min_ = 30;
}

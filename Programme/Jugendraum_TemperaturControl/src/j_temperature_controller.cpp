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
    readConfigFromFile("/home/pi/conf/temperature_controller.cfg");

    // get the register from the arduino
    sensor_reg_= hw::getSensorRegister(sensor_id_);

    // setup a timer for updating
    update_timer_ = new QTimer(this);
    connect(update_timer_, SIGNAL(timeout()), this, SLOT(update()));
    // update_timer_->start(UPDATE_CYCLE_S);
}

JTemperatureController::JTemperatureController(QObject *parent, int sensor_id, QString device_name) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;

    // move parameters to private variables
    sensor_id_ = sensor_id;
    device_name_ = device_name;
    fan_reg_ = -1;
    has_fan_ = false;

    // get some configuration parameters from a file
    readConfigFromFile("file");

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

void JTemperatureController::saveConfigToFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;

    // QString::append() changes the string it was called on
    // Therefore it needs to be reset after each entry was done
    QString tmp_name = device_name_;

    // store
    FileHandler* fh = new FileHandler(filename);
    fh->writeToFile(tmp_name.append("::temp_high_"), temp_high_); tmp_name = device_name_;
    fh->writeToFile(tmp_name.append("::temp_crit_"), temp_crit_); tmp_name = device_name_;
    fh->writeToFile(tmp_name.append("::temp_threshold_"), temp_threshold_); tmp_name = device_name_;
    fh->writeToFile(tmp_name.append("::temp_hysteresis_"), temp_hysteresis_); tmp_name = device_name_;
    fh->writeToFile(tmp_name.append("::fan_min_"), fan_min_); tmp_name = device_name_;
    delete fh;
}

void JTemperatureController::readConfigFromFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;

    // QString::append() changes the string it was called on
    // Therefore it needs to be reset after each entry was done
    QString tmp_name = device_name_;

    FileHandler* fh = new FileHandler(filename);
    try
    {
        // read
        temp_high_ = fh->readFromFile<double>(tmp_name.append("::temp_high_")); tmp_name = device_name_;
        temp_crit_ = fh->readFromFile<double>(tmp_name.append("::temp_crit_")); tmp_name = device_name_;
        temp_threshold_ = fh->readFromFile<double>(tmp_name.append("::temp_threshold_")); tmp_name = device_name_;
        temp_hysteresis_ = fh->readFromFile<double>(tmp_name.append("::temp_hysteresis_"));  tmp_name = device_name_;
        fan_min_ = fh->readFromFile<int>(tmp_name.append("::fan_min_")); tmp_name = device_name_;
    }
    catch (std::domain_error& e)
    {
        qDebug() << e.what();
        // fallback to defaults
        temp_high_ = TEMP_HIGH;
        temp_crit_ = TEMP_CRIT;
        temp_threshold_ = TEMP_THRESHOLD;
        temp_hysteresis_ = TEMP_HYSTERESIS;
        fan_min_ = FAN_MIN;

        // and store them
        saveConfigToFile(filename);
    }

    delete fh;
}

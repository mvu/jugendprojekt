/*!
 * \file j_temperature_controller.cpp
 * \brief Source der JTemperatureController Klasse
 */
#include "inc/j_temperature_controller.h"

JTemperatureController::JTemperatureController(int sensors_id, int fan_reg, QString device_name_)
{
    qDebug() << Q_FUNC_INFO;

    sensor_id_ = sensor_id;
    fan_reg_ = fan_reg;
    device_name = device_name_;
}

JTemperatureController::~JTemperatureController()
{
    qDebug() << Q_FUNC_INFO;
}

float JTemperatureController::getTemperature()
{
    qDebug() << Q_FUNC_INFO;

    return temperatur_;
}

int JTemperatureController::getFanSpeed()
{
    qDebug() << Q_FUNC_INFO;

    return fan_speed_;
}

float JTemperatureController::readTemperature()
{
    qDebug() << Q_FUNC_INFO;
}

void JTemperatureController::writeFanSpeed(int value)
{
    qDebug() << Q_FUNC_INFO;

    hw::writePWMValue(fan_reg_, value);
}

int JTemperatureController::calculateFanSpeed(float temperatur)
{
    qDebug() << Q_FUNC_INFO;

    // Fan off when temperature lower than temp_threshold,
    // then quaratic ramp-up from fan_min @ temp_threshold to 100 @ temp_high
    int pwm;

    if (temperatur < temp_threshold_ - temp_hysteresis_){
        pwm = 0;
    }
    else if ((temperatur >= temperatur - temp_hysteresis_) && (temperatur <= temp_threshold_ + temp_hysteresis_)){
        (fan_speed_ != 0) ? pwm = fan_min_ : pwm = 0;
    }
    else if ((temperatur > temp_threshold_ + temp_hysteresis_) && (temperatur < temp_high_)){
        pwm = int((100 - fan_min_)/qPow((temp_high_ - temp_threshold_), 2) * qPow((temperatur - temp_threshold_), 2) + fan_min_);
    }
    else if (temperatur >= TempPlat_High){
        pwm = 1;
    }

    return int(pwm);
}

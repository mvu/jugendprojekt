/*!
 * \file temperature_controller_pi.h
 * \brief Header der TemperaturControllerPi Klasse
 */
#ifndef TEMPERATURE_CONTROLLER_PI_H
#define TEMPERATURE_CONTROLLER_PI_H

#include <QProcess>
#include <QString>
#include <QDebug>

#include "inc/j_temperature_controller.h"

/*!
 * \brief Klasse, die die Temperatur des RaspberryPi verwaltet
 * \details unterscheidet sich nur in readTempeartur() von JTemperaturController
 * \todo Lesen der Temperatur aus /sys/class/thermal/thermal_zone0/temp
 */
class TemperatureControllerPi : public JTemperatureController
{
public:
//    TemperatureControllerPi(QObject *parent = nullptr, QString device_name = "null") : JTempertureController() {}
    TemperatureControllerPi(QObject *parent = nullptr, QString device_name = "null");
//    TemperatureControllerPi() : JTempertureController() {}
private:
    double readTemperature() override;
    void init() override;
};

#endif // TEMPERATURE_CONTROLLER_PI_H

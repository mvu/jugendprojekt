/*!
 * \file temperature_controller_pi.cpp
 * \brief Source der TemperaturControllerPi Klasse
 */
#include "inc/temperature_controller_pi.h"

TemperatureControllerPi::TemperatureControllerPi(QObject *parent, QString device_name)
{
    qDebug() << Q_FUNC_INFO;

    // move parameters to private variables
    device_name_ = device_name;
    has_fan_ = false;

    // does all universal set up
    init();
}

double TemperatureControllerPi::readTemperature()
{
    int temp = 0;
    double T;
    QProcess process;
    process.start("vcgencmd measure_temp");
    process.waitForFinished(-1);//wait forever, otherwise time in ms in argument
    QString data = process.readAllStandardOutput();

    //parse data, format: temp=XX.X'C
    for (int i = 0; i < data.length(); i++)
    {
        if (data.at(i) == '=')
        {
            temp += data.at(i+1).digitValue()*100;
            temp += data.at(i+2).digitValue()*10;
            temp += data.at(i+4).digitValue();
            break;
        }
    }
    T = temp/10.;
    return T;
}

void TemperatureControllerPi::init()
{
    qDebug() << Q_FUNC_INFO;

    // setup a timer for updating
    update_timer_ = new QTimer(this);
    connect(update_timer_, SIGNAL(timeout()), this, SLOT(update()));
    update_timer_->setInterval(UPDATE_CYCLE_S * 1000);
}

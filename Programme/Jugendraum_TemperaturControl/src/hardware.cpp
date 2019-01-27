#include "inc/hardware.h"

void hw::init()
{
    qDebug() << Q_FUNC_INFO;

    udp_sensors = new QUdpSocket();
    udp_sensors->bind(QHostAddress(SENSORS_IP), SENSORS_PORT);
}

void hw::writePWMValue(uint8_t, reg, uint8_t value)
{
    qDebug() << Q_FUNC_INFO;
}

int hw::readPWMValue(uint8_t reg)
{
    qDebug() << Q_FUNC_INFO;

    wiringPiReadReg8(pca9635_fd_, reg);
}

float hw::getTemperature(int sensor)
{
    qDebug() << Q_FUNC_INFO;

    return temperatures[sensor];
}

void hw::updateTemperatures()
{
    qDebug() << Q_FUNC_INFO;

    // request all temps from arduino
    udp_sensors->writeDatagram('7', QHostAddress(SENSORS_IP), SENSORS_PORT);

    // wait for data to be received
    if (udp_sensors->waitForReadyRead(10000))
    {
        // store all temperatures in array
        while (udp_sensors_->hasPendingDatagrams())
        {
            buffer.resize(udp_sensors_->pendingDatagramSize());
            udp_sensors_->read(buffer.data(), buffer.size());
            temperatures.append(buffer.toFloat());
        }
    } else {
        // retry
    }
}

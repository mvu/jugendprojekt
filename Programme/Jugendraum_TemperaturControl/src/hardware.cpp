#include "inc/hardware.h"

namespace hw
{
    // something like a hack for privacy in namespaces
    namespace
    {
        int pca9635;

        int wiringPiI2CSetup(uint8_t addr){return 0;}
        int wiringPiI2CReadReg8(int fd, uint8_t reg){return 0;}
        int wiringPiI2CWriteReg8(int fd, uint8_t reg, uint8_t val){return 0;}

        QList<QByteArray> registers;
        QUdpSocket* udp;
    }
}

void hw::init()
{
    qDebug() << Q_FUNC_INFO;

    // setup I2C
    pca9635 = wiringPiI2CSetup(PCA9635_ADDR);
    // configure PCA9635
    //wiringPiI2CWriteReg8(pca9635, PCA9635_MODE1, 0x01);
    //wiringPiI2CWriteReg8(pca9635, PCA9635_MODE2, 0x1D);
    //wiringPiI2CWriteReg8(pca9635, PCA9635_GRPPWM, 0x00);
    // initialize all pwm outputs to 0
    for (uint8_t pwm_reg = 0x02; pwm_reg < 0x12; pwm_reg++)
    {
        // wiringPiI2CWriteReg8(pca9635, pwm_reg, 0);
        qDebug() << "not setting all pwm values to 0!!";
    }


    // get the sensors addresses from arduino
    udp = new QUdpSocket();
    udp->writeDatagram(QByteArray("0"), SENSORS_UDP);
    if (udp->waitForReadyRead(1000))
    {
        // store addresses
        QByteArray buffer;
        buffer.resize(udp->pendingDatagramSize());
        udp->readDatagram(buffer.data(), buffer.size());
        for (int i = 0; i < 6; i++) { registers.append(buffer.mid(2*i, 2)); }
    } else {
        qDebug() << "Failed to load Arduino's registers!";
        for (int i = 0; i < 6; i++) { registers.append(nullptr); }
    }
}

void hw::writePWMValue(uint8_t reg, double value)
{
    qDebug() << Q_FUNC_INFO;

    wiringPiI2CWriteReg8(pca9635, reg, (uint8_t(value * 2.55)));
}

double hw::readPWMValue(uint8_t reg)
{
    qDebug() << Q_FUNC_INFO;

    return wiringPiI2CReadReg8(pca9635, reg)/2.55;
}

QByteArray hw::getSensorRegister(int sensor)
{
    qDebug() << Q_FUNC_INFO << "with sensor = " << sensor;

    return registers.at(sensor);
}

void hw::writeUDP(QByteArray data, QHostAddress ip, quint16 port)
{
    qDebug() << Q_FUNC_INFO;

    udp->writeDatagram(data, ip, port);
    if (udp->waitForReadyRead(1000))
    {
        int aw = udp->receiveDatagram().data().toInt();
        if (aw != 0)
        {
            // do something because the write has failed!
            qDebug() << "Client returned " << aw;
        }
    }
}

double hw::readTemperatureUDP(QByteArray ptr)
{
    qDebug() << Q_FUNC_INFO;

    udp->writeDatagram(ptr, SENSORS_UDP);

    float temperature = 1e5;
    if (udp->waitForReadyRead(1000))
    {
        QByteArray buffer;
        buffer.resize(int(udp->pendingDatagramSize()));
        udp->readDatagram(buffer.data(), buffer.size());

        // convert buffer to float
        qint32 temp = (uint8_t(buffer[3]) << 24) | (uint8_t(buffer[2]) << 16) | (uint8_t(buffer[1]) << 8) | uint8_t(buffer[0]);
        float* out = reinterpret_cast<float*>(&temp);
        temperature = *out;
    } else {
        qDebug() << "Failed to read temperatur!";
    }
    return double(temperature);
}

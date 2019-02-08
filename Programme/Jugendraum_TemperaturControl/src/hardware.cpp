#include "inc/hardware.h"

namespace hw
{
    // something like a hack for privacy in namespaces
    namespace
    {
        int pca9635;
        int WiringPiI2CSetup(uint8_t addr){return 0;}
        int WiringPiI2CReadReg8(int fd, uint8_t reg){return 0;}
        int WiringPiI2CWriteReg8(int fd, uint8_t reg, uint8_t val){return 0;}
        QList<QByteArray> registers;
        QUdpSocket* udp;
    }
}

void hw::init()
{
    qDebug() << Q_FUNC_INFO;

    // setup I2C
    pca9635 = WiringPiI2CSetup(PCA9635_ADDR);

    // create a udp socket to communicate with the arduino
    udp = new QUdpSocket();
    // and get the addresses
    udp->writeDatagram(QByteArray("x"), SENSORS_UDP);
    if (udp->waitForReadyRead(1000))
    {
        // store addresses
        QByteArray raw = udp->receiveDatagram().data();
        for (int i = 0; i < 6; i++) { registers.append(raw.mid(2*i, 2)); }
    } else {
        qDebug() << "Failed to load Arduino's registers!";
        for (int i = 0; i < 6; i++) { registers.append(nullptr); }
    }
}

void hw::writePWMValue(uint8_t reg, uint8_t value)
{
    qDebug() << Q_FUNC_INFO;

    WiringPiI2CWriteReg8(pca9635, reg, value);
}

int hw::readPWMValue(uint8_t reg)
{
    qDebug() << Q_FUNC_INFO;

    WiringPiI2CReadReg8(pca9635, reg);
}

QByteArray hw::getSensorRegister(int sensor)
{
    qDebug() << Q_FUNC_INFO << "with sensor = " << sensor;

    return registers.at(sensor - 1);
}

int hw::readUDP(QByteArray reg, QHostAddress ip, quint16 port)
{
    qDebug() << Q_FUNC_INFO;

    // qDebug() << "want " << reg << "from " << ip << ":" << port;
    udp->writeDatagram(reg, ip, port);

    int tmp = -1;
    if (udp->waitForReadyRead(1000))
    {
        QNetworkDatagram d = udp->receiveDatagram();
        // qDebug() << "sender = " << d.senderAddress() << ":" << d.senderPort() << ", data: " << d.data();
        QByteArray raw = d.data();
        if (raw.length() == 2)
        {
            tmp = (uint8_t(raw.at(0)) << 8) + uint8_t(raw.at(1));
        }
        else
        {
            qDebug() << "data not as exspected, got " << d.data();
        }
    } else {
        qDebug() << "Failed to read Arduino's registers!";
    }

    return tmp;
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

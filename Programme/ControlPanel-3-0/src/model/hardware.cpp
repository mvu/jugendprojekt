#include "inc/model/hardware.h"

namespace hw 
{
    // something like a hack for privacy in namespaces
    namespace 
    {
        // file descriptor
        int mcp23017;
        int pca9635;
        // WiringPi dummy functions
        int WiringPiI2CSetup(uint8_t addr){return 0;}
        int WiringPiI2CReadReg8(int fd, uint8_t reg){return 0;}
        int WiringPiI2CWriteReg8(int fd, uint8_t reg, uint8_t val){return 0;}
        // store slider registers
        QList<QByteArray> slider_setpoints, slider_analogs, slider_actives;
        // udp
        QUdpSocket* udp = new QUdpSocket();
    }
}

void hw::init()
{
    qDebug() << Q_FUNC_INFO;

    // Setup I2C
    // first the portexpander
    mcp23017 = WiringPiI2CSetup(PORTEXPANDER);
    // then the PCA
    pca9635 = WiringPiI2CSetup(PCA_LICHT);

    // now create a udp socket to communicate with te sliders
    // udp = new QUdpSocket();
    // and get the addresses
    udp->writeDatagram(QByteArray("x"), SLIDER_UDP);
    if (udp->waitForReadyRead(1000))
    {
        // store addresses
        QByteArray raw = udp->receiveDatagram().data();
        qDebug() << "raw: " << raw;
        for (int i = 0; i <  4; i++) { slider_setpoints.append(raw.mid(2*i, 2)); }
        for (int i = 4; i <  8; i++) { slider_analogs.append(raw.mid(2*i, 2)); }
        for (int i = 8; i < 12; i++) { slider_actives.append(raw.mid(2*i, 2)); }
        qDebug() << "setpoints: " << slider_setpoints;
        qDebug() << "analogs:   " << slider_analogs;
        qDebug() << "actives:   " << slider_actives;
    } else {
        qDebug() << "Failed to load Arduino's registers!";
    }

    udp->writeDatagram(slider_analogs.at(1), SLIDER_UDP);
    if (udp->waitForReadyRead(1000))
    {
        QNetworkDatagram d = udp->receiveDatagram(512);
        qDebug() << "sender = " << d.senderAddress() << ":" << d.senderPort() << ", data: " << d.data();
    }

    readUDP(slider_analogs.at(1), SLIDER_UDP);
}

bool hw::readState(uint8_t bank, uint8_t bit)
{
    qDebug() << Q_FUNC_INFO;
    
    return bit & WiringPiI2CReadReg8(mcp23017, bank);
}

void hw::writeState(uint8_t bank, uint8_t bit, bool state)
{
    qDebug() << Q_FUNC_INFO;
    
    uint8_t val_old = WiringPiI2CReadReg8(mcp23017, bank);
    uint8_t val_new = (val_old & ~bit) | (state << bit);
    int ret = WiringPiI2CWriteReg8(mcp23017, bank, val_new);
} 

int hw::readValue(uint8_t reg)
{
    qDebug() << Q_FUNC_INFO;

    return WiringPiI2CReadReg8(pca9635, reg);
}

void hw::writeValue(uint8_t reg, int val)
{ 
    qDebug() << Q_FUNC_INFO;

    WiringPiI2CWriteReg8(pca9635, reg, val);
}

QList<QByteArray> hw::getSliderConfig(int slider_num)
{
    qDebug() << Q_FUNC_INFO;

    QList<QByteArray> tmp;
    tmp.append(slider_setpoints.at(slider_num - 1));
    tmp.append(slider_analogs.at(slider_num - 1));
    tmp.append(slider_actives.at(slider_num - 1));
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

int hw::readUDP(QByteArray reg, QHostAddress ip, quint16 port)
{
    qDebug() << Q_FUNC_INFO;

    // qDebug() << "want " << reg << "from " << ip << ":" << port;
    udp->writeDatagram(reg, ip, port);

    int tmp = -1;
    if (udp->waitForReadyRead(1000))
    {
        QNetworkDatagram d = udp->receiveDatagram(512);
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
        qDebug() << "Failed to load Arduino's registers!";
    }
    return tmp;
}

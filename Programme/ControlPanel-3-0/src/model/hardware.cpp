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
        QList<QByteArray> setpoints, analogs;
        // udp
        QUdpSocket* udp;
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
    udp = new QUdpSocket();
    // and get the addresses
    udp->writeDatagram(QByteArray("x"), QHostAddress(SLIDER_IP), SLIDER_PORT);
    if (udp->waitForReadyRead(1000))
    {
        // store addresses
        QByteArray raw = udp->receiveDatagram().data();
        qDebug() << "raw: " << raw;
        for (int i = 0; i < 4; i++) { setpoints.append(raw.mid(2*i, 2)); }
        for (int i = 4; i < 8; i++) { analogs.append(raw.mid(2*i, 2)); }
        qDebug() << "setpoints: " << setpoints;
        qDebug() << "analogs:   " << analogs;
    } else {
        qDebug() << "Failed to load Arduino's registers!";
    }
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

void hw::setSliderPosition(int slider_num, int val)
{
    qDebug() << Q_FUNC_INFO;

    // calculate actual setpoint for slider
    // whose ADC range is 10 bit with the maximum beeing at the bottom
    uint16_t hw_pos = (100 - val) * 1023/ 100;

    // prepare the datagram
    QByteArray datagram = setpoints.at(slider_num - 1); // address
    datagram.append(static_cast<uint8_t>(hw_pos >> 8)); // high byte of val
    datagram.append(static_cast<uint8_t>(hw_pos));      // low byte of val

    // send the datagram
    udp->writeDatagram(datagram, QHostAddress(SLIDER_IP), SLIDER_PORT);
}

int hw::getSliderPosition(int slider_num)
{
    qDebug() << Q_FUNC_INFO;

    // send request
    udp->writeDatagram(analogs.at(slider_num - 1), QHostAddress(SLIDER_IP), SLIDER_PORT);

    int tmp;
    // get the answer
    if (udp->waitForReadyRead(1000))
    {
        QByteArray raw = udp->receiveDatagram().data();
        qDebug() << "raw: " << raw;
        tmp = raw.toInt();
    } else {
        tmp = -1;
        qDebug() << "Failed to load Arduino's registers!";
    }
    qDebug() << tmp;
    return 0;
}

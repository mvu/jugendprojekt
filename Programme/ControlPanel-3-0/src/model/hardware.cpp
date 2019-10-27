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
        QUdpSocket* udp_slider_ = new QUdpSocket();
        QUdpSocket* udp_temperatur_ = new QUdpSocket();

        /*!
         * \brief sliderless_ used temporarily to disable slider features if they are not hooked up
         * ny slider-related function will return 0
         */
        bool sliderless_ = false;
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

    // bind udp_slider_ to the adress of the arduino
    udp_slider_->bind(SLIDER_UDP);
    // and get the addresses
    udp_slider_->writeDatagram(QByteArray("x"), SLIDER_UDP);
    if (udp_slider_->waitForReadyRead(1000))
    {
        QByteArray raw = udp_slider_->receiveDatagram().data();
        qDebug() << "raw: " << raw;
        for (int i = 0; i <  4; i++) { slider_setpoints.append(raw.mid(2*i, 2)); }
        for (int i = 4; i <  8; i++) { slider_analogs.append(raw.mid(2*i, 2)); }
        for (int i = 8; i < 12; i++) { slider_actives.append(raw.mid(2*i, 2)); }
        qDebug() << "setpoints: " << slider_setpoints;
        qDebug() << "analogs:   " << slider_analogs;
        qDebug() << "actives:   " << slider_actives;
    } else {
        qDebug() << "Failed to load Arduino's registers!";
        log(ERROR_LOG, "[ UDP ] timeout (1000 ms) reached when loading slider registers");
        for (int i = 0; i <  4; i++) { slider_setpoints.append(nullptr); }
        for (int i = 4; i <  8; i++) { slider_analogs.append(nullptr); }
        for (int i = 8; i < 12; i++) { slider_actives.append(nullptr); }

        sliderless_ = true;
    }

    // bind udp port for temperatur service to a port
    udp_temperatur_->bind(QHostAddress::LocalHost, TEMPERATUR_SERVICE_PORT);
    readUDP(QHostAddress::LocalHost, TEMPERATUR_SERVICE_PORT);
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

    /*
     * use the right socket for the transaction
     * this is done to ensure that the data received was emitted by the recipient
     * of the datagram
     */
    QUdpSocket* udp;
    if ((ip == QHostAddress(SLIDER_IP)) && (port == SLIDER_PORT)) udp = udp_slider_;
    else if ((ip == QHostAddress::LocalHost) && (port == TEMPERATUR_SERVICE_PORT)) udp = udp_temperatur_;
    else udp = new QUdpSocket();

    // transaction
    udp->writeDatagram(data, ip, port);
    if (udp->waitForReadyRead(1000))
    {
        int aw = udp->receiveDatagram().data().toInt();
        if (aw != 0)
        {
            // do something because the write has failed!
            qDebug() << "Client returned " << aw;
            log(ERROR_LOG, QString("[ UDP ] write to %1:%2 failed : client returned %3").arg(ip.toString()).arg(port).arg(aw));
        }
    }
    else
    {
        qDebug() << "Client timeout on write";
        log(ERROR_LOG, QString("[ UDP ] client %1:%2 timeout (1000 ms)").arg(ip.toString()).arg(port));
    }
}

int hw::readUDP(QByteArray reg, QHostAddress ip, quint16 port)
{
    qDebug() << Q_FUNC_INFO;
    // qDebug() << "want " << reg << "from " << ip << ":" << port;

    /*
     * use the right socket for the transaction
     * this is done to ensure that the data received was emitted by the recipient
     * of the datagram
     */
    QUdpSocket* udp;
    if ((ip == QHostAddress(SLIDER_IP)) && (port == SLIDER_PORT)) udp = udp_slider_;
    else if ((ip == QHostAddress::LocalHost) && (port == TEMPERATUR_SERVICE_PORT)) udp = udp_temperatur_;
    else udp = new QUdpSocket();

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
            qDebug() << "data not as exspected, got " << raw;
            log(ERROR_LOG, QString("[ UDP ] corrupted data from %1:%2 : expected 2 bytes, got %3").arg(ip.toString(), port, raw.length()));
        }
    }
    else
    {
        qDebug() << "Failed to load Arduino's registers!";
        log(ERROR_LOG, QString("[ UDP ] client %1:%2 timeout (1000 ms)").arg(ip.toString(), port));
    }
    return tmp;
}

QJsonDocument hw::readUDP(QHostAddress ip, quint16 port)
{
    qDebug() << Q_FUNC_INFO;

    QUdpSocket* udp;
    if ((ip == QHostAddress::LocalHost) && (port == TEMPERATUR_SERVICE_PORT)) udp = udp_temperatur_;
    else udp = new QUdpSocket();

    // send anything to trigger transaction
    udp->writeDatagram(QByteArray("x"), ip, port);

    // read the answer
    QJsonDocument jo;
    if (udp->waitForReadyRead(1000))
    {
        QNetworkDatagram d = udp->receiveDatagram();
        jo = QJsonDocument::fromJson(d.data());
        if (jo.isNull())
        {
            log(ERROR_LOG, QString("[ UDP ] failed to convert data from %1:%2 to json").arg(ip.toString()).arg(port));
        }
    }
    else
    {
        qDebug() << "Failed to read temperatures!";
        log(ERROR_LOG, QString("[ UDP ] client %1:%2 timeout (1000 ms)").arg(ip.toString()).arg(port));
    }
    return jo;
}

bool hw::sliderless()
{
    qDebug() << Q_FUNC_INFO;

    return sliderless_;
}

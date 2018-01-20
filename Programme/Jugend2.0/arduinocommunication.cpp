#include "arduinocommunication.h"

ArduinoCommunication::ArduinoCommunication()
{
    udpSocket = new QUdpSocket();
    //udpSocket->bind(65100);
    //connect(udpSocket, SIGNAL(readyRead()), this, SLOT(DataAvailable()));
}

float ArduinoCommunication::readSensor(int sensor)
{
    //send(QString("%1").arg(sensor));
    //while (!udpSocket->waitForReadyRead(100)){}
    float data = read();
    QThread::msleep(10);
    return data;
}

bool ArduinoCommunication::connectUDP(QString IP, quint16 PORT)
{
    ip = IP;
    port = PORT;
    udpSocket->connectToHost(QHostAddress(IP),PORT,QIODevice::ReadWrite);
    if (udpSocket->isOpen())return true;
    
}

void ArduinoCommunication::DataAvailable()
{
    data_avilable = true;
    //qDebug() << "Data available!";
}

void ArduinoCommunication::requestAll()
{
            //qDebug() << word;
            QString word = "7";
            QByteArray buffer = word.toUtf8();
            //QHostAddress sender ;
            udpSocket->write(buffer.data());
}

float ArduinoCommunication::read()
{
    QByteArray buffer;
    buffer.resize(udpSocket->pendingDatagramSize());
    udpSocket->read(buffer.data(), buffer.size());
    float data = buffer.toFloat();
    return data;
}

void ArduinoCommunication::closeUDP()
{
    udpSocket->close();
}

QList<float > ArduinoCommunication::allSensors()
{
    //std::cout << "ArduinoUDP: allSensors()\n";

    QList<float > temp;
    temp.clear();
    if(udpSocket->isOpen()){
        //qint64 time_start = QDateTime::currentMSecsSinceEpoch();
        requestAll();
        //qint64 time_1 = QDateTime::currentMSecsSinceEpoch();
        //std::cout << "Zeit 1: "<< time_1 - time_start << "\n";
//        while (!udpSocket->waitForReadyRead(10)){
//            std::cout << "waitForReadyRead\n";
//            QThread::msleep(100);
//        }
        QThread::msleep(200);

        //qint64 time_2 = QDateTime::currentMSecsSinceEpoch();
        //std::cout << "Zeit 2: " << time_2 - time_1 << "\n";
        //std::cout << "udpSocket->pendingDatagramSize: " << udpSocket->pendingDatagramSize() << "\n";
        while (udpSocket->hasPendingDatagrams())
        {
            //std::cout << "ReadData\n";
            temp.append(read());
            //std::cout << "reading sensor\n";
        }
        //qint64 time_3 = QDateTime::currentMSecsSinceEpoch();
       // std::cout << "Zeit 3: " << time_3 - time_2 << "\n";
        //qDebug() << temp;
        return temp;
        //udpSocket->disconnectFromHost();
    }
//    QList<float> temp;
//    for (int i = 0; i < 6; i++){
//        temp.append(0.0);
//    }
//    return temp;
}

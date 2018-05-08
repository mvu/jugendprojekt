#include "Steuer_arduinocommunication.h"

ArduinoCommunication::ArduinoCommunication()
{
    udpSocketSlider = new QUdpSocket();
    udpSocketTemp   = new QUdpSocket();

    if(!NotaPi) udpSocketSlider->connectToHost(QHostAddress(IP_Slider),PORT_Slider,QIODevice::ReadWrite);
    if(!NotaPi) udpSocketTemp->connectToHost(QHostAddress(IP_Temp),PORT_Temp,QIODevice::ReadWrite);
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

bool ArduinoCommunication::connectUDP(bool udp, QString IP, quint16 PORT)
{
    ip = IP;
    port = PORT;
    if(udp){
        udpSocketSlider->connectToHost(QHostAddress(IP),PORT,QIODevice::ReadWrite);
        if (udpSocketSlider->isOpen())return true;
    }
    else{
        udpSocketTemp->connectToHost(QHostAddress(IP),PORT,QIODevice::ReadWrite);
        if (udpSocketTemp->isOpen())return true;
    }
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
            udpSocketTemp->write(buffer.data());
}

float ArduinoCommunication::read()
{
    QByteArray buffer;
    buffer.resize(udpSocketTemp->pendingDatagramSize());
    udpSocketTemp->read(buffer.data(), buffer.size());
    float data = buffer.toFloat();
    return data;
}

void ArduinoCommunication::closeUDPTemp()
{
    udpSocketTemp->close();
}

void ArduinoCommunication::closeUDPSlider()
{
    udpSocketSlider->close();
}

QList<float > ArduinoCommunication::allSensors()
{
    //std::cout << "ArduinoUDP: allSensors()\n";

    QList<float > temp;
    temp.clear();
    if(udpSocketTemp->isOpen()){
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
        while (udpSocketTemp->hasPendingDatagrams())
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

bool ArduinoCommunication::statusSlider(){
    if(udpSocketSlider->isOpen()) return true;
    else return false;
}

bool ArduinoCommunication::statusTemp(){
    if(udpSocketTemp->isOpen())return true;
    else return false;
}

void ArduinoCommunication::setSlider(char sliderNum, int value)
{
    if(udpSocketSlider->isOpen()){
        word.append(sliderNum);
        word.append(QString::number(value));
        QByteArray send = word.toUtf8();
        udpSocketSlider->write(send.data());
    }
}

int ArduinoCommunication::readSlider(char sliderNum)
{
    if(udpSocketSlider->isOpen()){
        word.append(sliderNum);
        word.append(QString::number(0));
        QByteArray send = word.toUtf8();
        udpSocketSlider->write(send.data());
    }
    while (!udpSocketSlider->waitForReadyRead(200)) { // warten auf antwort solange warten in msec
    }
    buffer.resize(udpSocketSlider->pendingDatagramSize());
    //udpSocketSlider->read(buffer.data(),buffer.size());
    return  1024 - buffer.toInt();
}

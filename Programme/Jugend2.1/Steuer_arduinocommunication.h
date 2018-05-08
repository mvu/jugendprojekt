#ifndef ARDUINOCOMMUNICATION_H
#define ARDUINOCOMMUNICATION_H

#include <QtCore>
#include <QString>
#include <QtNetwork>
#include <QIODevice>
#include <QObject>
#include <iostream>
#include <QTime>
#include "thread_ueberwachung.h"


using namespace std;

class ArduinoCommunication : public QObject
{
    Q_OBJECT

public:
    ArduinoCommunication();
    QString ip;
    quint16 port;
    float readSensor(int sensor);
    bool connectUDP(bool udp ,QString IP, quint16 PORT);
    void closeUDPTemp();
    void closeUDPSlider();
    QList<float > allSensors();
    bool statusSlider();
    bool statusTemp();
    int readSlider(char sliderNum);
    void setSlider(char sliderNum, int value);

private:
    QUdpSocket *udpSocketSlider;
    QUdpSocket *udpSocketTemp;

    bool data_avilable = false;
    QString buffer;
    QString word;

public slots:



private slots:
    void DataAvailable();
    float read();
    void requestAll();
};

#endif // ARDUINOCOMMUNICATION_H

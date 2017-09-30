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

private:
    QUdpSocket *udpSocket;
    bool data_avilable = false;

public slots:
    float readSensor(int sensor);
    bool connectUDP(QString IP, quint16 PORT);
    void closeUDP();
    QList<float > allSensors();

private slots:
    void DataAvailable();
    float read();
    void requestAll();
};

#endif // ARDUINOCOMMUNICATION_H

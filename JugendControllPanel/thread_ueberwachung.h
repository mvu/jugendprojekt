#ifndef THREAD_UEBERWACHUNG_H
#define THREAD_UEBERWACHUNG_H

#define TempSensorDecke "/sys/bus/w1/devices/28-0000074aa720/w1_slave"
#define TempSensorHauptlicht2 "/sys/bus/w1/devices/28-0000074a81fb/w1_slave"
#define TempSensorHauptlicht1 "/sys/bus/w1/devices/28-0000074b3149/w1_slave"
#define TempSensorNetzteile "/sys/bus/w1/devices/28-0000074b3149/w1_slave"

#include "mainconfig.h"

using namespace std;

class steuerungThreadLicht;

class thread_Ueberwachung : public QThread
{
    Q_OBJECT

public:
    explicit thread_Ueberwachung(QObject *parent = 0, steuerungThreadLicht *s = NULL);
    void run();

private:
    float Temperaturen[4];
        //0: Platine, beide werte gemittelt
        //1: Netzteile
        //2: Raum
        //4: Pi
    QList <char *> ArrayOfSensors;
    QTimer *timer;

protected:
    void timerEvent();

signals:
    void TempPiChanged(float);
    void TempNetzteileChanged(float);
    void TempSteuerplatineChanged(float);
    void TempDeckeChanged(float);
    void WandschalterPressed(bool);

public slots:
    void setLuefter(int number, int val);    //to set fan-value
    float requestTemp(int Sensor);  //returns Temperaturen[Sensor]

private slots:
    float getTemp(int Sensor);
    float getTemp_pi();
    bool checkWandschalter();
    void checkTemp();

};

#endif // THREAD_UEBERWACHUNG_H

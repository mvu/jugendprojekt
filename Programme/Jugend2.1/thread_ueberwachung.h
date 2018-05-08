#ifndef THREAD_UEBERWACHUNG_H
#define THREAD_UEBERWACHUNG_H

#define TempSensorDecke "/sys/bus/w1/devices/28-0000074aa720/w1_slave"
#define TempSensorHauptlicht2 "/sys/bus/w1/devices/28-0000074a81fb/w1_slave"
#define TempSensorHauptlicht1 "/sys/bus/w1/devices/28-0000074b3149/w1_slave"
#define TempSensorNetzteile "/sys/bus/w1/devices/28-0000074b3149/w1_slave"

#define ArduinoPort 8888
#define ArduinoIp   "192.168.188.250"

#include "mainconfig.h"
#include "Steuer_arduinocommunication.h"

using namespace std;

class steuerungThreadLicht;
class ModelThreadLicht;
class ArduinoCommunication;

class thread_Ueberwachung : public QThread
{
    Q_OBJECT

public:
    explicit thread_Ueberwachung(QObject *parent = 0, steuerungThreadLicht *s = NULL, ModelThreadLicht *m =NULL);
    void run();

private:
    float Temperaturen[6];
        //0: Platine, beide werte gemittelt
        //1: Netzteile
        //2: Raum
        //3: Pi
        //4: ONKYO
        //5: PC
    float TemperaturenArduino[6];
        //0: Netzteile
        //1: Platine
        //2: Platine
        //3: PC
        //4: Raum
        //5: ONKYO
    QList <const float> TempSave;
    QList <char *> ArrayOfSensors;
    QTimer *timer;
    ArduinoCommunication *ArduinoUDP;
    steuerungThreadLicht *sThread;
    ModelThreadLicht * mThread;

    float minTemp = 10.;
    float maxTemp = 100.;

protected:
    void timerEvent();

signals:
    void TempPiChanged(float);
    void TempNetzteileChanged(float, int);
    void TempSteuerplatineChanged(float, int);
    void TempDeckeChanged(float, int);
    void TempVerstaerkerChanged(float, int);
    void TempPCChanged(float);
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

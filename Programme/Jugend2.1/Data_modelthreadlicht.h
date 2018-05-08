#ifndef MODELTHREADLICHT_H
#define MODELTHREADLICHT_H

#include <QObject>
#include <QThread>
#include <QtCore>
#include "mainconfig.h"

class steuerungThreadLicht;

class ModelThreadLicht : public QThread
{
    Q_OBJECT

public:
    explicit ModelThreadLicht(QObject *parent = 0, steuerungThreadLicht * s = NULL);
    void run();


    float arrayTemp[5] = {0.00, 0.00, 0.00, 0.00, 0.00};
    bool arrayRelais[9];
    int arrayPWMHL[8] = {0, 0, 0, 0, 0, 0, 0, 0,};
    bool arryStatus[8];
    int t_main = 1000, t_Slider = 10000;
    bool SliderOn;

private:
    QTimer *timer_mainInfo;
    QTimer *timer_SLiderCheck;
    steuerungThreadLicht *sThread;

    float minTemp = 10.;
    float maxTemp = 100.;
    float arrayTempOld[5] = {0.00, 0.00, 0.00, 0.00, 0.00};

    void setHL();
    void setStatusRelais();

public slots:
    void mainInfoCheck();
    void getHauptlichtslot(int val, int LED);
    void getStatusRelaisslot(bool);

    // alle mit in sind die feedback eingänge für die anfrage mit get

    void updateFinish();


signals:
//    void getHauptlicht(int val);                // Aktuellen PWM wertes des Hauptlichtes

    void update();
};

#endif // MODELTHREADLICHT_H

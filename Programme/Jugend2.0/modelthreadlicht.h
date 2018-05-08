#ifndef MODELTHREADLICHT_H
#define MODELTHREADLICHT_H

#include <QObject>
#include <QThread>
#include <QtCore>
#include "mainconfig.h"

class ModelThreadLicht : public QThread
{
    Q_OBJECT

public:
    explicit ModelThreadLicht(QObject *parent = 0);
    void run();
    float TempPC,TempNetzteil,TempOnkyo,TempPi,TempDecke;
    int PwmHL_1,PwmHL_2,PwmHL_3,PwmHL_4,PwmHL_5,PwmHL_6,PwmHL_7,PwmHL_8,
        Hl_Relais,PC_Relais,Netzteil48V_Relais,Netzteil12V_Relais,Status_Relais,Theke_Relais;

private:
    QTimer *timer_mainInfo;
    QTimer *timer_SLiderCheck;

public slots:
    void mainInfoCheck();
signals:


};

#endif // MODELTHREADLICHT_H

#ifndef GPIOCONTROLL_H
#define GPIOCONTROLL_H
#include <QtCore>
#include <QDebug>
#include <wiringPi.h>
#include <wiringPiI2C.h>

class gpiocontroll
{

private:
    QMutex mutex;
public:
    gpiocontroll();
    //void setup();
    //void WriteA(int val, int set);
    //void WriteB(int val);
    //void off();

    //int readA();
};

#endif // GPIOCONTROLL_H


#define PortA 0x14
#define PortB 0x15
#define Power48V 0x80
#define Theke 0x02
#define Palette 0x04
#define DirektenA 0x00
#define DirektinB 0x01

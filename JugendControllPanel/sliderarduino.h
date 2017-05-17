#ifndef SLIDERARDUINO_H
#define SLIDERARDUINO_H

#include "mainconfig.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>

#include <QObject>

class SliderArduino : public QObject
{
    Q_OBJECT
public:
    explicit SliderArduino(QObject *parent = 0);

signals:

public slots:

    void set(int slider , int value);
    int get(int slider);
private:
    int slider1;


};

#endif // SLIDERARDUINO_H

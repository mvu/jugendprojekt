#ifndef SLIDERARDUINO_H
#define SLIDERARDUINO_H

#include "mainconfig.h"
#include <QtNetwork>
#include <QTimer>


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
    QUdpSocket *udp;
    QTimer *timer;
    QByteArray buffer;
    int valSlider[4], Sliderwechsel = 0;
    char Slider[6] {'0','A','B','C','D'};
private slots:
    void read();
    void timerEnd();

};

#endif // SLIDERARDUINO_H

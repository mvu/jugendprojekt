#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include "mainconfig.h"
#include "pca_9635.h"
#include "gpiocontroll.h"

class mainThread : public QObject
{
    Q_OBJECT
private:
    int fd ;     //Bus Addresse von PCA HL
    int fa ;    // Bus Address von PCA RGB
    int hlPower ;    // Summe des Hauptlicht Leistung
    int hlvalue ;    // zwischen Speicher des ausgelesen wertes
    float last;          // die last ist in Prozent
    int arrayHL[];


    pca_9635 *pcaHL;
    pca_9635 *pcaRGB;
    gpiocontroll *gpio;
    QThread *thread;
    void lueftercontroll();
    void rgbTest();


public:
    explicit mainThread(QObject *parent = 0);
    void init(QThread &cThread);
    bool Stop;

signals:

public slots:
    void mainLoop();
};

#endif // MAINTHREAD_H

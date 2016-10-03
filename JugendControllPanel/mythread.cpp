#include "mythread.h"
#include <QtCore>
#include "pca9635.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>




MyThread::MyThread(QObject *parent) :
    QThread(parent)
{

}


void MyThread::run()
{
    int i = 0;
    //int ledAddresse = 0x5f;
    int arduinoAddresse = 0x0e;
    //int ledRegister = 9;
    int sliderValue = 0;
    //int pcaInit = wiringPiI2CSetup(ledAddresse);
    int arduinoInit = wiringPiI2CSetup(arduinoAddresse);
    emit Verbunden(arduinoInit);

    if (arduinoInit < 0);
    else{
        while(1)
        {

            float sliderValuefloat = wiringPiI2CReadReg8(arduinoInit, 9);
            sliderValuefloat = sliderValue / 100.0;
            sliderValue = 255 - (255.0 * sliderValuefloat);
            if (sliderValue == 252)sliderValue = 255;
            //PCA9635PWMWrite(pcaInit, ledRegister, sliderValue);
            emit ValChanged(sliderValuefloat);
            i++;
            emit Threadrun(i);
            QThread::msleep(10);
            //QMutex mutex;
            //mutex.lock();
            if(this->stop)break;
            //mutex.unlock();

        }
    }
}

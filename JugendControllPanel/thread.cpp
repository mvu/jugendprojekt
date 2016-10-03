#include <QtCore>
#include <QDebug>
#include "thread.h"
#include "pca9635.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>




int ledAddresse = 0x5f;
int arduinoAddresse = 0x0e;
int ledRegister = 9;
int sliderValue = 0;

Thread::Thread(QObject *parent) :
    QObject(parent)
{

}


void Thread::threadInit(QThread &cThread)
{
    connect(&cThread,SIGNAL(started()),this,SLOT(threadEinstellungHauptlicht()));

}


void Thread::threadEinstellungHauptlicht()
{
        int pcaInit = 0;//pca9635Setup(ledAddresse);
        int arduinoInit = wiringPiI2CSetup(arduinoAddresse);
    //if (arduinoInit < 0) ;
    if (pcaInit < 0);
    else{
        while(1)
        {
	    
            float sliderValuefloat = wiringPiI2CReadReg8(arduinoInit, 9);
            sliderValuefloat = sliderValue / 100.0;
            sliderValue = 255 - (255.0 * sliderValuefloat);
            if (sliderValue == 252)sliderValue = 255;
            //PCA9635PWMWrite(pcaInit, ledRegister, sliderValue);
            emit ValSlider(sliderValue);

            QThread::msleep(100);

            QMutex mutex;
            mutex.lock();
            if(this->Stop)break;
            mutex.unlock();

        }
    }
}

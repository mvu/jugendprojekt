#include "mythread.h"
#include <QtCore>
#include "pca9635.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "MainVisu_einstellunghauptlicht.h"
#include "mainconfig.h"

bool arryHauptlicht[8];

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
    connect(parent, SIGNAL(CheckBoxChanged(int,bool)), this,SLOT(checkBoxChanged(int,bool)));
}

void MyThread::run()
{
    for(int i=0; i<8; i++)
        arryHauptlicht[i] = false;

    int sliderOld = pca->pca9635PWMRead(pcaHL,0x03);
    slider->set(SLIDERSETONE,sliderOld / 2.55);
    emit SliderChanged(sliderOld);

    int sliderVal = slider->get(SLIDERGETONE);
    int sliderValNeu = 0;
    int sliderDif = 0;
    emit Verbunden(1);
    while(1)
    {
        sliderValNeu = slider->get(SLIDERGETONE);

        if (sliderVal != sliderValNeu)
        {
            sliderDif = abs(sliderValNeu - sliderVal); // Prüfen ob neue Slider Wert +/- 20% vom alten wert nicht überschreitet

            if (sliderDif <=20)
            {   // Wenn der neue Slider wert im berreich drinnen ist
                sliderVal = sliderValNeu;                                                   // wird der neue Wert übernommen
                emit ValChanged(sliderVal);
                //if (sliderVal <= 4)sliderVal=0;
                sliderVal *= 2.55;
                if (sliderVal >= 180)
                    sliderVal = 180;

                while(sliderOld != sliderVal)
                {                                  // Alten Slider wert auf Neuen wert in 1 schritten ranfahren
                    if(sliderOld < sliderVal)
                        sliderOld++;
                    else
                        sliderOld--;

                    for(int i = 2; i < 10; i++)
                    {
                        if (arryHauptlicht[i - 2]== 1)
                            pca->pca9635PWMWrite(pcaHL,i,sliderOld);
               // Alten Slider wert der um 1 erhöt wurde in alle LEDs schreiben
                    }
                    QThread::msleep(10);

                }
            }
        }

        QThread::msleep(150);
        if(this->Stop){
            slider->set(SLIDERSETONE, 1);
            emit Verbunden(0);

            int hlprozent = 0;
            for(int i = 2; i < 10; i++)
            {
                hlprozent += pca->pca9635PWMRead(pcaHL, i);
            }
            hlprozent /= 8;
            pca->pca9635PWMWrite(pcaHL,LUEFTERHAUPTLICHT,hlprozent);
            pca->pca9635PWMWrite(pcaHL,LUEFTERNETZEIL,hlprozent + 70);
            break;
        }
    }
}

void MyThread::checkBoxChanged(int index, bool value)
{
    arryHauptlicht[index] = value;
}

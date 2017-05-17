#include "mainthread.h"

mainThread::mainThread(QObject *parent) :
    QObject(parent)
{

}


void mainThread::init(QThread &cThread)
{
    connect(&cThread,SIGNAL(started()),this,SLOT(mainLoop()));      // Verbindung des Thread mit Mainloop
}

void mainThread::mainLoop()
{
    fa = pcaRGB->pcaInit(PcaRGB);

    rgbTest();

    while(1)
    {
    //lueftercontroll();    // UP Lüftercotroll Automatik
    //thread->msleep(100);
    }
}


void mainThread::lueftercontroll()
{
    fd = pcaHL->pcaInit(PcaHL);                         //Bus Init

    for (int i = 2; i <=9; i++)
    {
        arrayHL[i] = pcaHL->pca9635PWMRead(fd,i);       // Alles werte des HL in Array speichern
    }

    for (int a = 2; a <=9; a++)
    {
        hlPower = hlPower + arrayHL[a] ;                // Alle Array werte Summieren
    }

    last = (2040 / hlPower) * 100;
    last = 2.55 * last;
    last = int(last);
    if (last <= 100)
        last = 0;

    qDebug() << last;
    //pcaHL->pca9635PWMWrite(fd,LuefterHL,last);
    //pcaHL->pca9635PWMWrite(fd,LuefterUnten,last);
    //pcaHL->pca9635PWMWrite(fd,LuefterTop,last - 40);

}

void mainThread::rgbTest(){

    for(int i = 0; i > 255; i++)
    {
        pcaRGB->pca9635PWMWrite(fa,RGBFensterGruen,i);
        thread->msleep(10);
    }

    for(int i = 0; i > 255; i++)
    {
        pcaRGB->pca9635PWMWrite(fa,RGBFensterBlau,i);
        thread->msleep(10);
    }
    for(int i = 0; i > 255; i++)
    {
        pcaRGB->pca9635PWMWrite(fa,RGBFensterRot,i);
        thread->msleep(10);
    }



}

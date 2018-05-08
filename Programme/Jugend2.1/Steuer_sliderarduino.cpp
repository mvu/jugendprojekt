#include "Steuer_sliderarduino.h"


using namespace std;

SliderArduino::SliderArduino(QObject *parent) : QObject(parent)
{
    udp = new QUdpSocket(this);
    timer = new QTimer(this);
    udp->connectToHost(QHostAddress(IP_Slider),PORT_Slider,QIODevice::ReadWrite);     // Hinterlagt in der Mainconfig
    if(udp->isOpen()){
        timer->start(AktualisierungsZeit);                              // Hinterlegt in der Mainconfig
        connect(udp,SIGNAL(readyRead()),this,SLOT(read()));
        connect(timer,SIGNAL(timeout()),this,SLOT(timerEnd()));
    }
}

void SliderArduino::set(char sliderNum, int value)
{
    if(udp->isOpen()){
        QString word = sliderNum;
        word.append(QString::number(value));
        QByteArray send = word.toUtf8();
        udp->write(send.data());
    }
}

int SliderArduino::get(int sliderNum)
{
    return val1[sliderNum -1];
}

void SliderArduino::read(){
    buffer.resize(udp->pendingDatagramSize());
    udp->read(buffer.data(),buffer.size());
    valSlider[Sliderwechsel] = 1024 - buffer.toInt();
}

void SliderArduino::timerEnd(){
    if(udp->isOpen()){
        //qDebug()<<"Write data";
        QString word;
        Sliderwechsel++;
        switch (Sliderwechsel) {
        case 1:
            word = "A0";
            break;
        case 2:
            word = "B0";
            break;
        case 3:
            word = "C0";
            break;
        case 4:
            word = "D0";
            break;
        default:
            Sliderwechsel = 0;
            break;
        }
        QByteArray send = word.toUtf8();
        udp->write(send.data());
    }
}

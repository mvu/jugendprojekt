#include "thread_ueberwachung.h"

//for debug
#include <iostream>

using namespace std;

thread_Ueberwachung::thread_Ueberwachung(QObject *parent, steuerungThreadLicht *s)
{
    //setup on start

    //setup TemperaturSensors
    ArrayOfSensors.append(TempSensorHauptlicht1);
    ArrayOfSensors.append(TempSensorHauptlicht2);
    ArrayOfSensors.append(TempSensorNetzteile);
    ArrayOfSensors.append(TempSensorDecke);
    for (int i = 0; i < 3; i++){
        Temperaturen[i] = 0;
    }

    //setup timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkTemp()));
    //start timer with 5s interval
    timer->start(500000);
    //initial reading
    checkTemp();

    connect(this, SIGNAL(WandschalterPressed(bool)), s, SLOT(toggleStandard(bool)));
}


void thread_Ueberwachung::run(){
    bool status_old = checkWandschalter();
    while (true){
        bool status_new = checkWandschalter();
        if (status_new != status_old){
            emit WandschalterPressed(status_new);
            status_old = status_new;
        }
        QThread::msleep(100);
    }
}

//public slots/////////////////////////////////////////

void thread_Ueberwachung::setLuefter(int luefter, int val)
{

}

float thread_Ueberwachung::requestTemp(int Sensor)
{
    return Temperaturen[Sensor];
}

//private slots////////////////////////////////////////

float thread_Ueberwachung::getTemp(int Sensor){
    int temp = 0;
    float T;

    //open file and read
    QFile file(ArrayOfSensors[Sensor]);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString data = in.readLine();//read first line
    data = in.readLine();//read second line, owerwrite first one
    file.close();
    //parse data for information in second line: "t=XXXXX"
    for (int i = 0; i < data.length(); i++){
        if (data.at(i) == 't'){
            temp += data.at(i+2).digitValue()*10000;
            temp += data.at(i+3).digitValue()*1000;
            temp += data.at(i+4).digitValue()*100;
            temp += data.at(i+5).digitValue()*10;
            temp += data.at(i+6).digitValue();
            break;
        }
    }

   // std::cout << temp << "\n";
    T = temp/1000.;
    return T;
}

bool thread_Ueberwachung::checkWandschalter()
{
    //std::cout << "Wandschalter: " << gpiocontrollReadB(0x10) << "\n";
    if (gpiocontrollReadB(0x10) >= 1) return true;
    else return false;
}

void thread_Ueberwachung::checkTemp(){
    //std::cout<<"Temperaturen[3] = "<<Temperaturen[3]<<"\n";

    //first read all sensors
    float tempTemp[]={(getTemp(0)+getTemp(1))/2., getTemp(2), getTemp(3), getTemp_pi()};

    //then compare
    //no loop because of different names of signals
    if (tempTemp[0] != Temperaturen[0]){
        emit TempSteuerplatineChanged(tempTemp[0]);
        Temperaturen[0] = tempTemp[0];
    }
    if (tempTemp[1] != Temperaturen[1]){
        emit TempNetzteileChanged(tempTemp[1]);
        Temperaturen[1] = tempTemp[1];
    }
    if (tempTemp[2] != Temperaturen[2]){
        emit TempDeckeChanged(tempTemp[2]);
        Temperaturen[2] = tempTemp[2];
    }
    if (tempTemp[3] != Temperaturen[3]){
        emit TempPiChanged(tempTemp[3]);
        Temperaturen[3] = tempTemp[3];
    }
}

float thread_Ueberwachung::getTemp_pi()
{
    int temp = 0;
    float T;
    QProcess process;
    process.start("vcgencmd measure_temp");
    process.waitForFinished(-1);//wait forever, otherwise time in ms in argument
    QString data = process.readAllStandardOutput();

    //parse data, format: temp=XX.X'C
    for (int i = 0; i<data.length(); i++)
    {
        if (data.at(i) == '=')
        {
            temp += data.at(i+1).digitValue()*100;
            temp += data.at(i+2).digitValue()*10;
            temp += data.at(i+4).digitValue();
            break;
        }
    }
    T = temp/10.;
    //std::cout<<"temp: "<<temp<<", T: "<<T<<"\n";
    return T;
}

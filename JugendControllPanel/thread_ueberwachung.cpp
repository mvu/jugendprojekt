#include "thread_ueberwachung.h"

//for debug
#include <iostream>
#include <QtGlobal>

using namespace std;

thread_Ueberwachung::thread_Ueberwachung(QObject *parent, steuerungThreadLicht *s)
{
    //setup on start

    //setup TemperaturSensors
    /*
    ArrayOfSensors.append(TempSensorHauptlicht1);
    ArrayOfSensors.append(TempSensorHauptlicht2);
    ArrayOfSensors.append(TempSensorNetzteile);
    ArrayOfSensors.append(TempSensorDecke);

    for (int i = 0; i < 3; i++){
        Temperaturen[i] = 0;
    }
    */

    sThread = s;

    ArduinoUDP = new ArduinoCommunication();
    bool con = ArduinoUDP->connectUDP(ArduinoIp, ArduinoPort);
    checkTemp();

    //setup timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkTemp()));
    //start timer with 5s interval
    timer->start(5000);

    wiringPiSetup();
    pinMode(7, INPUT);

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
    /* // Alte Messung über DS1820
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
    */
}

bool thread_Ueberwachung::checkWandschalter()
{

    if(digitalRead(7) == true && digitalRead(6) == true && digitalRead(5) == true){
        QThread::msleep(1000);
        if(digitalRead(7) == true){
            QThread::msleep(1000);
                    if(digitalRead(6) == true){
                        QThread::msleep(1000);
                        if(digitalRead(5) == true){
                            QThread::msleep(1000);
							if(digitalRead(7) == true) return true;
							else return false;
						}
						else return false;
					}
					else return false;
		}			
        else return false;
    }
    if(digitalRead(7) == false && digitalRead(6) == false && digitalRead(5) == false){
        QThread::msleep(2000);
        if(digitalRead(6) == false) {
            QThread::msleep(2000);
            if(digitalRead(5) == false) return false;
			else return true;
		}
		else return true;
	}
    /*
    bool stat1 = digitalRead(7);
    QThread::msleep(50);
    bool stat2 = digitalRead(7);

    if (stat1 == stat2){
        return stat1;
    }
    else {
        bool stat3 = digitalRead(7);
        return stat3;
    }


    //std::cout << "Wandschalter: " << gpiocontrollReadB(0x10) << "\n";
    if (gpiocontrollReadB(0x10) >= 1){
        QThread::msleep(500);
        if (gpiocontrollReadB(0x10) >= 1){
            QThread::msleep(500);
            if(gpiocontrollReadB(0x10)>= 1)return true;
            else return false;
        }
    }
    else return false;
    */
}

void thread_Ueberwachung::checkTemp(){
    //std::cout << "Start Temp \n";
    //std::cout<<"Temperaturen[3] = "<<Temperaturen[3]<<"\n";

    //first read all sensors
    //qint64 time_start = QDateTime::currentMSecsSinceEpoch();

    QList<float> TempArray = ArduinoUDP->allSensors();
    float test[] = {TempArray.at(0),TempArray.at(1),TempArray.at(2),TempArray.at(3),TempArray.at(4),TempArray.at(5),TempArray.at(6)};
    //std::cout << "check Temp \n";
    if(TempArray.length() == 6){
        for (int var = 0; var < 6; ++var) {
            if (test[var] < minTemp)test[var] = minTemp;
            else if(test[var] > maxTemp)test[var] = maxTemp;

        }
    }
    float pwm;
    int stat;

//    qint64 time_1 = QDateTime::currentMSecsSinceEpoch();
//    std::cout << "Zeit 1: "<< time_1 - time_start << "\n";

    if (TempArray.length() == 6){
        float tempTemp[] = {(TempArray.at(1) + TempArray.at(2))/2., TempArray.at(0), TempArray.at(4), getTemp_pi(), TempArray.at(5), TempArray.at(3)};


        //then compare
        //no loop because of different signalnames
        if (tempTemp[0] != Temperaturen[0]){
        //PLATINE
            Temperaturen[0] = tempTemp[0];
            //set Luefter
            stat = pca9635RGBRead(LUEFTERHAUPTLICHT);
            if (Temperaturen[0] < THRESHOLD-HYSTERESE){
                pwm = 0;
            }
            else if ((Temperaturen[0] >= THRESHOLD-HYSTERESE) && (Temperaturen[0] <= THRESHOLD+HYSTERESE)){
                if (stat != 0) pwm = LuefterMin;
                else pwm = 0;
            }
            else if ((Temperaturen[0] > THRESHOLD+HYSTERESE) && (Temperaturen[0] < TempPlat_High)){
                pwm = LuefterMin/((THRESHOLD-TempPlat_High)*(THRESHOLD-TempPlat_High)) * (Temperaturen[0]-THRESHOLD)*(Temperaturen[0]-THRESHOLD) + LuefterMin;
            }
            else if (Temperaturen[0] >= TempPlat_High){
                pwm = 1;
            }
            else if (Temperaturen[0] >= TempPlat_Crit){
                //ALERT!!!!!!!!!!
                pwm = 1;
            }
            emit TempSteuerplatineChanged(tempTemp[0], int(pwm*100));
            sThread->luefterController(int(pwm*255));
        }
        if (tempTemp[1] != Temperaturen[1]){
        //Netzteile
            Temperaturen[1] = tempTemp[1];
            //set Luefter
            stat = pca9635RGBRead(LUEFTERNETZEIL);
            if (Temperaturen[1] < THRESHOLD){
                if ((sThread->getStatusHauptlicht()) || (sThread->getStatusRGBRelais())){
                    pwm = LuefterMin;
                }
                else{
                    if(gpiocontrollReadA(NETZTEIL48V) >= 1) pwm = LuefterMin;                   // !!! Neu zum sicher gehen das wenn Netzteil an ist Lüfter auch an sind
                    else pwm = 0;
                }
            }
            else if ((Temperaturen[1] > THRESHOLD) && (Temperaturen[1] < TempNetz_High)){
                pwm = LuefterMin/((THRESHOLD-TempNetz_High)*(THRESHOLD-TempNetz_High)) * (Temperaturen[1]-THRESHOLD)*(Temperaturen[1]-THRESHOLD) + LuefterMin;
            }
            else if (Temperaturen[1] > TempNetz_High){
                pwm = 1;
            }
            else if (Temperaturen[1] > TempNetz_Crit){
                //ALERT!!!!!!!!!!
                pwm = 1;
            }
            sThread->luefterNetzteil(int(pwm*255));
            emit TempNetzteileChanged(tempTemp[1], int(pwm*100));
        }
        if (tempTemp[2] != Temperaturen[2]){
        //KAMMER
            Temperaturen[2] = tempTemp[2];
            //set Luefter
            if (Temperaturen[2] < THRESHOLD){
                pwm = 0;
            }
            else if ((Temperaturen[2] > THRESHOLD) && (Temperaturen[2] < TempRaum_High)){
                pwm = LuefterTopMin/((THRESHOLD-TempRaum_High)*(THRESHOLD-TempRaum_High)) * (Temperaturen[2]-THRESHOLD)*(Temperaturen[2]-THRESHOLD) + LuefterTopMin;
            }
            else if (Temperaturen[2] > TempRaum_High){
                pwm = 1;
            }
            else if (Temperaturen[2] > TempRaum_Crit){
                //ALERT!!!!!!!!!!
                pwm = 1;
            }
            sThread->luefterAusgangOben(int(pwm*255));
            emit TempDeckeChanged(tempTemp[2], int(pwm*100));

        }
        if (tempTemp[3] != Temperaturen[3]){
        //PI
            emit TempPiChanged(tempTemp[3]);
            Temperaturen[3] = tempTemp[3];

        }
        if (tempTemp[4] != Temperaturen[4]){
        //ONKYO
            Temperaturen[4] = tempTemp[4];
            //set Luefter
            stat = pca9635RGBRead(LUEFTERONKYO);
            if (Temperaturen[4] < THRESHOLD-HYSTERESE){
                pwm = 0;
            }
            else if ((Temperaturen[4] >= THRESHOLD-HYSTERESE) && (Temperaturen[4] <= THRESHOLD+HYSTERESE)){
                if (stat != 0) pwm = LuefterMin;
                else pwm = 0;
            }
            else if ((Temperaturen[4] > THRESHOLD+HYSTERESE) && (Temperaturen[4] < TempPlat_High)){
                pwm = LuefterMin/((THRESHOLD-TempOnkyo_High)*(THRESHOLD-TempOnkyo_High)) * (Temperaturen[4]-THRESHOLD)*(Temperaturen[4]-THRESHOLD) + LuefterMin;
            }
            else if (Temperaturen[4] >= TempOnkyo_High){
                pwm = 1;
            }
            else if (Temperaturen[4] >= TempOnkyo_Crit){
                //ALERT!!!!!!!!!!
                pwm = 1;
            }
            sThread->luefterOnkyo(int(pwm*255));
            emit TempVerstaerkerChanged(tempTemp[4], int(pwm*100));
        }
        if (tempTemp[5] != Temperaturen[5]){
        //PC
            emit TempPCChanged(tempTemp[5]);
            Temperaturen[5] = tempTemp[5];
        }
    }

//    qint64 time_2 = QDateTime::currentMSecsSinceEpoch();
//    std::cout << "Zeit 2: "<< time_2 - time_1 << "\n";
//    std::cout << "End Temp \n";
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


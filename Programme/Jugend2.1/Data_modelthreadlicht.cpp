#include "Data_modelthreadlicht.h"
//QThread(parent)
ModelThreadLicht::ModelThreadLicht(QObject *parent, steuerungThreadLicht *s)

{
    sThread = s;
    timer_SLiderCheck = new QTimer(this);
    timer_mainInfo = new QTimer(this);

    // Signale

    connect(this,SIGNAL(update()),s,SLOT(updateAll()));
    connect(timer_mainInfo,SIGNAL(timeout()),this,SLOT(mainInfoCheck()));

    // SLOT

    connect(s,SIGNAL(updateFinish()),this,SLOT(updateFinish()));

    timer_mainInfo->start(t_main);

}

void ModelThreadLicht::run()
{

}

void ModelThreadLicht::mainInfoCheck(){
    qDebug()<< " Check main Info";

    emit update();



}


void ModelThreadLicht::updateFinish()
{
        for (int var = 0; var < 9; ++var) {
            // was besseres überlegen um fehler zu erkennen
            arrayPWMHL[var] = (sThread->Hauptlicht_Data[var] + sThread->Hauptlicht_Data_Read[var]) / 2;
        }

        if(UART = -1)arryStatus[arStUart] = true;
        else arryStatus[arStUart] = false;


        // Temperatur auswertung wenn min oder max Temperatur erkannt wurde wird gemessener wert verworfen
        // ist Temperatur unterschied größer als 4 C° wird der mittelwert genommen von beiden
        if(arryStatus[arStUart]){
            for (int var = 0; var < 6; ++var) {
                arrayTemp[var] = sThread->Temp_all[var];
            }
            for (int var = 0; var < 6; ++var) {
                if (arrayTemp[var] > minTemp && arrayTemp[var] < maxTemp){
                    if(abs(arrayTemp[var] - arrayTempOld[var]) >= 4){
                        arrayTemp[var] = (arrayTemp[var] + arrayTempOld[var]) / 2;
                        arrayTempOld[var] = arrayTemp[var];
                    }
                else arrayTempOld[var] = arrayTemp[var];
            }

        }

}


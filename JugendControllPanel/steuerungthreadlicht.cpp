#include "steuerungthreadlicht.h"
#include <QtCore>
#include <QtDebug>
#include <iostream>

steuerungThreadLicht::steuerungThreadLicht(QObject *parent) :
    QThread(parent)
{
    //initialize RGB_Decke
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 3; j++){
            RGB_Decke_Data[i][j] = 0;
        }
        RGB_Decke_Checked[i] = false;
    }
    //initialize RGB_Theke_Data
    for (int i = 0; i < 3; i++)
    {
        RGB_Theke_Data[i] = 10;
    }
    //initialize Hauptlicht
    for (int i = 0; i < 9; i++)
    {
         Hauptlicht_Data[i] = 0;
         Hauptlicht_Checked[i] = false;
    }
}

void steuerungThreadLicht::run()
{
    //connect(this, SIGNAL(fenstergetRGBvalue(int,int,int)),RgbWand,SLOT(setRGBwand(int,int,int)));
    //connect(this, SIGNAL(thekegetRGBvalue(int,int,int)),RgbTheke,SLOT(getRGBvalue(int,int,int)));

}

// INIT CONTROLLER ##################################################
void steuerungThreadLicht::initGPIO()
{
    gpiocontrollSetup();
}

void steuerungThreadLicht::initHauptlicht()
{
    pca9635Setup();
}

void steuerungThreadLicht::initRGB()
{
    pca9635Setup();
}

// DEFAULT#################################################

void steuerungThreadLicht::toggleStandard(bool on)
{
    std::cout << "Setting Standard to -> " << on << "\n";
    if (on)
    {
        standardOn();
        luefterNetzteil(0xff);
        luefterController(0xff);
    }
    else
    {
        allOFF();
        luefterNetzteil(0x00);
        luefterController(0x00);
    }
}

// HAUPTLICHT #########################################

void steuerungThreadLicht::hauptlichtAll(int val)
{
    //wants 8bit pwm value
    pca9635HLWriteAll(val);
}

void steuerungThreadLicht::hauptlichtSelect(int leuchte, int val)
{
    pca9635HLWrite(leuchte,val);
}

void steuerungThreadLicht::hauptlichtNetzteilOnOff()
{
    // toggeld das Netzteil für 48V
    if(gpiocontrollReadA(NETZTEIL48V) >= 1)gpiocontrollWriteA(NETZTEIL48V,0);
    else gpiocontrollWriteA(NETZTEIL48V,1);
}

void steuerungThreadLicht::hauptlichtSelectVal(int leuchte)
{
    emit hauptlichtSelectValSig( pca9635HLRead(leuchte));
}

void steuerungThreadLicht::hauptlichtAllVal()
{
    emit hauptlichtAllVal();
}

void steuerungThreadLicht::SetHauptlicht(int val)
{
    //sets value only if box checked
    for (int i = 0; i < 8; i++){
        if (Hauptlicht_Checked[i]){
            Hauptlicht_Data[i] = val;
            pca9635HLWrite(i,val);
        }
    }
}

// THEKE ###########################################################

void steuerungThreadLicht::thekeRGBAllVal(int valR, int valG, int valB)
{
    pca9635RGBallWrite(RGBTHEKEROT,valR,valG,valB);
}

void steuerungThreadLicht::thekeRGBSelectVal(int farbe, int val)
{
    pca9635RGBWrite(farbe, val);
}

void steuerungThreadLicht::thekeRGBRainbowOnOff()
{
    // parallel task ??
}

void steuerungThreadLicht::thekegetRGB()
{
    int r = pca9635RGBRead(RGBTHEKEROT);
    int g = pca9635RGBRead(RGBTHEKEGREUN);
    int b = pca9635RGBRead(RGBTHEKEBLAU);
    emit thekegetRGBvalue(r,g,b);
}

// FENSTER #######################################################

void steuerungThreadLicht::fensterRGBAllVal(int val)
{
    pca9635RGBallWrite(RGBFENSTERROT,val,val,val);
}

void steuerungThreadLicht::fensterRGBSelectVal(int farbe, int val)
{
    pca9635RGBWrite(farbe, val);
}

void steuerungThreadLicht::fensterRGBRainbowOnOff()
{
    // parallel Task ??
}

void steuerungThreadLicht::fenstergetRGB()
{
    int r = pca9635RGBRead(RGBFENSTERROT);
    int g = pca9635RGBRead(RGBFENSTERGRUEN);
    int b = pca9635RGBRead(RGBFENSTERBLAU);
    emit fenstergetRGBvalue(r,g,b);
}

// Relais ##############################################################

void steuerungThreadLicht::thekeLichtOnOff(bool checked)
{
    if (gpiocontrollReadA(THEKE) >= 1) gpiocontrollWriteA(THEKE,0);
    else gpiocontrollWriteA(THEKE, 1);
}

void steuerungThreadLicht::paletteLichtOnOff(bool checked)
{
    if (gpiocontrollReadA(PALETTE) >= 1) gpiocontrollWriteA(THEKE, 0);
    else gpiocontrollWriteA(THEKE, 1);
}

void steuerungThreadLicht::beamerOnOff(bool checked)
{
    if (gpiocontrollReadA(BEAMER) >= 1) gpiocontrollWriteA(BEAMER, 0);
    else gpiocontrollWriteA(BEAMER, 1);
}

// DECKEN RGB LEUCHTEN #########################################

void steuerungThreadLicht::deckeRGBPowerOnOff()
{
    if (gpiocontrollReadA(NETZTEIL12V)>= 1)gpiocontrollWriteA(NETZTEIL12V, 0);
    else gpiocontrollWriteA(NETZTEIL12V, 1);
}

void steuerungThreadLicht::RGB_Decke_DataRot_Changed(int val)
{
    std::cout << "RGB-Decke-ROT changed to " << val << "\n";
    for (int i = 0; i < 18; i++){
        if (RGB_Decke_Checked[i]){
            RGB_Decke_Data[i][0] = val;
            sendRGB(i+1, RGB_Decke_Data[i][0], RGB_Decke_Data[i][1], RGB_Decke_Data[i][2]);
        }
    }
}

void steuerungThreadLicht::RGB_Decke_DataGruen_Changed(int val)
{
    std::cout << "RGB-Decke-GRUEN changed to " << val << "\n";
    for (int i = 0; i < 18; i++){
        if (RGB_Decke_Checked[i]){
            RGB_Decke_Data[i][1] = val;
            sendRGB(i+1, RGB_Decke_Data[i][0], RGB_Decke_Data[i][1], RGB_Decke_Data[i][2]);
        }
    }
}

void steuerungThreadLicht::RGB_Decke_DataBlau_Changed(int val)
{
    std::cout << "RGB-Decke-BLAU changed to " << val << "\n";
    for (int i = 0; i < 18; i++){
        if (RGB_Decke_Checked[i]){
            RGB_Decke_Data[i][2] = val;
            sendRGB(i+1, RGB_Decke_Data[i][0], RGB_Decke_Data[i][1], RGB_Decke_Data[i][2]);
        }
    }
}


// Lüfter Controller ###################################################

void steuerungThreadLicht::luefterController(int val)
{
    pca9635HLWrite(LUEFTERHAUPTLICHT,val);
}

void steuerungThreadLicht::luefterAusgangOben(int val)
{
    pca9635HLWrite(LUEFTERTOP, val);
}

void steuerungThreadLicht::luefterNetzteil(int val)
{
    pca9635HLWrite(LUEFTERNETZEIL, val);
}

void steuerungThreadLicht::getLuefterAusgangObenslot()
{
    emit getLuefterAusgangOben(pca9635HLRead(LUEFTERTOP));
}

void steuerungThreadLicht::getLuefterControllerslot()
{
    emit getLuefterController(pca9635HLRead(LUEFTERHAUPTLICHT));
}

void steuerungThreadLicht::getLuefterNetzteilslot()
{
    emit getLuefterNetzteil(pca9635HLRead(LUEFTERNETZEIL));
}


// MISC ######################################################
void steuerungThreadLicht::allOFF()
{
    std::cout << "switching all OFF \n";
    //alle lichter aus
    hauptlichtAll(0);
    //check for all 0
//    for (int i = 2; i < 9; ++i) {
//        while (true)
//        {
//            int val = pca9635HLRead(i);
//            if(val = 0)break;
//            else hauptlichtSelect(i,0);
//        }
//    }
    //alle Decken-RGB im Array auf 0
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 3; j++){
            RGB_Decke_Data[i][j] = 0;
        }
        RGB_Decke_Checked[i] = false;
    }
    //fenster RGB off
    fensterRGBAllVal(0);

    //theke rgb off
    thekeRGBAllVal(0,0,0);

    //alle relais aus
    gpiocontrollWriteAllA(0x00);
}

void steuerungThreadLicht::standardOn()
{
    std::cout << "switching std ON\n";
    //theke on
    gpiocontrollWriteA(0x02, true);
    //hauptlicht an
    hauptlichtNetzteilOnOff();
    hauptlichtAll(0x55);
}

void steuerungThreadLicht::jugendLichtON(){
    int hlOld = pcaHlReadAll();
    if(hlOld > 150){
        while(hlOld != 150){
            hlOld--;
            pca9635HLWriteAll(hlOld);
        }
    }
    else {
        while(hlOld != 150){
            hlOld++;
            pca9635HLWriteAll(hlOld);
        }
    }
    gpiocontrollWriteA(THEKE, 1);
    gpiocontrollWriteA(PALETTE, 1);
}

void steuerungThreadLicht::teenLichtOn(){
    int hlOld = pcaHlReadAll();
    if(hlOld > 150){
        while(hlOld != 130){
            hlOld--;
            pca9635HLWriteAll(hlOld);
        }
    }
    else {
        while(hlOld != 130){
            hlOld++;
            pca9635HLWriteAll(hlOld);
        }
    }
    gpiocontrollWriteA(THEKE, 0);
    gpiocontrollWriteA(PALETTE, 0);
}

void steuerungThreadLicht::kino(){

}

void steuerungThreadLicht::praistime(){

}

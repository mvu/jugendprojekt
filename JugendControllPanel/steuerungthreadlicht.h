#ifndef STEUERUNGTHREADLICHT_H
#define STEUERUNGTHREADLICHT_H

#include <QObject>
#include <QThread>
#include <QtCore>
#include "mainconfig.h"
#include "maincontroll.h"
#include "theke.h"
#include "rgbwand.h"
#include "einstellung.h"

class steuerungThreadLicht : public QThread
{
    Q_OBJECT

public:
    explicit steuerungThreadLicht(QObject *parent = 0);
    void run();
    int RGB_Decke_Data[18][3];
    bool RGB_Decke_Checked[18];
    int RGB_Wand_Data[3];
    int RGB_Theke_Data[3];
    int Hauptlicht_Data[9];
    bool Hauptlicht_Checked[9];

signals:
    // Hauptlicht Helligkeit Infos
    void hauptlichtAllVal(int);
    void hauptlichtSelectValSig(int);

    // Theke Farbwerte
    void thekegetRGBvalue(int r,int g, int b);

    // Fenster Farbwerte
    void fensterRot(int);
    void fensterBlau(int);
    void fensterGruen(int);
    void fenstergetRGBvalue(int r,int g, int b);

    // Relais Schaltzustand
    void thekeLicht(int);
    void paletteLicht(int);
    void beamer(int);
    void hauptlichtPower(int);
    void rgbPower(int);

    // Decke Farbwert ???


    // Lüfter
    void getLuefterNetzteil(int val);
    void getLuefterController(int val);
    void getLuefterAusgangOben(int val);


public slots:
    // Init
    void initHauptlicht();
    void initRGB();
    void initGPIO();

    //default
    void toggleStandard(bool on);

    // Hauptlicht
    void hauptlichtAll(int val);
    void hauptlichtSelect(int leuchte, int val);
    void hauptlichtSelectVal(int leuchte);
    void hauptlichtAllVal();
    void SetHauptlicht(int val);
    bool getStatusHauptlicht();

    // Theke
    void thekeRGBAllVal(int valR, int valG, int valB);
    void thekeRGBSelectVal(int farbe, int val);
    void thekeRGBRainbowOnOff();
    void thekegetRGB();
    bool thekegetDecke();

    // Fenster
    void fensterRGBAllVal(int val);
    void fensterRGBSelectVal(int farbe, int val);
    void fensterRGBRainbowOnOff();
    void fenstergetRGB();

    // Relais Controll
    void deckeRGBPowerOnOff();
    void thekeLichtOnOff(bool checked);
    void paletteLichtOnOff(bool checked);
    void hauptlichtNetzteilOnOff();
    void beamerOnOff(bool checked);
    void pc_pulse();
    bool getStatusBeamer();
    bool getStatusPalette();

    // Decken RGB Leuchten
    void RGB_Decke_DataRot_Changed(int val);
    void RGB_Decke_DataGruen_Changed(int val);
    void RGB_Decke_DataBlau_Changed(int val);
    bool getStatusRGBRelais();

    // main Controll
    void allOFF();
    void jugendLichtON();
    void teenLichtOn();              // fehlt noch
    void kino();                   // fehlt noch
    void praistime();                   // fehlt noch

    // Lüfter Controll
    void luefterNetzteil(int val);
    void luefterController(int val);
    void luefterAusgangOben(int val);
    void luefterOnkyo(int val);
    void getLuefterNetzteilslot();
    void getLuefterAusgangObenslot();
    void getLuefterControllerslot();

    //MISC
    void standardOn();

};

#endif // STEUERUNGTHREADLICHT_H

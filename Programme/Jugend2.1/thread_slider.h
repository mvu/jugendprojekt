#ifndef THREAD_SLIDER_H
#define THREAD_SLIDER_H

//Thread to communicate with sliders
//checks for change of Sliders every 10ms and emits Signal if changed
//also you can set Sliders from 0 to 100 (in %)

//#define Slider1 SLIDERSETONE
//#define Slider2 SLIDERSETTWO
//#define Slider3 SLIDERSETTHREE
//#define Slider4 SLIDERSETFOUR

#include "mainconfig.h"

#include "Steuer_sliderarduino.h"

class SliderArduino;

class thread_Slider : public QThread
{
    Q_OBJECT

public:
    explicit thread_Slider(QObject *parent = 0);
    void run();

private:
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;

    SliderArduino *SliderControl;

    int SliderOld[4];//for storing values to compare with

signals:
    void Slider1_Changed(int);  //value from 0% to 100%
    void Slider2_Changed(int);  //value from 0% to 100%
    void Slider3_Changed(int);  //value from 0% to 100%
    void Slider4_Changed(int);  //value from 0% to 100%

private slots:
    void Slider1_Check();
    void Slider2_Check();
    void Slider3_Check();
    void Slider4_Check();

public slots:
    void close();
    void init(int val1, int val2, int val3, int val4);  //value from 0% to 100%
    void setSlider(int slider, int val);                //value from 0% to 100%

};

#endif // THREAD_SLIDER_H

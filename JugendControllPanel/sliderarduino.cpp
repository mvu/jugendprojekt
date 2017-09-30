#include "sliderarduino.h"


using namespace std;

SliderArduino::SliderArduino(QObject *parent) : QObject(parent)
{

}



void SliderArduino::set(int sliderNum, int value)
{
    wiringPiI2CWriteReg8(slider, sliderNum, value);
}

int SliderArduino::get(int sliderNum)
{
    //Arduino sends percent
    int val1 = wiringPiI2CReadReg8(slider, sliderNum);
    std:cout << "Read Slider"<<val1<<"\n";

//    if ((val1 == 0) || (val1 >= 99)){
//        int val2 = wiringPiI2CReadReg8(slider, sliderNum);
//        if (val2 == val1) return val1;
//        else return -1;
//    }
    return val1;
}

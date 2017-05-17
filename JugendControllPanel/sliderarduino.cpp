#include "sliderarduino.h"

SliderArduino::SliderArduino(QObject *parent) : QObject(parent)
{

}



void SliderArduino::set(int sliderNum, int value)
{
    wiringPiI2CWriteReg8(slider, sliderNum, value);
}

int SliderArduino::get(int sliderNum)
{
    //Arduino sends 8bit, map to percent
    int val = wiringPiI2CReadReg8(slider, sliderNum);
    return int(val/2.55);
}

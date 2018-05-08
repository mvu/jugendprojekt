#include "gpiocontroll.h"
#include "mainconfig.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>

gpiocontroll::gpiocontroll()
{

}

void gpiocontroll::setup(){
   // mutex.lock();
        int fd = wiringPiI2CSetup(PortExpander);
         wiringPiI2CWriteReg8(fd, 0x00, 0x00);
         wiringPiI2CWriteReg8(fd, 0x01, 0x00);
         //mutex.unlock();
}

void gpiocontroll::WriteA(int val, int set){
    //mutex.lock();
    int fd = wiringPiI2CSetup(PORTEXPANDER);
    int read = wiringPiI2CReadReg8(fd,PortA);
    if (set == 1)
    {
      wiringPiI2CWriteReg8(fd, PortA, read | val);
    }
    else
    {
        wiringPiI2CWriteReg8(fd, PortA, read ^ val);
    }



    //mutex.unlock();

}

void gpiocontroll::WriteB(int val){
    //mutex.lock();
    int fd = wiringPiI2CSetup(PortExpander);
    wiringPiI2CWriteReg8(fd, PortB, val);
    //mutex.unlock();
}

int gpiocontroll::readA(){

    int fd = wiringPiI2CSetup(PortExpander);
    int read = wiringPiI2CReadReg8(fd,PortA);
    return read;
}

void gpiocontroll::off()
{
    int fd = wiringPiI2CSetup(PortExpander);
    wiringPiI2CWriteReg8(fd,PortA,0x00);

}

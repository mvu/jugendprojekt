#include "Steuer_pca_9635.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>


pca_9635::pca_9635(QObject *parent) :
    QObject(parent)
{

}


int pca_9635::pcaInit(int i2c){
    int fd = wiringPiI2CSetup(i2c);
    if (fd < 0)
        return fd;
    return fd;
}

int pca_9635::pca9635Setup(int i2cAddress)
{
    //mutex.lock();
    int fd = wiringPiI2CSetup(i2cAddress);
    if (fd < 0)
        return fd;

    wiringPiI2CWriteReg8(fd, PCA9635_MODE1, 0x00);
    wiringPiI2CWriteReg8(fd, PCA9635_MODE2, 0x1D);
    wiringPiI2CWriteReg8(fd, PCA9635_GRPPWM, 0x00);

    wiringPiI2CWriteReg8(fd, PCA9635_LEDOUT0, 0xAA);
    wiringPiI2CWriteReg8(fd, PCA9635_LEDOUT1, 0xAA);
    wiringPiI2CWriteReg8(fd, PCA9635_LEDOUT2, 0xAA);
    wiringPiI2CWriteReg8(fd, PCA9635_LEDOUT3, 0xAA);
    //mutex.unlock();
    return fd;

}

int pca_9635::pca9635PWMRead(int fd, int reg)
{
    //mutex.lock();
    int val =wiringPiI2CReadReg8(fd, reg);
    //mutex.unlock();
    return val;

}


void pca_9635::pca9635PWMReset(int fd)
{
    //wiringPiI2CWriteReg16(fd, LEDALL_ON_L	 , 0x0);
    //wiringPiI2CWriteReg16(fd, LEDALL_ON_L + 2, 0x1000);
    return;
}

void pca_9635::pca9635PWMWrite(int fd, int pin, int pwm)
{
    //mutex.lock();
    wiringPiI2CWriteReg8(fd, pin, pwm);
   // mutex.unlock();
    return;
}

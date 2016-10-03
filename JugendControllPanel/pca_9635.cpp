#include "pca_9635.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>

pca_9635::pca_9635(QObject *parent) :
    QObject(parent)
{
}


int pca_9635::pca9635Setup(int i2cAddress)
{
    int fd = wiringPiI2CSetup(i2cAddress);
    if (fd < 0)
        return fd;

    wiringPiI2CWriteReg8(fd, PCA9635_MODE1, 0x00);
    wiringPiI2CWriteReg8(fd, PCA9635_MDOE2, 0x0D);
    wiringPiI2CWriteReg8(fd, PCA9635_GRPPWM, 0x00);

    wiringPiI2CWriteReg8(fd, PCA9635_LEDOUT0, 0xAA);
    wiringPiI2CWriteReg8(fd, PCA9635_LEDOUT1, 0xAA);
    wiringPiI2CWriteReg8(fd, PCA9635_LEDOUT2, 0xAA);
    wiringPiI2CWriteReg8(fd, PCA9635_LEDOUT3, 0xAA);
    return fd;

}

int pca_9635::pca9635PWMRead(int fd, int reg)
{
    int val =wiringPiI2CReadReg8(fd, reg);
    return val;

}

void pca_9635::pca9635FullOff(int fd, int pin, int tf)
{
    return;
}

void pca_9635::pca9635FullOn(int fd, int pin, int tf)
{
    return;
}

void pca_9635::pca9635PWMFreq(int fd, float freq)
{
    // Cap at min and max
    freq = (freq > 1000 ? 1000 : (freq < 40 ? 40 : freq));

    // To set pwm frequency we have to set the prescale register. The formula is:
    // prescale = round(osc_clock / (4096 * frequency))) - 1 where osc_clock = 25 MHz
    // Further info here: http://www.nxp.com/documents/data_sheet/PCA9635.pdf Page 24
    int prescale = (int)(25000000.0f / (4096 * freq) - 0.5f);

    // Get settings and calc bytes for the different states.
    int settings = wiringPiI2CReadReg8(fd, PCA9635_MODE1) & 0x7F;	// Set restart bit to 0
    int sleep	= settings | 0x10;									// Set sleep bit to 1
    int wake 	= settings & 0xEF;									// Set sleep bit to 0
    int restart = wake | 0x80;										// Set restart bit to 1

    // Go to sleep, set prescale and wake up again.
    wiringPiI2CWriteReg8(fd, PCA9635_MODE1, sleep);
    wiringPiI2CWriteReg8(fd, PCA9635_PRESCALE, prescale);
    wiringPiI2CWriteReg8(fd, PCA9635_MODE1, wake);

    // Now wait a millisecond until oscillator finished stabilizing and restart PWM.
    delay(1);
    wiringPiI2CWriteReg8(fd, PCA9635_MODE1, restart);
    return;
}

void pca_9635::pca9635PWMReset(int fd)
{
    wiringPiI2CWriteReg16(fd, LEDALL_ON_L	 , 0x0);
    wiringPiI2CWriteReg16(fd, LEDALL_ON_L + 2, 0x1000);
    return;
}

void pca_9635::pca9635PWMWrite(int fd, int pin, int pwm)
{
    wiringPiI2CWriteReg8(fd, pin, pwm);
    return;
}

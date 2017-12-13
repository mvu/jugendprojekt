#include "mainconfig.h"

int pcaRGB;
int pcaHL;
int expander;
int slider;
int UART;

void init(){
    pcaHL = wiringPiI2CSetup(PCAHL);
    pcaRGB = wiringPiI2CSetup(PCARGB);
    expander = wiringPiI2CSetup(PORTEXPANDER);
    slider = wiringPiI2CSetup(ARDUINOSLIDER);

    wiringPiI2CWriteReg8(expander, IODIRB, 0xf0);

    //initializes UART on /dev/ttyS0 on pi3
    UART = open("/dev/ttyS0", O_WRONLY | O_NOCTTY);
    //returns -1 if failed to open port
    if (UART != -1){
        struct termios options;
        tcgetattr(UART, &options);
        options.c_cflag = B115200 | CS8 | CLOCAL;
        options.c_iflag = 0;
        options.c_oflag = 0;
        options.c_lflag = 0;
        tcflush(UART, TCIFLUSH);
        tcsetattr(UART, TCSANOW, &options);
    }

    wiringPiI2CWriteReg8(pcaHL, PCA9635_MODE1, 0x00);
    wiringPiI2CWriteReg8(pcaHL, PCA9635_MODE2, 0x1D);
    wiringPiI2CWriteReg8(pcaHL, PCA9635_GRPPWM, 0x00);

    wiringPiI2CWriteReg8(pcaHL, PCA9635_LEDOUT0, 0xAA);
    wiringPiI2CWriteReg8(pcaHL, PCA9635_LEDOUT1, 0xAA);
    wiringPiI2CWriteReg8(pcaHL, PCA9635_LEDOUT2, 0xAA);
    wiringPiI2CWriteReg8(pcaHL, PCA9635_LEDOUT3, 0xAA);

    wiringPiI2CWriteReg8(pcaRGB, PCA9635_MODE1, 0x00);
    wiringPiI2CWriteReg8(pcaRGB, PCA9635_MODE2, 0x1D);
    wiringPiI2CWriteReg8(pcaRGB, PCA9635_GRPPWM, 0x00);

    wiringPiI2CWriteReg8(pcaRGB, PCA9635_LEDOUT0, 0xAA);
    wiringPiI2CWriteReg8(pcaRGB, PCA9635_LEDOUT1, 0xAA);
    wiringPiI2CWriteReg8(pcaRGB, PCA9635_LEDOUT2, 0xAA);
    wiringPiI2CWriteReg8(pcaRGB, PCA9635_LEDOUT3, 0xAA);

    wiringPiSetup();
    pinMode(7,INPUT);
    pinMode(6,INPUT);
    pinMode(5,INPUT);

}

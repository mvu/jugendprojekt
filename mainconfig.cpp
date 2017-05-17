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

    //initializes UART on /dev/ttyAMA0
    //use /dev/ttyS0 on pi3
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
}

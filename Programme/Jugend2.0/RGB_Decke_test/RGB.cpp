#include "RGB.h"

void initUART(){
	//initializes UART on /dev/ttyAMA0
	//use /dev/ttyS0 on pi3
	UART = open("/dev/ttyAMA0", O_WRONLY | O_NOCTTY);
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

int sendRGB(int addr, int red, int green, int blue){
	//sends data to RGB-Module via UART
	int8_t data[4];
	int8_t *byte; //pointer
	//make data
	byte = &data[0];
	*byte++ = addr | 0x80;
	*byte++ = red & 0x7F;
	*byte++ = green & 0x7F;
	*byte++ = blue & 0x7F;
	//write data
	int n = write(bus, &data[0], (byte - &data[0]));
	return n;
}

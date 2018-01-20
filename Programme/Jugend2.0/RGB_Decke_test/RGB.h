#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include <errno.h>

int setupUART();
void sendRGB(int bus, int addr, int red, int green, int blue);


int setupUART(){
  //Open the Port, use /dev/ttyS0 on pi3
  int uart;
  uart = open("/dev/ttyAMA0", O_WRONLY | O_NOCTTY);
  if (uart == -1) {
    perror("[ERROR] Unable to open /dev/ttyAMA0 - ");
    return(-1);
  }

  struct termios options;
  tcgetattr(uart, &options);
  options.c_cflag = B115200 | CS8 | CLOCAL;
  options.c_iflag = 0;
  options.c_oflag = 0;
  options.c_lflag = 0;
  tcflush(uart, TCIFLUSH);
  tcsetattr(uart, TCSANOW, &options);

  return uart;
}

void sendRGB(int bus, int addr, int red, int green, int blue){
  //sends data to RGB-Module via UART
  int8_t data[4];
  int8_t *byte; //pointer
  //make data
  byte = &data[0];
  *byte++ = addr | 0x80;//ensure leading 1
  *byte++ = red & 0x7F;//ensure leading 0
  *byte++ = green & 0x7F;//ensure leading 0
  *byte++ = blue & 0x7F;//ensure leading 0
  //write data
  int n = write(bus, &data[0], (byte - &data[0]));
  if (n < 0) {
    perror("[ERROR] Write failed - ");
  }
}

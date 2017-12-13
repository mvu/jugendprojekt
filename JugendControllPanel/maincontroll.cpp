#include "maincontroll.h"

void pca9635Setup(){
    // Init alle zwei PCA 9635

    // Init PCA 9635 für Hauptlicht

    wiringPiI2CWriteReg8(pcaHL, PCA9635_MODE1, 0x00);
    wiringPiI2CWriteReg8(pcaHL, PCA9635_MODE2, 0x1D);
    wiringPiI2CWriteReg8(pcaHL, PCA9635_GRPPWM, 0x00);

    wiringPiI2CWriteReg8(pcaHL, PCA9635_LEDOUT0, 0xAA);
    wiringPiI2CWriteReg8(pcaHL, PCA9635_LEDOUT1, 0xAA);
    wiringPiI2CWriteReg8(pcaHL, PCA9635_LEDOUT2, 0xAA);
    wiringPiI2CWriteReg8(pcaHL, PCA9635_LEDOUT3, 0xAA);

    // Init PCA 9635 für RGB Licht

    wiringPiI2CWriteReg8(pcaRGB, PCA9635_MODE1, 0x00);
    wiringPiI2CWriteReg8(pcaRGB, PCA9635_MODE2, 0x1D);
    wiringPiI2CWriteReg8(pcaRGB, PCA9635_GRPPWM, 0x00);

    wiringPiI2CWriteReg8(pcaRGB, PCA9635_LEDOUT0, 0xAA);
    wiringPiI2CWriteReg8(pcaRGB, PCA9635_LEDOUT1, 0xAA);
    wiringPiI2CWriteReg8(pcaRGB, PCA9635_LEDOUT2, 0xAA);
    wiringPiI2CWriteReg8(pcaRGB, PCA9635_LEDOUT3, 0xAA);

}

void pca9635HLWrite(int pin, int pwm){                      // Funktion zur Steuerung des Hauptlichtes Pin von 1 bis 8
    if (pin < 9)wiringPiI2CWriteReg8(pcaHL, pin + 2, pwm);  // +2 bei Pin um keine umrechnung zu haben von Leute zu Register
}

void pca9635RGBWrite(int pin, int pwm){                     // Funktion zur Steuerung des RGB Controllers aber nur 1 Farbe
    wiringPiI2CWriteReg8(pcaRGB, pin, pwm);
}

void pca9635HLWriteAll(int pwm){
    for (int var = 2; var < 10; ++var) {
        wiringPiI2CWriteReg8(pcaHL, var, pwm);
    }
    //wiringPiI2CWriteReg8(pcaHL, 0x05, pwm);

}

void pca9635RGBallWrite(int pin, int pwmR, int pwmG, int pwmB){ // Funktion zur Steuerung des RGB Controllers aber direkt eines Farblocks
    wiringPiI2CWriteReg8(pcaRGB, pin, pwmR);                    // R G B direkt zusammen start mit Rot
    wiringPiI2CWriteReg8(pcaRGB, pin +1, pwmG);
    wiringPiI2CWriteReg8(pcaRGB, pin +2, pwmB);
}

int pca9635HLRead(int pin){                                     // zur auslesen das Aktuellen Helligkeit eines Lichtes
    return wiringPiI2CReadReg8(pcaHL, pin);
}

int pcaHlReadAll(){                                             // Auslesen der Gesamt Helligkeit
    int HlSumme = 0;
    for (int var = 1; var < 9; ++var) {                         // List alle werte aus und Addiert sie
        HlSumme += wiringPiI2CReadReg8(pcaHL,var);
    }
    return HlSumme / 8;                                         // Rückgabewert Summe geteilt durch 8
}

int pca9635RGBRead(int pin){                                    // zum Lesen eines RGB wertes
    return wiringPiI2CReadReg8(pcaRGB, pin);
}

void gpiocontrollSetup(){                                       // Init den Portexpander und legt alles als Ausgang fest
    wiringPiI2CWriteReg8(expander, 0x00, 0x00);
    wiringPiI2CWriteReg8(expander, 0x01, 0x00);
}

void gpiocontrollWriteA(int pin, bool val){
    int read = wiringPiI2CReadReg8(expander,PORTA);
    if (val == true) wiringPiI2CWriteReg8(expander, PORTA, read | pin);
    else wiringPiI2CWriteReg8(expander, PORTA, read ^ pin);
}

void gpiocontrollWriteB(int pin, bool val){
    int read = wiringPiI2CReadReg8(expander,PORTB);
    if (val == true) wiringPiI2CWriteReg8(expander, PORTB, read | pin);
    else wiringPiI2CWriteReg8(expander, PORTB, read ^ pin);
}

void gpiocontrollWriteAllA(int val){
    wiringPiI2CWriteReg8(expander, PORTA, val);
}

void gpiocontrollWriteAllB(int val){
    wiringPiI2CWriteReg8(expander, PORTB, val);
}

int gpiocontrollReadA(int pin){
    return pin & wiringPiI2CReadReg8(expander,PORTA);
}

int gpiocontrollReadB(int pin){
    return pin & wiringPiI2CReadReg8(expander,PORTB);
}

int gpiocontrollReadAllA(){
    return wiringPiI2CReadReg8(expander,PORTA);
}

int gpiocontrollReadAllB(){
    return wiringPiI2CReadReg8(expander,PORTB);
}

void sendRGB(int addr, int red, int green, int blue){
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
    int n = write(UART, &data[0], (byte - &data[0]));
}

#include "Steuer_maincontroll.h"

void pca9635Setup(){
    // Init alle zwei PCA 9635
    // Init PCA 9635 für Hauptlicht
    if(useWiringPi){
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
    else {
        qDebug()<<"PCA Init";
    }
}

void pca9635HLWrite(int pin, int pwm){                      // Funktion zur Steuerung des Hauptlichtes Pin von 1 bis 8
    if(useWiringPi){
        if (pin < 9)wiringPiI2CWriteReg8(pcaHL, pin + 2, pwm);  // +2 bei Pin um keine umrechnung zu haben von Leute zu Register
    }
    else qDebug()<<"Write Hauptlicht:"<<pin<<":"<<pwm;
}

void pca9635RGBWrite(int pin, int pwm){                     // Funktion zur Steuerung des RGB Controllers aber nur 1 Farbe
    if(useWiringPi){
        wiringPiI2CWriteReg8(pcaRGB, pin, pwm);
    }
    else qDebug()<<"Write PCA RGB:"<<pin<<":"<<pwm;
}

void pca9635HLWriteAll(int pwm){
    if(useWiringPi){
        for (int var = 2; var < 10; ++var) {
            wiringPiI2CWriteReg8(pcaHL, var, pwm);
        }
        //wiringPiI2CWriteReg8(pcaHL, 0x05, pwm);
    }
    else qDebug()<<"Write Hauptlicht alle:"<< pwm;
}

void pca9635RGBallWrite(int pin, int pwmR, int pwmG, int pwmB){ // Funktion zur Steuerung des RGB Controllers aber direkt eines Farblocks
    if(useWiringPi){
        wiringPiI2CWriteReg8(pcaRGB, pin, pwmR);                    // R G B direkt zusammen start mit Rot
        wiringPiI2CWriteReg8(pcaRGB, pin +1, pwmG);
        wiringPiI2CWriteReg8(pcaRGB, pin +2, pwmB);
    }
    else qDebug()<<"Write Pca RGB alle:"<<pin<<"Rot:"<<pwmR<<"Grün:"<<pwmG<<"Blau:"<<pwmB;
}

int pca9635HLRead(int pin){                                     // zur auslesen das Aktuellen Helligkeit eines Lichtes
    if(useWiringPi){
        return wiringPiI2CReadReg8(pcaHL, pin);
    }
    else qDebug()<<"Read Hauptlicht:"<<pin; return 100;
}

int pcaHlReadAll(){                                             // Auslesen der Gesamt Helligkeit
    if(useWiringPi){
        int HlSumme = 0;
        for (int var = 1; var < 9; ++var) {                         // List alle werte aus und Addiert sie
            HlSumme += wiringPiI2CReadReg8(pcaHL,var);
        }
        return HlSumme / 8;                                         // Rückgabewert Summe geteilt durch 8
    }
    else qDebug()<<"Read Hauptlicht Summe:"; return 100;
}

int pca9635RGBRead(int pin){                                    // zum Lesen eines RGB wertes
    if(useWiringPi){
        return wiringPiI2CReadReg8(pcaRGB, pin);
    }
    qDebug()<<"Read PCA RGB:"<<pin; return 50;
}

void gpiocontrollSetup(){                                       // Init den Portexpander und legt alles als Ausgang fest
    if(useWiringPi){
        wiringPiI2CWriteReg8(expander, IODIRA, PortExpanderIOA);
        wiringPiI2CWriteReg8(expander, IODIRB, PortExpanderIOB);
    }
    else qDebug()<<"Portexpander Setup";
}

void gpiocontrollWriteA(int pin, bool val){
    if(useWiringPi){
        int read = wiringPiI2CReadReg8(expander,PORTA);
        if (val == true) wiringPiI2CWriteReg8(expander, PORTA, read | pin);
        else wiringPiI2CWriteReg8(expander, PORTA, read ^ pin);
    }
    else qDebug()<<"Write Port A Portexpander Bit:"<<pin<<":"<<val;
}

void gpiocontrollWriteB(int pin, bool val){
    if(useWiringPi){
        int read = wiringPiI2CReadReg8(expander,PORTB);
        if (val == true) wiringPiI2CWriteReg8(expander, PORTB, read | pin);
        else wiringPiI2CWriteReg8(expander, PORTB, read ^ pin);
    }
    else qDebug()<<"Write Port B Portexpander Bit:"<<pin<<":"<<val;
}

void gpiocontrollWriteAllA(int val){
    if(useWiringPi) wiringPiI2CWriteReg8(expander, PORTA, val);
    else qDebug()<<"Write Port A Portexpander Register:"<<val;
}

void gpiocontrollWriteAllB(int val){
    if(useWiringPi) wiringPiI2CWriteReg8(expander, PORTB, val);
    else qDebug()<<"Write Port B Portexpander Register:"<<val;
}

int gpiocontrollReadA(int pin){
    if(useWiringPi) return pin & wiringPiI2CReadReg8(expander,PORTA);
    else qDebug()<<"Read Pin Port A:"<<pin; return 1;
}

int gpiocontrollReadB(int pin){
    if(useWiringPi) return pin & wiringPiI2CReadReg8(expander,PORTB);
    else qDebug()<<"Read Pin Port B:"<<pin; return 1;
}

int gpiocontrollReadAllA(){
    if(useWiringPi) return wiringPiI2CReadReg8(expander,PORTA);
    else qDebug()<<"Read Register Port A:"; return 10;
}

int gpiocontrollReadAllB(){
    if(useWiringPi) return wiringPiI2CReadReg8(expander,PORTB);
    else qDebug()<<"Read Register Port B"; return 10;
}

int sendRGB(int addr, int red, int green, int blue){
    if(useWiringPi){
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
        return write(UART, &data[0], (byte - &data[0]));
    }
    else qDebug()<<"Send RGB über Uart: addr:"<<addr<<"Rot:"<<red<<"Grün:"<<green<<"Blau:"<<blue;
}

bool statusi2c(){
    if(wiringPiI2CRead(expander) != -1)return true;
    else return false;
}

bool statusUart(){
    if(UART != -1) return true;
    else return false;
}

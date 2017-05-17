#ifndef MAINCONTROLL_H
#define MAINCONTROLL_H

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringPiSPI.h>
#include "mainconfig.h"

#define PORTA 0x12
#define PORTB 0x13

void pca9635Setup();
void pca9635HLWrite(int pin, int pwm);
void pca9635HLWriteAll(int pwm);
int pca9635HLRead(int pin);
int pcaHlReadAll();

void pca9635RGBWrite(int pin, int pwm);
void pca9635RGBallWrite(int pin, int pwmR, int pwmG, int pwmB);
int pca9635RGBRead(int pin);

void gpiocontrollSetup();
void gpiocontrollWriteA(int pin, bool val);
void gpiocontrollWriteB(int pin, bool val);
void gpiocontrollWriteAllA(int val);
void gpiocontrollWriteAllB(int val);
int gpiocontrollReadA(int pin);
int gpiocontrollReadB(int pin);
int gpiocontrollReadAllA();
int gpiocontrollReadAllB();

void sendRGB(int addr, int red, int green, int blue);//to write RGB to Ceiling

#endif // MAINCONTROLL_H

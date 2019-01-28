<<<<<<< Updated upstream
#include <AFMotor.h>       // Motorshield library
#include <PID_v1.h>        // PID library
=======
#include "slider.h"
>>>>>>> Stashed changes

#define ADC_SLIDER_1    A0
#define ADC_SLIDER_2    A1
#define ADC_SLIDER_3    A2
#define ADC_SLIDER_4    A3

<<<<<<< Updated upstream
struct Slider {
    double setpoint, analog_value, motor_speed, kp, ki, kd;
    uint8_t analog_pin;
};

//                         set in out   p   i   d   pin
struct Slider slider_1 = {  0,  0,  0,  2,  5,  1,  ADC_SLIDER_1};
struct Slider slider_2 = {  0,  0,  0,  2,  5,  1,  ADC_SLIDER_2};
struct Slider slider_3 = {  0,  0,  0,  2,  5,  1,  ADC_SLIDER_3};
struct Slider slider_4 = {  500,  0,  0,  1, 5,  0,  ADC_SLIDER_4};

// create four PID controllers for the sliders
PID pid_1(&slider_1.analog_value, &slider_1.motor_speed, &slider_1.setpoint,\
            slider_1.kp, slider_1.ki, slider_1.kd, DIRECT);
PID pid_2(&slider_2.analog_value, &slider_2.motor_speed, &slider_2.setpoint,\
            slider_2.kp, slider_2.ki, slider_2.kd, DIRECT);
PID pid_3(&slider_3.analog_value, &slider_3.motor_speed, &slider_3.setpoint,\
            slider_3.kp, slider_3.ki, slider_3.kd, DIRECT);
PID pid_4(&slider_4.analog_value, &slider_4.motor_speed, &slider_4.setpoint,\
            slider_4.kp, slider_4.ki, slider_4.kd, DIRECT);

// create 4 AF_DCMotor objects for the motors controlling the sliders
AF_DCMotor motor_1(1, MOTOR12_1KHZ);
AF_DCMotor motor_2(2, MOTOR12_1KHZ);
AF_DCMotor motor_3(3, MOTOR12_1KHZ);
AF_DCMotor motor_4(4, MOTOR12_1KHZ);

=======
Slider slider_1(ADC_SLIDER_1, 1, 1.1, 5, 0);
Slider slider_2(ADC_SLIDER_2, 2, 1.1, 5, 0);
Slider slider_3(ADC_SLIDER_3, 3, 5, 2, 0);
Slider slider_4(ADC_SLIDER_4, 4, 0.3, 2, 0);
>>>>>>> Stashed changes

void setup()
{
    Serial.begin(115200);
<<<<<<< Updated upstream
    Serial.println("Slider Controller Version 3.0\nIntialization started");

    // setup pins for analog input
    pinMode(slider_1.analog_pin, INPUT);
    pinMode(slider_1.analog_pin, INPUT);
    pinMode(slider_1.analog_pin, INPUT);
    pinMode(slider_1.analog_pin, INPUT);
    // and do first measurement
    slider_1.analog_value = analogRead(slider_1.analog_pin);
    slider_2.analog_value = analogRead(slider_2.analog_pin);
    slider_3.analog_value = analogRead(slider_3.analog_pin);
    slider_4.analog_value = analogRead(slider_4.analog_pin);
    Serial.println("\tADC ready");

    // motors don't need additional initialization
    Serial.println("\tMotors ready");

    // turn on pid controllers
    pid_1.SetMode(AUTOMATIC);
    pid_1.SetSampleTime(50);
    pid_2.SetMode(AUTOMATIC);
    pid_2.SetSampleTime(50);
    pid_3.SetMode(AUTOMATIC);
    pid_3.SetSampleTime(50);
    pid_4.SetMode(AUTOMATIC);
    pid_4.SetSampleTime(25);
    pid_4.SetOutputLimits(-255,255);
    Serial.println("\tPID controllers ready");

    // show the addresses of the setpoints
    Serial.println("Intialization completed.\n");
=======

    // Nice Serial Output ;)
    Serial.println("Slider controller version 3.0");
    Serial.println("Intialization completed.\n");
    // Tell user about addresses of setpoints
>>>>>>> Stashed changes
    Serial.println("Use the following addresses to move the sliders:");
    Serial.print("\tSlider 1 -> "); Serial.println(reinterpret_cast<int>(&slider_1.setpoint), HEX);
    Serial.print("\tSlider 2 -> "); Serial.println(reinterpret_cast<int>(&slider_2.setpoint), HEX);
    Serial.print("\tSlider 3 -> "); Serial.println(reinterpret_cast<int>(&slider_3.setpoint), HEX);
    Serial.print("\tSlider 4 -> "); Serial.println(reinterpret_cast<int>(&slider_4.setpoint), HEX);
<<<<<<< Updated upstream
=======
    // Tell user about addresses of active flags
    Serial.println("Use the following addresses to activate the sliders:");
    Serial.print("\tSlider 1 -> "); Serial.println(reinterpret_cast<int>(&slider_1.active), HEX);
    Serial.print("\tSlider 2 -> "); Serial.println(reinterpret_cast<int>(&slider_2.active), HEX);
    Serial.print("\tSlider 3 -> "); Serial.println(reinterpret_cast<int>(&slider_3.active), HEX);
    Serial.print("\tSlider 4 -> "); Serial.println(reinterpret_cast<int>(&slider_4.active), HEX);

    // use slider_3 for testing
    slider_4.active = true;
    slider_4.setpoint = 500;
>>>>>>> Stashed changes
}

void loop()
{
<<<<<<< Updated upstream
    // delay(500);
    slider_4.analog_value = analogRead(slider_4.analog_pin);

    pid_4.Compute();

    // Serial.println(slider_4.analog_value);
    // Serial.println(slider_4.motor_speed);
    motor_4.run((slider_4.motor_speed <= 0) ? FORWARD : BACKWARD);
    motor_4.setSpeed(abs(slider_4.motor_speed));

    if (Serial.available() > 0){
        int tmp = Serial.parseInt();
        slider_4.setpoint = tmp;
        Serial.println(tmp);
    }
=======
    slider_4.update();

    if (Serial.available() > 0)
    {
        slider_4.setpoint = Serial.parseInt();
    }

>>>>>>> Stashed changes
}

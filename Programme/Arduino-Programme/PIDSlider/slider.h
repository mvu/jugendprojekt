#include <Arduino.h>        // standard arduino functionality
#include <AFMotor.h>        // Motorshield library

class Slider {

public:
    Slider(int analog_pin, int motor_num);

    void update();
    void activate();
    void deactivate();
private:
    AF_DCMotor motor_;
    PID pid_;

    void pid_compute();

    // PID parameters
    double analog_value_, motor_speed_, setpoint_;
    double kp_, ki_, kd_;
    int sample_time_;
    // PID varaibles
    unsigned long last_time_;
    double last_analog_value_, output_sum_;
    double out_min_, out_max_;
    // adc pin
    int analog_pin_;
    // status
    bool active_, released_;
}

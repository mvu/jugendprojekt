#include "slider.h"

Slider::Slider(int analog_pin, int motor_num){
    // initialize variables
    analog_pin_ = analog_pin;
    kp_ = 1.1;
    ki_ = 0.3;
    kd_ = 0;
    setpoint_ = 0;
    sample_time_ = 50;
    motor_speed_ = 0;

    active_ = false;
    free_running = true;

    // setup pin
    pinMode(analog_pin_, INPUT);
    analog_value_ = analogRead(analog_pin_);

    // set up AFMotor
    motor_ = AF_DCMotor(motor_num, MOTOR12_1KHZ);
    motor_.run(RELEASE);

    // setup PID controller
    pid_ = PID(&analog_value_, &motor_speed_, &setpoint_, kp_, ki_, kd_, DIRECT);
    pid_.SetSampleTime(sample_time_);
}

void Slider::update(){
    if (active) {
        analog_value_ = analogRead(analog_pin_);
        if (not free_running_) {
            pid_.Compute();
            motor_.setSpeed(abs(motor_speed_));
            motor_.run((motor_speed_ <= 0) ? FORWARD : BACKWARD);
        }
    }
}

void Slider::activate(){
    active_ = true;
}

void Slider::deactivate(){
    active_ = false;
}

void Slider::pid_compute(){
    // heavily based upon PIDLibrary from Brett Beauregard
    // see https://playground.arduino.cc/Code/PIDLibrary

    unsigned long now = millis();
    unsigned long time_change = now - last_time_;

    if(time_change >= sample_time_) {
    /*Compute all the working error variables*/
        double error = setpoint_ - analog_value_;
        double d_input = analog_value_ - last_analog_value_);
        output_sum_ += (ki_ * error);

        if(output_sum > out_max_) output_sum_ = out_max_;
        else if(output_sum < out_min_) output_sum_ = out_min_;

        // add up parts
        double output = kp_ * error + output_sum_ - kd_ * d_input;

        if(output > out_max_) output = out_max_;
        else if(output < out_min_) output = out_min_;
        motor_speed_ = output;

        /*Remember some variables for next time*/
        last_analog_value_ = analog_value_;
        last_time_ = now;
    }
}

#include "slider.h"

Slider::Slider(int analog_pin, int motor_num, double kp, double ki, double kd){
    // initialize variables
    sample_time_ = 25;
    last_setpoint_ = -1;
    setpoint = 1023; // so it automatically moves to the bottom on start up
    motor_speed_ = 0;
    settle_time_ = 300;
    settle_threshold_ = 50;
    last_settle_value_ = 2047;
    compute_cycle_counter_ = 0;
    out_min_ = -255;
    out_max_ = 255;
    analog_pin_ = analog_pin;

    // compute some values
    settle_counter_ = settle_time_ / sample_time_;
    kp_ = kp;
    ki_ = ki * sample_time_/1000;
    kd_ = 0; // kd / (sample_time_/1000);

    // setup pin
    pinMode(analog_pin_, INPUT);
    analog_value = analogRead(analog_pin_);

    // set up AFMotor
    motor_ = new AF_DCMotor(motor_num, MOTOR12_1KHZ);
    motor_->run(RELEASE);

    active = true;
    released_ = false;
}

void Slider::update()
{
    unsigned long before = micros();
    // only do stuff, when active
    if (active)
    {
        // get the new AD reading
        analog_value = analogRead(analog_pin_);

        // check for new setpoint
        if (last_setpoint_ != setpoint)
        {
            released_ = false;
            last_setpoint_ = setpoint;
        }

        // compute motor speed, if slider needs to be moved
        if (not released_)
        {
            pid_compute();
            // do nothing if pid_compute has changed the state of released_
            if (not released_) {
                motor_->setSpeed(abs(motor_speed_));
                motor_->run((motor_speed_ <= 0) ? FORWARD : BACKWARD);
            }
        }
    }
    unsigned long after = micros();
    Serial.println(after-before);
}

void Slider::pid_compute(){
    // heavily based upon PIDLibrary from Brett Beauregard
    // see https://playground.arduino.cc/Code/PIDLibrary


    unsigned long now = millis();
    unsigned long time_change = now - last_time_;

    if(time_change >= sample_time_)
    {
        // Compute all the working error variables
        double error = setpoint - analog_value;
        double d_input = analog_value - last_analog_value_;
        output_sum_ += (ki_ * error);
        if(output_sum_ > out_max_) output_sum_ = out_max_;
        else if(output_sum_ < out_min_) output_sum_ = out_min_;

        // add up parts
        double output = kp_ * error + output_sum_ - kd_ * d_input;

        // limit the output
        if(output > out_max_) output = out_max_;
        else if(output < out_min_) output = out_min_;
        motor_speed_ = output;

        // detect if steady state is reached
        // in that case turn of motor
        compute_cycle_counter_ ++;
        if (compute_cycle_counter_ == settle_counter_)
        {
            if ((abs(last_settle_value_ - analog_value) <= settle_threshold_) &&
                (abs(last_settle_value_ - setpoint) < settle_threshold_) &&
                (abs(analog_value - setpoint) < settle_threshold_))
            {
                motor_->run(RELEASE);
                released_ = true;
            }
            compute_cycle_counter_ = 0;
            last_settle_value_ = analog_value;
        }

        // Remember some variables for next time
        last_analog_value_ = analog_value;
        last_time_ = now;
    }

}

#include "temperatur_sensor.h"

TemperaturSensor::TemperaturSensor(int analog_pin, double a, double b, double c, int mov_avg_ind, int update_freq_ms)
{
    // move the paramers to private variables
    analog_pin_ = analog_pin;
    a_ = a;
    b_ = b;
    c_ = c;
    mov_avg_ind_ = (mov_avg_ind <= MAX_AVG_RANGE) ? mov_avg_ind : MAX_AVG_RANGE;
    update_freq_ms_ = update_freq_ms;

    // initialize stuff
    curr_total_ = 0;
    curr_read_index_ = 0;
    for (int i = 0; i < mov_avg_ind_; i++)
    {
        readings_[i] = analogRead(analog_pin_);
        curr_total_ += readings_[i];
    }
    temp = ADValueToTemperature(curr_total_);
    last_read_time_ = millis();
}

double TemperaturSensor::ADValueToTemperature(double ad_mean)
{
    // use a quatratic approximation for the thermal resistor
    double RT = 2700.0 * ad_mean/(1024.0 - ad_mean);
    double T = -b_/(2.0 * a_) + sqrt(1.0 / a_ * (b_*b_/(4.0*a_) + RT - c_));
    return T;
}

void TemperaturSensor::update()
{
    unsigned long now = millis();

    if (abs(now - last_read_time_) > update_freq_ms_) //
    {
        // get a new reading
        int ad = analogRead(analog_pin_);
        last_read_time_ = now;

        // update the average
        curr_total_ -= readings_[curr_read_index_];
        curr_total_ += ad;
        readings_[curr_read_index_] = ad;
        curr_read_index_ = (curr_read_index_ + 1) % mov_avg_ind_;

        // update temperature
        temp = ADValueToTemperature(curr_total_/mov_avg_ind_);
    }
}

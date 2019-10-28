#include <Arduino.h>

#define MAX_AVG_RANGE 64

class TemperaturSensor {

public:
    TemperaturSensor(int analog_pin, double a, double b, double c, int mov_avg_ind, int update_freq_ms);
    void update();

    /*
    * Here the current value is stored and gets updated on every call to
    * update(). This memory is read via pointer fom the remote device via UDP
    */
    double temp;
private:
    double ADValueToTemperature(double ad_mean);
    int analog_pin_;                // pin to read the analog value from
    double a_, b_, c_;              // paramters of fit function
    int update_freq_ms_;            // controls update frequency
    unsigned long last_read_time_;  // timestamp of last measurement

    // variables for the moving average
    int mov_avg_ind_;               // the amount of readings to be averaged over
    int readings_[MAX_AVG_RANGE];   // readings to average over
    int curr_read_index_;           // index of reading to be redone
    unsigned long curr_total_;      // store the current total of mov_avg_ind_ readings
};

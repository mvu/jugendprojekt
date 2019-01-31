#include <Arduino.h>        // standard arduino functionality
#include <AFMotor.h>        // Motorshield library

class Slider {

public:
    Slider(int analog_pin, int motor_num, double kp, double ki, double kd);
    void update();
    void disable() {active = false; released_ = true;}

    bool active;
    double setpoint, analog_value;
private:
    AF_DCMotor* motor_;

    void pid_compute();

    // PID parameters
    double motor_speed_;
    double kp_, ki_, kd_;
    int sample_time_;
    // PID varaibles
    unsigned long last_time_;
    double last_analog_value_, output_sum_;
    double out_min_, out_max_;
    // to detect when position reached and motors can be released
    double settle_time_, last_settle_value_, settle_threshold_;
    int settle_counter_, compute_cycle_counter_;
    // to detect when slider should be moved
    double last_setpoint_;
    // adc pin
    int analog_pin_;
    // status
    bool released_, last_active_;
};

/*
 * Laufzeiten:
 *
 * handleUDP():
 *     - ohne Anfrage: 44 µs
 *     - get/set       570 µs
 * pid_compute():
 *     - typisch       8 µs ... 80 µs
 *     - release       250 µs
 * update():
 *     - not active    4 µs
 *     - released      120 µs
 *     - moving        280 µs
 */

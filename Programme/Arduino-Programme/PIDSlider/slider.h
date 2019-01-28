#include <Arduino.h>        // standard arduino functionality
#include <AFMotor.h>        // Motorshield library

class Slider {

public:
<<<<<<< Updated upstream
    Slider(int analog_pin, int motor_num);

    void update();
    void activate();
    void deactivate();
private:
    AF_DCMotor motor_;
    PID pid_;
=======
    Slider(int analog_pin, int motor_num, double kp, double ki, double kd);
    void update();

    bool active;
    double setpoint;
private:
    AF_DCMotor* motor_;
>>>>>>> Stashed changes

    void pid_compute();

    // PID parameters
<<<<<<< Updated upstream
    double analog_value_, motor_speed_, setpoint_;
=======
    double analog_value_, motor_speed_;
>>>>>>> Stashed changes
    double kp_, ki_, kd_;
    int sample_time_;
    // PID varaibles
    unsigned long last_time_;
    double last_analog_value_, output_sum_;
    double out_min_, out_max_;
<<<<<<< Updated upstream
    // adc pin
    int analog_pin_;
    // status
    bool active_, released_;
}
=======
    // to detect when position reached and motors can be released
    double settle_time_, last_settle_value_, settle_threshold_;
    int settle_counter_, compute_cycle_counter_;
    // to detect when slider should be moved
    double last_setpoint_;
    // adc pin
    int analog_pin_;
    // status
    bool released_;
};
>>>>>>> Stashed changes

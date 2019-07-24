/*!
 * \file hardware_config.h
 * \brief Definiert die Pinbelegung im Schaltschrank
 * \todo eine globale Konfiguarationsdatei zusammen mit ControlPanel-3-0 sinnvoller
 */
#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

// file locations
#define LOGFILE             "/home/pi/log/temperature.log"
// udp connections
#define SENSORS_UDP         QHostAddress("192.168.188.202"), 9999
#define CONTROL_UDP         QHostAddress::LocalHost, 9091

// pca address
#define PCA9635_ADDR        0x70

// update cycle in seconds
#define UPDATE_CYCLE_S      1

// noise threshold for temp sensors
#define TEMP_NOISE_THRESHOLD 0.1

// connections
#define FAN_CABIN           0x0a
#define FAN_ONKYO           0x0b
#define FAN_PWR_SUPPLY      0x0c
#define FAN_TEST            0x0f
//#define FAN_PI              0x0e


#define SENSOR_CABIN        0
#define SENSOR_ONKYO        3
#define SENSOR_TEST         3
#define SENSOR_PWR_SUPPLY   5
#define SENSOR_PI           0
#define SENSOR_PC           0
#define SENSOR_PCB          0

// default config params for JTemperaturController
// These get used if the configuration file can't be found
#define TEMP_HIGH           60
#define TEMP_CRIT           80
#define TEMP_THRESHOLD      35
#define TEMP_HYSTERESIS     5
#define FAN_MIN             50

#endif // HARDWARE_CONFIG_H

/*!
 * \file hardware_config.h
 * \brief Definiert die Pinbelegung im Schaltschrank
 * \todo eine globale Konfiguarationsdatei zusammen mit ControlPanel-3-0 sinnvoller
 */
#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

// udp connections
#define SENSORS_UDP         QHostAddress("192.168.2.101"), 9999
#define CONTROL_PANEL_UDP   QHostAddress::LocalHost, 9091

// pca address
#define PCA9635_ADDR        0x70

// update cycle in seconds
#define UPDATE_CYCLE_S      3

// noise threshold for temp sensors
#define TEMP_NOISE_THRESHOLD 0.1

// connections
#define FAN_ONKYO           0x01
#define FAN_PWR_SUPPLY      0x02
#define FAN_CABIN           0x03
#define FAN_PI              0x04

#define SENSOR_ONKYO        1
#define SENSOR_PWR_SUPPLY   2
#define SENSOR_CABIN        3
#define SENSOR_PI           4
#define SENSOR_PC           5
#define SENSOR_PCB          6

// default config params for JTemperaturController
// These get used if the configuration file can't be found
#define TEMP_HIGH           60
#define TEMP_CRIT           80
#define TEMP_THRESHOLD      35
#define TEMP_HYSTERESIS     5
#define FAN_MIN             30

#endif // HARDWARE_CONFIG_H

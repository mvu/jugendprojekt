/*!
 * \file hardware_config.h
 * \brief Definiert die Pinbelegung im Schaltschrank
 * \todo eine globale Konfiguarationsdatei zusammen mit ControlPanel-3-0 sinnvoller
 */
#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

#define SENSORS_IP          "192.168.2.101"
#define SENSORS_PORT        9999

#define CONTROL_PANEL_PORT  9091

#define FAN_ONKYO           0x01
#define FAN_PWR_SUPPLY      0x02
#define FAN_CABINET         0x03
#define FAN_PI              0x04

#define SENSOR_ONKYO        1
#define SENSOR_PWR_SUPPLY   2
#define SENSOR_CABINET      3
#define SENSOR_PI           4

#endif // HARDWARE_CONFIG_H

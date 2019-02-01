#include <Ethernet.h>
#include <EthernetUdp.h>

#include "slider.h"

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEf };
IPAddress ip(192, 168, 1, 111);
unsigned int local_port = 8888;

uint8_t packet_buffer[UDP_TX_PACKET_MAX_SIZE];
uint8_t reply_buffer[UDP_TX_PACKET_MAX_SIZE];
uint8_t register_buffer[24];

EthernetUDP udp;

#define ADC_SLIDER_1    A0
#define ADC_SLIDER_2    A1
#define ADC_SLIDER_3    A2
#define ADC_SLIDER_4    A3

Slider slider_1(ADC_SLIDER_1, 1, 0.2, 2.5, 0);
Slider slider_2(ADC_SLIDER_2, 2, 0.2, 2.5, 0);
Slider slider_3(ADC_SLIDER_3, 3, 0.2, 2.5, 0);
Slider slider_4(ADC_SLIDER_4, 4, 0.2, 2.5, 0);

void setup()
{
    Serial.begin(115200);

    // Nice Serial Output ;)
    Serial.println("Slider controller version 3.0");
    Serial.println("Initializing...");

    // setup Ethernet
    Ethernet.begin(mac, ip);
    udp.begin(local_port);
    packThePacket();
    Serial.print("\tEthernet ready on "); for (int i = 0; i < 4; i++) {Serial.print(ip[i], DEC); if (i < 3) Serial.print(".");}; Serial.print(":"); Serial.println(local_port, DEC);

    Serial.println("\tSlider ready");
    Serial.println("Intialization completed.\n");
    // Tell user about addresses of setpoints
    Serial.println("Use the following addresses to move the sliders:");
    Serial.print("\tSlider 1 -> "); Serial.println(reinterpret_cast<int>(&slider_1.setpoint), DEC);
    Serial.print("\tSlider 2 -> "); Serial.println(reinterpret_cast<int>(&slider_2.setpoint), DEC);
    Serial.print("\tSlider 3 -> "); Serial.println(reinterpret_cast<int>(&slider_3.setpoint), DEC);
    Serial.print("\tSlider 4 -> "); Serial.println(reinterpret_cast<int>(&slider_4.setpoint), DEC);
    // Tell user about addresses of analog_values
    Serial.println("Get the positions from the following addresses:");
    Serial.print("\tSlider 1 -> "); Serial.println(reinterpret_cast<int>(&slider_1.analog_value), DEC);
    Serial.print("\tSlider 2 -> "); Serial.println(reinterpret_cast<int>(&slider_2.analog_value), DEC);
    Serial.print("\tSlider 3 -> "); Serial.println(reinterpret_cast<int>(&slider_3.analog_value), DEC);
    Serial.print("\tSlider 4 -> "); Serial.println(reinterpret_cast<int>(&slider_4.analog_value), DEC);
    // Tell user about addresses of active flags
    Serial.println("Use the following addresses to activate the sliders:");
    Serial.print("\tSlider 1 -> "); Serial.println(reinterpret_cast<int>(&slider_1.active), DEC);
    Serial.print("\tSlider 2 -> "); Serial.println(reinterpret_cast<int>(&slider_2.active), DEC);
    Serial.print("\tSlider 3 -> "); Serial.println(reinterpret_cast<int>(&slider_3.active), DEC);
    Serial.print("\tSlider 4 -> "); Serial.println(reinterpret_cast<int>(&slider_4.active), DEC);

    slider_1.disable();
}

void loop()
{
    slider_1.update();
    slider_2.update();
    slider_3.update();
    slider_4.update();

    handleUDP();
}

void handleUDP()
{
    int packet_size = udp.parsePacket();
    if (packet_size)
    {
        // Serial.print("packet_size = "); Serial.print(packet_size, DEC);
        // Serial.print(" from "); Serial.print(udp.remoteIP(), DEC); Serial.print(":"); Serial.print(udp.remotePort(), DEC);
        // Serial.print(" : ");
        // high byte in 0, low byte in 1
        udp.read(packet_buffer, UDP_TX_PACKET_MAX_SIZE);
        if (packet_size == 1)
        {
            // Serial.println("done");
            // send addresses
            udp.beginPacket(udp.remoteIP(), udp.remotePort());
            udp.write(register_buffer, 24);
            udp.endPacket();
        }
        else if (packet_size == 2)
        {
            // Serial.println((packet_buffer[0] << 8) + packet_buffer[1], DEC);
            // send content of memory address
            uint16_t reg = (packet_buffer[0] << 8) + packet_buffer[1];
            uint8_t value[] = {(uint8_t)(int(*(reinterpret_cast<double* >(reg))) >> 8), (uint8_t)*(reinterpret_cast<double* >(reg))};
            udp.beginPacket(udp.remoteIP(), udp.remotePort());
            udp.write(value, 2);
            udp.endPacket();
        }
        else if (packet_size == 3)
        {
            // Serial.print((packet_buffer[0] << 8) + packet_buffer[1], DEC); Serial.print(" -> ");
            // Serial.println(bool(packet_buffer[2]));
            // set active
            *(reinterpret_cast<bool*>((packet_buffer[0] << 8) + packet_buffer[1])) = bool(packet_buffer[2]);
            // report success
            udp.beginPacket(udp.remoteIP(), udp.remotePort());
            udp.write('0');
            udp.endPacket();

        }
        else if (packet_size == 4)
        {
            // Serial.print((packet_buffer[0] << 8) + packet_buffer[1], DEC); Serial.print(" -> ");
            // Serial.println(double((packet_buffer[2] << 8) + packet_buffer[3]));
            // set content of memory address
            *(reinterpret_cast<double*>((packet_buffer[0] << 8) + packet_buffer[1])) = double((packet_buffer[2] << 8) + packet_buffer[3]);
            // report success
            udp.beginPacket(udp.remoteIP(), udp.remotePort());
            udp.write('0');
            udp.endPacket();
        }
    }
}

void packThePacket()
{
    uint16_t addr[12] = { \
        reinterpret_cast<uint16_t>(&slider_1.setpoint), \
        reinterpret_cast<uint16_t>(&slider_2.setpoint), \
        reinterpret_cast<uint16_t>(&slider_3.setpoint), \
        reinterpret_cast<uint16_t>(&slider_4.setpoint), \
        reinterpret_cast<uint16_t>(&slider_1.analog_value), \
        reinterpret_cast<uint16_t>(&slider_2.analog_value), \
        reinterpret_cast<uint16_t>(&slider_3.analog_value), \
        reinterpret_cast<uint16_t>(&slider_4.analog_value), \
        reinterpret_cast<uint16_t>(&slider_1.active), \
        reinterpret_cast<uint16_t>(&slider_2.active), \
        reinterpret_cast<uint16_t>(&slider_3.active), \
        reinterpret_cast<uint16_t>(&slider_4.active) \
    };
    for (int i = 0; i < 12; i++)
    {
        register_buffer[2*i] = addr[i] >> 8;
        register_buffer[2*i + 1] = addr[i];
    }
}

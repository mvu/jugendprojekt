#include <Ethernet.h>
#include <EthernetUdp.h>

#include "temperatur_sensor.h"

byte mac[] = { 0xAA, 0xE5, 0xCe, 0xC4, 0x4F, 0xF0};
IPAddress ip(192, 168, 188, 202);
unsigned int local_port = 9999;

uint8_t packet_buffer[UDP_TX_PACKET_MAX_SIZE];
uint8_t reply_buffer[UDP_TX_PACKET_MAX_SIZE];
uint8_t register_buffer[12];    // holds the adresses to read the temperatures from

EthernetUDP udp;

TemperaturSensor t0(A0, 0.0193, 6.9300, 819, 10, 200);
TemperaturSensor t1(A1, 0.0200, 6.9200, 821, 10, 200);
TemperaturSensor t2(A2, 0.0203, 6.8400, 824, 10, 200);
TemperaturSensor t3(A3, 0.0206, 6.9200, 825, 10, 200);
TemperaturSensor t4(A4, 0.0187, 6.8700, 824, 10, 200);
TemperaturSensor t5(A5, 0.0201, 6.7300, 821, 10, 200);

void setup() {
    Serial.begin(115200);

    // Nice Serial Output on boot
    Serial.println("Temperatur Interface via UDP, version 2.0");
    Serial.println("Initializing...");

    // set up Ethernet
    Ethernet.begin(mac, ip);
    udp.begin(local_port);
    // create a packet with all available registers
    createRegisterSummary();
    Serial.print("\tEthernet ready on "); for (int i = 0; i < 4; i++) {Serial.print(ip[i], DEC); if (i < 3) Serial.print(".");}; Serial.print(":"); Serial.println(local_port, DEC);

    // report initialization of sensors and corresponding registers
    Serial.println("\tSensors ready");
    Serial.println("Intialization completed.\n");
    Serial.println("Read temperatures from the following addresses:");
    Serial.print("\tT0 -> "); Serial.println(reinterpret_cast<int>(&t0.temp), DEC);
    Serial.print("\tT1 -> "); Serial.println(reinterpret_cast<int>(&t1.temp), DEC);
    Serial.print("\tT2 -> "); Serial.println(reinterpret_cast<int>(&t2.temp), DEC);
    Serial.print("\tT3 -> "); Serial.println(reinterpret_cast<int>(&t3.temp), DEC);
    Serial.print("\tT4 -> "); Serial.println(reinterpret_cast<int>(&t4.temp), DEC);
    Serial.print("\tT5 -> "); Serial.println(reinterpret_cast<int>(&t5.temp), DEC);
}

void createRegisterSummary()
{
    uint16_t addr[6] = { \
        reinterpret_cast<uint16_t>(&t0.temp),\
        reinterpret_cast<uint16_t>(&t1.temp),\
        reinterpret_cast<uint16_t>(&t2.temp),\
        reinterpret_cast<uint16_t>(&t3.temp),\
        reinterpret_cast<uint16_t>(&t4.temp),\
        reinterpret_cast<uint16_t>(&t5.temp)\
    };
    for (int i = 0; i < 6; i++)
    {
        register_buffer[2*i] = addr[i] >> 8;
        register_buffer[2*i + 1] = addr[i];
    }
}

void loop() {
    t0.update();
    t1.update();
    t2.update();
    t3.update();
    t4.update();
    t5.update();

    handleUDP();
}

void handleUDP()
{
    /*
    * Read a packet if available and determine action based upon size of packet:
    *   -> 1 byte : report addresses
    *   -> 2 bytes: return content of register
    */
    int packet_size = udp.parsePacket();
    if (packet_size)
    {
        udp.read(packet_buffer, UDP_TX_PACKET_MAX_SIZE);
        if (packet_size == 1)
        {
            Serial.println("request for addresses");
            udp.beginPacket(udp.remoteIP(), udp.remotePort());
            udp.write(register_buffer, 12);
            udp.endPacket();
        }
        else if (packet_size == 2)
        {
            Serial.print("request for temp\n\t-> ");
            Serial.write(packet_buffer, 24);
            Serial.print("\n");
            uint16_t reg = (packet_buffer[0] << 8) + packet_buffer[1];
            double val = *reinterpret_cast<double* >(reg);
            int raw_buffer_size = sizeof(val);
            uint8_t raw_buffer[raw_buffer_size];
            memcpy(raw_buffer, &val, raw_buffer_size);
            udp.beginPacket(udp.remoteIP(), udp.remotePort());
            udp.write(raw_buffer, raw_buffer_size);
            udp.endPacket();
        }
    }
}

// uncomment below to read registers via serialPort
// note: Serial.parseInt is really slow!

void serialEvent()
{
    int addr = Serial.parseInt();
    Serial.println(int(*(reinterpret_cast<double* >(addr))));
}

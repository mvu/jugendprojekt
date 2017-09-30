#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include "wiring_private.h"
#include "pins_arduino.h"

const int SENSOR[6] = {A0, A1, A2, A3, A4, A5};
const float a[6] = {0.0193, 0.0200, 0.0203, 0.0206, 0.0187, 0.0201};
const float b[6] = {6.9300, 6.9200, 6.8400, 6.9200, 6.8700, 6.7300};
const int c[6] = {819, 821, 824, 825, 824, 821};
float aktuelle_Temperatur[] = { 0.,0.,0.,0.,0.,0. };

const byte mac[] = {0x90, 0xA2, 0xDA, 0x10, 0xBA, 0xE8};
IPAddress ip(192, 168, 188, 250);

unsigned int localPort = 8888;

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];  //buffer to hold incoming packet,
//char ReplyBuffer[];                         //a string to send back

void sendData(float data);
//float getTemp(int sensor);

EthernetUDP Udp;

void setup()
{
  // start the Ethernet and UDP:
  Ethernet.begin(mac, ip);
  Udp.begin(localPort);

  //Serial.begin(19200);
}

void loop() 
{
  // if there's data available, read a packet
	read_all_temp();
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    /*
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remote = Udp.remoteIP();
    for (int i = 0; i < 4; i++) {
      Serial.print(remote[i], DEC);
      if (i < 3) {
        Serial.print(".");
      }
    }
    Serial.print(", port ");
    Serial.println(Udp.remotePort());
    */
    // read the packet into packetBuffer
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    //Serial.print("Contents: ");
    //Serial.println(packetBuffer);

    int request = atoi(packetBuffer);
    //Serial.print("requested Sensor ");
    //Serial.println(request);
    if ((request >= 0) && (request < 6))
    {
      sendData(aktuelle_Temperatur[request]);
    }
    else if (request == 7)
    {
      for (int i = 0; i < 6; i++)
      {
        //unsigned long ms1 = micros();
        sendData(aktuelle_Temperatur[i]);
		//Serial.println(aktuelle_Temperatur[i]);
        //unsigned long ms2 = micros();
        //Serial.print("Time for reading temperature in µs: ");
        //Serial.println(ms2-ms1);
      }
    }
  }
}

void sendData(float data){
  //Serial.print(data);
  //Serial.println(" to send\nstart conversion to Buffer");
  char Buffer[5];
  dtostrf(data, 5, 1, Buffer);
  //Serial.print("Send Buffer = ");
  //Serial.println(Buffer);
  Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
  Udp.write(Buffer);
  Udp.endPacket();
  delayMicroseconds(100);
}

void read_all_temp(){
	for (int i = 0; i < 6; i++) {
		int AD = analogRead(SENSOR[i]);
		AD = max(min(AD, 1000),100);
		//delayMicroseconds(200);
		//Serial.print(i);
		//Serial.println(AD);
		float rT = 2700.0 * float(AD) / (1024.0 - float(AD));
		float e = -b[i] / (2.0*a[i]) + sqrt(1.0 / a[i] * (b[i] * b[i] / (a[i] * 4.0) + rT - c[i]));
		aktuelle_Temperatur[i] = e;
		//aktuelle_Temperatur[i] = rT;
		//delayMicroseconds(200);
		//Serial.println(aktuelle_Temperatur[i]);
		//Serial.print(i);
	}
  //unsigned long ms2 = micros();
  /*
  Serial.print("Requested Sensor: ");
  Serial.println(sensor);
  Serial.print("Sensor AD: ");
  Serial.println(AD);
  Serial.print("Sensor R: ");
  Serial.println(rT);
  Serial.print("Sensor Temp: ");
  Serial.println(T);
  Serial.print("Time for reading temperature in µs: ");
  Serial.println(ms2-ms1);
  */
  return;
}


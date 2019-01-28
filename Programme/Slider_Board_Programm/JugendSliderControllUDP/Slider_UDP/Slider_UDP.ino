/*
 Name:		Slider_UDP.ino
 Created:	16.02.2018 15:21:43
 Author:	Martin
*/

#include <AFMotor.h>
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <string.h>

#define adSlider1 A0
#define adSlider2 A1
#define adSlider3 A2
#define adSlider4 A3
#define udpPort 4506

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEf };
IPAddress ip(192, 168, 188, 251);									//  in der Fritzbox Jugend hinterlegt
IPAddress gateway(192, 168, 188, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress RecipientIP(192, 168, 188, 1);

unsigned int localPort = 8888;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
int arraySlider[4], arraySliderOld[4], arraySliderValue[4];
char arrayAd[] = { A0, A1, A2, A3 };
int wireValue, slider = 0, slider1 = 0 , slider2 = 0 , slider3 = 0 , slider4 = 0;
int a;


EthernetUDP Udp;

// Motor configurieren

AF_DCMotor mSlider1(1, MOTOR12_1KHZ);
AF_DCMotor mSlider2(2, MOTOR12_1KHZ);
AF_DCMotor mSlider3(3, MOTOR12_1KHZ);
AF_DCMotor mSlider4(4, MOTOR12_1KHZ);

void setup() {

	pinMode(adSlider1, INPUT);					// Sider A/D wert abfrage A0 = Slider1
	pinMode(adSlider2, INPUT);
	pinMode(adSlider3, INPUT);
	pinMode(adSlider4, INPUT);

	mSlider1.run(RELEASE);						// Alle Slider Motoren loslassen ( freigeben zum bewegen)
	mSlider2.run(RELEASE);
	mSlider3.run(RELEASE);
	mSlider4.run(RELEASE);

	Serial.begin(115200);
	Ethernet.begin(mac, ip);
	Udp.begin(localPort);

	for (size_t i = 0; i < 5; i++){				// Slider Arry auf Null setzten;
		arraySlider[i] = 0;
	}

	delay(10);
	Serial.println("Slider Controllpanal Version 2.1");

	mSlider1.run(BACKWARD);
	mSlider1.setSpeed(160);
	mSlider2.run(BACKWARD);
	mSlider2.setSpeed(160);
	mSlider3.run(BACKWARD);
	mSlider3.setSpeed(160);
	mSlider4.run(BACKWARD);
	mSlider4.setSpeed(160);

	while (true)
	{
		Serial.println(slider2);
		if (slider1 == 0) if (analogRead(adSlider1) >= 1020) { slider1 = 1; mSlider1.run(RELEASE); };
		if (slider2 == 0) if (analogRead(adSlider2) >= 1020) { slider2 = 1; mSlider2.run(RELEASE); };
		if (slider3 == 0) if (analogRead(adSlider3) >= 1020) { slider3 = 1; mSlider3.run(RELEASE); };
		if (slider4 == 0) if (analogRead(adSlider4) >= 1020) { slider4 = 1; mSlider4.run(RELEASE); };
		if (slider1 == 1 && slider2 == 1 && slider3 == 1 && slider4 == 1) break;
	}

	Serial.println("Intialization completed.\n");
	Serial.println("Use the following addresses to move the sliders:");
	for (int i = 0; i < 4; i++) {
		Serial.print('\tSlider ' + i + ' -> '); Serial.println(reinterpret_cast<int>(&arraySlider[i]), HEX);
	}
}

// the loop function runs over and over again until power down or reset
void loop() {

	// checkUDP();

	if (Serial.available() > 0) {
		int i = 0;
	}

	for (size_t a = 0; a < 4; a++)
	{
		int read = analogRead(arrayAd[a]);
		read += analogRead(arrayAd[a]);
		read += analogRead(arrayAd[a]);
		read += analogRead(arrayAd[a]);
		arraySliderValue[a] = read / 4;
	}


	for (size_t i = 0; i < 4; i++)
	{
		if (arraySlider[i] != arraySliderOld[i]) {
			Serial.println("Set Slider");
			int valPoti = analogRead(arrayAd[i]);
			if (abs(valPoti - arraySlider[i]) > 20) {
				switch (i)
				{
				case 0:
					if (valPoti > arraySlider[i])mSlider1.run(FORWARD);
					else mSlider1.run(BACKWARD);
					mSlider1.setSpeed(max(min(abs(valPoti - arraySlider[i]), 200), 140));
					if (abs(arraySlider[i] - arraySliderValue[i]) < 40) {
						mSlider1.setSpeed(0);
						mSlider1.run(RELEASE);
						arraySliderOld[i] = arraySlider[i];
					}
					break;
				case 1:
					if (valPoti > arraySlider[i])mSlider2.run(FORWARD);
					else mSlider2.run(BACKWARD);
					mSlider2.setSpeed(max(min(abs(valPoti - arraySlider[i]), 200), 140));
					if (abs(arraySlider[i] - arraySliderValue[i]) < 40) {
						mSlider2.setSpeed(0);
						mSlider2.run(RELEASE);
						arraySliderOld[i] = arraySlider[i];
					}
					break;
				case 2:
					if (valPoti > arraySlider[i]) mSlider3.run(FORWARD);
					else mSlider3.run(BACKWARD);
					mSlider3.setSpeed(max(min(abs(valPoti - arraySlider[i]), 200), 140));
					if (abs(arraySlider[i] - arraySliderValue[i]) < 40) {
						mSlider3.setSpeed(0);
						mSlider3.run(RELEASE);
						arraySliderOld[i] = arraySlider[i];
					}
					break;
				case 3:
					Serial.println("case4");
					if (valPoti > arraySlider[i])mSlider4.run(FORWARD);
					else mSlider4.run(BACKWARD);
					mSlider4.setSpeed(max(min(abs(valPoti - arraySlider[i]), 200), 140));
					if (abs(arraySlider[i] - arraySliderValue[i]) < 40) {
						mSlider4.setSpeed(0);
						mSlider4.run(RELEASE);
						arraySliderOld[i] = arraySlider[i];
					}
					break;
				default:
					break;
				}
			}
		}
	}
}

// void checkUDP() {
// 	if (Udp.parsePacket()) {
// 		Serial.print("data received: ");
// 		Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
// 		Serial.println(packetBuffer);
// 		Serial.println(sizeof(packetBuffer)/sizeof(packetBuffer[0]));
// 		char Sliderwahl = packetBuffer[0];
// 		Serial.println(Sliderwahl);
// 		packetBuffer[0] = 0;
// 		packetBuffer[4] = 0;
// 		int val = atoi(packetBuffer);
// 		Serial.println(val);
// 		val = max(min(val,100), 0);
// 		if (val < 1) {
// 			switch (Sliderwahl)
// 			{
// 			case'A':
// 				Udp.print(arraySliderValue[0]);
// 				Udp.endPacket();
// 				break;
// 			case'B':
// 				Udp.print(arraySliderValue[1]);
// 				Udp.endPacket();
// 				break;
// 			case'C':
// 				Udp.print(arraySliderValue[2]);
// 				Udp.endPacket();
// 				break;
// 			case'D':
// 				Udp.print(arraySliderValue[3]);
// 				Udp.endPacket();
// 				break;
// 			default:
// 				break;
// 			}
// 		}
// 		else if (val == 1){
// 			switch (Sliderwahl)
// 			{
// 			case 'A':
// 				arraySlider[0] = 0;
// 				break;
//
// 			case 'B':
// 				arraySlider[1] = 0;
// 				break;
//
// 			case 'C':
// 				arraySlider[2] = 0;
// 				break;
//
// 			case 'D':
// 				arraySlider[3] = 0;
// 				break;
// 			default:
// 				break;
// 			}
// 		}
// 		else {
// 			switch (Sliderwahl)
// 			{
// 			case 'A':
// 				arraySliderValue[0] = val;
// 				break;
//
// 			case 'B':
// 				arraySliderValue[1] = val;
// 				break;
//
// 			case 'C':
// 				arraySliderValue[2] = val;
// 				break;
//
// 			case 'D':
// 				arraySliderValue[3] = val;
// 				break;
// 			default:
// 				break;
// 			}
// 		}
//
// 	}
// }

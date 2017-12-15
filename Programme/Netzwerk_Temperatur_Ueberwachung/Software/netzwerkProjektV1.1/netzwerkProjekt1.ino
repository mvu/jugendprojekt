/*
 Name:		netzwerkProjekt.ino
 Created:	10.05.2017 08:26:00
 Author:	Martin
*/

// the setup function runs once when you press reset or power the board

// Version 1.1
//änderung zu 1.0 
// Temperatur messung wird dauerhaft durchgeführt und mittelwert aus beiden messungen wird im array abgespeichert.
// Bei anfrage auf Temperatur kann sofort geantwortet werden ohne vorher die messung durch zu führen.

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <string.h>

#define udpPort 4505

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,188,250);									//  in der Fritzbox Jugend hinterlegt
IPAddress gateway(192, 168, 188, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress RecipientIP(192, 168, 188, 1);
unsigned int localPort = 8888;

EthernetUDP Udp;

char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
char arrayad[] = { A0, A1, A2, A3, A4, A5 };
int arrayAdValue[] = { 0,0,0,0,0,0 };

void setup() {
	Ethernet.begin(mac, ip);
	Udp.begin(localPort);
	Serial.begin(9600);
	Serial.println("Run:");
}

// the loop function runs over and over again until power down or reset
void loop() {
	checkUDP();
	tempMessung();
	/*
	int packetsice = Udp.parsePacket();
	if (packetsice) {
		Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
		Serial.println(packetBuffer);
	}*/
	//Udp.beginPacket(("192.168.1.115"), 8889);
	//Udp.write("Hello");
}

void checkUDP()
{
	int auswahl = 0;			// Hilfs Merker für ad messung
	
	int packetSize = Udp.parsePacket();								// if there's data available, read a packet
	if (packetSize)
	{
		// read the packet into packetBufffer
		Serial.println("Packet udp");
		Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);				// Auslesen des Buffers mit Max 24 zeichen
		int i = atoi(packetBuffer);
		Serial.println(i);
		switch (i)									// Buffer umwandeln in Int 
		{
		case 101:
			if (Udp.beginPacket(Udp.remoteIP(), udpPort)) {			// Start vom Sender Packet mit Empfangener IP und Port 
				//Udp.write(adMessung());
				Udp.print(arrayAdValue[0]);							// Print für Int für char write
				Udp.endPacket();									// Ende des Packets
				//Serial.print("Gesendet");
				Serial.println(arrayAdValue[0]);
			}
			else
				Serial.println("Fail to connect Clint");			
			break;
		case 102:
			if (Udp.beginPacket(Udp.remoteIP(), udpPort)) {
				//Udp.write(adMessung());
				Udp.print(arrayAdValue[1]);
				Udp.endPacket();
				//Serial.print("Gesendet");
				Serial.println(arrayAdValue[1]);
			}
			else
				Serial.println("Fail to connect Clint");
			break;
		case 103:
			if (Udp.beginPacket(Udp.remoteIP(), udpPort)) {
				//Udp.write(adMessung());
				Udp.print(arrayAdValue[2]);
				Udp.endPacket();
				//Serial.print("Gesendet");
				//Serial.println(adMessung(2));
			}
			else
				Serial.println("Fail to connect Clint");
			break;
		case 104:
			if (Udp.beginPacket(Udp.remoteIP(), udpPort)) {
				//Udp.write(adMessung());
				Udp.print(arrayAdValue[3]);
				Udp.endPacket();
				//Serial.print("Gesendet");
				//Serial.println(adMessung(3));
			}
			else
				Serial.println("Fail to connect Clint");
			break;
		case 105:
			if (Udp.beginPacket(Udp.remoteIP(), udpPort)) {
				//Udp.write(adMessung());
				Udp.print(arrayAdValue[4]);
				Udp.endPacket();
				//Serial.print("Gesendet");
				//Serial.println(adMessung(4));
			}
			else
				Serial.println("Fail to connect Clint");
			break;
		case 106:
			if (Udp.beginPacket(Udp.remoteIP(), udpPort)) {
				//Udp.write(adMessung());
				Udp.print(arrayAdValue[5]);
				Udp.endPacket();
				//Serial.print("Gesendet");
				//Serial.println(adMessung(5));
			}
			else
				Serial.println("Fail to connect Clint");
			break;
		case 7:
			if (Udp.beginPacket(Udp.remoteIP(), udpPort)) {
				//Udp.write(adMessung());
				Udp.print(arrayAdValue[0]);
				Udp.endPacket();
				Serial.print("Gesendet");
				//Serial.println(adMessung(5));
			}
			else
				Serial.println("Fail to connect Clint");

		default:
			if (Udp.beginPacket(Udp.remoteIP(), udpPort)) {				// Ist der Eingegangen wert auserhalb des Messbereiches wird ein -1 zurück gesendet
				//Udp.write(adMessung());
				Udp.print(-1);
				Udp.endPacket();
			}
			else
				Serial.println("Fail to connect Clint");
			break;
		}
	}
}

int adMessung(int val) {
	//delay(500);
	//int i = ((analogRead(A0) / 1.579) - 150) * 10;

	/*
	Auslesen des AD Wertes 
	Der ADC des Atmel misst (ohne besondere Maßnahmen) externe Spannungen mit einer Auflösung von 4,883 mV/digit. 
	Eine Änderung der Eingangsspannung um 4,883 mV verändert den vom ADC ausgegebenen Zahlenwert also um 1.
	Aus diesen beiden Zahlen ergibt sich, dass die Änderung des ADC-Ergebnisses um 1 einer Temperaturveränderung
	um 0,633 Grad entspricht. Deshalb ist es nötig, das ADC-Ergebnis im Atmel durch den Korrekturwert 1,579 zu dividieren
	(oder mit 0,633 zu multiplizieren), um ein Ergebnis zu erhalten, das sich bei einer 
	Temperaturveränderung um 1 Grad um den Wert 1 ändert.
	Da ein Float wert rauskommt muss das Komma noch um zwei stellen verschoben werden.
	*/

	return ((analogRead(arrayad[val]) / 1.579) - 150) * 100;		
}


 void tempMessung() {
	 for (int i = 0; i < 6; i++) {
		 arrayAdValue[i] = (adMessung(i) + adMessung(i) + arrayAdValue[i]) / 3;
		 //Serial.println(arrayAdValue[i]);
	 }
	 return;
}
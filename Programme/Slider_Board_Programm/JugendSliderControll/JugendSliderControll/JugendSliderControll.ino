/*
 Name:		JugendSliderControll.ino
 Created:	16.04.2017 16:09:39
 Author:	Martin Laptop
 Version	V2.0

 Neu aufbau der Slider rotine.
 Verbesserung: 
 Schneller Slider anfahrt bewegung 
 Weniger Fehler beim anfahren von sollwert. 
 Auslese Genauigkeit verbessert durch 4 mal auslesen des AD wertes dann erst Senden


 Ablauf:
 Die Main loop kontrolliert zyklisch ob die Slider postition der Werten entspricht die im Array Slider drinnen steht. Wenn dies erreicht wurde werden die Motoren frei gegeben und erst wieder 
 geändert wenn über I2C das Array geändert wurde.
 Wenn über I2C neue Slider werte kommen wird nur das Array geändert und keine Funktion aufgerufen.
 Beim lesen der Aktuellen Postion wird 4 mal ein AD wert aufgenommen und davon ein Mittelwert erstellt und dieser wird dann gesendet
*/


#include <Wire.h>
#include <AFMotor.h>

#define adSlider1 A0
#define adSlider2 A1
#define adSlider3 A2
#define adSlider4 A3
#define i2cAdresse 0x0E

int arraySlider[4];
int arraySliderOld[4];
char arrayAd[] = { A0, A1, A2, A3 };
int arraySliderValue[4];
int wireValue;
int slider, slider1, slider2, slider3, slider4;
int a;

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

	Wire.begin(i2cAdresse);						// I2C Adresse festlegen 
	Wire.onReceive(interruptSet);				// Aufruf der Funktion beim Empfang von Daten
	Wire.onRequest(interruptGet);				// Aufruf der Funktion beim Senden von Daten


	for (size_t i = 0; i < 5; i++)				// Slider Arry auf Null setzten;
	{
		arraySlider[i] = 0;
	}

	Serial.begin(115200);
	delay(10);
	Serial.println("Slider Controllpanal V2.0");
	mSlider1.run(BACKWARD);
	mSlider1.setSpeed(160);
	mSlider2.run(BACKWARD);
	mSlider2.setSpeed(160);
	mSlider3.run(BACKWARD);
	mSlider3.setSpeed(160);
	mSlider4.run(BACKWARD);
	mSlider4.setSpeed(160);
	slider1 = 0;
	slider2 = 0;
	slider3 = 0;
	slider4 = 0;

	while (true)
	{
		if (slider1 == 0)if (analogRead(adSlider1) >= 1020) {slider1 = 1; mSlider1.run(RELEASE);};
		if (slider2 == 0)if (analogRead(adSlider2) >= 1020) {slider2 = 1; mSlider2.run(RELEASE);};
		if (slider3 == 0)if (analogRead(adSlider3) >= 1020) {slider3 = 1; mSlider3.run(RELEASE);};
		if (slider4 == 0)if (analogRead(adSlider4) >= 1020) {slider4 = 1; mSlider4.run(RELEASE);};
		if (slider1 == 1 && slider2 == 1 && slider3 == 1 && slider4 == 1) break;
	}


}

// the loop function runs over and over again until power down or reset
void loop() {
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

void interruptSet(int byteCount) {
	if (Wire.available())
	{
		slider = Wire.read();
		int i = Wire.read();
		
		if (i >= 0) {
			i = max(min(i, 100), 1);
			arraySlider[slider] = 1024 - (float(10.24) * float(i));
			Serial.println(arraySlider[slider]);
		}
		//Serial.print("Slider ad:");
		//Serial.println(slider);
		//Serial.print("Slider Value:");
		//Serial.println(arraySlider[slider]);
	}
}

void interruptGet() {
	Serial.print("Silder abfrage:");
	Serial.println(slider);
	int i = Wire.read();
	Wire.write(100 - (max(min((arraySliderValue[slider] / 10), 100), 1)));
	//Serial.print("Send:");
	//Serial.println(arraySliderValue[slider]);
	Wire.read();
	Wire.clearWriteError();
}

void sliderSet(int num, int Val) {

}

void sliderGet() {

}
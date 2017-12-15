#define Rout 9
#define Gout 6
#define Bout 5
#define DIR 10

const int8_t addr0 = 3;
const int8_t addr1 = 102;
const int8_t addr2 = 120;

int rgb_Rot = 0;
int rgb_Blau = 0;
int rgb_gruen = 0;
int rgb_addr = 0;
int rgb_Info = 0;
int i;
int a;
int info;

void setup() {
  pinMode(Rout, OUTPUT);
  pinMode(Gout, OUTPUT);
  pinMode(Bout, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(DIR, LOW); //listen on UART
  analogWrite(Rout, 0);
  analogWrite(Gout, 0);
  analogWrite(Bout, 0);
  digitalWrite(13, HIGH);
  //digitalWrite(9,HIGH);
  Serial.begin(115200);
  //Serial2.begin(115200);
}

void loop() {
    if (Serial.available() > 3) {
		//Serial.println("Vier byte erhalten START !!!!!!!!!!!");
		//temp = Serial.read();
		rgb_Info = Serial.read();				// Auslesen aller 4 Byte 


		//info = rgb_Info & B10000000;
		if (rgb_Info & B10000000 >= 78)	// wenn info 
		{
			rgb_addr = rgb_Info & B01111111;
			//Serial.print("Read Addresse:");
			//Serial.println(rgb_addr);
  
			if ((rgb_addr == addr0) || (rgb_addr == addr1) || (rgb_addr == addr2)) {
        digitalWrite(13,LOW);
        rgb_Rot = Serial.read();
        rgb_gruen = Serial.read();
        rgb_Blau = Serial.read();
				if (rgb_Rot & 0B10000000 >  2)analogWrite(Rout, rgb_Rot << 1);
				if (rgb_gruen & 0B10000000 >  2)analogWrite(Gout, rgb_gruen << 1);
				if (rgb_Blau & 0B10000000 >  2)analogWrite(Bout, rgb_Blau << 1);
			}
			else
			{
				while(Serial.available())
				{
					//Serial.println("Buffer leeren nach falscher addresse");
					a = Serial.read();
				}
			}
		}
		else {
			// rest l�schen
			//Serial.println("erste Packet keine Addresse");
			while (Serial.available())
			{				
				a = Serial.read();
			}
			//Serial.println("back to loop");
			//i++;
			//Serial.println(i);
		}
  }
}
/*

void write_RGB() {

	int a;
	rgb_addr = rgb_Info & B01111111;
	//Serial.print("Read Addresse:");
	//Serial.println(rgb_addr);
	if ((rgb_addr == addr0) || (rgb_addr == addr1) || (rgb_addr == addr2)) {
		rgb_Rot = Serial2.read();
		rgb_gruen = Serial2.read();
		rgb_Blau = Serial2.read();
		analogWrite(Rout, rgb_Rot << 1);
		analogWrite(Gout, rgb_gruen << 1);
		analogWrite(Bout, rgb_Blau << 1);
	}
	else
	{
		for (size_t i = 0; i < 3; i++)
		{
			//Serial.println("Buffer leeren nach falscher addresse");
			a = Serial2.read();
		}
	}
	//Serial.println("back to loop");
	loop();
}
*/

#define Rout 9
#define Gout 6
#define Bout 5
#define DIR 10

const byte addr0 = 12 + 128;   //einzel 
const byte addr1 = 106 + 128; //doppel
const byte addr2 = 120 + 128; //alle

byte serialData1 = 0;
byte serialData2 = 0;
byte serialData3 = 0;
byte serialData4 = 0;

void setup() {
  pinMode(Rout, OUTPUT);
  pinMode(Gout, OUTPUT);
  pinMode(Bout, OUTPUT);
  pinMode(DIR, OUTPUT);

  digitalWrite(DIR, LOW); //listen on UART
  analogWrite(Rout, 0);
  analogWrite(Gout, 0);
  analogWrite(Bout, 0);
  
  Serial.begin(115200);
}

void loop() {
  analogWrite(Rout, serialData2 << 1);
  analogWrite(Gout, serialData3 << 1);
  analogWrite(Bout, serialData4 << 1);
  
}

void serialEvent() {
  serialData1 = Serial.read();
  if (serialData1 == addr0) {
    while(Serial.available() < 3){
      //nop;
    }
    serialData2 = Serial.read();
    serialData3 = Serial.read();
    serialData4 = Serial.read();
    //break;
  }
   else if (serialData1 == addr1) {
    while(Serial.available() < 3){
      //nop;
    }
    serialData2 = Serial.read();
    serialData3 = Serial.read();
    serialData4 = Serial.read();
      //break;
  }
  else if (serialData1 == addr2) {
    while(Serial.available() < 3){
      //nop;
    }
    serialData2 = Serial.read();
    serialData3 = Serial.read();
    serialData4 = Serial.read();
  }
}

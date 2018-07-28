//default values
int freq = 100;
int pwm = 50;

int f_corr = 1;

void serialEvent(){
	delay(100);
	int n = Serial.available();
	char in_buf[n-1];

	char com = Serial.read();
	for (int i = 0; i < n-1; i++){
		in_buf[i] = Serial.read();
	}
	int arg = atoi(in_buf);

	switch (com){
		case 'f':
			//set frequency in kHz
			(arg > 62) ? freq = arg : freq = 63;
			break;
		case 'd':
			pwm = arg;
			break;
	}
	int compA = 16000 / freq - f_corr;
	int compB = compA * float(pwm)/100.;
	uint8_t tccr2b_tmp;
	(pwm > 0) ? tccr2b_tmp = TCCR2B | 0x01 : tccr2b_tmp = TCCR2B & 0xFE;
	
	noInterrupts();
	TCCR2B = tccr2b_tmp;
	OCR2A = compA;
	OCR2B = compB;
	interrupts();
	
	Serial.print("f = ");
	Serial.print(freq);
	Serial.print("kHz @ ");
	Serial.print(pwm);
	Serial.println(" % Duty");
}

void setup() {
	Serial.begin(19200);
	DDRB = 0xff;
	DDRD = 0xff;

	int compA = 16000 / freq - f_corr;
	int compB = compA * float(pwm)/100.;
	
	noInterrupts();
	TCCR2A = _BV(WGM21) | _BV(WGM20) | _BV(COM2B1);
	TCCR2B = _BV(CS20) | _BV(WGM22);
	TCNT2  = 0x00;

	OCR2A = compA;
	OCR2B = compB;
	interrupts();
}

void loop() {
	//nop
}

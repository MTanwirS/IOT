int led = 13;
int ldr = A0;
int ldrStatus ;
void setup() {

	Serial.begin(9600);
	pinMode(led, OUTPUT);
	pinMode(ldr, INPUT);
	ldrStatus = 1000 ;
}

void loop() {

	ldrStatus = analogRead(ldr);
  
	if (ldrStatus <= 300) {
		digitalWrite(led,HIGH);
		Serial.print(" LED on , It's Dark : ");
		Serial.println(ldrStatus);
	} 
  	else {
		digitalWrite(led,LOW);
		Serial.print("LED off, It's Bright : ");
		Serial.println(ldrStatus);
	}
}
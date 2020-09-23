void setup()
{
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop()
{
	int analog = analogRead(A0);
  int br = map(analog,0,1023,0,255);
  analogWrite(9,br);
  Serial.println((String)"Analog: "+analog+ "Brightness : " +br);
  delay(500);
}
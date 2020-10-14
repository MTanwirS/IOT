int sensor = A0;
int led = 13 ;
int val ;
int threshold = 100 ;

void setup()
{
	Serial.begin(9600); 
}

void loop()
{ 
  val = analogRead(sensor);
	Serial.println( val);
  if(val>threshold){
  	digitalWrite(led,HIGH);
  }
  else {
  digitalWrite(led,LOW);
  }
	delay(500); 
}

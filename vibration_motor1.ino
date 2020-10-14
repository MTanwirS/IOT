int sensorPin = A0 ;
int threshold = 400 ;
int motorPin = 3 ;

void setup ()
{
	Serial.begin(9600);
  	pinMode(motorPin,OUTPUT);
}

void loop()
{	
  	int value = analogRead(sensorPin);
  	Serial.println(value);
  	if(value > threshold)
    {
    	digitalWrite(motorPin, HIGH);
    }
  else
  	{
    	digitalWrite(motorPin , LOW);    
	}

}
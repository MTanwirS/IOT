#include <Servo.h>

int servom = 3 ;
Servo motor;
int sensor = A0 ;

void setup()
{
  Serial.begin(9600);
  pinMode(servom, OUTPUT);
  motor.attach(servom);
}

void loop()
{
	int analog = analogRead(sensor);
  	int pos = map(analog,0,1023,0,255);
    motor.write(pos);
    delay(50);
 	Serial.println((String)"Sensor: "+analog+ "Moisture : " +pos);
 	delay(500);
}
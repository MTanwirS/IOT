int led = 13;
int sensor = 2;

void setup()
{
   pinMode (led,OUTPUT);
   pinMode (sensor,INPUT);
   Serial.begin(9600);
}

void loop()
{
  int val = digitalRead(sensor);
  Serial.println(val) ;
  if (val == HIGH) 
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  delay(500);
  
}

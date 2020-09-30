int buzzer = 12;
int pir = 8;
int led = 13;
void setup() 
{
  pinMode(buzzer, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(pir,LOW);
  Serial.begin(9600);

}

void loop() 
{
  if(digitalRead(pir)==HIGH)
  {
   digitalWrite(led,HIGH);
   Serial.println("Motion detected");
    while(digitalRead(pir)==HIGH){
    	digitalWrite(buzzer,HIGH);
   		delay(1000);
   		digitalWrite(buzzer,LOW); 
    }
  }
  else {
    Serial.println("NO motion detected");
  	digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW); 
  }

}
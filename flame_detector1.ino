int led = 13 ;
int buzzer = 12;
int sensor = A0 ;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
   int temp = analogRead(sensor);
 	temp = (temp * 0.4854369) - 49.271845 ;
   Serial.println((String)"TEMPERATURE = "+temp+" *C ");
  	
  if(temp > 50)
  {
      while(temp>50)
      {
  		digitalWrite(led, HIGH);
    	digitalWrite(buzzer,HIGH);
    	delay(1000);
    	digitalWrite(led, LOW);
    	digitalWrite(buzzer,LOW);
        temp = analogRead(sensor);
       temp = (temp * 0.4854369) - 49.271845 ;
      }
  }
   delay(1000); 
}
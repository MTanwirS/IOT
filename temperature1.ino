float temp;
int sensor = A0;

void setup() {
   Serial.begin(9600);
}

void loop() {
   temp = analogRead(sensor);
 	temp = (temp * 0.4854369) - 49.271845 ;
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); 
   Serial.print("*C / ");
   Serial.print(((temp*9)/5)+32);
  	Serial.print("*F\n");
   delay(1000); 
}
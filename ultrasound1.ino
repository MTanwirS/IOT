int signalpin = 12 ;
int echopin = 8 ;
int buzzer = 7 ;

void setup(){
  
	Serial.begin(9600);
	pinMode(signalpin, OUTPUT);
  	pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);
  
}

void loop(){
	//output signal pulse
  digitalWrite(signalpin, LOW);
  delayMicroseconds(2);
  digitalWrite(signalpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(signalpin,LOW);
  
  float distance = pulseIn(echopin , HIGH);
	distance = (distance/2)*0.0349 ;
  Serial.println((String)" Distance = "+distance+" cm.");
  
  if (distance <50){
  	digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
}
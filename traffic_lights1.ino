int r = 4 , rdelay = 7500;
int y = 3 , ydelay = 2500;
int g = 2 , gdelay = 5000;

void red(){
  digitalWrite(r,HIGH);
  digitalWrite(y,LOW);
  digitalWrite(g,LOW);
}

void yellow(){
  digitalWrite(y,HIGH);
  digitalWrite(r,LOW);
  digitalWrite(g,LOW);
}

void green(){
  digitalWrite(g,HIGH);
  digitalWrite(y,LOW);
  digitalWrite(r,LOW);
}


void setup(){
	pinMode(r, OUTPUT);
	pinMode(y, OUTPUT);
  	pinMode(g, OUTPUT);
}

void loop(){
	red();
  	delay(rdelay);
  	yellow();
  	delay(ydelay);
  	green();
  	delay(gdelay);
    yellow();
  	delay(ydelay);
}


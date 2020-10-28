#include <IRremote.h>
#include <Servo.h>

int pos = 0;
int irsensor = 9;
Servo smotor;
IRrecv irinput(irsensor);
decode_results results ;
int val = 1 ;
int flag = 0 ;

void setup()
{	
  	Serial.begin(9600);
  	pinMode(irsensor, INPUT);
  	irinput.enableIRIn();
	Serial.println("Power is off");
}

void pwr ()
{
 	if (flag == 0)
    {
    	smotor.attach(11);
      	Serial.println("Power on");
        flag = 1 ;
    }
  	else if (flag == 1)
    {
    	smotor.detach();
        Serial.println("Power off");
    	flag = 0 ;
    }
}

void loop()
{
  if (irinput.decode(&results))
  {
    Serial.println(results.value, HEX);
    irinput.resume();
  }
  
  switch(results.value)
  {
    case 0xFD00FF :
    {
      pwr();
      break ;
    }
    case 0xFD807F : 
    {
      if (abs(val) >= 10)
      {
        Serial.println("Maximum speed");
      }
      else
      {
        val = val > 0 ? val + 1 : val - 1 ;
        Serial.println("Speed increased");
      }
      break ;
    }
    case 0xFD906F :
    {
      if (abs(val) <= 1)
      {
        Serial.println("Minimum speed");
      }
      else
      {
        val = val > 0 ? val - 1 : val + 1 ; 
        Serial.println("Speed decreased");
      }
      break;
    }
    case 0xFD20DF :
    {
      val = -abs(val) ;
      Serial.println("Anti-clockwise");
      break;
    }
    case 0xFD609F : 
    {
      val = abs(val) ;
      Serial.println("Clockwise");
      break;
    }
    default: Serial.println("No Function");
  }
  
  if (flag == 1)
  {  
    if(pos >= 180 )
    {
  	  val = -val ;
    }
    else if ( pos <= 0)
    {
    	val = abs(val);
    }
    pos += val ;
    smotor.write(pos);
    Serial.println(pos);
    delay(25);
  }
  
  results.value = NULL ;
  delay(50);
}

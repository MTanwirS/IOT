#include <LiquidCrystal.h>

int red = 6 ;
int blue = 10 ;
int green = 9 ;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void redc()
{
 lcd.setCursor(0, 0);
 analogWrite(red, 255);
 analogWrite(blue, 0);
 analogWrite(green, 0);
 lcd.print("RED  ");
}

void bluec()
{
 lcd.setCursor(0, 0);
 analogWrite(red, 0);
 analogWrite(blue, 255);
 analogWrite(green, 0);
 lcd.print("BLUE ");
}

void greenc()
{
 lcd.setCursor(0, 0);
 analogWrite(red, 0);
 analogWrite(blue, 0);
 analogWrite(green, 255);
 lcd.print("GREEN");
}

void setup()
{
 pinMode(red,OUTPUT);
 lcd.begin(16, 2);
 pinMode(blue,OUTPUT);
 pinMode(green,OUTPUT);
}

void loop()
{
  redc();
  delay(1000);
  bluec();
  delay(1000);
  greenc();
  delay(1000); 
}



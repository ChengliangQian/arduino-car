#include <Servo.h>
#钱程亮帅╮(╯▽╰)╭

Servo Steering0;
String inString = "";    // string to hold input

int pos=90;         //舵机角度

void setup ()
{
   Serial.begin(9600);
  Steering0.attach(5);
  }

void loop ()
{
  while (Serial.available() > 0) 
  {
    int inChar = Serial.read();
    if (isDigit(inChar)) 
    {
      inString += (char)inChar; 
    }

    if (inChar == '\n') 
    {
      Serial.print("Value:");
      Serial.println(inString.toInt());
      pos=inString.toInt();
        Steering0.write(pos);
        delay(30);
      // clear the string for new input:
      inString = ""; 
    }
  }
  }



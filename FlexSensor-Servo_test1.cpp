#include <Servo.h>

Servo servo1;
const int flexPin = A0; // pin A0 to read analog input

// Variables:
int value;

void setup()
{
  servo1.attach(A1);
  Serial.begin(9600); // initialize serial moniter read in and out at specified baud rate
}

void loop()
{
  value = analogRead(flexPin);// range of flex sensor is 197
  //value -= 767;
  value = map(value, 767, 964, 0, 197); // bounds of flex sensor input are 767 to 964. Ouput range mapped 0 to 197 for servo motor
  Serial.println(value);
  servo1.write(value);
  delay(250);
}
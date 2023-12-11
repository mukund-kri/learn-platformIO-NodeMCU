#include <Arduino.h>

#define LED D2

void setup()
{
  // Initialize the pin as an output:
  pinMode(LED, OUTPUT);
}

void loop()
{
  //  Blink the LED around once per second:
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
}

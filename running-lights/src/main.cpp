#include <Arduino.h>

int leds[] = {D0, D1, D2, D3, D4};

void setup()
{
  // Initialize the pins as an output:
  for (int i = 0; i < 5; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  //  Blink the LED briefly to simulate running lights
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
  }
}

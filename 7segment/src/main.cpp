#include <Arduino.h>

// Nodemcu pins connected to 7 segment leds
int leds[] = {D6, D5, D4, D3, D2, D1, D0};

// LED states to display number
int digits[][10] = {
    {0, 1, 1, 1, 1, 1, 1}, // zero
    {0, 0, 0, 0, 1, 1, 0}, //  one
    {1, 0, 1, 1, 0, 1, 1}, // two
    {1, 0, 0, 1, 1, 1, 1}, // three
    {1, 1, 0, 0, 1, 1, 0}, // four
    {1, 1, 0, 1, 1, 0, 1}, // five
    {1, 1, 1, 1, 1, 0, 1}, // six
    {0, 0, 0, 0, 1, 1, 1}, // seven
    {1, 1, 1, 1, 1, 1, 1}, // eight
    {1, 1, 0, 0, 1, 1, 1}  // nine
};

void setup()
{
  // Initialize led
  for (int i = 0; i < 7; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{

  for (int num = 0; num < 10; num++)
  {
    // Display number
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(leds[i], digits[num][i]);
    }
    delay(1000);
  }
}

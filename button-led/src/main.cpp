#include <Arduino.h>

#define LED_PIN D2
#define BUTTON_PIN D3

int buttonState = 0;                // Current state of the button
int lastButtonState = 0;            // Previous reading we choose to store
unsigned long lastDebounceTime = 0; // Last time the output pin was toggled
unsigned long debounceDelay = 50;   // Debounce time; increase if the output flickers
int ledState = 0;

void setup()
{
  // Setup ports
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
  // Read button state
  int reading = digitalRead(BUTTON_PIN);

  // If there has been a change in the button state note the time
  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }

  // If the button state has been in the same state for longer than the debounce delay
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // If the button state has changed
    if (reading != buttonState)
    {
      buttonState = reading;
      // If the button is pressed
      if (buttonState == HIGH)
      {
        ledState = !ledState;
      }
    }
  }
  // Keep track of the last button state
  lastButtonState = reading;

  // Set the LED to the correct state
  digitalWrite(LED_PIN, ledState);
}

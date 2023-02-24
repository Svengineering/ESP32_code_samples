#include <Arduino.h>



void setup() {

// initialize digital pin LED_BUILTIN as an output.
pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  int off_time_ms = 500;
  int on_time_ms = 100;

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(on_time_ms);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(off_time_ms);                       // wait for a second
}
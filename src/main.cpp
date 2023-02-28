#include <Arduino.h>

void setup() {

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  {
    Serial.begin(9600); //Sets the data rate in bits per second (baud) for serial data transmission.
    
    //time without serial input (= empty input buffer) to wait after reading from serial input has started before finish reading
    //
    //(for Serial functions that use this setting)
    //that means: i.e. serial input has started by typing something, then the "timeout" time between typing the keys must not be 
    //longer than this if the read method should continue listening for input
    Serial.setTimeout(10000); 
    
    //this is just for the first execution after upload: the first serial output of the script wouldn't be 
    //printed without waiting (upload/terminal with VS Code)
    delay(1000); 
  }

}



void loop() {
  int off_time_ms = 500;
  int on_time_ms = 100;

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(on_time_ms);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(off_time_ms);                       // wait for a second
  


 //string buffer
  int str_max_len = 128;
  uint8_t str[str_max_len] = {};

  Serial.printf("\nString eingeben (max. %d Zeichen, beende Eingabe mit Enter):\n", str_max_len);
  
  //wait until serial input is starting
  while(Serial.available() == 0){
    ; //wait
  }
  
  //read until [Enter]
  Serial.readBytesUntil('\n', str, 128);

  //print out input
  Serial.println("Eingabe ist:");
  Serial.printf("%s\n", str);

  //TODO: translate input into morse code...

}

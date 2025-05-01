#include "Led7Seg.h"
const int dataPin = 1;  // 14 IC
const int latchPin = 0; // 12 IC  
const int clockPin = 2; // 11 IC  

ledCA led(dataPin, latchPin, clockPin);

void setup(){
  led.init();

}

void loop(){
  led.displayNumber(23,2);
}
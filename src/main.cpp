#include <Arduino.h>
#include <Led7Seg.h>
#include <TrafficLight.h>

const uint64_t duration = 250;
uint64_t previousMillis = 0; 

const int dataPin = 1;   // Chân DS của 74HC595
const int latchPin = 0;   // Chân ST_CP của 74HC595
const int clockPin = 2;   // Chân SH_CP của 74HC595

uint8_t is_green[4] = {1, 0, 0 ,0};
uint8_t time_count[4] = {30, 30, 60, 90};

ledCA seg(dataPin,latchPin,clockPin);
TrafficLight den_1(19,14);
TrafficLight den_2(17,18);
TrafficLight den_3(15,16);
TrafficLight den_4(10,11);
TrafficLight tf[4] = {den_1, den_2, den_3, den_4};


void setup(){
  seg.init();
  for (int i = 0; i < 4; i++){
    tf[i].init();
    if (is_green[i] == 1) tf[i].setGreenOn();
    else tf[i].setRedon();
  }
}

void loop(){
  // seg.displayNumber(23,0);
  uint64_t currentMillis = millis();
  if(currentMillis - previousMillis >= duration){
    previousMillis = currentMillis;
    for(int i = 0 ; i < 4; i++){
      if (time_count[i] > 0) {
        time_count[i]--;
        if (time_count[i] == 3 && is_green[i] == 1) tf[i].setYellowOn();
      }
      else{
        if (is_green[i] == 1){
          is_green[i] = 0;
          time_count[i] = 90;
          tf[i].setRedon();
          if (i<3)  {
            is_green[i+1] = 1;
            time_count[i+1] = 30;
            tf[i+1].setGreenOn();
          }
          else {
            is_green[0] = 1;
            time_count[0] = 30;
            tf[0].setGreenOn();
          }
        }
      }
    }
  }
  for (int i = 0 ; i < 4; i++){
    seg.displayNumber(time_count[i], i);
  }
}


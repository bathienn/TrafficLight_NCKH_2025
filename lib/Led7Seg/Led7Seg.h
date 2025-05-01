#ifndef LED7SEG_H
#define LED7SEG_H

#include <Arduino.h>
#include <stdlib.h>
#include <stdint.h>

// #define onPulse(x) digitalWrite(x,1)
// #define offPulse(x) digitalWrite(x,0)

void onPulse(int x);
void offPulse(int x);

extern uint8_t ledCA_bits[];

class ledCA{
private:
    // pin 14 IC 74HC595
    uint8_t dataPin;
    // pin 12 IC 74HC595
    uint8_t latchPin;
    // pin 11 IC 74HC595
    uint8_t clockPin;
public:
    ledCA(); // default constructor

    ledCA(uint8_t data, uint8_t latch, uint8_t clock); // constructor has parameter

    void init(); //initialize

    uint8_t getDataPin(); // get data pin
    uint8_t getLatchPin(); // get latch pin
    uint8_t getClockPin(); // get clock pin

    // Display number in led 7 seg number num, position pos
    // pos = [0, 1, 2, 3]
    void displayNumber(uint8_t num, uint8_t pos);
};

#endif  /*Led7Seg*/
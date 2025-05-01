#include "Led7Seg.h"

void onPulse(int x) {digitalWrite(x,HIGH);}
void offPulse(int x) {digitalWrite(x,LOW);}

uint8_t ledCA_bits[]={
    0xC0,
    0xF9,
    0xA4,
    0xB0,
    0x99,
    0x92,
    0x82,
    0xF8,
    0x80,
    0x90
};

ledCA::ledCA(){};

ledCA::ledCA(uint8_t data, uint8_t latch, uint8_t clock){
    this->dataPin = data;
    this->clockPin = clock;
    this->latchPin = latch;
}

void ledCA::init(){
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
}

uint8_t ledCA::getClockPin(){
    return this->clockPin;
}

uint8_t ledCA::getDataPin(){
    return this->dataPin;
}

uint8_t ledCA::getLatchPin(){
    return this->latchPin;
}

void ledCA::displayNumber(uint8_t num, uint8_t pos){
    uint8_t digit_1, digit_10, pos_1, pos_10;
    if (num>=99){
        digit_1 = 9;
        digit_10 = 9;
    }
    else {
        digit_1 = num % 10;
        digit_10 = num / 10;
    }
    switch(pos){
        case 0 :
            pos_1  = 0b01000000;
            pos_10 = 0b10000000;
            break;

        case 1: 
            pos_1  = 0b00010000;
            pos_10 = 0b00100000;
            break;
        
        case 2:
            pos_1  = 0b00000100;
            pos_10 = 0b00001000;
            break;

        case 3: 
            pos_1  = 0b00000001;
            pos_10 = 0b00000010;
            break;
        default: 
            break;
    }

    offPulse(this->latchPin);
    shiftOut(this->dataPin, this->clockPin, LSBFIRST, pos_1);
    shiftOut(this->dataPin, this->clockPin, MSBFIRST, ledCA_bits[digit_1]);
    onPulse(this->latchPin);
    delayMicroseconds((50));

    offPulse(this->latchPin);
    shiftOut(this->dataPin, this->clockPin, LSBFIRST, pos_10);
    shiftOut(this->dataPin, this->clockPin, MSBFIRST, ledCA_bits[digit_10]);
    onPulse(this->latchPin);
    delayMicroseconds((50));
}

#include"TrafficLight.h"

// Turn on the pulse for 1 pin
void TrafficLight::onPulse(int pin) {digitalWrite(pin,HIGH);}
// Turn off the pulse for 1 pin
void TrafficLight::offPulse(int pin) {digitalWrite(pin,LOW);}
// Create one pulse
void TrafficLight::onePulse(int pin) {
    offPulse(pin);
    delayMicroseconds(1);
    onPulse(pin);
    delayMicroseconds(1);
}

TrafficLight::TrafficLight(int pin_0, int pin_1){
    this->pin_0 = pin_0;
    this->pin_1 = pin_1;
}

void TrafficLight::init(){
    pinMode(pin_0,OUTPUT);
    pinMode(pin_1,OUTPUT);
    offPulse(this->pin_0);
    onPulse(this->pin_1);
    this->state = 2;
    this->preState = 2;
    setOffAll();
}

void TrafficLight::setOffPin_0(){
    offPulse(pin_0);
}

void TrafficLight::setRedon(){
    this->state = 1;
    this->updateLight();
}

void TrafficLight::setYellowOn(){
    this->state = 2;
    this->updateLight();
}

void TrafficLight::setGreenOn(){
    this->state = 3;
    this->updateLight();
}

void TrafficLight::setOffAll(){
    this->state = 0;
    this->updateLight();
}

void TrafficLight::toggleYellow(){
    digitalWrite(pin_0,!(digitalRead(pin_0)));
}

void TrafficLight::updateLight(){
    offPulse(pin_0);
    uint8_t s1 = this->state;
    uint8_t s2 = this->preState;
    this->preState = this->state;
    switch(s1){
        case 0:             // Turn off all led
            switch(s2){
                case 0: 
                    break;
                case 1:
                    onePulse(this->pin_1);
                    onePulse(this->pin_1);
                    break;
                case 2:
                    onePulse(this->pin_1);
                    break;
                case 3:
                    onPulse(this->pin_1);
                    onePulse(this->pin_1);
                    onePulse(this->pin_1);
                    break;
                default:
                    break;
            }
        break;
        case 1:             // Turn on red led
            switch(s2){
                case 0:
                    onePulse(this->pin_1);
                    break;
                case 1:
                    break;
                case 2:
                    onePulse(this->pin_1);
                    onePulse(this->pin_1);
                    break;
                case 3:
                    onPulse(this->pin_1);
                    break;
                default:
                    break;
            }
        break;
        case 2:             // Turn on yellow led
            switch(s2){
                case 0:
                    onePulse(this->pin_1);
                    onePulse(this->pin_1);
                    break;
                case 1:
                    onePulse(this->pin_1);
                    break;
                case 2:
                    break;
                case 3:
                    onPulse(this->pin_1);
                    onePulse(this->pin_1);
                    break;
                default:
                    break;
            }
        break;
        case 3:             // Tyrn on Green led
            switch(s2){
                case 0:
                    offPulse(this->pin_1);
                    break;
                case 1:
                    onePulse(this->pin_1);
                    onePulse(this->pin_1);
                    offPulse(this->pin_1);
                    break;
                case 2:
                    onePulse(this->pin_1);
                    offPulse(this->pin_1);
                    break;
                case 3:
                    break;
                default:
                    break;
            }
        break;
        default:    
            break;
    }
}

int TrafficLight::getState(){
    return this->state;
}

int TrafficLight::getPreState(){
    return this->preState;
}

void TrafficLight::onPin_1(){
    onPulse(this->pin_1);
}

void TrafficLight::offPin_1(){
    offPulse(this->pin_1);
}

void TrafficLight::OffOnPin_1(){
    offPin_1();
    delayMicroseconds(1);
    onPin_1();
}

void TrafficLight::setState(int value){
    this->state = value;
}

void TrafficLight::setPreState(int value){
    this->preState = value;
}

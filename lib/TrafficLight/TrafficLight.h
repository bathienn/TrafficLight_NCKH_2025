#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include<Arduino.h>

// Class traffic light
class TrafficLight{
private:
    int pin_0, pin_1;  //Define pin     
    uint8_t state, preState;       // State: move state, // preState : the previous state  
public:
    TrafficLight();  // Default Constructor

    TrafficLight(int pin_0, int pin_1);  // Parameterized Constructor

    void init();         // Initializer function

    void setOffPin_0();  // function: Turn off Pin 0

    void setRedon();     // function: Set red led on

    void setYellowOn();  // function: Set yellow led on

    void setGreenOn();   // function: Set green led on

    void setOffAll();    // function: Turn off all led

    void toggleYellow(); // function: toggle led yellow   

    void updateLight();  // function: update traffic light   

    int getState();

    int getPreState();

    void onPin_1();

    void offPin_1();

    void OffOnPin_1();

    void setState(int value);

    void setPreState(int value);

    void onPulse(int pin);

    void offPulse(int pin);

    void onePulse(int pin);
};

#endif
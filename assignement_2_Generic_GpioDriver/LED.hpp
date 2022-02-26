#ifndef LED_H_
#define LED_H_

#include "GPIO.hpp"

template<typename Base>
class LED
{
    GPIO<Base> led;                 // GPIO object in LED driver
    public:
        LED();      //default constructor
        ~LED();     //default destructor
        void LedOn(PortID_t prt,int  pinNum);
        void LedOff(PortID_t prt,int  pinNum);
};


#endif
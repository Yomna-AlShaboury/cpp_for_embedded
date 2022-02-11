#ifndef LED_H_
#define LED_H_

#include "GPIO.hpp"

template<typename Base>
class LED
{
    public:
        LED();      //default constructor
        ~LED();     //default destructor
        void LedOn(PortID_t prt,int  pinNum);
        void LedOff(PortID_t prt,int  pinNum);
};


#endif
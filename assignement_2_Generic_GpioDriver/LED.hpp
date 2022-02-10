#include "GPIO.hpp"

class LED:public GPIO<ARM_GPIO>
{
    public:
        LED();
        ~LED();
        void LedOn(PortID_t prt,int  pinNum);
        void LedOff(PortID_t prt,int  pinNum);
};
#include<iostream>
#include"LED.hpp"

template<typename Base>
LED<Base>::LED(){
    /*
        default constructor
    */

    std::cout<<"LED"<<std::endl;    // print "LED"
}
template<typename Base>
LED<Base>::~LED(){
    /*
        default destructor
    */
   
}
template<typename Base>
void LED<Base>::LedOn(PortID_t prt,int  pinNum){
    led.GPIO_SetPinDirection(prt, pinNum, 1);
    led.GPIO_WriteonPin (prt,pinNum ,1);
    std::cout<<"Led on"<<std::endl;
}

/*
    explicit template instantiation
*/
template class LED<ARM_GPIO>;
template class LED<AVR_GPIO>;

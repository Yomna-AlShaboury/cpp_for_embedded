#include<iostream>
#include"LED.hpp"

template<typename Base>
LED<Base>::LED(){
    /*
        default constructor
    */

    GPIO<Base> led;                 // GPIO object in LED driver
    std::cout<<"LED"<<std::endl;    // print "LED"
}
template<typename Base>
LED<Base>::~LED(){
    /*
        default destructor
    */
   
}


/*
    explicit template instantiation
*/
template class LED<ARM_GPIO>;
template class LED<AVR_GPIO>;

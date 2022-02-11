#include<iostream>
#include"GPIO.hpp"

AVR_GPIO::AVR_GPIO(){
    /* 
        default constuctor
    */    
    std::cout<<"AVR"<<std::endl;    // print "AVR"
}
AVR_GPIO::~AVR_GPIO(){
    /* 
        default destuctor
    */
}

ARM_GPIO::ARM_GPIO(){
    /* 
        default constuctor
    */
   std::cout<<"ARM"<<std::endl;     // print "ARM"

    }
ARM_GPIO::~ARM_GPIO(){
    /* 
        default destuctor
    */
}

template<typename Base>
GPIO<Base>::GPIO(){
    /* 
        default constuctor
    */    
    std::cout<<"General GPIO"<<std::endl;   // print "General GPIO"
}

template<typename Base>
GPIO<Base>::~GPIO(){
    /* 
        default destuctor
    */
}


/*
    explicit template instantiation
*/
template class GPIO<ARM_GPIO>;
template class GPIO<AVR_GPIO>;
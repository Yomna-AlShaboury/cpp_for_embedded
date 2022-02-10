#include<iostream>
#include"GPIO.hpp"

AVR_GPIO::AVR_GPIO(){
std::cout<<"AVR"<<std::endl;

}
AVR_GPIO::~AVR_GPIO(){

}

ARM_GPIO::ARM_GPIO(){
std::cout<<"ARM"<<std::endl;

    }
ARM_GPIO::~ARM_GPIO(){

}

// template<typename Base>
// class GPIO: public Base
// {

      
// };
template<typename Base>
GPIO<Base>::GPIO(){
    std::cout<<"hi"<<std::endl;
}

template<typename Base>
GPIO<Base>::~GPIO(){

}


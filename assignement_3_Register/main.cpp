#include <iostream>
#include "Generic_Register.hpp"

int main (){
    std::uint8_t Register = 0;
    ERROR_STATUS ErrorChecker;
    Generic_Register ObjTest(&Register , RESERVED);
    ErrorChecker = ObjTest.setBit(0);
    if(ErrorChecker == OK)
    std::cout<<"SET_BIT -> "<<(int)Register<<std::endl;
    else
    std::cout<<"PERMISSION DENIED"<<std::endl;

}
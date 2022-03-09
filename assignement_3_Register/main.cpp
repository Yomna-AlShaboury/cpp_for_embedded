#include <iostream>
#include "GenericRegister.hpp"
void print_s(retStatus_t s);

int main (){
    unsigned int   DDRA;
    unsigned int   DDRB;
    unsigned int   DDRC;
    unsigned int   DDRD;

    retStatus_t state;
    unsigned int val;
    unsigned char bitVal;

    GenericRegister DDRA_REG(&DDRA, readOnly);
    GenericRegister DDRB_REG(&DDRB, writeOnly);
    GenericRegister DDRC_REG(&DDRC, readWrite);
    GenericRegister DDRD_REG(&DDRD, reserved);
    
    state = DDRA_REG.setRegisterValue(5);
    std::cout<<"SET_R       ";        print_s(state);     std::cout<<"DDRA: "<<DDRA<<std::endl;
    
    state = DDRA_REG.getRegisterValue(val);
    std::cout<<"GET_R       ";        print_s(state);     std::cout<<"DDRA: "<<val<<std::endl;
    
    state = DDRA_REG.setPermission(36, readWrite);
    std::cout<<"SET_P       ";        print_s(state);     std::cout<<"DDRA: "<<DDRA<<std::endl;

    state = DDRA_REG.setPermission(3, readWrite);
    std::cout<<"SET_P       ";        print_s(state);     std::cout<<"DDRA: "<<DDRA<<std::endl;

    state = DDRA_REG.setBit(3);
    std::cout<<"SET_B       ";        print_s(state);     std::cout<<"DDRA: "<<DDRA<<std::endl;
    
    state = DDRA_REG.getBit(3, bitVal);
    std::cout<<"GET_B       ";        print_s(state);     std::cout<<"DDRA: "<<(int)bitVal<<std::endl;
    
    state = DDRA_REG.clearBit(3);
    std::cout<<"CLR_R       ";        print_s(state);     std::cout<<"DDRA: "<<DDRA<<std::endl;
    
    state = DDRA_REG.getBit(3, bitVal);
    std::cout<<"GET_B       ";        print_s(state);     std::cout<<"DDRA: "<<(int)bitVal<<std::endl;
     
   
    std::cout<<"-------------------------------------------------------------------"<<std::endl;
   
    state = DDRB_REG.setRegisterValue(5);
    std::cout<<"SET_R       ";        print_s(state);     std::cout<<"DDRB: "<<DDRB<<std::endl;
    
    state = DDRB_REG.getRegisterValue(val);
    std::cout<<"GET_R       ";        print_s(state);     std::cout<<"DDRB: "<<val<<std::endl;
    
    state = DDRB_REG.setPermission(36, readWrite);
    std::cout<<"SET_P       ";        print_s(state);     std::cout<<"DDRB: "<<DDRB<<std::endl;

    state = DDRB_REG.setPermission(3, readWrite);
    std::cout<<"SET_P       ";        print_s(state);     std::cout<<"DDRB: "<<DDRB<<std::endl;

    state = DDRB_REG.setBit(3);
    std::cout<<"SET_B       ";        print_s(state);     std::cout<<"DDRB: "<<DDRB<<std::endl;
    
    state = DDRB_REG.getBit(3, bitVal);
    std::cout<<"GET_B       ";        print_s(state);     std::cout<<"DDRB: "<<(int)bitVal<<std::endl;
    
    state = DDRB_REG.clearBit(3);
    std::cout<<"CLR_R       ";        print_s(state);     std::cout<<"DDRB: "<<DDRB<<std::endl;
    
    state = DDRB_REG.getBit(3, bitVal);
    std::cout<<"GET_B       ";        print_s(state);     std::cout<<"DDRB: "<<(int)bitVal<<std::endl;
     
    std::cout<<"-------------------------------------------------------------------"<<std::endl;
    
    
    state = DDRC_REG.setRegisterValue(5);
    std::cout<<"SET_R       ";        print_s(state);     std::cout<<"DDRC: "<<DDRC<<std::endl;
    
    state = DDRC_REG.getRegisterValue(val);
    std::cout<<"GET_R       ";        print_s(state);     std::cout<<"DDRC: "<<val<<std::endl;
    
    state = DDRC_REG.setPermission(36, readWrite);
    std::cout<<"SET_P       ";        print_s(state);     std::cout<<"DDRC: "<<DDRC<<std::endl;

    state = DDRC_REG.setPermission(3, readWrite);
    std::cout<<"SET_P       ";        print_s(state);     std::cout<<"DDRC: "<<DDRC<<std::endl;

    state = DDRC_REG.setBit(3);
    std::cout<<"SET_B       ";        print_s(state);     std::cout<<"DDRC: "<<DDRC<<std::endl;
    
    state = DDRC_REG.getBit(3, bitVal);
    std::cout<<"GET_B       ";        print_s(state);     std::cout<<"DDRC: "<<(int)bitVal<<std::endl;
    
    state = DDRC_REG.clearBit(3);
    std::cout<<"CLR_R       ";        print_s(state);     std::cout<<"DDRC: "<<DDRC<<std::endl;
    
    state = DDRC_REG.getBit(3, bitVal);
    std::cout<<"GET_B       ";        print_s(state);     std::cout<<"DDRC: "<<(int)bitVal<<std::endl;
     
    std::cout<<"-------------------------------------------------------------------"<<std::endl;
    
    state = DDRD_REG.setRegisterValue(5);
    std::cout<<"SET_R       ";        print_s(state);     std::cout<<"DDRD: "<<DDRD<<std::endl;
    
    state = DDRD_REG.getRegisterValue(val);
    std::cout<<"GET_R       ";        print_s(state);     std::cout<<"DDRD: "<<val<<std::endl;
    
    state = DDRD_REG.setPermission(36, readWrite);
    std::cout<<"SET_P       ";        print_s(state);     std::cout<<"DDRD: "<<DDRD<<std::endl;

    state = DDRD_REG.setPermission(3, readWrite);
    std::cout<<"SET_P       ";        print_s(state);     std::cout<<"DDRD: "<<DDRA<<std::endl;

    state = DDRD_REG.setBit(3);
    std::cout<<"SET_B       ";        print_s(state);     std::cout<<"DDRD: "<<DDRD<<std::endl;
    
    state = DDRD_REG.getBit(3, bitVal);
    std::cout<<"GET_B       ";        print_s(state);     std::cout<<"DDRD: "<<(int)bitVal<<std::endl;
    
    state = DDRD_REG.clearBit(3);
    std::cout<<"CLR_R       ";        print_s(state);     std::cout<<"DDRD: "<<DDRD<<std::endl;
    
    state = DDRD_REG.getBit(3, bitVal);
    std::cout<<"GET_B       ";        print_s(state);     std::cout<<"DDRD: "<<(int)bitVal<<std::endl;

}

void print_s(retStatus_t s){
    switch (s)
    {
    case allowed:
        std::cout<<"Allowed:                    ";
        break;
    case notAllowed:
        std::cout<<"NotAllowed:                 ";
        break;
    case someNonPermissableBits:
        std::cout<<"Some Non Permissable Bits:  ";
        break;
    case invalidBitNo:
        std::cout<<"Invalid Bit No:             ";
        break;
    default:
        break;
    }
}
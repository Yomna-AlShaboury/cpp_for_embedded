/*
*
*       Auther  : Yomna Al-Shaboury
*       Date    : 8/3/2022
*       Generic Register Class
*
*/

#ifndef GENERIC_REGISTER_H_
#define GENERIC_REGISTER_H_

// enum type for the statusor status (ok, nok)
typedef enum{
    allowed,
    notAllowed,
    someNonPermissableBits,
    invalidBitNo
}retStatus_t;

// enum type for register permissions
typedef enum{
    readOnly,
    writeOnly,
    readWrite,
    reserved
}permission_t;

template<typename T>
class GenericRegister
{
private:
    T * pReg;                                                                   // pointer holding register address
    T readMask;                                                                 // set bit by 1 if read is allowed
    T writeMask;                                                                // set bit by 1 if write is allowed

public:
    GenericRegister(T * pReg, permission_t perm = readWrite);
    ~GenericRegister();
    retStatus_t setRegisterValue(T val);                                        // Sets the whole register bits with the value sent by the user
    retStatus_t getRegisterValue(T & val);                                      // Reads the whole register value
    retStatus_t setBit(unsigned char bitNo);                                    // set only a specific bit in the register by 1
    retStatus_t clearBit(unsigned char bitNo);                                  // set only a specific bit in the register by 0
    retStatus_t getBit(unsigned char bitNo, unsigned char & bitVal);            // get only the value of a specific bit in the register
    retStatus_t setPermission(unsigned char bitNo, permission_t perm);          // change the register permission of certain bit of the register
    retStatus_t setPermission(permission_t perm);                               // change the register permission the whole register
};




template<typename T>
GenericRegister<T>::GenericRegister(T * pReg, permission_t perm){
    this->pReg  = pReg;
    this->setPermission(perm);
    // initialize by zero
    *pReg = 0x00;
}

template<typename T>
GenericRegister<T>::~GenericRegister(){
}

template<typename T>
retStatus_t GenericRegister<T>::setRegisterValue(T val){
    retStatus_t status = allowed;
    // if register is non writable
    if(writeMask == 0x00){
        status = notAllowed;
    }
    else{
        *pReg = val & writeMask;
        // if register has some non writable bits, write on allowed and return status
        if(writeMask != ~((T)0x00)){
            status = someNonPermissableBits;
        }
    }    
    return status;
}

template<typename T>
retStatus_t GenericRegister<T>::getRegisterValue(T & val){
    retStatus_t status = allowed;
    // if register is non readable
    if(readMask == 0x00){
        status = notAllowed;
        val = 0x00;
    }
    else{
        val = (*pReg)&readMask;
        // if register has some non readable bits, read allowable (non readable bits are read as zero) and return status
        if(readMask != ~((T)0x00)){
            status = someNonPermissableBits;
        }
    } 
    return status;
}

template<typename T>
retStatus_t GenericRegister<T>::setBit(unsigned char bitNo){
    retStatus_t status = allowed;
    // check if bit number is valid
    if(!(bitNo < (sizeof(T)*8))){
        status = invalidBitNo;
    }
    else{
        // check if bit is writable, set by 1
        if((writeMask >> bitNo) & 0x01){
            *pReg |= 0x01 << bitNo;
        }
        else{
            status = notAllowed;
        }
    }
    return status;
}

template<typename T>
retStatus_t GenericRegister<T>::clearBit(unsigned char bitNo){
    retStatus_t status = allowed;
    // check if bit number is valid
    if(!(bitNo < (sizeof(T)*8))){
        status = invalidBitNo;
    }
    else{
        // check if bit is writable, set by 0
        if((writeMask >> bitNo) & 0x01){
            *pReg &= ~(0x01 << bitNo);
        }
        else{
            status = notAllowed;
        }
    }
    return status;
}
template<typename T>
retStatus_t GenericRegister<T>::getBit(unsigned char bitNo, unsigned char & bitVal){
    retStatus_t status = allowed;
    // check if bit number is valid
    if(!(bitNo < (sizeof(T)*8))){
        status = invalidBitNo;
    }
    else{
        // check if bit is readable, get bit
        if((readMask >> bitNo) & 0x01){
            bitVal = ((*pReg) >> bitNo) & 0x01;
        }
        else{
            status = notAllowed;
            bitVal = 0x00;
        }
    }
    return status;
}
template<typename T>
retStatus_t GenericRegister<T>::setPermission(unsigned char bitNo, permission_t perm){
    retStatus_t status = allowed;
    // check if bit number is valid
    if(!(bitNo < (sizeof(T)*8))){
        status = invalidBitNo;
    }
    else{
        switch (perm)
        {
        case readOnly:
            readMask    |= 0x01 << bitNo;
            writeMask   &= ~(0x01 << bitNo);
            break;
        case writeOnly:
            readMask    &= ~(0x01 << bitNo);
            writeMask   |= 0x01 << bitNo;
            break;
        case readWrite:
            readMask    |= 0x01 << bitNo;
            writeMask   |= 0x01 << bitNo;
            break;
        case reserved:
            readMask    &= ~(0x01 << bitNo);
            writeMask   &= ~(0x01 << bitNo);
            break;
        default:
            break;
        }
    }
    return status;
}
template<typename T>
retStatus_t GenericRegister<T>::setPermission(permission_t perm){
    retStatus_t status = allowed;
    switch (perm)
    {
    case readOnly:
        readMask    = ~((T)0x00);
        writeMask   = 0x00;
        break;
    case writeOnly:
        readMask    = 0x00;
        writeMask   = ~((T)0x00);
        break;
    case readWrite:
        readMask    = ~((T)0x00);
        writeMask   = ~((T)0x00);
        break;
    case reserved:
        readMask    = 0x00;
        writeMask   = 0x00;
        break;    
    default:
        break;
    }
    return status;
}

#endif
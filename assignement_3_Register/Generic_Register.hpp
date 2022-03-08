#ifndef GENERIC_REGISTER_H_
#define GENERIC_REGISTER_H_

#define GET_BIT(REG,BIT)        ((REG>>BIT) & 0x01)

typedef enum{
    OK=0,
    NOK

}ERROR_STATUS;

typedef enum{
    READ_ONLY = 0,
    WRITE_ONLY,
    READ_AND_WRITE,
    RESERVED
}REGISTER_PERMISSION;



template <class T>
class Generic_Register{
    private:
        T * PrvRegister;
        T   Write_Only;
        T   Read_Only;
    public:
    Generic_Register(T * Register , REGISTER_PERMISSION Permission = READ_AND_WRITE);

    ERROR_STATUS setRegisterValue(T Copy_tValue);
    ERROR_STATUS getRegisterValue(T & Ref_tValue);
    ERROR_STATUS setBit(std::uint8_t Copy_BitNum);
    ERROR_STATUS clearBit(std::uint8_t Copy_BitNum);
    ERROR_STATUS getBit(std::uint8_t Copy_BitNum , bool &Ref_BitValue);
    ERROR_STATUS setPermission(REGISTER_PERMISSION Permission);  
    ERROR_STATUS setPermission(T Copy_Mask , REGISTER_PERMISSION Permission);  
    ERROR_STATUS setBitPermission(std::uint8_t Copy_BitNum , REGISTER_PERMISSION Permission);  
};


template <class T>
Generic_Register<T>::Generic_Register(T * Register , REGISTER_PERMISSION Permission)
{
    PrvRegister = Register;
    switch(Permission)
    {
        case READ_ONLY:
            Read_Only = ~((T) 0);
            Write_Only = 0;
            break;
        case WRITE_ONLY:
            Write_Only = ~((T) 0);
            Read_Only = 0;
            break;        
        case READ_AND_WRITE:
            Write_Only = ~((T) 0);
            Read_Only = ~((T) 0);
            break;
        case RESERVED:
            Read_Only = 0;
            Write_Only = 0;
            break;            
    }
    
}

template <class T>
ERROR_STATUS Generic_Register<T>::setRegisterValue(T Copy_tValue)
{
    ERROR_STATUS LOC_enuReturnError = NOK;
    if(Write_Only == ~((T) 0))
    {
        *PrvRegister = Copy_tValue;
        LOC_enuReturnError= OK;
    }

    return LOC_enuReturnError;
}
template <class T>
ERROR_STATUS Generic_Register<T>::getRegisterValue(T & Ref_tValue)
{
    ERROR_STATUS LOC_enuReturnError= NOK;
    if(Read_Only == ~((T) 0))
    {
        Ref_tValue = *PrvRegister;
        LOC_enuReturnError= OK;
    }
    return LOC_enuReturnError;
}
template <class T>
ERROR_STATUS Generic_Register<T>::setBit(std::uint8_t Copy_BitNum)
{
    ERROR_STATUS LOC_enuReturnError= NOK;
    if(GET_BIT(Write_Only , Copy_BitNum) == 1)
    {
        *PrvRegister |= (1<<Copy_BitNum);
        LOC_enuReturnError= OK;
    }
    return LOC_enuReturnError;
}
template <class T>
ERROR_STATUS Generic_Register<T>::clearBit(std::uint8_t Copy_BitNum)
{
    ERROR_STATUS LOC_enuReturnError= NOK;
    if(GET_BIT(Write_Only , Copy_BitNum) == 1)
    {
    *PrvRegister &= ~(1<<Copy_BitNum);
        LOC_enuReturnError= OK;
    }
    return LOC_enuReturnError;
}

template <class T>
ERROR_STATUS Generic_Register<T>:: getBit(std::uint8_t Copy_BitNum , bool &Ref_BitValue)
{
    ERROR_STATUS LOC_enuReturnError= NOK;
    if(GET_BIT(Read_Only , Copy_BitNum) == 1)
    {
        Ref_BitValue = (*PrvRegister >> Copy_BitNum)  & 1;
        LOC_enuReturnError= OK;

    }
    return LOC_enuReturnError;
}

template <class T>
ERROR_STATUS Generic_Register<T>::setPermission(REGISTER_PERMISSION Permission)
{
    ERROR_STATUS LOC_enuReturnError= OK;
    switch(Permission)
    {
        case READ_ONLY:
            Read_Only = ~((T) 0);
            Write_Only = 0;
            break;
        case WRITE_ONLY:
            Write_Only = ~((T) 0);
            Read_Only = 0;
            break;        
        case READ_AND_WRITE:
            Write_Only = ~((T) 0);
            Read_Only = ~((T) 0);
            break;
        case RESERVED:
            Read_Only = 0;
            Write_Only = 0;
            break;            
    }
    return LOC_enuReturnError;
}

template <class T>
ERROR_STATUS Generic_Register<T>::setBitPermission(std::uint8_t Copy_BitNum , REGISTER_PERMISSION Permission)
{
    ERROR_STATUS LOC_enuReturnError= OK;
    switch(Permission)
    {
        case READ_ONLY:
            Read_Only |= (1<<Copy_BitNum);
            Write_Only &= ~(1<<Copy_BitNum);
            break;
        case WRITE_ONLY:
            Write_Only |= (1<<Copy_BitNum);
            Read_Only &= ~(1<<Copy_BitNum);
            break;        
        case READ_AND_WRITE:
            Write_Only |= (1<<Copy_BitNum);
            Read_Only |= (1<<Copy_BitNum);
            break;
        case RESERVED:
            Read_Only &= ~(1<<Copy_BitNum);
            Write_Only &= ~(1<<Copy_BitNum);
            break;            
    }
    return LOC_enuReturnError;
}


template <class T>
ERROR_STATUS Generic_Register<T>::setPermission(T Copy_Mask , REGISTER_PERMISSION Permission)
{
    ERROR_STATUS LOC_enuReturnError= OK;
    switch(Permission)
    {
        case READ_ONLY:
            Read_Only |= (Copy_Mask);
            Write_Only &= ~(Copy_Mask);
            break;
        case WRITE_ONLY:
            Write_Only |= (Copy_Mask);
            Read_Only &= ~(Copy_Mask);
            break;        
        case READ_AND_WRITE:
            Write_Only |= (Copy_Mask);
            Read_Only |= (Copy_Mask);
            break;
        case RESERVED:
            Read_Only &= ~(Copy_Mask);
            Write_Only &= ~(Copy_Mask);
            break;            
    }
    return LOC_enuReturnError;
}

#endif
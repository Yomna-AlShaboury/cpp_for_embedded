#ifndef GPIO_H_
#define GPIO_H_

/*
    available ports
*/
typedef enum
{
	PA=0,
	PB,
	PC,
	PD

}PortID_t;


class AVR_GPIO
{   public:
        AVR_GPIO();             // default constuctor
        ~AVR_GPIO();            // default destuctor
        // GPIO AVR functions
        void funcNotinArm(void);

        // GPIO General functions __ AVR Implemetation
        void GPIO_SetPinDirection (PortID_t prt,int  pinNum,int direction); 
        void GPIO_SetPortDirection (PortID_t port,int direction );
        void GPIO_WriteonPin (PortID_t port,int  pinNum ,int value);
        void GPIO_WriteonPort (PortID_t port,int valu);
        int  GPIO_ReadFromPin (PortID_t port,int  pinNum );
        int  GPIO_ReadFromPort (PortID_t port);
};

class ARM_GPIO
{
    public:
        ARM_GPIO();             // default constuctor
        ~ARM_GPIO();            // default destuctor
        // GPIO ARM functions
        void GPIO_SetPortInit(PortID_t port);
        void GPIO_SetAllPortSInit(PortID_t port);

        // GPIO General functions __ ARM Implemetation
        void GPIO_SetPinDirection (PortID_t prt,int  pinNum,int direction); 
        void GPIO_SetPortDirection (PortID_t port,int direction );
        void GPIO_WriteonPin (PortID_t port,int  pinNum ,int value);
        void GPIO_WriteonPort (PortID_t port,int valu);
        int  GPIO_ReadFromPin (PortID_t port,int  pinNum );
        int  GPIO_ReadFromPort (PortID_t port);
};

/*
    General GPIO Class that inherites from a template class
*/
template<typename Base>
class GPIO: public Base
{
    public:
        GPIO();                 // default constuctor
        ~GPIO();                //default destuctor
};

#endif
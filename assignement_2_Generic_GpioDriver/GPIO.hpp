typedef enum
{
	PA=0,
	PB,
	PC,
	PD

}PortID_t;


class AVR_GPIO
{   public:
    AVR_GPIO();
    ~AVR_GPIO();
    void funcNotinArm(void);
};

class ARM_GPIO
{
    public:
        ARM_GPIO();
        ~ARM_GPIO();
        void GPIO_SetPortInit(PortID_t port);
        void GPIO_SetAllPortSInit(PortID_t port);
};

template<typename Base>
class GPIO: public Base
{
    public:
        GPIO();
        void GPIO_SetPinDirection (PortID_t prt,int  pinNum,int direction); 
        void GPIO_SetPortDirection (PortID_t port,int direction );
        void GPIO_WriteonPin (PortID_t port,int  pinNum ,int value);
        void GPIO_WriteonPort (PortID_t port,int valu);
        int  GPIO_ReadFromPin (PortID_t port,int  pinNum );
        int  GPIO_ReadFromPort (PortID_t port);
        ~GPIO();
};

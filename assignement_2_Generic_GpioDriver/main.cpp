#include"LED.hpp"

int main(void){
    /*
        test the driver design by creating an LED object
    */
    LED<AVR_GPIO> ledaiah_AVR;
    ledaiah_AVR.LedOn(PA,0);
    // LED<ARM_GPIO> ledaiah_ARM;
    return 0;
}


#include "demo.h"

void irda_test(int num)
{
    LED led1(48);
    LED led2(49);
    IRDA irda(num);
    
    led1.off();
    led2.off();

    while(1)
    {
        irda.readKey();
        
        switch (irda.code) 
        {
        case KEY_1:
            if (irda.value == 0)
                led1.off();
            else 
                led1.on();
            break;
        
        case KEY_2:
            if (irda.value == 0)
                led2.off();
            else 
                led2.on();
            break;
        default:
            break;
        }
    }

}
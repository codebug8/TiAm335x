#include "demo.h"
#include "sr501.h"

void sr501_test(int num)
{
    LED led1(1*32+16);
    SR501 sr501(num);
    
    while(1)
    {
        if(sr501.getSignal() == 1)
            led1.on(); 
        else
            led1.off(); 
        
        msleep(200);     
    }
    
}


#include "led.h"

void led_test(int num)
{
	LED led(num);
    
    while(1)
    {
        led.on();  
        sleep(1);
        
        led.off(); 
        sleep(1);
    }
}


#include "demo.h"

void oled_test(void)
{
    OLED oled = OLED(1);

    oled.OLEDPrint(4, 0, "6453210123456789");
    oled.OLEDPrint(6, 0, "1234567890123456789"); 
    
    sleep(1);
    
    oled.OLEDClearAll();
    oled.OLEDPrint(3, 50, "ok");
    sleep(1);
    
    oled.OLEDClearAll();
    int page=0;
    while (1)
    {
        if(page < 8)
        {
            oled.OLEDPrint(page, 0, "1234567890123456"); 
            page += 2;
            sleep(1);   
        }
        else
        {
            page = 0;
            oled.OLEDClearAll();    
            sleep(1);
        }
    }
}

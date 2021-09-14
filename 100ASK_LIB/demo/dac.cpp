
#include "demo.h"
#include "dac_tlc5615.h"


//vol range: 0 ~ 4.092
void dac_test()
{
    DAC dac(1);
    
    float vol;
    
    for (vol = 0; vol < 4.092; vol = vol + 0.01)
    {
        dac.setVoltage(vol);
        msleep(100);
        
        if (vol > 4.092)
            vol = 0;
    }
}



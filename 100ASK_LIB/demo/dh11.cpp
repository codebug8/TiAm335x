
#include "demo.h"

/*************************
Temperature: 22'C
Humdity；89%
*************************/

void dh11_test(int num)
{
    DH11 dh11(num);
    
    while(1)
    {
        cout << "Temperature: " << dh11.readTemperature() << "'C" << endl;
        cout << "Humdity；" << dh11.readHumdity() << "%" << endl;
        
        sleep(1);
    }
}

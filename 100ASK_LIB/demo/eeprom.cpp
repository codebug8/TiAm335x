
#include "eeprom.h"

void eeprom_test1(int num)
{
    EEPROM eeprom(num);
    
    string txString = "www.100ask.org";
    string rxString;
    
    eeprom.writeEEPROM(0, txString.size(), txString);
    eeprom.readEEPROM(0, txString.size(), &rxString);
    cout << "rxString: " << rxString << endl;
}

void eeprom_test2(int num)
{
    int i;
    int txArray[10] = {10, 20, 30, 254, 255};
    int rxArray[10];
    int txLen = sizeof(txArray)/sizeof(txArray[0]);
    int rxLen = sizeof(rxArray)/sizeof(rxArray[0]);
    
    EEPROM eeprom(num);
    
    eeprom.writeEEPROM(0, txLen, txArray);
    eeprom.readEEPROM(0, rxLen, rxArray);
    
    cout << "rxArray: "; 
    for (i=0; i<rxLen; i++)
        cout << rxArray[i] << " " ; 
    cout << endl; 
}
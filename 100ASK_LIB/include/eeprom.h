#ifndef EEPROM_H
#define EEPROM_H


#include <stdlib.h>
#include <string.h>
#include "i2c.h"

using namespace std;

class EEPROM : public I2C {
	
public:
	EEPROM(int num);
	virtual int readEEPROM(unsigned int addr, unsigned int len, string *rxBuffer);
	virtual int writeEEPROM(unsigned int addr, unsigned int len, string txBuffer);
	
	virtual int readEEPROM(unsigned int addr, unsigned int len, int *rxBuffer);
	virtual int writeEEPROM(unsigned int addr, unsigned int len, int txBuffer[]);
	
	virtual ~EEPROM();
};

	
#endif


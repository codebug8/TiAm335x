#ifndef I2C_H
#define I2C_H


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> 

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <stdint.h>


#define I2C0  "/dev/i2c-0"
#define I2C1  "/dev/i2c-1"

#define AT24C256 0x50
#define DS3231   0x68

using namespace std;

class I2C {
private:
	static int m_iUseCount;
	
	string m_sPath;
	static int m_iFile;
	unsigned int m_iDevAddr;
	
public:

	I2C();
	I2C(string bus, unsigned int dev);
	virtual unsigned char readRegister(unsigned int registerAddress);
	virtual int writeRegister(unsigned int registerAddress, unsigned char value);
	virtual ~I2C();
};

#endif
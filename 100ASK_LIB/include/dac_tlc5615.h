#ifndef DAC_TLC5615_H
#define DAC_TLC5615_H

#include <stdlib.h>
#include <string.h>
#include "spi.h"

using namespace std;

class DAC : public SPI {
private:
	float m_fVoltage;
	int m_SPInum;
		
public:
	DAC(int num = 0);
	virtual int setVoltage(float vol = 0);
	virtual int setVoltage(int vol = 0);
	virtual ~DAC();
};

#endif
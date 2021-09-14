#ifndef GPIO_H
#define GPIO_H


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> 

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <fstream>


using namespace std;

class GPIO {
	private:
		int m_iPin;
		string m_sPath;
		
	public:
		GPIO(void);
		GPIO(int pin);
		
		void setPin(int pin);
		int getPin(void);	
		
		void setPath(int pin);
		string getPath(void);
		
		int setDirection(int d);
		int getDirection(void);
		
		int setValue(int v);
		int getValue(void);
		
		int exportGPIO(void);
		int unexportGPIO(void);
};

#endif
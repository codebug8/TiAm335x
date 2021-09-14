#ifndef RTC_H
#define RTC_H


#include <stdlib.h>
#include <string.h>
#include "i2c.h"

using namespace std;

#define H12 1
#define H24 0
#define AM  0
#define PM  1

class RTC : public I2C {
	public:	
		unsigned int year;
		unsigned char month;
		unsigned char date;
		unsigned char day;
		unsigned char hour;
		unsigned char minute;
		unsigned char second;
		
		unsigned char h12;
		unsigned char am_pm;
		const char *week[7] = {"Mon","Tue","Wed","Thur", "Fri","Sat","Sun"};
		
	public:
		RTC(int num);
		virtual int readTime();
		virtual int setTime();
		virtual int timePrintf();
		virtual ~RTC();
};

#endif


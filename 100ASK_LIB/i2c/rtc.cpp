#include "demo.h"
#include "i2c.h"
#include "rtc.h"

RTC::RTC(int num)
{
	if (num == 0)
		I2C(I2C0, DS3231);
	else if(num == 1)
		I2C(I2C1, DS3231);
}


int RTC::readTime()
{
	int i;
	unsigned char rtc_data[7];
	unsigned char rtc_address[7]={0x00,0x01,0x02,0x03,0x04,0x05,0x06};
	
	for (i=0; i<7; i++)
	{
		rtc_data[i] = readRegister(rtc_address[i]);
		//printf("read: rtc_data[%d]=%d\n", i, rtc_data[i]);
	}
	
	this->second = (rtc_data[0] & 0xF) + ((rtc_data[0] & 0x70)>>4)*10;
	
	this->minute = (rtc_data[1] & 0xF) + ((rtc_data[1] & 0x70)>>4)*10;
	
	this->h12 = (rtc_data[2] & 0x40);
	if (this->h12)
	{
		this->am_pm = (rtc_data[2] & 0x20);
		this->hour = (rtc_data[2] & 0xF) + ((rtc_data[2] & 0x10)>>4)*10;
	}
	else
		this->hour = (rtc_data[2] & 0x7) + ((rtc_data[2] & 0x30)>>4)*10;
	
	this->day = (rtc_data[3] & 0x7);
	
	this->date = (rtc_data[4] & 0xF) + ((rtc_data[4] & 0x30)>>4)*10;
	
	this->month = (rtc_data[5] & 0xF) + ((rtc_data[5] & 0x10)>>4)*10;
	
	this->year = (rtc_data[6] & 0xF) + ((rtc_data[6] & 0xF0)>>4)*10 + 2000;
	
	return 0;
}

int RTC::setTime()
{
	int i;
	unsigned char rtc_data[7];
	unsigned char rtc_address[7]={0x00,0x01,0x02,0x03,0x04,0x05,0x06};
	
	if(this->second > 59)
        goto err;
	else
		rtc_data[0] = (this->second/10)<<4 | (this->second%10);
	
	
	if(this->minute > 59)
        goto err;
	else
		rtc_data[1] = (this->minute/10)<<4 | (this->minute%10);
	
	if (this->h12)
	{
		if (this->hour>12 || this->hour==0)
			goto err;	
		else
		{
			if (this->am_pm)
				rtc_data[2] = (this->hour/10)<<4 | (this->hour%10) | (1<<6) | (1<<5);
			else
				rtc_data[2] = (this->hour/10)<<4 | (this->hour%10) | (1<<6);
		}

	}
	else
	{
		if (this->hour>23)
			goto err;	
		else
			rtc_data[2] = (this->hour/10)<<4 | (this->hour%10);
	}
		
	
	if(this->day>7 || this->day==0)
		goto err;
	else
		rtc_data[3] = this->day;
	
	
	if(this->date > 31)
        goto err;
	else
		rtc_data[4] = (this->date/10)<<4 | (this->date%10);
	
	
	if(this->month > 12 || this->month==0)
        goto err;
	else
		rtc_data[5] = (this->month/10)<<4 | (this->month%10);
	
	
	if((this->year-2000) > 99)
        goto err;
	else
		rtc_data[6] = ((this->year-2000)/10)<<4 | ((this->year-2000)%10);
	
	for (i=0; i<7; i++)
	{
		writeRegister(rtc_address[i], rtc_data[i]);
		//printf("set: rtc_data[%d]=%d\n", i, rtc_data[i]);
	}
	
	return 0;

err:
    printf("setTime err.\n\r");
    return 1;		
}

int RTC::timePrintf()
{
	 readTime();
	
	if(this->h12)
	{
		if (this->am_pm)
			printf("Time: %d-%02d-%02d %02d:%02d:%02d PM %s\n", this->year, this->month,this->date,this->hour,this->minute,this->second, this->week[this->day-1]);
		else
			printf("Time: %d-%02d-%02d %02d:%02d:%02d AM %s\n", this->year, this->month,this->date,this->hour,this->minute,this->second, this->week[this->day-1]);
	}
	else
		printf("Time: %d-%02d-%02d %02d:%02d:%02d %s\n", this->year, this->month,this->date,this->hour,this->minute,this->second, this->week[this->day-1]);
	
	return 0;
}


RTC::~RTC()
{
	
}

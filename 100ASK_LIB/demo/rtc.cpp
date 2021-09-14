
#include "demo.h"
#include "rtc.h"

void rtc_test(int num)
{
	RTC rtc(num);
	
	rtc.timePrintf();
	
	rtc.year = 2019;
	rtc.month = 4;
	rtc.date = 9;
	rtc.day = 2;
	rtc.h12 = H12; 
	rtc.am_pm = PM;
	rtc.hour = 2;
	rtc.minute = 59;
	rtc.second = 54;

	rtc.setTime();
	
	while(1)
	{
		rtc.timePrintf();
		sleep(1);
	}
	
}


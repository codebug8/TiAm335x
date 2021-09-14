
#include "demo.h"

void adxl345_test1(int num)
{
	
	ADXL345 adxl345(num);
	
	while(1)
	{
		adxl345.readData();
		
		while(adxl345.touch_value == 0)
		{
			adxl345.readData();
			if(adxl345.touch_value == 1)
				cout << "You hit it" << endl;
			
		}
	}
}

void adxl345_test2(int num)
{
	
	ADXL345 adxl345(num);
	
	while(1)
	{
		adxl345.readData();
		  
		cout << "X: " << setw(4) << adxl345.x_value <<  "  Y: " << setw(4) << adxl345.y_value <<  "  Z: " << setw(4) << adxl345.z_value << endl;
		
		msleep(200);
	}
}

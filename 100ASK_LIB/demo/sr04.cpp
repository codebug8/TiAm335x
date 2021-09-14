#include "demo.h"
#include "sr04.h"

void sr04_test(void)
{
	SR04 sr04;
	while(1)
	{
		cout << "distance: " << sr04.getDistance() << "cm" <<endl;
		msleep(200);
	}
}


#include "demo.h"

/*************************
SerialNum: 8933200182180
Temperature: 21.875
FamilyCode: 40
CRC: 151
*************************/

void ds18b20_test(int num)
{
    DS18B20 ds18b20(num);

	int i;
	unsigned char SerialNum[6];
	ds18b20.readSerialNum(SerialNum);
	cout << "SerialNum: ";
	for (i=0; i<6; i++)
		cout << (int)SerialNum[i];
	cout << endl;
	
	cout << "Temperature: " << ds18b20.readTemperature() << endl;
	cout << "FamilyCode: " <<  ds18b20.readFamilyCode() << endl;
    cout << "CRC: " <<  ds18b20.readCRC() << endl;
}


#include "demo.h"

void keyboard_test()
{
	KEYBOARD keyboard;
	
	while(1)
	{
		keyboard.readKey();
		cout << "Code:" << keyboard.code << "Value:" << keyboard.value << endl;
	}
}
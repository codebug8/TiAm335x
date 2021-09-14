#ifndef _LED_H
#define _LED_H

#include "gpio.h"

class LED : public GPIO {
	public:

		LED(int pin);
		~LED(void);
		
		int on(void);
		int off(void);
};


#endif /* _LED_H */



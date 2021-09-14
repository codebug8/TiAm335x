#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/input.h> 

using namespace std;



#define KEYBOARD_EVENT_PATH   "/dev/input/event0"

class KEYBOARD  {
	private:
		string m_sPath;
		int m_iFileEvent;
		
	public:	
		int code;
		int value;
	
	public:
		KEYBOARD();
		virtual int readKey(void);
		~KEYBOARD(void);
};


#endif 



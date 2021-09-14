#ifndef _IRDA_H
#define _IRDA_H

#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/input.h> 

using namespace std;

#define IRDA_IOC_MAGIC    'i'
#define IRDA_IOCINIT      _IOW(IRDA_IOC_MAGIC, 0, int)

#define IRDA_PATH         "/dev/irda"
#define IRDA_EVENT_PATH   "/dev/input/event1"

class IRDA  {
	private:
		int m_iPin;
		string m_sPath;
		int m_iFileIRDA;
		int m_iFileEvent;
		
	public:	
		int code;
		int value;
	
	public:
		IRDA(int pin);
		virtual int readKey(void);
		~IRDA(void);
};


#endif



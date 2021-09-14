
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include "demo.h"
#include "i2c.h"

int I2C::m_iUseCount = 0;
int I2C::m_iFile = 0;

I2C::I2C()
{
	m_iUseCount++;
}

I2C::I2C(string bus, unsigned int dev) : m_sPath(bus), m_iDevAddr(dev)
{
	m_iUseCount++;

	this->m_iFile = open(this->m_sPath.c_str(), O_RDWR);
	if (this->m_iFile < 0)
		perror("can't open device");
	
	if(ioctl(this->m_iFile, I2C_SLAVE, this->m_iDevAddr) < 0) 
		perror("I2C: Failed to connect to the device\n");
	
}

unsigned char I2C::readRegister(unsigned int registerAddress)
{
	unsigned char buffer;
	
	if(write(this->m_iFile, &registerAddress, 1) != 1) 
		perror("I2C: Failed to write to the device\n");
	else
	{
		if(read(this->m_iFile, &buffer, 1) != 1) 
			perror("I2C: Failed to read in the value\n");
	}
	
	usleep(2000); //must add, Otherwise error: Remote I/O error
	return buffer;
}


int I2C::writeRegister(unsigned int registerAddress, unsigned char value)
{
#if 1
	unsigned char buffer[2];
	buffer[0] = registerAddress;
	buffer[1] = value;
	
	if(write(this->m_iFile, buffer, 2) != 2) 
	{
		perror("I2C: Failed to write to the device\n");
		return 1;
	}
	usleep(2000); //must add, Otherwise error: Remote I/O error

#else
	struct i2c_rdwr_ioctl_data work_queue;
	int ret;
	work_queue.nmsgs  = 1;	
	(work_queue.msgs[0]).len = 2;
	(work_queue.msgs[0]).flags = 0; //write
	(work_queue.msgs[0]).addr = this->m_iDevAddr;
	(work_queue.msgs[0]).buf = (unsigned char *)malloc(2);
	(work_queue.msgs[0]).buf[0] = registerAddress; 
	(work_queue.msgs[0]).buf[1] = value; 

	ret = ioctl(this->m_iFile, I2C_RDWR, (unsigned long)&work_queue);
	if(ret < 0)
		printf("error during I2C_RDWR ioctl with error code %d\n", ret);
#endif

	return 0;
}


I2C::~I2C()
{
	m_iUseCount--;
	if (m_iUseCount == 0)
		close(this->m_iFile);
}
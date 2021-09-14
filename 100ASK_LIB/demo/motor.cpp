#include "demo.h"
#include "motor.h"

void motor_test(void)
{
    MOTOR motor;
	
	motor.setSpeed(2);
   
    motor.motorForward(512); //正转一圈
	motor.motorStop(); //停止
	
	motor.motorReverse(512); //反转一圈
	motor.motorStop(); //停止
}

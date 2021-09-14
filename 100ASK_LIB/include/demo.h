#ifndef DEMO_H
#define DEMO_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <getopt.h>
#include <fcntl.h>

#include "gpio.h"
#include "led.h"
#include "keyboard.h"
#include "ds18b20.h"
#include "dh11.h"
#include "irda.h"
#include "sr501.h"
#include "sr04.h"
#include "motor.h"

#include "spi.h"
#include "dac_tlc5615.h"
#include "oled_ssd1306.h"
#include "adxl345.h"

#include "eeprom.h"
#include "rtc.h"

#define msleep(n) usleep(n*1000)

void led_test(int num);
void keyboard_test();
void ds18b20_test(int num);
void dh11_test(int num);
void irda_test(int num);
void sr501_test(int num);
void sr04_test(void);
void motor_test(void);

void dac_test(void);
void oled_test(void);
void adxl345_test1(int num);
void adxl345_test2(int num);

void eeprom_test1(int num);
void eeprom_test2(int num);
void rtc_test(int num);

#endif

#include "s3c6410macro.h"
#include "uart.h"
#include "vic.h"
#include "time.h"
#include "led.h"
#include "adc.h"
#include "lcd.h"
#include "ds18b20.h"
//**************************************************
//函数 :    void delay(u32 del) 
//功能 :    延时 
//参数 :    整型
//返回 :    无 
//说明 :    通过消耗CPU来实现延时，时间不准确，不线性 
//**************************************************
void delay(u32 del)
{
  while(del--);
}
void devInit(void)
{
	ledPortInit();
	gpioConfigEi();
	vicInit();

	pwm1Init();
//	watchdogInit();	
	adcInit();
	time4Init();
}
void tsInit(void)
{
	rADCTSC =0X0D3;//11010011b
}
void Main()
{
	int temper=0;
	devInit();
//	tsInit();
	//initLcdPort();
//	initLcd();
	//clearScr(0xffffff);
	//for(i=10;i<100;i++)
//	disPoint(i,0,0xff0000);
	while(1)
	{
	 //temper=DS18B20_ReadTemper();
	//uartPrintf("the temperature is:%d.%d\n",temper/100,temper%100);
	//delay(6000000);
	}
}

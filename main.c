
#include "s3c6410macro.h"
#include "uart.h"
#include "vic.h"
#include "time.h"
#include "led.h"
#include "adc.h"
#include "lcd.h"
#include "ds18b20.h"
//**************************************************
//���� :    void delay(u32 del) 
//���� :    ��ʱ 
//���� :    ����
//���� :    �� 
//˵�� :    ͨ������CPU��ʵ����ʱ��ʱ�䲻׼ȷ�������� 
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

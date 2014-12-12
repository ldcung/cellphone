#include "s3c6410macro.h"

#define AD12 16
void adcInit(void)
{
	rADCCON =0;
	rADCCON |=1<<AD12;//12 BIT adc
	//rADCCON |=1<<14;
//	rADCCON |=5<<6;	
}
unsigned int adConv(void)
{
	rADCCON |=1;//ADC START
	while(rADCCON & 1);//
	while(!(rADCCON & (1<<15)));//
    return rADCDATA0 & 0xFFF;//		
}

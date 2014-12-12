//#include "uart.h"
#include "s3c6410macro.h"
#include <stdio.h>
#include <stdarg.h>
void uart0Init(void)
{
	rGPACON  &=~0xff;
	rGPACON |=0x22;//config rxd,txd
	rULCON0 =0x03;//frame
	rUCON0  =0x805;//pclk choose
	rUBRDIV0 =(unsigned)PCLK / (115200*16) -1;//baund rate

}
void putChar(char dat)
{
	while(!(rUTRSTAT0 & 0x04));
	rUTXH0=dat;//SEND A CHAR	
}
void putString(char *p)
{
	while(*p)
	{
		putChar(*p);
		p++;	
	}
}
void putNum(unsigned char num)
{
	putChar('0'+num/100%10);
	putChar('0'+num/10%10);
	putChar('0'+num%10);
}
void uartPrintf(char * fmt, ...)
{
	char buf[256];
	
	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buf, fmt, argptr);
	va_end(argptr);
	
	putString(buf);	
}

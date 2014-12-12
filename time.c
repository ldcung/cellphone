#include "s3c6410macro.h"
#include "uart.h"
u32 pwmTime=1500;
void watchdogInit(void)
{
//	rWTDAT =16176;
//	rWTCNT =0x8000;
	rWTCNT =10000;
	rWTCON =0xf039;
}
void time4Init(void)
{
//----------------------------f=1Mhz
	rTCFG0 &=~(0XFF<<8);
	rTCFG0 |=65<<8;
	rTCFG1 &=~(0XF<<16);
//-----------------------------------
    rTCNTB4=500000;
    rTCON |=3<<21;
    rTCON &=~(1<<21);//clear manual
    rTCON |=1<<20;
    rTINT_CSTAT |=1<<9;//CLEAR INITER FLAG
    rTINT_CSTAT |=1<<4;//ENABLE INTERRUPT
}
/*
void pwm1Init(void)
{
	rGPFCON &=~((unsigned)3<<30);
	rGPFCON |=(unsigned)1<<31;
	rGPFPUD &=~((unsigned)3<<30);
	//--------------------
	rTCFG0 &=~0xff;
	rTCFG0 |=65;
	rTCFG1 &=~(0xf<<4);
	//-------------------
	rTCNTB1=2000;
	rTCMPB1=pwmTime;
	rTCON |=5<<9;
	rTCON &=~(1<<9);//clear manual
	rTCON |=1<<8;//start time1
	rTINT_CSTAT |=1<<6;//clear time1 interrupt flag
	rTINT_CSTAT |=1<<1;//enable time1 interrupt
}*/
void pwm1Init(void)
{
//	rTCON &=~(1<<8);//TIME1 off
	rGPFCON &=~(0x3<<30);
	rGPFCON |=(unsigned)2<<30;//gpf pwmout
	rTCFG0 &=~0xff;
	rTCFG0 |=65;//
	rTCFG1 &=~(0xff<<4);//
	rTCNTB1 =2000;
	rTCMPB1 =pwmTime;
//	rTCON |=1<<11;//AUTO RELOAD
    rTCON |=5<<9;
	rTCON &=~(1<<9);//clear manual
	rTCON |=1<<8;//TIME1 START
	
	rTINT_CSTAT |=1<<6;//clear interupt flag
	rTINT_CSTAT |=1<<1;//enable inter
}
u8 pwmoff=0;
void __irq time4_isr(void)
{
  //user code
   pwmoff++;
  uartPrintf("the last time:%d\n",pwmoff);
  /*
  rTCMPB1=pwmTime;
  rWTCNT =10000;
  	//rWTCNT =16176;
  if(pwmTime>10)
  	pwmTime--;
  //else
  	//pwmTime=1000;
  	*/
  rTINT_CSTAT |=1<<9;//CLEAR INITER FLAG
  rVIC0ADDRESS=0;		
}
void __irq pwm_time1_isr(void)
{
	//
   
  //	if(pwmoff>20)
	rTCON &=~(1<<8);//TIME1 OFF
	rTINT_CSTAT |=1<<6;//clear time1 interrupt flag	
	rVIC0ADDRESS=0;
}

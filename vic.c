#include "s3c6410macro.h"
#include "uart.h"
#include "vic.h"
#include "time.h"
void gpioConfigEi(void)
{
	rGPNCON &=~0xfff;
	rGPNCON |= 0xaaa;//EXTENAL INTERRUPT
	rEINT0CON0 &= ~0xFFF;
	rEINT0CON0 |= 0x333;//FALILLING EDAGE
	rEINT0MASK &=~0x3f;//ENABLE
	//	
}
void vicInit(void)
{
    rVIC0INTSELECT=0;//irq
    rVIC1INTSELECT=0;//IRQ
    rVIC0INTENABLE|=0X03;//
    rVIC0INTENABLE |=1<<28;//TIME4
    rVIC0INTENABLE |=1<<24;//TIME1
    rVIC1INTENABLE |=1<<30;//ts UPDOWN
    rVIC1INTENABLE |=(unsigned)1<<31;//adc
    rVIC0VECTADDR0=(unsigned int)eint03_isr;
    rVIC0VECTADDR1=(unsigned int)eint45_isr;
    rVIC0VECTADDR24=(unsigned int)pwm_time1_isr;
    rVIC0VECTADDR28=(unsigned int)time4_isr;
    rVIC1VECTADDR30=(unsigned int)touch_isr;
    rVIC0ADDRESS=0;	
    rVIC1ADDRESS=0;
    uartPrintf("function is:%x\n",(unsigned int)touch_isr);
}
void __irq eint03_isr(void)
{
    putString("i am here!\n");
    if(rEINT0PEND & 0x01)
    {
    	//USER CODE
    	rEINT0PEND |=0x01;
    }
     if(rEINT0PEND & 0x02)
    {
    	//USER CODE
    	rEINT0PEND |=0x02;
    }
     rVIC0ADDRESS=0;	 
}
void __irq eint45_isr(void)
{
  rVIC0ADDRESS=0;		
}
void __irq touch_isr(void)
{
//	uartPrintf("i am here");
	
	if(rADCUPDW & UP)
	{
	    rADCTSC =0X0D3;
		putString("up interrupt!\n");
			
	}
		if(rADCUPDW & DW)
	{
		rADCTSC =0X1D3;	
	    putString("down interrupt!\n");
	    //enable adc conv
	}
	
	rADCCLRINT=0x1;//clear adc interrupt flag
	rADCCLRUDINT=0x1;//clear ts interrupt flag
	rVIC1ADDRESS=0;
	rVIC0ADDRESS=0;
}

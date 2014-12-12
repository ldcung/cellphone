#ifndef __S3C6410_MACRO_H
#define __S3C6410_MACRO_H

typedef unsigned char u8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long u32;

#define rGPMCON (*(volatile unsigned*)(0x7f008820))
#define rGPMDAT (*(volatile unsigned*)(0x7f008824))
#define rGPMPUD (*(volatile unsigned*)(0x7f008828))//led
#define rGPNCON (*(volatile unsigned*)(0x7f008830))
#define rGPNDAT (*(volatile unsigned*)(0x7f008834))
#define rGPNPUD (*(volatile unsigned*)(0x7f008838))//key

#define rGPECON (*(volatile unsigned*)(0x7f008080))
#define rGPEDAT (*(volatile unsigned*)(0x7f008084))
#define rGPEPUD (*(volatile unsigned*)(0x7f008088))

#define rGPFCON (*(volatile unsigned*)(0x7f0080A0))
#define rGPFDAT (*(volatile unsigned*)(0x7f0080A4))
#define rGPFPUD (*(volatile unsigned*)(0x7f0080A8))//PWM
//-----------------------------------------------------
//-------------------------------------------------uart
#define rGPACON 	(*(volatile unsigned*)(0x7f008000))
#define rGPAPUD 	(*(volatile unsigned*)(0x7f008008))
#define rULCON0 	(*(volatile unsigned*)(0x7f005000))
#define rUCON0  	(*(volatile unsigned*)(0x7f005004))
#define rUFCON0  	(*(volatile unsigned*)(0x7f005008))
#define rUMCON0  	(*(volatile unsigned*)(0x7f00500c))
#define rUTRSTAT0   (*(volatile unsigned*)(0x7f005010))
#define rUTXH0  	(*(volatile unsigned*)(0x7f005020))
#define rURXH0  	(*(volatile unsigned*)(0x7f005024))
#define rUBRDIV0  	(*(volatile unsigned*)(0x7f005028))
#define PCLK 66000000
//-----------------------------------------------------interrupt
#define rEINT0CON0 			(*(volatile unsigned*)(0x7f008900))
#define rEINT0MASK 			(*(volatile unsigned*)(0x7f008920))
#define rEINT0PEND 			(*(volatile unsigned*)(0x7f008924))
#define rEINT0FLTCON0   	(*(volatile unsigned*)(0x7f008910))//FLT

#define rVIC0INTSELECT 		(*(volatile unsigned*)(0x7120000C))
#define rVIC1INTSELECT 		(*(volatile unsigned*)(0x7130000C))
#define VIC0VECTADDR 		(*(volatile unsigned*)(0x71200100))
#define rVIC0INTENABLE 		(*(volatile unsigned*)(0x71200010))
#define rVIC1INTENABLE 		(*(volatile unsigned*)(0x71300010))
#define rVIC0VECTADDR0 		(*(volatile unsigned*)(0x71200100))
#define rVIC0VECTADDR1 		(*(volatile unsigned*)(0x71200104))

#define rVIC0VECTADDR24 	(*(volatile unsigned*)(0x71200160))
#define rVIC0VECTADDR27 	(*(volatile unsigned*)(0x7120016c))
#define rVIC0VECTADDR28 	(*(volatile unsigned*)(0x71200170))

#define rVIC1VECTADDR0 		    (*(volatile unsigned*)(0x71300100))
#define rVIC1VECTADDR30 		(*(volatile unsigned*)(0x71300178))

#define rVIC0INTENCLEAR 	(*(volatile unsigned*)(0x71200014))
#define rVIC1INTENCLEAR 	(*(volatile unsigned*)(0x71300014))
#define rVIC0ADDRESS		(*(volatile unsigned*)(0x71200f00))
#define rVIC1ADDRESS 		(*(volatile unsigned*)(0x71300f00))//vic
//-----------------------------------------------------TIME
#define rTCFG0 		(*(volatile unsigned*)(0x7f006000))
#define rTCFG1 		(*(volatile unsigned*)(0x7f006004))
#define rTCON  		(*(volatile unsigned*)(0x7f006008))
#define rTCNTB0     (*(volatile unsigned*)(0x7f00600c))
#define rTCMPB0     (*(volatile unsigned*)(0x7f006010))
#define rTCNT00     (*(volatile unsigned*)(0x7f006014))
#define rTCNTB1     (*(volatile unsigned*)(0x7f006018))
#define rTCMPB1     (*(volatile unsigned*)(0x7f00601c))
#define rTCNT01     (*(volatile unsigned*)(0x7f006020))

#define rTCNTB2     (*(volatile unsigned*)(0x7f006024))
#define rTCMPB2     (*(volatile unsigned*)(0x7f006028))
#define rTCNT02     (*(volatile unsigned*)(0x7f00602c))

#define rTCNTB3 	(*(volatile unsigned*)(0x7f006030))
#define rTCMPB3 	(*(volatile unsigned*)(0x7f006034))
#define rTCNT03 	(*(volatile unsigned*)(0x7f006038))
#define rTCNTB4 	(*(volatile unsigned*)(0x7f00603c))
#define rTCNTB04 	(*(volatile unsigned*)(0x7f006040))
#define rTINT_CSTAT (*(volatile unsigned*)(0x7f006044))

#define rWTCON 		(*(volatile unsigned*)(0x7e004000))
#define rWTDAT 		(*(volatile unsigned*)(0x7e004004))
#define rWTCNT 		(*(volatile unsigned*)(0x7e004008))
#define rWTCLRINT 	(*(volatile unsigned*)(0x7e00400c))
//-----------------------------------------------------adc
#define rADCCON   (*(volatile unsigned*)(0x7E00B000))
#define rADCDATA0 (*(volatile unsigned*)(0x7E00B00C))
#define rADCTSC    (*(volatile unsigned*)(0x7E00B004))
#define rADCUPDW   (*(volatile unsigned*)(0x7E00B014))
#define rADCCLRINT    	(*(volatile unsigned*)(0x7E00B018))
#define rADCCLRUDINT    (*(volatile unsigned*)(0x7E00B020))
//-----------------------------------------------------
#define UP 2
#define DW 1
#endif

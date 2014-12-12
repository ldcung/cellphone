#include "s3c6410macro.h"
void ledPortInit(void)
{
	rGPMCON &= ~0xffff;//rGPMCON = rGPMCON & (~0XFFFF);
	rGPMCON |= 0x1111;/*配置GPM(0-3)为基本输入输出口，方向为输出*/	
}

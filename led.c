#include "s3c6410macro.h"
void ledPortInit(void)
{
	rGPMCON &= ~0xffff;//rGPMCON = rGPMCON & (~0XFFFF);
	rGPMCON |= 0x1111;/*����GPM(0-3)Ϊ������������ڣ�����Ϊ���*/	
}

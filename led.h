#ifndef __LED_H__
#define __LED_H__
#define LEDON()     rGPMDAT &=~1;//����LED��
#define LEDOFF() 	rGPMDAT |=1; //���LED��
void ledPortInit(void);
#endif

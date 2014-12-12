#ifndef __LED_H__
#define __LED_H__
#define LEDON()     rGPMDAT &=~1;//µ„¡¡LEDµ∆
#define LEDOFF() 	rGPMDAT |=1; //√µÙLEDµ∆
void ledPortInit(void);
#endif

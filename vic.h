#ifndef __VIC_H__
#define __VIC_H__
void gpioConfigEi(void);
void vicInit(void);
void __irq eint03_isr(void);
void __irq eint45_isr(void);
void __irq touch_isr(void);
#endif

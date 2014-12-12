#ifndef __TIME_H__
#define __TIME_H__
void time4Init(void);
void pwm1Init(void);
void __irq time4_isr(void);
void __irq pwm_time1_isr(void);
void watchdogInit(void);
#endif

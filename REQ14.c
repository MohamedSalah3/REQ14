/*
 * REQ14.c
 *
 * Created: 25/01/2020 12:28:18 ص
 *  Author: mo
 */
#include "softwareDelay.h"
#include "timers.h"
#include "Interrupts.h"
#include "registers.h"
#include "std_types.h"
volatile uint32_t u32_ovf_counter=0;
int main(void)
{
	uint8_t u8_duty=0;
PORTC_DIR |=0xff;
timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_1024 ,0,100,T0_INTERRUPT_CMP);
//timer2Init(T2_NORMAL_MODE,T2_OC2_DIS,T2_PRESCALER_1024,0,0,0,T0_POLLING);
gpioPortDirection(GPIOB,OUTPUT);
gpioPortDirection(GPIOD,OUTPUT);
gpioPortWrite(GPIOB,LOW);
gpioPortWrite(GPIOD,LOW);
    while(1)
    {	//u8_duty=10;
		timer0SwPWM(u8_duty++,0);
		//timer2Start();
		//timer2DelayMs(100);
		softwareDelayMs(1000);
	}
}
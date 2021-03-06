/*
 * Interrupts.c
 *
 * Created: 21/01/2020 01:18:13 م
 *  Author: mo
 */
//#include "pushButton.h"
#include "timers.h"
#include "Interrupts.h"
ptr_to_Fun INT0_external_interrupt;
ptr_to_Fun INT1_external_interrupt;
ptr_to_Fun INT2_external_interrupt=check_button;
ptr_to_Fun TIMER2COMP;
ptr_to_Fun TIMER2OVF;
ptr_to_Fun TIMER1CAPT;
ptr_to_Fun TIMER1COMPA;
ptr_to_Fun TIMER1COMPB;
ptr_to_Fun TIMER1OVF;
ptr_to_Fun TIMER0COMP=Timer_interrupt_COMP_routine;
ptr_to_Fun TIMER0OVF_INT=Timer_interrupt_routine;
ptr_to_Fun SPI_STC;
ptr_to_Fun USART_RXC;
ptr_to_Fun USART_UDRE;
ptr_to_Fun USART_TXC;
ptr_to_Fun ADC_INT;
ptr_to_Fun EE_RDY;
ptr_to_Fun ANA_COMP;
ptr_to_Fun TWI_I2C;
ptr_to_Fun SPM_RDY;

void G_interrupt_Enable(void)
{
//	sei();
 SREG |=(0x80);
}
void EX_interrupt_enable2(void)
{

SET_BIT(GICR,INT2);
SET_BIT(MCUCSR,6);
}
void G_interrupt_Disable(void)
{

CLEAR_BIT(SREG,7);
}
void __vector_1(void) __attribute__((signal,__INTR_ATTRS));
void __vector_1(void)
{
  INT0_external_interrupt();
}


void __vector_2(void) __attribute__((signal,__INTR_ATTRS));
void __vector_2(void)
{
  INT1_external_interrupt();
}


void __vector_3(void) __attribute__((signal,__INTR_ATTRS));
void __vector_3(void)
{
  INT2_external_interrupt();
}


void __vector_4(void) __attribute__((signal,__INTR_ATTRS));
void __vector_4(void)
{
TIMER2COMP();
}


void __vector_5(void) __attribute__((signal,__INTR_ATTRS));
void __vector_5(void)
{
  TIMER2OVF();
}

void __vector_6(void) __attribute__((signal,__INTR_ATTRS));
void __vector_6(void)
{
  TIMER1CAPT();
}

void __vector_7(void) __attribute__((signal,__INTR_ATTRS));
void __vector_7(void)
{
TIMER1COMPA();
}

void __vector_8(void) __attribute__((signal,__INTR_ATTRS));
void __vector_8(void)
{
  TIMER1COMPB();
}

void __vector_9(void) __attribute__((signal,__INTR_ATTRS));
void __vector_9(void)
{
  TIMER1OVF();
}

void __vector_10(void) __attribute__((signal,__INTR_ATTRS));
void __vector_10(void)
{

  TIMER0COMP();
}

void __vector_11(void) __attribute__((signal,__INTR_ATTRS));
void __vector_11(void)
{

  TIMER0OVF_INT();
}

void __vector_12(void) __attribute__((signal,__INTR_ATTRS));
void __vector_12(void)
{
  SPI_STC();
}

void __vector_13(void) __attribute__((signal,__INTR_ATTRS));
void __vector_13(void)
{
  USART_RXC();
}

void __vector_14(void) __attribute__((signal,__INTR_ATTRS));
void __vector_14(void)
{
  USART_UDRE();
}

void __vector_15(void) __attribute__((signal,__INTR_ATTRS));
void __vector_15(void)
{
  USART_TXC();
}

void __vector_16(void) __attribute__((signal,__INTR_ATTRS));
void __vector_16(void)
{
  ADC_INT();
}

void __vector_17(void) __attribute__((signal,__INTR_ATTRS));
void __vector_17(void)
{
  EE_RDY();
}

void __vector_18(void) __attribute__((signal,__INTR_ATTRS));
void __vector_18(void)
{
  ANA_COMP();
}

void __vector_19(void) __attribute__((signal,__INTR_ATTRS));
void __vector_19(void)
{
  TWI_I2C();
}

void __vector_20(void) __attribute__((signal,__INTR_ATTRS));
void __vector_20(void)
{
  SPM_RDY();
}

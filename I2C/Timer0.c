/*
 * Timer0.c
 *
 *  Created on: Apr 6, 2017
 *      Author: Mohamed Tarek
 */
#include "Datatypes.h"
#include "Timer0_cfg.h"
#include "DIO.h"
#include "Registers.h"
#include "Macros.h"
#include "AVR/interrupt.h"

void(*Gptr)(void) ;

void Timer0_init(void)
{
	TCCR0 = TIMER0_MODE | OC0_PIN_FUNC | PRESCALER;

#if(TIMER0_MODE == CTC)
	OCR0 = CTC_COMP_VALUE;
#endif

#if((TIMER0_INT_EN == TRUE) && (TIMER0_MODE == CTC))
	TIMSK = 0b00000010;
	SET_BIT(SREG,7);
#elif((TIMER0_INT_EN == TRUE) &&(TIMER0_MODE == OVF))
	SET_BIT(SREG,7);
	TIMSK =	0b00000001;

#endif
}

void Timer0_Preload_ForceComp(void)
{
	SET_BIT(TCCR0,7);
}

void Timer0_CTC_CompValue(u8 Value)
{
#if(TIMER0_MODE == CTC)
	OCR0 = Value;
#endif
}

u8 Timer0_GetIntFlag(void)
{
#if(TIMER0_MODE == OVF)
	return TIFR;
#elif(TIMER_MODE == CTC)
	return (GET_BIT(TIFR,1));
#endif
}

void Timer0_ClearIntFlag(void)
{
#if(TIMER0_MODE == OVF)
	CLEAR_BIT(TIFR,0);
#elif(TIMER_MODE == CTC)
	CLEAR_BIT(TIFR,1);
#endif
}


void Timer0_Set_OVF_ISR( void(*ptr)(void))
{
	Gptr = ptr;

}

ISR(TIMER0_OVF_vect)
{
	Gptr();
}


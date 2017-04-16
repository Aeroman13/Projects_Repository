/*
 * PWM1.c
 *
 *  Created on: Apr 9, 2017
 *      Author: Mohamed Tarek
 */
#include "Registers.h"
#include "Datatypes.h"
#include "DIO.h"
#include "PWM1_cfg.h"
#undef F_CPU
#define F_CPU 16000000ul

static f32 T_PWM;
static f32 NO_ticks_cycle;


void PWM_init(void)
{
	TCCR1A = PWM_PINS | 0b00000010;
	TCCR1B = 0b00011000 | PRESCALER;

#if(PWM_PINS == OC1A)
	DIO_SetPinDirection(3,5,OUTPUT);
#elif(PWM_PINS == OC1B)
	DIO_SetPinDirection(3,4,OUTPUT);
#elif(PWM_PINS == OC1AB)
	DIO_SetPinDirection(3,5,OUTPUT);
	DIO_SetPinDirection(3,4,OUTPUT);
#endif
}

void PWM_SetFreq(f32 Freq_PWM)
{
//	f32 T_tick = 1/(16000000/PRESCALER_VALUE);
// Freq_tick = F_CPU/PRESCALER_VALUE =1/ T_tick
//	NO_ticks_cycle = T_cycle / T_tick;
	T_PWM = 1/Freq_PWM;
	NO_ticks_cycle = (F_CPU)/(Freq_PWM *PRESCALER_VALUE);
	ICR1A = NO_ticks_cycle;
}


void PWM_SetDutyCycle1A(f32 DutyCycle1A)
{
#if((PWM_PINS == OC1A) || (PWM_PINS == OC1AB))
	f32 value =(DutyCycle1A * NO_ticks_cycle)/(T_PWM * 1000);
	OCR1A = value;
#endif
}



void PWM_SetDutyCycle1B(f32 DutyCycle1B)
{
#if((PWM_PINS == OC1B) || (PWM_PINS == OC1AB))
	f32 value =(DutyCycle1B * NO_ticks_cycle)/(T_PWM * 1000);
	OCR1B = value;
#endif
}


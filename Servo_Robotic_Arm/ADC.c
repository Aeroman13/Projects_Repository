/*
 * ADC.c
 *
 *  Created on: Mar 31, 2017
 *      Author: Mohamed Tarek
 */

#include "Datatypes.h"
#include "ADC_cfg.h"
#include "Macros.h"
#include "Registers.h"

void ADC_init(void)
{
	ADMUX = REF_VOLTAGE_SOURCE | (LEFT_ADJUST<<5)  |INITIAL_CHANNEL ;
	ADCSRA = (ADC_EN << 7) | SELECT_MODE | (ADC_INT_EN << 3) | ADC_PRESCALLER;

#if(SELECT_MODE == AUTO_TRIGGER)
	SFIOR = TRIG_SOURCE;
	#if(TRIG_SOURCE == FREE_RUNNING)
		SET_BIT(ADCSRA,6);
	#endif
#endif

#if(ADC_INT_EN == TRUE)
	SET_BIT(SREG,7);
#endif
}

void ADC_StartConversion(void)
{
	SET_BIT(ADCSRA,6);
#if((SELECT_MODE == AUTO_TRIGGER) && (TRIG_SOURCE == FREE_RUNNING))
#warning "Conversion already started in ADC_init Function"
#endif

}

u8 ADC_GetIntFlag(void)
{
	return GET_BIT(ADCSRA,4);
}

void ADC_ClearIntFlag(void)
{
#if(ADC_INT_EN == FALSE)
	SET_BIT(ADCSRA,4);
#endif
}

void ADC_DataAdjustment(u8 adj)
{
	if(adj == LEFT)
	{
		SET_BIT(ADMUX,5);
	}
	else if(adj == RIGHT)
	{
		CLEAR_BIT(ADMUX,5);
	}
	else{}
}

u16 ADC_Read_10Bit(void)
{
	return ADCLH;
}

u8 ADC_Read_8Bit(void)
{
	return ADCH;

}

void ADC_ChangeChannel(u8 Channel)
{
	ADMUX |= Channel;
}



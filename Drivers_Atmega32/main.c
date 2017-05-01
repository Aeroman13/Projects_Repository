/*
 * main.c
 *
 *  Created on: Apr 21, 2017
 *      Author: Mohamed Tarek
 */
#undef F_CPU
#define FCPU 16000000ul
#include "DIO.h"
#include "Registers.h"
#include "Datatypes.h"
#include "avr/interrupt.h"
#include "UART.h"
#include "Macros.h"
#include "Keypad.h"
#include "PWM1.h"
#include "Buzzer.h"
//#include "util/delay.h"
f32 read;
f32 x;

int main(void)
{
	UART_init();
	PWM_init();
	PWM_SetFreq(447);
	while(1)
	{

		x = (read*100)/127;
		PWM_SetDutyCycle1A(x);

		if(GET_BIT(UCSRA,7) == 0)
		{
//			PWM_SetDutyCycle1A(0);
//			read=0;
		}

	}
	return 0;
}
ISR(USART_RXC_vect)
{
	read = UART_ReadData();

}


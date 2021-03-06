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
#include "util/delay.h"
#include "Macros.h"
#include "Keypad.h"



int main(void)
{
	u16 button;
	UART_init();
	Keypad_init();

	DIO_SetPinDirection(1,0,OUTPUT);
	while(1)
	{
		button = Keypad_ReadButton(0);
		_delay_ms(100);
		if(button == 0)
		{
			UART_TransmitData('b');
		}
	}
	return 0;
}
ISR(USART_RXC_vect)
{
	if(UART_ReadData() == 'a')
	{
		DIO_TogglePin(1,0);
	}
}


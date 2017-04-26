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



int main(void)
{
//	UCSRA = 0x00;
//	UCSRB = 0b10010000;
//	UCSRC = 0b10000110;
//	UBRRL = 104;		// Baud Rate = 9600 bps
//	SET_BIT(SREG,7);
	DIO_SetPinDirection(0,0,OUTPUT);
	UART_init();
	while(1)
	{

	}
	return 0;
}
ISR(USART_RXC_vect)
{
	if(UDR == 'a')
	{
		DIO_TogglePin(0,0);
	}
}


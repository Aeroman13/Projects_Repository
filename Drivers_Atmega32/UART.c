/*
 * UART.c
 *
 *  Created on: Apr 21, 2017
 *      Author: Mohamed Tarek
 */
#include "Datatypes.h"
#include "DIO.h"
#include "Macros.h"
#include "UART_cfg.h"
#include "Registers.h"

void UART_init(void)
{
	UCSRA = 0x0 | (DOUBLE_SPEED<<1) | (MULTI_PROCESSOR);
	UCSRB = (RECIEVE_INT_EN << 7)|(TRANSMIT_INT_EN<<6)|(UDR_EMPTY_INT_EN<<5)|(RECIEVE_EN<<4)|(TRANSMIT_EN<<3)|(CHARACTER_SIZE&(1<<2));
	UCSRC = SET_BIT(UCSRC,7)|(MODE<<6)|PARITY_MODE|(STOP_BIT<<3)|(GET_BIT(CHARACTER_SIZE,1)<<2)|(GET_BIT(CHARACTER_SIZE,0)<<1);
#if(BAUD_RATE <= 255)
	UBRRL =BAUD_RATE;
#else
	CLEAR_BIT(UCSRC,7);		// For HIGHER BAUD Rates
	UBRRL =BAUD_RATE;
	URRLH |=0b00000001;
#endif

#if(TRANSMIT_INT_EN == ON)|| (RECIEVE_INT_EN == ON)|| (UDR_EMPTY_INT_EN == ON)
	SET_BIT(SREG,7);
#endif
}

u16 UART_ReadData(void)
{
	u16 read;
#if(CHARACTER_SIZE == BIT_9)
	read = (GET_BIT(UCSRB,1)<<8);		// read ninth bit
#endif
	read =UDR;						// read low eight bits
	return read;
}

void UART_TransmitData(u16 Data)
{
	while(GET_BIT(UCSRA,5) != 1);
#if(CHARACTER_SIZE == BIT_9)
	CLEAR_BIT(UCSRB,0);			// atmn enha fadya :)
	UCSRB = GET_BIT(Data,8);
#endif
	UDR = Data;
#if(TRANSMIT_INT_EN == OFF)
	CLEAR_BIT(UCSRA,6);
#endif
}

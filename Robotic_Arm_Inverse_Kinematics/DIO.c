/*
 * DIO.c
 *
 *  Created on: Mar 6, 2017
 *      Author: Mohamed Tarek
 */
// This is the DIO Driver of the Mcal (Micro Controller Abstraction Layer) which protects the application form the H/W
#include "Datatypes.h"
#include"Registers.h"
#include"Macros.h"



		// DIO _ Pin
void DIO_SetPinDirection(u8 Port_Number, u8 Pin_Number, u8 Direction){
	volatile u8 *arr[4] = { &DDRA, &DDRB, &DDRC, &DDRD};
	if(Direction == 0)
	{			// input pin
		CLEAR_BIT(*arr[Port_Number],Pin_Number);
	}
	else
	{
		SET_BIT(*arr[Port_Number],Pin_Number);
	}
}

void DIO_SetPinValue(u8 Port_Number, u8 Pin_Number, u8 Value){
	volatile u8 *arr[4]= { &PORTA, &PORTB, &PORTC, &PORTD };

	if(Value == 0)
	{
		CLEAR_BIT(*arr[Port_Number],Pin_Number);
	}
	else
	{
		SET_BIT(*arr[Port_Number],Pin_Number);
	}

}

u8 DIO_GetPinValue(u8 Port_Number, u8 Pin_Number){
	u8 Return_Value;
	volatile u8 *arr[4] = { &PINA, &PINB, &PINC, &PIND };

	Return_Value = GET_BIT(*arr[Port_Number], Pin_Number);
	return Return_Value;
}

void DIO_TogglePin(u8 Port_Number, u8 Pin_Number){
	volatile u8 *arr[4] = { &PORTA, &PORTB,&PORTC,&PORTD};
	TOGGLE_BIT(*arr[Port_Number],Pin_Number);
}

		// DIO _ Port
void DIO_SetPortDirection(u8 Port_Number, u8 Direction){
	volatile u8 *arr[4] = { &DDRA, &DDRB, &DDRC, &DDRD};
	if(Direction == 0)
	{
		*arr[Port_Number] = 0;
	}
	else
	{
		*arr[Port_Number] = 0b11111111;
	}

}

void DIO_SetPortValue(u8 Port_Number, u8 Value)
{
	volatile u8 *arr[4] = { &PORTA, &PORTB, &PORTC, &PORTD};

	*arr[Port_Number] = Value;
}

u8 DIO_GetPortValue(u8 Port_Number){
	u8 Return_Value;
	volatile u8 *arr[4] = { &PINA, &PINB, &PINC, &PIND};

	Return_Value = *arr[Port_Number];
	return Return_Value;
}

		// Hit_Pin Directly (Bonus)	Pin_Number 0 - 31
void DIO_PinDirection(u8 Pin_Number, u8 Direction){
	volatile u8 *arr[4] = { &DDRA, &DDRB, &DDRC, &DDRD};
	u8 Port_Number = Pin_Number / 8;
	Pin_Number = Pin_Number % 8;

	if(Direction == 0)
		{			// input pin
			CLEAR_BIT(*arr[Port_Number],Pin_Number);
		}
		else
		{
			SET_BIT(*arr[Port_Number],Pin_Number);
		}

}

void DIO_PinValue(u8 Pin_Number, u8 Value){
	volatile u8 *arr[4] = { &PORTA, &PORTB, &PORTC, &PORTD};
	u8 Port_Number = Pin_Number / 8;
	Pin_Number = Pin_Number % 8;
	if(Value == 0)
	{
		CLEAR_BIT(*arr[Port_Number],Pin_Number);
	}
	else
	{
		SET_BIT(*arr[Port_Number],Pin_Number);
	}
}

u8 DIO_GetPin(u8 Pin_Number){
	volatile u8 *arr[4] = { &PINA, &PINB, &PINC, &PIND};
	u8 Port_Number = Pin_Number / 8;
	Pin_Number = Pin_Number % 8;
	u8 Return_Value;
	Pin_Number = Pin_Number % 8;

	Return_Value =GET_BIT(*arr[Port_Number],Pin_Number);
	return Return_Value;
}

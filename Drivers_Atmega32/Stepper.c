/*
 * DIO_Stepper.c
 *
 *  Created on: Mar 23, 2017
 *      Author: Mohamed Tarek
 */
#undef F_CPU
#define F_CPU 16000000ul
#include "util/delay.h"
#include "DIO.h"
#include "Datatypes.h"
#include "Stepper_cfg.h"
#include "Stepper.h"

static u8 Status;
void Stepper_init(void)
{
	DIO_SetPinDirection(STEPPER_PORT,A,OUTPUT);
	DIO_SetPinDirection(STEPPER_PORT,B,OUTPUT);
	DIO_SetPinDirection(STEPPER_PORT,C,OUTPUT);
	DIO_SetPinDirection(STEPPER_PORT,D,OUTPUT);

}

void StepperFullWave(u8 Direction, u16 Delay)
{
	u8 i=0;
	u8 Coil[8] = {A,B,C,D,D,C,B,A};


	for(i=Direction - 4;i<Direction;i++)
	{
		DIO_SetPinValue(STEPPER_PORT,A,0);
		DIO_SetPinValue(STEPPER_PORT,B,0);
		DIO_SetPinValue(STEPPER_PORT,C,0);
		DIO_SetPinValue(STEPPER_PORT,D,0);
		DIO_SetPinValue(STEPPER_PORT,Coil[i],1);
		_delay_ms(Delay);
	}
	Status = Direction;
}

void StepperHalfWave(u8 Direction, u16 Delay)
{
	u8 i=0;
	u8 Coil[8] = {A,B,C,D,D,C,B,A};
	for(i = Direction - 4; i<Direction; i++)
	{
		DIO_SetPinValue(STEPPER_PORT,A,0);
		DIO_SetPinValue(STEPPER_PORT,B,0);
		DIO_SetPinValue(STEPPER_PORT,C,0);
		DIO_SetPinValue(STEPPER_PORT,D,0);
		DIO_SetPinValue(STEPPER_PORT,Coil[i],1);
		_delay_ms(Delay);
		if(i == 3)
		{
			DIO_SetPinValue(STEPPER_PORT,Coil[0],1);
			_delay_ms(Delay);
		}
		else
		{
			DIO_SetPinValue(STEPPER_PORT,Coil[i+1],1);
			_delay_ms(Delay);
		}
	}
	Status = Direction;
}

void Stepper_Break()
{
	DIO_SetPinValue(STEPPER_PORT,A,1);
	DIO_SetPinValue(STEPPER_PORT,B,1);
	DIO_SetPinValue(STEPPER_PORT,C,1);
	DIO_SetPinValue(STEPPER_PORT,D,1);
	Status = STOP;
}

void Stepper_Free()
{
	DIO_SetPinValue(STEPPER_PORT,A,0);
	DIO_SetPinValue(STEPPER_PORT,B,0);
	DIO_SetPinValue(STEPPER_PORT,C,0);
	DIO_SetPinValue(STEPPER_PORT,D,0);
	Status = STOP;
}

u8 Stepper_Status()
{
	return Status;
}

/*
 * Motor_Relay.c
 *
 *  Created on: Mar 18, 2017
 *      Author: Mohamed Tarek
 */
#include "MotorRelay_cfg.h"
#include "Datatypes.h"
#include "DIO.h"
#include "MotorRelay.h"
static u8 status;

void MotorRelay_init(void){
	DIO_SetPinDirection(MotorPort,MotorPin1,OUTPUT);
	DIO_SetPinDirection(MotorPort,MotorPin2,OUTPUT);
	DIO_SetPinValue(MotorPort,MotorPin1,0);
	DIO_SetPinValue(MotorPort,MotorPin2,0);
	status =STOP;
}

void MotorRelay_Right(void){
	DIO_SetPinValue(MotorPort,MotorPin1,1);
	DIO_SetPinValue(MotorPort,MotorPin2,0);
	status =RIGHT;
}

void MotorRelay_Left(void){
	DIO_SetPinValue(MotorPort,MotorPin1,0);
	DIO_SetPinValue(MotorPort,MotorPin2,1);
	status =LEFT;
}

void MotorRelay_Free(void){
	DIO_SetPinValue(MotorPort,MotorPin1,0);
	DIO_SetPinValue(MotorPort,MotorPin2,0);
	status =STOP;
}
void MotorRelay_Break(void){
	DIO_SetPinValue(MotorPort,MotorPin1,1);
	DIO_SetPinValue(MotorPort,MotorPin2,1);
	status =STOP;
}

u8 MotorRelay_Status(void){
	return status;
}




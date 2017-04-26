/*
 * DIO.h
 *
 *  Created on: Mar 6, 2017
 *      Author: Mohamed Tarek
 */
// DIO Prototypes which will be include in the main.c to link application to functions body
#ifndef DIO_H_
#define DIO_H_

#include "Datatypes.h"
void DIO_SetPinDirection(u8 Port_Number, u8 Pin_Number, u8 Direction);
void DIO_SetPinValue(u8 Port_Number, u8 Pin_Number, u8 Value);
u8 DIO_GetPinValue(u8 Port_Number, u8 Pin_Number);
void DIO_TogglePin(u8 Port_Number, u8 Pin_Number);

void DIO_SetPortDirection(u8 Port_Number, u8 Direction);
void DIO_SetPortValue(u8 Port_Number, u8 Value);
u8 DIO_GetPortValue(u8 Port_Number);

// Hit_Pin Directly (Bonus)	Pin_Number 0 - 31
void DIO_PinDirection(u8 Pin_Number, u8 Direction);
void DIO_PinValue(u8 Pin_Number, u8 Value);
u8 DIO_GetPin(u8 Pin_Number);

#endif /* DIO_H_ */

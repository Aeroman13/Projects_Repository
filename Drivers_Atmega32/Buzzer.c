/*
 * Buzzer.c
 *
 *  Created on: Mar 16, 2017
 *      Author: Mohamed Tarek
 */
#undef F_CPU
#define F_CPU 16000000ul
#include "DIO.h"
#include "Buzzer_cfg.h"
#include "Datatypes.h"
#include "util/delay.h"
void Buzzer_init(){
	DIO_SetPinDirection(BUZZER_PORT,BUZZER_PIN,OUTPUT);
}

void Buzzer_ON(u16 F_Tone){

	DIO_SetPinValue(BUZZER_PORT,BUZZER_PIN,ON);
	_delay_us(F_Tone/2);
	DIO_SetPinValue(BUZZER_PORT,BUZZER_PIN,OFF);
	_delay_us(F_Tone/2);
}

void Buzzer_OFF(){
	DIO_SetPinValue(BUZZER_PORT,BUZZER_PIN,OFF);
}

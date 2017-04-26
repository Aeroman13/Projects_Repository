/*
 * Servo1.c
 *
 *  Created on: Apr 14, 2017
 *      Author: Mohamed Tarek
 */
#include "Servo1_cfg.h"
#include "PWM1_cfg.h"
#include "Registers.h"
#include "Datatypes.h"
#include "PWM1.h"

void Servo1_init(void)
{
#undef PWM_PINS
#define PWM_PINS	SERVO_PINS
#undef	PRESCALER
#define PRESCALER 	SERVO_PRESCALER
	PWM_init();
	PWM_SetFreq(SERVO_FREQ);

}

void Servo1A_Test(f32 Duty_Cycle)			// used to test the range of and get limits of servo
{
	PWM_SetDutyCycle1A(Duty_Cycle);
}


void Servo1A_SetAngle(f32 Angle)
{
#if(SERVO_1A == ON)
	f32 DutyCycle_Angle;
	DutyCycle_Angle = (((DUTY_CYCLE1A_180DEG - DUTY_CYCLE1A_0DEG)* Angle )/180)+ DUTY_CYCLE1A_0DEG;
	PWM_SetDutyCycle1A(DutyCycle_Angle);
#endif
}




void Servo1B_SetAngle(f32 Angle)
{
#if(SERVO_1B == ON)
	f32 DutyCycle_Angle;
	DutyCycle_Angle = (((DUTY_CYCLE1B_180DEG - DUTY_CYCLE1B_0DEG)* Angle )/180)+ DUTY_CYCLE1B_0DEG;
	PWM_SetDutyCycle1B(DutyCycle_Angle);
#endif
}


/*
 * Stepper.h
 *
 *  Created on: Mar 24, 2017
 *      Author: Mohamed Tarek
 */

#ifndef STEPPER_H_
#define STEPPER_H_

#define STOP 0
#define RIGHT 4
#define LEFT 8
void Stepper_init(void);
void StepperFullWave(u8 Direction, u16 Delay);
void StepperHalfWave(u8 Direction, u16 Delay);
void Stepper_Break();
void Stepper_Free();
u8 Stepper_Status();

#endif /* STEPPER_H_ */

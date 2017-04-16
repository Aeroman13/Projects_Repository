/*
 * MotorRelay.h
 *
 *  Created on: Mar 18, 2017
 *      Author: Mohamed Tarek
 */

#ifndef MOTORRELAY_H_
#define MOTORRELAY_H_


#define STOP 0
#define RIGHT 1
#define LEFT 2

void MotorRelay_init(void);
void MotorRelay_Right(void);
void MotorRelay_Left(void);
void MotorRelay_Free(void);
void MotorRelay_Break(void);
u8 MotorRelay_Status(void);


#endif /* MOTORRELAY_H_ */

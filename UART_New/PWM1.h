/*
 * PWM1.h
 *
 *  Created on: Apr 10, 2017
 *      Author: Mohamed Tarek
 */

#ifndef PWM1_H_
#define PWM1_H_

void PWM_init(void);
void PWM_SetFreq(f32 Freq_PWM);
void PWM_SetDutyCycle1A(f32 DutyCycle1A);
void PWM_SetDutyCycle1B(f32 DutyCycle1B);

#endif /* PWM1_H_ */

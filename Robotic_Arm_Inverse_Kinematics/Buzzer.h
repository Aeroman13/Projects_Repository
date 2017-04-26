/*
 * Buzzer.h
 *
 *  Created on: Mar 16, 2017
 *      Author: Mohamed Tarek
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#undef F_CPU
#define F_CPU 16000000

void Buzzer_init();
void Buzzer_ON(u16 F_Tone);
void Buzzer_OFF();

#endif /* BUZZER_H_ */

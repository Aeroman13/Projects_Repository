/*
 * Timer0.h
 *
 *  Created on: Apr 6, 2017
 *      Author: Mohamed Tarek
 */

#ifndef TIMER0_H_
#define TIMER0_H_
void Timer0_init(void);
void Timer0_Preload_ForceComp(void);
void Timer0_CTC_CompValue(u8 Value);
u8 Timer0_GetIntFlag(void);
void Timer0_ClearIntFlag(void);
void Timer0_Set_OVF_ISR( void (*ptr)(void));


#endif /* TIMER0_H_ */

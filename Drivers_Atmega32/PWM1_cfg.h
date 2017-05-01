/*
 * PWM1_cfg.h
 *
 *  Created on: Apr 9, 2017
 *      Author: Mohamed Tarek
 */

#ifndef PWM1_CFG_H_
#define PWM1_CFG_H_


#define PRESCALER_8		0b00000010
#define PRESCALER_64	0b00000011
#define PRESCALER_256 	0b00000100

#define OC1A 	0b10000000		// in Fast_PWM mode
#define OC1B	0b00100000		// in Fast_PWM mode
#define OC1AB	0b10100000

/* PWM Configuration */

// Select Prescaler and Pin
#define PRESCALER	PRESCALER_64
#define PWM_PINS	OC1A


/***************************************************************************/

#if(PRESCALER == PRESCALER_64)
#define  PRESCALER_VALUE	64
#endif

#if(PRESCALER == PRESCALER_256)
#define  PRESCALER_VALUE	256
#endif


#endif /* PWM1_CFG_H_ */

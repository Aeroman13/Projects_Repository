/*
 * Timer0_cfg.h
 *
 *  Created on: Apr 6, 2017
 *      Author: Mohamed Tarek
 */

#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

#define TRUE	1
#define FALSE	0

#define	OVF 0b00000000
#define CTC	0b00001000

#define DISCONNECTED	0b00000000
#define TOGGLE			0b00010000
#define CLEAR			0b00100000
#define SET				0b00110000

#define TIMER_OFF		0b00000000
#define NO_PRESCALING	0b00000001
#define PRESCALER_8		0b00000010
#define PRESCALER_64	0b00000011
#define PRESCALER_256	0b00000100
#define PRESCALER_1024	0b00000101

/* Configuration */
#define TIMER0_MODE		OVF
#define OC0_PIN_FUNC	DISCONNECTED
#define PRESCALER		PRESCALER_1024
#define TIMER0_INT_EN	TRUE
#define CTC_COMP_VALUE	128				// this is a non static configuration which can change through run time
/***********************************************************************/


#endif /* TIMER0_CFG_H_ */

/*
 * ADC_cfg.h
 *
 *  Created on: Mar 31, 2017
 *      Author: Mohamed Tarek
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#define LEFT 	1
#define RIGHT 	0
#define TRUE	1
#define FALSE	0

#define EXTERNAL_AREF	0b00000000
#define INTERNAL_AVCC	0b01000000
#define INTERNAL_2_56V	0b11000000

#define ADC0	0b00000000
#define ADC1	0b00000001
#define ADC2	0b00000010
#define ADC3	0b00000011
#define ADC4	0b00000100
#define ADC5	0b00000101
#define ADC6	0b00000110
#define ADC7	0b00000111

// Auto Trigger
#define FREE_RUNNING	0b00000000
#define ANALOG_COMPARATOR	0b00100000
#define EXTERNAL_INTERRUPT0	0b01000000

// Pre_scaler
#define PRE_16	0b00000100
#define PRE_32	0b00000101
#define PRE_64	0b00000110


#define SINGLE_CONVERSION	0b00000000
#define AUTO_TRIGGER	0b00100000

/* Configuration */

// ADMUX
#define REF_VOLTAGE_SOURCE	INTERNAL_AVCC
#define LEFT_ADJUST			FALSE
#define INITIAL_CHANNEL		ADC0

// ADCSRA
#define ADC_EN 			TRUE
#define SELECT_MODE		AUTO_TRIGGER

#define ADC_INT_EN 		FALSE
#define ADC_PRESCALLER	PRE_64

#define TRIG_SOURCE		FREE_RUNNING
#endif /* ADC_CFG_H_ */

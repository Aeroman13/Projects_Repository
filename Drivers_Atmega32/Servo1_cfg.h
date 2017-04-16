/*
 * Servo1_cfg.h
 *
 *  Created on: Apr 14, 2017
 *      Author: Mohamed Tarek
 */

#ifndef SERVO1_CFG_H_
#define SERVO1_CFG_H_
#define  ON		1
#define  OFF	0


/* Servo Driver */		// Values for Both Servos
#define SERVO_FREQ			50 		// HZ
#define SERVO_PRESCALER		PRESCALER_64

/* Servo 1A */   // Connected to Pin OC1A
#define SERVO_1A				ON
#define DUTY_CYCLE1A_0DEG		0.5	// ms
#define DUTY_CYCLE1A_180DEG		2.25 	//ms


/* Servo 1B */  // Connected to Pin OC1B
#define SERVO_1B				ON
#define DUTY_CYCLE1B_0DEG		0.65	// ms
#define DUTY_CYCLE1B_180DEG		2.1 	//ms
/***********************************************************************************/
// Note : GO in PWM_cfg and Set PWM PINS in PWM Drivers OC1A or OC1B or OC1AB & Prescaler
/***********************************************************************************/

//
//#if((SERVO_1A == ON) && (SERVO_1B == OFF))
//#define SERVO_PINS				OC1A
//#endif
//
//#if((SERVO_1B == ON) && (SERVO_1A == OFF))
//#define SERVO_PINS				OC1B
//#endif
//
//#if((SERVO_1A ==ON) && (SERVO1_1B == ON))		// Both Pins are ON
//#define	SERVO_PINS				OC1AB
//#endif


#endif /* SERVO1_CFG_H_ */

/*
 * I2C_cfg.h
 *
 *  Created on: May 2, 2017
 *      Author: Mohamed Tarek
 */

#ifndef I2C_CFG_H_
#define I2C_CFG_H_
#define TRUE	1
#define FALSE	0

#define PRE_1	0
#define PRE_4	1
#define PRE_16	2
#define PRE_64	3

#define I2C_ENABLE	TRUE
#define INT_ENABLE	FALSE
#define ACK_ENABLE	TRUE		// If False will virtually disconnect the corresponding node

#define BIT_RATE	0x03			//F_CPU = 16M , TWBR =0x03, TWPS = 1,  SCL= F_CPU/(16+2(TWBR).4^TWPS), SCL = 400.000 kbps,
#define PRESCALER	PRE_1
#endif /* I2C_CFG_H_ */

/*
 * UART_cfg.h
 *
 *  Created on: Apr 25, 2017
 *      Author: Mohamed Tarek
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_

#define ON 1
#define OFF	0
#define SYNCHRONOUS 	1
#define ASYNCHRONOUS	0
#define DISABLED		0b00000000
#define EVEN_PARITY		0b00100000
#define ODD_PARITY		0b00110000
#define ONE_BIT			0
#define TWO_BIT			1
#define	BIT_5			0b00000000
#define BIT_6			0b00000001
#define BIT_7			0b00000010
#define BIT_8			0b00000011
#define BIT_9			0b00000111
#define RATE_9600		103
/* UART Configuration */

#define MODE				ASYNCHRONOUS
#define TRANSMIT_EN			OFF
#define RECIEVE_EN			ON
#define PARITY_MODE			DISABLED
#define STOP_BIT			ONE_BIT
#define CHARACTER_SIZE		BIT_8
#define BAUD_RATE			RATE_9600	//bps
// Interrupt
#define TRANSMIT_INT_EN		OFF
#define RECIEVE_INT_EN		ON
#define UDR_EMPTY_INT_EN	OFF


#define DOUBLE_SPEED		OFF
#define MULTI_PROCESSOR		OFF


#endif /* UART_CFG_H_ */

/*
 * UART.h
 *
 *  Created on: Apr 21, 2017
 *      Author: Mohamed Tarek
 */

#ifndef UART_H_
#define UART_H_

void UART_init(void);
u16 UART_ReadData(void);
void UART_TransmitData(u16 Data);

#endif /* UART_H_ */

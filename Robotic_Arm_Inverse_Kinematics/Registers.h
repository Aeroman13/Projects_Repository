/*
 * Registers.h
 *
 *  Created on: Mar 5, 2017
 *      Author: Mohamed Tarek
 */

// Instead of using library avr/io.h

#ifndef REGISTERS_H_
#define REGISTERS_H_

#define DDRA *((volatile u8*)0x3A)
#define PORTA *((volatile u8*)0x3B)
#define PINA *((volatile u8*)0x39)

#define DDRB *((volatile u8*)0x37)
#define PORTB *((volatile u8*)0x38)
#define PINB *((volatile u8*)0x36)

#define DDRC *((volatile u8*)0x34)
#define PORTC *((volatile u8*)0x35)
#define PINC *((volatile u8*)0x33)

#define DDRD *((volatile u8*)0x31)
#define PORTD *((volatile u8*)0x32)
#define PIND *((volatile u8*)0x30)

#define MCUCR *((volatile u8*)0x55)
#define GICR *((volatile u8*)0x5B)
#define SREG *((volatile u8*)0x5F)

#define ADMUX *((volatile u8*)0X27)
#define ADCSRA *((volatile u8*)0x26)
#define SFIOR *((volatile u8*)0x50)
#define ADCL *((volatile u8*)0X24)
#define ADCH *((volatile u8*)0x25)
#define ADCLH *((volatile u16*)0x24)

#define TCCR0 *((volatile u8*)0x53)
#define TIMSK *((volatile u8*)0x59)
#define TIFR *((volatile u8*)0x58)
#define OCR0 *((volatile u8*)0x5c)
#define TCNT0 *((volatile u8*)0x52)

#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)
#define OCR1A *((volatile u16*)0x4A)
#define OCR1B *((volatile u16*)0x48)
#define ICR1A *((volatile u16*)0x46)



#endif /* REGISTERS_H_ */

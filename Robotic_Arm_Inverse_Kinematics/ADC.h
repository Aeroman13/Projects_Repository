/*
 * ADC.h
 *
 *  Created on: Apr 1, 2017
 *      Author: Mohamed Tarek
 */

#ifndef ADC_H_
#define ADC_H_

void ADC_init(void);
void ADC_StartConversion(void);
u8 ADC_GetIntFlag(void);
void ADC_ClearIntFlag(void);
void ADC_DataAdjustment(u8 adj);
u16 ADC_Read_10Bit(void);
u8 ADC_Read_8Bit(void);
#endif /* ADC_H_ */

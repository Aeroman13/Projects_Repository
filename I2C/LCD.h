/*
 * LCD.h
 *
 *  Created on: Mar 11, 2017
 *      Author: Mohamed Tarek
 */

#ifndef LCD_H_
#define LCD_H_


void LCD_WriteData(u8 Data);
void LCD_WriteCommand(u8 Command);
void LCD_init(void);
void LCD_WriteString(u8 str[30]);
void LCD_MoveCu(u8 y_pos , u8 x_pos);
void LCD_WriteNumber(u16 value);
void LCD_ClearScreen(void);
#endif /* LCD_H_ */

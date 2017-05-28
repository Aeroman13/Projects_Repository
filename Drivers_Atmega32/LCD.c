/*
+ * LCD.c
 *
 *  Created on: Mar 11, 2017
 *      Author: Mohamed Tarek
 */
#undef F_CPU
#define F_CPU 16000000ul
#include "LCD_Cfg.h"
#include "DIO.h"
#include "Datatypes.h"
#include "util/delay.h"


void LCD_WriteData(u8 Data){
	DIO_PinValue(RS_PIN,1);

	DIO_SetPortValue(DATA_PORT,Data);
	DIO_PinValue(E_PIN,1);
//	_delay_ms(2);
	DIO_PinValue(E_PIN,0);
//	_delay_ms(2);
}

void LCD_WriteCommand(u8 Command){
	DIO_PinValue(RS_PIN,0);

	DIO_SetPortValue(DATA_PORT,Command);
	DIO_PinValue(E_PIN,1);
//	_delay_ms(2);
	DIO_PinValue(E_PIN,0);
//	_delay_ms(2);
}

void LCD_init(void){
	DIO_SetPortDirection(DATA_PORT,OUTPUT);
	DIO_PinDirection(RS_PIN,OUTPUT);
	DIO_PinDirection(E_PIN,OUTPUT);
	LCD_WriteCommand(0x01);
	_delay_ms(50);
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x38);
}

void LCD_WriteString(u8 str[16])
{
	u8 i;

	for(i=0;i<16;i++)
	{
		if(str[i] != '\0')
		{

			LCD_WriteData(str[i]);
		}
		else
		{
			i=16;
		}
	}
}

void LCD_WriteNumber(u16 value)
{	// 5 digits only
	u16 i=0,f=0;
	u16	arr[10]={0};

	for(i=1;i<10;i++)
	{
		arr[i] = value%10;
		value = value/10;
		if(value ==0)
			break;

	}
//	i=i--;
	f=0;
	for(i=4;i>0;i--)		// 3nd el i =0 bt3ml moshkla
	{

		LCD_WriteData(48 + (u8)arr[i]);
		f++;
//		if(f>3) // onlye 4 digits
//		{
//			break;
//		}
//		--i;
	}

//	LCD_WriteData(48 + (value/10000));
//	LCD_WriteData(48 +((value/1000)%10));
//	LCD_WriteData(48 + (value/100)%10);
//	LCD_WriteData(48 + (value%100)/10);
//	LCD_WriteData(48 + (value%10));
//	LCD_WriteData(48 + (value*10));
}
//void LCD_WriteFloat(f32 value)
//{
//	u8 x,i;
//	for(i=0;i<6;i++)
//	{
//		x = value/10;
//		value = value%10;
//		if(x == 46)
//		{
//			LCD_WriteData(46);
//		}
//		else
//		{
//			LCD_WriteData(48 + x);
//		}
//	}
//}

void LCD_ClearScreen(void)
{
	LCD_WriteCommand(0x01);
}

void LCD_MoveCu(u8 y_pos , u8 x_pos)
{
	if(y_pos == 0)
	{
		LCD_WriteCommand(0x80+x_pos);
	}
	else if(y_pos == 1)
	{
		LCD_WriteCommand(0xc0 + x_pos);
	}
}

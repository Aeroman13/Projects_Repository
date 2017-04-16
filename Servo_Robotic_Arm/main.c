/*
 * main.c*/
#undef F_CPU
#define F_CPU 16000000ul

#include "Datatypes.h"
#include "Keypad.h"
#include "LCD.h"
#include "Servo1.h"
#include "util/delay.h"
#include "Timer0.h"



int main(void)
{
	f32 j0=90,j1=90;
	LCD_init();
	Servo1_init();
	Keypad_init();
	Timer0_init();

	Servo1A_SetAngle(j0);
	Servo1B_SetAngle(j1);
	LCD_MoveCu(0,0);
	LCD_WriteString("2DForward_Kinem");
	LCD_MoveCu(1,0);
	LCD_WriteString("j0=");
	LCD_WriteNumber(j0);
	LCD_MoveCu(1,7);
	LCD_WriteString("j1=");
	LCD_WriteNumber(j1);
	while(1)
	{
		if(Keypad_ReadButton(0) == 0)
		{
			j0 += 1;
			_delay_ms(100);
			if(j0 >= 130)
			{
				j0 = 130;
			}
			Servo1A_SetAngle(j0);
			LCD_MoveCu(1,3);
			LCD_WriteNumber(j0);
		}
		if(Keypad_ReadButton(4) == 0)
		{
			j0 -= 1;
			_delay_ms(100);
			if(j0 <= 60)
			{
				j0 = 60;
			}
			Servo1A_SetAngle(j0);
			LCD_MoveCu(1,3);
			LCD_WriteNumber(j0);
		}

		if(Keypad_ReadButton(1) == 0)
		{
			j1 += 1;
			_delay_ms(100);
			if(j1 >= 150)
			{
				j1 = 150;
			}
			Servo1B_SetAngle(j1);
			LCD_MoveCu(1,10);
			LCD_WriteNumber(j1);
		}
		if(Keypad_ReadButton(5) == 0)
		{
			j1 -= 1;
			_delay_ms(100);
			if(j1 <= 30)
			{
				j1 = 30;
			}
			Servo1B_SetAngle(j1);
			LCD_MoveCu(1,10);
			LCD_WriteNumber(j1);
		}

	}
}

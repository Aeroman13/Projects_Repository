/*
 * main.c*/
#undef F_CPU
#define F_CPU 16000000ul


#include "Datatypes.h"
#include "Keypad.h"
#include "DIO.h"
#include "LCD.h"
#include "Servo1.h"
#include "util/delay.h"
//#include "math.h"
#include "Inverse_Kinematics.h"


int main(void)
{
	f64 j2,j3,q2=90,q3=0,i;
	u8 Flag,start=1,end=1;
	u16 arr_x[4]={90,100,230,90};
	u16 arr_y[4]={320,310,200,320};
	u16 *ptr_x=arr_x,x,y;
	u16 *ptr_y=arr_y;

	LCD_init();
	Servo1_init();
	Keypad_init();
	DIO_SetPinDirection(1,7,OUTPUT);

	LCD_MoveCu(0,0);
	LCD_WriteString("2D_Inverse_Kinem");
	Servo1A_SetAngle(q2);
	Servo1B_SetAngle(q3);
	while(1)
	{
		x = *ptr_x;
		y= *ptr_y;
		Flag = Inverse_Kinematics(x,y);
		start = Keypad_ReadButton(0);
		_delay_ms(100);
		end = Keypad_ReadButton(4);
		_delay_ms(100);
		if(Flag == 1)
		{
		j2 = Theta_2();
		j3 = Theta_3();
		LCD_MoveCu(1,0);
		LCD_WriteString("j2=");
		LCD_WriteNumber(j2);
		LCD_MoveCu(1,7);
		LCD_WriteString("j3=");
		LCD_WriteNumber(j3);
		}
		else
		{
			LCD_MoveCu(1,0);
			LCD_WriteString("Too Far        ");
		}

		if(start == 0)
		{
			DIO_SetPinValue(1,7,1);
			if(q2<j2)
			{
				for(i=q2;i<j2;i++)
				{
					q2++;
					Servo1A_SetAngle(q2);
					_delay_ms(100);
				}
			}
			if(q2>j2)
			{
				for(i=q2;i>j2;i--)
				{
					q2--;
					Servo1A_SetAngle(q2);
					_delay_ms(100);
				}
			}
			if(q3<j3)
			{
				for(i=q3;i<j3;i++)
				{
					q3++;
					Servo1B_SetAngle(q3);
					_delay_ms(100);
				}
			}
			if(q3>j3)
			{
				for(i=q3;i>j3;i--)
				{
					q3--;
					Servo1B_SetAngle(q3);
					_delay_ms(100);
				}
			}
			start =1;
			DIO_SetPinValue(1,7,0);
			ptr_x++;
			ptr_y++;
		}

		if(end == 0)
		{
			DIO_SetPinValue(1,7,1);
			if(q2 > 90)
			{
				for(i=q2;i>90;i--)
				{
					q2--;
					Servo1A_SetAngle(q2);
					_delay_ms(100);
				}
			}
			if(q2 < 90)
			{
				for(i=q2;i<90;i++)
				{
					q2++;
					Servo1A_SetAngle(q2);
					_delay_ms(100);
				}

			}
			if(q3 > 0)
			{
				for(i=q3;i>0;i--)
				{
					q3--;
					Servo1B_SetAngle(q3);
					_delay_ms(100);
				}
			}

			end =1;
			DIO_SetPinValue(1,7,0);
		}


	}

	return 0;
}



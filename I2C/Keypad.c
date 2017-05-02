/*
 * Keypad.c
 *
 *  Created on: Mar 12, 2017
 *      Author: Mohamed Tarek
 */

#include "Datatypes.h"
#include "Keypad_cfg.h"
#include "DIO.h"

void Keypad_init(void){
#if(R0 != OFF)
	DIO_PinDirection(R0,OUTPUT);
#endif
#if(R1 != OFF)
	DIO_PinDirection(R1,OUTPUT);
#endif
#if(R2 != OFF)
	DIO_PinDirection(R2,OUTPUT);
#endif
#if(R3 != OFF)
	DIO_PinDirection(R3,OUTPUT);
#endif
#if(C0 != OFF)
	DIO_PinDirection(C0,INPUT);
	DIO_PinValue(C0,1);		// Pull up resistance enable
#endif
#if(C1 != OFF)
	DIO_PinDirection(C1,INPUT);
	DIO_PinValue(C1,1);		// Pull up resistance enable
#endif
#if(C2 != OFF)
	DIO_PinDirection(C2,INPUT);
	DIO_PinValue(C2,1);		// Pull up resistance enable
#endif
#if(C3 != OFF)
	DIO_PinDirection(C3,INPUT);
	DIO_PinValue(C3,1);		// Pull up resistance enable
#endif

}

u8 Keypad_ReadButton(u8 Button_Number){
	u8 arr_row[4] = {R0,R1,R2,R3};
	u8 arr_col[4] = {C0,C1,C2,C3};
	u8 Return_Value;
	u8 row,col;
	row = Button_Number / 4;
	col = Button_Number % 4;

	DIO_PinValue(R0,1);
	DIO_PinValue(R1,1);
	DIO_PinValue(R2,1);
	DIO_PinValue(R3,1);

	DIO_PinValue(arr_row[row],0);
	Return_Value = DIO_GetPin(arr_col[col]);
	return Return_Value;
}

struct Keypad Keypad_Scan(void){
	u8 arr_row[4] = {R0,R1,R2,R3};
	u8 arr_col[4] = {C0,C1,C2,C3};
	u8 row,col,i;
	struct Keypad Mykeypad;
	u8 arr[16];

	for(i=0 ; i<16;i++)
	{
		row = i / 4;
		col = i % 4;

		DIO_PinValue(R0,1);
		DIO_PinValue(R1,1);
		DIO_PinValue(R2,1);
		DIO_PinValue(R3,1);
		DIO_PinValue(arr_row[row],0);
		arr[i] = DIO_GetPin(arr_col[col]);

	}
		Mykeypad.Button0 = arr[0];
		Mykeypad.Button1 = arr[1];
		Mykeypad.Button2 = arr[2];
		Mykeypad.Button3 = arr[3];
		Mykeypad.Button4 = arr[4];
		Mykeypad.Button5 = arr[5];
		Mykeypad.Button6 = arr[6];
		Mykeypad.Button7 = arr[7];
		Mykeypad.Button8 = arr[8];
		Mykeypad.Button9 = arr[9];
		Mykeypad.Button10 = arr[10];
		Mykeypad.Button11 = arr[11];
		Mykeypad.Button12 = arr[12];
		Mykeypad.Button13 = arr[13];
		Mykeypad.Button14 = arr[14];
		Mykeypad.Button15 = arr[15];

		return Mykeypad;
}


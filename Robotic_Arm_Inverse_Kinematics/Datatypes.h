/*
 * Typedef.h
 *
 *  Created on: Mar 5, 2017
 *      Author: Mohamed Tarek
 */

#ifndef DATATYPES_H_
#define DATATYPES_H_

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;
typedef long unsigned int u32;
typedef float f32;
typedef double f64;
#define INPUT	0
#define OUTPUT	1

struct Keypad
{
	u16 Button0 :1;
	u16 Button1 :1;
	u16 Button2 :1;
	u16 Button3 :1;
	u16 Button4 :1;
	u16 Button5 :1;
	u16 Button6 :1;
	u16 Button7 :1;
	u16 Button8 :1;
	u16 Button9 :1;
	u16 Button10 :1;
	u16 Button11 :1;
	u16 Button12 :1;
	u16 Button13 :1;
	u16 Button14 :1;
	u16 Button15 :1;
};



#endif /* DATATYPES_H_ */

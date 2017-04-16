/*
 * Keypad.h
 *
 *  Created on: Mar 12, 2017
 *      Author: Mohamed Tarek
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

void Keypad_init(void);
u8 Keypad_ReadButton(u8 Button_Number);
struct Keypad Keypad_Scan(void);
#endif /* KEYPAD_H_ */

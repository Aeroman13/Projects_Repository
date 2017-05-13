/*
 * EEPROM.h
 *
 *  Created on: May 5, 2017
 *      Author: Mohamed Tarek
 */

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_Init(void);
void EEPROM_SaveData_InLocation(u8 Data, u16 Byte_Location);
u8 EEPROM_GiveData_InLocation(u16 Byte_Location);

#endif /* EEPROM_H_ */

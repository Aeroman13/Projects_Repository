/*
 * EEPROM.c
 *
 *  Created on: May 5, 2017
 *      Author: Mohamed Tarek
 */


#include "Datatypes.h"
#include "Macros.h"
#include "DIO.h"

#include "I2C.h"

void EEPROM_Init(void)
{
	I2C_InitMaster();

	return;
}

void EEPROM_SaveData_InLocation(u8 Data, u16 Byte_Location)
{
	// Extract Page Location from Byte_Location (0 to 1023 locations)
	I2C_Start();

	I2C_Master_Send_SLA_WriteRequest( 0x50|((Byte_Location & 0x0300)>>8) );


	// Page Location(x and y) ( Bit 8 and 9 ) Extracted by anding of Byte_Location with (0x0300) (0000 0011 0000 0000) then shifted to right to be (0000 00xy)
	// then ored with 0x50 (0101 0000) to be (0101 00xy) so we have the sla which contain page no and device address (EEPROM)
	I2C_MasterSendData((u8)Byte_Location);		// Catsing

	// Casting of Byte_Location from u16 to u8 to get the byte location in the page ( in a page we have from 0 to 255 locations)
	I2C_MasterSendData(Data);		// Data is one Byte
	I2C_Stop();
	return;
}

u8 EEPROM_GiveData_InLocation(u16 Byte_Location)
{
	u8 Data;
	I2C_Start();
	I2C_Master_Send_SLA_WriteRequest( 0x50|((Byte_Location & 0x0300)>>8) );
	// Page Location(x and y) ( Bit 8 and 9 ) Extracted by anding of Byte_Location with (0x0300) (0000 0011 0000 0000) then shifted to right to be (0000 00xy)
	// then ored with 0x50 (0101 0000) to be (0101 00xy) so we have the sla which contain page no and device address (EEPROM)
	I2C_MasterSendData((u8) Byte_Location);	// Casting
	// Casting of Byte_Location from u16 to u8 to get the byte location in the page ( in a page we have from 0 to 255 locations)
	I2C_RepeatedStart();		// Repeated Start to change request
	I2C_Master_Send_SLA_ReadReuqest(0x50|((Byte_Location & 0x0300)>>8));
	Data = I2C_MasterReceiveData();
	return Data;
}

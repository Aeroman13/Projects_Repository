/*
 * I2C.c
 *
 *  Created on: May 2, 2017
 *      Author: Mohamed Tarek
 */
#include "Registers.h"
#include "Macros.h"
#include "Datatypes.h"
#include "I2C_cfg.h"

// Single Master Multi Slave

// Master Transmitter Receiver
void I2C_MasterInit(void)
{
	// No Need for Slave Adderess because its a single master
	TWBR = BIT_RATE;
	TWCR |= (ACK_ENABLE<<6) | (I2C_ENABLE<<2);
	return;
}



void I2C_Start(void)
{
	SET_BIT(TWCR,2);	// Enable TWI
	SET_BIT(TWCR,5);	// Start Condition
	SET_BIT(TWCR,7); 	// Clear Flag to start operation
	while(GET_BIT(TWCR,7) == 0);		// waiting the flage to be set ( Can be neglected and Ack is enough )
	while((TWSR & 0xF8) !=	0x08 );			// Waiting Start Ack
	return;
}

void I2C_MasterTo_SLA_Write(u8 SLA)		// Master specifies the Slave by address with write request.
{
	SET_BIT(TWCR,2);	// Enable TWI
	TWDR = (SLA << 1);	// SLA + W
	CLEAR_BIT(TWDR,0);
	SET_BIT(TWCR,7);						// Clear Flag to Start Operation
	while(GET_BIT(TWCR,7) == 0);
	if((TWSR & 0xF8) != 0x18)  			// Hal Lazem astna Ack !!!!!!!!!!!!! ?
	{
		// error !!!!!!!!
	}
	return;
}

void I2C_MasterTo_SLA_Read(u8 SLA)		// Master specifies the Slave by address with read request
{
	SET_BIT(TWCR,2);	// Enable TWI
	TWDR = (SLA<<1);	// SLA + R
	SET_BIT(TWDR,0);
	SET_BIT(TWCR,7);						// Clear Flag to Start Operation
	while(GET_BIT(TWCR,7) == 0);		// Hal Lazem Astna El flag              >>>>>>>>>> Momken nt3aml m3 el interrupt of flag m3 el ACK
	if((TWSR & 0xF8) != 0x40)  			// Hal Lazem astna Ack !!!!!!!!!!!!! ?
	{
		// error !!!!!!!!
	}
	return;
}

void I2C_MasterSendData(u8 Data)
{
	SET_BIT(TWCR,2);	// Enable TWI
	TWDR = Data;
	SET_BIT(TWCR,7);						// Clear Flag to Start Operation
	while(GET_BIT(TWCR,7) == 0);
	if((TWSR & 0xF8) != 0x28)  			// Hal Lazem astna Ack !!!!!!!!!!!!! ?
	{
		// error !!!!!!!!
	}
	return;
}

u8 I2C_MasterReceiveData(void)
{
	u8 Data;
	while(GET_BIT(TWCR,7)  == 0);		// Wait until reading has been accomplished and flag set
	Data = TWDR;
	SET_BIT(TWCR,2);	// Enable TWI
	SET_BIT(TWCR,7);	// Clear Flag
	if((TWSR & 0xF8) != 0x50)  			// Hal Lazem astna Ack !!!!!!!!!!!!! ?
	{
		// error !!!!!!!!
	}
	return Data;
}

void I2C_RepeatedStart(void)
{
	SET_BIT(TWCR,2);			//Enable TWI
	SET_BIT(TWCR,5);			//Start Condition
	SET_BIT(TWCR,7);			// Clear Flag to start operation
	if((TWSR & 0xF8) != 0x10)  			// Hal Lazem astna Ack !!!!!!!!!!!!! ?
	{
		// error !!!!!!!!
	}
	return;
}

void I2C_Stop(void)
{
	SET_BIT(TWCR,2);			//Enable TWI
	SET_BIT(TWCR,4);			//Start Condition
	SET_BIT(TWCR,7);			// Clear Flag to start operation
}


// Slave Transmitter Receiver				( This Configurations for each Slave Unit )

void I2C_SlaveInit(void)
{

//	TWCR =  0b01000100;
	TWAR =	0x01; 			// First Slave
	 SET_BIT(TWCR,6);
	 SET_BIT(TWCR,2);		//Enable Ack, TWI En

}

u8 I2C_SlaveReceiveData(void)
{
	u8 Data;
	while(GET_BIT(TWCR,7) ==0);			// Wait till TWDR is filled and INt flag is set
	Data = TWDR;
//	TWCR = SET_BIT(TWCR,7) | SET_BIT(TWCR,6) | SET_BIT(TWCR,2);		// Clear Flag , Enable Ack, Enable TWI
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,6);
	SET_BIT(TWCR,2);
	//	TWCR = (1<<7) | (1<<6) | (1<<2);
	// Ack LEha LAzma  fe t3
	return Data;
}

void I2C_SlaveSendData(u8 Data)
{
	TWDR = Data;
//	TWCR = SET_BIT(TWCR,7) | SET_BIT(TWCR,6) | SET_BIT(TWCR,2);		// Clear Flag , Enable Ack, Enable TWI
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,6);
	SET_BIT(TWCR,2);
	while(GET_BIT(TWCR,7) ==0);						// wait until operation is finished and flag is set

	// Check Ack , ele ana mesh shayef leh lazma 8er fe el interrupt bas
	return;
}


// Slave Master Check for master receive
// Slave Master Check for slave receive

/*
 * I2C.h
 *
 *  Created on: May 2, 2017
 *      Author: Mohamed Tarek
 */

#ifndef I2C_H_
#define I2C_H_

void I2C_InitMaster(void);
void I2C_Start(void);
void I2C_Master_Send_SLA_WriteRequest(u8 SLA);
void I2C_Master_Send_SLA_ReadReuqest(u8 SLA);
void I2C_MasterSendData(u8 Data);
u8 I2C_MasterReceiveData(void);
void I2C_RepeatedStart(void);
void I2C_Stop(void);
void I2C_InitSlave(void);
u8 I2C_SlaveReceiveData(void);
void I2C_SlaveSendData(u8 Data);

#endif /* I2C_H_ */

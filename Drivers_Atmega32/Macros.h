/*
 * Macros.h
 *
 *  Created on: Mar 4, 2017
 *      Author: Mohamed Tarek
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(R,BIT_NUMBER) R|=(1<<BIT_NUMBER)
#define CLEAR_BIT(R,BIT_NUMBER) R&=~(1<<BIT_NUMBER)
#define TOGGLE_BIT(R,BIT_NUMBER) R^=(1<<BIT_NUMBER)
#define GET_BIT(R,BIT_NUMBER) ((R&(1<<BIT_NUMBER))>>BIT_NUMBER)

#endif /* MACROS_H_ */



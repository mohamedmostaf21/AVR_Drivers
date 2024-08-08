/*
 * KPD_interface.h
 *
 *  Created on: Aug 7, 2024
 *      Author: k.m
 */

#ifndef HAL_KEYPAD_DRIVER_KPD_INTERFACE_H_
#define HAL_KEYPAD_DRIVER_KPD_INTERFACE_H_

/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! Keypad driver for 4x4 keypad                                          */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/




/***************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
u8 KPD_u8GetPressedKeyy(void);

#endif /* HAL_KEYPAD_DRIVER_KPD_INTERFACE_H_ */

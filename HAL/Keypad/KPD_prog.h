/*
 * KPD_prog.h
 *
 *  Created on: Aug 7, 2024
 *      Author: k.m
 */

#ifndef HAL_KEYPAD_KPD_PROG_H_
#define HAL_KEYPAD_KPD_PROG_H_

typedef enum Keypad_enuState {
    Keypad_enuNormalState=0,
    Keypad_enuNullPointerException
}Keypad_enuState;

void Keypad_voidInit(void);
Keypad_enuState Keypad_u8GetPressedButtonValue(u8 * u8PtrToVal);
#endif /* HAL_KEYPAD_KPD_PROG_H_ */

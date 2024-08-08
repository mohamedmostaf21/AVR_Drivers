/*
 * KPD_priv.h
 *
 *  Created on: Aug 7, 2024
 *      Author: k.m
 */

#ifndef HAL_KEYPAD_KPD_PRIV_H_
#define HAL_KEYPAD_KPD_PRIV_H_

/******** Columns Definition *********/
/* RANGE : DIO_enuPin0 -----> DIO_enuPin31 */
#define C4 DIO_PIN_NUM_15
#define C3 DIO_PIN_NUM_14
#define C2 DIO_PIN_NUM_13
#define C1 DIO_PIN_NUM_12

/******** Rows Definition *********/
/* RANGE : DIO_enuPin0 -----> DIO_enuPin31 */
#define R4 DIO_PIN_NUM_11
#define R3 DIO_PIN_NUM_10
#define R2 DIO_PIN_NUM_9
#define R1 DIO_PIN_NUM_8

/******** Buttons Definition ********/
/** RANGE : u8 ---> 0 to 255 values */
#define BUTTON1_VAL 0
#define BUTTON2_VAL 1
#define BUTTON3_VAL 2
#define BUTTON4_VAL 3
#define BUTTON5_VAL 4
#define BUTTON6_VAL 5
#define BUTTON7_VAL 6
#define BUTTON8_VAL 7
#define BUTTON9_VAL 8
#define BUTTON10_VAL 9
#define BUTTON11_VAL 10
#define BUTTON12_VAL 11
#define BUTTON13_VAL 12
#define BUTTON14_VAL 13
#define BUTTON15_VAL 14
#define BUTTON16_VAL 15

#endif /* HAL_KEYPAD_KPD_PRIV_H_ */

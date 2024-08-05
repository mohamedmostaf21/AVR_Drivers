/*
 * LCD_cfg.c
 *
 *  Created on: Aug 4, 2024
 *      Author: k.m
 */
#include  "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"
#include "../../LIBS/delay.h"
#include "../../MCAL/DIO/DIO.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"
u8 DataREG[8] = {LCD_D0, LCD_D1, LCD_D2, LCD_D3, LCD_D4, LCD_D5, LCD_D6, LCD_D7};
u8 DataVal[8] = {DIO_LOW};
void PutOnBusLCD(u8* u8DataREG, u8 u8num){
    u8 u8Num[8]; //0x0011 1111
  	u8 cntr;
  	for(cntr = 0; cntr < 8; cntr++){
  		u8Num[cntr] = GET_BIT(u8num, cntr);
  	}
    DIO_enuWriteGroup(u8DataREG, u8Num, 8);
}

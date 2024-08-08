///*
// * TestLCD.c
// *
// *  Created on: Aug 4, 2024
// *      Author: k.m
// */
//
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include "../LIBS/STD_TYPES.h"
#include "../LIBS/delay.h"
#include "../HAL/Keypad/KPD_prog.h"
int main(){

	DIO_voidInit();
	Keypad_voidInit();
	Lcd_DisplayControlType LCD_type;
	LCD_type.cursor = LCD_STATE_OFF;
	LCD_type.display = LCD_STATE_ON;
	LCD_type.cursorBlink = LCD_STATE_OFF;
	LCD_type.font = LCD_FONT_5X7;
	LCD_type.lines = LCD_LINES_1;
	Lcd_Init(&LCD_type);
	//Lcd_Init(LCD_type->display);
	Lcd_ClearDisplay();
	Lcd_ReturnHome();
	u8 pressedKey;
	Lcd_SetCursorPosition(0, 1);
	Lcd_ShiftDisplayRight(2);
	while(1){


		Keypad_u8GetPressedButtonValue(&pressedKey);
		//LCD_vidWriteCharctr(1);

		Lcd_DisplayNumber(pressedKey);
		Delay_ms(10);


	}
	return 0;
}

/*
 * LCD.h
 *
 *  Created on: Aug 4, 2024
 *      Author: k.m
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#define LCD_ON			1
#define LCD_OFF			0
#define LCD_NUMBER   	0
#define LCD_STRING   	1
/*LCD lines*/
#define LCD_LINE1    1
#define LCD_LINE2    2
extern u8 upperBoundVal[4];
extern u8 upperBoundGroup[4];


/*
 * Prototype   : void LCD_voidInitialize(void);
 * Description : Initialize LCD in a desired data and control registers
 *               in 4 bit mode control and data register must be the same register
 * Arguments   : void
 * return      : void
 */
 void LCD_voidInitialize(void);

 /*
  * Prototype   : void LCD_voidClear(void);
  * Description : clear LCD and return cursor to first position
  * Arguments   : void
  * return      : void
  */
  void LCD_voidClear(void);

 /*
  * Prototype   : void LCD_voidReturnHome(void);
  * Description : return cursor to first position LCD content doesn't affect
  * Arguments   : void
  * return      : void
  */
  void LCD_voidReturnHome(void);

 /*
  * Prototype   : void LCD_voidSelectLine(u8 u8Line);
  * Description : Select line 1 or 2 in LCD
  * Arguments   : choose line from (LCD_LINE1 or LCD_LINE2)
  * return      : void
  */
  void LCD_voidSelectLine(u8 u8Line);

 /*
  * Prototype   : void LCD_voidSetCursorPosition(u8 u8Line,u8 u8Position);
  * Description : set cursor in specific position (choose line and position in line from 1 to 16)
  * Arguments   : line LCD_LINE1 or LCD_LINE2
  *               Position from 1 to 16
  * return      : void
  */
  void LCD_voidSetCursorPosition(u8 u8Line,u8 u8Position);

 /*
  * Prototype   : void LCD_voidDisplayChar(u8 u8CharData);
  * Description : Output character to current cursor position
  * Arguments   : Char_Data : Character to be displayed
  * return      : void
  */
  void LCD_voidDisplayChar(u8 u8CharData);

 /*
  * Prototype   : void LCD_voidDisplayChar(u8 u8CharData);
  * Description : Output String or a number to LCD at current cursor position
  * Arguments   : DataPointer: pointer to data stream to be displayed it could be
  *               - Number of type u32 but function can handle up to 10 digit number (0,1,...,4294967296)
  *               - u8 character string
  *			      Data type: LCD_NUMBER or LCD_STRING
  * return      : void
  */
  void LCD_voidDisplayString(u32 *u32StringDataPtr,u8 u8DataType);

 /*
  * Prototype   : void LCD_voidShiftRight(void);
  * Description : Shift all display right one step
  * Arguments   : void
  * return      : void
  */
  void LCD_voidShiftRight(void);

 /*
  * Prototype   : void LCD_voidShiftLeft(void);
  * Description : Shift all display left one step
  * Arguments   : void
  * return      : void
  */
  void LCD_voidShiftLeft(void);

 /*
  * Prototype   : void LCD_voidCursorShiftRight(u8 u8Steps);
  * Description : shift cursor position right number of steps
  * Arguments   : Number of Steps
  * return      : void
  */
  void LCD_voidCursorShiftRight(u8 u8Steps);

 /*
  * Prototype   : void LCD_voidCursorShiftLeft(u8 u8Steps);
  * Description : shift cursor position Left number of steps
  * Arguments   : Number of Steps
  * return      : void
  */
  void LCD_voidCursorShiftLeft(u8 u8Steps);

 /*
  * Prototype   : void LCD_voidCursorDisplayOnOff(u8 u8Status);
  * Description : set cursor display on and off
  * Arguments   : Status : LCD_Disp_ON_OFF or LCD_CURSOR_OFF
  * return      : void
  */
  void LCD_voidCursorDisplayOnOff(u8 u8Status);

 /*
  * Prototype   : void LCD_voidCursorBlinkOnOff(u8 u8Status);
  * Description : set cursor blinking on and off
  * Arguments   : Status : LCD_Disp_ON_OFF or LCD_BLINK_OFF
  * return      : void
  */
  void LCD_voidCursorBlinkOnOff(u8 u8Status);


 /*
  * Prototype   : void LCD_voidDisplayOnOff(u8 u8Status);
  * Description : set Whole display on & off
  * Arguments   : Status :
  *               LCD_Disp_OFF or LCD_Disp_ON_OFF
  * return      : void
  */
  void LCD_voidScreenDisplayOnOff(u8 u8Status);


#endif /* HAL_LCD_LCD_H_ */

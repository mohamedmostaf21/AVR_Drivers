/*
 * LCD.c
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
/*==============================================================================================================================================
 * Global variables
 *==============================================================================================================================================*/

/*Initialize display with cursor and display enabled*/
u8 DisplayAndCursorCommand  = 0b00001111;
/*initialize font size with 7 Dot size, 2 lines and, 4Bit Modes */
u8 FontSizeAndLineCommand   = 0b00101000;

u8 upperBoundVal[4];
u8 upperBoundGroup[4] = {LCD_D4, LCD_D5, LCD_D6, LCD_D7};

/*==============================================================================================================================================
 * Private Modules
 *==============================================================================================================================================*/

static void LCD_voidWriteCommand(u8 u8Command);
static void LCD_voidWriteData(u8 u8Data);




/*=================================================================================================
 * 8 Bit Mode
 *=================================================================================================*/

#if (LCD_MODE == LCD_8BIT)
/*
  * Prototype   : u8 LCD_voidWriteCommand(u8 u8Command);
  * Description : write command to LCD
  * Arguments   : u8 Command
  * return      : void
  */
void LCD_voidWriteCommand(u8 u8Command)
 {
	  /*Set RW pin 0 (Write Mode selected)*/
	  DIO_enuWritePin(LCD_RW, DIO_LOW);
	  /*Set RS pin 0 (Instruction register selected)*/
	  DIO_enuWritePin(LCD_RW, DIO_LOW);
	  /*output instruction data to Data Bus*/
	  switch(u8Command)
	  {
		  /*if command value is 1 clear data register and output 1 to it*/
		  case 1  : {
			  	  	  DIO_enuWriteGroup(DataREG, DataVal, 8);
			  	  	  DIO_enuWritePin(LCD_D0, DIO_HIGH);
		  	  	  	}
		  break;
		  /*else output command to data register*/
		  default : {
			  	  	  PutOnBusLCD(DataREG, u8Command);
		  	  	  	}

	  }/*end of switch case*/

	  /*Set EN pin 1 (LCD Read data )*/
	  DIO_enuWritePin(LCD_EN, DIO_HIGH);
	  //_delay_ms(2);
	  Delay_ms(2);
	  /*Set EN pin 0 (LCD Write data to its reg)*/
	  DIO_enuWritePin(LCD_EN, DIO_LOW);
 }

/*
 * Prototype   : void LCD_voidWriteData(u8 u8Data);
 * Description : write Data to LCD
 * Arguments   : u8 Data
 * return      : void
 */
 void LCD_voidWriteData(u8 u8Data)
 {
	 /*Set RW pin 0 (Write Mode selected)*/
	 DIO_enuWritePin(LCD_RW, DIO_LOW);
	 /*Set RS pin 1 (Data register selected)*/
	 DIO_enuWritePin(LCD_RW, DIO_HIGH);
	 /*output data to Data Bus*/
	 /*output instruction data to Data Bus*/
	 switch(u8Data)
	 {
		 /*if Data value is 1 clear data register and output 1 to it*/
		 case 1  : {
			  	  	 DIO_enuWriteGroup(DataREG, DataVal, 8);
			  	  	 DIO_enuWritePin(LCD_D0, DIO_HIGH);
		 	 	   }
		 break;
		 /*else output Data to data register*/
		 default : {
			 	 	 PutOnBusLCD(DataREG, u8Data);
		 	 	   }

	 }/*end of switch case*/

	 /*Set EN pin 1 (LCD Read data )*/
	 DIO_enuWritePin(LCD_EN, DIO_HIGH);
	 //_delay_ms(2);
	 Delay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 DIO_enuWritePin(LCD_EN, DIO_LOW);

 }/*end of LCD_u8WriteData()*/



 /*=================================================================================================
  * 4 Bit Mode
  *=================================================================================================*/

#elif (LCD_MODE == LCD_4BIT)


/*
* Prototype   : u8 HLCD_voidWriteCommand(u8 u8Command);
* Description : write command to LCD
* Arguments   : u8 Command
* return      : void
*/
  void LCD_voidWriteCommand(u8 u8Command)
  {
 	 /*Set RW pin 0 (Write Mode selected)*/
	  DIO_enuWritePin(LCD_RW, DIO_LOW);
 	 /*Set RS pin 0 (Instruction register selected)*/
	  DIO_enuWritePin(LCD_RW, DIO_LOW);
 	 /*output first 4 bits instruction data to Data Bus*/
 	 for(u8 i=4;i<8;i++)
 	 {
 		 /*Output value of Instruction bit i at Data Register DIO Pin i*/
 		upperBoundVal[i-4] = GET_BIT(u8Command, i);

 	 }
 	 DIO_enuWriteGroup(upperBoundGroup, upperBoundVal, 4);
 	 /*latch sent data*/
 	 /*Set EN pin 1 (LCD Read data )*/
 	 DIO_enuWritePin(LCD_EN, DIO_HIGH);
 	 //_delay_ms(2);
 	 Delay_ms(2);
 	 /*Set EN pin 0 (LCD Write data to its reg)*/
 	 DIO_enuWritePin(LCD_EN, DIO_LOW);

 	 /*output second 4 bits instruction to data bus*/
 	 for(u8 i=0;i<4;i++)
 	 {
 		 /*Output value of Instruction bit i at Data Register DIO Pin i*/
 		upperBoundVal[i] = GET_BIT(u8Command, i);
 	 }
 	 DIO_enuWriteGroup(upperBoundGroup, upperBoundVal, 4);
 	 /*latch sent data*/
 	 /*Set EN pin 1 (LCD Read data )*/
 	 DIO_enuWritePin(LCD_EN, DIO_HIGH);
 	 //_delay_ms(2);
 	 Delay_ms(2);
 	 /*Set EN pin 0 (LCD Write data to its reg)*/
 	 DIO_enuWritePin(LCD_EN, DIO_LOW);
}/*end of LCD_voidWriteCommand()*/


/*
* Prototype   : void HLCD_voidWriteData(u8 u8Data);
* Description : write Data to LCD
* Arguments   : u8 Data
* return      : void
*/
void LCD_voidWriteData(u8 u8Data)
  {
 	 /*Set RW pin 0 (Write Mode selected)*/
	 DIO_enuWritePin(LCD_RW, DIO_LOW);
 	 /*Set RS pin 1 (Data register selected)*/
 	 DIO_enuWritePin(LCD_RS, DIO_HIGH);
 	 /*output first 4 Data bits to Data Bus*/
 	 for(u8 i=4;i<8;i++)
 	 {
 		 /*Output value of Data bit i at Data register DIO Pin i*/
 		 upperBoundVal[i-4] = GET_BIT(u8Data, i);
 	 }
 	 DIO_enuWriteGroup(upperBoundGroup, upperBoundVal, 4);
 	 /*latch sent data*/
 	 /*Set EN pin 1 (LCD Read data )*/
 	 DIO_enuWritePin(LCD_EN, DIO_HIGH);
 	 //_delay_ms(2);
 	 Delay_ms(2);
 	 /*Set EN pin 0 (LCD Write data to its reg)*/
 	 DIO_enuWritePin(LCD_EN, DIO_LOW);

 	 /*output second 4 bits Data to data bus*/
 	 for(u8 i=0;i<4;i++)
 	 {
 		 /*Output value of Data bit i at Data register DIO Pin i*/
 		 upperBoundVal[i] = GET_BIT(u8Data, i);
 	 }
 	 DIO_enuWriteGroup(upperBoundGroup, upperBoundVal, 4);
 	 /*latch sent data*/
 	 /*Set EN pin 1 (LCD Read data)*/
 	 DIO_enuWritePin(LCD_EN, DIO_HIGH);
 	 //_delay_ms(2);
 	 Delay_ms(2);
 	 /*Set EN pin 0 (LCD Write data to its reg)*/
 	 DIO_enuWritePin(LCD_EN, DIO_LOW);

  }/*end of LCD_voidWriteData()*/


 #endif /*end of Mode select*/


void LCD_voidInitialize(void)
{

	 //_delay_ms(50);
	 Delay_ms(50);

	 /*==============================================================
	  * Choose font size and number of lines
	  *==============================================================*/
	 /*Set Font size value 5*7 dots or 5*10 dots*/
	  L_UTILS_SET_BIT_VALUE(FontSizeAndLineCommand,LCD_FONT_BIT,LCD_FONT_SIZE);
	 /*Set number of lines 1 or 2*/
	  L_UTILS_SET_BIT_VALUE(FontSizeAndLineCommand,LCD_LINE_BIT,LCD_LINE_MODE);

	 /*==============================================================
	  * LCD initialization sequence
	  *==============================================================
	  * 8Bit Mode initialization
	  *====================================*/
	 #if (LCD_MODE == LCD_8BIT)
	    /*Choose 8Bit mode in function set instruction*/
		SET_BIT(FontSizeAndLineCommand,LCD_DATALENGTH_BIT);
		/*send Function set instruction*/
		LCD_voidWriteCommand(FontSizeAndLineCommand);
		//_delay_ms(1);
		Delay_ms(1);
	 /*====================================
	  * 4Bit Mode initialization
	  *====================================*/
    #elif (LCD_MODE == LCD_4BIT)
		/*send 4BIT Function set instruction two times*/
		LCD_voidWriteCommand(LCD_FN_SET_4BIT);
		/*send Function set instruction for font and number of lines*/
		LCD_voidWriteCommand(FontSizeAndLineCommand);
		//_delay_ms(1);
		Delay_ms(1);
	 #endif

	 /*send Display ON OFF instruction*/
	 LCD_voidWriteCommand(DisplayAndCursorCommand);
	 //_delay_ms(1);
	 Delay_ms(1);
	 /*send Display clear instruction*/
	 LCD_voidWriteCommand(LCD_DISP_CLEAR);
	 //_delay_ms(2);
	 Delay_ms(2);
	 /*send ENTRY MODE set instruction*/
	 LCD_voidWriteCommand(LCD_ENTRY_MODE);
	 //_delay_ms(2);
	 Delay_ms(2);


	 /*return to DDRAM address 1*/
	 LCD_voidWriteCommand(LCD_DDRAM_ADD1);

}/*end of LCD_u8Initialize()*/

void LCD_voidClear(void)
{
	  /*send Display clear instruction*/
	  LCD_voidWriteCommand(LCD_DISP_CLEAR);

}/*end of LCD_voidClear()*/


void LCD_voidReturnHome(void)
{
  /*send Return home instruction*/
  LCD_voidWriteCommand(LCD_RET_HOME);

}/*end of LCD_voidReturnHome()*/

void LCD_voidSelectLine(u8 u8Line)
{
  /*choose line*/
  switch(u8Line)
  {
	  case LCD_LINE1 : {  LCD_voidWriteCommand(LCD_DDRAM_ADD1); } break;
	  case LCD_LINE2 : {  LCD_voidWriteCommand(LCD_DDRAM_ADD2); } break;

  }/*end of line switch case*/

}/*end of LCD_voidSelectLine()*/

void LCD_voidSetCursorPosition(u8 u8Line,u8 u8Position)
{
  /*choose line*/
  switch(u8Line)
  {
	  case LCD_LINE1 : { LCD_voidWriteCommand(LCD_DDRAM_ADD1+ u8Position -1); } break;
	  case LCD_LINE2 : { LCD_voidWriteCommand(LCD_DDRAM_ADD2+ u8Position -1); } break;

  }/*end of line switch case*/

}/*end of LCD_voidSetCursorPosition()*/


void LCD_voidDisplayChar(u8 u8CharData)
{
  /*check character type*/
  if( (u8CharData >= 0) && (u8CharData < 10) )
  {
	  /*if character is number*/
	  LCD_voidWriteData((u8CharData+'0'));

  }
  else
  {
	  /*if character is char*/
	  LCD_voidWriteData(u8CharData);

  }/*end of character type check*/


}/*end of LCD_voidDisplayChar*/



void LCD_voidShiftRight(void)
{
	  /*send shift right instruction*/
	  LCD_voidWriteCommand(LCD_DISP_SHIFT_RIGHT);

}/*end of LCD_voidShiftRight()*/


void LCD_voidShiftLeft(void)
{
	 /*send shift left instruction*/
	 LCD_voidWriteCommand(LCD_DISP_SHIFT_LEFT);

}/*end of LCD_voidShiftLeft()*/


void LCD_voidCursorShiftRight(u8 u8Steps)
{
	  /*loop steps*/
	  for(u8 i = 0 ; i < u8Steps ; i++)
	  {
		  /*Shift cursor one step right instruction*/
		  LCD_voidWriteCommand(LCD_CURSOR_SHIFT_RIGHT);

	  }/*end of steps for loop*/

}/*end of LCD_voidCursorShiftRight()*/


void LCD_voidCursorShiftLeft(u8 u8Steps)
{
	  /*loop steps*/
	  for(u8 i = 0 ; i < u8Steps ; i++)
	  {
		  /*Shift cursor one step Left instruction*/
		  LCD_voidWriteCommand(LCD_CURSOR_SHIFT_LEFT);

	  }/*end of steps for loop*/

}/*end of LCD_voidCursorShiftLeft()*/

/*
* Prototype   : void HLCD_voidCursorDisplayOnOff(u8 u8Status);
* Description : set cursor display on and off
* Arguments   : Status : HLCD_ON or HLCD_OFF
* return      : void
*/
void LCD_voidCursorDisplayOnOff(u8 u8Status)
{
	  /*Set Display status value (on or off)*/
	  L_UTILS_SET_BIT_VALUE(DisplayAndCursorCommand,LCD_CURSOR_BIT,u8Status);
	  /*Send command*/
	  LCD_voidWriteCommand(DisplayAndCursorCommand);

}/*end of LCD_voidCursorDisplayOnOff()*/


void LCD_voidCursorBlinkOnOff(u8 u8Status)
{
	  /*Set Cursor status value (on or off)*/
	  L_UTILS_SET_BIT_VALUE(DisplayAndCursorCommand,LCD_BLINK_BIT,u8Status);
	  /*Send command*/
	  LCD_voidWriteCommand(DisplayAndCursorCommand);

}/*end of LCD_voidCursorBlinkOnOff()*/



void LCD_voidScreenDisplayOnOff(u8 u8Status)
{
	  /*Set Display status value (on or off)*/
	  L_UTILS_SET_BIT_VALUE(DisplayAndCursorCommand,LCD_DISP_BIT,u8Status);
	  /*Send command*/
	  LCD_voidWriteCommand(DisplayAndCursorCommand);

}/*end of LCD_voidDisplayOnOff()*/

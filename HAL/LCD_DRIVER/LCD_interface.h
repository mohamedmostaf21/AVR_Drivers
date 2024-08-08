/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

#ifndef LCD_H_
#define LCD_H_

/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PC5|---------------->|E         |
 |        PC6|---------------->|RW        |
 |        PC7|---------------->|RS        |
 -----------                   ----------
 */

/*Define Register selector pin*/
#define LCD_RS 		DIO_PIN_NUM_23
/*Define Register selector pin*/
#define LCD_RW 		DIO_PIN_NUM_22
/*Define Register selector pin*/
#define LCD_EN  	DIO_PIN_NUM_21



/** D0 t0 D7 **/
#define LCD_D0		DIO_PIN_NUM_24
#define LCD_D1		DIO_PIN_NUM_25
#define LCD_D2		DIO_PIN_NUM_26
#define LCD_D3		DIO_PIN_NUM_27
#define LCD_D4		DIO_PIN_NUM_28
#define LCD_D5		DIO_PIN_NUM_29
#define LCD_D6		DIO_PIN_NUM_30
#define LCD_D7		DIO_PIN_NUM_31
extern u8 REG[8];
#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position
void PutOnLCD(u8* u8DataREG, u8 u8num);
/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void);

/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(u8 u8CmdCpy);

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(u8 u8DataCpy);

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index);


void Gotoxy (u8 Y,u8 X);
void LCD_vidWriteExtraChar (u8 Y,u8 X);

#endif /* LCD_H_ */

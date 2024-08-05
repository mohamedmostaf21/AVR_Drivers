/*
 * LCD_priv.h
 *
 *  Created on: Aug 4, 2024
 *      Author: k.m
 */

#ifndef HAL_LCD_LCD_PRIV_H_
#define HAL_LCD_LCD_PRIV_H_
/*data length*/
#define LCD_4BIT			0
#define LCD_8BIT			1

/*number of lines*/
#define LCD_ONE_LINE		0
#define LCD_TWO_LINES		1

/*font size*/
#define LCD_7_DOTS			0
#define LCD_10_DOTS			1



/*
 * Display CLEAR instruction format
 * 0b00000001
 * Clear Display and return cursor to initial position
 * Initialize Address counter AC    *Fill LCD DDRAM with spaces
 */
 #define LCD_DISP_CLEAR		  	0b00000001

/*
 * Return home instruction format
 * 0b0000001-X
 * X:Don't care
 * return cursor to initial position
 * Doesn't effect DDRAM
 */

#define LCD_RET_HOME			0b00000010

/*
 *Entry mode instruction format
 * 0b000001-I/D-Sh
 * I/D:Cursor Direction 0->decrement / 1->Increment
 * Sh:Cursor on  0->NO Shift / 1->Shift R/L epend on I/D
 */
#define LCD_ENTRY_MODE			0b00000110

/*
 * Shift Right display instruction format
 * 0b0001-S/C-R/L-X-X
 * R/L:Cursor Direction 0->Shift Left / 1->Shift Right
 * S/C:Shift on  0->no shift / 1->Shift Shift entire disp with cursor Right or Left depend on S/C
 */
#define LCD_DISP_SHIFT_RIGHT	0b00011100

/*
 * Shift Left display instruction format
 * 0b0001-S/C-R/L-X-X
 * R/L:Cursor Direction 0->Shift Left/ 1->Shift Right
 * S/C:Shift on  0->no shift / 1->Shift Shift entire disp with cursor Right or Left depend on S/C
 */
#define LCD_DISP_SHIFT_LEFT     0b00011000

/*
 * Shift Right display instruction format
 * 0b0001-S/C-R/L-X-X
 * R/L:Cursor Direction 0->Shift Left/ 1->Shift Right
 * S/C:Shift on  0->no shift /1->Shift Shift entire disp with cursor Right or Left depend on S/C
 */
#define LCD_CURSOR_SHIFT_RIGHT  0b00010100

/*
 * Shift Left display instruction format
 * 0b0001-S/C-R/L-X-X
 * R/L:Cursor Direction 0->Shift Left/ 1->Shift Right
 * S/C:Shift on  0->no shift /1->Shift Shift entire disp with cursor Right or Left depend on S/C
 */
#define LCD_CURSOR_SHIFT_LEFT   0b00010000

/*
 * set DDRAM address instruction format
 * 0b1-AC6~AC0
 * AC: address counter bits from 0 to 6
 */
#define LCD_DDRAM_ADD1		  0b10000000

/*
 * set DDRAM address instruction format
 * 0b1-AC6~AC0
 * AC: address counter bits from 0 to 6
 */
#define LCD_DDRAM_ADD2		  0b11000000

/*
 * Functions set instruction format
 * send 0010 two times i a row
 */
#define LCD_FN_SET_4BIT		  0b00100010

/*
 * Display ON OFF instruction format
 * 0b00001-D-C-B
 * D:Display on 0->OFF/1->ON
 * C:Cursor on  0->OFF/1->ON
 * B:Blinking   0->OFF/1->ON
 * those bits will be used in bit manipulation
 */
 #define LCD_BLINK_BIT			0
 #define LCD_CURSOR_BIT			1
 #define LCD_DISP_BIT			2

 /*
 * Functions set instruction format
 * 0b001-DL-N-F-X-X
 * DL:Data length    0->4BIT/1->8BIT
 * N:Number of lines 0->(1)/1->(2)
 * F:Character Font  0->(5X7)/1->(5X10)
 */
 #define LCD_FONT_BIT          2
 #define LCD_LINE_BIT          3
 #define LCD_DATALENGTH_BIT    4

void PutOnBusLCD(u8* u8DataREG, u8 u8num);
#endif /* HAL_LCD_LCD_PRIV_H_ */

/*
 * LCD_cfg.h
 *
 *  Created on: Aug 4, 2024
 *      Author: k.m
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_
/*
 * Choose LCD Data length Mode :
 * LCD_8BIT or LCD_4BIT
 */
#define LCD_MODE		  	LCD_4BIT

/*
 * Choose LCD Number of lines :
 * LCD_ONE_LINE or LCD_TWO_LINES
 */
#define LCD_LINE_MODE   	LCD_TWO_LINES

/*
 * Choose LCD Font size:
 * LCD_7_DOTS or LCD_10_DOTS
 * 10 dots size ONLY work with one line mode
 */
#define LCD_FONT_SIZE   	LCD_7_DOTS

/*============================================================================
 * LCD Connections
 *============================================================================
 * in 4Bit mode:
 * - Control  and data registers must be the same
 * - Data bits are connected D4->Bit4 D5->Bit5 D6->Bit6 D7->Bit7
 */

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
extern u8 DataREG[8];
extern u8 DataVal[8];

#endif /* HAL_LCD_LCD_CFG_H_ */

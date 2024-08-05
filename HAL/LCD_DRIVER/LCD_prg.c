/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

/********************************** Header Files INCLUSIONS ****************************/
#define F_CPU 16000000
#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"
#include "util/delay.h"

#include "../../MCAL/DIO/DIO.h"
#include "LCD_interface.h"
#include "LCD_Extra.h"
u8 REG[8] = {LCD_D0, LCD_D1, LCD_D2, LCD_D3, LCD_D4, LCD_D5, LCD_D6, LCD_D7};

void PutOnLCD(u8* u8REG, u8 u8num){
    u8 u8Num[8]; //0x0011 1111
  	u8 cntr;
  	for(cntr = 0; cntr < 8; cntr++){
  		u8Num[cntr] = GET_BIT(u8num, cntr);
  	}
    DIO_enuWriteGroup(u8REG, u8Num, 8);
}
/***************************************************************************************/

/***************************************************************************************/
/********************************** Function Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/



/***************************************************************************************/
/********************************** Constant Variables *********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void)
{
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Return Home  */
	LCD_vidSendCommand(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(2);

}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(u8 u8CmdCpy)
{

	/* Set RS to LOW */
	DIO_enuWritePin(LCD_RS, DIO_LOW);

	/* Set R/W to LOW */
	DIO_enuWritePin(LCD_RW, DIO_LOW);

	/* Set E to HIGH  */
	DIO_enuWritePin(LCD_EN, DIO_HIGH);

	/* Load Command on Data bus */

	PutOnLCD(REG, u8CmdCpy);



	/* Set E to LOW */
	DIO_enuWritePin(LCD_EN, DIO_LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_enuWritePin(LCD_EN, DIO_HIGH);

	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(u8 u8DataCpy)
{
	/* Set RS to HIG */
	DIO_enuWritePin(LCD_RS, DIO_HIGH);

	/* Set R/W to LOW */
	DIO_enuWritePin(LCD_RW, DIO_LOW);

	/* Set E to HIGH */
	DIO_enuWritePin(LCD_EN, DIO_HIGH);

	/* Load Command on Data bus */
	PutOnLCD(REG, u8DataCpy);

	/* Set E to LOW */
	DIO_enuWritePin(LCD_EN, DIO_LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_enuWritePin(LCD_EN, DIO_HIGH);

	/* Delay to let the LCD Display the character */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index)
{

//	/* Local loop index */
//	u8 u8Index = 0;
	u8 iteration=0;
//	while (pu8StringCpy[u8Index] != '\0')
	for (iteration=0; iteration<u8Index ; iteration++)
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr(pu8StringCpy[iteration]);

//		/* Increment local loop index */
//		u8Index++;

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}

}

/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void Gotoxy (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	LCD_vidSendCommand(X+127);
		    break;
		    case 2:
		    	LCD_vidSendCommand(X+191);
		    break;
		    default:
		    break;
	    }
	}
}

/***************************************************************************************/
/* Description! Interface to write extra characters saved in the CGRAM                 */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteExtraChar (u8 Y,u8 X)
{
    u8 iteration1,iteration2;

    /*DDRAM-->CGRAM*/
    LCD_vidSendCommand(64);
	for(iteration1=0 ; iteration1<64 ; iteration1++)
	{
		LCD_vidWriteCharctr(ExtraChar[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_vidSendCommand(128);
	Gotoxy(Y,X);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_vidWriteCharctr(iteration2);

		_delay_ms(5);
	}
}

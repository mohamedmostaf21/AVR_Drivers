/*
 * KPD_prog.c
 *
 *  Created on: Aug 7, 2024
 *      Author: k.m
 */


/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! Keypad driver for 4x4 keypad                                          */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/


/********************************** Header Files INCLUSIONS ****************************/
#include "../../LIBS/STD_TYPES.h"

#define F_CPU 8000000
#include "util/delay.h"

#include "../../MCAL/DIO/DIO.h"
#include "KPD_interface.h"
/***************************************************************************************/

/************* KeyPad Key Index ***************/
/*         Col_3    Col_2   Col_1   Col_0     */
/*	                                          */
/* row_0      1        2       3       4      */
/*	                                          */
/* row_1  	  5        6       7       8      */
/*	                                          */
/* row_2	  9        10      11      12     */
/*	                                          */
/* row_3	  13       14      15      16     */
/**********************************************/


/*************************************** Constants *************************************/
/* Values of the Key Pad switches                                                      */
/* Matrix is not standard it depends on the connection between the Micro and KeyPad    */
const u8 KPD_au8SwitchVal[4][4] ={    { 1,  2,  3,  'A'},
									  { 4,  5,  6,  'B'},
									  { 7,  8,  9,  'C'},
									  {'#', 0, '*', 'D'}
};

/***************************************************************************************/


/***************************************** Macros **************************************/


#define COL_INIT   0

#define COL_FIN    4

#define ROW_INIT   4

#define ROW_FIN    8

#define NOT_PRESSED    0
/***************************************************************************************/


/***************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
u8 KPD_u8GetPressedKeyy(void)
{

  u8 LOC_u8Column;

  u8 LOC_u8Row;

  /* Initialize the switch status to NOT Pressed                                                                     */
  u8 LOC_u8Retrun = NOT_PRESSED;
  u8 status;
  /* Looping on columns of the Key Pad                                                                               */
  for (LOC_u8Column = 0 + COL_INIT; LOC_u8Column < COL_FIN; LOC_u8Column++)
  {
    /* Activate the Column                                                                                           */
    DIO_enuWritePin(LOC_u8Column, DIO_LOW);

    /* Loop on the rows of the Key Pad                                                                               */
    for (LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++)
    {
    	DIO_enuReadPin(LOC_u8Row, &status);
      /* Check the status of the switch                                                                              */
      if (!status)
      {
        /* Get the value of the currently pressed switch                                                             */
        LOC_u8Retrun = KPD_au8SwitchVal[LOC_u8Column - COL_INIT][LOC_u8Row - ROW_INIT];
        DIO_enuReadPin(LOC_u8Row, &status);
        /* Wait until the switch is released (Single Press)                                                          */
        while (!status)
          ;

        /* Delay to avoid bouncing                                                                                   */
        _delay_ms(10);

      }
    }

    /* Deactivate the Column                                                                                         */
    DIO_enuWritePin(LOC_u8Column, DIO_HIGH);
  }

  return LOC_u8Retrun;
}

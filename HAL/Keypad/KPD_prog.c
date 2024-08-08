/*
 * KPD_prog.c
 *
 *  Created on: Aug 7, 2024
 *      Author: k.m
 */


/*
 * Prototype   : void KPD_voidInitializeKeypad(void);
 * Description : initialize 4X4 keypad at a given port set 4 pins output and 4 pins input
 * Arguments   : void
 * Return      : void
 */
#include "../../LIBS/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIBS/delay.h"
#include "KPD_prog.h"
#include "KPD_cfg.h"
#include "KPD_priv.h"

void Keypad_voidInit(void)
{
    /* Set Column Initial Values to 1111 */
    DIO_enuWritePin(C1, DIO_HIGH);
    DIO_enuWritePin(C2, DIO_HIGH);
    DIO_enuWritePin(C3, DIO_HIGH);;
    DIO_enuWritePin(C4, DIO_HIGH);
    /* Enable Pull down Resistors at Input Rows */
    DIO_enuWritePin(R1, DIO_LOW);;
    DIO_enuWritePin(R2, DIO_LOW);
    DIO_enuWritePin(R3, DIO_LOW);
    DIO_enuWritePin(R4, DIO_LOW);
}

Keypad_enuState Keypad_u8GetPressedButtonValue(u8 *u8PtrToVal)
{
	Keypad_enuState Local_KeypadState;
    u8 Local_ColCount, Local_RowCount;
    u8 rowVal;
    u8 flag = 0;
    if (u8PtrToVal != NULL_Ptr)
    {
        for (Local_ColCount = 0; Local_ColCount < KEYPADSIZE; Local_ColCount++)
        {
            //activate current colmun
        	DIO_enuWritePin(ColArr[Local_ColCount], DIO_HIGH);
            for (Local_RowCount = 0; Local_RowCount < KEYPADSIZE; Local_RowCount++)
            {
                //check row value if it is 0 then this column and row is connected
                DIO_enuReadPin(RowArr[Local_RowCount], &rowVal);
                if (rowVal)
                {
                	*u8PtrToVal = buttonArr[Local_ColCount][Local_RowCount];
                	 /* Wait until the switch is released (Single Press)                                                          */
                	 DIO_enuReadPin(RowArr[Local_RowCount], &rowVal);
                	while (rowVal);

					/* Delay to avoid bouncing                                                                                   */
					Delay_ms(10);
                }
            }
//            //if the inner row loop has broken and flag is set,
//            //place value in return pointer and exit outer column loop.
//            if (flag == 1)
//            {
//                *u8PtrToVal = u8buttonArr[Local_ColCount][Local_RowCount];
//                /* Delay to avoid bouncing                                                                                   */
//                Delay_ms(10);
//                break;
//            }



            //de-activate current column.
            DIO_enuWritePin(ColArr[Local_ColCount], DIO_LOW);
        }
        Local_KeypadState = Keypad_enuNormalState;
    }
    else
        Local_KeypadState = Keypad_enuNullPointerException;

    return Local_KeypadState;
}

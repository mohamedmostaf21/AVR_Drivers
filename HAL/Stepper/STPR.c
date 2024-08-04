/*
 * STPR.c
 *
 *  Created on: Aug 3, 2024
 *      Author: Mohamed
 */
#include "../../LIBS/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIBS/delay.h"
#include "STPR.h"
#include "STPR_cfg.h"
#include "STPR_priv.h"


void STPR_FullStep_Right(u8 speed)
{
	//full step
	DIO_enuWritePin(STPR_COIL_0,DIO_HIGH); //activate coil 1
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_0,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_1,DIO_HIGH); //activate coil 2
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_1,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_2,DIO_HIGH);//activate coil 3
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_2,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_3,DIO_HIGH); //activate coil 4
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_3,DIO_LOW);
}

void STPR_FullStep_Left(u32 speed)
{
	//full step
	DIO_enuWritePin(STPR_COIL_3,DIO_HIGH); //activate coil 4
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_3,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_2,DIO_HIGH); //activate coil 3
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_2,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_1,DIO_HIGH);//activate coil 2
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_1,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_0,DIO_HIGH); //activate coil 1
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_0,DIO_LOW);
}

void STPR_HalfStep_Right(u8 speed)
{

	DIO_enuWritePin(STPR_COIL_0,DIO_HIGH); //activate coil 1
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_0,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_0,DIO_HIGH);//activate coil 1,2
	DIO_enuWritePin(STPR_COIL_1,DIO_HIGH);
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_0,DIO_LOW);//deactivate coil 1,2
	DIO_enuWritePin(STPR_COIL_1,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_1,DIO_HIGH);//activate coil 2
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_1,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_1,DIO_HIGH); //activate coil 2,3
	DIO_enuWritePin(STPR_COIL_2,DIO_HIGH);
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_1,DIO_LOW); //deactivate coil 2,3
	DIO_enuWritePin(STPR_COIL_2,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_2,DIO_HIGH); //activate coil 3
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_2,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_2,DIO_HIGH); //activate coil 3,4
	DIO_enuWritePin(STPR_COIL_3,DIO_HIGH);
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_2,DIO_LOW); //deactivate coil 3,4
	DIO_enuWritePin(STPR_COIL_3,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_3,DIO_HIGH); //activate coil 4
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_3,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_0,DIO_HIGH);  //activate coil 1,4
	DIO_enuWritePin(STPR_COIL_3,DIO_HIGH);
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_0,DIO_LOW);  //deactivate coil 1,4
	DIO_enuWritePin(STPR_COIL_3,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_0,DIO_HIGH);
	Delay_ms(speed);
}

void STPR_HalfStep_Left(u8 speed)
{
	//half step
	DIO_enuWritePin(STPR_COIL_0,DIO_HIGH);  //deactivate coil 1,4
	DIO_enuWritePin(STPR_COIL_3,DIO_HIGH);
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_0,DIO_LOW);  //deactivate coil 1,4
	DIO_enuWritePin(STPR_COIL_3,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_3,DIO_HIGH);  //activate coil 4
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_3,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_3,DIO_HIGH); //activate coil 3,4
	DIO_enuWritePin(STPR_COIL_2,DIO_HIGH);
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_3,DIO_LOW); //deactivate coil 3,4
	DIO_enuWritePin(STPR_COIL_2,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_2,DIO_HIGH);//activate coil 3
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_2,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_2,DIO_HIGH); //activate coil 2,3
	DIO_enuWritePin(STPR_COIL_1,DIO_HIGH);
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_2,DIO_LOW); //deactivate coil 2,3
	DIO_enuWritePin(STPR_COIL_1,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_1,DIO_HIGH);//activate coil 2
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_1,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_1,DIO_HIGH); //activate coil 1,2
	DIO_enuWritePin(STPR_COIL_0,DIO_HIGH);
	Delay_ms(speed);
	DIO_enuWritePin(STPR_COIL_1,DIO_LOW); //deactivate coil 1,2
	DIO_enuWritePin(STPR_COIL_0,DIO_LOW);
	DIO_enuWritePin(STPR_COIL_0,DIO_HIGH); //activate coil 1
	Delay_ms(speed);

}







void STPR_Stop(void)
{
	u8 allPins[4] = {STPR_COIL_0, STPR_COIL_1, STPR_COIL_2, STPR_COIL_3};
	u8 disableAll[4] = {DIO_LOW};
	DIO_enuWriteGroup(allPins, disableAll, 4); //disable all coils

}

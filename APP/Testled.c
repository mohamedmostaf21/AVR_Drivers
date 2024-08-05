/*
 * Testled.c
 *
 *  Created on: Aug 5, 2024
 *      Author: k.m
 */

#include "../MCAL/DIO/DIO.h"
#include "../LIBS/BIT_MATH.h"
#include "../MCAL/DIO/DIO_priv.h"
#include "../LIBS/delay.h"

int main(){
	DIO_voidInit();

	DIO_enuStatePullup(DIO_PIN_NUM_24, DIO_HIGH);
	DIO_enuWritePin(DIO_PIN_NUM_25, DIO_LOW);
	u8 out;
	while(1){
		DIO_enuReadPin(DIO_PIN_NUM_24, &out);
		if(out == DIO_LOW){
			DIO_enuWritePin(DIO_PIN_NUM_25, DIO_HIGH);


		}else if(out == DIO_HIGH){
			DIO_enuWritePin(DIO_PIN_NUM_25, DIO_LOW);
		}
	}


	return 0;
}

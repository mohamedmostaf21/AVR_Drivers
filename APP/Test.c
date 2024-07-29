
#include "../MCAL/DIO/DIO.h"
#include "../LIBS/delay.h"
int main(){
	 DIO_voidInit();
	 u8 pins[8] = {DIO_PIN_NUM_0, DIO_PIN_NUM_1, DIO_PIN_NUM_2, DIO_PIN_NUM_3,DIO_PIN_NUM_4, DIO_PIN_NUM_5, DIO_PIN_NUM_6, DIO_PIN_NUM_7};
	// u8 values_high[8] = {DIO_HIGH, DIO_HIGH, DIO_HIGH, DIO_HIGH, DIO_HIGH, DIO_HIGH, DIO_HIGH, DIO_HIGH};
	 u8 values_low[8] = {DIO_LOW, DIO_LOW, DIO_LOW, DIO_LOW, DIO_LOW, DIO_LOW, DIO_LOW, DIO_LOW};
	 DIO_enuWriteGroup(pins, values_low, 8);

	 //PB0, PB1
	 DIO_enuWritePin(DIO_PIN_NUM_8, DIO_LOW);
	 DIO_enuWritePin(DIO_PIN_NUM_9, DIO_LOW);
	 while(1){
		 DIO_enuWritePin(DIO_PIN_NUM_4, DIO_HIGH);
		 DIO_enuWritePin(DIO_PIN_NUM_5, DIO_HIGH);
		Delay_ms(75);
		DIO_enuWritePin(DIO_PIN_NUM_4, DIO_LOW);
		DIO_enuWritePin(DIO_PIN_NUM_5, DIO_LOW);

		DIO_enuWritePin(DIO_PIN_NUM_3, DIO_HIGH);
		DIO_enuWritePin(DIO_PIN_NUM_6, DIO_HIGH);
		Delay_ms(75);

		DIO_enuWritePin(DIO_PIN_NUM_3, DIO_LOW);
		DIO_enuWritePin(DIO_PIN_NUM_6, DIO_LOW);


		DIO_enuWritePin(DIO_PIN_NUM_2, DIO_HIGH);
		DIO_enuWritePin(DIO_PIN_NUM_7, DIO_HIGH);
		Delay_ms(75);

		DIO_enuWritePin(DIO_PIN_NUM_2, DIO_LOW);
		DIO_enuWritePin(DIO_PIN_NUM_7, DIO_LOW);


		DIO_enuWritePin(DIO_PIN_NUM_1, DIO_HIGH);
		DIO_enuWritePin(DIO_PIN_NUM_8, DIO_HIGH);
		Delay_ms(75);
		DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
		DIO_enuWritePin(DIO_PIN_NUM_8, DIO_LOW);

		DIO_enuWritePin(DIO_PIN_NUM_0, DIO_HIGH);
		DIO_enuWritePin(DIO_PIN_NUM_9, DIO_HIGH);
		Delay_ms(75);
		DIO_enuWritePin(DIO_PIN_NUM_0, DIO_LOW);
		DIO_enuWritePin(DIO_PIN_NUM_9, DIO_LOW);
	 }
	return 0;
}

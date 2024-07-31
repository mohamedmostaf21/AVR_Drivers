
#include "../MCAL/DIO/DIO.h"
#include "../HAL/SEVEN_SEGMENT/SEV.h"
#include "../LIBS/delay.h"
void RunCountdown() {
    Sev_Display(1, 3);
    Sev_Display(0, 0);
   Delay_ms(50);
    for (int i = 2; i >= 0; i--) {
        Sev_Display(1, i);
        for (int j = 9; j >= 0; j--){
        	 Sev_Display(0, j);
        	 Delay_ms(50);
        }
    }
}

int main(){
	 DIO_voidInit();
	 DIO_enuWritePin(DIO_PIN_NUM_0, DIO_LOW);
	 DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
	 DIO_enuWritePin(DIO_PIN_NUM_2, DIO_LOW);

	 //segment 1
	 Sev_PowerOn(0);
	//segment 2
	 Sev_PowerOn(1);


	while (1) {
		DIO_enuWritePin(DIO_PIN_NUM_2, DIO_HIGH);
		RunCountdown(); // Segment 1 active
		DIO_enuWritePin(DIO_PIN_NUM_2, DIO_LOW);
		DIO_enuWritePin(DIO_PIN_NUM_1, DIO_HIGH);
		RunCountdown(); // Segment 2 active
		DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
		DIO_enuWritePin(DIO_PIN_NUM_0, DIO_HIGH);
		RunCountdown(); // Segment 3 active
		DIO_enuWritePin(DIO_PIN_NUM_0, DIO_LOW);

	}
	return 0;
}


#include "../MCAL/DIO/DIO.h"
#include "../HAL/SEVEN_SEGMENT/SEV.h"
#include "../LIBS/delay.h"
int main(){
	 DIO_voidInit();
	 //segment 1
	 Sev_PowerOn(0);
	//segment 2
	 Sev_PowerOn(1);
	 while(1){
		Sev_Display(0, 0);
		Sev_Display(1, 0);
		Delay_ms(75);
		Sev_Display(0, 1);
		Sev_Display(1, 1);
		Delay_ms(75);
		Sev_Display(0, 2);
		Sev_Display(1, 2);
		Delay_ms(75);
		Sev_Display(0, 3);
		Sev_Display(1, 3);
		Delay_ms(75);
		Sev_Display(0, 4);
		Sev_Display(1, 4);
		Delay_ms(75);
		Sev_Display(0, 5);
		Sev_Display(1, 5);
		Delay_ms(75);
		Sev_Display(0, 6);
		Sev_Display(1, 6);
		Delay_ms(75);
		Sev_Display(0, 7);
		Sev_Display(1, 7);
		Delay_ms(75);
		Sev_Display(0, 8);
		Sev_Display(1, 8);
		Delay_ms(75);
		Sev_Display(0, 9);
		Sev_Display(1, 9);
		Delay_ms(75);
	 }
	return 0;
}

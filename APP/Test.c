//
//#include "../MCAL/DIO/DIO.h"
//#include "../HAL/SEVEN_SEGMENT/SEV.h"
//#include "../LIBS/delay.h"
//#include "../HAL/LCD_DRIVER/LCD_interface.h"
//void RunCountdown(){
//    Sev_Display(1, 3);
//    Sev_Display(0, 0);
//    Delay_ms(1000);
//    for (int i = 2; i >= 0; i--) {
//        Sev_Display(1, i);
//        for (int j = 9; j >= 0; j--){
//        	 Sev_Display(0, j);
//        	 Delay_ms(1000);
//        }
//    }
//}
//
//int main(){
//	 DIO_voidInit();
//	 DIO_enuWritePin(DIO_PIN_NUM_0, DIO_LOW);
//	 DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
//	 DIO_enuWritePin(DIO_PIN_NUM_2, DIO_LOW);
//	 DIO_enuWritePin(DIO_PIN_NUM_6, DIO_LOW);
//	 //segment 1
//	 Sev_PowerOn(0);
//	//segment 2
//	 Sev_PowerOn(1);
//
//	 LCD_vidInit();
//	 LCD_vidSendCommand(lcd_DisplayOn);
//	 LCD_vidSendCommand(lcd_EntryMode);
//	 LCD_vidSendCommand(lcd_FunctionSet8bit);
//	 LCD_vidSendCommand(lcd_SetCursor);
//	while (1) {
//		LCD_vidWriteString("Stop", 4);
//		DIO_enuWritePin(DIO_PIN_NUM_2, DIO_HIGH);
//		RunCountdown(); // Segment 1 active
//		LCD_vidSendCommand(lcd_SetCursor);
//		LCD_vidWriteString("Ready", 5);
//		DIO_enuWritePin(DIO_PIN_NUM_2, DIO_LOW);
//		DIO_enuWritePin(DIO_PIN_NUM_1, DIO_HIGH);
//		RunCountdown(); // Segment 2 active
//		 LCD_vidSendCommand(lcd_SetCursor);
//		LCD_vidWriteString("Go   ", 5);
//		DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
//		DIO_enuWritePin(DIO_PIN_NUM_0, DIO_HIGH);
//		DIO_enuWritePin(DIO_PIN_NUM_6, DIO_HIGH);
//		RunCountdown(); // Segment 3 active
//		DIO_enuWritePin(DIO_PIN_NUM_6, DIO_LOW);
//		DIO_enuWritePin(DIO_PIN_NUM_0, DIO_LOW);
//		LCD_vidSendCommand(lcd_SetCursor);
//	}
//	return 0;
//}

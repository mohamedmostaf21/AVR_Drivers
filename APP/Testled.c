///*
// * Testled.c
// *
// *  Created on: Aug 5, 2024
// *      Author: k.m
// */
//
//#include "../MCAL/DIO/DIO.h"
//#include "../LIBS/BIT_MATH.h"
//#include "../MCAL/DIO/DIO_priv.h"
//#include "../LIBS/delay.h"
//#include "../MCAL/GIE/GIE_prog.h"
//#include "../MCAL/EXTI/EXTI.h"
//#include "../MCAL/EXTI/EXTI_priv.h"
//void LED_ON();
//void LED_OFF();
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
//	DIO_voidInit();
//	DIO_enuWritePin(DIO_PIN_NUM_0, DIO_LOW);
//	 DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
//	 DIO_enuWritePin(DIO_PIN_NUM_2, DIO_LOW);
//	 DIO_enuWritePin(DIO_PIN_NUM_25, DIO_LOW);
//	EXTI_InitMode(EXTI_RAIS_EDGE, EXTI_INT0);
//	EXTI_InitMode(EXTI_RAIS_EDGE, EXTI_INT1);
//	EXTI_Enable(EXTI_INT0);
//	EXTI_Enable(EXTI_INT1);
//	DIO_enuStatePullup(EXTI_INT0_PIN, DIO_HIGH);
//	DIO_enuStatePullup(EXTI_INT1_PIN, DIO_HIGH);
//	EXTI_FnCallBack_INT0(LED_ON);
//	EXTI_FnCallBack_INT1(LED_OFF);
//	GIE_Enable();
//
//	//EXTI_FnCallBack_INT0(LED_OFF);
//	while(1){
//
//			//DIO_enuWritePin(DIO_PIN_NUM_2, DIO_HIGH);
//			RunCountdown(); // Segment 1 active
//
//			//DIO_enuWritePin(DIO_PIN_NUM_2, DIO_LOW);
//			//DIO_enuWritePin(DIO_PIN_NUM_1, DIO_HIGH);
//			//RunCountdown(); // Segment 2 active
//
//			//DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
//			//DIO_enuWritePin(DIO_PIN_NUM_0, DIO_HIGH);
//
//			//RunCountdown(); // Segment 3 active
//
//			//DIO_enuWritePin(DIO_PIN_NUM_0, DIO_LOW);
//
//	}
//
//
//	return 0;
//}
//void LED_ON(){
//	u8 out;
//	DIO_enuReadPin(EXTI_INT0_PIN, &out);
//	if(out == DIO_LOW){
//		DIO_enuWritePin(DIO_PIN_NUM_0, DIO_HIGH);
//		DIO_enuWritePin(DIO_PIN_NUM_1, DIO_HIGH);
//		DIO_enuWritePin(DIO_PIN_NUM_2, DIO_HIGH);
//
//	}
//
//
//
//}
//void LED_OFF(){
//	u8 out;
//	DIO_enuReadPin(EXTI_INT1_PIN, &out);
//	if(out == DIO_LOW){
//		DIO_enuWritePin(DIO_PIN_NUM_0, DIO_LOW);
//		DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
//		DIO_enuWritePin(DIO_PIN_NUM_2, DIO_LOW);
//
//	}
//
//
//
//}
//

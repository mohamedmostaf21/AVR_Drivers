/*
 * TIMER_prog.c
 *
 *  Created on: Aug 14, 2024
 *      Author: k.m
 */



/******************  ******************/

#include "TIMER_prog.h"
#include "../UART/UART_prog.h"
#include "../DIO/DIO.h"
extern TMR_cfg_t TIMER2;
u8 timer2_flag = 0;

void TMR_vInit(const TMR_cfg_t *TMR){
	if(TMR != NULL){
		switch(TMR->TMR_TimerChannel){
		case TIMER0_NORMAL:
			TCCR0_REG = (TCCR0_REG&0xB7);
			if(TMR->TMR_ToggleMode == TMR_InterruptMode){
				TIMSK_REG = (TIMSK_REG&0xFC) | 0x01;
			}
			else if(TMR->TMR_ToggleMode == TMR_OCMode){
				if(TMR->TMR_OCMode == OC_Disconnected){
					TCCR0_REG = (TCCR0_REG & 0xCF);
				}
				else if(TMR->TMR_OCMode == OC_Toggle){
					TCCR0_REG = (TCCR0_REG & 0xCF) | 0x10;
				}
				else if(TMR->TMR_OCMode == OC_Clear){
					TCCR0_REG = (TCCR0_REG & 0xCF) | 0x20;
				}
				else if(TMR->TMR_OCMode == OC_Set){
					TCCR0_REG = (TCCR0_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER0_CTC:
			TCCR0_REG = (TCCR0_REG&0xB7) | 0x8;
			if(TMR->TMR_ToggleMode == TMR_InterruptMode){
				TIMSK_REG = (TIMSK_REG&0xFC) | 0x02;
			}
			else if(TMR->TMR_ToggleMode == TMR_OCMode){
				if(TMR->TMR_OCMode == OC_Disconnected){
					TCCR0_REG = (TCCR0_REG & 0xCF);
				}
				else if(TMR->TMR_OCMode == OC_Toggle){
					TCCR0_REG = (TCCR0_REG & 0xCF) | 0x10;
				}
				else if(TMR->TMR_OCMode == OC_Clear){
					TCCR0_REG = (TCCR0_REG & 0xCF) | 0x20;
				}
				else if(TMR->TMR_OCMode == OC_Set){
					TCCR0_REG = (TCCR0_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_NORMAL:
			TCCR1A_REG = (TCCR1A_REG & 0xFC);
			TCCR1B_REG = (TCCR1B_REG & 0xE7);
			if(TMR->TMR_ToggleMode == TMR_InterruptMode){
				TIMSK_REG = (TIMSK_REG&0xC3) | 0x04;
			}
			else if(TMR->TMR_ToggleMode == TMR_OCMode){
				if(TMR->TMR_OCMode == OC_Disconnected){
					TCCR1A_REG = (TCCR1A_REG & 0xCF);
				}
				else if(TMR->TMR_OCMode == OC_Toggle){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x10;
				}
				else if(TMR->TMR_OCMode == OC_Clear){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(TMR->TMR_OCMode == OC_Set){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_CTC_OCR:
			TCCR1A_REG = (TCCR1A_REG & 0xFC);
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x08;
			if(TMR->TMR_ToggleMode == TMR_InterruptMode){
				TIMSK_REG = (TIMSK_REG&0xC3) | 0x18;
			}
			else if(TMR->TMR_ToggleMode == TMR_OCMode){
				if(TMR->TMR_OCMode == OC_Disconnected){
					TCCR1A_REG = (TCCR1A_REG & 0xCF);
				}
				else if(TMR->TMR_OCMode == OC_Toggle){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x10;
				}
				else if(TMR->TMR_OCMode == OC_Clear){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(TMR->TMR_OCMode == OC_Set){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_CTC_ICR:
			TCCR1A_REG = (TCCR1A_REG & 0xFC);
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x18;
			if(TMR->TMR_ToggleMode == TMR_InterruptMode){
				TIMSK_REG = (TIMSK_REG&0xC3) | 0x18;
			}
			else if(TMR->TMR_ToggleMode == TMR_OCMode){
				if(TMR->TMR_OCMode == OC_Disconnected){
					TCCR1A_REG = (TCCR1A_REG & 0xCF);
				}
				else if(TMR->TMR_OCMode == OC_Toggle){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x10;
				}
				else if(TMR->TMR_OCMode == OC_Clear){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(TMR->TMR_OCMode == OC_Set){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER2_NORMAL:
			TCCR2_REG = (TCCR2_REG&0xB7);
			if(TMR->TMR_ToggleMode == TMR_InterruptMode){
				TIMSK_REG = (TIMSK_REG&0x3F) | 0x40;
			}
			else if(TMR->TMR_ToggleMode == TMR_OCMode){
				if(TMR->TMR_OCMode == OC_Disconnected){
					TCCR2_REG = (TCCR2_REG & 0xCF);
				}
				else if(TMR->TMR_OCMode == OC_Toggle){
					TCCR2_REG = (TCCR2_REG & 0xCF) | 0x10;
				}
				else if(TMR->TMR_OCMode == OC_Clear){
					TCCR2_REG = (TCCR2_REG & 0xCF) | 0x20;
				}
				else if(TMR->TMR_OCMode == OC_Set){
					TCCR2_REG = (TCCR2_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER2_CTC:
			TCCR2_REG = (TCCR2_REG&0xB7);
			if(TMR->TMR_ToggleMode == TMR_InterruptMode){
				TIMSK_REG = (TIMSK_REG&0x3F) | 0x80;
			}
			else if(TMR->TMR_ToggleMode == TMR_OCMode){
				if(TMR->TMR_OCMode == OC_Disconnected){
					TCCR2_REG = (TCCR2_REG & 0xCF);
				}
				else if(TMR->TMR_OCMode == OC_Toggle){
					TCCR2_REG = (TCCR2_REG & 0xCF) | 0x10;
				}
				else if(TMR->TMR_OCMode == OC_Clear){
					TCCR2_REG = (TCCR2_REG & 0xCF) | 0x20;
				}
				else if(TMR->TMR_OCMode == OC_Set){
					TCCR2_REG = (TCCR2_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		default: /* Do Nothing */ break;
		}
	}
}

void TMR_vStartTimer(const TMR_cfg_t *TMR){
	if(TMR != NULL){
		switch(TMR->TMR_TimerChannel){
		case TIMER0_NORMAL:
		case TIMER0_CTC:
			switch(TMR->TMR_Prescale){
			case TMR_PRE_NO_CLK:
				TCCR0_REG = (TCCR0_REG&0xF8);
				break;
			case TMR_PRE_0:
				TCCR0_REG = (TCCR0_REG&0xF8) | 1;
				break;
			case TMR_PRE_8:
				TCCR0_REG = (TCCR0_REG&0xF8) | 2;
				break;
			case TMR_PRE_64:
				TCCR0_REG = (TCCR0_REG&0xF8) | 3;
				break;
			case TMR_PRE_256:
				TCCR0_REG = (TCCR0_REG&0xF8) | 4;
				break;
			case TMR_PRE_1024:
				TCCR0_REG = (TCCR0_REG&0xF8) | 5;
				break;
			case TMR_PRE_EXT_FALLING:
				TCCR0_REG = (TCCR0_REG&0xF8) | 6;
				break;
			case TMR_PRE_EXT_RISING:
				TCCR0_REG = (TCCR0_REG&0xF8) | 7;
				break;
			default: /* Do Nothing */ break;
			}
			break;
		case TIMER1_NORMAL:
		case TIMER1_CTC_OCR:
		case TIMER1_CTC_ICR:
			switch(TMR->TMR_Prescale){
			case TMR_PRE_NO_CLK:
				TCCR1B_REG = (TCCR1B_REG&0xF8);
				break;
			case TMR_PRE_0:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 1;
				break;
			case TMR_PRE_8:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 2;
				break;
			case TMR_PRE_64:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 3;
				break;
			case TMR_PRE_256:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 4;
				break;
			case TMR_PRE_1024:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 5;
				break;
			case TMR_PRE_EXT_FALLING:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 6;
				break;
			case TMR_PRE_EXT_RISING:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 7;
				break;
			default: /* Do Nothing */ break;
			}
			break;
		case TIMER2_NORMAL:
		case TIMER2_CTC:
			switch(TMR->TMR_Prescale){
			case TMR_PRE_NO_CLK:
				TCCR2_REG = (TCCR2_REG&0xF8);
				break;
			case TMR_PRE_0:
				TCCR2_REG = (TCCR2_REG&0xF8) | 1;
				break;
			case TMR_PRE_8:
				TCCR2_REG = (TCCR2_REG&0xF8) | 2;
				break;
			case TMR_PRE_32:
				TCCR2_REG = (TCCR2_REG&0xF8) | 3;
				break;
			case TMR_PRE_64:
				TCCR2_REG = (TCCR2_REG&0xF8) | 4;
				break;
			case TMR_PRE_128:
				TCCR2_REG = (TCCR2_REG&0xF8) | 5;
				break;
			case TMR_PRE_256:
				TCCR2_REG = (TCCR2_REG&0xF8) | 6;
				break;
			case TMR_PRE_1024:
				TCCR2_REG = (TCCR2_REG&0xF8) | 7;
				break;
			default: /* Do Nothing */ break;
			}
			break;
		default: /* Do Nothing */ break;
		}
	}
}

void TMR_vStop(const TMR_cfg_t *TMR){
	if(TMR != NULL){
		switch(TMR->TMR_TimerChannel){
		case TIMER0_NORMAL:
		case TIMER0_CTC:
			TCCR0_REG &= 0xF8;
			break;
		case TIMER1_NORMAL:
		case TIMER1_CTC_OCR:
		case TIMER1_CTC_ICR:
			TCCR1B_REG &= 0xF8;
			break;
		case TIMER2_NORMAL:
		case TIMER2_CTC:
			TCCR2_REG &= 0xF8;
			break;
		default: /* Do Nothing */ break;
		}
	}
}

void TMR_vSetICRValue(const TMR_cfg_t *TMR, u16 Copy_u16ICRValue){
	if(TMR != NULL){
		switch(TMR->TMR_TimerChannel){

		case TIMER1_NORMAL:
		case TIMER1_CTC_OCR:
		case TIMER1_CTC_ICR:
			ICR1_REG = Copy_u16ICRValue;
			break;
		default: /* Do Nothing */ break;
		}
	}
}

void TMR_vSetOCRValue(const TMR_cfg_t *TMR, u16 Copy_u16OCRValue){
	if(TMR != NULL){
		switch(TMR->TMR_TimerChannel){
		case TIMER0_NORMAL:
		case TIMER0_CTC:
			OCR0_REG = (u8)Copy_u16OCRValue;
			break;
		case TIMER1_NORMAL:
		case TIMER1_CTC_OCR:
		case TIMER1_CTC_ICR:
			OCR1A_REG = Copy_u16OCRValue;
			break;
		case TIMER2_NORMAL:
		case TIMER2_CTC:
			OCR2_REG = (u8)Copy_u16OCRValue;
			break;
		default: /* Do Nothing */ break;
		}
	}
}


void __vector_5(void) __attribute__((signal));
void __vector_5(void){
	static u8 timer2_inner_counter = 0;
	static u8 timer2_seconds = 10;
	u8 preload_value = 124;
	u8 overflow_max = 31;
	timer2_inner_counter++;
	if(timer2_inner_counter == overflow_max){
		UART_vSendData(timer2_seconds+47);
		UART_vSendString((u8*)" seconds remaining!\r\n");
		timer2_inner_counter = 0;
		TCNT2_REG = preload_value;
		timer2_seconds--;
	}
	if(timer2_seconds == 0){
		UART_vSendString((u8*)"\r\n\r\n");
		timer2_seconds = 10;
		TMR_vStop(&TIMER2);
		timer2_flag = FLAG_ON;
		DIO_enuWritePin(DIO_PIN_NUM_0, DIO_LOW);
	}
}

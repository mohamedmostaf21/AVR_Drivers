/*
 * ADC_prog.h
 *
 *  Created on: Aug 8, 2024
 *      Author: k.m
 */

#ifndef MCAL_ADC_ADC_PROG_H_
#define MCAL_ADC_ADC_PROG_H_
/*Channels*/
#define ADC_CHANNEL_0   	0
#define ADC_CHANNEL_1   	1
#define ADC_CHANNEL_2   	2
#define ADC_CHANNEL_3   	3
#define ADC_CHANNEL_4   	4
#define ADC_CHANNEL_5   	5
#define ADC_CHANNEL_6   	6
#define ADC_CHANNEL_7   	7
#define ADC_CH0_CH0_G10 	8
#define ADC_CH1_CH0_G10 	9
void ADC_voidInit(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);
void ADC_voidEnableInterrupt(void);
void ADC_voidDisableInterrupt(void);
void ADC_voidSetCallback(pf pfCallbackCpy);
void ADC_voidStartConversion(u8 u8ChannelNbCpy);
void ADC_voidChangeMode(u8 u8ModeCpy);

u16 ADC_u16ReadSync(u8 u8ChannelNbCpy);
u16 ADC_u16ReadAsync(void);
void __vector_16 (void) __attribute__((signal ,used));

#endif /* MCAL_ADC_ADC_PROG_H_ */

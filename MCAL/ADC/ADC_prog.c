/*
 * ADC_prog.c
 *
 *  Created on: Aug 8, 2024
 *      Author: k.m
 */
#include "../../LIBS/BIT_MATH.h"
#include "../../LIBS/STD_TYPES.h"
#include "../EXTI/EXTI.h"
#include "ADC_prog.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"
pf ADC_pfCall = NULL_PTR;
u16 ADC_u16ReadValue ;

void ADC_voidInit(void){

	#if ADC_RESOLUTION_MODE == ADC_bit_Mode_8
	//Write one to ADLAR to left adjust the result
		SET_BIT(ADCMUX, ADC_ADLAR_BIT);
	#else
		CLR_BIT(ADCMUX, ADC_ADLAR_BIT);
	#endif

	#if ADC_VOLTAGE_REF == ADC_AREF
		CLR_BIT(ADCMUX, ADC_REFS0_BIT);
		CLR_BIT(ADCMUX, ADC_REFS1_BIT);
	#elif ADC_VOLTAGE_REF == ADC_AVCC
		SET_BIT(ADCMUX, ADC_REFS0_BIT);
		CLR_BIT(ADCMUX, ADC_REFS1_BIT);
	#else
		SET_BIT(ADCMUX, ADC_REFS0_BIT);
		SET_BIT(ADCMUX, ADC_REFS1_BIT);
	#endif

	ADCSRA &= 0b11111000;
	SET_BIT(ADCSRA, ADC_PRESCALAR);

	#if ADC_TRIGGER_MODE == ADC_SINGLE_MODE
		CLR_BIT(ADCSRA, ADC_ADATE_BIT);
	#else
		SET_BIT(ADCSRA , ADC_ADATE_BIT) ;
		SFIOR &= 0b00011111;
		SFIOR |= ADC_TRIGGER_MODE << 5;
	#endif
}

void ADC_voidEnable(void)
{
	SET_BIT(ADCSRA , ADC_ADEN_BIT);
}

void ADC_voidDisable(void)
{
	CLR_BIT(ADCSRA , ADC_ADEN_BIT);
}

void ADC_voidEnableInterrupt(void)
{
	SET_BIT(ADCSRA , ADC_ADIE_BIT);
}
void ADC_voidDisableInterrupt(void)
{
	CLR_BIT(ADCSRA , ADC_ADIE_BIT);
}

void ADC_voidSetCallback(pf pfCallbackCpy)
{
	ADC_pfCall = pfCallbackCpy ;
}

void ADC_voidStartConversion(u8 u8ChannelNbCpy)
{
	ADCMUX &= 0b11100000;
	ADCMUX |= u8ChannelNbCpy ;
	//start conversion
	SET_BIT(ADCSRA , ADC_ADSC_BIT) ;
}

void ADC_voidChangeMode(u8 u8ModeCpy)
{
	if (u8ModeCpy < ADC_SINGLE_MODE)
	{
		SET_BIT(ADCSRA , ADC_ADATE_BIT) ;
		SFIOR &=0b00011111;
		SFIOR |= u8ModeCpy << 5;
	}
	else if (u8ModeCpy == ADC_SINGLE_MODE)
	{
		CLR_BIT(ADCSRA , ADC_ADATE_BIT) ;
	}
	else
	{

	}
}

/* polling */
u16 ADC_u16ReadSync(u8 u8ChannelNbCpy)
{
	u16 u16ReadValueLoc;

	ADC_voidStartConversion(u8ChannelNbCpy);

	/*wait conversion till finish*/
	while ((GET_BIT(ADCSRA , ADC_ADIF_BIT)) == 0);
	/*Clear Flag bit*/
	SET_BIT(ADCSRA , ADC_ADIF_BIT);

	#if ADC_RESOLUTION_MODE == ADC_bit_Mode_8
		u16ReadValueLoc = ADCH ;
	#else
		u16ReadValueLoc = ADCL;
		u16ReadValueLoc |= (ADCH<<8) ;
	#endif

	return u16ReadValueLoc ;

}

u16 ADC_u16ReadAsync(void)
{
	return ADC_u16ReadValue;
}

/*Interrupt*/
void __vector_16(void)
{
	if (ADC_pfCall != NULL_PTR)
	{
		ADC_pfCall();
	}
	#if ADC_RESOLUTION_MODE == ADC_bit_Mode_8
		ADC_u16ReadValue = ADCH ;
	#else
		ADC_u16ReadValue = ADCL;
		ADC_u16ReadValue |= (ADCH<<8) ;
	#endif


}

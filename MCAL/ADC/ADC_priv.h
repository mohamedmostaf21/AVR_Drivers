/*
 * ADC_priv.h
 *
 *  Created on: Aug 8, 2024
 *      Author: k.m
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

#define SFIOR	      (*(volatile u8 *)(0x50))
#define ADCMUX         (*(volatile u8 *)(0x27))
#define ADCSRA        (*(volatile u8 *)(0x26))
#define ADCH          (*(volatile u8 *)(0x25))
#define ADCL          (*(volatile u8 *)(0x24))

/*Choose Resolution Mode*/
#define ADC_bit_Mode_8		0
#define ADC_bit_Mode_10 	1

/*ADC Trigger Sources */
#define ADC_FREE_RUNNING           0
#define ADC_ANALOG_COMPARATOR      1
#define ADC_EXTERNAL_INT0	       2
#define ADC_TIMER0_COMPARE_MATCH   3
#define ADC_TIMER0_OVER_FLOW       4
#define ADC_TIMERB_COMPARE_MATCH   5
#define ADC_TIMER1_OVER_FLOW       6
#define ADC_TIMER1_CAPTURE_EVENT   7
#define ADC_SINGLE_MODE			   8

/*SFIOR Reg*/
#define ADC_ADTS0_BIT		5
#define ADC_ADTS1_BIT		6
#define ADC_ADTS2_BIT		7


/*ADC Input CLK Pre_scaler*/
#define ADC_PRESCALER_2							1
#define ADC_PRESCALER_4							2
#define ADC_PRESCALER_8							3
#define ADC_PRESCALER_16						4
#define ADC_PRESCALER_32						5
#define ADC_PRESCALER_64						6
#define ADC_PRESCALER_128						7


/*ADMUX Reg*/
#define ADC_MUX0_BIT      	0
#define ADC_MUX1_BIT       	1
#define ADC_MUX2_BIT		2
#define ADC_MUX3_BIT		3
#define ADC_MUX4_BIT		4
#define ADC_ADLAR_BIT		5
#define ADC_REFS0_BIT		6
#define ADC_REFS1_BIT		7



/*ADCSRA Reg*/
#define ADC_ADPS0_BIT       0
#define ADC_ADPS1_BIT       1
#define ADC_ADPS2_BIT		2
#define ADC_ADIE_BIT		3
#define ADC_ADIF_BIT		4
#define ADC_ADATE_BIT		5
#define ADC_ADSC_BIT		6
#define ADC_ADEN_BIT		7



/*Reference Selection Bits*/
#define ADC_AREF			0
#define ADC_AVCC			1
#define ADC_INTERNAL_VREF	3


#endif /* MCAL_ADC_ADC_PRIV_H_ */

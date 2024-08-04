/*
 * STPR.h
 *
 *  Created on: Aug 3, 2024
 *      Author: Mohamed
 */

#ifndef HAL_STEPPER_STPR_H_
#define HAL_STEPPER_STPR_H_


void STPR_FullStep_Right(u8 speed);
void STPR_FullStep_Left(u32 speed);
void STPR_HalfStep_Right(u8 speed);
void STPR_HalfStep_Left(u8 speed);
void STPR_Stop(void);



#endif /* HAL_STEPPER_STPR_H_ */

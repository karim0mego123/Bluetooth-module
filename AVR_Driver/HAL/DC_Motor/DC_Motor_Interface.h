/*
 * DC_Motor.h
 *
 * Created: 7/16/2023 10:59:36 PM
 *  Author: karim
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "DC_Motor_Priv.h"
#include "DC_Motor_CFG.h"
#include "Timer1_Interface.h"

void DC_MotorInit() ;
void DC_MotorMoveRight(uint8_t Motor_Number) ;
void DC_MotorMoveLeft(uint8_t Motor_Number) ;
void DC_MotorSetSpeed(uint16_t Freq , uint8_t Duty ) ;
void DC_MotorStop(uint8_t Motor_Number) ;


#endif /* DC_MOTOR_H_ */

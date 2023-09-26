/*
 * PIR_Sensor_interface.h
 *
 *  Created on: Sep 23, 2023
 *      Author: karim
 */

#ifndef HAL_PIR_SENSOR_PIR_SENSOR_INTERFACE_H_
#define HAL_PIR_SENSOR_PIR_SENSOR_INTERFACE_H_


void PIR_voidInit() ;

void PIR_Set_CallBack(void(*PtrFun)(void),void(*PtrNFun)(void)) ;

#endif /* HAL_PIR_SENSOR_PIR_SENSOR_INTERFACE_H_ */

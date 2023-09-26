/*
 * PIR_Sensor_Prog.c
 *
 *  Created on: Sep 23, 2023
 *      Author: karim
 */

#include "PIR_Sensor_Config.h"
#include "PIR_Sensor_interface.h"


void PIR_voidInit()
{
	DIO_Write_Pin_Dir(PIR_OUT_PORT,PIR_OUT_PIN,LOW) ;
}

void PIR_Set_CallBack(void(*PtrFun)(void),void(*PtrNFun)(void))
{
	uint8_t Val = 0 ;
	DIO_Read(PIR_OUT_PORT,PIR_OUT_PIN,&Val) ;
	if(Val==1)
	{
		PtrFun() ;
		while((PINB&PIR_OUT_PIN)==1) ;
	}
	else
	{
		PtrNFun() ;
	}
}

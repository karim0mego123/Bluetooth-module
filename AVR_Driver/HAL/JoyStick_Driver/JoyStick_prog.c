/*
 * JoyStick_prog.c
 *
 *  Created on: Sep 23, 2023
 *      Author: karim
 */


#include "JoyStick_Interface.h"
#include "ADC_INT.h"

void JoyStick_voidInit()
{
	ADC_INIT() ;
	ADC_Select_Channel(CHANNEL_0);
	ADC_Enable_Triggring_Mode(FREE_RUNNIG);

	DIO_Write_Pin_Dir(VRX_PORT,VRX_PIN,LOW) ;
	DIO_Write_Pin_Dir(SW_PORT,SW_PIN,LOW) ;
}

void JoyStick_voidStart(uint16_t Data)
{
	ADC_Start() ;
	ADC_PollingSystem() ;
	ADC_Read(&Data) ;
}

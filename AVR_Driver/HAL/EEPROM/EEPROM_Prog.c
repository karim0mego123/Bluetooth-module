/*
 * EEPROM_Prog.c
 *
 * Created: 8/30/2023 12:36:39 PM
 *  Author: karim
 */ 
#include "EEPROM_Int.h"
#include "EEPROM_Priv.h"
#include "EEPROM_Config.h"
#include "IIC_Int.h"
#include "avr/delay.h"


ES_t EEPROM_INTT(uint8_t Address) 
{
	ES_t Loc_ErrorState = NO_Error ; 

	IIC_MasterInit();
	
	if (IIC_SlaveInit(Address)!=NO_Error)
	{
	}
	
	return Loc_ErrorState ; 
	
}

ES_t EEPROM_WriteData(uint16_t Address , uint8_t Data ) 
{
	ES_t Loc_ErrorState = NO_Error ;
	
	#if EEPROM_TYPE == EIGHT_KBIT
	
	uint8_t Loc_Address = ((0xA0 | (EEPROM_A2_State<<3) | (((Address>>8)&3)<<1))>>1) ;
	uint8_t Loc_ByteAddress = (uint8_t)Address ; 
#endif
	
	if (IIC_StartCondition()==NOError)
	{
		if (IIC_SendSlaveAdress(Loc_Address,0) == NOError)
		{
			if (IIC_MasterSendData_ACK(Loc_ByteAddress)==NOError)
			{				
				if (IIC_MasterSendData_ACK(Data)==NOError)
				{
					IIC_StopCondition();
				}
			}

		}
	}
	
	return Loc_ErrorState ;
}


ES_t EEPROM_ReadData(uint16_t Address , uint8_t* Data ) 
{
	ES_t Loc_ErrorState = NO_Error ;
	
	#if EEPROM_TYPE == EIGHT_KBIT
	 
	uint8_t Loc_Address = ((0xA0 | (EEPROM_A2_State<<3) | (((Address>>8)&3)<<1))>>1) ;
	uint8_t Loc_ByteAddress = (uint8_t)Address ;
	
	#endif


	if (IIC_StartCondition()==NOError)
	{
		if (IIC_SendSlaveAdress(Loc_Address,0)==NOError)
		{
			if (IIC_MasterSendData_ACK(Loc_ByteAddress)==NOError)
			{
				if (IIC_RepeatedStartCondition()==NOError)
				{
					if (IIC_SendSlaveAdress(Loc_Address,1)==NOError)
					{
						if (IIC_Master_ReadData_NACK(Data)==NOError)
						{
							IIC_StopCondition();
						}
					}
				}
			}
		}
	}
	

	return Loc_ErrorState ;
}

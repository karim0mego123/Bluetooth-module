#include "IIC_Int.h"


ES_t IIC_MasterInit(void)
{
	ES_t Loc_ErrorState = Error ; 
	
	SET_TWBR_VALUE ;

    // Clear prescaler bits (TWSR) for TWI
    TWSR = 0;
	
	#if I2C_PRESCALER == PRES_1
	SET_I2C_PRESCALER_1;
	Loc_ErrorState = NO_Error;

	#elif I2C_PRESCALER == PRES_4
	SET_I2C_PRESCALER_4;
	Loc_ErrorState = NO_Error;

	#elif I2C_PRESCALER == PRES_16
	SET_I2C_PRESCALER_16;
	Loc_ErrorState = NO_Error;

	#elif I2C_PRESCALER == PRES_64
	SET_I2C_PRESCALER_64;
	Loc_ErrorState = NO_Error;

	#endif
	
	SET_I2C_ENABLE;

	return Loc_ErrorState ; 	
}

ES_t IIC_SlaveInit(uint8_t SlaveAddress)
{
	ES_t Loc_ErrorState = NO_Error ;
		
	SET_ECU_ADDRESS(SlaveAddress) ;
	
    TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);/* Enable TWI, Enable ack generation */ 
	
	return Loc_ErrorState ;

}
Error_TX_RX_e IIC_SlaveCheckAdress (void)
{
	Error_TX_RX_e Loc_ErrorState = NOError ; 
	
	while(1)
	{
		while(WAIT_FLAG) ;
		
		if (SLAVE_WRITE_RECIEVED) /* Own SLA+W received &ack returned */
		{
			break;
		}
		if (SLAVE_RAED_RECIEVED) /* Own SLA+R received &ack returned */
		{
			break;
		}
		if (SLAVE_GENERALCALL_RECIEVED_ACK) /* General call received &ack returned */
		{
			break;
		}
	}
	return Loc_ErrorState ; 
}

Error_TX_RX_e IIC_StartCondition(void)
{
	Error_TX_RX_e Loc_ErrorState = NOError ;

    TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT); /* Enable TWI, generate START */
	
	while (WAIT_FLAG);

	if (!START_CONDITION_TRANSMIT)
	{
		Loc_ErrorState =  START_CONDITION_TRANSMIT_Error ;
	}

	return Loc_ErrorState ;
	
}

Error_TX_RX_e IIC_RepeatedStartCondition(void)
{
	Error_TX_RX_e Loc_ErrorState = NOError ; 
			
	    TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);/* Enable TWI, generate start */

		while (WAIT_FLAG); 		// Wait for start condition to be transmitted
		
		if (REPEAT_START_CONDITION_TRANSMIT) /* Check for repeated start transmitted */
		{
			; 	
		}
		return Loc_ErrorState ; 
}
Error_TX_RX_e IIC_SendSlaveAdress(uint8_t LOC_uint8_tSlaveAdress , uint8_t operation)
{
	Error_TX_RX_e Loc_ErrorState = NOError ;
	
    TWDR = (LOC_uint8_tSlaveAdress << 1) | (operation & 0x01);

    TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI & clear interrupt flag */

	while (WAIT_FLAG); 	 // Wait until the transmission is complete
	
	if (SLA_WRITE_RECIEVED_ACK) /* Check for SLA+W transmitted &ack received */
	{
			;
	}
	if (SLA_WRITE_RECIEVED_NACK) /* Check for SLA+W transmitted &nack received */
	{
		;		
	}
	
	return Loc_ErrorState ;
}

Error_TX_RX_e IIC_MasterSendData_ACK(uint8_t LOC_uint8_tData)
{
	Error_TX_RX_e 	Loc_ErrorState = MASTER_DATA_TRANSMIT_Error ;
	
	SEND_DATA_REGISTER(LOC_uint8_tData);
		
    TWCR = (1<<TWEN) | (1<<TWINT);	    /* Enable TWI and clear interrupt flag */
	
	while (WAIT_FLAG);
	
	if (MASTER_DATA_TRANSMIT_ACK) /* Check for data transmitted &ack received */
	{
		Loc_ErrorState = NOError ;
	}
	
	return Loc_ErrorState;
	
}

Error_TX_RX_e IIC_SlaveReceieveData(uint8_t*ReceivedData)
{
	Error_TX_RX_e Loc_ErrorState = NOError ;
	
    TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);/* Enable TWI & generation of ack */
	
	while (WAIT_FLAG);
	
	if (SLAVE_DATA_RECIEVED) /* Check for data received &ack returned */
	{
		*ReceivedData = TWDR ;
	}
	/* Check for data received, nack returned & switched to not addressed slave mode */
	if(((TWSR & 0xf8) == 0x88)||((TWSR & 0xf8) == 0x98))
		return TWDR;
	 
	return Loc_ErrorState;
}

Error_TX_RX_e IIC_Master_ReadData_ACK(uint8_t* Data ) 
{
	ES_t Loc_ErrorState = IIC_Master_ReadData_Error ; 
	
    TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);/* Enable TWI & clear interrupt flag */

	while(WAIT_FLAG) ; 
	
	if (MASTER_RECIEVE_ACK) /*Data byte has been received	ACK has been returned*/
	{
		*Data = TWDR ; 
		Loc_ErrorState = NOError ; 
	}

	return Loc_ErrorState ; 
}
Error_TX_RX_e IIC_Master_ReadData_NACK(uint8_t* Data )
{
	ES_t Loc_ErrorState = IIC_Master_ReadData_Error ;
	
	TWCR=(1<<TWEN)|(1<<TWINT);/* Enable TWI & clear interrupt flag */

	while(WAIT_FLAG) ;
	
	if (MASTER_RECIEVE_NACK) /*Data byte has been received	ACK has been returned*/
	{
		*Data = TWDR ;
		Loc_ErrorState = NOError ;
	}
	
	return Loc_ErrorState ;
}
ES_t IIC_StopCondition(void)
{
	ES_t Loc_ErrorState = NO_Error ;
	
    TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);/* Enable TWI, generate stop */
   
    while(TWCR&(1<<TWSTO));	/* Wait until stop condition execution */
	   
	return Loc_ErrorState ;
}

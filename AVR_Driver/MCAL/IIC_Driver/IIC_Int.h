#ifndef  _TWI_INT_H_
#define  _TWI_INT_H_

#include "utils.h"
#include "Types.h"
#include "ErrorState.h"
#include "IIC_Priv.h"
#include "IIC_Congig.h"


ES_t IIC_MasterInit(void);

ES_t IIC_SlaveInit(uint8_t SlaveAddress); 

Error_TX_RX_e IIC_StartCondition(void);

Error_TX_RX_e IIC_RepeatedStartCondition(void);

Error_TX_RX_e IIC_SendSlaveAdress(uint8_t LOC_uint8_tSlaveAdress , uint8_t operation) ;

Error_TX_RX_e IIC_SendSlaveAdress_NACK(uint8_t LOC_uint8_tSlaveAdress , uint8_t operation) ;

Error_TX_RX_e IIC_SlaveCheckAdress (void);

Error_TX_RX_e IIC_MasterSendData_ACK(uint8_t LOC_uint8_tData);

Error_TX_RX_e IIC_Master_ReadData_ACK(uint8_t* Data )  ; 

Error_TX_RX_e IIC_Master_ReadData_NACK(uint8_t* Data ) ; 

uint8_t IIC_SlaveReceieveData(uint8_t* Data);


ES_t IIC_StopCondition(void);


#endif
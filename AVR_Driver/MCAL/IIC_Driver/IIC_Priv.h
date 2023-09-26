#ifndef  _TWI_PRIV_H_
#define  _TWI_PRIV_H_

#include "IIC_Congig.h"

#define  TWBR        *((volatile uint8_t*)  0x20)
#define  TWSR        *((volatile uint8_t*)  0x21)
#define  TWAR        *((volatile uint8_t*)  0x22)
#define  TWCR        *((volatile uint8_t*)  0x56)
#define  TWDR        *((volatile uint8_t*)  0x23)

/*TWI Status Register -TWSR*/
#define TWS7      7
#define TWS6      6
#define TWS5      5
#define TWS4      4
#define TWS3      3
#define TWPS1     1
#define TWPS0     0

/*TWI Control Register -TWCR*/
#define TWINT     7
#define TWEA      6
#define TWSTA     5
#define TWSTO     4
#define TWWC      3
#define TWEN      2
#define TWIE      0

/************************************************************************/
/*     PRES To Set TWBR                                                                 */
/**********************************************Æ**************************/
#define PRES_1		1
#define PRES_4		2
#define PRES_16		16
#define PRES_64		64

#define SET_I2C_PRESCALER_1					TWSR&=~(1<<0) &(~(1<<1))


#define SET_I2C_PRESCALER_4					TWSR&=~(1<<1) ; \
											TWSR|= (1<<0)

#define SET_I2C_PRESCALER_16				TWSR&=~(1<<0) ; \
											TWSR|= (1<<1)

#define SET_I2C_PRESCALER_64				TWSR|= (1<<0) | (1<<1)

#define I2C_ONE								1
#define I2C_MAX_SLAVES						127


#define TWBR_VALUE							    TWBR = ((F_CPU-16UL*TWI_FREQ)/(2UL*TWI_FREQ*I2C_PRESCALER))


#define SET_TWBR_VALUE						TWBR = TWBR_VALUE
#define SET_I2C_ENABLE						TWCR|=(1<<2)
#define SET_ECU_ADDRESS(SlaveAddress)		TWAR=SlaveAddress<<1 
#define SET_START_CONDITION					TWCR|= (1<<5)
#define CLEAR_START_CONDITION				TWCR&=~(1<<5)
#define SET_STOP_CONDITION					TWCR|= (1<<4)
#define SET_ACKNOWLEDGE						TWCR|= (1<<6)
#define SET_INTERRUPT						TWCR|= (1<<0)

#define CLEAR_IIC_FLAG							TWCR|= (1<<7)


#define WAIT_FLAG							!((TWCR>>7) & 1)




#define SET_SLAVE_ADDRESS(Address)			TWDR=(Address<<1)
#define SET_SLAVE_ACTION(Action)			TWDR|=Action

#define SEND_DATA_REGISTER(Data)			TWDR=Data

/************************************************************************/
/*           IIC_CLKSPEED 100K : 400K                                                           */
/************************************************************************/
#define IIC_CLKSPEED_100K	100000UL
#define IIC_CLKSPEED_400K	400000UL



#define REPEAT_START_CONDITION_TRANSMIT		((TWSR & 0xf8) == 0x10)
#define START_CONDITION_TRANSMIT			((TWSR & 0xf8) == 0x08)
#define SLA_WRITE_RECIEVED_ACK				((TWSR & 0xf8) == 0x18)
#define SLA_WRITE_RECIEVED_NACK				((TWSR & 0xf8) == 0x20)
#define SLA_READ_TRANSMIT_ACK				((TWSR & 0xf8) == 0x40)
#define SLA_READ_TRANSMIT_NACK				((TWSR & 0xf8) == 0x48)
#define MASTER_DATA_TRANSMIT_ACK			((TWSR & 0xf8) == 0x28)
#define MASTER_DATA_TRANSMIT_NACK			((TWSR & 0xf8) == 0x30)
#define MASTER_RECIEVE_ACK					((TWSR&0xF8)==0x50 )
#define MASTER_RECIEVE_NACK					((TWSR&0xF8)==0x58 )
#define SLAVE_DATA_RECIEVED					((TWSR & 0xf8) == 0x80)||((TWSR & 0xf8) == 0x90)
#define SLAVE_WRITE_RECIEVED				((TWSR & 0xf8) == 0x68)||((TWSR & 0xf8) == 0x60)
#define SLAVE_RAED_RECIEVED					((TWSR & 0xf8) == 0xA8)||((TWSR & 0xf8) == 0xB0)
#define SLAVE_GENERALCALL_RECIEVED_ACK		((TWSR & 0xf8) == 0x70)||((TWSR & 0xf8) == 0x78)

typedef enum {
	NOError , 
	START_CONDITION_TRANSMIT_Error , 
	REPEAT_START_CONDITION_TRANSMIT_Error , 
	SLA_WRITE_RECIEVED_NACK_Error , 
	SLA_READ_TRANSMIT_Error , 
	MASTER_DATA_TRANSMIT_Error , 
	SLAVE_DATA_RECIEVED_Error , 
	SLAVE_WRITE_RECIEVE_ADDRESS_Error , 
	SLAVE_READ_RECIEVE_ADDRESS_Error ,
	IIC_Master_ReadData_Error
}Error_TX_RX_e;

#endif
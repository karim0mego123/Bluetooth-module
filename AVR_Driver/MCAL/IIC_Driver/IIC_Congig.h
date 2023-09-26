#ifndef  _TWI_CONFIG_H_
#define  _TWI_CONFIG_H_





/*TWBR RRES 1 4 16 64*/
//  PRES_1		
//  PRES_4		
//  PRES_16		
//  PRES_64	
#define I2C_PRESCALER	PRES_4

#define WRITE				0
#define READ				1
 
// TWI_FREQ_100K
// TWI_FREQ_400K
#define TWI_FREQ	IIC_CLKSPEED_100K

/*TWI Slave Adress Register -TWAR*/
#define TWGCE     0

/*TWI ERROR STATE*/
#define NOK    0
#define OK     1


#define F_CPU		8000000UL


#endif
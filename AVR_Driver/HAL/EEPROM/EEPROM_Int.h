/*
 * EEPROM_Int.h
 *
 * Created: 8/30/2023 12:36:52 PM
 *  Author: karim
 */ 


#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

#include "ErrorState.h"
#include "Types.h"
#include "utils.h"

ES_t EEPROM_INTT(uint8_t Address);

ES_t EEPROM_WriteData(uint16_t Address , uint8_t Data ) ;

ES_t EEPROM_ReadData(uint16_t Address , uint8_t* Data ) ;


#endif /* EEPROM_INT_H_ */
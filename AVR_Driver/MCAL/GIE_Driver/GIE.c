/*
 * GIE.c
 *
 * Created: 4/25/2023 2:47:23 PM
 *  Author: karim
 */ 
#include "GIE.h"

ES_t EnableGlobalEnterrupt(void) 
{
	ES_t Local_state = NO_Error ; 
	
	SET_BIT(SREG,7) ;
	
	return Local_state ; 
}
ES_t DisableGlobalEnterrupt(void) 
{
	ES_t Local_state = NO_Error ;
	
	CLEAR_BIT(SREG,7) ;
	
	return Local_state ;
}
/*
 * Ultrasonic_Interface.h
 *
 * Created: 7/17/2023 2:18:02 AM
 *  Author: karim
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

#include "Timer1_Interface.h"
#include "Ultrasonic_Config.h"
#include "Ultrasonic_Priv.h"


/************************************************************************************/
/* Description: this function is init Ultrasonic with call back functions			*/
/* Inputs: void														 	 		    */
/* Output: void								  										*/
/************************************************************************************/
void Ultrasonic_VoidInit() ;

/************************************************************************************/
/* Description:		function used in start Ultrasonic in mode of no block 			*/
/* Inputs: TR PORT ,  TR PIN										 	 		    */
/* Output: uint8_t not doing start untill read for first start occur				*/
/************************************************************************************/
void Ultrasonic_u8Start(uint8_t PORT_TR, uint8_t TR_Pin ) ;

/************************************************************************************/
/* Description:	this function read distance after doing init for ultrasonic			*/
/* Inputs: Distance													 	 		    */
/* Output: void											  						    */
/************************************************************************************/
void Ultrasonic_VoidReadDistance(uint8_t*Distance ,uint8_t PORT_TR ,uint8_t TR_Pin);

/************************************************************************************/
/* Description: after doing init to ultrasonic and strat you can use this function  */
/*to read distance with out blocked in function										*/
/* Inputs: TOP value													 		    */
/* Output: void								  									    */
/************************************************************************************/
uint8_t Ultrasonic_VoidReadDistanceNoBlock(uint8_t* Distance) ; 

#endif /* ULTRASONIC_INTERFACE_H_ */

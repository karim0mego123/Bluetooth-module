/*
 * Ultrasonic_Prog.c
 *
 * Created: 7/17/2023 2:19:03 AM
 *  Author: karim
 */ 
#include "Ultrasonic_Interface.h"

static volatile uint8_t c = 0 , c1 = 0  , c2 = 0 , flag = 0 ; 
static volatile uint16_t t1 = 0  , t2 = 0 ;

static void Fun_ICU ()
{
	if (flag == 0 )
	{
		c = 0 ;
		t1 = ICR1 ; 
		flag = 1 ; 
		Timer1_voidICEdgeSelect(_FALLING_EDGE) ; 
	}
	else if ( flag == 1 )
	{
		t2 = ICR1 ; 
		flag = 2 ; 
		Timer1_voidICEdgeSelect(_RISING_EDGE) ; 
		Timer1_voidOVFDisableInterrupt() ; 
		Timer1_voidCaptureEventDisableInterrupt();
	}
}
static void Fun_OVF()
{
	c++ ; 
}
void Ultrasonic_VoidInit() 
{
	/************************************************************************/
	/* Timer1_init --------> NOrmal mode OC1A , OC1B Disconnect                                                                     */
	/************************************************************************/
	
	Timer1_voidCaptureEventSetCallBack(Fun_ICU) ; 
	Timer1_voidOVFSetCallBack(Fun_OVF) ;
}
void Ultrasonic_u8Start(uint8_t PORT_TR, uint8_t TR_Pin )
{
	if (flag==0)
	{
		c1 = c ;
		DIO_Write_Pin_Dir(PORT_TR,TR_Pin,OUT);
		DIO_Write_Pin_Dir(Ultrasonic_ECHO_PORT,Ultrasonic_ECHO_PIN,OUT);
		DIO_Write_Pin(PORT_TR,TR_Pin,HIGH) ;
		_delay_us(20) ;
		DIO_Write_Pin(PORT_TR,TR_Pin,LOW) ;
		Timer1_voidICEdgeSelect(_RISING_EDGE);
		Timer1_voidOVFEnableInterrupt();
		Timer1_voidCaptureEventEnableInterrupt();
	}
}
uint8_t Ultrasonic_VoidReadDistanceNoBlock(uint8_t* Distance )
{
	uint16_t Time = 0 ;
	if (flag==2)
	{
		c2 = c ;
		Time = t2 - t1 +((uint32_t)(c2-c1)*65535) ;
		*Distance = Time / 58 ;
		Timer1_voidOVFEnableInterrupt();
		flag=0 ;
		return 1 ;
	}
	return 0 ;
}
void Ultrasonic_VoidReadDistance(uint8_t*Distance ,uint8_t PORT_TR ,uint8_t TR_Pin) 
{
	uint16_t Loc_Time = 0 ; 
	
	DIO_Write_Pin_Dir(PORT_TR,TR_Pin,OUT);
	DIO_Write_Pin_Dir(Ultrasonic_ECHO_PORT,Ultrasonic_ECHO_PIN,OUT);
	
	DIO_Write_Pin(PORT_TR,TR_Pin,HIGH) ; 
	_delay_us(20) ; 
	DIO_Write_Pin(PORT_TR,TR_Pin,LOW) ;
	
	Timer1_voidICEdgeSelect(_RISING_EDGE);
	c1 = c ;
	flag=0 ; 
	Timer1_voidOVFEnableInterrupt();
	Timer1_voidCaptureEventEnableInterrupt();
	sei() ; 
	while(flag<2);
	c2 = c ; 
	Loc_Time = t2 - t1 + (c2-c1)*65535UL ; 
	*Distance = Loc_Time / 58 ; 	
	Timer1_voidCaptureEventDisableInterrupt();
}

/*
 * Timer_services.c
 *
 * Created: 9/9/2023 1:06:28 PM
 *  Author: karim
 */ 
#include "Timer1_Interface.h"

volatile uint16_t t1 , t2 , t3  ; 
volatile uint8_t flag = 0 ;  
static void Func_ICU()
{
	if (flag==0)
	{
		t1 = ICR1 ; 
		Timer1_voidICEdgeSelect(_FALLING_EDGE) ; 
		flag = 1 ;  
	}
	else if (flag==1)
	{
		t2 = ICR1 ; 
		Timer1_voidICEdgeSelect(_RISING_EDGE) ;
		flag = 2 ;
	}
	else if (flag==2)
	{
		t3 = ICR1 ; 
		Timer1_voidCaptureEventDisableInterrupt() ; 
		flag = 3 ; 
	}
}
/************************************************************************/
/* its better to init timer in normal mode here divide by 1000000 as	*/
/* i used 8000000 and pres 8  OC1A , OC1B Disconnected                 */
/************************************************************************/
void PWM_Measure(uint32_t* Ptr_Freq , uint8_t* Ptr_Duty ) 
{
	uint16_t Ton = 0  , Toff = 0 ;
	Timer1_voidCaptureEventSetCallBack(Func_ICU) ; 
	Timer1_voidICEdgeSelect(_RISING_EDGE) ; 
	Timer1_voidCaptureEventEnableInterrupt() ; 
	EnableGlobalEnterrupt() ;
	flag = 0 ; 
	while(flag<3) ;
	Ton = t2 - t1 ; 
	Toff = t3 - t2 ;
	*Ptr_Freq = (1000000UL) / (Ton+Toff) ; 
	*Ptr_Duty = ((Ton*100 )/(Ton+Toff)); 
}

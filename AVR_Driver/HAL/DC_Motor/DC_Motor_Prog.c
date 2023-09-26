/*
 * DC_Motor.c
 *
 * Created: 7/16/2023 10:59:22 PM
 *  Author: karim
 */ 
#include "DC_Motor_Interface.h"
#include "DIO.h"
#include "GIE.h"

void DC_MotorInit()
{
	PWM_Init() ;
	Timer1_voidOCAEnableInterrupt() ;
	EnableGlobalEnterrupt() ;

#ifdef DC_MOTOR_1
	DIO_Write_Pin_Dir(DC_IN1_PORT,DC_IN1_PIN,OUT);	
	DIO_Write_Pin_Dir(DC_IN2_PORT,DC_IN2_PIN,OUT);
	DIO_Write_Pin_Dir(DC_EN1_PORT,DC_EN1_PIN,OUT);
#endif
#ifdef DC_MOTOR_2
	DIO_Write_Pin_Dir(DC_IN3_PORT,DC_IN3_PIN,OUT);
	DIO_Write_Pin_Dir(DC_IN4_PORT,DC_IN4_PIN,OUT);
	DIO_Write_Pin_Dir(DC_EN2_PORT,DC_EN2_PIN,OUT);
#endif

#ifdef DC_MOTOR_3
	DIO_Write_Pin_Dir(DC_IN7_PORT,DC_IN7_PIN,OUT);
	DIO_Write_Pin_Dir(DC_IN8_PORT,DC_IN8_PIN,OUT);
	DIO_Write_Pin_Dir(DC_EN3_PORT,DC_EN3_PIN,OUT);
#endif

#ifdef DC_MOTOR_4
	DIO_Write_Pin_Dir(DC_IN7_PORT,DC_IN7_PIN,OUT);
	DIO_Write_Pin_Dir(DC_IN8_PORT,DC_IN8_PIN,OUT);
	DIO_Write_Pin_Dir(DC_EN4_PORT,DC_EN4_PIN,OUT);
#endif


}
void DC_MotorMoveRight(uint8_t Motor_Number)
{
	switch(Motor_Number)
	{
	case 1 :
		DIO_Write_Pin(DC_IN1_PORT,DC_IN1_PIN,HIGH);
		DIO_Write_Pin(DC_IN2_PORT,DC_IN2_PIN,LOW);
		break ;
	case 2 :
		DIO_Write_Pin(DC_IN3_PORT,DC_IN3_PIN,HIGH);
		DIO_Write_Pin(DC_IN4_PORT,DC_IN4_PIN,LOW);
		break ;
	case 3 :
		DIO_Write_Pin(DC_IN5_PORT,DC_IN5_PIN,HIGH);
		DIO_Write_Pin(DC_IN6_PORT,DC_IN6_PIN,LOW);
		break ;
	case 4 :
		DIO_Write_Pin(DC_IN7_PORT,DC_IN7_PIN,HIGH);
		DIO_Write_Pin(DC_IN8_PORT,DC_IN8_PIN,LOW);
		break ;
	default :
		break ;

	}

}
void DC_MotorMoveLeft(uint8_t Motor_Number)
{
	switch(Motor_Number)
	{
	case 1 :
		DIO_Write_Pin(DC_IN1_PORT,DC_IN1_PIN,LOW);
		DIO_Write_Pin(DC_IN2_PORT,DC_IN2_PIN,HIGH);
		break ;
	case 2 :
		DIO_Write_Pin(DC_IN3_PORT,DC_IN3_PIN,LOW);
		DIO_Write_Pin(DC_IN4_PORT,DC_IN4_PIN,HIGH);
		break ;
	case 3 :
		DIO_Write_Pin(DC_IN5_PORT,DC_IN5_PIN,LOW);
		DIO_Write_Pin(DC_IN6_PORT,DC_IN6_PIN,HIGH);
		break ;
	case 4 :
		DIO_Write_Pin(DC_IN7_PORT,DC_IN7_PIN,LOW);
		DIO_Write_Pin(DC_IN8_PORT,DC_IN8_PIN,HIGH);
		break ;
	default :
		break ;
	}
}
void DC_MotorSetSpeed(uint16_t Freq , uint8_t Duty )
{
#ifdef DC_MOTOR_1 || DC_MOTOR_2
	PWM_Freq_Hz(Freq) ;
	PWM_Duty_OCR1A(Duty);
#endif

#ifdef DC_MOTOR_3 || DC_MOTOR_4
	PWM_Freq_Hz(Freq) ;
	PWM_Duty_OCR1B(Duty);
#endif
}
void DC_MotorStop(uint8_t Motor_Number)
{
	switch(Motor_Number)
	{
	case 1 :
		DIO_Write_Pin(DC_IN1_PORT,DC_IN1_PIN,LOW);
		DIO_Write_Pin(DC_IN2_PORT,DC_IN2_PIN,LOW);
		break ;
	case 2 :
		DIO_Write_Pin(DC_IN3_PORT,DC_IN3_PIN,LOW);
		DIO_Write_Pin(DC_IN4_PORT,DC_IN4_PIN,LOW);
		break ;
	case 3 :
		DIO_Write_Pin(DC_IN5_PORT,DC_IN5_PIN,LOW);
		DIO_Write_Pin(DC_IN6_PORT,DC_IN6_PIN,LOW);
		break ;
	case 4 :
		DIO_Write_Pin(DC_IN7_PORT,DC_IN7_PIN,LOW);
		DIO_Write_Pin(DC_IN8_PORT,DC_IN8_PIN,LOW);
		break ;
	default :
		break ;
	}
}

/*
 * AVR_Driver.c
 *
 * Created: 1/29/2023 12:30:53 AM
 * Author : karim
 */ 

#include "string.h"
#include "LCD.h"
#include "USART.h"


int main ()
{

	uint8_t Data1[20] ={0}  , i = 0 ;

	DIO_Write_Pin_Dir(PORT_B,PIN3,OUT) ;
	DIO_Write_Pin_Dir(PORT_B,PIN4,OUT) ;
	DIO_Write_Pin_Dir(PORT_B,PIN5,OUT) ;
	DIO_Write_Pin_Dir(PORT_B,PIN6,OUT) ;

	LCD_Init() ;
	USART_Init() ;

	while(1)
	{
		i = 0 ;
		while(1)
		{
			USART_Recieve_Char(&Data1[i]) ;
			if(Data1[i]=='0')
			{
				Data1[i] = '\0' ;
				break ;
			}
			i++ ;
		}
		LCD_Clear_Screen() ;
		if(strcmp((char*)Data1,"LCD ON")==0)
		{
			LCD_Write_String((uint8_t*)"Hello LCD",0,0) ;
		}
		else if(strcmp((char*)Data1,"LED 1 ON")==0)
		{
			DIO_Write_Pin(PORT_B,PIN4,HIGH) ;
			LCD_Write_String((uint8_t*)"LED 1 ON",0,0) ;
		}
		else if(strcmp((char*)Data1,"LED 1 OFF")==0)
		{
			DIO_Write_Pin(PORT_B,PIN4,LOW) ;
			LCD_Write_String((uint8_t*)"LED 1 OFF",0,0) ;
		}
		else if(strcmp((char*)Data1,"LED 2 ON")==0)
		{
			DIO_Write_Pin(PORT_B,PIN5,HIGH) ;
			LCD_Write_String((uint8_t*)"LED 2 ON",0,0) ;
		}
		else if(strcmp((char*)Data1,"LED 2 OFF")==0)
		{
			DIO_Write_Pin(PORT_B,PIN5,LOW) ;
			LCD_Write_String((uint8_t*)"LED 2 OFF",0,0) ;
		}
		else if(strcmp((char*)Data1,"LED 3 ON")==0)
		{
			DIO_Write_Pin(PORT_B,PIN6,HIGH) ;
			LCD_Write_String((uint8_t*)"LED 3 ON",0,0) ;
		}
		else if(strcmp((char*)Data1,"LED 3 OFF")==0)
		{
			DIO_Write_Pin(PORT_B,PIN6,LOW) ;
			LCD_Write_String((uint8_t*)"LED 3 OFF",0,0) ;
		}
		else if(strcmp((char*)Data1,"BUZZER ON")==0)
		{
			DIO_Write_Pin(PORT_B,PIN3,HIGH) ;
			LCD_Write_String((uint8_t*)"BUZZER ON",0,0) ;
		}
		else if(strcmp((char*)Data1,"BUZZER OFF")==0)
		{
			DIO_Write_Pin(PORT_B,PIN3,LOW) ;
			LCD_Write_String((uint8_t*)"BUZZER OFF",0,0) ;
		}
	}
}

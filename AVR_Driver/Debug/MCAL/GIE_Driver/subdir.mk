################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GIE_Driver/GIE.c 

OBJS += \
./MCAL/GIE_Driver/GIE.o 

C_DEPS += \
./MCAL/GIE_Driver/GIE.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GIE_Driver/%.o: ../MCAL/GIE_Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\MCAL\ADC_Driver" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\HAL\JoyStick_Driver" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\HAL\PIR_Sensor" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\MCAL\GIE_Driver" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\MCAL\DIO_Driver" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\MCAL\EXTI_Driver" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\MCAL\IIC_Driver" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\MCAL\SPI_Driver" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\MCAL\TIMER0" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\MCAL\TIMER1" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\MCAL\USART_Driver" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\Utilities" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\HAL\7 segment" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\HAL\DC_Motor" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\HAL\EEPROM" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\HAL\KeyPad_Driver" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\HAL\LCD_Driver" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\HAL\Stepper_Motor" -I"C:\Users\karim\Desktop\WorkSpace\eclipse_avr\AVR_Driver\HAL\Ultrasonic" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



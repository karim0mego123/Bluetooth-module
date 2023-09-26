/*
 * JoyStick_Config.h
 *
 *  Created on: Sep 23, 2023
 *      Author: karim
 */

#ifndef HAL_JOYSTICK_DRIVER_JOYSTICK_CONFIG_H_
#define HAL_JOYSTICK_DRIVER_JOYSTICK_CONFIG_H_

#include "DIO.h"

#define VRX_PORT		PORT_A
#define VRX_PIN			GPIO_PIN_0

#define VRY_PORT		PORT_A
#define VRY_PIN			GPIO_PIN_1

#define SW_PORT		PORT_B
#define SW_PIN			GPIO_PIN_4

#endif /* HAL_JOYSTICK_DRIVER_JOYSTICK_CONFIG_H_ */

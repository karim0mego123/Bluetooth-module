/*
 * DC_Motor_CFG.h
 *
 * Created: 7/16/2023 11:07:39 PM
 *  Author: karim
 */ 


#ifndef DC_MOTOR_CFG_H_
#define DC_MOTOR_CFG_H_

/*
L293D
*/

#define DC_MOTOR_1
#define DC_MOTOR_2
#define DC_MOTOR_3
#define DC_MOTOR_4


#include "Regesters.h"

#ifdef  DC_MOTOR_1

#define DC_EN1_PORT PORT_D
#define DC_EN1_PIN	PIN5

#define DC_IN1_PORT	PORT_C
#define DC_IN1_PIN	PIN0

#define DC_IN2_PORT	PORT_C
#define DC_IN2_PIN	PIN1

#endif
/*-------------------------------------*/

#ifdef DC_MOTOR_2

#define DC_EN2_PORT PORT_D
#define DC_EN2_PIN	PIN5


#define DC_IN3_PORT	PORT_C
#define DC_IN3_PIN	PIN0

#define DC_IN4_PORT	PORT_C
#define DC_IN4_PIN	PIN1

#endif

/*-------------------------------------*/

#ifdef DC_MOTOR_3

#define DC_EN3_PORT PORT_D
#define DC_EN3_PIN	PIN4

#define DC_IN5_PORT	PORT_C
#define DC_IN5_PIN	PIN2

#define DC_IN6_PORT	PORT_C
#define DC_IN6_PIN	PIN3

#endif
/*-------------------------------------*/

#ifdef DC_MOTOR_4

#define DC_EN4_PORT PORT_D
#define DC_EN4_PIN	PIN4

#define DC_IN7_PORT	PORT_C
#define DC_IN7_PIN	PIN2

#define DC_IN8_PORT	PORT_C
#define DC_IN8_PIN	PIN3

#endif

#endif /* DC_MOTOR_CFG_H_ */

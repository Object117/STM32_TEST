/*
 * device_PIRsensor.h
 *
 *  Created on: 2018. 9. 6.
 *      Author: leejh
 */

#ifndef DEVICE_PIRSENSOR_H_
#define DEVICE_PIRSENSOR_H_

#include"stm32f0xx_hal.h"

typedef enum {
	PIR_SENSOR1 = 0
}PIRsensor_TypeDef;		// PIR : Passive Infrated Sensor : for Motion detection

#define PIR_SENSORn					1

#define PIR1_SENSOR_PIN				GPIO_PIN_12
#define PIR1_SENSOR_PORT			GPIOB
#define PIR1_EXTI_IRQn				EXTI4_15_IRQn
#define PIR1_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOB_CLK_ENABLE()
#define PIR1_GPIO_CLK_DISABLE()		__HAL_RCC_GPIOB_CLK_DISABLE()
#define PIR1_EXTI_IRQn				EXTI4_15_IRQn

#define PIRx_GPIO_CLK_ENABLE(__PIR__) do { if((__PIR__) == PIR_SENSOR1) PIR1_GPIO_CLK_ENABLE(); }while(0)
#define PIRx_GPIO_CLK_DISABLE(__PIR__) (((__PIR__) == PIR_SENSOR1) ? PIR1_GPIO_CLK_DISABLE() : 0)

void PIR_Sensor_Init(PIRsensor_TypeDef pirsensor);

#endif /* DEVICE_PIRSENSOR_H_ */

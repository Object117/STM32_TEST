/*
 * device_delay.h
 *
 *  Created on: 2018. 9. 5.
 *      Author: leejh
 */

#ifndef DEVICE_RELAY_H_
#define DEVICE_RELAY_H_

/**	@defgroup RELAY TEST (ks0057 keyestudio Dual Relay Module) in STM32F072B_DISCOVERY
 * @{
 */
#include "stm32f0xx_hal.h"

typedef enum {
	RELAY1 = 0	,
	RELAY2 = 1
}Relay_TypeDef;

#define RELAYn							2

#define RELAY1_PIN						GPIO_PIN_4
#define RELAY1_GPIO_PORT				GPIOA
#define RELAY1_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOA_CLK_ENABLE()
#define RELAY1_GPIO_CLK_DISABLE()		__HAL_RCC_GPIOA_CLK_DISABLE()

#define RELAY2_PIN						GPIO_PIN_5
#define RELAY2_GPIO_PORT				GPIOA
#define RELAY2_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOA_CLK_ENABLE()
#define RELAY2_GPIO_CLK_DISABLE()		__HAL_RCC_GPIOA_CLK_DISABLE()

#define RELAYx_GPIO_CLK_ENABLE(__RELAY__) do { if((__RELAY__) == RELAY1) RELAY1_GPIO_CLK_ENABLE(); else \
											   if((__RELAY__) == RELAY2) RELAY2_GPIO_CLK_ENABLE();} while(0)

#define RELAYx_GPIO_CLK_DISABLE(__RELAY__) (((__RELAY__) == RELAY1) ? RELAY1_GPIO_CLK_DISABLE() : \
											((__RELAY__) == RELAY2) ? RELAY2_GPIO_CLK_DISABLE() : 0)

void Relay_DeviceSetup(void);
void Relay_Init(Relay_TypeDef relay);
void relay_on(void);
void relay_off(void);

void excuteRelayTest(void);

#endif /* DEVICE_RELAY_H_ */

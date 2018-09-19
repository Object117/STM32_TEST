/*
 * led.h
 *
 *  Created on: 2018. 9. 3.
 *      Author: leejh
 */

#ifndef DEVICE_LED_H_
#define DEVICE_LED_H_

/**
 * @brief LED Types Definition
 */
#include "stm32f0xx_hal.h"

typedef enum {
	LED3 = 0,
	LED4 = 1,
	LED5 = 2,
	LED6 = 3,
	/* Color led aliases */
	LED_RED = LED3,
	LED_ORANGE = LED4,
	LED_GREEN = LED5,
	LED_BLUE = LED6
}Led_TypeDef;


/**
 * @brief BUTTON Definition
 */

typedef enum {
	BUTTON_USER = 0
}Button_TypeDef;

typedef enum
{
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
}ButtonMode_TypeDef;


/** @defgroup STM32F072B_DISCOVERY_LED STM32F072B_DISCOVERY LED
  * @{
  */
#define LEDn                             4

#define LED3_PIN                         GPIO_PIN_6
#define LED3_GPIO_PORT                   GPIOC
#define LED3_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()
#define LED3_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOC_CLK_DISABLE()

#define LED4_PIN                         GPIO_PIN_8
#define LED4_GPIO_PORT                   GPIOC
#define LED4_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()
#define LED4_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOC_CLK_DISABLE()

#define LED5_PIN                         GPIO_PIN_9
#define LED5_GPIO_PORT                   GPIOC
#define LED5_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()
#define LED5_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOC_CLK_DISABLE()

#define LED6_PIN                         GPIO_PIN_7
#define LED6_GPIO_PORT                   GPIOC
#define LED6_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()
#define LED6_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOC_CLK_DISABLE()

#define LEDx_GPIO_CLK_ENABLE(__LED__) do { if((__LED__) == LED3) LED3_GPIO_CLK_ENABLE(); else \
                                           if((__LED__) == LED4) LED4_GPIO_CLK_ENABLE(); else \
                                           if((__LED__) == LED5) LED5_GPIO_CLK_ENABLE(); else \
                                           if((__LED__) == LED6) LED6_GPIO_CLK_ENABLE();} while(0)

#define LEDx_GPIO_CLK_DISABLE(__LED__)  (((__LED__) == LED3) ? LED3_GPIO_CLK_DISABLE() :\
                                         ((__LED__) == LED4) ? LED4_GPIO_CLK_DISABLE() :\
                                         ((__LED__) == LED5) ? LED5_GPIO_CLK_DISABLE() : \
                                         ((__LED__) == LED6) ? LED6_GPIO_CLK_DISABLE() : 0 )
/**
  * @}
  */

/** @defgroup STM32F072B_DISCOVERY_BUTTON STM32F072B_DISCOVERY BUTTON
  * @{
  */
#define BUTTONn                          1

/**
 * @brief USER push-button
 */
#define USER_BUTTON_PIN                GPIO_PIN_0                       /* PA0 */
#define USER_BUTTON_GPIO_PORT          GPIOA
#define USER_BUTTON_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_BUTTON_GPIO_CLK_DISABLE() __HAL_RCC_GPIOA_CLK_DISABLE()
#define USER_BUTTON_EXTI_IRQn          EXTI0_1_IRQn

#define BUTTONx_GPIO_CLK_ENABLE(__BUTTON__)    do { if((__BUTTON__) == BUTTON_USER) USER_BUTTON_GPIO_CLK_ENABLE();} while(0)

#define BUTTONx_GPIO_CLK_DISABLE(__BUTTON__)   (((__BUTTON__) == BUTTON_USER) ? USER_BUTTON_GPIO_CLK_DISABLE() : 0 )
/**
  * @}
  */

/** @defgroup STM32F072B_LED_Related_Function
  * @{
  */
void LED_Init(Led_TypeDef Led);
void LED_ON(Led_TypeDef Led);
void LED_OFF(Led_TypeDef Led);
void LED_Toggle(Led_TypeDef Led);
void LED_ALL_BLINK(Led_TypeDef Led1, Led_TypeDef Led2, Led_TypeDef Led3, Led_TypeDef Led4);

/** @defgroup STM32F072B_LED_Related_Function
  * @{
  */
void PB_Init(Button_TypeDef Button, ButtonMode_TypeDef Mode);
uint32_t PB_GetState(Button_TypeDef Button);

#endif /* DEVICE_LED_H_ */


/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_hal.h"
#include "i2c.h"
#include "spi.h"
#include "tsc.h"
#include "usart.h"
#include "usb.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#include "device_led.h"
#include "device_relay.h"
#include "device_photoInterrupter.h"
#include "device_PIRsensor.h"
#include "stateMachine.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
uint8_t TxBuffer[] = "Interrupt!\n";
UART_HandleTypeDef huart1;

USER_ACTION standby_functions = {STANDBY_inner_door_open	,
								STANDBY_inner_door_close	,
								STANDBY_extdoor_open	,
								STANDBY_extdoor_close	,
								STANDBY_baby_in			,
								STANDBY_baby_none
};

USER_ACTION ready_functions = {READY_inner_door_open	,
						READY_inner_door_close	,
						READY_extdoor_open	,
						READY_extdoor_close	,
						READY_baby_in	,
						READY_baby_none
};

USER_ACTION enter_functions = {ENTER_inner_door_open	,
						ENTER_inner_door_close	,
						ENTER_extdoor_open	,
						ENTER_extdoor_close	,
						ENTER_baby_in	,
						ENTER_baby_none
};

USER_ACTION protection_functions = {PROTECTION_inner_door_open	,
								PROTECTION_inner_door_close		,
								PROTECTION_extdoor_open		,
								PROTECTION_extdoor_close	,
								PROTECTION_baby_in		,
								PROTECTION_baby_none
};

USER_ACTION confirm_functions = {CONFIRM_inner_door_open	,
							CONFIRM_inner_door_close	,
							CONFIRM_extdoor_open	,
							CONFIRM_extdoor_close	,
							CONFIRM_baby_in			,
							CONFIRM_baby_none
};

USER_ACTION exit_functions = {EXIT_inner_door_open	,
						EXIT_inner_door_close	,
						EXIT_extdoor_open	,
						EXIT_extdoor_close	,
						EXIT_baby_in	,
						EXIT_baby_none
};


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
static void EXTI0_1_IRQHandler_Config(void);
static void EXTI2_3_IRQHandler_Config(void);
static void EXTI4_15_IRQHandler_Config(void);
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  EXTI0_1_IRQHandler_Config();
  EXTI2_3_IRQHandler_Config();
  EXTI4_15_IRQHandler_Config();
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C2_Init();
  MX_SPI2_Init();
  MX_TSC_Init();
  MX_USB_PCD_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  LED_Init(LED3);
  PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);
  PIS_Init(PIS1);
  Relay_Init(RELAY1);
  Relay_Init(RELAY2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  //  state = init_state_machine();

  while (1)
  {
	  /* USER CODE END WHILE */
	  //run_state_machine(state);

	  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB|RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;

  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */
static void EXTI0_1_IRQHandler_Config(void) {		// User Button
	/*Enable and set EXTI lines 0 to 1 Interrupt to the lowest priority */
	HAL_NVIC_SetPriority(EXTI0_1_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);
}

static void EXTI2_3_IRQHandler_Config(void) {		// Photo Interrupter
	/*Enable and set EXTI lines 2 to 3 Interrupt*/
	HAL_NVIC_SetPriority(EXTI2_3_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);
}

static void EXTI4_15_IRQHandler_Config(void) {		// PIR Motion Sensor
	/*Enable and set EXTI lines 4 to 15 Interrupt*/
	HAL_NVIC_SetPriority(EXTI4_15_IRQn, 4, 0);
	HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);
}


#if 1		//
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	uint8_t door_open[] = "DOOR_OPEN";
	uint8_t switch_open[] = "SWITCH_OPEN";
	uint8_t door_close[] = "DOOR_CLOSE";


	USER_ACTION* tStandby_state = &standby_functions;
	USER_ACTION* tReady_state = &ready_functions;
	USER_ACTION* tEnter_state = &enter_functions;

	if(GPIO_Pin == PIS1_PIN) {
		HAL_UART_Transmit(&huart1, (uint8_t*)door_open, sizeof(door_open), 10);		// TESTING
		tStandby_state->inner_door_open();
	}

	if(GPIO_Pin == USER_BUTTON_PIN){
		HAL_UART_Transmit(&huart1, (uint8_t*)switch_open, sizeof(switch_open), 10);		// TESTING
		tReady_state->inner_door_open();
	}

	if(GPIO_Pin == PIR1_SENSOR_PIN) {
		HAL_UART_Transmit(&huart1, (uint8_t*)door_close, sizeof(door_close), 10);		// TESTING
		tEnter_state->inner_door_open();
	}


}

#else		//
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	uint8_t door_open[] = "DOOR_OPEN";
	uint8_t switch_open[] = "SWITCH_OPEN";
	uint8_t door_close[] = "DOOR_CLOSE";

	//	HAL_UART_Transmit(&huart1, (uint8_t*)TxBuffer, sizeof(TxBuffer), 10);		// TESTING
	if((GPIO_Pin == PIS1_PIN) && (doing_action == DOOR_CLOSE)) {
		HAL_UART_Transmit(&huart1, (uint8_t*)door_open, sizeof(door_open), 10);		// TESTING
		doing_action = DOOR_OPEN;
	}

	if((GPIO_Pin == USER_BUTTON_PIN) && (doing_action == DOOR_OPEN)) {
		HAL_UART_Transmit(&huart1, (uint8_t*)switch_open, sizeof(switch_open), 10);		// TESTING
		doing_action = SWITCH_OPEN;
	}

	if((GPIO_Pin == PIR1_SENSOR_PIN) && (doing_action == SWITCH_OPEN)) {
		HAL_UART_Transmit(&huart1, (uint8_t*)door_close, sizeof(door_close), 10);		// TESTING
		doing_action = DOOR_CLOSE;
	}

}
#endif
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

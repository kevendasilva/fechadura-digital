/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "terminal_log.h"

#include "menu.h"

#include "another_keypad.h"

#include "lcd_v1.2.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  lcd_20x4_4bits_Init(); // Iniciando o display

  // Senha padrão
  int senha = 1234;

  // Mensagem inicial do menu
  menuInit();

  // Mensagem inicial do terminal
  terminalPrintInit();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  HAL_GPIO_WritePin(Led_locked_GPIO_Port, Led_locked_Pin, 1);
	  menuPassword();

	  int entrada;

	  entrada = keypadLoopF();

	  if(senha == entrada)
	  {

		  terminalPasswordLog(senha, 1);
		  menuMain();

		  int op;

		  // Capturando a opção digitada pelo usuário
		  op = keypadLoopO();

		  switch (op)
		  {
		  case 1:
			  // Caso queira abrir a porta

			  HAL_GPIO_WritePin(Led_locked_GPIO_Port, Led_locked_Pin, 0);
			  HAL_GPIO_WritePin(Led_open_GPIO_Port, Led_open_Pin, 1);

			  terminalPrintNL(2);
			  terminalPrint("Door open!");
			  terminalPrintNL(2);

			  HAL_GPIO_TogglePin(Atuador_GPIO_Port, Atuador_Pin);
			  HAL_Delay(200);
			  HAL_GPIO_TogglePin(Atuador_GPIO_Port, Atuador_Pin);
			  HAL_Delay(200);
			  HAL_GPIO_TogglePin(Atuador_GPIO_Port, Atuador_Pin);
			  HAL_Delay(200);
			  HAL_GPIO_TogglePin(Atuador_GPIO_Port, Atuador_Pin);
			  HAL_Delay(200);

			  // Aguardando a porta ser fechada
			  while (HAL_GPIO_ReadPin(Btn_locked_GPIO_Port, Btn_locked_Pin) != 1);

			  terminalPrintNL(2);uyk-axgr-irc
			  terminalPrint("Door closed!");
			  terminalPrintNL(2);

			  HAL_GPIO_WritePin(Led_open_GPIO_Port, Led_open_Pin, 0);

			  break;
		  case 2:
			  // Caso deseje alterar a senha


			  menu2();
			  terminalPasswordChanged();
			  senha = keypadLoopF();
			  break;
		  case 3:
			  // Caso deseje retornar para os padrões de fábrica

			  menu3();
			  terminalResetPassword();
			  HAL_Delay(200);
			  senha = 1234;
			  break;
		  default:
			  menuE();
		  }

	  }
	  else
	  {
		 // Usuario errou a senha

		 HAL_GPIO_TogglePin(Led_locked_GPIO_Port, Led_locked_Pin);
		 HAL_Delay(100);
		 HAL_GPIO_TogglePin(Led_locked_GPIO_Port, Led_locked_Pin);
		 HAL_Delay(100);
		 HAL_GPIO_TogglePin(Led_locked_GPIO_Port, Led_locked_Pin);
		 HAL_Delay(100);
		 HAL_GPIO_TogglePin(Led_locked_GPIO_Port, Led_locked_Pin);
		 HAL_Delay(100);
		 terminalPasswordLog(senha, 0);
		 menuPasswordFail();
	  }

	  HAL_Delay(100);
	  lcd_limpa_display();

    /* USER CODE END WHILE */

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
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LCD_RS_Pin|LCD_EN_Pin|LCD_D4_Pin|LCD_D5_Pin
                          |LCD_D6_Pin|LCD_D7_Pin|KOut1_Pin|KOut2_Pin
                          |KOut3_Pin|KOut4_Pin|Atuador_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Led_open_Pin|Led_locked_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LCD_RS_Pin LCD_EN_Pin LCD_D4_Pin LCD_D5_Pin
                           LCD_D6_Pin LCD_D7_Pin KOut1_Pin KOut2_Pin
                           KOut3_Pin KOut4_Pin Atuador_Pin */
  GPIO_InitStruct.Pin = LCD_RS_Pin|LCD_EN_Pin|LCD_D4_Pin|LCD_D5_Pin
                          |LCD_D6_Pin|LCD_D7_Pin|KOut1_Pin|KOut2_Pin
                          |KOut3_Pin|KOut4_Pin|Atuador_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Led_open_Pin Led_locked_Pin */
  GPIO_InitStruct.Pin = Led_open_Pin|Led_locked_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : Btn_locked_Pin */
  GPIO_InitStruct.Pin = Btn_locked_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(Btn_locked_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : KIn1_Pin KIn2_Pin KIn3_Pin KIn4_Pin */
  GPIO_InitStruct.Pin = KIn1_Pin|KIn2_Pin|KIn3_Pin|KIn4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
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
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

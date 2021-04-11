/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_RS_Pin GPIO_PIN_0
#define LCD_RS_GPIO_Port GPIOA
#define LCD_EN_Pin GPIO_PIN_1
#define LCD_EN_GPIO_Port GPIOA
#define LCD_D4_Pin GPIO_PIN_2
#define LCD_D4_GPIO_Port GPIOA
#define LCD_D5_Pin GPIO_PIN_3
#define LCD_D5_GPIO_Port GPIOA
#define LCD_D6_Pin GPIO_PIN_4
#define LCD_D6_GPIO_Port GPIOA
#define LCD_D7_Pin GPIO_PIN_5
#define LCD_D7_GPIO_Port GPIOA
#define KOut1_Pin GPIO_PIN_6
#define KOut1_GPIO_Port GPIOA
#define KOut2_Pin GPIO_PIN_7
#define KOut2_GPIO_Port GPIOA
#define Led_open_Pin GPIO_PIN_0
#define Led_open_GPIO_Port GPIOB
#define Led_locked_Pin GPIO_PIN_1
#define Led_locked_GPIO_Port GPIOB
#define Btn_locked_Pin GPIO_PIN_2
#define Btn_locked_GPIO_Port GPIOB
#define KOut3_Pin GPIO_PIN_8
#define KOut3_GPIO_Port GPIOA
#define KOut4_Pin GPIO_PIN_9
#define KOut4_GPIO_Port GPIOA
#define KIn1_Pin GPIO_PIN_10
#define KIn1_GPIO_Port GPIOA
#define KIn2_Pin GPIO_PIN_11
#define KIn2_GPIO_Port GPIOA
#define KIn3_Pin GPIO_PIN_12
#define KIn3_GPIO_Port GPIOA
#define KIn4_Pin GPIO_PIN_13
#define KIn4_GPIO_Port GPIOA
#define Atuador_Pin GPIO_PIN_15
#define Atuador_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

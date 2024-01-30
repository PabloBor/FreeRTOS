/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    usart.h
 * @brief   This file contains the headers of the interrupt handlers.
 ******************************************************************************
*/
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H
#define __USART_H

#include "stm32f4xx.h"

#define BIT_7           7U
#define BIT_2           2U

void _init_usart();
void __usart_write(USART_TypeDef *usart, char c);





#endif

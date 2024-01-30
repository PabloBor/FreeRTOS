/**
  ******************************************************************************
  * @file    usart.c
  * @author  Jose Urias
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer System Source File.
  *
  ******************************************************************************
*/
#include "usart.h"

#define HSI_Value 16000000 // Assuming 16 MHz for HSI
#define PLL_N 336
#define PLL_M 16
#define USART2_BaudRate 57600 // Replace with your desired baud rate

uint32_t calculate_fCLK();
uint16_t calculate_USART2_BRR();

void _init_usart()
{
    /* Enable USART2 clock */
  RCC->APB1ENR |= (1 << RCC_APB1ENR_USART2EN_Pos);
  // do two dummy reads after enabling the peripheral clock, as per the errata
  volatile uint32_t dummy;
  dummy = RCC->APB1ENR;
  dummy = RCC->APB1ENR;

  /* Enable GPIOA clock*/
  RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOAEN);
  // do two dummy reads after enabling the peripheral clock, as per the errata
  dummy = RCC->AHB1ENR;
  dummy = RCC->AHB1ENR;

  /* Set PA2 and PA3 to alternate function */
  GPIOA->MODER &= ~(GPIO_MODER_MODE2_Msk | GPIO_MODER_MODE3_Msk);
  GPIOA->MODER |= (BIT_2 << GPIO_MODER_MODE2_Pos) | (BIT_2 << GPIO_MODER_MODE3_Pos);

  // USART2 is AF7 (found in datasheet)
  GPIOA->AFR[0] &= ~(GPIO_AFRL_AFRL2 | GPIO_AFRL_AFRL3);
  GPIOA->AFR[0] |= (BIT_7 << GPIO_AFRL_AFSEL2_Pos) | (BIT_7 << GPIO_AFRL_AFSEL3_Pos);
  
  uint16_t USART2_BRR_value = calculate_USART2_BRR();
   /* Configure and enable USART2 */
  USART2->BRR = USART2_BRR_value; // 115200 baud @ 50 MHz APB1 clock and 16x oversampling
  USART2->CR1 |= USART_CR1_UE | USART_CR1_TE; // USART enable and transmitter enable

}

void __usart_write(USART_TypeDef *usart, char c)
{
    usart->DR = c;
    while (!(usart->SR & USART_SR_TC));
}

uint32_t calculate_fCLK() {
    uint32_t fCLK = (HSI_Value/PLL_M) * PLL_N;
    return fCLK;
}

uint16_t calculate_USART2_BRR() {
    uint32_t fCLK = calculate_fCLK();
    return (uint16_t)(fCLK / (16 * USART2_BaudRate));
}


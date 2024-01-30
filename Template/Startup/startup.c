#include <stdint.h>

#define SRAM_START (0x20000000U)
#define SRAM_SIZE (128U * 1024U)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_POINTER_INIT_ADDRESS (SRAM_END)
#define ISR_VECTOR_SIZE_WORDS 114


/* System exception vector handler */
void Reset_Handler(void);
void default_handler(void);

// Cortex-M system exceptions
void NMI_Handler(void) __attribute__((weak, alias("default_handler")));
void HardFault_Handler(void) __attribute__((weak, alias("default_handler")));
void MemManage_Handler(void) __attribute__((weak, alias("default_handler")));
void BusFault_Handler(void) __attribute__((weak, alias("default_handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("default_handler")));
void SVC_Handler(void) __attribute__((weak, alias("default_handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("default_handler")));
void PendSV_Handler(void) __attribute__((weak, alias("default_handler")));
void SysTick_Handler(void) __attribute__((weak, alias("default_handler")));


// STM32F446RE interrupt handlers
void WWDG_IRQHandler(void) __attribute__((weak, alias("default_handler")));                                       
void PVD_IRQHandler(void) __attribute__((weak, alias("default_handler")));   
void TAMP_STAMP_IRQHandler(void) __attribute__((weak, alias("default_handler")));                    
void RTC_WKUP_IRQHandler(void) __attribute__((weak, alias("default_handler")));                      
void FLASH_IRQHandler(void) __attribute__((weak, alias("default_handler")));                                         
void RCC_IRQHandler(void) __attribute__((weak, alias("default_handler")));                                          
void EXTI0_IRQHandler(void) __attribute__((weak, alias("default_handler")));                       
void EXTI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void EXTI2_IRQHandler(void) __attribute__((weak, alias("default_handler")));                        
void EXTI3_IRQHandler(void) __attribute__((weak, alias("default_handler")));                          
void EXTI4_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void DMA1_Stream0_IRQHandler(void) __attribute__((weak, alias("default_handler")));                 
void DMA1_Stream1_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void DMA1_Stream2_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void DMA1_Stream3_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void DMA1_Stream4_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void DMA1_Stream5_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void DMA1_Stream6_IRQHandler(void) __attribute__((weak, alias("default_handler")));                 
void ADC_IRQHandler(void) __attribute__((weak, alias("default_handler")));                 
void CAN1_TX_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void CAN1_RX0_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void CAN1_RX1_IRQHandler(void) __attribute__((weak, alias("default_handler")));                          
void CAN1_SCE_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void TIM1_BRK_TIM9_IRQHandler(void) __attribute__((weak, alias("default_handler")));        
void TIM1_UP_TIM10_IRQHandler(void) __attribute__((weak, alias("default_handler")));       
void TIM1_TRG_COM_TIM11_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void TIM2_IRQHandler(void) __attribute__((weak, alias("default_handler")));                 
void TIM3_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void TIM4_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));                        
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));                       
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));                          
void SPI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void SPI2_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void USART1_IRQHandler(void) __attribute__((weak, alias("default_handler")));                   
void USART2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USART3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void RTC_Alarm_IRQHandler(void) __attribute__((weak, alias("default_handler")));                 
void OTG_FS_WKUP_IRQHandler(void) __attribute__((weak, alias("default_handler")));                      
void TIM8_BRK_TIM12_IRQHandler(void) __attribute__((weak, alias("default_handler")));        
void TIM8_UP_TIM13_IRQHandler(void) __attribute__((weak, alias("default_handler")));      
void TIM8_TRG_COM_TIM14_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM8_CC_IRQHandler(void) __attribute__((weak, alias("default_handler")));                        
void DMA1_Stream7_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void FMC_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void SDIO_IRQHandler(void) __attribute__((weak, alias("default_handler")));                 
void TIM5_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void SPI3_IRQHandler(void) __attribute__((weak, alias("default_handler")));                   
void UART4_IRQHandler(void) __attribute__((weak, alias("default_handler")));                
void UART5_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void TIM6_DAC_IRQHandler(void) __attribute__((weak, alias("default_handler")));                 
void TIM7_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Stream0_IRQHandler(void) __attribute__((weak, alias("default_handler")));                
void DMA2_Stream1_IRQHandler(void) __attribute__((weak, alias("default_handler")));                 
void DMA2_Stream2_IRQHandler(void) __attribute__((weak, alias("default_handler")));                 
void DMA2_Stream3_IRQHandler(void) __attribute__((weak, alias("default_handler")));               
void DMA2_Stream4_IRQHandler(void) __attribute__((weak, alias("default_handler")));  
void CAN2_TX_IRQHandler(void) __attribute__((weak, alias("default_handler")));                        
void CAN2_RX0_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void CAN2_RX1_IRQHandler(void) __attribute__((weak, alias("default_handler")));                          
void CAN2_SCE_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void OTG_FS_IRQHandler(void) __attribute__((weak, alias("default_handler")));                   
void DMA2_Stream5_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void DMA2_Stream6_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void DMA2_Stream7_IRQHandler(void) __attribute__((weak, alias("default_handler")));                
void USART6_IRQHandler(void) __attribute__((weak, alias("default_handler")));               
void I2C3_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));                          
void I2C3_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));                         
void OTG_HS_EP1_OUT_IRQHandler(void) __attribute__((weak, alias("default_handler")));                
void OTG_HS_EP1_IN_IRQHandler(void) __attribute__((weak, alias("default_handler")));                   
void OTG_HS_WKUP_IRQHandler(void) __attribute__((weak, alias("default_handler")));                      
void OTG_HS_IRQHandler(void) __attribute__((weak, alias("default_handler")));                  
void DCMI_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FPU_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SAI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SAI2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void QUADSPI_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void CEC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPDIF_RX_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FMPI2C1_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FMPI2C1_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));


uint32_t isr_vector[ISR_VECTOR_SIZE_WORDS] __attribute__((section(".isr_vector"))) = {
  STACK_POINTER_INIT_ADDRESS,
  // Cortex-M system exceptions
  (uint32_t)&Reset_Handler,
  (uint32_t)&NMI_Handler,
  (uint32_t)&HardFault_Handler,
  (uint32_t)&MemManage_Handler,
  (uint32_t)&BusFault_Handler,
  (uint32_t)&UsageFault_Handler,
  0,
  0,
  0,
  0,
  (uint32_t)&SVC_Handler,
  (uint32_t)&DebugMon_Handler,
  0,
  (uint32_t)&PendSV_Handler,
  (uint32_t)&SysTick_Handler,
  // STM32F446RE interrupt handlers
  (uint32_t)&WWDG_IRQHandler,                   /* Window WatchDog              */                                        
  (uint32_t)&PVD_IRQHandler,                   /* PVD through EXTI Line detection */                        
  (uint32_t)&TAMP_STAMP_IRQHandler,             /* Tamper and TimeStamps through the EXTI line */            
  (uint32_t)&RTC_WKUP_IRQHandler,              /* RTC Wakeup through the EXTI line */                      
  (uint32_t)&FLASH_IRQHandler,                  /* FLASH                        */                                          
  (uint32_t)&RCC_IRQHandler,                    /* RCC                          */                                            
  (uint32_t)&EXTI0_IRQHandler,                  /* EXTI Line0                   */                        
  (uint32_t)&EXTI1_IRQHandler,                  /* EXTI Line1                   */                          
  (uint32_t)&EXTI2_IRQHandler,                  /* EXTI Line2                   */                          
  (uint32_t)&EXTI3_IRQHandler,                  /* EXTI Line3                   */                          
  (uint32_t)&EXTI4_IRQHandler,                  /* EXTI Line4                   */                          
  (uint32_t)&DMA1_Stream0_IRQHandler,           /* DMA1 Stream 0                */                  
  (uint32_t)&DMA1_Stream1_IRQHandler,           /* DMA1 Stream 1                */                   
  (uint32_t)&DMA1_Stream2_IRQHandler,           /* DMA1 Stream 2                */                   
  (uint32_t)&DMA1_Stream3_IRQHandler,           /* DMA1 Stream 3                */                   
  (uint32_t)&DMA1_Stream4_IRQHandler,           /* DMA1 Stream 4                */                   
  (uint32_t)&DMA1_Stream5_IRQHandler,           /* DMA1 Stream 5                */                   
  (uint32_t)&DMA1_Stream6_IRQHandler,           /* DMA1 Stream 6                */                   
  (uint32_t)&ADC_IRQHandler,                    /* ADC1, ADC2 and ADC3s         */                   
  (uint32_t)&CAN1_TX_IRQHandler,                /* CAN1 TX                      */                         
  (uint32_t)&CAN1_RX0_IRQHandler,               /* CAN1 RX0                     */                          
  (uint32_t)&CAN1_RX1_IRQHandler,               /* CAN1 RX1                     */                          
  (uint32_t)&CAN1_SCE_IRQHandler,               /* CAN1 SCE                     */                          
  (uint32_t)&EXTI9_5_IRQHandler,                /* External Line[9:5]s          */                          
  (uint32_t)&TIM1_BRK_TIM9_IRQHandler,          /* TIM1 Break and TIM9          */         
  (uint32_t)&TIM1_UP_TIM10_IRQHandler,          /* TIM1 Update and TIM10        */         
  (uint32_t)&TIM1_TRG_COM_TIM11_IRQHandler,     /* TIM1 Trigger and Commutation and TIM11 */
  (uint32_t)&TIM1_CC_IRQHandler,                /* TIM1 Capture Compare         */                          
  (uint32_t)&TIM2_IRQHandler,                   /* TIM2                         */                   
  (uint32_t)&TIM3_IRQHandler,                   /* TIM3                         */                   
  (uint32_t)&TIM4_IRQHandler,                   /* TIM4                         */                   
  (uint32_t)&I2C1_EV_IRQHandler,                /* I2C1 Event                   */                          
  (uint32_t)&I2C1_ER_IRQHandler,                /* I2C1 Error                   */                          
  (uint32_t)&I2C2_EV_IRQHandler,                /* I2C2 Event                   */                          
  (uint32_t)&I2C2_ER_IRQHandler,                /* I2C2 Error                   */                            
  (uint32_t)&SPI1_IRQHandler,                   /* SPI1                         */                   
  (uint32_t)&SPI2_IRQHandler,                   /* SPI2                         */                   
  (uint32_t)&USART1_IRQHandler,                 /* USART1                       */                   
  (uint32_t)&USART2_IRQHandler,                 /* USART2                       */                   
  (uint32_t)&USART3_IRQHandler,                 /* USART3                       */                   
  (uint32_t)&EXTI15_10_IRQHandler,              /* External Line[15:10]s        */                          
  (uint32_t)&RTC_Alarm_IRQHandler,              /* RTC Alarm (A and B) through EXTI Line */                 
  (uint32_t)&OTG_FS_WKUP_IRQHandler,            /* USB OTG FS Wakeup through EXTI line */                       
  (uint32_t)&TIM8_BRK_TIM12_IRQHandler,         /* TIM8 Break and TIM12         */         
  (uint32_t)&TIM8_UP_TIM13_IRQHandler,          /* TIM8 Update and TIM13        */         
  (uint32_t)&TIM8_TRG_COM_TIM14_IRQHandler,     /* TIM8 Trigger and Commutation and TIM14 */
  (uint32_t)&TIM8_CC_IRQHandler,                /* TIM8 Capture Compare         */                          
  (uint32_t)&DMA1_Stream7_IRQHandler,           /* DMA1 Stream7                 */                          
  (uint32_t)&FMC_IRQHandler,                    /* FMC                          */                   
  (uint32_t)&SDIO_IRQHandler,                   /* SDIO                         */                   
  (uint32_t)&TIM5_IRQHandler,                   /* TIM5                         */                   
  (uint32_t)&SPI3_IRQHandler,                   /* SPI3                         */                   
  (uint32_t)&UART4_IRQHandler,                  /* UART4                        */                   
  (uint32_t)&UART5_IRQHandler,                  /* UART5                        */                   
  (uint32_t)&TIM6_DAC_IRQHandler,               /* TIM6 and DAC1&2 underrun errors */                   
  (uint32_t)&TIM7_IRQHandler,                   /* TIM7                         */
  (uint32_t)&DMA2_Stream0_IRQHandler,           /* DMA2 Stream 0                */                   
  (uint32_t)&DMA2_Stream1_IRQHandler,           /* DMA2 Stream 1                */                   
  (uint32_t)&DMA2_Stream2_IRQHandler,           /* DMA2 Stream 2                */                   
  (uint32_t)&DMA2_Stream3_IRQHandler,           /* DMA2 Stream 3                */                   
  (uint32_t)&DMA2_Stream4_IRQHandler,           /* DMA2 Stream 4                */                   
  0,                                            /* Reserved                     */                   
  0,                                            /* Reserved                     */                     
  (uint32_t)&CAN2_TX_IRQHandler,                /* CAN2 TX                      */                          
  (uint32_t)&CAN2_RX0_IRQHandler,               /* CAN2 RX0                     */                          
  (uint32_t)&CAN2_RX1_IRQHandler,               /* CAN2 RX1                     */                          
  (uint32_t)&CAN2_SCE_IRQHandler,               /* CAN2 SCE                     */                          
  (uint32_t)&OTG_FS_IRQHandler,                 /* USB OTG FS                   */                   
  (uint32_t)& DMA2_Stream5_IRQHandler,           /* DMA2 Stream 5                */                   
  (uint32_t)&DMA2_Stream6_IRQHandler,           /* DMA2 Stream 6                */                   
  (uint32_t)&DMA2_Stream7_IRQHandler,           /* DMA2 Stream 7                */                   
  (uint32_t)&USART6_IRQHandler,                 /* USART6                       */                    
  (uint32_t)&I2C3_EV_IRQHandler,                /* I2C3 event                   */                          
  (uint32_t)&I2C3_ER_IRQHandler,                /* I2C3 error                   */                          
  (uint32_t)&OTG_HS_EP1_OUT_IRQHandler,         /* USB OTG HS End Point 1 Out   */                   
  (uint32_t)&OTG_HS_EP1_IN_IRQHandler,          /* USB OTG HS End Point 1 In    */                   
  (uint32_t)&OTG_HS_WKUP_IRQHandler,            /* USB OTG HS Wakeup through EXTI */                         
  (uint32_t)&OTG_HS_IRQHandler,                 /* USB OTG HS                   */                   
  (uint32_t)&DCMI_IRQHandler,                   /* DCMI                         */                   
  0,                                 /* Reserved                     */                   
  0,                                 /* Reserved                     */
  (uint32_t)&FPU_IRQHandler,                    /* FPU                          */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  (uint32_t)&SPI4_IRQHandler,                   /* SPI4                         */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  (uint32_t)&SAI1_IRQHandler,                   /* SAI1                         */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  (uint32_t)&SAI2_IRQHandler,                   /* SAI2                         */
  (uint32_t)&QUADSPI_IRQHandler,                /* QuadSPI                      */
  (uint32_t)&CEC_IRQHandler,                    /* CEC                          */
  (uint32_t)&SPDIF_RX_IRQHandler,               /* SPDIF RX                     */
  (uint32_t)&FMPI2C1_EV_IRQHandler,          /* FMPI2C 1 Event               */
  (uint32_t)&FMPI2C1_ER_IRQHandler          /* FMPI2C 1 Error               */
};

extern uint32_t _etext, _sdata, _edata, _sbss, _ebss, _sidata;

void main(void);
// void __libc_init_array();

void Reset_Handler(void)
{
  // Copy .data from FLASH to SRAM
  uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
  uint8_t *flash_data = (uint8_t*) &_sidata; // Data load address (in flash)
  uint8_t *sram_data = (uint8_t*) &_sdata; // Data virtual address (in sram)
  
  for (uint32_t i = 0; i < data_size; i++)
  {
    sram_data[i] = flash_data[i];
  }

  // Zero-fill .bss section in SRAM
  uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  uint8_t *bss = (uint8_t*) &_sbss;

  for (uint32_t i = 0; i < bss_size; i++)
  {
    bss[i] = 0;
  }

  // __libc_init_array();
  main();
}

void default_handler(void)
{
  while(1);
}
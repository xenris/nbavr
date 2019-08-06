#ifndef NBLIB_STM32F103C8_MD_HPP
#define NBLIB_STM32F103C8_MD_HPP

#define NBLIB_CHIP_DEFINED

//------------------------------------------------
// Peripherals base address. (All peripherals.)

#define CHIP_ADDR_PERIPHERALS                                       (0x4000'0000)

//------------------------------------------------
// Peripherals' base address. (Each peripheral.)

#define CHIP_ADDR_TIMER_2                                           (CHIP_ADDR_PERIPHERALS + 0x0000'0000)
#define CHIP_ADDR_TIMER_3                                           (CHIP_ADDR_PERIPHERALS + 0x0000'0400)
#define CHIP_ADDR_TIMER_4                                           (CHIP_ADDR_PERIPHERALS + 0x0000'0800)
#define CHIP_ADDR_TIMER_5                                           (CHIP_ADDR_PERIPHERALS + 0x0000'0C00)
#define CHIP_ADDR_TIMER_6                                           (CHIP_ADDR_PERIPHERALS + 0x0000'1000)
#define CHIP_ADDR_TIMER_7                                           (CHIP_ADDR_PERIPHERALS + 0x0000'1400)
#define CHIP_ADDR_TIMER_12                                          (CHIP_ADDR_PERIPHERALS + 0x0000'1800)
#define CHIP_ADDR_TIMER_13                                          (CHIP_ADDR_PERIPHERALS + 0x0000'1C00)
#define CHIP_ADDR_TIMER_14                                          (CHIP_ADDR_PERIPHERALS + 0x0000'2000)
#define CHIP_ADDR_RTC                                               (CHIP_ADDR_PERIPHERALS + 0x0000'2800)
#define CHIP_ADDR_WWDG                                              (CHIP_ADDR_PERIPHERALS + 0x0000'2C00)
#define CHIP_ADDR_IWDG                                              (CHIP_ADDR_PERIPHERALS + 0x0000'3000)
#define CHIP_ADDR_SPI_2                                             (CHIP_ADDR_PERIPHERALS + 0x0000'3800)
#define CHIP_ADDR_SPI_3                                             (CHIP_ADDR_PERIPHERALS + 0x0000'3C00)
#define CHIP_ADDR_USART_2                                           (CHIP_ADDR_PERIPHERALS + 0x0000'4400)
#define CHIP_ADDR_USART_3                                           (CHIP_ADDR_PERIPHERALS + 0x0000'4800)
#define CHIP_ADDR_USART_4                                           (CHIP_ADDR_PERIPHERALS + 0x0000'4C00)
#define CHIP_ADDR_USART_5                                           (CHIP_ADDR_PERIPHERALS + 0x0000'5000)
#define CHIP_ADDR_I2C_1                                             (CHIP_ADDR_PERIPHERALS + 0x0000'5400)
#define CHIP_ADDR_I2C_2                                             (CHIP_ADDR_PERIPHERALS + 0x0000'5800)
#define CHIP_ADDR_USB                                               (CHIP_ADDR_PERIPHERALS + 0x0000'5C00)
#define CHIP_ADDR_USB_CAN_SRAM                                      (CHIP_ADDR_PERIPHERALS + 0x0000'6000)
#define CHIP_ADDR_BX_CAN_1_SRAM                                     (CHIP_ADDR_PERIPHERALS + 0x0000'6400)
#define CHIP_ADDR_BX_CAN_2_SRAM                                     (CHIP_ADDR_PERIPHERALS + 0x0000'6800)
#define CHIP_ADDR_BKP                                               (CHIP_ADDR_PERIPHERALS + 0x0000'6C00)
#define CHIP_ADDR_PWR                                               (CHIP_ADDR_PERIPHERALS + 0x0000'7000)
#define CHIP_ADDR_DAC                                               (CHIP_ADDR_PERIPHERALS + 0x0000'7400)
#define CHIP_ADDR_AFIO                                              (CHIP_ADDR_PERIPHERALS + 0x0001'0000)
#define CHIP_ADDR_EXTI                                              (CHIP_ADDR_PERIPHERALS + 0x0001'0400)
#define CHIP_ADDR_PORT_A                                            (CHIP_ADDR_PERIPHERALS + 0x0001'0800)
#define CHIP_ADDR_PORT_B                                            (CHIP_ADDR_PERIPHERALS + 0x0001'0C00)
#define CHIP_ADDR_PORT_C                                            (CHIP_ADDR_PERIPHERALS + 0x0001'1000)
#define CHIP_ADDR_PORT_D                                            (CHIP_ADDR_PERIPHERALS + 0x0001'1400)
#define CHIP_ADDR_PORT_E                                            (CHIP_ADDR_PERIPHERALS + 0x0001'1800)
#define CHIP_ADDR_PORT_F                                            (CHIP_ADDR_PERIPHERALS + 0x0001'1C00)
#define CHIP_ADDR_PORT_G                                            (CHIP_ADDR_PERIPHERALS + 0x0001'2000)
#define CHIP_ADDR_ADC_1                                             (CHIP_ADDR_PERIPHERALS + 0x0001'2400)
#define CHIP_ADDR_ADC_2                                             (CHIP_ADDR_PERIPHERALS + 0x0001'2800)
#define CHIP_ADDR_TIMER_1                                           (CHIP_ADDR_PERIPHERALS + 0x0001'2C00)
#define CHIP_ADDR_SPI_1                                             (CHIP_ADDR_PERIPHERALS + 0x0001'3000)
#define CHIP_ADDR_TIMER_8                                           (CHIP_ADDR_PERIPHERALS + 0x0001'3400)
#define CHIP_ADDR_USART_1                                           (CHIP_ADDR_PERIPHERALS + 0x0001'3800)
#define CHIP_ADDR_ADC_3                                             (CHIP_ADDR_PERIPHERALS + 0x0001'3C00)
#define CHIP_ADDR_TIMER_9                                           (CHIP_ADDR_PERIPHERALS + 0x0001'4C00)
#define CHIP_ADDR_TIMER_10                                          (CHIP_ADDR_PERIPHERALS + 0x0001'5000)
#define CHIP_ADDR_TIMER_11                                          (CHIP_ADDR_PERIPHERALS + 0x0001'5400)
#define CHIP_ADDR_SDIO                                              (CHIP_ADDR_PERIPHERALS + 0x0001'8000)
#define CHIP_ADDR_DMA_1                                             (CHIP_ADDR_PERIPHERALS + 0x0002'0000)
#define CHIP_ADDR_DMA_2                                             (CHIP_ADDR_PERIPHERALS + 0x0002'0400)
#define CHIP_ADDR_RCC                                               (CHIP_ADDR_PERIPHERALS + 0x0002'1000)
#define CHIP_ADDR_FLASH                                             (CHIP_ADDR_PERIPHERALS + 0x0002'2000)
#define CHIP_ADDR_CRC                                               (CHIP_ADDR_PERIPHERALS + 0x0002'3000)
#define CHIP_ADDR_ETHERNET                                          (CHIP_ADDR_PERIPHERALS + 0x0002'8000)
#define CHIP_ADDR_USB_OTG                                           (CHIP_ADDR_PERIPHERALS + 0x1000'0000)
#define CHIP_ADDR_FSMC                                              (CHIP_ADDR_PERIPHERALS + 0x6000'0000)

#define CHIP_ADDR_OFFSET_CRL                                        0x00
#define CHIP_ADDR_OFFSET_CRH                                        0x04
#define CHIP_ADDR_OFFSET_IDR                                        0x08
// TODO ...

#define CHIP_REG_PORT_A_CRL_ADDR                                    (CHIP_ADDR_PORT_A + CHIP_ADDR_OFFSET_CRL)
#define CHIP_REG_PORT_A_CRL_TYPE                                    uint32_t
#define CHIP_REG_PORT_A_CRH_ADDR                                    (CHIP_ADDR_PORT_A + CHIP_ADDR_OFFSET_CRH)
#define CHIP_REG_PORT_A_CRH_TYPE                                    uint32_t
#define CHIP_REG_PORT_A_IDR_ADDR                                    (CHIP_ADDR_PORT_A + CHIP_ADDR_OFFSET_IDR)
#define CHIP_REG_PORT_A_IDR_TYPE                                    uint16_t // FIXME Should this be uint32_t?
#define CHIP_REG_PORT_A_ODR_ADDR                                    (CHIP_ADDR_PORT_A + 0x0C)
#define CHIP_REG_PORT_A_ODR_TYPE                                    uint16_t
#define CHIP_REG_PORT_A_BSRR_ADDR                                   (CHIP_ADDR_PORT_A + 0x10)
#define CHIP_REG_PORT_A_BSRR_TYPE                                   uint32_t
#define CHIP_REG_PORT_A_BSRR_SET_ADDR                               (CHIP_ADDR_PORT_A + 0x10)
#define CHIP_REG_PORT_A_BSRR_SET_TYPE                               uint16_t
#define CHIP_REG_PORT_A_BSRR_CLEAR_ADDR                             (CHIP_ADDR_PORT_A + 0x12)
#define CHIP_REG_PORT_A_BSRR_CLEAR_TYPE                             uint16_t
#define CHIP_REG_PORT_A_BRR_ADDR                                    (CHIP_ADDR_PORT_A + 0x14)
#define CHIP_REG_PORT_A_BRR_TYPE                                    uint16_t
#define CHIP_REG_PORT_A_LCKR_ADDR                                   (CHIP_ADDR_PORT_A + 0x18)
#define CHIP_REG_PORT_A_LCKR_TYPE                                   uint32_t

#define CHIP_REG_PORT_B_CRL_ADDR                                    (CHIP_ADDR_PORT_B + CHIP_ADDR_OFFSET_CRL)
#define CHIP_REG_PORT_B_CRL_TYPE                                    uint32_t
#define CHIP_REG_PORT_B_CRH_ADDR                                    (CHIP_ADDR_PORT_B + CHIP_ADDR_OFFSET_CRH)
#define CHIP_REG_PORT_B_CRH_TYPE                                    uint32_t
#define CHIP_REG_PORT_B_IDR_ADDR                                    (CHIP_ADDR_PORT_B + CHIP_ADDR_OFFSET_IDR)
#define CHIP_REG_PORT_B_IDR_TYPE                                    uint16_t
#define CHIP_REG_PORT_B_ODR_ADDR                                    (CHIP_ADDR_PORT_B + 0x0C)
#define CHIP_REG_PORT_B_ODR_TYPE                                    uint16_t
#define CHIP_REG_PORT_B_BSRR_ADDR                                   (CHIP_ADDR_PORT_B + 0x10)
#define CHIP_REG_PORT_B_BSRR_TYPE                                   uint32_t
#define CHIP_REG_PORT_B_BSRR_SET_ADDR                               (CHIP_ADDR_PORT_B + 0x10)
#define CHIP_REG_PORT_B_BSRR_SET_TYPE                               uint16_t
#define CHIP_REG_PORT_B_BSRR_CLEAR_ADDR                             (CHIP_ADDR_PORT_B + 0x12)
#define CHIP_REG_PORT_B_BSRR_CLEAR_TYPE                             uint16_t
#define CHIP_REG_PORT_B_BRR_ADDR                                    (CHIP_ADDR_PORT_B + 0x14)
#define CHIP_REG_PORT_B_BRR_TYPE                                    uint16_t
#define CHIP_REG_PORT_B_LCKR_ADDR                                   (CHIP_ADDR_PORT_B + 0x18)
#define CHIP_REG_PORT_B_LCKR_TYPE                                   uint32_t

#define CHIP_REG_PORT_C_CRL_ADDR                                    (CHIP_ADDR_PORT_C + CHIP_ADDR_OFFSET_CRL)
#define CHIP_REG_PORT_C_CRL_TYPE                                    uint32_t
#define CHIP_REG_PORT_C_CRH_ADDR                                    (CHIP_ADDR_PORT_C + CHIP_ADDR_OFFSET_CRH)
#define CHIP_REG_PORT_C_CRH_TYPE                                    uint32_t
#define CHIP_REG_PORT_C_IDR_ADDR                                    (CHIP_ADDR_PORT_C + CHIP_ADDR_OFFSET_IDR)
#define CHIP_REG_PORT_C_IDR_TYPE                                    uint16_t
#define CHIP_REG_PORT_C_ODR_ADDR                                    (CHIP_ADDR_PORT_C + 0x0C)
#define CHIP_REG_PORT_C_ODR_TYPE                                    uint16_t
#define CHIP_REG_PORT_C_BSRR_ADDR                                   (CHIP_ADDR_PORT_C + 0x10)
#define CHIP_REG_PORT_C_BSRR_TYPE                                   uint32_t
#define CHIP_REG_PORT_C_BSRR_SET_ADDR                               (CHIP_ADDR_PORT_C + 0x10)
#define CHIP_REG_PORT_C_BSRR_SET_TYPE                               uint16_t
#define CHIP_REG_PORT_C_BSRR_CLEAR_ADDR                             (CHIP_ADDR_PORT_C + 0x12)
#define CHIP_REG_PORT_C_BSRR_CLEAR_TYPE                             uint16_t
#define CHIP_REG_PORT_C_BRR_ADDR                                    (CHIP_ADDR_PORT_C + 0x14)
#define CHIP_REG_PORT_C_BRR_TYPE                                    uint16_t
#define CHIP_REG_PORT_C_LCKR_ADDR                                   (CHIP_ADDR_PORT_C + 0x18)
#define CHIP_REG_PORT_C_LCKR_TYPE                                   uint32_t

#define CHIP_ADDR_OFFSET_TIMX_CR1                                   0x00
#define CHIP_ADDR_OFFSET_TIMX_CR2                                   0x04
#define CHIP_ADDR_OFFSET_TIMX_SMCR                                  0x08
#define CHIP_ADDR_OFFSET_TIMX_DIER                                  0x0C
#define CHIP_ADDR_OFFSET_TIMX_SR                                    0x10
#define CHIP_ADDR_OFFSET_TIMX_EGR                                   0x14
#define CHIP_ADDR_OFFSET_TIMX_CCMR1                                 0x18
#define CHIP_ADDR_OFFSET_TIMX_CCMR2                                 0x1C
#define CHIP_ADDR_OFFSET_TIMX_CCER                                  0x20
#define CHIP_ADDR_OFFSET_TIMX_CNT                                   0x24
#define CHIP_ADDR_OFFSET_TIMX_PSC                                   0x28
#define CHIP_ADDR_OFFSET_TIMX_ARR                                   0x2C
#define CHIP_ADDR_OFFSET_TIMX_RCR                                   0x30
#define CHIP_ADDR_OFFSET_TIMX_CCR1                                  0x34
#define CHIP_ADDR_OFFSET_TIMX_CCR2                                  0x38
#define CHIP_ADDR_OFFSET_TIMX_CCR3                                  0x3C
#define CHIP_ADDR_OFFSET_TIMX_CCR4                                  0x40
#define CHIP_ADDR_OFFSET_TIMX_BDTR                                  0x44
#define CHIP_ADDR_OFFSET_TIMX_DCR                                   0x48
#define CHIP_ADDR_OFFSET_TIMX_DMAR                                  0x4C

#define CHIP_ADDR_OFFSET_USART_DR                                   0x04
#define CHIP_ADDR_OFFSET_USART_BRR                                  0x08

#define CHIP_REG_TIM1_CR1_ADDR                                      (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_CR1)
#define CHIP_REG_TIM1_CR1_TYPE                                      uint32_t
#define CHIP_REG_TIM1_CR2_ADDR                                      (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_CR2)
#define CHIP_REG_TIM1_CR2_TYPE                                      uint32_t
#define CHIP_REG_TIM1_SMCR_ADDR                                     (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_SMCR)
#define CHIP_REG_TIM1_SMCR_TYPE                                     uint32_t
#define CHIP_REG_TIM1_DIER_ADDR                                     (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_DIER)
#define CHIP_REG_TIM1_DIER_TYPE                                     uint32_t
#define CHIP_REG_TIM1_SR_ADDR                                       (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_SR)
#define CHIP_REG_TIM1_SR_TYPE                                       uint32_t
#define CHIP_REG_TIM1_EGR_ADDR                                      (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_EGR)
#define CHIP_REG_TIM1_EGR_TYPE                                      uint32_t
#define CHIP_REG_TIM1_CCMR1_ADDR                                    (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_CCMR1)
#define CHIP_REG_TIM1_CCMR1_TYPE                                    uint32_t
#define CHIP_REG_TIM1_CCMR2_ADDR                                    (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_CCMR2)
#define CHIP_REG_TIM1_CCMR2_TYPE                                    uint32_t
#define CHIP_REG_TIM1_CCER_ADDR                                     (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_CCER)
#define CHIP_REG_TIM1_CCER_TYPE                                     uint32_t
#define CHIP_REG_TIM1_CNT_ADDR                                      (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_CNT)
#define CHIP_REG_TIM1_CNT_TYPE                                      uint32_t
#define CHIP_REG_TIM1_PSC_ADDR                                      (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_PSC)
#define CHIP_REG_TIM1_PSC_TYPE                                      uint32_t
#define CHIP_REG_TIM1_ARR_ADDR                                      (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_ARR)
#define CHIP_REG_TIM1_ARR_TYPE                                      uint32_t
#define CHIP_REG_TIM1_RCR_ADDR                                      (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_RCR)
#define CHIP_REG_TIM1_RCR_TYPE                                      uint32_t
#define CHIP_REG_TIM1_CCR1_ADDR                                     (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_CCR1)
#define CHIP_REG_TIM1_CCR1_TYPE                                     uint32_t
#define CHIP_REG_TIM1_CCR2_ADDR                                     (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_CCR2)
#define CHIP_REG_TIM1_CCR2_TYPE                                     uint32_t
#define CHIP_REG_TIM1_CCR3_ADDR                                     (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_CCR3)
#define CHIP_REG_TIM1_CCR3_TYPE                                     uint32_t
#define CHIP_REG_TIM1_CCR4_ADDR                                     (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_CCR4)
#define CHIP_REG_TIM1_CCR4_TYPE                                     uint32_t
#define CHIP_REG_TIM1_BDTR_ADDR                                     (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_BDTR)
#define CHIP_REG_TIM1_BDTR_TYPE                                     uint32_t
#define CHIP_REG_TIM1_DCR_ADDR                                      (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_DCR)
#define CHIP_REG_TIM1_DCR_TYPE                                      uint32_t
#define CHIP_REG_TIM1_DMAR_ADDR                                     (CHIP_ADDR_TIMER_1 + CHIP_ADDR_OFFSET_TIMX_DMAR)
#define CHIP_REG_TIM1_DMAR_TYPE                                     uint32_t

#define CHIP_REG_TIM2_CR1_ADDR                                      (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_CR1)
#define CHIP_REG_TIM2_CR1_TYPE                                      uint32_t
#define CHIP_REG_TIM2_CR2_ADDR                                      (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_CR2)
#define CHIP_REG_TIM2_CR2_TYPE                                      uint32_t
#define CHIP_REG_TIM2_SMCR_ADDR                                     (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_SMCR)
#define CHIP_REG_TIM2_SMCR_TYPE                                     uint32_t
#define CHIP_REG_TIM2_DIER_ADDR                                     (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_DIER)
#define CHIP_REG_TIM2_DIER_TYPE                                     uint32_t
#define CHIP_REG_TIM2_SR_ADDR                                       (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_SR)
#define CHIP_REG_TIM2_SR_TYPE                                       uint32_t
#define CHIP_REG_TIM2_EGR_ADDR                                      (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_EGR)
#define CHIP_REG_TIM2_EGR_TYPE                                      uint32_t
#define CHIP_REG_TIM2_CCMR1_ADDR                                    (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_CCMR1)
#define CHIP_REG_TIM2_CCMR1_TYPE                                    uint32_t
#define CHIP_REG_TIM2_CCMR2_ADDR                                    (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_CCMR2)
#define CHIP_REG_TIM2_CCMR2_TYPE                                    uint32_t
#define CHIP_REG_TIM2_CCER_ADDR                                     (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_CCER)
#define CHIP_REG_TIM2_CCER_TYPE                                     uint32_t
#define CHIP_REG_TIM2_CNT_ADDR                                      (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_CNT)
#define CHIP_REG_TIM2_CNT_TYPE                                      uint32_t
#define CHIP_REG_TIM2_PSC_ADDR                                      (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_PSC)
#define CHIP_REG_TIM2_PSC_TYPE                                      uint32_t
#define CHIP_REG_TIM2_ARR_ADDR                                      (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_ARR)
#define CHIP_REG_TIM2_ARR_TYPE                                      uint32_t
#define CHIP_REG_TIM2_CCR1_ADDR                                     (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_CCR1)
#define CHIP_REG_TIM2_CCR1_TYPE                                     uint32_t
#define CHIP_REG_TIM2_CCR2_ADDR                                     (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_CCR2)
#define CHIP_REG_TIM2_CCR2_TYPE                                     uint32_t
#define CHIP_REG_TIM2_CCR3_ADDR                                     (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_CCR3)
#define CHIP_REG_TIM2_CCR3_TYPE                                     uint32_t
#define CHIP_REG_TIM2_CCR4_ADDR                                     (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_CCR4)
#define CHIP_REG_TIM2_CCR4_TYPE                                     uint32_t
#define CHIP_REG_TIM2_DCR_ADDR                                      (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_DCR)
#define CHIP_REG_TIM2_DCR_TYPE                                      uint32_t
#define CHIP_REG_TIM2_DMAR_ADDR                                     (CHIP_ADDR_TIMER_2 + CHIP_ADDR_OFFSET_TIMX_DMAR)
#define CHIP_REG_TIM2_DMAR_TYPE                                     uint32_t

#define CHIP_REG_USART_1_BRR_ADDR                                   (CHIP_ADDR_USART_1 + CHIP_ADDR_OFFSET_USART_BRR)
#define CHIP_REG_USART_1_BRR_TYPE                                   uint16_t
#define CHIP_REG_USART_1_DR_ADDR                                    (CHIP_ADDR_USART_1 + CHIP_ADDR_OFFSET_USART_DR)
#define CHIP_REG_USART_1_DR_TYPE                                    uint8_t

#define CHIP_VECT_RESET                                             1
#define CHIP_VECT_NMI
#define CHIP_VECT_HARD_FAULT
#define CHIP_VECT_MEM_MANAGE
#define CHIP_VECT_BUS_FAULT
#define CHIP_VECT_USAGE_FAULT
#define CHIP_VECT_SV_CALL
#define CHIP_VECT_DEBUG_MONITOR
#define CHIP_VECT_PEND_SV
#define CHIP_VECT_SYS_TICK
#define CHIP_VECT_WWDG
#define CHIP_VECT_PVD
#define CHIP_VECT_TAMPER
#define CHIP_VECT_RTC
#define CHIP_VECT_FLASH
#define CHIP_VECT_RCC
#define CHIP_VECT_EXT_INT_0
#define CHIP_VECT_EXT_INT_1
#define CHIP_VECT_EXT_INT_2
#define CHIP_VECT_EXT_INT_3
#define CHIP_VECT_EXT_INT_4
#define CHIP_VECT_DMA_1_CHANNEL_1
#define CHIP_VECT_DMA_1_CHANNEL_2
#define CHIP_VECT_DMA_1_CHANNEL_3
#define CHIP_VECT_DMA_1_CHANNEL_4
#define CHIP_VECT_DMA_1_CHANNEL_5
#define CHIP_VECT_DMA_1_CHANNEL_6
#define CHIP_VECT_DMA_1_CHANNEL_7
#define CHIP_VECT_ADC_1_2
#define CHIP_VECT_
#define CHIP_VECT_
#define CHIP_VECT_
#define CHIP_VECT_

//------------------------------------------------

#define CHIP_RAM_SIZE                                               2048

//------------------------------------------------
// RCC.

#define CHIP_REG_APB2_ADDR                                          (CHIP_ADDR_RCC + 0x18)
#define CHIP_REG_APB2_TYPE                                          uint32_t

//------------------------------------------------
// IO Ports.

#define CHIP_PORT_MIN                                               A
#define CHIP_PORT_MAX                                               C

#define CHIP_PORT_A                                                 true
#define CHIP_PORT_A_CLOCK_ENABLE_REG                                CHIP_REG_APB2
#define CHIP_PORT_A_CLOCK_ENABLE_BIT                                2
#define CHIP_PORT_A_OUTPUT_REG                                      CHIP_REG_PORT_A_ODR
#define CHIP_PORT_A_SET_OUTPUTS_REG                                 CHIP_REG_PORT_A_BSRR_SET
#define CHIP_PORT_A_CLEAR_OUTPUTS_REG                               CHIP_REG_PORT_A_BSRR_CLEAR
#define CHIP_PORT_A_INPUT_REG                                       CHIP_REG_PORT_A_IDR

#define CHIP_PORT_B                                                 true
#define CHIP_PORT_B_CLOCK_ENABLE_REG                                CHIP_REG_APB2
#define CHIP_PORT_B_CLOCK_ENABLE_BIT                                3
#define CHIP_PORT_B_OUTPUT_REG                                      CHIP_REG_PORT_B_ODR
#define CHIP_PORT_B_SET_OUTPUTS_REG                                 CHIP_REG_PORT_B_BSRR_SET
#define CHIP_PORT_B_CLEAR_OUTPUTS_REG                               CHIP_REG_PORT_B_BSRR_CLEAR
#define CHIP_PORT_B_INPUT_REG                                       CHIP_REG_PORT_B_IDR

#define CHIP_PORT_C                                                 true
#define CHIP_PORT_C_CLOCK_ENABLE_REG                                CHIP_REG_APB2
#define CHIP_PORT_C_CLOCK_ENABLE_BIT                                4
#define CHIP_PORT_C_OUTPUT_REG                                      CHIP_REG_PORT_C_ODR
#define CHIP_PORT_C_SET_OUTPUTS_REG                                 CHIP_REG_PORT_C_BSRR_SET
#define CHIP_PORT_C_CLEAR_OUTPUTS_REG                               CHIP_REG_PORT_C_BSRR_CLEAR
#define CHIP_PORT_C_INPUT_REG                                       CHIP_REG_PORT_C_IDR

//------------------------------------------------
// IO Pins.

#define CHIP_PIN_MODE_INPUT_ANALOG_ID                               0b0000
#define CHIP_PIN_MODE_INPUT_FLOATING_ID                             0b0100
#define CHIP_PIN_MODE_INPUT_PULLUPDOWN_ID                           0b1000

#define CHIP_PIN_MODE_OUTPUT_GENERAL_PUSH_PULL_10MHZ_ID             0b0001
#define CHIP_PIN_MODE_OUTPUT_GENERAL_OPEN_DRAIN_10MHZ_ID            0b0101
#define CHIP_PIN_MODE_OUTPUT_ALTERNATE_PUSH_PULL_10MHZ_ID           0b1001
#define CHIP_PIN_MODE_OUTPUT_ALTERNATE_OPEN_DRAIN_10MHZ_ID          0b1101

#define CHIP_PIN_MODE_OUTPUT_GENERAL_PUSH_PULL_2MHZ_ID              0b0010
#define CHIP_PIN_MODE_OUTPUT_GENERAL_OPEN_DRAIN_2MHZ_ID             0b0110
#define CHIP_PIN_MODE_OUTPUT_ALTERNATE_PUSH_PULL_2MHZ_ID            0b1010
#define CHIP_PIN_MODE_OUTPUT_ALTERNATE_OPEN_DRAIN_2MHZ_ID           0b1110

#define CHIP_PIN_MODE_OUTPUT_GENERAL_PUSH_PULL_50MHZ_ID             0b0011
#define CHIP_PIN_MODE_OUTPUT_GENERAL_OPEN_DRAIN_50MHZ_ID            0b0111
#define CHIP_PIN_MODE_OUTPUT_ALTERNATE_PUSH_PULL_50MHZ_ID           0b1011
#define CHIP_PIN_MODE_OUTPUT_ALTERNATE_OPEN_DRAIN_50MHZ_ID          0b1111

#define CHIP_PIN_A0                                                 true
#define CHIP_PIN_A0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_A0_MODE_BIT_0_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A0_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_A0_MODE_BIT_1_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A0_MODE_BIT_2_BIT                                  2
#define CHIP_PIN_A0_MODE_BIT_2_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A0_MODE_BIT_3_BIT                                  3
#define CHIP_PIN_A0_MODE_BIT_3_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_A0_INPUT_BIT_0_REG                                 CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_A0_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A1                                                 true
#define CHIP_PIN_A1_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_A1_MODE_BIT_0_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A1_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_A1_MODE_BIT_1_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A1_MODE_BIT_2_BIT                                  6
#define CHIP_PIN_A1_MODE_BIT_2_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A1_MODE_BIT_3_BIT                                  7
#define CHIP_PIN_A1_MODE_BIT_3_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_A1_INPUT_BIT_0_REG                                 CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_A1_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A2                                                 true
#define CHIP_PIN_A2_MODE_BIT_0_BIT                                  8
#define CHIP_PIN_A2_MODE_BIT_0_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A2_MODE_BIT_1_BIT                                  9
#define CHIP_PIN_A2_MODE_BIT_1_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A2_MODE_BIT_2_BIT                                  10
#define CHIP_PIN_A2_MODE_BIT_2_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A2_MODE_BIT_3_BIT                                  11
#define CHIP_PIN_A2_MODE_BIT_3_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_A2_INPUT_BIT_0_REG                                 CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_A2_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A3                                                 true
#define CHIP_PIN_A3_MODE_BIT_0_BIT                                  12
#define CHIP_PIN_A3_MODE_BIT_0_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A3_MODE_BIT_1_BIT                                  13
#define CHIP_PIN_A3_MODE_BIT_1_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A3_MODE_BIT_2_BIT                                  14
#define CHIP_PIN_A3_MODE_BIT_2_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A3_MODE_BIT_3_BIT                                  15
#define CHIP_PIN_A3_MODE_BIT_3_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_A3_INPUT_BIT_0_REG                                 CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_A3_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A4                                                 true
#define CHIP_PIN_A4_MODE_BIT_0_BIT                                  16
#define CHIP_PIN_A4_MODE_BIT_0_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A4_MODE_BIT_1_BIT                                  17
#define CHIP_PIN_A4_MODE_BIT_1_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A4_MODE_BIT_2_BIT                                  18
#define CHIP_PIN_A4_MODE_BIT_2_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A4_MODE_BIT_3_BIT                                  19
#define CHIP_PIN_A4_MODE_BIT_3_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_A4_INPUT_BIT_0_REG                                 CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_A4_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A5                                                 true
#define CHIP_PIN_A5_MODE_BIT_0_BIT                                  20
#define CHIP_PIN_A5_MODE_BIT_0_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A5_MODE_BIT_1_BIT                                  21
#define CHIP_PIN_A5_MODE_BIT_1_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A5_MODE_BIT_2_BIT                                  22
#define CHIP_PIN_A5_MODE_BIT_2_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A5_MODE_BIT_3_BIT                                  23
#define CHIP_PIN_A5_MODE_BIT_3_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_A5_INPUT_BIT_0_REG                                 CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_A5_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A6                                                 true
#define CHIP_PIN_A6_MODE_BIT_0_BIT                                  24
#define CHIP_PIN_A6_MODE_BIT_0_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A6_MODE_BIT_1_BIT                                  25
#define CHIP_PIN_A6_MODE_BIT_1_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A6_MODE_BIT_2_BIT                                  26
#define CHIP_PIN_A6_MODE_BIT_2_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A6_MODE_BIT_3_BIT                                  27
#define CHIP_PIN_A6_MODE_BIT_3_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_A6_INPUT_BIT_0_REG                                 CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_A6_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A7                                                 true
#define CHIP_PIN_A7_MODE_BIT_0_BIT                                  28
#define CHIP_PIN_A7_MODE_BIT_0_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A7_MODE_BIT_1_BIT                                  29
#define CHIP_PIN_A7_MODE_BIT_1_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A7_MODE_BIT_2_BIT                                  30
#define CHIP_PIN_A7_MODE_BIT_2_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A7_MODE_BIT_3_BIT                                  31
#define CHIP_PIN_A7_MODE_BIT_3_REG                                  CHIP_REG_PORT_A_CRL
#define CHIP_PIN_A7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_A7_INPUT_BIT_0_REG                                 CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_A7_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A8                                                 true
#define CHIP_PIN_A8_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_A8_MODE_BIT_0_REG                                  CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A8_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_A8_MODE_BIT_1_REG                                  CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A8_MODE_BIT_2_BIT                                  2
#define CHIP_PIN_A8_MODE_BIT_2_REG                                  CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A8_MODE_BIT_3_BIT                                  3
#define CHIP_PIN_A8_MODE_BIT_3_REG                                  CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A8_INPUT_BIT_0_BIT                                 8
#define CHIP_PIN_A8_INPUT_BIT_0_REG                                 CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A8_OUTPUT_BIT_0_BIT                                8
#define CHIP_PIN_A8_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A9                                                 true
#define CHIP_PIN_A9_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_A9_MODE_BIT_0_REG                                  CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A9_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_A9_MODE_BIT_1_REG                                  CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A9_MODE_BIT_2_BIT                                  6
#define CHIP_PIN_A9_MODE_BIT_2_REG                                  CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A9_MODE_BIT_3_BIT                                  7
#define CHIP_PIN_A9_MODE_BIT_3_REG                                  CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A9_INPUT_BIT_0_BIT                                 9
#define CHIP_PIN_A9_INPUT_BIT_0_REG                                 CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A9_OUTPUT_BIT_0_BIT                                9
#define CHIP_PIN_A9_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A10                                                true
#define CHIP_PIN_A10_MODE_BIT_0_BIT                                 8
#define CHIP_PIN_A10_MODE_BIT_0_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A10_MODE_BIT_1_BIT                                 9
#define CHIP_PIN_A10_MODE_BIT_1_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A10_MODE_BIT_2_BIT                                 10
#define CHIP_PIN_A10_MODE_BIT_2_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A10_MODE_BIT_3_BIT                                 11
#define CHIP_PIN_A10_MODE_BIT_3_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A10_INPUT_BIT_0_BIT                                0
#define CHIP_PIN_A10_INPUT_BIT_0_REG                                CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A10_OUTPUT_BIT_0_BIT                               0
#define CHIP_PIN_A10_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A11                                                true
#define CHIP_PIN_A11_MODE_BIT_0_BIT                                 12
#define CHIP_PIN_A11_MODE_BIT_0_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A11_MODE_BIT_1_BIT                                 13
#define CHIP_PIN_A11_MODE_BIT_1_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A11_MODE_BIT_2_BIT                                 14
#define CHIP_PIN_A11_MODE_BIT_2_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A11_MODE_BIT_3_BIT                                 15
#define CHIP_PIN_A11_MODE_BIT_3_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A11_INPUT_BIT_0_BIT                                11
#define CHIP_PIN_A11_INPUT_BIT_0_REG                                CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A11_OUTPUT_BIT_0_BIT                               11
#define CHIP_PIN_A11_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A12                                                true
#define CHIP_PIN_A12_MODE_BIT_0_BIT                                 16
#define CHIP_PIN_A12_MODE_BIT_0_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A12_MODE_BIT_1_BIT                                 17
#define CHIP_PIN_A12_MODE_BIT_1_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A12_MODE_BIT_2_BIT                                 18
#define CHIP_PIN_A12_MODE_BIT_2_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A12_MODE_BIT_3_BIT                                 19
#define CHIP_PIN_A12_MODE_BIT_3_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A12_INPUT_BIT_0_BIT                                12
#define CHIP_PIN_A12_INPUT_BIT_0_REG                                CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A12_OUTPUT_BIT_0_BIT                               12
#define CHIP_PIN_A12_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A13                                                true
#define CHIP_PIN_A13_MODE_BIT_0_BIT                                 20
#define CHIP_PIN_A13_MODE_BIT_0_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A13_MODE_BIT_1_BIT                                 21
#define CHIP_PIN_A13_MODE_BIT_1_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A13_MODE_BIT_2_BIT                                 22
#define CHIP_PIN_A13_MODE_BIT_2_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A13_MODE_BIT_3_BIT                                 23
#define CHIP_PIN_A13_MODE_BIT_3_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A13_INPUT_BIT_0_BIT                                13
#define CHIP_PIN_A13_INPUT_BIT_0_REG                                CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A13_OUTPUT_BIT_0_BIT                               13
#define CHIP_PIN_A13_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A14                                                true
#define CHIP_PIN_A14_MODE_BIT_0_BIT                                 24
#define CHIP_PIN_A14_MODE_BIT_0_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A14_MODE_BIT_1_BIT                                 25
#define CHIP_PIN_A14_MODE_BIT_1_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A14_MODE_BIT_2_BIT                                 26
#define CHIP_PIN_A14_MODE_BIT_2_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A14_MODE_BIT_3_BIT                                 27
#define CHIP_PIN_A14_MODE_BIT_3_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A14_INPUT_BIT_0_BIT                                14
#define CHIP_PIN_A14_INPUT_BIT_0_REG                                CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A14_OUTPUT_BIT_0_BIT                               14
#define CHIP_PIN_A14_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_A_ODR

#define CHIP_PIN_A15                                                true
#define CHIP_PIN_A15_MODE_BIT_0_BIT                                 28
#define CHIP_PIN_A15_MODE_BIT_0_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A15_MODE_BIT_1_BIT                                 29
#define CHIP_PIN_A15_MODE_BIT_1_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A15_MODE_BIT_2_BIT                                 30
#define CHIP_PIN_A15_MODE_BIT_2_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A15_MODE_BIT_3_BIT                                 31
#define CHIP_PIN_A15_MODE_BIT_3_REG                                 CHIP_REG_PORT_A_CRH
#define CHIP_PIN_A15_INPUT_BIT_0_BIT                                15
#define CHIP_PIN_A15_INPUT_BIT_0_REG                                CHIP_REG_PORT_A_IDR
#define CHIP_PIN_A15_OUTPUT_BIT_0_BIT                               15
#define CHIP_PIN_A15_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_A_ODR

#define CHIP_PIN_B0                                                 true
#define CHIP_PIN_B0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_B0_MODE_BIT_0_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B0_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_B0_MODE_BIT_1_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B0_MODE_BIT_2_BIT                                  2
#define CHIP_PIN_B0_MODE_BIT_2_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B0_MODE_BIT_3_BIT                                  3
#define CHIP_PIN_B0_MODE_BIT_3_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_B0_INPUT_BIT_0_REG                                 CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_B0_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B1                                                 true
#define CHIP_PIN_B1_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_B1_MODE_BIT_0_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B1_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_B1_MODE_BIT_1_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B1_MODE_BIT_2_BIT                                  6
#define CHIP_PIN_B1_MODE_BIT_2_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B1_MODE_BIT_3_BIT                                  7
#define CHIP_PIN_B1_MODE_BIT_3_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_B1_INPUT_BIT_0_REG                                 CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_B1_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B2                                                 true
#define CHIP_PIN_B2_MODE_BIT_0_BIT                                  8
#define CHIP_PIN_B2_MODE_BIT_0_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B2_MODE_BIT_1_BIT                                  9
#define CHIP_PIN_B2_MODE_BIT_1_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B2_MODE_BIT_2_BIT                                  10
#define CHIP_PIN_B2_MODE_BIT_2_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B2_MODE_BIT_3_BIT                                  11
#define CHIP_PIN_B2_MODE_BIT_3_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_B2_INPUT_BIT_0_REG                                 CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_B2_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B3                                                 true
#define CHIP_PIN_B3_MODE_BIT_0_BIT                                  12
#define CHIP_PIN_B3_MODE_BIT_0_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B3_MODE_BIT_1_BIT                                  13
#define CHIP_PIN_B3_MODE_BIT_1_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B3_MODE_BIT_2_BIT                                  14
#define CHIP_PIN_B3_MODE_BIT_2_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B3_MODE_BIT_3_BIT                                  15
#define CHIP_PIN_B3_MODE_BIT_3_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_B3_INPUT_BIT_0_REG                                 CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_B3_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B4                                                 true
#define CHIP_PIN_B4_MODE_BIT_0_BIT                                  16
#define CHIP_PIN_B4_MODE_BIT_0_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B4_MODE_BIT_1_BIT                                  17
#define CHIP_PIN_B4_MODE_BIT_1_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B4_MODE_BIT_2_BIT                                  18
#define CHIP_PIN_B4_MODE_BIT_2_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B4_MODE_BIT_3_BIT                                  19
#define CHIP_PIN_B4_MODE_BIT_3_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_B4_INPUT_BIT_0_REG                                 CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_B4_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B5                                                 true
#define CHIP_PIN_B5_MODE_BIT_0_BIT                                  20
#define CHIP_PIN_B5_MODE_BIT_0_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B5_MODE_BIT_1_BIT                                  21
#define CHIP_PIN_B5_MODE_BIT_1_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B5_MODE_BIT_2_BIT                                  22
#define CHIP_PIN_B5_MODE_BIT_2_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B5_MODE_BIT_3_BIT                                  23
#define CHIP_PIN_B5_MODE_BIT_3_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_B5_INPUT_BIT_0_REG                                 CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_B5_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B6                                                 true
#define CHIP_PIN_B6_MODE_BIT_0_BIT                                  24
#define CHIP_PIN_B6_MODE_BIT_0_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B6_MODE_BIT_1_BIT                                  25
#define CHIP_PIN_B6_MODE_BIT_1_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B6_MODE_BIT_2_BIT                                  26
#define CHIP_PIN_B6_MODE_BIT_2_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B6_MODE_BIT_3_BIT                                  27
#define CHIP_PIN_B6_MODE_BIT_3_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_B6_INPUT_BIT_0_REG                                 CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_B6_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B7                                                 true
#define CHIP_PIN_B7_MODE_BIT_0_BIT                                  28
#define CHIP_PIN_B7_MODE_BIT_0_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B7_MODE_BIT_1_BIT                                  29
#define CHIP_PIN_B7_MODE_BIT_1_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B7_MODE_BIT_2_BIT                                  30
#define CHIP_PIN_B7_MODE_BIT_2_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B7_MODE_BIT_3_BIT                                  31
#define CHIP_PIN_B7_MODE_BIT_3_REG                                  CHIP_REG_PORT_B_CRL
#define CHIP_PIN_B7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_B7_INPUT_BIT_0_REG                                 CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_B7_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B8                                                 true
#define CHIP_PIN_B8_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_B8_MODE_BIT_0_REG                                  CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B8_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_B8_MODE_BIT_1_REG                                  CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B8_MODE_BIT_2_BIT                                  2
#define CHIP_PIN_B8_MODE_BIT_2_REG                                  CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B8_MODE_BIT_3_BIT                                  3
#define CHIP_PIN_B8_MODE_BIT_3_REG                                  CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B8_INPUT_BIT_0_BIT                                 8
#define CHIP_PIN_B8_INPUT_BIT_0_REG                                 CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B8_OUTPUT_BIT_0_BIT                                8
#define CHIP_PIN_B8_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B9                                                 true
#define CHIP_PIN_B9_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_B9_MODE_BIT_0_REG                                  CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B9_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_B9_MODE_BIT_1_REG                                  CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B9_MODE_BIT_2_BIT                                  6
#define CHIP_PIN_B9_MODE_BIT_2_REG                                  CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B9_MODE_BIT_3_BIT                                  7
#define CHIP_PIN_B9_MODE_BIT_3_REG                                  CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B9_INPUT_BIT_0_BIT                                 9
#define CHIP_PIN_B9_INPUT_BIT_0_REG                                 CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B9_OUTPUT_BIT_0_BIT                                9
#define CHIP_PIN_B9_OUTPUT_BIT_0_REG                                CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B10                                                true
#define CHIP_PIN_B10_MODE_BIT_0_BIT                                 8
#define CHIP_PIN_B10_MODE_BIT_0_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B10_MODE_BIT_1_BIT                                 9
#define CHIP_PIN_B10_MODE_BIT_1_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B10_MODE_BIT_2_BIT                                 10
#define CHIP_PIN_B10_MODE_BIT_2_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B10_MODE_BIT_3_BIT                                 11
#define CHIP_PIN_B10_MODE_BIT_3_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B10_INPUT_BIT_0_BIT                                0
#define CHIP_PIN_B10_INPUT_BIT_0_REG                                CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B10_OUTPUT_BIT_0_BIT                               0
#define CHIP_PIN_B10_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B11                                                true
#define CHIP_PIN_B11_MODE_BIT_0_BIT                                 12
#define CHIP_PIN_B11_MODE_BIT_0_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B11_MODE_BIT_1_BIT                                 13
#define CHIP_PIN_B11_MODE_BIT_1_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B11_MODE_BIT_2_BIT                                 14
#define CHIP_PIN_B11_MODE_BIT_2_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B11_MODE_BIT_3_BIT                                 15
#define CHIP_PIN_B11_MODE_BIT_3_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B11_INPUT_BIT_0_BIT                                11
#define CHIP_PIN_B11_INPUT_BIT_0_REG                                CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B11_OUTPUT_BIT_0_BIT                               11
#define CHIP_PIN_B11_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B12                                                true
#define CHIP_PIN_B12_MODE_BIT_0_BIT                                 16
#define CHIP_PIN_B12_MODE_BIT_0_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B12_MODE_BIT_1_BIT                                 17
#define CHIP_PIN_B12_MODE_BIT_1_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B12_MODE_BIT_2_BIT                                 18
#define CHIP_PIN_B12_MODE_BIT_2_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B12_MODE_BIT_3_BIT                                 19
#define CHIP_PIN_B12_MODE_BIT_3_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B12_INPUT_BIT_0_BIT                                12
#define CHIP_PIN_B12_INPUT_BIT_0_REG                                CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B12_OUTPUT_BIT_0_BIT                               12
#define CHIP_PIN_B12_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B13                                                true
#define CHIP_PIN_B13_MODE_BIT_0_BIT                                 20
#define CHIP_PIN_B13_MODE_BIT_0_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B13_MODE_BIT_1_BIT                                 21
#define CHIP_PIN_B13_MODE_BIT_1_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B13_MODE_BIT_2_BIT                                 22
#define CHIP_PIN_B13_MODE_BIT_2_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B13_MODE_BIT_3_BIT                                 23
#define CHIP_PIN_B13_MODE_BIT_3_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B13_INPUT_BIT_0_BIT                                13
#define CHIP_PIN_B13_INPUT_BIT_0_REG                                CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B13_OUTPUT_BIT_0_BIT                               13
#define CHIP_PIN_B13_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B14                                                true
#define CHIP_PIN_B14_MODE_BIT_0_BIT                                 24
#define CHIP_PIN_B14_MODE_BIT_0_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B14_MODE_BIT_1_BIT                                 25
#define CHIP_PIN_B14_MODE_BIT_1_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B14_MODE_BIT_2_BIT                                 26
#define CHIP_PIN_B14_MODE_BIT_2_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B14_MODE_BIT_3_BIT                                 27
#define CHIP_PIN_B14_MODE_BIT_3_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B14_INPUT_BIT_0_BIT                                14
#define CHIP_PIN_B14_INPUT_BIT_0_REG                                CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B14_OUTPUT_BIT_0_BIT                               14
#define CHIP_PIN_B14_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_B_ODR

#define CHIP_PIN_B15                                                true
#define CHIP_PIN_B15_MODE_BIT_0_BIT                                 28
#define CHIP_PIN_B15_MODE_BIT_0_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B15_MODE_BIT_1_BIT                                 29
#define CHIP_PIN_B15_MODE_BIT_1_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B15_MODE_BIT_2_BIT                                 30
#define CHIP_PIN_B15_MODE_BIT_2_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B15_MODE_BIT_3_BIT                                 31
#define CHIP_PIN_B15_MODE_BIT_3_REG                                 CHIP_REG_PORT_B_CRH
#define CHIP_PIN_B15_INPUT_BIT_0_BIT                                15
#define CHIP_PIN_B15_INPUT_BIT_0_REG                                CHIP_REG_PORT_B_IDR
#define CHIP_PIN_B15_OUTPUT_BIT_0_BIT                               15
#define CHIP_PIN_B15_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_B_ODR

#define CHIP_PIN_C13                                                true
#define CHIP_PIN_C13_MODE_BIT_0_BIT                                 20
#define CHIP_PIN_C13_MODE_BIT_0_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C13_MODE_BIT_1_BIT                                 21
#define CHIP_PIN_C13_MODE_BIT_1_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C13_MODE_BIT_2_BIT                                 22
#define CHIP_PIN_C13_MODE_BIT_2_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C13_MODE_BIT_3_BIT                                 23
#define CHIP_PIN_C13_MODE_BIT_3_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C13_INPUT_BIT_0_BIT                                13
#define CHIP_PIN_C13_INPUT_BIT_0_REG                                CHIP_REG_PORT_C_IDR
#define CHIP_PIN_C13_OUTPUT_BIT_0_BIT                               13
#define CHIP_PIN_C13_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_C_ODR

#define CHIP_PIN_C14                                                true
#define CHIP_PIN_C14_MODE_BIT_0_BIT                                 24
#define CHIP_PIN_C14_MODE_BIT_0_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C14_MODE_BIT_1_BIT                                 25
#define CHIP_PIN_C14_MODE_BIT_1_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C14_MODE_BIT_2_BIT                                 26
#define CHIP_PIN_C14_MODE_BIT_2_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C14_MODE_BIT_3_BIT                                 27
#define CHIP_PIN_C14_MODE_BIT_3_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C14_INPUT_BIT_0_BIT                                14
#define CHIP_PIN_C14_INPUT_BIT_0_REG                                CHIP_REG_PORT_C_IDR
#define CHIP_PIN_C14_OUTPUT_BIT_0_BIT                               14
#define CHIP_PIN_C14_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_C_ODR

#define CHIP_PIN_C15                                                true
#define CHIP_PIN_C15_MODE_BIT_0_BIT                                 28
#define CHIP_PIN_C15_MODE_BIT_0_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C15_MODE_BIT_1_BIT                                 29
#define CHIP_PIN_C15_MODE_BIT_1_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C15_MODE_BIT_2_BIT                                 30
#define CHIP_PIN_C15_MODE_BIT_2_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C15_MODE_BIT_3_BIT                                 31
#define CHIP_PIN_C15_MODE_BIT_3_REG                                 CHIP_REG_PORT_C_CRH
#define CHIP_PIN_C15_INPUT_BIT_0_BIT                                15
#define CHIP_PIN_C15_INPUT_BIT_0_REG                                CHIP_REG_PORT_C_IDR
#define CHIP_PIN_C15_OUTPUT_BIT_0_BIT                               15
#define CHIP_PIN_C15_OUTPUT_BIT_0_REG                               CHIP_REG_PORT_C_ODR

//------------------------------------------------
// ADC

// #define CHIP_ADC                                                        true

// #define CHIP_ADC_ENABLE_REG                                             REG8(CHIP_ADDR_ADCSRA)
// #define CHIP_ADC_ENABLE_BIT                                             7

// #define CHIP_ADC_START_REG                                              REG8(CHIP_ADDR_ADCSRA)
// #define CHIP_ADC_START_BIT                                              6

// #define CHIP_ADC_REFERENCE_BIT_0_REG                                    REG8(CHIP_ADDR_ADMUX)
// #define CHIP_ADC_REFERENCE_BIT_1_REG                                    REG8(CHIP_ADDR_ADMUX)
// #define CHIP_ADC_REFERENCE_BIT_0_BIT                                    6
// #define CHIP_ADC_REFERENCE_BIT_1_BIT                                    7
// #define CHIP_ADC_REFERENCE_AREF_ID                                      0
// #define CHIP_ADC_REFERENCE_AVCC_ID                                      1
// #define CHIP_ADC_REFERENCE_INTERNAL_ID                                  3

// #define CHIP_ADC_CHANNEL_BIT_0_REG                                      REG8(CHIP_ADDR_ADMUX)
// #define CHIP_ADC_CHANNEL_BIT_1_REG                                      REG8(CHIP_ADDR_ADMUX)
// #define CHIP_ADC_CHANNEL_BIT_2_REG                                      REG8(CHIP_ADDR_ADMUX)
// #define CHIP_ADC_CHANNEL_BIT_3_REG                                      REG8(CHIP_ADDR_ADMUX)
// #define CHIP_ADC_CHANNEL_BIT_0_BIT                                      0
// #define CHIP_ADC_CHANNEL_BIT_1_BIT                                      1
// #define CHIP_ADC_CHANNEL_BIT_2_BIT                                      2
// #define CHIP_ADC_CHANNEL_BIT_3_BIT                                      3
// #define CHIP_ADC_CHANNEL_0_ID                                           0
// #define CHIP_ADC_CHANNEL_1_ID                                           1
// #define CHIP_ADC_CHANNEL_2_ID                                           2
// #define CHIP_ADC_CHANNEL_3_ID                                           3
// #define CHIP_ADC_CHANNEL_4_ID                                           4
// #define CHIP_ADC_CHANNEL_5_ID                                           5
// #define CHIP_ADC_CHANNEL_6_ID                                           6
// #define CHIP_ADC_CHANNEL_7_ID                                           7
// #define CHIP_ADC_CHANNEL_8_ID                                           8
// #define CHIP_ADC_CHANNEL_VBG_ID                                         14
// #define CHIP_ADC_CHANNEL_GND_ID                                         15

// #define CHIP_ADC_TRIGGER                                                true
// #define CHIP_ADC_TRIGGER_ENABLE_REG                                     REG8(CHIP_ADDR_ADCSRA)
// #define CHIP_ADC_TRIGGER_ENABLE_BIT                                     5
// #define CHIP_ADC_TRIGGER_BIT_0_REG                                      REG8(CHIP_ADDR_ADCSRB)
// #define CHIP_ADC_TRIGGER_BIT_1_REG                                      REG8(CHIP_ADDR_ADCSRB)
// #define CHIP_ADC_TRIGGER_BIT_2_REG                                      REG8(CHIP_ADDR_ADCSRB)
// #define CHIP_ADC_TRIGGER_BIT_0_BIT                                      0
// #define CHIP_ADC_TRIGGER_BIT_1_BIT                                      1
// #define CHIP_ADC_TRIGGER_BIT_2_BIT                                      2
// #define CHIP_ADC_TRIGGER_FREE_RUNNING_ID                                0
// #define CHIP_ADC_TRIGGER_ANALOG_COMPARATOR_ID                           1
// #define CHIP_ADC_TRIGGER_EXTERNAL_INT_0_ID                              2
// #define CHIP_ADC_TRIGGER_TIMER0_COMPARE_MATCH_A_ID                      3
// #define CHIP_ADC_TRIGGER_TIMER0_OVERFLOW_ID                             4
// #define CHIP_ADC_TRIGGER_TIMER1_COMPARE_MATCH_B_ID                      5
// #define CHIP_ADC_TRIGGER_TIMER1_OVERFLOW_ID                             6
// #define CHIP_ADC_TRIGGER_TIMER1_CAPTURE_EVENT_ID                        7

// #define CHIP_ADC_INT_FLAG_REG                                           REG8(CHIP_ADDR_ADCSRA)
// #define CHIP_ADC_INT_FLAG_BIT                                           4
// #define CHIP_ADC_INT_ENABLE_REG                                         REG8(CHIP_ADDR_ADCSRA)
// #define CHIP_ADC_INT_ENABLE_BIT                                         3
// #define CHIP_ADC_INT_VECTOR                                             VECT(CHIP_VECT_ADC)

// #define CHIP_ADC_LEFT_ADJUST_REG                                        REG8(CHIP_ADDR_ADMUX)
// #define CHIP_ADC_LEFT_ADJUST_BIT                                        5

// #define CHIP_ADC_DATA_REG                                               REG16(CHIP_ADDR_ADCL)

// #define CHIP_ADC_PRESCALER                                              true
// #define CHIP_ADC_PRESCALER_BIT_0_REG                                    REG8(CHIP_ADDR_ADCSRA)
// #define CHIP_ADC_PRESCALER_BIT_1_REG                                    REG8(CHIP_ADDR_ADCSRA)
// #define CHIP_ADC_PRESCALER_BIT_2_REG                                    REG8(CHIP_ADDR_ADCSRA)
// #define CHIP_ADC_PRESCALER_BIT_0_BIT                                    0
// #define CHIP_ADC_PRESCALER_BIT_1_BIT                                    1
// #define CHIP_ADC_PRESCALER_BIT_2_BIT                                    2
// #define CHIP_ADC_PRESCALER_2_ID                                         0
// #define CHIP_ADC_PRESCALER_4_ID                                         2
// #define CHIP_ADC_PRESCALER_8_ID                                         3
// #define CHIP_ADC_PRESCALER_16_ID                                        4
// #define CHIP_ADC_PRESCALER_32_ID                                        5
// #define CHIP_ADC_PRESCALER_64_ID                                        6
// #define CHIP_ADC_PRESCALER_128_ID                                       7

// //------------------------------------------------
// // External Interrupts

// #define CHIP_EXINT_COUNT                                                2

// #define CHIP_EXINT_0                                                    true
// #define CHIP_EXINT_0_ENABLE_REG                                         REG8(CHIP_ADDR_EIMSK)
// #define CHIP_EXINT_0_ENABLE_BIT                                         0
// #define CHIP_EXINT_0_FLAG_REG                                           REG8(CHIP_ADDR_EIFR)
// #define CHIP_EXINT_0_FLAG_BIT                                           0
// #define CHIP_EXINT_0_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_EICRA)
// #define CHIP_EXINT_0_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_EICRA)
// #define CHIP_EXINT_0_TRIGGER_BIT_0_BIT                                  0
// #define CHIP_EXINT_0_TRIGGER_BIT_1_BIT                                  1
// #define CHIP_EXINT_0_INT_VECTOR                                         VECT(CHIP_VECT_INT0)
// #define CHIP_EXINT_0_TRIGGER_LOW_ID                                     0
// #define CHIP_EXINT_0_TRIGGER_CHANGE_ID                                  1
// #define CHIP_EXINT_0_TRIGGER_FALLING_ID                                 2
// #define CHIP_EXINT_0_TRIGGER_RISING_ID                                  3

// #define CHIP_EXINT_1                                                    true
// #define CHIP_EXINT_1_ENABLE_REG                                         REG8(CHIP_ADDR_EIMSK)
// #define CHIP_EXINT_1_ENABLE_BIT                                         1
// #define CHIP_EXINT_1_FLAG_REG                                           REG8(CHIP_ADDR_EIFR)
// #define CHIP_EXINT_1_FLAG_BIT                                           1
// #define CHIP_EXINT_1_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_EICRA)
// #define CHIP_EXINT_1_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_EICRA)
// #define CHIP_EXINT_1_TRIGGER_BIT_0_BIT                                  2
// #define CHIP_EXINT_1_TRIGGER_BIT_1_BIT                                  3
// #define CHIP_EXINT_1_INT_VECTOR                                         VECT(CHIP_VECT_INT1)
// #define CHIP_EXINT_1_TRIGGER_LOW_ID                                     0
// #define CHIP_EXINT_1_TRIGGER_CHANGE_ID                                  1
// #define CHIP_EXINT_1_TRIGGER_FALLING_ID                                 2
// #define CHIP_EXINT_1_TRIGGER_RISING_ID                                  3

// //------------------------------------------------
// // Pin Change Interrupts

// #define CHIP_PCINT_COUNT                                                3

// #define CHIP_PCINT_0                                                    true
// #define CHIP_PCINT_0_ENABLE_REG                                         REG8(CHIP_ADDR_PCICR)
// #define CHIP_PCINT_0_ENABLE_BIT                                         0
// #define CHIP_PCINT_0_FLAG_REG                                           REG8(CHIP_ADDR_PCIFR)
// #define CHIP_PCINT_0_FLAG_BIT                                           0
// #define CHIP_PCINT_0_MASK_REG                                           REG8(CHIP_ADDR_PCMSK0)
// #define CHIP_PCINT_0_INT_VECTOR                                         VECT(CHIP_VECT_PCINT0)

// #define CHIP_PCINT_1                                                    true
// #define CHIP_PCINT_1_ENABLE_REG                                         REG8(CHIP_ADDR_PCICR)
// #define CHIP_PCINT_1_ENABLE_BIT                                         1
// #define CHIP_PCINT_1_FLAG_REG                                           REG8(CHIP_ADDR_PCIFR)
// #define CHIP_PCINT_1_FLAG_BIT                                           1
// #define CHIP_PCINT_1_MASK_REG                                           REG8(CHIP_ADDR_PCMSK1)
// #define CHIP_PCINT_1_INT_VECTOR                                         VECT(CHIP_VECT_PCINT1)

// #define CHIP_PCINT_2                                                    true
// #define CHIP_PCINT_2_ENABLE_REG                                         REG8(CHIP_ADDR_PCICR)
// #define CHIP_PCINT_2_ENABLE_BIT                                         2
// #define CHIP_PCINT_2_FLAG_REG                                           REG8(CHIP_ADDR_PCIFR)
// #define CHIP_PCINT_2_FLAG_BIT                                           2
// #define CHIP_PCINT_2_MASK_REG                                           REG8(CHIP_ADDR_PCMSK2)
// #define CHIP_PCINT_2_INT_VECTOR                                         VECT(CHIP_VECT_PCINT2)

// //------------------------------------------------
// // Timer Counters

// #define CHIP_TIMER_COUNT                                         3

// //------------------------------------------------
// // Timer Counter 0

// #define CHIP_TIMER_0                                             true

// #define CHIP_TIMER_0_TYPE                                        uint8_t

// #define CHIP_TIMER_0_WAVEFORM                                    true
// #define CHIP_TIMER_0_WAVEFORM_NORMAL_ID                          0
// #define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_ID               1
// #define CHIP_TIMER_0_WAVEFORM_CTC_OCRA_ID                        2
// #define CHIP_TIMER_0_WAVEFORM_FAST_PWM_ID                        3
// #define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          5
// #define CHIP_TIMER_0_WAVEFORM_FAST_PWM_OCRA_ID                   7
// #define CHIP_TIMER_0_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR0A)
// #define CHIP_TIMER_0_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR0A)
// #define CHIP_TIMER_0_WAVEFORM_BIT_2_REG                          REG8(CHIP_ADDR_TCCR0B)
// #define CHIP_TIMER_0_WAVEFORM_BIT_0_BIT                          0
// #define CHIP_TIMER_0_WAVEFORM_BIT_1_BIT                          1
// #define CHIP_TIMER_0_WAVEFORM_BIT_2_BIT                          3

// #define CHIP_TIMER_0_CLOCK_NONE_ID                               0
// #define CHIP_TIMER_0_CLOCK_1_ID                                  1
// #define CHIP_TIMER_0_CLOCK_8_ID                                  2
// #define CHIP_TIMER_0_CLOCK_64_ID                                 3
// #define CHIP_TIMER_0_CLOCK_256_ID                                4
// #define CHIP_TIMER_0_CLOCK_1024_ID                               5
// #define CHIP_TIMER_0_CLOCK_EXT_FALLING_ID                        6
// #define CHIP_TIMER_0_CLOCK_EXT_RISING_ID                         7
// #define CHIP_TIMER_0_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR0B)
// #define CHIP_TIMER_0_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR0B)
// #define CHIP_TIMER_0_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR0B)
// #define CHIP_TIMER_0_CLOCK_BIT_0_BIT                             0
// #define CHIP_TIMER_0_CLOCK_BIT_1_BIT                             1
// #define CHIP_TIMER_0_CLOCK_BIT_2_BIT                             2

// #define CHIP_TIMER_0_COUNTER_REG                                 REG8(CHIP_ADDR_TCNT0)

// #define CHIP_TIMER_0_OUTPUTCOMPARE_A                             true
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_PIN                         PinD6
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR0A)
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR0A)
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_MODE_SET_ID                 3
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_REG                         REG8(CHIP_ADDR_OCR0A)
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK0)
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_INT_ENABLE_BIT              1
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR0)
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_INT_FLAG_BIT                1
// #define CHIP_TIMER_0_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER0_COMPA)

// #define CHIP_TIMER_0_OUTPUTCOMPARE_B                             true
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_PIN                         PinD5
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR0A)
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR0A)
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_MODE_SET_ID                 3
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_REG                         REG8(CHIP_ADDR_OCR0B)
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK0)
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_INT_ENABLE_BIT              2
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR0)
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_INT_FLAG_BIT                2
// #define CHIP_TIMER_0_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER0_COMPB)

// #define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK0)
// #define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                     0
// #define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR0)
// #define CHIP_TIMER_0_OVERFLOW_INT_FLAG_BIT                       0
// #define CHIP_TIMER_0_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER0_OVF)

//------------------------------------------------
// Timer Counter 1

// #define CHIP_TIMER_1                                             true

// #define CHIP_TIMER_1_TYPE                                        uint16_t

// #define CHIP_TIMER_1_WAVEFORM                                    true
// #define CHIP_TIMER_1_WAVEFORM_NORMAL_ID                          0
// #define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_8_ID             1
// #define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_9_ID             2
// #define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_10_ID            3
// #define CHIP_TIMER_1_WAVEFORM_CTC_OCRA_ID                        4
// #define CHIP_TIMER_1_WAVEFORM_FAST_PWM_8_ID                      5
// #define CHIP_TIMER_1_WAVEFORM_FAST_PWM_9_ID                      6
// #define CHIP_TIMER_1_WAVEFORM_FAST_PWM_10_ID                     7
// #define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID          8
// #define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID     9
// #define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_ID               10
// #define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          11
// #define CHIP_TIMER_1_WAVEFORM_CTC_ID                             12
// #define CHIP_TIMER_1_WAVEFORM_FAST_PWM_ID                        14
// #define CHIP_TIMER_1_WAVEFORM_FAST_PWM_OCRA_ID                   15
// #define CHIP_TIMER_1_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR1A)
// #define CHIP_TIMER_1_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR1A)
// #define CHIP_TIMER_1_WAVEFORM_BIT_2_REG                          REG8(CHIP_ADDR_TCCR1B)
// #define CHIP_TIMER_1_WAVEFORM_BIT_3_REG                          REG8(CHIP_ADDR_TCCR1B)
// #define CHIP_TIMER_1_WAVEFORM_BIT_0_BIT                          0
// #define CHIP_TIMER_1_WAVEFORM_BIT_1_BIT                          1
// #define CHIP_TIMER_1_WAVEFORM_BIT_2_BIT                          3
// #define CHIP_TIMER_1_WAVEFORM_BIT_3_BIT                          4

// #define CHIP_TIMER_1_CLOCK_NONE_ID                               0
// #define CHIP_TIMER_1_CLOCK_1_ID                                  1
// #define CHIP_TIMER_1_CLOCK_8_ID                                  2
// #define CHIP_TIMER_1_CLOCK_64_ID                                 3
// #define CHIP_TIMER_1_CLOCK_256_ID                                4
// #define CHIP_TIMER_1_CLOCK_1024_ID                               5
// #define CHIP_TIMER_1_CLOCK_EXT_FALLING_ID                        6
// #define CHIP_TIMER_1_CLOCK_EXT_RISING_ID                         7
// #define CHIP_TIMER_1_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR1B)
// #define CHIP_TIMER_1_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR1B)
// #define CHIP_TIMER_1_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR1B)
// #define CHIP_TIMER_1_CLOCK_BIT_0_BIT                             0
// #define CHIP_TIMER_1_CLOCK_BIT_1_BIT                             1
// #define CHIP_TIMER_1_CLOCK_BIT_2_BIT                             2

// #define CHIP_TIMER_1_COUNTER_REG                                 REG16(CHIP_ADDR_TCNT1L)
// #define CHIP_TIMER_1_COUNTER_REG                                    CHIP_REG_TIM1_CNT

// #define CHIP_TIMER_1_OUTPUTCOMPARE_A                             true
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_PIN                         PinB1
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR1A)
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR1A)
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_MODE_SET_ID                 3
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_REG                         REG16(CHIP_ADDR_OCR1AL)
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK1)
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_INT_ENABLE_BIT              1
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR1)
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_INT_FLAG_BIT                1
// #define CHIP_TIMER_1_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER1_COMPA)

// #define CHIP_TIMER_1_OUTPUTCOMPARE_B                             true
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_PIN                         PinB2
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR1A)
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR1A)
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_MODE_SET_ID                 3
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_REG                         REG16(CHIP_ADDR_OCR1BL)
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK1)
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_INT_ENABLE_BIT              2
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR1)
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_INT_FLAG_BIT                2
// #define CHIP_TIMER_1_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER1_COMPB)

// #define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK1)
// #define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                     0
// #define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR1)
// #define CHIP_TIMER_1_OVERFLOW_INT_FLAG_BIT                       0
// #define CHIP_TIMER_1_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER1_OVF)

// #define CHIP_TIMER_1_INPUTCAPTURE                                true
// #define CHIP_TIMER_1_INPUTCAPTURE_PIN                            PinB0
// #define CHIP_TIMER_1_INPUTCAPTURE_NOISE_CANCELER_REG             REG8(CHIP_ADDR_TCCR1B)
// #define CHIP_TIMER_1_INPUTCAPTURE_NOISE_CANCELER_BIT             7
// #define CHIP_TIMER_1_INPUTCAPTURE_EDGE_REG                       REG8(CHIP_ADDR_TCCR1B)
// #define CHIP_TIMER_1_INPUTCAPTURE_EDGE_BIT                       6
// #define CHIP_TIMER_1_INPUTCAPTURE_EDGE_FALLING_ID                0
// #define CHIP_TIMER_1_INPUTCAPTURE_EDGE_RISING_ID                 1
// #define CHIP_TIMER_1_INPUTCAPTURE_REG                            REG16(CHIP_ADDR_ICR1L)
// #define CHIP_TIMER_1_INPUTCAPTURE_INT_ENABLE_REG                 REG8(CHIP_ADDR_TIMSK1)
// #define CHIP_TIMER_1_INPUTCAPTURE_INT_ENABLE_BIT                 5
// #define CHIP_TIMER_1_INPUTCAPTURE_INT_FLAG_REG                   REG8(CHIP_ADDR_TIFR1)
// #define CHIP_TIMER_1_INPUTCAPTURE_INT_FLAG_BIT                   5
// #define CHIP_TIMER_1_INPUTCAPTURE_INT_VECTOR                     VECT(CHIP_VECT_TIMER1_CAPT)

//------------------------------------------------
// Timer Counter 2

#define CHIP_TIMER_2                                             true

#define CHIP_TIMER_2_TYPE                                        uint16_t

// #define CHIP_TIMER_2_WAVEFORM                                    true
// #define CHIP_TIMER_2_WAVEFORM_NORMAL_ID                          0
// #define CHIP_TIMER_2_WAVEFORM_PWM_PHASE_CORRECT_ID               1
// #define CHIP_TIMER_2_WAVEFORM_CTC_OCRA_ID                        2
// #define CHIP_TIMER_2_WAVEFORM_FAST_PWM_ID                        3
// #define CHIP_TIMER_2_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          5
// #define CHIP_TIMER_2_WAVEFORM_FAST_PWM_OCRA_ID                   7
// #define CHIP_TIMER_2_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR2A)
// #define CHIP_TIMER_2_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR2A)
// #define CHIP_TIMER_2_WAVEFORM_BIT_2_REG                          REG8(CHIP_ADDR_TCCR2B)
// #define CHIP_TIMER_2_WAVEFORM_BIT_0_BIT                          0
// #define CHIP_TIMER_2_WAVEFORM_BIT_1_BIT                          1
// #define CHIP_TIMER_2_WAVEFORM_BIT_2_BIT                          3

// #define CHIP_TIMER_2_CLOCK_NONE_ID                               0
// #define CHIP_TIMER_2_CLOCK_1_ID                                  1
// #define CHIP_TIMER_2_CLOCK_8_ID                                  2
// #define CHIP_TIMER_2_CLOCK_32_ID                                 3
// #define CHIP_TIMER_2_CLOCK_64_ID                                 4
// #define CHIP_TIMER_2_CLOCK_128_ID                                5
// #define CHIP_TIMER_2_CLOCK_256_ID                                6
// #define CHIP_TIMER_2_CLOCK_1024_ID                               7
// #define CHIP_TIMER_2_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR2B)
// #define CHIP_TIMER_2_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR2B)
// #define CHIP_TIMER_2_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR2B)
// #define CHIP_TIMER_2_CLOCK_BIT_0_BIT                             0
// #define CHIP_TIMER_2_CLOCK_BIT_1_BIT                             1
// #define CHIP_TIMER_2_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMER_2_COUNTER_REG                                    CHIP_REG_TIM2_CNT

// #define CHIP_TIMER_2_OUTPUTCOMPARE_A                             true
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_PIN                         PinB3
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR2A)
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR2A)
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_MODE_SET_ID                 3
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_REG                         REG8(CHIP_ADDR_OCR2A)
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK2)
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_INT_ENABLE_BIT              1
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR2)
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_INT_FLAG_BIT                1
// #define CHIP_TIMER_2_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER2_COMPA)

// #define CHIP_TIMER_2_OUTPUTCOMPARE_B                             true
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_PIN                         PinD3
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR2A)
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR2A)
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_MODE_SET_ID                 3
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_REG                         REG8(CHIP_ADDR_OCR2B)
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK2)
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_INT_ENABLE_BIT              2
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR2)
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_INT_FLAG_BIT                2
// #define CHIP_TIMER_2_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER2_COMPB)

// #define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK2)
// #define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_BIT                     0
// #define CHIP_TIMER_2_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR2)
// #define CHIP_TIMER_2_OVERFLOW_INT_FLAG_BIT                       0
// #define CHIP_TIMER_2_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER2_OVF)

//------------------------------------------------
// USART0

// #define CHIP_USART_COUNT                                                1

#define CHIP_USART_1                                                true

#define CHIP_USART_1_DATA_REG                                       CHIP_REG_USART_1_DR

#define CHIP_USART_1_BAUD_RATE_REG                                  CHIP_REG_USART_1_BRR

// #define CHIP_USART_1_FRAME_ERROR_REG                                    REG8(CHIP_ADDR_UCSR0A)
// #define CHIP_USART_1_FRAME_ERROR_BIT                                    4
// #define CHIP_USART_1_DATA_OVERRUN_REG                                   REG8(CHIP_ADDR_UCSR0A)
// #define CHIP_USART_1_DATA_OVERRUN_BIT                                   3
// #define CHIP_USART_1_PARITY_ERROR_REG                                   REG8(CHIP_ADDR_UCSR0A)
// #define CHIP_USART_1_PARITY_ERROR_BIT                                   2

// #define CHIP_USART_1_DOUBLE_SPEED_REG                                   REG8(CHIP_ADDR_UCSR0A)
// #define CHIP_USART_1_DOUBLE_SPEED_BIT                                   1

// #define CHIP_USART_1_MULTI_PROCESSOR_COMMUNICATION_REG                  REG8(CHIP_ADDR_UCSR0A)
// #define CHIP_USART_1_MULTI_PROCESSOR_COMMUNICATION_BIT                  0

// #define CHIP_USART_1_RX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSR0B)
// #define CHIP_USART_1_RX_COMPLETE_INT_ENABLE_BIT                         7
// #define CHIP_USART_1_TX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSR0B)
// #define CHIP_USART_1_TX_COMPLETE_INT_ENABLE_BIT                         6
// #define CHIP_USART_1_DATA_REG_EMPTY_INT_ENABLE_REG                      REG8(CHIP_ADDR_UCSR0B)
// #define CHIP_USART_1_DATA_REG_EMPTY_INT_ENABLE_BIT                      5

// #define CHIP_USART_1_RX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSR0B)
// #define CHIP_USART_1_RX_ENABLE_BIT                                      4
// #define CHIP_USART_1_TX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSR0B)
// #define CHIP_USART_1_TX_ENABLE_BIT                                      3

// #define CHIP_USART_1_RX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSR0B)
// #define CHIP_USART_1_RX_DATA_BIT_8_BIT                                  1
// #define CHIP_USART_1_TX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSR0B)
// #define CHIP_USART_1_TX_DATA_BIT_8_BIT                                  0

// #define CHIP_USART_1_MODE_ASYNCHRONOUS_ID                               0
// #define CHIP_USART_1_MODE_SYNCHRONOUS_ID                                1
// #define CHIP_USART_1_MODE_MASTER_SPI_ID                                 3
// #define CHIP_USART_1_MODE_BIT_0_REG                                     REG8(CHIP_ADDR_UCSR0C)
// #define CHIP_USART_1_MODE_BIT_1_REG                                     REG8(CHIP_ADDR_UCSR0C)
// #define CHIP_USART_1_MODE_BIT_0_BIT                                     6
// #define CHIP_USART_1_MODE_BIT_1_BIT                                     7

// #define CHIP_USART_1_PARITY_DISABLE_ID                                  0
// #define CHIP_USART_1_PARITY_EVEN_ID                                     2
// #define CHIP_USART_1_PARITY_ODD_ID                                      3
// #define CHIP_USART_1_PARITY_BIT_0_REG                                   REG8(CHIP_ADDR_UCSR0C)
// #define CHIP_USART_1_PARITY_BIT_1_REG                                   REG8(CHIP_ADDR_UCSR0C)
// #define CHIP_USART_1_PARITY_BIT_0_BIT                                   4
// #define CHIP_USART_1_PARITY_BIT_1_BIT                                   5

// #define CHIP_USART_1_STOP_BITS_1_ID                                     0
// #define CHIP_USART_1_STOP_BITS_2_ID                                     1
// #define CHIP_USART_1_STOP_BITS_REG                                      REG8(CHIP_ADDR_UCSR0C)
// #define CHIP_USART_1_STOP_BITS_BIT                                      3

// #define CHIP_USART_1_CHARACTER_SIZE_5_ID                                0
// #define CHIP_USART_1_CHARACTER_SIZE_6_ID                                1
// #define CHIP_USART_1_CHARACTER_SIZE_7_ID                                2
// #define CHIP_USART_1_CHARACTER_SIZE_8_ID                                3
// #define CHIP_USART_1_CHARACTER_SIZE_9_ID                                7
// #define CHIP_USART_1_CHARACTER_SIZE_BIT_0_REG                           REG8(CHIP_ADDR_UCSR0C)
// #define CHIP_USART_1_CHARACTER_SIZE_BIT_1_REG                           REG8(CHIP_ADDR_UCSR0C)
// #define CHIP_USART_1_CHARACTER_SIZE_BIT_2_REG                           REG8(CHIP_ADDR_UCSR0B)
// #define CHIP_USART_1_CHARACTER_SIZE_BIT_0_BIT                           1
// #define CHIP_USART_1_CHARACTER_SIZE_BIT_1_BIT                           2
// #define CHIP_USART_1_CHARACTER_SIZE_BIT_2_BIT                           2

// #define CHIP_USART_1_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID             0
// #define CHIP_USART_1_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID             1
// #define CHIP_USART_1_CLOCK_POLARITY_REG                                 REG8(CHIP_ADDR_UCSR0C)
// #define CHIP_USART_1_CLOCK_POLARITY_BIT                                 0

// #define CHIP_USART_1_RX_INT_VECTOR                                      VECT(CHIP_VECT_USART_RX)
// #define CHIP_USART_1_DE_INT_VECTOR                                      VECT(CHIP_VECT_USART_UDRE)
// #define CHIP_USART_1_TX_INT_VECTOR                                      VECT(CHIP_VECT_USART_TX)

// //------------------------------------------------
// // Two Wire Serial Interface

// #define CHIP_TWI                                                        true

// #define CHIP_TWI_PRESCALER_1_ID                                         0
// #define CHIP_TWI_PRESCALER_4_ID                                         1
// #define CHIP_TWI_PRESCALER_16_ID                                        2
// #define CHIP_TWI_PRESCALER_64_ID                                        3

// #define CHIP_TWI_PRESCALER_BIT_0_REG                                    REG8(CHIP_ADDR_TWSR)
// #define CHIP_TWI_PRESCALER_BIT_0_BIT                                    0
// #define CHIP_TWI_PRESCALER_BIT_1_REG                                    REG8(CHIP_ADDR_TWSR)
// #define CHIP_TWI_PRESCALER_BIT_1_BIT                                    1

// #define CHIP_TWI_DATA_REG                                               REG8(CHIP_ADDR_TWDR)

// #define CHIP_TWI_STATUS_REG                                             REG8(CHIP_ADDR_TWSR)

// #define CHIP_TWI_CONTROL_REG                                            REG8(CHIP_ADDR_TWCR)

// #define CHIP_TWI_BIT_RATE_REG                                           REG8(CHIP_ADDR_TWBR)

// #define CHIP_TWI_ENABLE_REG                                             REG8(CHIP_ADDR_TWCR)
// #define CHIP_TWI_ENABLE_BIT                                             2

// #define CHIP_TWI_INT_FLAG_REG                                           REG8(CHIP_ADDR_TWCR)
// #define CHIP_TWI_INT_FLAG_BIT                                           7

// #define CHIP_TWI_INT_ENABLE_REG                                         REG8(CHIP_ADDR_TWCR)
// #define CHIP_TWI_INT_ENABLE_BIT                                         0

// #define CHIP_TWI_ENABLE_ACK_REG                                         REG8(CHIP_ADDR_TWCR)
// #define CHIP_TWI_ENABLE_ACK_BIT                                         6

// #define CHIP_TWI_START_CONDITION_REG                                    REG8(CHIP_ADDR_TWCR)
// #define CHIP_TWI_START_CONDITION_BIT                                    5

// #define CHIP_TWI_STOP_CONDITION_REG                                     REG8(CHIP_ADDR_TWCR)
// #define CHIP_TWI_STOP_CONDITION_BIT                                     4

// #define CHIP_TWI_WRITE_COLLISION_FLAG_REG                               REG8(CHIP_ADDR_TWCR)
// #define CHIP_TWI_WRITE_COLLISION_FLAG_BIT                               3

// #define CHIP_TWI_GEN_CALL_REC_ENABLE_REG                                REG8(CHIP_ADDR_TWAR)
// #define CHIP_TWI_GEN_CALL_REC_ENABLE_BIT                                0

// #define CHIP_TWI_SLAVE_ADDRESS_REG                                      REG8(CHIP_ADDR_TWAR)
// #define CHIP_TWI_SLAVE_ADDRESS_MASK_REG                                 REG8(CHIP_ADDR_TWAMR)

// #define CHIP_TWI_INT_VECTOR                                             VECT(CHIP_VECT_TWI)

// //------------------------------------------------
// // EEPROM

// #define CHIP_EEPROM                                                     true

// // #define CHIP_EEPROM_ADDRESS_REG_SPLIT                                   true
// // #define CHIP_EEPROM_ADDRESS_REG_HIGH                                    REG8(CHIP_ADDR_EEARH)
// // #define CHIP_EEPROM_ADDRESS_REG_LOW                                     REG8(CHIP_ADDR_EEARL)
// #define CHIP_EEPROM_ADDRESS_REG                                         REG8(CHIP_ADDR_EEARL)

// #define CHIP_EEPROM_DATA_REG                                            REG8(CHIP_ADDR_EEDR)

// #define CHIP_EEPROM_PROGRAMMING_MODE_ERASE_WRITE_ID                     0
// #define CHIP_EEPROM_PROGRAMMING_MODE_ERASE_ONLY_ID                      1
// #define CHIP_EEPROM_PROGRAMMING_MODE_WRITE_ONLY_ID                      2
// #define CHIP_EEPROM_PROGRAMMING_MODE_BIT_0_REG                          REG8(CHIP_ADDR_EECR)
// #define CHIP_EEPROM_PROGRAMMING_MODE_BIT_0_BIT                          4
// #define CHIP_EEPROM_PROGRAMMING_MODE_BIT_1_REG                          REG8(CHIP_ADDR_EECR)
// #define CHIP_EEPROM_PROGRAMMING_MODE_BIT_1_BIT                          5

// #define CHIP_EEPROM_READY_INT_ENABLE_REG                                REG8(CHIP_ADDR_EECR)
// #define CHIP_EEPROM_READY_INT_ENABLE_BIT                                3

// #define CHIP_EEPROM_MASTER_WRITE_ENABLE_REG                             REG8(CHIP_ADDR_EECR)
// #define CHIP_EEPROM_MASTER_WRITE_ENABLE_BIT                             2

// #define CHIP_EEPROM_WRITE_ENABLE_REG                                    REG8(CHIP_ADDR_EECR)
// #define CHIP_EEPROM_WRITE_ENABLE_BIT                                    1

// #define CHIP_EEPROM_READ_ENABLE_REG                                     REG8(CHIP_ADDR_EECR)
// #define CHIP_EEPROM_READ_ENABLE_BIT                                     0

// #define CHIP_EEPROM_EE_READY_INT_VECTOR                                 VECT(CHIP_VECT_EE_READY)

#endif

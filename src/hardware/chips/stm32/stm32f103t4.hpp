#ifndef NBLIB_STM32F103T4_HPP
#define NBLIB_STM32F103T4_HPP

#define CHIP stm32f103t4

//------------------------------------------------
// Peripherals

#define CHIP_MODULE_TIM2_ADDR                                       0x4000'0000
#define CHIP_MODULE_TIM3_ADDR                                       0x4000'0400
#define CHIP_MODULE_TIM4_ADDR                                       0x4000'0800
#define CHIP_MODULE_TIM5_ADDR                                       0x4000'0C00
#define CHIP_MODULE_TIM6_ADDR                                       0x4000'1000
#define CHIP_MODULE_TIM7_ADDR                                       0x4000'1400
#define CHIP_MODULE_TIM12_ADDR                                      0x4000'1800
#define CHIP_MODULE_TIM13_ADDR                                      0x4000'1C00
#define CHIP_MODULE_TIM14_ADDR                                      0x4000'2000
#define CHIP_MODULE_RTC_ADDR                                        0x4000'2800
#define CHIP_MODULE_WWDG_ADDR                                       0x4000'2C00
#define CHIP_MODULE_IWDG_ADDR                                       0x4000'3000
#define CHIP_MODULE_SPI2_ADDR                                       0x4000'3800
#define CHIP_MODULE_SPI3_ADDR                                       0x4000'3C00
#define CHIP_MODULE_USART2_ADDR                                     0x4000'4400
#define CHIP_MODULE_USART3_ADDR                                     0x4000'4800
#define CHIP_MODULE_UART4_ADDR                                      0x4000'4C00
#define CHIP_MODULE_UART5_ADDR                                      0x4000'5000
#define CHIP_MODULE_I2C1_ADDR                                       0x4000'5400
#define CHIP_MODULE_I2C2_ADDR                                       0x4000'5800
#define CHIP_MODULE_USB_ADDR                                        0x4000'5C00
// #define CHIP_MODULE_USB_CAN_SRAM_ADDR                               0x4000'6000
#define CHIP_MODULE_CAN1_ADDR                                       0x4000'6400
#define CHIP_MODULE_CAN2_ADDR                                       0x4000'6800
#define CHIP_MODULE_BKP_ADDR                                        0x4000'6C00
#define CHIP_MODULE_PWR_ADDR                                        0x4000'7000
#define CHIP_MODULE_DAC_ADDR                                        0x4000'7400
#define CHIP_MODULE_AFIO_ADDR                                       0x4001'0000
#define CHIP_MODULE_EXTI_ADDR                                       0x4001'0400
#define CHIP_MODULE_GPIOA_ADDR                                      0x4001'0800
#define CHIP_MODULE_GPIOB_ADDR                                      0x4001'0C00
#define CHIP_MODULE_GPIOC_ADDR                                      0x4001'1000
// #define CHIP_MODULE_GPIOD_ADDR                                      0x4001'1400
// #define CHIP_MODULE_GPIOE_ADDR                                      0x4001'1800
// #define CHIP_MODULE_GPIOF_ADDR                                      0x4001'1C00
// #define CHIP_MODULE_GPIOG_ADDR                                      0x4001'2000
#define CHIP_MODULE_ADC1_ADDR                                       0x4001'2400
#define CHIP_MODULE_ADC2_ADDR                                       0x4001'2800
#define CHIP_MODULE_TIM1_ADDR                                       0x4001'2C00
#define CHIP_MODULE_SPI1_ADDR                                       0x4001'3000
#define CHIP_MODULE_TIM8_ADDR                                       0x4001'3400
#define CHIP_MODULE_USART1_ADDR                                     0x4001'3800
#define CHIP_MODULE_ADC3_ADDR                                       0x4001'3C00
#define CHIP_MODULE_TIM9_ADDR                                       0x4001'4C00
#define CHIP_MODULE_TIM10_ADDR                                      0x4001'5000
#define CHIP_MODULE_TIM11_ADDR                                      0x4001'5400
#define CHIP_MODULE_SDIO_ADDR                                       0x4001'8000
#define CHIP_MODULE_DMA1_ADDR                                       0x4002'0000
#define CHIP_MODULE_DMA2_ADDR                                       0x4002'0400
#define CHIP_MODULE_RCC_ADDR                                        0x4002'1000
#define CHIP_MODULE_FLASH_ADDR                                      0x4002'2000
#define CHIP_MODULE_CRC_ADDR                                        0x4002'3000
#define CHIP_MODULE_ETHERNET_ADDR                                   0x4002'8000
#define CHIP_MODULE_USB_OTG_ADDR                                    0x5000'0000
#define CHIP_MODULE_FSMC_ADDR                                       0xA000'0000

// #define CHIP_ADDR_OFFSET_CRL                                        0x00
// #define CHIP_ADDR_OFFSET_CRH                                        0x04
// #define CHIP_ADDR_OFFSET_IDR                                        0x08
// TODO ...

//------------------------------------------------
// Registers

// TODO TIM2
// TODO TIM3
// TODO TIM4
// TODO TIM5
// TODO TIM6
// TODO TIM7
// TODO TIM12
// TODO TIM13
// TODO TIM14
// TODO RTC
// TODO WWDG
// TODO IWDG
// TODO SPI2
// TODO SPI3
// TODO USART2
// TODO USART3
// TODO UART4
// TODO UART5
// TODO I2C1
// TODO I2C2
// TODO USB
// TODO CAN1
// TODO CAN2
// TODO BKP
// TODO PWR
// TODO DAC
// TODO AFIO
// TODO EXTI

#define CHIP_REG_GPIOA_CRL                                          Register<uint32_t, CHIP_MODULE_GPIOA_ADDR + 0x00>
#define CHIP_REG_GPIOA_CRH                                          Register<uint32_t, CHIP_MODULE_GPIOA_ADDR + 0x04>
#define CHIP_REG_GPIOA_IDR                                          Register<uint32_t, CHIP_MODULE_GPIOA_ADDR + 0x08>
#define CHIP_REG_GPIOA_ODR                                          Register<uint32_t, CHIP_MODULE_GPIOA_ADDR + 0x0C>
#define CHIP_REG_GPIOA_BSRR                                         Register<uint32_t, CHIP_MODULE_GPIOA_ADDR + 0x10, 0xFFFF'FFFF>
#define CHIP_REG_GPIOA_BRR                                          Register<uint32_t, CHIP_MODULE_GPIOA_ADDR + 0x14, 0xFFFF'FFFF>
#define CHIP_REG_GPIOA_LCK                                          Register<uint32_t, CHIP_MODULE_GPIOA_ADDR + 0x18>

#define CHIP_REG_GPIOB_CRL                                          Register<uint32_t, CHIP_MODULE_GPIOB_ADDR + 0x00>
#define CHIP_REG_GPIOB_CRH                                          Register<uint32_t, CHIP_MODULE_GPIOB_ADDR + 0x04>
#define CHIP_REG_GPIOB_IDR                                          Register<uint32_t, CHIP_MODULE_GPIOB_ADDR + 0x08>
#define CHIP_REG_GPIOB_ODR                                          Register<uint32_t, CHIP_MODULE_GPIOB_ADDR + 0x0C>
#define CHIP_REG_GPIOB_BSRR                                         Register<uint32_t, CHIP_MODULE_GPIOB_ADDR + 0x10, 0xFFFF'FFFF>
#define CHIP_REG_GPIOB_BRR                                          Register<uint32_t, CHIP_MODULE_GPIOB_ADDR + 0x14, 0xFFFF'FFFF>
#define CHIP_REG_GPIOB_LCK                                          Register<uint32_t, CHIP_MODULE_GPIOB_ADDR + 0x18>

#define CHIP_REG_GPIOC_CRL                                          Register<uint32_t, CHIP_MODULE_GPIOC_ADDR + 0x00>
#define CHIP_REG_GPIOC_CRH                                          Register<uint32_t, CHIP_MODULE_GPIOC_ADDR + 0x04>
#define CHIP_REG_GPIOC_IDR                                          Register<uint32_t, CHIP_MODULE_GPIOC_ADDR + 0x08>
#define CHIP_REG_GPIOC_ODR                                          Register<uint32_t, CHIP_MODULE_GPIOC_ADDR + 0x0C>
#define CHIP_REG_GPIOC_BSRR                                         Register<uint32_t, CHIP_MODULE_GPIOC_ADDR + 0x10, 0xFFFF'FFFF>
#define CHIP_REG_GPIOC_BRR                                          Register<uint32_t, CHIP_MODULE_GPIOC_ADDR + 0x14, 0xFFFF'FFFF>
#define CHIP_REG_GPIOC_LCK                                          Register<uint32_t, CHIP_MODULE_GPIOC_ADDR + 0x18>

// TODO PORTD
// TODO PORTE
// TODO PORTF
// TODO PORTG
// TODO ADC1
// TODO ADC2
// TODO TIM1
// TODO SPI1
// TODO TIM8
// TODO USART1
// TODO ADC3
// TODO TIM9
// TODO TIM10
// TODO TIM11
// TODO SDIO
// TODO DMA1
// TODO DMA2

#define CHIP_REG_RCC_CR                                             Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x00>
#define CHIP_REG_RCC_CFGR                                           Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x04>
#define CHIP_REG_RCC_CIR                                            Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x08>
#define CHIP_REG_RCC_APB2RSTR                                       Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x0C>
#define CHIP_REG_RCC_APB1RSTR                                       Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x10>
#define CHIP_REG_RCC_AHBENR                                         Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x14>
#define CHIP_REG_RCC_APB2ENR                                        Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x18>
#define CHIP_REG_RCC_APB1ENR                                        Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x1C>
#define CHIP_REG_RCC_BDCR                                           Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x20>
#define CHIP_REG_RCC_CSR                                            Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x24>
#define CHIP_REG_RCC_AHBSTR                                         Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x28>
#define CHIP_REG_RCC_CFGR2                                          Register<uint32_t, CHIP_MODULE_RCC_ADDR + 0x2C>

// TODO FLASH
// TODO CRC
// TODO ETHERNET
// TODO USB_OTG
// TODO FSMC

// #define CHIP_VECT_RESET                                             1
// #define CHIP_VECT_NMI
// #define CHIP_VECT_HARD_FAULT
// #define CHIP_VECT_MEM_MANAGE
// #define CHIP_VECT_BUS_FAULT
// #define CHIP_VECT_USAGE_FAULT
// #define CHIP_VECT_SV_CALL
// #define CHIP_VECT_DEBUG_MONITOR
// #define CHIP_VECT_PEND_SV
// #define CHIP_VECT_SYS_TICK
// #define CHIP_VECT_WWDG
// #define CHIP_VECT_PVD
// #define CHIP_VECT_TAMPER
// #define CHIP_VECT_RTC
// #define CHIP_VECT_FLASH
// #define CHIP_VECT_RCC
// #define CHIP_VECT_EXT_INT_0
// #define CHIP_VECT_EXT_INT_1
// #define CHIP_VECT_EXT_INT_2
// #define CHIP_VECT_EXT_INT_3
// #define CHIP_VECT_EXT_INT_4
// #define CHIP_VECT_DMA_1_CHANNEL_1
// #define CHIP_VECT_DMA_1_CHANNEL_2
// #define CHIP_VECT_DMA_1_CHANNEL_3
// #define CHIP_VECT_DMA_1_CHANNEL_4
// #define CHIP_VECT_DMA_1_CHANNEL_5
// #define CHIP_VECT_DMA_1_CHANNEL_6
// #define CHIP_VECT_DMA_1_CHANNEL_7
// #define CHIP_VECT_ADC_1_2
// #define CHIP_VECT_
// #define CHIP_VECT_
// #define CHIP_VECT_
// #define CHIP_VECT_

//------------------------------------------------
// Clock

#define CHIP_CLOCK_PLL_3_READY_REG                                  CHIP_REG_RCC_CR
#define CHIP_CLOCK_PLL_3_READY_BIT                                  29

#define CHIP_CLOCK_PLL_3_ENABLE_REG                                 CHIP_REG_RCC_CR
#define CHIP_CLOCK_PLL_3_ENABLE_BIT                                 28

#define CHIP_CLOCK_PLL_2_READY_REG                                  CHIP_REG_RCC_CR
#define CHIP_CLOCK_PLL_2_READY_BIT                                  27

#define CHIP_CLOCK_PLL_2_ENABLE_REG                                 CHIP_REG_RCC_CR
#define CHIP_CLOCK_PLL_2_ENABLE_BIT                                 26

#define CHIP_CLOCK_PLL_1_READY_REG                                  CHIP_REG_RCC_CR
#define CHIP_CLOCK_PLL_1_READY_BIT                                  25

#define CHIP_CLOCK_PLL_1_ENABLE_REG                                 CHIP_REG_RCC_CR
#define CHIP_CLOCK_PLL_1_ENABLE_BIT                                 24

#define CHIP_CLOCK_EXTERNAL_HIGH_SPEED_CLOCK_READY_REG              CHIP_REG_RCC_CR
#define CHIP_CLOCK_EXTERNAL_HIGH_SPEED_CLOCK_READY_BIT              17

#define CHIP_CLOCK_EXTERNAL_HIGH_SPEED_CLOCK_ENABLE_REG             CHIP_REG_RCC_CR
#define CHIP_CLOCK_EXTERNAL_HIGH_SPEED_CLOCK_ENABLE_BIT             16

#define CHIP_CLOCK_INTERNAL_HIGH_SPEED_CLOCK_READY_REG              CHIP_REG_RCC_CR
#define CHIP_CLOCK_INTERNAL_HIGH_SPEED_CLOCK_READY_BIT              1

#define CHIP_CLOCK_INTERNAL_HIGH_SPEED_CLOCK_ENABLE_REG             CHIP_REG_RCC_CR
#define CHIP_CLOCK_INTERNAL_HIGH_SPEED_CLOCK_ENABLE_BIT             0

#define CHIP_CLOCK_PLL_3_MULTIPLIER_REG                             CHIP_REG_RCC_CFGR2
#define CHIP_CLOCK_PLL_3_MULTIPLIER_MASK                            0x0000'F000
#define CHIP_CLOCK_PLL_3_MULTIPLIER_8_ID                            0x0000'6000
#define CHIP_CLOCK_PLL_3_MULTIPLIER_9_ID                            0x0000'7000
#define CHIP_CLOCK_PLL_3_MULTIPLIER_10_ID                           0x0000'8000
#define CHIP_CLOCK_PLL_3_MULTIPLIER_11_ID                           0x0000'9000
#define CHIP_CLOCK_PLL_3_MULTIPLIER_12_ID                           0x0000'A000
#define CHIP_CLOCK_PLL_3_MULTIPLIER_13_ID                           0x0000'B000
#define CHIP_CLOCK_PLL_3_MULTIPLIER_14_ID                           0x0000'C000
#define CHIP_CLOCK_PLL_3_MULTIPLIER_16_ID                           0x0000'E000
#define CHIP_CLOCK_PLL_3_MULTIPLIER_20_ID                           0x0000'F000

#define CHIP_CLOCK_PLL_2_MULTIPLIER_REG                             CHIP_REG_RCC_CFGR2
#define CHIP_CLOCK_PLL_2_MULTIPLIER_MASK                            0x0000'0F00
#define CHIP_CLOCK_PLL_2_MULTIPLIER_8_ID                            0x0000'0600
#define CHIP_CLOCK_PLL_2_MULTIPLIER_9_ID                            0x0000'0700
#define CHIP_CLOCK_PLL_2_MULTIPLIER_10_ID                           0x0000'0800
#define CHIP_CLOCK_PLL_2_MULTIPLIER_11_ID                           0x0000'0900
#define CHIP_CLOCK_PLL_2_MULTIPLIER_12_ID                           0x0000'0A00
#define CHIP_CLOCK_PLL_2_MULTIPLIER_13_ID                           0x0000'0B00
#define CHIP_CLOCK_PLL_2_MULTIPLIER_14_ID                           0x0000'0C00
#define CHIP_CLOCK_PLL_2_MULTIPLIER_16_ID                           0x0000'0E00
#define CHIP_CLOCK_PLL_2_MULTIPLIER_20_ID                           0x0000'0F00

#define CHIP_CLOCK_PLL_1_MULTIPLIER_REG                             CHIP_REG_RCC_CFGR
#define CHIP_CLOCK_PLL_1_MULTIPLIER_MASK                            0x003C'0000
#define CHIP_CLOCK_PLL_1_MULTIPLIER_4_ID                            0x0008'0000
#define CHIP_CLOCK_PLL_1_MULTIPLIER_5_ID                            0x000C'0000
#define CHIP_CLOCK_PLL_1_MULTIPLIER_6_ID                            0x0010'0000
#define CHIP_CLOCK_PLL_1_MULTIPLIER_7_ID                            0x0014'0000
#define CHIP_CLOCK_PLL_1_MULTIPLIER_8_ID                            0x0018'0000
#define CHIP_CLOCK_PLL_1_MULTIPLIER_9_ID                            0x001C'0000
#define CHIP_CLOCK_PLL_1_MULTIPLIER_6_5_ID                          0x0034'0000

#define CHIP_CLOCK_PLL_2_PRESCALER_REG                              CHIP_REG_RCC_CFGR2
#define CHIP_CLOCK_PLL_2_PRESCALER_MASK                             0x000'00F0
#define CHIP_CLOCK_PLL_2_PRESCALER_1_ID                             0x000'0000
#define CHIP_CLOCK_PLL_2_PRESCALER_2_ID                             0x000'0010
#define CHIP_CLOCK_PLL_2_PRESCALER_3_ID                             0x000'0020
#define CHIP_CLOCK_PLL_2_PRESCALER_4_ID                             0x000'0030
#define CHIP_CLOCK_PLL_2_PRESCALER_5_ID                             0x000'0040
#define CHIP_CLOCK_PLL_2_PRESCALER_6_ID                             0x000'0050
#define CHIP_CLOCK_PLL_2_PRESCALER_7_ID                             0x000'0060
#define CHIP_CLOCK_PLL_2_PRESCALER_8_ID                             0x000'0070
#define CHIP_CLOCK_PLL_2_PRESCALER_9_ID                             0x000'0080
#define CHIP_CLOCK_PLL_2_PRESCALER_10_ID                            0x000'0090
#define CHIP_CLOCK_PLL_2_PRESCALER_11_ID                            0x000'00A0
#define CHIP_CLOCK_PLL_2_PRESCALER_12_ID                            0x000'00B0
#define CHIP_CLOCK_PLL_2_PRESCALER_13_ID                            0x000'00C0
#define CHIP_CLOCK_PLL_2_PRESCALER_14_ID                            0x000'00D0
#define CHIP_CLOCK_PLL_2_PRESCALER_15_ID                            0x000'00E0
#define CHIP_CLOCK_PLL_2_PRESCALER_16_ID                            0x000'00F0

#define CHIP_CLOCK_PLL_1_PRESCALER_REG                              CHIP_REG_RCC_CFGR2
#define CHIP_CLOCK_PLL_1_PRESCALER_MASK                             0x000'000F
#define CHIP_CLOCK_PLL_1_PRESCALER_1_ID                             0x000'0000
#define CHIP_CLOCK_PLL_1_PRESCALER_2_ID                             0x000'0001
#define CHIP_CLOCK_PLL_1_PRESCALER_3_ID                             0x000'0002
#define CHIP_CLOCK_PLL_1_PRESCALER_4_ID                             0x000'0003
#define CHIP_CLOCK_PLL_1_PRESCALER_5_ID                             0x000'0004
#define CHIP_CLOCK_PLL_1_PRESCALER_6_ID                             0x000'0005
#define CHIP_CLOCK_PLL_1_PRESCALER_7_ID                             0x000'0006
#define CHIP_CLOCK_PLL_1_PRESCALER_8_ID                             0x000'0007
#define CHIP_CLOCK_PLL_1_PRESCALER_9_ID                             0x000'0008
#define CHIP_CLOCK_PLL_1_PRESCALER_10_ID                            0x000'0009
#define CHIP_CLOCK_PLL_1_PRESCALER_11_ID                            0x000'000A
#define CHIP_CLOCK_PLL_1_PRESCALER_12_ID                            0x000'000B
#define CHIP_CLOCK_PLL_1_PRESCALER_13_ID                            0x000'000C
#define CHIP_CLOCK_PLL_1_PRESCALER_14_ID                            0x000'000D
#define CHIP_CLOCK_PLL_1_PRESCALER_15_ID                            0x000'000E
#define CHIP_CLOCK_PLL_1_PRESCALER_16_ID                            0x000'000F

#define CHIP_CLOCK_SOURCE_REG                                       CHIP_REG_RCC_CFGR
#define CHIP_CLOCK_SOURCE_MASK                                      0x000'0003
#define CHIP_CLOCK_SOURCE_HIGH_SPEED_INTERNAL_ID                    0x000'0000
#define CHIP_CLOCK_SOURCE_HIGH_SPEED_EXTERNAL_ID                    0x000'0001
#define CHIP_CLOCK_SOURCE_PLL1_ID                                   0x000'0002

//------------------------------------------------
// IO ports

#define CHIP_PORT_A
#define CHIP_PORT_A_CLOCK_ENABLE_REG                                CHIP_REG_RCC_APB2ENR
#define CHIP_PORT_A_CLOCK_ENABLE_BIT                                2
#define CHIP_PORT_A_OUTPUT_REG                                      CHIP_REG_GPIOA_ODR
#define CHIP_PORT_A_OUTPUT_SET_REG                                  CHIP_REG_GPIOA_BSRR
#define CHIP_PORT_A_OUTPUT_CLEAR_REG                                CHIP_REG_GPIOA_BRR
#define CHIP_PORT_A_INPUT_REG                                       CHIP_REG_GPIOA_IDR

#define CHIP_PORT_B
#define CHIP_PORT_B_CLOCK_ENABLE_REG                                CHIP_REG_RCC_APB2ENR
#define CHIP_PORT_B_CLOCK_ENABLE_BIT                                3
#define CHIP_PORT_B_OUTPUT_REG                                      CHIP_REG_GPIOB_ODR
#define CHIP_PORT_B_OUTPUT_SET_REG                                  CHIP_REG_GPIOB_BSRR
#define CHIP_PORT_B_OUTPUT_CLEAR_REG                                CHIP_REG_GPIOB_BRR
#define CHIP_PORT_B_INPUT_REG                                       CHIP_REG_GPIOB_IDR

#define CHIP_PORT_C
#define CHIP_PORT_C_CLOCK_ENABLE_REG                                CHIP_REG_RCC_APB2ENR
#define CHIP_PORT_C_CLOCK_ENABLE_BIT                                4
#define CHIP_PORT_C_OUTPUT_REG                                      CHIP_REG_GPIOC_ODR
#define CHIP_PORT_C_OUTPUT_SET_REG                                  CHIP_REG_GPIOC_BSRR
#define CHIP_PORT_C_OUTPUT_CLEAR_REG                                CHIP_REG_GPIOC_BRR
#define CHIP_PORT_C_INPUT_REG                                       CHIP_REG_GPIOC_IDR

//------------------------------------------------
// IO Pins.

#define CHIP_PIN_A0
#define CHIP_PIN_A0_DIRECTION_REG                                   CHIP_REG_GPIOA_CRL
#define CHIP_PIN_A0_DIRECTION_MASK                                  0x0000'000F
#define CHIP_PIN_A0_DIRECTION_ANALOG_ID                             0x0000'0000
#define CHIP_PIN_A0_DIRECTION_INPUT_FLOAT_ID                        0x0000'0004
#define CHIP_PIN_A0_DIRECTION_INPUT_PULL_ID                         0x0000'0008
#define CHIP_PIN_A0_DIRECTION_OUTPUT_PUSH_PULL_2MHZ_ID              0x0000'0002
#define CHIP_PIN_A0_DIRECTION_OUTPUT_OPEN_DRAIN_2MHZ_ID             0x0000'0006
#define CHIP_PIN_A0_DIRECTION_OUTPUT_PUSH_PULL_10MHZ_ID             0x0000'0001
#define CHIP_PIN_A0_DIRECTION_OUTPUT_OPEN_DRAIN_10MHZ_ID            0x0000'0005
#define CHIP_PIN_A0_DIRECTION_OUTPUT_PUSH_PULL_50MHZ_ID             0x0000'0003
#define CHIP_PIN_A0_DIRECTION_OUTPUT_OPEN_DRAIN_50MHZ_ID            0x0000'0007
#define CHIP_PIN_A0_DIRECTION_ALT_OUTPUT_PUSH_PULL_2MHZ_ID          0x0000'000A
#define CHIP_PIN_A0_DIRECTION_ALT_OUTPUT_OPEN_DRAIN_2MHZ_ID         0x0000'000E
#define CHIP_PIN_A0_DIRECTION_ALT_OUTPUT_PUSH_PULL_10MHZ_ID         0x0000'0009
#define CHIP_PIN_A0_DIRECTION_ALT_OUTPUT_OPEN_DRAIN_10MHZ_ID        0x0000'000D
#define CHIP_PIN_A0_DIRECTION_ALT_OUTPUT_PUSH_PULL_50MHZ_ID         0x0000'000B
#define CHIP_PIN_A0_DIRECTION_ALT_OUTPUT_OPEN_DRAIN_50MHZ_ID        0x0000'000F
#define CHIP_PIN_A0_OUTPUT_SET_REG                                  CHIP_REG_GPIOA_BSRR
#define CHIP_PIN_A0_OUTPUT_SET_BIT                                  0
#define CHIP_PIN_A0_OUTPUT_CLEAR_REG                                CHIP_REG_GPIOA_BRR
#define CHIP_PIN_A0_OUTPUT_CLEAR_BIT                                0
#define CHIP_PIN_A0_INPUT_REG                                       CHIP_REG_GPIOA_IDR
#define CHIP_PIN_A0_INPUT_BIT                                       0

#define CHIP_PIN_C13
#define CHIP_PIN_C13_DIRECTION_REG                                   CHIP_REG_GPIOC_CRH
#define CHIP_PIN_C13_DIRECTION_MASK                                  0x00F0'0000
#define CHIP_PIN_C13_DIRECTION_ANALOG_ID                             0x0000'0000
#define CHIP_PIN_C13_DIRECTION_INPUT_FLOAT_ID                        0x0040'0000
#define CHIP_PIN_C13_DIRECTION_INPUT_PULL_ID                         0x0080'0000
#define CHIP_PIN_C13_DIRECTION_OUTPUT_PUSH_PULL_2MHZ_ID              0x0020'0000
#define CHIP_PIN_C13_DIRECTION_OUTPUT_OPEN_DRAIN_2MHZ_ID             0x0060'0000
#define CHIP_PIN_C13_DIRECTION_OUTPUT_PUSH_PULL_10MHZ_ID             0x0010'0000
#define CHIP_PIN_C13_DIRECTION_OUTPUT_OPEN_DRAIN_10MHZ_ID            0x0050'0000
#define CHIP_PIN_C13_DIRECTION_OUTPUT_PUSH_PULL_50MHZ_ID             0x0030'0000
#define CHIP_PIN_C13_DIRECTION_OUTPUT_OPEN_DRAIN_50MHZ_ID            0x0070'0000
#define CHIP_PIN_C13_DIRECTION_ALT_OUTPUT_PUSH_PULL_2MHZ_ID          0x00A0'0000
#define CHIP_PIN_C13_DIRECTION_ALT_OUTPUT_OPEN_DRAIN_2MHZ_ID         0x00E0'0000
#define CHIP_PIN_C13_DIRECTION_ALT_OUTPUT_PUSH_PULL_10MHZ_ID         0x0090'0000
#define CHIP_PIN_C13_DIRECTION_ALT_OUTPUT_OPEN_DRAIN_10MHZ_ID        0x00D0'0000
#define CHIP_PIN_C13_DIRECTION_ALT_OUTPUT_PUSH_PULL_50MHZ_ID         0x00B0'0000
#define CHIP_PIN_C13_DIRECTION_ALT_OUTPUT_OPEN_DRAIN_50MHZ_ID        0x00F0'0000
#define CHIP_PIN_C13_OUTPUT_SET_REG                                  CHIP_REG_GPIOC_BSRR
#define CHIP_PIN_C13_OUTPUT_SET_BIT                                  13
#define CHIP_PIN_C13_OUTPUT_CLEAR_REG                                CHIP_REG_GPIOC_BRR
#define CHIP_PIN_C13_OUTPUT_CLEAR_BIT                                13
#define CHIP_PIN_C13_INPUT_REG                                       CHIP_REG_GPIOC_IDR
#define CHIP_PIN_C13_INPUT_BIT                                       13

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

// #define CHIP_TIMER_2                                             true

// #define CHIP_TIMER_2_TYPE                                        uint16_t

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

// #define CHIP_TIMER_2_COUNTER_REG                                    CHIP_REG_TIM2_CNT

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

// #define CHIP_USART_1                                                true

// #define CHIP_USART_1_DATA_REG                                       CHIP_REG_USART_1_DR

// #define CHIP_USART_1_BAUD_RATE_REG                                  CHIP_REG_USART_1_BRR

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

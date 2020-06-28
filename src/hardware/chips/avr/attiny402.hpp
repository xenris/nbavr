#ifndef NBLIB_ATTINY402_HPP
#define NBLIB_ATTINY402_HPP

#define CHIP attiny402

// TODO
// 402 404 406 202 204 and others seem to be all nearly the same.
// Remove CHIP_RAM_SIZE (maybe use the linker defined version, if needed.)
// Then all the hardware descriptions should be very similar for these
// chips, allowing for reuse of hardware descriptions.

// TODO Voltage Reference, Usart, Port Multiplexer

//------------------------------------------------
// Memory

#define CHIP_RAM_SIZE                                               256

//------------------------------------------------
// Modules

#define CHIP_MODULE_VPORT_A_ADDR                                    0x0000
// This looks like a typo in the Microchip/Atmel docs. GPIO should be GPIOR
#define CHIP_MODULE_GPIO_ADDR                                       0x001C
#define CHIP_MODULE_CPU_ADDR                                        0x0030
#define CHIP_MODULE_RSTCTRL_ADDR                                    0x0040
#define CHIP_MODULE_SLPCTRL_ADDR                                    0x0050
#define CHIP_MODULE_CLKCTRL_ADDR                                    0x0060
#define CHIP_MODULE_BOD_ADDR                                        0x0080
#define CHIP_MODULE_VREF_ADDR                                       0x00A0
#define CHIP_MODULE_WDT_ADDR                                        0x0100
#define CHIP_MODULE_CPUINT_ADDR                                     0x0110
#define CHIP_MODULE_CRCSCAN_ADDR                                    0x0120
#define CHIP_MODULE_RTC_ADDR                                        0x0140
#define CHIP_MODULE_EVSYS_ADDR                                      0x0180
#define CHIP_MODULE_CCL_ADDR                                        0x01C0
#define CHIP_MODULE_PORTMUX_ADDR                                    0x0200
#define CHIP_MODULE_PORT_A_ADDR                                     0x0400
#define CHIP_MODULE_ADC0_ADDR                                       0x0600
#define CHIP_MODULE_AC0_ADDR                                        0x0680
#define CHIP_MODULE_USART0_ADDR                                     0x0800
#define CHIP_MODULE_TWI0_ADDR                                       0x0810
#define CHIP_MODULE_SPI0_ADDR                                       0x0820
#define CHIP_MODULE_TCA0_ADDR                                       0x0A00
#define CHIP_MODULE_TCB0_ADDR                                       0x0A40
#define CHIP_MODULE_SYSCFG_ADDR                                     0x0F00
#define CHIP_MODULE_NVMCTRL_ADDR                                    0x1000
#define CHIP_MODULE_SIGROW_ADDR                                     0x1100
#define CHIP_MODULE_FUSES_ADDR                                      0x1280
#define CHIP_MODULE_USERROW_ADDR                                    0x1300

//------------------------------------------------
// Vectors

#define vectorCrcFailure                                            ISR(__vector_1)
#define vectorBodVlm                                                ISR(__vector_2)
#define vectorPortA                                                 ISR(__vector_3)
#define vectorRtc                                                   ISR(__vector_6)
#define vectorRtcPit                                                ISR(__vector_7)
#define vectorTimer0Overflow                                        ISR(__vector_8)
#define vectorTimer0LowByteUnderflow                                ISR(__vector_8)
#define vectorTimer0HighByteUnderflow                               ISR(__vector_9)
#define vectorTimer0Compare0                                        ISR(__vector_10)
#define vectorTimer0Compare1                                        ISR(__vector_11)
#define vectorTimer0Compare2                                        ISR(__vector_12)
#define vectorTimer1                                                ISR(__vector_13)
#define vectorAc0                                                   ISR(__vector_16)
#define vectorAdc0Result                                            ISR(__vector_17)
#define vectorAdc0Window                                            ISR(__vector_18)
#define vectorTwi0Slave                                             ISR(__vector_19)
#define vectorTwi0Master                                            ISR(__vector_20)
#define vectorSpi0                                                  ISR(__vector_21)
#define vectorUsart0Rx                                              ISR(__vector_22)
#define vectorUsart0Dre                                             ISR(__vector_23)
#define vectorUsart0Tx                                              ISR(__vector_24)
#define vectorNvmEepromReady                                        ISR(__vector_25)

//------------------------------------------------
// System

#define CHIP_REG_SREG_ADDR                                          (CHIP_MODULE_CPU_ADDR + 0x0F)
#define CHIP_REG_SREG_TYPE                                          uint8_t

// Possibly need IDs for chips which have inhibit instead of enable.
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG                      CHIP_REG_SREG
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_BIT                      7

// //------------------------------------------------
// // Sleep

// #define CHIP_SLEEP_MODE_IDLE_ID                                     0
// #define CHIP_SLEEP_MODE_ADC_NOISE_REDUCTION_ID                      1
// #define CHIP_SLEEP_MODE_POWER_DOWN_ID                               2

// #define CHIP_SLEEP_MODE_BIT_0_REG                                   CHIP_REG_MCUCR
// #define CHIP_SLEEP_MODE_BIT_0_BIT                                   3
// #define CHIP_SLEEP_MODE_BIT_1_REG                                   CHIP_REG_MCUCR
// #define CHIP_SLEEP_MODE_BIT_1_BIT                                   4

// #define CHIP_SLEEP_ENABLE_BIT_0_REG                                 CHIP_REG_MCUCR
// #define CHIP_SLEEP_ENABLE_BIT_0_BIT                                 5

// // //------------------------------------------------
// // // Status Register

// // #define CHIP_STATUS_REG                                                 REG8(CHIP_ADDR_SREG)

// // //------------------------------------------------
// // // Reset Status Register

// // #define CHIP_RESET_STATUS_REG                                           REG8(CHIP_ADDR_MCUSR)

// // //------------------------------------------------
// // // Watchdog Timer

// // #define CHIP_WATCHDOG_TIMER_CONTROL_REG                                 REG8(CHIP_ADDR_WDTCR)
// // #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_0_BIT                         0
// // #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_1_BIT                         1
// // #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_2_BIT                         2
// // #define CHIP_WATCHDOG_TIMER_ENABLE_BIT                                  3
// // #define CHIP_WATCHDOG_TIMER_CHANGE_ENABLE_BIT                           4
// // #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_3_BIT                         5
// // #define CHIP_WATCHDOG_TIMER_INT_ENABLE_BIT                              6
// // #define CHIP_WATCHDOG_TIMER_INT_FLAG_BIT                                7

//------------------------------------------------
// IO ports

#define CHIP_REG_PORT_DIR_OFFSET                                    0x00
#define CHIP_REG_PORT_DIRSET_OFFSET                                 0x01
#define CHIP_REG_PORT_DIRCLR_OFFSET                                 0x02
#define CHIP_REG_PORT_DIRTGL_OFFSET                                 0x03
#define CHIP_REG_PORT_OUT_OFFSET                                    0x04
#define CHIP_REG_PORT_OUTSET_OFFSET                                 0x05
#define CHIP_REG_PORT_OUTCLR_OFFSET                                 0x06
#define CHIP_REG_PORT_OUTTGL_OFFSET                                 0x07
#define CHIP_REG_PORT_IN_OFFSET                                     0x08
#define CHIP_REG_PORT_INTFLAGS_OFFSET                               0x09
#define CHIP_REG_PORT_PIN0CTRL_OFFSET                               0x10
#define CHIP_REG_PORT_PIN1CTRL_OFFSET                               0x11
#define CHIP_REG_PORT_PIN2CTRL_OFFSET                               0x12
#define CHIP_REG_PORT_PIN3CTRL_OFFSET                               0x13
#define CHIP_REG_PORT_PIN4CTRL_OFFSET                               0x14
#define CHIP_REG_PORT_PIN5CTRL_OFFSET                               0x15
#define CHIP_REG_PORT_PIN6CTRL_OFFSET                               0x16
#define CHIP_REG_PORT_PIN7CTRL_OFFSET                               0x17

#define CHIP_REG_PORT_A_DIR_ADDR                                    (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_DIR_OFFSET)
#define CHIP_REG_PORT_A_DIR_TYPE                                    uint8_t
#define CHIP_REG_PORT_A_DIRSET_ADDR                                 (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_DIRSET_OFFSET)
#define CHIP_REG_PORT_A_DIRSET_TYPE                                 uint8_t
#define CHIP_REG_PORT_A_DIRCLR_ADDR                                 (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_DIRCLR_OFFSET)
#define CHIP_REG_PORT_A_DIRCLR_TYPE                                 uint8_t
#define CHIP_REG_PORT_A_DIRTGL_ADDR                                 (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_DIRTGL_OFFSET)
#define CHIP_REG_PORT_A_DIRTGL_TYPE                                 uint8_t
#define CHIP_REG_PORT_A_OUT_ADDR                                    (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_OUT_OFFSET)
#define CHIP_REG_PORT_A_OUT_TYPE                                    uint8_t
#define CHIP_REG_PORT_A_OUTSET_ADDR                                 (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_OUTSET_OFFSET)
#define CHIP_REG_PORT_A_OUTSET_TYPE                                 uint8_t
#define CHIP_REG_PORT_A_OUTCLR_ADDR                                 (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_OUTCLR_OFFSET)
#define CHIP_REG_PORT_A_OUTCLR_TYPE                                 uint8_t
#define CHIP_REG_PORT_A_OUTTGL_ADDR                                 (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_OUTTGL_OFFSET)
#define CHIP_REG_PORT_A_OUTTGL_TYPE                                 uint8_t
#define CHIP_REG_PORT_A_IN_ADDR                                     (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_IN_OFFSET)
#define CHIP_REG_PORT_A_IN_TYPE                                     uint8_t
#define CHIP_REG_PORT_A_INTFLAGS_ADDR                               (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_INTFLAGS_OFFSET)
#define CHIP_REG_PORT_A_INTFLAGS_TYPE                               uint8_t
#define CHIP_REG_PORT_A_PIN0CTRL_ADDR                               (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_PIN0CTRL_OFFSET)
#define CHIP_REG_PORT_A_PIN0CTRL_TYPE                               uint8_t
#define CHIP_REG_PORT_A_PIN1CTRL_ADDR                               (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_PIN1CTRL_OFFSET)
#define CHIP_REG_PORT_A_PIN1CTRL_TYPE                               uint8_t
#define CHIP_REG_PORT_A_PIN2CTRL_ADDR                               (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_PIN2CTRL_OFFSET)
#define CHIP_REG_PORT_A_PIN2CTRL_TYPE                               uint8_t
#define CHIP_REG_PORT_A_PIN3CTRL_ADDR                               (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_PIN3CTRL_OFFSET)
#define CHIP_REG_PORT_A_PIN3CTRL_TYPE                               uint8_t
#define CHIP_REG_PORT_A_PIN4CTRL_ADDR                               (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_PIN4CTRL_OFFSET)
#define CHIP_REG_PORT_A_PIN4CTRL_TYPE                               uint8_t
#define CHIP_REG_PORT_A_PIN5CTRL_ADDR                               (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_PIN5CTRL_OFFSET)
#define CHIP_REG_PORT_A_PIN5CTRL_TYPE                               uint8_t
#define CHIP_REG_PORT_A_PIN6CTRL_ADDR                               (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_PIN6CTRL_OFFSET)
#define CHIP_REG_PORT_A_PIN6CTRL_TYPE                               uint8_t
#define CHIP_REG_PORT_A_PIN7CTRL_ADDR                               (CHIP_MODULE_PORT_A_ADDR + CHIP_REG_PORT_PIN7CTRL_OFFSET)
#define CHIP_REG_PORT_A_PIN7CTRL_TYPE                               uint8_t

#define CHIP_REG_VPORT_DIR_OFFSET                                    0x00
#define CHIP_REG_VPORT_OUT_OFFSET                                    0x01
#define CHIP_REG_VPORT_IN_OFFSET                                     0x02
#define CHIP_REG_VPORT_INTFLAGS_OFFSET                               0x03

#define CHIP_REG_VPORT_A_DIR_ADDR                                   (CHIP_MODULE_VPORT_A_ADDR + CHIP_REG_VPORT_DIR_OFFSET)
#define CHIP_REG_VPORT_A_DIR_TYPE                                   uint8_t
#define CHIP_REG_VPORT_A_OUT_ADDR                                   (CHIP_MODULE_VPORT_A_ADDR + CHIP_REG_VPORT_OUT_OFFSET)
#define CHIP_REG_VPORT_A_OUT_TYPE                                   uint8_t
#define CHIP_REG_VPORT_A_IN_ADDR                                    (CHIP_MODULE_VPORT_A_ADDR + CHIP_REG_VPORT_IN_OFFSET)
#define CHIP_REG_VPORT_A_IN_TYPE                                    uint8_t
#define CHIP_REG_VPORT_A_INTFLAGS_ADDR                              (CHIP_MODULE_VPORT_A_ADDR + CHIP_REG_VPORT_INTFLAGS_OFFSET)
#define CHIP_REG_VPORT_A_INTFLAGS_TYPE                              uint8_t

#define CHIP_PORT_A                                                 true
// #define CHIP_PORT_A_DIRECTION_REG
// #define CHIP_PORT_A_DIRECTION_SET_REG
// #define CHIP_PORT_A_DIRECTION_CLEAR_REG
// #define CHIP_PORT_A_DIRECTION_TOGGLE_REG
// #define CHIP_PORT_A_OUTPUT_REG                                      CHIP_REG_PORT_A_OUT
// #define CHIP_PORT_A_OUTPUT_SET_REG
// #define CHIP_PORT_A_OUTPUT_CLEAR_REG
// #define CHIP_PORT_A_OUTPUT_TOGGLE_REG
// #define CHIP_PORT_A_INPUT_REG
// #define CHIP_PORT_A_INT_FLAG_REG

// #define CHIP_PORT_A                                                 true
// #define CHIP_PORT_A_CLOCK_ENABLE_REG                                CHIP_REG_APB2
// #define CHIP_PORT_A_CLOCK_ENABLE_BIT                                2
// #define CHIP_PORT_A_OUTPUT_REG                                      CHIP_REG_PORT_A_ODR
// #define CHIP_PORT_A_SET_OUTPUTS_REG                                 CHIP_REG_PORT_A_BSRR_SET
// #define CHIP_PORT_A_CLEAR_OUTPUTS_REG                               CHIP_REG_PORT_A_BSRR_CLEAR
// #define CHIP_PORT_A_INPUT_REG                                       CHIP_REG_PORT_A_IDR

//------------------------------------------------
// IO pins

#define CHIP_PIN_A0                                                 true
#define CHIP_PIN_A0_DIRECTION_BIT_0_BIT                             0
#define CHIP_PIN_A0_DIRECTION_BIT_0_REG                             CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_A0_OUTPUT_BIT_0_REG                                CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_A0_INPUT_BIT_0_REG                                 CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A0_PULLUP_BIT_0_BIT                                3
#define CHIP_PIN_A0_PULLUP_BIT_0_REG                                CHIP_REG_PORT_A_PIN0CTRL

#define CHIP_PIN_A1                                                 true
#define CHIP_PIN_A1_DIRECTION_BIT_0_BIT                             1
#define CHIP_PIN_A1_DIRECTION_BIT_0_REG                             CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_A1_OUTPUT_BIT_0_REG                                CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_A1_INPUT_BIT_0_REG                                 CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A1_PULLUP_BIT_0_BIT                                3
#define CHIP_PIN_A1_PULLUP_BIT_0_REG                                CHIP_REG_PORT_A_PIN1CTRL

#define CHIP_PIN_A2                                                 true
#define CHIP_PIN_A2_DIRECTION_BIT_0_BIT                             2
#define CHIP_PIN_A2_DIRECTION_BIT_0_REG                             CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_A2_OUTPUT_BIT_0_REG                                CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_A2_INPUT_BIT_0_REG                                 CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A2_PULLUP_BIT_0_BIT                                3
#define CHIP_PIN_A2_PULLUP_BIT_0_REG                                CHIP_REG_PORT_A_PIN2CTRL

#define CHIP_PIN_A3                                                 true
#define CHIP_PIN_A3_DIRECTION_BIT_0_BIT                             3
#define CHIP_PIN_A3_DIRECTION_BIT_0_REG                             CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_A3_OUTPUT_BIT_0_REG                                CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_A3_INPUT_BIT_0_REG                                 CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A3_PULLUP_BIT_0_BIT                                3
#define CHIP_PIN_A3_PULLUP_BIT_0_REG                                CHIP_REG_PORT_A_PIN3CTRL

#define CHIP_PIN_A6                                                 true
#define CHIP_PIN_A6_DIRECTION_BIT_0_BIT                             6
#define CHIP_PIN_A6_DIRECTION_BIT_0_REG                             CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_A6_OUTPUT_BIT_0_REG                                CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_A6_INPUT_BIT_0_REG                                 CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A6_PULLUP_BIT_0_BIT                                3
#define CHIP_PIN_A6_PULLUP_BIT_0_REG                                CHIP_REG_PORT_A_PIN6CTRL

#define CHIP_PIN_A7                                                 true
#define CHIP_PIN_A7_DIRECTION_BIT_0_BIT                             7
#define CHIP_PIN_A7_DIRECTION_BIT_0_REG                             CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_A7_OUTPUT_BIT_0_REG                                CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_A7_INPUT_BIT_0_REG                                 CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A7_PULLUP_BIT_0_BIT                                3
#define CHIP_PIN_A7_PULLUP_BIT_0_REG                                CHIP_REG_PORT_A_PIN7CTRL

//------------------------------------------------
// Analog to digital converters

// TODO
// #define CHIP_REG_ADC_0_CTRLA_ADDR                                       (CHIP_MODULE_ADC0_ADDR + 0x00)

#define CHIP_ADC_0_CTRLA_ADDR                                       (CHIP_MODULE_ADC0_ADDR + 0x00)
#define CHIP_ADC_0_CTRLA_TYPE                                       uint8_t
#define CHIP_ADC_0_CTRLB_ADDR                                       (CHIP_MODULE_ADC0_ADDR + 0x01)
#define CHIP_ADC_0_CTRLB_TYPE                                       uint8_t
#define CHIP_ADC_0_CTRLC_ADDR                                       (CHIP_MODULE_ADC0_ADDR + 0x02)
#define CHIP_ADC_0_CTRLC_TYPE                                       uint8_t
#define CHIP_ADC_0_CTRLD_ADDR                                       (CHIP_MODULE_ADC0_ADDR + 0x03)
#define CHIP_ADC_0_CTRLD_TYPE                                       uint8_t
#define CHIP_ADC_0_CTRLE_ADDR                                       (CHIP_MODULE_ADC0_ADDR + 0x04)
#define CHIP_ADC_0_CTRLE_TYPE                                       uint8_t
#define CHIP_ADC_0_SAMPCTRL_ADDR                                    (CHIP_MODULE_ADC0_ADDR + 0x05)
#define CHIP_ADC_0_SAMPCTRL_TYPE                                    uint8_t
#define CHIP_ADC_0_MUXPOS_ADDR                                      (CHIP_MODULE_ADC0_ADDR + 0x06)
#define CHIP_ADC_0_MUXPOS_TYPE                                      uint8_t
#define CHIP_ADC_0_COMMAND_ADDR                                     (CHIP_MODULE_ADC0_ADDR + 0x08)
#define CHIP_ADC_0_COMMAND_TYPE                                     uint8_t
#define CHIP_ADC_0_EVCTRL_ADDR                                      (CHIP_MODULE_ADC0_ADDR + 0x09)
#define CHIP_ADC_0_EVCTRL_TYPE                                      uint8_t
#define CHIP_ADC_0_INTCTRL_ADDR                                     (CHIP_MODULE_ADC0_ADDR + 0x0A)
#define CHIP_ADC_0_INTCTRL_TYPE                                     uint8_t
#define CHIP_ADC_0_INTFLAGS_ADDR                                    (CHIP_MODULE_ADC0_ADDR + 0x0B)
#define CHIP_ADC_0_INTFLAGS_TYPE                                    uint8_t
#define CHIP_ADC_0_DBGCTRL_ADDR                                     (CHIP_MODULE_ADC0_ADDR + 0x0C)
#define CHIP_ADC_0_DBGCTRL_TYPE                                     uint8_t
#define CHIP_ADC_0_TEMP_ADDR                                        (CHIP_MODULE_ADC0_ADDR + 0x0D)
#define CHIP_ADC_0_TEMP_TYPE                                        uint8_t
#define CHIP_ADC_0_RES_ADDR                                         (CHIP_MODULE_ADC0_ADDR + 0x10)
#define CHIP_ADC_0_RES_TYPE                                         uint16_t
#define CHIP_ADC_0_WINLT_ADDR                                       (CHIP_MODULE_ADC0_ADDR + 0x12)
#define CHIP_ADC_0_WINLT_TYPE                                       uint16_t
#define CHIP_ADC_0_WINHT_ADDR                                       (CHIP_MODULE_ADC0_ADDR + 0x14)
#define CHIP_ADC_0_WINHT_TYPE                                       uint16_t
#define CHIP_ADC_0_CALIB_ADDR                                       (CHIP_MODULE_ADC0_ADDR + 0x16)
#define CHIP_ADC_0_CALIB_TYPE                                       uint8_t

#define CHIP_ADC_0                                                  true

#define CHIP_ADC_0_RESULT_REG                                       CHIP_ADC_0_RES

#define CHIP_ADC_0_ENABLE_BIT_0_REG                                 CHIP_ADC_0_CTRLA
#define CHIP_ADC_0_ENABLE_BIT_0_BIT                                 0

#define CHIP_ADC_0_START_BIT_0_REG                                  CHIP_ADC_0_COMMAND
#define CHIP_ADC_0_START_BIT_0_BIT                                  0

#define CHIP_ADC_0_REFERENCE_BIT_0_REG                              CHIP_ADC_0_CTRLC
#define CHIP_ADC_0_REFERENCE_BIT_1_REG                              CHIP_ADC_0_CTRLC
#define CHIP_ADC_0_REFERENCE_BIT_0_BIT                              4
#define CHIP_ADC_0_REFERENCE_BIT_1_BIT                              5
#define CHIP_ADC_0_REFERENCE_INTERNAL_ID                            0
#define CHIP_ADC_0_REFERENCE_VDD_ID                                 1

#define CHIP_ADC_0_CHANNEL_BIT_0_REG                                CHIP_ADC_0_MUXPOS
#define CHIP_ADC_0_CHANNEL_BIT_1_REG                                CHIP_ADC_0_MUXPOS
#define CHIP_ADC_0_CHANNEL_BIT_2_REG                                CHIP_ADC_0_MUXPOS
#define CHIP_ADC_0_CHANNEL_BIT_3_REG                                CHIP_ADC_0_MUXPOS
#define CHIP_ADC_0_CHANNEL_BIT_4_REG                                CHIP_ADC_0_MUXPOS
#define CHIP_ADC_0_CHANNEL_BIT_0_BIT                                0
#define CHIP_ADC_0_CHANNEL_BIT_1_BIT                                1
#define CHIP_ADC_0_CHANNEL_BIT_2_BIT                                2
#define CHIP_ADC_0_CHANNEL_BIT_3_BIT                                3
#define CHIP_ADC_0_CHANNEL_BIT_4_BIT                                4
#define CHIP_ADC_0_CHANNEL_0_ID                                     0
#define CHIP_ADC_0_CHANNEL_1_ID                                     1
#define CHIP_ADC_0_CHANNEL_2_ID                                     2
#define CHIP_ADC_0_CHANNEL_3_ID                                     3
#define CHIP_ADC_0_CHANNEL_6_ID                                     6
#define CHIP_ADC_0_CHANNEL_7_ID                                     7
#define CHIP_ADC_0_CHANNEL_INTERNAL_ID                              29
#define CHIP_ADC_0_CHANNEL_TEMPERATURE_ID                           30
#define CHIP_ADC_0_CHANNEL_GND_ID                                   31

#define CHIP_ADC_0_TRIGGER_BIT_0_REG                                CHIP_ADC_0_CTRLA
#define CHIP_ADC_0_TRIGGER_BIT_1_REG                                CHIP_ADC_0_EVCTRL
#define CHIP_ADC_0_TRIGGER_BIT_0_BIT                                1
#define CHIP_ADC_0_TRIGGER_BIT_1_BIT                                0
#define CHIP_ADC_0_TRIGGER_SINGLE_CONVERSION_ID                     0
#define CHIP_ADC_0_TRIGGER_FREE_RUNNING_ID                          1
#define CHIP_ADC_0_TRIGGER_EVENT_ID                                 2

#define CHIP_ADC_0_INT_FLAG_BIT_0_REG                               CHIP_ADC_0_INTFLAGS
#define CHIP_ADC_0_INT_FLAG_BIT_0_BIT                               0

#define CHIP_ADC_0_INT_ENABLE_BIT_0_REG                             CHIP_ADC_0_INTCTRL
#define CHIP_ADC_0_INT_ENABLE_BIT_0_BIT                             0

#define CHIP_ADC_0_PRESCALER_BIT_0_REG                              CHIP_ADC_0_CTRLC
#define CHIP_ADC_0_PRESCALER_BIT_1_REG                              CHIP_ADC_0_CTRLC
#define CHIP_ADC_0_PRESCALER_BIT_2_REG                              CHIP_ADC_0_CTRLC
#define CHIP_ADC_0_PRESCALER_BIT_0_BIT                              0
#define CHIP_ADC_0_PRESCALER_BIT_1_BIT                              1
#define CHIP_ADC_0_PRESCALER_BIT_2_BIT                              2
#define CHIP_ADC_0_PRESCALER_2_ID                                   0
#define CHIP_ADC_0_PRESCALER_4_ID                                   1
#define CHIP_ADC_0_PRESCALER_8_ID                                   2
#define CHIP_ADC_0_PRESCALER_16_ID                                  3
#define CHIP_ADC_0_PRESCALER_32_ID                                  4
#define CHIP_ADC_0_PRESCALER_64_ID                                  5
#define CHIP_ADC_0_PRESCALER_128_ID                                 6
#define CHIP_ADC_0_PRESCALER_256_ID                                 7

// //------------------------------------------------
// // External interrupts

// #define CHIP_EXINT_0                                                true
// #define CHIP_EXINT_0_ENABLE_BIT_0_REG                               CHIP_REG_GIMSK
// #define CHIP_EXINT_0_ENABLE_BIT_0_BIT                               6
// #define CHIP_EXINT_0_INT_FLAG_BIT_0_REG                             CHIP_REG_GIFR
// #define CHIP_EXINT_0_INT_FLAG_BIT_0_BIT                             6
// #define CHIP_EXINT_0_TRIGGER_BIT_0_REG                              CHIP_REG_MCUCR
// #define CHIP_EXINT_0_TRIGGER_BIT_1_REG                              CHIP_REG_MCUCR
// #define CHIP_EXINT_0_TRIGGER_BIT_0_BIT                              0
// #define CHIP_EXINT_0_TRIGGER_BIT_1_BIT                              1
// #define CHIP_EXINT_0_TRIGGER_LOW_ID                                 0
// #define CHIP_EXINT_0_TRIGGER_CHANGE_ID                              1
// #define CHIP_EXINT_0_TRIGGER_FALLING_ID                             2
// #define CHIP_EXINT_0_TRIGGER_RISING_ID                              3
// #define CHIP_EXINT_0_INT_VECTOR                                     VECT(CHIP_VECT_INT0)

// //------------------------------------------------
// // Pin change interrupts

// #define CHIP_PCINT_0                                                true
// #define CHIP_PCINT_0_ENABLE_BIT_0_REG                               CHIP_REG_GIMSK
// #define CHIP_PCINT_0_ENABLE_BIT_0_BIT                               5
// #define CHIP_PCINT_0_INT_FLAG_BIT_0_REG                             CHIP_REG_GIFR
// #define CHIP_PCINT_0_INT_FLAG_BIT_0_BIT                             6
// #define CHIP_PCINT_0_MASK_REG                                       CHIP_REG_PCMSK
// #define CHIP_PCINT_0_INT_VECTOR                                     VECT(CHIP_VECT_PCINT0)

//------------------------------------------------
// Timers

#define CHIP_REG_TIMER_0_CTRLA_ADDR                                 (CHIP_MODULE_TCA0_ADDR + 0x00)
#define CHIP_REG_TIMER_0_CTRLA_TYPE                                 uint8_t
#define CHIP_REG_TIMER_0_CTRLB_ADDR                                 (CHIP_MODULE_TCA0_ADDR + 0x01)
#define CHIP_REG_TIMER_0_CTRLB_TYPE                                 uint8_t
#define CHIP_REG_TIMER_0_CTRLC_ADDR                                 (CHIP_MODULE_TCA0_ADDR + 0x02)
#define CHIP_REG_TIMER_0_CTRLC_TYPE                                 uint8_t
#define CHIP_REG_TIMER_0_CTRLD_ADDR                                 (CHIP_MODULE_TCA0_ADDR + 0x03)
#define CHIP_REG_TIMER_0_CTRLD_TYPE                                 uint8_t
#define CHIP_REG_TIMER_0_CTRLECLR_ADDR                              (CHIP_MODULE_TCA0_ADDR + 0x04)
#define CHIP_REG_TIMER_0_CTRLECLR_TYPE                              uint8_t
#define CHIP_REG_TIMER_0_CTRLESET_ADDR                              (CHIP_MODULE_TCA0_ADDR + 0x05)
#define CHIP_REG_TIMER_0_CTRLESET_TYPE                              uint8_t
#define CHIP_REG_TIMER_0_CTRLFCLR_ADDR                              (CHIP_MODULE_TCA0_ADDR + 0x06)
#define CHIP_REG_TIMER_0_CTRLFCLR_TYPE                              uint8_t
#define CHIP_REG_TIMER_0_CTRLFSET_ADDR                              (CHIP_MODULE_TCA0_ADDR + 0x07)
#define CHIP_REG_TIMER_0_CTRLFSET_TYPE                              uint8_t
#define CHIP_REG_TIMER_0_EVCTRL_ADDR                                (CHIP_MODULE_TCA0_ADDR + 0x09)
#define CHIP_REG_TIMER_0_EVCTRL_TYPE                                uint8_t
#define CHIP_REG_TIMER_0_INTCTRL_ADDR                               (CHIP_MODULE_TCA0_ADDR + 0x0A)
#define CHIP_REG_TIMER_0_INTCTRL_TYPE                               uint8_t
#define CHIP_REG_TIMER_0_INTFLAGS_ADDR                              (CHIP_MODULE_TCA0_ADDR + 0x0B)
#define CHIP_REG_TIMER_0_INTFLAGS_TYPE                              uint8_t
#define CHIP_REG_TIMER_0_DBGCTRL_ADDR                               (CHIP_MODULE_TCA0_ADDR + 0x0E)
#define CHIP_REG_TIMER_0_DBGCTRL_TYPE                               uint8_t
#define CHIP_REG_TIMER_0_TEMP_ADDR                                  (CHIP_MODULE_TCA0_ADDR + 0x0F)
#define CHIP_REG_TIMER_0_TEMP_TYPE                                  uint8_t
#define CHIP_REG_TIMER_0_CNT_ADDR                                   (CHIP_MODULE_TCA0_ADDR + 0x20)
#define CHIP_REG_TIMER_0_CNT_TYPE                                   uint16_t
#define CHIP_REG_TIMER_0_PER_ADDR                                   (CHIP_MODULE_TCA0_ADDR + 0x26)
#define CHIP_REG_TIMER_0_PER_TYPE                                   uint16_t
#define CHIP_REG_TIMER_0_CMP0_ADDR                                  (CHIP_MODULE_TCA0_ADDR + 0x28)
#define CHIP_REG_TIMER_0_CMP0_TYPE                                  uint16_t
#define CHIP_REG_TIMER_0_CMP1_ADDR                                  (CHIP_MODULE_TCA0_ADDR + 0x2A)
#define CHIP_REG_TIMER_0_CMP1_TYPE                                  uint16_t
#define CHIP_REG_TIMER_0_CMP2_ADDR                                  (CHIP_MODULE_TCA0_ADDR + 0x2C)
#define CHIP_REG_TIMER_0_CMP2_TYPE                                  uint16_t
#define CHIP_REG_TIMER_0_PERBUF_ADDR                                (CHIP_MODULE_TCA0_ADDR + 0x36)
#define CHIP_REG_TIMER_0_PERBUF_TYPE                                uint16_t
#define CHIP_REG_TIMER_0_CMP0nBUF_ADDR                              (CHIP_MODULE_TCA0_ADDR + 0x38)
#define CHIP_REG_TIMER_0_CMP0nBUF_TYPE                              uint16_t
#define CHIP_REG_TIMER_0_CMP1nBUF_ADDR                              (CHIP_MODULE_TCA0_ADDR + 0x3A)
#define CHIP_REG_TIMER_0_CMP1nBUF_TYPE                              uint16_t
#define CHIP_REG_TIMER_0_CMP2nBUF_ADDR                              (CHIP_MODULE_TCA0_ADDR + 0x3C)
#define CHIP_REG_TIMER_0_CMP2nBUF_TYPE                              uint16_t

#define CHIP_TIMER_0                                                true

#define CHIP_TIMER_0_COUNTER_REG                                    CHIP_REG_TIMER_0_CNT

#define CHIP_TIMER_0_TOP_REG                                        CHIP_REG_TIMER_0_PER

#define CHIP_TIMER_0_WAVEFORM_BIT_0_REG                             CHIP_REG_TIMER_0_CTRLB
#define CHIP_TIMER_0_WAVEFORM_BIT_1_REG                             CHIP_REG_TIMER_0_CTRLB
#define CHIP_TIMER_0_WAVEFORM_BIT_2_REG                             CHIP_REG_TIMER_0_CTRLB
#define CHIP_TIMER_0_WAVEFORM_BIT_0_BIT                             0
#define CHIP_TIMER_0_WAVEFORM_BIT_1_BIT                             1
#define CHIP_TIMER_0_WAVEFORM_BIT_2_BIT                             2
#define CHIP_TIMER_0_WAVEFORM_NORMAL_ID                             0
#define CHIP_TIMER_0_WAVEFORM_FREQUENCY_ID                          1
#define CHIP_TIMER_0_WAVEFORM_SINGLE_SLOPE_PWM_ID                   3
#define CHIP_TIMER_0_WAVEFORM_DUAL_SLOPE_PWM_OVF_TOP_ID             5
#define CHIP_TIMER_0_WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTH_ID            6
#define CHIP_TIMER_0_WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTTOM_ID          7

#define CHIP_TIMER_0_CLOCK_1_ID                                     0
#define CHIP_TIMER_0_CLOCK_2_ID                                     1
#define CHIP_TIMER_0_CLOCK_4_ID                                     2
#define CHIP_TIMER_0_CLOCK_8_ID                                     3
#define CHIP_TIMER_0_CLOCK_16_ID                                    4
#define CHIP_TIMER_0_CLOCK_64_ID                                    5
#define CHIP_TIMER_0_CLOCK_256_ID                                   6
#define CHIP_TIMER_0_CLOCK_1024_ID                                  7
#define CHIP_TIMER_0_CLOCK_BIT_0_REG                                CHIP_REG_TIMER_0_CTRLA
#define CHIP_TIMER_0_CLOCK_BIT_1_REG                                CHIP_REG_TIMER_0_CTRLA
#define CHIP_TIMER_0_CLOCK_BIT_2_REG                                CHIP_REG_TIMER_0_CTRLA
#define CHIP_TIMER_0_CLOCK_BIT_0_BIT                                1
#define CHIP_TIMER_0_CLOCK_BIT_1_BIT                                2
#define CHIP_TIMER_0_CLOCK_BIT_2_BIT                                3

#define CHIP_TIMER_0_ENABLE_REG                                     CHIP_REG_TIMER_0_CTRLA
#define CHIP_TIMER_0_ENABLE_BIT                                     0

#define CHIP_TIMER_0_COMPARE_A_OUTPUT_ENABLE_REG                    CHIP_REG_TIMER_0_CTRLB
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_ENABLE_BIT                    4
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_ENABLE_REG                    CHIP_REG_TIMER_0_CTRLB
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_ENABLE_BIT                    5
#define CHIP_TIMER_0_COMPARE_C_OUTPUT_ENABLE_REG                    CHIP_REG_TIMER_0_CTRLB
#define CHIP_TIMER_0_COMPARE_C_OUTPUT_ENABLE_BIT                    6

#define CHIP_TIMER_0_COMPARE_A_INT_ENABLE_REG                       CHIP_REG_TIMER_0_INTCTRL
#define CHIP_TIMER_0_COMPARE_A_INT_ENABLE_BIT                       4
#define CHIP_TIMER_0_COMPARE_B_INT_ENABLE_REG                       CHIP_REG_TIMER_0_INTCTRL
#define CHIP_TIMER_0_COMPARE_B_INT_ENABLE_BIT                       5
#define CHIP_TIMER_0_COMPARE_C_INT_ENABLE_REG                       CHIP_REG_TIMER_0_INTCTRL
#define CHIP_TIMER_0_COMPARE_C_INT_ENABLE_BIT                       6

#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMER_0_INTCTRL
#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                        0

#define CHIP_TIMER_0_COMPARE_A_INT_FLAG_REG                         CHIP_REG_TIMER_0_INTFLAGS
#define CHIP_TIMER_0_COMPARE_A_INT_FLAG_BIT                         4
#define CHIP_TIMER_0_COMPARE_B_INT_FLAG_REG                         CHIP_REG_TIMER_0_INTFLAGS
#define CHIP_TIMER_0_COMPARE_B_INT_FLAG_BIT                         5
#define CHIP_TIMER_0_COMPARE_C_INT_FLAG_REG                         CHIP_REG_TIMER_0_INTFLAGS
#define CHIP_TIMER_0_COMPARE_C_INT_FLAG_BIT                         6

#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIMER_0_INTFLAGS
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_BIT                          0

#define CHIP_TIMER_0_COMPARE_A_REG                                  CHIP_REG_TIMER_0_CMP0
#define CHIP_TIMER_0_COMPARE_B_REG                                  CHIP_REG_TIMER_0_CMP1
#define CHIP_TIMER_0_COMPARE_C_REG                                  CHIP_REG_TIMER_0_CMP2

// //------------------------------------------------

// #define CHIP_TIMER_1                                                true

// #define CHIP_TIMER_1_TYPE                                           uint8_t

// #define CHIP_TIMER_1_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR1
// #define CHIP_TIMER_1_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR1
// #define CHIP_TIMER_1_WAVEFORM_BIT_2_REG                             CHIP_REG_GTCCR
// #define CHIP_TIMER_1_WAVEFORM_BIT_0_BIT                             6
// #define CHIP_TIMER_1_WAVEFORM_BIT_1_BIT                             7
// #define CHIP_TIMER_1_WAVEFORM_BIT_2_BIT                             6
// #define CHIP_TIMER_1_WAVEFORM_NORMAL_ID                             0
// #define CHIP_TIMER_1_WAVEFORM_FAST_PWM_A_OCRC_ID                    1
// #define CHIP_TIMER_1_WAVEFORM_CTC_OCRC_ID                           2
// #define CHIP_TIMER_1_WAVEFORM_FAST_PWM_B_OCRC_ID                    4
// #define CHIP_TIMER_1_WAVEFORM_FAST_PWM_A_B_OCRC_ID                  5

// #define CHIP_TIMER_1_CLOCK_BIT_0_REG                                CHIP_REG_TCCR1
// #define CHIP_TIMER_1_CLOCK_BIT_1_REG                                CHIP_REG_TCCR1
// #define CHIP_TIMER_1_CLOCK_BIT_2_REG                                CHIP_REG_TCCR1
// #define CHIP_TIMER_1_CLOCK_BIT_3_REG                                CHIP_REG_TCCR1
// #define CHIP_TIMER_1_CLOCK_BIT_0_BIT                                0
// #define CHIP_TIMER_1_CLOCK_BIT_1_BIT                                1
// #define CHIP_TIMER_1_CLOCK_BIT_2_BIT                                2
// #define CHIP_TIMER_1_CLOCK_BIT_3_BIT                                3
// #define CHIP_TIMER_1_CLOCK_NONE_ID                                  0
// #define CHIP_TIMER_1_CLOCK_1_ID                                     1
// #define CHIP_TIMER_1_CLOCK_2_ID                                     2
// #define CHIP_TIMER_1_CLOCK_4_ID                                     3
// #define CHIP_TIMER_1_CLOCK_8_ID                                     4
// #define CHIP_TIMER_1_CLOCK_16_ID                                    5
// #define CHIP_TIMER_1_CLOCK_32_ID                                    6
// #define CHIP_TIMER_1_CLOCK_64_ID                                    7
// #define CHIP_TIMER_1_CLOCK_128_ID                                   8
// #define CHIP_TIMER_1_CLOCK_256_ID                                   9
// #define CHIP_TIMER_1_CLOCK_512_ID                                   10
// #define CHIP_TIMER_1_CLOCK_1024_ID                                  11
// #define CHIP_TIMER_1_CLOCK_2048_ID                                  12
// #define CHIP_TIMER_1_CLOCK_4096_ID                                  13
// #define CHIP_TIMER_1_CLOCK_8192_ID                                  14
// #define CHIP_TIMER_1_CLOCK_16384_ID                                 15

// #define CHIP_TIMER_1_COUNTER_REG                                    CHIP_REG_TCNT1

// #define CHIP_TIMER_1_OUTPUT_A                                       true
// #define CHIP_TIMER_1_OUTPUT_A_PIN                                   PortB::Pin1
// #define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_0_REG                        CHIP_REG_TCCR1
// #define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_1_REG                        CHIP_REG_TCCR1
// #define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_0_BIT                        4
// #define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_1_BIT                        5
// #define CHIP_TIMER_1_OUTPUT_A_MODE_DISCONNECTED_ID                  0
// #define CHIP_TIMER_1_OUTPUT_A_MODE_TOGGLE_ID                        1
// #define CHIP_TIMER_1_OUTPUT_A_MODE_CLEAR_ID                         2
// #define CHIP_TIMER_1_OUTPUT_A_MODE_SET_ID                           3
// #define CHIP_TIMER_1_OUTPUT_A_REG                                   CHIP_REG_OCR1A
// #define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK
// #define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_BIT                        6
// #define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR
// #define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_BIT                          6
// #define CHIP_TIMER_1_OUTPUT_A_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_COMPA)

// #define CHIP_TIMER_1_OUTPUT_B                                       true
// #define CHIP_TIMER_1_OUTPUT_B_PIN                                   PortB::Pin4
// #define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_0_REG                        CHIP_REG_GTCCR
// #define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_1_REG                        CHIP_REG_GTCCR
// #define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_0_BIT                        4
// #define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_1_BIT                        5
// #define CHIP_TIMER_1_OUTPUT_B_MODE_DISCONNECTED_ID                  0
// #define CHIP_TIMER_1_OUTPUT_B_MODE_TOGGLE_ID                        1
// #define CHIP_TIMER_1_OUTPUT_B_MODE_CLEAR_ID                         2
// #define CHIP_TIMER_1_OUTPUT_B_MODE_SET_ID                           3
// #define CHIP_TIMER_1_OUTPUT_B_REG                                   CHIP_REG_OCR1B
// #define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_REG                        CHIP_REG_TIMSK
// #define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_BIT                        5
// #define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_REG                          CHIP_REG_TIFR
// #define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_BIT                          5
// #define CHIP_TIMER_1_OUTPUT_B_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_COMPB)

// #define CHIP_TIMER_1_OUTPUT_C                                       true
// #define CHIP_TIMER_1_OUTPUT_C_REG                                   CHIP_REG_OCR1C
// #define CHIP_TIMER_1_OUTPUT_C_INT_FLAG_REG                          CHIP_REG_TIFR

// #define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK
// #define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                        2
// #define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR
// #define CHIP_TIMER_1_OVERFLOW_INT_FLAG_BIT                          2
// #define CHIP_TIMER_1_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_OVF)

//------------------------------------------------
// Usarts

#define CHIP_REG_USART_0_RXDATA_ADDR                                (CHIP_MODULE_USART0_ADDR + 0x00)
#define CHIP_REG_USART_0_RXDATA_TYPE                                uint16_t
#define CHIP_REG_USART_0_RXDATAL_ADDR                               (CHIP_MODULE_USART0_ADDR + 0x00)
#define CHIP_REG_USART_0_RXDATAL_TYPE                               uint8_t
#define CHIP_REG_USART_0_RXDATAH_ADDR                               (CHIP_MODULE_USART0_ADDR + 0x01)
#define CHIP_REG_USART_0_RXDATAH_TYPE                               uint8_t
#define CHIP_REG_USART_0_TXDATA_ADDR                                (CHIP_MODULE_USART0_ADDR + 0x02)
#define CHIP_REG_USART_0_TXDATA_TYPE                                uint16_t
#define CHIP_REG_USART_0_TXDATAL_ADDR                               (CHIP_MODULE_USART0_ADDR + 0x02)
#define CHIP_REG_USART_0_TXDATAL_TYPE                               uint8_t
#define CHIP_REG_USART_0_TXDATAH_ADDR                               (CHIP_MODULE_USART0_ADDR + 0x03)
#define CHIP_REG_USART_0_TXDATAH_TYPE                               uint8_t
#define CHIP_REG_USART_0_STATUS_ADDR                                (CHIP_MODULE_USART0_ADDR + 0x04)
#define CHIP_REG_USART_0_STATUS_TYPE                                uint8_t
#define CHIP_REG_USART_0_CTRLA_ADDR                                 (CHIP_MODULE_USART0_ADDR + 0x05)
#define CHIP_REG_USART_0_CTRLA_TYPE                                 uint8_t
#define CHIP_REG_USART_0_CTRLB_ADDR                                 (CHIP_MODULE_USART0_ADDR + 0x06)
#define CHIP_REG_USART_0_CTRLB_TYPE                                 uint8_t
#define CHIP_REG_USART_0_CTRLC_ADDR                                 (CHIP_MODULE_USART0_ADDR + 0x07)
#define CHIP_REG_USART_0_CTRLC_TYPE                                 uint8_t
#define CHIP_REG_USART_0_CTRLC_ADDR                                 (CHIP_MODULE_USART0_ADDR + 0x07)
#define CHIP_REG_USART_0_CTRLC_TYPE                                 uint8_t
#define CHIP_REG_USART_0_BAUD_ADDR                                  (CHIP_MODULE_USART0_ADDR + 0x08)
#define CHIP_REG_USART_0_BAUD_TYPE                                  uint16_t
#define CHIP_REG_USART_0_DBGCTRL_ADDR                               (CHIP_MODULE_USART0_ADDR + 0x0B)
#define CHIP_REG_USART_0_DBGCTRL_TYPE                               uint8_t
#define CHIP_REG_USART_0_EVCTRL_ADDR                                (CHIP_MODULE_USART0_ADDR + 0x0C)
#define CHIP_REG_USART_0_EVCTRL_TYPE                                uint8_t
#define CHIP_REG_USART_0_TXPLCTRL_ADDR                              (CHIP_MODULE_USART0_ADDR + 0x0D)
#define CHIP_REG_USART_0_TXPLCTRL_TYPE                              uint8_t
#define CHIP_REG_USART_0_RXPLCTRL_ADDR                              (CHIP_MODULE_USART0_ADDR + 0x0E)
#define CHIP_REG_USART_0_RXPLCTRL_TYPE                              uint8_t

#define CHIP_USART_0                                                true

#define CHIP_USART_0_RX_DATA_REG                                    CHIP_REG_USART_0_RXDATAL
#define CHIP_USART_0_RX_DATA9_REG                                   CHIP_REG_USART_0_RXDATA

#define CHIP_USART_0_TX_DATA_REG                                    CHIP_REG_USART_0_TXDATAL
#define CHIP_USART_0_TX_DATA9_REG                                   CHIP_REG_USART_0_TXDATA

// TODO rename to just "baud" (not "baud rate").
#define CHIP_USART_0_BAUD_RATE_REG                                  CHIP_REG_USART_0_BAUD

// #define CHIP_USART_0_FRAME_ERROR_BIT_0_REG                          CHIP_REG_UCSR0A
// #define CHIP_USART_0_FRAME_ERROR_BIT_0_BIT                          4
// #define CHIP_USART_0_DATA_OVERRUN_BIT_0_REG                         CHIP_REG_UCSR0A
// #define CHIP_USART_0_DATA_OVERRUN_BIT_0_BIT                         3
#define CHIP_USART_0_PARITY_ERROR_BIT_0_REG                         CHIP_REG_USART_0_RXDATAH
#define CHIP_USART_0_PARITY_ERROR_BIT_0_BIT                         2

#define CHIP_USART_0_BAUD_MODE_NORMAL_ID                            0
#define CHIP_USART_0_BAUD_MODE_DOUBLE_ID                            1
#define CHIP_USART_0_BAUD_MODE_GENAUTO_ID                           2
#define CHIP_USART_0_BAUD_MODE_LINAUTO_ID                           3
#define CHIP_USART_0_BAUD_MODE_BIT_0_REG                            CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_BAUD_MODE_BIT_1_REG                            CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_BAUD_MODE_BIT_0_BIT                            1
#define CHIP_USART_0_BAUD_MODE_BIT_1_BIT                            2

// #define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT_0_REG        CHIP_REG_UCSR0A
// #define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT        0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_USART_0_CTRLA
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT_0_BIT               7
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_USART_0_CTRLA
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT_0_BIT               6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT_0_REG            CHIP_REG_USART_0_CTRLA
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT            5

// #define CHIP_USART_0_RX_COMPLETE_INT_FLAG_IMPURE                    TRUE
#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_BIT_0_REG                 CHIP_REG_USART_0_STATUS
#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_BIT_0_BIT                 7
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_BIT_0_REG                 CHIP_REG_USART_0_STATUS
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_BIT_0_BIT                 6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_BIT_0_REG              CHIP_REG_USART_0_STATUS
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_BIT_0_BIT              5

#define CHIP_USART_0_RX_ENABLE_BIT_0_REG                            CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_RX_ENABLE_BIT_0_BIT                            7
#define CHIP_USART_0_TX_ENABLE_BIT_0_REG                            CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_TX_ENABLE_BIT_0_BIT                            6

// #define CHIP_USART_0_RX_DATA_BIT_8_REG                              CHIP_REG_UCSR0B
// #define CHIP_USART_0_RX_DATA_BIT_8_BIT                              1
// #define CHIP_USART_0_TX_DATA_BIT_8_REG                              CHIP_REG_UCSR0B
// #define CHIP_USART_0_TX_DATA_BIT_8_BIT                              0

// #define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                           0
// #define CHIP_USART_0_MODE_SYNCHRONOUS_ID                            1
// #define CHIP_USART_0_MODE_MASTER_SPI_ID                             3
// #define CHIP_USART_0_MODE_BIT_0_REG                                 CHIP_REG_UCSR0C
// #define CHIP_USART_0_MODE_BIT_1_REG                                 CHIP_REG_UCSR0C
// #define CHIP_USART_0_MODE_BIT_0_BIT                                 6
// #define CHIP_USART_0_MODE_BIT_1_BIT                                 7

#define CHIP_USART_0_PARITY_DISABLE_ID                              0
#define CHIP_USART_0_PARITY_EVEN_ID                                 2
#define CHIP_USART_0_PARITY_ODD_ID                                  3
#define CHIP_USART_0_PARITY_BIT_0_REG                               CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_PARITY_BIT_1_REG                               CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_PARITY_BIT_0_BIT                               4
#define CHIP_USART_0_PARITY_BIT_1_BIT                               5

#define CHIP_USART_0_STOP_BITS_1_ID                                 0
#define CHIP_USART_0_STOP_BITS_2_ID                                 1
#define CHIP_USART_0_STOP_BITS_BIT_0_REG                            CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_STOP_BITS_BIT_0_BIT                            3

#define CHIP_USART_0_CHARACTER_SIZE_5_ID                            0
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                            1
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                            2
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                            3
// #define CHIP_USART_0_CHARACTER_SIZE_9_ID                            7
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_REG                       CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_REG                       CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_REG                       CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_BIT                       0
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_BIT                       1
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_BIT                       2

// #define CHIP_USART_0_POLARITY_TX_RISING_RX_FALLING_ID               0
// #define CHIP_USART_0_POLARITY_TX_FALLING_RX_RISING_ID               1
// #define CHIP_USART_0_POLARITY_BIT_0_REG                             CHIP_REG_UCSR0C
// #define CHIP_USART_0_POLARITY_BIT_0_BIT                             0

// #define CHIP_USART_0_RX_INT_VECTOR                                  VECT(CHIP_VECT_USART0_RX)
// #define CHIP_USART_0_DE_INT_VECTOR                                  VECT(CHIP_VECT_USART0_UDRE)
// #define CHIP_USART_0_TX_INT_VECTOR                                  VECT(CHIP_VECT_USART0_TX)

#endif

#ifndef NBLIB_ATTINY402_HPP
#define NBLIB_ATTINY402_HPP

#define CHIP attiny402

// TODO
// 402 404 406 202 204 and others seem to be all nearly the same.

// TODO Port Multiplexer. Should this be its own hardware, or part of the relevant hardware?

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
// Registers

#define CHIP_REG_VPORT_A_DIR                                        Register<uint8_t, CHIP_MODULE_VPORT_A_ADDR + 0x00>
#define CHIP_REG_VPORT_A_OUT                                        Register<uint8_t, CHIP_MODULE_VPORT_A_ADDR + 0x01>
#define CHIP_REG_VPORT_A_IN                                         Register<uint8_t, CHIP_MODULE_VPORT_A_ADDR + 0x02>
#define CHIP_REG_VPORT_A_INTFLAGS                                   Register<uint8_t, CHIP_MODULE_VPORT_A_ADDR + 0x03, 0xFF>

// TODO GPIO

#define CHIP_REG_CPU_CCP                                            Register<uint8_t, CHIP_MODULE_CPU_ADDR + 0x04>
#define CHIP_REG_CPU_SP                                             Register<uint16_t, CHIP_MODULE_CPU_ADDR + 0x0D>
#define CHIP_REG_CPU_SREG                                           Register<uint8_t, CHIP_MODULE_CPU_ADDR + 0x0F>

#define CHIP_REG_RSTCTRL_RSTFR                                      Register<uint8_t, CHIP_MODULE_RSTCTRL_ADDR + 0x00>
#define CHIP_REG_RSTCTRL_SWRR                                       Register<uint8_t, CHIP_MODULE_RSTCTRL_ADDR + 0x01>

#define CHIP_REG_SLPCTRL_CTRLA                                      Register<uint8_t, CHIP_MODULE_SLPCTRL_ADDR + 0x00>

#define CHIP_REG_CLKCTRL_MCLKCTRLA                                  Register<uint8_t, CHIP_MODULE_CLKCTRL_ADDR + 0x00, 0xFC, Ccp::ioReg>
#define CHIP_REG_CLKCTRL_MCLKCTRLB                                  Register<uint8_t, CHIP_MODULE_CLKCTRL_ADDR + 0x01, 0xE0, Ccp::ioReg>
#define CHIP_REG_CLKCTRL_MCLKLOCK                                   Register<uint8_t, CHIP_MODULE_CLKCTRL_ADDR + 0x02, 0xFE, Ccp::ioReg>
#define CHIP_REG_CLKCTRL_MCLKSTATUS                                 Register<uint8_t, CHIP_MODULE_CLKCTRL_ADDR + 0x03, 0xFF>
#define CHIP_REG_CLKCTRL_OSC20MCTRLA                                Register<uint8_t, CHIP_MODULE_CLKCTRL_ADDR + 0x10, 0xFD>
#define CHIP_REG_CLKCTRL_OSC20MCALIBA                               Register<uint8_t, CHIP_MODULE_CLKCTRL_ADDR + 0x11, 0xC0>
#define CHIP_REG_CLKCTRL_OSC20MCALIBB                               Register<uint8_t, CHIP_MODULE_CLKCTRL_ADDR + 0x12, 0xF0>
#define CHIP_REG_CLKCTRL_OSC32KCTRLA                                Register<uint8_t, CHIP_MODULE_CLKCTRL_ADDR + 0x18, 0xFD>

// TODO BOD

#define CHIP_REG_VREF_CTRLA                                         Register<uint8_t, CHIP_MODULE_VREF_ADDR + 0x00>
#define CHIP_REG_VREF_CTRLB                                         Register<uint8_t, CHIP_MODULE_VREF_ADDR + 0x01>

// TODO WDT
// TODO CPUINT
// TODO CRCSCAN
// TODO RTC
// TODO EVSYS
// TODO CCL

#define CHIP_REG_PORTMUX_CTRLA                                      Register<uint8_t, CHIP_MODULE_PORTMUX_ADDR + 0x00>
#define CHIP_REG_PORTMUX_CTRLB                                      Register<uint8_t, CHIP_MODULE_PORTMUX_ADDR + 0x01>
#define CHIP_REG_PORTMUX_CTRLC                                      Register<uint8_t, CHIP_MODULE_PORTMUX_ADDR + 0x02>

#define CHIP_REG_PORT_A_DIR                                         Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x00>
#define CHIP_REG_PORT_A_DIRSET                                      Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x01, 0xFF>
#define CHIP_REG_PORT_A_DIRCLR                                      Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x02, 0xFF>
#define CHIP_REG_PORT_A_DIRTGL                                      Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x03, 0xFF>
#define CHIP_REG_PORT_A_OUT                                         Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x04>
#define CHIP_REG_PORT_A_OUTSET                                      Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x05, 0xFF>
#define CHIP_REG_PORT_A_OUTCLR                                      Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x06, 0xFF>
#define CHIP_REG_PORT_A_OUTTGL                                      Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x07, 0xFF>
#define CHIP_REG_PORT_A_IN                                          Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x08>
#define CHIP_REG_PORT_A_INTFLAGS                                    Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x09, 0xFF>
#define CHIP_REG_PORT_A_PIN0CTRL                                    Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x10>
#define CHIP_REG_PORT_A_PIN1CTRL                                    Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x11>
#define CHIP_REG_PORT_A_PIN2CTRL                                    Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x12>
#define CHIP_REG_PORT_A_PIN3CTRL                                    Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x13>
#define CHIP_REG_PORT_A_PIN4CTRL                                    Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x14>
#define CHIP_REG_PORT_A_PIN5CTRL                                    Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x15>
#define CHIP_REG_PORT_A_PIN6CTRL                                    Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x16>
#define CHIP_REG_PORT_A_PIN7CTRL                                    Register<uint8_t, CHIP_MODULE_PORT_A_ADDR + 0x17>

#define CHIP_REG_ADC_0_CTRLA                                        Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x00>
#define CHIP_REG_ADC_0_CTRLB                                        Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x01>
#define CHIP_REG_ADC_0_CTRLC                                        Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x02>
#define CHIP_REG_ADC_0_CTRLD                                        Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x03>
#define CHIP_REG_ADC_0_CTRLE                                        Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x04>
#define CHIP_REG_ADC_0_SAMPCTRL                                     Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x05>
#define CHIP_REG_ADC_0_MUXPOS                                       Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x06>
#define CHIP_REG_ADC_0_COMMAND                                      Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x08>
#define CHIP_REG_ADC_0_EVCTRL                                       Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x09>
#define CHIP_REG_ADC_0_INTCTRL                                      Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x0A>
#define CHIP_REG_ADC_0_INTFLAGS                                     Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x0B, 0xFF>
#define CHIP_REG_ADC_0_DBGCTRL                                      Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x0C>
#define CHIP_REG_ADC_0_TEMP                                         Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x0D>
#define CHIP_REG_ADC_0_RES                                          Register<uint16_t, CHIP_MODULE_ADC0_ADDR + 0x10>
#define CHIP_REG_ADC_0_WINLT                                        Register<uint16_t, CHIP_MODULE_ADC0_ADDR + 0x12>
#define CHIP_REG_ADC_0_WINHT                                        Register<uint16_t, CHIP_MODULE_ADC0_ADDR + 0x14>
#define CHIP_REG_ADC_0_CALIB                                        Register<uint8_t, CHIP_MODULE_ADC0_ADDR + 0x16>

// TODO AC0

#define CHIP_REG_USART_0_RXDATAL                                    Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x00, 0xFF>
#define CHIP_REG_USART_0_RXDATAH                                    Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x01, 0xC7>
#define CHIP_REG_USART_0_TXDATAL                                    Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x02>
#define CHIP_REG_USART_0_TXDATAH                                    Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x03>
#define CHIP_REG_USART_0_STATUS                                     Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x04, 0xFF>
#define CHIP_REG_USART_0_CTRLA                                      Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x05>
#define CHIP_REG_USART_0_CTRLB                                      Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x06>
#define CHIP_REG_USART_0_CTRLC                                      Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x07>
#define CHIP_REG_USART_0_BAUD                                       Register<uint16_t, CHIP_MODULE_USART0_ADDR + 0x08>
#define CHIP_REG_USART_0_DBGCTRL                                    Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x0B>
#define CHIP_REG_USART_0_EVCTRL                                     Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x0C>
#define CHIP_REG_USART_0_TXPLCTRL                                   Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x0D>
#define CHIP_REG_USART_0_RXPLCTRL                                   Register<uint8_t, CHIP_MODULE_USART0_ADDR + 0x0E>

// TODO TWI0
// TODO SPI0

#define CHIP_REG_TCA0_CTRLA                                         Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x00>
#define CHIP_REG_TCA0_CTRLB                                         Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x01>
#define CHIP_REG_TCA0_CTRLC                                         Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x02>
#define CHIP_REG_TCA0_CTRLD                                         Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x03>
#define CHIP_REG_TCA0_CTRLECLR                                      Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x04, 0xFF>
#define CHIP_REG_TCA0_CTRLESET                                      Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x05, 0xFF>
#define CHIP_REG_TCA0_CTRLFCLR                                      Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x06, 0xFF>
#define CHIP_REG_TCA0_CTRLFSET                                      Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x07, 0xFF>
#define CHIP_REG_TCA0_EVCTRL                                        Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x09>
#define CHIP_REG_TCA0_INTCTRL                                       Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x0A>
#define CHIP_REG_TCA0_INTFLAGS                                      Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x0B, 0xFF>
#define CHIP_REG_TCA0_DBGCTRL                                       Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x0E>
#define CHIP_REG_TCA0_TEMP                                          Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x0F>
#define CHIP_REG_TCA0_CNT                                           Register<uint16_t, CHIP_MODULE_TCA0_ADDR + 0x20>
#define CHIP_REG_TCA0_PER                                           Register<uint16_t, CHIP_MODULE_TCA0_ADDR + 0x26>
#define CHIP_REG_TCA0_CMP0                                          Register<uint16_t, CHIP_MODULE_TCA0_ADDR + 0x28>
#define CHIP_REG_TCA0_CMP1                                          Register<uint16_t, CHIP_MODULE_TCA0_ADDR + 0x2A>
#define CHIP_REG_TCA0_CMP2                                          Register<uint16_t, CHIP_MODULE_TCA0_ADDR + 0x2C>
#define CHIP_REG_TCA0_PERBUF                                        Register<uint16_t, CHIP_MODULE_TCA0_ADDR + 0x36>
#define CHIP_REG_TCA0_CMP0nBUF                                      Register<uint16_t, CHIP_MODULE_TCA0_ADDR + 0x38>
#define CHIP_REG_TCA0_CMP1nBUF                                      Register<uint16_t, CHIP_MODULE_TCA0_ADDR + 0x3A>
#define CHIP_REG_TCA0_CMP2nBUF                                      Register<uint16_t, CHIP_MODULE_TCA0_ADDR + 0x3C>

#define CHIP_REG_TCA0_LCNT                                          Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x20>
#define CHIP_REG_TCA0_HCNT                                          Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x21>
#define CHIP_REG_TCA0_LPER                                          Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x26>
#define CHIP_REG_TCA0_HPER                                          Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x27>
#define CHIP_REG_TCA0_HPER                                          Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x27>
#define CHIP_REG_TCA0_LCMP0                                         Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x28>
#define CHIP_REG_TCA0_HCMP0                                         Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x29>
#define CHIP_REG_TCA0_LCMP1                                         Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x2A>
#define CHIP_REG_TCA0_HCMP1                                         Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x2B>
#define CHIP_REG_TCA0_LCMP2                                         Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x2C>
#define CHIP_REG_TCA0_HCMP2                                         Register<uint8_t, CHIP_MODULE_TCA0_ADDR + 0x2D>

#define CHIP_REG_TCB0_CTRLA                                         Register<uint8_t, CHIP_MODULE_TCB0_ADDR + 0x00>
#define CHIP_REG_TCB0_CTRLB                                         Register<uint8_t, CHIP_MODULE_TCB0_ADDR + 0x01>
#define CHIP_REG_TCB0_EVCTRL                                        Register<uint8_t, CHIP_MODULE_TCB0_ADDR + 0x04>
#define CHIP_REG_TCB0_INTCTRL                                       Register<uint8_t, CHIP_MODULE_TCB0_ADDR + 0x05>
#define CHIP_REG_TCB0_INTFLAGS                                      Register<uint8_t, CHIP_MODULE_TCB0_ADDR + 0x06, 0xFF>
#define CHIP_REG_TCB0_STATUS                                        Register<uint8_t, CHIP_MODULE_TCB0_ADDR + 0x07>
#define CHIP_REG_TCB0_DBGCTRL                                       Register<uint8_t, CHIP_MODULE_TCB0_ADDR + 0x08>
#define CHIP_REG_TCB0_TEMP                                          Register<uint8_t, CHIP_MODULE_TCB0_ADDR + 0x09>
#define CHIP_REG_TCB0_CNT                                           Register<uint16_t, CHIP_MODULE_TCB0_ADDR + 0x0A>
#define CHIP_REG_TCB0_CCMP                                          Register<uint16_t, CHIP_MODULE_TCB0_ADDR + 0x0C>

// TODO SYSCFG
// TODO NVMCTRL
// TODO SIGROW
// TODO FUSES
// TODO USERROW

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
#define vectorTimer0CompareA                                        ISR(__vector_10)
#define vectorTimer0CompareB                                        ISR(__vector_11)
#define vectorTimer0CompareC                                        ISR(__vector_12)
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

#define CHIP_SYSTEM_ALLOW_CONFIG_CHANGE_REG                         CHIP_REG_CPU_CCP
#define CHIP_SYSTEM_ALLOW_CONFIG_CHANGE_SELF_PROGRAM_ID             0x9D
#define CHIP_SYSTEM_ALLOW_CONFIG_CHANGE_IO_REG_ID                   0xD8

#define CHIP_SYSTEM_GLOBAL_INTERRUPT_REG                            CHIP_REG_CPU_SREG
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT                            7

//------------------------------------------------
// Clock

#define CHIP_CLOCK_SOURCE_REG                                       CHIP_REG_CLKCTRL_MCLKCTRLA
#define CHIP_CLOCK_SOURCE_MASK                                      0x03
#define CHIP_CLOCK_SOURCE_16M20M_ID                                 0x00
#define CHIP_CLOCK_SOURCE_32K_ID                                    0x01
#define CHIP_CLOCK_SOURCE_EXTERNAL_ID                               0x03

#define CHIP_CLOCK_PRESCALER_REG                                    CHIP_REG_CLKCTRL_MCLKCTRLB
#define CHIP_CLOCK_PRESCALER_MASK                                   0x1E
#define CHIP_CLOCK_PRESCALER_2_ID                                   0x00
#define CHIP_CLOCK_PRESCALER_4_ID                                   0x02
#define CHIP_CLOCK_PRESCALER_8_ID                                   0x04
#define CHIP_CLOCK_PRESCALER_16_ID                                  0x06
#define CHIP_CLOCK_PRESCALER_32_ID                                  0x08
#define CHIP_CLOCK_PRESCALER_64_ID                                  0x0A
#define CHIP_CLOCK_PRESCALER_6_ID                                   0x10
#define CHIP_CLOCK_PRESCALER_10_ID                                  0x12
#define CHIP_CLOCK_PRESCALER_12_ID                                  0x14
#define CHIP_CLOCK_PRESCALER_24_ID                                  0x16
#define CHIP_CLOCK_PRESCALER_48_ID                                  0x18

#define CHIP_CLOCK_PRESCALER_ENABLE_REG                             CHIP_REG_CLKCTRL_MCLKCTRLB
#define CHIP_CLOCK_PRESCALER_ENABLE_BIT                             0

#define CHIP_CLOCK_LOCK_REG                                         CHIP_REG_CLKCTRL_MCLKLOCK
#define CHIP_CLOCK_LOCK_BIT                                         0

// ...

//------------------------------------------------
// Sleep

#define CHIP_SLEEP_MODE_REG                                         CHIP_REG_SLPCTRL_CTRLA
#define CHIP_SLEEP_MODE_MASK                                        0x06
#define CHIP_SLEEP_MODE_IDLE_ID                                     0x00
#define CHIP_SLEEP_MODE_STANDBY_ID                                  0x02
#define CHIP_SLEEP_MODE_POWER_DOWN_ID                               0x04

#define CHIP_SLEEP_ENABLE_REG                                       CHIP_REG_SLPCTRL_CTRLA
#define CHIP_SLEEP_ENABLE_BIT                                       0


//------------------------------------------------
// IO ports

#define CHIP_PORT_A
#define CHIP_PORT_A_DIRECTION_REG                                   CHIP_REG_VPORT_A_DIR
// #define CHIP_PORT_A_DIRECTION_SET_REG
// #define CHIP_PORT_A_DIRECTION_CLEAR_REG
// #define CHIP_PORT_A_DIRECTION_TOGGLE_REG                            CHIP_REG_PORT_A_DIRTGL
#define CHIP_PORT_A_OUTPUT_REG                                      CHIP_REG_VPORT_A_OUT
// #define CHIP_PORT_A_OUTPUT_SET_REG
// #define CHIP_PORT_A_OUTPUT_CLEAR_REG
#define CHIP_PORT_A_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_A_OUTTGL
#define CHIP_PORT_A_INPUT_REG                                       CHIP_REG_VPORT_A_IN
#define CHIP_PORT_A_INT_FLAG_REG                                    CHIP_REG_VPORT_A_INTFLAGS

//------------------------------------------------
// IO pins

#define CHIP_PIN_A0
#define CHIP_PIN_A0_DIRECTION_REG                                   CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A0_DIRECTION_BIT                                   0
#define CHIP_PIN_A0_OUTPUT_REG                                      CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A0_OUTPUT_BIT                                      0
#define CHIP_PIN_A0_INPUT_REG                                       CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A0_INPUT_BIT                                       0
#define CHIP_PIN_A0_PULLUP_REG                                      CHIP_REG_PORT_A_PIN0CTRL
#define CHIP_PIN_A0_PULLUP_BIT                                      3
#define CHIP_PIN_A0_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_A_OUTTGL
#define CHIP_PIN_A0_OUTPUT_TOGGLE_BIT                               0
// TODO Add int flag.

#define CHIP_PIN_A1
#define CHIP_PIN_A1_DIRECTION_REG                                   CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A1_DIRECTION_BIT                                   1
#define CHIP_PIN_A1_OUTPUT_REG                                      CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A1_OUTPUT_BIT                                      1
#define CHIP_PIN_A1_INPUT_REG                                       CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A1_INPUT_BIT                                       1
#define CHIP_PIN_A1_PULLUP_REG                                      CHIP_REG_PORT_A_PIN1CTRL
#define CHIP_PIN_A1_PULLUP_BIT                                      3
#define CHIP_PIN_A1_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_A_OUTTGL
#define CHIP_PIN_A1_OUTPUT_TOGGLE_BIT                               1

#define CHIP_PIN_A2
#define CHIP_PIN_A2_DIRECTION_REG                                   CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A2_DIRECTION_BIT                                   2
#define CHIP_PIN_A2_OUTPUT_REG                                      CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A2_OUTPUT_BIT                                      2
#define CHIP_PIN_A2_INPUT_REG                                       CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A2_INPUT_BIT                                       2
#define CHIP_PIN_A2_PULLUP_REG                                      CHIP_REG_PORT_A_PIN2CTRL
#define CHIP_PIN_A2_PULLUP_BIT                                      3
#define CHIP_PIN_A2_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_A_OUTTGL
#define CHIP_PIN_A2_OUTPUT_TOGGLE_BIT                               2

#define CHIP_PIN_A3
#define CHIP_PIN_A3_DIRECTION_REG                                   CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A3_DIRECTION_BIT                                   3
#define CHIP_PIN_A3_OUTPUT_REG                                      CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A3_OUTPUT_BIT                                      3
#define CHIP_PIN_A3_INPUT_REG                                       CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A3_INPUT_BIT                                       3
#define CHIP_PIN_A3_PULLUP_REG                                      CHIP_REG_PORT_A_PIN3CTRL
#define CHIP_PIN_A3_PULLUP_BIT                                      3
#define CHIP_PIN_A3_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_A_OUTTGL
#define CHIP_PIN_A3_OUTPUT_TOGGLE_BIT                               3

#define CHIP_PIN_A6
#define CHIP_PIN_A6_DIRECTION_REG                                   CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A6_DIRECTION_BIT                                   6
#define CHIP_PIN_A6_OUTPUT_REG                                      CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A6_OUTPUT_BIT                                      6
#define CHIP_PIN_A6_INPUT_REG                                       CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A6_INPUT_BIT                                       6
#define CHIP_PIN_A6_PULLUP_REG                                      CHIP_REG_PORT_A_PIN6CTRL
#define CHIP_PIN_A6_PULLUP_BIT                                      3
#define CHIP_PIN_A6_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_A_OUTTGL
#define CHIP_PIN_A6_OUTPUT_TOGGLE_BIT                               6

#define CHIP_PIN_A7
#define CHIP_PIN_A7_DIRECTION_REG                                   CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A7_DIRECTION_BIT                                   7
#define CHIP_PIN_A7_OUTPUT_REG                                      CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A7_OUTPUT_BIT                                      7
#define CHIP_PIN_A7_INPUT_REG                                       CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A7_INPUT_BIT                                       7
#define CHIP_PIN_A7_PULLUP_REG                                      CHIP_REG_PORT_A_PIN7CTRL
#define CHIP_PIN_A7_PULLUP_BIT                                      3
#define CHIP_PIN_A7_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_A_OUTTGL
#define CHIP_PIN_A7_OUTPUT_TOGGLE_BIT                               7

//------------------------------------------------
// Voltage References

#define CHIP_VREF_0

#define CHIP_VREF_0_VOLTAGE_REG                                     CHIP_REG_VREF_CTRLA
#define CHIP_VREF_0_VOLTAGE_MASK                                    0x07
#define CHIP_VREF_0_VOLTAGE_0_55_V_ID                               0x00
#define CHIP_VREF_0_VOLTAGE_1_1_V_ID                                0x01
#define CHIP_VREF_0_VOLTAGE_2_5_V_ID                                0x02
#define CHIP_VREF_0_VOLTAGE_4_3_V_ID                                0x03
#define CHIP_VREF_0_VOLTAGE_1_5_V_ID                                0x04

#define CHIP_VREF_1

#define CHIP_VREF_1_VOLTAGE_REG                                     CHIP_REG_VREF_CTRLA
#define CHIP_VREF_1_VOLTAGE_MASK                                    0x70
#define CHIP_VREF_1_VOLTAGE_0_55_V_ID                               0x00
#define CHIP_VREF_1_VOLTAGE_1_1_V_ID                                0x10
#define CHIP_VREF_1_VOLTAGE_2_5_V_ID                                0x20
#define CHIP_VREF_1_VOLTAGE_4_3_V_ID                                0x30
#define CHIP_VREF_1_VOLTAGE_1_5_V_ID                                0x40

//------------------------------------------------
// Analog to digital converters

#define CHIP_ADC_0

#define CHIP_ADC_0_RESULT_REG                                       CHIP_REG_ADC_0_RES

#define CHIP_ADC_0_ENABLE_REG                                       CHIP_REG_ADC_0_CTRLA
#define CHIP_ADC_0_ENABLE_BIT                                       0

#define CHIP_ADC_0_START_REG                                        CHIP_REG_ADC_0_COMMAND
#define CHIP_ADC_0_START_BIT                                        0

#define CHIP_ADC_0_REFERENCE_REG                                    CHIP_REG_ADC_0_CTRLC
#define CHIP_ADC_0_REFERENCE_MASK                                   0x30
#define CHIP_ADC_0_REFERENCE_INTERNAL_ID                            0x00
#define CHIP_ADC_0_REFERENCE_VDD_ID                                 0x10

#define CHIP_ADC_0_CHANNEL_REG                                      CHIP_REG_ADC_0_MUXPOS
#define CHIP_ADC_0_CHANNEL_MASK                                     0x1F
#define CHIP_ADC_0_CHANNEL_0_ID                                     0x00
#define CHIP_ADC_0_CHANNEL_1_ID                                     0x01
#define CHIP_ADC_0_CHANNEL_2_ID                                     0x02
#define CHIP_ADC_0_CHANNEL_3_ID                                     0x03
#define CHIP_ADC_0_CHANNEL_6_ID                                     0x06
#define CHIP_ADC_0_CHANNEL_7_ID                                     0x07
#define CHIP_ADC_0_CHANNEL_INTERNAL_ID                              0x1D
#define CHIP_ADC_0_CHANNEL_TEMPERATURE_ID                           0x1E
#define CHIP_ADC_0_CHANNEL_GND_ID                                   0x1F

#define CHIP_ADC_0_FREE_RUNNING_REG                                 CHIP_REG_ADC_0_CTRLA
#define CHIP_ADC_0_FREE_RUNNING_BIT                                 1

#define CHIP_ADC_0_TRIGGER_ENABLE_REG                               CHIP_REG_ADC_0_EVCTRL
#define CHIP_ADC_0_TRIGGER_ENABLE_BIT                               0

#define CHIP_ADC_0_INT_FLAG_REG                                     CHIP_REG_ADC_0_INTFLAGS
#define CHIP_ADC_0_INT_FLAG_BIT                                     0

#define CHIP_ADC_0_INT_ENABLE_REG                                   CHIP_REG_ADC_0_INTCTRL
#define CHIP_ADC_0_INT_ENABLE_BIT                                   0

#define CHIP_ADC_0_PRESCALER_REG                                    CHIP_REG_ADC_0_CTRLC
#define CHIP_ADC_0_PRESCALER_MASK                                   0x07
#define CHIP_ADC_0_PRESCALER_2_ID                                   0x00
#define CHIP_ADC_0_PRESCALER_4_ID                                   0x01
#define CHIP_ADC_0_PRESCALER_8_ID                                   0x02
#define CHIP_ADC_0_PRESCALER_16_ID                                  0x03
#define CHIP_ADC_0_PRESCALER_32_ID                                  0x04
#define CHIP_ADC_0_PRESCALER_64_ID                                  0x05
#define CHIP_ADC_0_PRESCALER_128_ID                                 0x06
#define CHIP_ADC_0_PRESCALER_256_ID                                 0x07

//------------------------------------------------
// Timers

#define CHIP_TIMER_0

#define CHIP_TIMER_0_COUNTER_REG                                    CHIP_REG_TCA0_CNT

#define CHIP_TIMER_0_TOP_REG                                        CHIP_REG_TCA0_PER

#define CHIP_TIMER_0_WAVEFORM_REG                                   CHIP_REG_TCA0_CTRLB
#define CHIP_TIMER_0_WAVEFORM_MASK                                  0x07
#define CHIP_TIMER_0_WAVEFORM_NORMAL_ID                             0x00
#define CHIP_TIMER_0_WAVEFORM_FREQUENCY_ID                          0x01
#define CHIP_TIMER_0_WAVEFORM_SINGLE_SLOPE_PWM_ID                   0x03
#define CHIP_TIMER_0_WAVEFORM_DUAL_SLOPE_PWM_OVF_TOP_ID             0x05
#define CHIP_TIMER_0_WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTH_ID            0x06
#define CHIP_TIMER_0_WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTTOM_ID          0x07

#define CHIP_TIMER_0_CLOCK_REG                                      CHIP_REG_TCA0_CTRLA
#define CHIP_TIMER_0_CLOCK_MASK                                     0x0E
#define CHIP_TIMER_0_CLOCK_1_ID                                     0x00
#define CHIP_TIMER_0_CLOCK_2_ID                                     0x02
#define CHIP_TIMER_0_CLOCK_4_ID                                     0x04
#define CHIP_TIMER_0_CLOCK_8_ID                                     0x06
#define CHIP_TIMER_0_CLOCK_16_ID                                    0x08
#define CHIP_TIMER_0_CLOCK_64_ID                                    0x0A
#define CHIP_TIMER_0_CLOCK_256_ID                                   0x0C
#define CHIP_TIMER_0_CLOCK_1024_ID                                  0x0E

#define CHIP_TIMER_0_ENABLE_REG                                     CHIP_REG_TCA0_CTRLA
#define CHIP_TIMER_0_ENABLE_BIT                                     0

#define CHIP_TIMER_0_COMPARE_A_REG                                  CHIP_REG_TCA0_CMP0
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_ENABLE_REG                    CHIP_REG_TCA0_CTRLB
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_ENABLE_BIT                    4
#define CHIP_TIMER_0_COMPARE_A_INT_ENABLE_REG                       CHIP_REG_TCA0_INTCTRL
#define CHIP_TIMER_0_COMPARE_A_INT_ENABLE_BIT                       4
#define CHIP_TIMER_0_COMPARE_A_INT_FLAG_REG                         CHIP_REG_TCA0_INTFLAGS
#define CHIP_TIMER_0_COMPARE_A_INT_FLAG_BIT                         4

#define CHIP_TIMER_0_COMPARE_B_REG                                  CHIP_REG_TCA0_CMP1
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_ENABLE_REG                    CHIP_REG_TCA0_CTRLB
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_ENABLE_BIT                    5
#define CHIP_TIMER_0_COMPARE_B_INT_ENABLE_REG                       CHIP_REG_TCA0_INTCTRL
#define CHIP_TIMER_0_COMPARE_B_INT_ENABLE_BIT                       5
#define CHIP_TIMER_0_COMPARE_B_INT_FLAG_REG                         CHIP_REG_TCA0_INTFLAGS
#define CHIP_TIMER_0_COMPARE_B_INT_FLAG_BIT                         5

#define CHIP_TIMER_0_COMPARE_C_REG                                  CHIP_REG_TCA0_CMP2
#define CHIP_TIMER_0_COMPARE_C_OUTPUT_ENABLE_REG                    CHIP_REG_TCA0_CTRLB
#define CHIP_TIMER_0_COMPARE_C_OUTPUT_ENABLE_BIT                    6
#define CHIP_TIMER_0_COMPARE_C_INT_ENABLE_REG                       CHIP_REG_TCA0_INTCTRL
#define CHIP_TIMER_0_COMPARE_C_INT_ENABLE_BIT                       6
#define CHIP_TIMER_0_COMPARE_C_INT_FLAG_REG                         CHIP_REG_TCA0_INTFLAGS
#define CHIP_TIMER_0_COMPARE_C_INT_FLAG_BIT                         6

#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TCA0_INTCTRL
#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                        0

#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TCA0_INTFLAGS
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_BIT                          0

//------------------------------------------------
// Usarts

#define CHIP_USART_0

#define CHIP_USART_0_RX_DATA_REG                                    CHIP_REG_USART_0_RXDATAL
#define CHIP_USART_0_RX_DATA9_REG                                   CHIP_REG_USART_0_RXDATAH
#define CHIP_USART_0_RX_DATA9_BIT                                   0

#define CHIP_USART_0_TX_DATA_REG                                    CHIP_REG_USART_0_TXDATAL
#define CHIP_USART_0_TX_DATA9_REG                                   CHIP_REG_USART_0_TXDATAH
#define CHIP_USART_0_TX_DATA9_BIT                                   0

#define CHIP_USART_0_BAUD_REG                                       CHIP_REG_USART_0_BAUD

#define CHIP_USART_0_PARITY_ERROR_REG                               CHIP_REG_USART_0_RXDATAH
#define CHIP_USART_0_PARITY_ERROR_BIT                               2

#define CHIP_USART_0_BAUD_MODE_REG                                  CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_BAUD_MODE_MASK                                 0x06
#define CHIP_USART_0_BAUD_MODE_NORMAL_ID                            0x00
#define CHIP_USART_0_BAUD_MODE_DOUBLE_ID                            0x02
#define CHIP_USART_0_BAUD_MODE_GENAUTO_ID                           0x04
#define CHIP_USART_0_BAUD_MODE_LINAUTO_ID                           0x06

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG              CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT              0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_USART_0_CTRLA
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                     7
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_USART_0_CTRLA
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                     6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG                  CHIP_REG_USART_0_CTRLA
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT                  5

#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_REG                       CHIP_REG_USART_0_STATUS
#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_BIT                       7
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_REG                       CHIP_REG_USART_0_STATUS
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_BIT                       6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_REG                    CHIP_REG_USART_0_STATUS
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_BIT                    5

#define CHIP_USART_0_RX_ENABLE_REG                                  CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_RX_ENABLE_BIT                                  7
#define CHIP_USART_0_TX_ENABLE_REG                                  CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_TX_ENABLE_BIT                                  6

#define CHIP_USART_0_ENABLE_ALTERNATE_PINS_REG                      CHIP_REG_PORTMUX_CTRLB
#define CHIP_USART_0_ENABLE_ALTERNATE_PINS_BIT                      0

#define CHIP_USART_0_MODE_REG                                       CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_MODE_MASK                                      0xC0
#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                           0x00
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                            0x40
#define CHIP_USART_0_MODE_IRCOM_ID                                  0x80
#define CHIP_USART_0_MODE_MASTER_SPI_ID                             0xC0

#define CHIP_USART_0_PARITY_REG                                     CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_PARITY_MASK                                    0x30
#define CHIP_USART_0_PARITY_DISABLE_ID                              0x00
#define CHIP_USART_0_PARITY_EVEN_ID                                 0x20
#define CHIP_USART_0_PARITY_ODD_ID                                  0x30

#define CHIP_USART_0_STOP_BITS_REG                                  CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_STOP_BITS_MASK                                 0x08
#define CHIP_USART_0_STOP_BITS_1_ID                                 0x00
#define CHIP_USART_0_STOP_BITS_2_ID                                 0x08

#define CHIP_USART_0_CHARACTER_SIZE_REG                             CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_CHARACTER_SIZE_MASK                            0x07
#define CHIP_USART_0_CHARACTER_SIZE_5_ID                            0x00
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                            0x01
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                            0x02
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                            0x03
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                            0x06
// #define CHIP_USART_0_CHARACTER_SIZE_9_LOW_ID                        0x06
// #define CHIP_USART_0_CHARACTER_SIZE_9_HIGH_ID                       0x07

#endif

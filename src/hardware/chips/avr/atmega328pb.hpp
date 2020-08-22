#ifndef NBLIB_ATMEGA328PB_HPP
#define NBLIB_ATMEGA328PB_HPP

#include "atmega328p.hpp"

#undef CHIP
#define CHIP atmega328pb

//------------------------------------------------
// Registers

#define CHIP_REG_PINE                                               Register<uint8_t, 0x2C, 0xFF>
#define CHIP_REG_DDRE                                               Register<uint8_t, 0x2D>
#define CHIP_REG_PORTE                                              Register<uint8_t, 0x2E>
#define CHIP_REG_TIFR3                                              Register<uint8_t, 0x38, 0xFF>
#define CHIP_REG_TIFR4                                              Register<uint8_t, 0x39, 0xFF>
#define CHIP_REG_ACSRB                                              Register<uint8_t, 0x4F>
#define CHIP_REG_XFDCSR                                             Register<uint8_t, 0x62>
#define CHIP_REG_PRR1                                               Register<uint8_t, 0x65>
#define CHIP_REG_TIMSK3                                             Register<uint8_t, 0x71>
#define CHIP_REG_TIMSK4                                             Register<uint8_t, 0x72>
#define CHIP_REG_PCMSK3                                             Register<uint8_t, 0x73>
#define CHIP_REG_TCCR3A                                             Register<uint8_t, 0x90>
#define CHIP_REG_TCCR3B                                             Register<uint8_t, 0x91>
#define CHIP_REG_TCCR3C                                             Register<uint8_t, 0x92>
#define CHIP_REG_TCNT3                                              Register<uint16_t, 0x94>
#define CHIP_REG_ICR3                                               Register<uint16_t, 0x96>
#define CHIP_REG_OCR3A                                              Register<uint16_t, 0x98>
#define CHIP_REG_OCR3B                                              Register<uint16_t, 0x9A>
#define CHIP_REG_TCCR4A                                             Register<uint8_t, 0xA0>
#define CHIP_REG_TCCR4B                                             Register<uint8_t, 0xA1>
#define CHIP_REG_TCCR4C                                             Register<uint8_t, 0xA2>
#define CHIP_REG_TCNT4                                              Register<uint16_t, 0xA4>
#define CHIP_REG_ICR4                                               Register<uint16_t, 0xA6>
#define CHIP_REG_OCR4A                                              Register<uint16_t, 0xA8>
#define CHIP_REG_OCR4B                                              Register<uint16_t, 0xAA>
#define CHIP_REG_SPCR1                                              Register<uint8_t, 0xAC>
#define CHIP_REG_SPSR1                                              Register<uint8_t, 0xAD, 0xC0>
#define CHIP_REG_SPDR1                                              Register<uint8_t, 0xAE>
#define CHIP_REG_UCSR0D                                             Register<uint8_t, 0xC3>
#define CHIP_REG_UDR1                                               Register<uint8_t, 0xC7>
#define CHIP_REG_UCSR1A                                             Register<uint8_t, 0xC8, 0xFC>
#define CHIP_REG_UCSR1B                                             Register<uint8_t, 0xC9>
#define CHIP_REG_UCSR1C                                             Register<uint8_t, 0xCA>
#define CHIP_REG_UCSR1D                                             Register<uint8_t, 0xCB>
#define CHIP_REG_UBRR1                                              Register<uint16_t, 0xCC>
#define CHIP_REG_TWBR1                                              Register<uint8_t, 0xD8>
#define CHIP_REG_TWSR1                                              Register<uint8_t, 0xD9>
#define CHIP_REG_TWAR1                                              Register<uint8_t, 0xDA>
#define CHIP_REG_TWDR1                                              Register<uint8_t, 0xDB>
#define CHIP_REG_TWCR1                                              Register<uint8_t, 0xDC>
#define CHIP_REG_TWAMR1                                             Register<uint8_t, 0xDD>

//------------------------------------------------
// Vectors

#define vectorUsart0Start                                           ISR(__vector_26)
#define vectorPcInt3                                                ISR(__vector_27)
#define vectorUsart1RxComplete                                      ISR(__vector_28)
#define vectorUsart1DataRegEmpty                                    ISR(__vector_29)
#define vectorUsart1TxComplete                                      ISR(__vector_30)
#define vectorUsart1Start                                           ISR(__vector_31)
#define vectorTc3InputCapture                                       ISR(__vector_32)
#define vectorTc3CompareA                                           ISR(__vector_33)
#define vectorTc3CompareB                                           ISR(__vector_34)
#define vectorTc3Overflow                                           ISR(__vector_35)
#define vectorClockFailure                                          ISR(__vector_36)
#define vectorTouchConversionEnd                                    ISR(__vector_37)
#define vectorTouchWindowComparitor                                 ISR(__vector_38)
#define vectorSpi1                                                  ISR(__vector_39)
#define vectorTwi1                                                  ISR(__vector_40)
#define vectorTc4InputCapture                                       ISR(__vector_41)
#define vectorTc4CompareA                                           ISR(__vector_42)
#define vectorTc4CompareB                                           ISR(__vector_43)
#define vectorTc4Overflow                                           ISR(__vector_44)

//------------------------------------------------
// IO ports

#define CHIP_PORT_E
#define CHIP_PORT_E_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PORT_E_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PORT_E_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PORT_E_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PORT_E_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE

//------------------------------------------------
// IO pins

#define CHIP_PIN_E0
#define CHIP_PIN_E0_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E0_DIRECTION_BIT                                   0
#define CHIP_PIN_E0_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E0_INPUT_BIT                                       0
#define CHIP_PIN_E0_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E0_OUTPUT_BIT                                      0
#define CHIP_PIN_E0_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_E0_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E0_PULLUP_BIT                                      0

#define CHIP_PIN_E1
#define CHIP_PIN_E1_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E1_DIRECTION_BIT                                   1
#define CHIP_PIN_E1_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E1_INPUT_BIT                                       1
#define CHIP_PIN_E1_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E1_OUTPUT_BIT                                      1
#define CHIP_PIN_E1_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_E1_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E1_PULLUP_BIT                                      1

#define CHIP_PIN_E2
#define CHIP_PIN_E2_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E2_DIRECTION_BIT                                   2
#define CHIP_PIN_E2_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E2_INPUT_BIT                                       2
#define CHIP_PIN_E2_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E2_OUTPUT_BIT                                      2
#define CHIP_PIN_E2_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_E2_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E2_PULLUP_BIT                                      2

#define CHIP_PIN_E3
#define CHIP_PIN_E3_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E3_DIRECTION_BIT                                   3
#define CHIP_PIN_E3_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E3_INPUT_BIT                                       3
#define CHIP_PIN_E3_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E3_OUTPUT_BIT                                      3
#define CHIP_PIN_E3_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_E3_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E3_PULLUP_BIT                                      3

//------------------------------------------------
// Pin change interrupts

#define CHIP_PCINT_3
#define CHIP_PCINT_3_ENABLE_REG                                     CHIP_REG_PCICR
#define CHIP_PCINT_3_ENABLE_BIT                                     3
#define CHIP_PCINT_3_INT_FLAG_REG                                   CHIP_REG_PCIFR
#define CHIP_PCINT_3_INT_FLAG_BIT                                   3
#define CHIP_PCINT_3_MASK_REG                                       CHIP_REG_PCMSK3

//------------------------------------------------
// Timer/Counter

#define CHIP_TC_3

#define CHIP_TC_3_WAVEFORM_REG                                      CHIP_REG_TCCR3A
#define CHIP_TC_3_WAVEFORM_MASK                                     0x03
#define CHIP_TC_3_WAVEFORM_REG_EXTRA                                CHIP_REG_TCCR3B
#define CHIP_TC_3_WAVEFORM_MASK_EXTRA                               0x18
#define CHIP_TC_3_WAVEFORM_NORMAL_ID                                0x0000
#define CHIP_TC_3_WAVEFORM_PWM_PHASE_CORRECT_8_ID                   0x0001
#define CHIP_TC_3_WAVEFORM_PWM_PHASE_CORRECT_9_ID                   0x0002
#define CHIP_TC_3_WAVEFORM_PWM_PHASE_CORRECT_10_ID                  0x0003
#define CHIP_TC_3_WAVEFORM_CTC_OCRA_ID                              0x0800
#define CHIP_TC_3_WAVEFORM_FAST_PWM_8_ID                            0x0801
#define CHIP_TC_3_WAVEFORM_FAST_PWM_9_ID                            0x0802
#define CHIP_TC_3_WAVEFORM_FAST_PWM_10_ID                           0x0803
#define CHIP_TC_3_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID                0x1000
#define CHIP_TC_3_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID           0x1001
#define CHIP_TC_3_WAVEFORM_PWM_PHASE_CORRECT_ID                     0x1002
#define CHIP_TC_3_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID                0x1003
#define CHIP_TC_3_WAVEFORM_CTC_ICR_ID                               0x1800
#define CHIP_TC_3_WAVEFORM_FAST_PWM_ID                              0x1802
#define CHIP_TC_3_WAVEFORM_FAST_PWM_OCRA_ID                         0x1803

#define CHIP_TC_3_CLOCK_REG                                         CHIP_REG_TCCR3B
#define CHIP_TC_3_CLOCK_MASK                                        0x07
#define CHIP_TC_3_CLOCK_NONE_ID                                     0x00
#define CHIP_TC_3_CLOCK_1_ID                                        0x01
#define CHIP_TC_3_CLOCK_8_ID                                        0x02
#define CHIP_TC_3_CLOCK_64_ID                                       0x03
#define CHIP_TC_3_CLOCK_256_ID                                      0x04
#define CHIP_TC_3_CLOCK_1024_ID                                     0x05
#define CHIP_TC_3_CLOCK_EXT_FALLING_ID                              0x06
#define CHIP_TC_3_CLOCK_EXT_RISING_ID                               0x07

#define CHIP_TC_3_COUNTER_REG                                       CHIP_REG_TCNT3

#define CHIP_TC_3_PRESCALER_RESET_REG                               CHIP_REG_GTCCR
#define CHIP_TC_3_PRESCALER_RESET_BIT                               0

#define CHIP_TC_3_SYNCHRONIZE_REG                                   CHIP_REG_GTCCR
#define CHIP_TC_3_SYNCHRONIZE_BIT                                   7

#define CHIP_TC_3_COMPARE_A_REG                                     CHIP_REG_OCR3A
#define CHIP_TC_3_COMPARE_A_INT_ENABLE_REG                          CHIP_REG_TIMSK3
#define CHIP_TC_3_COMPARE_A_INT_ENABLE_BIT                          1
#define CHIP_TC_3_COMPARE_A_INT_FLAG_REG                            CHIP_REG_TIFR3
#define CHIP_TC_3_COMPARE_A_INT_FLAG_BIT                            1
#define CHIP_TC_3_COMPARE_A_OUTPUT_MODE_REG                         CHIP_REG_TCCR3A
#define CHIP_TC_3_COMPARE_A_OUTPUT_MODE_MASK                        0xC0
#define CHIP_TC_3_COMPARE_A_OUTPUT_MODE_DISCONNECTED_ID             0x00
#define CHIP_TC_3_COMPARE_A_OUTPUT_MODE_TOGGLE_ID                   0x40
#define CHIP_TC_3_COMPARE_A_OUTPUT_MODE_CLEAR_ID                    0x80
#define CHIP_TC_3_COMPARE_A_OUTPUT_MODE_SET_ID                      0xC0

#define CHIP_TC_3_COMPARE_B_REG                                     CHIP_REG_OCR3B
#define CHIP_TC_3_COMPARE_B_INT_ENABLE_REG                          CHIP_REG_TIMSK3
#define CHIP_TC_3_COMPARE_B_INT_ENABLE_BIT                          2
#define CHIP_TC_3_COMPARE_B_INT_FLAG_REG                            CHIP_REG_TIFR3
#define CHIP_TC_3_COMPARE_B_INT_FLAG_BIT                            2
#define CHIP_TC_3_COMPARE_B_OUTPUT_MODE_REG                         CHIP_REG_TCCR3A
#define CHIP_TC_3_COMPARE_B_OUTPUT_MODE_MASK                        0x30
#define CHIP_TC_3_COMPARE_B_OUTPUT_MODE_DISCONNECTED_ID             0x00
#define CHIP_TC_3_COMPARE_B_OUTPUT_MODE_TOGGLE_ID                   0x10
#define CHIP_TC_3_COMPARE_B_OUTPUT_MODE_CLEAR_ID                    0x20
#define CHIP_TC_3_COMPARE_B_OUTPUT_MODE_SET_ID                      0x30

#define CHIP_TC_3_OVERFLOW_INT_ENABLE_REG                           CHIP_REG_TIMSK3
#define CHIP_TC_3_OVERFLOW_INT_ENABLE_BIT                           0
#define CHIP_TC_3_OVERFLOW_INT_FLAG_REG                             CHIP_REG_TIFR3
#define CHIP_TC_3_OVERFLOW_INT_FLAG_BIT                             0

#define CHIP_TC_3_CAPTURE_REG                                       CHIP_REG_ICR3
#define CHIP_TC_3_CAPTURE_NOISE_CANCEL_ENABLE_REG                   CHIP_REG_TCCR3B
#define CHIP_TC_3_CAPTURE_NOISE_CANCEL_ENABLE_BIT                   7
#define CHIP_TC_3_CAPTURE_EDGE_REG                                  CHIP_REG_TCCR3B
#define CHIP_TC_3_CAPTURE_EDGE_MASK                                 0x40
#define CHIP_TC_3_CAPTURE_EDGE_FALLING_ID                           0x00
#define CHIP_TC_3_CAPTURE_EDGE_RISING_ID                            0x40
#define CHIP_TC_3_CAPTURE_INT_ENABLE_REG                            CHIP_REG_TIMSK3
#define CHIP_TC_3_CAPTURE_INT_ENABLE_BIT                            5
#define CHIP_TC_3_CAPTURE_INT_FLAG_REG                              CHIP_REG_TIFR3
#define CHIP_TC_3_CAPTURE_INT_FLAG_BIT                              5

//------------------------------------------------

#define CHIP_TC_4

#define CHIP_TC_4_WAVEFORM_REG                                      CHIP_REG_TCCR4A
#define CHIP_TC_4_WAVEFORM_MASK                                     0x03
#define CHIP_TC_4_WAVEFORM_REG_EXTRA                                CHIP_REG_TCCR4B
#define CHIP_TC_4_WAVEFORM_MASK_EXTRA                               0x18
#define CHIP_TC_4_WAVEFORM_NORMAL_ID                                0x0000
#define CHIP_TC_4_WAVEFORM_PWM_PHASE_CORRECT_8_ID                   0x0001
#define CHIP_TC_4_WAVEFORM_PWM_PHASE_CORRECT_9_ID                   0x0002
#define CHIP_TC_4_WAVEFORM_PWM_PHASE_CORRECT_10_ID                  0x0003
#define CHIP_TC_4_WAVEFORM_CTC_OCRA_ID                              0x0800
#define CHIP_TC_4_WAVEFORM_FAST_PWM_8_ID                            0x0801
#define CHIP_TC_4_WAVEFORM_FAST_PWM_9_ID                            0x0802
#define CHIP_TC_4_WAVEFORM_FAST_PWM_10_ID                           0x0803
#define CHIP_TC_4_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID                0x1000
#define CHIP_TC_4_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID           0x1001
#define CHIP_TC_4_WAVEFORM_PWM_PHASE_CORRECT_ID                     0x1002
#define CHIP_TC_4_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID                0x1003
#define CHIP_TC_4_WAVEFORM_CTC_ICR_ID                               0x1800
#define CHIP_TC_4_WAVEFORM_FAST_PWM_ID                              0x1802
#define CHIP_TC_4_WAVEFORM_FAST_PWM_OCRA_ID                         0x1803

#define CHIP_TC_4_CLOCK_REG                                         CHIP_REG_TCCR4B
#define CHIP_TC_4_CLOCK_MASK                                        0x07
#define CHIP_TC_4_CLOCK_NONE_ID                                     0x00
#define CHIP_TC_4_CLOCK_1_ID                                        0x01
#define CHIP_TC_4_CLOCK_8_ID                                        0x02
#define CHIP_TC_4_CLOCK_64_ID                                       0x03
#define CHIP_TC_4_CLOCK_256_ID                                      0x04
#define CHIP_TC_4_CLOCK_1024_ID                                     0x05
#define CHIP_TC_4_CLOCK_EXT_FALLING_ID                              0x06
#define CHIP_TC_4_CLOCK_EXT_RISING_ID                               0x07

#define CHIP_TC_4_COUNTER_REG                                       CHIP_REG_TCNT4

#define CHIP_TC_4_PRESCALER_RESET_REG                               CHIP_REG_GTCCR
#define CHIP_TC_4_PRESCALER_RESET_BIT                               0

#define CHIP_TC_4_SYNCHRONIZE_REG                                   CHIP_REG_GTCCR
#define CHIP_TC_4_SYNCHRONIZE_BIT                                   7

#define CHIP_TC_4_COMPARE_A_REG                                     CHIP_REG_OCR4A
#define CHIP_TC_4_COMPARE_A_INT_ENABLE_REG                          CHIP_REG_TIMSK4
#define CHIP_TC_4_COMPARE_A_INT_ENABLE_BIT                          1
#define CHIP_TC_4_COMPARE_A_INT_FLAG_REG                            CHIP_REG_TIFR4
#define CHIP_TC_4_COMPARE_A_INT_FLAG_BIT                            1
#define CHIP_TC_4_COMPARE_A_OUTPUT_MODE_REG                         CHIP_REG_TCCR4A
#define CHIP_TC_4_COMPARE_A_OUTPUT_MODE_MASK                        0xC0
#define CHIP_TC_4_COMPARE_A_OUTPUT_MODE_DISCONNECTED_ID             0x00
#define CHIP_TC_4_COMPARE_A_OUTPUT_MODE_TOGGLE_ID                   0x40
#define CHIP_TC_4_COMPARE_A_OUTPUT_MODE_CLEAR_ID                    0x80
#define CHIP_TC_4_COMPARE_A_OUTPUT_MODE_SET_ID                      0xC0

#define CHIP_TC_4_COMPARE_B_REG                                     CHIP_REG_OCR4B
#define CHIP_TC_4_COMPARE_B_INT_ENABLE_REG                          CHIP_REG_TIMSK4
#define CHIP_TC_4_COMPARE_B_INT_ENABLE_BIT                          2
#define CHIP_TC_4_COMPARE_B_INT_FLAG_REG                            CHIP_REG_TIFR4
#define CHIP_TC_4_COMPARE_B_INT_FLAG_BIT                            2
#define CHIP_TC_4_COMPARE_B_OUTPUT_MODE_REG                         CHIP_REG_TCCR4A
#define CHIP_TC_4_COMPARE_B_OUTPUT_MODE_MASK                        0x30
#define CHIP_TC_4_COMPARE_B_OUTPUT_MODE_DISCONNECTED_ID             0x00
#define CHIP_TC_4_COMPARE_B_OUTPUT_MODE_TOGGLE_ID                   0x10
#define CHIP_TC_4_COMPARE_B_OUTPUT_MODE_CLEAR_ID                    0x20
#define CHIP_TC_4_COMPARE_B_OUTPUT_MODE_SET_ID                      0x30

#define CHIP_TC_4_OVERFLOW_INT_ENABLE_REG                           CHIP_REG_TIMSK4
#define CHIP_TC_4_OVERFLOW_INT_ENABLE_BIT                           0
#define CHIP_TC_4_OVERFLOW_INT_FLAG_REG                             CHIP_REG_TIFR4
#define CHIP_TC_4_OVERFLOW_INT_FLAG_BIT                             0

#define CHIP_TC_4_CAPTURE_REG                                       CHIP_REG_ICR4
#define CHIP_TC_4_CAPTURE_NOISE_CANCEL_ENABLE_REG                   CHIP_REG_TCCR4B
#define CHIP_TC_4_CAPTURE_NOISE_CANCEL_ENABLE_BIT                   7
#define CHIP_TC_4_CAPTURE_EDGE_REG                                  CHIP_REG_TCCR4B
#define CHIP_TC_4_CAPTURE_EDGE_MASK                                 0x40
#define CHIP_TC_4_CAPTURE_EDGE_FALLING_ID                           0x00
#define CHIP_TC_4_CAPTURE_EDGE_RISING_ID                            0x40
#define CHIP_TC_4_CAPTURE_INT_ENABLE_REG                            CHIP_REG_TIMSK4
#define CHIP_TC_4_CAPTURE_INT_ENABLE_BIT                            5
#define CHIP_TC_4_CAPTURE_INT_FLAG_REG                              CHIP_REG_TIFR4
#define CHIP_TC_4_CAPTURE_INT_FLAG_BIT                              5

//------------------------------------------------
// Usarts

#define CHIP_USART_1

#define CHIP_USART_1_RX_DATA_REG                                    CHIP_REG_UDR1
#define CHIP_USART_1_RX_DATA_9_REG                                  CHIP_REG_UCSR1B
#define CHIP_USART_1_RX_DATA_9_BIT                                  1

#define CHIP_USART_1_TX_DATA_REG                                    CHIP_REG_UDR1
#define CHIP_USART_1_TX_DATA_9_REG                                  CHIP_REG_UCSR1B
#define CHIP_USART_1_TX_DATA_9_BIT                                  0

#define CHIP_USART_1_BAUD_REG                                       CHIP_REG_UBRR1

#define CHIP_USART_1_FRAME_ERROR_REG                                CHIP_REG_UCSR1A
#define CHIP_USART_1_FRAME_ERROR_BIT                                4
#define CHIP_USART_1_DATA_OVERRUN_REG                               CHIP_REG_UCSR1A
#define CHIP_USART_1_DATA_OVERRUN_BIT                               3
#define CHIP_USART_1_PARITY_ERROR_REG                               CHIP_REG_UCSR1A
#define CHIP_USART_1_PARITY_ERROR_BIT                               2

#define CHIP_USART_1_BAUD_MODE_REG                                  CHIP_REG_UCSR1A
#define CHIP_USART_1_BAUD_MODE_MASK                                 0x02
#define CHIP_USART_1_BAUD_MODE_NORMAL_ID                            0x00
#define CHIP_USART_1_BAUD_MODE_DOUBLE_ID                            0x02

#define CHIP_USART_1_MULTI_PROCESSOR_COMMUNICATION_REG              CHIP_REG_UCSR1A
#define CHIP_USART_1_MULTI_PROCESSOR_COMMUNICATION_BIT              0

#define CHIP_USART_1_RX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSR1B
#define CHIP_USART_1_RX_COMPLETE_INT_ENABLE_BIT                     7
#define CHIP_USART_1_TX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSR1B
#define CHIP_USART_1_TX_COMPLETE_INT_ENABLE_BIT                     6
#define CHIP_USART_1_DATA_REG_EMPTY_INT_ENABLE_REG                  CHIP_REG_UCSR1B
#define CHIP_USART_1_DATA_REG_EMPTY_INT_ENABLE_BIT                  5

#define CHIP_USART_1_RX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSR1A
#define CHIP_USART_1_RX_COMPLETE_INT_FLAG_BIT                       7
#define CHIP_USART_1_TX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSR1A
#define CHIP_USART_1_TX_COMPLETE_INT_FLAG_BIT                       6
#define CHIP_USART_1_DATA_REG_EMPTY_INT_FLAG_REG                    CHIP_REG_UCSR1A
#define CHIP_USART_1_DATA_REG_EMPTY_INT_FLAG_BIT                    5

#define CHIP_USART_1_RX_ENABLE_REG                                  CHIP_REG_UCSR1B
#define CHIP_USART_1_RX_ENABLE_BIT                                  4
#define CHIP_USART_1_TX_ENABLE_REG                                  CHIP_REG_UCSR1B
#define CHIP_USART_1_TX_ENABLE_BIT                                  3

#define CHIP_USART_1_MODE_REG                                       CHIP_REG_UCSR1C
#define CHIP_USART_1_MODE_MASK                                      0xC0
#define CHIP_USART_1_MODE_ASYNCHRONOUS_ID                           0x00
#define CHIP_USART_1_MODE_SYNCHRONOUS_ID                            0x40
#define CHIP_USART_1_MODE_MASTER_SPI_ID                             0xC0

#define CHIP_USART_1_PARITY_REG                                     CHIP_REG_UCSR1C
#define CHIP_USART_1_PARITY_MASK                                    0x30
#define CHIP_USART_1_PARITY_DISABLE_ID                              0x00
#define CHIP_USART_1_PARITY_EVEN_ID                                 0x20
#define CHIP_USART_1_PARITY_ODD_ID                                  0x30

#define CHIP_USART_1_STOP_BITS_REG                                  CHIP_REG_UCSR1C
#define CHIP_USART_1_STOP_BITS_MASK                                 0x08
#define CHIP_USART_1_STOP_BITS_1_ID                                 0x00
#define CHIP_USART_1_STOP_BITS_2_ID                                 0x08

#define CHIP_USART_1_CHARACTER_SIZE_REG                             CHIP_REG_UCSR1C
#define CHIP_USART_1_CHARACTER_SIZE_MASK                            0x06
#define CHIP_USART_1_CHARACTER_SIZE_REG_EXTRA                       CHIP_REG_UCSR1B
#define CHIP_USART_1_CHARACTER_SIZE_MASK_EXTRA                      0x04
#define CHIP_USART_1_CHARACTER_SIZE_5_ID                            0x0000
#define CHIP_USART_1_CHARACTER_SIZE_6_ID                            0x0002
#define CHIP_USART_1_CHARACTER_SIZE_7_ID                            0x0004
#define CHIP_USART_1_CHARACTER_SIZE_8_ID                            0x0006
#define CHIP_USART_1_CHARACTER_SIZE_9_ID                            0x0406

#define CHIP_USART_1_POLARITY_REG                                   CHIP_REG_UCSR1C
#define CHIP_USART_1_POLARITY_MASK                                  0x01
#define CHIP_USART_1_POLARITY_TX_RISING_RX_FALLING_ID               0x00
#define CHIP_USART_1_POLARITY_TX_FALLING_RX_RISING_ID               0x01

//------------------------------------------------
// Serial peripheral interfaces

#define CHIP_SPI_1

#define CHIP_SPI_1_DATA_REG                                         CHIP_REG_SPDR1

#define CHIP_SPI_1_ENABLE_REG                                       CHIP_REG_SPCR1
#define CHIP_SPI_1_ENABLE_BIT                                       6

#define CHIP_SPI_1_INT_ENABLE_REG                                   CHIP_REG_SPCR1
#define CHIP_SPI_1_INT_ENABLE_BIT                                   7

#define CHIP_SPI_1_DATA_ORDER_REG                                   CHIP_REG_SPCR1
#define CHIP_SPI_1_DATA_ORDER_MASK                                  0x20
#define CHIP_SPI_1_DATA_ORDER_MSB_FIRST_ID                          0x00
#define CHIP_SPI_1_DATA_ORDER_LSB_FIRST_ID                          0x20

#define CHIP_SPI_1_MASTER_SLAVE_SELECT_REG                          CHIP_REG_SPCR1
#define CHIP_SPI_1_MASTER_SLAVE_SELECT_MASK                         0x10
#define CHIP_SPI_1_MASTER_SLAVE_SELECT_SLAVE_ID                     0x00
#define CHIP_SPI_1_MASTER_SLAVE_SELECT_MASTER_ID                    0x10

#define CHIP_SPI_1_POLARITY_REG                                     CHIP_REG_SPCR1
#define CHIP_SPI_1_POLARITY_MASK                                    0x08
#define CHIP_SPI_1_POLARITY_LEADING_RISING_TRAILING_FALLING_ID      0x00
#define CHIP_SPI_1_POLARITY_LEADING_FALLING_TRAILING_RISING_ID      0x08

#define CHIP_SPI_1_PHASE_REG                                        CHIP_REG_SPCR1
#define CHIP_SPI_1_PHASE_MASK                                       0x04
#define CHIP_SPI_1_PHASE_LEADING_SAMPLE_TRAILING_SETUP_ID           0x00
#define CHIP_SPI_1_PHASE_LEADING_SETUP_TRAILING_SAMPLE_ID           0x04

#define CHIP_SPI_1_CLOCK_REG                                        CHIP_REG_SPCR1
#define CHIP_SPI_1_CLOCK_MASK                                       0x03
#define CHIP_SPI_1_CLOCK_REG_EXTRA                                  CHIP_REG_SPSR1
#define CHIP_SPI_1_CLOCK_MASK_EXTRA                                 0x01
#define CHIP_SPI_1_CLOCK_DIV_4_ID                                   0x0000
#define CHIP_SPI_1_CLOCK_DIV_16_ID                                  0x0001
#define CHIP_SPI_1_CLOCK_DIV_64_ID                                  0x0002
#define CHIP_SPI_1_CLOCK_DIV_128_ID                                 0x0003
#define CHIP_SPI_1_CLOCK_DIV_2_ID                                   0x0100
#define CHIP_SPI_1_CLOCK_DIV_8_ID                                   0x0101
#define CHIP_SPI_1_CLOCK_DIV_32_ID                                  0x0102

#define CHIP_SPI_1_INT_FLAG_REG                                     CHIP_REG_SPSR1
#define CHIP_SPI_1_INT_FLAG_BIT                                     7

#define CHIP_SPI_1_COLLISION_FLAG_REG                               CHIP_REG_SPSR1
#define CHIP_SPI_1_COLLISION_FLAG_BIT                               6

//------------------------------------------------
// Two wire serial interfaces

#define CHIP_TWI_1

#define CHIP_TWI_1_PRESCALER_REG                                    CHIP_REG_TWSR1
#define CHIP_TWI_1_PRESCALER_MASK                                   0x03
#define CHIP_TWI_1_PRESCALER_1_ID                                   0x00
#define CHIP_TWI_1_PRESCALER_4_ID                                   0x01
#define CHIP_TWI_1_PRESCALER_16_ID                                  0x02
#define CHIP_TWI_1_PRESCALER_64_ID                                  0x03

#define CHIP_TWI_1_DATA_REG                                         CHIP_REG_TWDR1

#define CHIP_TWI_1_STATUS_REG                                       CHIP_REG_TWSR1
#define CHIP_TWI_1_STATUS_MASK                                      0xF8
// TODO Add status values. Make sense of all this.
// #define CHIP_TWI_1_STATUS_MT_START_ID                               0x08
// #define CHIP_TWI_1_STATUS_MT_REPEAT_ID                              0x10
// #define CHIP_TWI_1_STATUS_MT_SLA_W_ACK_ID                           0x18
// #define CHIP_TWI_1_STATUS_MT_SLA_W_NOT_ACK_ID                       0x20
// #define CHIP_TWI_1_STATUS_MT_DATA_ACK_ID                            0x28
// #define CHIP_TWI_1_STATUS_MT_DATA_NOT_ACK_ID                        0x30
// #define CHIP_TWI_1_STATUS_MT_ARB_LOST_ID                            0x38
// #define CHIP_TWI_1_STATUS_MR_START_ID                               0x08
// #define CHIP_TWI_1_STATUS_MR_REPEAT_ID                              0x10
// #define CHIP_TWI_1_STATUS_MR_ARB_LOST_ID                            0x38
// #define CHIP_TWI_1_STATUS_MR_SLA_R_ACK_ID                           0x40
// #define CHIP_TWI_1_STATUS_MR_SLA_R_NOT_ACK_ID                       0x48
// #define CHIP_TWI_1_STATUS_MR_DATA_ACK_ID                            0x50
// #define CHIP_TWI_1_STATUS_MR_DATA_NOT_ACK_ID                        0x58

#define CHIP_TWI_1_BIT_RATE_REG                                     CHIP_REG_TWBR1

#define CHIP_TWI_1_CONTROL_REG                                      CHIP_REG_TWCR1

#define CHIP_TWI_1_ENABLE_REG                                       CHIP_REG_TWCR1
#define CHIP_TWI_1_ENABLE_BIT                                       2

#define CHIP_TWI_1_INT_FLAG_REG                                     CHIP_REG_TWCR1
#define CHIP_TWI_1_INT_FLAG_BIT                                     7

#define CHIP_TWI_1_INT_ENABLE_REG                                   CHIP_REG_TWCR1
#define CHIP_TWI_1_INT_ENABLE_BIT                                   0

#define CHIP_TWI_1_ENABLE_ACK_REG                                   CHIP_REG_TWCR1
#define CHIP_TWI_1_ENABLE_ACK_BIT                                   6

#define CHIP_TWI_1_START_CONDITION_REG                              CHIP_REG_TWCR1
#define CHIP_TWI_1_START_CONDITION_BIT                              5

#define CHIP_TWI_1_STOP_CONDITION_REG                               CHIP_REG_TWCR1
#define CHIP_TWI_1_STOP_CONDITION_BIT                               4

#define CHIP_TWI_1_WRITE_COLLISION_FLAG_REG                         CHIP_REG_TWCR1
#define CHIP_TWI_1_WRITE_COLLISION_FLAG_BIT                         3

#define CHIP_TWI_1_GEN_CALL_REC_ENABLE_REG                          CHIP_REG_TWAR1
#define CHIP_TWI_1_GEN_CALL_REC_ENABLE_BIT                          0

#define CHIP_TWI_1_ADDRESS_REG                                      CHIP_REG_TWAR1
#define CHIP_TWI_1_ADDRESS_MASK                                     0xFE

#define CHIP_TWI_1_ADDRESS_MASK_REG                                 CHIP_REG_TWAMR1
#define CHIP_TWI_1_ADDRESS_MASK_MASK                                0xFE

#endif

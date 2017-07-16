#ifndef NBAVR_ATTINY85_H
#define NBAVR_ATTINY85_H

#define ATTINY85

#define NBAVR_CHIP_DEFINED

//------------------------------------------------
// Ram Size

#define CHIP_RAM_SIZE                                                   512

//------------------------------------------------
// Status Register

#define CHIP_STATUS_REG                                                 REG8(0x3f)

//------------------------------------------------
// Reset Status Register

#define CHIP_RESET_STATUS_REG                                           REG8(0x34)

//------------------------------------------------
// Watchdog Timer

#define CHIP_WATCHDOG_TIMER_CONTROL_REG                                 REG8(0x21)
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_0_BIT                         0
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_1_BIT                         1
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_2_BIT                         2
#define CHIP_WATCHDOG_TIMER_ENABLE_BIT                                  3
#define CHIP_WATCHDOG_TIMER_CHANGE_ENABLE_BIT                           4
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_3_BIT                         5
#define CHIP_WATCHDOG_TIMER_INT_ENABLE_BIT                              6
#define CHIP_WATCHDOG_TIMER_INT_FLAG_BIT                                7

//------------------------------------------------
// IO Ports

// Including non-existant ports.
#define CHIP_PORT_COUNT                                                 2

#define CHIP_PORT_B                                                     TRUE
#define CHIP_PORT_B_OUTPUT_REG                                          REG8(0x18)
#define CHIP_PORT_B_DIRECTION_REG                                       REG8(0x17)
#define CHIP_PORT_B_INPUT_REG                                           REG8(0x16)

//------------------------------------------------
// IO Pins

// Maximum number of pins per port.
#define CHIP_PIN_COUNT                                                  6

#define CHIP_PIN_B0                                                     TRUE
#define CHIP_PIN_B1                                                     TRUE
#define CHIP_PIN_B2                                                     TRUE
#define CHIP_PIN_B3                                                     TRUE
#define CHIP_PIN_B4                                                     TRUE
#define CHIP_PIN_B5                                                     TRUE

//------------------------------------------------
// ADC

#define CHIP_ADC                                                        TRUE

#define CHIP_ADC_ENABLE_REG                                             REG8(0x06)
#define CHIP_ADC_ENABLE_BIT                                             7

#define CHIP_ADC_START_REG                                              REG8(0x06)
#define CHIP_ADC_START_BIT                                              6

// TODO Add extra reference sources to hardware code.
#define CHIP_ADC_REFERENCE_BIT_0_REG                                    REG8(0x07)
#define CHIP_ADC_REFERENCE_BIT_1_REG                                    REG8(0x07)
// #define CHIP_ADC_REFERENCE_BIT_1_REG                                    REG8(0x07)
#define CHIP_ADC_REFERENCE_BIT_0_BIT                                    6
#define CHIP_ADC_REFERENCE_BIT_1_BIT                                    7
// #define CHIP_ADC_REFERENCE_BIT_1_BIT                                    4
#define CHIP_ADC_REFERENCE_AREF_ID                                      1
#define CHIP_ADC_REFERENCE_AVCC_ID                                      0
#define CHIP_ADC_REFERENCE_INTERNAL_ID                                  2

// TODO Add differential and gain to hardware code.
#define CHIP_ADC_CHANNEL_BIT_0_REG                                      REG8(0x07)
#define CHIP_ADC_CHANNEL_BIT_1_REG                                      REG8(0x07)
#define CHIP_ADC_CHANNEL_BIT_2_REG                                      REG8(0x07)
#define CHIP_ADC_CHANNEL_BIT_3_REG                                      REG8(0x07)
#define CHIP_ADC_CHANNEL_BIT_0_BIT                                      0
#define CHIP_ADC_CHANNEL_BIT_1_BIT                                      1
#define CHIP_ADC_CHANNEL_BIT_2_BIT                                      2
#define CHIP_ADC_CHANNEL_BIT_3_BIT                                      3
#define CHIP_ADC_CHANNEL_0_ID                                           0
#define CHIP_ADC_CHANNEL_1_ID                                           1
#define CHIP_ADC_CHANNEL_2_ID                                           2
#define CHIP_ADC_CHANNEL_3_ID                                           3
#define CHIP_ADC_CHANNEL_VBG_ID                                         12
#define CHIP_ADC_CHANNEL_GND_ID                                         13

#define CHIP_ADC_TRIGGER                                                TRUE
#define CHIP_ADC_TRIGGER_ENABLE_REG                                     REG8(0x06)
#define CHIP_ADC_TRIGGER_ENABLE_BIT                                     5
#define CHIP_ADC_TRIGGER_BIT_0_REG                                      REG8(0x03)
#define CHIP_ADC_TRIGGER_BIT_1_REG                                      REG8(0x03)
#define CHIP_ADC_TRIGGER_BIT_2_REG                                      REG8(0x03)
#define CHIP_ADC_TRIGGER_BIT_0_BIT                                      0
#define CHIP_ADC_TRIGGER_BIT_1_BIT                                      1
#define CHIP_ADC_TRIGGER_BIT_2_BIT                                      2
#define CHIP_ADC_TRIGGER_FREE_RUNNING_ID                                0
#define CHIP_ADC_TRIGGER_ANALOG_COMPARATOR_ID                           1
#define CHIP_ADC_TRIGGER_EXTERNAL_INT_0_ID                              2
#define CHIP_ADC_TRIGGER_TIMER0_COMPARE_MATCH_A_ID                      3
#define CHIP_ADC_TRIGGER_TIMER0_OVERFLOW_ID                             4
// #define CHIP_ADC_TRIGGER_TIMER0_COMPARE_MATCH_B_ID                      5
// TODO Add more trigger sources to hardware code.

#define CHIP_ADC_INT_FLAG_REG                                           REG8(0x06)
#define CHIP_ADC_INT_FLAG_BIT                                           4
#define CHIP_ADC_INT_ENABLE_REG                                         REG8(0x06)
#define CHIP_ADC_INT_ENABLE_BIT                                         3
#define CHIP_ADC_INT_VECTOR                                             VECT(9)

#define CHIP_ADC_LEFT_ADJUST_REG                                        REG8(0x07)
#define CHIP_ADC_LEFT_ADJUST_BIT                                        5

#define CHIP_ADC_DATA_REG                                               REG16(0x04)

#define CHIP_ADC_PRESCALER                                              TRUE
#define CHIP_ADC_PRESCALER_BIT_0_REG                                    REG8(0x06)
#define CHIP_ADC_PRESCALER_BIT_1_REG                                    REG8(0x06)
#define CHIP_ADC_PRESCALER_BIT_2_REG                                    REG8(0x06)
#define CHIP_ADC_PRESCALER_BIT_0_BIT                                    0
#define CHIP_ADC_PRESCALER_BIT_1_BIT                                    1
#define CHIP_ADC_PRESCALER_BIT_2_BIT                                    2
#define CHIP_ADC_PRESCALER_2_ID                                         0
#define CHIP_ADC_PRESCALER_4_ID                                         2
#define CHIP_ADC_PRESCALER_8_ID                                         3
#define CHIP_ADC_PRESCALER_16_ID                                        4
#define CHIP_ADC_PRESCALER_32_ID                                        5
#define CHIP_ADC_PRESCALER_64_ID                                        6
#define CHIP_ADC_PRESCALER_128_ID                                       7

//------------------------------------------------
// External Interrupts

#define CHIP_EXINT_COUNT                                                1

#define CHIP_EXINT_0                                                    TRUE
#define CHIP_EXINT_0_ENABLE_REG                                         REG8(0x3b)
#define CHIP_EXINT_0_ENABLE_BIT                                         6
#define CHIP_EXINT_0_FLAG_REG                                           REG8(0x3a)
#define CHIP_EXINT_0_FLAG_BIT                                           6
#define CHIP_EXINT_0_TRIGGER_BIT_0_REG                                  REG8(0x35)
#define CHIP_EXINT_0_TRIGGER_BIT_1_REG                                  REG8(0x35)
#define CHIP_EXINT_0_TRIGGER_BIT_0_BIT                                  0
#define CHIP_EXINT_0_TRIGGER_BIT_1_BIT                                  1
#define CHIP_EXINT_0_VECTOR                                             VECT(2)
#define CHIP_EXINT_0_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_0_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_0_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_0_TRIGGER_RISING_ID                                  3

//------------------------------------------------
// Pin Change Interrupts

#define CHIP_PCINT_COUNT                                                1

#define CHIP_PCINT_0                                                    TRUE
#define CHIP_PCINT_0_ENABLE_REG                                         REG8(0x3b)
#define CHIP_PCINT_0_ENABLE_BIT                                         5
#define CHIP_PCINT_0_FLAG_REG                                           REG8(0x3a)
#define CHIP_PCINT_0_FLAG_BIT                                           6
#define CHIP_PCINT_0_MASK_REG                                           REG8(0x15)
#define CHIP_PCINT_0_INT_VECTOR                                         VECT(3)

//------------------------------------------------
// Timer Counters

#define CHIP_TIMERCOUNTER_COUNT                                         2

//------------------------------------------------
// Timer Counter 0

#define CHIP_TIMERCOUNTER_0                                             TRUE

#define CHIP_TIMERCOUNTER_0_TYPE                                        uint8_t

#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_MODE                          TRUE
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_MODE_DISCONNECTED_ID          0
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_MODE_TOGGLE_ID                1
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_MODE_CLEAR_ID                 2
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_MODE_SET_ID                   3

#define CHIP_TIMERCOUNTER_0_WAVEFORM                                    TRUE
#define CHIP_TIMERCOUNTER_0_WAVEFORM_NORMAL_ID                          0
#define CHIP_TIMERCOUNTER_0_WAVEFORM_PWM_PHASE_CORRECT_ID               1
#define CHIP_TIMERCOUNTER_0_WAVEFORM_CTC_OCRA_ID                        2
#define CHIP_TIMERCOUNTER_0_WAVEFORM_FAST_PWM_ID                        3
#define CHIP_TIMERCOUNTER_0_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          5
#define CHIP_TIMERCOUNTER_0_WAVEFORM_FAST_PWM_OCRA_ID                   7

#define CHIP_TIMERCOUNTER_0_WAVEFORM_BIT_COUNT                          3
#define CHIP_TIMERCOUNTER_0_WAVEFORM_BIT_0_REG                          REG8(0x2a)
#define CHIP_TIMERCOUNTER_0_WAVEFORM_BIT_1_REG                          REG8(0x2a)
#define CHIP_TIMERCOUNTER_0_WAVEFORM_BIT_2_REG                          REG8(0x33)
#define CHIP_TIMERCOUNTER_0_WAVEFORM_BIT_0_BIT                          0
#define CHIP_TIMERCOUNTER_0_WAVEFORM_BIT_1_BIT                          1
#define CHIP_TIMERCOUNTER_0_WAVEFORM_BIT_2_BIT                          3

#define CHIP_TIMERCOUNTER_0_CLOCK_NONE_ID                               0
#define CHIP_TIMERCOUNTER_0_CLOCK_1_ID                                  1
#define CHIP_TIMERCOUNTER_0_CLOCK_8_ID                                  2
#define CHIP_TIMERCOUNTER_0_CLOCK_64_ID                                 3
#define CHIP_TIMERCOUNTER_0_CLOCK_256_ID                                4
#define CHIP_TIMERCOUNTER_0_CLOCK_1024_ID                               5
#define CHIP_TIMERCOUNTER_0_CLOCK_EXT_FALLING_ID                        6
#define CHIP_TIMERCOUNTER_0_CLOCK_EXT_RISING_ID                         7
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_0_REG                             REG8(0x33)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_1_REG                             REG8(0x33)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_2_REG                             REG8(0x33)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_0_COUNTER_REG                                 REG8(0x32)

#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(0x2a)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(0x2a)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_REG                         REG8(0x29)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(0x39)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_ENABLE_BIT              2
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(0x38)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_FLAG_BIT                4
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(11)

#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(0x2a)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(0x2a)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_REG                         REG8(0x28)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(0x39)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_ENABLE_BIT              3
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(0x38)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_FLAG_BIT                3
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(12)

#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_ENABLE_REG                     REG8(0x39)
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_ENABLE_BIT                     1
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_FLAG_REG                       REG8(0x38)
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_FLAG_BIT                       1
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_VECTOR                         VECT(6)

// TODO Add input capture definitions.

//------------------------------------------------
// Timer Counter X

#define CHIP_TIMERCOUNTER_1                                             TRUE

#define CHIP_TIMERCOUNTER_1_TYPE                                        uint8_t

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_MODE                          TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_MODE_DISCONNECTED_ID          0
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_MODE_TOGGLE_ID                1
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_MODE_CLEAR_ID                 2
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_MODE_SET_ID                   3

// TODO Change ORCA to OCR throughout code. Or maybe add OCRC option?
#define CHIP_TIMERCOUNTER_1_WAVEFORM                                    TRUE
#define CHIP_TIMERCOUNTER_1_WAVEFORM_NORMAL_ID                          0
#define CHIP_TIMERCOUNTER_1_WAVEFORM_CTC_OCRA_ID                        2 // XXX Actually OCRC
#define CHIP_TIMERCOUNTER_1_WAVEFORM_FAST_PWM_OCRA_ID                   1 // XXX Actually OCRC
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_COUNT                          2
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_0_REG                          REG8(0x30)
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_1_REG                          REG8(0x30)
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_0_BIT                          6
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_1_BIT                          7

#define CHIP_TIMERCOUNTER_1_CLOCK_NONE_ID                               0
#define CHIP_TIMERCOUNTER_1_CLOCK_1_ID                                  1
// #define CHIP_TIMERCOUNTER_1_CLOCK_2_ID                                  2
// #define CHIP_TIMERCOUNTER_1_CLOCK_4_ID                                  3
#define CHIP_TIMERCOUNTER_1_CLOCK_8_ID                                  4
// #define CHIP_TIMERCOUNTER_1_CLOCK_16_ID                                 5
#define CHIP_TIMERCOUNTER_1_CLOCK_32_ID                                 6
#define CHIP_TIMERCOUNTER_1_CLOCK_64_ID                                 7
#define CHIP_TIMERCOUNTER_1_CLOCK_128_ID                                8
#define CHIP_TIMERCOUNTER_1_CLOCK_256_ID                                9
// #define CHIP_TIMERCOUNTER_1_CLOCK_512_ID                                10
#define CHIP_TIMERCOUNTER_1_CLOCK_1024_ID                               11
// #define CHIP_TIMERCOUNTER_1_CLOCK_2048_ID                               12
// #define CHIP_TIMERCOUNTER_1_CLOCK_4096_ID                               13
// #define CHIP_TIMERCOUNTER_1_CLOCK_8192_ID                               14
// #define CHIP_TIMERCOUNTER_1_CLOCK_16384_ID                              15
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_0_REG                             REG8(0x30)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_1_REG                             REG8(0x30)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_2_REG                             REG8(0x30)
// #define CHIP_TIMERCOUNTER_1_CLOCK_BIT_3_REG                             REG8(0x30)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_2_BIT                             2
// #define CHIP_TIMERCOUNTER_1_CLOCK_BIT_3_BIT                             3
// TODO Add more clock modes to hardware code.

#define CHIP_TIMERCOUNTER_1_COUNTER_REG                                 REG8(0x2f)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(0x30)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(0x30)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_REG                         REG8(0x2e)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(0x39)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_ENABLE_BIT              6
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(0x38)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_FLAG_BIT                6
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(4)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(0x2c)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(0x2c)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_REG                         REG8(0x2b)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(0x39)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_ENABLE_BIT              5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(0x38)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_FLAG_BIT                5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(10)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_REG                         REG8(0x2d)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_INT_FLAG_REG                REG8(0x38)

#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_ENABLE_REG                     REG8(0x39)
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_ENABLE_BIT                     2
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_FLAG_REG                       REG8(0x38)
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_FLAG_BIT                       2
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_VECTOR                         VECT(5)

//------------------------------------------------
// Usart

// #define CHIP_USART_COUNT                                                1
//
// #define CHIP_USART_0                                                    TRUE
//
// #define CHIP_USART_0_DATA_REG                                           REG8(0x0f)
//
// #define CHIP_USART_0_BAUD_RATE_REG_HIGH                                 REG8(0xXX)
// #define CHIP_USART_0_BAUD_RATE_REG_LOW                                  REG8(0xXX)
//
// #define CHIP_USART_0_FRAME_ERROR_REG                                    REG8(0xXX)
// #define CHIP_USART_0_FRAME_ERROR_BIT                                    X
// #define CHIP_USART_0_DATA_OVERRUN_REG                                   REG8(0xXX)
// #define CHIP_USART_0_DATA_OVERRUN_BIT                                   X
// #define CHIP_USART_0_PARITY_ERROR_REG                                   REG8(0xXX)
// #define CHIP_USART_0_PARITY_ERROR_BIT                                   X
//
// #define CHIP_USART_0_DOUBLE_SPEED_REG                                   REG8(0xXX)
// #define CHIP_USART_0_DOUBLE_SPEED_BIT                                   X
//
// #define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG                  REG8(0xXX)
// #define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT                  X
//
// #define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                         REG8(0xXX)
// #define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                         X
// #define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                         REG8(0xXX)
// #define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                         X
// #define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG                      REG8(0xXX)
// #define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT                      X
//
// #define CHIP_USART_0_RX_ENABLE_REG                                      REG8(0xXX)
// #define CHIP_USART_0_RX_ENABLE_BIT                                      X
// #define CHIP_USART_0_TX_ENABLE_REG                                      REG8(0xXX)
// #define CHIP_USART_0_TX_ENABLE_BIT                                      X
//
// #define CHIP_USART_0_RX_DATA_BIT_8_REG                                  REG8(0xXX)
// #define CHIP_USART_0_RX_DATA_BIT_8_BIT                                  X
// #define CHIP_USART_0_TX_DATA_BIT_8_REG                                  REG8(0xXX)
// #define CHIP_USART_0_TX_DATA_BIT_8_BIT                                  X
//
// #define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                               X
// #define CHIP_USART_0_MODE_SYNCHRONOUS_ID                                X
// #define CHIP_USART_0_MODE_MASTER_SPI_ID                                 X
// #define CHIP_USART_0_MODE_BIT_COUNT                                     X
// #define CHIP_USART_0_MODE_BIT_0_REG                                     REG8(0xXX)
// #define CHIP_USART_0_MODE_BIT_1_REG                                     REG8(0xXX)
// #define CHIP_USART_0_MODE_BIT_0_BIT                                     X
// #define CHIP_USART_0_MODE_BIT_1_BIT                                     X
//
// #define CHIP_USART_0_PARITY_DISABLE_ID                                  X
// #define CHIP_USART_0_PARITY_EVEN_ID                                     X
// #define CHIP_USART_0_PARITY_ODD_ID                                      X
// #define CHIP_USART_0_PARITY_BIT_0_REG                                   REG8(0xXX)
// #define CHIP_USART_0_PARITY_BIT_1_REG                                   REG8(0xXX)
// #define CHIP_USART_0_PARITY_BIT_0_BIT                                   X
// #define CHIP_USART_0_PARITY_BIT_1_BIT                                   X
//
// #define CHIP_USART_0_STOP_BITS_1_ID                                     X
// #define CHIP_USART_0_STOP_BITS_2_ID                                     X
// #define CHIP_USART_0_STOP_BITS_REG                                      REG8(0xXX)
// #define CHIP_USART_0_STOP_BITS_BIT                                      X
//
// #define CHIP_USART_0_CHARACTER_SIZE_5_ID                                X
// #define CHIP_USART_0_CHARACTER_SIZE_6_ID                                X
// #define CHIP_USART_0_CHARACTER_SIZE_7_ID                                X
// #define CHIP_USART_0_CHARACTER_SIZE_8_ID                                X
// #define CHIP_USART_0_CHARACTER_SIZE_9_ID                                X
// #define CHIP_USART_0_CHARACTER_SIZE_BIT_0_REG                           REG8(0xXX)
// #define CHIP_USART_0_CHARACTER_SIZE_BIT_1_REG                           REG8(0xXX)
// #define CHIP_USART_0_CHARACTER_SIZE_BIT_2_REG                           REG8(0xXX)
// #define CHIP_USART_0_CHARACTER_SIZE_BIT_0_BIT                           X
// #define CHIP_USART_0_CHARACTER_SIZE_BIT_1_BIT                           X
// #define CHIP_USART_0_CHARACTER_SIZE_BIT_2_BIT                           X
//
// #define CHIP_USART_0_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID             X
// #define CHIP_USART_0_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID             X
// #define CHIP_USART_0_CLOCK_POLARITY_REG                                 REG8(0xXX)
// #define CHIP_USART_0_CLOCK_POLARITY_BIT                                 X
//
// #define CHIP_USART_0_RX_INT_VECTOR                                      VECT(X)
// #define CHIP_USART_0_DE_INT_VECTOR                                      VECT(X)
// #define CHIP_USART_0_TX_INT_VECTOR                                      VECT(X)

#endif

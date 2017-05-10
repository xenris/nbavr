#ifndef NBAVR_ATMEGA8_HPP
#define NBAVR_ATMEGA8_HPP

#define ATMEGA8

#define NBAVR_CHIP_DEFINED

//------------------------------------------------
// Status Register

#define CHIP_STATUS_REG                                                 REG8(0x5F)

//------------------------------------------------
// Reset Status Register

#define CHIP_RESET_STATUS_REG                                           REG8(0x54)

//------------------------------------------------
// Watchdog Timer

#define CHIP_WATCHDOG_TIMER_CONTROL_REG                                 REG8(0x41)
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_0_BIT                         0
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_1_BIT                         1
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_2_BIT                         2
#define CHIP_WATCHDOG_TIMER_ENABLE_BIT                                  3
#define CHIP_WATCHDOG_TIMER_CHANGE_ENABLE_BIT                           4

//------------------------------------------------
// IO Ports

// Including non-existant ports.
#define CHIP_PORT_COUNT                                                 4

#define CHIP_PORT_B                                                     TRUE
#define CHIP_PORT_B_OUTPUT_REG                                          REG8(0x25)
#define CHIP_PORT_B_DIRECTION_REG                                       REG8(0x24)
#define CHIP_PORT_B_INPUT_REG                                           REG8(0x23)

#define CHIP_PORT_C                                                     TRUE
#define CHIP_PORT_C_OUTPUT_REG                                          REG8(0x28)
#define CHIP_PORT_C_DIRECTION_REG                                       REG8(0x27)
#define CHIP_PORT_C_INPUT_REG                                           REG8(0x26)

#define CHIP_PORT_D                                                     TRUE
#define CHIP_PORT_D_OUTPUT_REG                                          REG8(0x2B)
#define CHIP_PORT_D_DIRECTION_REG                                       REG8(0x2A)
#define CHIP_PORT_D_INPUT_REG                                           REG8(0x29)

//------------------------------------------------
// IO Pins

// Maximum number of pins per port.
#define CHIP_PIN_COUNT                                                  8

#define CHIP_PIN_B0                                                     TRUE
#define CHIP_PIN_B1                                                     TRUE
#define CHIP_PIN_B2                                                     TRUE
#define CHIP_PIN_B3                                                     TRUE
#define CHIP_PIN_B4                                                     TRUE
#define CHIP_PIN_B5                                                     TRUE
#define CHIP_PIN_B6                                                     TRUE
#define CHIP_PIN_B7                                                     TRUE

#define CHIP_PIN_C0                                                     TRUE
#define CHIP_PIN_C1                                                     TRUE
#define CHIP_PIN_C2                                                     TRUE
#define CHIP_PIN_C3                                                     TRUE
#define CHIP_PIN_C4                                                     TRUE
#define CHIP_PIN_C5                                                     TRUE
#define CHIP_PIN_C6                                                     TRUE

#define CHIP_PIN_D0                                                     TRUE
#define CHIP_PIN_D1                                                     TRUE
#define CHIP_PIN_D2                                                     TRUE
#define CHIP_PIN_D3                                                     TRUE
#define CHIP_PIN_D4                                                     TRUE
#define CHIP_PIN_D5                                                     TRUE
#define CHIP_PIN_D6                                                     TRUE
#define CHIP_PIN_D7                                                     TRUE

//------------------------------------------------
// ADC

#define CHIP_ADC                                                        TRUE

#define CHIP_ADC_ENABLE_REG                                             REG8(0x26)
#define CHIP_ADC_ENABLE_BIT                                             7

#define CHIP_ADC_START_REG                                              REG8(0x26)
#define CHIP_ADC_START_BIT                                              6

#define CHIP_ADC_REFERENCE_BIT_0_REG                                    REG8(0x27)
#define CHIP_ADC_REFERENCE_BIT_1_REG                                    REG8(0x27)
#define CHIP_ADC_REFERENCE_BIT_0_BIT                                    6
#define CHIP_ADC_REFERENCE_BIT_1_BIT                                    7
#define CHIP_ADC_REFERENCE_AREF_ID                                      0
#define CHIP_ADC_REFERENCE_AVCC_ID                                      1
#define CHIP_ADC_REFERENCE_INTERNAL_ID                                  3

#define CHIP_ADC_CHANNEL_BIT_0_REG                                      REG8(0x27)
#define CHIP_ADC_CHANNEL_BIT_1_REG                                      REG8(0x27)
#define CHIP_ADC_CHANNEL_BIT_2_REG                                      REG8(0x27)
#define CHIP_ADC_CHANNEL_BIT_3_REG                                      REG8(0x27)
#define CHIP_ADC_CHANNEL_BIT_0_BIT                                      0
#define CHIP_ADC_CHANNEL_BIT_1_BIT                                      1
#define CHIP_ADC_CHANNEL_BIT_2_BIT                                      2
#define CHIP_ADC_CHANNEL_BIT_3_BIT                                      3
#define CHIP_ADC_CHANNEL_0_ID                                           0
#define CHIP_ADC_CHANNEL_1_ID                                           1
#define CHIP_ADC_CHANNEL_2_ID                                           2
#define CHIP_ADC_CHANNEL_3_ID                                           3
#define CHIP_ADC_CHANNEL_4_ID                                           4
#define CHIP_ADC_CHANNEL_5_ID                                           5
#define CHIP_ADC_CHANNEL_6_ID                                           6
#define CHIP_ADC_CHANNEL_7_ID                                           7
#define CHIP_ADC_CHANNEL_VBG_ID                                         14
#define CHIP_ADC_CHANNEL_GND_ID                                         15

#define CHIP_ADC_FREE_RUNNING_ENABLE_REG                                REG8(0x26)
#define CHIP_ADC_FREE_RUNNING_ENABLE_BIT                                5

#define CHIP_ADC_INT_FLAG_REG                                           REG8(0x26)
#define CHIP_ADC_INT_FLAG_BIT                                           4
#define CHIP_ADC_INT_ENABLE_REG                                         REG8(0x26)
#define CHIP_ADC_INT_ENABLE_BIT                                         3
#define CHIP_ADC_INT_VECTOR                                             VECT(14)

#define CHIP_ADC_LEFT_ADJUST_REG                                        REG8(0x27)
#define CHIP_ADC_LEFT_ADJUST_BIT                                        5

#define CHIP_ADC_DATA_REG                                               REG8(0x24)

#define CHIP_ADC_PRESCALER                                              TRUE
#define CHIP_ADC_PRESCALER_BIT_0_REG                                    REG8(0x26)
#define CHIP_ADC_PRESCALER_BIT_1_REG                                    REG8(0x26)
#define CHIP_ADC_PRESCALER_BIT_2_REG                                    REG8(0x26)
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

#define CHIP_EXINT_COUNT                                                2

#define CHIP_EXINT_0                                                      TRUE
#define CHIP_EXINT_0_ENABLE_REG                                           REG8(0x5B)
#define CHIP_EXINT_0_ENABLE_BIT                                           6
#define CHIP_EXINT_0_FLAG_REG                                             REG8(0x5A)
#define CHIP_EXINT_0_FLAG_BIT                                             6
#define CHIP_EXINT_0_TRIGGER_BIT_0_REG                                    REG8(0x55)
#define CHIP_EXINT_0_TRIGGER_BIT_1_REG                                    REG8(0x55)
#define CHIP_EXINT_0_TRIGGER_BIT_0_BIT                                    0
#define CHIP_EXINT_0_TRIGGER_BIT_1_BIT                                    1
#define CHIP_EXINT_0_INT_VECTOR                                           VECT(1)
#define CHIP_EXINT_0_TRIGGER_LOW_ID                                       0
#define CHIP_EXINT_0_TRIGGER_CHANGE_ID                                    1
#define CHIP_EXINT_0_TRIGGER_FALLING_ID                                   2
#define CHIP_EXINT_0_TRIGGER_RISING_ID                                    3

#define CHIP_EXINT_1                                                      TRUE
#define CHIP_EXINT_1_ENABLE_REG                                           REG8(0x5B)
#define CHIP_EXINT_1_ENABLE_BIT                                           7
#define CHIP_EXINT_1_FLAG_REG                                             REG8(0x5A)
#define CHIP_EXINT_1_FLAG_BIT                                             7
#define CHIP_EXINT_1_TRIGGER_BIT_0_REG                                    REG8(0x55)
#define CHIP_EXINT_1_TRIGGER_BIT_1_REG                                    REG8(0x55)
#define CHIP_EXINT_1_TRIGGER_BIT_0_BIT                                    2
#define CHIP_EXINT_1_TRIGGER_BIT_1_BIT                                    3
#define CHIP_EXINT_1_INT_VECTOR                                           VECT(2)
#define CHIP_EXINT_1_TRIGGER_LOW_ID                                       0
#define CHIP_EXINT_1_TRIGGER_CHANGE_ID                                    1
#define CHIP_EXINT_1_TRIGGER_FALLING_ID                                   2
#define CHIP_EXINT_1_TRIGGER_RISING_ID                                    3

//------------------------------------------------
// Timer Counters

#define CHIP_TIMERCOUNTER_COUNT                                         3

//------------------------------------------------
// Timer Counter 0

#define CHIP_TIMERCOUNTER_0                                             TRUE

#define CHIP_TIMERCOUNTER_0_TYPE                                        uint8_t

#define CHIP_TIMERCOUNTER_0_CLOCK_NONE_ID                               0
#define CHIP_TIMERCOUNTER_0_CLOCK_1_ID                                  1
#define CHIP_TIMERCOUNTER_0_CLOCK_8_ID                                  2
#define CHIP_TIMERCOUNTER_0_CLOCK_64_ID                                 3
#define CHIP_TIMERCOUNTER_0_CLOCK_256_ID                                4
#define CHIP_TIMERCOUNTER_0_CLOCK_1024_ID                               5
#define CHIP_TIMERCOUNTER_0_CLOCK_FALLING_ID                            6
#define CHIP_TIMERCOUNTER_0_CLOCK_RISING_ID                             7
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_0_REG                             REG8(0x53)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_1_REG                             REG8(0x53)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_2_REG                             REG8(0x53)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_0_COUNTER_REG                                 REG8(0x52)

#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_ENABLE_REG                     REG8(0x59)
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_ENABLE_BIT                     0
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_FLAG_REG                       REG8(0x58)
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_FLAG_BIT                       0
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_VECTOR                         VECT(9)

//------------------------------------------------
// Timer Counter 1

#define CHIP_TIMERCOUNTER_1                                             TRUE

#define CHIP_TIMERCOUNTER_1_TYPE                                        uint16_t

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_MODE                          TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_MODE_DISCONNECTED_ID          0
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_MODE_TOGGLE_ID                1
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_MODE_CLEAR_ID                 2
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_MODE_SET_ID                   3

#define CHIP_TIMERCOUNTER_1_WAVEFORM                                    TRUE
#define CHIP_TIMERCOUNTER_1_WAVEFORM_NORMAL_ID                          0
#define CHIP_TIMERCOUNTER_1_WAVEFORM_PWM_PHASE_CORRECT_8_ID             1
#define CHIP_TIMERCOUNTER_1_WAVEFORM_PWM_PHASE_CORRECT_9_ID             2
#define CHIP_TIMERCOUNTER_1_WAVEFORM_PWM_PHASE_CORRECT_10_ID            3
#define CHIP_TIMERCOUNTER_1_WAVEFORM_CTC_OCRA_ID                        4
#define CHIP_TIMERCOUNTER_1_WAVEFORM_FAST_PWM_8_ID                      5
#define CHIP_TIMERCOUNTER_1_WAVEFORM_FAST_PWM_9_ID                      6
#define CHIP_TIMERCOUNTER_1_WAVEFORM_FAST_PWM_10_ID                     7
#define CHIP_TIMERCOUNTER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID          8
#define CHIP_TIMERCOUNTER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID 9
#define CHIP_TIMERCOUNTER_1_WAVEFORM_PWM_PHASE_CORRECT_ID               10
#define CHIP_TIMERCOUNTER_1_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          11
#define CHIP_TIMERCOUNTER_1_WAVEFORM_CTC_ID                             12
#define CHIP_TIMERCOUNTER_1_WAVEFORM_FAST_PWM_ID                        14
#define CHIP_TIMERCOUNTER_1_WAVEFORM_FAST_PWM_OCRA_ID                   15
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_COUNT                          4
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_0_REG                          REG8(0x4F)
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_1_REG                          REG8(0x4F)
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_2_REG                          REG8(0x4E)
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_3_REG                          REG8(0x4E)
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_0_BIT                          0
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_1_BIT                          1
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_2_BIT                          3
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_3_BIT                          4

#define CHIP_TIMERCOUNTER_1_CLOCK_NONE_ID                               0
#define CHIP_TIMERCOUNTER_1_CLOCK_1_ID                                  1
#define CHIP_TIMERCOUNTER_1_CLOCK_8_ID                                  2
#define CHIP_TIMERCOUNTER_1_CLOCK_64_ID                                 3
#define CHIP_TIMERCOUNTER_1_CLOCK_256_ID                                4
#define CHIP_TIMERCOUNTER_1_CLOCK_1024_ID                               5
#define CHIP_TIMERCOUNTER_1_CLOCK_FALLING_ID                            6
#define CHIP_TIMERCOUNTER_1_CLOCK_RISING_ID                             7
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_0_REG                             REG8(0x4E)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_1_REG                             REG8(0x4E)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_2_REG                             REG8(0x4E)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_1_COUNTER_REG                                 REG8(0x4C)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(0x4F)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(0x4F)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_REG                         REG8(0x4A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(0x59)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_ENABLE_BIT              4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(0x58)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_FLAG_BIT                4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(6)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(0x4F)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(0x4F)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_REG                         REG8(0x48)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(0x59)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_ENABLE_BIT              3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(0x58)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_FLAG_BIT                3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(7)

#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_ENABLE_REG                     REG8(0x59)
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_ENABLE_BIT                     2
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_FLAG_REG                       REG8(0x58)
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_FLAG_BIT                       2
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_VECTOR                         VECT(8)

// TODO Add input capture definitions.

//------------------------------------------------
// Timer2

#define CHIP_TIMERCOUNTER_2                                             TRUE

#define CHIP_TIMERCOUNTER_2_TYPE                                        uint8_t

#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_MODE                          TRUE
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_MODE_DISCONNECTED_ID          0
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_MODE_TOGGLE_ID                1
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_MODE_CLEAR_ID                 2
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_MODE_SET_ID                   3

#define CHIP_TIMERCOUNTER_2_WAVEFORM                                    TRUE
#define CHIP_TIMERCOUNTER_2_WAVEFORM_NORMAL_ID                          0
#define CHIP_TIMERCOUNTER_2_WAVEFORM_PWM_PHASE_CORRECT_ID               1
#define CHIP_TIMERCOUNTER_2_WAVEFORM_CTC_OCRA_ID                        2
#define CHIP_TIMERCOUNTER_2_WAVEFORM_FAST_PWM_ID                        3
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_COUNT                          2
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_0_REG                          REG8(0x45)
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_1_REG                          REG8(0x45)
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_0_BIT                          6
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_1_BIT                          5

#define CHIP_TIMERCOUNTER_2_CLOCK_NONE_ID                               0
#define CHIP_TIMERCOUNTER_2_CLOCK_1_ID                                  1
#define CHIP_TIMERCOUNTER_2_CLOCK_8_ID                                  2
#define CHIP_TIMERCOUNTER_2_CLOCK_32_ID                                 3
#define CHIP_TIMERCOUNTER_2_CLOCK_64_ID                                 4
#define CHIP_TIMERCOUNTER_2_CLOCK_128_ID                                5
#define CHIP_TIMERCOUNTER_2_CLOCK_256_ID                                6
#define CHIP_TIMERCOUNTER_2_CLOCK_1024_ID                               7
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_0_REG                             REG8(0x45)
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_1_REG                             REG8(0x45)
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_2_REG                             REG8(0x45)
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_2_COUNTER_REG                                 REG8(0x44)

#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(0x45)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(0x45)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_REG                         REG8(0x43)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(0x59)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_ENABLE_BIT              7
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(0x58)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_FLAG_BIT                7
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(3)

#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_ENABLE_REG                     REG8(0x59)
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_ENABLE_BIT                     6
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_FLAG_REG                       REG8(0x58)
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_FLAG_BIT                       6
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_VECTOR                         VECT(4)

//------------------------------------------------
// USART0

#define CHIP_USART_COUNT                                                1

#define CHIP_USART_0                                                    TRUE

#define CHIP_USART_0_DATA_REG                                           REG8(0x2C)

#define CHIP_USART_0_USART_REG_SELECT                                   TRUE
#define CHIP_USART_0_USART_REG_SELECT_REG                               REG8(0x40)
#define CHIP_USART_0_USART_REG_SELECT_BIT                               7

#define CHIP_USART_0_BAUD_RATE_REG_HIGH                                 REG8(0x40)
#define CHIP_USART_0_BAUD_RATE_REG_LOW                                  REG8(0x29)

#define CHIP_USART_0_FRAME_ERROR_REG                                    REG8(0x2B)
#define CHIP_USART_0_FRAME_ERROR_BIT                                    4
#define CHIP_USART_0_DATA_OVERRUN_REG                                   REG8(0x2B)
#define CHIP_USART_0_DATA_OVERRUN_BIT                                   3
#define CHIP_USART_0_PARITY_ERROR_REG                                   REG8(0x2B)
#define CHIP_USART_0_PARITY_ERROR_BIT                                   2

#define CHIP_USART_0_DOUBLE_SPEED_REG                                   REG8(0x2B)
#define CHIP_USART_0_DOUBLE_SPEED_BIT                                   1

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG                  REG8(0x2B)
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT                  0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                         REG8(0x2A)
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                         7
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                         REG8(0x2A)
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                         6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG                      REG8(0x2A)
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT                      5

#define CHIP_USART_0_RX_ENABLE_REG                                      REG8(0x2A)
#define CHIP_USART_0_RX_ENABLE_BIT                                      4
#define CHIP_USART_0_TX_ENABLE_REG                                      REG8(0x2A)
#define CHIP_USART_0_TX_ENABLE_BIT                                      3

#define CHIP_USART_0_RX_DATA_BIT_8_REG                                  REG8(0x2A)
#define CHIP_USART_0_RX_DATA_BIT_8_BIT                                  1
#define CHIP_USART_0_TX_DATA_BIT_8_REG                                  REG8(0x2A)
#define CHIP_USART_0_TX_DATA_BIT_8_BIT                                  0

#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                               0
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                                1
#define CHIP_USART_0_MODE_BIT_COUNT                                     1
#define CHIP_USART_0_MODE_BIT_0_REG                                     REG8(0x40)
#define CHIP_USART_0_MODE_BIT_0_BIT                                     6

#define CHIP_USART_0_PARITY_DISABLE_ID                                  0
#define CHIP_USART_0_PARITY_EVEN_ID                                     2
#define CHIP_USART_0_PARITY_ODD_ID                                      3
#define CHIP_USART_0_PARITY_BIT_0_REG                                   REG8(0x40)
#define CHIP_USART_0_PARITY_BIT_1_REG                                   REG8(0x40)
#define CHIP_USART_0_PARITY_BIT_0_BIT                                   4
#define CHIP_USART_0_PARITY_BIT_1_BIT                                   5

#define CHIP_USART_0_STOP_BITS_1_ID                                     0
#define CHIP_USART_0_STOP_BITS_2_ID                                     1
#define CHIP_USART_0_STOP_BITS_REG                                      REG8(0x40)
#define CHIP_USART_0_STOP_BITS_BIT                                      3

#define CHIP_USART_0_CHARACTER_SIZE_5_ID                                0
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                                1
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                                2
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                                3
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                                7
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_REG                           REG8(0x40)
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_REG                           REG8(0x40)
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_REG                           REG8(0x2A)
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_BIT                           1
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_BIT                           2
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_BIT                           2

#define CHIP_USART_0_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID             0
#define CHIP_USART_0_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID             1
#define CHIP_USART_0_CLOCK_POLARITY_REG                                 REG8(0x40)
#define CHIP_USART_0_CLOCK_POLARITY_BIT                                 0

#define CHIP_USART_0_RX_INT_VECTOR                                      VECT(11)
#define CHIP_USART_0_DE_INT_VECTOR                                      VECT(12)
#define CHIP_USART_0_TX_INT_VECTOR                                      VECT(13)

#endif

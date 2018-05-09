#ifndef NBOS_XXX_HPP
#define NBOS_XXX_HPP

// #define CHIP_ADDR_XXX                                            0x00
// #define CHIP_REG_XXX_ADDR                                        CHIP_ADDR_XXX
// #define CHIP_REG_XXX_TYPE                                        uint16_t

// #define CHIP_VECT_XXX                                            0

// #define CHIP_

// #define CHIP_PORT_MIN                                            A
// #define CHIP_PORT_MAX                                            Z

// #define CHIP_PORT_A                                              true
// #define CHIP_PORT_A_PIN_MIN                                      0
// #define CHIP_PORT_A_PIN_MAX                                      7
// #define CHIP_PORT_A_OUTPUT_REG                                   CHIP_REG_PORTB
// #define CHIP_PORT_A_TOGGLE_OUTPUTS_REG                           CHIP_REG_PINB
// #define CHIP_PORT_A_INPUT_REG                                    CHIP_REG_PINB

#define NBOS_CHIP_DEFINED

//------------------------------------------------
// Ram Size

#define CHIP_RAM_SIZE                                                   X

//------------------------------------------------
// Status Register

#define CHIP_STATUS_REG                                                 REG8(0xXX)

//------------------------------------------------
// Reset Status Register

#define CHIP_RESET_STATUS_REG                                           REG8(0xXX)

//------------------------------------------------
// Watchdog Timer

#define CHIP_WATCHDOG_TIMER_CONTROL_REG                                 REG8(0xXX)
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_0_BIT                         X
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_1_BIT                         X
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_2_BIT                         X
#define CHIP_WATCHDOG_TIMER_ENABLE_BIT                                  X
#define CHIP_WATCHDOG_TIMER_CHANGE_ENABLE_BIT                           X
#define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_3_BIT                         X
#define CHIP_WATCHDOG_TIMER_INT_ENABLE_BIT                              X
#define CHIP_WATCHDOG_TIMER_INT_FLAG_BIT                                X

//------------------------------------------------
// IO Ports

// Including non-existant ports.
#define CHIP_PORT_COUNT                                                 X

#define CHIP_PORT_X                                                     true
#define CHIP_PORT_X_OUTPUT_REG                                          REG8(0xXX)
#define CHIP_PORT_X_DIRECTION_REG                                       REG8(0xXX)
#define CHIP_PORT_X_INPUT_REG                                           REG8(0xXX)

//------------------------------------------------
// IO Pins

// Maximum number of pins per port.
#define CHIP_PIN_COUNT                                                  8

#define CHIP_PIN_XX                                                     true

//------------------------------------------------
// ADC

#define CHIP_ADC                                                        true

#define CHIP_ADC_ENABLE_REG                                             REG8(0xXX)
#define CHIP_ADC_ENABLE_BIT                                             X

#define CHIP_ADC_START_REG                                              REG8(0xXX)
#define CHIP_ADC_START_BIT                                              X

#define CHIP_ADC_REFERENCE_BIT_0_REG                                    REG8(0xXX)
#define CHIP_ADC_REFERENCE_BIT_1_REG                                    REG8(0xXX)
#define CHIP_ADC_REFERENCE_BIT_0_BIT                                    X
#define CHIP_ADC_REFERENCE_BIT_1_BIT                                    X
#define CHIP_ADC_REFERENCE_AREF_ID                                      X
#define CHIP_ADC_REFERENCE_AVCC_ID                                      X
#define CHIP_ADC_REFERENCE_INTERNAL_ID                                  X

#define CHIP_ADC_CHANNEL_BIT_0_REG                                      REG8(0xXX)
#define CHIP_ADC_CHANNEL_BIT_1_REG                                      REG8(0xXX)
#define CHIP_ADC_CHANNEL_BIT_2_REG                                      REG8(0xXX)
#define CHIP_ADC_CHANNEL_BIT_3_REG                                      REG8(0xXX)
#define CHIP_ADC_CHANNEL_BIT_0_BIT                                      X
#define CHIP_ADC_CHANNEL_BIT_1_BIT                                      X
#define CHIP_ADC_CHANNEL_BIT_2_BIT                                      X
#define CHIP_ADC_CHANNEL_BIT_3_BIT                                      X
#define CHIP_ADC_CHANNEL_0_ID                                           X
#define CHIP_ADC_CHANNEL_1_ID                                           X
#define CHIP_ADC_CHANNEL_2_ID                                           X
#define CHIP_ADC_CHANNEL_3_ID                                           X
#define CHIP_ADC_CHANNEL_4_ID                                           X
#define CHIP_ADC_CHANNEL_5_ID                                           X
#define CHIP_ADC_CHANNEL_6_ID                                           X
#define CHIP_ADC_CHANNEL_7_ID                                           X
#define CHIP_ADC_CHANNEL_8_ID                                           X
#define CHIP_ADC_CHANNEL_VBG_ID                                         X
#define CHIP_ADC_CHANNEL_GND_ID                                         X

#define CHIP_ADC_FREE_RUNNING_ENABLE_REG                                REG8(0xXX)
#define CHIP_ADC_FREE_RUNNING_ENABLE_BIT                                X

#define CHIP_ADC_TRIGGER                                                true
#define CHIP_ADC_TRIGGER_ENABLE_REG                                     REG8(0xXX)
#define CHIP_ADC_TRIGGER_ENABLE_BIT                                     X
#define CHIP_ADC_TRIGGER_BIT_0_REG                                      REG8(0xXX)
#define CHIP_ADC_TRIGGER_BIT_1_REG                                      REG8(0xXX)
#define CHIP_ADC_TRIGGER_BIT_2_REG                                      REG8(0xXX)
#define CHIP_ADC_TRIGGER_BIT_0_BIT                                      X
#define CHIP_ADC_TRIGGER_BIT_1_BIT                                      X
#define CHIP_ADC_TRIGGER_BIT_2_BIT                                      X
#define CHIP_ADC_TRIGGER_FREE_RUNNING_ID                                X
#define CHIP_ADC_TRIGGER_ANALOG_COMPARATOR_ID                           X
#define CHIP_ADC_TRIGGER_EXTERNAL_INT_0_ID                              X
#define CHIP_ADC_TRIGGER_TIMER0_COMPARE_MATCH_A_ID                      X
#define CHIP_ADC_TRIGGER_TIMER0_OVERFLOW_ID                             X
#define CHIP_ADC_TRIGGER_TIMER1_COMPARE_MATCH_B_ID                      X
#define CHIP_ADC_TRIGGER_TIMER1_OVERFLOW_ID                             X
#define CHIP_ADC_TRIGGER_TIMER1_CAPTURE_EVENT_ID                        X

#define CHIP_ADC_INT_FLAG_REG                                           REG8(0xXX)
#define CHIP_ADC_INT_FLAG_BIT                                           X
#define CHIP_ADC_INT_ENABLE_REG                                         REG8(0xXX)
#define CHIP_ADC_INT_ENABLE_BIT                                         X
#define CHIP_ADC_INT_VECTOR                                             VECT(X)

#define CHIP_ADC_LEFT_ADJUST_REG                                        REG8(0xXX)
#define CHIP_ADC_LEFT_ADJUST_BIT                                        X

#define CHIP_ADC_DATA_REG                                               REGX(0xXX)

#define CHIP_ADC_PRESCALER                                              true
#define CHIP_ADC_PRESCALER_BIT_0_REG                                    REG8(0xXX)
#define CHIP_ADC_PRESCALER_BIT_1_REG                                    REG8(0xXX)
#define CHIP_ADC_PRESCALER_BIT_2_REG                                    REG8(0xXX)
#define CHIP_ADC_PRESCALER_BIT_0_BIT                                    X
#define CHIP_ADC_PRESCALER_BIT_1_BIT                                    X
#define CHIP_ADC_PRESCALER_BIT_2_BIT                                    X
#define CHIP_ADC_PRESCALER_2_ID                                         X
#define CHIP_ADC_PRESCALER_4_ID                                         X
#define CHIP_ADC_PRESCALER_8_ID                                         X
#define CHIP_ADC_PRESCALER_16_ID                                        X
#define CHIP_ADC_PRESCALER_32_ID                                        X
#define CHIP_ADC_PRESCALER_64_ID                                        X
#define CHIP_ADC_PRESCALER_128_ID                                       X

//------------------------------------------------
// External Interrupts

#define CHIP_EXINT_COUNT                                                X

#define CHIP_EXINT_X                                                    true
#define CHIP_EXINT_X_ENABLE_REG                                         REG8(0xXX)
#define CHIP_EXINT_X_ENABLE_BIT                                         X
#define CHIP_EXINT_X_FLAG_REG                                           REG8(0xXX)
#define CHIP_EXINT_X_FLAG_BIT                                           X
#define CHIP_EXINT_X_TRIGGER_BIT_0_REG                                  REG8(0xXX)
#define CHIP_EXINT_X_TRIGGER_BIT_1_REG                                  REG8(0xXX)
#define CHIP_EXINT_X_TRIGGER_BIT_0_BIT                                  X
#define CHIP_EXINT_X_TRIGGER_BIT_1_BIT                                  X
#define CHIP_EXINT_X_VECTOR                                             VECT(X)
#define CHIP_EXINT_X_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_X_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_X_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_X_TRIGGER_RISING_ID                                  3

//------------------------------------------------
// Pin Change Interrupts

#define CHIP_PCINT_COUNT                                                X

#define CHIP_PCINT_X                                                    true
#define CHIP_PCINT_X_ENABLE_REG                                         REG8(0xXX)
#define CHIP_PCINT_X_ENABLE_BIT                                         X
#define CHIP_PCINT_X_FLAG_REG                                           REG8(0xXX)
#define CHIP_PCINT_X_FLAG_BIT                                           X
#define CHIP_PCINT_X_MASK_REG                                           REG8(0xXX)
#define CHIP_PCINT_X_INT_VECTOR                                         VECT(X)

//------------------------------------------------
// Timer Counters

#define CHIP_TIMERCOUNTER_COUNT                                         X

//------------------------------------------------
// Timer Counter X

#define CHIP_TIMERCOUNTER_X                                             true

#define CHIP_TIMERCOUNTER_X_TYPE                                        uintX_t

#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_MODE                          true
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_MODE_DISCONNECTED_ID          X
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_MODE_TOGGLE_ID                X
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_MODE_CLEAR_ID                 X
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_MODE_SET_ID                   X

#define CHIP_TIMERCOUNTER_X_WAVEFORM                                    true
#define CHIP_TIMERCOUNTER_X_WAVEFORM_NORMAL_ID                          X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_PWM_PHASE_CORRECT_8_ID             X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_PWM_PHASE_CORRECT_9_ID             X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_PWM_PHASE_CORRECT_10_ID            X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_CTC_OCRA_ID                        X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_FAST_PWM_8_ID                      X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_FAST_PWM_9_ID                      X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_FAST_PWM_10_ID                     X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID          X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID     X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_PWM_PHASE_CORRECT_ID               X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_CTC_ID                             X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_FAST_PWM_ID                        X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_FAST_PWM_OCRA_ID                   X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_BIT_0_REG                          REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_WAVEFORM_BIT_1_REG                          REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_WAVEFORM_BIT_2_REG                          REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_WAVEFORM_BIT_3_REG                          REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_WAVEFORM_BIT_0_BIT                          X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_BIT_1_BIT                          X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_BIT_2_BIT                          X
#define CHIP_TIMERCOUNTER_X_WAVEFORM_BIT_3_BIT                          X

#define CHIP_TIMERCOUNTER_X_CLOCK_NONE_ID                               X
#define CHIP_TIMERCOUNTER_X_CLOCK_1_ID                                  X
#define CHIP_TIMERCOUNTER_X_CLOCK_8_ID                                  X
#define CHIP_TIMERCOUNTER_X_CLOCK_32_ID                                 X
#define CHIP_TIMERCOUNTER_X_CLOCK_64_ID                                 X
#define CHIP_TIMERCOUNTER_X_CLOCK_128_ID                                X
#define CHIP_TIMERCOUNTER_X_CLOCK_256_ID                                X
#define CHIP_TIMERCOUNTER_X_CLOCK_1024_ID                               X
#define CHIP_TIMERCOUNTER_X_CLOCK_EXT_FALLING_ID                        X
#define CHIP_TIMERCOUNTER_X_CLOCK_EXT_RISING_ID                         X
#define CHIP_TIMERCOUNTER_X_CLOCK_BIT_0_REG                             REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_CLOCK_BIT_1_REG                             REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_CLOCK_BIT_2_REG                             REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_CLOCK_BIT_0_BIT                             X
#define CHIP_TIMERCOUNTER_X_CLOCK_BIT_1_BIT                             X
#define CHIP_TIMERCOUNTER_X_CLOCK_BIT_2_BIT                             X

#define CHIP_TIMERCOUNTER_X_COUNTER_REG                                 REGX(0xXX)

#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X                             true
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X_MODE_BIT_0_REG              REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X_MODE_BIT_1_REG              REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X_MODE_BIT_0_BIT              X
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X_MODE_BIT_1_BIT              X
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X_REG                         REGX(0xXX)
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X_INT_ENABLE_REG              REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X_INT_ENABLE_BIT              X
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X_INT_FLAG_REG                REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X_INT_FLAG_BIT                X
#define CHIP_TIMERCOUNTER_X_OUTPUTCOMPARE_X_INT_VECTOR                  VECT(X)

#define CHIP_TIMERCOUNTER_X_OVERFLOW_INT_ENABLE_REG                     REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_OVERFLOW_INT_ENABLE_BIT                     X
#define CHIP_TIMERCOUNTER_X_OVERFLOW_INT_FLAG_REG                       REG8(0xXX)
#define CHIP_TIMERCOUNTER_X_OVERFLOW_INT_FLAG_BIT                       X
#define CHIP_TIMERCOUNTER_X_OVERFLOW_INT_VECTOR                         VECT(X)

// TODO Add input capture definitions.

//------------------------------------------------
// Usart

#define CHIP_USART_COUNT                                                1

#define CHIP_USART_X                                                    true

#define CHIP_USART_X_DATA_REG                                           REG8(0xXX)

#define CHIP_USART_X_BAUD_RATE_REG_HIGH                                 REG8(0xXX)
#define CHIP_USART_X_BAUD_RATE_REG_LOW                                  REG8(0xXX)

#define CHIP_USART_X_FRAME_ERROR_REG                                    REG8(0xXX)
#define CHIP_USART_X_FRAME_ERROR_BIT                                    X
#define CHIP_USART_X_DATA_OVERRUN_REG                                   REG8(0xXX)
#define CHIP_USART_X_DATA_OVERRUN_BIT                                   X
#define CHIP_USART_X_PARITY_ERROR_REG                                   REG8(0xXX)
#define CHIP_USART_X_PARITY_ERROR_BIT                                   X

#define CHIP_USART_X_DOUBLE_SPEED_REG                                   REG8(0xXX)
#define CHIP_USART_X_DOUBLE_SPEED_BIT                                   X

#define CHIP_USART_X_MULTI_PROCESSOR_COMMUNICATION_REG                  REG8(0xXX)
#define CHIP_USART_X_MULTI_PROCESSOR_COMMUNICATION_BIT                  X

#define CHIP_USART_X_RX_COMPLETE_INT_ENABLE_REG                         REG8(0xXX)
#define CHIP_USART_X_RX_COMPLETE_INT_ENABLE_BIT                         X
#define CHIP_USART_X_TX_COMPLETE_INT_ENABLE_REG                         REG8(0xXX)
#define CHIP_USART_X_TX_COMPLETE_INT_ENABLE_BIT                         X
#define CHIP_USART_X_DATA_REG_EMPTY_INT_ENABLE_REG                      REG8(0xXX)
#define CHIP_USART_X_DATA_REG_EMPTY_INT_ENABLE_BIT                      X

#define CHIP_USART_X_RX_ENABLE_REG                                      REG8(0xXX)
#define CHIP_USART_X_RX_ENABLE_BIT                                      X
#define CHIP_USART_X_TX_ENABLE_REG                                      REG8(0xXX)
#define CHIP_USART_X_TX_ENABLE_BIT                                      X

#define CHIP_USART_X_RX_DATA_BIT_8_REG                                  REG8(0xXX)
#define CHIP_USART_X_RX_DATA_BIT_8_BIT                                  X
#define CHIP_USART_X_TX_DATA_BIT_8_REG                                  REG8(0xXX)
#define CHIP_USART_X_TX_DATA_BIT_8_BIT                                  X

#define CHIP_USART_X_MODE_ASYNCHRONOUS_ID                               X
#define CHIP_USART_X_MODE_SYNCHRONOUS_ID                                X
#define CHIP_USART_X_MODE_MASTER_SPI_ID                                 X
#define CHIP_USART_X_MODE_BIT_0_REG                                     REG8(0xXX)
#define CHIP_USART_X_MODE_BIT_1_REG                                     REG8(0xXX)
#define CHIP_USART_X_MODE_BIT_0_BIT                                     X
#define CHIP_USART_X_MODE_BIT_1_BIT                                     X

#define CHIP_USART_X_PARITY_DISABLE_ID                                  X
#define CHIP_USART_X_PARITY_EVEN_ID                                     X
#define CHIP_USART_X_PARITY_ODD_ID                                      X
#define CHIP_USART_X_PARITY_BIT_0_REG                                   REG8(0xXX)
#define CHIP_USART_X_PARITY_BIT_1_REG                                   REG8(0xXX)
#define CHIP_USART_X_PARITY_BIT_0_BIT                                   X
#define CHIP_USART_X_PARITY_BIT_1_BIT                                   X

#define CHIP_USART_X_STOP_BITS_1_ID                                     X
#define CHIP_USART_X_STOP_BITS_2_ID                                     X
#define CHIP_USART_X_STOP_BITS_REG                                      REG8(0xXX)
#define CHIP_USART_X_STOP_BITS_BIT                                      X

#define CHIP_USART_X_CHARACTER_SIZE_5_ID                                X
#define CHIP_USART_X_CHARACTER_SIZE_6_ID                                X
#define CHIP_USART_X_CHARACTER_SIZE_7_ID                                X
#define CHIP_USART_X_CHARACTER_SIZE_8_ID                                X
#define CHIP_USART_X_CHARACTER_SIZE_9_ID                                X
#define CHIP_USART_X_CHARACTER_SIZE_BIT_0_REG                           REG8(0xXX)
#define CHIP_USART_X_CHARACTER_SIZE_BIT_1_REG                           REG8(0xXX)
#define CHIP_USART_X_CHARACTER_SIZE_BIT_2_REG                           REG8(0xXX)
#define CHIP_USART_X_CHARACTER_SIZE_BIT_0_BIT                           X
#define CHIP_USART_X_CHARACTER_SIZE_BIT_1_BIT                           X
#define CHIP_USART_X_CHARACTER_SIZE_BIT_2_BIT                           X

#define CHIP_USART_X_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID             X
#define CHIP_USART_X_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID             X
#define CHIP_USART_X_CLOCK_POLARITY_REG                                 REG8(0xXX)
#define CHIP_USART_X_CLOCK_POLARITY_BIT                                 X

#define CHIP_USART_X_RX_INT_VECTOR                                      VECT(X)
#define CHIP_USART_X_DE_INT_VECTOR                                      VECT(X)
#define CHIP_USART_X_TX_INT_VECTOR                                      VECT(X)

#endif

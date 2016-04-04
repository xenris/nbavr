#ifndef NBAVR_ATMEGA8_H
#define NBAVR_ATMEGA8_H

#define NBAVR_CHIP_DEFINED

#define TRUE 1

////////////////////////////////////////////////////////////////////
// ADC

#define CHIP_ADC                                                TRUE

#define CHIP_ADC_ENABLE_REG                                     ADCSRA
#define CHIP_ADC_ENABLE_BIT                                     ADEN

#define CHIP_ADC_START_REG                                      ADCSRA
#define CHIP_ADC_START_BIT                                      ADSC

#define CHIP_ADC_CHANNEL_BIT_0_REG                              ADMUX
#define CHIP_ADC_CHANNEL_BIT_1_REG                              ADMUX
#define CHIP_ADC_CHANNEL_BIT_2_REG                              ADMUX
#define CHIP_ADC_CHANNEL_BIT_3_REG                              ADMUX
#define CHIP_ADC_CHANNEL_BIT_0                                  MUX0
#define CHIP_ADC_CHANNEL_BIT_1                                  MUX1
#define CHIP_ADC_CHANNEL_BIT_2                                  MUX2
#define CHIP_ADC_CHANNEL_BIT_3                                  MUX3
#define CHIP_ADC_CHANNEL_0_ID                                   0
#define CHIP_ADC_CHANNEL_1_ID                                   1
#define CHIP_ADC_CHANNEL_2_ID                                   2
#define CHIP_ADC_CHANNEL_3_ID                                   3
#define CHIP_ADC_CHANNEL_4_ID                                   4
#define CHIP_ADC_CHANNEL_5_ID                                   5
#define CHIP_ADC_CHANNEL_6_ID                                   6
#define CHIP_ADC_CHANNEL_7_ID                                   7
#define CHIP_ADC_CHANNEL_VBG_ID                                 14
#define CHIP_ADC_CHANNEL_GND_ID                                 15

#define CHIP_ADC_FREE_RUNNING_ENABLE_REG                        ADCSRA
#define CHIP_ADC_FREE_RUNNING_ENABLE_BIT                        ADFR

#define CHIP_ADC_INT_FLAG_REG                                   ADCSRA
#define CHIP_ADC_INT_FLAG_BIT                                   ADIF
#define CHIP_ADC_INT_ENABLE_REG                                 ADCSRA
#define CHIP_ADC_INT_ENABLE_BIT                                 ADIE
#define CHIP_ADC_INT_VECTOR                                     ADC_vect

#define CHIP_ADC_LEFT_ADJUST_REG                                ADMUX
#define CHIP_ADC_LEFT_ADJUST_BIT                                ADLAR

#define CHIP_ADC_DATA_REG                                       ADC

#define CHIP_ADC_PRESCALER                                      TRUE
#define CHIP_ADC_PRESCALER_BIT_0_REG                            ADCSRA
#define CHIP_ADC_PRESCALER_BIT_1_REG                            ADCSRA
#define CHIP_ADC_PRESCALER_BIT_2_REG                            ADCSRA
#define CHIP_ADC_PRESCALER_BIT_0                                ADPS0
#define CHIP_ADC_PRESCALER_BIT_1                                ADPS1
#define CHIP_ADC_PRESCALER_BIT_2                                ADPS2
#define CHIP_ADC_PRESCALER_2_ID                                 0
#define CHIP_ADC_PRESCALER_4_ID                                 2
#define CHIP_ADC_PRESCALER_8_ID                                 3
#define CHIP_ADC_PRESCALER_16_ID                                4
#define CHIP_ADC_PRESCALER_32_ID                                5
#define CHIP_ADC_PRESCALER_64_ID                                6
#define CHIP_ADC_PRESCALER_128_ID                               7

////////////////////////////////////////////////////////////////////
// EXTERNAL INTERRUPTS

#define CHIP_INT_0                                              TRUE
#define CHIP_INT_0_ENABLE_REG                                   GICR
#define CHIP_INT_0_ENABLE_BIT                                   INT0
#define CHIP_INT_0_FLAG_REG                                     GIFR
#define CHIP_INT_0_FLAG_BIT                                     INTF0
#define CHIP_INT_0_TRIGGER_LOW_ID                               0
#define CHIP_INT_0_TRIGGER_CHANGE_ID                            1
#define CHIP_INT_0_TRIGGER_FALLING_ID                           2
#define CHIP_INT_0_TRIGGER_RISING_ID                            3
#define CHIP_INT_0_TRIGGER_BIT_0_REG                            MCUCR
#define CHIP_INT_0_TRIGGER_BIT_1_REG                            MCUCR
#define CHIP_INT_0_TRIGGER_BIT_0                                ISC00
#define CHIP_INT_0_TRIGGER_BIT_1                                ISC01
#define CHIP_INT_0_VECTOR                                       INT0_vect

#define CHIP_INT_1                                              TRUE
#define CHIP_INT_1_ENABLE_REG                                   GICR
#define CHIP_INT_1_ENABLE_BIT                                   INT1
#define CHIP_INT_1_FLAG_REG                                     GIFR
#define CHIP_INT_1_FLAG_BIT                                     INTF1
#define CHIP_INT_1_TRIGGER_LOW_ID                               0
#define CHIP_INT_1_TRIGGER_CHANGE_ID                            1
#define CHIP_INT_1_TRIGGER_FALLING_ID                           2
#define CHIP_INT_1_TRIGGER_RISING_ID                            3
#define CHIP_INT_1_TRIGGER_BIT_0_REG                            MCUCR
#define CHIP_INT_1_TRIGGER_BIT_1_REG                            MCUCR
#define CHIP_INT_1_TRIGGER_BIT_0                                ISC10
#define CHIP_INT_1_TRIGGER_BIT_1                                ISC11
#define CHIP_INT_1_VECTOR                                       INT1_vect

////////////////////////////////////////////////////////////////////
// Timer0

#define CHIP_TIMER_0                                            TRUE

#define CHIP_TIMER_0_TYPE                                       uint8_t

#define CHIP_TIMER_0_CLOCK_NONE_ID                              0
#define CHIP_TIMER_0_CLOCK_1_ID                                 1
#define CHIP_TIMER_0_CLOCK_8_ID                                 2
#define CHIP_TIMER_0_CLOCK_64_ID                                3
#define CHIP_TIMER_0_CLOCK_256_ID                               4
#define CHIP_TIMER_0_CLOCK_1024_ID                              5
#define CHIP_TIMER_0_CLOCK_FALLING_ID                           6
#define CHIP_TIMER_0_CLOCK_RISING_ID                            7
#define CHIP_TIMER_0_CLOCK_BIT_0_REG                            TCCR0
#define CHIP_TIMER_0_CLOCK_BIT_1_REG                            TCCR0
#define CHIP_TIMER_0_CLOCK_BIT_2_REG                            TCCR0
#define CHIP_TIMER_0_CLOCK_BIT_0                                CS00
#define CHIP_TIMER_0_CLOCK_BIT_1                                CS01
#define CHIP_TIMER_0_CLOCK_BIT_2                                CS02

#define CHIP_TIMER_0_TIMER_COUNTER_REG                          TCNT0

#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                    TIMSK
#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                    TOIE0
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                      TIFR
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_BIT                      TOV0
#define CHIP_TIMER_0_OVERFLOW_INT_VECTOR                        TIMER0_OVF_vect

////////////////////////////////////////////////////////////////////
// Timer1

#define CHIP_TIMER_1                                            TRUE

#define CHIP_TIMER_1_TYPE                                       uint16_t

#define CHIP_TIMER_1_OUTPUT_MODE                                TRUE
#define CHIP_TIMER_1_OUTPUT_MODE_DISCONNECTED_ID                0
#define CHIP_TIMER_1_OUTPUT_MODE_TOGGLE_ID                      1
#define CHIP_TIMER_1_OUTPUT_MODE_CLEAR_ID                       2
#define CHIP_TIMER_1_OUTPUT_MODE_SET_ID                         3

#define CHIP_TIMER_1_WAVEFORM                                   TRUE
#define CHIP_TIMER_1_WAVEFORM_NORMAL_ID                         0
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_8_ID            1
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_9_ID            2
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_10_ID           3
#define CHIP_TIMER_1_WAVEFORM_CTC_OCRA_ID                       4
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_8_ID                     5
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_9_ID                     6
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_10_ID                    7
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID         8
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID    9
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_ID              10
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID         11
#define CHIP_TIMER_1_WAVEFORM_CTC_ID                            12
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_ID                       14
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_OCRA_ID                  15
#define CHIP_TIMER_1_WAVEFORM_BIT_COUNT                         4
#define CHIP_TIMER_1_WAVEFORM_BIT_0_REG                         TCCR1A
#define CHIP_TIMER_1_WAVEFORM_BIT_1_REG                         TCCR1A
#define CHIP_TIMER_1_WAVEFORM_BIT_2_REG                         TCCR1B
#define CHIP_TIMER_1_WAVEFORM_BIT_3_REG                         TCCR1B
#define CHIP_TIMER_1_WAVEFORM_BIT_0                             WGM10
#define CHIP_TIMER_1_WAVEFORM_BIT_1                             WGM11
#define CHIP_TIMER_1_WAVEFORM_BIT_2                             WGM12
#define CHIP_TIMER_1_WAVEFORM_BIT_3                             WGM13

#define CHIP_TIMER_1_CLOCK_NONE_ID                              0
#define CHIP_TIMER_1_CLOCK_1_ID                                 1
#define CHIP_TIMER_1_CLOCK_8_ID                                 2
#define CHIP_TIMER_1_CLOCK_64_ID                                3
#define CHIP_TIMER_1_CLOCK_256_ID                               4
#define CHIP_TIMER_1_CLOCK_1024_ID                              5
#define CHIP_TIMER_1_CLOCK_FALLING_ID                           6
#define CHIP_TIMER_1_CLOCK_RISING_ID                            7
#define CHIP_TIMER_1_CLOCK_BIT_0_REG                            TCCR1B
#define CHIP_TIMER_1_CLOCK_BIT_1_REG                            TCCR1B
#define CHIP_TIMER_1_CLOCK_BIT_2_REG                            TCCR1B
#define CHIP_TIMER_1_CLOCK_BIT_0                                CS10
#define CHIP_TIMER_1_CLOCK_BIT_1                                CS11
#define CHIP_TIMER_1_CLOCK_BIT_2                                CS12

#define CHIP_TIMER_1_TIMER_COUNTER_REG                          TCNT1

#define CHIP_TIMER_1_OUTPUT_A                                   TRUE
#define CHIP_TIMER_1_OUTPUT_A_REG                               OCR1A
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_REG                    TIMSK
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_BIT                    OCIE1A
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_REG                      TIFR
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_BIT                      OCF1A
#define CHIP_TIMER_1_OUTPUT_A_INT_VECTOR                        TIMER1_COMPA_vect

#define CHIP_TIMER_1_OUTPUT_B                                   TRUE
#define CHIP_TIMER_1_OUTPUT_B_REG                               OCR1B
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_REG                    TIMSK
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_BIT                    OCIE1B
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_REG                      TIFR
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_BIT                      OCF1B
#define CHIP_TIMER_1_OUTPUT_B_INT_VECTOR                        TIMER1_COMPB_vect

#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                    TIMSK
#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                    TOIE1
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                      TIFR
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_BIT                      TOV1
#define CHIP_TIMER_1_OVERFLOW_INT_VECTOR                        TIMER1_OVF_vect

// TODO Add input capture definitions.

////////////////////////////////////////////////////////////////////
// Timer2

#define CHIP_TIMER_2                                            TRUE

#define CHIP_TIMER_2_TYPE                                       uint8_t

#define CHIP_TIMER_2_OUTPUT_MODE                                TRUE
#define CHIP_TIMER_2_OUTPUT_MODE_DISCONNECTED_ID                0
#define CHIP_TIMER_2_OUTPUT_MODE_TOGGLE_ID                      1
#define CHIP_TIMER_2_OUTPUT_MODE_CLEAR_ID                       2
#define CHIP_TIMER_2_OUTPUT_MODE_SET_ID                         3

#define CHIP_TIMER_2_WAVEFORM                                   TRUE
#define CHIP_TIMER_2_WAVEFORM_NORMAL_ID                         0
#define CHIP_TIMER_2_WAVEFORM_PWM_PHASE_CORRECT_ID              1
#define CHIP_TIMER_2_WAVEFORM_CTC_OCRA_ID                       2
#define CHIP_TIMER_2_WAVEFORM_FAST_PWM_ID                       3
#define CHIP_TIMER_2_WAVEFORM_BIT_COUNT                         2
#define CHIP_TIMER_2_WAVEFORM_BIT_0_REG                         TCCR2
#define CHIP_TIMER_2_WAVEFORM_BIT_1_REG                         TCCR2
#define CHIP_TIMER_2_WAVEFORM_BIT_0                             WGM20
#define CHIP_TIMER_2_WAVEFORM_BIT_1                             WGM21

#define CHIP_TIMER_2_CLOCK_NONE_ID                              0
#define CHIP_TIMER_2_CLOCK_1_ID                                 1
#define CHIP_TIMER_2_CLOCK_8_ID                                 2
#define CHIP_TIMER_2_CLOCK_32_ID                                3
#define CHIP_TIMER_2_CLOCK_64_ID                                4
#define CHIP_TIMER_2_CLOCK_128_ID                               5
#define CHIP_TIMER_2_CLOCK_256_ID                               6
#define CHIP_TIMER_2_CLOCK_1024_ID                              7
#define CHIP_TIMER_2_CLOCK_BIT_0_REG                            TCCR2
#define CHIP_TIMER_2_CLOCK_BIT_1_REG                            TCCR2
#define CHIP_TIMER_2_CLOCK_BIT_2_REG                            TCCR2
#define CHIP_TIMER_2_CLOCK_BIT_0                                CS20
#define CHIP_TIMER_2_CLOCK_BIT_1                                CS21
#define CHIP_TIMER_2_CLOCK_BIT_2                                CS22

#define CHIP_TIMER_2_TIMER_COUNTER_REG                          TCNT2

#define CHIP_TIMER_2_OUTPUT_A                                   TRUE
#define CHIP_TIMER_2_OUTPUT_A_REG                               OCR2
#define CHIP_TIMER_2_OUTPUT_A_INT_ENABLE_REG                    TIMSK
#define CHIP_TIMER_2_OUTPUT_A_INT_ENABLE_BIT                    OCIE2
#define CHIP_TIMER_2_OUTPUT_A_INT_FLAG_REG                      TIFR
#define CHIP_TIMER_2_OUTPUT_A_INT_FLAG_BIT                      OCF2
#define CHIP_TIMER_2_OUTPUT_A_INT_VECTOR                        TIMER2_COMP_vect

#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_REG                    TIMSK
#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_BIT                    TOIE2
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_REG                      TIFR
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_BIT                      TOV2
#define CHIP_TIMER_2_OVERFLOW_INT_VECTOR                        TIMER2_OVF_vect

////////////////////////////////////////////////////////////////////
// USART0

#define CHIP_USART_0                                            TRUE

#define CHIP_USART_0_DATA_REG                                   UDR

#define CHIP_USART_0_BAUD_RATE_REG_HIGH                         UBRRH
#define CHIP_USART_0_BAUD_RATE_REG_LOW                          UBRRL

#define CHIP_USART_0_FRAME_ERROR_REG                            UCSRA
#define CHIP_USART_0_FRAME_ERROR_BIT                            FE
#define CHIP_USART_0_DATA_OVERRUN_REG                           UCSRA
#define CHIP_USART_0_DATA_OVERRUN_BIT                           DOR
#define CHIP_USART_0_PARITY_ERROR_REG                           UCSRA
#define CHIP_USART_0_PARITY_ERROR_BIT                           PE

#define CHIP_USART_0_DOUBLE_SPEED_REG                           UCSRA
#define CHIP_USART_0_DOUBLE_SPEED_BIT                           U2X

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG          UCSRA
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT          MPCM

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                 UCSRB
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                 RXCIE
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                 UCSRB
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                 TXCIE
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG              UCSRB
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT              UDRIE

#define CHIP_USART_0_RX_ENABLE_REG                              UCSRB
#define CHIP_USART_0_RX_ENABLE_BIT                              RXEN
#define CHIP_USART_0_TX_ENABLE_REG                              UCSRB
#define CHIP_USART_0_TX_ENABLE_BIT                              TXEN

#define CHIP_USART_0_RX_DATA_BIT_8_REG                          UCSRB
#define CHIP_USART_0_RX_DATA_BIT_8_BIT                          RXB8
#define CHIP_USART_0_TX_DATA_BIT_8_REG                          UCSRB
#define CHIP_USART_0_TX_DATA_BIT_8_BIT                          TXB8

#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                       0
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                        1
#define CHIP_USART_0_MODE_BIT_COUNT                             1
#define CHIP_USART_0_MODE_BIT_0_REG                             UCSRC
#define CHIP_USART_0_MODE_BIT_0                                 UMSEL

#define CHIP_USART_0_PARITY_DISABLE_ID                          0
#define CHIP_USART_0_PARITY_EVEN_ID                             2
#define CHIP_USART_0_PARITY_ODD_ID                              3
#define CHIP_USART_0_PARITY_BIT_0_REG                           UCSRC
#define CHIP_USART_0_PARITY_BIT_1_REG                           UCSRC
#define CHIP_USART_0_PARITY_BIT_0                               UPM0
#define CHIP_USART_0_PARITY_BIT_1                               UPM1

#define CHIP_USART_0_STOP_BITS_1_ID                             0
#define CHIP_USART_0_STOP_BITS_2_ID                             1
#define CHIP_USART_0_STOP_BITS_REG                              UCSRC
#define CHIP_USART_0_STOP_BITS_BIT                              USBS

#define CHIP_USART_0_CHARACTER_SIZE_5_ID                        0
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                        1
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                        2
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                        3
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                        7
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_REG                   UCSRC
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_REG                   UCSRC
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_REG                   UCSRB
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0                       UCSZ0
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1                       UCSZ1
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2                       UCSZ2

#define CHIP_USART_0_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID     0
#define CHIP_USART_0_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID     1
#define CHIP_USART_0_CLOCK_POLARITY_REG                         UCSRC
#define CHIP_USART_0_CLOCK_POLARITY_BIT                         UCPOL

#define CHIP_USART_0_RX_COMPLETE_INT_VECTOR                     USART_RXC_vect
#define CHIP_USART_0_TX_COMPLETE_INT_VECTOR                     USART_TXC_vect
#define CHIP_USART_0_DATA_REG_EMPTY_INT_VECTOR                  USART_UDRE_vect

#endif

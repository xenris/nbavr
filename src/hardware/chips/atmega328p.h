#ifndef NBAVR_ATMEGA328P_H
#define NBAVR_ATMEGA328P_H

#define NBAVR_CHIP_DEFINED

#define TRUE 1

////////////////////////////////////////////////////////////////////
// ADC

#define CHIP_ADC                                                TRUE

#define CHIP_ADC_ENABLE_REG                                     ADCSRA
#define CHIP_ADC_ENABLE_BIT                                     ADEN

#define CHIP_ADC_START_REG                                      ADCSRA
#define CHIP_ADC_START_BIT                                      ADSC

#define CHIP_ADC_REFERENCE_BIT_0_REG                            ADMUX
#define CHIP_ADC_REFERENCE_BIT_1_REG                            ADMUX
#define CHIP_ADC_REFERENCE_BIT_0                                REFS0
#define CHIP_ADC_REFERENCE_BIT_1                                REFS1
#define CHIP_ADC_REFERENCE_AREF_ID                              0
#define CHIP_ADC_REFERENCE_AVCC_ID                              1
#define CHIP_ADC_REFERENCE_INTERNAL_ID                          3

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
#define CHIP_ADC_CHANNEL_8_ID                                   8
#define CHIP_ADC_CHANNEL_VBG_ID                                 14
#define CHIP_ADC_CHANNEL_GND_ID                                 15

#define CHIP_ADC_TRIGGER                                        TRUE
#define CHIP_ADC_TRIGGER_ENABLE_REG                             ADCSRA
#define CHIP_ADC_TRIGGER_ENABLE_BIT                             ADATE
#define CHIP_ADC_TRIGGER_BIT_0_REG                              ADCSRB
#define CHIP_ADC_TRIGGER_BIT_1_REG                              ADCSRB
#define CHIP_ADC_TRIGGER_BIT_2_REG                              ADCSRB
#define CHIP_ADC_TRIGGER_BIT_0                                  ADTS0
#define CHIP_ADC_TRIGGER_BIT_1                                  ADTS1
#define CHIP_ADC_TRIGGER_BIT_2                                  ADTS2
#define CHIP_ADC_TRIGGER_FREE_RUNNING_ID                        0
#define CHIP_ADC_TRIGGER_ANALOG_COMPARATOR_ID                   1
#define CHIP_ADC_TRIGGER_EXTERNAL_INT_0_ID                      2
#define CHIP_ADC_TRIGGER_TIMER0_COMPARE_MATCH_A_ID              3
#define CHIP_ADC_TRIGGER_TIMER0_OVERFLOW_ID                     4
#define CHIP_ADC_TRIGGER_TIMER1_COMPARE_MATCH_B_ID              5
#define CHIP_ADC_TRIGGER_TIMER1_OVERFLOW_ID                     6
#define CHIP_ADC_TRIGGER_TIMER1_CAPTURE_EVENT_ID                7

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
#define CHIP_INT_0_ENABLE_REG                                   EIMSK
#define CHIP_INT_0_ENABLE_BIT                                   INT0
#define CHIP_INT_0_FLAG_REG                                     EIFR
#define CHIP_INT_0_FLAG_BIT                                     INTF0
#define CHIP_INT_0_TRIGGER_LOW_ID                               0
#define CHIP_INT_0_TRIGGER_CHANGE_ID                            1
#define CHIP_INT_0_TRIGGER_FALLING_ID                           2
#define CHIP_INT_0_TRIGGER_RISING_ID                            3
#define CHIP_INT_0_TRIGGER_BIT_0_REG                            EICRA
#define CHIP_INT_0_TRIGGER_BIT_1_REG                            EICRA
#define CHIP_INT_0_TRIGGER_BIT_0                                ISC00
#define CHIP_INT_0_TRIGGER_BIT_1                                ISC01
#define CHIP_INT_0_VECTOR                                       INT0_vect

#define CHIP_INT_1                                              TRUE
#define CHIP_INT_1_ENABLE_REG                                   EIMSK
#define CHIP_INT_1_ENABLE_BIT                                   INT1
#define CHIP_INT_1_FLAG_REG                                     EIFR
#define CHIP_INT_1_FLAG_BIT                                     INTF1
#define CHIP_INT_1_TRIGGER_LOW_ID                               0
#define CHIP_INT_1_TRIGGER_CHANGE_ID                            1
#define CHIP_INT_1_TRIGGER_FALLING_ID                           2
#define CHIP_INT_1_TRIGGER_RISING_ID                            3
#define CHIP_INT_1_TRIGGER_BIT_0_REG                            EICRA
#define CHIP_INT_1_TRIGGER_BIT_1_REG                            EICRA
#define CHIP_INT_1_TRIGGER_BIT_0                                ISC10
#define CHIP_INT_1_TRIGGER_BIT_1                                ISC11
#define CHIP_INT_1_VECTOR                                       INT1_vect

#define CHIP_PC_INT_0                                           TRUE
#define CHIP_PC_INT_0_ENABLE_REG                                PCICR
#define CHIP_PC_INT_0_ENABLE_BIT                                PCIE0
#define CHIP_PC_INT_0_FLAG_REG                                  PCIFR
#define CHIP_PC_INT_0_FLAG_BIT                                  PCIF0
#define CHIP_PC_INT_0_MASK_REG                                  PCMSK0
#define CHIP_PC_INT_0_MASK_BITS                                 0xFF
#define CHIP_PC_INT_0_VECTOR                                    PCINT0_vect

#define CHIP_PC_INT_1                                           TRUE
#define CHIP_PC_INT_1_ENABLE_REG                                PCICR
#define CHIP_PC_INT_1_ENABLE_BIT                                PCIE1
#define CHIP_PC_INT_1_FLAG_REG                                  PCIFR
#define CHIP_PC_INT_1_FLAG_BIT                                  PCIF1
#define CHIP_PC_INT_1_MASK_REG                                  PCMSK1
#define CHIP_PC_INT_1_MASK_BITS                                 0x7F
#define CHIP_PC_INT_1_VECTOR                                    PCINT1_vect

#define CHIP_PC_INT_2                                           TRUE
#define CHIP_PC_INT_2_ENABLE_REG                                PCICR
#define CHIP_PC_INT_2_ENABLE_BIT                                PCIE2
#define CHIP_PC_INT_2_FLAG_REG                                  PCIFR
#define CHIP_PC_INT_2_FLAG_BIT                                  PCIF2
#define CHIP_PC_INT_2_MASK_REG                                  PCMSK2
#define CHIP_PC_INT_2_MASK_BITS                                 0xFF
#define CHIP_PC_INT_2_VECTOR                                    PCINT2_vect

////////////////////////////////////////////////////////////////////
// Timer0

#define CHIP_TIMER_0                                            TRUE

#define CHIP_TIMER_0_TYPE                                       uint8_t

#define CHIP_TIMER_0_OUTPUT_MODE                                TRUE
#define CHIP_TIMER_0_OUTPUT_MODE_DISCONNECTED_ID                0
#define CHIP_TIMER_0_OUTPUT_MODE_TOGGLE_ID                      1
#define CHIP_TIMER_0_OUTPUT_MODE_CLEAR_ID                       2
#define CHIP_TIMER_0_OUTPUT_MODE_SET_ID                         3

#define CHIP_TIMER_0_WAVEFORM                                   TRUE
#define CHIP_TIMER_0_WAVEFORM_NORMAL_ID                         0
#define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_ID              1
#define CHIP_TIMER_0_WAVEFORM_CTC_OCRA_ID                       2
#define CHIP_TIMER_0_WAVEFORM_FAST_PWM_ID                       3
#define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID         5
#define CHIP_TIMER_0_WAVEFORM_FAST_PWM_OCRA_ID                  7
#define CHIP_TIMER_0_WAVEFORM_BIT_COUNT                         3
#define CHIP_TIMER_0_WAVEFORM_BIT_0_REG                         TCCR0A
#define CHIP_TIMER_0_WAVEFORM_BIT_1_REG                         TCCR0A
#define CHIP_TIMER_0_WAVEFORM_BIT_2_REG                         TCCR0B
#define CHIP_TIMER_0_WAVEFORM_BIT_0                             WGM00
#define CHIP_TIMER_0_WAVEFORM_BIT_1                             WGM01
#define CHIP_TIMER_0_WAVEFORM_BIT_2                             WGM02

#define CHIP_TIMER_0_CLOCK_NONE_ID                              0
#define CHIP_TIMER_0_CLOCK_1_ID                                 1
#define CHIP_TIMER_0_CLOCK_8_ID                                 2
#define CHIP_TIMER_0_CLOCK_64_ID                                3
#define CHIP_TIMER_0_CLOCK_256_ID                               4
#define CHIP_TIMER_0_CLOCK_1024_ID                              5
#define CHIP_TIMER_0_CLOCK_FALLING_ID                           6
#define CHIP_TIMER_0_CLOCK_RISING_ID                            7
#define CHIP_TIMER_0_CLOCK_BIT_0_REG                            TCCR0B
#define CHIP_TIMER_0_CLOCK_BIT_1_REG                            TCCR0B
#define CHIP_TIMER_0_CLOCK_BIT_2_REG                            TCCR0B
#define CHIP_TIMER_0_CLOCK_BIT_0                                CS00
#define CHIP_TIMER_0_CLOCK_BIT_1                                CS01
#define CHIP_TIMER_0_CLOCK_BIT_2                                CS02

#define CHIP_TIMER_0_TIMER_COUNTER_REG                          TCNT0

#define CHIP_TIMER_0_OUTPUT_A                                   TRUE
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_0_REG                    TCCR0A
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_1_REG                    TCCR0A
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_0                        COM0A0
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_1                        COM0A1
#define CHIP_TIMER_0_OUTPUT_A_REG                               OCR0A
#define CHIP_TIMER_0_OUTPUT_A_INT_ENABLE_REG                    TIMSK0
#define CHIP_TIMER_0_OUTPUT_A_INT_ENABLE_BIT                    OCIE0A
#define CHIP_TIMER_0_OUTPUT_A_INT_FLAG_REG                      TIFR0
#define CHIP_TIMER_0_OUTPUT_A_INT_FLAG_BIT                      OCF0A
#define CHIP_TIMER_0_OUTPUT_A_INT_VECTOR                        TIMER0_COMPA_vect

#define CHIP_TIMER_0_OUTPUT_B                                   TRUE
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_0_REG                    TCCR0A
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_1_REG                    TCCR0A
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_0                        COM0B0
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_1                        COM0B1
#define CHIP_TIMER_0_OUTPUT_B_REG                               OCR0B
#define CHIP_TIMER_0_OUTPUT_B_INT_ENABLE_REG                    TIMSK0
#define CHIP_TIMER_0_OUTPUT_B_INT_ENABLE_BIT                    OCIE0B
#define CHIP_TIMER_0_OUTPUT_B_INT_FLAG_REG                      TIFR0
#define CHIP_TIMER_0_OUTPUT_B_INT_FLAG_BIT                      OCF0B
#define CHIP_TIMER_0_OUTPUT_B_INT_VECTOR                        TIMER0_COMPB_vect

#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                    TIMSK0
#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                    TOIE0
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                      TIFR0
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
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_0_REG                    TCCR1A
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_1_REG                    TCCR1A
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_0                        COM1A0
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_1                        COM1A1
#define CHIP_TIMER_1_OUTPUT_A_REG                               OCR1A
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_REG                    TIMSK1
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_BIT                    OCIE1A
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_REG                      TIFR1
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_BIT                      OCF1A
#define CHIP_TIMER_1_OUTPUT_A_INT_VECTOR                        TIMER1_COMPA_vect

#define CHIP_TIMER_1_OUTPUT_B                                   TRUE
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_0_REG                    TCCR1A
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_1_REG                    TCCR1A
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_0                        COM1B0
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_1                        COM1B1
#define CHIP_TIMER_1_OUTPUT_B_REG                               OCR1B
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_REG                    TIMSK1
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_BIT                    OCIE1B
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_REG                      TIFR1
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_BIT                      OCF1B
#define CHIP_TIMER_1_OUTPUT_B_INT_VECTOR                        TIMER1_COMPB_vect

#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                    TIMSK1
#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                    TOIE1
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                      TIFR1
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
#define CHIP_TIMER_2_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID         5
#define CHIP_TIMER_2_WAVEFORM_FAST_PWM_OCRA_ID                  7
#define CHIP_TIMER_2_WAVEFORM_BIT_COUNT                         3
#define CHIP_TIMER_2_WAVEFORM_BIT_0_REG                         TCCR2A
#define CHIP_TIMER_2_WAVEFORM_BIT_1_REG                         TCCR2A
#define CHIP_TIMER_2_WAVEFORM_BIT_2_REG                         TCCR2B
#define CHIP_TIMER_2_WAVEFORM_BIT_0                             WGM20
#define CHIP_TIMER_2_WAVEFORM_BIT_1                             WGM21
#define CHIP_TIMER_2_WAVEFORM_BIT_2                             WGM22

#define CHIP_TIMER_2_CLOCK_NONE_ID                              0
#define CHIP_TIMER_2_CLOCK_1_ID                                 1
#define CHIP_TIMER_2_CLOCK_8_ID                                 2
#define CHIP_TIMER_2_CLOCK_32_ID                                3
#define CHIP_TIMER_2_CLOCK_64_ID                                4
#define CHIP_TIMER_2_CLOCK_128_ID                               5
#define CHIP_TIMER_2_CLOCK_256_ID                               6
#define CHIP_TIMER_2_CLOCK_1024_ID                              7
#define CHIP_TIMER_2_CLOCK_BIT_0_REG                            TCCR2B
#define CHIP_TIMER_2_CLOCK_BIT_1_REG                            TCCR2B
#define CHIP_TIMER_2_CLOCK_BIT_2_REG                            TCCR2B
#define CHIP_TIMER_2_CLOCK_BIT_0                                CS20
#define CHIP_TIMER_2_CLOCK_BIT_1                                CS21
#define CHIP_TIMER_2_CLOCK_BIT_2                                CS22

#define CHIP_TIMER_2_TIMER_COUNTER_REG                          TCNT2

#define CHIP_TIMER_2_OUTPUT_A                                   TRUE
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_0_REG                    TCCR2A
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_1_REG                    TCCR2A
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_0                        COM2A0
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_1                        COM2A1
#define CHIP_TIMER_2_OUTPUT_A_REG                               OCR2A
#define CHIP_TIMER_2_OUTPUT_A_INT_ENABLE_REG                    TIMSK2
#define CHIP_TIMER_2_OUTPUT_A_INT_ENABLE_BIT                    OCIE2A
#define CHIP_TIMER_2_OUTPUT_A_INT_FLAG_REG                      TIFR2
#define CHIP_TIMER_2_OUTPUT_A_INT_FLAG_BIT                      OCF2A
#define CHIP_TIMER_2_OUTPUT_A_INT_VECTOR                        TIMER2_COMPA_vect

#define CHIP_TIMER_2_OUTPUT_B                                   TRUE
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_0_REG                    TCCR2A
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_1_REG                    TCCR2A
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_0                        COM2B0
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_1                        COM2B1
#define CHIP_TIMER_2_OUTPUT_B_REG                               OCR2B
#define CHIP_TIMER_2_OUTPUT_B_INT_ENABLE_REG                    TIMSK2
#define CHIP_TIMER_2_OUTPUT_B_INT_ENABLE_BIT                    OCIE2B
#define CHIP_TIMER_2_OUTPUT_B_INT_FLAG_REG                      TIFR2
#define CHIP_TIMER_2_OUTPUT_B_INT_FLAG_BIT                      OCF2B
#define CHIP_TIMER_2_OUTPUT_B_INT_VECTOR                        TIMER2_COMPB_vect

#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_REG                    TIMSK2
#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_BIT                    TOIE2
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_REG                      TIFR2
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_BIT                      TOV2
#define CHIP_TIMER_2_OVERFLOW_INT_VECTOR                        TIMER2_OVF_vect

////////////////////////////////////////////////////////////////////
// USART0

#define CHIP_USART_0                                            TRUE

#define CHIP_USART_0_DATA_REG                                   UDR0

#define CHIP_USART_0_BAUD_RATE_REG_HIGH                         UBRR0H
#define CHIP_USART_0_BAUD_RATE_REG_LOW                          UBRR0L

#define CHIP_USART_0_FRAME_ERROR_REG                            UCSR0A
#define CHIP_USART_0_FRAME_ERROR_BIT                            FE0
#define CHIP_USART_0_DATA_OVERRUN_REG                           UCSR0A
#define CHIP_USART_0_DATA_OVERRUN_BIT                           DOR0
#define CHIP_USART_0_PARITY_ERROR_REG                           UCSR0A
#define CHIP_USART_0_PARITY_ERROR_BIT                           UPE0

#define CHIP_USART_0_DOUBLE_SPEED_REG                           UCSR0A
#define CHIP_USART_0_DOUBLE_SPEED_BIT                           U2X0

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG          UCSR0A
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT          MPCM0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                 UCSR0B
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                 RXCIE0
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                 UCSR0B
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                 TXCIE0
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG              UCSR0B
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT              UDRIE0

#define CHIP_USART_0_RX_ENABLE_REG                              UCSR0B
#define CHIP_USART_0_RX_ENABLE_BIT                              RXEN0
#define CHIP_USART_0_TX_ENABLE_REG                              UCSR0B
#define CHIP_USART_0_TX_ENABLE_BIT                              TXEN0

#define CHIP_USART_0_RX_DATA_BIT_8_REG                          UCSR0B
#define CHIP_USART_0_RX_DATA_BIT_8_BIT                          RXB80
#define CHIP_USART_0_TX_DATA_BIT_8_REG                          UCSR0B
#define CHIP_USART_0_TX_DATA_BIT_8_BIT                          TXB80

#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                       0
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                        1
#define CHIP_USART_0_MODE_MASTER_SPI_ID                         3
#define CHIP_USART_0_MODE_BIT_COUNT                             2
#define CHIP_USART_0_MODE_BIT_0_REG                             UCSR0C
#define CHIP_USART_0_MODE_BIT_1_REG                             UCSR0C
#define CHIP_USART_0_MODE_BIT_0                                 UMSEL00
#define CHIP_USART_0_MODE_BIT_1                                 UMSEL01

#define CHIP_USART_0_PARITY_DISABLE_ID                          0
#define CHIP_USART_0_PARITY_EVEN_ID                             2
#define CHIP_USART_0_PARITY_ODD_ID                              3
#define CHIP_USART_0_PARITY_BIT_0_REG                           UCSR0C
#define CHIP_USART_0_PARITY_BIT_1_REG                           UCSR0C
#define CHIP_USART_0_PARITY_BIT_0                               UPM00
#define CHIP_USART_0_PARITY_BIT_1                               UPM01

#define CHIP_USART_0_STOP_BITS_1_ID                             0
#define CHIP_USART_0_STOP_BITS_2_ID                             1
#define CHIP_USART_0_STOP_BITS_REG                              UCSR0C
#define CHIP_USART_0_STOP_BITS_BIT                              USBS0

#define CHIP_USART_0_CHARACTER_SIZE_5_ID                        0
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                        1
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                        2
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                        3
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                        7
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_REG                   UCSR0C
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_REG                   UCSR0C
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_REG                   UCSR0B
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0                       UCSZ00
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1                       UCSZ01
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2                       UCSZ02

#define CHIP_USART_0_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID     0
#define CHIP_USART_0_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID     1
#define CHIP_USART_0_CLOCK_POLARITY_REG                         UCSR0C
#define CHIP_USART_0_CLOCK_POLARITY_BIT                         UCPOL0

#define CHIP_USART_0_RX_COMPLETE_INT_VECTOR                     USART_RX_vect
#define CHIP_USART_0_TX_COMPLETE_INT_VECTOR                     USART_TX_vect
#define CHIP_USART_0_DATA_REG_EMPTY_INT_VECTOR                  USART_UDRE_vect

#endif

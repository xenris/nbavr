#ifndef NBAVR_ATMEGA8_HPP
#define NBAVR_ATMEGA8_HPP

#define ATMEGA8

#define NBAVR_CHIP_DEFINED

#define CHIP_ADDR_SREG              0x5F
#define CHIP_ADDR_SPH               0x5E
#define CHIP_ADDR_SPL               0x5D
#define CHIP_ADDR_GICR              0x5B
#define CHIP_ADDR_GIFR              0x5A
#define CHIP_ADDR_TIMSK             0x59
#define CHIP_ADDR_TIFR              0x58
#define CHIP_ADDR_SPMCR             0x57
#define CHIP_ADDR_TWCR              0x56
#define CHIP_ADDR_MCUCR             0x55
#define CHIP_ADDR_MCUCSR            0x54
#define CHIP_ADDR_TCCR0             0x53
#define CHIP_ADDR_TCNT0             0x52
#define CHIP_ADDR_OSCCAL            0x51
#define CHIP_ADDR_SFIOR             0x50
#define CHIP_ADDR_TCCR1A            0x4F
#define CHIP_ADDR_TCCR1B            0x4E
#define CHIP_ADDR_TCNT1H            0x4D
#define CHIP_ADDR_TCNT1L            0x4C
#define CHIP_ADDR_OCR1AH            0x4B
#define CHIP_ADDR_OCR1AL            0x4A
#define CHIP_ADDR_OCR1BH            0x49
#define CHIP_ADDR_OCR1BL            0x48
#define CHIP_ADDR_ICR1H             0x47
#define CHIP_ADDR_ICR1L             0x46
#define CHIP_ADDR_TCCR2             0x45
#define CHIP_ADDR_TCNT2             0x44
#define CHIP_ADDR_OCR2              0x43
#define CHIP_ADDR_ASSR              0x42
#define CHIP_ADDR_WDTCR             0x41
#define CHIP_ADDR_UBRRH             0x40
#define CHIP_ADDR_UCSRC             0x40
#define CHIP_ADDR_EEARH             0x3F
#define CHIP_ADDR_EEARL             0x3E
#define CHIP_ADDR_EEDR              0x3D
#define CHIP_ADDR_EECR              0x3C
#define CHIP_ADDR_PORTB             0x38
#define CHIP_ADDR_DDRB              0x37
#define CHIP_ADDR_PINB              0x36
#define CHIP_ADDR_PORTC             0x35
#define CHIP_ADDR_DDRC              0x34
#define CHIP_ADDR_PINC              0x33
#define CHIP_ADDR_PORTD             0x32
#define CHIP_ADDR_DDRD              0x31
#define CHIP_ADDR_PIND              0x30
#define CHIP_ADDR_SPDR              0x2F
#define CHIP_ADDR_SPSR              0x2E
#define CHIP_ADDR_SPCR              0x2D
#define CHIP_ADDR_UDR               0x2C
#define CHIP_ADDR_UCSRA             0x2B
#define CHIP_ADDR_UCSRB             0x2A
#define CHIP_ADDR_UBRRL             0x29
#define CHIP_ADDR_ACSR              0x28
#define CHIP_ADDR_ADMUX             0x27
#define CHIP_ADDR_ADCSRA            0x26
#define CHIP_ADDR_ADCH              0x25
#define CHIP_ADDR_ADCL              0x24
#define CHIP_ADDR_TWDR              0x23
#define CHIP_ADDR_TWAR              0x22
#define CHIP_ADDR_TWSR              0x21
#define CHIP_ADDR_TWBR              0x20

#define CHIP_VECT_RESET             1
#define CHIP_VECT_INT0              2
#define CHIP_VECT_INT1              3
#define CHIP_VECT_TIMER2_COMP       4
#define CHIP_VECT_TIMER2_OVF        5
#define CHIP_VECT_TIMER1_CAPT       6
#define CHIP_VECT_TIMER1_COMPA      7
#define CHIP_VECT_TIMER1_COMPB      8
#define CHIP_VECT_TIMER1_OVF        9
#define CHIP_VECT_TIMER0_OVF        10
#define CHIP_VECT_SPI_STC           11
#define CHIP_VECT_USART_RX          12
#define CHIP_VECT_USART_UDRE        13
#define CHIP_VECT_USART_TX          14
#define CHIP_VECT_ADC               15
#define CHIP_VECT_EE_READY          16
#define CHIP_VECT_ANALOG_COMP       17
#define CHIP_VECT_TWI               18
#define CHIP_VECT_SPM_READY         19

//------------------------------------------------
// Ram Size

#define CHIP_RAM_SIZE                                                   1024

//------------------------------------------------
// Status Register

#define CHIP_STATUS_REG                                                 REG8(CHIP_ADDR_SREG)

//------------------------------------------------
// Reset Status Register

#define CHIP_RESET_STATUS_REG                                           REG8(CHIP_ADDR_MCUCSR)

//------------------------------------------------
// Watchdog Timer

#define CHIP_WATCHDOG_TIMER_CONTROL_REG                                 REG8(CHIP_ADDR_WDTCR)
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
#define CHIP_PORT_B_OUTPUT_REG                                          REG8(CHIP_ADDR_ADCH)
#define CHIP_PORT_B_DIRECTION_REG                                       REG8(CHIP_ADDR_ADCL)
#define CHIP_PORT_B_INPUT_REG                                           REG8(CHIP_ADDR_TWDR)

#define CHIP_PORT_C                                                     TRUE
#define CHIP_PORT_C_OUTPUT_REG                                          REG8(CHIP_ADDR_ACSR)
#define CHIP_PORT_C_DIRECTION_REG                                       REG8(CHIP_ADDR_ADMUX)
#define CHIP_PORT_C_INPUT_REG                                           REG8(CHIP_ADDR_ADCSRA)

#define CHIP_PORT_D                                                     TRUE
#define CHIP_PORT_D_OUTPUT_REG                                          REG8(CHIP_ADDR_UCSRA)
#define CHIP_PORT_D_DIRECTION_REG                                       REG8(CHIP_ADDR_UCSRB)
#define CHIP_PORT_D_INPUT_REG                                           REG8(CHIP_ADDR_UBRRL)

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

#define CHIP_ADC_ENABLE_REG                                             REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_ENABLE_BIT                                             7

#define CHIP_ADC_START_REG                                              REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_START_BIT                                              6

#define CHIP_ADC_REFERENCE_BIT_0_REG                                    REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_REFERENCE_BIT_1_REG                                    REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_REFERENCE_BIT_0_BIT                                    6
#define CHIP_ADC_REFERENCE_BIT_1_BIT                                    7
#define CHIP_ADC_REFERENCE_AREF_ID                                      0
#define CHIP_ADC_REFERENCE_AVCC_ID                                      1
#define CHIP_ADC_REFERENCE_INTERNAL_ID                                  3

#define CHIP_ADC_CHANNEL_BIT_0_REG                                      REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_CHANNEL_BIT_1_REG                                      REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_CHANNEL_BIT_2_REG                                      REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_CHANNEL_BIT_3_REG                                      REG8(CHIP_ADDR_ADMUX)
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

#define CHIP_ADC_FREE_RUNNING_ENABLE_REG                                REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_FREE_RUNNING_ENABLE_BIT                                5

#define CHIP_ADC_INT_FLAG_REG                                           REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_INT_FLAG_BIT                                           4
#define CHIP_ADC_INT_ENABLE_REG                                         REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_INT_ENABLE_BIT                                         3
#define CHIP_ADC_INT_VECTOR                                             VECT(CHIP_VECT_ADC)

#define CHIP_ADC_LEFT_ADJUST_REG                                        REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_LEFT_ADJUST_BIT                                        5

#define CHIP_ADC_DATA_REG                                               REG8(CHIP_ADDR_ADCL)

#define CHIP_ADC_PRESCALER                                              TRUE
#define CHIP_ADC_PRESCALER_BIT_0_REG                                    REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_PRESCALER_BIT_1_REG                                    REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_PRESCALER_BIT_2_REG                                    REG8(CHIP_ADDR_ADCSRA)
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
#define CHIP_EXINT_0_ENABLE_REG                                           REG8(CHIP_ADDR_GICR)
#define CHIP_EXINT_0_ENABLE_BIT                                           6
#define CHIP_EXINT_0_FLAG_REG                                             REG8(CHIP_ADDR_GIFR)
#define CHIP_EXINT_0_FLAG_BIT                                             6
#define CHIP_EXINT_0_TRIGGER_BIT_0_REG                                    REG8(CHIP_ADDR_MCUCR)
#define CHIP_EXINT_0_TRIGGER_BIT_1_REG                                    REG8(CHIP_ADDR_MCUCR)
#define CHIP_EXINT_0_TRIGGER_BIT_0_BIT                                    0
#define CHIP_EXINT_0_TRIGGER_BIT_1_BIT                                    1
#define CHIP_EXINT_0_INT_VECTOR                                           VECT(CHIP_VECT_INT0)
#define CHIP_EXINT_0_TRIGGER_LOW_ID                                       0
#define CHIP_EXINT_0_TRIGGER_CHANGE_ID                                    1
#define CHIP_EXINT_0_TRIGGER_FALLING_ID                                   2
#define CHIP_EXINT_0_TRIGGER_RISING_ID                                    3

#define CHIP_EXINT_1                                                      TRUE
#define CHIP_EXINT_1_ENABLE_REG                                           REG8(CHIP_ADDR_GICR)
#define CHIP_EXINT_1_ENABLE_BIT                                           7
#define CHIP_EXINT_1_FLAG_REG                                             REG8(CHIP_ADDR_GIFR)
#define CHIP_EXINT_1_FLAG_BIT                                             7
#define CHIP_EXINT_1_TRIGGER_BIT_0_REG                                    REG8(CHIP_ADDR_MCUCR)
#define CHIP_EXINT_1_TRIGGER_BIT_1_REG                                    REG8(CHIP_ADDR_MCUCR)
#define CHIP_EXINT_1_TRIGGER_BIT_0_BIT                                    2
#define CHIP_EXINT_1_TRIGGER_BIT_1_BIT                                    3
#define CHIP_EXINT_1_INT_VECTOR                                           VECT(CHIP_VECT_INT1)
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
#define CHIP_TIMERCOUNTER_0_CLOCK_EXT_FALLING_ID                        6
#define CHIP_TIMERCOUNTER_0_CLOCK_EXT_RISING_ID                         7
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR0)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR0)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR0)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_0_COUNTER_REG                                 REG8(CHIP_ADDR_TCNT0)

#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_ENABLE_BIT                     0
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_FLAG_BIT                       0
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER0_OVF)

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
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_2_REG                          REG8(CHIP_ADDR_TCCR1B)
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_3_REG                          REG8(CHIP_ADDR_TCCR1B)
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
#define CHIP_TIMERCOUNTER_1_CLOCK_EXT_FALLING_ID                        6
#define CHIP_TIMERCOUNTER_1_CLOCK_EXT_RISING_ID                         7
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR1B)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR1B)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR1B)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_1_COUNTER_REG                                 REG8(CHIP_ADDR_TCNT1L)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_REG                         REG8(CHIP_ADDR_OCR1AL)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_ENABLE_BIT              4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_FLAG_BIT                4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER1_COMPA)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_REG                         REG8(CHIP_ADDR_OCR1BL)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_ENABLE_BIT              3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_FLAG_BIT                3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER1_COMPB)

#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_ENABLE_BIT                     2
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_FLAG_BIT                       2
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER1_OVF)

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
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR2)
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR2)
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
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR2)
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR2)
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR2)
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_2_COUNTER_REG                                 REG8(CHIP_ADDR_TCNT2)

#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR2)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR2)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_REG                         REG8(CHIP_ADDR_OCR2)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_ENABLE_BIT              7
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_FLAG_BIT                7
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER2_COMP)

#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_ENABLE_BIT                     6
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_FLAG_BIT                       6
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER2_OVF)

//------------------------------------------------
// USART0

#define CHIP_USART_COUNT                                                1

#define CHIP_USART_0                                                    TRUE

#define CHIP_USART_0_DATA_REG                                           REG8(CHIP_ADDR_UDR)

#define CHIP_USART_0_USART_REG_SELECT_REG                               REG8(CHIP_ADDR_UCSRC)
#define CHIP_USART_0_USART_REG_SELECT_BIT                               7

#define CHIP_USART_0_BAUD_RATE_REG_SPLIT                                TRUE
#define CHIP_USART_0_BAUD_RATE_REG_HIGH                                 REG8(CHIP_ADDR_UBRRH)
#define CHIP_USART_0_BAUD_RATE_REG_LOW                                  REG8(CHIP_ADDR_UBRRL)

#define CHIP_USART_0_FRAME_ERROR_REG                                    REG8(CHIP_ADDR_UCSRA)
#define CHIP_USART_0_FRAME_ERROR_BIT                                    4
#define CHIP_USART_0_DATA_OVERRUN_REG                                   REG8(CHIP_ADDR_UCSRA)
#define CHIP_USART_0_DATA_OVERRUN_BIT                                   3
#define CHIP_USART_0_PARITY_ERROR_REG                                   REG8(CHIP_ADDR_UCSRA)
#define CHIP_USART_0_PARITY_ERROR_BIT                                   2

#define CHIP_USART_0_DOUBLE_SPEED_REG                                   REG8(CHIP_ADDR_UCSRA)
#define CHIP_USART_0_DOUBLE_SPEED_BIT                                   1

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG                  REG8(CHIP_ADDR_UCSRA)
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT                  0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSRB)
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                         7
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSRB)
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                         6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG                      REG8(CHIP_ADDR_UCSRB)
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT                      5

#define CHIP_USART_0_RX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSRB)
#define CHIP_USART_0_RX_ENABLE_BIT                                      4
#define CHIP_USART_0_TX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSRB)
#define CHIP_USART_0_TX_ENABLE_BIT                                      3

#define CHIP_USART_0_RX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSRB)
#define CHIP_USART_0_RX_DATA_BIT_8_BIT                                  1
#define CHIP_USART_0_TX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSRB)
#define CHIP_USART_0_TX_DATA_BIT_8_BIT                                  0

#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                               0
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                                1
#define CHIP_USART_0_MODE_BIT_0_REG                                     REG8(CHIP_ADDR_UCSRC)
#define CHIP_USART_0_MODE_BIT_0_BIT                                     6

#define CHIP_USART_0_PARITY_DISABLE_ID                                  0
#define CHIP_USART_0_PARITY_EVEN_ID                                     2
#define CHIP_USART_0_PARITY_ODD_ID                                      3
#define CHIP_USART_0_PARITY_BIT_0_REG                                   REG8(CHIP_ADDR_UCSRC)
#define CHIP_USART_0_PARITY_BIT_1_REG                                   REG8(CHIP_ADDR_UCSRC)
#define CHIP_USART_0_PARITY_BIT_0_BIT                                   4
#define CHIP_USART_0_PARITY_BIT_1_BIT                                   5

#define CHIP_USART_0_STOP_BITS_1_ID                                     0
#define CHIP_USART_0_STOP_BITS_2_ID                                     1
#define CHIP_USART_0_STOP_BITS_REG                                      REG8(CHIP_ADDR_UCSRC)
#define CHIP_USART_0_STOP_BITS_BIT                                      3

#define CHIP_USART_0_CHARACTER_SIZE_5_ID                                0
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                                1
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                                2
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                                3
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                                7
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_REG                           REG8(CHIP_ADDR_UCSRC)
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_REG                           REG8(CHIP_ADDR_UCSRC)
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_REG                           REG8(CHIP_ADDR_UCSRB)
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_BIT                           1
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_BIT                           2
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_BIT                           2

#define CHIP_USART_0_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID             0
#define CHIP_USART_0_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID             1
#define CHIP_USART_0_CLOCK_POLARITY_REG                                 REG8(CHIP_ADDR_UCSRC)
#define CHIP_USART_0_CLOCK_POLARITY_BIT                                 0

#define CHIP_USART_0_RX_INT_VECTOR                                      VECT(CHIP_VECT_USART_RX)
#define CHIP_USART_0_DE_INT_VECTOR                                      VECT(CHIP_VECT_USART_UDRE)
#define CHIP_USART_0_TX_INT_VECTOR                                      VECT(CHIP_VECT_USART_TX)

#endif

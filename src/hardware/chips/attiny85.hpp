#ifndef NBAVR_ATTINY85_HPP
#define NBAVR_ATTINY85_HPP

#define ATTINY85

#define CHIP_ADDR_SREG              0x3F
#define CHIP_ADDR_SPH               0x3E
#define CHIP_ADDR_SPL               0x3D
#define CHIP_ADDR_GIMSK             0x3B
#define CHIP_ADDR_GIFR              0x3A
#define CHIP_ADDR_TIMSK             0x39
#define CHIP_ADDR_TIFR              0x38
#define CHIP_ADDR_SPMCSR            0x37
#define CHIP_ADDR_MCUCR             0x35
#define CHIP_ADDR_MCUSR             0x34
#define CHIP_ADDR_TCCR0B            0x33
#define CHIP_ADDR_TCNT0             0x32
#define CHIP_ADDR_OSCCAL            0x31
#define CHIP_ADDR_TCCR1             0x30
#define CHIP_ADDR_TCNT1             0x2F
#define CHIP_ADDR_OCR1A             0x2E
#define CHIP_ADDR_OCR1C             0x2D
#define CHIP_ADDR_GTCCR             0x2C
#define CHIP_ADDR_OCR1B             0x2B
#define CHIP_ADDR_TCCR0A            0x2A
#define CHIP_ADDR_OCR0A             0x29
#define CHIP_ADDR_OCR0B             0x28
#define CHIP_ADDR_PLLCSR            0x27
#define CHIP_ADDR_CLKPR             0x26
#define CHIP_ADDR_DT1A              0x25
#define CHIP_ADDR_DT1B              0x24
#define CHIP_ADDR_DTPS1             0x23
#define CHIP_ADDR_DWDR              0x22
#define CHIP_ADDR_WDTCR             0x21
#define CHIP_ADDR_PRR               0x20
#define CHIP_ADDR_EEARH             0x1F
#define CHIP_ADDR_EEARL             0x1E
#define CHIP_ADDR_EEDR              0x1D
#define CHIP_ADDR_EECR              0x1C
#define CHIP_ADDR_PORTB             0x18
#define CHIP_ADDR_DDRB              0x17
#define CHIP_ADDR_PINB              0x16
#define CHIP_ADDR_PCMSK             0x15
#define CHIP_ADDR_DIDR0             0x14
#define CHIP_ADDR_GPIOR2            0x13
#define CHIP_ADDR_GPIOR1            0x12
#define CHIP_ADDR_GPIOR0            0x11
#define CHIP_ADDR_USIBR             0x10
#define CHIP_ADDR_USIDR             0x0F
#define CHIP_ADDR_USISR             0x0E
#define CHIP_ADDR_USICR             0x0D
#define CHIP_ADDR_ACSR              0x08
#define CHIP_ADDR_ADMUX             0x07
#define CHIP_ADDR_ADCSRA            0x06
#define CHIP_ADDR_ADCH              0x05
#define CHIP_ADDR_ADCL              0x04
#define CHIP_ADDR_ADCSRB            0x03

#define CHIP_VECT_RESET             1
#define CHIP_VECT_INT0              2
#define CHIP_VECT_PCINT0            3
#define CHIP_VECT_TIMER1_COMPA      4
#define CHIP_VECT_TIMER1_OVF        5
#define CHIP_VECT_TIMER0_OVF        6
#define CHIP_VECT_EE_READY          7
#define CHIP_VECT_ANALOG_COMP       8
#define CHIP_VECT_ADC               9
#define CHIP_VECT_TIMER1_COMPB      10
#define CHIP_VECT_TIMER0_COMPA      11
#define CHIP_VECT_TIMER0_COMPB      12
#define CHIP_VECT_WDT               13
#define CHIP_VECT_USI_START         14
#define CHIP_VECT_USI_OVF           15

#define NBAVR_CHIP_DEFINED

//------------------------------------------------
// Ram Size

#define CHIP_RAM_SIZE                                                   512

//------------------------------------------------
// Status Register

#define CHIP_STATUS_REG                                                 REG8(CHIP_ADDR_SREG)

//------------------------------------------------
// Reset Status Register

#define CHIP_RESET_STATUS_REG                                           REG8(CHIP_ADDR_MCUSR)

//------------------------------------------------
// Watchdog Timer

#define CHIP_WATCHDOG_TIMER_CONTROL_REG                                 REG8(CHIP_ADDR_WDTCR)
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
#define CHIP_PORT_B_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTB)
#define CHIP_PORT_B_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRB)
#define CHIP_PORT_B_INPUT_REG                                           REG8(CHIP_ADDR_PINB)

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

#define CHIP_ADC_ENABLE_REG                                             REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_ENABLE_BIT                                             7

#define CHIP_ADC_START_REG                                              REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_START_BIT                                              6

// TODO Add extra reference sources to hardware code.
#define CHIP_ADC_REFERENCE_BIT_0_REG                                    REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_REFERENCE_BIT_1_REG                                    REG8(CHIP_ADDR_ADMUX)
// #define CHIP_ADC_REFERENCE_BIT_1_REG                                    REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_REFERENCE_BIT_0_BIT                                    6
#define CHIP_ADC_REFERENCE_BIT_1_BIT                                    7
// #define CHIP_ADC_REFERENCE_BIT_1_BIT                                    4
#define CHIP_ADC_REFERENCE_AREF_ID                                      1
#define CHIP_ADC_REFERENCE_AVCC_ID                                      0
#define CHIP_ADC_REFERENCE_INTERNAL_ID                                  2

// TODO Add differential and gain to hardware code.
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
#define CHIP_ADC_CHANNEL_VBG_ID                                         12
#define CHIP_ADC_CHANNEL_GND_ID                                         13

#define CHIP_ADC_TRIGGER                                                TRUE
#define CHIP_ADC_TRIGGER_ENABLE_REG                                     REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_TRIGGER_ENABLE_BIT                                     5
#define CHIP_ADC_TRIGGER_BIT_0_REG                                      REG8(CHIP_ADDR_ADCSRB)
#define CHIP_ADC_TRIGGER_BIT_1_REG                                      REG8(CHIP_ADDR_ADCSRB)
#define CHIP_ADC_TRIGGER_BIT_2_REG                                      REG8(CHIP_ADDR_ADCSRB)
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

#define CHIP_ADC_INT_FLAG_REG                                           REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_INT_FLAG_BIT                                           4
#define CHIP_ADC_INT_ENABLE_REG                                         REG8(CHIP_ADDR_ADCSRA)
#define CHIP_ADC_INT_ENABLE_BIT                                         3
#define CHIP_ADC_INT_VECTOR                                             VECT(CHIP_VECT_ADC)

#define CHIP_ADC_LEFT_ADJUST_REG                                        REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_LEFT_ADJUST_BIT                                        5

#define CHIP_ADC_DATA_REG                                               REG16(CHIP_ADDR_ADCL)

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

#define CHIP_EXINT_COUNT                                                1

#define CHIP_EXINT_0                                                    TRUE
#define CHIP_EXINT_0_ENABLE_REG                                         REG8(CHIP_ADDR_GIMSK)
#define CHIP_EXINT_0_ENABLE_BIT                                         6
#define CHIP_EXINT_0_FLAG_REG                                           REG8(CHIP_ADDR_GIFR)
#define CHIP_EXINT_0_FLAG_BIT                                           6
#define CHIP_EXINT_0_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_MCUCR)
#define CHIP_EXINT_0_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_MCUCR)
#define CHIP_EXINT_0_TRIGGER_BIT_0_BIT                                  0
#define CHIP_EXINT_0_TRIGGER_BIT_1_BIT                                  1
#define CHIP_EXINT_0_VECTOR                                             VECT(CHIP_VECT_INT0)
#define CHIP_EXINT_0_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_0_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_0_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_0_TRIGGER_RISING_ID                                  3

//------------------------------------------------
// Pin Change Interrupts

#define CHIP_PCINT_COUNT                                                1

#define CHIP_PCINT_0                                                    TRUE
#define CHIP_PCINT_0_ENABLE_REG                                         REG8(CHIP_ADDR_GIMSK)
#define CHIP_PCINT_0_ENABLE_BIT                                         5
#define CHIP_PCINT_0_FLAG_REG                                           REG8(CHIP_ADDR_GIFR)
#define CHIP_PCINT_0_FLAG_BIT                                           6
#define CHIP_PCINT_0_MASK_REG                                           REG8(CHIP_ADDR_PCMSK)
#define CHIP_PCINT_0_INT_VECTOR                                         VECT(CHIP_VECT_PCINT0)

//------------------------------------------------
// Timer Counters

#define CHIP_TIMERCOUNTER_COUNT                                         2

//------------------------------------------------
// Timer Counter 0

#define CHIP_TIMERCOUNTER_0                                             TRUE

#define CHIP_TIMERCOUNTER_0_TYPE                                        uint8_t

#define CHIP_TIMERCOUNTER_0_WAVEFORM                                    TRUE
#define CHIP_TIMERCOUNTER_0_WAVEFORM_NORMAL_ID                          0
#define CHIP_TIMERCOUNTER_0_WAVEFORM_PWM_PHASE_CORRECT_ID               1
#define CHIP_TIMERCOUNTER_0_WAVEFORM_CTC_OCRA_ID                        2
#define CHIP_TIMERCOUNTER_0_WAVEFORM_FAST_PWM_ID                        3
#define CHIP_TIMERCOUNTER_0_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          5
#define CHIP_TIMERCOUNTER_0_WAVEFORM_FAST_PWM_OCRA_ID                   7

#define CHIP_TIMERCOUNTER_0_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR0A)
#define CHIP_TIMERCOUNTER_0_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR0A)
#define CHIP_TIMERCOUNTER_0_WAVEFORM_BIT_2_REG                          REG8(CHIP_ADDR_TCCR0B)
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
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR0B)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR0B)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR0B)
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_0_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_0_COUNTER_REG                                 REG8(CHIP_ADDR_TCNT0)

#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_PIN                         PinB0
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR0A)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR0A)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_REG                         REG8(CHIP_ADDR_OCR0A)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_ENABLE_BIT              2
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_FLAG_BIT                4
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER0_COMPA)

#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_PIN                         PinB3
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR0A)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR0A)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_REG                         REG8(CHIP_ADDR_OCR0B)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_ENABLE_BIT              3
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_FLAG_BIT                3
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER0_COMPB)

#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_ENABLE_BIT                     1
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_FLAG_BIT                       1
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER0_OVF)

// TODO Add input capture definitions.

//------------------------------------------------
// Timer Counter X

#define CHIP_TIMERCOUNTER_1                                             TRUE

#define CHIP_TIMERCOUNTER_1_TYPE                                        uint8_t

// TODO Change ORCA to OCR throughout code. Or maybe add OCRC option?
#define CHIP_TIMERCOUNTER_1_WAVEFORM                                    TRUE
#define CHIP_TIMERCOUNTER_1_WAVEFORM_NORMAL_ID                          0
#define CHIP_TIMERCOUNTER_1_WAVEFORM_CTC_OCRA_ID                        2 // XXX Actually OCRC
#define CHIP_TIMERCOUNTER_1_WAVEFORM_FAST_PWM_OCRA_ID                   1 // XXX Actually OCRC
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR1)
#define CHIP_TIMERCOUNTER_1_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR1)
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
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR1)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR1)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR1)
// #define CHIP_TIMERCOUNTER_1_CLOCK_BIT_3_REG                             REG8(CHIP_ADDR_TCCR1)
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_1_CLOCK_BIT_2_BIT                             2
// #define CHIP_TIMERCOUNTER_1_CLOCK_BIT_3_BIT                             3
// TODO Add more clock modes to hardware code.

#define CHIP_TIMERCOUNTER_1_COUNTER_REG                                 REG8(CHIP_ADDR_TCNT1)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_PIN                         PinB1
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR1)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR1)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_REG                         REG8(CHIP_ADDR_OCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_ENABLE_BIT              6
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_FLAG_BIT                6
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER1_COMPA)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_PIN                         PinB4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_GTCCR)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_GTCCR)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_REG                         REG8(CHIP_ADDR_OCR1B)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_ENABLE_BIT              5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_FLAG_BIT                5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER1_COMPB)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_REG                         REG8(CHIP_ADDR_OCR1C)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR)

#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK)
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_ENABLE_BIT                     2
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR)
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_FLAG_BIT                       2
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER1_OVF)

//------------------------------------------------
// Usart

// #define CHIP_USART_COUNT                                                1
//
// #define CHIP_USART_0                                                    TRUE
//
// #define CHIP_USART_0_DATA_REG                                           REG8(0xXX)
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

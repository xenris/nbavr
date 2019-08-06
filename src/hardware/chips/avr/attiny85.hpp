#ifndef NBLIB_ATTINY85_HPP
#define NBLIB_ATTINY85_HPP

#define NBLIB_CHIP_DEFINED

//------------------------------------------------
// Memory

#define CHIP_RAM_SIZE                                               512

//------------------------------------------------
// Registers


#define CHIP_REG_ADCSRB_ADDR                                        0x23
#define CHIP_REG_ADCSRB_TYPE                                        uint8_t
#define CHIP_REG_ADC_ADDR                                           0x24
#define CHIP_REG_ADC_TYPE                                           uint16_t
#define CHIP_REG_ADCSRA_ADDR                                        0x26
#define CHIP_REG_ADCSRA_TYPE                                        uint8_t
#define CHIP_REG_ADMUX_ADDR                                         0x27
#define CHIP_REG_ADMUX_TYPE                                         uint8_t
#define CHIP_REG_ACSR_ADDR                                          0x28
#define CHIP_REG_ACSR_TYPE                                          uint8_t
#define CHIP_REG_USICR_ADDR                                         0x2D
#define CHIP_REG_USICR_TYPE                                         uint8_t
#define CHIP_REG_USISR_ADDR                                         0x2E
#define CHIP_REG_USISR_TYPE                                         uint8_t
#define CHIP_REG_USIDR_ADDR                                         0x2F
#define CHIP_REG_USIDR_TYPE                                         uint8_t
#define CHIP_REG_USIBR_ADDR                                         0x30
#define CHIP_REG_USIBR_TYPE                                         uint8_t
#define CHIP_REG_GPIOR0_ADDR                                        0x31
#define CHIP_REG_GPIOR0_TYPE                                        uint8_t
#define CHIP_REG_GPIOR1_ADDR                                        0x32
#define CHIP_REG_GPIOR1_TYPE                                        uint8_t
#define CHIP_REG_GPIOR2_ADDR                                        0x33
#define CHIP_REG_GPIOR2_TYPE                                        uint8_t
#define CHIP_REG_DIDR0_ADDR                                         0x34
#define CHIP_REG_DIDR0_TYPE                                         uint8_t
#define CHIP_REG_PCMSK_ADDR                                         0x35
#define CHIP_REG_PCMSK_TYPE                                         uint8_t
#define CHIP_REG_PINB_ADDR                                          0x36
#define CHIP_REG_PINB_TYPE                                          uint8_t
#define CHIP_REG_DDRB_ADDR                                          0x37
#define CHIP_REG_DDRB_TYPE                                          uint8_t
#define CHIP_REG_PORTB_ADDR                                         0x38
#define CHIP_REG_PORTB_TYPE                                         uint8_t
#define CHIP_REG_EECR_ADDR                                          0x3C
#define CHIP_REG_EECR_TYPE                                          uint8_t
#define CHIP_REG_EEDR_ADDR                                          0x3D
#define CHIP_REG_EEDR_TYPE                                          uint8_t
#define CHIP_REG_EEARL_ADDR                                         0x3E
#define CHIP_REG_EEARL_TYPE                                         uint8_t
#define CHIP_REG_EEARH_ADDR                                         0x3F
#define CHIP_REG_EEARH_TYPE                                         uint8_t
#define CHIP_REG_PRR_ADDR                                           0x40
#define CHIP_REG_PRR_TYPE                                           uint8_t
#define CHIP_REG_WDTCR_ADDR                                         0x41
#define CHIP_REG_WDTCR_TYPE                                         uint8_t
#define CHIP_REG_DWDR_ADDR                                          0x42
#define CHIP_REG_DWDR_TYPE                                          uint8_t
#define CHIP_REG_DTPS1_ADDR                                         0x43
#define CHIP_REG_DTPS1_TYPE                                         uint8_t
#define CHIP_REG_DT1B_ADDR                                          0x44
#define CHIP_REG_DT1B_TYPE                                          uint8_t
#define CHIP_REG_DT1A_ADDR                                          0x45
#define CHIP_REG_DT1A_TYPE                                          uint8_t
#define CHIP_REG_CLKPR_ADDR                                         0x46
#define CHIP_REG_CLKPR_TYPE                                         uint8_t
#define CHIP_REG_PLLCSR_ADDR                                        0x47
#define CHIP_REG_PLLCSR_TYPE                                        uint8_t
#define CHIP_REG_OCR0B_ADDR                                         0x48
#define CHIP_REG_OCR0B_TYPE                                         uint8_t
#define CHIP_REG_OCR0A_ADDR                                         0x49
#define CHIP_REG_OCR0A_TYPE                                         uint8_t
#define CHIP_REG_TCCR0A_ADDR                                        0x4A
#define CHIP_REG_TCCR0A_TYPE                                        uint8_t
#define CHIP_REG_OCR1B_ADDR                                         0x4B
#define CHIP_REG_OCR1B_TYPE                                         uint8_t
#define CHIP_REG_GTCCR_ADDR                                         0x4C
#define CHIP_REG_GTCCR_TYPE                                         uint8_t
#define CHIP_REG_OCR1C_ADDR                                         0x4D
#define CHIP_REG_OCR1C_TYPE                                         uint8_t
#define CHIP_REG_OCR1A_ADDR                                         0x4E
#define CHIP_REG_OCR1A_TYPE                                         uint8_t
#define CHIP_REG_TCNT1_ADDR                                         0x4F
#define CHIP_REG_TCNT1_TYPE                                         uint8_t
#define CHIP_REG_TCCR1_ADDR                                         0x50
#define CHIP_REG_TCCR1_TYPE                                         uint8_t
#define CHIP_REG_OSCCAL_ADDR                                        0x51
#define CHIP_REG_OSCCAL_TYPE                                        uint8_t
#define CHIP_REG_TCNT0_ADDR                                         0x52
#define CHIP_REG_TCNT0_TYPE                                         uint8_t
#define CHIP_REG_TCCR0B_ADDR                                        0x53
#define CHIP_REG_TCCR0B_TYPE                                        uint8_t
#define CHIP_REG_MCUSR_ADDR                                         0x54
#define CHIP_REG_MCUSR_TYPE                                         uint8_t
#define CHIP_REG_MCUCR_ADDR                                         0x55
#define CHIP_REG_MCUCR_TYPE                                         uint8_t
#define CHIP_REG_SPMCSR_ADDR                                        0x57
#define CHIP_REG_SPMCSR_TYPE                                        uint8_t
#define CHIP_REG_TIFR_ADDR                                          0x58
#define CHIP_REG_TIFR_TYPE                                          uint8_t
#define CHIP_REG_TIMSK_ADDR                                         0x59
#define CHIP_REG_TIMSK_TYPE                                         uint8_t
#define CHIP_REG_GIFR_ADDR                                          0x5A
#define CHIP_REG_GIFR_TYPE                                          uint8_t
#define CHIP_REG_GIMSK_ADDR                                         0x5B
#define CHIP_REG_GIMSK_TYPE                                         uint8_t
#define CHIP_REG_SPL_ADDR                                           0x5D
#define CHIP_REG_SPL_TYPE                                           uint8_t
#define CHIP_REG_SPH_ADDR                                           0x5E
#define CHIP_REG_SPH_TYPE                                           uint8_t
#define CHIP_REG_SREG_ADDR                                          0x5F
#define CHIP_REG_SREG_TYPE                                          uint8_t

#define CHIP_VECT_RESET                                             1
#define CHIP_VECT_INT0                                              2
#define CHIP_VECT_PCINT0                                            3
#define CHIP_VECT_TIMER1_COMPA                                      4
#define CHIP_VECT_TIMER1_OVF                                        5
#define CHIP_VECT_TIMER0_OVF                                        6
#define CHIP_VECT_EE_READY                                          7
#define CHIP_VECT_ANALOG_COMP                                       8
#define CHIP_VECT_ADC                                               9
#define CHIP_VECT_TIMER1_COMPB                                      10
#define CHIP_VECT_TIMER0_COMPA                                      11
#define CHIP_VECT_TIMER0_COMPB                                      12
#define CHIP_VECT_WDT                                               13
#define CHIP_VECT_USI_START                                         14
#define CHIP_VECT_USI_OVF                                           15

//------------------------------------------------
// System

// Possibly need IDs for chips which have inhibit instead of enable.
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG                      CHIP_REG_SREG
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_BIT                      7

// //------------------------------------------------
// // Status Register

// #define CHIP_STATUS_REG                                                 REG8(CHIP_ADDR_SREG)

// //------------------------------------------------
// // Reset Status Register

// #define CHIP_RESET_STATUS_REG                                           REG8(CHIP_ADDR_MCUSR)

// //------------------------------------------------
// // Watchdog Timer

// #define CHIP_WATCHDOG_TIMER_CONTROL_REG                                 REG8(CHIP_ADDR_WDTCR)
// #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_0_BIT                         0
// #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_1_BIT                         1
// #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_2_BIT                         2
// #define CHIP_WATCHDOG_TIMER_ENABLE_BIT                                  3
// #define CHIP_WATCHDOG_TIMER_CHANGE_ENABLE_BIT                           4
// #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_3_BIT                         5
// #define CHIP_WATCHDOG_TIMER_INT_ENABLE_BIT                              6
// #define CHIP_WATCHDOG_TIMER_INT_FLAG_BIT                                7

//------------------------------------------------
// IO ports

#define CHIP_PORT_B                                                 true
#define CHIP_PORT_B_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PORT_B_TOGGLE_OUTPUTS_REG                              CHIP_REG_PINB
#define CHIP_PORT_B_INPUT_REG                                       CHIP_REG_PINB

//------------------------------------------------
// IO pins

#define CHIP_PIN_MODE_INPUT_ID                                      0
#define CHIP_PIN_MODE_OUTPUT_ID                                     1
#define CHIP_PIN_MODE_INPUT_PULLUP_ID                               2

#define CHIP_PIN_B0                                                 true
#define CHIP_PIN_B0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_B0_MODE_BIT_0_REG                                  CHIP_REG_DDRB
#define CHIP_PIN_B0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_B0_MODE_BIT_1_REG                                  CHIP_REG_PORTB
#define CHIP_PIN_B0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_B0_INPUT_BIT_0_REG                                 CHIP_REG_PINB
#define CHIP_PIN_B0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_B0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTB
#define CHIP_PIN_B0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_B0_TOGGLE_BIT_0_REG                                CHIP_REG_PINB

#define CHIP_PIN_B1                                                 true
#define CHIP_PIN_B1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_B1_MODE_BIT_0_REG                                  CHIP_REG_DDRB
#define CHIP_PIN_B1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_B1_MODE_BIT_1_REG                                  CHIP_REG_PORTB
#define CHIP_PIN_B1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_B1_INPUT_BIT_0_REG                                 CHIP_REG_PINB
#define CHIP_PIN_B1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_B1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTB
#define CHIP_PIN_B1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_B1_TOGGLE_BIT_0_REG                                CHIP_REG_PINB

#define CHIP_PIN_B2                                                 true
#define CHIP_PIN_B2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_B2_MODE_BIT_0_REG                                  CHIP_REG_DDRB
#define CHIP_PIN_B2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_B2_MODE_BIT_1_REG                                  CHIP_REG_PORTB
#define CHIP_PIN_B2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_B2_INPUT_BIT_0_REG                                 CHIP_REG_PINB
#define CHIP_PIN_B2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_B2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTB
#define CHIP_PIN_B2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_B2_TOGGLE_BIT_0_REG                                CHIP_REG_PINB

#define CHIP_PIN_B3                                                 true
#define CHIP_PIN_B3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_B3_MODE_BIT_0_REG                                  CHIP_REG_DDRB
#define CHIP_PIN_B3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_B3_MODE_BIT_1_REG                                  CHIP_REG_PORTB
#define CHIP_PIN_B3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_B3_INPUT_BIT_0_REG                                 CHIP_REG_PINB
#define CHIP_PIN_B3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_B3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTB
#define CHIP_PIN_B3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_B3_TOGGLE_BIT_0_REG                                CHIP_REG_PINB

#define CHIP_PIN_B4                                                 true
#define CHIP_PIN_B4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_B4_MODE_BIT_0_REG                                  CHIP_REG_DDRB
#define CHIP_PIN_B4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_B4_MODE_BIT_1_REG                                  CHIP_REG_PORTB
#define CHIP_PIN_B4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_B4_INPUT_BIT_0_REG                                 CHIP_REG_PINB
#define CHIP_PIN_B4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_B4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTB
#define CHIP_PIN_B4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_B4_TOGGLE_BIT_0_REG                                CHIP_REG_PINB

#define CHIP_PIN_B5                                                 true
#define CHIP_PIN_B5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_B5_MODE_BIT_0_REG                                  CHIP_REG_DDRB
#define CHIP_PIN_B5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_B5_MODE_BIT_1_REG                                  CHIP_REG_PORTB
#define CHIP_PIN_B5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_B5_INPUT_BIT_0_REG                                 CHIP_REG_PINB
#define CHIP_PIN_B5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_B5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTB
#define CHIP_PIN_B5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_B5_TOGGLE_BIT_0_REG                                CHIP_REG_PINB

//------------------------------------------------
// Analog to digital converters

#define CHIP_ADC_0                                                  true

#define CHIP_ADC_0_DATA_REG                                         CHIP_REG_ADC

#define CHIP_ADC_0_ENABLE_BIT_0_REG                                 CHIP_REG_ADCSRA
#define CHIP_ADC_0_ENABLE_BIT_0_BIT                                 7

#define CHIP_ADC_0_START_BIT_0_REG                                  CHIP_REG_ADCSRA
#define CHIP_ADC_0_START_BIT_0_BIT                                  6

#define CHIP_ADC_0_REFERENCE_BIT_0_REG                              CHIP_REG_ADMUX
#define CHIP_ADC_0_REFERENCE_BIT_1_REG                              CHIP_REG_ADMUX
#define CHIP_ADC_0_REFERENCE_BIT_2_REG                              CHIP_REG_ADMUX
#define CHIP_ADC_0_REFERENCE_BIT_0_BIT                              6
#define CHIP_ADC_0_REFERENCE_BIT_1_BIT                              7
#define CHIP_ADC_0_REFERENCE_BIT_2_BIT                              4
#define CHIP_ADC_0_REFERENCE_AVCC_ID                                0
#define CHIP_ADC_0_REFERENCE_AREF_ID                                1
#define CHIP_ADC_0_REFERENCE_INTERNAL_1_1_ID                        2
#define CHIP_ADC_0_REFERENCE_INTERNAL_2_56_ID                       6
#define CHIP_ADC_0_REFERENCE_INTERNAL_2_56_CAP_ID                   7

#define CHIP_ADC_0_CHANNEL_BIT_0_REG                                CHIP_REG_ADMUX
#define CHIP_ADC_0_CHANNEL_BIT_1_REG                                CHIP_REG_ADMUX
#define CHIP_ADC_0_CHANNEL_BIT_2_REG                                CHIP_REG_ADMUX
#define CHIP_ADC_0_CHANNEL_BIT_3_REG                                CHIP_REG_ADMUX
#define CHIP_ADC_0_CHANNEL_BIT_0_BIT                                0
#define CHIP_ADC_0_CHANNEL_BIT_1_BIT                                1
#define CHIP_ADC_0_CHANNEL_BIT_2_BIT                                2
#define CHIP_ADC_0_CHANNEL_BIT_3_BIT                                3
#define CHIP_ADC_0_CHANNEL_0_ID                                     0
#define CHIP_ADC_0_CHANNEL_1_ID                                     1
#define CHIP_ADC_0_CHANNEL_2_ID                                     2
#define CHIP_ADC_0_CHANNEL_3_ID                                     3

#define CHIP_ADC_0_CHANNEL_2_2_1X_ID                                4
#define CHIP_ADC_0_CHANNEL_2_2_20X_ID                               5
#define CHIP_ADC_0_CHANNEL_2_3_1X_ID                                6
#define CHIP_ADC_0_CHANNEL_2_3_20X_ID                               7
#define CHIP_ADC_0_CHANNEL_0_0_1X_ID                                8
#define CHIP_ADC_0_CHANNEL_0_0_20X_ID                               9
#define CHIP_ADC_0_CHANNEL_0_1_1X_ID                                10
#define CHIP_ADC_0_CHANNEL_0_1_20X_ID                               11
#define CHIP_ADC_0_CHANNEL_VBG_ID                                   12
#define CHIP_ADC_0_CHANNEL_GND_ID                                   13
#define CHIP_ADC_0_CHANNEL_4_ID                                     15

#define CHIP_ADC_0_TRIGGER_BIT_0_REG                                CHIP_REG_ADCSRB
#define CHIP_ADC_0_TRIGGER_BIT_1_REG                                CHIP_REG_ADCSRB
#define CHIP_ADC_0_TRIGGER_BIT_2_REG                                CHIP_REG_ADCSRB
#define CHIP_ADC_0_TRIGGER_BIT_3_REG                                CHIP_REG_ADCSRA
#define CHIP_ADC_0_TRIGGER_BIT_0_BIT                                0
#define CHIP_ADC_0_TRIGGER_BIT_1_BIT                                1
#define CHIP_ADC_0_TRIGGER_BIT_2_BIT                                2
#define CHIP_ADC_0_TRIGGER_BIT_3_BIT                                5
#define CHIP_ADC_0_TRIGGER_SINGLE_CONVERSION_ID                     0
#define CHIP_ADC_0_TRIGGER_FREE_RUNNING_ID                          8
#define CHIP_ADC_0_TRIGGER_ANALOG_COMPARATOR_ID                     9
#define CHIP_ADC_0_TRIGGER_EXTERNAL_INT_0_ID                        10
#define CHIP_ADC_0_TRIGGER_TIMER0_COMPARE_MATCH_A_ID                11
#define CHIP_ADC_0_TRIGGER_TIMER0_OVERFLOW_ID                       12
#define CHIP_ADC_0_TRIGGER_TIMER0_COMPARE_MATCH_B_ID                13
#define CHIP_ADC_0_TRIGGER_PIN_CHANGE_INT_0_ID                      14

#define CHIP_ADC_0_INT_FLAG_BIT_0_REG                               CHIP_REG_ADCSRA
#define CHIP_ADC_0_INT_FLAG_BIT_0_BIT                               4
#define CHIP_ADC_0_INT_ENABLE_BIT_0_REG                             CHIP_REG_ADCSRA
#define CHIP_ADC_0_INT_ENABLE_BIT_0_BIT                             3
#define CHIP_ADC_0_INT_VECTOR                                       VECT(CHIP_VECT_ADC)

#define CHIP_ADC_0_LEFT_ADJUST_BIT_0_REG                            CHIP_REG_ADMUX
#define CHIP_ADC_0_LEFT_ADJUST_BIT_0_BIT                            5

#define CHIP_ADC_0_PRESCALER_BIT_0_REG                              CHIP_REG_ADCSRA
#define CHIP_ADC_0_PRESCALER_BIT_1_REG                              CHIP_REG_ADCSRA
#define CHIP_ADC_0_PRESCALER_BIT_2_REG                              CHIP_REG_ADCSRA
#define CHIP_ADC_0_PRESCALER_BIT_0_BIT                              0
#define CHIP_ADC_0_PRESCALER_BIT_1_BIT                              1
#define CHIP_ADC_0_PRESCALER_BIT_2_BIT                              2
#define CHIP_ADC_0_PRESCALER_2_ID                                   0
#define CHIP_ADC_0_PRESCALER_4_ID                                   2
#define CHIP_ADC_0_PRESCALER_8_ID                                   3
#define CHIP_ADC_0_PRESCALER_16_ID                                  4
#define CHIP_ADC_0_PRESCALER_32_ID                                  5
#define CHIP_ADC_0_PRESCALER_64_ID                                  6
#define CHIP_ADC_0_PRESCALER_128_ID                                 7

//------------------------------------------------
// External interrupts

#define CHIP_EXINT_0                                                true
#define CHIP_EXINT_0_ENABLE_BIT_0_REG                               CHIP_REG_GIMSK
#define CHIP_EXINT_0_ENABLE_BIT_0_BIT                               6
#define CHIP_EXINT_0_INT_FLAG_BIT_0_REG                             CHIP_REG_GIFR
#define CHIP_EXINT_0_INT_FLAG_BIT_0_BIT                             6
#define CHIP_EXINT_0_TRIGGER_BIT_0_REG                              CHIP_REG_MCUCR
#define CHIP_EXINT_0_TRIGGER_BIT_1_REG                              CHIP_REG_MCUCR
#define CHIP_EXINT_0_TRIGGER_BIT_0_BIT                              0
#define CHIP_EXINT_0_TRIGGER_BIT_1_BIT                              1
#define CHIP_EXINT_0_TRIGGER_LOW_ID                                 0
#define CHIP_EXINT_0_TRIGGER_CHANGE_ID                              1
#define CHIP_EXINT_0_TRIGGER_FALLING_ID                             2
#define CHIP_EXINT_0_TRIGGER_RISING_ID                              3
#define CHIP_EXINT_0_INT_VECTOR                                     VECT(CHIP_VECT_INT0)

//------------------------------------------------
// Pin change interrupts

#define CHIP_PCINT_0                                                true
#define CHIP_PCINT_0_ENABLE_BIT_0_REG                               CHIP_REG_GIMSK
#define CHIP_PCINT_0_ENABLE_BIT_0_BIT                               5
#define CHIP_PCINT_0_INT_FLAG_BIT_0_REG                             CHIP_REG_GIFR
#define CHIP_PCINT_0_INT_FLAG_BIT_0_BIT                             6
#define CHIP_PCINT_0_MASK_REG                                       CHIP_REG_PCMSK
#define CHIP_PCINT_0_INT_VECTOR                                     VECT(CHIP_VECT_PCINT0)

//------------------------------------------------
// Timers

#define CHIP_TIMER_0                                                true

#define CHIP_TIMER_0_TYPE                                           uint8_t

#define CHIP_TIMER_0_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR0A
#define CHIP_TIMER_0_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR0A
#define CHIP_TIMER_0_WAVEFORM_BIT_2_REG                             CHIP_REG_TCCR0B
#define CHIP_TIMER_0_WAVEFORM_BIT_0_BIT                             0
#define CHIP_TIMER_0_WAVEFORM_BIT_1_BIT                             1
#define CHIP_TIMER_0_WAVEFORM_BIT_2_BIT                             3
#define CHIP_TIMER_0_WAVEFORM_NORMAL_ID                             0
#define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_ID                  1
#define CHIP_TIMER_0_WAVEFORM_CTC_OCRA_ID                           2
#define CHIP_TIMER_0_WAVEFORM_FAST_PWM_ID                           3
#define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             5
#define CHIP_TIMER_0_WAVEFORM_FAST_PWM_OCRA_ID                      7

#define CHIP_TIMER_0_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_0_CLOCK_1_ID                                     1
#define CHIP_TIMER_0_CLOCK_8_ID                                     2
#define CHIP_TIMER_0_CLOCK_64_ID                                    3
#define CHIP_TIMER_0_CLOCK_256_ID                                   4
#define CHIP_TIMER_0_CLOCK_1024_ID                                  5
#define CHIP_TIMER_0_CLOCK_EXT_FALLING_ID                           6
#define CHIP_TIMER_0_CLOCK_EXT_RISING_ID                            7
#define CHIP_TIMER_0_CLOCK_BIT_0_REG                                CHIP_REG_TCCR0B
#define CHIP_TIMER_0_CLOCK_BIT_1_REG                                CHIP_REG_TCCR0B
#define CHIP_TIMER_0_CLOCK_BIT_2_REG                                CHIP_REG_TCCR0B
#define CHIP_TIMER_0_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_0_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_0_CLOCK_BIT_2_BIT                                2

#define CHIP_TIMER_0_COUNTER_REG                                    CHIP_REG_TCNT0

#define CHIP_TIMER_0_OUTPUT_A                                       true
#define CHIP_TIMER_0_OUTPUT_A_PIN                                   PortB::Pin0
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_0_REG                        CHIP_REG_TCCR0A
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_1_REG                        CHIP_REG_TCCR0A
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_0_BIT                        6
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_1_BIT                        7
#define CHIP_TIMER_0_OUTPUT_A_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_0_OUTPUT_A_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_0_OUTPUT_A_MODE_CLEAR_ID                         2
#define CHIP_TIMER_0_OUTPUT_A_MODE_SET_ID                           3
#define CHIP_TIMER_0_OUTPUT_A_REG                                   CHIP_REG_OCR0A
#define CHIP_TIMER_0_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_0_OUTPUT_A_INT_ENABLE_BIT                        2
#define CHIP_TIMER_0_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_0_OUTPUT_A_INT_FLAG_BIT                          4
#define CHIP_TIMER_0_OUTPUT_A_INT_VECTOR                            VECT(CHIP_VECT_TIMER0_COMPA)

#define CHIP_TIMER_0_OUTPUT_B                                       true
#define CHIP_TIMER_0_OUTPUT_B_PIN                                   PortB::Pin3
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_0_REG                        CHIP_REG_TCCR0A
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_1_REG                        CHIP_REG_TCCR0A
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_0_BIT                        4
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_1_BIT                        5
#define CHIP_TIMER_0_OUTPUT_B_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_0_OUTPUT_B_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_0_OUTPUT_B_MODE_CLEAR_ID                         2
#define CHIP_TIMER_0_OUTPUT_B_MODE_SET_ID                           3
#define CHIP_TIMER_0_OUTPUT_B_REG                                   CHIP_REG_OCR0B
#define CHIP_TIMER_0_OUTPUT_B_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_0_OUTPUT_B_INT_ENABLE_BIT                        3
#define CHIP_TIMER_0_OUTPUT_B_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_0_OUTPUT_B_INT_FLAG_BIT                          3
#define CHIP_TIMER_0_OUTPUT_B_INT_VECTOR                            VECT(CHIP_VECT_TIMER0_COMPB)

#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                        1
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_BIT                          1
#define CHIP_TIMER_0_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER0_OVF)

//------------------------------------------------

#define CHIP_TIMER_1                                                true

#define CHIP_TIMER_1_TYPE                                           uint8_t

#define CHIP_TIMER_1_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR1
#define CHIP_TIMER_1_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR1
#define CHIP_TIMER_1_WAVEFORM_BIT_0_BIT                             6
#define CHIP_TIMER_1_WAVEFORM_BIT_1_BIT                             7
#define CHIP_TIMER_1_WAVEFORM_NORMAL_ID                             0
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_OCRC_ID                      1
#define CHIP_TIMER_1_WAVEFORM_CTC_OCRA_ID                           2

#define CHIP_TIMER_1_CLOCK_BIT_0_REG                                CHIP_REG_TCCR1
#define CHIP_TIMER_1_CLOCK_BIT_1_REG                                CHIP_REG_TCCR1
#define CHIP_TIMER_1_CLOCK_BIT_2_REG                                CHIP_REG_TCCR1
#define CHIP_TIMER_1_CLOCK_BIT_3_REG                                CHIP_REG_TCCR1
#define CHIP_TIMER_1_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_1_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_1_CLOCK_BIT_2_BIT                                2
#define CHIP_TIMER_1_CLOCK_BIT_3_BIT                                3
#define CHIP_TIMER_1_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_1_CLOCK_1_ID                                     1
#define CHIP_TIMER_1_CLOCK_2_ID                                     2
#define CHIP_TIMER_1_CLOCK_4_ID                                     3
#define CHIP_TIMER_1_CLOCK_8_ID                                     4
#define CHIP_TIMER_1_CLOCK_16_ID                                    5
#define CHIP_TIMER_1_CLOCK_32_ID                                    6
#define CHIP_TIMER_1_CLOCK_64_ID                                    7
#define CHIP_TIMER_1_CLOCK_128_ID                                   8
#define CHIP_TIMER_1_CLOCK_256_ID                                   9
#define CHIP_TIMER_1_CLOCK_512_ID                                   10
#define CHIP_TIMER_1_CLOCK_1024_ID                                  11
#define CHIP_TIMER_1_CLOCK_2048_ID                                  12
#define CHIP_TIMER_1_CLOCK_4096_ID                                  13
#define CHIP_TIMER_1_CLOCK_8192_ID                                  14
#define CHIP_TIMER_1_CLOCK_16384_ID                                 15

#define CHIP_TIMER_1_COUNTER_REG                                    CHIP_REG_TCNT1

#define CHIP_TIMER_1_OUTPUT_A                                       true
#define CHIP_TIMER_1_OUTPUT_A_PIN                                   PortB::Pin1
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_0_REG                        CHIP_REG_TCCR1
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_1_REG                        CHIP_REG_TCCR1
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_0_BIT                        4
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_1_BIT                        5
#define CHIP_TIMER_1_OUTPUT_A_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_1_OUTPUT_A_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_1_OUTPUT_A_MODE_CLEAR_ID                         2
#define CHIP_TIMER_1_OUTPUT_A_MODE_SET_ID                           3
#define CHIP_TIMER_1_OUTPUT_A_REG                                   CHIP_REG_OCR1A
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_BIT                        6
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_BIT                          6
#define CHIP_TIMER_1_OUTPUT_A_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_COMPA)

#define CHIP_TIMER_1_OUTPUT_B                                       true
#define CHIP_TIMER_1_OUTPUT_B_PIN                                   PortB::Pin4
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_0_REG                        CHIP_REG_GTCCR
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_1_REG                        CHIP_REG_GTCCR
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_0_BIT                        4
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_1_BIT                        5
#define CHIP_TIMER_1_OUTPUT_B_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_1_OUTPUT_B_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_1_OUTPUT_B_MODE_CLEAR_ID                         2
#define CHIP_TIMER_1_OUTPUT_B_MODE_SET_ID                           3
#define CHIP_TIMER_1_OUTPUT_B_REG                                   CHIP_REG_OCR1B
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_BIT                        5
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_BIT                          5
#define CHIP_TIMER_1_OUTPUT_B_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_COMPB)

#define CHIP_TIMER_1_OUTPUT_C                                       true
#define CHIP_TIMER_1_OUTPUT_C_REG                                   CHIP_REG_OCR1C
#define CHIP_TIMER_1_OUTPUT_C_INT_FLAG_REG                          CHIP_REG_TIFR

#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                        2
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_BIT                          2
#define CHIP_TIMER_1_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_OVF)

//------------------------------------------------
// Universal serial interfaces

#define CHIP_USI_0                                                  true

#define CHIP_USI_0_PIN_DO                                           PortB::Pin1
#define CHIP_USI_0_PIN_DI                                           PortB::Pin0
#define CHIP_USI_0_PIN_SDA                                          PortB::Pin0
#define CHIP_USI_0_PIN_SCL                                          PortB::Pin2
#define CHIP_USI_0_PIN_USCK                                         PortB::Pin2

#define CHIP_USI_0_DATA_REG                                         CHIP_REG_USIDR
#define CHIP_USI_0_BUFFER_REG                                       CHIP_REG_USIBR

#define CHIP_USI_0_START_CONDITION_INT_FLAG_BIT_0_REG               CHIP_REG_USISR
#define CHIP_USI_0_START_CONDITION_INT_FLAG_BIT_0_BIT               7

#define CHIP_USI_0_COUNTER_OVERFLOW_INT_FLAG_BIT_0_REG              CHIP_REG_USISR
#define CHIP_USI_0_COUNTER_OVERFLOW_INT_FLAG_BIT_0_BIT              6

#define CHIP_USI_0_STOP_CONDITION_INT_FLAG_BIT_0_REG                CHIP_REG_USISR
#define CHIP_USI_0_STOP_CONDITION_INT_FLAG_BIT_0_BIT                5

#define CHIP_USI_0_COLLISION_FLAG_BIT_0_REG                         CHIP_REG_USISR
#define CHIP_USI_0_COLLISION_FLAG_BIT_0_BIT                         4

#define CHIP_USI_0_COUNTER_BIT_0_REG                                CHIP_REG_USISR
#define CHIP_USI_0_COUNTER_BIT_0_BIT                                0
#define CHIP_USI_0_COUNTER_BIT_1_REG                                CHIP_REG_USISR
#define CHIP_USI_0_COUNTER_BIT_1_BIT                                1
#define CHIP_USI_0_COUNTER_BIT_2_REG                                CHIP_REG_USISR
#define CHIP_USI_0_COUNTER_BIT_2_BIT                                2
#define CHIP_USI_0_COUNTER_BIT_3_REG                                CHIP_REG_USISR
#define CHIP_USI_0_COUNTER_BIT_3_BIT                                3

#define CHIP_USI_0_START_CONDITION_INT_ENABLE_BIT_0_REG             CHIP_REG_USICR
#define CHIP_USI_0_START_CONDITION_INT_ENABLE_BIT_0_BIT             7

#define CHIP_USI_0_COUNTER_OVERFLOW_INT_ENABLE_BIT_0_REG            CHIP_REG_USICR
#define CHIP_USI_0_COUNTER_OVERFLOW_INT_ENABLE_BIT_0_BIT            6

#define CHIP_USI_0_WIRE_MODE_DISABLED_ID                            0
#define CHIP_USI_0_WIRE_MODE_THREE_WIRE_ID                          1
#define CHIP_USI_0_WIRE_MODE_TWO_WIRE_ID                            2
#define CHIP_USI_0_WIRE_MODE_TWO_WIRE_OVERFLOW_ID                   3

#define CHIP_USI_0_WIRE_MODE_BIT_0_REG                              CHIP_REG_USICR
#define CHIP_USI_0_WIRE_MODE_BIT_0_BIT                              4
#define CHIP_USI_0_WIRE_MODE_BIT_1_REG                              CHIP_REG_USICR
#define CHIP_USI_0_WIRE_MODE_BIT_1_BIT                              5

#define CHIP_USI_0_CLOCK_SELECT_NONE_ID                             0
#define CHIP_USI_0_CLOCK_SELECT_TIMER_0_COMPARE_MATCH_ID            1
#define CHIP_USI_0_CLOCK_SELECT_EXTERNAL_POSITIVE_EDGE_ID           2
#define CHIP_USI_0_CLOCK_SELECT_EXTERNAL_NEGATIVE_EDGE_ID           3

#define CHIP_USI_0_CLOCK_SELECT_BIT_0_REG                           CHIP_REG_USICR
#define CHIP_USI_0_CLOCK_SELECT_BIT_0_BIT                           2
#define CHIP_USI_0_CLOCK_SELECT_BIT_1_REG                           CHIP_REG_USICR
#define CHIP_USI_0_CLOCK_SELECT_BIT_1_BIT                           3

#define CHIP_USI_0_CLOCK_STROBE_BIT_0_REG                           CHIP_REG_USICR
#define CHIP_USI_0_CLOCK_STROBE_BIT_0_BIT                           1

#define CHIP_USI_0_TOGGLE_CLOCK_PIN_BIT_0_REG                       CHIP_REG_USICR
#define CHIP_USI_0_TOGGLE_CLOCK_PIN_BIT_0_BIT                       0

#define CHIP_USI_0_OVERFLOW_INT_VECTOR                              VECT(CHIP_VECT_USI_START)
#define CHIP_USI_0_START_INT_VECTOR                                 VECT(CHIP_VECT_USI_OVF)

#endif

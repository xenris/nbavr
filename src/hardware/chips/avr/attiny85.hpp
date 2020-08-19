#ifndef NBLIB_ATTINY85_HPP
#define NBLIB_ATTINY85_HPP

#define CHIP attiny85

//------------------------------------------------
// Registers

#define CHIP_REG_ADCSRB                                             Register<uint8_t, 0x23>
#define CHIP_REG_ADC                                                Register<uint16_t, 0x24>
#define CHIP_REG_ADCSRA                                             Register<uint8_t, 0x26, 0x50>
#define CHIP_REG_ADMUX                                              Register<uint8_t, 0x27>
#define CHIP_REG_ACSR                                               Register<uint8_t, 0x28, 0x10>
#define CHIP_REG_USICR                                              Register<uint8_t, 0x2D>
#define CHIP_REG_USISR                                              Register<uint8_t, 0x2E, 0xFF>
#define CHIP_REG_USIDR                                              Register<uint8_t, 0x2F>
#define CHIP_REG_USIBR                                              Register<uint8_t, 0x30>
#define CHIP_REG_GPIOR0                                             Register<uint8_t, 0x31>
#define CHIP_REG_GPIOR1                                             Register<uint8_t, 0x32>
#define CHIP_REG_GPIOR2                                             Register<uint8_t, 0x33>
#define CHIP_REG_DIDR0                                              Register<uint8_t, 0x34>
#define CHIP_REG_PCMSK                                              Register<uint8_t, 0x35>
#define CHIP_REG_PINB                                               Register<uint8_t, 0x36, 0xFF>
#define CHIP_REG_DDRB                                               Register<uint8_t, 0x37>
#define CHIP_REG_PORTB                                              Register<uint8_t, 0x38>
#define CHIP_REG_EECR                                               Register<uint8_t, 0x3C>
#define CHIP_REG_EEDR                                               Register<uint8_t, 0x3D>
#define CHIP_REG_EEARL                                              Register<uint8_t, 0x3E>
#define CHIP_REG_EEARH                                              Register<uint8_t, 0x3F>
#define CHIP_REG_PRR                                                Register<uint8_t, 0x40>
#define CHIP_REG_WDTCR                                              Register<uint8_t, 0x41>
#define CHIP_REG_DWDR                                               Register<uint8_t, 0x42>
#define CHIP_REG_DTPS1                                              Register<uint8_t, 0x43>
#define CHIP_REG_DT1B                                               Register<uint8_t, 0x44>
#define CHIP_REG_DT1A                                               Register<uint8_t, 0x45>
#define CHIP_REG_CLKPR                                              Register<uint8_t, 0x46>
#define CHIP_REG_PLLCSR                                             Register<uint8_t, 0x47>
#define CHIP_REG_OCR0B                                              Register<uint8_t, 0x48>
#define CHIP_REG_OCR0A                                              Register<uint8_t, 0x49>
#define CHIP_REG_TCCR0A                                             Register<uint8_t, 0x4A>
#define CHIP_REG_OCR1B                                              Register<uint8_t, 0x4B>
#define CHIP_REG_GTCCR                                              Register<uint8_t, 0x4C>
#define CHIP_REG_OCR1C                                              Register<uint8_t, 0x4D>
#define CHIP_REG_OCR1A                                              Register<uint8_t, 0x4E>
#define CHIP_REG_TCNT1                                              Register<uint8_t, 0x4F>
#define CHIP_REG_TCCR1                                              Register<uint8_t, 0x50>
#define CHIP_REG_OSCCAL                                             Register<uint8_t, 0x51>
#define CHIP_REG_TCNT0                                              Register<uint8_t, 0x52>
#define CHIP_REG_TCCR0B                                             Register<uint8_t, 0x53>
#define CHIP_REG_MCUSR                                              Register<uint8_t, 0x54>
#define CHIP_REG_MCUCR                                              Register<uint8_t, 0x55>
#define CHIP_REG_SPMCSR                                             Register<uint8_t, 0x57>
#define CHIP_REG_TIFR                                               Register<uint8_t, 0x58, 0xFF>
#define CHIP_REG_TIMSK                                              Register<uint8_t, 0x59>
#define CHIP_REG_GIFR                                               Register<uint8_t, 0x5A, 0xFF>
#define CHIP_REG_GIMSK                                              Register<uint8_t, 0x5B>
#define CHIP_REG_SPL                                                Register<uint8_t, 0x5D>
#define CHIP_REG_SPH                                                Register<uint8_t, 0x5E>
#define CHIP_REG_SREG                                               Register<uint8_t, 0x5F>

//------------------------------------------------
// Vectors

#define vectorInt0                                                  ISR(__vector_1)
#define vectorPcInt0                                                ISR(__vector_2)
#define vectorTimer1CompareA                                        ISR(__vector_3)
#define vectorTimer1Overflow                                        ISR(__vector_4)
#define vectorTimer0Overflow                                        ISR(__vector_5)
#define vectorEepromReady                                           ISR(__vector_6)
#define vectorAnalogComparator0                                     ISR(__vector_7)
#define vectorAdc0                                                  ISR(__vector_8)
#define vectorTimer1CompareB                                        ISR(__vector_9)
#define vectorTimer0CompareA                                        ISR(__vector_10)
#define vectorTimer0CompareB                                        ISR(__vector_11)
#define vectorWatchdogTimeout                                       ISR(__vector_12)
#define vectorUsi0Start                                             ISR(__vector_13)
#define vectorUsi0Overflow                                          ISR(__vector_14)

//------------------------------------------------
// System

// Possibly need IDs for chips which have inhibit instead of enable.
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_REG                            CHIP_REG_SREG
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT                            7

//------------------------------------------------
// Sleep


#define CHIP_SLEEP_MODE_REG                                         CHIP_REG_MCUCR
#define CHIP_SLEEP_MODE_MASK                                        0x18
#define CHIP_SLEEP_MODE_IDLE_ID                                     0x00
#define CHIP_SLEEP_MODE_ADC_NOISE_REDUCTION_ID                      0x08
#define CHIP_SLEEP_MODE_POWER_DOWN_ID                               0x10

#define CHIP_SLEEP_ENABLE_REG                                       CHIP_REG_MCUCR
#define CHIP_SLEEP_ENABLE_BIT                                       5

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

#define CHIP_PORT_B
#define CHIP_PORT_B_DIRECTION_REG                                   CHIP_REG_DDRB
#define CHIP_PORT_B_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PORT_B_OUTPUT_TOGGLE_REG                               CHIP_REG_PINB
#define CHIP_PORT_B_INPUT_REG                                       CHIP_REG_PINB
#define CHIP_PORT_B_PULLUP_REG                                      CHIP_REG_PORTB

//------------------------------------------------
// IO pins

#define CHIP_PIN_B0
#define CHIP_PIN_B0_DIRECTION_REG                                   CHIP_REG_DDRB
#define CHIP_PIN_B0_DIRECTION_BIT                                   0
#define CHIP_PIN_B0_INPUT_REG                                       CHIP_REG_PINB
#define CHIP_PIN_B0_INPUT_BIT                                       0
#define CHIP_PIN_B0_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B0_OUTPUT_BIT                                      0
#define CHIP_PIN_B0_OUTPUT_TOGGLE_REG                               CHIP_REG_PINB
#define CHIP_PIN_B0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_B0_PULLUP_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B0_PULLUP_BIT                                      0

#define CHIP_PIN_B1
#define CHIP_PIN_B1_DIRECTION_REG                                   CHIP_REG_DDRB
#define CHIP_PIN_B1_DIRECTION_BIT                                   1
#define CHIP_PIN_B1_INPUT_REG                                       CHIP_REG_PINB
#define CHIP_PIN_B1_INPUT_BIT                                       1
#define CHIP_PIN_B1_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B1_OUTPUT_BIT                                      1
#define CHIP_PIN_B1_OUTPUT_TOGGLE_REG                               CHIP_REG_PINB
#define CHIP_PIN_B1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_B1_PULLUP_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B1_PULLUP_BIT                                      1

#define CHIP_PIN_B2
#define CHIP_PIN_B2_DIRECTION_REG                                   CHIP_REG_DDRB
#define CHIP_PIN_B2_DIRECTION_BIT                                   2
#define CHIP_PIN_B2_INPUT_REG                                       CHIP_REG_PINB
#define CHIP_PIN_B2_INPUT_BIT                                       2
#define CHIP_PIN_B2_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B2_OUTPUT_BIT                                      2
#define CHIP_PIN_B2_OUTPUT_TOGGLE_REG                               CHIP_REG_PINB
#define CHIP_PIN_B2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_B2_PULLUP_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B2_PULLUP_BIT                                      2

#define CHIP_PIN_B3
#define CHIP_PIN_B3_DIRECTION_REG                                   CHIP_REG_DDRB
#define CHIP_PIN_B3_DIRECTION_BIT                                   3
#define CHIP_PIN_B3_INPUT_REG                                       CHIP_REG_PINB
#define CHIP_PIN_B3_INPUT_BIT                                       3
#define CHIP_PIN_B3_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B3_OUTPUT_BIT                                      3
#define CHIP_PIN_B3_OUTPUT_TOGGLE_REG                               CHIP_REG_PINB
#define CHIP_PIN_B3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_B3_PULLUP_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B3_PULLUP_BIT                                      3

#define CHIP_PIN_B4
#define CHIP_PIN_B4_DIRECTION_REG                                   CHIP_REG_DDRB
#define CHIP_PIN_B4_DIRECTION_BIT                                   4
#define CHIP_PIN_B4_INPUT_REG                                       CHIP_REG_PINB
#define CHIP_PIN_B4_INPUT_BIT                                       4
#define CHIP_PIN_B4_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B4_OUTPUT_BIT                                      4
#define CHIP_PIN_B4_OUTPUT_TOGGLE_REG                               CHIP_REG_PINB
#define CHIP_PIN_B4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_B4_PULLUP_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B4_PULLUP_BIT                                      4

#define CHIP_PIN_B5
#define CHIP_PIN_B5_DIRECTION_REG                                   CHIP_REG_DDRB
#define CHIP_PIN_B5_DIRECTION_BIT                                   5
#define CHIP_PIN_B5_INPUT_REG                                       CHIP_REG_PINB
#define CHIP_PIN_B5_INPUT_BIT                                       5
#define CHIP_PIN_B5_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B5_OUTPUT_BIT                                      5
#define CHIP_PIN_B5_OUTPUT_TOGGLE_REG                               CHIP_REG_PINB
#define CHIP_PIN_B5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_B5_PULLUP_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B5_PULLUP_BIT                                      5

//------------------------------------------------
// Analog to digital converters

#define CHIP_ADC_0

#define CHIP_ADC_0_RESULT_REG                                       CHIP_REG_ADC

#define CHIP_ADC_0_ENABLE_REG                                       CHIP_REG_ADCSRA
#define CHIP_ADC_0_ENABLE_BIT                                       7

#define CHIP_ADC_0_START_REG                                        CHIP_REG_ADCSRA
#define CHIP_ADC_0_START_BIT                                        6

#define CHIP_ADC_0_REFERENCE_REG                                    CHIP_REG_ADMUX
#define CHIP_ADC_0_REFERENCE_MASK                                   0xD0
#define CHIP_ADC_0_REFERENCE_VCC_ID                                 0x00
#define CHIP_ADC_0_REFERENCE_AREF_ID                                0x40
#define CHIP_ADC_0_REFERENCE_INTERNAL_1_1_ID                        0x80
#define CHIP_ADC_0_REFERENCE_INTERNAL_2_56_ID                       0x90
#define CHIP_ADC_0_REFERENCE_INTERNAL_2_56_CAP_ID                   0xD0

#define CHIP_ADC_0_CHANNEL_REG                                      CHIP_REG_ADMUX
#define CHIP_ADC_0_CHANNEL_MASK                                     0x0F
#define CHIP_ADC_0_CHANNEL_0_ID                                     0x00
#define CHIP_ADC_0_CHANNEL_1_ID                                     0x01
#define CHIP_ADC_0_CHANNEL_2_ID                                     0x02
#define CHIP_ADC_0_CHANNEL_3_ID                                     0x03
#define CHIP_ADC_0_CHANNEL_2_2_1X_ID                                0x04
#define CHIP_ADC_0_CHANNEL_2_2_20X_ID                               0x05
#define CHIP_ADC_0_CHANNEL_2_3_1X_ID                                0x06
#define CHIP_ADC_0_CHANNEL_2_3_20X_ID                               0x07
#define CHIP_ADC_0_CHANNEL_0_0_1X_ID                                0x08
#define CHIP_ADC_0_CHANNEL_0_0_20X_ID                               0x09
#define CHIP_ADC_0_CHANNEL_0_1_1X_ID                                0x0A
#define CHIP_ADC_0_CHANNEL_0_1_20X_ID                               0x0B
#define CHIP_ADC_0_CHANNEL_VBG_ID                                   0x0C
#define CHIP_ADC_0_CHANNEL_GND_ID                                   0x0D
#define CHIP_ADC_0_CHANNEL_4_ID                                     0x0F

#define CHIP_ADC_0_TRIGGER_ENABLE_REG                               CHIP_REG_ADCSRA
#define CHIP_ADC_0_TRIGGER_ENABLE_BIT                               5

#define CHIP_ADC_0_TRIGGER_REG                                      CHIP_REG_ADCSRB
#define CHIP_ADC_0_TRIGGER_MASK                                     0x07
#define CHIP_ADC_0_TRIGGER_FREE_RUNNING_ID                          0x00
#define CHIP_ADC_0_TRIGGER_ANALOG_COMPARATOR_ID                     0x01
#define CHIP_ADC_0_TRIGGER_EXTERNAL_INT_0_ID                        0x02
#define CHIP_ADC_0_TRIGGER_TIMER0_COMPARE_MATCH_A_ID                0x03
#define CHIP_ADC_0_TRIGGER_TIMER0_OVERFLOW_ID                       0x04
#define CHIP_ADC_0_TRIGGER_TIMER0_COMPARE_MATCH_B_ID                0x05
#define CHIP_ADC_0_TRIGGER_PIN_CHANGE_INT_0_ID                      0x06

#define CHIP_ADC_0_INT_FLAG_REG                                     CHIP_REG_ADCSRA
#define CHIP_ADC_0_INT_FLAG_BIT                                     4

#define CHIP_ADC_0_INT_ENABLE_REG                                   CHIP_REG_ADCSRA
#define CHIP_ADC_0_INT_ENABLE_BIT                                   3

#define CHIP_ADC_0_PRESCALER_REG                                    CHIP_REG_ADCSRA
#define CHIP_ADC_0_PRESCALER_MASK                                   0x07
#define CHIP_ADC_0_PRESCALER_2_ID                                   0x00
#define CHIP_ADC_0_PRESCALER_4_ID                                   0x02
#define CHIP_ADC_0_PRESCALER_8_ID                                   0x03
#define CHIP_ADC_0_PRESCALER_16_ID                                  0x04
#define CHIP_ADC_0_PRESCALER_32_ID                                  0x05
#define CHIP_ADC_0_PRESCALER_64_ID                                  0x06
#define CHIP_ADC_0_PRESCALER_128_ID                                 0x07

#define CHIP_ADC_0_BIPOLAR_MODE_REG                                 CHIP_REG_ADCSRB
#define CHIP_ADC_0_BIPOLAR_MODE_BIT                                 7

//------------------------------------------------
// External interrupts

#define CHIP_EXINT_0
#define CHIP_EXINT_0_ENABLE_REG                                     CHIP_REG_GIMSK
#define CHIP_EXINT_0_ENABLE_BIT                                     6
#define CHIP_EXINT_0_INT_FLAG_REG                                   CHIP_REG_GIFR
#define CHIP_EXINT_0_INT_FLAG_BIT                                   6
#define CHIP_EXINT_0_TRIGGER_REG                                    CHIP_REG_MCUCR
#define CHIP_EXINT_0_TRIGGER_MASK                                   0x03
#define CHIP_EXINT_0_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_0_TRIGGER_CHANGE_ID                              0x01
#define CHIP_EXINT_0_TRIGGER_FALLING_ID                             0x02
#define CHIP_EXINT_0_TRIGGER_RISING_ID                              0x03

//------------------------------------------------
// Pin change interrupts

#define CHIP_PCINT_0
#define CHIP_PCINT_0_ENABLE_REG                                     CHIP_REG_GIMSK
#define CHIP_PCINT_0_ENABLE_BIT                                     5
#define CHIP_PCINT_0_INT_FLAG_REG                                   CHIP_REG_GIFR
#define CHIP_PCINT_0_INT_FLAG_BIT                                   6
#define CHIP_PCINT_0_MASK_REG                                       CHIP_REG_PCMSK

//------------------------------------------------
// Timers

#define CHIP_TIMER_0

#define CHIP_TIMER_0_WAVEFORM_REG                                   CHIP_REG_TCCR0A
#define CHIP_TIMER_0_WAVEFORM_MASK                                  0x03
#define CHIP_TIMER_0_WAVEFORM_REG_EXTRA                             CHIP_REG_TCCR0B
#define CHIP_TIMER_0_WAVEFORM_MASK_EXTRA                            0x08
#define CHIP_TIMER_0_WAVEFORM_NORMAL_ID                             0x0000
#define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_ID                  0x0001
#define CHIP_TIMER_0_WAVEFORM_CTC_OCRA_ID                           0x0002
#define CHIP_TIMER_0_WAVEFORM_FAST_PWM_ID                           0x0003
#define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             0x0801
#define CHIP_TIMER_0_WAVEFORM_FAST_PWM_OCRA_ID                      0x0803

#define CHIP_TIMER_0_CLOCK_REG                                      CHIP_REG_TCCR0B
#define CHIP_TIMER_0_CLOCK_MASK                                     0x07
#define CHIP_TIMER_0_CLOCK_NONE_ID                                  0x00
#define CHIP_TIMER_0_CLOCK_1_ID                                     0x01
#define CHIP_TIMER_0_CLOCK_8_ID                                     0x02
#define CHIP_TIMER_0_CLOCK_64_ID                                    0x03
#define CHIP_TIMER_0_CLOCK_256_ID                                   0x04
#define CHIP_TIMER_0_CLOCK_1024_ID                                  0x05
#define CHIP_TIMER_0_CLOCK_EXT_FALLING_ID                           0x06
#define CHIP_TIMER_0_CLOCK_EXT_RISING_ID                            0x07

#define CHIP_TIMER_0_COUNTER_REG                                    CHIP_REG_TCNT0

#define CHIP_TIMER_0_PRESCALER_RESET_REG                            CHIP_REG_GTCCR
#define CHIP_TIMER_0_PRESCALER_RESET_BIT                            0

#define CHIP_TIMER_0_SYNCHRONIZE_REG                                CHIP_REG_GTCCR
#define CHIP_TIMER_0_SYNCHRONIZE_BIT                                7

#define CHIP_TIMER_0_COMPARE_A_REG                                  CHIP_REG_OCR0A
#define CHIP_TIMER_0_COMPARE_A_INT_ENABLE_REG                       CHIP_REG_TIMSK
#define CHIP_TIMER_0_COMPARE_A_INT_ENABLE_BIT                       4
#define CHIP_TIMER_0_COMPARE_A_INT_FLAG_REG                         CHIP_REG_TIFR
#define CHIP_TIMER_0_COMPARE_A_INT_FLAG_BIT                         4
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_REG                           CHIP_REG_TCCR0A
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_MASK                          0xC0
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_TOGGLE_ID                     0x40
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_CLEAR_ID                      0x80
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_SET_ID                        0xC0

#define CHIP_TIMER_0_COMPARE_B_REG                                  CHIP_REG_OCR0B
#define CHIP_TIMER_0_COMPARE_B_INT_ENABLE_REG                       CHIP_REG_TIMSK
#define CHIP_TIMER_0_COMPARE_B_INT_ENABLE_BIT                       3
#define CHIP_TIMER_0_COMPARE_B_INT_FLAG_REG                         CHIP_REG_TIFR
#define CHIP_TIMER_0_COMPARE_B_INT_FLAG_BIT                         3
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_REG                           CHIP_REG_TCCR0A
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_MASK                          0x30
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_TOGGLE_ID                     0x10
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_CLEAR_ID                      0x20
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_SET_ID                        0x30

#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                        1
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_BIT                          1

//------------------------------------------------

#define CHIP_TIMER_1

#define CHIP_TIMER_1_WAVEFORM_REG                                   CHIP_REG_TCCR1
#define CHIP_TIMER_1_WAVEFORM_MASK                                  0x80
#define CHIP_TIMER_1_WAVEFORM_NORMAL_ID                             0x00
#define CHIP_TIMER_1_WAVEFORM_CTC_OCRC_ID                           0x80

#define CHIP_TIMER_1_CLOCK_REG                                      CHIP_REG_TCCR1
#define CHIP_TIMER_1_CLOCK_MASK                                     0x0F
#define CHIP_TIMER_1_CLOCK_NONE_ID                                  0x00
#define CHIP_TIMER_1_CLOCK_1_ID                                     0x01
#define CHIP_TIMER_1_CLOCK_2_ID                                     0x02
#define CHIP_TIMER_1_CLOCK_4_ID                                     0x03
#define CHIP_TIMER_1_CLOCK_8_ID                                     0x04
#define CHIP_TIMER_1_CLOCK_16_ID                                    0x05
#define CHIP_TIMER_1_CLOCK_32_ID                                    0x06
#define CHIP_TIMER_1_CLOCK_64_ID                                    0x07
#define CHIP_TIMER_1_CLOCK_128_ID                                   0x08
#define CHIP_TIMER_1_CLOCK_256_ID                                   0x09
#define CHIP_TIMER_1_CLOCK_512_ID                                   0x0A
#define CHIP_TIMER_1_CLOCK_1024_ID                                  0x0B
#define CHIP_TIMER_1_CLOCK_2048_ID                                  0x0C
#define CHIP_TIMER_1_CLOCK_4096_ID                                  0x0D
#define CHIP_TIMER_1_CLOCK_8192_ID                                  0x0E
#define CHIP_TIMER_1_CLOCK_16384_ID                                 0x0F

#define CHIP_TIMER_1_COUNTER_REG                                    CHIP_REG_TCNT1

#define CHIP_TIMER_1_COMPARE_A_REG                                  CHIP_REG_OCR1A
#define CHIP_TIMER_1_COMPARE_A_INT_ENABLE_REG                       CHIP_REG_TIMSK
#define CHIP_TIMER_1_COMPARE_A_INT_ENABLE_BIT                       6
#define CHIP_TIMER_1_COMPARE_A_INT_FLAG_REG                         CHIP_REG_TIFR
#define CHIP_TIMER_1_COMPARE_A_INT_FLAG_BIT                         6
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_REG                           CHIP_REG_TCCR1
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_MASK                          0x30
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_TOGGLE_ID                     0x10
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_CLEAR_ID                      0x20
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_SET_ID                        0x30
#define CHIP_TIMER_1_COMPARE_A_PWM_OUTPUT_ENABLE_REG                CHIP_REG_TCCR1
#define CHIP_TIMER_1_COMPARE_A_PWM_OUTPUT_ENABLE_BIT                6

#define CHIP_TIMER_1_COMPARE_B_REG                                  CHIP_REG_OCR1B
#define CHIP_TIMER_1_COMPARE_B_INT_ENABLE_REG                       CHIP_REG_TIMSK
#define CHIP_TIMER_1_COMPARE_B_INT_ENABLE_BIT                       5
#define CHIP_TIMER_1_COMPARE_B_INT_FLAG_REG                         CHIP_REG_TIFR
#define CHIP_TIMER_1_COMPARE_B_INT_FLAG_BIT                         5
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_REG                           CHIP_REG_GTCCR
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_MASK                          0x30
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_TOGGLE_ID                     0x10
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_CLEAR_ID                      0x20
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_SET_ID                        0x30
#define CHIP_TIMER_1_COMPARE_B_PWM_OUTPUT_ENABLE_REG                CHIP_REG_GTCCR
#define CHIP_TIMER_1_COMPARE_B_PWM_OUTPUT_ENABLE_BIT                6

#define CHIP_TIMER_1_COMPARE_C_REG                                  CHIP_REG_OCR1C

#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                        2
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_BIT                          2

//------------------------------------------------
// Universal serial interfaces

#define CHIP_USI_0

#define CHIP_USI_0_DATA_REG                                         CHIP_REG_USIDR
#define CHIP_USI_0_BUFFER_REG                                       CHIP_REG_USIBR

#define CHIP_USI_0_START_CONDITION_INT_FLAG_REG                     CHIP_REG_USISR
#define CHIP_USI_0_START_CONDITION_INT_FLAG_BIT                     7

#define CHIP_USI_0_COUNTER_OVERFLOW_INT_FLAG_REG                    CHIP_REG_USISR
#define CHIP_USI_0_COUNTER_OVERFLOW_INT_FLAG_BIT                    6

#define CHIP_USI_0_STOP_CONDITION_INT_FLAG_REG                      CHIP_REG_USISR
#define CHIP_USI_0_STOP_CONDITION_INT_FLAG_BIT                      5

#define CHIP_USI_0_COLLISION_FLAG_REG                               CHIP_REG_USISR
#define CHIP_USI_0_COLLISION_FLAG_BIT                               4

#define CHIP_USI_0_COUNTER_REG                                      CHIP_REG_USISR
#define CHIP_USI_0_COUNTER_MASK                                     0x0F

#define CHIP_USI_0_START_CONDITION_INT_ENABLE_REG                   CHIP_REG_USICR
#define CHIP_USI_0_START_CONDITION_INT_ENABLE_BIT                   7

#define CHIP_USI_0_COUNTER_OVERFLOW_INT_ENABLE_REG                  CHIP_REG_USICR
#define CHIP_USI_0_COUNTER_OVERFLOW_INT_ENABLE_BIT                  6

#define CHIP_USI_0_WIRE_MODE_REG                                    CHIP_REG_USICR
#define CHIP_USI_0_WIRE_MODE_MASK                                   0x30
#define CHIP_USI_0_WIRE_MODE_DISABLED_ID                            0x00
#define CHIP_USI_0_WIRE_MODE_THREE_WIRE_ID                          0x10
#define CHIP_USI_0_WIRE_MODE_TWO_WIRE_ID                            0x20
#define CHIP_USI_0_WIRE_MODE_TWO_WIRE_OVERFLOW_ID                   0x30

#define CHIP_USI_0_CLOCK_SELECT_REG                                 CHIP_REG_USICR
#define CHIP_USI_0_CLOCK_SELECT_MASK                                0x0C
#define CHIP_USI_0_CLOCK_SELECT_NONE_ID                             0x00
#define CHIP_USI_0_CLOCK_SELECT_TIMER_0_COMPARE_MATCH_ID            0x04
#define CHIP_USI_0_CLOCK_SELECT_EXTERNAL_POSITIVE_EDGE_ID           0x08
#define CHIP_USI_0_CLOCK_SELECT_EXTERNAL_NEGATIVE_EDGE_ID           0x0C

#define CHIP_USI_0_CLOCK_STROBE_REG                                 CHIP_REG_USICR
#define CHIP_USI_0_CLOCK_STROBE_BIT                                 1

#define CHIP_USI_0_TOGGLE_CLOCK_PIN_REG                             CHIP_REG_USICR
#define CHIP_USI_0_TOGGLE_CLOCK_PIN_BIT                             0

#endif

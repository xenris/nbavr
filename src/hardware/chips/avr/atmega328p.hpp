#ifndef NBLIB_ATMEGA328P_HPP
#define NBLIB_ATMEGA328P_HPP

#define CHIP atmega328p

//------------------------------------------------
// Memory

#define CHIP_RAM_SIZE                                               (1024 * 2)

//------------------------------------------------
// Registers

#define CHIP_REG_PINB_ADDR                                          0x23
#define CHIP_REG_PINB_TYPE                                          uint8_t
#define CHIP_REG_DDRB_ADDR                                          0x24
#define CHIP_REG_DDRB_TYPE                                          uint8_t
#define CHIP_REG_PORTB_ADDR                                         0x25
#define CHIP_REG_PORTB_TYPE                                         uint8_t
#define CHIP_REG_PINC_ADDR                                          0x26
#define CHIP_REG_PINC_TYPE                                          uint8_t
#define CHIP_REG_DDRC_ADDR                                          0x27
#define CHIP_REG_DDRC_TYPE                                          uint8_t
#define CHIP_REG_PORTC_ADDR                                         0x28
#define CHIP_REG_PORTC_TYPE                                         uint8_t
#define CHIP_REG_PIND_ADDR                                          0x29
#define CHIP_REG_PIND_TYPE                                          uint8_t
#define CHIP_REG_DDRD_ADDR                                          0x2A
#define CHIP_REG_DDRD_TYPE                                          uint8_t
#define CHIP_REG_PORTD_ADDR                                         0x2B
#define CHIP_REG_PORTD_TYPE                                         uint8_t
#define CHIP_REG_TIFR0_ADDR                                         0x35
#define CHIP_REG_TIFR0_TYPE                                         uint8_t
#define CHIP_REG_TIFR1_ADDR                                         0x36
#define CHIP_REG_TIFR1_TYPE                                         uint8_t
#define CHIP_REG_TIFR2_ADDR                                         0x37
#define CHIP_REG_TIFR2_TYPE                                         uint8_t
#define CHIP_REG_PCIFR_ADDR                                         0x3B
#define CHIP_REG_PCIFR_TYPE                                         uint8_t
#define CHIP_REG_EIFR_ADDR                                          0x3C
#define CHIP_REG_EIFR_TYPE                                          uint8_t
#define CHIP_REG_EIMSK_ADDR                                         0x3D
#define CHIP_REG_EIMSK_TYPE                                         uint8_t
#define CHIP_REG_GPIOR0_ADDR                                        0x3E
#define CHIP_REG_GPIOR0_TYPE                                        uint8_t
#define CHIP_REG_EECR_ADDR                                          0x3F
#define CHIP_REG_EECR_TYPE                                          uint8_t
#define CHIP_REG_EEDR_ADDR                                          0x40
#define CHIP_REG_EEDR_TYPE                                          uint8_t
#define CHIP_REG_EEAR_ADDR                                          0x41
#define CHIP_REG_EEAR_TYPE                                          uint16_t
#define CHIP_REG_GTCCR_ADDR                                         0x43
#define CHIP_REG_GTCCR_TYPE                                         uint8_t
#define CHIP_REG_TCCR0A_ADDR                                        0x44
#define CHIP_REG_TCCR0A_TYPE                                        uint8_t
#define CHIP_REG_TCCR0B_ADDR                                        0x45
#define CHIP_REG_TCCR0B_TYPE                                        uint8_t
#define CHIP_REG_TCNT0_ADDR                                         0x46
#define CHIP_REG_TCNT0_TYPE                                         uint8_t
#define CHIP_REG_OCR0A_ADDR                                         0x47
#define CHIP_REG_OCR0A_TYPE                                         uint8_t
#define CHIP_REG_OCR0B_ADDR                                         0x48
#define CHIP_REG_OCR0B_TYPE                                         uint8_t
#define CHIP_REG_GPIOR1_ADDR                                        0x4A
#define CHIP_REG_GPIOR1_TYPE                                        uint8_t
#define CHIP_REG_GPIOR2_ADDR                                        0x4B
#define CHIP_REG_GPIOR2_TYPE                                        uint8_t
#define CHIP_REG_SPCR_ADDR                                          0x4C
#define CHIP_REG_SPCR_TYPE                                          uint8_t
#define CHIP_REG_SPSR_ADDR                                          0x4D
#define CHIP_REG_SPSR_TYPE                                          uint8_t
#define CHIP_REG_SPDR_ADDR                                          0x4E
#define CHIP_REG_SPDR_TYPE                                          uint8_t
#define CHIP_REG_ACSR_ADDR                                          0x50
#define CHIP_REG_ACSR_TYPE                                          uint8_t
#define CHIP_REG_SMCR_ADDR                                          0x53
#define CHIP_REG_SMCR_TYPE                                          uint8_t
#define CHIP_REG_MCUSR_ADDR                                         0x54
#define CHIP_REG_MCUSR_TYPE                                         uint8_t
#define CHIP_REG_MCUCR_ADDR                                         0x55
#define CHIP_REG_MCUCR_TYPE                                         uint8_t
#define CHIP_REG_SPMCSR_ADDR                                        0x57
#define CHIP_REG_SPMCSR_TYPE                                        uint8_t
#define CHIP_REG_SPL_ADDR                                           0x5D
#define CHIP_REG_SPL_TYPE                                           uint8_t
#define CHIP_REG_SPH_ADDR                                           0x5E
#define CHIP_REG_SPH_TYPE                                           uint8_t
#define CHIP_REG_SREG_ADDR                                          0x5F
#define CHIP_REG_SREG_TYPE                                          uint8_t
#define CHIP_REG_WDTCSR_ADDR                                        0x60
#define CHIP_REG_WDTCSR_TYPE                                        uint8_t
#define CHIP_REG_CLKPR_ADDR                                         0x61
#define CHIP_REG_CLKPR_TYPE                                         uint8_t
#define CHIP_REG_PRR_ADDR                                           0x64
#define CHIP_REG_PRR_TYPE                                           uint8_t
#define CHIP_REG_OSCCAL_ADDR                                        0x66
#define CHIP_REG_OSCCAL_TYPE                                        uint8_t
#define CHIP_REG_PCICR_ADDR                                         0x68
#define CHIP_REG_PCICR_TYPE                                         uint8_t
#define CHIP_REG_EICRA_ADDR                                         0x69
#define CHIP_REG_EICRA_TYPE                                         uint8_t
#define CHIP_REG_PCMSK0_ADDR                                        0x6B
#define CHIP_REG_PCMSK0_TYPE                                        uint8_t
#define CHIP_REG_PCMSK1_ADDR                                        0x6C
#define CHIP_REG_PCMSK1_TYPE                                        uint8_t
#define CHIP_REG_PCMSK2_ADDR                                        0x6D
#define CHIP_REG_PCMSK2_TYPE                                        uint8_t
#define CHIP_REG_TIMSK0_ADDR                                        0x6E
#define CHIP_REG_TIMSK0_TYPE                                        uint8_t
#define CHIP_REG_TIMSK1_ADDR                                        0x6F
#define CHIP_REG_TIMSK1_TYPE                                        uint8_t
#define CHIP_REG_TIMSK2_ADDR                                        0x70
#define CHIP_REG_TIMSK2_TYPE                                        uint8_t
#define CHIP_REG_ADC_ADDR                                           0x78
#define CHIP_REG_ADC_TYPE                                           uint16_t
#define CHIP_REG_ADCSRA_ADDR                                        0x7A
#define CHIP_REG_ADCSRA_TYPE                                        uint8_t
#define CHIP_REG_ADCSRB_ADDR                                        0x7B
#define CHIP_REG_ADCSRB_TYPE                                        uint8_t
#define CHIP_REG_ADMUX_ADDR                                         0x7C
#define CHIP_REG_ADMUX_TYPE                                         uint8_t
#define CHIP_REG_DIDR0_ADDR                                         0x7E
#define CHIP_REG_DIDR0_TYPE                                         uint8_t
#define CHIP_REG_DIDR1_ADDR                                         0x7F
#define CHIP_REG_DIDR1_TYPE                                         uint8_t
#define CHIP_REG_TCCR1A_ADDR                                        0x80
#define CHIP_REG_TCCR1A_TYPE                                        uint8_t
#define CHIP_REG_TCCR1B_ADDR                                        0x81
#define CHIP_REG_TCCR1B_TYPE                                        uint8_t
#define CHIP_REG_TCCR1C_ADDR                                        0x82
#define CHIP_REG_TCCR1C_TYPE                                        uint8_t
#define CHIP_REG_TCNT1L_ADDR                                        0x84
#define CHIP_REG_TCNT1L_TYPE                                        uint16_t
#define CHIP_REG_TCNT1H_ADDR                                        0x85
#define CHIP_REG_TCNT1H_TYPE                                        uint8_t
#define CHIP_REG_ICR1_ADDR                                          0x86
#define CHIP_REG_ICR1_TYPE                                          uint16_t
#define CHIP_REG_OCR1A_ADDR                                         0x88
#define CHIP_REG_OCR1A_TYPE                                         uint16_t
#define CHIP_REG_OCR1B_ADDR                                         0x8A
#define CHIP_REG_OCR1B_TYPE                                         uint16_t
#define CHIP_REG_TCCR2A_ADDR                                        0xB0
#define CHIP_REG_TCCR2A_TYPE                                        uint8_t
#define CHIP_REG_TCCR2B_ADDR                                        0xB1
#define CHIP_REG_TCCR2B_TYPE                                        uint8_t
#define CHIP_REG_TCNT2_ADDR                                         0xB2
#define CHIP_REG_TCNT2_TYPE                                         uint8_t
#define CHIP_REG_OCR2A_ADDR                                         0xB3
#define CHIP_REG_OCR2A_TYPE                                         uint8_t
#define CHIP_REG_OCR2B_ADDR                                         0xB4
#define CHIP_REG_OCR2B_TYPE                                         uint8_t
#define CHIP_REG_ASSR_ADDR                                          0xB6
#define CHIP_REG_ASSR_TYPE                                          uint8_t
#define CHIP_REG_TWBR_ADDR                                          0xB8
#define CHIP_REG_TWBR_TYPE                                          uint8_t
#define CHIP_REG_TWSR_ADDR                                          0xB9
#define CHIP_REG_TWSR_TYPE                                          uint8_t
#define CHIP_REG_TWAR_ADDR                                          0xBA
#define CHIP_REG_TWAR_TYPE                                          uint8_t
#define CHIP_REG_TWDR_ADDR                                          0xBB
#define CHIP_REG_TWDR_TYPE                                          uint8_t
#define CHIP_REG_TWCR_ADDR                                          0xBC
#define CHIP_REG_TWCR_TYPE                                          uint8_t
#define CHIP_REG_TWAMR_ADDR                                         0xBD
#define CHIP_REG_TWAMR_TYPE                                         uint8_t
#define CHIP_REG_UCSR0A_ADDR                                        0xC0
#define CHIP_REG_UCSR0A_TYPE                                        uint8_t
#define CHIP_REG_UCSR0B_ADDR                                        0xC1
#define CHIP_REG_UCSR0B_TYPE                                        uint8_t
#define CHIP_REG_UCSR0C_ADDR                                        0xC2
#define CHIP_REG_UCSR0C_TYPE                                        uint8_t
#define CHIP_REG_UBRR0_ADDR                                         0xC4
#define CHIP_REG_UBRR0_TYPE                                         uint16_t
#define CHIP_REG_UDR0_ADDR                                          0xC6
#define CHIP_REG_UDR0_TYPE                                          uint8_t

//------------------------------------------------
// Vectors

#define vectorInt0                                                  ISR(__vector_1)
#define vectorInt1                                                  ISR(__vector_2)
#define vectorPcInt0                                                ISR(__vector_3)
#define vectorPcInt1                                                ISR(__vector_4)
#define vectorPcInt2                                                ISR(__vector_5)
#define vectorWatchdogTimeout                                       ISR(__vector_6)
#define vectorTimer2CompareA                                        ISR(__vector_7)
#define vectorTimer2CompareB                                        ISR(__vector_8)
#define vectorTimer2Overflow                                        ISR(__vector_9)
#define vectorTimer1InputCapture                                    ISR(__vector_10)
#define vectorTimer1CompareA                                        ISR(__vector_11)
#define vectorTimer1CompareB                                        ISR(__vector_12)
#define vectorTimer1Overflow                                        ISR(__vector_13)
#define vectorTimer0CompareA                                        ISR(__vector_14)
#define vectorTimer0CompareB                                        ISR(__vector_15)
#define vectorTimer0Overflow                                        ISR(__vector_16)
#define vectorSpi0                                                  ISR(__vector_17)
#define vectorUsart0RxComplete                                      ISR(__vector_18)
#define vectorUsart0DataRegEmpty                                    ISR(__vector_19)
#define vectorUsart0TxComplete                                      ISR(__vector_20)
#define vectorAdc0                                                  ISR(__vector_21)
#define vectorEepromReady                                           ISR(__vector_22)
#define vectorAnalogComparator0                                     ISR(__vector_23)
#define vectorTwi0                                                  ISR(__vector_24)
#define vectorSpmReady                                              ISR(__vector_25)

//------------------------------------------------
// System

// Possibly need IDs for chips which have inhibit instead of enable.
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG                      CHIP_REG_SREG
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_BIT                      7

//------------------------------------------------
// Sleep

#define CHIP_SLEEP_MODE_IDLE_ID                                     0
#define CHIP_SLEEP_MODE_ADC_NOISE_REDUCTION_ID                      1
#define CHIP_SLEEP_MODE_POWER_DOWN_ID                               2
#define CHIP_SLEEP_MODE_POWER_SAVE_ID                               3
#define CHIP_SLEEP_MODE_STANDBY_ID                                  6
#define CHIP_SLEEP_MODE_EXTENDED_STANDBY_ID                         7

#define CHIP_SLEEP_MODE_BIT_0_BIT                                   1
#define CHIP_SLEEP_MODE_BIT_0_REG                                   CHIP_REG_SMCR
#define CHIP_SLEEP_MODE_BIT_1_BIT                                   2
#define CHIP_SLEEP_MODE_BIT_1_REG                                   CHIP_REG_SMCR
#define CHIP_SLEEP_MODE_BIT_2_BIT                                   3
#define CHIP_SLEEP_MODE_BIT_2_REG                                   CHIP_REG_SMCR

#define CHIP_SLEEP_ENABLE_BIT_0_BIT                                 0
#define CHIP_SLEEP_ENABLE_BIT_0_REG                                 CHIP_REG_SMCR


// //------------------------------------------------
// // Reset Status Register

// #define CHIP_RESET_STATUS_REG                                           CHIP_REG_MCUSR

// //------------------------------------------------
// // Watchdog Timer

// #define CHIP_WATCHDOG_TIMER_CONTROL_REG                                 CHIP_REG_WDTCSR
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

#define CHIP_PORT_C                                                 true
#define CHIP_PORT_C_OUTPUT_REG                                      CHIP_REG_PORTC
#define CHIP_PORT_C_TOGGLE_OUTPUTS_REG                              CHIP_REG_PINC
#define CHIP_PORT_C_INPUT_REG                                       CHIP_REG_PINC

#define CHIP_PORT_D                                                 true
#define CHIP_PORT_D_OUTPUT_REG                                      CHIP_REG_PORTD
#define CHIP_PORT_D_TOGGLE_OUTPUTS_REG                              CHIP_REG_PIND
#define CHIP_PORT_D_INPUT_REG                                       CHIP_REG_PIND

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
#define CHIP_PIN_B0_DIRECTION_BIT_0_BIT                             0
#define CHIP_PIN_B0_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
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
#define CHIP_PIN_B1_DIRECTION_BIT_0_BIT                             1
#define CHIP_PIN_B1_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
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
#define CHIP_PIN_B2_DIRECTION_BIT_0_BIT                             2
#define CHIP_PIN_B2_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
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
#define CHIP_PIN_B3_DIRECTION_BIT_0_BIT                             3
#define CHIP_PIN_B3_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
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
#define CHIP_PIN_B4_DIRECTION_BIT_0_BIT                             4
#define CHIP_PIN_B4_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
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
#define CHIP_PIN_B5_DIRECTION_BIT_0_BIT                             5
#define CHIP_PIN_B5_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_B5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_B5_INPUT_BIT_0_REG                                 CHIP_REG_PINB
#define CHIP_PIN_B5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_B5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTB
#define CHIP_PIN_B5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_B5_TOGGLE_BIT_0_REG                                CHIP_REG_PINB

#define CHIP_PIN_B6                                                 true
#define CHIP_PIN_B6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_B6_MODE_BIT_0_REG                                  CHIP_REG_DDRB
#define CHIP_PIN_B6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_B6_MODE_BIT_1_REG                                  CHIP_REG_PORTB
#define CHIP_PIN_B6_DIRECTION_BIT_0_BIT                             6
#define CHIP_PIN_B6_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_B6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_B6_INPUT_BIT_0_REG                                 CHIP_REG_PINB
#define CHIP_PIN_B6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_B6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTB
#define CHIP_PIN_B6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_B6_TOGGLE_BIT_0_REG                                CHIP_REG_PINB

#define CHIP_PIN_B7                                                 true
#define CHIP_PIN_B7_MODE_BIT_0_BIT                                  7
#define CHIP_PIN_B7_MODE_BIT_0_REG                                  CHIP_REG_DDRB
#define CHIP_PIN_B7_MODE_BIT_1_BIT                                  7
#define CHIP_PIN_B7_MODE_BIT_1_REG                                  CHIP_REG_PORTB
#define CHIP_PIN_B7_DIRECTION_BIT_0_BIT                             7
#define CHIP_PIN_B7_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_B7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_B7_INPUT_BIT_0_REG                                 CHIP_REG_PINB
#define CHIP_PIN_B7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_B7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTB
#define CHIP_PIN_B7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_B7_TOGGLE_BIT_0_REG                                CHIP_REG_PINB

#define CHIP_PIN_C0                                                 true
#define CHIP_PIN_C0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_C0_MODE_BIT_0_REG                                  CHIP_REG_DDRC
#define CHIP_PIN_C0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_C0_MODE_BIT_1_REG                                  CHIP_REG_PORTC
#define CHIP_PIN_C0_DIRECTION_BIT_0_BIT                             0
#define CHIP_PIN_C0_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_C0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_C0_INPUT_BIT_0_REG                                 CHIP_REG_PINC
#define CHIP_PIN_C0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_C0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTC
#define CHIP_PIN_C0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_C0_TOGGLE_BIT_0_REG                                CHIP_REG_PINC

#define CHIP_PIN_C1                                                 true
#define CHIP_PIN_C1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_C1_MODE_BIT_0_REG                                  CHIP_REG_DDRC
#define CHIP_PIN_C1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_C1_MODE_BIT_1_REG                                  CHIP_REG_PORTC
#define CHIP_PIN_C1_DIRECTION_BIT_0_BIT                             1
#define CHIP_PIN_C1_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_C1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_C1_INPUT_BIT_0_REG                                 CHIP_REG_PINC
#define CHIP_PIN_C1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_C1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTC
#define CHIP_PIN_C1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_C1_TOGGLE_BIT_0_REG                                CHIP_REG_PINC

#define CHIP_PIN_C2                                                 true
#define CHIP_PIN_C2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_C2_MODE_BIT_0_REG                                  CHIP_REG_DDRC
#define CHIP_PIN_C2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_C2_MODE_BIT_1_REG                                  CHIP_REG_PORTC
#define CHIP_PIN_C2_DIRECTION_BIT_0_BIT                             2
#define CHIP_PIN_C2_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_C2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_C2_INPUT_BIT_0_REG                                 CHIP_REG_PINC
#define CHIP_PIN_C2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_C2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTC
#define CHIP_PIN_C2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_C2_TOGGLE_BIT_0_REG                                CHIP_REG_PINC

#define CHIP_PIN_C3                                                 true
#define CHIP_PIN_C3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_C3_MODE_BIT_0_REG                                  CHIP_REG_DDRC
#define CHIP_PIN_C3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_C3_MODE_BIT_1_REG                                  CHIP_REG_PORTC
#define CHIP_PIN_C3_DIRECTION_BIT_0_BIT                             3
#define CHIP_PIN_C3_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_C3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_C3_INPUT_BIT_0_REG                                 CHIP_REG_PINC
#define CHIP_PIN_C3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_C3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTC
#define CHIP_PIN_C3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_C3_TOGGLE_BIT_0_REG                                CHIP_REG_PINC

#define CHIP_PIN_C4                                                 true
#define CHIP_PIN_C4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_C4_MODE_BIT_0_REG                                  CHIP_REG_DDRC
#define CHIP_PIN_C4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_C4_MODE_BIT_1_REG                                  CHIP_REG_PORTC
#define CHIP_PIN_C4_DIRECTION_BIT_0_BIT                             4
#define CHIP_PIN_C4_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_C4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_C4_INPUT_BIT_0_REG                                 CHIP_REG_PINC
#define CHIP_PIN_C4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_C4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTC
#define CHIP_PIN_C4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_C4_TOGGLE_BIT_0_REG                                CHIP_REG_PINC

#define CHIP_PIN_C5                                                 true
#define CHIP_PIN_C5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_C5_MODE_BIT_0_REG                                  CHIP_REG_DDRC
#define CHIP_PIN_C5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_C5_MODE_BIT_1_REG                                  CHIP_REG_PORTC
#define CHIP_PIN_C5_DIRECTION_BIT_0_BIT                             5
#define CHIP_PIN_C5_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_C5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_C5_INPUT_BIT_0_REG                                 CHIP_REG_PINC
#define CHIP_PIN_C5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_C5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTC
#define CHIP_PIN_C5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_C5_TOGGLE_BIT_0_REG                                CHIP_REG_PINC

#define CHIP_PIN_C6                                                 true
#define CHIP_PIN_C6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_C6_MODE_BIT_0_REG                                  CHIP_REG_DDRC
#define CHIP_PIN_C6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_C6_MODE_BIT_1_REG                                  CHIP_REG_PORTC
#define CHIP_PIN_C6_DIRECTION_BIT_0_BIT                             6
#define CHIP_PIN_C6_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_C6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_C6_INPUT_BIT_0_REG                                 CHIP_REG_PINC
#define CHIP_PIN_C6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_C6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTC
#define CHIP_PIN_C6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_C6_TOGGLE_BIT_0_REG                                CHIP_REG_PINC

#define CHIP_PIN_D0                                                 true
#define CHIP_PIN_D0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_D0_MODE_BIT_0_REG                                  CHIP_REG_DDRD
#define CHIP_PIN_D0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_D0_MODE_BIT_1_REG                                  CHIP_REG_PORTD
#define CHIP_PIN_D0_DIRECTION_BIT_0_BIT                             0
#define CHIP_PIN_D0_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_D0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_D0_INPUT_BIT_0_REG                                 CHIP_REG_PIND
#define CHIP_PIN_D0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_D0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTD
#define CHIP_PIN_D0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_D0_TOGGLE_BIT_0_REG                                CHIP_REG_PIND

#define CHIP_PIN_D1                                                 true
#define CHIP_PIN_D1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_D1_MODE_BIT_0_REG                                  CHIP_REG_DDRD
#define CHIP_PIN_D1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_D1_MODE_BIT_1_REG                                  CHIP_REG_PORTD
#define CHIP_PIN_D1_DIRECTION_BIT_0_BIT                             1
#define CHIP_PIN_D1_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_D1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_D1_INPUT_BIT_0_REG                                 CHIP_REG_PIND
#define CHIP_PIN_D1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_D1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTD
#define CHIP_PIN_D1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_D1_TOGGLE_BIT_0_REG                                CHIP_REG_PIND

#define CHIP_PIN_D2                                                 true
#define CHIP_PIN_D2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_D2_MODE_BIT_0_REG                                  CHIP_REG_DDRD
#define CHIP_PIN_D2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_D2_MODE_BIT_1_REG                                  CHIP_REG_PORTD
#define CHIP_PIN_D2_DIRECTION_BIT_0_BIT                             2
#define CHIP_PIN_D2_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_D2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_D2_INPUT_BIT_0_REG                                 CHIP_REG_PIND
#define CHIP_PIN_D2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_D2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTD
#define CHIP_PIN_D2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_D2_TOGGLE_BIT_0_REG                                CHIP_REG_PIND

#define CHIP_PIN_D3                                                 true
#define CHIP_PIN_D3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_D3_MODE_BIT_0_REG                                  CHIP_REG_DDRD
#define CHIP_PIN_D3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_D3_MODE_BIT_1_REG                                  CHIP_REG_PORTD
#define CHIP_PIN_D3_DIRECTION_BIT_0_BIT                             3
#define CHIP_PIN_D3_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_D3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_D3_INPUT_BIT_0_REG                                 CHIP_REG_PIND
#define CHIP_PIN_D3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_D3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTD
#define CHIP_PIN_D3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_D3_TOGGLE_BIT_0_REG                                CHIP_REG_PIND

#define CHIP_PIN_D4                                                 true
#define CHIP_PIN_D4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_D4_MODE_BIT_0_REG                                  CHIP_REG_DDRD
#define CHIP_PIN_D4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_D4_MODE_BIT_1_REG                                  CHIP_REG_PORTD
#define CHIP_PIN_D4_DIRECTION_BIT_0_BIT                             4
#define CHIP_PIN_D4_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_D4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_D4_INPUT_BIT_0_REG                                 CHIP_REG_PIND
#define CHIP_PIN_D4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_D4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTD
#define CHIP_PIN_D4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_D4_TOGGLE_BIT_0_REG                                CHIP_REG_PIND

#define CHIP_PIN_D5                                                 true
#define CHIP_PIN_D5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_D5_MODE_BIT_0_REG                                  CHIP_REG_DDRD
#define CHIP_PIN_D5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_D5_MODE_BIT_1_REG                                  CHIP_REG_PORTD
#define CHIP_PIN_D5_DIRECTION_BIT_0_BIT                             5
#define CHIP_PIN_D5_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_D5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_D5_INPUT_BIT_0_REG                                 CHIP_REG_PIND
#define CHIP_PIN_D5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_D5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTD
#define CHIP_PIN_D5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_D5_TOGGLE_BIT_0_REG                                CHIP_REG_PIND

#define CHIP_PIN_D6                                                 true
#define CHIP_PIN_D6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_D6_MODE_BIT_0_REG                                  CHIP_REG_DDRD
#define CHIP_PIN_D6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_D6_MODE_BIT_1_REG                                  CHIP_REG_PORTD
#define CHIP_PIN_D6_DIRECTION_BIT_0_BIT                             6
#define CHIP_PIN_D6_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_D6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_D6_INPUT_BIT_0_REG                                 CHIP_REG_PIND
#define CHIP_PIN_D6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_D6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTD
#define CHIP_PIN_D6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_D6_TOGGLE_BIT_0_REG                                CHIP_REG_PIND

#define CHIP_PIN_D7                                                 true
#define CHIP_PIN_D7_MODE_BIT_0_BIT                                  7
#define CHIP_PIN_D7_MODE_BIT_0_REG                                  CHIP_REG_DDRD
#define CHIP_PIN_D7_MODE_BIT_1_BIT                                  7
#define CHIP_PIN_D7_MODE_BIT_1_REG                                  CHIP_REG_PORTD
#define CHIP_PIN_D7_DIRECTION_BIT_0_BIT                             7
#define CHIP_PIN_D7_DIRECTION_BIT_0_REG                             CHIP_REG_PORTB
#define CHIP_PIN_D7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_D7_INPUT_BIT_0_REG                                 CHIP_REG_PIND
#define CHIP_PIN_D7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_D7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTD
#define CHIP_PIN_D7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_D7_TOGGLE_BIT_0_REG                                CHIP_REG_PIND

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
#define CHIP_ADC_0_REFERENCE_BIT_0_BIT                              6
#define CHIP_ADC_0_REFERENCE_BIT_1_BIT                              7
#define CHIP_ADC_0_REFERENCE_AREF_ID                                0
#define CHIP_ADC_0_REFERENCE_AVCC_ID                                1
#define CHIP_ADC_0_REFERENCE_INTERNAL_ID                            3

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
#define CHIP_ADC_0_CHANNEL_4_ID                                     4
#define CHIP_ADC_0_CHANNEL_5_ID                                     5
#define CHIP_ADC_0_CHANNEL_6_ID                                     6
#define CHIP_ADC_0_CHANNEL_7_ID                                     7
#define CHIP_ADC_0_CHANNEL_8_ID                                     8
#define CHIP_ADC_0_CHANNEL_VBG_ID                                   14
#define CHIP_ADC_0_CHANNEL_GND_ID                                   15

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
#define CHIP_ADC_0_TRIGGER_TIMER1_COMPARE_MATCH_B_ID                13
#define CHIP_ADC_0_TRIGGER_TIMER1_OVERFLOW_ID                       14
#define CHIP_ADC_0_TRIGGER_TIMER1_CAPTURE_EVENT_ID                  15

#define CHIP_ADC_0_INT_FLAG_IMPURE                                  true
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
#define CHIP_EXINT_0_ENABLE_BIT_0_REG                               CHIP_REG_EIMSK
#define CHIP_EXINT_0_ENABLE_BIT_0_BIT                               0
#define CHIP_EXINT_0_INT_FLAG_BIT_0_REG                             CHIP_REG_EIFR
#define CHIP_EXINT_0_INT_FLAG_BIT_0_BIT                             0
#define CHIP_EXINT_0_TRIGGER_BIT_0_REG                              CHIP_REG_EICRA
#define CHIP_EXINT_0_TRIGGER_BIT_1_REG                              CHIP_REG_EICRA
#define CHIP_EXINT_0_TRIGGER_BIT_0_BIT                              0
#define CHIP_EXINT_0_TRIGGER_BIT_1_BIT                              1
#define CHIP_EXINT_0_TRIGGER_LOW_ID                                 0
#define CHIP_EXINT_0_TRIGGER_CHANGE_ID                              1
#define CHIP_EXINT_0_TRIGGER_FALLING_ID                             2
#define CHIP_EXINT_0_TRIGGER_RISING_ID                              3
#define CHIP_EXINT_0_INT_VECTOR                                     VECT(CHIP_VECT_INT0)

#define CHIP_EXINT_1                                                true
#define CHIP_EXINT_1_ENABLE_BIT_0_REG                               CHIP_REG_EIMSK
#define CHIP_EXINT_1_ENABLE_BIT_0_BIT                               1
#define CHIP_EXINT_1_INT_FLAG_BIT_0_REG                             CHIP_REG_EIFR
#define CHIP_EXINT_1_INT_FLAG_BIT_0_BIT                             1
#define CHIP_EXINT_1_TRIGGER_BIT_0_REG                              CHIP_REG_EICRA
#define CHIP_EXINT_1_TRIGGER_BIT_1_REG                              CHIP_REG_EICRA
#define CHIP_EXINT_1_TRIGGER_BIT_0_BIT                              2
#define CHIP_EXINT_1_TRIGGER_BIT_1_BIT                              3
#define CHIP_EXINT_1_TRIGGER_LOW_ID                                 0
#define CHIP_EXINT_1_TRIGGER_CHANGE_ID                              1
#define CHIP_EXINT_1_TRIGGER_FALLING_ID                             2
#define CHIP_EXINT_1_TRIGGER_RISING_ID                              3
#define CHIP_EXINT_1_INT_VECTOR                                     VECT(CHIP_VECT_INT1)

//------------------------------------------------
// Pin change interrupts

#define CHIP_PCINT_0                                                true
#define CHIP_PCINT_0_ENABLE_BIT_0_REG                               CHIP_REG_PCICR
#define CHIP_PCINT_0_ENABLE_BIT_0_BIT                               0
#define CHIP_PCINT_0_INT_FLAG_BIT_0_REG                             CHIP_REG_PCIFR
#define CHIP_PCINT_0_INT_FLAG_BIT_0_BIT                             0
#define CHIP_PCINT_0_MASK_REG                                       CHIP_REG_PCMSK0
#define CHIP_PCINT_0_INT_VECTOR                                     VECT(CHIP_VECT_PCINT0)

#define CHIP_PCINT_1                                                true
#define CHIP_PCINT_1_ENABLE_BIT_0_REG                               CHIP_REG_PCICR
#define CHIP_PCINT_1_ENABLE_BIT_0_BIT                               1
#define CHIP_PCINT_1_INT_FLAG_BIT_0_REG                             CHIP_REG_PCIFR
#define CHIP_PCINT_1_INT_FLAG_BIT_0_BIT                             1
#define CHIP_PCINT_1_MASK_REG                                       CHIP_REG_PCMSK1
#define CHIP_PCINT_1_INT_VECTOR                                     VECT(CHIP_VECT_PCINT1)

#define CHIP_PCINT_2                                                true
#define CHIP_PCINT_2_ENABLE_BIT_0_REG                               CHIP_REG_PCICR
#define CHIP_PCINT_2_ENABLE_BIT_0_BIT                               2
#define CHIP_PCINT_2_INT_FLAG_BIT_0_REG                             CHIP_REG_PCIFR
#define CHIP_PCINT_2_INT_FLAG_BIT_0_BIT                             2
#define CHIP_PCINT_2_MASK_REG                                       CHIP_REG_PCMSK2
#define CHIP_PCINT_2_INT_VECTOR                                     VECT(CHIP_VECT_PCINT2)

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

#define CHIP_TIMER_0_CLOCK_BIT_0_REG                                CHIP_REG_TCCR0B
#define CHIP_TIMER_0_CLOCK_BIT_1_REG                                CHIP_REG_TCCR0B
#define CHIP_TIMER_0_CLOCK_BIT_2_REG                                CHIP_REG_TCCR0B
#define CHIP_TIMER_0_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_0_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_0_CLOCK_BIT_2_BIT                                2
#define CHIP_TIMER_0_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_0_CLOCK_1_ID                                     1
#define CHIP_TIMER_0_CLOCK_8_ID                                     2
#define CHIP_TIMER_0_CLOCK_64_ID                                    3
#define CHIP_TIMER_0_CLOCK_256_ID                                   4
#define CHIP_TIMER_0_CLOCK_1024_ID                                  5
#define CHIP_TIMER_0_CLOCK_EXT_FALLING_ID                           6
#define CHIP_TIMER_0_CLOCK_EXT_RISING_ID                            7

#define CHIP_TIMER_0_COUNTER_REG                                    CHIP_REG_TCNT0

#define CHIP_TIMER_0_PRESCALER_RESET_REG                            CHIP_REG_GTCCR
#define CHIP_TIMER_0_PRESCALER_RESET_BIT                            0
#define CHIP_TIMER_0_SYNCHRONIZE_REG                                CHIP_REG_GTCCR
#define CHIP_TIMER_0_SYNCHRONIZE_BIT                                7

#define CHIP_TIMER_0_OUTPUT_A                                       true
#define CHIP_TIMER_0_OUTPUT_A_PIN                                   PortD::Pin6
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_0_REG                        CHIP_REG_TCCR0A
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_1_REG                        CHIP_REG_TCCR0A
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_0_BIT                        6
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_1_BIT                        7
#define CHIP_TIMER_0_OUTPUT_A_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_0_OUTPUT_A_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_0_OUTPUT_A_MODE_CLEAR_ID                         2
#define CHIP_TIMER_0_OUTPUT_A_MODE_SET_ID                           3
#define CHIP_TIMER_0_OUTPUT_A_REG                                   CHIP_REG_OCR0A
#define CHIP_TIMER_0_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK0
#define CHIP_TIMER_0_OUTPUT_A_INT_ENABLE_BIT                        1
#define CHIP_TIMER_0_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR0
#define CHIP_TIMER_0_OUTPUT_A_INT_FLAG_BIT                          1
#define CHIP_TIMER_0_OUTPUT_A_INT_VECTOR                            VECT(CHIP_VECT_TIMER0_COMPA)

#define CHIP_TIMER_0_OUTPUT_B                                       true
#define CHIP_TIMER_0_OUTPUT_B_PIN                                   PortD::Pin5
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_0_REG                        CHIP_REG_TCCR0A
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_1_REG                        CHIP_REG_TCCR0A
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_0_BIT                        4
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_1_BIT                        5
#define CHIP_TIMER_0_OUTPUT_B_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_0_OUTPUT_B_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_0_OUTPUT_B_MODE_CLEAR_ID                         2
#define CHIP_TIMER_0_OUTPUT_B_MODE_SET_ID                           3
#define CHIP_TIMER_0_OUTPUT_B_REG                                   CHIP_REG_OCR0B
#define CHIP_TIMER_0_OUTPUT_B_INT_ENABLE_REG                        CHIP_REG_TIMSK0
#define CHIP_TIMER_0_OUTPUT_B_INT_ENABLE_BIT                        2
#define CHIP_TIMER_0_OUTPUT_B_INT_FLAG_REG                          CHIP_REG_TIFR0
#define CHIP_TIMER_0_OUTPUT_B_INT_FLAG_BIT                          2
#define CHIP_TIMER_0_OUTPUT_B_INT_VECTOR                            VECT(CHIP_VECT_TIMER0_COMPB)

#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK0
#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR0
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_BIT                          0
#define CHIP_TIMER_0_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER0_OVF)

//------------------------------------------------

#define CHIP_TIMER_1                                                true

#define CHIP_TIMER_1_TYPE                                           uint16_t

#define CHIP_TIMER_1_WAVEFORM                                       true
#define CHIP_TIMER_1_WAVEFORM_NORMAL_ID                             0
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_8_ID                1
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_9_ID                2
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_10_ID               3
#define CHIP_TIMER_1_WAVEFORM_CTC_OCRA_ID                           4
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_8_ID                         5
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_9_ID                         6
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_10_ID                        7
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID             8
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID        9
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_ID                  10
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             11
#define CHIP_TIMER_1_WAVEFORM_CTC_ICR_ID                            12
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_ID                           14
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_OCRA_ID                      15
#define CHIP_TIMER_1_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR1A
#define CHIP_TIMER_1_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR1A
#define CHIP_TIMER_1_WAVEFORM_BIT_2_REG                             CHIP_REG_TCCR1B
#define CHIP_TIMER_1_WAVEFORM_BIT_3_REG                             CHIP_REG_TCCR1B
#define CHIP_TIMER_1_WAVEFORM_BIT_0_BIT                             0
#define CHIP_TIMER_1_WAVEFORM_BIT_1_BIT                             1
#define CHIP_TIMER_1_WAVEFORM_BIT_2_BIT                             3
#define CHIP_TIMER_1_WAVEFORM_BIT_3_BIT                             4

#define CHIP_TIMER_1_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_1_CLOCK_1_ID                                     1
#define CHIP_TIMER_1_CLOCK_8_ID                                     2
#define CHIP_TIMER_1_CLOCK_64_ID                                    3
#define CHIP_TIMER_1_CLOCK_256_ID                                   4
#define CHIP_TIMER_1_CLOCK_1024_ID                                  5
#define CHIP_TIMER_1_CLOCK_EXT_FALLING_ID                           6
#define CHIP_TIMER_1_CLOCK_EXT_RISING_ID                            7
#define CHIP_TIMER_1_CLOCK_BIT_0_REG                                CHIP_REG_TCCR1B
#define CHIP_TIMER_1_CLOCK_BIT_1_REG                                CHIP_REG_TCCR1B
#define CHIP_TIMER_1_CLOCK_BIT_2_REG                                CHIP_REG_TCCR1B
#define CHIP_TIMER_1_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_1_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_1_CLOCK_BIT_2_BIT                                2

#define CHIP_TIMER_1_COUNTER_REG                                    CHIP_REG_TCNT1L

#define CHIP_TIMER_1_PRESCALER_RESET_REG                            CHIP_REG_GTCCR
#define CHIP_TIMER_1_PRESCALER_RESET_BIT                            0
#define CHIP_TIMER_1_SYNCHRONIZE_REG                                CHIP_REG_GTCCR
#define CHIP_TIMER_1_SYNCHRONIZE_BIT                                7

#define CHIP_TIMER_1_OUTPUT_A                                       true
#define CHIP_TIMER_1_OUTPUT_A_PIN                                   PortB::Pin1
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_0_REG                        CHIP_REG_TCCR1A
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_1_REG                        CHIP_REG_TCCR1A
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_0_BIT                        6
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_1_BIT                        7
#define CHIP_TIMER_1_OUTPUT_A_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_1_OUTPUT_A_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_1_OUTPUT_A_MODE_CLEAR_ID                         2
#define CHIP_TIMER_1_OUTPUT_A_MODE_SET_ID                           3
#define CHIP_TIMER_1_OUTPUT_A_REG                                   CHIP_REG_OCR1A
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK1
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_BIT                        1
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR1
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_BIT                          1
#define CHIP_TIMER_1_OUTPUT_A_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_COMPA)

#define CHIP_TIMER_1_OUTPUT_B                                       true
#define CHIP_TIMER_1_OUTPUT_B_PIN                                   PortB::Pin2
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_0_REG                        CHIP_REG_TCCR1A
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_1_REG                        CHIP_REG_TCCR1A
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_0_BIT                        4
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_1_BIT                        5
#define CHIP_TIMER_1_OUTPUT_B_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_1_OUTPUT_B_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_1_OUTPUT_B_MODE_CLEAR_ID                         2
#define CHIP_TIMER_1_OUTPUT_B_MODE_SET_ID                           3
#define CHIP_TIMER_1_OUTPUT_B_REG                                   CHIP_REG_OCR1B
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_REG                        CHIP_REG_TIMSK1
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_BIT                        2
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_REG                          CHIP_REG_TIFR1
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_BIT                          2
#define CHIP_TIMER_1_OUTPUT_B_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_COMPB)

#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK1
#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR1
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_BIT                          0
#define CHIP_TIMER_1_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_OVF)

#define CHIP_TIMER_1_INPUT                                          true
#define CHIP_TIMER_1_INPUT_REG                                      CHIP_REG_ICR1
#define CHIP_TIMER_1_INPUT_PIN                                      PortB::Pin0
#define CHIP_TIMER_1_INPUT_NOISE_CANCELER_REG                       CHIP_REG_TCCR1B
#define CHIP_TIMER_1_INPUT_NOISE_CANCELER_BIT                       7
#define CHIP_TIMER_1_INPUT_EDGE_SELECT_REG                          CHIP_REG_TCCR1B
#define CHIP_TIMER_1_INPUT_EDGE_SELECT_BIT                          6
#define CHIP_TIMER_1_INPUT_EDGE_FALLING_ID                          0
#define CHIP_TIMER_1_INPUT_EDGE_RISING_ID                           1
#define CHIP_TIMER_1_INPUT_INT_ENABLE_REG                           CHIP_REG_TIMSK1
#define CHIP_TIMER_1_INPUT_INT_ENABLE_BIT                           5
#define CHIP_TIMER_1_INPUT_INT_FLAG_REG                             CHIP_REG_TIFR1
#define CHIP_TIMER_1_INPUT_INT_FLAG_BIT                             5
#define CHIP_TIMER_1_INPUT_INT_VECTOR                               VECT(CHIP_VECT_TIMER1_CAPT)

//------------------------------------------------

#define CHIP_TIMER_2                                                true

#define CHIP_TIMER_2_TYPE                                           uint8_t

#define CHIP_TIMER_2_WAVEFORM                                       true
#define CHIP_TIMER_2_WAVEFORM_NORMAL_ID                             0
#define CHIP_TIMER_2_WAVEFORM_PWM_PHASE_CORRECT_ID                  1
#define CHIP_TIMER_2_WAVEFORM_CTC_OCRA_ID                           2
#define CHIP_TIMER_2_WAVEFORM_FAST_PWM_ID                           3
#define CHIP_TIMER_2_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             5
#define CHIP_TIMER_2_WAVEFORM_FAST_PWM_OCRA_ID                      7
#define CHIP_TIMER_2_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR2A
#define CHIP_TIMER_2_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR2A
#define CHIP_TIMER_2_WAVEFORM_BIT_2_REG                             CHIP_REG_TCCR2B
#define CHIP_TIMER_2_WAVEFORM_BIT_0_BIT                             0
#define CHIP_TIMER_2_WAVEFORM_BIT_1_BIT                             1
#define CHIP_TIMER_2_WAVEFORM_BIT_2_BIT                             3

#define CHIP_TIMER_2_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_2_CLOCK_1_ID                                     1
#define CHIP_TIMER_2_CLOCK_8_ID                                     2
#define CHIP_TIMER_2_CLOCK_32_ID                                    3
#define CHIP_TIMER_2_CLOCK_64_ID                                    4
#define CHIP_TIMER_2_CLOCK_128_ID                                   5
#define CHIP_TIMER_2_CLOCK_256_ID                                   6
#define CHIP_TIMER_2_CLOCK_1024_ID                                  7
#define CHIP_TIMER_2_CLOCK_BIT_0_REG                                CHIP_REG_TCCR2B
#define CHIP_TIMER_2_CLOCK_BIT_1_REG                                CHIP_REG_TCCR2B
#define CHIP_TIMER_2_CLOCK_BIT_2_REG                                CHIP_REG_TCCR2B
#define CHIP_TIMER_2_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_2_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_2_CLOCK_BIT_2_BIT                                2

#define CHIP_TIMER_2_COUNTER_REG                                    CHIP_REG_TCNT2

#define CHIP_TIMER_2_PRESCALER_RESET_REG                            CHIP_REG_GTCCR
#define CHIP_TIMER_2_PRESCALER_RESET_BIT                            1
#define CHIP_TIMER_2_SYNCHRONIZE_REG                                CHIP_REG_GTCCR
#define CHIP_TIMER_2_SYNCHRONIZE_BIT                                7

#define CHIP_TIMER_2_OUTPUT_A                                       true
#define CHIP_TIMER_2_OUTPUT_A_PIN                                   PortB::Pin3
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_0_REG                        CHIP_REG_TCCR2A
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_1_REG                        CHIP_REG_TCCR2A
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_0_BIT                        6
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_1_BIT                        7
#define CHIP_TIMER_2_OUTPUT_A_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_2_OUTPUT_A_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_2_OUTPUT_A_MODE_CLEAR_ID                         2
#define CHIP_TIMER_2_OUTPUT_A_MODE_SET_ID                           3
#define CHIP_TIMER_2_OUTPUT_A_REG                                   CHIP_REG_OCR2A
#define CHIP_TIMER_2_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK2
#define CHIP_TIMER_2_OUTPUT_A_INT_ENABLE_BIT                        1
#define CHIP_TIMER_2_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR2
#define CHIP_TIMER_2_OUTPUT_A_INT_FLAG_BIT                          1
#define CHIP_TIMER_2_OUTPUT_A_INT_VECTOR                            VECT(CHIP_VECT_TIMER2_COMPA)

#define CHIP_TIMER_2_OUTPUT_B                                       true
#define CHIP_TIMER_2_OUTPUT_B_PIN                                   PortD::Pin3
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_0_REG                        CHIP_REG_TCCR2A
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_1_REG                        CHIP_REG_TCCR2A
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_0_BIT                        4
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_1_BIT                        5
#define CHIP_TIMER_2_OUTPUT_B_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_2_OUTPUT_B_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_2_OUTPUT_B_MODE_CLEAR_ID                         2
#define CHIP_TIMER_2_OUTPUT_B_MODE_SET_ID                           3
#define CHIP_TIMER_2_OUTPUT_B_REG                                   CHIP_REG_OCR2B
#define CHIP_TIMER_2_OUTPUT_B_INT_ENABLE_REG                        CHIP_REG_TIMSK2
#define CHIP_TIMER_2_OUTPUT_B_INT_ENABLE_BIT                        2
#define CHIP_TIMER_2_OUTPUT_B_INT_FLAG_REG                          CHIP_REG_TIFR2
#define CHIP_TIMER_2_OUTPUT_B_INT_FLAG_BIT                          2
#define CHIP_TIMER_2_OUTPUT_B_INT_VECTOR                            VECT(CHIP_VECT_TIMER2_COMPB)

#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK2
#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR2
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_BIT                          0
#define CHIP_TIMER_2_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER2_OVF)

//------------------------------------------------
// Usarts

#define CHIP_USART_0                                                true

#define CHIP_USART_0_DATA_REG                                       CHIP_REG_UDR0

#define CHIP_USART_0_BAUD_RATE_REG                                  CHIP_REG_UBRR0

#define CHIP_USART_0_FRAME_ERROR_BIT_0_REG                          CHIP_REG_UCSR0A
#define CHIP_USART_0_FRAME_ERROR_BIT_0_BIT                          4
#define CHIP_USART_0_DATA_OVERRUN_BIT_0_REG                         CHIP_REG_UCSR0A
#define CHIP_USART_0_DATA_OVERRUN_BIT_0_BIT                         3
#define CHIP_USART_0_PARITY_ERROR_BIT_0_REG                         CHIP_REG_UCSR0A
#define CHIP_USART_0_PARITY_ERROR_BIT_0_BIT                         2

#define CHIP_USART_0_DOUBLE_SPEED_BIT_0_REG                         CHIP_REG_UCSR0A
#define CHIP_USART_0_DOUBLE_SPEED_BIT_0_BIT                         1

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT_0_REG        CHIP_REG_UCSR0A
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT        0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_UCSR0B
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT_0_BIT               7
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_UCSR0B
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT_0_BIT               6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT_0_REG            CHIP_REG_UCSR0B
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT            5

#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_BIT_0_REG                 CHIP_REG_UCSR0A
#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_BIT_0_BIT                 7
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_BIT_0_REG                 CHIP_REG_UCSR0A
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_BIT_0_BIT                 6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_BIT_0_REG              CHIP_REG_UCSR0A
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_BIT_0_BIT              5

#define CHIP_USART_0_RX_ENABLE_BIT_0_REG                            CHIP_REG_UCSR0B
#define CHIP_USART_0_RX_ENABLE_BIT_0_BIT                            4
#define CHIP_USART_0_TX_ENABLE_BIT_0_REG                            CHIP_REG_UCSR0B
#define CHIP_USART_0_TX_ENABLE_BIT_0_BIT                            3

#define CHIP_USART_0_RX_DATA_BIT_8_REG                              CHIP_REG_UCSR0B
#define CHIP_USART_0_RX_DATA_BIT_8_BIT                              1
#define CHIP_USART_0_TX_DATA_BIT_8_REG                              CHIP_REG_UCSR0B
#define CHIP_USART_0_TX_DATA_BIT_8_BIT                              0

#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                           0
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                            1
#define CHIP_USART_0_MODE_MASTER_SPI_ID                             3
#define CHIP_USART_0_MODE_BIT_0_REG                                 CHIP_REG_UCSR0C
#define CHIP_USART_0_MODE_BIT_1_REG                                 CHIP_REG_UCSR0C
#define CHIP_USART_0_MODE_BIT_0_BIT                                 6
#define CHIP_USART_0_MODE_BIT_1_BIT                                 7

#define CHIP_USART_0_PARITY_DISABLE_ID                              0
#define CHIP_USART_0_PARITY_EVEN_ID                                 2
#define CHIP_USART_0_PARITY_ODD_ID                                  3
#define CHIP_USART_0_PARITY_BIT_0_REG                               CHIP_REG_UCSR0C
#define CHIP_USART_0_PARITY_BIT_1_REG                               CHIP_REG_UCSR0C
#define CHIP_USART_0_PARITY_BIT_0_BIT                               4
#define CHIP_USART_0_PARITY_BIT_1_BIT                               5

#define CHIP_USART_0_STOP_BITS_1_ID                                 0
#define CHIP_USART_0_STOP_BITS_2_ID                                 1
#define CHIP_USART_0_STOP_BITS_BIT_0_REG                            CHIP_REG_UCSR0C
#define CHIP_USART_0_STOP_BITS_BIT_0_BIT                            3

#define CHIP_USART_0_CHARACTER_SIZE_5_ID                            0
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                            1
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                            2
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                            3
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                            7
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_REG                       CHIP_REG_UCSR0C
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_REG                       CHIP_REG_UCSR0C
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_REG                       CHIP_REG_UCSR0B
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_BIT                       1
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_BIT                       2
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_BIT                       2

#define CHIP_USART_0_POLARITY_TX_RISING_RX_FALLING_ID               0
#define CHIP_USART_0_POLARITY_TX_FALLING_RX_RISING_ID               1
#define CHIP_USART_0_POLARITY_BIT_0_REG                             CHIP_REG_UCSR0C
#define CHIP_USART_0_POLARITY_BIT_0_BIT                             0

#define CHIP_USART_0_RX_INT_VECTOR                                  VECT(CHIP_VECT_USART_RX)
#define CHIP_USART_0_DE_INT_VECTOR                                  VECT(CHIP_VECT_USART_UDRE)
#define CHIP_USART_0_TX_INT_VECTOR                                  VECT(CHIP_VECT_USART_TX)

//------------------------------------------------
// Serial peripheral interfaces

#define CHIP_SPI_0                                                  true

#define CHIP_SPI_0_ENABLE_BIT_0_REG                                 CHIP_REG_SPCR
#define CHIP_SPI_0_ENABLE_BIT_0_BIT                                 6

#define CHIP_SPI_0_INT_ENABLE_BIT_0_REG                             CHIP_REG_SPCR
#define CHIP_SPI_0_INT_ENABLE_BIT_0_BIT                             7

#define CHIP_SPI_0_DATA_ORDER_MSB_FIRST_ID                          0
#define CHIP_SPI_0_DATA_ORDER_LSB_FIRST_ID                          1
#define CHIP_SPI_0_DATA_ORDER_BIT_0_REG                             CHIP_REG_SPCR
#define CHIP_SPI_0_DATA_ORDER_BIT_0_BIT                             5

#define CHIP_SPI_0_MASTER_SLAVE_SELECT_SLAVE_ID                     0
#define CHIP_SPI_0_MASTER_SLAVE_SELECT_MASTER_ID                    1
#define CHIP_SPI_0_MASTER_SLAVE_SELECT_BIT_0_REG                    CHIP_REG_SPCR
#define CHIP_SPI_0_MASTER_SLAVE_SELECT_BIT_0_BIT                    4

#define CHIP_SPI_0_POLARITY_LEADING_RISING_TRAILING_FALLING_ID      0
#define CHIP_SPI_0_POLARITY_LEADING_FALLING_TRAILING_RISING_ID      0
#define CHIP_SPI_0_POLARITY_BIT_0_REG                               CHIP_REG_SPCR
#define CHIP_SPI_0_POLARITY_BIT_0_BIT                               3

#define CHIP_SPI_0_PHASE_LEADING_SAMPLE_TRAILING_SETUP_ID           0
#define CHIP_SPI_0_PHASE_LEADING_SETUP_TRAILING_SAMPLE_ID           0
#define CHIP_SPI_0_PHASE_BIT_0_REG                                  CHIP_REG_SPCR
#define CHIP_SPI_0_PHASE_BIT_0_BIT                                  2

#define CHIP_SPI_0_CLOCK_DIV_2_ID                                   4
#define CHIP_SPI_0_CLOCK_DIV_4_ID                                   0
#define CHIP_SPI_0_CLOCK_DIV_8_ID                                   5
#define CHIP_SPI_0_CLOCK_DIV_16_ID                                  1
#define CHIP_SPI_0_CLOCK_DIV_32_ID                                  6
#define CHIP_SPI_0_CLOCK_DIV_64_ID                                  2
#define CHIP_SPI_0_CLOCK_DIV_128_ID                                 3
#define CHIP_SPI_0_CLOCK_BIT_0_REG                                  CHIP_REG_SPCR
#define CHIP_SPI_0_CLOCK_BIT_0_BIT                                  0
#define CHIP_SPI_0_CLOCK_BIT_1_REG                                  CHIP_REG_SPCR
#define CHIP_SPI_0_CLOCK_BIT_1_BIT                                  1
#define CHIP_SPI_0_CLOCK_BIT_2_REG                                  CHIP_REG_SPSR
#define CHIP_SPI_0_CLOCK_BIT_2_BIT                                  0

#define CHIP_SPI_0_INT_FLAG_BIT_0_REG                               CHIP_REG_SPSR
#define CHIP_SPI_0_INT_FLAG_BIT_0_BIT                               7

#define CHIP_SPI_0_COLLISION_FLAG_BIT_0_REG                         CHIP_REG_SPSR
#define CHIP_SPI_0_COLLISION_FLAG_BIT_0_BIT                         6

#define CHIP_SPI_0_DATA_REG                                         CHIP_REG_SPDR

#define CHIP_SPI_0_INT_VECTOR                                       VECT(CHIP_VECT_SPI_STC)

#define CHIP_SPI_0_PIN_MISO                                         PortB::Pin4
#define CHIP_SPI_0_PIN_MOSI                                         PortB::Pin3
#define CHIP_SPI_0_PIN_SCK                                          PortB::Pin5
#define CHIP_SPI_0_PIN_SS                                           PortB::Pin2

//------------------------------------------------
// Two wire serial interfaces

#define CHIP_TWI_0                                                  true

#define CHIP_TWI_0_PRESCALER_1_ID                                   0
#define CHIP_TWI_0_PRESCALER_4_ID                                   1
#define CHIP_TWI_0_PRESCALER_16_ID                                  2
#define CHIP_TWI_0_PRESCALER_64_ID                                  3

#define CHIP_TWI_0_PRESCALER_BIT_0_REG                              CHIP_REG_TWSR
#define CHIP_TWI_0_PRESCALER_BIT_0_BIT                              0
#define CHIP_TWI_0_PRESCALER_BIT_1_REG                              CHIP_REG_TWSR
#define CHIP_TWI_0_PRESCALER_BIT_1_BIT                              1

#define CHIP_TWI_0_DATA_REG                                         CHIP_REG_TWDR

#define CHIP_TWI_0_STATUS_REG                                       CHIP_REG_TWSR

#define CHIP_TWI_0_CONTROL_REG                                      CHIP_REG_TWCR

#define CHIP_TWI_0_BIT_RATE_REG                                     CHIP_REG_TWBR

#define CHIP_TWI_0_ENABLE_REG                                       CHIP_REG_TWCR
#define CHIP_TWI_0_ENABLE_BIT                                       2

#define CHIP_TWI_0_INT_FLAG_REG                                     CHIP_REG_TWCR
#define CHIP_TWI_0_INT_FLAG_BIT                                     7

#define CHIP_TWI_0_INT_ENABLE_REG                                   CHIP_REG_TWCR
#define CHIP_TWI_0_INT_ENABLE_BIT                                   0

#define CHIP_TWI_0_ENABLE_ACK_REG                                   CHIP_REG_TWCR
#define CHIP_TWI_0_ENABLE_ACK_BIT                                   6

#define CHIP_TWI_0_START_CONDITION_REG                              CHIP_REG_TWCR
#define CHIP_TWI_0_START_CONDITION_BIT                              5

#define CHIP_TWI_0_STOP_CONDITION_REG                               CHIP_REG_TWCR
#define CHIP_TWI_0_STOP_CONDITION_BIT                               4

#define CHIP_TWI_0_WRITE_COLLISION_FLAG_REG                         CHIP_REG_TWCR
#define CHIP_TWI_0_WRITE_COLLISION_FLAG_BIT                         3

#define CHIP_TWI_0_GEN_CALL_REC_ENABLE_REG                          CHIP_REG_TWAR
#define CHIP_TWI_0_GEN_CALL_REC_ENABLE_BIT                          0

#define CHIP_TWI_0_SLAVE_ADDRESS_REG                                CHIP_REG_TWAR
#define CHIP_TWI_0_SLAVE_ADDRESS_MASK_REG                           CHIP_REG_TWAMR

#define CHIP_TWI_0_INT_VECTOR                                       VECT(CHIP_VECT_TWI)

//------------------------------------------------
// Eeprom

#define CHIP_EEPROM_0                                               true

#define CHIP_EEPROM_0_ADDRESS_REG                                   CHIP_REG_EEAR

#define CHIP_EEPROM_0_DATA_REG                                      CHIP_REG_EEDR

#define CHIP_EEPROM_0_PROGRAMMING_MODE_ERASE_WRITE_ID               0
#define CHIP_EEPROM_0_PROGRAMMING_MODE_ERASE_ONLY_ID                1
#define CHIP_EEPROM_0_PROGRAMMING_MODE_WRITE_ONLY_ID                2
#define CHIP_EEPROM_0_PROGRAMMING_MODE_BIT_0_REG                    CHIP_REG_EECR
#define CHIP_EEPROM_0_PROGRAMMING_MODE_BIT_0_BIT                    4
#define CHIP_EEPROM_0_PROGRAMMING_MODE_BIT_1_REG                    CHIP_REG_EECR
#define CHIP_EEPROM_0_PROGRAMMING_MODE_BIT_1_BIT                    5

#define CHIP_EEPROM_0_READY_INT_ENABLE_REG                          CHIP_REG_EECR
#define CHIP_EEPROM_0_READY_INT_ENABLE_BIT                          3

#define CHIP_EEPROM_0_MASTER_WRITE_ENABLE_REG                       CHIP_REG_EECR
#define CHIP_EEPROM_0_MASTER_WRITE_ENABLE_BIT                       2

#define CHIP_EEPROM_0_WRITE_ENABLE_REG                              CHIP_REG_EECR
#define CHIP_EEPROM_0_WRITE_ENABLE_BIT                              1

#define CHIP_EEPROM_0_READ_ENABLE_REG                               CHIP_REG_EECR
#define CHIP_EEPROM_0_READ_ENABLE_BIT                               0

#define CHIP_EEPROM_0_EE_READY_INT_VECTOR                           VECT(CHIP_VECT_EE_READY)

#endif

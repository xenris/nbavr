#ifndef NBAVR_ATMEGA328P_HPP
#define NBAVR_ATMEGA328P_HPP

#define ATMEGA328P

#define NBAVR_CHIP_DEFINED

#define CHIP_ADDR_UDR3              0x136
#define CHIP_ADDR_UBRR3H            0x135
#define CHIP_ADDR_UBRR3L            0x134
#define CHIP_ADDR_UCSR3C            0x132
#define CHIP_ADDR_UCSR3B            0x131
#define CHIP_ADDR_UCSR3A            0x130
#define CHIP_ADDR_OCR5CH            0x12D
#define CHIP_ADDR_OCR5CL            0x12C
#define CHIP_ADDR_OCR5BH            0x12B
#define CHIP_ADDR_OCR5BL            0x12A
#define CHIP_ADDR_OCR5AH            0x129
#define CHIP_ADDR_OCR5AL            0x128
#define CHIP_ADDR_ICR5H             0x127
#define CHIP_ADDR_ICR5L             0x126
#define CHIP_ADDR_TCNT5H            0x125
#define CHIP_ADDR_TCNT5L            0x124
#define CHIP_ADDR_TCCR5C            0x122
#define CHIP_ADDR_TCCR5B            0x121
#define CHIP_ADDR_TCCR5A            0x120
#define CHIP_ADDR_PORTL             0x10B
#define CHIP_ADDR_DDRL              0x10A
#define CHIP_ADDR_PINL              0x109
#define CHIP_ADDR_PORTK             0x108
#define CHIP_ADDR_DDRK              0x107
#define CHIP_ADDR_PINK              0x106
#define CHIP_ADDR_PORTJ             0x105
#define CHIP_ADDR_DDRJ              0x104
#define CHIP_ADDR_PINJ              0x103
#define CHIP_ADDR_PORTH             0x102
#define CHIP_ADDR_DDRH              0x101
#define CHIP_ADDR_PINH              0x100
#define CHIP_ADDR_UDR2              0xD6
#define CHIP_ADDR_UBRR2H            0xD5
#define CHIP_ADDR_UBRR2L            0xD4
#define CHIP_ADDR_UCSR2C            0xD2
#define CHIP_ADDR_UCSR2B            0xD1
#define CHIP_ADDR_UCSR2A            0xD0
#define CHIP_ADDR_UDR1              0xCE
#define CHIP_ADDR_UBRR1H            0xCD
#define CHIP_ADDR_UBRR1L            0xCC
#define CHIP_ADDR_UCSR1C            0xCA
#define CHIP_ADDR_UCSR1B            0xC9
#define CHIP_ADDR_UCSR1A            0xC8
#define CHIP_ADDR_UDR0              0xC6
#define CHIP_ADDR_UBRR0H            0xC5
#define CHIP_ADDR_UBRR0L            0xC4
#define CHIP_ADDR_UCSR0C            0xC2
#define CHIP_ADDR_UCSR0B            0xC1
#define CHIP_ADDR_UCSR0A            0xC0
#define CHIP_ADDR_TWAMR             0xBD
#define CHIP_ADDR_TWCR              0xBC
#define CHIP_ADDR_TWDR              0xBB
#define CHIP_ADDR_TWAR              0xBA
#define CHIP_ADDR_TWSR              0xB9
#define CHIP_ADDR_TWBR              0xB8
#define CHIP_ADDR_ASSR              0xB6
#define CHIP_ADDR_OCR2B             0xB4
#define CHIP_ADDR_OCR2A             0xB3
#define CHIP_ADDR_TCNT2             0xB2
#define CHIP_ADDR_TCCR2B            0xB1
#define CHIP_ADDR_TCCR2A            0xB0
#define CHIP_ADDR_OCR4CH            0xAD
#define CHIP_ADDR_OCR4CL            0xAC
#define CHIP_ADDR_OCR4BH            0xAB
#define CHIP_ADDR_OCR4BL            0xAA
#define CHIP_ADDR_OCR4AH            0xA9
#define CHIP_ADDR_OCR4AL            0xA8
#define CHIP_ADDR_ICR4H             0xA7
#define CHIP_ADDR_ICR4L             0xA6
#define CHIP_ADDR_TCNT4H            0xA5
#define CHIP_ADDR_TCNT4L            0xA4
#define CHIP_ADDR_TCCR4C            0xA2
#define CHIP_ADDR_TCCR4B            0xA1
#define CHIP_ADDR_TCCR4A            0xA0
#define CHIP_ADDR_OCR3CH            0x9D
#define CHIP_ADDR_OCR3CL            0x9C
#define CHIP_ADDR_OCR3BH            0x9B
#define CHIP_ADDR_OCR3BL            0x9A
#define CHIP_ADDR_OCR3AH            0x99
#define CHIP_ADDR_OCR3AL            0x98
#define CHIP_ADDR_ICR3H             0x97
#define CHIP_ADDR_ICR3L             0x96
#define CHIP_ADDR_TCNT3H            0x95
#define CHIP_ADDR_TCNT3L            0x94
#define CHIP_ADDR_TCCR3C            0x92
#define CHIP_ADDR_TCCR3B            0x91
#define CHIP_ADDR_TCCR3A            0x90
#define CHIP_ADDR_OCR1CH            0x8D
#define CHIP_ADDR_OCR1CL            0x8C
#define CHIP_ADDR_OCR1BH            0x8B
#define CHIP_ADDR_OCR1BL            0x8A
#define CHIP_ADDR_OCR1AH            0x89
#define CHIP_ADDR_OCR1AL            0x88
#define CHIP_ADDR_ICR1H             0x87
#define CHIP_ADDR_ICR1L             0x86
#define CHIP_ADDR_TCNT1H            0x85
#define CHIP_ADDR_TCNT1L            0x84
#define CHIP_ADDR_TCCR1C            0x82
#define CHIP_ADDR_TCCR1B            0x81
#define CHIP_ADDR_TCCR1A            0x80
#define CHIP_ADDR_DIDR1             0x7F
#define CHIP_ADDR_DIDR0             0x7E
#define CHIP_ADDR_DIDR2             0x7D
#define CHIP_ADDR_ADMUX             0x7C
#define CHIP_ADDR_ADCSRB            0x7B
#define CHIP_ADDR_ADCSRA            0x7A
#define CHIP_ADDR_ADCH              0x79
#define CHIP_ADDR_ADCL              0x78
#define CHIP_ADDR_XMCRB             0x75
#define CHIP_ADDR_XMCRA             0x74
#define CHIP_ADDR_TIMSK5            0x73
#define CHIP_ADDR_TIMSK4            0x72
#define CHIP_ADDR_TIMSK3            0x71
#define CHIP_ADDR_TIMSK2            0x70
#define CHIP_ADDR_TIMSK1            0x6F
#define CHIP_ADDR_TIMSK0            0x6E
#define CHIP_ADDR_PCMSK2            0x6D
#define CHIP_ADDR_PCMSK1            0x6C
#define CHIP_ADDR_PCMSK0            0x6B
#define CHIP_ADDR_EICRB             0x6A
#define CHIP_ADDR_EICRA             0x69
#define CHIP_ADDR_PCICR             0x68
#define CHIP_ADDR_OSCCAL            0x66
#define CHIP_ADDR_PRR1              0x65
#define CHIP_ADDR_PRR0              0x64
#define CHIP_ADDR_CLKPR             0x61
#define CHIP_ADDR_WDTCSR            0x60
#define CHIP_ADDR_SREG              0x5F
#define CHIP_ADDR_SPH               0x5E
#define CHIP_ADDR_SPL               0x5D
#define CHIP_ADDR_EIND              0x5C
#define CHIP_ADDR_RAMPZ             0x5B
#define CHIP_ADDR_SPMCSR            0x57
#define CHIP_ADDR_MCUCR             0x55
#define CHIP_ADDR_MCUSR             0x54
#define CHIP_ADDR_SMCR              0x53
#define CHIP_ADDR_OCDR              0x51
#define CHIP_ADDR_ACSR              0x50
#define CHIP_ADDR_SPDR              0x4E
#define CHIP_ADDR_SPSR              0x4D
#define CHIP_ADDR_SPCR              0x4C
#define CHIP_ADDR_GPIOR2            0x4B
#define CHIP_ADDR_GPIOR1            0x4A
#define CHIP_ADDR_OCR0B             0x48
#define CHIP_ADDR_OCR0A             0x47
#define CHIP_ADDR_TCNT0             0x46
#define CHIP_ADDR_TCCR0B            0x45
#define CHIP_ADDR_TCCR0A            0x44
#define CHIP_ADDR_GTCCR             0x43
#define CHIP_ADDR_EEARH             0x42
#define CHIP_ADDR_EEARL             0x41
#define CHIP_ADDR_EEDR              0x40
#define CHIP_ADDR_EECR              0x3F
#define CHIP_ADDR_GPIOR0            0x3E
#define CHIP_ADDR_EIMSK             0x3D
#define CHIP_ADDR_EIFR              0x3C
#define CHIP_ADDR_PCIFR             0x3B
#define CHIP_ADDR_TIFR5             0x3A
#define CHIP_ADDR_TIFR4             0x39
#define CHIP_ADDR_TIFR3             0x38
#define CHIP_ADDR_TIFR2             0x37
#define CHIP_ADDR_TIFR1             0x36
#define CHIP_ADDR_TIFR0             0x35
#define CHIP_ADDR_PORTG             0x34
#define CHIP_ADDR_DDRG              0x33
#define CHIP_ADDR_PING              0x32
#define CHIP_ADDR_PORTF             0x31
#define CHIP_ADDR_DDRF              0x30
#define CHIP_ADDR_PINF              0x2F
#define CHIP_ADDR_PORTE             0x2E
#define CHIP_ADDR_DDRE              0x2D
#define CHIP_ADDR_PINE              0x2C
#define CHIP_ADDR_PORTD             0x2B
#define CHIP_ADDR_DDRD              0x2A
#define CHIP_ADDR_PIND              0x29
#define CHIP_ADDR_PORTC             0x28
#define CHIP_ADDR_DDRC              0x27
#define CHIP_ADDR_PINC              0x26
#define CHIP_ADDR_PORTB             0x25
#define CHIP_ADDR_DDRB              0x24
#define CHIP_ADDR_PINB              0x23
#define CHIP_ADDR_PORTA             0x22
#define CHIP_ADDR_DDRA              0x21
#define CHIP_ADDR_PINA              0x20

#define CHIP_VECT_RESET             1
#define CHIP_VECT_INT0              2
#define CHIP_VECT_INT1              3
#define CHIP_VECT_INT2              4
#define CHIP_VECT_INT3              5
#define CHIP_VECT_INT4              6
#define CHIP_VECT_INT5              7
#define CHIP_VECT_INT6              8
#define CHIP_VECT_INT7              9
#define CHIP_VECT_PCINT0            10
#define CHIP_VECT_PCINT1            11
#define CHIP_VECT_PCINT2            12
#define CHIP_VECT_WDT               13
#define CHIP_VECT_TIMER2_COMPA      14
#define CHIP_VECT_TIMER2_COMPB      15
#define CHIP_VECT_TIMER2_OVF        16
#define CHIP_VECT_TIMER1_CAPT       17
#define CHIP_VECT_TIMER1_COMPA      18
#define CHIP_VECT_TIMER1_COMPB      19
#define CHIP_VECT_TIMER1_COMPC      20
#define CHIP_VECT_TIMER1_OVF        21
#define CHIP_VECT_TIMER0_COMPA      22
#define CHIP_VECT_TIMER0_COMPB      23
#define CHIP_VECT_TIMER0_OVF        24
#define CHIP_VECT_SPI_STC           25
#define CHIP_VECT_USART0_RX         26
#define CHIP_VECT_USART0_UDRE       27
#define CHIP_VECT_USART0_TX         28
#define CHIP_VECT_ANALOG_COMP       29
#define CHIP_VECT_ADC               30
#define CHIP_VECT_EE_READY          31
#define CHIP_VECT_TIMER3_CAPT       32
#define CHIP_VECT_TIMER3_COMPA      33
#define CHIP_VECT_TIMER3_COMPB      34
#define CHIP_VECT_TIMER3_COMPC      35
#define CHIP_VECT_TIMER3_OVF        36
#define CHIP_VECT_USART1_RX         37
#define CHIP_VECT_USART1_UDRE       38
#define CHIP_VECT_USART1_TX         39
#define CHIP_VECT_TWI               40
#define CHIP_VECT_SPM_READY         41
#define CHIP_VECT_TIMER4_CAPT       42
#define CHIP_VECT_TIMER4_COMPA      43
#define CHIP_VECT_TIMER4_COMPB      44
#define CHIP_VECT_TIMER4_COMPC      45
#define CHIP_VECT_TIMER4_OVF        46
#define CHIP_VECT_TIMER5_CAPT       47
#define CHIP_VECT_TIMER5_COMPA      48
#define CHIP_VECT_TIMER5_COMPB      49
#define CHIP_VECT_TIMER5_COMPC      50
#define CHIP_VECT_TIMER5_OVF        51
#define CHIP_VECT_USART2_RX         52
#define CHIP_VECT_USART2_UDRE       53
#define CHIP_VECT_USART2_TX         54
#define CHIP_VECT_USART3_RX         55
#define CHIP_VECT_USART3_UDRE       56
#define CHIP_VECT_USART3_TX         57

//------------------------------------------------
// Ram Size

#define CHIP_RAM_SIZE                                                   (1024 * 8)

//------------------------------------------------
// Status Register

#define CHIP_STATUS_REG                                                 REG8(CHIP_ADDR_SREG)

//------------------------------------------------
// Reset Status Register

#define CHIP_RESET_STATUS_REG                                           REG8(CHIP_ADDR_MCUCR)

//------------------------------------------------
// Watchdog Timer

#define CHIP_WATCHDOG_TIMER_CONTROL_REG                                 REG8(CHIP_ADDR_WDTCSR)
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
#define CHIP_PORT_COUNT                                                 12

#define CHIP_PORT_A                                                     TRUE
#define CHIP_PORT_A_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTA)
#define CHIP_PORT_A_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRA)
#define CHIP_PORT_A_INPUT_REG                                           REG8(CHIP_ADDR_PINA)

#define CHIP_PORT_B                                                     TRUE
#define CHIP_PORT_B_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTB)
#define CHIP_PORT_B_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRB)
#define CHIP_PORT_B_INPUT_REG                                           REG8(CHIP_ADDR_PINB)

#define CHIP_PORT_C                                                     TRUE
#define CHIP_PORT_C_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTC)
#define CHIP_PORT_C_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRC)
#define CHIP_PORT_C_INPUT_REG                                           REG8(CHIP_ADDR_PINC)

#define CHIP_PORT_D                                                     TRUE
#define CHIP_PORT_D_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTD)
#define CHIP_PORT_D_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRD)
#define CHIP_PORT_D_INPUT_REG                                           REG8(CHIP_ADDR_PIND)

#define CHIP_PORT_E                                                     TRUE
#define CHIP_PORT_E_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTE)
#define CHIP_PORT_E_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRE)
#define CHIP_PORT_E_INPUT_REG                                           REG8(CHIP_ADDR_PINE)

#define CHIP_PORT_F                                                     TRUE
#define CHIP_PORT_F_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTF)
#define CHIP_PORT_F_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRF)
#define CHIP_PORT_F_INPUT_REG                                           REG8(CHIP_ADDR_PINF)

#define CHIP_PORT_G                                                     TRUE
#define CHIP_PORT_G_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTG)
#define CHIP_PORT_G_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRG)
#define CHIP_PORT_G_INPUT_REG                                           REG8(CHIP_ADDR_PING)

#define CHIP_PORT_H                                                     TRUE
#define CHIP_PORT_H_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTH)
#define CHIP_PORT_H_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRH)
#define CHIP_PORT_H_INPUT_REG                                           REG8(CHIP_ADDR_PINH)

#define CHIP_PORT_J                                                     TRUE
#define CHIP_PORT_J_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTJ)
#define CHIP_PORT_J_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRJ)
#define CHIP_PORT_J_INPUT_REG                                           REG8(CHIP_ADDR_PINJ)

#define CHIP_PORT_K                                                     TRUE
#define CHIP_PORT_K_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTK)
#define CHIP_PORT_K_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRK)
#define CHIP_PORT_K_INPUT_REG                                           REG8(CHIP_ADDR_PINK)

#define CHIP_PORT_L                                                     TRUE
#define CHIP_PORT_L_OUTPUT_REG                                          REG8(CHIP_ADDR_PORTL)
#define CHIP_PORT_L_DIRECTION_REG                                       REG8(CHIP_ADDR_DDRL)
#define CHIP_PORT_L_INPUT_REG                                           REG8(CHIP_ADDR_PINL)

//------------------------------------------------
// IO Pins

// Maximum number of pins per port.
#define CHIP_PIN_COUNT                                                  8

#define CHIP_PIN_A0                                                     TRUE
#define CHIP_PIN_A1                                                     TRUE
#define CHIP_PIN_A2                                                     TRUE
#define CHIP_PIN_A3                                                     TRUE
#define CHIP_PIN_A4                                                     TRUE
#define CHIP_PIN_A5                                                     TRUE
#define CHIP_PIN_A6                                                     TRUE
#define CHIP_PIN_A7                                                     TRUE

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
#define CHIP_PIN_C7                                                     TRUE

#define CHIP_PIN_D0                                                     TRUE
#define CHIP_PIN_D1                                                     TRUE
#define CHIP_PIN_D2                                                     TRUE
#define CHIP_PIN_D3                                                     TRUE
#define CHIP_PIN_D4                                                     TRUE
#define CHIP_PIN_D5                                                     TRUE
#define CHIP_PIN_D6                                                     TRUE
#define CHIP_PIN_D7                                                     TRUE

#define CHIP_PIN_E0                                                     TRUE
#define CHIP_PIN_E1                                                     TRUE
#define CHIP_PIN_E2                                                     TRUE
#define CHIP_PIN_E3                                                     TRUE
#define CHIP_PIN_E4                                                     TRUE
#define CHIP_PIN_E5                                                     TRUE
#define CHIP_PIN_E6                                                     TRUE
#define CHIP_PIN_E7                                                     TRUE

#define CHIP_PIN_F0                                                     TRUE
#define CHIP_PIN_F1                                                     TRUE
#define CHIP_PIN_F2                                                     TRUE
#define CHIP_PIN_F3                                                     TRUE
#define CHIP_PIN_F4                                                     TRUE
#define CHIP_PIN_F5                                                     TRUE
#define CHIP_PIN_F6                                                     TRUE
#define CHIP_PIN_F7                                                     TRUE

#define CHIP_PIN_G0                                                     TRUE
#define CHIP_PIN_G1                                                     TRUE
#define CHIP_PIN_G2                                                     TRUE
#define CHIP_PIN_G3                                                     TRUE
#define CHIP_PIN_G4                                                     TRUE
#define CHIP_PIN_G5                                                     TRUE

#define CHIP_PIN_H0                                                     TRUE
#define CHIP_PIN_H1                                                     TRUE
#define CHIP_PIN_H2                                                     TRUE
#define CHIP_PIN_H3                                                     TRUE
#define CHIP_PIN_H4                                                     TRUE
#define CHIP_PIN_H5                                                     TRUE
#define CHIP_PIN_H6                                                     TRUE
#define CHIP_PIN_H7                                                     TRUE

#define CHIP_PIN_J0                                                     TRUE
#define CHIP_PIN_J1                                                     TRUE
#define CHIP_PIN_J2                                                     TRUE
#define CHIP_PIN_J3                                                     TRUE
#define CHIP_PIN_J4                                                     TRUE
#define CHIP_PIN_J5                                                     TRUE
#define CHIP_PIN_J6                                                     TRUE
#define CHIP_PIN_J7                                                     TRUE

#define CHIP_PIN_K0                                                     TRUE
#define CHIP_PIN_K1                                                     TRUE
#define CHIP_PIN_K2                                                     TRUE
#define CHIP_PIN_K3                                                     TRUE
#define CHIP_PIN_K4                                                     TRUE
#define CHIP_PIN_K5                                                     TRUE
#define CHIP_PIN_K6                                                     TRUE
#define CHIP_PIN_K7                                                     TRUE

#define CHIP_PIN_L0                                                     TRUE
#define CHIP_PIN_L1                                                     TRUE
#define CHIP_PIN_L2                                                     TRUE
#define CHIP_PIN_L3                                                     TRUE
#define CHIP_PIN_L4                                                     TRUE
#define CHIP_PIN_L5                                                     TRUE
#define CHIP_PIN_L6                                                     TRUE
#define CHIP_PIN_L7                                                     TRUE

//------------------------------------------------
// ADC

// TODO

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
// TODO Add other internal voltage reference.

#define CHIP_ADC_CHANNEL_BIT_0_REG                                      REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_CHANNEL_BIT_1_REG                                      REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_CHANNEL_BIT_2_REG                                      REG8(CHIP_ADDR_ADMUX)
#define CHIP_ADC_CHANNEL_BIT_3_REG                                      REG8(CHIP_ADDR_ADMUX)
// #define CHIP_ADC_CHANNEL_BIT_4_REG                                      REG8(CHIP_ADDR_ADMUX)
// #define CHIP_ADC_CHANNEL_BIT_5_REG                                      REG8(CHIP_ADDR_ADCSRB)
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
// #define CHIP_ADC_CHANNEL_VBG_ID                                         30
// #define CHIP_ADC_CHANNEL_GND_ID                                         31
// #define CHIP_ADC_CHANNEL_8_ID                                           32
// #define CHIP_ADC_CHANNEL_9_ID                                           33
// #define CHIP_ADC_CHANNEL_10_ID                                          34
// #define CHIP_ADC_CHANNEL_11_ID                                          35
// #define CHIP_ADC_CHANNEL_12_ID                                          36
// #define CHIP_ADC_CHANNEL_13_ID                                          37
// #define CHIP_ADC_CHANNEL_14_ID                                          38
// #define CHIP_ADC_CHANNEL_15_ID                                          39
// TODO Add extra channel select bits.
// TODO Add differential and gain channels.

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
#define CHIP_ADC_TRIGGER_TIMER1_COMPARE_MATCH_B_ID                      5
#define CHIP_ADC_TRIGGER_TIMER1_OVERFLOW_ID                             6
#define CHIP_ADC_TRIGGER_TIMER1_CAPTURE_EVENT_ID                        7

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

#define CHIP_EXINT_COUNT                                                8

#define CHIP_EXINT_0                                                    TRUE
#define CHIP_EXINT_0_ENABLE_REG                                         REG8(CHIP_ADDR_EIMSK)
#define CHIP_EXINT_0_ENABLE_BIT                                         0
#define CHIP_EXINT_0_FLAG_REG                                           REG8(CHIP_ADDR_EIFR)
#define CHIP_EXINT_0_FLAG_BIT                                           0
#define CHIP_EXINT_0_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_EICRA)
#define CHIP_EXINT_0_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_EICRA)
#define CHIP_EXINT_0_TRIGGER_BIT_0_BIT                                  0
#define CHIP_EXINT_0_TRIGGER_BIT_1_BIT                                  1
#define CHIP_EXINT_0_INT_VECTOR                                         VECT(CHIP_VECT_INT0)
#define CHIP_EXINT_0_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_0_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_0_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_0_TRIGGER_RISING_ID                                  3

#define CHIP_EXINT_1                                                    TRUE
#define CHIP_EXINT_1_ENABLE_REG                                         REG8(CHIP_ADDR_EIMSK)
#define CHIP_EXINT_1_ENABLE_BIT                                         1
#define CHIP_EXINT_1_FLAG_REG                                           REG8(CHIP_ADDR_EIFR)
#define CHIP_EXINT_1_FLAG_BIT                                           1
#define CHIP_EXINT_1_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_EICRA)
#define CHIP_EXINT_1_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_EICRA)
#define CHIP_EXINT_1_TRIGGER_BIT_0_BIT                                  2
#define CHIP_EXINT_1_TRIGGER_BIT_1_BIT                                  3
#define CHIP_EXINT_1_INT_VECTOR                                         VECT(CHIP_VECT_INT1)
#define CHIP_EXINT_1_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_1_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_1_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_1_TRIGGER_RISING_ID                                  3

#define CHIP_EXINT_2                                                    TRUE
#define CHIP_EXINT_2_ENABLE_REG                                         REG8(CHIP_ADDR_EIMSK)
#define CHIP_EXINT_2_ENABLE_BIT                                         2
#define CHIP_EXINT_2_FLAG_REG                                           REG8(CHIP_ADDR_EIFR)
#define CHIP_EXINT_2_FLAG_BIT                                           2
#define CHIP_EXINT_2_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_EICRA)
#define CHIP_EXINT_2_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_EICRA)
#define CHIP_EXINT_2_TRIGGER_BIT_0_BIT                                  4
#define CHIP_EXINT_2_TRIGGER_BIT_1_BIT                                  5
#define CHIP_EXINT_2_INT_VECTOR                                         VECT(CHIP_VECT_INT2)
#define CHIP_EXINT_2_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_2_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_2_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_2_TRIGGER_RISING_ID                                  3

#define CHIP_EXINT_3                                                    TRUE
#define CHIP_EXINT_3_ENABLE_REG                                         REG8(CHIP_ADDR_EIMSK)
#define CHIP_EXINT_3_ENABLE_BIT                                         3
#define CHIP_EXINT_3_FLAG_REG                                           REG8(CHIP_ADDR_EIFR)
#define CHIP_EXINT_3_FLAG_BIT                                           3
#define CHIP_EXINT_3_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_EICRA)
#define CHIP_EXINT_3_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_EICRA)
#define CHIP_EXINT_3_TRIGGER_BIT_0_BIT                                  6
#define CHIP_EXINT_3_TRIGGER_BIT_1_BIT                                  7
#define CHIP_EXINT_3_INT_VECTOR                                         VECT(CHIP_VECT_INT3)
#define CHIP_EXINT_3_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_3_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_3_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_3_TRIGGER_RISING_ID                                  3

#define CHIP_EXINT_4                                                    TRUE
#define CHIP_EXINT_4_ENABLE_REG                                         REG8(CHIP_ADDR_EIMSK)
#define CHIP_EXINT_4_ENABLE_BIT                                         4
#define CHIP_EXINT_4_FLAG_REG                                           REG8(CHIP_ADDR_EIFR)
#define CHIP_EXINT_4_FLAG_BIT                                           4
#define CHIP_EXINT_4_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_EICRB)
#define CHIP_EXINT_4_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_EICRB)
#define CHIP_EXINT_4_TRIGGER_BIT_0_BIT                                  0
#define CHIP_EXINT_4_TRIGGER_BIT_1_BIT                                  1
#define CHIP_EXINT_4_INT_VECTOR                                         VECT(CHIP_VECT_INT4)
#define CHIP_EXINT_4_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_4_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_4_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_4_TRIGGER_RISING_ID                                  3

#define CHIP_EXINT_5                                                    TRUE
#define CHIP_EXINT_5_ENABLE_REG                                         REG8(CHIP_ADDR_EIMSK)
#define CHIP_EXINT_5_ENABLE_BIT                                         5
#define CHIP_EXINT_5_FLAG_REG                                           REG8(CHIP_ADDR_EIFR)
#define CHIP_EXINT_5_FLAG_BIT                                           5
#define CHIP_EXINT_5_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_EICRB)
#define CHIP_EXINT_5_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_EICRB)
#define CHIP_EXINT_5_TRIGGER_BIT_0_BIT                                  2
#define CHIP_EXINT_5_TRIGGER_BIT_1_BIT                                  3
#define CHIP_EXINT_5_INT_VECTOR                                         VECT(CHIP_VECT_INT5)
#define CHIP_EXINT_5_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_5_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_5_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_5_TRIGGER_RISING_ID                                  3

#define CHIP_EXINT_6                                                    TRUE
#define CHIP_EXINT_6_ENABLE_REG                                         REG8(CHIP_ADDR_EIMSK)
#define CHIP_EXINT_6_ENABLE_BIT                                         6
#define CHIP_EXINT_6_FLAG_REG                                           REG8(CHIP_ADDR_EIFR)
#define CHIP_EXINT_6_FLAG_BIT                                           6
#define CHIP_EXINT_6_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_EICRB)
#define CHIP_EXINT_6_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_EICRB)
#define CHIP_EXINT_6_TRIGGER_BIT_0_BIT                                  4
#define CHIP_EXINT_6_TRIGGER_BIT_1_BIT                                  5
#define CHIP_EXINT_6_INT_VECTOR                                         VECT(CHIP_VECT_INT6)
#define CHIP_EXINT_6_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_6_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_6_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_6_TRIGGER_RISING_ID                                  3

#define CHIP_EXINT_7                                                    TRUE
#define CHIP_EXINT_7_ENABLE_REG                                         REG8(CHIP_ADDR_EIMSK)
#define CHIP_EXINT_7_ENABLE_BIT                                         7
#define CHIP_EXINT_7_FLAG_REG                                           REG8(CHIP_ADDR_EIFR)
#define CHIP_EXINT_7_FLAG_BIT                                           7
#define CHIP_EXINT_7_TRIGGER_BIT_0_REG                                  REG8(CHIP_ADDR_EICRB)
#define CHIP_EXINT_7_TRIGGER_BIT_1_REG                                  REG8(CHIP_ADDR_EICRB)
#define CHIP_EXINT_7_TRIGGER_BIT_0_BIT                                  6
#define CHIP_EXINT_7_TRIGGER_BIT_1_BIT                                  7
#define CHIP_EXINT_7_INT_VECTOR                                         VECT(CHIP_VECT_INT7)
#define CHIP_EXINT_7_TRIGGER_LOW_ID                                     0
#define CHIP_EXINT_7_TRIGGER_CHANGE_ID                                  1
#define CHIP_EXINT_7_TRIGGER_FALLING_ID                                 2
#define CHIP_EXINT_7_TRIGGER_RISING_ID                                  3

//------------------------------------------------
// Pin Change Interrupts

#define CHIP_PCINT_COUNT                                                3

#define CHIP_PCINT_0                                                    TRUE
#define CHIP_PCINT_0_ENABLE_REG                                         REG8(CHIP_ADDR_PCICR)
#define CHIP_PCINT_0_ENABLE_BIT                                         0
#define CHIP_PCINT_0_FLAG_REG                                           REG8(CHIP_ADDR_PCIFR)
#define CHIP_PCINT_0_FLAG_BIT                                           0
#define CHIP_PCINT_0_MASK_REG                                           REG8(CHIP_ADDR_PCMSK0)
#define CHIP_PCINT_0_INT_VECTOR                                         VECT(CHIP_VECT_PCINT0)

#define CHIP_PCINT_1                                                    TRUE
#define CHIP_PCINT_1_ENABLE_REG                                         REG8(CHIP_ADDR_PCICR)
#define CHIP_PCINT_1_ENABLE_BIT                                         1
#define CHIP_PCINT_1_FLAG_REG                                           REG8(CHIP_ADDR_PCIFR)
#define CHIP_PCINT_1_FLAG_BIT                                           1
#define CHIP_PCINT_1_MASK_REG                                           REG8(CHIP_ADDR_PCMSK1)
#define CHIP_PCINT_1_INT_VECTOR                                         VECT(CHIP_VECT_PCINT1)

#define CHIP_PCINT_2                                                    TRUE
#define CHIP_PCINT_2_ENABLE_REG                                         REG8(CHIP_ADDR_PCICR)
#define CHIP_PCINT_2_ENABLE_BIT                                         2
#define CHIP_PCINT_2_FLAG_REG                                           REG8(CHIP_ADDR_PCIFR)
#define CHIP_PCINT_2_FLAG_BIT                                           2
#define CHIP_PCINT_2_MASK_REG                                           REG8(CHIP_ADDR_PCMSK2)
#define CHIP_PCINT_2_INT_VECTOR                                         VECT(CHIP_VECT_PCINT2)

//------------------------------------------------
// Timer Counters

#define CHIP_TIMERCOUNTER_COUNT                                         6

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
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_PIN                         PinB7
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR0A)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR0A)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_REG                         REG8(CHIP_ADDR_OCR0A)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK0)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_ENABLE_BIT              1
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR0)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_FLAG_BIT                1
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER0_COMPA)

#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_PIN                         PinG5
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR0A)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR0A)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_REG                         REG8(CHIP_ADDR_OCR0B)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK0)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_ENABLE_BIT              2
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR0)
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_FLAG_BIT                2
#define CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER0_COMPB)

#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK0)
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_ENABLE_BIT                     0
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR0)
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_FLAG_BIT                       0
#define CHIP_TIMERCOUNTER_0_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER0_OVF)

//------------------------------------------------
// Timer Counter 1

#define CHIP_TIMERCOUNTER_1                                             TRUE

#define CHIP_TIMERCOUNTER_1_TYPE                                        uint16_t

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
#define CHIP_TIMERCOUNTER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID     9
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

#define CHIP_TIMERCOUNTER_1_COUNTER_REG                                 REG16(CHIP_ADDR_TCNT1L)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_PIN                         PinB5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_REG                         REG16(CHIP_ADDR_OCR1AL)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK1)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_ENABLE_BIT              1
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR1)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_FLAG_BIT                1
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER1_COMPA)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_PIN                         PinB6
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_REG                         REG16(CHIP_ADDR_OCR1BL)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK1)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_ENABLE_BIT              2
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR1)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_FLAG_BIT                2
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER1_COMPB)

#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C                             TRUE
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_PIN                         PinB7
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR1A)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_MODE_BIT_0_BIT              2
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_MODE_BIT_1_BIT              3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_REG                         REG16(CHIP_ADDR_OCR1CL)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK1)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_INT_ENABLE_BIT              3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR1)
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_INT_FLAG_BIT                3
#define CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C_INT_VECTOR                  VECT(CHIP_VECT_TIMER1_COMPC)

#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK1)
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_ENABLE_BIT                     0
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR1)
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_FLAG_BIT                       0
#define CHIP_TIMERCOUNTER_1_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER1_OVF)

//------------------------------------------------
// Timer Counter 2

#define CHIP_TIMERCOUNTER_2                                             TRUE

#define CHIP_TIMERCOUNTER_2_TYPE                                        uint8_t

#define CHIP_TIMERCOUNTER_2_WAVEFORM                                    TRUE
#define CHIP_TIMERCOUNTER_2_WAVEFORM_NORMAL_ID                          0
#define CHIP_TIMERCOUNTER_2_WAVEFORM_PWM_PHASE_CORRECT_ID               1
#define CHIP_TIMERCOUNTER_2_WAVEFORM_CTC_OCRA_ID                        2
#define CHIP_TIMERCOUNTER_2_WAVEFORM_FAST_PWM_ID                        3
#define CHIP_TIMERCOUNTER_2_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          5
#define CHIP_TIMERCOUNTER_2_WAVEFORM_FAST_PWM_OCRA_ID                   7
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR2A)
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR2A)
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_2_REG                          REG8(CHIP_ADDR_TCCR2B)
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_0_BIT                          0
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_1_BIT                          1
#define CHIP_TIMERCOUNTER_2_WAVEFORM_BIT_2_BIT                          3

#define CHIP_TIMERCOUNTER_2_CLOCK_NONE_ID                               0
#define CHIP_TIMERCOUNTER_2_CLOCK_1_ID                                  1
#define CHIP_TIMERCOUNTER_2_CLOCK_8_ID                                  2
#define CHIP_TIMERCOUNTER_2_CLOCK_32_ID                                 3
#define CHIP_TIMERCOUNTER_2_CLOCK_64_ID                                 4
#define CHIP_TIMERCOUNTER_2_CLOCK_128_ID                                5
#define CHIP_TIMERCOUNTER_2_CLOCK_256_ID                                6
#define CHIP_TIMERCOUNTER_2_CLOCK_1024_ID                               7
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR2B)
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR2B)
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR2B)
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_2_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_2_COUNTER_REG                                 REG8(CHIP_ADDR_TCNT2)

#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_PIN                         PinB4
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR2A)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR2A)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_REG                         REG8(CHIP_ADDR_OCR2A)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK2)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_ENABLE_BIT              1
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR2)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_FLAG_BIT                1
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER2_COMPA)

#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_PIN                         PinH6
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR2A)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR2A)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_REG                         REG8(CHIP_ADDR_OCR2B)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK2)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_INT_ENABLE_BIT              2
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR2)
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_INT_FLAG_BIT                2
#define CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER2_COMPB)

#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK2)
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_ENABLE_BIT                     0
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR2)
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_FLAG_BIT                       0
#define CHIP_TIMERCOUNTER_2_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER2_OVF)

// TODO Add input capture definitions.

//------------------------------------------------
// Timer Counter 3

#define CHIP_TIMERCOUNTER_3                                             TRUE

#define CHIP_TIMERCOUNTER_3_TYPE                                        uint16_t

#define CHIP_TIMERCOUNTER_3_WAVEFORM                                    TRUE
#define CHIP_TIMERCOUNTER_3_WAVEFORM_NORMAL_ID                          0
#define CHIP_TIMERCOUNTER_3_WAVEFORM_PWM_PHASE_CORRECT_8_ID             1
#define CHIP_TIMERCOUNTER_3_WAVEFORM_PWM_PHASE_CORRECT_9_ID             2
#define CHIP_TIMERCOUNTER_3_WAVEFORM_PWM_PHASE_CORRECT_10_ID            3
#define CHIP_TIMERCOUNTER_3_WAVEFORM_CTC_OCRA_ID                        4
#define CHIP_TIMERCOUNTER_3_WAVEFORM_FAST_PWM_8_ID                      5
#define CHIP_TIMERCOUNTER_3_WAVEFORM_FAST_PWM_9_ID                      6
#define CHIP_TIMERCOUNTER_3_WAVEFORM_FAST_PWM_10_ID                     7
#define CHIP_TIMERCOUNTER_3_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID          8
#define CHIP_TIMERCOUNTER_3_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID     9
#define CHIP_TIMERCOUNTER_3_WAVEFORM_PWM_PHASE_CORRECT_ID               10
#define CHIP_TIMERCOUNTER_3_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          11
#define CHIP_TIMERCOUNTER_3_WAVEFORM_CTC_ID                             12
#define CHIP_TIMERCOUNTER_3_WAVEFORM_FAST_PWM_ID                        14
#define CHIP_TIMERCOUNTER_3_WAVEFORM_FAST_PWM_OCRA_ID                   15
#define CHIP_TIMERCOUNTER_3_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR3A)
#define CHIP_TIMERCOUNTER_3_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR3A)
#define CHIP_TIMERCOUNTER_3_WAVEFORM_BIT_2_REG                          REG8(CHIP_ADDR_TCCR3B)
#define CHIP_TIMERCOUNTER_3_WAVEFORM_BIT_3_REG                          REG8(CHIP_ADDR_TCCR3B)
#define CHIP_TIMERCOUNTER_3_WAVEFORM_BIT_0_BIT                          0
#define CHIP_TIMERCOUNTER_3_WAVEFORM_BIT_1_BIT                          1
#define CHIP_TIMERCOUNTER_3_WAVEFORM_BIT_2_BIT                          3
#define CHIP_TIMERCOUNTER_3_WAVEFORM_BIT_3_BIT                          4

#define CHIP_TIMERCOUNTER_3_CLOCK_NONE_ID                               0
#define CHIP_TIMERCOUNTER_3_CLOCK_1_ID                                  1
#define CHIP_TIMERCOUNTER_3_CLOCK_8_ID                                  2
#define CHIP_TIMERCOUNTER_3_CLOCK_64_ID                                 3
#define CHIP_TIMERCOUNTER_3_CLOCK_256_ID                                4
#define CHIP_TIMERCOUNTER_3_CLOCK_1024_ID                               5
#define CHIP_TIMERCOUNTER_3_CLOCK_EXT_FALLING_ID                        6
#define CHIP_TIMERCOUNTER_3_CLOCK_EXT_RISING_ID                         7
#define CHIP_TIMERCOUNTER_3_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR3B)
#define CHIP_TIMERCOUNTER_3_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR3B)
#define CHIP_TIMERCOUNTER_3_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR3B)
#define CHIP_TIMERCOUNTER_3_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_3_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_3_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_3_COUNTER_REG                                 REG16(CHIP_ADDR_TCNT3L)

#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_PIN                         PinE3
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR3A)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR3A)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_REG                         REG16(CHIP_ADDR_OCR3AL)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK3)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_INT_ENABLE_BIT              1
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR3)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_INT_FLAG_BIT                1
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER3_COMPA)

#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_PIN                         PinE4
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR3A)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR3A)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_REG                         REG16(CHIP_ADDR_OCR3BL)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK3)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_INT_ENABLE_BIT              2
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR3)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_INT_FLAG_BIT                2
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER3_COMPB)

#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C                             TRUE
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_PIN                         PinE5
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR3A)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR3A)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_MODE_BIT_0_BIT              2
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_MODE_BIT_1_BIT              3
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_REG                         REG16(CHIP_ADDR_OCR3CL)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK3)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_INT_ENABLE_BIT              3
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR3)
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_INT_FLAG_BIT                3
#define CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C_INT_VECTOR                  VECT(CHIP_VECT_TIMER3_COMPC)

#define CHIP_TIMERCOUNTER_3_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK3)
#define CHIP_TIMERCOUNTER_3_OVERFLOW_INT_ENABLE_BIT                     0
#define CHIP_TIMERCOUNTER_3_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR3)
#define CHIP_TIMERCOUNTER_3_OVERFLOW_INT_FLAG_BIT                       0
#define CHIP_TIMERCOUNTER_3_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER3_OVF)

//------------------------------------------------
// Timer Counter 4

#define CHIP_TIMERCOUNTER_4                                             TRUE

#define CHIP_TIMERCOUNTER_4_TYPE                                        uint16_t

#define CHIP_TIMERCOUNTER_4_WAVEFORM                                    TRUE
#define CHIP_TIMERCOUNTER_4_WAVEFORM_NORMAL_ID                          0
#define CHIP_TIMERCOUNTER_4_WAVEFORM_PWM_PHASE_CORRECT_8_ID             1
#define CHIP_TIMERCOUNTER_4_WAVEFORM_PWM_PHASE_CORRECT_9_ID             2
#define CHIP_TIMERCOUNTER_4_WAVEFORM_PWM_PHASE_CORRECT_10_ID            3
#define CHIP_TIMERCOUNTER_4_WAVEFORM_CTC_OCRA_ID                        4
#define CHIP_TIMERCOUNTER_4_WAVEFORM_FAST_PWM_8_ID                      5
#define CHIP_TIMERCOUNTER_4_WAVEFORM_FAST_PWM_9_ID                      6
#define CHIP_TIMERCOUNTER_4_WAVEFORM_FAST_PWM_10_ID                     7
#define CHIP_TIMERCOUNTER_4_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID          8
#define CHIP_TIMERCOUNTER_4_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID     9
#define CHIP_TIMERCOUNTER_4_WAVEFORM_PWM_PHASE_CORRECT_ID               10
#define CHIP_TIMERCOUNTER_4_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          11
#define CHIP_TIMERCOUNTER_4_WAVEFORM_CTC_ID                             12
#define CHIP_TIMERCOUNTER_4_WAVEFORM_FAST_PWM_ID                        14
#define CHIP_TIMERCOUNTER_4_WAVEFORM_FAST_PWM_OCRA_ID                   15
#define CHIP_TIMERCOUNTER_4_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR4A)
#define CHIP_TIMERCOUNTER_4_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR4A)
#define CHIP_TIMERCOUNTER_4_WAVEFORM_BIT_2_REG                          REG8(CHIP_ADDR_TCCR4B)
#define CHIP_TIMERCOUNTER_4_WAVEFORM_BIT_3_REG                          REG8(CHIP_ADDR_TCCR4B)
#define CHIP_TIMERCOUNTER_4_WAVEFORM_BIT_0_BIT                          0
#define CHIP_TIMERCOUNTER_4_WAVEFORM_BIT_1_BIT                          1
#define CHIP_TIMERCOUNTER_4_WAVEFORM_BIT_2_BIT                          3
#define CHIP_TIMERCOUNTER_4_WAVEFORM_BIT_3_BIT                          4

#define CHIP_TIMERCOUNTER_4_CLOCK_NONE_ID                               0
#define CHIP_TIMERCOUNTER_4_CLOCK_1_ID                                  1
#define CHIP_TIMERCOUNTER_4_CLOCK_8_ID                                  2
#define CHIP_TIMERCOUNTER_4_CLOCK_64_ID                                 3
#define CHIP_TIMERCOUNTER_4_CLOCK_256_ID                                4
#define CHIP_TIMERCOUNTER_4_CLOCK_1024_ID                               5
#define CHIP_TIMERCOUNTER_4_CLOCK_EXT_FALLING_ID                        6
#define CHIP_TIMERCOUNTER_4_CLOCK_EXT_RISING_ID                         7
#define CHIP_TIMERCOUNTER_4_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR4B)
#define CHIP_TIMERCOUNTER_4_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR4B)
#define CHIP_TIMERCOUNTER_4_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR4B)
#define CHIP_TIMERCOUNTER_4_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_4_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_4_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_4_COUNTER_REG                                 REG16(CHIP_ADDR_TCNT4L)

#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_PIN                         PinH3
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR4A)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR4A)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_REG                         REG16(CHIP_ADDR_OCR4AL)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK4)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_INT_ENABLE_BIT              1
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR4)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_INT_FLAG_BIT                1
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER4_COMPA)

#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_PIN                         PinH4
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR4A)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR4A)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_REG                         REG16(CHIP_ADDR_OCR4BL)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK4)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_INT_ENABLE_BIT              2
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR4)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_INT_FLAG_BIT                2
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER4_COMPB)

#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C                             TRUE
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_PIN                         PinH5
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR4A)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR4A)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_MODE_BIT_0_BIT              2
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_MODE_BIT_1_BIT              3
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_REG                         REG16(CHIP_ADDR_OCR4CL)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK4)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_INT_ENABLE_BIT              3
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR4)
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_INT_FLAG_BIT                3
#define CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C_INT_VECTOR                  VECT(CHIP_VECT_TIMER4_COMPC)

#define CHIP_TIMERCOUNTER_4_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK4)
#define CHIP_TIMERCOUNTER_4_OVERFLOW_INT_ENABLE_BIT                     0
#define CHIP_TIMERCOUNTER_4_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR4)
#define CHIP_TIMERCOUNTER_4_OVERFLOW_INT_FLAG_BIT                       0
#define CHIP_TIMERCOUNTER_4_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER4_OVF)

//------------------------------------------------
// Timer Counter 5

#define CHIP_TIMERCOUNTER_5                                             TRUE

#define CHIP_TIMERCOUNTER_5_TYPE                                        uint16_t

#define CHIP_TIMERCOUNTER_5_WAVEFORM                                    TRUE
#define CHIP_TIMERCOUNTER_5_WAVEFORM_NORMAL_ID                          0
#define CHIP_TIMERCOUNTER_5_WAVEFORM_PWM_PHASE_CORRECT_8_ID             1
#define CHIP_TIMERCOUNTER_5_WAVEFORM_PWM_PHASE_CORRECT_9_ID             2
#define CHIP_TIMERCOUNTER_5_WAVEFORM_PWM_PHASE_CORRECT_10_ID            3
#define CHIP_TIMERCOUNTER_5_WAVEFORM_CTC_OCRA_ID                        4
#define CHIP_TIMERCOUNTER_5_WAVEFORM_FAST_PWM_8_ID                      5
#define CHIP_TIMERCOUNTER_5_WAVEFORM_FAST_PWM_9_ID                      6
#define CHIP_TIMERCOUNTER_5_WAVEFORM_FAST_PWM_10_ID                     7
#define CHIP_TIMERCOUNTER_5_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID          8
#define CHIP_TIMERCOUNTER_5_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID     9
#define CHIP_TIMERCOUNTER_5_WAVEFORM_PWM_PHASE_CORRECT_ID               10
#define CHIP_TIMERCOUNTER_5_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID          11
#define CHIP_TIMERCOUNTER_5_WAVEFORM_CTC_ID                             12
#define CHIP_TIMERCOUNTER_5_WAVEFORM_FAST_PWM_ID                        14
#define CHIP_TIMERCOUNTER_5_WAVEFORM_FAST_PWM_OCRA_ID                   15
#define CHIP_TIMERCOUNTER_5_WAVEFORM_BIT_0_REG                          REG8(CHIP_ADDR_TCCR5A)
#define CHIP_TIMERCOUNTER_5_WAVEFORM_BIT_1_REG                          REG8(CHIP_ADDR_TCCR5A)
#define CHIP_TIMERCOUNTER_5_WAVEFORM_BIT_2_REG                          REG8(CHIP_ADDR_TCCR5B)
#define CHIP_TIMERCOUNTER_5_WAVEFORM_BIT_3_REG                          REG8(CHIP_ADDR_TCCR5B)
#define CHIP_TIMERCOUNTER_5_WAVEFORM_BIT_0_BIT                          0
#define CHIP_TIMERCOUNTER_5_WAVEFORM_BIT_1_BIT                          1
#define CHIP_TIMERCOUNTER_5_WAVEFORM_BIT_2_BIT                          3
#define CHIP_TIMERCOUNTER_5_WAVEFORM_BIT_3_BIT                          4

#define CHIP_TIMERCOUNTER_5_CLOCK_NONE_ID                               0
#define CHIP_TIMERCOUNTER_5_CLOCK_1_ID                                  1
#define CHIP_TIMERCOUNTER_5_CLOCK_8_ID                                  2
#define CHIP_TIMERCOUNTER_5_CLOCK_64_ID                                 3
#define CHIP_TIMERCOUNTER_5_CLOCK_256_ID                                4
#define CHIP_TIMERCOUNTER_5_CLOCK_1024_ID                               5
#define CHIP_TIMERCOUNTER_5_CLOCK_EXT_FALLING_ID                        6
#define CHIP_TIMERCOUNTER_5_CLOCK_EXT_RISING_ID                         7
#define CHIP_TIMERCOUNTER_5_CLOCK_BIT_0_REG                             REG8(CHIP_ADDR_TCCR5B)
#define CHIP_TIMERCOUNTER_5_CLOCK_BIT_1_REG                             REG8(CHIP_ADDR_TCCR5B)
#define CHIP_TIMERCOUNTER_5_CLOCK_BIT_2_REG                             REG8(CHIP_ADDR_TCCR5B)
#define CHIP_TIMERCOUNTER_5_CLOCK_BIT_0_BIT                             0
#define CHIP_TIMERCOUNTER_5_CLOCK_BIT_1_BIT                             1
#define CHIP_TIMERCOUNTER_5_CLOCK_BIT_2_BIT                             2

#define CHIP_TIMERCOUNTER_5_COUNTER_REG                                 REG16(CHIP_ADDR_TCNT5L)

#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A                             TRUE
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_PIN                         PinL3
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR5A)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR5A)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_MODE_BIT_0_BIT              6
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_MODE_BIT_1_BIT              7
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_REG                         REG16(CHIP_ADDR_OCR5AL)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK5)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_INT_ENABLE_BIT              1
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR5)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_INT_FLAG_BIT                1
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A_INT_VECTOR                  VECT(CHIP_VECT_TIMER5_COMPA)

#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B                             TRUE
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_PIN                         PinL4
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR5A)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR5A)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_MODE_BIT_0_BIT              4
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_MODE_BIT_1_BIT              5
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_REG                         REG16(CHIP_ADDR_OCR5BL)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK5)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_INT_ENABLE_BIT              2
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR5)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_INT_FLAG_BIT                2
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B_INT_VECTOR                  VECT(CHIP_VECT_TIMER5_COMPB)

#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C                             TRUE
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_PIN                         PinL5
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_MODE_BIT_0_REG              REG8(CHIP_ADDR_TCCR5A)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_MODE_BIT_1_REG              REG8(CHIP_ADDR_TCCR5A)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_MODE_BIT_0_BIT              2
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_MODE_BIT_1_BIT              3
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_MODE_DISCONNECTED_ID        0
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_MODE_TOGGLE_ID              1
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_MODE_CLEAR_ID               2
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_MODE_SET_ID                 3
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_REG                         REG16(CHIP_ADDR_OCR5CL)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_INT_ENABLE_REG              REG8(CHIP_ADDR_TIMSK5)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_INT_ENABLE_BIT              3
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_INT_FLAG_REG                REG8(CHIP_ADDR_TIFR5)
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_INT_FLAG_BIT                3
#define CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C_INT_VECTOR                  VECT(CHIP_VECT_TIMER5_COMPC)

#define CHIP_TIMERCOUNTER_5_OVERFLOW_INT_ENABLE_REG                     REG8(CHIP_ADDR_TIMSK5)
#define CHIP_TIMERCOUNTER_5_OVERFLOW_INT_ENABLE_BIT                     0
#define CHIP_TIMERCOUNTER_5_OVERFLOW_INT_FLAG_REG                       REG8(CHIP_ADDR_TIFR5)
#define CHIP_TIMERCOUNTER_5_OVERFLOW_INT_FLAG_BIT                       0
#define CHIP_TIMERCOUNTER_5_OVERFLOW_INT_VECTOR                         VECT(CHIP_VECT_TIMER5_OVF)

//------------------------------------------------
// Usarts

#define CHIP_USART_COUNT                                                4

//------------------------------------------------
// Usart 0

#define CHIP_USART_0                                                    TRUE

#define CHIP_USART_0_DATA_REG                                           REG8(CHIP_ADDR_UDR0)

#define CHIP_USART_0_BAUD_RATE_REG                                      REG16(CHIP_ADDR_UBRR0L)
#define CHIP_USART_0_BAUD_RATE_REG_HIGH                                 REG8(CHIP_ADDR_UBRR0H)
#define CHIP_USART_0_BAUD_RATE_REG_LOW                                  REG8(CHIP_ADDR_UBRR0L)

#define CHIP_USART_0_FRAME_ERROR_REG                                    REG8(CHIP_ADDR_UCSR0A)
#define CHIP_USART_0_FRAME_ERROR_BIT                                    4
#define CHIP_USART_0_DATA_OVERRUN_REG                                   REG8(CHIP_ADDR_UCSR0A)
#define CHIP_USART_0_DATA_OVERRUN_BIT                                   3
#define CHIP_USART_0_PARITY_ERROR_REG                                   REG8(CHIP_ADDR_UCSR0A)
#define CHIP_USART_0_PARITY_ERROR_BIT                                   2

#define CHIP_USART_0_DOUBLE_SPEED_REG                                   REG8(CHIP_ADDR_UCSR0A)
#define CHIP_USART_0_DOUBLE_SPEED_BIT                                   1

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG                  REG8(CHIP_ADDR_UCSR0A)
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT                  0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSR0B)
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                         7
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSR0B)
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                         6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG                      REG8(CHIP_ADDR_UCSR0B)
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT                      5

#define CHIP_USART_0_RX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSR0B)
#define CHIP_USART_0_RX_ENABLE_BIT                                      4
#define CHIP_USART_0_TX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSR0B)
#define CHIP_USART_0_TX_ENABLE_BIT                                      3

#define CHIP_USART_0_RX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSR0B)
#define CHIP_USART_0_RX_DATA_BIT_8_BIT                                  1
#define CHIP_USART_0_TX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSR0B)
#define CHIP_USART_0_TX_DATA_BIT_8_BIT                                  0

#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                               0
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                                1
#define CHIP_USART_0_MODE_MASTER_SPI_ID                                 3
#define CHIP_USART_0_MODE_BIT_0_REG                                     REG8(CHIP_ADDR_UCSR0C)
#define CHIP_USART_0_MODE_BIT_1_REG                                     REG8(CHIP_ADDR_UCSR0C)
#define CHIP_USART_0_MODE_BIT_0_BIT                                     6
#define CHIP_USART_0_MODE_BIT_1_BIT                                     7

#define CHIP_USART_0_PARITY_DISABLE_ID                                  0
#define CHIP_USART_0_PARITY_EVEN_ID                                     2
#define CHIP_USART_0_PARITY_ODD_ID                                      3
#define CHIP_USART_0_PARITY_BIT_0_REG                                   REG8(CHIP_ADDR_UCSR0C)
#define CHIP_USART_0_PARITY_BIT_1_REG                                   REG8(CHIP_ADDR_UCSR0C)
#define CHIP_USART_0_PARITY_BIT_0_BIT                                   4
#define CHIP_USART_0_PARITY_BIT_1_BIT                                   5

#define CHIP_USART_0_STOP_BITS_1_ID                                     0
#define CHIP_USART_0_STOP_BITS_2_ID                                     1
#define CHIP_USART_0_STOP_BITS_REG                                      REG8(CHIP_ADDR_UCSR0C)
#define CHIP_USART_0_STOP_BITS_BIT                                      3

#define CHIP_USART_0_CHARACTER_SIZE_5_ID                                0
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                                1
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                                2
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                                3
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                                7
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_REG                           REG8(CHIP_ADDR_UCSR0C)
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_REG                           REG8(CHIP_ADDR_UCSR0C)
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_REG                           REG8(CHIP_ADDR_UCSR0B)
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_BIT                           1
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_BIT                           2
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_BIT                           2

#define CHIP_USART_0_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID             0
#define CHIP_USART_0_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID             1
#define CHIP_USART_0_CLOCK_POLARITY_REG                                 REG8(CHIP_ADDR_UCSR0C)
#define CHIP_USART_0_CLOCK_POLARITY_BIT                                 0

#define CHIP_USART_0_RX_INT_VECTOR                                      VECT(CHIP_VECT_USART0_RX)
#define CHIP_USART_0_DE_INT_VECTOR                                      VECT(CHIP_VECT_USART0_UDRE)
#define CHIP_USART_0_TX_INT_VECTOR                                      VECT(CHIP_VECT_USART0_TX)

//------------------------------------------------
// Usart 1

#define CHIP_USART_1                                                    TRUE

#define CHIP_USART_1_DATA_REG                                           REG8(CHIP_ADDR_UDR1)

#define CHIP_USART_1_BAUD_RATE_REG                                      REG16(CHIP_ADDR_UBRR1L)
#define CHIP_USART_1_BAUD_RATE_REG_HIGH                                 REG8(CHIP_ADDR_UBRR1H)
#define CHIP_USART_1_BAUD_RATE_REG_LOW                                  REG8(CHIP_ADDR_UBRR1L)

#define CHIP_USART_1_FRAME_ERROR_REG                                    REG8(CHIP_ADDR_UCSR1A)
#define CHIP_USART_1_FRAME_ERROR_BIT                                    4
#define CHIP_USART_1_DATA_OVERRUN_REG                                   REG8(CHIP_ADDR_UCSR1A)
#define CHIP_USART_1_DATA_OVERRUN_BIT                                   3
#define CHIP_USART_1_PARITY_ERROR_REG                                   REG8(CHIP_ADDR_UCSR1A)
#define CHIP_USART_1_PARITY_ERROR_BIT                                   2

#define CHIP_USART_1_DOUBLE_SPEED_REG                                   REG8(CHIP_ADDR_UCSR1A)
#define CHIP_USART_1_DOUBLE_SPEED_BIT                                   1

#define CHIP_USART_1_MULTI_PROCESSOR_COMMUNICATION_REG                  REG8(CHIP_ADDR_UCSR1A)
#define CHIP_USART_1_MULTI_PROCESSOR_COMMUNICATION_BIT                  0

#define CHIP_USART_1_RX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSR1B)
#define CHIP_USART_1_RX_COMPLETE_INT_ENABLE_BIT                         7
#define CHIP_USART_1_TX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSR1B)
#define CHIP_USART_1_TX_COMPLETE_INT_ENABLE_BIT                         6
#define CHIP_USART_1_DATA_REG_EMPTY_INT_ENABLE_REG                      REG8(CHIP_ADDR_UCSR1B)
#define CHIP_USART_1_DATA_REG_EMPTY_INT_ENABLE_BIT                      5

#define CHIP_USART_1_RX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSR1B)
#define CHIP_USART_1_RX_ENABLE_BIT                                      4
#define CHIP_USART_1_TX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSR1B)
#define CHIP_USART_1_TX_ENABLE_BIT                                      3

#define CHIP_USART_1_RX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSR1B)
#define CHIP_USART_1_RX_DATA_BIT_8_BIT                                  1
#define CHIP_USART_1_TX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSR1B)
#define CHIP_USART_1_TX_DATA_BIT_8_BIT                                  0

#define CHIP_USART_1_MODE_ASYNCHRONOUS_ID                               0
#define CHIP_USART_1_MODE_SYNCHRONOUS_ID                                1
#define CHIP_USART_1_MODE_MASTER_SPI_ID                                 3
#define CHIP_USART_1_MODE_BIT_0_REG                                     REG8(CHIP_ADDR_UCSR1C)
#define CHIP_USART_1_MODE_BIT_1_REG                                     REG8(CHIP_ADDR_UCSR1C)
#define CHIP_USART_1_MODE_BIT_0_BIT                                     6
#define CHIP_USART_1_MODE_BIT_1_BIT                                     7

#define CHIP_USART_1_PARITY_DISABLE_ID                                  0
#define CHIP_USART_1_PARITY_EVEN_ID                                     2
#define CHIP_USART_1_PARITY_ODD_ID                                      3
#define CHIP_USART_1_PARITY_BIT_0_REG                                   REG8(CHIP_ADDR_UCSR1C)
#define CHIP_USART_1_PARITY_BIT_1_REG                                   REG8(CHIP_ADDR_UCSR1C)
#define CHIP_USART_1_PARITY_BIT_0_BIT                                   4
#define CHIP_USART_1_PARITY_BIT_1_BIT                                   5

#define CHIP_USART_1_STOP_BITS_1_ID                                     0
#define CHIP_USART_1_STOP_BITS_2_ID                                     1
#define CHIP_USART_1_STOP_BITS_REG                                      REG8(CHIP_ADDR_UCSR1C)
#define CHIP_USART_1_STOP_BITS_BIT                                      3

#define CHIP_USART_1_CHARACTER_SIZE_5_ID                                0
#define CHIP_USART_1_CHARACTER_SIZE_6_ID                                1
#define CHIP_USART_1_CHARACTER_SIZE_7_ID                                2
#define CHIP_USART_1_CHARACTER_SIZE_8_ID                                3
#define CHIP_USART_1_CHARACTER_SIZE_9_ID                                7
#define CHIP_USART_1_CHARACTER_SIZE_BIT_0_REG                           REG8(CHIP_ADDR_UCSR1C)
#define CHIP_USART_1_CHARACTER_SIZE_BIT_1_REG                           REG8(CHIP_ADDR_UCSR1C)
#define CHIP_USART_1_CHARACTER_SIZE_BIT_2_REG                           REG8(CHIP_ADDR_UCSR1B)
#define CHIP_USART_1_CHARACTER_SIZE_BIT_0_BIT                           1
#define CHIP_USART_1_CHARACTER_SIZE_BIT_1_BIT                           2
#define CHIP_USART_1_CHARACTER_SIZE_BIT_2_BIT                           2

#define CHIP_USART_1_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID             0
#define CHIP_USART_1_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID             1
#define CHIP_USART_1_CLOCK_POLARITY_REG                                 REG8(CHIP_ADDR_UCSR1C)
#define CHIP_USART_1_CLOCK_POLARITY_BIT                                 0

#define CHIP_USART_1_RX_INT_VECTOR                                      VECT(CHIP_VECT_USART1_RX)
#define CHIP_USART_1_DE_INT_VECTOR                                      VECT(CHIP_VECT_USART1_UDRE)
#define CHIP_USART_1_TX_INT_VECTOR                                      VECT(CHIP_VECT_USART1_TX)

//------------------------------------------------
// Usart 2

#define CHIP_USART_2                                                    TRUE

#define CHIP_USART_2_DATA_REG                                           REG8(CHIP_ADDR_UDR2)

#define CHIP_USART_2_BAUD_RATE_REG                                      REG16(CHIP_ADDR_UBRR2L)
#define CHIP_USART_2_BAUD_RATE_REG_HIGH                                 REG8(CHIP_ADDR_UBRR2H)
#define CHIP_USART_2_BAUD_RATE_REG_LOW                                  REG8(CHIP_ADDR_UBRR2L)

#define CHIP_USART_2_FRAME_ERROR_REG                                    REG8(CHIP_ADDR_UCSR2A)
#define CHIP_USART_2_FRAME_ERROR_BIT                                    4
#define CHIP_USART_2_DATA_OVERRUN_REG                                   REG8(CHIP_ADDR_UCSR2A)
#define CHIP_USART_2_DATA_OVERRUN_BIT                                   3
#define CHIP_USART_2_PARITY_ERROR_REG                                   REG8(CHIP_ADDR_UCSR2A)
#define CHIP_USART_2_PARITY_ERROR_BIT                                   2

#define CHIP_USART_2_DOUBLE_SPEED_REG                                   REG8(CHIP_ADDR_UCSR2A)
#define CHIP_USART_2_DOUBLE_SPEED_BIT                                   1

#define CHIP_USART_2_MULTI_PROCESSOR_COMMUNICATION_REG                  REG8(CHIP_ADDR_UCSR2A)
#define CHIP_USART_2_MULTI_PROCESSOR_COMMUNICATION_BIT                  0

#define CHIP_USART_2_RX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSR2B)
#define CHIP_USART_2_RX_COMPLETE_INT_ENABLE_BIT                         7
#define CHIP_USART_2_TX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSR2B)
#define CHIP_USART_2_TX_COMPLETE_INT_ENABLE_BIT                         6
#define CHIP_USART_2_DATA_REG_EMPTY_INT_ENABLE_REG                      REG8(CHIP_ADDR_UCSR2B)
#define CHIP_USART_2_DATA_REG_EMPTY_INT_ENABLE_BIT                      5

#define CHIP_USART_2_RX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSR2B)
#define CHIP_USART_2_RX_ENABLE_BIT                                      4
#define CHIP_USART_2_TX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSR2B)
#define CHIP_USART_2_TX_ENABLE_BIT                                      3

#define CHIP_USART_2_RX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSR2B)
#define CHIP_USART_2_RX_DATA_BIT_8_BIT                                  1
#define CHIP_USART_2_TX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSR2B)
#define CHIP_USART_2_TX_DATA_BIT_8_BIT                                  0

#define CHIP_USART_2_MODE_ASYNCHRONOUS_ID                               0
#define CHIP_USART_2_MODE_SYNCHRONOUS_ID                                1
#define CHIP_USART_2_MODE_MASTER_SPI_ID                                 3
#define CHIP_USART_2_MODE_BIT_0_REG                                     REG8(CHIP_ADDR_UCSR2C)
#define CHIP_USART_2_MODE_BIT_1_REG                                     REG8(CHIP_ADDR_UCSR2C)
#define CHIP_USART_2_MODE_BIT_0_BIT                                     6
#define CHIP_USART_2_MODE_BIT_1_BIT                                     7

#define CHIP_USART_2_PARITY_DISABLE_ID                                  0
#define CHIP_USART_2_PARITY_EVEN_ID                                     2
#define CHIP_USART_2_PARITY_ODD_ID                                      3
#define CHIP_USART_2_PARITY_BIT_0_REG                                   REG8(CHIP_ADDR_UCSR2C)
#define CHIP_USART_2_PARITY_BIT_1_REG                                   REG8(CHIP_ADDR_UCSR2C)
#define CHIP_USART_2_PARITY_BIT_0_BIT                                   4
#define CHIP_USART_2_PARITY_BIT_1_BIT                                   5

#define CHIP_USART_2_STOP_BITS_1_ID                                     0
#define CHIP_USART_2_STOP_BITS_2_ID                                     1
#define CHIP_USART_2_STOP_BITS_REG                                      REG8(CHIP_ADDR_UCSR2C)
#define CHIP_USART_2_STOP_BITS_BIT                                      3

#define CHIP_USART_2_CHARACTER_SIZE_5_ID                                0
#define CHIP_USART_2_CHARACTER_SIZE_6_ID                                1
#define CHIP_USART_2_CHARACTER_SIZE_7_ID                                2
#define CHIP_USART_2_CHARACTER_SIZE_8_ID                                3
#define CHIP_USART_2_CHARACTER_SIZE_9_ID                                7
#define CHIP_USART_2_CHARACTER_SIZE_BIT_0_REG                           REG8(CHIP_ADDR_UCSR2C)
#define CHIP_USART_2_CHARACTER_SIZE_BIT_1_REG                           REG8(CHIP_ADDR_UCSR2C)
#define CHIP_USART_2_CHARACTER_SIZE_BIT_2_REG                           REG8(CHIP_ADDR_UCSR2B)
#define CHIP_USART_2_CHARACTER_SIZE_BIT_0_BIT                           1
#define CHIP_USART_2_CHARACTER_SIZE_BIT_1_BIT                           2
#define CHIP_USART_2_CHARACTER_SIZE_BIT_2_BIT                           2

#define CHIP_USART_2_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID             0
#define CHIP_USART_2_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID             1
#define CHIP_USART_2_CLOCK_POLARITY_REG                                 REG8(CHIP_ADDR_UCSR2C)
#define CHIP_USART_2_CLOCK_POLARITY_BIT                                 0

#define CHIP_USART_2_RX_INT_VECTOR                                      VECT(CHIP_VECT_USART2_RX)
#define CHIP_USART_2_DE_INT_VECTOR                                      VECT(CHIP_VECT_USART2_UDRE)
#define CHIP_USART_2_TX_INT_VECTOR                                      VECT(CHIP_VECT_USART2_TX)

//------------------------------------------------
// Usart 3

#define CHIP_USART_3                                                    TRUE

#define CHIP_USART_3_DATA_REG                                           REG8(CHIP_ADDR_UDR3)

#define CHIP_USART_3_BAUD_RATE_REG                                      REG16(CHIP_ADDR_UBRR3L)
#define CHIP_USART_3_BAUD_RATE_REG_HIGH                                 REG8(CHIP_ADDR_UBRR3H)
#define CHIP_USART_3_BAUD_RATE_REG_LOW                                  REG8(CHIP_ADDR_UBRR3L)

#define CHIP_USART_3_FRAME_ERROR_REG                                    REG8(CHIP_ADDR_UCSR3A)
#define CHIP_USART_3_FRAME_ERROR_BIT                                    4
#define CHIP_USART_3_DATA_OVERRUN_REG                                   REG8(CHIP_ADDR_UCSR3A)
#define CHIP_USART_3_DATA_OVERRUN_BIT                                   3
#define CHIP_USART_3_PARITY_ERROR_REG                                   REG8(CHIP_ADDR_UCSR3A)
#define CHIP_USART_3_PARITY_ERROR_BIT                                   2

#define CHIP_USART_3_DOUBLE_SPEED_REG                                   REG8(CHIP_ADDR_UCSR3A)
#define CHIP_USART_3_DOUBLE_SPEED_BIT                                   1

#define CHIP_USART_3_MULTI_PROCESSOR_COMMUNICATION_REG                  REG8(CHIP_ADDR_UCSR3A)
#define CHIP_USART_3_MULTI_PROCESSOR_COMMUNICATION_BIT                  0

#define CHIP_USART_3_RX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSR3B)
#define CHIP_USART_3_RX_COMPLETE_INT_ENABLE_BIT                         7
#define CHIP_USART_3_TX_COMPLETE_INT_ENABLE_REG                         REG8(CHIP_ADDR_UCSR3B)
#define CHIP_USART_3_TX_COMPLETE_INT_ENABLE_BIT                         6
#define CHIP_USART_3_DATA_REG_EMPTY_INT_ENABLE_REG                      REG8(CHIP_ADDR_UCSR3B)
#define CHIP_USART_3_DATA_REG_EMPTY_INT_ENABLE_BIT                      5

#define CHIP_USART_3_RX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSR3B)
#define CHIP_USART_3_RX_ENABLE_BIT                                      4
#define CHIP_USART_3_TX_ENABLE_REG                                      REG8(CHIP_ADDR_UCSR3B)
#define CHIP_USART_3_TX_ENABLE_BIT                                      3

#define CHIP_USART_3_RX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSR3B)
#define CHIP_USART_3_RX_DATA_BIT_8_BIT                                  1
#define CHIP_USART_3_TX_DATA_BIT_8_REG                                  REG8(CHIP_ADDR_UCSR3B)
#define CHIP_USART_3_TX_DATA_BIT_8_BIT                                  0

#define CHIP_USART_3_MODE_ASYNCHRONOUS_ID                               0
#define CHIP_USART_3_MODE_SYNCHRONOUS_ID                                1
#define CHIP_USART_3_MODE_MASTER_SPI_ID                                 3
#define CHIP_USART_3_MODE_BIT_0_REG                                     REG8(CHIP_ADDR_UCSR3C)
#define CHIP_USART_3_MODE_BIT_1_REG                                     REG8(CHIP_ADDR_UCSR3C)
#define CHIP_USART_3_MODE_BIT_0_BIT                                     6
#define CHIP_USART_3_MODE_BIT_1_BIT                                     7

#define CHIP_USART_3_PARITY_DISABLE_ID                                  0
#define CHIP_USART_3_PARITY_EVEN_ID                                     2
#define CHIP_USART_3_PARITY_ODD_ID                                      3
#define CHIP_USART_3_PARITY_BIT_0_REG                                   REG8(CHIP_ADDR_UCSR3C)
#define CHIP_USART_3_PARITY_BIT_1_REG                                   REG8(CHIP_ADDR_UCSR3C)
#define CHIP_USART_3_PARITY_BIT_0_BIT                                   4
#define CHIP_USART_3_PARITY_BIT_1_BIT                                   5

#define CHIP_USART_3_STOP_BITS_1_ID                                     0
#define CHIP_USART_3_STOP_BITS_2_ID                                     1
#define CHIP_USART_3_STOP_BITS_REG                                      REG8(CHIP_ADDR_UCSR3C)
#define CHIP_USART_3_STOP_BITS_BIT                                      3

#define CHIP_USART_3_CHARACTER_SIZE_5_ID                                0
#define CHIP_USART_3_CHARACTER_SIZE_6_ID                                1
#define CHIP_USART_3_CHARACTER_SIZE_7_ID                                2
#define CHIP_USART_3_CHARACTER_SIZE_8_ID                                3
#define CHIP_USART_3_CHARACTER_SIZE_9_ID                                7
#define CHIP_USART_3_CHARACTER_SIZE_BIT_0_REG                           REG8(CHIP_ADDR_UCSR3C)
#define CHIP_USART_3_CHARACTER_SIZE_BIT_1_REG                           REG8(CHIP_ADDR_UCSR3C)
#define CHIP_USART_3_CHARACTER_SIZE_BIT_2_REG                           REG8(CHIP_ADDR_UCSR3B)
#define CHIP_USART_3_CHARACTER_SIZE_BIT_0_BIT                           1
#define CHIP_USART_3_CHARACTER_SIZE_BIT_1_BIT                           2
#define CHIP_USART_3_CHARACTER_SIZE_BIT_2_BIT                           2

#define CHIP_USART_3_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID             0
#define CHIP_USART_3_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID             1
#define CHIP_USART_3_CLOCK_POLARITY_REG                                 REG8(CHIP_ADDR_UCSR3C)
#define CHIP_USART_3_CLOCK_POLARITY_BIT                                 0

#define CHIP_USART_3_RX_INT_VECTOR                                      VECT(CHIP_VECT_USART3_RX)
#define CHIP_USART_3_DE_INT_VECTOR                                      VECT(CHIP_VECT_USART3_UDRE)
#define CHIP_USART_3_TX_INT_VECTOR                                      VECT(CHIP_VECT_USART3_TX)

#endif

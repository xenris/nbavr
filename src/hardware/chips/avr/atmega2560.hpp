#ifndef NBLIB_ATMEGA2560_HPP
#define NBLIB_ATMEGA2560_HPP

#define CHIP atmega2560

//------------------------------------------------
// Registers

#define CHIP_REG_PINA                                               Register<uint8_t, 0x20, 0xFF>
#define CHIP_REG_DDRA                                               Register<uint8_t, 0x21>
#define CHIP_REG_PORTA                                              Register<uint8_t, 0x22>
#define CHIP_REG_PINB                                               Register<uint8_t, 0x23, 0xFF>
#define CHIP_REG_DDRB                                               Register<uint8_t, 0x24>
#define CHIP_REG_PORTB                                              Register<uint8_t, 0x25>
#define CHIP_REG_PINC                                               Register<uint8_t, 0x26, 0xFF>
#define CHIP_REG_DDRC                                               Register<uint8_t, 0x27>
#define CHIP_REG_PORTC                                              Register<uint8_t, 0x28>
#define CHIP_REG_PIND                                               Register<uint8_t, 0x29, 0xFF>
#define CHIP_REG_DDRD                                               Register<uint8_t, 0x2A>
#define CHIP_REG_PORTD                                              Register<uint8_t, 0x2B>
#define CHIP_REG_PINE                                               Register<uint8_t, 0x2C, 0xFF>
#define CHIP_REG_DDRE                                               Register<uint8_t, 0x2D>
#define CHIP_REG_PORTE                                              Register<uint8_t, 0x2E>
#define CHIP_REG_PINF                                               Register<uint8_t, 0x2F, 0xFF>
#define CHIP_REG_DDRF                                               Register<uint8_t, 0x30>
#define CHIP_REG_PORTF                                              Register<uint8_t, 0x31>
#define CHIP_REG_PING                                               Register<uint8_t, 0x32, 0xFF>
#define CHIP_REG_DDRG                                               Register<uint8_t, 0x33>
#define CHIP_REG_PORTG                                              Register<uint8_t, 0x34>
#define CHIP_REG_TIFR0                                              Register<uint8_t, 0x35, 0xFF>
#define CHIP_REG_TIFR1                                              Register<uint8_t, 0x36, 0xFF>
#define CHIP_REG_TIFR2                                              Register<uint8_t, 0x37, 0xFF>
#define CHIP_REG_TIFR3                                              Register<uint8_t, 0x38, 0xFF>
#define CHIP_REG_TIFR4                                              Register<uint8_t, 0x39, 0xFF>
#define CHIP_REG_TIFR5                                              Register<uint8_t, 0x3A, 0xFF>
#define CHIP_REG_PCIFR                                              Register<uint8_t, 0x3B, 0xFF>
#define CHIP_REG_EIFR                                               Register<uint8_t, 0x3C, 0xFF>
#define CHIP_REG_EIMSK                                              Register<uint8_t, 0x3D>
#define CHIP_REG_GPIOR0                                             Register<uint8_t, 0x3E>
#define CHIP_REG_EECR                                               Register<uint8_t, 0x3F>
#define CHIP_REG_EEDR                                               Register<uint8_t, 0x40>
#define CHIP_REG_EEAR                                               Register<uint16_t, 0x41>
#define CHIP_REG_GTCCR                                              Register<uint8_t, 0x43>
#define CHIP_REG_TCCR0A                                             Register<uint8_t, 0x44>
#define CHIP_REG_TCCR0B                                             Register<uint8_t, 0x45>
#define CHIP_REG_TCNT0                                              Register<uint8_t, 0x46>
#define CHIP_REG_OCR0A                                              Register<uint8_t, 0x47>
#define CHIP_REG_OCR0B                                              Register<uint8_t, 0x48>
#define CHIP_REG_GPIOR1                                             Register<uint8_t, 0x4A>
#define CHIP_REG_GPIOR2                                             Register<uint8_t, 0x4B>
#define CHIP_REG_SPCR                                               Register<uint8_t, 0x4C>
#define CHIP_REG_SPSR                                               Register<uint8_t, 0x4D, 0xC0>
#define CHIP_REG_SPDR                                               Register<uint8_t, 0x4E>
#define CHIP_REG_ACSR                                               Register<uint8_t, 0x50>
#define CHIP_REG_OCDR                                               Register<uint8_t, 0x51>
#define CHIP_REG_SMCR                                               Register<uint8_t, 0x53>
#define CHIP_REG_MCUSR                                              Register<uint8_t, 0x54>
#define CHIP_REG_MCUCR                                              Register<uint8_t, 0x55>
#define CHIP_REG_SPMCSR                                             Register<uint8_t, 0x57>
#define CHIP_REG_RAMPZ                                              Register<uint8_t, 0x5B>
#define CHIP_REG_EIND                                               Register<uint8_t, 0x5C>
#define CHIP_REG_SP                                                 Register<uint16_t, 0x5D>
#define CHIP_REG_SREG                                               Register<uint8_t, 0x5F>
#define CHIP_REG_WDTCSR                                             Register<uint8_t, 0x60>
#define CHIP_REG_CLKPR                                              Register<uint8_t, 0x61>
#define CHIP_REG_PRR0                                               Register<uint8_t, 0x64>
#define CHIP_REG_PRR1                                               Register<uint8_t, 0x65>
#define CHIP_REG_OSCCAL                                             Register<uint8_t, 0x66>
#define CHIP_REG_PCICR                                              Register<uint8_t, 0x68>
#define CHIP_REG_EICRA                                              Register<uint8_t, 0x69>
#define CHIP_REG_EICRB                                              Register<uint8_t, 0x6A>
#define CHIP_REG_PCMSK0                                             Register<uint8_t, 0x6B>
#define CHIP_REG_PCMSK1                                             Register<uint8_t, 0x6C>
#define CHIP_REG_PCMSK2                                             Register<uint8_t, 0x6D>
#define CHIP_REG_TIMSK0                                             Register<uint8_t, 0x6E>
#define CHIP_REG_TIMSK1                                             Register<uint8_t, 0x6F>
#define CHIP_REG_TIMSK2                                             Register<uint8_t, 0x70>
#define CHIP_REG_TIMSK3                                             Register<uint8_t, 0x71>
#define CHIP_REG_TIMSK4                                             Register<uint8_t, 0x72>
#define CHIP_REG_TIMSK5                                             Register<uint8_t, 0x73>
#define CHIP_REG_XMCRA                                              Register<uint8_t, 0x74>
#define CHIP_REG_XMCRB                                              Register<uint8_t, 0x75>
#define CHIP_REG_ADC                                                Register<uint16_t, 0x78>
#define CHIP_REG_ADCSRA                                             Register<uint8_t, 0x7A, 0x50>
#define CHIP_REG_ADCSRB                                             Register<uint8_t, 0x7B>
#define CHIP_REG_ADMUX                                              Register<uint8_t, 0x7C>
#define CHIP_REG_DIDR2                                              Register<uint8_t, 0x7D>
#define CHIP_REG_DIDR0                                              Register<uint8_t, 0x7E>
#define CHIP_REG_DIDR1                                              Register<uint8_t, 0x7F>
#define CHIP_REG_TCCR1A                                             Register<uint8_t, 0x80>
#define CHIP_REG_TCCR1B                                             Register<uint8_t, 0x81>
#define CHIP_REG_TCCR1C                                             Register<uint8_t, 0x82>
#define CHIP_REG_TCNT1                                              Register<uint16_t, 0x84>
#define CHIP_REG_ICR1                                               Register<uint16_t, 0x86>
#define CHIP_REG_OCR1A                                              Register<uint16_t, 0x88>
#define CHIP_REG_OCR1B                                              Register<uint16_t, 0x8A>
#define CHIP_REG_OCR1C                                              Register<uint16_t, 0x8C>
#define CHIP_REG_TCCR3A                                             Register<uint8_t, 0x90>
#define CHIP_REG_TCCR3B                                             Register<uint8_t, 0x91>
#define CHIP_REG_TCCR3C                                             Register<uint8_t, 0x92>
#define CHIP_REG_TCNT3                                              Register<uint16_t, 0x94>
#define CHIP_REG_ICR3                                               Register<uint16_t, 0x96>
#define CHIP_REG_OCR3A                                              Register<uint16_t, 0x98>
#define CHIP_REG_OCR3B                                              Register<uint16_t, 0x9A>
#define CHIP_REG_OCR3C                                              Register<uint16_t, 0x9C>
#define CHIP_REG_TCCR4A                                             Register<uint8_t, 0xA0>
#define CHIP_REG_TCCR4B                                             Register<uint8_t, 0xA1>
#define CHIP_REG_TCCR4C                                             Register<uint8_t, 0xA2>
#define CHIP_REG_TCNT4                                              Register<uint16_t, 0xA4>
#define CHIP_REG_ICR4                                               Register<uint16_t, 0xA6>
#define CHIP_REG_OCR4A                                              Register<uint16_t, 0xA8>
#define CHIP_REG_OCR4B                                              Register<uint16_t, 0xAA>
#define CHIP_REG_OCR4C                                              Register<uint16_t, 0xAC>
#define CHIP_REG_TCCR2A                                             Register<uint8_t, 0xB0>
#define CHIP_REG_TCCR2B                                             Register<uint8_t, 0xB1>
#define CHIP_REG_TCNT2                                              Register<uint8_t, 0xB2>
#define CHIP_REG_OCR2A                                              Register<uint8_t, 0xB3>
#define CHIP_REG_OCR2B                                              Register<uint8_t, 0xB4>
#define CHIP_REG_ASSR                                               Register<uint8_t, 0xB6>
#define CHIP_REG_TWBR                                               Register<uint8_t, 0xB8>
#define CHIP_REG_TWSR                                               Register<uint8_t, 0xB9, 0xF8>
#define CHIP_REG_TWAR                                               Register<uint8_t, 0xBA>
#define CHIP_REG_TWDR                                               Register<uint8_t, 0xBB>
#define CHIP_REG_TWCR                                               Register<uint8_t, 0xBC, 0x88>
#define CHIP_REG_TWAMR                                              Register<uint8_t, 0xBD>
#define CHIP_REG_UCSR0A                                             Register<uint8_t, 0xC0, 0xFC>
#define CHIP_REG_UCSR0B                                             Register<uint8_t, 0xC1>
#define CHIP_REG_UCSR0C                                             Register<uint8_t, 0xC2>
#define CHIP_REG_UBRR0                                              Register<uint16_t, 0xC4>
#define CHIP_REG_UDR0                                               Register<uint8_t, 0xC6>
#define CHIP_REG_UCSR1A                                             Register<uint8_t, 0xC8, 0xFC>
#define CHIP_REG_UCSR1B                                             Register<uint8_t, 0xC9>
#define CHIP_REG_UCSR1C                                             Register<uint8_t, 0xCA>
#define CHIP_REG_UBRR1                                              Register<uint16_t, 0xCC>
#define CHIP_REG_UDR1                                               Register<uint8_t, 0xCE>
#define CHIP_REG_UCSR2A                                             Register<uint8_t, 0xD0, 0xFC>
#define CHIP_REG_UCSR2B                                             Register<uint8_t, 0xD1>
#define CHIP_REG_UCSR2C                                             Register<uint8_t, 0xD2>
#define CHIP_REG_UBRR2                                              Register<uint16_t, 0xD4>
#define CHIP_REG_UDR2                                               Register<uint8_t, 0xD6>
#define CHIP_REG_PINH                                               Register<uint8_t, 0x100, 0xFF>
#define CHIP_REG_DDRH                                               Register<uint8_t, 0x101>
#define CHIP_REG_PORTH                                              Register<uint8_t, 0x102>
#define CHIP_REG_PINJ                                               Register<uint8_t, 0x103, 0xFF>
#define CHIP_REG_DDRJ                                               Register<uint8_t, 0x104>
#define CHIP_REG_PORTJ                                              Register<uint8_t, 0x105>
#define CHIP_REG_PINK                                               Register<uint8_t, 0x106, 0xFF>
#define CHIP_REG_DDRK                                               Register<uint8_t, 0x107>
#define CHIP_REG_PORTK                                              Register<uint8_t, 0x108>
#define CHIP_REG_PINL                                               Register<uint8_t, 0x109, 0xFF>
#define CHIP_REG_DDRL                                               Register<uint8_t, 0x10A>
#define CHIP_REG_PORTL                                              Register<uint8_t, 0x10B>
#define CHIP_REG_TCCR5A                                             Register<uint8_t, 0x120>
#define CHIP_REG_TCCR5B                                             Register<uint8_t, 0x121>
#define CHIP_REG_TCCR5C                                             Register<uint8_t, 0x122>
#define CHIP_REG_TCNT5                                              Register<uint16_t, 0x124>
#define CHIP_REG_ICR5                                               Register<uint16_t, 0x126>
#define CHIP_REG_OCR5A                                              Register<uint16_t, 0x128>
#define CHIP_REG_OCR5B                                              Register<uint16_t, 0x12A>
#define CHIP_REG_OCR5C                                              Register<uint16_t, 0x12C>
#define CHIP_REG_UCSR3A                                             Register<uint8_t, 0x130, 0xFC>
#define CHIP_REG_UCSR3B                                             Register<uint8_t, 0x131>
#define CHIP_REG_UCSR3C                                             Register<uint8_t, 0x132>
#define CHIP_REG_UBRR3                                              Register<uint16_t, 0x134>
#define CHIP_REG_UDR3                                               Register<uint8_t, 0x136>

//------------------------------------------------
// Vectors

#define vectorInt0                                                  ISR(__vector_1)
#define vectorInt1                                                  ISR(__vector_2)
#define vectorInt2                                                  ISR(__vector_3)
#define vectorInt3                                                  ISR(__vector_4)
#define vectorInt4                                                  ISR(__vector_5)
#define vectorInt5                                                  ISR(__vector_6)
#define vectorInt6                                                  ISR(__vector_7)
#define vectorInt7                                                  ISR(__vector_8)
#define vectorPcInt0                                                ISR(__vector_9)
#define vectorPcInt1                                                ISR(__vector_10)
#define vectorPcInt2                                                ISR(__vector_11)
#define vectorWatchdogTimeout                                       ISR(__vector_12)
#define vectorTimer2CompareA                                        ISR(__vector_13)
#define vectorTimer2CompareB                                        ISR(__vector_14)
#define vectorTimer2Overflow                                        ISR(__vector_15)
#define vectorTimer1InputCapture                                    ISR(__vector_16)
#define vectorTimer1CompareA                                        ISR(__vector_17)
#define vectorTimer1CompareB                                        ISR(__vector_18)
#define vectorTimer1CompareC                                        ISR(__vector_19)
#define vectorTimer1Overflow                                        ISR(__vector_20)
#define vectorTimer0CompareA                                        ISR(__vector_21)
#define vectorTimer0CompareB                                        ISR(__vector_22)
#define vectorTimer0Overflow                                        ISR(__vector_23)
#define vectorSpi0                                                  ISR(__vector_24)
#define vectorUsart0RxComplete                                      ISR(__vector_25)
#define vectorUsart0DataRegEmpty                                    ISR(__vector_26)
#define vectorUsart0TxComplete                                      ISR(__vector_27)
#define vectorAnalogComparator0                                     ISR(__vector_28)
#define vectorAdc0                                                  ISR(__vector_29)
#define vectorEepromReady                                           ISR(__vector_30)
#define vectorTimer3InputCapture                                    ISR(__vector_31)
#define vectorTimer3CompareA                                        ISR(__vector_32)
#define vectorTimer3CompareB                                        ISR(__vector_33)
#define vectorTimer3CompareC                                        ISR(__vector_34)
#define vectorTimer3Overflow                                        ISR(__vector_35)
#define vectorUsart1RxComplete                                      ISR(__vector_36)
#define vectorUsart1DataRegEmpty                                    ISR(__vector_37)
#define vectorUsart1TxComplete                                      ISR(__vector_38)
#define vectorTwi0                                                  ISR(__vector_39)
#define vectorSpmReady                                              ISR(__vector_40)
#define vectorTimer4InputCapture                                    ISR(__vector_41)
#define vectorTimer4CompareA                                        ISR(__vector_42)
#define vectorTimer4CompareB                                        ISR(__vector_43)
#define vectorTimer4CompareC                                        ISR(__vector_44)
#define vectorTimer4Overflow                                        ISR(__vector_45)
#define vectorTimer5InputCapture                                    ISR(__vector_46)
#define vectorTimer5CompareA                                        ISR(__vector_47)
#define vectorTimer5CompareB                                        ISR(__vector_48)
#define vectorTimer5CompareC                                        ISR(__vector_49)
#define vectorTimer5Overflow                                        ISR(__vector_50)
#define vectorUsart2RxComplete                                      ISR(__vector_51)
#define vectorUsart2DataRegEmpty                                    ISR(__vector_52)
#define vectorUsart2TxComplete                                      ISR(__vector_53)
#define vectorUsart3RxComplete                                      ISR(__vector_54)
#define vectorUsart3DataRegEmpty                                    ISR(__vector_55)
#define vectorUsart3TxComplete                                      ISR(__vector_56)

//------------------------------------------------
// System

#define CHIP_SYSTEM_GLOBAL_INTERRUPT_REG                            CHIP_REG_SREG
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT                            7

//------------------------------------------------
// Sleep

#define CHIP_SLEEP_MODE_REG                                         CHIP_REG_SMCR
#define CHIP_SLEEP_MODE_MASK                                        0x0E
#define CHIP_SLEEP_MODE_IDLE_ID                                     0x00
#define CHIP_SLEEP_MODE_ADC_NOISE_REDUCTION_ID                      0x02
#define CHIP_SLEEP_MODE_POWER_DOWN_ID                               0x04
#define CHIP_SLEEP_MODE_POWER_SAVE_ID                               0x06
#define CHIP_SLEEP_MODE_STANDBY_ID                                  0x0C
#define CHIP_SLEEP_MODE_EXTENDED_STANDBY_ID                         0x0E

#define CHIP_SLEEP_ENABLE_REG                                       CHIP_REG_SMCR
#define CHIP_SLEEP_ENABLE_BIT                                       0

//------------------------------------------------
// IO ports

#define CHIP_PORT_A
#define CHIP_PORT_A_DIRECTION_REG                                   CHIP_REG_DDRA
#define CHIP_PORT_A_OUTPUT_REG                                      CHIP_REG_PORTA
#define CHIP_PORT_A_INPUT_REG                                       CHIP_REG_PINA
#define CHIP_PORT_A_PULLUP_REG                                      CHIP_REG_PORTA
#define CHIP_PORT_A_OUTPUT_TOGGLE_REG                               CHIP_REG_PINA

#define CHIP_PORT_B
#define CHIP_PORT_B_DIRECTION_REG                                   CHIP_REG_DDRB
#define CHIP_PORT_B_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PORT_B_INPUT_REG                                       CHIP_REG_PINB
#define CHIP_PORT_B_PULLUP_REG                                      CHIP_REG_PORTB
#define CHIP_PORT_B_OUTPUT_TOGGLE_REG                               CHIP_REG_PINB

#define CHIP_PORT_C
#define CHIP_PORT_C_DIRECTION_REG                                   CHIP_REG_DDRC
#define CHIP_PORT_C_OUTPUT_REG                                      CHIP_REG_PORTC
#define CHIP_PORT_C_INPUT_REG                                       CHIP_REG_PINC
#define CHIP_PORT_C_PULLUP_REG                                      CHIP_REG_PORTC
#define CHIP_PORT_C_OUTPUT_TOGGLE_REG                               CHIP_REG_PINC

#define CHIP_PORT_D
#define CHIP_PORT_D_DIRECTION_REG                                   CHIP_REG_DDRD
#define CHIP_PORT_D_OUTPUT_REG                                      CHIP_REG_PORTD
#define CHIP_PORT_D_INPUT_REG                                       CHIP_REG_PIND
#define CHIP_PORT_D_PULLUP_REG                                      CHIP_REG_PORTD
#define CHIP_PORT_D_OUTPUT_TOGGLE_REG                               CHIP_REG_PIND

#define CHIP_PORT_E
#define CHIP_PORT_E_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PORT_E_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PORT_E_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PORT_E_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PORT_E_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE

#define CHIP_PORT_F
#define CHIP_PORT_F_DIRECTION_REG                                   CHIP_REG_DDRF
#define CHIP_PORT_F_OUTPUT_REG                                      CHIP_REG_PORTF
#define CHIP_PORT_F_INPUT_REG                                       CHIP_REG_PINF
#define CHIP_PORT_F_PULLUP_REG                                      CHIP_REG_PORTF
#define CHIP_PORT_F_OUTPUT_TOGGLE_REG                               CHIP_REG_PINF

#define CHIP_PORT_G
#define CHIP_PORT_G_DIRECTION_REG                                   CHIP_REG_DDRG
#define CHIP_PORT_G_OUTPUT_REG                                      CHIP_REG_PORTG
#define CHIP_PORT_G_INPUT_REG                                       CHIP_REG_PING
#define CHIP_PORT_G_PULLUP_REG                                      CHIP_REG_PORTG
#define CHIP_PORT_G_OUTPUT_TOGGLE_REG                               CHIP_REG_PING

#define CHIP_PORT_H
#define CHIP_PORT_H_DIRECTION_REG                                   CHIP_REG_DDRH
#define CHIP_PORT_H_OUTPUT_REG                                      CHIP_REG_PORTH
#define CHIP_PORT_H_INPUT_REG                                       CHIP_REG_PINH
#define CHIP_PORT_H_PULLUP_REG                                      CHIP_REG_PORTH
#define CHIP_PORT_H_OUTPUT_TOGGLE_REG                               CHIP_REG_PINH

#define CHIP_PORT_J
#define CHIP_PORT_J_DIRECTION_REG                                   CHIP_REG_DDRJ
#define CHIP_PORT_J_OUTPUT_REG                                      CHIP_REG_PORTJ
#define CHIP_PORT_J_INPUT_REG                                       CHIP_REG_PINJ
#define CHIP_PORT_J_PULLUP_REG                                      CHIP_REG_PORTJ
#define CHIP_PORT_J_OUTPUT_TOGGLE_REG                               CHIP_REG_PINJ

#define CHIP_PORT_K
#define CHIP_PORT_K_DIRECTION_REG                                   CHIP_REG_DDRK
#define CHIP_PORT_K_OUTPUT_REG                                      CHIP_REG_PORTK
#define CHIP_PORT_K_INPUT_REG                                       CHIP_REG_PINK
#define CHIP_PORT_K_PULLUP_REG                                      CHIP_REG_PORTK
#define CHIP_PORT_K_OUTPUT_TOGGLE_REG                               CHIP_REG_PINK

#define CHIP_PORT_L
#define CHIP_PORT_L_DIRECTION_REG                                   CHIP_REG_DDRL
#define CHIP_PORT_L_OUTPUT_REG                                      CHIP_REG_PORTL
#define CHIP_PORT_L_INPUT_REG                                       CHIP_REG_PINL
#define CHIP_PORT_L_PULLUP_REG                                      CHIP_REG_PORTL
#define CHIP_PORT_L_OUTPUT_TOGGLE_REG                               CHIP_REG_PINL
//------------------------------------------------
// IO pins

#define CHIP_PIN_A0
#define CHIP_PIN_A0_DIRECTION_REG                                   CHIP_REG_DDRA
#define CHIP_PIN_A0_DIRECTION_BIT                                   0
#define CHIP_PIN_A0_INPUT_REG                                       CHIP_REG_PINA
#define CHIP_PIN_A0_INPUT_BIT                                       0
#define CHIP_PIN_A0_OUTPUT_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A0_OUTPUT_BIT                                      0
#define CHIP_PIN_A0_OUTPUT_TOGGLE_REG                               CHIP_REG_PINA
#define CHIP_PIN_A0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_A0_PULLUP_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A0_PULLUP_BIT                                      0

#define CHIP_PIN_A1
#define CHIP_PIN_A1_DIRECTION_REG                                   CHIP_REG_DDRA
#define CHIP_PIN_A1_DIRECTION_BIT                                   1
#define CHIP_PIN_A1_INPUT_REG                                       CHIP_REG_PINA
#define CHIP_PIN_A1_INPUT_BIT                                       1
#define CHIP_PIN_A1_OUTPUT_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A1_OUTPUT_BIT                                      1
#define CHIP_PIN_A1_OUTPUT_TOGGLE_REG                               CHIP_REG_PINA
#define CHIP_PIN_A1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_A1_PULLUP_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A1_PULLUP_BIT                                      1

#define CHIP_PIN_A2
#define CHIP_PIN_A2_DIRECTION_REG                                   CHIP_REG_DDRA
#define CHIP_PIN_A2_DIRECTION_BIT                                   2
#define CHIP_PIN_A2_INPUT_REG                                       CHIP_REG_PINA
#define CHIP_PIN_A2_INPUT_BIT                                       2
#define CHIP_PIN_A2_OUTPUT_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A2_OUTPUT_BIT                                      2
#define CHIP_PIN_A2_OUTPUT_TOGGLE_REG                               CHIP_REG_PINA
#define CHIP_PIN_A2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_A2_PULLUP_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A2_PULLUP_BIT                                      2

#define CHIP_PIN_A3
#define CHIP_PIN_A3_DIRECTION_REG                                   CHIP_REG_DDRA
#define CHIP_PIN_A3_DIRECTION_BIT                                   3
#define CHIP_PIN_A3_INPUT_REG                                       CHIP_REG_PINA
#define CHIP_PIN_A3_INPUT_BIT                                       3
#define CHIP_PIN_A3_OUTPUT_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A3_OUTPUT_BIT                                      3
#define CHIP_PIN_A3_OUTPUT_TOGGLE_REG                               CHIP_REG_PINA
#define CHIP_PIN_A3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_A3_PULLUP_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A3_PULLUP_BIT                                      3

#define CHIP_PIN_A4
#define CHIP_PIN_A4_DIRECTION_REG                                   CHIP_REG_DDRA
#define CHIP_PIN_A4_DIRECTION_BIT                                   4
#define CHIP_PIN_A4_INPUT_REG                                       CHIP_REG_PINA
#define CHIP_PIN_A4_INPUT_BIT                                       4
#define CHIP_PIN_A4_OUTPUT_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A4_OUTPUT_BIT                                      4
#define CHIP_PIN_A4_OUTPUT_TOGGLE_REG                               CHIP_REG_PINA
#define CHIP_PIN_A4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_A4_PULLUP_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A4_PULLUP_BIT                                      4

#define CHIP_PIN_A5
#define CHIP_PIN_A5_DIRECTION_REG                                   CHIP_REG_DDRA
#define CHIP_PIN_A5_DIRECTION_BIT                                   5
#define CHIP_PIN_A5_INPUT_REG                                       CHIP_REG_PINA
#define CHIP_PIN_A5_INPUT_BIT                                       5
#define CHIP_PIN_A5_OUTPUT_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A5_OUTPUT_BIT                                      5
#define CHIP_PIN_A5_OUTPUT_TOGGLE_REG                               CHIP_REG_PINA
#define CHIP_PIN_A5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_A5_PULLUP_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A5_PULLUP_BIT                                      5

#define CHIP_PIN_A6
#define CHIP_PIN_A6_DIRECTION_REG                                   CHIP_REG_DDRA
#define CHIP_PIN_A6_DIRECTION_BIT                                   6
#define CHIP_PIN_A6_INPUT_REG                                       CHIP_REG_PINA
#define CHIP_PIN_A6_INPUT_BIT                                       6
#define CHIP_PIN_A6_OUTPUT_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A6_OUTPUT_BIT                                      6
#define CHIP_PIN_A6_OUTPUT_TOGGLE_REG                               CHIP_REG_PINA
#define CHIP_PIN_A6_OUTPUT_TOGGLE_BIT                               6
#define CHIP_PIN_A6_PULLUP_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A6_PULLUP_BIT                                      6

#define CHIP_PIN_A7
#define CHIP_PIN_A7_DIRECTION_REG                                   CHIP_REG_DDRA
#define CHIP_PIN_A7_DIRECTION_BIT                                   7
#define CHIP_PIN_A7_INPUT_REG                                       CHIP_REG_PINA
#define CHIP_PIN_A7_INPUT_BIT                                       7
#define CHIP_PIN_A7_OUTPUT_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A7_OUTPUT_BIT                                      7
#define CHIP_PIN_A7_OUTPUT_TOGGLE_REG                               CHIP_REG_PINA
#define CHIP_PIN_A7_OUTPUT_TOGGLE_BIT                               7
#define CHIP_PIN_A7_PULLUP_REG                                      CHIP_REG_PORTA
#define CHIP_PIN_A7_PULLUP_BIT                                      7

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

#define CHIP_PIN_B6
#define CHIP_PIN_B6_DIRECTION_REG                                   CHIP_REG_DDRB
#define CHIP_PIN_B6_DIRECTION_BIT                                   6
#define CHIP_PIN_B6_INPUT_REG                                       CHIP_REG_PINB
#define CHIP_PIN_B6_INPUT_BIT                                       6
#define CHIP_PIN_B6_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B6_OUTPUT_BIT                                      6
#define CHIP_PIN_B6_OUTPUT_TOGGLE_REG                               CHIP_REG_PINB
#define CHIP_PIN_B6_OUTPUT_TOGGLE_BIT                               6
#define CHIP_PIN_B6_PULLUP_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B6_PULLUP_BIT                                      6

#define CHIP_PIN_B7
#define CHIP_PIN_B7_DIRECTION_REG                                   CHIP_REG_DDRB
#define CHIP_PIN_B7_DIRECTION_BIT                                   7
#define CHIP_PIN_B7_INPUT_REG                                       CHIP_REG_PINB
#define CHIP_PIN_B7_INPUT_BIT                                       7
#define CHIP_PIN_B7_OUTPUT_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B7_OUTPUT_BIT                                      7
#define CHIP_PIN_B7_OUTPUT_TOGGLE_REG                               CHIP_REG_PINB
#define CHIP_PIN_B7_OUTPUT_TOGGLE_BIT                               7
#define CHIP_PIN_B7_PULLUP_REG                                      CHIP_REG_PORTB
#define CHIP_PIN_B7_PULLUP_BIT                                      7

#define CHIP_PIN_C0
#define CHIP_PIN_C0_DIRECTION_REG                                   CHIP_REG_DDRC
#define CHIP_PIN_C0_DIRECTION_BIT                                   0
#define CHIP_PIN_C0_INPUT_REG                                       CHIP_REG_PINC
#define CHIP_PIN_C0_INPUT_BIT                                       0
#define CHIP_PIN_C0_OUTPUT_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C0_OUTPUT_BIT                                      0
#define CHIP_PIN_C0_OUTPUT_TOGGLE_REG                               CHIP_REG_PINC
#define CHIP_PIN_C0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_C0_PULLUP_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C0_PULLUP_BIT                                      0

#define CHIP_PIN_C1
#define CHIP_PIN_C1_DIRECTION_REG                                   CHIP_REG_DDRC
#define CHIP_PIN_C1_DIRECTION_BIT                                   1
#define CHIP_PIN_C1_INPUT_REG                                       CHIP_REG_PINC
#define CHIP_PIN_C1_INPUT_BIT                                       1
#define CHIP_PIN_C1_OUTPUT_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C1_OUTPUT_BIT                                      1
#define CHIP_PIN_C1_OUTPUT_TOGGLE_REG                               CHIP_REG_PINC
#define CHIP_PIN_C1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_C1_PULLUP_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C1_PULLUP_BIT                                      1

#define CHIP_PIN_C2
#define CHIP_PIN_C2_DIRECTION_REG                                   CHIP_REG_DDRC
#define CHIP_PIN_C2_DIRECTION_BIT                                   2
#define CHIP_PIN_C2_INPUT_REG                                       CHIP_REG_PINC
#define CHIP_PIN_C2_INPUT_BIT                                       2
#define CHIP_PIN_C2_OUTPUT_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C2_OUTPUT_BIT                                      2
#define CHIP_PIN_C2_OUTPUT_TOGGLE_REG                               CHIP_REG_PINC
#define CHIP_PIN_C2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_C2_PULLUP_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C2_PULLUP_BIT                                      2

#define CHIP_PIN_C3
#define CHIP_PIN_C3_DIRECTION_REG                                   CHIP_REG_DDRC
#define CHIP_PIN_C3_DIRECTION_BIT                                   3
#define CHIP_PIN_C3_INPUT_REG                                       CHIP_REG_PINC
#define CHIP_PIN_C3_INPUT_BIT                                       3
#define CHIP_PIN_C3_OUTPUT_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C3_OUTPUT_BIT                                      3
#define CHIP_PIN_C3_OUTPUT_TOGGLE_REG                               CHIP_REG_PINC
#define CHIP_PIN_C3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_C3_PULLUP_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C3_PULLUP_BIT                                      3

#define CHIP_PIN_C4
#define CHIP_PIN_C4_DIRECTION_REG                                   CHIP_REG_DDRC
#define CHIP_PIN_C4_DIRECTION_BIT                                   4
#define CHIP_PIN_C4_INPUT_REG                                       CHIP_REG_PINC
#define CHIP_PIN_C4_INPUT_BIT                                       4
#define CHIP_PIN_C4_OUTPUT_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C4_OUTPUT_BIT                                      4
#define CHIP_PIN_C4_OUTPUT_TOGGLE_REG                               CHIP_REG_PINC
#define CHIP_PIN_C4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_C4_PULLUP_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C4_PULLUP_BIT                                      4

#define CHIP_PIN_C5
#define CHIP_PIN_C5_DIRECTION_REG                                   CHIP_REG_DDRC
#define CHIP_PIN_C5_DIRECTION_BIT                                   5
#define CHIP_PIN_C5_INPUT_REG                                       CHIP_REG_PINC
#define CHIP_PIN_C5_INPUT_BIT                                       5
#define CHIP_PIN_C5_OUTPUT_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C5_OUTPUT_BIT                                      5
#define CHIP_PIN_C5_OUTPUT_TOGGLE_REG                               CHIP_REG_PINC
#define CHIP_PIN_C5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_C5_PULLUP_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C5_PULLUP_BIT                                      5

#define CHIP_PIN_C6
#define CHIP_PIN_C6_DIRECTION_REG                                   CHIP_REG_DDRC
#define CHIP_PIN_C6_DIRECTION_BIT                                   6
#define CHIP_PIN_C6_INPUT_REG                                       CHIP_REG_PINC
#define CHIP_PIN_C6_INPUT_BIT                                       6
#define CHIP_PIN_C6_OUTPUT_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C6_OUTPUT_BIT                                      6
#define CHIP_PIN_C6_OUTPUT_TOGGLE_REG                               CHIP_REG_PINC
#define CHIP_PIN_C6_OUTPUT_TOGGLE_BIT                               6
#define CHIP_PIN_C6_PULLUP_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C6_PULLUP_BIT                                      6

#define CHIP_PIN_C7
#define CHIP_PIN_C7_DIRECTION_REG                                   CHIP_REG_DDRC
#define CHIP_PIN_C7_DIRECTION_BIT                                   7
#define CHIP_PIN_C7_INPUT_REG                                       CHIP_REG_PINC
#define CHIP_PIN_C7_INPUT_BIT                                       7
#define CHIP_PIN_C7_OUTPUT_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C7_OUTPUT_BIT                                      7
#define CHIP_PIN_C7_OUTPUT_TOGGLE_REG                               CHIP_REG_PINC
#define CHIP_PIN_C7_OUTPUT_TOGGLE_BIT                               7
#define CHIP_PIN_C7_PULLUP_REG                                      CHIP_REG_PORTC
#define CHIP_PIN_C7_PULLUP_BIT                                      7

#define CHIP_PIN_D0
#define CHIP_PIN_D0_DIRECTION_REG                                   CHIP_REG_DDRD
#define CHIP_PIN_D0_DIRECTION_BIT                                   0
#define CHIP_PIN_D0_INPUT_REG                                       CHIP_REG_PIND
#define CHIP_PIN_D0_INPUT_BIT                                       0
#define CHIP_PIN_D0_OUTPUT_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D0_OUTPUT_BIT                                      0
#define CHIP_PIN_D0_OUTPUT_TOGGLE_REG                               CHIP_REG_PIND
#define CHIP_PIN_D0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_D0_PULLUP_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D0_PULLUP_BIT                                      0

#define CHIP_PIN_D1
#define CHIP_PIN_D1_DIRECTION_REG                                   CHIP_REG_DDRD
#define CHIP_PIN_D1_DIRECTION_BIT                                   1
#define CHIP_PIN_D1_INPUT_REG                                       CHIP_REG_PIND
#define CHIP_PIN_D1_INPUT_BIT                                       1
#define CHIP_PIN_D1_OUTPUT_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D1_OUTPUT_BIT                                      1
#define CHIP_PIN_D1_OUTPUT_TOGGLE_REG                               CHIP_REG_PIND
#define CHIP_PIN_D1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_D1_PULLUP_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D1_PULLUP_BIT                                      1

#define CHIP_PIN_D2
#define CHIP_PIN_D2_DIRECTION_REG                                   CHIP_REG_DDRD
#define CHIP_PIN_D2_DIRECTION_BIT                                   2
#define CHIP_PIN_D2_INPUT_REG                                       CHIP_REG_PIND
#define CHIP_PIN_D2_INPUT_BIT                                       2
#define CHIP_PIN_D2_OUTPUT_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D2_OUTPUT_BIT                                      2
#define CHIP_PIN_D2_OUTPUT_TOGGLE_REG                               CHIP_REG_PIND
#define CHIP_PIN_D2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_D2_PULLUP_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D2_PULLUP_BIT                                      2

#define CHIP_PIN_D3
#define CHIP_PIN_D3_DIRECTION_REG                                   CHIP_REG_DDRD
#define CHIP_PIN_D3_DIRECTION_BIT                                   3
#define CHIP_PIN_D3_INPUT_REG                                       CHIP_REG_PIND
#define CHIP_PIN_D3_INPUT_BIT                                       3
#define CHIP_PIN_D3_OUTPUT_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D3_OUTPUT_BIT                                      3
#define CHIP_PIN_D3_OUTPUT_TOGGLE_REG                               CHIP_REG_PIND
#define CHIP_PIN_D3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_D3_PULLUP_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D3_PULLUP_BIT                                      3

#define CHIP_PIN_D4
#define CHIP_PIN_D4_DIRECTION_REG                                   CHIP_REG_DDRD
#define CHIP_PIN_D4_DIRECTION_BIT                                   4
#define CHIP_PIN_D4_INPUT_REG                                       CHIP_REG_PIND
#define CHIP_PIN_D4_INPUT_BIT                                       4
#define CHIP_PIN_D4_OUTPUT_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D4_OUTPUT_BIT                                      4
#define CHIP_PIN_D4_OUTPUT_TOGGLE_REG                               CHIP_REG_PIND
#define CHIP_PIN_D4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_D4_PULLUP_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D4_PULLUP_BIT                                      4

#define CHIP_PIN_D5
#define CHIP_PIN_D5_DIRECTION_REG                                   CHIP_REG_DDRD
#define CHIP_PIN_D5_DIRECTION_BIT                                   5
#define CHIP_PIN_D5_INPUT_REG                                       CHIP_REG_PIND
#define CHIP_PIN_D5_INPUT_BIT                                       5
#define CHIP_PIN_D5_OUTPUT_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D5_OUTPUT_BIT                                      5
#define CHIP_PIN_D5_OUTPUT_TOGGLE_REG                               CHIP_REG_PIND
#define CHIP_PIN_D5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_D5_PULLUP_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D5_PULLUP_BIT                                      5

#define CHIP_PIN_D6
#define CHIP_PIN_D6_DIRECTION_REG                                   CHIP_REG_DDRD
#define CHIP_PIN_D6_DIRECTION_BIT                                   6
#define CHIP_PIN_D6_INPUT_REG                                       CHIP_REG_PIND
#define CHIP_PIN_D6_INPUT_BIT                                       6
#define CHIP_PIN_D6_OUTPUT_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D6_OUTPUT_BIT                                      6
#define CHIP_PIN_D6_OUTPUT_TOGGLE_REG                               CHIP_REG_PIND
#define CHIP_PIN_D6_OUTPUT_TOGGLE_BIT                               6
#define CHIP_PIN_D6_PULLUP_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D6_PULLUP_BIT                                      6

#define CHIP_PIN_D7
#define CHIP_PIN_D7_DIRECTION_REG                                   CHIP_REG_DDRD
#define CHIP_PIN_D7_DIRECTION_BIT                                   7
#define CHIP_PIN_D7_INPUT_REG                                       CHIP_REG_PIND
#define CHIP_PIN_D7_INPUT_BIT                                       7
#define CHIP_PIN_D7_OUTPUT_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D7_OUTPUT_BIT                                      7
#define CHIP_PIN_D7_OUTPUT_TOGGLE_REG                               CHIP_REG_PIND
#define CHIP_PIN_D7_OUTPUT_TOGGLE_BIT                               7
#define CHIP_PIN_D7_PULLUP_REG                                      CHIP_REG_PORTD
#define CHIP_PIN_D7_PULLUP_BIT                                      7

#define CHIP_PIN_E0
#define CHIP_PIN_E0_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E0_DIRECTION_BIT                                   0
#define CHIP_PIN_E0_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E0_INPUT_BIT                                       0
#define CHIP_PIN_E0_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E0_OUTPUT_BIT                                      0
#define CHIP_PIN_E0_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_E0_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E0_PULLUP_BIT                                      0

#define CHIP_PIN_E1
#define CHIP_PIN_E1_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E1_DIRECTION_BIT                                   1
#define CHIP_PIN_E1_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E1_INPUT_BIT                                       1
#define CHIP_PIN_E1_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E1_OUTPUT_BIT                                      1
#define CHIP_PIN_E1_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_E1_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E1_PULLUP_BIT                                      1

#define CHIP_PIN_E2
#define CHIP_PIN_E2_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E2_DIRECTION_BIT                                   2
#define CHIP_PIN_E2_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E2_INPUT_BIT                                       2
#define CHIP_PIN_E2_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E2_OUTPUT_BIT                                      2
#define CHIP_PIN_E2_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_E2_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E2_PULLUP_BIT                                      2

#define CHIP_PIN_E3
#define CHIP_PIN_E3_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E3_DIRECTION_BIT                                   3
#define CHIP_PIN_E3_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E3_INPUT_BIT                                       3
#define CHIP_PIN_E3_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E3_OUTPUT_BIT                                      3
#define CHIP_PIN_E3_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_E3_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E3_PULLUP_BIT                                      3

#define CHIP_PIN_E4
#define CHIP_PIN_E4_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E4_DIRECTION_BIT                                   4
#define CHIP_PIN_E4_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E4_INPUT_BIT                                       4
#define CHIP_PIN_E4_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E4_OUTPUT_BIT                                      4
#define CHIP_PIN_E4_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_E4_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E4_PULLUP_BIT                                      4

#define CHIP_PIN_E5
#define CHIP_PIN_E5_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E5_DIRECTION_BIT                                   5
#define CHIP_PIN_E5_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E5_INPUT_BIT                                       5
#define CHIP_PIN_E5_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E5_OUTPUT_BIT                                      5
#define CHIP_PIN_E5_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_E5_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E5_PULLUP_BIT                                      5

#define CHIP_PIN_E6
#define CHIP_PIN_E6_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E6_DIRECTION_BIT                                   6
#define CHIP_PIN_E6_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E6_INPUT_BIT                                       6
#define CHIP_PIN_E6_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E6_OUTPUT_BIT                                      6
#define CHIP_PIN_E6_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E6_OUTPUT_TOGGLE_BIT                               6
#define CHIP_PIN_E6_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E6_PULLUP_BIT                                      6

#define CHIP_PIN_E7
#define CHIP_PIN_E7_DIRECTION_REG                                   CHIP_REG_DDRE
#define CHIP_PIN_E7_DIRECTION_BIT                                   7
#define CHIP_PIN_E7_INPUT_REG                                       CHIP_REG_PINE
#define CHIP_PIN_E7_INPUT_BIT                                       7
#define CHIP_PIN_E7_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E7_OUTPUT_BIT                                      7
#define CHIP_PIN_E7_OUTPUT_TOGGLE_REG                               CHIP_REG_PINE
#define CHIP_PIN_E7_OUTPUT_TOGGLE_BIT                               7
#define CHIP_PIN_E7_PULLUP_REG                                      CHIP_REG_PORTE
#define CHIP_PIN_E7_PULLUP_BIT                                      7

#define CHIP_PIN_F0
#define CHIP_PIN_F0_DIRECTION_REG                                   CHIP_REG_DDRF
#define CHIP_PIN_F0_DIRECTION_BIT                                   0
#define CHIP_PIN_F0_INPUT_REG                                       CHIP_REG_PINF
#define CHIP_PIN_F0_INPUT_BIT                                       0
#define CHIP_PIN_F0_OUTPUT_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F0_OUTPUT_BIT                                      0
#define CHIP_PIN_F0_OUTPUT_TOGGLE_REG                               CHIP_REG_PINF
#define CHIP_PIN_F0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_F0_PULLUP_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F0_PULLUP_BIT                                      0

#define CHIP_PIN_F1
#define CHIP_PIN_F1_DIRECTION_REG                                   CHIP_REG_DDRF
#define CHIP_PIN_F1_DIRECTION_BIT                                   1
#define CHIP_PIN_F1_INPUT_REG                                       CHIP_REG_PINF
#define CHIP_PIN_F1_INPUT_BIT                                       1
#define CHIP_PIN_F1_OUTPUT_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F1_OUTPUT_BIT                                      1
#define CHIP_PIN_F1_OUTPUT_TOGGLE_REG                               CHIP_REG_PINF
#define CHIP_PIN_F1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_F1_PULLUP_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F1_PULLUP_BIT                                      1

#define CHIP_PIN_F2
#define CHIP_PIN_F2_DIRECTION_REG                                   CHIP_REG_DDRF
#define CHIP_PIN_F2_DIRECTION_BIT                                   2
#define CHIP_PIN_F2_INPUT_REG                                       CHIP_REG_PINF
#define CHIP_PIN_F2_INPUT_BIT                                       2
#define CHIP_PIN_F2_OUTPUT_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F2_OUTPUT_BIT                                      2
#define CHIP_PIN_F2_OUTPUT_TOGGLE_REG                               CHIP_REG_PINF
#define CHIP_PIN_F2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_F2_PULLUP_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F2_PULLUP_BIT                                      2

#define CHIP_PIN_F3
#define CHIP_PIN_F3_DIRECTION_REG                                   CHIP_REG_DDRF
#define CHIP_PIN_F3_DIRECTION_BIT                                   3
#define CHIP_PIN_F3_INPUT_REG                                       CHIP_REG_PINF
#define CHIP_PIN_F3_INPUT_BIT                                       3
#define CHIP_PIN_F3_OUTPUT_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F3_OUTPUT_BIT                                      3
#define CHIP_PIN_F3_OUTPUT_TOGGLE_REG                               CHIP_REG_PINF
#define CHIP_PIN_F3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_F3_PULLUP_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F3_PULLUP_BIT                                      3

#define CHIP_PIN_F4
#define CHIP_PIN_F4_DIRECTION_REG                                   CHIP_REG_DDRF
#define CHIP_PIN_F4_DIRECTION_BIT                                   4
#define CHIP_PIN_F4_INPUT_REG                                       CHIP_REG_PINF
#define CHIP_PIN_F4_INPUT_BIT                                       4
#define CHIP_PIN_F4_OUTPUT_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F4_OUTPUT_BIT                                      4
#define CHIP_PIN_F4_OUTPUT_TOGGLE_REG                               CHIP_REG_PINF
#define CHIP_PIN_F4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_F4_PULLUP_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F4_PULLUP_BIT                                      4

#define CHIP_PIN_F5
#define CHIP_PIN_F5_DIRECTION_REG                                   CHIP_REG_DDRF
#define CHIP_PIN_F5_DIRECTION_BIT                                   5
#define CHIP_PIN_F5_INPUT_REG                                       CHIP_REG_PINF
#define CHIP_PIN_F5_INPUT_BIT                                       5
#define CHIP_PIN_F5_OUTPUT_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F5_OUTPUT_BIT                                      5
#define CHIP_PIN_F5_OUTPUT_TOGGLE_REG                               CHIP_REG_PINF
#define CHIP_PIN_F5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_F5_PULLUP_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F5_PULLUP_BIT                                      5

#define CHIP_PIN_F6
#define CHIP_PIN_F6_DIRECTION_REG                                   CHIP_REG_DDRF
#define CHIP_PIN_F6_DIRECTION_BIT                                   6
#define CHIP_PIN_F6_INPUT_REG                                       CHIP_REG_PINF
#define CHIP_PIN_F6_INPUT_BIT                                       6
#define CHIP_PIN_F6_OUTPUT_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F6_OUTPUT_BIT                                      6
#define CHIP_PIN_F6_OUTPUT_TOGGLE_REG                               CHIP_REG_PINF
#define CHIP_PIN_F6_OUTPUT_TOGGLE_BIT                               6
#define CHIP_PIN_F6_PULLUP_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F6_PULLUP_BIT                                      6

#define CHIP_PIN_F7
#define CHIP_PIN_F7_DIRECTION_REG                                   CHIP_REG_DDRF
#define CHIP_PIN_F7_DIRECTION_BIT                                   7
#define CHIP_PIN_F7_INPUT_REG                                       CHIP_REG_PINF
#define CHIP_PIN_F7_INPUT_BIT                                       7
#define CHIP_PIN_F7_OUTPUT_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F7_OUTPUT_BIT                                      7
#define CHIP_PIN_F7_OUTPUT_TOGGLE_REG                               CHIP_REG_PINF
#define CHIP_PIN_F7_OUTPUT_TOGGLE_BIT                               7
#define CHIP_PIN_F7_PULLUP_REG                                      CHIP_REG_PORTF
#define CHIP_PIN_F7_PULLUP_BIT                                      7

#define CHIP_PIN_G0
#define CHIP_PIN_G0_DIRECTION_REG                                   CHIP_REG_DDRG
#define CHIP_PIN_G0_DIRECTION_BIT                                   0
#define CHIP_PIN_G0_INPUT_REG                                       CHIP_REG_PING
#define CHIP_PIN_G0_INPUT_BIT                                       0
#define CHIP_PIN_G0_OUTPUT_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G0_OUTPUT_BIT                                      0
#define CHIP_PIN_G0_OUTPUT_TOGGLE_REG                               CHIP_REG_PING
#define CHIP_PIN_G0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_G0_PULLUP_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G0_PULLUP_BIT                                      0

#define CHIP_PIN_G1
#define CHIP_PIN_G1_DIRECTION_REG                                   CHIP_REG_DDRG
#define CHIP_PIN_G1_DIRECTION_BIT                                   1
#define CHIP_PIN_G1_INPUT_REG                                       CHIP_REG_PING
#define CHIP_PIN_G1_INPUT_BIT                                       1
#define CHIP_PIN_G1_OUTPUT_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G1_OUTPUT_BIT                                      1
#define CHIP_PIN_G1_OUTPUT_TOGGLE_REG                               CHIP_REG_PING
#define CHIP_PIN_G1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_G1_PULLUP_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G1_PULLUP_BIT                                      1

#define CHIP_PIN_G2
#define CHIP_PIN_G2_DIRECTION_REG                                   CHIP_REG_DDRG
#define CHIP_PIN_G2_DIRECTION_BIT                                   2
#define CHIP_PIN_G2_INPUT_REG                                       CHIP_REG_PING
#define CHIP_PIN_G2_INPUT_BIT                                       2
#define CHIP_PIN_G2_OUTPUT_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G2_OUTPUT_BIT                                      2
#define CHIP_PIN_G2_OUTPUT_TOGGLE_REG                               CHIP_REG_PING
#define CHIP_PIN_G2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_G2_PULLUP_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G2_PULLUP_BIT                                      2

#define CHIP_PIN_G3
#define CHIP_PIN_G3_DIRECTION_REG                                   CHIP_REG_DDRG
#define CHIP_PIN_G3_DIRECTION_BIT                                   3
#define CHIP_PIN_G3_INPUT_REG                                       CHIP_REG_PING
#define CHIP_PIN_G3_INPUT_BIT                                       3
#define CHIP_PIN_G3_OUTPUT_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G3_OUTPUT_BIT                                      3
#define CHIP_PIN_G3_OUTPUT_TOGGLE_REG                               CHIP_REG_PING
#define CHIP_PIN_G3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_G3_PULLUP_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G3_PULLUP_BIT                                      3

#define CHIP_PIN_G4
#define CHIP_PIN_G4_DIRECTION_REG                                   CHIP_REG_DDRG
#define CHIP_PIN_G4_DIRECTION_BIT                                   4
#define CHIP_PIN_G4_INPUT_REG                                       CHIP_REG_PING
#define CHIP_PIN_G4_INPUT_BIT                                       4
#define CHIP_PIN_G4_OUTPUT_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G4_OUTPUT_BIT                                      4
#define CHIP_PIN_G4_OUTPUT_TOGGLE_REG                               CHIP_REG_PING
#define CHIP_PIN_G4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_G4_PULLUP_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G4_PULLUP_BIT                                      4

#define CHIP_PIN_G5
#define CHIP_PIN_G5_DIRECTION_REG                                   CHIP_REG_DDRG
#define CHIP_PIN_G5_DIRECTION_BIT                                   5
#define CHIP_PIN_G5_INPUT_REG                                       CHIP_REG_PING
#define CHIP_PIN_G5_INPUT_BIT                                       5
#define CHIP_PIN_G5_OUTPUT_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G5_OUTPUT_BIT                                      5
#define CHIP_PIN_G5_OUTPUT_TOGGLE_REG                               CHIP_REG_PING
#define CHIP_PIN_G5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_G5_PULLUP_REG                                      CHIP_REG_PORTG
#define CHIP_PIN_G5_PULLUP_BIT                                      5

#define CHIP_PIN_H0
#define CHIP_PIN_H0_DIRECTION_REG                                   CHIP_REG_DDRH
#define CHIP_PIN_H0_DIRECTION_BIT                                   0
#define CHIP_PIN_H0_INPUT_REG                                       CHIP_REG_PINH
#define CHIP_PIN_H0_INPUT_BIT                                       0
#define CHIP_PIN_H0_OUTPUT_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H0_OUTPUT_BIT                                      0
#define CHIP_PIN_H0_OUTPUT_TOGGLE_REG                               CHIP_REG_PINH
#define CHIP_PIN_H0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_H0_PULLUP_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H0_PULLUP_BIT                                      0

#define CHIP_PIN_H1
#define CHIP_PIN_H1_DIRECTION_REG                                   CHIP_REG_DDRH
#define CHIP_PIN_H1_DIRECTION_BIT                                   1
#define CHIP_PIN_H1_INPUT_REG                                       CHIP_REG_PINH
#define CHIP_PIN_H1_INPUT_BIT                                       1
#define CHIP_PIN_H1_OUTPUT_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H1_OUTPUT_BIT                                      1
#define CHIP_PIN_H1_OUTPUT_TOGGLE_REG                               CHIP_REG_PINH
#define CHIP_PIN_H1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_H1_PULLUP_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H1_PULLUP_BIT                                      1

#define CHIP_PIN_H2
#define CHIP_PIN_H2_DIRECTION_REG                                   CHIP_REG_DDRH
#define CHIP_PIN_H2_DIRECTION_BIT                                   2
#define CHIP_PIN_H2_INPUT_REG                                       CHIP_REG_PINH
#define CHIP_PIN_H2_INPUT_BIT                                       2
#define CHIP_PIN_H2_OUTPUT_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H2_OUTPUT_BIT                                      2
#define CHIP_PIN_H2_OUTPUT_TOGGLE_REG                               CHIP_REG_PINH
#define CHIP_PIN_H2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_H2_PULLUP_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H2_PULLUP_BIT                                      2

#define CHIP_PIN_H3
#define CHIP_PIN_H3_DIRECTION_REG                                   CHIP_REG_DDRH
#define CHIP_PIN_H3_DIRECTION_BIT                                   3
#define CHIP_PIN_H3_INPUT_REG                                       CHIP_REG_PINH
#define CHIP_PIN_H3_INPUT_BIT                                       3
#define CHIP_PIN_H3_OUTPUT_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H3_OUTPUT_BIT                                      3
#define CHIP_PIN_H3_OUTPUT_TOGGLE_REG                               CHIP_REG_PINH
#define CHIP_PIN_H3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_H3_PULLUP_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H3_PULLUP_BIT                                      3

#define CHIP_PIN_H4
#define CHIP_PIN_H4_DIRECTION_REG                                   CHIP_REG_DDRH
#define CHIP_PIN_H4_DIRECTION_BIT                                   4
#define CHIP_PIN_H4_INPUT_REG                                       CHIP_REG_PINH
#define CHIP_PIN_H4_INPUT_BIT                                       4
#define CHIP_PIN_H4_OUTPUT_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H4_OUTPUT_BIT                                      4
#define CHIP_PIN_H4_OUTPUT_TOGGLE_REG                               CHIP_REG_PINH
#define CHIP_PIN_H4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_H4_PULLUP_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H4_PULLUP_BIT                                      4

#define CHIP_PIN_H5
#define CHIP_PIN_H5_DIRECTION_REG                                   CHIP_REG_DDRH
#define CHIP_PIN_H5_DIRECTION_BIT                                   5
#define CHIP_PIN_H5_INPUT_REG                                       CHIP_REG_PINH
#define CHIP_PIN_H5_INPUT_BIT                                       5
#define CHIP_PIN_H5_OUTPUT_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H5_OUTPUT_BIT                                      5
#define CHIP_PIN_H5_OUTPUT_TOGGLE_REG                               CHIP_REG_PINH
#define CHIP_PIN_H5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_H5_PULLUP_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H5_PULLUP_BIT                                      5

#define CHIP_PIN_H6
#define CHIP_PIN_H6_DIRECTION_REG                                   CHIP_REG_DDRH
#define CHIP_PIN_H6_DIRECTION_BIT                                   6
#define CHIP_PIN_H6_INPUT_REG                                       CHIP_REG_PINH
#define CHIP_PIN_H6_INPUT_BIT                                       6
#define CHIP_PIN_H6_OUTPUT_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H6_OUTPUT_BIT                                      6
#define CHIP_PIN_H6_OUTPUT_TOGGLE_REG                               CHIP_REG_PINH
#define CHIP_PIN_H6_OUTPUT_TOGGLE_BIT                               6
#define CHIP_PIN_H6_PULLUP_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H6_PULLUP_BIT                                      6

#define CHIP_PIN_H7
#define CHIP_PIN_H7_DIRECTION_REG                                   CHIP_REG_DDRH
#define CHIP_PIN_H7_DIRECTION_BIT                                   7
#define CHIP_PIN_H7_INPUT_REG                                       CHIP_REG_PINH
#define CHIP_PIN_H7_INPUT_BIT                                       7
#define CHIP_PIN_H7_OUTPUT_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H7_OUTPUT_BIT                                      7
#define CHIP_PIN_H7_OUTPUT_TOGGLE_REG                               CHIP_REG_PINH
#define CHIP_PIN_H7_OUTPUT_TOGGLE_BIT                               7
#define CHIP_PIN_H7_PULLUP_REG                                      CHIP_REG_PORTH
#define CHIP_PIN_H7_PULLUP_BIT                                      7

#define CHIP_PIN_J0
#define CHIP_PIN_J0_DIRECTION_REG                                   CHIP_REG_DDRJ
#define CHIP_PIN_J0_DIRECTION_BIT                                   0
#define CHIP_PIN_J0_INPUT_REG                                       CHIP_REG_PINJ
#define CHIP_PIN_J0_INPUT_BIT                                       0
#define CHIP_PIN_J0_OUTPUT_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J0_OUTPUT_BIT                                      0
#define CHIP_PIN_J0_OUTPUT_TOGGLE_REG                               CHIP_REG_PINJ
#define CHIP_PIN_J0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_J0_PULLUP_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J0_PULLUP_BIT                                      0

#define CHIP_PIN_J1
#define CHIP_PIN_J1_DIRECTION_REG                                   CHIP_REG_DDRJ
#define CHIP_PIN_J1_DIRECTION_BIT                                   1
#define CHIP_PIN_J1_INPUT_REG                                       CHIP_REG_PINJ
#define CHIP_PIN_J1_INPUT_BIT                                       1
#define CHIP_PIN_J1_OUTPUT_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J1_OUTPUT_BIT                                      1
#define CHIP_PIN_J1_OUTPUT_TOGGLE_REG                               CHIP_REG_PINJ
#define CHIP_PIN_J1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_J1_PULLUP_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J1_PULLUP_BIT                                      1

#define CHIP_PIN_J2
#define CHIP_PIN_J2_DIRECTION_REG                                   CHIP_REG_DDRJ
#define CHIP_PIN_J2_DIRECTION_BIT                                   2
#define CHIP_PIN_J2_INPUT_REG                                       CHIP_REG_PINJ
#define CHIP_PIN_J2_INPUT_BIT                                       2
#define CHIP_PIN_J2_OUTPUT_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J2_OUTPUT_BIT                                      2
#define CHIP_PIN_J2_OUTPUT_TOGGLE_REG                               CHIP_REG_PINJ
#define CHIP_PIN_J2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_J2_PULLUP_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J2_PULLUP_BIT                                      2

#define CHIP_PIN_J3
#define CHIP_PIN_J3_DIRECTION_REG                                   CHIP_REG_DDRJ
#define CHIP_PIN_J3_DIRECTION_BIT                                   3
#define CHIP_PIN_J3_INPUT_REG                                       CHIP_REG_PINJ
#define CHIP_PIN_J3_INPUT_BIT                                       3
#define CHIP_PIN_J3_OUTPUT_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J3_OUTPUT_BIT                                      3
#define CHIP_PIN_J3_OUTPUT_TOGGLE_REG                               CHIP_REG_PINJ
#define CHIP_PIN_J3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_J3_PULLUP_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J3_PULLUP_BIT                                      3

#define CHIP_PIN_J4
#define CHIP_PIN_J4_DIRECTION_REG                                   CHIP_REG_DDRJ
#define CHIP_PIN_J4_DIRECTION_BIT                                   4
#define CHIP_PIN_J4_INPUT_REG                                       CHIP_REG_PINJ
#define CHIP_PIN_J4_INPUT_BIT                                       4
#define CHIP_PIN_J4_OUTPUT_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J4_OUTPUT_BIT                                      4
#define CHIP_PIN_J4_OUTPUT_TOGGLE_REG                               CHIP_REG_PINJ
#define CHIP_PIN_J4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_J4_PULLUP_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J4_PULLUP_BIT                                      4

#define CHIP_PIN_J5
#define CHIP_PIN_J5_DIRECTION_REG                                   CHIP_REG_DDRJ
#define CHIP_PIN_J5_DIRECTION_BIT                                   5
#define CHIP_PIN_J5_INPUT_REG                                       CHIP_REG_PINJ
#define CHIP_PIN_J5_INPUT_BIT                                       5
#define CHIP_PIN_J5_OUTPUT_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J5_OUTPUT_BIT                                      5
#define CHIP_PIN_J5_OUTPUT_TOGGLE_REG                               CHIP_REG_PINJ
#define CHIP_PIN_J5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_J5_PULLUP_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J5_PULLUP_BIT                                      5

#define CHIP_PIN_J6
#define CHIP_PIN_J6_DIRECTION_REG                                   CHIP_REG_DDRJ
#define CHIP_PIN_J6_DIRECTION_BIT                                   6
#define CHIP_PIN_J6_INPUT_REG                                       CHIP_REG_PINJ
#define CHIP_PIN_J6_INPUT_BIT                                       6
#define CHIP_PIN_J6_OUTPUT_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J6_OUTPUT_BIT                                      6
#define CHIP_PIN_J6_OUTPUT_TOGGLE_REG                               CHIP_REG_PINJ
#define CHIP_PIN_J6_OUTPUT_TOGGLE_BIT                               6
#define CHIP_PIN_J6_PULLUP_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J6_PULLUP_BIT                                      6

#define CHIP_PIN_J7
#define CHIP_PIN_J7_DIRECTION_REG                                   CHIP_REG_DDRJ
#define CHIP_PIN_J7_DIRECTION_BIT                                   7
#define CHIP_PIN_J7_INPUT_REG                                       CHIP_REG_PINJ
#define CHIP_PIN_J7_INPUT_BIT                                       7
#define CHIP_PIN_J7_OUTPUT_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J7_OUTPUT_BIT                                      7
#define CHIP_PIN_J7_OUTPUT_TOGGLE_REG                               CHIP_REG_PINJ
#define CHIP_PIN_J7_OUTPUT_TOGGLE_BIT                               7
#define CHIP_PIN_J7_PULLUP_REG                                      CHIP_REG_PORTJ
#define CHIP_PIN_J7_PULLUP_BIT                                      7

#define CHIP_PIN_K0
#define CHIP_PIN_K0_DIRECTION_REG                                   CHIP_REG_DDRK
#define CHIP_PIN_K0_DIRECTION_BIT                                   0
#define CHIP_PIN_K0_INPUT_REG                                       CHIP_REG_PINK
#define CHIP_PIN_K0_INPUT_BIT                                       0
#define CHIP_PIN_K0_OUTPUT_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K0_OUTPUT_BIT                                      0
#define CHIP_PIN_K0_OUTPUT_TOGGLE_REG                               CHIP_REG_PINK
#define CHIP_PIN_K0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_K0_PULLUP_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K0_PULLUP_BIT                                      0

#define CHIP_PIN_K1
#define CHIP_PIN_K1_DIRECTION_REG                                   CHIP_REG_DDRK
#define CHIP_PIN_K1_DIRECTION_BIT                                   1
#define CHIP_PIN_K1_INPUT_REG                                       CHIP_REG_PINK
#define CHIP_PIN_K1_INPUT_BIT                                       1
#define CHIP_PIN_K1_OUTPUT_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K1_OUTPUT_BIT                                      1
#define CHIP_PIN_K1_OUTPUT_TOGGLE_REG                               CHIP_REG_PINK
#define CHIP_PIN_K1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_K1_PULLUP_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K1_PULLUP_BIT                                      1

#define CHIP_PIN_K2
#define CHIP_PIN_K2_DIRECTION_REG                                   CHIP_REG_DDRK
#define CHIP_PIN_K2_DIRECTION_BIT                                   2
#define CHIP_PIN_K2_INPUT_REG                                       CHIP_REG_PINK
#define CHIP_PIN_K2_INPUT_BIT                                       2
#define CHIP_PIN_K2_OUTPUT_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K2_OUTPUT_BIT                                      2
#define CHIP_PIN_K2_OUTPUT_TOGGLE_REG                               CHIP_REG_PINK
#define CHIP_PIN_K2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_K2_PULLUP_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K2_PULLUP_BIT                                      2

#define CHIP_PIN_K3
#define CHIP_PIN_K3_DIRECTION_REG                                   CHIP_REG_DDRK
#define CHIP_PIN_K3_DIRECTION_BIT                                   3
#define CHIP_PIN_K3_INPUT_REG                                       CHIP_REG_PINK
#define CHIP_PIN_K3_INPUT_BIT                                       3
#define CHIP_PIN_K3_OUTPUT_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K3_OUTPUT_BIT                                      3
#define CHIP_PIN_K3_OUTPUT_TOGGLE_REG                               CHIP_REG_PINK
#define CHIP_PIN_K3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_K3_PULLUP_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K3_PULLUP_BIT                                      3

#define CHIP_PIN_K4
#define CHIP_PIN_K4_DIRECTION_REG                                   CHIP_REG_DDRK
#define CHIP_PIN_K4_DIRECTION_BIT                                   4
#define CHIP_PIN_K4_INPUT_REG                                       CHIP_REG_PINK
#define CHIP_PIN_K4_INPUT_BIT                                       4
#define CHIP_PIN_K4_OUTPUT_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K4_OUTPUT_BIT                                      4
#define CHIP_PIN_K4_OUTPUT_TOGGLE_REG                               CHIP_REG_PINK
#define CHIP_PIN_K4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_K4_PULLUP_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K4_PULLUP_BIT                                      4

#define CHIP_PIN_K5
#define CHIP_PIN_K5_DIRECTION_REG                                   CHIP_REG_DDRK
#define CHIP_PIN_K5_DIRECTION_BIT                                   5
#define CHIP_PIN_K5_INPUT_REG                                       CHIP_REG_PINK
#define CHIP_PIN_K5_INPUT_BIT                                       5
#define CHIP_PIN_K5_OUTPUT_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K5_OUTPUT_BIT                                      5
#define CHIP_PIN_K5_OUTPUT_TOGGLE_REG                               CHIP_REG_PINK
#define CHIP_PIN_K5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_K5_PULLUP_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K5_PULLUP_BIT                                      5

#define CHIP_PIN_K6
#define CHIP_PIN_K6_DIRECTION_REG                                   CHIP_REG_DDRK
#define CHIP_PIN_K6_DIRECTION_BIT                                   6
#define CHIP_PIN_K6_INPUT_REG                                       CHIP_REG_PINK
#define CHIP_PIN_K6_INPUT_BIT                                       6
#define CHIP_PIN_K6_OUTPUT_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K6_OUTPUT_BIT                                      6
#define CHIP_PIN_K6_OUTPUT_TOGGLE_REG                               CHIP_REG_PINK
#define CHIP_PIN_K6_OUTPUT_TOGGLE_BIT                               6
#define CHIP_PIN_K6_PULLUP_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K6_PULLUP_BIT                                      6

#define CHIP_PIN_K7
#define CHIP_PIN_K7_DIRECTION_REG                                   CHIP_REG_DDRK
#define CHIP_PIN_K7_DIRECTION_BIT                                   7
#define CHIP_PIN_K7_INPUT_REG                                       CHIP_REG_PINK
#define CHIP_PIN_K7_INPUT_BIT                                       7
#define CHIP_PIN_K7_OUTPUT_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K7_OUTPUT_BIT                                      7
#define CHIP_PIN_K7_OUTPUT_TOGGLE_REG                               CHIP_REG_PINK
#define CHIP_PIN_K7_OUTPUT_TOGGLE_BIT                               7
#define CHIP_PIN_K7_PULLUP_REG                                      CHIP_REG_PORTK
#define CHIP_PIN_K7_PULLUP_BIT                                      7

#define CHIP_PIN_L0
#define CHIP_PIN_L0_DIRECTION_REG                                   CHIP_REG_DDRL
#define CHIP_PIN_L0_DIRECTION_BIT                                   0
#define CHIP_PIN_L0_INPUT_REG                                       CHIP_REG_PINL
#define CHIP_PIN_L0_INPUT_BIT                                       0
#define CHIP_PIN_L0_OUTPUT_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L0_OUTPUT_BIT                                      0
#define CHIP_PIN_L0_OUTPUT_TOGGLE_REG                               CHIP_REG_PINL
#define CHIP_PIN_L0_OUTPUT_TOGGLE_BIT                               0
#define CHIP_PIN_L0_PULLUP_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L0_PULLUP_BIT                                      0

#define CHIP_PIN_L1
#define CHIP_PIN_L1_DIRECTION_REG                                   CHIP_REG_DDRL
#define CHIP_PIN_L1_DIRECTION_BIT                                   1
#define CHIP_PIN_L1_INPUT_REG                                       CHIP_REG_PINL
#define CHIP_PIN_L1_INPUT_BIT                                       1
#define CHIP_PIN_L1_OUTPUT_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L1_OUTPUT_BIT                                      1
#define CHIP_PIN_L1_OUTPUT_TOGGLE_REG                               CHIP_REG_PINL
#define CHIP_PIN_L1_OUTPUT_TOGGLE_BIT                               1
#define CHIP_PIN_L1_PULLUP_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L1_PULLUP_BIT                                      1

#define CHIP_PIN_L2
#define CHIP_PIN_L2_DIRECTION_REG                                   CHIP_REG_DDRL
#define CHIP_PIN_L2_DIRECTION_BIT                                   2
#define CHIP_PIN_L2_INPUT_REG                                       CHIP_REG_PINL
#define CHIP_PIN_L2_INPUT_BIT                                       2
#define CHIP_PIN_L2_OUTPUT_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L2_OUTPUT_BIT                                      2
#define CHIP_PIN_L2_OUTPUT_TOGGLE_REG                               CHIP_REG_PINL
#define CHIP_PIN_L2_OUTPUT_TOGGLE_BIT                               2
#define CHIP_PIN_L2_PULLUP_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L2_PULLUP_BIT                                      2

#define CHIP_PIN_L3
#define CHIP_PIN_L3_DIRECTION_REG                                   CHIP_REG_DDRL
#define CHIP_PIN_L3_DIRECTION_BIT                                   3
#define CHIP_PIN_L3_INPUT_REG                                       CHIP_REG_PINL
#define CHIP_PIN_L3_INPUT_BIT                                       3
#define CHIP_PIN_L3_OUTPUT_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L3_OUTPUT_BIT                                      3
#define CHIP_PIN_L3_OUTPUT_TOGGLE_REG                               CHIP_REG_PINL
#define CHIP_PIN_L3_OUTPUT_TOGGLE_BIT                               3
#define CHIP_PIN_L3_PULLUP_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L3_PULLUP_BIT                                      3

#define CHIP_PIN_L4
#define CHIP_PIN_L4_DIRECTION_REG                                   CHIP_REG_DDRL
#define CHIP_PIN_L4_DIRECTION_BIT                                   4
#define CHIP_PIN_L4_INPUT_REG                                       CHIP_REG_PINL
#define CHIP_PIN_L4_INPUT_BIT                                       4
#define CHIP_PIN_L4_OUTPUT_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L4_OUTPUT_BIT                                      4
#define CHIP_PIN_L4_OUTPUT_TOGGLE_REG                               CHIP_REG_PINL
#define CHIP_PIN_L4_OUTPUT_TOGGLE_BIT                               4
#define CHIP_PIN_L4_PULLUP_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L4_PULLUP_BIT                                      4

#define CHIP_PIN_L5
#define CHIP_PIN_L5_DIRECTION_REG                                   CHIP_REG_DDRL
#define CHIP_PIN_L5_DIRECTION_BIT                                   5
#define CHIP_PIN_L5_INPUT_REG                                       CHIP_REG_PINL
#define CHIP_PIN_L5_INPUT_BIT                                       5
#define CHIP_PIN_L5_OUTPUT_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L5_OUTPUT_BIT                                      5
#define CHIP_PIN_L5_OUTPUT_TOGGLE_REG                               CHIP_REG_PINL
#define CHIP_PIN_L5_OUTPUT_TOGGLE_BIT                               5
#define CHIP_PIN_L5_PULLUP_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L5_PULLUP_BIT                                      5

#define CHIP_PIN_L6
#define CHIP_PIN_L6_DIRECTION_REG                                   CHIP_REG_DDRL
#define CHIP_PIN_L6_DIRECTION_BIT                                   6
#define CHIP_PIN_L6_INPUT_REG                                       CHIP_REG_PINL
#define CHIP_PIN_L6_INPUT_BIT                                       6
#define CHIP_PIN_L6_OUTPUT_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L6_OUTPUT_BIT                                      6
#define CHIP_PIN_L6_OUTPUT_TOGGLE_REG                               CHIP_REG_PINL
#define CHIP_PIN_L6_OUTPUT_TOGGLE_BIT                               6
#define CHIP_PIN_L6_PULLUP_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L6_PULLUP_BIT                                      6

#define CHIP_PIN_L7
#define CHIP_PIN_L7_DIRECTION_REG                                   CHIP_REG_DDRL
#define CHIP_PIN_L7_DIRECTION_BIT                                   7
#define CHIP_PIN_L7_INPUT_REG                                       CHIP_REG_PINL
#define CHIP_PIN_L7_INPUT_BIT                                       7
#define CHIP_PIN_L7_OUTPUT_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L7_OUTPUT_BIT                                      7
#define CHIP_PIN_L7_OUTPUT_TOGGLE_REG                               CHIP_REG_PINL
#define CHIP_PIN_L7_OUTPUT_TOGGLE_BIT                               7
#define CHIP_PIN_L7_PULLUP_REG                                      CHIP_REG_PORTL
#define CHIP_PIN_L7_PULLUP_BIT                                      7

//------------------------------------------------
// Analog to digital converters

#define CHIP_ADC_0

#define CHIP_ADC_0_RESULT_REG                                       CHIP_REG_ADC

#define CHIP_ADC_0_ENABLE_REG                                       CHIP_REG_ADCSRA
#define CHIP_ADC_0_ENABLE_BIT                                       7

#define CHIP_ADC_0_START_REG                                        CHIP_REG_ADCSRA
#define CHIP_ADC_0_START_BIT                                        6

#define CHIP_ADC_0_REFERENCE_REG                                    CHIP_REG_ADMUX
#define CHIP_ADC_0_REFERENCE_MASK                                   0xC0
#define CHIP_ADC_0_REFERENCE_AREF_ID                                0x00
#define CHIP_ADC_0_REFERENCE_AVCC_ID                                0x40
#define CHIP_ADC_0_REFERENCE_INTERNAL_1_1_ID                        0x80
#define CHIP_ADC_0_REFERENCE_INTERNAL_2_56_ID                       0xC0

#define CHIP_ADC_0_CHANNEL_REG                                      CHIP_REG_ADMUX
#define CHIP_ADC_0_CHANNEL_REG_EXTENDED                             CHIP_REG_ADCSRB
#define CHIP_ADC_0_CHANNEL_MASK                                     0x1F
#define CHIP_ADC_0_CHANNEL_MASK_EXTENDED                            0x08
#define CHIP_ADC_0_CHANNEL_0_ID                                     0x0000
#define CHIP_ADC_0_CHANNEL_1_ID                                     0x0001
#define CHIP_ADC_0_CHANNEL_2_ID                                     0x0002
#define CHIP_ADC_0_CHANNEL_3_ID                                     0x0003
#define CHIP_ADC_0_CHANNEL_4_ID                                     0x0004
#define CHIP_ADC_0_CHANNEL_5_ID                                     0x0005
#define CHIP_ADC_0_CHANNEL_6_ID                                     0x0006
#define CHIP_ADC_0_CHANNEL_7_ID                                     0x0007
#define CHIP_ADC_0_CHANNEL_0_0_10X_ID                               0x0008
#define CHIP_ADC_0_CHANNEL_1_0_10X_ID                               0x0009
#define CHIP_ADC_0_CHANNEL_0_0_200X_ID                              0x000A
#define CHIP_ADC_0_CHANNEL_1_0_200X_ID                              0x000B
#define CHIP_ADC_0_CHANNEL_2_2_10X_ID                               0x000C
#define CHIP_ADC_0_CHANNEL_3_2_10X_ID                               0x000D
#define CHIP_ADC_0_CHANNEL_2_2_200X_ID                              0x000E
#define CHIP_ADC_0_CHANNEL_3_2_200X_ID                              0x000F
#define CHIP_ADC_0_CHANNEL_0_1_1X_ID                                0x0010
#define CHIP_ADC_0_CHANNEL_1_1_1X_ID                                0x0011
#define CHIP_ADC_0_CHANNEL_2_1_1X_ID                                0x0012
#define CHIP_ADC_0_CHANNEL_3_1_1X_ID                                0x0013
#define CHIP_ADC_0_CHANNEL_4_1_1X_ID                                0x0014
#define CHIP_ADC_0_CHANNEL_5_1_1X_ID                                0x0015
#define CHIP_ADC_0_CHANNEL_6_1_1X_ID                                0x0016
#define CHIP_ADC_0_CHANNEL_7_1_1X_ID                                0x0017
#define CHIP_ADC_0_CHANNEL_0_2_1X_ID                                0x0018
#define CHIP_ADC_0_CHANNEL_1_2_1X_ID                                0x0019
#define CHIP_ADC_0_CHANNEL_2_2_1X_ID                                0x001A
#define CHIP_ADC_0_CHANNEL_3_2_1X_ID                                0x001B
#define CHIP_ADC_0_CHANNEL_4_2_1X_ID                                0x001C
#define CHIP_ADC_0_CHANNEL_5_2_1X_ID                                0x001D
#define CHIP_ADC_0_CHANNEL_VBG_ID                                   0x001E
#define CHIP_ADC_0_CHANNEL_GND_ID                                   0x001F
#define CHIP_ADC_0_CHANNEL_8_ID                                     0x0100
#define CHIP_ADC_0_CHANNEL_9_ID                                     0x0101
#define CHIP_ADC_0_CHANNEL_10_ID                                    0x0102
#define CHIP_ADC_0_CHANNEL_11_ID                                    0x0103
#define CHIP_ADC_0_CHANNEL_12_ID                                    0x0104
#define CHIP_ADC_0_CHANNEL_13_ID                                    0x0105
#define CHIP_ADC_0_CHANNEL_14_ID                                    0x0106
#define CHIP_ADC_0_CHANNEL_15_ID                                    0x0107

#define CHIP_ADC_0_TRIGGER_ENABLE_REG                               CHIP_REG_ADCSRA
#define CHIP_ADC_0_TRIGGER_ENABLE_BIT                               5

#define CHIP_ADC_0_TRIGGER_REG                                      CHIP_REG_ADCSRB
#define CHIP_ADC_0_TRIGGER_MASK                                     0x07
#define CHIP_ADC_0_TRIGGER_FREE_RUNNING_ID                          0x00
#define CHIP_ADC_0_TRIGGER_ANALOG_COMPARATOR_ID                     0x01
#define CHIP_ADC_0_TRIGGER_EXTERNAL_INT_0_ID                        0x02
#define CHIP_ADC_0_TRIGGER_TIMER0_COMPARE_MATCH_A_ID                0x03
#define CHIP_ADC_0_TRIGGER_TIMER0_OVERFLOW_ID                       0x04
#define CHIP_ADC_0_TRIGGER_TIMER1_COMPARE_MATCH_B_ID                0x05
#define CHIP_ADC_0_TRIGGER_TIMER1_OVERFLOW_ID                       0x06
#define CHIP_ADC_0_TRIGGER_TIMER1_CAPTURE_EVENT_ID                  0x07

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

//------------------------------------------------
// External Interrupts

#define CHIP_EXINT_0
#define CHIP_EXINT_0_ENABLE_REG                                     CHIP_REG_EIMSK
#define CHIP_EXINT_0_ENABLE_BIT                                     0
#define CHIP_EXINT_0_INT_FLAG_REG                                   CHIP_REG_EIFR
#define CHIP_EXINT_0_INT_FLAG_BIT                                   0
#define CHIP_EXINT_0_TRIGGER_REG                                    CHIP_REG_EICRA
#define CHIP_EXINT_0_TRIGGER_MASK                                   0x03
#define CHIP_EXINT_0_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_0_TRIGGER_CHANGE_ID                              0x01
#define CHIP_EXINT_0_TRIGGER_FALLING_ID                             0x02
#define CHIP_EXINT_0_TRIGGER_RISING_ID                              0x03

#define CHIP_EXINT_1
#define CHIP_EXINT_1_ENABLE_REG                                     CHIP_REG_EIMSK
#define CHIP_EXINT_1_ENABLE_BIT                                     1
#define CHIP_EXINT_1_INT_FLAG_REG                                   CHIP_REG_EIFR
#define CHIP_EXINT_1_INT_FLAG_BIT                                   1
#define CHIP_EXINT_1_TRIGGER_REG                                    CHIP_REG_EICRA
#define CHIP_EXINT_1_TRIGGER_MASK                                   0x0C
#define CHIP_EXINT_1_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_1_TRIGGER_CHANGE_ID                              0x04
#define CHIP_EXINT_1_TRIGGER_FALLING_ID                             0x08
#define CHIP_EXINT_1_TRIGGER_RISING_ID                              0x0C

#define CHIP_EXINT_2
#define CHIP_EXINT_2_ENABLE_REG                                     CHIP_REG_EIMSK
#define CHIP_EXINT_2_ENABLE_BIT                                     2
#define CHIP_EXINT_2_INT_FLAG_REG                                   CHIP_REG_EIFR
#define CHIP_EXINT_2_INT_FLAG_BIT                                   2
#define CHIP_EXINT_2_TRIGGER_REG                                    CHIP_REG_EICRA
#define CHIP_EXINT_2_TRIGGER_MASK                                   0x30
#define CHIP_EXINT_2_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_2_TRIGGER_CHANGE_ID                              0x10
#define CHIP_EXINT_2_TRIGGER_FALLING_ID                             0x20
#define CHIP_EXINT_2_TRIGGER_RISING_ID                              0x30

#define CHIP_EXINT_3
#define CHIP_EXINT_3_ENABLE_REG                                     CHIP_REG_EIMSK
#define CHIP_EXINT_3_ENABLE_BIT                                     3
#define CHIP_EXINT_3_INT_FLAG_REG                                   CHIP_REG_EIFR
#define CHIP_EXINT_3_INT_FLAG_BIT                                   3
#define CHIP_EXINT_3_TRIGGER_REG                                    CHIP_REG_EICRA
#define CHIP_EXINT_3_TRIGGER_MASK                                   0xC0
#define CHIP_EXINT_3_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_3_TRIGGER_CHANGE_ID                              0x40
#define CHIP_EXINT_3_TRIGGER_FALLING_ID                             0x80
#define CHIP_EXINT_3_TRIGGER_RISING_ID                              0xC0

#define CHIP_EXINT_4
#define CHIP_EXINT_4_ENABLE_REG                                     CHIP_REG_EIMSK
#define CHIP_EXINT_4_ENABLE_BIT                                     4
#define CHIP_EXINT_4_INT_FLAG_REG                                   CHIP_REG_EIFR
#define CHIP_EXINT_4_INT_FLAG_BIT                                   4
#define CHIP_EXINT_4_TRIGGER_REG                                    CHIP_REG_EICRB
#define CHIP_EXINT_4_TRIGGER_MASK                                   0x03
#define CHIP_EXINT_4_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_4_TRIGGER_CHANGE_ID                              0x01
#define CHIP_EXINT_4_TRIGGER_FALLING_ID                             0x02
#define CHIP_EXINT_4_TRIGGER_RISING_ID                              0x03

#define CHIP_EXINT_5
#define CHIP_EXINT_5_ENABLE_REG                                     CHIP_REG_EIMSK
#define CHIP_EXINT_5_ENABLE_BIT                                     5
#define CHIP_EXINT_5_INT_FLAG_REG                                   CHIP_REG_EIFR
#define CHIP_EXINT_5_INT_FLAG_BIT                                   5
#define CHIP_EXINT_5_TRIGGER_REG                                    CHIP_REG_EICRB
#define CHIP_EXINT_5_TRIGGER_MASK                                   0x0C
#define CHIP_EXINT_5_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_5_TRIGGER_CHANGE_ID                              0x04
#define CHIP_EXINT_5_TRIGGER_FALLING_ID                             0x08
#define CHIP_EXINT_5_TRIGGER_RISING_ID                              0x0C

#define CHIP_EXINT_6
#define CHIP_EXINT_6_ENABLE_REG                                     CHIP_REG_EIMSK
#define CHIP_EXINT_6_ENABLE_BIT                                     6
#define CHIP_EXINT_6_INT_FLAG_REG                                   CHIP_REG_EIFR
#define CHIP_EXINT_6_INT_FLAG_BIT                                   6
#define CHIP_EXINT_6_TRIGGER_REG                                    CHIP_REG_EICRB
#define CHIP_EXINT_6_TRIGGER_MASK                                   0x30
#define CHIP_EXINT_6_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_6_TRIGGER_CHANGE_ID                              0x10
#define CHIP_EXINT_6_TRIGGER_FALLING_ID                             0x20
#define CHIP_EXINT_6_TRIGGER_RISING_ID                              0x30

#define CHIP_EXINT_7
#define CHIP_EXINT_7_ENABLE_REG                                     CHIP_REG_EIMSK
#define CHIP_EXINT_7_ENABLE_BIT                                     7
#define CHIP_EXINT_7_INT_FLAG_REG                                   CHIP_REG_EIFR
#define CHIP_EXINT_7_INT_FLAG_BIT                                   7
#define CHIP_EXINT_7_TRIGGER_REG                                    CHIP_REG_EICRB
#define CHIP_EXINT_7_TRIGGER_MASK                                   0xC0
#define CHIP_EXINT_7_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_7_TRIGGER_CHANGE_ID                              0x40
#define CHIP_EXINT_7_TRIGGER_FALLING_ID                             0x80
#define CHIP_EXINT_7_TRIGGER_RISING_ID                              0xC0

//------------------------------------------------
// Pin Change Interrupts

#define CHIP_PCINT_0
#define CHIP_PCINT_0_ENABLE_REG                                     CHIP_REG_PCICR
#define CHIP_PCINT_0_ENABLE_BIT                                     0
#define CHIP_PCINT_0_INT_FLAG_REG                                   CHIP_REG_PCIFR
#define CHIP_PCINT_0_INT_FLAG_BIT                                   0
#define CHIP_PCINT_0_MASK_REG                                       CHIP_REG_PCMSK0

#define CHIP_PCINT_1
#define CHIP_PCINT_1_ENABLE_REG                                     CHIP_REG_PCICR
#define CHIP_PCINT_1_ENABLE_BIT                                     1
#define CHIP_PCINT_1_INT_FLAG_REG                                   CHIP_REG_PCIFR
#define CHIP_PCINT_1_INT_FLAG_BIT                                   1
#define CHIP_PCINT_1_MASK_REG                                       CHIP_REG_PCMSK1

#define CHIP_PCINT_2
#define CHIP_PCINT_2_ENABLE_REG                                     CHIP_REG_PCICR
#define CHIP_PCINT_2_ENABLE_BIT                                     2
#define CHIP_PCINT_2_INT_FLAG_REG                                   CHIP_REG_PCIFR
#define CHIP_PCINT_2_INT_FLAG_BIT                                   2
#define CHIP_PCINT_2_MASK_REG                                       CHIP_REG_PCMSK2

//------------------------------------------------
// Timer Counters

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
#define CHIP_TIMER_0_COMPARE_A_INT_ENABLE_REG                       CHIP_REG_TIMSK0
#define CHIP_TIMER_0_COMPARE_A_INT_ENABLE_BIT                       1
#define CHIP_TIMER_0_COMPARE_A_INT_FLAG_REG                         CHIP_REG_TIFR0
#define CHIP_TIMER_0_COMPARE_A_INT_FLAG_BIT                         1
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_REG                           CHIP_REG_TCCR0A
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_MASK                          0xC0
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_TOGGLE_ID                     0x40
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_CLEAR_ID                      0x80
#define CHIP_TIMER_0_COMPARE_A_OUTPUT_SET_ID                        0xC0

#define CHIP_TIMER_0_COMPARE_B_REG                                  CHIP_REG_OCR0B
#define CHIP_TIMER_0_COMPARE_B_INT_ENABLE_REG                       CHIP_REG_TIMSK0
#define CHIP_TIMER_0_COMPARE_B_INT_ENABLE_BIT                       2
#define CHIP_TIMER_0_COMPARE_B_INT_FLAG_REG                         CHIP_REG_TIFR0
#define CHIP_TIMER_0_COMPARE_B_INT_FLAG_BIT                         2
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_REG                           CHIP_REG_TCCR0A
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_MASK                          0x30
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_TOGGLE_ID                     0x10
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_CLEAR_ID                      0x20
#define CHIP_TIMER_0_COMPARE_B_OUTPUT_SET_ID                        0x30

#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK0
#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR0
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_BIT                          0

//------------------------------------------------

#define CHIP_TIMER_1

#define CHIP_TIMER_1_WAVEFORM_REG                                   CHIP_REG_TCCR1A
#define CHIP_TIMER_1_WAVEFORM_MASK                                  0x03
#define CHIP_TIMER_1_WAVEFORM_REG_EXTRA                             CHIP_REG_TCCR1B
#define CHIP_TIMER_1_WAVEFORM_MASK_EXTRA                            0x18
#define CHIP_TIMER_1_WAVEFORM_NORMAL_ID                             0x0000
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_8_ID                0x0001
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_9_ID                0x0002
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_10_ID               0x0003
#define CHIP_TIMER_1_WAVEFORM_CTC_OCRA_ID                           0x0800
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_8_ID                         0x0801
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_9_ID                         0x0802
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_10_ID                        0x0803
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID             0x1000
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID        0x1001
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_ID                  0x1002
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             0x1003
#define CHIP_TIMER_1_WAVEFORM_CTC_ICR_ID                            0x1800
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_ID                           0x1802
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_OCRA_ID                      0x1803

#define CHIP_TIMER_1_CLOCK_REG                                      CHIP_REG_TCCR1B
#define CHIP_TIMER_1_CLOCK_MASK                                     0x07
#define CHIP_TIMER_1_CLOCK_NONE_ID                                  0x00
#define CHIP_TIMER_1_CLOCK_1_ID                                     0x01
#define CHIP_TIMER_1_CLOCK_8_ID                                     0x02
#define CHIP_TIMER_1_CLOCK_64_ID                                    0x03
#define CHIP_TIMER_1_CLOCK_256_ID                                   0x04
#define CHIP_TIMER_1_CLOCK_1024_ID                                  0x05
#define CHIP_TIMER_1_CLOCK_EXT_FALLING_ID                           0x06
#define CHIP_TIMER_1_CLOCK_EXT_RISING_ID                            0x07

#define CHIP_TIMER_1_COUNTER_REG                                    CHIP_REG_TCNT1

#define CHIP_TIMER_1_PRESCALER_RESET_REG                            CHIP_REG_GTCCR
#define CHIP_TIMER_1_PRESCALER_RESET_BIT                            0

#define CHIP_TIMER_1_SYNCHRONIZE_REG                                CHIP_REG_GTCCR
#define CHIP_TIMER_1_SYNCHRONIZE_BIT                                7

#define CHIP_TIMER_1_COMPARE_A_REG                                  CHIP_REG_OCR1A
#define CHIP_TIMER_1_COMPARE_A_INT_ENABLE_REG                       CHIP_REG_TIMSK1
#define CHIP_TIMER_1_COMPARE_A_INT_ENABLE_BIT                       1
#define CHIP_TIMER_1_COMPARE_A_INT_FLAG_REG                         CHIP_REG_TIFR1
#define CHIP_TIMER_1_COMPARE_A_INT_FLAG_BIT                         1
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_REG                           CHIP_REG_TCCR1A
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_MASK                          0xC0
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_TOGGLE_ID                     0x40
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_CLEAR_ID                      0x80
#define CHIP_TIMER_1_COMPARE_A_OUTPUT_SET_ID                        0xC0

#define CHIP_TIMER_1_COMPARE_B_REG                                  CHIP_REG_OCR1B
#define CHIP_TIMER_1_COMPARE_B_INT_ENABLE_REG                       CHIP_REG_TIMSK1
#define CHIP_TIMER_1_COMPARE_B_INT_ENABLE_BIT                       2
#define CHIP_TIMER_1_COMPARE_B_INT_FLAG_REG                         CHIP_REG_TIFR1
#define CHIP_TIMER_1_COMPARE_B_INT_FLAG_BIT                         2
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_REG                           CHIP_REG_TCCR1A
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_MASK                          0x30
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_TOGGLE_ID                     0x10
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_CLEAR_ID                      0x20
#define CHIP_TIMER_1_COMPARE_B_OUTPUT_SET_ID                        0x30

#define CHIP_TIMER_1_COMPARE_C_REG                                  CHIP_REG_OCR1C
#define CHIP_TIMER_1_COMPARE_C_INT_ENABLE_REG                       CHIP_REG_TIMSK1
#define CHIP_TIMER_1_COMPARE_C_INT_ENABLE_BIT                       3
#define CHIP_TIMER_1_COMPARE_C_INT_FLAG_REG                         CHIP_REG_TIFR1
#define CHIP_TIMER_1_COMPARE_C_INT_FLAG_BIT                         3
#define CHIP_TIMER_1_COMPARE_C_OUTPUT_REG                           CHIP_REG_TCCR1A
#define CHIP_TIMER_1_COMPARE_C_OUTPUT_MASK                          0x0C
#define CHIP_TIMER_1_COMPARE_C_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_1_COMPARE_C_OUTPUT_TOGGLE_ID                     0x04
#define CHIP_TIMER_1_COMPARE_C_OUTPUT_CLEAR_ID                      0x08
#define CHIP_TIMER_1_COMPARE_C_OUTPUT_SET_ID                        0x0C

#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK1
#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR1
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_BIT                          0

#define CHIP_TIMER_1_CAPTURE_REG                                    CHIP_REG_ICR1
#define CHIP_TIMER_1_CAPTURE_NOISE_CANCEL_ENABLE_REG                CHIP_REG_TCCR1B
#define CHIP_TIMER_1_CAPTURE_NOISE_CANCEL_ENABLE_BIT                7
#define CHIP_TIMER_1_CAPTURE_EDGE_REG                               CHIP_REG_TCCR1B
#define CHIP_TIMER_1_CAPTURE_EDGE_MASK                              0x40
#define CHIP_TIMER_1_CAPTURE_EDGE_FALLING_ID                        0x00
#define CHIP_TIMER_1_CAPTURE_EDGE_RISING_ID                         0x40
#define CHIP_TIMER_1_CAPTURE_INT_ENABLE_REG                         CHIP_REG_TIMSK1
#define CHIP_TIMER_1_CAPTURE_INT_ENABLE_BIT                         5
#define CHIP_TIMER_1_CAPTURE_INT_FLAG_REG                           CHIP_REG_TIFR1
#define CHIP_TIMER_1_CAPTURE_INT_FLAG_BIT                           5

//------------------------------------------------

#define CHIP_TIMER_2

#define CHIP_TIMER_2_WAVEFORM_REG                                   CHIP_REG_TCCR2A
#define CHIP_TIMER_2_WAVEFORM_MASK                                  0x03
#define CHIP_TIMER_2_WAVEFORM_REG_EXTRA                             CHIP_REG_TCCR2B
#define CHIP_TIMER_2_WAVEFORM_MASK_EXTRA                            0x08
#define CHIP_TIMER_2_WAVEFORM_NORMAL_ID                             0x0000
#define CHIP_TIMER_2_WAVEFORM_PWM_PHASE_CORRECT_ID                  0x0001
#define CHIP_TIMER_2_WAVEFORM_CTC_OCRA_ID                           0x0002
#define CHIP_TIMER_2_WAVEFORM_FAST_PWM_ID                           0x0003
#define CHIP_TIMER_2_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             0x0801
#define CHIP_TIMER_2_WAVEFORM_FAST_PWM_OCRA_ID                      0x0803

#define CHIP_TIMER_2_CLOCK_REG                                      CHIP_REG_TCCR2B
#define CHIP_TIMER_2_CLOCK_MASK                                     0x07
#define CHIP_TIMER_2_CLOCK_NONE_ID                                  0x00
#define CHIP_TIMER_2_CLOCK_1_ID                                     0x01
#define CHIP_TIMER_2_CLOCK_8_ID                                     0x02
#define CHIP_TIMER_2_CLOCK_32_ID                                    0x03
#define CHIP_TIMER_2_CLOCK_64_ID                                    0x04
#define CHIP_TIMER_2_CLOCK_128_ID                                   0x05
#define CHIP_TIMER_2_CLOCK_256_ID                                   0x06
#define CHIP_TIMER_2_CLOCK_1024_ID                                  0x07

#define CHIP_TIMER_2_COUNTER_REG                                    CHIP_REG_TCNT2

#define CHIP_TIMER_2_PRESCALER_RESET_REG                            CHIP_REG_GTCCR
#define CHIP_TIMER_2_PRESCALER_RESET_BIT                            1

#define CHIP_TIMER_2_SYNCHRONIZE_REG                                CHIP_REG_GTCCR
#define CHIP_TIMER_2_SYNCHRONIZE_BIT                                7

#define CHIP_TIMER_2_COMPARE_A_REG                                  CHIP_REG_OCR2A
#define CHIP_TIMER_2_COMPARE_A_INT_ENABLE_REG                       CHIP_REG_TIMSK2
#define CHIP_TIMER_2_COMPARE_A_INT_ENABLE_BIT                       1
#define CHIP_TIMER_2_COMPARE_A_INT_FLAG_REG                         CHIP_REG_TIFR2
#define CHIP_TIMER_2_COMPARE_A_INT_FLAG_BIT                         1
#define CHIP_TIMER_2_COMPARE_A_OUTPUT_REG                           CHIP_REG_TCCR2A
#define CHIP_TIMER_2_COMPARE_A_OUTPUT_MASK                          0xC0
#define CHIP_TIMER_2_COMPARE_A_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_2_COMPARE_A_OUTPUT_TOGGLE_ID                     0x40
#define CHIP_TIMER_2_COMPARE_A_OUTPUT_CLEAR_ID                      0x80
#define CHIP_TIMER_2_COMPARE_A_OUTPUT_SET_ID                        0xC0

#define CHIP_TIMER_2_COMPARE_B_REG                                  CHIP_REG_OCR2B
#define CHIP_TIMER_2_COMPARE_B_INT_ENABLE_REG                       CHIP_REG_TIMSK2
#define CHIP_TIMER_2_COMPARE_B_INT_ENABLE_BIT                       2
#define CHIP_TIMER_2_COMPARE_B_INT_FLAG_REG                         CHIP_REG_TIFR2
#define CHIP_TIMER_2_COMPARE_B_INT_FLAG_BIT                         2
#define CHIP_TIMER_2_COMPARE_B_OUTPUT_REG                           CHIP_REG_TCCR2A
#define CHIP_TIMER_2_COMPARE_B_OUTPUT_MASK                          0x30
#define CHIP_TIMER_2_COMPARE_B_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_2_COMPARE_B_OUTPUT_TOGGLE_ID                     0x10
#define CHIP_TIMER_2_COMPARE_B_OUTPUT_CLEAR_ID                      0x20
#define CHIP_TIMER_2_COMPARE_B_OUTPUT_SET_ID                        0x30

#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK2
#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR2
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_BIT                          0

//------------------------------------------------

#define CHIP_TIMER_3

#define CHIP_TIMER_3_WAVEFORM_REG                                   CHIP_REG_TCCR3A
#define CHIP_TIMER_3_WAVEFORM_MASK                                  0x03
#define CHIP_TIMER_3_WAVEFORM_REG_EXTRA                             CHIP_REG_TCCR3B
#define CHIP_TIMER_3_WAVEFORM_MASK_EXTRA                            0x18
#define CHIP_TIMER_3_WAVEFORM_NORMAL_ID                             0x0000
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_CORRECT_8_ID                0x0001
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_CORRECT_9_ID                0x0002
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_CORRECT_10_ID               0x0003
#define CHIP_TIMER_3_WAVEFORM_CTC_OCRA_ID                           0x0800
#define CHIP_TIMER_3_WAVEFORM_FAST_PWM_8_ID                         0x0801
#define CHIP_TIMER_3_WAVEFORM_FAST_PWM_9_ID                         0x0802
#define CHIP_TIMER_3_WAVEFORM_FAST_PWM_10_ID                        0x0803
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID             0x1000
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID        0x1001
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_CORRECT_ID                  0x1002
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             0x1003
#define CHIP_TIMER_3_WAVEFORM_CTC_ICR_ID                            0x1800
#define CHIP_TIMER_3_WAVEFORM_FAST_PWM_ID                           0x1802
#define CHIP_TIMER_3_WAVEFORM_FAST_PWM_OCRA_ID                      0x1803

#define CHIP_TIMER_3_CLOCK_REG                                      CHIP_REG_TCCR3B
#define CHIP_TIMER_3_CLOCK_MASK                                     0x07
#define CHIP_TIMER_3_CLOCK_NONE_ID                                  0x00
#define CHIP_TIMER_3_CLOCK_1_ID                                     0x01
#define CHIP_TIMER_3_CLOCK_8_ID                                     0x02
#define CHIP_TIMER_3_CLOCK_64_ID                                    0x03
#define CHIP_TIMER_3_CLOCK_256_ID                                   0x04
#define CHIP_TIMER_3_CLOCK_1024_ID                                  0x05
#define CHIP_TIMER_3_CLOCK_EXT_FALLING_ID                           0x06
#define CHIP_TIMER_3_CLOCK_EXT_RISING_ID                            0x07

#define CHIP_TIMER_3_COUNTER_REG                                    CHIP_REG_TCNT3

#define CHIP_TIMER_3_PRESCALER_RESET_REG                            CHIP_REG_GTCCR
#define CHIP_TIMER_3_PRESCALER_RESET_BIT                            0

#define CHIP_TIMER_3_SYNCHRONIZE_REG                                CHIP_REG_GTCCR
#define CHIP_TIMER_3_SYNCHRONIZE_BIT                                7

#define CHIP_TIMER_3_COMPARE_A_REG                                  CHIP_REG_OCR3A
#define CHIP_TIMER_3_COMPARE_A_INT_ENABLE_REG                       CHIP_REG_TIMSK3
#define CHIP_TIMER_3_COMPARE_A_INT_ENABLE_BIT                       1
#define CHIP_TIMER_3_COMPARE_A_INT_FLAG_REG                         CHIP_REG_TIFR3
#define CHIP_TIMER_3_COMPARE_A_INT_FLAG_BIT                         1
#define CHIP_TIMER_3_COMPARE_A_OUTPUT_REG                           CHIP_REG_TCCR3A
#define CHIP_TIMER_3_COMPARE_A_OUTPUT_MASK                          0xC0
#define CHIP_TIMER_3_COMPARE_A_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_3_COMPARE_A_OUTPUT_TOGGLE_ID                     0x40
#define CHIP_TIMER_3_COMPARE_A_OUTPUT_CLEAR_ID                      0x80
#define CHIP_TIMER_3_COMPARE_A_OUTPUT_SET_ID                        0xC0

#define CHIP_TIMER_3_COMPARE_B_REG                                  CHIP_REG_OCR3B
#define CHIP_TIMER_3_COMPARE_B_INT_ENABLE_REG                       CHIP_REG_TIMSK3
#define CHIP_TIMER_3_COMPARE_B_INT_ENABLE_BIT                       2
#define CHIP_TIMER_3_COMPARE_B_INT_FLAG_REG                         CHIP_REG_TIFR3
#define CHIP_TIMER_3_COMPARE_B_INT_FLAG_BIT                         2
#define CHIP_TIMER_3_COMPARE_B_OUTPUT_REG                           CHIP_REG_TCCR3A
#define CHIP_TIMER_3_COMPARE_B_OUTPUT_MASK                          0x30
#define CHIP_TIMER_3_COMPARE_B_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_3_COMPARE_B_OUTPUT_TOGGLE_ID                     0x10
#define CHIP_TIMER_3_COMPARE_B_OUTPUT_CLEAR_ID                      0x20
#define CHIP_TIMER_3_COMPARE_B_OUTPUT_SET_ID                        0x30

#define CHIP_TIMER_3_COMPARE_C_REG                                  CHIP_REG_OCR3C
#define CHIP_TIMER_3_COMPARE_C_INT_ENABLE_REG                       CHIP_REG_TIMSK3
#define CHIP_TIMER_3_COMPARE_C_INT_ENABLE_BIT                       3
#define CHIP_TIMER_3_COMPARE_C_INT_FLAG_REG                         CHIP_REG_TIFR3
#define CHIP_TIMER_3_COMPARE_C_INT_FLAG_BIT                         3
#define CHIP_TIMER_3_COMPARE_C_OUTPUT_REG                           CHIP_REG_TCCR3A
#define CHIP_TIMER_3_COMPARE_C_OUTPUT_MASK                          0x0C
#define CHIP_TIMER_3_COMPARE_C_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_3_COMPARE_C_OUTPUT_TOGGLE_ID                     0x04
#define CHIP_TIMER_3_COMPARE_C_OUTPUT_CLEAR_ID                      0x08
#define CHIP_TIMER_3_COMPARE_C_OUTPUT_SET_ID                        0x0C

#define CHIP_TIMER_3_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK3
#define CHIP_TIMER_3_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_3_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR3
#define CHIP_TIMER_3_OVERFLOW_INT_FLAG_BIT                          0

#define CHIP_TIMER_3_CAPTURE_REG                                    CHIP_REG_ICR3
#define CHIP_TIMER_3_CAPTURE_NOISE_CANCEL_ENABLE_REG                CHIP_REG_TCCR3B
#define CHIP_TIMER_3_CAPTURE_NOISE_CANCEL_ENABLE_BIT                7
#define CHIP_TIMER_3_CAPTURE_EDGE_REG                               CHIP_REG_TCCR3B
#define CHIP_TIMER_3_CAPTURE_EDGE_MASK                              0x40
#define CHIP_TIMER_3_CAPTURE_EDGE_FALLING_ID                        0x00
#define CHIP_TIMER_3_CAPTURE_EDGE_RISING_ID                         0x40
#define CHIP_TIMER_3_CAPTURE_INT_ENABLE_REG                         CHIP_REG_TIMSK3
#define CHIP_TIMER_3_CAPTURE_INT_ENABLE_BIT                         5
#define CHIP_TIMER_3_CAPTURE_INT_FLAG_REG                           CHIP_REG_TIFR3
#define CHIP_TIMER_3_CAPTURE_INT_FLAG_BIT                           5

//------------------------------------------------

#define CHIP_TIMER_4

#define CHIP_TIMER_4_WAVEFORM_REG                                   CHIP_REG_TCCR4A
#define CHIP_TIMER_4_WAVEFORM_MASK                                  0x03
#define CHIP_TIMER_4_WAVEFORM_REG_EXTRA                             CHIP_REG_TCCR4B
#define CHIP_TIMER_4_WAVEFORM_MASK_EXTRA                            0x18
#define CHIP_TIMER_4_WAVEFORM_NORMAL_ID                             0x0000
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_CORRECT_8_ID                0x0001
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_CORRECT_9_ID                0x0002
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_CORRECT_10_ID               0x0003
#define CHIP_TIMER_4_WAVEFORM_CTC_OCRA_ID                           0x0800
#define CHIP_TIMER_4_WAVEFORM_FAST_PWM_8_ID                         0x0801
#define CHIP_TIMER_4_WAVEFORM_FAST_PWM_9_ID                         0x0802
#define CHIP_TIMER_4_WAVEFORM_FAST_PWM_10_ID                        0x0803
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID             0x1000
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID        0x1001
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_CORRECT_ID                  0x1002
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             0x1003
#define CHIP_TIMER_4_WAVEFORM_CTC_ICR_ID                            0x1800
#define CHIP_TIMER_4_WAVEFORM_FAST_PWM_ID                           0x1802
#define CHIP_TIMER_4_WAVEFORM_FAST_PWM_OCRA_ID                      0x1803

#define CHIP_TIMER_4_CLOCK_REG                                      CHIP_REG_TCCR4B
#define CHIP_TIMER_4_CLOCK_MASK                                     0x07
#define CHIP_TIMER_4_CLOCK_NONE_ID                                  0x00
#define CHIP_TIMER_4_CLOCK_1_ID                                     0x01
#define CHIP_TIMER_4_CLOCK_8_ID                                     0x02
#define CHIP_TIMER_4_CLOCK_64_ID                                    0x03
#define CHIP_TIMER_4_CLOCK_256_ID                                   0x04
#define CHIP_TIMER_4_CLOCK_1024_ID                                  0x05
#define CHIP_TIMER_4_CLOCK_EXT_FALLING_ID                           0x06
#define CHIP_TIMER_4_CLOCK_EXT_RISING_ID                            0x07

#define CHIP_TIMER_4_COUNTER_REG                                    CHIP_REG_TCNT4

#define CHIP_TIMER_4_PRESCALER_RESET_REG                            CHIP_REG_GTCCR
#define CHIP_TIMER_4_PRESCALER_RESET_BIT                            0

#define CHIP_TIMER_4_SYNCHRONIZE_REG                                CHIP_REG_GTCCR
#define CHIP_TIMER_4_SYNCHRONIZE_BIT                                7

#define CHIP_TIMER_4_COMPARE_A_REG                                  CHIP_REG_OCR4A
#define CHIP_TIMER_4_COMPARE_A_INT_ENABLE_REG                       CHIP_REG_TIMSK4
#define CHIP_TIMER_4_COMPARE_A_INT_ENABLE_BIT                       1
#define CHIP_TIMER_4_COMPARE_A_INT_FLAG_REG                         CHIP_REG_TIFR4
#define CHIP_TIMER_4_COMPARE_A_INT_FLAG_BIT                         1
#define CHIP_TIMER_4_COMPARE_A_OUTPUT_REG                           CHIP_REG_TCCR4A
#define CHIP_TIMER_4_COMPARE_A_OUTPUT_MASK                          0xC0
#define CHIP_TIMER_4_COMPARE_A_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_4_COMPARE_A_OUTPUT_TOGGLE_ID                     0x40
#define CHIP_TIMER_4_COMPARE_A_OUTPUT_CLEAR_ID                      0x80
#define CHIP_TIMER_4_COMPARE_A_OUTPUT_SET_ID                        0xC0

#define CHIP_TIMER_4_COMPARE_B_REG                                  CHIP_REG_OCR4B
#define CHIP_TIMER_4_COMPARE_B_INT_ENABLE_REG                       CHIP_REG_TIMSK4
#define CHIP_TIMER_4_COMPARE_B_INT_ENABLE_BIT                       2
#define CHIP_TIMER_4_COMPARE_B_INT_FLAG_REG                         CHIP_REG_TIFR4
#define CHIP_TIMER_4_COMPARE_B_INT_FLAG_BIT                         2
#define CHIP_TIMER_4_COMPARE_B_OUTPUT_REG                           CHIP_REG_TCCR4A
#define CHIP_TIMER_4_COMPARE_B_OUTPUT_MASK                          0x30
#define CHIP_TIMER_4_COMPARE_B_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_4_COMPARE_B_OUTPUT_TOGGLE_ID                     0x10
#define CHIP_TIMER_4_COMPARE_B_OUTPUT_CLEAR_ID                      0x20
#define CHIP_TIMER_4_COMPARE_B_OUTPUT_SET_ID                        0x30

#define CHIP_TIMER_4_COMPARE_C_REG                                  CHIP_REG_OCR4C
#define CHIP_TIMER_4_COMPARE_C_INT_ENABLE_REG                       CHIP_REG_TIMSK4
#define CHIP_TIMER_4_COMPARE_C_INT_ENABLE_BIT                       3
#define CHIP_TIMER_4_COMPARE_C_INT_FLAG_REG                         CHIP_REG_TIFR4
#define CHIP_TIMER_4_COMPARE_C_INT_FLAG_BIT                         3
#define CHIP_TIMER_4_COMPARE_C_OUTPUT_REG                           CHIP_REG_TCCR4A
#define CHIP_TIMER_4_COMPARE_C_OUTPUT_MASK                          0x0C
#define CHIP_TIMER_4_COMPARE_C_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_4_COMPARE_C_OUTPUT_TOGGLE_ID                     0x04
#define CHIP_TIMER_4_COMPARE_C_OUTPUT_CLEAR_ID                      0x08
#define CHIP_TIMER_4_COMPARE_C_OUTPUT_SET_ID                        0x0C

#define CHIP_TIMER_4_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK4
#define CHIP_TIMER_4_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_4_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR4
#define CHIP_TIMER_4_OVERFLOW_INT_FLAG_BIT                          0

#define CHIP_TIMER_4_CAPTURE_REG                                    CHIP_REG_ICR4
#define CHIP_TIMER_4_CAPTURE_NOISE_CANCEL_ENABLE_REG                CHIP_REG_TCCR4B
#define CHIP_TIMER_4_CAPTURE_NOISE_CANCEL_ENABLE_BIT                7
#define CHIP_TIMER_4_CAPTURE_EDGE_REG                               CHIP_REG_TCCR4B
#define CHIP_TIMER_4_CAPTURE_EDGE_MASK                              0x40
#define CHIP_TIMER_4_CAPTURE_EDGE_FALLING_ID                        0x00
#define CHIP_TIMER_4_CAPTURE_EDGE_RISING_ID                         0x40
#define CHIP_TIMER_4_CAPTURE_INT_ENABLE_REG                         CHIP_REG_TIMSK4
#define CHIP_TIMER_4_CAPTURE_INT_ENABLE_BIT                         5
#define CHIP_TIMER_4_CAPTURE_INT_FLAG_REG                           CHIP_REG_TIFR4
#define CHIP_TIMER_4_CAPTURE_INT_FLAG_BIT                           5

//------------------------------------------------

#define CHIP_TIMER_5

#define CHIP_TIMER_5_WAVEFORM_REG                                   CHIP_REG_TCCR5A
#define CHIP_TIMER_5_WAVEFORM_MASK                                  0x03
#define CHIP_TIMER_5_WAVEFORM_REG_EXTRA                             CHIP_REG_TCCR5B
#define CHIP_TIMER_5_WAVEFORM_MASK_EXTRA                            0x18
#define CHIP_TIMER_5_WAVEFORM_NORMAL_ID                             0x0000
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_CORRECT_8_ID                0x0001
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_CORRECT_9_ID                0x0002
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_CORRECT_10_ID               0x0003
#define CHIP_TIMER_5_WAVEFORM_CTC_OCRA_ID                           0x0800
#define CHIP_TIMER_5_WAVEFORM_FAST_PWM_8_ID                         0x0801
#define CHIP_TIMER_5_WAVEFORM_FAST_PWM_9_ID                         0x0802
#define CHIP_TIMER_5_WAVEFORM_FAST_PWM_10_ID                        0x0803
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID             0x1000
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID        0x1001
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_CORRECT_ID                  0x1002
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             0x1003
#define CHIP_TIMER_5_WAVEFORM_CTC_ICR_ID                            0x1800
#define CHIP_TIMER_5_WAVEFORM_FAST_PWM_ID                           0x1802
#define CHIP_TIMER_5_WAVEFORM_FAST_PWM_OCRA_ID                      0x1803

#define CHIP_TIMER_5_CLOCK_REG                                      CHIP_REG_TCCR5B
#define CHIP_TIMER_5_CLOCK_MASK                                     0x07
#define CHIP_TIMER_5_CLOCK_NONE_ID                                  0x00
#define CHIP_TIMER_5_CLOCK_1_ID                                     0x01
#define CHIP_TIMER_5_CLOCK_8_ID                                     0x02
#define CHIP_TIMER_5_CLOCK_64_ID                                    0x03
#define CHIP_TIMER_5_CLOCK_256_ID                                   0x04
#define CHIP_TIMER_5_CLOCK_1024_ID                                  0x05
#define CHIP_TIMER_5_CLOCK_EXT_FALLING_ID                           0x06
#define CHIP_TIMER_5_CLOCK_EXT_RISING_ID                            0x07

#define CHIP_TIMER_5_COUNTER_REG                                    CHIP_REG_TCNT5

#define CHIP_TIMER_5_PRESCALER_RESET_REG                            CHIP_REG_GTCCR
#define CHIP_TIMER_5_PRESCALER_RESET_BIT                            0

#define CHIP_TIMER_5_SYNCHRONIZE_REG                                CHIP_REG_GTCCR
#define CHIP_TIMER_5_SYNCHRONIZE_BIT                                7

#define CHIP_TIMER_5_COMPARE_A_REG                                  CHIP_REG_OCR5A
#define CHIP_TIMER_5_COMPARE_A_INT_ENABLE_REG                       CHIP_REG_TIMSK5
#define CHIP_TIMER_5_COMPARE_A_INT_ENABLE_BIT                       1
#define CHIP_TIMER_5_COMPARE_A_INT_FLAG_REG                         CHIP_REG_TIFR5
#define CHIP_TIMER_5_COMPARE_A_INT_FLAG_BIT                         1
#define CHIP_TIMER_5_COMPARE_A_OUTPUT_REG                           CHIP_REG_TCCR5A
#define CHIP_TIMER_5_COMPARE_A_OUTPUT_MASK                          0xC0
#define CHIP_TIMER_5_COMPARE_A_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_5_COMPARE_A_OUTPUT_TOGGLE_ID                     0x40
#define CHIP_TIMER_5_COMPARE_A_OUTPUT_CLEAR_ID                      0x80
#define CHIP_TIMER_5_COMPARE_A_OUTPUT_SET_ID                        0xC0

#define CHIP_TIMER_5_COMPARE_B_REG                                  CHIP_REG_OCR5B
#define CHIP_TIMER_5_COMPARE_B_INT_ENABLE_REG                       CHIP_REG_TIMSK5
#define CHIP_TIMER_5_COMPARE_B_INT_ENABLE_BIT                       2
#define CHIP_TIMER_5_COMPARE_B_INT_FLAG_REG                         CHIP_REG_TIFR5
#define CHIP_TIMER_5_COMPARE_B_INT_FLAG_BIT                         2
#define CHIP_TIMER_5_COMPARE_B_OUTPUT_REG                           CHIP_REG_TCCR5A
#define CHIP_TIMER_5_COMPARE_B_OUTPUT_MASK                          0x30
#define CHIP_TIMER_5_COMPARE_B_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_5_COMPARE_B_OUTPUT_TOGGLE_ID                     0x10
#define CHIP_TIMER_5_COMPARE_B_OUTPUT_CLEAR_ID                      0x20
#define CHIP_TIMER_5_COMPARE_B_OUTPUT_SET_ID                        0x30

#define CHIP_TIMER_5_COMPARE_C_REG                                  CHIP_REG_OCR5C
#define CHIP_TIMER_5_COMPARE_C_INT_ENABLE_REG                       CHIP_REG_TIMSK5
#define CHIP_TIMER_5_COMPARE_C_INT_ENABLE_BIT                       3
#define CHIP_TIMER_5_COMPARE_C_INT_FLAG_REG                         CHIP_REG_TIFR5
#define CHIP_TIMER_5_COMPARE_C_INT_FLAG_BIT                         3
#define CHIP_TIMER_5_COMPARE_C_OUTPUT_REG                           CHIP_REG_TCCR5A
#define CHIP_TIMER_5_COMPARE_C_OUTPUT_MASK                          0x0C
#define CHIP_TIMER_5_COMPARE_C_OUTPUT_DISCONNECTED_ID               0x00
#define CHIP_TIMER_5_COMPARE_C_OUTPUT_TOGGLE_ID                     0x04
#define CHIP_TIMER_5_COMPARE_C_OUTPUT_CLEAR_ID                      0x08
#define CHIP_TIMER_5_COMPARE_C_OUTPUT_SET_ID                        0x0C

#define CHIP_TIMER_5_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK5
#define CHIP_TIMER_5_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_5_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR5
#define CHIP_TIMER_5_OVERFLOW_INT_FLAG_BIT                          0

#define CHIP_TIMER_5_CAPTURE_REG                                    CHIP_REG_ICR5
#define CHIP_TIMER_5_CAPTURE_NOISE_CANCEL_ENABLE_REG                CHIP_REG_TCCR5B
#define CHIP_TIMER_5_CAPTURE_NOISE_CANCEL_ENABLE_BIT                7
#define CHIP_TIMER_5_CAPTURE_EDGE_REG                               CHIP_REG_TCCR5B
#define CHIP_TIMER_5_CAPTURE_EDGE_MASK                              0x40
#define CHIP_TIMER_5_CAPTURE_EDGE_FALLING_ID                        0x00
#define CHIP_TIMER_5_CAPTURE_EDGE_RISING_ID                         0x40
#define CHIP_TIMER_5_CAPTURE_INT_ENABLE_REG                         CHIP_REG_TIMSK5
#define CHIP_TIMER_5_CAPTURE_INT_ENABLE_BIT                         5
#define CHIP_TIMER_5_CAPTURE_INT_FLAG_REG                           CHIP_REG_TIFR5
#define CHIP_TIMER_5_CAPTURE_INT_FLAG_BIT                           5

//------------------------------------------------

#define CHIP_USART_0

#define CHIP_USART_0_RX_DATA_REG                                    CHIP_REG_UDR0
#define CHIP_USART_0_RX_DATA_9_REG                                  CHIP_REG_UCSR0B
#define CHIP_USART_0_RX_DATA_9_BIT                                  1

#define CHIP_USART_0_TX_DATA_REG                                    CHIP_REG_UDR0
#define CHIP_USART_0_TX_DATA_9_REG                                  CHIP_REG_UCSR0B
#define CHIP_USART_0_TX_DATA_9_BIT                                  0

#define CHIP_USART_0_BAUD_REG                                       CHIP_REG_UBRR0

#define CHIP_USART_0_FRAME_ERROR_REG                                CHIP_REG_UCSR0A
#define CHIP_USART_0_FRAME_ERROR_BIT                                4
#define CHIP_USART_0_DATA_OVERRUN_REG                               CHIP_REG_UCSR0A
#define CHIP_USART_0_DATA_OVERRUN_BIT                               3
#define CHIP_USART_0_PARITY_ERROR_REG                               CHIP_REG_UCSR0A
#define CHIP_USART_0_PARITY_ERROR_BIT                               2

#define CHIP_USART_0_BAUD_MODE_REG                                  CHIP_REG_UCSR0A
#define CHIP_USART_0_BAUD_MODE_MASK                                 0x02
#define CHIP_USART_0_BAUD_MODE_NORMAL_ID                            0x00
#define CHIP_USART_0_BAUD_MODE_DOUBLE_ID                            0x02

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG              CHIP_REG_UCSR0A
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT              0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSR0B
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                     7
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSR0B
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                     6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG                  CHIP_REG_UCSR0B
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT                  5

#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSR0A
#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_BIT                       7
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSR0A
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_BIT                       6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_REG                    CHIP_REG_UCSR0A
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_BIT                    5

#define CHIP_USART_0_RX_ENABLE_REG                                  CHIP_REG_UCSR0B
#define CHIP_USART_0_RX_ENABLE_BIT                                  4
#define CHIP_USART_0_TX_ENABLE_REG                                  CHIP_REG_UCSR0B
#define CHIP_USART_0_TX_ENABLE_BIT                                  3

#define CHIP_USART_0_MODE_REG                                       CHIP_REG_UCSR0C
#define CHIP_USART_0_MODE_MASK                                      0xC0
#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                           0x00
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                            0x40
#define CHIP_USART_0_MODE_MASTER_SPI_ID                             0xC0

#define CHIP_USART_0_PARITY_REG                                     CHIP_REG_UCSR0C
#define CHIP_USART_0_PARITY_MASK                                    0x30
#define CHIP_USART_0_PARITY_DISABLE_ID                              0x00
#define CHIP_USART_0_PARITY_EVEN_ID                                 0x20
#define CHIP_USART_0_PARITY_ODD_ID                                  0x30

#define CHIP_USART_0_STOP_BITS_REG                                  CHIP_REG_UCSR0C
#define CHIP_USART_0_STOP_BITS_MASK                                 0x08
#define CHIP_USART_0_STOP_BITS_1_ID                                 0x00
#define CHIP_USART_0_STOP_BITS_2_ID                                 0x08

#define CHIP_USART_0_CHARACTER_SIZE_REG                             CHIP_REG_UCSR0C
#define CHIP_USART_0_CHARACTER_SIZE_MASK                            0x06
#define CHIP_USART_0_CHARACTER_SIZE_REG_EXTRA                       CHIP_REG_UCSR0B
#define CHIP_USART_0_CHARACTER_SIZE_MASK_EXTRA                      0x04
#define CHIP_USART_0_CHARACTER_SIZE_5_ID                            0x0000
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                            0x0002
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                            0x0004
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                            0x0006
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                            0x0406

#define CHIP_USART_0_POLARITY_REG                                   CHIP_REG_UCSR0C
#define CHIP_USART_0_POLARITY_MASK                                  0x01
#define CHIP_USART_0_POLARITY_TX_RISING_RX_FALLING_ID               0x00
#define CHIP_USART_0_POLARITY_TX_FALLING_RX_RISING_ID               0x01

//------------------------------------------------

#define CHIP_USART_1

#define CHIP_USART_1_RX_DATA_REG                                    CHIP_REG_UDR1
#define CHIP_USART_1_RX_DATA_9_REG                                  CHIP_REG_UCSR1B
#define CHIP_USART_1_RX_DATA_9_BIT                                  1

#define CHIP_USART_1_TX_DATA_REG                                    CHIP_REG_UDR1
#define CHIP_USART_1_TX_DATA_9_REG                                  CHIP_REG_UCSR1B
#define CHIP_USART_1_TX_DATA_9_BIT                                  0

#define CHIP_USART_1_BAUD_REG                                       CHIP_REG_UBRR1

#define CHIP_USART_1_FRAME_ERROR_REG                                CHIP_REG_UCSR1A
#define CHIP_USART_1_FRAME_ERROR_BIT                                4
#define CHIP_USART_1_DATA_OVERRUN_REG                               CHIP_REG_UCSR1A
#define CHIP_USART_1_DATA_OVERRUN_BIT                               3
#define CHIP_USART_1_PARITY_ERROR_REG                               CHIP_REG_UCSR1A
#define CHIP_USART_1_PARITY_ERROR_BIT                               2

#define CHIP_USART_1_BAUD_MODE_REG                                  CHIP_REG_UCSR1A
#define CHIP_USART_1_BAUD_MODE_MASK                                 0x02
#define CHIP_USART_1_BAUD_MODE_NORMAL_ID                            0x00
#define CHIP_USART_1_BAUD_MODE_DOUBLE_ID                            0x02

#define CHIP_USART_1_MULTI_PROCESSOR_COMMUNICATION_REG              CHIP_REG_UCSR1A
#define CHIP_USART_1_MULTI_PROCESSOR_COMMUNICATION_BIT              0

#define CHIP_USART_1_RX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSR1B
#define CHIP_USART_1_RX_COMPLETE_INT_ENABLE_BIT                     7
#define CHIP_USART_1_TX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSR1B
#define CHIP_USART_1_TX_COMPLETE_INT_ENABLE_BIT                     6
#define CHIP_USART_1_DATA_REG_EMPTY_INT_ENABLE_REG                  CHIP_REG_UCSR1B
#define CHIP_USART_1_DATA_REG_EMPTY_INT_ENABLE_BIT                  5

#define CHIP_USART_1_RX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSR1A
#define CHIP_USART_1_RX_COMPLETE_INT_FLAG_BIT                       7
#define CHIP_USART_1_TX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSR1A
#define CHIP_USART_1_TX_COMPLETE_INT_FLAG_BIT                       6
#define CHIP_USART_1_DATA_REG_EMPTY_INT_FLAG_REG                    CHIP_REG_UCSR1A
#define CHIP_USART_1_DATA_REG_EMPTY_INT_FLAG_BIT                    5

#define CHIP_USART_1_RX_ENABLE_REG                                  CHIP_REG_UCSR1B
#define CHIP_USART_1_RX_ENABLE_BIT                                  4
#define CHIP_USART_1_TX_ENABLE_REG                                  CHIP_REG_UCSR1B
#define CHIP_USART_1_TX_ENABLE_BIT                                  3

#define CHIP_USART_1_MODE_REG                                       CHIP_REG_UCSR1C
#define CHIP_USART_1_MODE_MASK                                      0xC0
#define CHIP_USART_1_MODE_ASYNCHRONOUS_ID                           0x00
#define CHIP_USART_1_MODE_SYNCHRONOUS_ID                            0x40
#define CHIP_USART_1_MODE_MASTER_SPI_ID                             0xC0

#define CHIP_USART_1_PARITY_REG                                     CHIP_REG_UCSR1C
#define CHIP_USART_1_PARITY_MASK                                    0x30
#define CHIP_USART_1_PARITY_DISABLE_ID                              0x00
#define CHIP_USART_1_PARITY_EVEN_ID                                 0x20
#define CHIP_USART_1_PARITY_ODD_ID                                  0x30

#define CHIP_USART_1_STOP_BITS_REG                                  CHIP_REG_UCSR1C
#define CHIP_USART_1_STOP_BITS_MASK                                 0x08
#define CHIP_USART_1_STOP_BITS_1_ID                                 0x00
#define CHIP_USART_1_STOP_BITS_2_ID                                 0x08

#define CHIP_USART_1_CHARACTER_SIZE_REG                             CHIP_REG_UCSR1C
#define CHIP_USART_1_CHARACTER_SIZE_MASK                            0x06
#define CHIP_USART_1_CHARACTER_SIZE_REG_EXTRA                       CHIP_REG_UCSR1B
#define CHIP_USART_1_CHARACTER_SIZE_MASK_EXTRA                      0x04
#define CHIP_USART_1_CHARACTER_SIZE_5_ID                            0x0000
#define CHIP_USART_1_CHARACTER_SIZE_6_ID                            0x0002
#define CHIP_USART_1_CHARACTER_SIZE_7_ID                            0x0004
#define CHIP_USART_1_CHARACTER_SIZE_8_ID                            0x0006
#define CHIP_USART_1_CHARACTER_SIZE_9_ID                            0x0406

#define CHIP_USART_1_POLARITY_REG                                   CHIP_REG_UCSR1C
#define CHIP_USART_1_POLARITY_MASK                                  0x01
#define CHIP_USART_1_POLARITY_TX_RISING_RX_FALLING_ID               0x00
#define CHIP_USART_1_POLARITY_TX_FALLING_RX_RISING_ID               0x01

//------------------------------------------------

#define CHIP_USART_2

#define CHIP_USART_2_RX_DATA_REG                                    CHIP_REG_UDR2
#define CHIP_USART_2_RX_DATA_9_REG                                  CHIP_REG_UCSR2B
#define CHIP_USART_2_RX_DATA_9_BIT                                  1

#define CHIP_USART_2_TX_DATA_REG                                    CHIP_REG_UDR2
#define CHIP_USART_2_TX_DATA_9_REG                                  CHIP_REG_UCSR2B
#define CHIP_USART_2_TX_DATA_9_BIT                                  0

#define CHIP_USART_2_BAUD_REG                                       CHIP_REG_UBRR2

#define CHIP_USART_2_FRAME_ERROR_REG                                CHIP_REG_UCSR2A
#define CHIP_USART_2_FRAME_ERROR_BIT                                4
#define CHIP_USART_2_DATA_OVERRUN_REG                               CHIP_REG_UCSR2A
#define CHIP_USART_2_DATA_OVERRUN_BIT                               3
#define CHIP_USART_2_PARITY_ERROR_REG                               CHIP_REG_UCSR2A
#define CHIP_USART_2_PARITY_ERROR_BIT                               2

#define CHIP_USART_2_BAUD_MODE_REG                                  CHIP_REG_UCSR2A
#define CHIP_USART_2_BAUD_MODE_MASK                                 0x02
#define CHIP_USART_2_BAUD_MODE_NORMAL_ID                            0x00
#define CHIP_USART_2_BAUD_MODE_DOUBLE_ID                            0x02

#define CHIP_USART_2_MULTI_PROCESSOR_COMMUNICATION_REG              CHIP_REG_UCSR2A
#define CHIP_USART_2_MULTI_PROCESSOR_COMMUNICATION_BIT              0

#define CHIP_USART_2_RX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSR2B
#define CHIP_USART_2_RX_COMPLETE_INT_ENABLE_BIT                     7
#define CHIP_USART_2_TX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSR2B
#define CHIP_USART_2_TX_COMPLETE_INT_ENABLE_BIT                     6
#define CHIP_USART_2_DATA_REG_EMPTY_INT_ENABLE_REG                  CHIP_REG_UCSR2B
#define CHIP_USART_2_DATA_REG_EMPTY_INT_ENABLE_BIT                  5

#define CHIP_USART_2_RX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSR2A
#define CHIP_USART_2_RX_COMPLETE_INT_FLAG_BIT                       7
#define CHIP_USART_2_TX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSR2A
#define CHIP_USART_2_TX_COMPLETE_INT_FLAG_BIT                       6
#define CHIP_USART_2_DATA_REG_EMPTY_INT_FLAG_REG                    CHIP_REG_UCSR2A
#define CHIP_USART_2_DATA_REG_EMPTY_INT_FLAG_BIT                    5

#define CHIP_USART_2_RX_ENABLE_REG                                  CHIP_REG_UCSR2B
#define CHIP_USART_2_RX_ENABLE_BIT                                  4
#define CHIP_USART_2_TX_ENABLE_REG                                  CHIP_REG_UCSR2B
#define CHIP_USART_2_TX_ENABLE_BIT                                  3

#define CHIP_USART_2_MODE_REG                                       CHIP_REG_UCSR2C
#define CHIP_USART_2_MODE_MASK                                      0xC0
#define CHIP_USART_2_MODE_ASYNCHRONOUS_ID                           0x00
#define CHIP_USART_2_MODE_SYNCHRONOUS_ID                            0x40
#define CHIP_USART_2_MODE_MASTER_SPI_ID                             0xC0

#define CHIP_USART_2_PARITY_REG                                     CHIP_REG_UCSR2C
#define CHIP_USART_2_PARITY_MASK                                    0x30
#define CHIP_USART_2_PARITY_DISABLE_ID                              0x00
#define CHIP_USART_2_PARITY_EVEN_ID                                 0x20
#define CHIP_USART_2_PARITY_ODD_ID                                  0x30

#define CHIP_USART_2_STOP_BITS_REG                                  CHIP_REG_UCSR2C
#define CHIP_USART_2_STOP_BITS_MASK                                 0x08
#define CHIP_USART_2_STOP_BITS_1_ID                                 0x00
#define CHIP_USART_2_STOP_BITS_2_ID                                 0x08

#define CHIP_USART_2_CHARACTER_SIZE_REG                             CHIP_REG_UCSR2C
#define CHIP_USART_2_CHARACTER_SIZE_MASK                            0x06
#define CHIP_USART_2_CHARACTER_SIZE_REG_EXTRA                       CHIP_REG_UCSR2B
#define CHIP_USART_2_CHARACTER_SIZE_MASK_EXTRA                      0x04
#define CHIP_USART_2_CHARACTER_SIZE_5_ID                            0x0000
#define CHIP_USART_2_CHARACTER_SIZE_6_ID                            0x0002
#define CHIP_USART_2_CHARACTER_SIZE_7_ID                            0x0004
#define CHIP_USART_2_CHARACTER_SIZE_8_ID                            0x0006
#define CHIP_USART_2_CHARACTER_SIZE_9_ID                            0x0406

#define CHIP_USART_2_POLARITY_REG                                   CHIP_REG_UCSR2C
#define CHIP_USART_2_POLARITY_MASK                                  0x01
#define CHIP_USART_2_POLARITY_TX_RISING_RX_FALLING_ID               0x00
#define CHIP_USART_2_POLARITY_TX_FALLING_RX_RISING_ID               0x01

//------------------------------------------------

#define CHIP_USART_3

#define CHIP_USART_3_RX_DATA_REG                                    CHIP_REG_UDR3
#define CHIP_USART_3_RX_DATA_9_REG                                  CHIP_REG_UCSR3B
#define CHIP_USART_3_RX_DATA_9_BIT                                  1

#define CHIP_USART_3_TX_DATA_REG                                    CHIP_REG_UDR3
#define CHIP_USART_3_TX_DATA_9_REG                                  CHIP_REG_UCSR3B
#define CHIP_USART_3_TX_DATA_9_BIT                                  0

#define CHIP_USART_3_BAUD_REG                                       CHIP_REG_UBRR3

#define CHIP_USART_3_FRAME_ERROR_REG                                CHIP_REG_UCSR3A
#define CHIP_USART_3_FRAME_ERROR_BIT                                4
#define CHIP_USART_3_DATA_OVERRUN_REG                               CHIP_REG_UCSR3A
#define CHIP_USART_3_DATA_OVERRUN_BIT                               3
#define CHIP_USART_3_PARITY_ERROR_REG                               CHIP_REG_UCSR3A
#define CHIP_USART_3_PARITY_ERROR_BIT                               2

#define CHIP_USART_3_BAUD_MODE_REG                                  CHIP_REG_UCSR3A
#define CHIP_USART_3_BAUD_MODE_MASK                                 0x02
#define CHIP_USART_3_BAUD_MODE_NORMAL_ID                            0x00
#define CHIP_USART_3_BAUD_MODE_DOUBLE_ID                            0x02

#define CHIP_USART_3_MULTI_PROCESSOR_COMMUNICATION_REG              CHIP_REG_UCSR3A
#define CHIP_USART_3_MULTI_PROCESSOR_COMMUNICATION_BIT              0

#define CHIP_USART_3_RX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSR3B
#define CHIP_USART_3_RX_COMPLETE_INT_ENABLE_BIT                     7
#define CHIP_USART_3_TX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSR3B
#define CHIP_USART_3_TX_COMPLETE_INT_ENABLE_BIT                     6
#define CHIP_USART_3_DATA_REG_EMPTY_INT_ENABLE_REG                  CHIP_REG_UCSR3B
#define CHIP_USART_3_DATA_REG_EMPTY_INT_ENABLE_BIT                  5

#define CHIP_USART_3_RX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSR3A
#define CHIP_USART_3_RX_COMPLETE_INT_FLAG_BIT                       7
#define CHIP_USART_3_TX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSR3A
#define CHIP_USART_3_TX_COMPLETE_INT_FLAG_BIT                       6
#define CHIP_USART_3_DATA_REG_EMPTY_INT_FLAG_REG                    CHIP_REG_UCSR3A
#define CHIP_USART_3_DATA_REG_EMPTY_INT_FLAG_BIT                    5

#define CHIP_USART_3_RX_ENABLE_REG                                  CHIP_REG_UCSR3B
#define CHIP_USART_3_RX_ENABLE_BIT                                  4
#define CHIP_USART_3_TX_ENABLE_REG                                  CHIP_REG_UCSR3B
#define CHIP_USART_3_TX_ENABLE_BIT                                  3

#define CHIP_USART_3_MODE_REG                                       CHIP_REG_UCSR3C
#define CHIP_USART_3_MODE_MASK                                      0xC0
#define CHIP_USART_3_MODE_ASYNCHRONOUS_ID                           0x00
#define CHIP_USART_3_MODE_SYNCHRONOUS_ID                            0x40
#define CHIP_USART_3_MODE_MASTER_SPI_ID                             0xC0

#define CHIP_USART_3_PARITY_REG                                     CHIP_REG_UCSR3C
#define CHIP_USART_3_PARITY_MASK                                    0x30
#define CHIP_USART_3_PARITY_DISABLE_ID                              0x00
#define CHIP_USART_3_PARITY_EVEN_ID                                 0x20
#define CHIP_USART_3_PARITY_ODD_ID                                  0x30

#define CHIP_USART_3_STOP_BITS_REG                                  CHIP_REG_UCSR3C
#define CHIP_USART_3_STOP_BITS_MASK                                 0x08
#define CHIP_USART_3_STOP_BITS_1_ID                                 0x00
#define CHIP_USART_3_STOP_BITS_2_ID                                 0x08

#define CHIP_USART_3_CHARACTER_SIZE_REG                             CHIP_REG_UCSR3C
#define CHIP_USART_3_CHARACTER_SIZE_MASK                            0x06
#define CHIP_USART_3_CHARACTER_SIZE_REG_EXTRA                       CHIP_REG_UCSR3B
#define CHIP_USART_3_CHARACTER_SIZE_MASK_EXTRA                      0x04
#define CHIP_USART_3_CHARACTER_SIZE_5_ID                            0x0000
#define CHIP_USART_3_CHARACTER_SIZE_6_ID                            0x0002
#define CHIP_USART_3_CHARACTER_SIZE_7_ID                            0x0004
#define CHIP_USART_3_CHARACTER_SIZE_8_ID                            0x0006
#define CHIP_USART_3_CHARACTER_SIZE_9_ID                            0x0406

#define CHIP_USART_3_POLARITY_REG                                   CHIP_REG_UCSR3C
#define CHIP_USART_3_POLARITY_MASK                                  0x01
#define CHIP_USART_3_POLARITY_TX_RISING_RX_FALLING_ID               0x00
#define CHIP_USART_3_POLARITY_TX_FALLING_RX_RISING_ID               0x01

//------------------------------------------------
// Serial peripheral interfaces

#define CHIP_SPI_0

#define CHIP_SPI_0_DATA_REG                                         CHIP_REG_SPDR

#define CHIP_SPI_0_ENABLE_REG                                       CHIP_REG_SPCR
#define CHIP_SPI_0_ENABLE_BIT                                       6

#define CHIP_SPI_0_INT_ENABLE_REG                                   CHIP_REG_SPCR
#define CHIP_SPI_0_INT_ENABLE_BIT                                   7

#define CHIP_SPI_0_DATA_ORDER_REG                                   CHIP_REG_SPCR
#define CHIP_SPI_0_DATA_ORDER_MASK                                  0x20
#define CHIP_SPI_0_DATA_ORDER_MSB_FIRST_ID                          0x00
#define CHIP_SPI_0_DATA_ORDER_LSB_FIRST_ID                          0x20

#define CHIP_SPI_0_MASTER_SLAVE_SELECT_REG                          CHIP_REG_SPCR
#define CHIP_SPI_0_MASTER_SLAVE_SELECT_MASK                         0x10
#define CHIP_SPI_0_MASTER_SLAVE_SELECT_SLAVE_ID                     0x00
#define CHIP_SPI_0_MASTER_SLAVE_SELECT_MASTER_ID                    0x10

#define CHIP_SPI_0_POLARITY_REG                                     CHIP_REG_SPCR
#define CHIP_SPI_0_POLARITY_MASK                                    0x08
#define CHIP_SPI_0_POLARITY_LEADING_RISING_TRAILING_FALLING_ID      0x00
#define CHIP_SPI_0_POLARITY_LEADING_FALLING_TRAILING_RISING_ID      0x08

#define CHIP_SPI_0_PHASE_REG                                        CHIP_REG_SPCR
#define CHIP_SPI_0_PHASE_MASK                                       0x04
#define CHIP_SPI_0_PHASE_LEADING_SAMPLE_TRAILING_SETUP_ID           0x00
#define CHIP_SPI_0_PHASE_LEADING_SETUP_TRAILING_SAMPLE_ID           0x04

#define CHIP_SPI_0_CLOCK_REG                                        CHIP_REG_SPCR
#define CHIP_SPI_0_CLOCK_MASK                                       0x03
#define CHIP_SPI_0_CLOCK_REG_EXTRA                                  CHIP_REG_SPSR
#define CHIP_SPI_0_CLOCK_MASK_EXTRA                                 0x01
#define CHIP_SPI_0_CLOCK_DIV_4_ID                                   0x0000
#define CHIP_SPI_0_CLOCK_DIV_16_ID                                  0x0001
#define CHIP_SPI_0_CLOCK_DIV_64_ID                                  0x0002
#define CHIP_SPI_0_CLOCK_DIV_128_ID                                 0x0003
#define CHIP_SPI_0_CLOCK_DIV_2_ID                                   0x0100
#define CHIP_SPI_0_CLOCK_DIV_8_ID                                   0x0101
#define CHIP_SPI_0_CLOCK_DIV_32_ID                                  0x0102

#define CHIP_SPI_0_INT_FLAG_REG                                     CHIP_REG_SPSR
#define CHIP_SPI_0_INT_FLAG_BIT                                     7

#define CHIP_SPI_0_COLLISION_FLAG_REG                               CHIP_REG_SPSR
#define CHIP_SPI_0_COLLISION_FLAG_BIT                               6

//------------------------------------------------
// Two wire serial interfaces

#define CHIP_TWI_0

#define CHIP_TWI_0_PRESCALER_REG                                    CHIP_REG_TWSR
#define CHIP_TWI_0_PRESCALER_MASK                                   0x03
#define CHIP_TWI_0_PRESCALER_1_ID                                   0x00
#define CHIP_TWI_0_PRESCALER_4_ID                                   0x01
#define CHIP_TWI_0_PRESCALER_16_ID                                  0x02
#define CHIP_TWI_0_PRESCALER_64_ID                                  0x03

#define CHIP_TWI_0_DATA_REG                                         CHIP_REG_TWDR

#define CHIP_TWI_0_STATUS_REG                                       CHIP_REG_TWSR
#define CHIP_TWI_0_STATUS_MASK                                      0xF8
// TODO Add status values. Make sense of all this.
// #define CHIP_TWI_0_STATUS_MT_START_ID                               0x08
// #define CHIP_TWI_0_STATUS_MT_REPEAT_ID                              0x10
// #define CHIP_TWI_0_STATUS_MT_SLA_W_ACK_ID                           0x18
// #define CHIP_TWI_0_STATUS_MT_SLA_W_NOT_ACK_ID                       0x20
// #define CHIP_TWI_0_STATUS_MT_DATA_ACK_ID                            0x28
// #define CHIP_TWI_0_STATUS_MT_DATA_NOT_ACK_ID                        0x30
// #define CHIP_TWI_0_STATUS_MT_ARB_LOST_ID                            0x38
// #define CHIP_TWI_0_STATUS_MR_START_ID                               0x08
// #define CHIP_TWI_0_STATUS_MR_REPEAT_ID                              0x10
// #define CHIP_TWI_0_STATUS_MR_ARB_LOST_ID                            0x38
// #define CHIP_TWI_0_STATUS_MR_SLA_R_ACK_ID                           0x40
// #define CHIP_TWI_0_STATUS_MR_SLA_R_NOT_ACK_ID                       0x48
// #define CHIP_TWI_0_STATUS_MR_DATA_ACK_ID                            0x50
// #define CHIP_TWI_0_STATUS_MR_DATA_NOT_ACK_ID                        0x58

#define CHIP_TWI_0_BIT_RATE_REG                                     CHIP_REG_TWBR

#define CHIP_TWI_0_CONTROL_REG                                      CHIP_REG_TWCR

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

#define CHIP_TWI_0_ADDRESS_REG                                      CHIP_REG_TWAR
#define CHIP_TWI_0_ADDRESS_MASK                                     0xFE

#define CHIP_TWI_0_ADDRESS_MASK_REG                                 CHIP_REG_TWAMR
#define CHIP_TWI_0_ADDRESS_MASK_MASK                                0xFE

//------------------------------------------------
// Eeprom

#define CHIP_EEPROM_0

#define CHIP_EEPROM_0_ADDRESS_REG                                   CHIP_REG_EEAR

#define CHIP_EEPROM_0_DATA_REG                                      CHIP_REG_EEDR

#define CHIP_EEPROM_0_PROGRAMMING_MODE_REG                          CHIP_REG_EECR
#define CHIP_EEPROM_0_PROGRAMMING_MODE_MASK                         0x30
#define CHIP_EEPROM_0_PROGRAMMING_MODE_ERASE_WRITE_ID               0x00
#define CHIP_EEPROM_0_PROGRAMMING_MODE_ERASE_ONLY_ID                0x10
#define CHIP_EEPROM_0_PROGRAMMING_MODE_WRITE_ONLY_ID                0x20

#define CHIP_EEPROM_0_READY_INT_ENABLE_REG                          CHIP_REG_EECR
#define CHIP_EEPROM_0_READY_INT_ENABLE_BIT                          3

#define CHIP_EEPROM_0_MASTER_WRITE_ENABLE_REG                       CHIP_REG_EECR
#define CHIP_EEPROM_0_MASTER_WRITE_ENABLE_BIT                       2

#define CHIP_EEPROM_0_WRITE_ENABLE_REG                              CHIP_REG_EECR
#define CHIP_EEPROM_0_WRITE_ENABLE_BIT                              1

#define CHIP_EEPROM_0_READ_ENABLE_REG                               CHIP_REG_EECR
#define CHIP_EEPROM_0_READ_ENABLE_BIT                               0
#endif

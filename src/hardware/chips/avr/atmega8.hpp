#ifndef NBLIB_ATMEGA8_HPP
#define NBLIB_ATMEGA8_HPP

#define CHIP atmega8

//------------------------------------------------
// Registers

#define CHIP_REG_TWBR                                               Register<uint8_t, 0x20>
#define CHIP_REG_TWSR                                               Register<uint8_t, 0x21, 0xF8>
#define CHIP_REG_TWAR                                               Register<uint8_t, 0x22>
#define CHIP_REG_TWDR                                               Register<uint8_t, 0x23>
#define CHIP_REG_ADC                                                Register<uint16_t, 0x24>
#define CHIP_REG_ADCSRA                                             Register<uint8_t, 0x26, 0x50>
#define CHIP_REG_ADMUX                                              Register<uint8_t, 0x27>
#define CHIP_REG_ACSR                                               Register<uint8_t, 0x28>
#define CHIP_REG_UBRRL                                              Register<uint8_t, 0x29>
#define CHIP_REG_UCSRB                                              Register<uint8_t, 0x2A>
#define CHIP_REG_UCSRA                                              Register<uint8_t, 0x2B, 0xFC>
#define CHIP_REG_UDR                                                Register<uint8_t, 0x2C>
#define CHIP_REG_SPCR                                               Register<uint8_t, 0x2D>
#define CHIP_REG_SPSR                                               Register<uint8_t, 0x2E, 0xC0>
#define CHIP_REG_SPDR                                               Register<uint8_t, 0x2F>
#define CHIP_REG_PIND                                               Register<uint8_t, 0x30, 0xFF>
#define CHIP_REG_DDRD                                               Register<uint8_t, 0x31>
#define CHIP_REG_PORTD                                              Register<uint8_t, 0x32>
#define CHIP_REG_PINC                                               Register<uint8_t, 0x33, 0xFF>
#define CHIP_REG_DDRC                                               Register<uint8_t, 0x34>
#define CHIP_REG_PORTC                                              Register<uint8_t, 0x35>
#define CHIP_REG_PINB                                               Register<uint8_t, 0x36, 0xFF>
#define CHIP_REG_DDRB                                               Register<uint8_t, 0x37>
#define CHIP_REG_PORTB                                              Register<uint8_t, 0x38>
#define CHIP_REG_EECR                                               Register<uint8_t, 0x3C>
#define CHIP_REG_EEDR                                               Register<uint8_t, 0x3D>
#define CHIP_REG_EEAR                                               Register<uint16_t, 0x3E>
#define CHIP_REG_UBRRH                                              Register<uint8_t, 0x40>
#define CHIP_REG_UCSRC                                              Register<uint8_t, 0x40>
#define CHIP_REG_WDTCR                                              Register<uint8_t, 0x41>
#define CHIP_REG_ASSR                                               Register<uint8_t, 0x42>
#define CHIP_REG_OCR2                                               Register<uint8_t, 0x43>
#define CHIP_REG_TCNT2                                              Register<uint8_t, 0x44>
#define CHIP_REG_TCCR2                                              Register<uint8_t, 0x45>
#define CHIP_REG_ICR1                                               Register<uint16_t, 0x46>
#define CHIP_REG_OCR1B                                              Register<uint16_t, 0x48>
#define CHIP_REG_OCR1A                                              Register<uint16_t, 0x4A>
#define CHIP_REG_TCNT1                                              Register<uint16_t, 0x4C>
#define CHIP_REG_TCCR1B                                             Register<uint8_t, 0x4E>
#define CHIP_REG_TCCR1A                                             Register<uint8_t, 0x4F>
#define CHIP_REG_SFIOR                                              Register<uint8_t, 0x50>
#define CHIP_REG_OSCCAL                                             Register<uint8_t, 0x51>
#define CHIP_REG_TCNT0                                              Register<uint8_t, 0x52>
#define CHIP_REG_TCCR0                                              Register<uint8_t, 0x53>
#define CHIP_REG_MCUCSR                                             Register<uint8_t, 0x54>
#define CHIP_REG_MCUCR                                              Register<uint8_t, 0x55>
#define CHIP_REG_TWCR                                               Register<uint8_t, 0x56, 0x88>
#define CHIP_REG_SPMCR                                              Register<uint8_t, 0x57>
#define CHIP_REG_TIFR                                               Register<uint8_t, 0x58, 0xFF>
#define CHIP_REG_TIMSK                                              Register<uint8_t, 0x59>
#define CHIP_REG_GIFR                                               Register<uint8_t, 0x5A>
#define CHIP_REG_GICR                                               Register<uint8_t, 0x5B>
#define CHIP_REG_SP                                                 Register<uint16_t, 0x5D>
#define CHIP_REG_SREG                                               Register<uint8_t, 0x5F>

//------------------------------------------------
// Vectors

#define vectorInt0                                                  ISR(__vector_1)
#define vectorInt1                                                  ISR(__vector_2)
#define vectorTc2CompareA                                           ISR(__vector_3)
#define vectorTc2Overflow                                           ISR(__vector_4)
#define vectorTc1InputCapture                                       ISR(__vector_5)
#define vectorTc1CompareA                                           ISR(__vector_6)
#define vectorTc1CompareB                                           ISR(__vector_7)
#define vectorTc1Overflow                                           ISR(__vector_8)
#define vectorTc0Overflow                                           ISR(__vector_9)
#define vectorSpi0                                                  ISR(__vector_10)
#define vectorUsart0RxComplete                                      ISR(__vector_11)
#define vectorUsart0DataRegEmpty                                    ISR(__vector_12)
#define vectorUsart0TxComplete                                      ISR(__vector_13)
#define vectorAdc0                                                  ISR(__vector_14)
#define vectorEepromReady                                           ISR(__vector_15)
#define vectorAnalogComparator0                                     ISR(__vector_16)
#define vectorTwi0                                                  ISR(__vector_17)
#define vectorSpmReady                                              ISR(__vector_18)

//------------------------------------------------
// System

#define CHIP_SYSTEM_GLOBAL_INTERRUPT_REG                            CHIP_REG_SREG
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT                            7

//------------------------------------------------
// IO ports

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
#define CHIP_ADC_0_REFERENCE_INTERNAL_2_56_ID                       0xC0

#define CHIP_ADC_0_CHANNEL_REG                                      CHIP_REG_ADMUX
#define CHIP_ADC_0_CHANNEL_MASK                                     0x0F
#define CHIP_ADC_0_CHANNEL_0_ID                                     0x00
#define CHIP_ADC_0_CHANNEL_1_ID                                     0x01
#define CHIP_ADC_0_CHANNEL_2_ID                                     0x02
#define CHIP_ADC_0_CHANNEL_3_ID                                     0x03
#define CHIP_ADC_0_CHANNEL_4_ID                                     0x04
#define CHIP_ADC_0_CHANNEL_5_ID                                     0x05
#define CHIP_ADC_0_CHANNEL_6_ID                                     0x06
#define CHIP_ADC_0_CHANNEL_7_ID                                     0x07
#define CHIP_ADC_0_CHANNEL_8_ID                                     0x08
#define CHIP_ADC_0_CHANNEL_VBG_ID                                   0x0E
#define CHIP_ADC_0_CHANNEL_GND_ID                                   0x0F

#define CHIP_ADC_0_FREE_RUNNING_REG                                 CHIP_REG_ADCSRA
#define CHIP_ADC_0_FREE_RUNNING_BIT                                 5

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
// External interrupts

#define CHIP_EXINT_0
#define CHIP_EXINT_0_ENABLE_REG                                     CHIP_REG_GICR
#define CHIP_EXINT_0_ENABLE_BIT                                     6
#define CHIP_EXINT_0_INT_FLAG_REG                                   CHIP_REG_GIFR
#define CHIP_EXINT_0_INT_FLAG_BIT                                   6
#define CHIP_EXINT_0_TRIGGER_REG                                    CHIP_REG_MCUCR
#define CHIP_EXINT_0_TRIGGER_MASK                                   0x03
#define CHIP_EXINT_0_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_0_TRIGGER_CHANGE_ID                              0x01
#define CHIP_EXINT_0_TRIGGER_FALLING_ID                             0x02
#define CHIP_EXINT_0_TRIGGER_RISING_ID                              0x03

#define CHIP_EXINT_1
#define CHIP_EXINT_1_ENABLE_REG                                     CHIP_REG_GICR
#define CHIP_EXINT_1_ENABLE_BIT                                     7
#define CHIP_EXINT_1_INT_FLAG_REG                                   CHIP_REG_GIFR
#define CHIP_EXINT_1_INT_FLAG_BIT                                   7
#define CHIP_EXINT_1_TRIGGER_REG                                    CHIP_REG_MCUCR
#define CHIP_EXINT_1_TRIGGER_MASK                                   0x0C
#define CHIP_EXINT_1_TRIGGER_LOW_ID                                 0x00
#define CHIP_EXINT_1_TRIGGER_CHANGE_ID                              0x04
#define CHIP_EXINT_1_TRIGGER_FALLING_ID                             0x08
#define CHIP_EXINT_1_TRIGGER_RISING_ID                              0x0C

//------------------------------------------------
// Timer/Counters

#define CHIP_TC_0

#define CHIP_TC_0_CLOCK_REG                                         CHIP_REG_TCCR0
#define CHIP_TC_0_CLOCK_MASK                                        0x07
#define CHIP_TC_0_CLOCK_NONE_ID                                     0x00
#define CHIP_TC_0_CLOCK_1_ID                                        0x01
#define CHIP_TC_0_CLOCK_8_ID                                        0x02
#define CHIP_TC_0_CLOCK_64_ID                                       0x03
#define CHIP_TC_0_CLOCK_256_ID                                      0x04
#define CHIP_TC_0_CLOCK_1024_ID                                     0x05
#define CHIP_TC_0_CLOCK_EXT_FALLING_ID                              0x06
#define CHIP_TC_0_CLOCK_EXT_RISING_ID                               0x07

#define CHIP_TC_0_COUNTER_REG                                       CHIP_REG_TCNT0

#define CHIP_TC_0_PRESCALER_RESET_REG                               CHIP_REG_SFIOR
#define CHIP_TC_0_PRESCALER_RESET_BIT                               0

#define CHIP_TC_0_OVERFLOW_INT_ENABLE_REG                           CHIP_REG_TIMSK
#define CHIP_TC_0_OVERFLOW_INT_ENABLE_BIT                           0
#define CHIP_TC_0_OVERFLOW_INT_FLAG_REG                             CHIP_REG_TIFR
#define CHIP_TC_0_OVERFLOW_INT_FLAG_BIT                             0

//------------------------------------------------

#define CHIP_TC_1

#define CHIP_TC_1_WAVEFORM_REG                                      CHIP_REG_TCCR1A
#define CHIP_TC_1_WAVEFORM_MASK                                     0x03
#define CHIP_TC_1_WAVEFORM_REG_EXTRA                                CHIP_REG_TCCR1B
#define CHIP_TC_1_WAVEFORM_MASK_EXTRA                               0x18
#define CHIP_TC_1_WAVEFORM_NORMAL_ID                                0x0000
#define CHIP_TC_1_WAVEFORM_PWM_PHASE_CORRECT_8_ID                   0x0001
#define CHIP_TC_1_WAVEFORM_PWM_PHASE_CORRECT_9_ID                   0x0002
#define CHIP_TC_1_WAVEFORM_PWM_PHASE_CORRECT_10_ID                  0x0003
#define CHIP_TC_1_WAVEFORM_CTC_OCRA_ID                              0x0800
#define CHIP_TC_1_WAVEFORM_FAST_PWM_8_ID                            0x0801
#define CHIP_TC_1_WAVEFORM_FAST_PWM_9_ID                            0x0802
#define CHIP_TC_1_WAVEFORM_FAST_PWM_10_ID                           0x0803
#define CHIP_TC_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID                0x1000
#define CHIP_TC_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID           0x1001
#define CHIP_TC_1_WAVEFORM_PWM_PHASE_CORRECT_ID                     0x1002
#define CHIP_TC_1_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID                0x1003
#define CHIP_TC_1_WAVEFORM_CTC_ICR_ID                               0x1800
#define CHIP_TC_1_WAVEFORM_FAST_PWM_ID                              0x1802
#define CHIP_TC_1_WAVEFORM_FAST_PWM_OCRA_ID                         0x1803

#define CHIP_TC_1_CLOCK_REG                                         CHIP_REG_TCCR1B
#define CHIP_TC_1_CLOCK_MASK                                        0x07
#define CHIP_TC_1_CLOCK_NONE_ID                                     0x00
#define CHIP_TC_1_CLOCK_1_ID                                        0x01
#define CHIP_TC_1_CLOCK_8_ID                                        0x02
#define CHIP_TC_1_CLOCK_64_ID                                       0x03
#define CHIP_TC_1_CLOCK_256_ID                                      0x04
#define CHIP_TC_1_CLOCK_1024_ID                                     0x05
#define CHIP_TC_1_CLOCK_EXT_FALLING_ID                              0x06
#define CHIP_TC_1_CLOCK_EXT_RISING_ID                               0x07

#define CHIP_TC_1_COUNTER_REG                                       CHIP_REG_TCNT1

#define CHIP_TC_1_PRESCALER_RESET_REG                               CHIP_REG_SFIOR
#define CHIP_TC_1_PRESCALER_RESET_BIT                               0

#define CHIP_TC_1_COMPARE_A_REG                                     CHIP_REG_OCR1A
#define CHIP_TC_1_COMPARE_A_INT_ENABLE_REG                          CHIP_REG_TIMSK
#define CHIP_TC_1_COMPARE_A_INT_ENABLE_BIT                          4
#define CHIP_TC_1_COMPARE_A_INT_FLAG_REG                            CHIP_REG_TIFR
#define CHIP_TC_1_COMPARE_A_INT_FLAG_BIT                            4
#define CHIP_TC_1_COMPARE_A_OUTPUT_MODE_REG                         CHIP_REG_TCCR1A
#define CHIP_TC_1_COMPARE_A_OUTPUT_MODE_MASK                        0xC0
#define CHIP_TC_1_COMPARE_A_OUTPUT_MODE_DISCONNECTED_ID             0x00
#define CHIP_TC_1_COMPARE_A_OUTPUT_MODE_TOGGLE_ID                   0x40
#define CHIP_TC_1_COMPARE_A_OUTPUT_MODE_CLEAR_ID                    0x80
#define CHIP_TC_1_COMPARE_A_OUTPUT_MODE_SET_ID                      0xC0

#define CHIP_TC_1_COMPARE_B_REG                                     CHIP_REG_OCR1B
#define CHIP_TC_1_COMPARE_B_INT_ENABLE_REG                          CHIP_REG_TIMSK
#define CHIP_TC_1_COMPARE_B_INT_ENABLE_BIT                          3
#define CHIP_TC_1_COMPARE_B_INT_FLAG_REG                            CHIP_REG_TIFR
#define CHIP_TC_1_COMPARE_B_INT_FLAG_BIT                            3
#define CHIP_TC_1_COMPARE_B_OUTPUT_MODE_REG                         CHIP_REG_TCCR1A
#define CHIP_TC_1_COMPARE_B_OUTPUT_MODE_MASK                        0x30
#define CHIP_TC_1_COMPARE_B_OUTPUT_MODE_DISCONNECTED_ID             0x00
#define CHIP_TC_1_COMPARE_B_OUTPUT_MODE_TOGGLE_ID                   0x10
#define CHIP_TC_1_COMPARE_B_OUTPUT_MODE_CLEAR_ID                    0x20
#define CHIP_TC_1_COMPARE_B_OUTPUT_MODE_SET_ID                      0x30

#define CHIP_TC_1_OVERFLOW_INT_ENABLE_REG                           CHIP_REG_TIMSK
#define CHIP_TC_1_OVERFLOW_INT_ENABLE_BIT                           2
#define CHIP_TC_1_OVERFLOW_INT_FLAG_REG                             CHIP_REG_TIFR
#define CHIP_TC_1_OVERFLOW_INT_FLAG_BIT                             2

#define CHIP_TC_1_CAPTURE_REG                                       CHIP_REG_ICR1
#define CHIP_TC_1_CAPTURE_NOISE_CANCEL_ENABLE_REG                   CHIP_REG_TCCR1B
#define CHIP_TC_1_CAPTURE_NOISE_CANCEL_ENABLE_BIT                   7
#define CHIP_TC_1_CAPTURE_EDGE_REG                                  CHIP_REG_TCCR1B
#define CHIP_TC_1_CAPTURE_EDGE_MASK                                 0x40
#define CHIP_TC_1_CAPTURE_EDGE_FALLING_ID                           0x00
#define CHIP_TC_1_CAPTURE_EDGE_RISING_ID                            0x40
#define CHIP_TC_1_CAPTURE_INT_ENABLE_REG                            CHIP_REG_TIMSK
#define CHIP_TC_1_CAPTURE_INT_ENABLE_BIT                            5
#define CHIP_TC_1_CAPTURE_INT_FLAG_REG                              CHIP_REG_TIFR
#define CHIP_TC_1_CAPTURE_INT_FLAG_BIT                              5

//------------------------------------------------

#define CHIP_TC_2

#define CHIP_TC_2_WAVEFORM_REG                                      CHIP_REG_TCCR2
#define CHIP_TC_2_WAVEFORM_MASK                                     0x48
#define CHIP_TC_2_WAVEFORM_NORMAL_ID                                0x00
#define CHIP_TC_2_WAVEFORM_PWM_PHASE_CORRECT_ID                     0x40
#define CHIP_TC_2_WAVEFORM_CTC_OCRA_ID                              0x08
#define CHIP_TC_2_WAVEFORM_FAST_PWM_ID                              0x48

#define CHIP_TC_2_CLOCK_REG                                         CHIP_REG_TCCR2
#define CHIP_TC_2_CLOCK_MASK                                        0x07
#define CHIP_TC_2_CLOCK_NONE_ID                                     0x00
#define CHIP_TC_2_CLOCK_1_ID                                        0x01
#define CHIP_TC_2_CLOCK_8_ID                                        0x02
#define CHIP_TC_2_CLOCK_32_ID                                       0x03
#define CHIP_TC_2_CLOCK_64_ID                                       0x04
#define CHIP_TC_2_CLOCK_128_ID                                      0x05
#define CHIP_TC_2_CLOCK_256_ID                                      0x06
#define CHIP_TC_2_CLOCK_1024_ID                                     0x07

#define CHIP_TC_2_COUNTER_REG                                       CHIP_REG_TCNT2

#define CHIP_TC_2_PRESCALER_RESET_REG                               CHIP_REG_SFIOR
#define CHIP_TC_2_PRESCALER_RESET_BIT                               1

#define CHIP_TC_2_COMPARE_A_REG                                     CHIP_REG_OCR2
#define CHIP_TC_2_COMPARE_A_INT_ENABLE_REG                          CHIP_REG_TIMSK
#define CHIP_TC_2_COMPARE_A_INT_ENABLE_BIT                          7
#define CHIP_TC_2_COMPARE_A_INT_FLAG_REG                            CHIP_REG_TIFR
#define CHIP_TC_2_COMPARE_A_INT_FLAG_BIT                            7
#define CHIP_TC_2_COMPARE_A_OUTPUT_MODE_REG                         CHIP_REG_TCCR2
#define CHIP_TC_2_COMPARE_A_OUTPUT_MODE_MASK                        0x30
#define CHIP_TC_2_COMPARE_A_OUTPUT_MODE_DISCONNECTED_ID             0x00
#define CHIP_TC_2_COMPARE_A_OUTPUT_MODE_TOGGLE_ID                   0x10
#define CHIP_TC_2_COMPARE_A_OUTPUT_MODE_CLEAR_ID                    0x20
#define CHIP_TC_2_COMPARE_A_OUTPUT_MODE_SET_ID                      0x30

#define CHIP_TC_2_OVERFLOW_INT_ENABLE_REG                           CHIP_REG_TIMSK
#define CHIP_TC_2_OVERFLOW_INT_ENABLE_BIT                           6
#define CHIP_TC_2_OVERFLOW_INT_FLAG_REG                             CHIP_REG_TIFR
#define CHIP_TC_2_OVERFLOW_INT_FLAG_BIT                             6

//------------------------------------------------
// Usarts

#define CHIP_USART_0

#define CHIP_USART_0_RX_DATA_REG                                    CHIP_REG_UDR
#define CHIP_USART_0_RX_DATA_9_REG                                  CHIP_REG_UCSRB
#define CHIP_USART_0_RX_DATA_9_BIT                                  1

#define CHIP_USART_0_TX_DATA_REG                                    CHIP_REG_UDR
#define CHIP_USART_0_TX_DATA_9_REG                                  CHIP_REG_UCSRB
#define CHIP_USART_0_TX_DATA_9_BIT                                  0

#define CHIP_USART_0_BAUD_REG_HIGH                                  CHIP_REG_UBRRH
#define CHIP_USART_0_BAUD_REG_LOW                                   CHIP_REG_UBRRL

#define CHIP_USART_0_FRAME_ERROR_REG                                CHIP_REG_UCSRA
#define CHIP_USART_0_FRAME_ERROR_BIT                                4
#define CHIP_USART_0_DATA_OVERRUN_REG                               CHIP_REG_UCSRA
#define CHIP_USART_0_DATA_OVERRUN_BIT                               3
#define CHIP_USART_0_PARITY_ERROR_REG                               CHIP_REG_UCSRA
#define CHIP_USART_0_PARITY_ERROR_BIT                               2

#define CHIP_USART_0_BAUD_MODE_REG                                  CHIP_REG_UCSRA
#define CHIP_USART_0_BAUD_MODE_MASK                                 0x02
#define CHIP_USART_0_BAUD_MODE_NORMAL_ID                            0x00
#define CHIP_USART_0_BAUD_MODE_DOUBLE_ID                            0x02

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG              CHIP_REG_UCSRA
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT              0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSRB
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                     7
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_UCSRB
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                     6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG                  CHIP_REG_UCSRB
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT                  5

#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSRA
#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_BIT                       7
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_REG                       CHIP_REG_UCSRA
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_BIT                       6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_REG                    CHIP_REG_UCSRA
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_BIT                    5

#define CHIP_USART_0_RX_ENABLE_REG                                  CHIP_REG_UCSRB
#define CHIP_USART_0_RX_ENABLE_BIT                                  4
#define CHIP_USART_0_TX_ENABLE_REG                                  CHIP_REG_UCSRB
#define CHIP_USART_0_TX_ENABLE_BIT                                  3

#define CHIP_USART_0_MODE_REG                                       CHIP_REG_UCSRC
#define CHIP_USART_0_MODE_MASK                                      0xC0
#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                           0x80
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                            0xC0

#define CHIP_USART_0_PARITY_REG                                     CHIP_REG_UCSRC
#define CHIP_USART_0_PARITY_MASK                                    0xB0
#define CHIP_USART_0_PARITY_DISABLE_ID                              0x80
#define CHIP_USART_0_PARITY_EVEN_ID                                 0xA0
#define CHIP_USART_0_PARITY_ODD_ID                                  0xB0

#define CHIP_USART_0_STOP_BITS_REG                                  CHIP_REG_UCSRC
#define CHIP_USART_0_STOP_BITS_MASK                                 0x88
#define CHIP_USART_0_STOP_BITS_1_ID                                 0x80
#define CHIP_USART_0_STOP_BITS_2_ID                                 0x88

#define CHIP_USART_0_CHARACTER_SIZE_REG                             CHIP_REG_UCSRC
#define CHIP_USART_0_CHARACTER_SIZE_MASK                            0x86
#define CHIP_USART_0_CHARACTER_SIZE_REG_EXTRA                       CHIP_REG_UCSRB
#define CHIP_USART_0_CHARACTER_SIZE_MASK_EXTRA                      0x04
#define CHIP_USART_0_CHARACTER_SIZE_5_ID                            0x0080
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                            0x0082
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                            0x0084
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                            0x0086
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                            0x0486

#define CHIP_USART_0_POLARITY_REG                                   CHIP_REG_UCSRC
#define CHIP_USART_0_POLARITY_MASK                                  0x81
#define CHIP_USART_0_POLARITY_TX_RISING_RX_FALLING_ID               0x80
#define CHIP_USART_0_POLARITY_TX_FALLING_RX_RISING_ID               0x81

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

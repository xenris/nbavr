#ifndef NBOS_ATMEGA8_HPP
#define NBOS_ATMEGA8_HPP

#define NBOS_CHIP_DEFINED

//------------------------------------------------
// Memory

#define CHIP_RAM_SIZE                                               1024

//------------------------------------------------
// Registers

#define CHIP_REG_TWBR_ADDR                                          0x20
#define CHIP_REG_TWBR_TYPE                                          uint8_t
#define CHIP_REG_TWSR_ADDR                                          0x21
#define CHIP_REG_TWSR_TYPE                                          uint8_t
#define CHIP_REG_TWAR_ADDR                                          0x22
#define CHIP_REG_TWAR_TYPE                                          uint8_t
#define CHIP_REG_TWDR_ADDR                                          0x23
#define CHIP_REG_TWDR_TYPE                                          uint8_t
#define CHIP_REG_ADC_ADDR                                           0x24
#define CHIP_REG_ADC_TYPE                                           uint16_t
#define CHIP_REG_ADCSRA_ADDR                                        0x26
#define CHIP_REG_ADCSRA_TYPE                                        uint8_t
#define CHIP_REG_ADMUX_ADDR                                         0x27
#define CHIP_REG_ADMUX_TYPE                                         uint8_t
#define CHIP_REG_ACSR_ADDR                                          0x28
#define CHIP_REG_ACSR_TYPE                                          uint8_t
#define CHIP_REG_UBRRL_ADDR                                         0x29
#define CHIP_REG_UBRRL_TYPE                                         uint8_t
#define CHIP_REG_UCSRB_ADDR                                         0x2A
#define CHIP_REG_UCSRB_TYPE                                         uint8_t
#define CHIP_REG_UCSRA_ADDR                                         0x2B
#define CHIP_REG_UCSRA_TYPE                                         uint8_t
#define CHIP_REG_UDR_ADDR                                           0x2C
#define CHIP_REG_UDR_TYPE                                           uint8_t
#define CHIP_REG_SPCR_ADDR                                          0x2D
#define CHIP_REG_SPCR_TYPE                                          uint8_t
#define CHIP_REG_SPSR_ADDR                                          0x2E
#define CHIP_REG_SPSR_TYPE                                          uint8_t
#define CHIP_REG_SPDR_ADDR                                          0x2F
#define CHIP_REG_SPDR_TYPE                                          uint8_t
#define CHIP_REG_PIND_ADDR                                          0x30
#define CHIP_REG_PIND_TYPE                                          uint8_t
#define CHIP_REG_DDRD_ADDR                                          0x31
#define CHIP_REG_DDRD_TYPE                                          uint8_t
#define CHIP_REG_PORTD_ADDR                                         0x32
#define CHIP_REG_PORTD_TYPE                                         uint8_t
#define CHIP_REG_PINC_ADDR                                          0x33
#define CHIP_REG_PINC_TYPE                                          uint8_t
#define CHIP_REG_DDRC_ADDR                                          0x34
#define CHIP_REG_DDRC_TYPE                                          uint8_t
#define CHIP_REG_PORTC_ADDR                                         0x35
#define CHIP_REG_PORTC_TYPE                                         uint8_t
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
#define CHIP_REG_UBRRH_ADDR                                         0x40
#define CHIP_REG_UBRRH_TYPE                                         uint8_t
#define CHIP_REG_UCSRC_ADDR                                         0x40
#define CHIP_REG_UCSRC_TYPE                                         uint8_t
#define CHIP_REG_WDTCR_ADDR                                         0x41
#define CHIP_REG_WDTCR_TYPE                                         uint8_t
#define CHIP_REG_ASSR_ADDR                                          0x42
#define CHIP_REG_ASSR_TYPE                                          uint8_t
#define CHIP_REG_OCR2_ADDR                                          0x43
#define CHIP_REG_OCR2_TYPE                                          uint8_t
#define CHIP_REG_TCNT2_ADDR                                         0x44
#define CHIP_REG_TCNT2_TYPE                                         uint8_t
#define CHIP_REG_TCCR2_ADDR                                         0x45
#define CHIP_REG_TCCR2_TYPE                                         uint8_t
#define CHIP_REG_ICR1_ADDR                                          0x46
#define CHIP_REG_ICR1_TYPE                                          uint16_t
#define CHIP_REG_OCR1B_ADDR                                         0x48
#define CHIP_REG_OCR1B_TYPE                                         uint16_t
#define CHIP_REG_OCR1A_ADDR                                         0x4A
#define CHIP_REG_OCR1A_TYPE                                         uint16_t
#define CHIP_REG_TCNT1_ADDR                                         0x4C
#define CHIP_REG_TCNT1_TYPE                                         uint16_t
#define CHIP_REG_TCCR1B_ADDR                                        0x4E
#define CHIP_REG_TCCR1B_TYPE                                        uint8_t
#define CHIP_REG_TCCR1A_ADDR                                        0x4F
#define CHIP_REG_TCCR1A_TYPE                                        uint8_t
#define CHIP_REG_SFIOR_ADDR                                         0x50
#define CHIP_REG_SFIOR_TYPE                                         uint8_t
#define CHIP_REG_OSCCAL_ADDR                                        0x51
#define CHIP_REG_OSCCAL_TYPE                                        uint8_t
#define CHIP_REG_TCNT0_ADDR                                         0x52
#define CHIP_REG_TCNT0_TYPE                                         uint8_t
#define CHIP_REG_TCCR0_ADDR                                         0x53
#define CHIP_REG_TCCR0_TYPE                                         uint8_t
#define CHIP_REG_MCUCSR_ADDR                                        0x54
#define CHIP_REG_MCUCSR_TYPE                                        uint8_t
#define CHIP_REG_MCUCR_ADDR                                         0x55
#define CHIP_REG_MCUCR_TYPE                                         uint8_t
#define CHIP_REG_TWCR_ADDR                                          0x56
#define CHIP_REG_TWCR_TYPE                                          uint8_t
#define CHIP_REG_SPMCR_ADDR                                         0x57
#define CHIP_REG_SPMCR_TYPE                                         uint8_t
#define CHIP_REG_TIFR_ADDR                                          0x58
#define CHIP_REG_TIFR_TYPE                                          uint8_t
#define CHIP_REG_TIMSK_ADDR                                         0x59
#define CHIP_REG_TIMSK_TYPE                                         uint8_t
#define CHIP_REG_GIFR_ADDR                                          0x5A
#define CHIP_REG_GIFR_TYPE                                          uint8_t
#define CHIP_REG_GICR_ADDR                                          0x5B
#define CHIP_REG_GICR_TYPE                                          uint8_t
#define CHIP_REG_SPL_ADDR                                           0x5D
#define CHIP_REG_SPL_TYPE                                           uint8_t
#define CHIP_REG_SPH_ADDR                                           0x5E
#define CHIP_REG_SPH_TYPE                                           uint8_t
#define CHIP_REG_SREG_ADDR                                          0x5F
#define CHIP_REG_SREG_TYPE                                          uint8_t

//------------------------------------------------
// Vectors

#define CHIP_VECT_RESET                                             1
#define CHIP_VECT_INT0                                              2
#define CHIP_VECT_INT1                                              3
#define CHIP_VECT_TIMER2_COMP                                       4
#define CHIP_VECT_TIMER2_OVF                                        5
#define CHIP_VECT_TIMER1_CAPT                                       6
#define CHIP_VECT_TIMER1_COMPA                                      7
#define CHIP_VECT_TIMER1_COMPB                                      8
#define CHIP_VECT_TIMER1_OVF                                        9
#define CHIP_VECT_TIMER0_OVF                                        10
#define CHIP_VECT_SPI_STC                                           11
#define CHIP_VECT_USART_RX                                          12
#define CHIP_VECT_USART_UDRE                                        13
#define CHIP_VECT_USART_TX                                          14
#define CHIP_VECT_ADC                                               15
#define CHIP_VECT_EE_READY                                          16
#define CHIP_VECT_ANALOG_COMP                                       17
#define CHIP_VECT_TWI                                               18
#define CHIP_VECT_SPM_READY                                         19

//------------------------------------------------
// System

// Possibly need IDs for chips which have inhibit instead of enable.
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG                      CHIP_REG_SREG
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_BIT                      7

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

#define CHIP_PIN_B6                                                 true
#define CHIP_PIN_B6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_B6_MODE_BIT_0_REG                                  CHIP_REG_DDRB
#define CHIP_PIN_B6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_B6_MODE_BIT_1_REG                                  CHIP_REG_PORTB
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
#define CHIP_PIN_D7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_D7_INPUT_BIT_0_REG                                 CHIP_REG_PIND
#define CHIP_PIN_D7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_D7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTD
#define CHIP_PIN_D7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_D7_TOGGLE_BIT_0_REG                                CHIP_REG_PIND

// //------------------------------------------------
// // Reset Status Register

// #define CHIP_RESET_STATUS_REG                                       CHIP_REG_MCUCSR

// //------------------------------------------------
// // Watchdog Timer

// #define CHIP_WATCHDOG_TIMER_CONTROL_REG                             CHIP_REG_WDTCR
// #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_0_BIT                     0
// #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_1_BIT                     1
// #define CHIP_WATCHDOG_TIMER_PRESCALER_BIT_2_BIT                     2
// #define CHIP_WATCHDOG_TIMER_ENABLE_BIT                              3
// #define CHIP_WATCHDOG_TIMER_CHANGE_ENABLE_BIT                       4

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
#define CHIP_ADC_0_CHANNEL_VBG_ID                                   14
#define CHIP_ADC_0_CHANNEL_GND_ID                                   15

#define CHIP_ADC_0_TRIGGER_BIT_0_REG                                CHIP_REG_ADCSRA
#define CHIP_ADC_0_TRIGGER_BIT_0_BIT                                5
#define CHIP_ADC_0_TRIGGER_SINGLE_CONVERSION_ID                     0
#define CHIP_ADC_0_TRIGGER_FREE_RUNNING_ID                          1

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
#define CHIP_EXINT_0_ENABLE_BIT_0_REG                               CHIP_REG_GICR
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

#define CHIP_EXINT_1                                                true
#define CHIP_EXINT_1_ENABLE_BIT_0_REG                               CHIP_REG_GICR
#define CHIP_EXINT_1_ENABLE_BIT_0_BIT                               7
#define CHIP_EXINT_1_INT_FLAG_BIT_0_REG                             CHIP_REG_GIFR
#define CHIP_EXINT_1_INT_FLAG_BIT_0_BIT                             7
#define CHIP_EXINT_1_TRIGGER_BIT_0_REG                              CHIP_REG_MCUCR
#define CHIP_EXINT_1_TRIGGER_BIT_1_REG                              CHIP_REG_MCUCR
#define CHIP_EXINT_1_TRIGGER_BIT_0_BIT                              2
#define CHIP_EXINT_1_TRIGGER_BIT_1_BIT                              3
#define CHIP_EXINT_1_TRIGGER_LOW_ID                                 0
#define CHIP_EXINT_1_TRIGGER_CHANGE_ID                              1
#define CHIP_EXINT_1_TRIGGER_FALLING_ID                             2
#define CHIP_EXINT_1_TRIGGER_RISING_ID                              3
#define CHIP_EXINT_1_INT_VECTOR                                     VECT(CHIP_VECT_INT1)

//------------------------------------------------
// Timers

#define CHIP_TIMER_0                                                true

#define CHIP_TIMER_0_TYPE                                           uint8_t

#define CHIP_TIMER_0_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_0_CLOCK_1_ID                                     1
#define CHIP_TIMER_0_CLOCK_8_ID                                     2
#define CHIP_TIMER_0_CLOCK_64_ID                                    3
#define CHIP_TIMER_0_CLOCK_256_ID                                   4
#define CHIP_TIMER_0_CLOCK_1024_ID                                  5
#define CHIP_TIMER_0_CLOCK_EXT_FALLING_ID                           6
#define CHIP_TIMER_0_CLOCK_EXT_RISING_ID                            7
#define CHIP_TIMER_0_CLOCK_BIT_0_REG                                CHIP_REG_TCCR0
#define CHIP_TIMER_0_CLOCK_BIT_1_REG                                CHIP_REG_TCCR0
#define CHIP_TIMER_0_CLOCK_BIT_2_REG                                CHIP_REG_TCCR0
#define CHIP_TIMER_0_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_0_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_0_CLOCK_BIT_2_BIT                                2

#define CHIP_TIMER_0_COUNTER_REG                                    CHIP_REG_TCNT0

#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_BIT                          0
#define CHIP_TIMER_0_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER0_OVF)

//------------------------------------------------

#define CHIP_TIMER_1                                                true

#define CHIP_TIMER_1_TYPE                                           uint16_t

#define CHIP_TIMER_1_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR1A
#define CHIP_TIMER_1_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR1A
#define CHIP_TIMER_1_WAVEFORM_BIT_2_REG                             CHIP_REG_TCCR1B
#define CHIP_TIMER_1_WAVEFORM_BIT_3_REG                             CHIP_REG_TCCR1B
#define CHIP_TIMER_1_WAVEFORM_BIT_0_BIT                             0
#define CHIP_TIMER_1_WAVEFORM_BIT_1_BIT                             1
#define CHIP_TIMER_1_WAVEFORM_BIT_2_BIT                             3
#define CHIP_TIMER_1_WAVEFORM_BIT_3_BIT                             4
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
#define CHIP_TIMER_1_WAVEFORM_CTC_ID                                12
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_ID                           14
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_OCRA_ID                      15

#define CHIP_TIMER_1_CLOCK_BIT_0_REG                                CHIP_REG_TCCR1B
#define CHIP_TIMER_1_CLOCK_BIT_1_REG                                CHIP_REG_TCCR1B
#define CHIP_TIMER_1_CLOCK_BIT_2_REG                                CHIP_REG_TCCR1B
#define CHIP_TIMER_1_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_1_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_1_CLOCK_BIT_2_BIT                                2
#define CHIP_TIMER_1_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_1_CLOCK_1_ID                                     1
#define CHIP_TIMER_1_CLOCK_8_ID                                     2
#define CHIP_TIMER_1_CLOCK_64_ID                                    3
#define CHIP_TIMER_1_CLOCK_256_ID                                   4
#define CHIP_TIMER_1_CLOCK_1024_ID                                  5
#define CHIP_TIMER_1_CLOCK_EXT_FALLING_ID                           6
#define CHIP_TIMER_1_CLOCK_EXT_RISING_ID                            7

#define CHIP_TIMER_1_COUNTER_REG                                    CHIP_REG_TCNT1

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
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_BIT                        4
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_BIT                          4
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
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_BIT                        3
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_BIT                          3
#define CHIP_TIMER_1_OUTPUT_B_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_COMPB)

#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                        2
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_BIT                          2
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
#define CHIP_TIMER_1_INPUT_INT_ENABLE_REG                           CHIP_REG_TIMSK
#define CHIP_TIMER_1_INPUT_INT_ENABLE_BIT                           5
#define CHIP_TIMER_1_INPUT_INT_FLAG_REG                             CHIP_REG_TIFR
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
#define CHIP_TIMER_2_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR2
#define CHIP_TIMER_2_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR2
#define CHIP_TIMER_2_WAVEFORM_BIT_0_BIT                             6
#define CHIP_TIMER_2_WAVEFORM_BIT_1_BIT                             5

#define CHIP_TIMER_2_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_2_CLOCK_1_ID                                     1
#define CHIP_TIMER_2_CLOCK_8_ID                                     2
#define CHIP_TIMER_2_CLOCK_32_ID                                    3
#define CHIP_TIMER_2_CLOCK_64_ID                                    4
#define CHIP_TIMER_2_CLOCK_128_ID                                   5
#define CHIP_TIMER_2_CLOCK_256_ID                                   6
#define CHIP_TIMER_2_CLOCK_1024_ID                                  7
#define CHIP_TIMER_2_CLOCK_BIT_0_REG                                CHIP_REG_TCCR2
#define CHIP_TIMER_2_CLOCK_BIT_1_REG                                CHIP_REG_TCCR2
#define CHIP_TIMER_2_CLOCK_BIT_2_REG                                CHIP_REG_TCCR2
#define CHIP_TIMER_2_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_2_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_2_CLOCK_BIT_2_BIT                                2

#define CHIP_TIMER_2_COUNTER_REG                                    CHIP_REG_TCNT2

#define CHIP_TIMER_2_OUTPUT_A                                       true
#define CHIP_TIMER_2_OUTPUT_A_PIN                                   PortB::Pin3
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_0_REG                        CHIP_REG_TCCR2
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_1_REG                        CHIP_REG_TCCR2
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_0_BIT                        4
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_1_BIT                        5
#define CHIP_TIMER_2_OUTPUT_A_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_2_OUTPUT_A_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_2_OUTPUT_A_MODE_CLEAR_ID                         2
#define CHIP_TIMER_2_OUTPUT_A_MODE_SET_ID                           3
#define CHIP_TIMER_2_OUTPUT_A_REG                                   CHIP_REG_OCR2
#define CHIP_TIMER_2_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_2_OUTPUT_A_INT_ENABLE_BIT                        7
#define CHIP_TIMER_2_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_2_OUTPUT_A_INT_FLAG_BIT                          7
#define CHIP_TIMER_2_OUTPUT_A_INT_VECTOR                            VECT(CHIP_VECT_TIMER2_COMP)

#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK
#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_BIT                        6
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_BIT                          6
#define CHIP_TIMER_2_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER2_OVF)

//------------------------------------------------
// Usarts

#define CHIP_USART_0                                                true

#define CHIP_USART_0_DATA_REG                                       CHIP_REG_UDR

#define CHIP_USART_0_BAUD_RATE_REG_HIGH                             CHIP_REG_UBRRH
#define CHIP_USART_0_BAUD_RATE_REG_LOW                              CHIP_REG_UBRRL

#define CHIP_USART_0_FRAME_ERROR_BIT_0_REG                          CHIP_REG_UCSRA
#define CHIP_USART_0_FRAME_ERROR_BIT_0_BIT                          4
#define CHIP_USART_0_DATA_OVERRUN_BIT_0_REG                         CHIP_REG_UCSRA
#define CHIP_USART_0_DATA_OVERRUN_BIT_0_BIT                         3
#define CHIP_USART_0_PARITY_ERROR_BIT_0_REG                         CHIP_REG_UCSRA
#define CHIP_USART_0_PARITY_ERROR_BIT_0_BIT                         2

#define CHIP_USART_0_DOUBLE_SPEED_BIT_0_REG                         CHIP_REG_UCSRA
#define CHIP_USART_0_DOUBLE_SPEED_BIT_0_BIT                         1

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT_0_REG        CHIP_REG_UCSRA
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT        0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_UCSRB
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT_0_BIT               7
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_UCSRB
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT_0_BIT               6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT_0_REG            CHIP_REG_UCSRB
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT            5

#define CHIP_USART_0_RX_ENABLE_BIT_0_REG                            CHIP_REG_UCSRB
#define CHIP_USART_0_RX_ENABLE_BIT_0_BIT                            4
#define CHIP_USART_0_TX_ENABLE_BIT_0_REG                            CHIP_REG_UCSRB
#define CHIP_USART_0_TX_ENABLE_BIT_0_BIT                            3

#define CHIP_USART_0_RX_DATA_BIT_8_REG                              CHIP_REG_UCSRB
#define CHIP_USART_0_RX_DATA_BIT_8_BIT                              1
#define CHIP_USART_0_TX_DATA_BIT_8_REG                              CHIP_REG_UCSRB
#define CHIP_USART_0_TX_DATA_BIT_8_BIT                              0

#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                           2
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                            3
#define CHIP_USART_0_MODE_BIT_0_REG                                 CHIP_REG_UCSRC
#define CHIP_USART_0_MODE_BIT_1_REG                                 CHIP_REG_UCSRC
#define CHIP_USART_0_MODE_BIT_0_BIT                                 6
#define CHIP_USART_0_MODE_BIT_1_BIT                                 7

#define CHIP_USART_0_PARITY_DISABLE_ID                              4
#define CHIP_USART_0_PARITY_EVEN_ID                                 6
#define CHIP_USART_0_PARITY_ODD_ID                                  7
#define CHIP_USART_0_PARITY_BIT_0_REG                               CHIP_REG_UCSRC
#define CHIP_USART_0_PARITY_BIT_1_REG                               CHIP_REG_UCSRC
#define CHIP_USART_0_PARITY_BIT_2_REG                               CHIP_REG_UCSRC
#define CHIP_USART_0_PARITY_BIT_0_BIT                               4
#define CHIP_USART_0_PARITY_BIT_1_BIT                               5
#define CHIP_USART_0_PARITY_BIT_2_BIT                               7

#define CHIP_USART_0_STOP_BITS_1_ID                                 2
#define CHIP_USART_0_STOP_BITS_2_ID                                 3
#define CHIP_USART_0_STOP_BITS_BIT_0_REG                            CHIP_REG_UCSRC
#define CHIP_USART_0_STOP_BITS_BIT_1_REG                            CHIP_REG_UCSRC
#define CHIP_USART_0_STOP_BITS_BIT_0_BIT                            3
#define CHIP_USART_0_STOP_BITS_BIT_1_BIT                            7

#define CHIP_USART_0_CHARACTER_SIZE_5_ID                            8
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                            9
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                            10
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                            11
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                            15
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_REG                       CHIP_REG_UCSRC
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_REG                       CHIP_REG_UCSRC
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_REG                       CHIP_REG_UCSRB
#define CHIP_USART_0_CHARACTER_SIZE_BIT_3_REG                       CHIP_REG_UCSRC
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_BIT                       1
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_BIT                       2
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_BIT                       2
#define CHIP_USART_0_CHARACTER_SIZE_BIT_3_BIT                       7

#define CHIP_USART_0_POLARITY_TX_RISING_RX_FALLING_ID               2
#define CHIP_USART_0_POLARITY_TX_FALLING_RX_RISING_ID               3
#define CHIP_USART_0_POLARITY_BIT_0_REG                             CHIP_REG_UCSRC
#define CHIP_USART_0_POLARITY_BIT_1_REG                             CHIP_REG_UCSRC
#define CHIP_USART_0_POLARITY_BIT_0_BIT                             0
#define CHIP_USART_0_POLARITY_BIT_1_BIT                             7

#define CHIP_USART_0_RX_INT_VECTOR                                  VECT(CHIP_VECT_USART_RX)
#define CHIP_USART_0_DE_INT_VECTOR                                  VECT(CHIP_VECT_USART_UDRE)
#define CHIP_USART_0_TX_INT_VECTOR                                  VECT(CHIP_VECT_USART_TX)

#endif

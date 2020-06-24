#ifndef NBLIB_ATMEGA2560_HPP
#define NBLIB_ATMEGA2560_HPP

#define CHIP atmega2560

//------------------------------------------------
// Memory

#define CHIP_RAM_SIZE                                               (1024 * 8)

//------------------------------------------------
// Registers

#define CHIP_REG_PINA_ADDR                                          0x20
#define CHIP_REG_PINA_TYPE                                          uint8_t
#define CHIP_REG_DDRA_ADDR                                          0x21
#define CHIP_REG_DDRA_TYPE                                          uint8_t
#define CHIP_REG_PORTA_ADDR                                         0x22
#define CHIP_REG_PORTA_TYPE                                         uint8_t
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
#define CHIP_REG_PINE_ADDR                                          0x2C
#define CHIP_REG_PINE_TYPE                                          uint8_t
#define CHIP_REG_DDRE_ADDR                                          0x2D
#define CHIP_REG_DDRE_TYPE                                          uint8_t
#define CHIP_REG_PORTE_ADDR                                         0x2E
#define CHIP_REG_PORTE_TYPE                                         uint8_t
#define CHIP_REG_PINF_ADDR                                          0x2F
#define CHIP_REG_PINF_TYPE                                          uint8_t
#define CHIP_REG_DDRF_ADDR                                          0x30
#define CHIP_REG_DDRF_TYPE                                          uint8_t
#define CHIP_REG_PORTF_ADDR                                         0x31
#define CHIP_REG_PORTF_TYPE                                         uint8_t
#define CHIP_REG_PING_ADDR                                          0x32
#define CHIP_REG_PING_TYPE                                          uint8_t
#define CHIP_REG_DDRG_ADDR                                          0x33
#define CHIP_REG_DDRG_TYPE                                          uint8_t
#define CHIP_REG_PORTG_ADDR                                         0x34
#define CHIP_REG_PORTG_TYPE                                         uint8_t
#define CHIP_REG_TIFR0_ADDR                                         0x35
#define CHIP_REG_TIFR0_TYPE                                         uint8_t
#define CHIP_REG_TIFR1_ADDR                                         0x36
#define CHIP_REG_TIFR1_TYPE                                         uint8_t
#define CHIP_REG_TIFR2_ADDR                                         0x37
#define CHIP_REG_TIFR2_TYPE                                         uint8_t
#define CHIP_REG_TIFR3_ADDR                                         0x38
#define CHIP_REG_TIFR3_TYPE                                         uint8_t
#define CHIP_REG_TIFR4_ADDR                                         0x39
#define CHIP_REG_TIFR4_TYPE                                         uint8_t
#define CHIP_REG_TIFR5_ADDR                                         0x3A
#define CHIP_REG_TIFR5_TYPE                                         uint8_t
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
#define CHIP_REG_EEARL_ADDR                                         0x41
#define CHIP_REG_EEARL_TYPE                                         uint8_t
#define CHIP_REG_EEARH_ADDR                                         0x42
#define CHIP_REG_EEARH_TYPE                                         uint8_t
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
#define CHIP_REG_OCDR_ADDR                                          0x51
#define CHIP_REG_OCDR_TYPE                                          uint8_t
#define CHIP_REG_SMCR_ADDR                                          0x53
#define CHIP_REG_SMCR_TYPE                                          uint8_t
#define CHIP_REG_MCUSR_ADDR                                         0x54
#define CHIP_REG_MCUSR_TYPE                                         uint8_t
#define CHIP_REG_MCUCR_ADDR                                         0x55
#define CHIP_REG_MCUCR_TYPE                                         uint8_t
#define CHIP_REG_SPMCSR_ADDR                                        0x57
#define CHIP_REG_SPMCSR_TYPE                                        uint8_t
#define CHIP_REG_RAMPZ_ADDR                                         0x5B
#define CHIP_REG_RAMPZ_TYPE                                         uint8_t
#define CHIP_REG_EIND_ADDR                                          0x5C
#define CHIP_REG_EIND_TYPE                                          uint8_t
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
#define CHIP_REG_PRR0_ADDR                                          0x64
#define CHIP_REG_PRR0_TYPE                                          uint8_t
#define CHIP_REG_PRR1_ADDR                                          0x65
#define CHIP_REG_PRR1_TYPE                                          uint8_t
#define CHIP_REG_OSCCAL_ADDR                                        0x66
#define CHIP_REG_OSCCAL_TYPE                                        uint8_t
#define CHIP_REG_PCICR_ADDR                                         0x68
#define CHIP_REG_PCICR_TYPE                                         uint8_t
#define CHIP_REG_EICRA_ADDR                                         0x69
#define CHIP_REG_EICRA_TYPE                                         uint8_t
#define CHIP_REG_EICRB_ADDR                                         0x6A
#define CHIP_REG_EICRB_TYPE                                         uint8_t
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
#define CHIP_REG_TIMSK3_ADDR                                        0x71
#define CHIP_REG_TIMSK3_TYPE                                        uint8_t
#define CHIP_REG_TIMSK4_ADDR                                        0x72
#define CHIP_REG_TIMSK4_TYPE                                        uint8_t
#define CHIP_REG_TIMSK5_ADDR                                        0x73
#define CHIP_REG_TIMSK5_TYPE                                        uint8_t
#define CHIP_REG_XMCRA_ADDR                                         0x74
#define CHIP_REG_XMCRA_TYPE                                         uint8_t
#define CHIP_REG_XMCRB_ADDR                                         0x75
#define CHIP_REG_XMCRB_TYPE                                         uint8_t
#define CHIP_REG_ADC_ADDR                                           0x78
#define CHIP_REG_ADC_TYPE                                           uint16_t
#define CHIP_REG_ADCSRA_ADDR                                        0x7A
#define CHIP_REG_ADCSRA_TYPE                                        uint8_t
#define CHIP_REG_ADCSRB_ADDR                                        0x7B
#define CHIP_REG_ADCSRB_TYPE                                        uint8_t
#define CHIP_REG_ADMUX_ADDR                                         0x7C
#define CHIP_REG_ADMUX_TYPE                                         uint8_t
#define CHIP_REG_DIDR2_ADDR                                         0x7D
#define CHIP_REG_DIDR2_TYPE                                         uint8_t
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
#define CHIP_REG_TCNT1_ADDR                                         0x84
#define CHIP_REG_TCNT1_TYPE                                         uint16_t
#define CHIP_REG_ICR1_ADDR                                          0x86
#define CHIP_REG_ICR1_TYPE                                          uint16_t
#define CHIP_REG_OCR1A_ADDR                                         0x88
#define CHIP_REG_OCR1A_TYPE                                         uint16_t
#define CHIP_REG_OCR1B_ADDR                                         0x8A
#define CHIP_REG_OCR1B_TYPE                                         uint16_t
#define CHIP_REG_OCR1C_ADDR                                         0x8C
#define CHIP_REG_OCR1C_TYPE                                         uint16_t
#define CHIP_REG_TCCR3A_ADDR                                        0x90
#define CHIP_REG_TCCR3A_TYPE                                        uint8_t
#define CHIP_REG_TCCR3B_ADDR                                        0x91
#define CHIP_REG_TCCR3B_TYPE                                        uint8_t
#define CHIP_REG_TCCR3C_ADDR                                        0x92
#define CHIP_REG_TCCR3C_TYPE                                        uint8_t
#define CHIP_REG_TCNT3_ADDR                                         0x94
#define CHIP_REG_TCNT3_TYPE                                         uint16_t
#define CHIP_REG_ICR3_ADDR                                          0x96
#define CHIP_REG_ICR3_TYPE                                          uint16_t
#define CHIP_REG_OCR3A_ADDR                                         0x98
#define CHIP_REG_OCR3A_TYPE                                         uint16_t
#define CHIP_REG_OCR3B_ADDR                                         0x9A
#define CHIP_REG_OCR3B_TYPE                                         uint16_t
#define CHIP_REG_OCR3C_ADDR                                         0x9C
#define CHIP_REG_OCR3C_TYPE                                         uint16_t
#define CHIP_REG_TCCR4A_ADDR                                        0xA0
#define CHIP_REG_TCCR4A_TYPE                                        uint8_t
#define CHIP_REG_TCCR4B_ADDR                                        0xA1
#define CHIP_REG_TCCR4B_TYPE                                        uint8_t
#define CHIP_REG_TCCR4C_ADDR                                        0xA2
#define CHIP_REG_TCCR4C_TYPE                                        uint8_t
#define CHIP_REG_TCNT4_ADDR                                         0xA4
#define CHIP_REG_TCNT4_TYPE                                         uint16_t
#define CHIP_REG_ICR4_ADDR                                          0xA6
#define CHIP_REG_ICR4_TYPE                                          uint16_t
#define CHIP_REG_OCR4A_ADDR                                         0xA8
#define CHIP_REG_OCR4A_TYPE                                         uint16_t
#define CHIP_REG_OCR4B_ADDR                                         0xAA
#define CHIP_REG_OCR4B_TYPE                                         uint16_t
#define CHIP_REG_OCR4C_ADDR                                         0xAC
#define CHIP_REG_OCR4C_TYPE                                         uint16_t
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
#define CHIP_REG_UCSR1A_ADDR                                        0xC8
#define CHIP_REG_UCSR1A_TYPE                                        uint8_t
#define CHIP_REG_UCSR1B_ADDR                                        0xC9
#define CHIP_REG_UCSR1B_TYPE                                        uint8_t
#define CHIP_REG_UCSR1C_ADDR                                        0xCA
#define CHIP_REG_UCSR1C_TYPE                                        uint8_t
#define CHIP_REG_UBRR1_ADDR                                         0xCC
#define CHIP_REG_UBRR1_TYPE                                         uint16_t
#define CHIP_REG_UDR1_ADDR                                          0xCE
#define CHIP_REG_UDR1_TYPE                                          uint8_t
#define CHIP_REG_UCSR2A_ADDR                                        0xD0
#define CHIP_REG_UCSR2A_TYPE                                        uint8_t
#define CHIP_REG_UCSR2B_ADDR                                        0xD1
#define CHIP_REG_UCSR2B_TYPE                                        uint8_t
#define CHIP_REG_UCSR2C_ADDR                                        0xD2
#define CHIP_REG_UCSR2C_TYPE                                        uint8_t
#define CHIP_REG_UBRR2_ADDR                                         0xD4
#define CHIP_REG_UBRR2_TYPE                                         uint16_t
#define CHIP_REG_UDR2_ADDR                                          0xD6
#define CHIP_REG_UDR2_TYPE                                          uint8_t
#define CHIP_REG_PINH_ADDR                                          0x100
#define CHIP_REG_PINH_TYPE                                          uint8_t
#define CHIP_REG_DDRH_ADDR                                          0x101
#define CHIP_REG_DDRH_TYPE                                          uint8_t
#define CHIP_REG_PORTH_ADDR                                         0x102
#define CHIP_REG_PORTH_TYPE                                         uint8_t
#define CHIP_REG_PINJ_ADDR                                          0x103
#define CHIP_REG_PINJ_TYPE                                          uint8_t
#define CHIP_REG_DDRJ_ADDR                                          0x104
#define CHIP_REG_DDRJ_TYPE                                          uint8_t
#define CHIP_REG_PORTJ_ADDR                                         0x105
#define CHIP_REG_PORTJ_TYPE                                         uint8_t
#define CHIP_REG_PINK_ADDR                                          0x106
#define CHIP_REG_PINK_TYPE                                          uint8_t
#define CHIP_REG_DDRK_ADDR                                          0x107
#define CHIP_REG_DDRK_TYPE                                          uint8_t
#define CHIP_REG_PORTK_ADDR                                         0x108
#define CHIP_REG_PORTK_TYPE                                         uint8_t
#define CHIP_REG_PINL_ADDR                                          0x109
#define CHIP_REG_PINL_TYPE                                          uint8_t
#define CHIP_REG_DDRL_ADDR                                          0x10A
#define CHIP_REG_DDRL_TYPE                                          uint8_t
#define CHIP_REG_PORTL_ADDR                                         0x10B
#define CHIP_REG_PORTL_TYPE                                         uint8_t
#define CHIP_REG_TCCR5A_ADDR                                        0x120
#define CHIP_REG_TCCR5A_TYPE                                        uint8_t
#define CHIP_REG_TCCR5B_ADDR                                        0x121
#define CHIP_REG_TCCR5B_TYPE                                        uint8_t
#define CHIP_REG_TCCR5C_ADDR                                        0x122
#define CHIP_REG_TCCR5C_TYPE                                        uint8_t
#define CHIP_REG_TCNT5_ADDR                                         0x124
#define CHIP_REG_TCNT5_TYPE                                         uint16_t
#define CHIP_REG_ICR5_ADDR                                          0x126
#define CHIP_REG_ICR5_TYPE                                          uint16_t
#define CHIP_REG_OCR5A_ADDR                                         0x128
#define CHIP_REG_OCR5A_TYPE                                         uint16_t
#define CHIP_REG_OCR5B_ADDR                                         0x12A
#define CHIP_REG_OCR5B_TYPE                                         uint16_t
#define CHIP_REG_OCR5C_ADDR                                         0x12C
#define CHIP_REG_OCR5C_TYPE                                         uint16_t
#define CHIP_REG_UCSR3A_ADDR                                        0x130
#define CHIP_REG_UCSR3A_TYPE                                        uint8_t
#define CHIP_REG_UCSR3B_ADDR                                        0x131
#define CHIP_REG_UCSR3B_TYPE                                        uint8_t
#define CHIP_REG_UCSR3C_ADDR                                        0x132
#define CHIP_REG_UCSR3C_TYPE                                        uint8_t
#define CHIP_REG_UBRR3_ADDR                                         0x134
#define CHIP_REG_UBRR3_TYPE                                         uint16_t
#define CHIP_REG_UDR3_ADDR                                          0x136
#define CHIP_REG_UDR3_TYPE                                          uint8_t

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

// Possibly need IDs for chips which have inhibit instead of enable.
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG                      CHIP_REG_SREG
#define CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_BIT                      7

//------------------------------------------------
// Status Register

// #define CHIP_STATUS_REG                                             CHIP_REG_SREG

//------------------------------------------------
// Reset Status Register

// #define CHIP_RESET_STATUS_REG                                           CHIP_REG_MCUCR

//------------------------------------------------
// Watchdog Timer

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

#define CHIP_PORT_A                                                 true
#define CHIP_PORT_A_OUTPUT_REG                                      CHIP_REG_PORTA
#define CHIP_PORT_A_TOGGLE_OUTPUTS_REG                              CHIP_REG_PINA
#define CHIP_PORT_A_INPUT_REG                                       CHIP_REG_PINA

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

#define CHIP_PORT_E                                                 true
#define CHIP_PORT_E_OUTPUT_REG                                      CHIP_REG_PORTE
#define CHIP_PORT_E_TOGGLE_OUTPUTS_REG                              CHIP_REG_PINE
#define CHIP_PORT_E_INPUT_REG                                       CHIP_REG_PINE

#define CHIP_PORT_F                                                 true
#define CHIP_PORT_F_OUTPUT_REG                                      CHIP_REG_PORTF
#define CHIP_PORT_F_TOGGLE_OUTPUTS_REG                              CHIP_REG_PINF
#define CHIP_PORT_F_INPUT_REG                                       CHIP_REG_PINF

#define CHIP_PORT_G                                                 true
#define CHIP_PORT_G_OUTPUT_REG                                      CHIP_REG_PORTG
#define CHIP_PORT_G_TOGGLE_OUTPUTS_REG                              CHIP_REG_PING
#define CHIP_PORT_G_INPUT_REG                                       CHIP_REG_PING

#define CHIP_PORT_H                                                 true
#define CHIP_PORT_H_OUTPUT_REG                                      CHIP_REG_PORTH
#define CHIP_PORT_H_TOGGLE_OUTPUTS_REG                              CHIP_REG_PINH
#define CHIP_PORT_H_INPUT_REG                                       CHIP_REG_PINH

#define CHIP_PORT_J                                                 true
#define CHIP_PORT_J_OUTPUT_REG                                      CHIP_REG_PORTJ
#define CHIP_PORT_J_TOGGLE_OUTPUTS_REG                              CHIP_REG_PINJ
#define CHIP_PORT_J_INPUT_REG                                       CHIP_REG_PINJ

#define CHIP_PORT_K                                                 true
#define CHIP_PORT_K_OUTPUT_REG                                      CHIP_REG_PORTK
#define CHIP_PORT_K_TOGGLE_OUTPUTS_REG                              CHIP_REG_PINK
#define CHIP_PORT_K_INPUT_REG                                       CHIP_REG_PINK

#define CHIP_PORT_L                                                 true
#define CHIP_PORT_L_OUTPUT_REG                                      CHIP_REG_PORTL
#define CHIP_PORT_L_TOGGLE_OUTPUTS_REG                              CHIP_REG_PINL
#define CHIP_PORT_L_INPUT_REG                                       CHIP_REG_PINL

//------------------------------------------------
// IO pins

#define CHIP_PIN_MODE_INPUT_ID                                      0
#define CHIP_PIN_MODE_OUTPUT_ID                                     1
#define CHIP_PIN_MODE_INPUT_PULLUP_ID                               2

#define CHIP_PIN_A0                                                 true
#define CHIP_PIN_A0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_A0_MODE_BIT_0_REG                                  CHIP_REG_DDRA
#define CHIP_PIN_A0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_A0_MODE_BIT_1_REG                                  CHIP_REG_PORTA
#define CHIP_PIN_A0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_A0_INPUT_BIT_0_REG                                 CHIP_REG_PINA
#define CHIP_PIN_A0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_A0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTA
#define CHIP_PIN_A0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_A0_TOGGLE_BIT_0_REG                                CHIP_REG_PINA

#define CHIP_PIN_A1                                                 true
#define CHIP_PIN_A1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_A1_MODE_BIT_0_REG                                  CHIP_REG_DDRA
#define CHIP_PIN_A1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_A1_MODE_BIT_1_REG                                  CHIP_REG_PORTA
#define CHIP_PIN_A1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_A1_INPUT_BIT_0_REG                                 CHIP_REG_PINA
#define CHIP_PIN_A1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_A1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTA
#define CHIP_PIN_A1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_A1_TOGGLE_BIT_0_REG                                CHIP_REG_PINA

#define CHIP_PIN_A2                                                 true
#define CHIP_PIN_A2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_A2_MODE_BIT_0_REG                                  CHIP_REG_DDRA
#define CHIP_PIN_A2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_A2_MODE_BIT_1_REG                                  CHIP_REG_PORTA
#define CHIP_PIN_A2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_A2_INPUT_BIT_0_REG                                 CHIP_REG_PINA
#define CHIP_PIN_A2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_A2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTA
#define CHIP_PIN_A2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_A2_TOGGLE_BIT_0_REG                                CHIP_REG_PINA

#define CHIP_PIN_A3                                                 true
#define CHIP_PIN_A3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_A3_MODE_BIT_0_REG                                  CHIP_REG_DDRA
#define CHIP_PIN_A3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_A3_MODE_BIT_1_REG                                  CHIP_REG_PORTA
#define CHIP_PIN_A3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_A3_INPUT_BIT_0_REG                                 CHIP_REG_PINA
#define CHIP_PIN_A3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_A3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTA
#define CHIP_PIN_A3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_A3_TOGGLE_BIT_0_REG                                CHIP_REG_PINA

#define CHIP_PIN_A4                                                 true
#define CHIP_PIN_A4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_A4_MODE_BIT_0_REG                                  CHIP_REG_DDRA
#define CHIP_PIN_A4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_A4_MODE_BIT_1_REG                                  CHIP_REG_PORTA
#define CHIP_PIN_A4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_A4_INPUT_BIT_0_REG                                 CHIP_REG_PINA
#define CHIP_PIN_A4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_A4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTA
#define CHIP_PIN_A4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_A4_TOGGLE_BIT_0_REG                                CHIP_REG_PINA

#define CHIP_PIN_A5                                                 true
#define CHIP_PIN_A5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_A5_MODE_BIT_0_REG                                  CHIP_REG_DDRA
#define CHIP_PIN_A5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_A5_MODE_BIT_1_REG                                  CHIP_REG_PORTA
#define CHIP_PIN_A5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_A5_INPUT_BIT_0_REG                                 CHIP_REG_PINA
#define CHIP_PIN_A5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_A5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTA
#define CHIP_PIN_A5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_A5_TOGGLE_BIT_0_REG                                CHIP_REG_PINA

#define CHIP_PIN_A6                                                 true
#define CHIP_PIN_A6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_A6_MODE_BIT_0_REG                                  CHIP_REG_DDRA
#define CHIP_PIN_A6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_A6_MODE_BIT_1_REG                                  CHIP_REG_PORTA
#define CHIP_PIN_A6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_A6_INPUT_BIT_0_REG                                 CHIP_REG_PINA
#define CHIP_PIN_A6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_A6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTA
#define CHIP_PIN_A6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_A6_TOGGLE_BIT_0_REG                                CHIP_REG_PINA

#define CHIP_PIN_A7                                                 true
#define CHIP_PIN_A7_MODE_BIT_0_BIT                                  7
#define CHIP_PIN_A7_MODE_BIT_0_REG                                  CHIP_REG_DDRA
#define CHIP_PIN_A7_MODE_BIT_1_BIT                                  7
#define CHIP_PIN_A7_MODE_BIT_1_REG                                  CHIP_REG_PORTA
#define CHIP_PIN_A7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_A7_INPUT_BIT_0_REG                                 CHIP_REG_PINA
#define CHIP_PIN_A7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_A7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTA
#define CHIP_PIN_A7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_A7_TOGGLE_BIT_0_REG                                CHIP_REG_PINA

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

#define CHIP_PIN_E0                                                 true
#define CHIP_PIN_E0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_E0_MODE_BIT_0_REG                                  CHIP_REG_DDRE
#define CHIP_PIN_E0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_E0_MODE_BIT_1_REG                                  CHIP_REG_PORTE
#define CHIP_PIN_E0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_E0_INPUT_BIT_0_REG                                 CHIP_REG_PINE
#define CHIP_PIN_E0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_E0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTE
#define CHIP_PIN_E0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_E0_TOGGLE_BIT_0_REG                                CHIP_REG_PINE

#define CHIP_PIN_E1                                                 true
#define CHIP_PIN_E1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_E1_MODE_BIT_0_REG                                  CHIP_REG_DDRE
#define CHIP_PIN_E1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_E1_MODE_BIT_1_REG                                  CHIP_REG_PORTE
#define CHIP_PIN_E1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_E1_INPUT_BIT_0_REG                                 CHIP_REG_PINE
#define CHIP_PIN_E1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_E1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTE
#define CHIP_PIN_E1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_E1_TOGGLE_BIT_0_REG                                CHIP_REG_PINE

#define CHIP_PIN_E2                                                 true
#define CHIP_PIN_E2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_E2_MODE_BIT_0_REG                                  CHIP_REG_DDRE
#define CHIP_PIN_E2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_E2_MODE_BIT_1_REG                                  CHIP_REG_PORTE
#define CHIP_PIN_E2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_E2_INPUT_BIT_0_REG                                 CHIP_REG_PINE
#define CHIP_PIN_E2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_E2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTE
#define CHIP_PIN_E2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_E2_TOGGLE_BIT_0_REG                                CHIP_REG_PINE

#define CHIP_PIN_E3                                                 true
#define CHIP_PIN_E3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_E3_MODE_BIT_0_REG                                  CHIP_REG_DDRE
#define CHIP_PIN_E3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_E3_MODE_BIT_1_REG                                  CHIP_REG_PORTE
#define CHIP_PIN_E3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_E3_INPUT_BIT_0_REG                                 CHIP_REG_PINE
#define CHIP_PIN_E3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_E3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTE
#define CHIP_PIN_E3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_E3_TOGGLE_BIT_0_REG                                CHIP_REG_PINE

#define CHIP_PIN_E4                                                 true
#define CHIP_PIN_E4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_E4_MODE_BIT_0_REG                                  CHIP_REG_DDRE
#define CHIP_PIN_E4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_E4_MODE_BIT_1_REG                                  CHIP_REG_PORTE
#define CHIP_PIN_E4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_E4_INPUT_BIT_0_REG                                 CHIP_REG_PINE
#define CHIP_PIN_E4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_E4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTE
#define CHIP_PIN_E4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_E4_TOGGLE_BIT_0_REG                                CHIP_REG_PINE

#define CHIP_PIN_E5                                                 true
#define CHIP_PIN_E5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_E5_MODE_BIT_0_REG                                  CHIP_REG_DDRE
#define CHIP_PIN_E5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_E5_MODE_BIT_1_REG                                  CHIP_REG_PORTE
#define CHIP_PIN_E5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_E5_INPUT_BIT_0_REG                                 CHIP_REG_PINE
#define CHIP_PIN_E5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_E5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTE
#define CHIP_PIN_E5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_E5_TOGGLE_BIT_0_REG                                CHIP_REG_PINE

#define CHIP_PIN_E6                                                 true
#define CHIP_PIN_E6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_E6_MODE_BIT_0_REG                                  CHIP_REG_DDRE
#define CHIP_PIN_E6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_E6_MODE_BIT_1_REG                                  CHIP_REG_PORTE
#define CHIP_PIN_E6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_E6_INPUT_BIT_0_REG                                 CHIP_REG_PINE
#define CHIP_PIN_E6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_E6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTE
#define CHIP_PIN_E6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_E6_TOGGLE_BIT_0_REG                                CHIP_REG_PINE

#define CHIP_PIN_E7                                                 true
#define CHIP_PIN_E7_MODE_BIT_0_BIT                                  7
#define CHIP_PIN_E7_MODE_BIT_0_REG                                  CHIP_REG_DDRE
#define CHIP_PIN_E7_MODE_BIT_1_BIT                                  7
#define CHIP_PIN_E7_MODE_BIT_1_REG                                  CHIP_REG_PORTE
#define CHIP_PIN_E7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_E7_INPUT_BIT_0_REG                                 CHIP_REG_PINE
#define CHIP_PIN_E7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_E7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTE
#define CHIP_PIN_E7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_E7_TOGGLE_BIT_0_REG                                CHIP_REG_PINE

#define CHIP_PIN_F0                                                 true
#define CHIP_PIN_F0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_F0_MODE_BIT_0_REG                                  CHIP_REG_DDRF
#define CHIP_PIN_F0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_F0_MODE_BIT_1_REG                                  CHIP_REG_PORTF
#define CHIP_PIN_F0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_F0_INPUT_BIT_0_REG                                 CHIP_REG_PINF
#define CHIP_PIN_F0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_F0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTF
#define CHIP_PIN_F0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_F0_TOGGLE_BIT_0_REG                                CHIP_REG_PINF

#define CHIP_PIN_F1                                                 true
#define CHIP_PIN_F1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_F1_MODE_BIT_0_REG                                  CHIP_REG_DDRF
#define CHIP_PIN_F1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_F1_MODE_BIT_1_REG                                  CHIP_REG_PORTF
#define CHIP_PIN_F1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_F1_INPUT_BIT_0_REG                                 CHIP_REG_PINF
#define CHIP_PIN_F1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_F1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTF
#define CHIP_PIN_F1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_F1_TOGGLE_BIT_0_REG                                CHIP_REG_PINF

#define CHIP_PIN_F2                                                 true
#define CHIP_PIN_F2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_F2_MODE_BIT_0_REG                                  CHIP_REG_DDRF
#define CHIP_PIN_F2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_F2_MODE_BIT_1_REG                                  CHIP_REG_PORTF
#define CHIP_PIN_F2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_F2_INPUT_BIT_0_REG                                 CHIP_REG_PINF
#define CHIP_PIN_F2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_F2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTF
#define CHIP_PIN_F2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_F2_TOGGLE_BIT_0_REG                                CHIP_REG_PINF

#define CHIP_PIN_F3                                                 true
#define CHIP_PIN_F3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_F3_MODE_BIT_0_REG                                  CHIP_REG_DDRF
#define CHIP_PIN_F3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_F3_MODE_BIT_1_REG                                  CHIP_REG_PORTF
#define CHIP_PIN_F3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_F3_INPUT_BIT_0_REG                                 CHIP_REG_PINF
#define CHIP_PIN_F3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_F3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTF
#define CHIP_PIN_F3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_F3_TOGGLE_BIT_0_REG                                CHIP_REG_PINF

#define CHIP_PIN_F4                                                 true
#define CHIP_PIN_F4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_F4_MODE_BIT_0_REG                                  CHIP_REG_DDRF
#define CHIP_PIN_F4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_F4_MODE_BIT_1_REG                                  CHIP_REG_PORTF
#define CHIP_PIN_F4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_F4_INPUT_BIT_0_REG                                 CHIP_REG_PINF
#define CHIP_PIN_F4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_F4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTF
#define CHIP_PIN_F4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_F4_TOGGLE_BIT_0_REG                                CHIP_REG_PINF

#define CHIP_PIN_F5                                                 true
#define CHIP_PIN_F5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_F5_MODE_BIT_0_REG                                  CHIP_REG_DDRF
#define CHIP_PIN_F5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_F5_MODE_BIT_1_REG                                  CHIP_REG_PORTF
#define CHIP_PIN_F5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_F5_INPUT_BIT_0_REG                                 CHIP_REG_PINF
#define CHIP_PIN_F5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_F5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTF
#define CHIP_PIN_F5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_F5_TOGGLE_BIT_0_REG                                CHIP_REG_PINF

#define CHIP_PIN_F6                                                 true
#define CHIP_PIN_F6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_F6_MODE_BIT_0_REG                                  CHIP_REG_DDRF
#define CHIP_PIN_F6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_F6_MODE_BIT_1_REG                                  CHIP_REG_PORTF
#define CHIP_PIN_F6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_F6_INPUT_BIT_0_REG                                 CHIP_REG_PINF
#define CHIP_PIN_F6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_F6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTF
#define CHIP_PIN_F6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_F6_TOGGLE_BIT_0_REG                                CHIP_REG_PINF

#define CHIP_PIN_F7                                                 true
#define CHIP_PIN_F7_MODE_BIT_0_BIT                                  7
#define CHIP_PIN_F7_MODE_BIT_0_REG                                  CHIP_REG_DDRF
#define CHIP_PIN_F7_MODE_BIT_1_BIT                                  7
#define CHIP_PIN_F7_MODE_BIT_1_REG                                  CHIP_REG_PORTF
#define CHIP_PIN_F7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_F7_INPUT_BIT_0_REG                                 CHIP_REG_PINF
#define CHIP_PIN_F7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_F7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTF
#define CHIP_PIN_F7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_F7_TOGGLE_BIT_0_REG                                CHIP_REG_PINF

#define CHIP_PIN_G0                                                 true
#define CHIP_PIN_G0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_G0_MODE_BIT_0_REG                                  CHIP_REG_DDRG
#define CHIP_PIN_G0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_G0_MODE_BIT_1_REG                                  CHIP_REG_PORTG
#define CHIP_PIN_G0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_G0_INPUT_BIT_0_REG                                 CHIP_REG_PING
#define CHIP_PIN_G0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_G0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTG
#define CHIP_PIN_G0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_G0_TOGGLE_BIT_0_REG                                CHIP_REG_PING

#define CHIP_PIN_G1                                                 true
#define CHIP_PIN_G1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_G1_MODE_BIT_0_REG                                  CHIP_REG_DDRG
#define CHIP_PIN_G1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_G1_MODE_BIT_1_REG                                  CHIP_REG_PORTG
#define CHIP_PIN_G1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_G1_INPUT_BIT_0_REG                                 CHIP_REG_PING
#define CHIP_PIN_G1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_G1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTG
#define CHIP_PIN_G1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_G1_TOGGLE_BIT_0_REG                                CHIP_REG_PING

#define CHIP_PIN_G2                                                 true
#define CHIP_PIN_G2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_G2_MODE_BIT_0_REG                                  CHIP_REG_DDRG
#define CHIP_PIN_G2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_G2_MODE_BIT_1_REG                                  CHIP_REG_PORTG
#define CHIP_PIN_G2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_G2_INPUT_BIT_0_REG                                 CHIP_REG_PING
#define CHIP_PIN_G2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_G2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTG
#define CHIP_PIN_G2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_G2_TOGGLE_BIT_0_REG                                CHIP_REG_PING

#define CHIP_PIN_G3                                                 true
#define CHIP_PIN_G3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_G3_MODE_BIT_0_REG                                  CHIP_REG_DDRG
#define CHIP_PIN_G3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_G3_MODE_BIT_1_REG                                  CHIP_REG_PORTG
#define CHIP_PIN_G3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_G3_INPUT_BIT_0_REG                                 CHIP_REG_PING
#define CHIP_PIN_G3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_G3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTG
#define CHIP_PIN_G3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_G3_TOGGLE_BIT_0_REG                                CHIP_REG_PING

#define CHIP_PIN_G4                                                 true
#define CHIP_PIN_G4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_G4_MODE_BIT_0_REG                                  CHIP_REG_DDRG
#define CHIP_PIN_G4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_G4_MODE_BIT_1_REG                                  CHIP_REG_PORTG
#define CHIP_PIN_G4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_G4_INPUT_BIT_0_REG                                 CHIP_REG_PING
#define CHIP_PIN_G4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_G4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTG
#define CHIP_PIN_G4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_G4_TOGGLE_BIT_0_REG                                CHIP_REG_PING

#define CHIP_PIN_G5                                                 true
#define CHIP_PIN_G5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_G5_MODE_BIT_0_REG                                  CHIP_REG_DDRG
#define CHIP_PIN_G5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_G5_MODE_BIT_1_REG                                  CHIP_REG_PORTG
#define CHIP_PIN_G5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_G5_INPUT_BIT_0_REG                                 CHIP_REG_PING
#define CHIP_PIN_G5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_G5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTG
#define CHIP_PIN_G5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_G5_TOGGLE_BIT_0_REG                                CHIP_REG_PING

#define CHIP_PIN_G6                                                 true
#define CHIP_PIN_G6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_G6_MODE_BIT_0_REG                                  CHIP_REG_DDRG
#define CHIP_PIN_G6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_G6_MODE_BIT_1_REG                                  CHIP_REG_PORTG
#define CHIP_PIN_G6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_G6_INPUT_BIT_0_REG                                 CHIP_REG_PING
#define CHIP_PIN_G6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_G6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTG
#define CHIP_PIN_G6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_G6_TOGGLE_BIT_0_REG                                CHIP_REG_PING

#define CHIP_PIN_G7                                                 true
#define CHIP_PIN_G7_MODE_BIT_0_BIT                                  7
#define CHIP_PIN_G7_MODE_BIT_0_REG                                  CHIP_REG_DDRG
#define CHIP_PIN_G7_MODE_BIT_1_BIT                                  7
#define CHIP_PIN_G7_MODE_BIT_1_REG                                  CHIP_REG_PORTG
#define CHIP_PIN_G7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_G7_INPUT_BIT_0_REG                                 CHIP_REG_PING
#define CHIP_PIN_G7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_G7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTG
#define CHIP_PIN_G7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_G7_TOGGLE_BIT_0_REG                                CHIP_REG_PING

#define CHIP_PIN_H0                                                 true
#define CHIP_PIN_H0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_H0_MODE_BIT_0_REG                                  CHIP_REG_DDRH
#define CHIP_PIN_H0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_H0_MODE_BIT_1_REG                                  CHIP_REG_PORTH
#define CHIP_PIN_H0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_H0_INPUT_BIT_0_REG                                 CHIP_REG_PINH
#define CHIP_PIN_H0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_H0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTH
#define CHIP_PIN_H0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_H0_TOGGLE_BIT_0_REG                                CHIP_REG_PINH

#define CHIP_PIN_H1                                                 true
#define CHIP_PIN_H1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_H1_MODE_BIT_0_REG                                  CHIP_REG_DDRH
#define CHIP_PIN_H1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_H1_MODE_BIT_1_REG                                  CHIP_REG_PORTH
#define CHIP_PIN_H1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_H1_INPUT_BIT_0_REG                                 CHIP_REG_PINH
#define CHIP_PIN_H1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_H1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTH
#define CHIP_PIN_H1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_H1_TOGGLE_BIT_0_REG                                CHIP_REG_PINH

#define CHIP_PIN_H2                                                 true
#define CHIP_PIN_H2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_H2_MODE_BIT_0_REG                                  CHIP_REG_DDRH
#define CHIP_PIN_H2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_H2_MODE_BIT_1_REG                                  CHIP_REG_PORTH
#define CHIP_PIN_H2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_H2_INPUT_BIT_0_REG                                 CHIP_REG_PINH
#define CHIP_PIN_H2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_H2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTH
#define CHIP_PIN_H2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_H2_TOGGLE_BIT_0_REG                                CHIP_REG_PINH

#define CHIP_PIN_H3                                                 true
#define CHIP_PIN_H3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_H3_MODE_BIT_0_REG                                  CHIP_REG_DDRH
#define CHIP_PIN_H3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_H3_MODE_BIT_1_REG                                  CHIP_REG_PORTH
#define CHIP_PIN_H3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_H3_INPUT_BIT_0_REG                                 CHIP_REG_PINH
#define CHIP_PIN_H3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_H3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTH
#define CHIP_PIN_H3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_H3_TOGGLE_BIT_0_REG                                CHIP_REG_PINH

#define CHIP_PIN_H4                                                 true
#define CHIP_PIN_H4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_H4_MODE_BIT_0_REG                                  CHIP_REG_DDRH
#define CHIP_PIN_H4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_H4_MODE_BIT_1_REG                                  CHIP_REG_PORTH
#define CHIP_PIN_H4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_H4_INPUT_BIT_0_REG                                 CHIP_REG_PINH
#define CHIP_PIN_H4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_H4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTH
#define CHIP_PIN_H4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_H4_TOGGLE_BIT_0_REG                                CHIP_REG_PINH

#define CHIP_PIN_H5                                                 true
#define CHIP_PIN_H5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_H5_MODE_BIT_0_REG                                  CHIP_REG_DDRH
#define CHIP_PIN_H5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_H5_MODE_BIT_1_REG                                  CHIP_REG_PORTH
#define CHIP_PIN_H5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_H5_INPUT_BIT_0_REG                                 CHIP_REG_PINH
#define CHIP_PIN_H5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_H5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTH
#define CHIP_PIN_H5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_H5_TOGGLE_BIT_0_REG                                CHIP_REG_PINH

#define CHIP_PIN_H6                                                 true
#define CHIP_PIN_H6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_H6_MODE_BIT_0_REG                                  CHIP_REG_DDRH
#define CHIP_PIN_H6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_H6_MODE_BIT_1_REG                                  CHIP_REG_PORTH
#define CHIP_PIN_H6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_H6_INPUT_BIT_0_REG                                 CHIP_REG_PINH
#define CHIP_PIN_H6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_H6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTH
#define CHIP_PIN_H6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_H6_TOGGLE_BIT_0_REG                                CHIP_REG_PINH

#define CHIP_PIN_H7                                                 true
#define CHIP_PIN_H7_MODE_BIT_0_BIT                                  7
#define CHIP_PIN_H7_MODE_BIT_0_REG                                  CHIP_REG_DDRH
#define CHIP_PIN_H7_MODE_BIT_1_BIT                                  7
#define CHIP_PIN_H7_MODE_BIT_1_REG                                  CHIP_REG_PORTH
#define CHIP_PIN_H7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_H7_INPUT_BIT_0_REG                                 CHIP_REG_PINH
#define CHIP_PIN_H7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_H7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTH
#define CHIP_PIN_H7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_H7_TOGGLE_BIT_0_REG                                CHIP_REG_PINH

#define CHIP_PIN_J0                                                 true
#define CHIP_PIN_J0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_J0_MODE_BIT_0_REG                                  CHIP_REG_DDRJ
#define CHIP_PIN_J0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_J0_MODE_BIT_1_REG                                  CHIP_REG_PORTJ
#define CHIP_PIN_J0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_J0_INPUT_BIT_0_REG                                 CHIP_REG_PINJ
#define CHIP_PIN_J0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_J0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTJ
#define CHIP_PIN_J0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_J0_TOGGLE_BIT_0_REG                                CHIP_REG_PINJ

#define CHIP_PIN_J1                                                 true
#define CHIP_PIN_J1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_J1_MODE_BIT_0_REG                                  CHIP_REG_DDRJ
#define CHIP_PIN_J1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_J1_MODE_BIT_1_REG                                  CHIP_REG_PORTJ
#define CHIP_PIN_J1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_J1_INPUT_BIT_0_REG                                 CHIP_REG_PINJ
#define CHIP_PIN_J1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_J1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTJ
#define CHIP_PIN_J1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_J1_TOGGLE_BIT_0_REG                                CHIP_REG_PINJ

#define CHIP_PIN_J2                                                 true
#define CHIP_PIN_J2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_J2_MODE_BIT_0_REG                                  CHIP_REG_DDRJ
#define CHIP_PIN_J2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_J2_MODE_BIT_1_REG                                  CHIP_REG_PORTJ
#define CHIP_PIN_J2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_J2_INPUT_BIT_0_REG                                 CHIP_REG_PINJ
#define CHIP_PIN_J2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_J2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTJ
#define CHIP_PIN_J2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_J2_TOGGLE_BIT_0_REG                                CHIP_REG_PINJ

#define CHIP_PIN_J3                                                 true
#define CHIP_PIN_J3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_J3_MODE_BIT_0_REG                                  CHIP_REG_DDRJ
#define CHIP_PIN_J3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_J3_MODE_BIT_1_REG                                  CHIP_REG_PORTJ
#define CHIP_PIN_J3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_J3_INPUT_BIT_0_REG                                 CHIP_REG_PINJ
#define CHIP_PIN_J3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_J3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTJ
#define CHIP_PIN_J3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_J3_TOGGLE_BIT_0_REG                                CHIP_REG_PINJ

#define CHIP_PIN_J4                                                 true
#define CHIP_PIN_J4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_J4_MODE_BIT_0_REG                                  CHIP_REG_DDRJ
#define CHIP_PIN_J4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_J4_MODE_BIT_1_REG                                  CHIP_REG_PORTJ
#define CHIP_PIN_J4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_J4_INPUT_BIT_0_REG                                 CHIP_REG_PINJ
#define CHIP_PIN_J4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_J4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTJ
#define CHIP_PIN_J4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_J4_TOGGLE_BIT_0_REG                                CHIP_REG_PINJ

#define CHIP_PIN_J5                                                 true
#define CHIP_PIN_J5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_J5_MODE_BIT_0_REG                                  CHIP_REG_DDRJ
#define CHIP_PIN_J5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_J5_MODE_BIT_1_REG                                  CHIP_REG_PORTJ
#define CHIP_PIN_J5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_J5_INPUT_BIT_0_REG                                 CHIP_REG_PINJ
#define CHIP_PIN_J5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_J5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTJ
#define CHIP_PIN_J5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_J5_TOGGLE_BIT_0_REG                                CHIP_REG_PINJ

#define CHIP_PIN_J6                                                 true
#define CHIP_PIN_J6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_J6_MODE_BIT_0_REG                                  CHIP_REG_DDRJ
#define CHIP_PIN_J6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_J6_MODE_BIT_1_REG                                  CHIP_REG_PORTJ
#define CHIP_PIN_J6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_J6_INPUT_BIT_0_REG                                 CHIP_REG_PINJ
#define CHIP_PIN_J6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_J6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTJ
#define CHIP_PIN_J6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_J6_TOGGLE_BIT_0_REG                                CHIP_REG_PINJ

#define CHIP_PIN_J7                                                 true
#define CHIP_PIN_J7_MODE_BIT_0_BIT                                  7
#define CHIP_PIN_J7_MODE_BIT_0_REG                                  CHIP_REG_DDRJ
#define CHIP_PIN_J7_MODE_BIT_1_BIT                                  7
#define CHIP_PIN_J7_MODE_BIT_1_REG                                  CHIP_REG_PORTJ
#define CHIP_PIN_J7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_J7_INPUT_BIT_0_REG                                 CHIP_REG_PINJ
#define CHIP_PIN_J7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_J7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTJ
#define CHIP_PIN_J7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_J7_TOGGLE_BIT_0_REG                                CHIP_REG_PINJ

#define CHIP_PIN_K0                                                 true
#define CHIP_PIN_K0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_K0_MODE_BIT_0_REG                                  CHIP_REG_DDRK
#define CHIP_PIN_K0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_K0_MODE_BIT_1_REG                                  CHIP_REG_PORTK
#define CHIP_PIN_K0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_K0_INPUT_BIT_0_REG                                 CHIP_REG_PINK
#define CHIP_PIN_K0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_K0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTK
#define CHIP_PIN_K0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_K0_TOGGLE_BIT_0_REG                                CHIP_REG_PINK

#define CHIP_PIN_K1                                                 true
#define CHIP_PIN_K1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_K1_MODE_BIT_0_REG                                  CHIP_REG_DDRK
#define CHIP_PIN_K1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_K1_MODE_BIT_1_REG                                  CHIP_REG_PORTK
#define CHIP_PIN_K1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_K1_INPUT_BIT_0_REG                                 CHIP_REG_PINK
#define CHIP_PIN_K1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_K1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTK
#define CHIP_PIN_K1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_K1_TOGGLE_BIT_0_REG                                CHIP_REG_PINK

#define CHIP_PIN_K2                                                 true
#define CHIP_PIN_K2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_K2_MODE_BIT_0_REG                                  CHIP_REG_DDRK
#define CHIP_PIN_K2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_K2_MODE_BIT_1_REG                                  CHIP_REG_PORTK
#define CHIP_PIN_K2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_K2_INPUT_BIT_0_REG                                 CHIP_REG_PINK
#define CHIP_PIN_K2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_K2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTK
#define CHIP_PIN_K2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_K2_TOGGLE_BIT_0_REG                                CHIP_REG_PINK

#define CHIP_PIN_K3                                                 true
#define CHIP_PIN_K3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_K3_MODE_BIT_0_REG                                  CHIP_REG_DDRK
#define CHIP_PIN_K3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_K3_MODE_BIT_1_REG                                  CHIP_REG_PORTK
#define CHIP_PIN_K3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_K3_INPUT_BIT_0_REG                                 CHIP_REG_PINK
#define CHIP_PIN_K3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_K3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTK
#define CHIP_PIN_K3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_K3_TOGGLE_BIT_0_REG                                CHIP_REG_PINK

#define CHIP_PIN_K4                                                 true
#define CHIP_PIN_K4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_K4_MODE_BIT_0_REG                                  CHIP_REG_DDRK
#define CHIP_PIN_K4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_K4_MODE_BIT_1_REG                                  CHIP_REG_PORTK
#define CHIP_PIN_K4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_K4_INPUT_BIT_0_REG                                 CHIP_REG_PINK
#define CHIP_PIN_K4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_K4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTK
#define CHIP_PIN_K4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_K4_TOGGLE_BIT_0_REG                                CHIP_REG_PINK

#define CHIP_PIN_K5                                                 true
#define CHIP_PIN_K5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_K5_MODE_BIT_0_REG                                  CHIP_REG_DDRK
#define CHIP_PIN_K5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_K5_MODE_BIT_1_REG                                  CHIP_REG_PORTK
#define CHIP_PIN_K5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_K5_INPUT_BIT_0_REG                                 CHIP_REG_PINK
#define CHIP_PIN_K5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_K5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTK
#define CHIP_PIN_K5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_K5_TOGGLE_BIT_0_REG                                CHIP_REG_PINK

#define CHIP_PIN_K6                                                 true
#define CHIP_PIN_K6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_K6_MODE_BIT_0_REG                                  CHIP_REG_DDRK
#define CHIP_PIN_K6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_K6_MODE_BIT_1_REG                                  CHIP_REG_PORTK
#define CHIP_PIN_K6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_K6_INPUT_BIT_0_REG                                 CHIP_REG_PINK
#define CHIP_PIN_K6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_K6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTK
#define CHIP_PIN_K6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_K6_TOGGLE_BIT_0_REG                                CHIP_REG_PINK

#define CHIP_PIN_K7                                                 true
#define CHIP_PIN_K7_MODE_BIT_0_BIT                                  7
#define CHIP_PIN_K7_MODE_BIT_0_REG                                  CHIP_REG_DDRK
#define CHIP_PIN_K7_MODE_BIT_1_BIT                                  7
#define CHIP_PIN_K7_MODE_BIT_1_REG                                  CHIP_REG_PORTK
#define CHIP_PIN_K7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_K7_INPUT_BIT_0_REG                                 CHIP_REG_PINK
#define CHIP_PIN_K7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_K7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTK
#define CHIP_PIN_K7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_K7_TOGGLE_BIT_0_REG                                CHIP_REG_PINK

#define CHIP_PIN_L0                                                 true
#define CHIP_PIN_L0_MODE_BIT_0_BIT                                  0
#define CHIP_PIN_L0_MODE_BIT_0_REG                                  CHIP_REG_DDRL
#define CHIP_PIN_L0_MODE_BIT_1_BIT                                  0
#define CHIP_PIN_L0_MODE_BIT_1_REG                                  CHIP_REG_PORTL
#define CHIP_PIN_L0_INPUT_BIT_0_BIT                                 0
#define CHIP_PIN_L0_INPUT_BIT_0_REG                                 CHIP_REG_PINL
#define CHIP_PIN_L0_OUTPUT_BIT_0_BIT                                0
#define CHIP_PIN_L0_OUTPUT_BIT_0_REG                                CHIP_REG_PORTL
#define CHIP_PIN_L0_TOGGLE_BIT_0_BIT                                0
#define CHIP_PIN_L0_TOGGLE_BIT_0_REG                                CHIP_REG_PINL

#define CHIP_PIN_L1                                                 true
#define CHIP_PIN_L1_MODE_BIT_0_BIT                                  1
#define CHIP_PIN_L1_MODE_BIT_0_REG                                  CHIP_REG_DDRL
#define CHIP_PIN_L1_MODE_BIT_1_BIT                                  1
#define CHIP_PIN_L1_MODE_BIT_1_REG                                  CHIP_REG_PORTL
#define CHIP_PIN_L1_INPUT_BIT_0_BIT                                 1
#define CHIP_PIN_L1_INPUT_BIT_0_REG                                 CHIP_REG_PINL
#define CHIP_PIN_L1_OUTPUT_BIT_0_BIT                                1
#define CHIP_PIN_L1_OUTPUT_BIT_0_REG                                CHIP_REG_PORTL
#define CHIP_PIN_L1_TOGGLE_BIT_0_BIT                                1
#define CHIP_PIN_L1_TOGGLE_BIT_0_REG                                CHIP_REG_PINL

#define CHIP_PIN_L2                                                 true
#define CHIP_PIN_L2_MODE_BIT_0_BIT                                  2
#define CHIP_PIN_L2_MODE_BIT_0_REG                                  CHIP_REG_DDRL
#define CHIP_PIN_L2_MODE_BIT_1_BIT                                  2
#define CHIP_PIN_L2_MODE_BIT_1_REG                                  CHIP_REG_PORTL
#define CHIP_PIN_L2_INPUT_BIT_0_BIT                                 2
#define CHIP_PIN_L2_INPUT_BIT_0_REG                                 CHIP_REG_PINL
#define CHIP_PIN_L2_OUTPUT_BIT_0_BIT                                2
#define CHIP_PIN_L2_OUTPUT_BIT_0_REG                                CHIP_REG_PORTL
#define CHIP_PIN_L2_TOGGLE_BIT_0_BIT                                2
#define CHIP_PIN_L2_TOGGLE_BIT_0_REG                                CHIP_REG_PINL

#define CHIP_PIN_L3                                                 true
#define CHIP_PIN_L3_MODE_BIT_0_BIT                                  3
#define CHIP_PIN_L3_MODE_BIT_0_REG                                  CHIP_REG_DDRL
#define CHIP_PIN_L3_MODE_BIT_1_BIT                                  3
#define CHIP_PIN_L3_MODE_BIT_1_REG                                  CHIP_REG_PORTL
#define CHIP_PIN_L3_INPUT_BIT_0_BIT                                 3
#define CHIP_PIN_L3_INPUT_BIT_0_REG                                 CHIP_REG_PINL
#define CHIP_PIN_L3_OUTPUT_BIT_0_BIT                                3
#define CHIP_PIN_L3_OUTPUT_BIT_0_REG                                CHIP_REG_PORTL
#define CHIP_PIN_L3_TOGGLE_BIT_0_BIT                                3
#define CHIP_PIN_L3_TOGGLE_BIT_0_REG                                CHIP_REG_PINL

#define CHIP_PIN_L4                                                 true
#define CHIP_PIN_L4_MODE_BIT_0_BIT                                  4
#define CHIP_PIN_L4_MODE_BIT_0_REG                                  CHIP_REG_DDRL
#define CHIP_PIN_L4_MODE_BIT_1_BIT                                  4
#define CHIP_PIN_L4_MODE_BIT_1_REG                                  CHIP_REG_PORTL
#define CHIP_PIN_L4_INPUT_BIT_0_BIT                                 4
#define CHIP_PIN_L4_INPUT_BIT_0_REG                                 CHIP_REG_PINL
#define CHIP_PIN_L4_OUTPUT_BIT_0_BIT                                4
#define CHIP_PIN_L4_OUTPUT_BIT_0_REG                                CHIP_REG_PORTL
#define CHIP_PIN_L4_TOGGLE_BIT_0_BIT                                4
#define CHIP_PIN_L4_TOGGLE_BIT_0_REG                                CHIP_REG_PINL

#define CHIP_PIN_L5                                                 true
#define CHIP_PIN_L5_MODE_BIT_0_BIT                                  5
#define CHIP_PIN_L5_MODE_BIT_0_REG                                  CHIP_REG_DDRL
#define CHIP_PIN_L5_MODE_BIT_1_BIT                                  5
#define CHIP_PIN_L5_MODE_BIT_1_REG                                  CHIP_REG_PORTL
#define CHIP_PIN_L5_INPUT_BIT_0_BIT                                 5
#define CHIP_PIN_L5_INPUT_BIT_0_REG                                 CHIP_REG_PINL
#define CHIP_PIN_L5_OUTPUT_BIT_0_BIT                                5
#define CHIP_PIN_L5_OUTPUT_BIT_0_REG                                CHIP_REG_PORTL
#define CHIP_PIN_L5_TOGGLE_BIT_0_BIT                                5
#define CHIP_PIN_L5_TOGGLE_BIT_0_REG                                CHIP_REG_PINL

#define CHIP_PIN_L6                                                 true
#define CHIP_PIN_L6_MODE_BIT_0_BIT                                  6
#define CHIP_PIN_L6_MODE_BIT_0_REG                                  CHIP_REG_DDRL
#define CHIP_PIN_L6_MODE_BIT_1_BIT                                  6
#define CHIP_PIN_L6_MODE_BIT_1_REG                                  CHIP_REG_PORTL
#define CHIP_PIN_L6_INPUT_BIT_0_BIT                                 6
#define CHIP_PIN_L6_INPUT_BIT_0_REG                                 CHIP_REG_PINL
#define CHIP_PIN_L6_OUTPUT_BIT_0_BIT                                6
#define CHIP_PIN_L6_OUTPUT_BIT_0_REG                                CHIP_REG_PORTL
#define CHIP_PIN_L6_TOGGLE_BIT_0_BIT                                6
#define CHIP_PIN_L6_TOGGLE_BIT_0_REG                                CHIP_REG_PINL

#define CHIP_PIN_L7                                                 true
#define CHIP_PIN_L7_MODE_BIT_0_BIT                                  7
#define CHIP_PIN_L7_MODE_BIT_0_REG                                  CHIP_REG_DDRL
#define CHIP_PIN_L7_MODE_BIT_1_BIT                                  7
#define CHIP_PIN_L7_MODE_BIT_1_REG                                  CHIP_REG_PORTL
#define CHIP_PIN_L7_INPUT_BIT_0_BIT                                 7
#define CHIP_PIN_L7_INPUT_BIT_0_REG                                 CHIP_REG_PINL
#define CHIP_PIN_L7_OUTPUT_BIT_0_BIT                                7
#define CHIP_PIN_L7_OUTPUT_BIT_0_REG                                CHIP_REG_PORTL
#define CHIP_PIN_L7_TOGGLE_BIT_0_BIT                                7
#define CHIP_PIN_L7_TOGGLE_BIT_0_REG                                CHIP_REG_PINL

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
// TODO Add other internal voltage reference.

#define CHIP_ADC_0_CHANNEL_BIT_0_REG                                CHIP_REG_ADMUX
#define CHIP_ADC_0_CHANNEL_BIT_1_REG                                CHIP_REG_ADMUX
#define CHIP_ADC_0_CHANNEL_BIT_2_REG                                CHIP_REG_ADMUX
#define CHIP_ADC_0_CHANNEL_BIT_3_REG                                CHIP_REG_ADMUX
// #define CHIP_ADC_0_CHANNEL_BIT_4_REG                                CHIP_REG_ADMUX
// #define CHIP_ADC_0_CHANNEL_BIT_5_REG                                CHIP_REG_ADCSRB
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
// #define CHIP_ADC_0_CHANNEL_VBG_ID                                   30
// #define CHIP_ADC_0_CHANNEL_GND_ID                                   31
// #define CHIP_ADC_0_CHANNEL_8_ID                                     32
// #define CHIP_ADC_0_CHANNEL_9_ID                                     33
// #define CHIP_ADC_0_CHANNEL_10_ID                                    34
// #define CHIP_ADC_0_CHANNEL_11_ID                                    35
// #define CHIP_ADC_0_CHANNEL_12_ID                                    36
// #define CHIP_ADC_0_CHANNEL_13_ID                                    37
// #define CHIP_ADC_0_CHANNEL_14_ID                                    38
// #define CHIP_ADC_0_CHANNEL_15_ID                                    39
// TODO Add extra channel select bits.
// TODO Add differential and gain channels.

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
// External Interrupts

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

#define CHIP_EXINT_2                                                true
#define CHIP_EXINT_2_ENABLE_BIT_0_REG                               CHIP_REG_EIMSK
#define CHIP_EXINT_2_ENABLE_BIT_0_BIT                               2
#define CHIP_EXINT_2_INT_FLAG_BIT_0_REG                             CHIP_REG_EIFR
#define CHIP_EXINT_2_INT_FLAG_BIT_0_BIT                             2
#define CHIP_EXINT_2_TRIGGER_BIT_0_REG                              CHIP_REG_EICRA
#define CHIP_EXINT_2_TRIGGER_BIT_1_REG                              CHIP_REG_EICRA
#define CHIP_EXINT_2_TRIGGER_BIT_0_BIT                              4
#define CHIP_EXINT_2_TRIGGER_BIT_1_BIT                              5
#define CHIP_EXINT_2_TRIGGER_LOW_ID                                 0
#define CHIP_EXINT_2_TRIGGER_CHANGE_ID                              1
#define CHIP_EXINT_2_TRIGGER_FALLING_ID                             2
#define CHIP_EXINT_2_TRIGGER_RISING_ID                              3
#define CHIP_EXINT_2_INT_VECTOR                                     VECT(CHIP_VECT_INT2)

#define CHIP_EXINT_3                                                true
#define CHIP_EXINT_3_ENABLE_BIT_0_REG                               CHIP_REG_EIMSK
#define CHIP_EXINT_3_ENABLE_BIT_0_BIT                               3
#define CHIP_EXINT_3_INT_FLAG_BIT_0_REG                             CHIP_REG_EIFR
#define CHIP_EXINT_3_INT_FLAG_BIT_0_BIT                             3
#define CHIP_EXINT_3_TRIGGER_BIT_0_REG                              CHIP_REG_EICRA
#define CHIP_EXINT_3_TRIGGER_BIT_1_REG                              CHIP_REG_EICRA
#define CHIP_EXINT_3_TRIGGER_BIT_0_BIT                              6
#define CHIP_EXINT_3_TRIGGER_BIT_1_BIT                              7
#define CHIP_EXINT_3_TRIGGER_LOW_ID                                 0
#define CHIP_EXINT_3_TRIGGER_CHANGE_ID                              1
#define CHIP_EXINT_3_TRIGGER_FALLING_ID                             2
#define CHIP_EXINT_3_TRIGGER_RISING_ID                              3
#define CHIP_EXINT_3_INT_VECTOR                                     VECT(CHIP_VECT_INT3)

#define CHIP_EXINT_4                                                true
#define CHIP_EXINT_4_ENABLE_BIT_0_REG                               CHIP_REG_EIMSK
#define CHIP_EXINT_4_ENABLE_BIT_0_BIT                               4
#define CHIP_EXINT_4_INT_FLAG_BIT_0_REG                             CHIP_REG_EIFR
#define CHIP_EXINT_4_INT_FLAG_BIT_0_BIT                             4
#define CHIP_EXINT_4_TRIGGER_BIT_0_REG                              CHIP_REG_EICRB
#define CHIP_EXINT_4_TRIGGER_BIT_1_REG                              CHIP_REG_EICRB
#define CHIP_EXINT_4_TRIGGER_BIT_0_BIT                              0
#define CHIP_EXINT_4_TRIGGER_BIT_1_BIT                              1
#define CHIP_EXINT_4_TRIGGER_LOW_ID                                 0
#define CHIP_EXINT_4_TRIGGER_CHANGE_ID                              1
#define CHIP_EXINT_4_TRIGGER_FALLING_ID                             2
#define CHIP_EXINT_4_TRIGGER_RISING_ID                              3
#define CHIP_EXINT_4_INT_VECTOR                                     VECT(CHIP_VECT_INT4)

#define CHIP_EXINT_5                                                true
#define CHIP_EXINT_5_ENABLE_BIT_0_REG                               CHIP_REG_EIMSK
#define CHIP_EXINT_5_ENABLE_BIT_0_BIT                               5
#define CHIP_EXINT_5_INT_FLAG_BIT_0_REG                             CHIP_REG_EIFR
#define CHIP_EXINT_5_INT_FLAG_BIT_0_BIT                             5
#define CHIP_EXINT_5_TRIGGER_BIT_0_REG                              CHIP_REG_EICRB
#define CHIP_EXINT_5_TRIGGER_BIT_1_REG                              CHIP_REG_EICRB
#define CHIP_EXINT_5_TRIGGER_BIT_0_BIT                              2
#define CHIP_EXINT_5_TRIGGER_BIT_1_BIT                              3
#define CHIP_EXINT_5_TRIGGER_LOW_ID                                 0
#define CHIP_EXINT_5_TRIGGER_CHANGE_ID                              1
#define CHIP_EXINT_5_TRIGGER_FALLING_ID                             2
#define CHIP_EXINT_5_TRIGGER_RISING_ID                              3
#define CHIP_EXINT_5_INT_VECTOR                                     VECT(CHIP_VECT_INT5)

#define CHIP_EXINT_6                                                true
#define CHIP_EXINT_6_ENABLE_BIT_0_REG                               CHIP_REG_EIMSK
#define CHIP_EXINT_6_ENABLE_BIT_0_BIT                               6
#define CHIP_EXINT_6_INT_FLAG_BIT_0_REG                             CHIP_REG_EIFR
#define CHIP_EXINT_6_INT_FLAG_BIT_0_BIT                             6
#define CHIP_EXINT_6_TRIGGER_BIT_0_REG                              CHIP_REG_EICRB
#define CHIP_EXINT_6_TRIGGER_BIT_1_REG                              CHIP_REG_EICRB
#define CHIP_EXINT_6_TRIGGER_BIT_0_BIT                              4
#define CHIP_EXINT_6_TRIGGER_BIT_1_BIT                              5
#define CHIP_EXINT_6_TRIGGER_LOW_ID                                 0
#define CHIP_EXINT_6_TRIGGER_CHANGE_ID                              1
#define CHIP_EXINT_6_TRIGGER_FALLING_ID                             2
#define CHIP_EXINT_6_TRIGGER_RISING_ID                              3
#define CHIP_EXINT_6_INT_VECTOR                                     VECT(CHIP_VECT_INT6)

#define CHIP_EXINT_7                                                true
#define CHIP_EXINT_7_ENABLE_BIT_0_REG                               CHIP_REG_EIMSK
#define CHIP_EXINT_7_ENABLE_BIT_0_BIT                               7
#define CHIP_EXINT_7_INT_FLAG_BIT_0_REG                             CHIP_REG_EIFR
#define CHIP_EXINT_7_INT_FLAG_BIT_0_BIT                             7
#define CHIP_EXINT_7_TRIGGER_BIT_0_REG                              CHIP_REG_EICRB
#define CHIP_EXINT_7_TRIGGER_BIT_1_REG                              CHIP_REG_EICRB
#define CHIP_EXINT_7_TRIGGER_BIT_0_BIT                              6
#define CHIP_EXINT_7_TRIGGER_BIT_1_BIT                              7
#define CHIP_EXINT_7_TRIGGER_LOW_ID                                 0
#define CHIP_EXINT_7_TRIGGER_CHANGE_ID                              1
#define CHIP_EXINT_7_TRIGGER_FALLING_ID                             2
#define CHIP_EXINT_7_TRIGGER_RISING_ID                              3
#define CHIP_EXINT_7_INT_VECTOR                                     VECT(CHIP_VECT_INT7)

//------------------------------------------------
// Pin Change Interrupts

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
// Timer Counters

#define CHIP_TIMER_COUNT                                            6

//------------------------------------------------
// Timer Counter 0

#define CHIP_TIMER_0                                                true

#define CHIP_TIMER_0_TYPE                                           uint8_t

#define CHIP_TIMER_0_WAVEFORM                                       true
#define CHIP_TIMER_0_WAVEFORM_NORMAL_ID                             0
#define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_ID                  1
#define CHIP_TIMER_0_WAVEFORM_CTC_OCRA_ID                           2
#define CHIP_TIMER_0_WAVEFORM_FAST_PWM_ID                           3
#define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             5
#define CHIP_TIMER_0_WAVEFORM_FAST_PWM_OCRA_ID                      7
#define CHIP_TIMER_0_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR0A
#define CHIP_TIMER_0_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR0A
#define CHIP_TIMER_0_WAVEFORM_BIT_2_REG                             CHIP_REG_TCCR0B
#define CHIP_TIMER_0_WAVEFORM_BIT_0_BIT                             0
#define CHIP_TIMER_0_WAVEFORM_BIT_1_BIT                             1
#define CHIP_TIMER_0_WAVEFORM_BIT_2_BIT                             3

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
#define CHIP_TIMER_0_OUTPUT_A_PIN                                   PortB::Pin7
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
#define CHIP_TIMER_0_OUTPUT_B_PIN                                   PortG::Pin5
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
// Timer Counter 1

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
#define CHIP_TIMER_1_WAVEFORM_CTC_ID                                12
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

#define CHIP_TIMER_1_COUNTER_REG                                    CHIP_REG_TCNT1

#define CHIP_TIMER_1_OUTPUT_A                                       true
#define CHIP_TIMER_1_OUTPUT_A_PIN                                   PortB::Pin5
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
#define CHIP_TIMER_1_OUTPUT_B_PIN                                   PortB::Pin6
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

#define CHIP_TIMER_1_OUTPUT_C                                       true
#define CHIP_TIMER_1_OUTPUT_C_PIN                                   PortB::Pin7
#define CHIP_TIMER_1_OUTPUT_C_MODE_BIT_0_REG                        CHIP_REG_TCCR1A
#define CHIP_TIMER_1_OUTPUT_C_MODE_BIT_1_REG                        CHIP_REG_TCCR1A
#define CHIP_TIMER_1_OUTPUT_C_MODE_BIT_0_BIT                        2
#define CHIP_TIMER_1_OUTPUT_C_MODE_BIT_1_BIT                        3
#define CHIP_TIMER_1_OUTPUT_C_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_1_OUTPUT_C_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_1_OUTPUT_C_MODE_CLEAR_ID                         2
#define CHIP_TIMER_1_OUTPUT_C_MODE_SET_ID                           3
#define CHIP_TIMER_1_OUTPUT_C_REG                                   CHIP_REG_OCR1C
#define CHIP_TIMER_1_OUTPUT_C_INT_ENABLE_REG                        CHIP_REG_TIMSK1
#define CHIP_TIMER_1_OUTPUT_C_INT_ENABLE_BIT                        3
#define CHIP_TIMER_1_OUTPUT_C_INT_FLAG_REG                          CHIP_REG_TIFR1
#define CHIP_TIMER_1_OUTPUT_C_INT_FLAG_BIT                          3
#define CHIP_TIMER_1_OUTPUT_C_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_COMPC)

#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK1
#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR1
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_BIT                          0
#define CHIP_TIMER_1_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER1_OVF)

//------------------------------------------------
// Timer Counter 2

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

#define CHIP_TIMER_2_OUTPUT_A                                       true
#define CHIP_TIMER_2_OUTPUT_A_PIN                                   PortB::Pin4
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
#define CHIP_TIMER_2_OUTPUT_B_PIN                                   PortH::Pin6
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

// TODO Add input capture definitions.

//------------------------------------------------
// Timer Counter 3

#define CHIP_TIMER_3                                                true

#define CHIP_TIMER_3_TYPE                                           uint16_t

#define CHIP_TIMER_3_WAVEFORM                                       true
#define CHIP_TIMER_3_WAVEFORM_NORMAL_ID                             0
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_CORRECT_8_ID                1
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_CORRECT_9_ID                2
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_CORRECT_10_ID               3
#define CHIP_TIMER_3_WAVEFORM_CTC_OCRA_ID                           4
#define CHIP_TIMER_3_WAVEFORM_FAST_PWM_8_ID                         5
#define CHIP_TIMER_3_WAVEFORM_FAST_PWM_9_ID                         6
#define CHIP_TIMER_3_WAVEFORM_FAST_PWM_10_ID                        7
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID             8
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID        9
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_CORRECT_ID                  10
#define CHIP_TIMER_3_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             11
#define CHIP_TIMER_3_WAVEFORM_CTC_ID                                12
#define CHIP_TIMER_3_WAVEFORM_FAST_PWM_ID                           14
#define CHIP_TIMER_3_WAVEFORM_FAST_PWM_OCRA_ID                      15
#define CHIP_TIMER_3_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR3A
#define CHIP_TIMER_3_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR3A
#define CHIP_TIMER_3_WAVEFORM_BIT_2_REG                             CHIP_REG_TCCR3B
#define CHIP_TIMER_3_WAVEFORM_BIT_3_REG                             CHIP_REG_TCCR3B
#define CHIP_TIMER_3_WAVEFORM_BIT_0_BIT                             0
#define CHIP_TIMER_3_WAVEFORM_BIT_1_BIT                             1
#define CHIP_TIMER_3_WAVEFORM_BIT_2_BIT                             3
#define CHIP_TIMER_3_WAVEFORM_BIT_3_BIT                             4

#define CHIP_TIMER_3_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_3_CLOCK_1_ID                                     1
#define CHIP_TIMER_3_CLOCK_8_ID                                     2
#define CHIP_TIMER_3_CLOCK_64_ID                                    3
#define CHIP_TIMER_3_CLOCK_256_ID                                   4
#define CHIP_TIMER_3_CLOCK_1024_ID                                  5
#define CHIP_TIMER_3_CLOCK_EXT_FALLING_ID                           6
#define CHIP_TIMER_3_CLOCK_EXT_RISING_ID                            7
#define CHIP_TIMER_3_CLOCK_BIT_0_REG                                CHIP_REG_TCCR3B
#define CHIP_TIMER_3_CLOCK_BIT_1_REG                                CHIP_REG_TCCR3B
#define CHIP_TIMER_3_CLOCK_BIT_2_REG                                CHIP_REG_TCCR3B
#define CHIP_TIMER_3_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_3_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_3_CLOCK_BIT_2_BIT                                2

#define CHIP_TIMER_3_COUNTER_REG                                    CHIP_REG_TCNT3

#define CHIP_TIMER_3_OUTPUT_A                                       true
#define CHIP_TIMER_3_OUTPUT_A_PIN                                   PortE::Pin3
#define CHIP_TIMER_3_OUTPUT_A_MODE_BIT_0_REG                        CHIP_REG_TCCR3A
#define CHIP_TIMER_3_OUTPUT_A_MODE_BIT_1_REG                        CHIP_REG_TCCR3A
#define CHIP_TIMER_3_OUTPUT_A_MODE_BIT_0_BIT                        6
#define CHIP_TIMER_3_OUTPUT_A_MODE_BIT_1_BIT                        7
#define CHIP_TIMER_3_OUTPUT_A_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_3_OUTPUT_A_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_3_OUTPUT_A_MODE_CLEAR_ID                         2
#define CHIP_TIMER_3_OUTPUT_A_MODE_SET_ID                           3
#define CHIP_TIMER_3_OUTPUT_A_REG                                   CHIP_REG_OCR3A
#define CHIP_TIMER_3_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK3
#define CHIP_TIMER_3_OUTPUT_A_INT_ENABLE_BIT                        1
#define CHIP_TIMER_3_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR3
#define CHIP_TIMER_3_OUTPUT_A_INT_FLAG_BIT                          1
#define CHIP_TIMER_3_OUTPUT_A_INT_VECTOR                            VECT(CHIP_VECT_TIMER3_COMPA)

#define CHIP_TIMER_3_OUTPUT_B                                       true
#define CHIP_TIMER_3_OUTPUT_B_PIN                                   PortE::Pin4
#define CHIP_TIMER_3_OUTPUT_B_MODE_BIT_0_REG                        CHIP_REG_TCCR3A
#define CHIP_TIMER_3_OUTPUT_B_MODE_BIT_1_REG                        CHIP_REG_TCCR3A
#define CHIP_TIMER_3_OUTPUT_B_MODE_BIT_0_BIT                        4
#define CHIP_TIMER_3_OUTPUT_B_MODE_BIT_1_BIT                        5
#define CHIP_TIMER_3_OUTPUT_B_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_3_OUTPUT_B_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_3_OUTPUT_B_MODE_CLEAR_ID                         2
#define CHIP_TIMER_3_OUTPUT_B_MODE_SET_ID                           3
#define CHIP_TIMER_3_OUTPUT_B_REG                                   CHIP_REG_OCR3B
#define CHIP_TIMER_3_OUTPUT_B_INT_ENABLE_REG                        CHIP_REG_TIMSK3
#define CHIP_TIMER_3_OUTPUT_B_INT_ENABLE_BIT                        2
#define CHIP_TIMER_3_OUTPUT_B_INT_FLAG_REG                          CHIP_REG_TIFR3
#define CHIP_TIMER_3_OUTPUT_B_INT_FLAG_BIT                          2
#define CHIP_TIMER_3_OUTPUT_B_INT_VECTOR                            VECT(CHIP_VECT_TIMER3_COMPB)

#define CHIP_TIMER_3_OUTPUT_C                                       true
#define CHIP_TIMER_3_OUTPUT_C_PIN                                   PortE::Pin5
#define CHIP_TIMER_3_OUTPUT_C_MODE_BIT_0_REG                        CHIP_REG_TCCR3A
#define CHIP_TIMER_3_OUTPUT_C_MODE_BIT_1_REG                        CHIP_REG_TCCR3A
#define CHIP_TIMER_3_OUTPUT_C_MODE_BIT_0_BIT                        2
#define CHIP_TIMER_3_OUTPUT_C_MODE_BIT_1_BIT                        3
#define CHIP_TIMER_3_OUTPUT_C_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_3_OUTPUT_C_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_3_OUTPUT_C_MODE_CLEAR_ID                         2
#define CHIP_TIMER_3_OUTPUT_C_MODE_SET_ID                           3
#define CHIP_TIMER_3_OUTPUT_C_REG                                   CHIP_REG_OCR3C
#define CHIP_TIMER_3_OUTPUT_C_INT_ENABLE_REG                        CHIP_REG_TIMSK3
#define CHIP_TIMER_3_OUTPUT_C_INT_ENABLE_BIT                        3
#define CHIP_TIMER_3_OUTPUT_C_INT_FLAG_REG                          CHIP_REG_TIFR3
#define CHIP_TIMER_3_OUTPUT_C_INT_FLAG_BIT                          3
#define CHIP_TIMER_3_OUTPUT_C_INT_VECTOR                            VECT(CHIP_VECT_TIMER3_COMPC)

#define CHIP_TIMER_3_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK3
#define CHIP_TIMER_3_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_3_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR3
#define CHIP_TIMER_3_OVERFLOW_INT_FLAG_BIT                          0
#define CHIP_TIMER_3_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER3_OVF)

//------------------------------------------------
// Timer Counter 4

#define CHIP_TIMER_4                                                true

#define CHIP_TIMER_4_TYPE                                           uint16_t

#define CHIP_TIMER_4_WAVEFORM                                       true
#define CHIP_TIMER_4_WAVEFORM_NORMAL_ID                             0
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_CORRECT_8_ID                1
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_CORRECT_9_ID                2
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_CORRECT_10_ID               3
#define CHIP_TIMER_4_WAVEFORM_CTC_OCRA_ID                           4
#define CHIP_TIMER_4_WAVEFORM_FAST_PWM_8_ID                         5
#define CHIP_TIMER_4_WAVEFORM_FAST_PWM_9_ID                         6
#define CHIP_TIMER_4_WAVEFORM_FAST_PWM_10_ID                        7
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID             8
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID        9
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_CORRECT_ID                  10
#define CHIP_TIMER_4_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             11
#define CHIP_TIMER_4_WAVEFORM_CTC_ID                                12
#define CHIP_TIMER_4_WAVEFORM_FAST_PWM_ID                           14
#define CHIP_TIMER_4_WAVEFORM_FAST_PWM_OCRA_ID                      15
#define CHIP_TIMER_4_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR4A
#define CHIP_TIMER_4_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR4A
#define CHIP_TIMER_4_WAVEFORM_BIT_2_REG                             CHIP_REG_TCCR4B
#define CHIP_TIMER_4_WAVEFORM_BIT_3_REG                             CHIP_REG_TCCR4B
#define CHIP_TIMER_4_WAVEFORM_BIT_0_BIT                             0
#define CHIP_TIMER_4_WAVEFORM_BIT_1_BIT                             1
#define CHIP_TIMER_4_WAVEFORM_BIT_2_BIT                             3
#define CHIP_TIMER_4_WAVEFORM_BIT_3_BIT                             4

#define CHIP_TIMER_4_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_4_CLOCK_1_ID                                     1
#define CHIP_TIMER_4_CLOCK_8_ID                                     2
#define CHIP_TIMER_4_CLOCK_64_ID                                    3
#define CHIP_TIMER_4_CLOCK_256_ID                                   4
#define CHIP_TIMER_4_CLOCK_1024_ID                                  5
#define CHIP_TIMER_4_CLOCK_EXT_FALLING_ID                           6
#define CHIP_TIMER_4_CLOCK_EXT_RISING_ID                            7
#define CHIP_TIMER_4_CLOCK_BIT_0_REG                                CHIP_REG_TCCR4B
#define CHIP_TIMER_4_CLOCK_BIT_1_REG                                CHIP_REG_TCCR4B
#define CHIP_TIMER_4_CLOCK_BIT_2_REG                                CHIP_REG_TCCR4B
#define CHIP_TIMER_4_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_4_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_4_CLOCK_BIT_2_BIT                                2

#define CHIP_TIMER_4_COUNTER_REG                                    CHIP_REG_TCNT4

#define CHIP_TIMER_4_OUTPUT_A                                       true
#define CHIP_TIMER_4_OUTPUT_A_PIN                                   PortH::Pin3
#define CHIP_TIMER_4_OUTPUT_A_MODE_BIT_0_REG                        CHIP_REG_TCCR4A
#define CHIP_TIMER_4_OUTPUT_A_MODE_BIT_1_REG                        CHIP_REG_TCCR4A
#define CHIP_TIMER_4_OUTPUT_A_MODE_BIT_0_BIT                        6
#define CHIP_TIMER_4_OUTPUT_A_MODE_BIT_1_BIT                        7
#define CHIP_TIMER_4_OUTPUT_A_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_4_OUTPUT_A_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_4_OUTPUT_A_MODE_CLEAR_ID                         2
#define CHIP_TIMER_4_OUTPUT_A_MODE_SET_ID                           3
#define CHIP_TIMER_4_OUTPUT_A_REG                                   CHIP_REG_OCR4A
#define CHIP_TIMER_4_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK4
#define CHIP_TIMER_4_OUTPUT_A_INT_ENABLE_BIT                        1
#define CHIP_TIMER_4_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR4
#define CHIP_TIMER_4_OUTPUT_A_INT_FLAG_BIT                          1
#define CHIP_TIMER_4_OUTPUT_A_INT_VECTOR                            VECT(CHIP_VECT_TIMER4_COMPA)

#define CHIP_TIMER_4_OUTPUT_B                                       true
#define CHIP_TIMER_4_OUTPUT_B_PIN                                   PortH::Pin4
#define CHIP_TIMER_4_OUTPUT_B_MODE_BIT_0_REG                        CHIP_REG_TCCR4A
#define CHIP_TIMER_4_OUTPUT_B_MODE_BIT_1_REG                        CHIP_REG_TCCR4A
#define CHIP_TIMER_4_OUTPUT_B_MODE_BIT_0_BIT                        4
#define CHIP_TIMER_4_OUTPUT_B_MODE_BIT_1_BIT                        5
#define CHIP_TIMER_4_OUTPUT_B_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_4_OUTPUT_B_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_4_OUTPUT_B_MODE_CLEAR_ID                         2
#define CHIP_TIMER_4_OUTPUT_B_MODE_SET_ID                           3
#define CHIP_TIMER_4_OUTPUT_B_REG                                   CHIP_REG_OCR4B
#define CHIP_TIMER_4_OUTPUT_B_INT_ENABLE_REG                        CHIP_REG_TIMSK4
#define CHIP_TIMER_4_OUTPUT_B_INT_ENABLE_BIT                        2
#define CHIP_TIMER_4_OUTPUT_B_INT_FLAG_REG                          CHIP_REG_TIFR4
#define CHIP_TIMER_4_OUTPUT_B_INT_FLAG_BIT                          2
#define CHIP_TIMER_4_OUTPUT_B_INT_VECTOR                            VECT(CHIP_VECT_TIMER4_COMPB)

#define CHIP_TIMER_4_OUTPUT_C                                       true
#define CHIP_TIMER_4_OUTPUT_C_PIN                                   PortH::Pin5
#define CHIP_TIMER_4_OUTPUT_C_MODE_BIT_0_REG                        CHIP_REG_TCCR4A
#define CHIP_TIMER_4_OUTPUT_C_MODE_BIT_1_REG                        CHIP_REG_TCCR4A
#define CHIP_TIMER_4_OUTPUT_C_MODE_BIT_0_BIT                        2
#define CHIP_TIMER_4_OUTPUT_C_MODE_BIT_1_BIT                        3
#define CHIP_TIMER_4_OUTPUT_C_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_4_OUTPUT_C_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_4_OUTPUT_C_MODE_CLEAR_ID                         2
#define CHIP_TIMER_4_OUTPUT_C_MODE_SET_ID                           3
#define CHIP_TIMER_4_OUTPUT_C_REG                                   CHIP_REG_OCR4C
#define CHIP_TIMER_4_OUTPUT_C_INT_ENABLE_REG                        CHIP_REG_TIMSK4
#define CHIP_TIMER_4_OUTPUT_C_INT_ENABLE_BIT                        3
#define CHIP_TIMER_4_OUTPUT_C_INT_FLAG_REG                          CHIP_REG_TIFR4
#define CHIP_TIMER_4_OUTPUT_C_INT_FLAG_BIT                          3
#define CHIP_TIMER_4_OUTPUT_C_INT_VECTOR                            VECT(CHIP_VECT_TIMER4_COMPC)

#define CHIP_TIMER_4_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK4
#define CHIP_TIMER_4_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_4_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR4
#define CHIP_TIMER_4_OVERFLOW_INT_FLAG_BIT                          0
#define CHIP_TIMER_4_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER4_OVF)

//------------------------------------------------
// Timer Counter 5

#define CHIP_TIMER_5                                                true

#define CHIP_TIMER_5_WAVEFORM                                       true
#define CHIP_TIMER_5_WAVEFORM_NORMAL_ID                             0
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_CORRECT_8_ID                1
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_CORRECT_9_ID                2
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_CORRECT_10_ID               3
#define CHIP_TIMER_5_WAVEFORM_CTC_OCRA_ID                           4
#define CHIP_TIMER_5_WAVEFORM_FAST_PWM_8_ID                         5
#define CHIP_TIMER_5_WAVEFORM_FAST_PWM_9_ID                         6
#define CHIP_TIMER_5_WAVEFORM_FAST_PWM_10_ID                        7
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID             8
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID        9
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_CORRECT_ID                  10
#define CHIP_TIMER_5_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID             11
#define CHIP_TIMER_5_WAVEFORM_CTC_ID                                12
#define CHIP_TIMER_5_WAVEFORM_FAST_PWM_ID                           14
#define CHIP_TIMER_5_WAVEFORM_FAST_PWM_OCRA_ID                      15
#define CHIP_TIMER_5_WAVEFORM_BIT_0_REG                             CHIP_REG_TCCR5A
#define CHIP_TIMER_5_WAVEFORM_BIT_1_REG                             CHIP_REG_TCCR5A
#define CHIP_TIMER_5_WAVEFORM_BIT_2_REG                             CHIP_REG_TCCR5B
#define CHIP_TIMER_5_WAVEFORM_BIT_3_REG                             CHIP_REG_TCCR5B
#define CHIP_TIMER_5_WAVEFORM_BIT_0_BIT                             0
#define CHIP_TIMER_5_WAVEFORM_BIT_1_BIT                             1
#define CHIP_TIMER_5_WAVEFORM_BIT_2_BIT                             3
#define CHIP_TIMER_5_WAVEFORM_BIT_3_BIT                             4

#define CHIP_TIMER_5_CLOCK_NONE_ID                                  0
#define CHIP_TIMER_5_CLOCK_1_ID                                     1
#define CHIP_TIMER_5_CLOCK_8_ID                                     2
#define CHIP_TIMER_5_CLOCK_64_ID                                    3
#define CHIP_TIMER_5_CLOCK_256_ID                                   4
#define CHIP_TIMER_5_CLOCK_1024_ID                                  5
#define CHIP_TIMER_5_CLOCK_EXT_FALLING_ID                           6
#define CHIP_TIMER_5_CLOCK_EXT_RISING_ID                            7
#define CHIP_TIMER_5_CLOCK_BIT_0_REG                                CHIP_REG_TCCR5B
#define CHIP_TIMER_5_CLOCK_BIT_1_REG                                CHIP_REG_TCCR5B
#define CHIP_TIMER_5_CLOCK_BIT_2_REG                                CHIP_REG_TCCR5B
#define CHIP_TIMER_5_CLOCK_BIT_0_BIT                                0
#define CHIP_TIMER_5_CLOCK_BIT_1_BIT                                1
#define CHIP_TIMER_5_CLOCK_BIT_2_BIT                                2

#define CHIP_TIMER_5_COUNTER_REG                                    CHIP_REG_TCNT5

#define CHIP_TIMER_5_OUTPUT_A                                       true
#define CHIP_TIMER_5_OUTPUT_A_PIN                                   PortL::Pin3
#define CHIP_TIMER_5_OUTPUT_A_MODE_BIT_0_REG                        CHIP_REG_TCCR5A
#define CHIP_TIMER_5_OUTPUT_A_MODE_BIT_1_REG                        CHIP_REG_TCCR5A
#define CHIP_TIMER_5_OUTPUT_A_MODE_BIT_0_BIT                        6
#define CHIP_TIMER_5_OUTPUT_A_MODE_BIT_1_BIT                        7
#define CHIP_TIMER_5_OUTPUT_A_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_5_OUTPUT_A_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_5_OUTPUT_A_MODE_CLEAR_ID                         2
#define CHIP_TIMER_5_OUTPUT_A_MODE_SET_ID                           3
#define CHIP_TIMER_5_OUTPUT_A_REG                                   CHIP_REG_OCR5A
#define CHIP_TIMER_5_OUTPUT_A_INT_ENABLE_REG                        CHIP_REG_TIMSK5
#define CHIP_TIMER_5_OUTPUT_A_INT_ENABLE_BIT                        1
#define CHIP_TIMER_5_OUTPUT_A_INT_FLAG_REG                          CHIP_REG_TIFR5
#define CHIP_TIMER_5_OUTPUT_A_INT_FLAG_BIT                          1
#define CHIP_TIMER_5_OUTPUT_A_INT_VECTOR                            VECT(CHIP_VECT_TIMER5_COMPA)

#define CHIP_TIMER_5_OUTPUT_B                                       true
#define CHIP_TIMER_5_OUTPUT_B_PIN                                   PortL::Pin4
#define CHIP_TIMER_5_OUTPUT_B_MODE_BIT_0_REG                        CHIP_REG_TCCR5A
#define CHIP_TIMER_5_OUTPUT_B_MODE_BIT_1_REG                        CHIP_REG_TCCR5A
#define CHIP_TIMER_5_OUTPUT_B_MODE_BIT_0_BIT                        4
#define CHIP_TIMER_5_OUTPUT_B_MODE_BIT_1_BIT                        5
#define CHIP_TIMER_5_OUTPUT_B_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_5_OUTPUT_B_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_5_OUTPUT_B_MODE_CLEAR_ID                         2
#define CHIP_TIMER_5_OUTPUT_B_MODE_SET_ID                           3
#define CHIP_TIMER_5_OUTPUT_B_REG                                   CHIP_REG_OCR5B
#define CHIP_TIMER_5_OUTPUT_B_INT_ENABLE_REG                        CHIP_REG_TIMSK5
#define CHIP_TIMER_5_OUTPUT_B_INT_ENABLE_BIT                        2
#define CHIP_TIMER_5_OUTPUT_B_INT_FLAG_REG                          CHIP_REG_TIFR5
#define CHIP_TIMER_5_OUTPUT_B_INT_FLAG_BIT                          2
#define CHIP_TIMER_5_OUTPUT_B_INT_VECTOR                            VECT(CHIP_VECT_TIMER5_COMPB)

#define CHIP_TIMER_5_OUTPUT_C                                       true
#define CHIP_TIMER_5_OUTPUT_C_PIN                                   PortL::Pin5
#define CHIP_TIMER_5_OUTPUT_C_MODE_BIT_0_REG                        CHIP_REG_TCCR5A
#define CHIP_TIMER_5_OUTPUT_C_MODE_BIT_1_REG                        CHIP_REG_TCCR5A
#define CHIP_TIMER_5_OUTPUT_C_MODE_BIT_0_BIT                        2
#define CHIP_TIMER_5_OUTPUT_C_MODE_BIT_1_BIT                        3
#define CHIP_TIMER_5_OUTPUT_C_MODE_DISCONNECTED_ID                  0
#define CHIP_TIMER_5_OUTPUT_C_MODE_TOGGLE_ID                        1
#define CHIP_TIMER_5_OUTPUT_C_MODE_CLEAR_ID                         2
#define CHIP_TIMER_5_OUTPUT_C_MODE_SET_ID                           3
#define CHIP_TIMER_5_OUTPUT_C_REG                                   CHIP_REG_OCR5C
#define CHIP_TIMER_5_OUTPUT_C_INT_ENABLE_REG                        CHIP_REG_TIMSK5
#define CHIP_TIMER_5_OUTPUT_C_INT_ENABLE_BIT                        3
#define CHIP_TIMER_5_OUTPUT_C_INT_FLAG_REG                          CHIP_REG_TIFR5
#define CHIP_TIMER_5_OUTPUT_C_INT_FLAG_BIT                          3
#define CHIP_TIMER_5_OUTPUT_C_INT_VECTOR                            VECT(CHIP_VECT_TIMER5_COMPC)

#define CHIP_TIMER_5_OVERFLOW_INT_ENABLE_REG                        CHIP_REG_TIMSK5
#define CHIP_TIMER_5_OVERFLOW_INT_ENABLE_BIT                        0
#define CHIP_TIMER_5_OVERFLOW_INT_FLAG_REG                          CHIP_REG_TIFR5
#define CHIP_TIMER_5_OVERFLOW_INT_FLAG_BIT                          0
#define CHIP_TIMER_5_OVERFLOW_INT_VECTOR                            VECT(CHIP_VECT_TIMER5_OVF)

//------------------------------------------------
// Usart 0

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

#define CHIP_USART_0_RX_INT_VECTOR                                  VECT(CHIP_VECT_USART0_RX)
#define CHIP_USART_0_DE_INT_VECTOR                                  VECT(CHIP_VECT_USART0_UDRE)
#define CHIP_USART_0_TX_INT_VECTOR                                  VECT(CHIP_VECT_USART0_TX)

//------------------------------------------------
// Usart 1

#define CHIP_USART_1                                                true

#define CHIP_USART_1_DATA_REG                                       CHIP_REG_UDR1

#define CHIP_USART_1_BAUD_RATE_REG                                  CHIP_REG_UBRR1

#define CHIP_USART_1_FRAME_ERROR_BIT_0_REG                          CHIP_REG_UCSR1A
#define CHIP_USART_1_FRAME_ERROR_BIT_0_BIT                          4
#define CHIP_USART_1_DATA_OVERRUN_BIT_0_REG                         CHIP_REG_UCSR1A
#define CHIP_USART_1_DATA_OVERRUN_BIT_0_BIT                         3
#define CHIP_USART_1_PARITY_ERROR_BIT_0_REG                         CHIP_REG_UCSR1A
#define CHIP_USART_1_PARITY_ERROR_BIT_0_BIT                         2

#define CHIP_USART_1_DOUBLE_SPEED_BIT_0_REG                         CHIP_REG_UCSR1A
#define CHIP_USART_1_DOUBLE_SPEED_BIT_0_BIT                         1

#define CHIP_USART_1_MULTI_PROCESSOR_COMMUNICATION_BIT_0_REG        CHIP_REG_UCSR1A
#define CHIP_USART_1_MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT        0

#define CHIP_USART_1_RX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_UCSR1B
#define CHIP_USART_1_RX_COMPLETE_INT_ENABLE_BIT_0_BIT               7
#define CHIP_USART_1_TX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_UCSR1B
#define CHIP_USART_1_TX_COMPLETE_INT_ENABLE_BIT_0_BIT               6
#define CHIP_USART_1_DATA_REG_EMPTY_INT_ENABLE_BIT_0_REG            CHIP_REG_UCSR1B
#define CHIP_USART_1_DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT            5

#define CHIP_USART_1_RX_ENABLE_BIT_0_REG                            CHIP_REG_UCSR1B
#define CHIP_USART_1_RX_ENABLE_BIT_0_BIT                            4
#define CHIP_USART_1_TX_ENABLE_BIT_0_REG                            CHIP_REG_UCSR1B
#define CHIP_USART_1_TX_ENABLE_BIT_0_BIT                            3

#define CHIP_USART_1_RX_DATA_BIT_8_REG                              CHIP_REG_UCSR1B
#define CHIP_USART_1_RX_DATA_BIT_8_BIT                              1
#define CHIP_USART_1_TX_DATA_BIT_8_REG                              CHIP_REG_UCSR1B
#define CHIP_USART_1_TX_DATA_BIT_8_BIT                              0

#define CHIP_USART_1_MODE_ASYNCHRONOUS_ID                           0
#define CHIP_USART_1_MODE_SYNCHRONOUS_ID                            1
#define CHIP_USART_1_MODE_MASTER_SPI_ID                             3
#define CHIP_USART_1_MODE_BIT_0_REG                                 CHIP_REG_UCSR1C
#define CHIP_USART_1_MODE_BIT_1_REG                                 CHIP_REG_UCSR1C
#define CHIP_USART_1_MODE_BIT_0_BIT                                 6
#define CHIP_USART_1_MODE_BIT_1_BIT                                 7

#define CHIP_USART_1_PARITY_DISABLE_ID                              0
#define CHIP_USART_1_PARITY_EVEN_ID                                 2
#define CHIP_USART_1_PARITY_ODD_ID                                  3
#define CHIP_USART_1_PARITY_BIT_0_REG                               CHIP_REG_UCSR1C
#define CHIP_USART_1_PARITY_BIT_1_REG                               CHIP_REG_UCSR1C
#define CHIP_USART_1_PARITY_BIT_0_BIT                               4
#define CHIP_USART_1_PARITY_BIT_1_BIT                               5

#define CHIP_USART_1_STOP_BITS_1_ID                                 0
#define CHIP_USART_1_STOP_BITS_2_ID                                 1
#define CHIP_USART_1_STOP_BITS_BIT_0_REG                            CHIP_REG_UCSR1C
#define CHIP_USART_1_STOP_BITS_BIT_0_BIT                            3

#define CHIP_USART_1_CHARACTER_SIZE_5_ID                            0
#define CHIP_USART_1_CHARACTER_SIZE_6_ID                            1
#define CHIP_USART_1_CHARACTER_SIZE_7_ID                            2
#define CHIP_USART_1_CHARACTER_SIZE_8_ID                            3
#define CHIP_USART_1_CHARACTER_SIZE_9_ID                            7
#define CHIP_USART_1_CHARACTER_SIZE_BIT_0_REG                       CHIP_REG_UCSR1C
#define CHIP_USART_1_CHARACTER_SIZE_BIT_1_REG                       CHIP_REG_UCSR1C
#define CHIP_USART_1_CHARACTER_SIZE_BIT_2_REG                       CHIP_REG_UCSR1B
#define CHIP_USART_1_CHARACTER_SIZE_BIT_0_BIT                       1
#define CHIP_USART_1_CHARACTER_SIZE_BIT_1_BIT                       2
#define CHIP_USART_1_CHARACTER_SIZE_BIT_2_BIT                       2

#define CHIP_USART_1_POLARITY_TX_RISING_RX_FALLING_ID               0
#define CHIP_USART_1_POLARITY_TX_FALLING_RX_RISING_ID               1
#define CHIP_USART_1_POLARITY_BIT_0_REG                             CHIP_REG_UCSR1C
#define CHIP_USART_1_POLARITY_BIT_0_BIT                             0

#define CHIP_USART_1_RX_INT_VECTOR                                  VECT(CHIP_VECT_USART1_RX)
#define CHIP_USART_1_DE_INT_VECTOR                                  VECT(CHIP_VECT_USART1_UDRE)
#define CHIP_USART_1_TX_INT_VECTOR                                  VECT(CHIP_VECT_USART1_TX)

//------------------------------------------------
// Usart 2

#define CHIP_USART_2                                                true

#define CHIP_USART_2_DATA_REG                                       CHIP_REG_UDR2

#define CHIP_USART_2_BAUD_RATE_REG                                  CHIP_REG_UBRR2

#define CHIP_USART_2_FRAME_ERROR_BIT_0_REG                          CHIP_REG_UCSR2A
#define CHIP_USART_2_FRAME_ERROR_BIT_0_BIT                          4
#define CHIP_USART_2_DATA_OVERRUN_BIT_0_REG                         CHIP_REG_UCSR2A
#define CHIP_USART_2_DATA_OVERRUN_BIT_0_BIT                         3
#define CHIP_USART_2_PARITY_ERROR_BIT_0_REG                         CHIP_REG_UCSR2A
#define CHIP_USART_2_PARITY_ERROR_BIT_0_BIT                         2

#define CHIP_USART_2_DOUBLE_SPEED_BIT_0_REG                         CHIP_REG_UCSR2A
#define CHIP_USART_2_DOUBLE_SPEED_BIT_0_BIT                         1

#define CHIP_USART_2_MULTI_PROCESSOR_COMMUNICATION_BIT_0_REG        CHIP_REG_UCSR2A
#define CHIP_USART_2_MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT        0

#define CHIP_USART_2_RX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_UCSR2B
#define CHIP_USART_2_RX_COMPLETE_INT_ENABLE_BIT_0_BIT               7
#define CHIP_USART_2_TX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_UCSR2B
#define CHIP_USART_2_TX_COMPLETE_INT_ENABLE_BIT_0_BIT               6
#define CHIP_USART_2_DATA_REG_EMPTY_INT_ENABLE_BIT_0_REG            CHIP_REG_UCSR2B
#define CHIP_USART_2_DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT            5

#define CHIP_USART_2_RX_ENABLE_BIT_0_REG                            CHIP_REG_UCSR2B
#define CHIP_USART_2_RX_ENABLE_BIT_0_BIT                            4
#define CHIP_USART_2_TX_ENABLE_BIT_0_REG                            CHIP_REG_UCSR2B
#define CHIP_USART_2_TX_ENABLE_BIT_0_BIT                            3

#define CHIP_USART_2_RX_DATA_BIT_8_REG                              CHIP_REG_UCSR2B
#define CHIP_USART_2_RX_DATA_BIT_8_BIT                              1
#define CHIP_USART_2_TX_DATA_BIT_8_REG                              CHIP_REG_UCSR2B
#define CHIP_USART_2_TX_DATA_BIT_8_BIT                              0

#define CHIP_USART_2_MODE_ASYNCHRONOUS_ID                           0
#define CHIP_USART_2_MODE_SYNCHRONOUS_ID                            1
#define CHIP_USART_2_MODE_MASTER_SPI_ID                             3
#define CHIP_USART_2_MODE_BIT_0_REG                                 CHIP_REG_UCSR2C
#define CHIP_USART_2_MODE_BIT_1_REG                                 CHIP_REG_UCSR2C
#define CHIP_USART_2_MODE_BIT_0_BIT                                 6
#define CHIP_USART_2_MODE_BIT_1_BIT                                 7

#define CHIP_USART_2_PARITY_DISABLE_ID                              0
#define CHIP_USART_2_PARITY_EVEN_ID                                 2
#define CHIP_USART_2_PARITY_ODD_ID                                  3
#define CHIP_USART_2_PARITY_BIT_0_REG                               CHIP_REG_UCSR2C
#define CHIP_USART_2_PARITY_BIT_1_REG                               CHIP_REG_UCSR2C
#define CHIP_USART_2_PARITY_BIT_0_BIT                               4
#define CHIP_USART_2_PARITY_BIT_1_BIT                               5

#define CHIP_USART_2_STOP_BITS_1_ID                                 0
#define CHIP_USART_2_STOP_BITS_2_ID                                 1
#define CHIP_USART_2_STOP_BITS_BIT_0_REG                            CHIP_REG_UCSR2C
#define CHIP_USART_2_STOP_BITS_BIT_0_BIT                            3

#define CHIP_USART_2_CHARACTER_SIZE_5_ID                            0
#define CHIP_USART_2_CHARACTER_SIZE_6_ID                            1
#define CHIP_USART_2_CHARACTER_SIZE_7_ID                            2
#define CHIP_USART_2_CHARACTER_SIZE_8_ID                            3
#define CHIP_USART_2_CHARACTER_SIZE_9_ID                            7
#define CHIP_USART_2_CHARACTER_SIZE_BIT_0_REG                       CHIP_REG_UCSR2C
#define CHIP_USART_2_CHARACTER_SIZE_BIT_1_REG                       CHIP_REG_UCSR2C
#define CHIP_USART_2_CHARACTER_SIZE_BIT_2_REG                       CHIP_REG_UCSR2B
#define CHIP_USART_2_CHARACTER_SIZE_BIT_0_BIT                       1
#define CHIP_USART_2_CHARACTER_SIZE_BIT_1_BIT                       2
#define CHIP_USART_2_CHARACTER_SIZE_BIT_2_BIT                       2

#define CHIP_USART_2_POLARITY_TX_RISING_RX_FALLING_ID               0
#define CHIP_USART_2_POLARITY_TX_FALLING_RX_RISING_ID               1
#define CHIP_USART_2_POLARITY_BIT_0_REG                             CHIP_REG_UCSR2C
#define CHIP_USART_2_POLARITY_BIT_0_BIT                             0

#define CHIP_USART_2_RX_INT_VECTOR                                  VECT(CHIP_VECT_USART2_RX)
#define CHIP_USART_2_DE_INT_VECTOR                                  VECT(CHIP_VECT_USART2_UDRE)
#define CHIP_USART_2_TX_INT_VECTOR                                  VECT(CHIP_VECT_USART2_TX)

//------------------------------------------------
// Usart 3

#define CHIP_USART_3                                                true

#define CHIP_USART_3_DATA_REG                                       CHIP_REG_UDR3

#define CHIP_USART_3_BAUD_RATE_REG                                  CHIP_REG_UBRR3

#define CHIP_USART_3_FRAME_ERROR_BIT_0_REG                          CHIP_REG_UCSR3A
#define CHIP_USART_3_FRAME_ERROR_BIT_0_BIT                          4
#define CHIP_USART_3_DATA_OVERRUN_BIT_0_REG                         CHIP_REG_UCSR3A
#define CHIP_USART_3_DATA_OVERRUN_BIT_0_BIT                         3
#define CHIP_USART_3_PARITY_ERROR_BIT_0_REG                         CHIP_REG_UCSR3A
#define CHIP_USART_3_PARITY_ERROR_BIT_0_BIT                         2

#define CHIP_USART_3_DOUBLE_SPEED_BIT_0_REG                         CHIP_REG_UCSR3A
#define CHIP_USART_3_DOUBLE_SPEED_BIT_0_BIT                         1

#define CHIP_USART_3_MULTI_PROCESSOR_COMMUNICATION_BIT_0_REG        CHIP_REG_UCSR3A
#define CHIP_USART_3_MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT        0

#define CHIP_USART_3_RX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_UCSR3B
#define CHIP_USART_3_RX_COMPLETE_INT_ENABLE_BIT_0_BIT               7
#define CHIP_USART_3_TX_COMPLETE_INT_ENABLE_BIT_0_REG               CHIP_REG_UCSR3B
#define CHIP_USART_3_TX_COMPLETE_INT_ENABLE_BIT_0_BIT               6
#define CHIP_USART_3_DATA_REG_EMPTY_INT_ENABLE_BIT_0_REG            CHIP_REG_UCSR3B
#define CHIP_USART_3_DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT            5

#define CHIP_USART_3_RX_ENABLE_BIT_0_REG                            CHIP_REG_UCSR3B
#define CHIP_USART_3_RX_ENABLE_BIT_0_BIT                            4
#define CHIP_USART_3_TX_ENABLE_BIT_0_REG                            CHIP_REG_UCSR3B
#define CHIP_USART_3_TX_ENABLE_BIT_0_BIT                            3

#define CHIP_USART_3_RX_DATA_BIT_8_REG                              CHIP_REG_UCSR3B
#define CHIP_USART_3_RX_DATA_BIT_8_BIT                              1
#define CHIP_USART_3_TX_DATA_BIT_8_REG                              CHIP_REG_UCSR3B
#define CHIP_USART_3_TX_DATA_BIT_8_BIT                              0

#define CHIP_USART_3_MODE_ASYNCHRONOUS_ID                           0
#define CHIP_USART_3_MODE_SYNCHRONOUS_ID                            1
#define CHIP_USART_3_MODE_MASTER_SPI_ID                             3
#define CHIP_USART_3_MODE_BIT_0_REG                                 CHIP_REG_UCSR3C
#define CHIP_USART_3_MODE_BIT_1_REG                                 CHIP_REG_UCSR3C
#define CHIP_USART_3_MODE_BIT_0_BIT                                 6
#define CHIP_USART_3_MODE_BIT_1_BIT                                 7

#define CHIP_USART_3_PARITY_DISABLE_ID                              0
#define CHIP_USART_3_PARITY_EVEN_ID                                 2
#define CHIP_USART_3_PARITY_ODD_ID                                  3
#define CHIP_USART_3_PARITY_BIT_0_REG                               CHIP_REG_UCSR3C
#define CHIP_USART_3_PARITY_BIT_1_REG                               CHIP_REG_UCSR3C
#define CHIP_USART_3_PARITY_BIT_0_BIT                               4
#define CHIP_USART_3_PARITY_BIT_1_BIT                               5

#define CHIP_USART_3_STOP_BITS_1_ID                                 0
#define CHIP_USART_3_STOP_BITS_2_ID                                 1
#define CHIP_USART_3_STOP_BITS_BIT_0_REG                            CHIP_REG_UCSR3C
#define CHIP_USART_3_STOP_BITS_BIT_0_BIT                            3

#define CHIP_USART_3_CHARACTER_SIZE_5_ID                            0
#define CHIP_USART_3_CHARACTER_SIZE_6_ID                            1
#define CHIP_USART_3_CHARACTER_SIZE_7_ID                            2
#define CHIP_USART_3_CHARACTER_SIZE_8_ID                            3
#define CHIP_USART_3_CHARACTER_SIZE_9_ID                            7
#define CHIP_USART_3_CHARACTER_SIZE_BIT_0_REG                       CHIP_REG_UCSR3C
#define CHIP_USART_3_CHARACTER_SIZE_BIT_1_REG                       CHIP_REG_UCSR3C
#define CHIP_USART_3_CHARACTER_SIZE_BIT_2_REG                       CHIP_REG_UCSR3B
#define CHIP_USART_3_CHARACTER_SIZE_BIT_0_BIT                       1
#define CHIP_USART_3_CHARACTER_SIZE_BIT_1_BIT                       2
#define CHIP_USART_3_CHARACTER_SIZE_BIT_2_BIT                       2

#define CHIP_USART_3_POLARITY_TX_RISING_RX_FALLING_ID               0
#define CHIP_USART_3_POLARITY_TX_FALLING_RX_RISING_ID               1
#define CHIP_USART_3_POLARITY_BIT_0_REG                             CHIP_REG_UCSR3C
#define CHIP_USART_3_POLARITY_BIT_0_BIT                             0

#define CHIP_USART_3_RX_INT_VECTOR                                  VECT(CHIP_VECT_USART3_RX)
#define CHIP_USART_3_DE_INT_VECTOR                                  VECT(CHIP_VECT_USART3_UDRE)
#define CHIP_USART_3_TX_INT_VECTOR                                  VECT(CHIP_VECT_USART3_TX)

#endif

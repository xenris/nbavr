#ifndef NBAVR_XXX_H
#define NBAVR_XXX_H

#define NBAVR_CHIP_DEFINED

#define TRUE 1

////////////////////////////////////////////////////////////////////
// ADC

#define CHIP_ADC                                                TRUEx

#define CHIP_ADC_ENABLE_REG                                     ADCSRAx
#define CHIP_ADC_ENABLE_BIT                                     ADENx

#define CHIP_ADC_START_REG                                      ADCSRAx
#define CHIP_ADC_START_BIT                                      ADSCx

#define CHIP_ADC_REFERENCE_BIT_0_REG                            ADMUXx
#define CHIP_ADC_REFERENCE_BIT_1_REG                            ADMUXx
#define CHIP_ADC_REFERENCE_BIT_0                                REFS0x
#define CHIP_ADC_REFERENCE_BIT_1                                REFS1x
#define CHIP_ADC_REFERENCE_AREF_ID                              0x
#define CHIP_ADC_REFERENCE_AVCC_ID                              1x
#define CHIP_ADC_REFERENCE_INTERNAL_ID                          3x

#define CHIP_ADC_CHANNEL_BIT_0_REG                              ADMUXx
#define CHIP_ADC_CHANNEL_BIT_1_REG                              ADMUXx
#define CHIP_ADC_CHANNEL_BIT_2_REG                              ADMUXx
#define CHIP_ADC_CHANNEL_BIT_3_REG                              ADMUXx
#define CHIP_ADC_CHANNEL_BIT_0                                  MUX0x
#define CHIP_ADC_CHANNEL_BIT_1                                  MUX1x
#define CHIP_ADC_CHANNEL_BIT_2                                  MUX2x
#define CHIP_ADC_CHANNEL_BIT_3                                  MUX3x
#define CHIP_ADC_CHANNEL_0_ID                                   0x
#define CHIP_ADC_CHANNEL_1_ID                                   1x
#define CHIP_ADC_CHANNEL_2_ID                                   2x
#define CHIP_ADC_CHANNEL_3_ID                                   3x
#define CHIP_ADC_CHANNEL_4_ID                                   4x
#define CHIP_ADC_CHANNEL_5_ID                                   5x
#define CHIP_ADC_CHANNEL_6_ID                                   6x
#define CHIP_ADC_CHANNEL_7_ID                                   7x
#define CHIP_ADC_CHANNEL_8_ID                                   8x
#define CHIP_ADC_CHANNEL_VBG_ID                                 14x
#define CHIP_ADC_CHANNEL_GND_ID                                 15x

#define CHIP_ADC_FREE_RUNNING_ENABLE_REG                        ADCSRAx
#define CHIP_ADC_FREE_RUNNING_ENABLE_BIT                        ADFRx

#define CHIP_ADC_TRIGGER                                        TRUEx
#define CHIP_ADC_TRIGGER_ENABLE_REG                             ADCSRAx
#define CHIP_ADC_TRIGGER_ENABLE_BIT                             ADATEx
#define CHIP_ADC_TRIGGER_BIT_0_REG                              ADCSRBx
#define CHIP_ADC_TRIGGER_BIT_1_REG                              ADCSRBx
#define CHIP_ADC_TRIGGER_BIT_2_REG                              ADCSRBx
#define CHIP_ADC_TRIGGER_BIT_0                                  ADTS0x
#define CHIP_ADC_TRIGGER_BIT_1                                  ADTS1x
#define CHIP_ADC_TRIGGER_BIT_2                                  ADTS2x
#define CHIP_ADC_TRIGGER_FREE_RUNNING_ID                        0x
#define CHIP_ADC_TRIGGER_ANALOG_COMPARATOR_ID                   1x
#define CHIP_ADC_TRIGGER_EXTERNAL_INT_0_ID                      2x
#define CHIP_ADC_TRIGGER_TIMER0_COMPARE_MATCH_A_ID              3x
#define CHIP_ADC_TRIGGER_TIMER0_OVERFLOW_ID                     4x
#define CHIP_ADC_TRIGGER_TIMER1_COMPARE_MATCH_B_ID              5x
#define CHIP_ADC_TRIGGER_TIMER1_OVERFLOW_ID                     6x
#define CHIP_ADC_TRIGGER_TIMER1_CAPTURE_EVENT_ID                7x

#define CHIP_ADC_INT_FLAG_REG                                   ADCSRAx
#define CHIP_ADC_INT_FLAG_BIT                                   ADIFx
#define CHIP_ADC_INT_ENABLE_REG                                 ADCSRAx
#define CHIP_ADC_INT_ENABLE_BIT                                 ADIEx
#define CHIP_ADC_INT_VECTOR                                     ADC_vectx

#define CHIP_ADC_LEFT_ADJUST_REG                                ADMUXx
#define CHIP_ADC_LEFT_ADJUST_BIT                                ADLARx

#define CHIP_ADC_DATA_REG                                       ADCx

#define CHIP_ADC_PRESCALER                                      TRUEx
#define CHIP_ADC_PRESCALER_BIT_0_REG                            ADCSRAx
#define CHIP_ADC_PRESCALER_BIT_1_REG                            ADCSRAx
#define CHIP_ADC_PRESCALER_BIT_2_REG                            ADCSRAx
#define CHIP_ADC_PRESCALER_BIT_0                                ADPS0x
#define CHIP_ADC_PRESCALER_BIT_1                                ADPS1x
#define CHIP_ADC_PRESCALER_BIT_2                                ADPS2x
#define CHIP_ADC_PRESCALER_2_ID                                 0x
#define CHIP_ADC_PRESCALER_4_ID                                 2x
#define CHIP_ADC_PRESCALER_8_ID                                 3x
#define CHIP_ADC_PRESCALER_16_ID                                4x
#define CHIP_ADC_PRESCALER_32_ID                                5x
#define CHIP_ADC_PRESCALER_64_ID                                6x
#define CHIP_ADC_PRESCALER_128_ID                               7x

////////////////////////////////////////////////////////////////////
// EXTERNAL INTERRUPTS

#define CHIP_INT_0                                              TRUEx
#define CHIP_INT_0_ENABLE_REG                                   EIMSKx
#define CHIP_INT_0_ENABLE_BIT                                   INT0x
#define CHIP_INT_0_FLAG_REG                                     EIFRx
#define CHIP_INT_0_FLAG_BIT                                     INTF0x
#define CHIP_INT_0_TRIGGER_LOW_ID                               0x
#define CHIP_INT_0_TRIGGER_CHANGE_ID                            1x
#define CHIP_INT_0_TRIGGER_FALLING_ID                           2x
#define CHIP_INT_0_TRIGGER_RISING_ID                            3x
#define CHIP_INT_0_TRIGGER_BIT_0_REG                            EICRAx
#define CHIP_INT_0_TRIGGER_BIT_1_REG                            EICRAx
#define CHIP_INT_0_TRIGGER_BIT_0                                ISC00x
#define CHIP_INT_0_TRIGGER_BIT_1                                ISC01x
#define CHIP_INT_0_VECTOR                                       INT0_vectx

#define CHIP_INT_1                                              TRUEx
#define CHIP_INT_1_ENABLE_REG                                   EIMSKx
#define CHIP_INT_1_ENABLE_BIT                                   INT1x
#define CHIP_INT_1_FLAG_REG                                     EIFRx
#define CHIP_INT_1_FLAG_BIT                                     INTF1x
#define CHIP_INT_1_TRIGGER_LOW_ID                               0x
#define CHIP_INT_1_TRIGGER_CHANGE_ID                            1x
#define CHIP_INT_1_TRIGGER_FALLING_ID                           2x
#define CHIP_INT_1_TRIGGER_RISING_ID                            3x
#define CHIP_INT_1_TRIGGER_BIT_0_REG                            EICRAx
#define CHIP_INT_1_TRIGGER_BIT_1_REG                            EICRAx
#define CHIP_INT_1_TRIGGER_BIT_0                                ISC10x
#define CHIP_INT_1_TRIGGER_BIT_1                                ISC11x
#define CHIP_INT_1_VECTOR                                       INT1_vectx

#define CHIP_PC_INT_0                                           TRUEx
#define CHIP_PC_INT_0_ENABLE_REG                                PCICRx
#define CHIP_PC_INT_0_ENABLE_BIT                                PCIE0x
#define CHIP_PC_INT_0_FLAG_REG                                  PCIFRx
#define CHIP_PC_INT_0_FLAG_BIT                                  PCIF0x
#define CHIP_PC_INT_0_MASK_REG                                  PCMSK0x
#define CHIP_PC_INT_0_MASK_BITS                                 0xFFx
#define CHIP_PC_INT_0_VECTOR                                    PCINT0_vectx

#define CHIP_PC_INT_1                                           TRUEx
#define CHIP_PC_INT_1_ENABLE_REG                                PCICRx
#define CHIP_PC_INT_1_ENABLE_BIT                                PCIE1x
#define CHIP_PC_INT_1_FLAG_REG                                  PCIFRx
#define CHIP_PC_INT_1_FLAG_BIT                                  PCIF1x
#define CHIP_PC_INT_1_MASK_REG                                  PCMSK1x
#define CHIP_PC_INT_1_MASK_BITS                                 0x7Fx
#define CHIP_PC_INT_1_VECTOR                                    PCINT1_vectx

#define CHIP_PC_INT_2                                           TRUEx
#define CHIP_PC_INT_2_ENABLE_REG                                PCICRx
#define CHIP_PC_INT_2_ENABLE_BIT                                PCIE2x
#define CHIP_PC_INT_2_FLAG_REG                                  PCIFRx
#define CHIP_PC_INT_2_FLAG_BIT                                  PCIF2x
#define CHIP_PC_INT_2_MASK_REG                                  PCMSK2x
#define CHIP_PC_INT_2_MASK_BITS                                 0xFFx
#define CHIP_PC_INT_2_VECTOR                                    PCINT2_vectx

////////////////////////////////////////////////////////////////////
// Timer0

#define CHIP_TIMER_0                                            TRUEx

#define CHIP_TIMER_0_TYPE                                       uint8_tx

#define CHIP_TIMER_0_OUTPUT_MODE                                TRUEx
#define CHIP_TIMER_0_OUTPUT_MODE_DISCONNECTED_ID                0x
#define CHIP_TIMER_0_OUTPUT_MODE_TOGGLE_ID                      1x
#define CHIP_TIMER_0_OUTPUT_MODE_CLEAR_ID                       2x
#define CHIP_TIMER_0_OUTPUT_MODE_SET_ID                         3x

#define CHIP_TIMER_0_WAVEFORM                                   TRUEx
#define CHIP_TIMER_0_WAVEFORM_NORMAL_ID                         0x
#define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_ID              1x
#define CHIP_TIMER_0_WAVEFORM_CTC_OCRA_ID                       2x
#define CHIP_TIMER_0_WAVEFORM_FAST_PWM_ID                       3x
#define CHIP_TIMER_0_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID         5x
#define CHIP_TIMER_0_WAVEFORM_FAST_PWM_OCRA_ID                  7x
#define CHIP_TIMER_0_WAVEFORM_BIT_COUNT                         3x
#define CHIP_TIMER_0_WAVEFORM_BIT_0_REG                         TCCR0Ax
#define CHIP_TIMER_0_WAVEFORM_BIT_1_REG                         TCCR0Ax
#define CHIP_TIMER_0_WAVEFORM_BIT_2_REG                         TCCR0Bx
#define CHIP_TIMER_0_WAVEFORM_BIT_0                             WGM00x
#define CHIP_TIMER_0_WAVEFORM_BIT_1                             WGM01x
#define CHIP_TIMER_0_WAVEFORM_BIT_2                             WGM02x

#define CHIP_TIMER_0_CLOCK_NONE_ID                              0x
#define CHIP_TIMER_0_CLOCK_1_ID                                 1x
#define CHIP_TIMER_0_CLOCK_8_ID                                 2x
#define CHIP_TIMER_0_CLOCK_64_ID                                3x
#define CHIP_TIMER_0_CLOCK_256_ID                               4x
#define CHIP_TIMER_0_CLOCK_1024_ID                              5x
#define CHIP_TIMER_0_CLOCK_FALLING_ID                           6x
#define CHIP_TIMER_0_CLOCK_RISING_ID                            7x
#define CHIP_TIMER_0_CLOCK_BIT_0_REG                            TCCR0Bx
#define CHIP_TIMER_0_CLOCK_BIT_1_REG                            TCCR0Bx
#define CHIP_TIMER_0_CLOCK_BIT_2_REG                            TCCR0Bx
#define CHIP_TIMER_0_CLOCK_BIT_0                                CS00x
#define CHIP_TIMER_0_CLOCK_BIT_1                                CS01x
#define CHIP_TIMER_0_CLOCK_BIT_2                                CS02x

#define CHIP_TIMER_0_TIMER_COUNTER_REG                          TCNT0x

#define CHIP_TIMER_0_OUTPUT_A                                   TRUEx
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_0_REG                    TCCR0Ax
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_1_REG                    TCCR0Ax
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_0                        COM0A0x
#define CHIP_TIMER_0_OUTPUT_A_MODE_BIT_1                        COM0A1x
#define CHIP_TIMER_0_OUTPUT_A_REG                               OCR0Ax
#define CHIP_TIMER_0_OUTPUT_A_INT_ENABLE_REG                    TIMSK0x
#define CHIP_TIMER_0_OUTPUT_A_INT_ENABLE_BIT                    OCIE0Ax
#define CHIP_TIMER_0_OUTPUT_A_INT_FLAG_REG                      TIFR0x
#define CHIP_TIMER_0_OUTPUT_A_INT_FLAG_BIT                      OCF0Ax
#define CHIP_TIMER_0_OUTPUT_A_INT_VECTOR                        TIMER0_COMPA_vectx

#define CHIP_TIMER_0_OUTPUT_B                                   TRUEx
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_0_REG                    TCCR0Ax
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_1_REG                    TCCR0Ax
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_0                        COM0B0x
#define CHIP_TIMER_0_OUTPUT_B_MODE_BIT_1                        COM0B1x
#define CHIP_TIMER_0_OUTPUT_B_REG                               OCR0Bx
#define CHIP_TIMER_0_OUTPUT_B_INT_ENABLE_REG                    TIMSK0x
#define CHIP_TIMER_0_OUTPUT_B_INT_ENABLE_BIT                    OCIE0Bx
#define CHIP_TIMER_0_OUTPUT_B_INT_FLAG_REG                      TIFR0x
#define CHIP_TIMER_0_OUTPUT_B_INT_FLAG_BIT                      OCF0Bx
#define CHIP_TIMER_0_OUTPUT_B_INT_VECTOR                        TIMER0_COMPB_vectx

#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_REG                    TIMSK0x
#define CHIP_TIMER_0_OVERFLOW_INT_ENABLE_BIT                    TOIE0x
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_REG                      TIFR0x
#define CHIP_TIMER_0_OVERFLOW_INT_FLAG_BIT                      TOV0x
#define CHIP_TIMER_0_OVERFLOW_INT_VECTOR                        TIMER0_OVF_vectx

////////////////////////////////////////////////////////////////////
// Timer1

#define CHIP_TIMER_1                                            TRUEx

#define CHIP_TIMER_1_TYPE                                       uint16_tx

#define CHIP_TIMER_1_OUTPUT_MODE                                TRUEx
#define CHIP_TIMER_1_OUTPUT_MODE_DISCONNECTED_ID                0x
#define CHIP_TIMER_1_OUTPUT_MODE_TOGGLE_ID                      1x
#define CHIP_TIMER_1_OUTPUT_MODE_CLEAR_ID                       2x
#define CHIP_TIMER_1_OUTPUT_MODE_SET_ID                         3x

#define CHIP_TIMER_1_WAVEFORM                                   TRUEx
#define CHIP_TIMER_1_WAVEFORM_NORMAL_ID                         0x
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_8_ID            1x
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_9_ID            2x
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_10_ID           3x
#define CHIP_TIMER_1_WAVEFORM_CTC_OCRA_ID                       4x
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_8_ID                     5x
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_9_ID                     6x
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_10_ID                    7x
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_ID         8x
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_FREQ_CORRECT_OCRA_ID    9x
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_ID              10x
#define CHIP_TIMER_1_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID         11x
#define CHIP_TIMER_1_WAVEFORM_CTC_ID                            12x
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_ID                       14x
#define CHIP_TIMER_1_WAVEFORM_FAST_PWM_OCRA_ID                  15x
#define CHIP_TIMER_1_WAVEFORM_BIT_COUNT                         4x
#define CHIP_TIMER_1_WAVEFORM_BIT_0_REG                         TCCR1Ax
#define CHIP_TIMER_1_WAVEFORM_BIT_1_REG                         TCCR1Ax
#define CHIP_TIMER_1_WAVEFORM_BIT_2_REG                         TCCR1Bx
#define CHIP_TIMER_1_WAVEFORM_BIT_3_REG                         TCCR1Bx
#define CHIP_TIMER_1_WAVEFORM_BIT_0                             WGM10x
#define CHIP_TIMER_1_WAVEFORM_BIT_1                             WGM11x
#define CHIP_TIMER_1_WAVEFORM_BIT_2                             WGM12x
#define CHIP_TIMER_1_WAVEFORM_BIT_3                             WGM13x

#define CHIP_TIMER_1_CLOCK_NONE_ID                              0x
#define CHIP_TIMER_1_CLOCK_1_ID                                 1x
#define CHIP_TIMER_1_CLOCK_8_ID                                 2x
#define CHIP_TIMER_1_CLOCK_64_ID                                3x
#define CHIP_TIMER_1_CLOCK_256_ID                               4x
#define CHIP_TIMER_1_CLOCK_1024_ID                              5x
#define CHIP_TIMER_1_CLOCK_FALLING_ID                           6x
#define CHIP_TIMER_1_CLOCK_RISING_ID                            7x
#define CHIP_TIMER_1_CLOCK_BIT_0_REG                            TCCR1Bx
#define CHIP_TIMER_1_CLOCK_BIT_1_REG                            TCCR1Bx
#define CHIP_TIMER_1_CLOCK_BIT_2_REG                            TCCR1Bx
#define CHIP_TIMER_1_CLOCK_BIT_0                                CS10x
#define CHIP_TIMER_1_CLOCK_BIT_1                                CS11x
#define CHIP_TIMER_1_CLOCK_BIT_2                                CS12x

#define CHIP_TIMER_1_TIMER_COUNTER_REG                          TCNT1x

#define CHIP_TIMER_1_OUTPUT_A                                   TRUEx
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_0_REG                    TCCR1Ax
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_1_REG                    TCCR1Ax
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_0                        COM1A0x
#define CHIP_TIMER_1_OUTPUT_A_MODE_BIT_1                        COM1A1x
#define CHIP_TIMER_1_OUTPUT_A_REG                               OCR1Ax
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_REG                    TIMSK1x
#define CHIP_TIMER_1_OUTPUT_A_INT_ENABLE_BIT                    OCIE1Ax
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_REG                      TIFR1x
#define CHIP_TIMER_1_OUTPUT_A_INT_FLAG_BIT                      OCF1Ax
#define CHIP_TIMER_1_OUTPUT_A_INT_VECTOR                        TIMER1_COMPA_vectx

#define CHIP_TIMER_1_OUTPUT_B                                   TRUEx
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_0_REG                    TCCR1Ax
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_1_REG                    TCCR1Ax
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_0                        COM1B0x
#define CHIP_TIMER_1_OUTPUT_B_MODE_BIT_1                        COM1B1x
#define CHIP_TIMER_1_OUTPUT_B_REG                               OCR1Bx
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_REG                    TIMSK1x
#define CHIP_TIMER_1_OUTPUT_B_INT_ENABLE_BIT                    OCIE1Bx
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_REG                      TIFR1x
#define CHIP_TIMER_1_OUTPUT_B_INT_FLAG_BIT                      OCF1Bx
#define CHIP_TIMER_1_OUTPUT_B_INT_VECTOR                        TIMER1_COMPB_vectx

#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_REG                    TIMSK1x
#define CHIP_TIMER_1_OVERFLOW_INT_ENABLE_BIT                    TOIE1x
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_REG                      TIFR1x
#define CHIP_TIMER_1_OVERFLOW_INT_FLAG_BIT                      TOV1x
#define CHIP_TIMER_1_OVERFLOW_INT_VECTOR                        TIMER1_OVF_vectx

// TODO Add input capture definitions.

////////////////////////////////////////////////////////////////////
// Timer2

#define CHIP_TIMER_2                                            TRUEx

#define CHIP_TIMER_2_TYPE                                       uint8_tx

#define CHIP_TIMER_2_OUTPUT_MODE                                TRUEx
#define CHIP_TIMER_2_OUTPUT_MODE_DISCONNECTED_ID                0x
#define CHIP_TIMER_2_OUTPUT_MODE_TOGGLE_ID                      1x
#define CHIP_TIMER_2_OUTPUT_MODE_CLEAR_ID                       2x
#define CHIP_TIMER_2_OUTPUT_MODE_SET_ID                         3x

#define CHIP_TIMER_2_WAVEFORM                                   TRUEx
#define CHIP_TIMER_2_WAVEFORM_NORMAL_ID                         0x
#define CHIP_TIMER_2_WAVEFORM_PWM_PHASE_CORRECT_ID              1x
#define CHIP_TIMER_2_WAVEFORM_CTC_OCRA_ID                       2x
#define CHIP_TIMER_2_WAVEFORM_FAST_PWM_ID                       3x
#define CHIP_TIMER_2_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID         5x
#define CHIP_TIMER_2_WAVEFORM_FAST_PWM_OCRA_ID                  7x
#define CHIP_TIMER_2_WAVEFORM_BIT_COUNT                         3x
#define CHIP_TIMER_2_WAVEFORM_BIT_0_REG                         TCCR2Ax
#define CHIP_TIMER_2_WAVEFORM_BIT_1_REG                         TCCR2Ax
#define CHIP_TIMER_2_WAVEFORM_BIT_2_REG                         TCCR2Bx
#define CHIP_TIMER_2_WAVEFORM_BIT_0                             WGM20x
#define CHIP_TIMER_2_WAVEFORM_BIT_1                             WGM21x
#define CHIP_TIMER_2_WAVEFORM_BIT_2                             WGM22x

#define CHIP_TIMER_2_CLOCK_NONE_ID                              0x
#define CHIP_TIMER_2_CLOCK_1_ID                                 1x
#define CHIP_TIMER_2_CLOCK_8_ID                                 2x
#define CHIP_TIMER_2_CLOCK_32_ID                                3x
#define CHIP_TIMER_2_CLOCK_64_ID                                4x
#define CHIP_TIMER_2_CLOCK_128_ID                               5x
#define CHIP_TIMER_2_CLOCK_256_ID                               6x
#define CHIP_TIMER_2_CLOCK_1024_ID                              7x
#define CHIP_TIMER_2_CLOCK_BIT_0_REG                            TCCR2Bx
#define CHIP_TIMER_2_CLOCK_BIT_1_REG                            TCCR2Bx
#define CHIP_TIMER_2_CLOCK_BIT_2_REG                            TCCR2Bx
#define CHIP_TIMER_2_CLOCK_BIT_0                                CS20x
#define CHIP_TIMER_2_CLOCK_BIT_1                                CS21x
#define CHIP_TIMER_2_CLOCK_BIT_2                                CS22x

#define CHIP_TIMER_2_TIMER_COUNTER_REG                          TCNT2x

#define CHIP_TIMER_2_OUTPUT_A                                   TRUEx
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_0_REG                    TCCR2Ax
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_1_REG                    TCCR2Ax
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_0                        COM2A0x
#define CHIP_TIMER_2_OUTPUT_A_MODE_BIT_1                        COM2A1x
#define CHIP_TIMER_2_OUTPUT_A_REG                               OCR2Ax
#define CHIP_TIMER_2_OUTPUT_A_INT_ENABLE_REG                    TIMSK2x
#define CHIP_TIMER_2_OUTPUT_A_INT_ENABLE_BIT                    OCIE2Ax
#define CHIP_TIMER_2_OUTPUT_A_INT_FLAG_REG                      TIFR2x
#define CHIP_TIMER_2_OUTPUT_A_INT_FLAG_BIT                      OCF2Ax
#define CHIP_TIMER_2_OUTPUT_A_INT_VECTOR                        TIMER2_COMPA_vectx

#define CHIP_TIMER_2_OUTPUT_B                                   TRUEx
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_0_REG                    TCCR2Ax
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_1_REG                    TCCR2Ax
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_0                        COM2B0x
#define CHIP_TIMER_2_OUTPUT_B_MODE_BIT_1                        COM2B1x
#define CHIP_TIMER_2_OUTPUT_B_REG                               OCR2Bx
#define CHIP_TIMER_2_OUTPUT_B_INT_ENABLE_REG                    TIMSK2x
#define CHIP_TIMER_2_OUTPUT_B_INT_ENABLE_BIT                    OCIE2Bx
#define CHIP_TIMER_2_OUTPUT_B_INT_FLAG_REG                      TIFR2x
#define CHIP_TIMER_2_OUTPUT_B_INT_FLAG_BIT                      OCF2Bx
#define CHIP_TIMER_2_OUTPUT_B_INT_VECTOR                        TIMER2_COMPB_vectx

#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_REG                    TIMSK2x
#define CHIP_TIMER_2_OVERFLOW_INT_ENABLE_BIT                    TOIE2x
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_REG                      TIFR2x
#define CHIP_TIMER_2_OVERFLOW_INT_FLAG_BIT                      TOV2x
#define CHIP_TIMER_2_OVERFLOW_INT_VECTOR                        TIMER2_OVF_vectx

////////////////////////////////////////////////////////////////////
// USART0

#define CHIP_USART_0                                            TRUEx

#define CHIP_USART_0_DATA_REG                                   UDR0x

#define CHIP_USART_0_BAUD_RATE_REG_HIGH                         UBRR0Hx
#define CHIP_USART_0_BAUD_RATE_REG_LOW                          UBRR0Lx

#define CHIP_USART_0_FRAME_ERROR_REG                            UCSR0Ax
#define CHIP_USART_0_FRAME_ERROR_BIT                            FE0x
#define CHIP_USART_0_DATA_OVERRUN_REG                           UCSR0Ax
#define CHIP_USART_0_DATA_OVERRUN_BIT                           DOR0x
#define CHIP_USART_0_PARITY_ERROR_REG                           UCSR0Ax
#define CHIP_USART_0_PARITY_ERROR_BIT                           UPE0x

#define CHIP_USART_0_DOUBLE_SPEED_REG                           UCSR0Ax
#define CHIP_USART_0_DOUBLE_SPEED_BIT                           U2X0x

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG          UCSR0Ax
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT          MPCM0x

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                 UCSR0Bx
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                 RXCIE0x
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                 UCSR0Bx
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                 TXCIE0x
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG              UCSR0Bx
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT              UDRIE0x

#define CHIP_USART_0_RX_ENABLE_REG                              UCSR0Bx
#define CHIP_USART_0_RX_ENABLE_BIT                              RXEN0x
#define CHIP_USART_0_TX_ENABLE_REG                              UCSR0Bx
#define CHIP_USART_0_TX_ENABLE_BIT                              TXEN0x

#define CHIP_USART_0_RX_DATA_BIT_8_REG                          UCSR0Bx
#define CHIP_USART_0_RX_DATA_BIT_8_BIT                          RXB80x
#define CHIP_USART_0_TX_DATA_BIT_8_REG                          UCSR0Bx
#define CHIP_USART_0_TX_DATA_BIT_8_BIT                          TXB80x

#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                       0x
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                        1x
#define CHIP_USART_0_MODE_MASTER_SPI_ID                         3x
#define CHIP_USART_0_MODE_BIT_COUNT                             2x
#define CHIP_USART_0_MODE_BIT_0_REG                             UCSR0Cx
#define CHIP_USART_0_MODE_BIT_1_REG                             UCSR0Cx
#define CHIP_USART_0_MODE_BIT_0                                 UMSEL00x
#define CHIP_USART_0_MODE_BIT_1                                 UMSEL01x

#define CHIP_USART_0_PARITY_DISABLE_ID                          0x
#define CHIP_USART_0_PARITY_EVEN_ID                             2x
#define CHIP_USART_0_PARITY_ODD_ID                              3x
#define CHIP_USART_0_PARITY_BIT_0_REG                           UCSR0Cx
#define CHIP_USART_0_PARITY_BIT_1_REG                           UCSR0Cx
#define CHIP_USART_0_PARITY_BIT_0                               UPM00x
#define CHIP_USART_0_PARITY_BIT_1                               UPM01x

#define CHIP_USART_0_STOP_BITS_1_ID                             0x
#define CHIP_USART_0_STOP_BITS_2_ID                             1x
#define CHIP_USART_0_STOP_BITS_REG                              UCSR0Cx
#define CHIP_USART_0_STOP_BITS_BIT                              USBS0x

#define CHIP_USART_0_CHARACTER_SIZE_5_ID                        0x
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                        1x
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                        2x
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                        3x
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                        7x
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0_REG                   UCSR0Cx
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1_REG                   UCSR0Cx
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2_REG                   UCSR0Bx
#define CHIP_USART_0_CHARACTER_SIZE_BIT_0                       UCSZ00x
#define CHIP_USART_0_CHARACTER_SIZE_BIT_1                       UCSZ01x
#define CHIP_USART_0_CHARACTER_SIZE_BIT_2                       UCSZ02x

#define CHIP_USART_0_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID     0x
#define CHIP_USART_0_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID     1x
#define CHIP_USART_0_CLOCK_POLARITY_REG                         UCSR0Cx
#define CHIP_USART_0_CLOCK_POLARITY_BIT                         UCPOL0x

#define CHIP_USART_0_RX_COMPLETE_INT_VECTOR                     USART_RX_vectx
#define CHIP_USART_0_TX_COMPLETE_INT_VECTOR                     USART_TX_vectx
#define CHIP_USART_0_DATA_REG_EMPTY_INT_VECTOR                  USART_UDRE_vectx

#endif

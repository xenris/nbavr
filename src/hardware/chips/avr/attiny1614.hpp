#ifndef NBLIB_ATTINY1614_HPP
#define NBLIB_ATTINY1614_HPP

#include "attiny402.hpp"

#undef CHIP
#define CHIP attiny1614

//------------------------------------------------
// Modules

#define CHIP_MODULE_VPORTB_ADDR                                     0x0004
#define CHIP_MODULE_VPORTC_ADDR                                     0x0008
#define CHIP_MODULE_PORTB_ADDR                                      0x0420
#define CHIP_MODULE_PORTC_ADDR                                      0x0440
#define CHIP_MODULE_ADC1_ADDR                                       0x0640
#define CHIP_MODULE_AC1_ADDR                                        0x0688
#define CHIP_MODULE_AC2_ADDR                                        0x0690
#define CHIP_MODULE_DAC0_ADDR                                       0x06A0
#define CHIP_MODULE_DAC1_ADDR                                       0x06A8
#define CHIP_MODULE_DAC2_ADDR                                       0x06B0
#define CHIP_MODULE_TCB1_ADDR                                       0x0A50
#define CHIP_MODULE_TCD0_ADDR                                       0x0A80

//------------------------------------------------
// Registers

#define CHIP_REG_VPORT_B_DIR                                        Register<uint8_t, CHIP_MODULE_VPORTB_ADDR + 0x00>
#define CHIP_REG_VPORT_B_OUT                                        Register<uint8_t, CHIP_MODULE_VPORTB_ADDR + 0x01>
#define CHIP_REG_VPORT_B_IN                                         Register<uint8_t, CHIP_MODULE_VPORTB_ADDR + 0x02>
#define CHIP_REG_VPORT_B_INTFLAGS                                   Register<uint8_t, CHIP_MODULE_VPORTB_ADDR + 0x03, 0xFF>

#define CHIP_REG_VPORT_C_DIR                                        Register<uint8_t, CHIP_MODULE_VPORTC_ADDR + 0x00>
#define CHIP_REG_VPORT_C_OUT                                        Register<uint8_t, CHIP_MODULE_VPORTC_ADDR + 0x01>
#define CHIP_REG_VPORT_C_IN                                         Register<uint8_t, CHIP_MODULE_VPORTC_ADDR + 0x02>
#define CHIP_REG_VPORT_C_INTFLAGS                                   Register<uint8_t, CHIP_MODULE_VPORTC_ADDR + 0x03, 0xFF>

#define CHIP_REG_VREF_CTRLC                                         Register<uint8_t, CHIP_MODULE_VREF_ADDR + 0x02>
#define CHIP_REG_VREF_CTRLD                                         Register<uint8_t, CHIP_MODULE_VREF_ADDR + 0x03>

#define CHIP_REG_PORT_B_DIR                                         Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x00>
#define CHIP_REG_PORT_B_DIRSET                                      Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x01, 0xFF>
#define CHIP_REG_PORT_B_DIRCLR                                      Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x02, 0xFF>
#define CHIP_REG_PORT_B_DIRTGL                                      Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x03, 0xFF>
#define CHIP_REG_PORT_B_OUT                                         Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x04>
#define CHIP_REG_PORT_B_OUTSET                                      Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x05, 0xFF>
#define CHIP_REG_PORT_B_OUTCLR                                      Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x06, 0xFF>
#define CHIP_REG_PORT_B_OUTTGL                                      Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x07, 0xFF>
#define CHIP_REG_PORT_B_IN                                          Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x08>
#define CHIP_REG_PORT_B_INTFLAGS                                    Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x09, 0xFF>
#define CHIP_REG_PORT_B_PIN0CTRL                                    Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x10>
#define CHIP_REG_PORT_B_PIN1CTRL                                    Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x11>
#define CHIP_REG_PORT_B_PIN2CTRL                                    Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x12>
#define CHIP_REG_PORT_B_PIN3CTRL                                    Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x13>
#define CHIP_REG_PORT_B_PIN4CTRL                                    Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x14>
#define CHIP_REG_PORT_B_PIN5CTRL                                    Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x15>
#define CHIP_REG_PORT_B_PIN6CTRL                                    Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x16>
#define CHIP_REG_PORT_B_PIN7CTRL                                    Register<uint8_t, CHIP_MODULE_PORTB_ADDR + 0x17>

#define CHIP_REG_PORT_C_DIR                                         Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x00>
#define CHIP_REG_PORT_C_DIRSET                                      Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x01, 0xFF>
#define CHIP_REG_PORT_C_DIRCLR                                      Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x02, 0xFF>
#define CHIP_REG_PORT_C_DIRTGL                                      Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x03, 0xFF>
#define CHIP_REG_PORT_C_OUT                                         Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x04>
#define CHIP_REG_PORT_C_OUTSET                                      Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x05, 0xFF>
#define CHIP_REG_PORT_C_OUTCLR                                      Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x06, 0xFF>
#define CHIP_REG_PORT_C_OUTTGL                                      Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x07, 0xFF>
#define CHIP_REG_PORT_C_IN                                          Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x08>
#define CHIP_REG_PORT_C_INTFLAGS                                    Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x09, 0xFF>
#define CHIP_REG_PORT_C_PIN0CTRL                                    Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x10>
#define CHIP_REG_PORT_C_PIN1CTRL                                    Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x11>
#define CHIP_REG_PORT_C_PIN2CTRL                                    Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x12>
#define CHIP_REG_PORT_C_PIN3CTRL                                    Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x13>
#define CHIP_REG_PORT_C_PIN4CTRL                                    Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x14>
#define CHIP_REG_PORT_C_PIN5CTRL                                    Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x15>
#define CHIP_REG_PORT_C_PIN6CTRL                                    Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x16>
#define CHIP_REG_PORT_C_PIN7CTRL                                    Register<uint8_t, CHIP_MODULE_PORTC_ADDR + 0x17>

#define CHIP_REG_ADC_1_CTRLA                                        Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x00>
#define CHIP_REG_ADC_1_CTRLB                                        Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x01>
#define CHIP_REG_ADC_1_CTRLC                                        Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x02>
#define CHIP_REG_ADC_1_CTRLD                                        Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x03>
#define CHIP_REG_ADC_1_CTRLE                                        Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x04>
#define CHIP_REG_ADC_1_SAMPCTRL                                     Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x05>
#define CHIP_REG_ADC_1_MUXPOS                                       Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x06>
#define CHIP_REG_ADC_1_COMMAND                                      Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x08>
#define CHIP_REG_ADC_1_EVCTRL                                       Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x09>
#define CHIP_REG_ADC_1_INTCTRL                                      Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x0A>
#define CHIP_REG_ADC_1_INTFLAGS                                     Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x0B, 0xFF>
#define CHIP_REG_ADC_1_DBGCTRL                                      Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x0C>
#define CHIP_REG_ADC_1_TEMP                                         Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x0D>
#define CHIP_REG_ADC_1_RES                                          Register<uint16_t, CHIP_MODULE_ADC1_ADDR + 0x10>
#define CHIP_REG_ADC_1_WINLT                                        Register<uint16_t, CHIP_MODULE_ADC1_ADDR + 0x12>
#define CHIP_REG_ADC_1_WINHT                                        Register<uint16_t, CHIP_MODULE_ADC1_ADDR + 0x14>
#define CHIP_REG_ADC_1_CALIB                                        Register<uint8_t, CHIP_MODULE_ADC1_ADDR + 0x16>

#define CHIP_REG_AC_1_CTRLA                                         Register<uint8_t, CHIP_MODULE_AC1_ADDR + 0x00>
#define CHIP_REG_AC_1_MUXCTRLA                                      Register<uint8_t, CHIP_MODULE_AC1_ADDR + 0x02>
#define CHIP_REG_AC_1_INTCTRL                                       Register<uint8_t, CHIP_MODULE_AC1_ADDR + 0x06>
#define CHIP_REG_AC_1_STATUS                                        Register<uint8_t, CHIP_MODULE_AC1_ADDR + 0x07>

#define CHIP_REG_AC_2_CTRLA                                         Register<uint8_t, CHIP_MODULE_AC2_ADDR + 0x00>
#define CHIP_REG_AC_2_MUXCTRLA                                      Register<uint8_t, CHIP_MODULE_AC2_ADDR + 0x02>
#define CHIP_REG_AC_2_INTCTRL                                       Register<uint8_t, CHIP_MODULE_AC2_ADDR + 0x06>
#define CHIP_REG_AC_2_STATUS                                        Register<uint8_t, CHIP_MODULE_AC2_ADDR + 0x07>

#define CHIP_REG_DAC_0_CTRLA                                        Register<uint8_t, CHIP_MODULE_DAC0_ADDR + 0x00>
#define CHIP_REG_DAC_0_DATA                                         Register<uint8_t, CHIP_MODULE_DAC0_ADDR + 0x01>

#define CHIP_REG_DAC_1_CTRLA                                        Register<uint8_t, CHIP_MODULE_DAC1_ADDR + 0x00>
#define CHIP_REG_DAC_1_DATA                                         Register<uint8_t, CHIP_MODULE_DAC1_ADDR + 0x01>

#define CHIP_REG_DAC_2_CTRLA                                        Register<uint8_t, CHIP_MODULE_DAC2_ADDR + 0x00>
#define CHIP_REG_DAC_2_DATA                                         Register<uint8_t, CHIP_MODULE_DAC2_ADDR + 0x01>

#define CHIP_REG_TCB1_CTRLA                                         Register<uint8_t, CHIP_MODULE_TCB1_ADDR + 0x00>
#define CHIP_REG_TCB1_CTRLB                                         Register<uint8_t, CHIP_MODULE_TCB1_ADDR + 0x01>
#define CHIP_REG_TCB1_EVCTRL                                        Register<uint8_t, CHIP_MODULE_TCB1_ADDR + 0x04>
#define CHIP_REG_TCB1_INTCTRL                                       Register<uint8_t, CHIP_MODULE_TCB1_ADDR + 0x05>
#define CHIP_REG_TCB1_INTFLAGS                                      Register<uint8_t, CHIP_MODULE_TCB1_ADDR + 0x06, 0xFF>
#define CHIP_REG_TCB1_STATUS                                        Register<uint8_t, CHIP_MODULE_TCB1_ADDR + 0x07>
#define CHIP_REG_TCB1_DBGCTRL                                       Register<uint8_t, CHIP_MODULE_TCB1_ADDR + 0x08>
#define CHIP_REG_TCB1_TEMP                                          Register<uint8_t, CHIP_MODULE_TCB1_ADDR + 0x09>
#define CHIP_REG_TCB1_CNT                                           Register<uint16_t, CHIP_MODULE_TCB1_ADDR + 0x0A>
#define CHIP_REG_TCB1_CCMP                                          Register<uint16_t, CHIP_MODULE_TCB1_ADDR + 0x0C>

// TODO TCD0

//------------------------------------------------
// Vectors

#undef vectorAc0
#undef vectorAdc0Result
#undef vectorAdc0Window
#undef vectorTwi0Slave
#undef vectorTwi0Master
#undef vectorSpi0
#undef vectorUsart0Rx
#undef vectorUsart0Dre
#undef vectorUsart0Tx
#undef vectorNvmEepromReady

#define vectorPortB                                                 ISR(__vector_4)
#define vectorPortC                                                 ISR(__vector_5)
#define vectorTc2                                                   ISR(__vector_14)
#define vectorTc3Overflow                                           ISR(__vector_15)
#define vectorTc3Trigger                                            ISR(__vector_16)
#define vectorAc0                                                   ISR(__vector_17)
#define vectorAc1                                                   ISR(__vector_18)
#define vectorAc2                                                   ISR(__vector_19)
#define vectorAdc0Result                                            ISR(__vector_20)
#define vectorAdc0Window                                            ISR(__vector_21)
#define vectorAdc1Result                                            ISR(__vector_22)
#define vectorAdc1Window                                            ISR(__vector_23)
#define vectorTwi0Slave                                             ISR(__vector_24)
#define vectorTwi0Master                                            ISR(__vector_25)
#define vectorSpi0                                                  ISR(__vector_26)
#define vectorUsart0Rx                                              ISR(__vector_27)
#define vectorUsart0Dre                                             ISR(__vector_28)
#define vectorUsart0Tx                                              ISR(__vector_29)
#define vectorNvmEepromReady                                        ISR(__vector_30)

//------------------------------------------------
// IO ports

#define CHIP_PORT_B
#define CHIP_PORT_B_DIRECTION_REG                                   CHIP_REG_VPORT_B_DIR
#define CHIP_PORT_B_OUTPUT_REG                                      CHIP_REG_VPORT_B_OUT
#define CHIP_PORT_B_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_B_OUTTGL
#define CHIP_PORT_B_INPUT_REG                                       CHIP_REG_VPORT_B_IN
#define CHIP_PORT_B_INT_FLAG_REG                                    CHIP_REG_VPORT_B_INTFLAGS

#define CHIP_PORT_C
#define CHIP_PORT_C_DIRECTION_REG                                   CHIP_REG_VPORT_C_DIR
#define CHIP_PORT_C_OUTPUT_REG                                      CHIP_REG_VPORT_C_OUT
#define CHIP_PORT_C_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_C_OUTTGL
#define CHIP_PORT_C_INPUT_REG                                       CHIP_REG_VPORT_C_IN
#define CHIP_PORT_C_INT_FLAG_REG                                    CHIP_REG_VPORT_C_INTFLAGS

//------------------------------------------------
// IO pins

#define CHIP_PIN_A4
#define CHIP_PIN_A4_DIRECTION_REG                                   CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A4_DIRECTION_BIT                                   4
#define CHIP_PIN_A4_OUTPUT_REG                                      CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A4_OUTPUT_BIT                                      4
#define CHIP_PIN_A4_INPUT_REG                                       CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A4_INPUT_BIT                                       4
#define CHIP_PIN_A4_PULLUP_REG                                      CHIP_REG_PORT_A_PIN4CTRL
#define CHIP_PIN_A4_PULLUP_BIT                                      3
#define CHIP_PIN_A4_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_A_OUTTGL
#define CHIP_PIN_A4_OUTPUT_TOGGLE_BIT                               4

#define CHIP_PIN_A5
#define CHIP_PIN_A5_DIRECTION_REG                                   CHIP_REG_VPORT_A_DIR
#define CHIP_PIN_A5_DIRECTION_BIT                                   5
#define CHIP_PIN_A5_OUTPUT_REG                                      CHIP_REG_VPORT_A_OUT
#define CHIP_PIN_A5_OUTPUT_BIT                                      5
#define CHIP_PIN_A5_INPUT_REG                                       CHIP_REG_VPORT_A_IN
#define CHIP_PIN_A5_INPUT_BIT                                       5
#define CHIP_PIN_A5_PULLUP_REG                                      CHIP_REG_PORT_A_PIN5CTRL
#define CHIP_PIN_A5_PULLUP_BIT                                      3
#define CHIP_PIN_A5_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_A_OUTTGL
#define CHIP_PIN_A5_OUTPUT_TOGGLE_BIT                               5

#define CHIP_PIN_B0
#define CHIP_PIN_B0_DIRECTION_REG                                   CHIP_REG_VPORT_B_DIR
#define CHIP_PIN_B0_DIRECTION_BIT                                   0
#define CHIP_PIN_B0_OUTPUT_REG                                      CHIP_REG_VPORT_B_OUT
#define CHIP_PIN_B0_OUTPUT_BIT                                      0
#define CHIP_PIN_B0_INPUT_REG                                       CHIP_REG_VPORT_B_IN
#define CHIP_PIN_B0_INPUT_BIT                                       0
#define CHIP_PIN_B0_PULLUP_REG                                      CHIP_REG_PORT_B_PIN0CTRL
#define CHIP_PIN_B0_PULLUP_BIT                                      3
#define CHIP_PIN_B0_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_B_OUTTGL
#define CHIP_PIN_B0_OUTPUT_TOGGLE_BIT                               0

#define CHIP_PIN_B1
#define CHIP_PIN_B1_DIRECTION_REG                                   CHIP_REG_VPORT_B_DIR
#define CHIP_PIN_B1_DIRECTION_BIT                                   1
#define CHIP_PIN_B1_OUTPUT_REG                                      CHIP_REG_VPORT_B_OUT
#define CHIP_PIN_B1_OUTPUT_BIT                                      1
#define CHIP_PIN_B1_INPUT_REG                                       CHIP_REG_VPORT_B_IN
#define CHIP_PIN_B1_INPUT_BIT                                       1
#define CHIP_PIN_B1_PULLUP_REG                                      CHIP_REG_PORT_B_PIN1CTRL
#define CHIP_PIN_B1_PULLUP_BIT                                      3
#define CHIP_PIN_B1_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_B_OUTTGL
#define CHIP_PIN_B1_OUTPUT_TOGGLE_BIT                               1

#define CHIP_PIN_B2
#define CHIP_PIN_B2_DIRECTION_REG                                   CHIP_REG_VPORT_B_DIR
#define CHIP_PIN_B2_DIRECTION_BIT                                   2
#define CHIP_PIN_B2_OUTPUT_REG                                      CHIP_REG_VPORT_B_OUT
#define CHIP_PIN_B2_OUTPUT_BIT                                      2
#define CHIP_PIN_B2_INPUT_REG                                       CHIP_REG_VPORT_B_IN
#define CHIP_PIN_B2_INPUT_BIT                                       2
#define CHIP_PIN_B2_PULLUP_REG                                      CHIP_REG_PORT_B_PIN2CTRL
#define CHIP_PIN_B2_PULLUP_BIT                                      3
#define CHIP_PIN_B2_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_B_OUTTGL
#define CHIP_PIN_B2_OUTPUT_TOGGLE_BIT                               2

#define CHIP_PIN_B3
#define CHIP_PIN_B3_DIRECTION_REG                                   CHIP_REG_VPORT_B_DIR
#define CHIP_PIN_B3_DIRECTION_BIT                                   3
#define CHIP_PIN_B3_OUTPUT_REG                                      CHIP_REG_VPORT_B_OUT
#define CHIP_PIN_B3_OUTPUT_BIT                                      3
#define CHIP_PIN_B3_INPUT_REG                                       CHIP_REG_VPORT_B_IN
#define CHIP_PIN_B3_INPUT_BIT                                       3
#define CHIP_PIN_B3_PULLUP_REG                                      CHIP_REG_PORT_B_PIN3CTRL
#define CHIP_PIN_B3_PULLUP_BIT                                      3
#define CHIP_PIN_B3_OUTPUT_TOGGLE_REG                               CHIP_REG_PORT_B_OUTTGL
#define CHIP_PIN_B3_OUTPUT_TOGGLE_BIT                               3

//------------------------------------------------
// Voltage References

#define CHIP_VREF_2

#define CHIP_VREF_2_VOLTAGE_REG                                     CHIP_REG_VREF_CTRLC
#define CHIP_VREF_2_VOLTAGE_MASK                                    0x07
#define CHIP_VREF_2_VOLTAGE_0_55_V_ID                               0x00
#define CHIP_VREF_2_VOLTAGE_1_1_V_ID                                0x01
#define CHIP_VREF_2_VOLTAGE_2_5_V_ID                                0x02
#define CHIP_VREF_2_VOLTAGE_4_3_V_ID                                0x03
#define CHIP_VREF_2_VOLTAGE_1_5_V_ID                                0x04

#define CHIP_VREF_3

#define CHIP_VREF_3_VOLTAGE_REG                                     CHIP_REG_VREF_CTRLC
#define CHIP_VREF_3_VOLTAGE_MASK                                    0x70
#define CHIP_VREF_3_VOLTAGE_0_55_V_ID                               0x00
#define CHIP_VREF_3_VOLTAGE_1_1_V_ID                                0x10
#define CHIP_VREF_3_VOLTAGE_2_5_V_ID                                0x20
#define CHIP_VREF_3_VOLTAGE_4_3_V_ID                                0x30
#define CHIP_VREF_3_VOLTAGE_1_5_V_ID                                0x40

#define CHIP_VREF_4

#define CHIP_VREF_4_VOLTAGE_REG                                     CHIP_REG_VREF_CTRLD
#define CHIP_VREF_4_VOLTAGE_MASK                                    0x07
#define CHIP_VREF_4_VOLTAGE_0_55_V_ID                               0x00
#define CHIP_VREF_4_VOLTAGE_1_1_V_ID                                0x01
#define CHIP_VREF_4_VOLTAGE_2_5_V_ID                                0x02
#define CHIP_VREF_4_VOLTAGE_4_3_V_ID                                0x03
#define CHIP_VREF_4_VOLTAGE_1_5_V_ID                                0x04

//------------------------------------------------
// Analog to digital converters

#define CHIP_ADC_0_CHANNEL_4_ID                                     0x04
#define CHIP_ADC_0_CHANNEL_5_ID                                     0x05
#define CHIP_ADC_0_CHANNEL_10_ID                                    0x0A
#define CHIP_ADC_0_CHANNEL_11_ID                                    0x0B

#define CHIP_ADC_1

#define CHIP_ADC_1_RESULT_REG                                       CHIP_REG_ADC_1_RES

#define CHIP_ADC_1_ENABLE_REG                                       CHIP_REG_ADC_1_CTRLA
#define CHIP_ADC_1_ENABLE_BIT                                       0

#define CHIP_ADC_1_START_REG                                        CHIP_REG_ADC_1_COMMAND
#define CHIP_ADC_1_START_BIT                                        0

#define CHIP_ADC_1_REFERENCE_REG                                    CHIP_REG_ADC_1_CTRLC
#define CHIP_ADC_1_REFERENCE_MASK                                   0x30
#define CHIP_ADC_1_REFERENCE_INTERNAL_ID                            0x00
#define CHIP_ADC_1_REFERENCE_VDD_ID                                 0x10

#define CHIP_ADC_1_CHANNEL_REG                                      CHIP_REG_ADC_1_MUXPOS
#define CHIP_ADC_1_CHANNEL_MASK                                     0x1F
#define CHIP_ADC_1_CHANNEL_0_ID                                     0x00
#define CHIP_ADC_1_CHANNEL_1_ID                                     0x01
#define CHIP_ADC_1_CHANNEL_2_ID                                     0x02
#define CHIP_ADC_1_CHANNEL_3_ID                                     0x03
#define CHIP_ADC_1_CHANNEL_INTERNAL_ID                              0x1D
#define CHIP_ADC_1_CHANNEL_TEMPERATURE_ID                           0x1E
#define CHIP_ADC_1_CHANNEL_GND_ID                                   0x1F

#define CHIP_ADC_1_FREE_RUNNING_REG                                 CHIP_REG_ADC_1_CTRLA
#define CHIP_ADC_1_FREE_RUNNING_BIT                                 1

#define CHIP_ADC_1_TRIGGER_ENABLE_REG                               CHIP_REG_ADC_1_EVCTRL
#define CHIP_ADC_1_TRIGGER_ENABLE_BIT                               0

#define CHIP_ADC_1_INT_FLAG_REG                                     CHIP_REG_ADC_1_INTFLAGS
#define CHIP_ADC_1_INT_FLAG_BIT                                     0

#define CHIP_ADC_1_INT_ENABLE_REG                                   CHIP_REG_ADC_1_INTCTRL
#define CHIP_ADC_1_INT_ENABLE_BIT                                   0

#define CHIP_ADC_1_PRESCALER_REG                                    CHIP_REG_ADC_1_CTRLC
#define CHIP_ADC_1_PRESCALER_MASK                                   0x07
#define CHIP_ADC_1_PRESCALER_2_ID                                   0x00
#define CHIP_ADC_1_PRESCALER_4_ID                                   0x01
#define CHIP_ADC_1_PRESCALER_8_ID                                   0x02
#define CHIP_ADC_1_PRESCALER_16_ID                                  0x03
#define CHIP_ADC_1_PRESCALER_32_ID                                  0x04
#define CHIP_ADC_1_PRESCALER_64_ID                                  0x05
#define CHIP_ADC_1_PRESCALER_128_ID                                 0x06
#define CHIP_ADC_1_PRESCALER_256_ID                                 0x07

//------------------------------------------------
// Comparator

#define CHIP_AC_1

#define CHIP_AC_1_ENABLE_REG                                        CHIP_REG_AC_1_CTRLA
#define CHIP_AC_1_ENABLE_BIT                                        0

#define CHIP_AC_1_OUTPUT_ENABLE_REG                                 CHIP_REG_AC_1_CTRLA
#define CHIP_AC_1_OUTPUT_ENABLE_BIT                                 6

#define CHIP_AC_1_INT_EDGE_REG                                      CHIP_REG_AC_1_CTRLA
#define CHIP_AC_1_INT_EDGE_MASK                                     0x30
#define CHIP_AC_1_INT_EDGE_BOTH_ID                                  0x00
#define CHIP_AC_1_INT_EDGE_NEGATIVE_ID                              0x20
#define CHIP_AC_1_INT_EDGE_POSITIVE_ID                              0x30

#define CHIP_AC_1_HYSTERESIS_REG                                    CHIP_REG_AC_1_CTRLA
#define CHIP_AC_1_HYSTERESIS_MASK                                   0x06
#define CHIP_AC_1_HYSTERESIS_OFF_ID                                 0x00
#define CHIP_AC_1_HYSTERESIS_10_ID                                  0x02
#define CHIP_AC_1_HYSTERESIS_25_ID                                  0x04
#define CHIP_AC_1_HYSTERESIS_50_ID                                  0x06

#define CHIP_AC_1_OUTPUT_INVERT_REG                                 CHIP_REG_AC_1_MUXCTRLA
#define CHIP_AC_1_OUTPUT_INVERT_BIT                                 7

#define CHIP_AC_1_MUX_POS_REG                                       CHIP_REG_AC_1_MUXCTRLA
#define CHIP_AC_1_MUX_POS_MASK                                      0x18
#define CHIP_AC_1_MUX_POS_0_ID                                      0x00
#define CHIP_AC_1_MUX_POS_1_ID                                      0x08
#define CHIP_AC_1_MUX_POS_2_ID                                      0x10
#define CHIP_AC_1_MUX_POS_3_ID                                      0x18

#define CHIP_AC_1_MUX_NEG_REG                                       CHIP_REG_AC_1_MUXCTRLA
#define CHIP_AC_1_MUX_NEG_MASK                                      0x03
#define CHIP_AC_1_MUX_NEG_0_ID                                      0x00
#define CHIP_AC_1_MUX_NEG_1_ID                                      0x01
#define CHIP_AC_1_MUX_NEG_VREF_ID                                   0x02
#define CHIP_AC_1_MUX_NEG_DAC_ID                                    0x03

#define CHIP_AC_1_ENABLE_INT_REG                                    CHIP_REG_AC_1_INTCTRL
#define CHIP_AC_1_ENABLE_INT_BIT                                    0

#define CHIP_AC_1_STATE_REG                                         CHIP_REG_AC_1_STATUS
#define CHIP_AC_1_STATE_BIT                                         4

#define CHIP_AC_1_INT_FLAG_REG                                      CHIP_REG_AC_1_STATUS
#define CHIP_AC_1_INT_FLAG_BIT                                      0

//------------------------------------------------

#define CHIP_AC_2

#define CHIP_AC_2_ENABLE_REG                                        CHIP_REG_AC_2_CTRLA
#define CHIP_AC_2_ENABLE_BIT                                        0

#define CHIP_AC_2_OUTPUT_ENABLE_REG                                 CHIP_REG_AC_2_CTRLA
#define CHIP_AC_2_OUTPUT_ENABLE_BIT                                 6

#define CHIP_AC_2_INT_EDGE_REG                                      CHIP_REG_AC_2_CTRLA
#define CHIP_AC_2_INT_EDGE_MASK                                     0x30
#define CHIP_AC_2_INT_EDGE_BOTH_ID                                  0x00
#define CHIP_AC_2_INT_EDGE_NEGATIVE_ID                              0x20
#define CHIP_AC_2_INT_EDGE_POSITIVE_ID                              0x30

#define CHIP_AC_2_HYSTERESIS_REG                                    CHIP_REG_AC_2_CTRLA
#define CHIP_AC_2_HYSTERESIS_MASK                                   0x06
#define CHIP_AC_2_HYSTERESIS_OFF_ID                                 0x00
#define CHIP_AC_2_HYSTERESIS_10_ID                                  0x02
#define CHIP_AC_2_HYSTERESIS_25_ID                                  0x04
#define CHIP_AC_2_HYSTERESIS_50_ID                                  0x06

#define CHIP_AC_2_OUTPUT_INVERT_REG                                 CHIP_REG_AC_2_MUXCTRLA
#define CHIP_AC_2_OUTPUT_INVERT_BIT                                 7

#define CHIP_AC_2_MUX_POS_REG                                       CHIP_REG_AC_2_MUXCTRLA
#define CHIP_AC_2_MUX_POS_MASK                                      0x18
#define CHIP_AC_2_MUX_POS_0_ID                                      0x00
#define CHIP_AC_2_MUX_POS_1_ID                                      0x08
#define CHIP_AC_2_MUX_POS_2_ID                                      0x10
#define CHIP_AC_2_MUX_POS_3_ID                                      0x18

#define CHIP_AC_2_MUX_NEG_REG                                       CHIP_REG_AC_2_MUXCTRLA
#define CHIP_AC_2_MUX_NEG_MASK                                      0x03
#define CHIP_AC_2_MUX_NEG_0_ID                                      0x00
#define CHIP_AC_2_MUX_NEG_1_ID                                      0x01
#define CHIP_AC_2_MUX_NEG_VREF_ID                                   0x02
#define CHIP_AC_2_MUX_NEG_DAC_ID                                    0x03

#define CHIP_AC_2_ENABLE_INT_REG                                    CHIP_REG_AC_2_INTCTRL
#define CHIP_AC_2_ENABLE_INT_BIT                                    0

#define CHIP_AC_2_STATE_REG                                         CHIP_REG_AC_2_STATUS
#define CHIP_AC_2_STATE_BIT                                         4

#define CHIP_AC_2_INT_FLAG_REG                                      CHIP_REG_AC_2_STATUS
#define CHIP_AC_2_INT_FLAG_BIT                                      0

//------------------------------------------------
// DAC

#define CHIP_DAC_0

#define CHIP_DAC_0_ENABLE_REG                                       CHIP_REG_DAC_0_CTRLA
#define CHIP_DAC_0_ENABLE_BIT                                       0

#define CHIP_DAC_0_OUTPUT_ENABLE_REG                                CHIP_REG_DAC_0_CTRLA
#define CHIP_DAC_0_OUTPUT_ENABLE_BIT                                6

#define CHIP_DAC_0_DATA_REG                                         CHIP_REG_DAC_0_DATA

//------------------------------------------------

#define CHIP_DAC_1

#define CHIP_DAC_1_ENABLE_REG                                       CHIP_REG_DAC_1_CTRLA
#define CHIP_DAC_1_ENABLE_BIT                                       0

#define CHIP_DAC_1_OUTPUT_ENABLE_REG                                CHIP_REG_DAC_1_CTRLA
#define CHIP_DAC_1_OUTPUT_ENABLE_BIT                                6

#define CHIP_DAC_1_DATA_REG                                         CHIP_REG_DAC_0_DATA

//------------------------------------------------

#define CHIP_DAC_2

#define CHIP_DAC_2_ENABLE_REG                                       CHIP_REG_DAC_2_CTRLA
#define CHIP_DAC_2_ENABLE_BIT                                       0

#define CHIP_DAC_2_OUTPUT_ENABLE_REG                                CHIP_REG_DAC_2_CTRLA
#define CHIP_DAC_2_OUTPUT_ENABLE_BIT                                6

#define CHIP_DAC_2_DATA_REG                                         CHIP_REG_DAC_0_DATA

//------------------------------------------------
// Timer/Counters

// TODO

//------------------------------------------------
// Usarts

#define CHIP_USART_0

#define CHIP_USART_0_RX_DATA_REG                                    CHIP_REG_USART_0_RXDATAL
#define CHIP_USART_0_RX_DATA9_REG                                   CHIP_REG_USART_0_RXDATAH
#define CHIP_USART_0_RX_DATA9_BIT                                   0

#define CHIP_USART_0_TX_DATA_REG                                    CHIP_REG_USART_0_TXDATAL
#define CHIP_USART_0_TX_DATA9_REG                                   CHIP_REG_USART_0_TXDATAH
#define CHIP_USART_0_TX_DATA9_BIT                                   0

#define CHIP_USART_0_BAUD_REG                                       CHIP_REG_USART_0_BAUD

#define CHIP_USART_0_PARITY_ERROR_REG                               CHIP_REG_USART_0_RXDATAH
#define CHIP_USART_0_PARITY_ERROR_BIT                               2

#define CHIP_USART_0_BAUD_MODE_REG                                  CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_BAUD_MODE_MASK                                 0x06
#define CHIP_USART_0_BAUD_MODE_NORMAL_ID                            0x00
#define CHIP_USART_0_BAUD_MODE_DOUBLE_ID                            0x02
#define CHIP_USART_0_BAUD_MODE_GENAUTO_ID                           0x04
#define CHIP_USART_0_BAUD_MODE_LINAUTO_ID                           0x06

#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_REG              CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_MULTI_PROCESSOR_COMMUNICATION_BIT              0

#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_USART_0_CTRLA
#define CHIP_USART_0_RX_COMPLETE_INT_ENABLE_BIT                     7
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_REG                     CHIP_REG_USART_0_CTRLA
#define CHIP_USART_0_TX_COMPLETE_INT_ENABLE_BIT                     6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_REG                  CHIP_REG_USART_0_CTRLA
#define CHIP_USART_0_DATA_REG_EMPTY_INT_ENABLE_BIT                  5

#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_REG                       CHIP_REG_USART_0_STATUS
#define CHIP_USART_0_RX_COMPLETE_INT_FLAG_BIT                       7
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_REG                       CHIP_REG_USART_0_STATUS
#define CHIP_USART_0_TX_COMPLETE_INT_FLAG_BIT                       6
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_REG                    CHIP_REG_USART_0_STATUS
#define CHIP_USART_0_DATA_REG_EMPTY_INT_FLAG_BIT                    5

#define CHIP_USART_0_RX_ENABLE_REG                                  CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_RX_ENABLE_BIT                                  7
#define CHIP_USART_0_TX_ENABLE_REG                                  CHIP_REG_USART_0_CTRLB
#define CHIP_USART_0_TX_ENABLE_BIT                                  6

#define CHIP_USART_0_ENABLE_ALTERNATE_PINS_REG                      CHIP_REG_PORTMUX_CTRLB
#define CHIP_USART_0_ENABLE_ALTERNATE_PINS_BIT                      0

#define CHIP_USART_0_MODE_REG                                       CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_MODE_MASK                                      0xC0
#define CHIP_USART_0_MODE_ASYNCHRONOUS_ID                           0x00
#define CHIP_USART_0_MODE_SYNCHRONOUS_ID                            0x40
#define CHIP_USART_0_MODE_IRCOM_ID                                  0x80
#define CHIP_USART_0_MODE_MASTER_SPI_ID                             0xC0

#define CHIP_USART_0_PARITY_REG                                     CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_PARITY_MASK                                    0x30
#define CHIP_USART_0_PARITY_DISABLE_ID                              0x00
#define CHIP_USART_0_PARITY_EVEN_ID                                 0x20
#define CHIP_USART_0_PARITY_ODD_ID                                  0x30

#define CHIP_USART_0_STOP_BITS_REG                                  CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_STOP_BITS_MASK                                 0x08
#define CHIP_USART_0_STOP_BITS_1_ID                                 0x00
#define CHIP_USART_0_STOP_BITS_2_ID                                 0x08

#define CHIP_USART_0_CHARACTER_SIZE_REG                             CHIP_REG_USART_0_CTRLC
#define CHIP_USART_0_CHARACTER_SIZE_MASK                            0x07
#define CHIP_USART_0_CHARACTER_SIZE_5_ID                            0x00
#define CHIP_USART_0_CHARACTER_SIZE_6_ID                            0x01
#define CHIP_USART_0_CHARACTER_SIZE_7_ID                            0x02
#define CHIP_USART_0_CHARACTER_SIZE_8_ID                            0x03
#define CHIP_USART_0_CHARACTER_SIZE_9_ID                            0x06
// #define CHIP_USART_0_CHARACTER_SIZE_9_LOW_ID                        0x06
// #define CHIP_USART_0_CHARACTER_SIZE_9_HIGH_ID                       0x07

#endif

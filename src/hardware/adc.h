#ifndef NBAVR_ADC_H
#define NBAVR_ADC_H

#include <avr/io.h>
#include <stdbool.h>
#include <stddef.h>
#include "chip.h"
#include "util.h"

#ifdef CHIP_ADC

typedef void (*ADCCallback)(uint16_t value);

typedef enum {
    ADC_REFERENCE_AREF = 0,
    ADC_REFERENCE_AVCC = 1,
    ADC_REFERENCE_INTERNAL = 3,
} ADCReference;

typedef enum {
    #ifdef CHIP_ADC_CHANNEL_0_ID
        ADC_CHANNEL_0 = CHIP_ADC_CHANNEL_0_ID,
    #endif
    #ifdef CHIP_ADC_CHANNEL_1_ID
        ADC_CHANNEL_1 = CHIP_ADC_CHANNEL_1_ID,
    #endif
    #ifdef CHIP_ADC_CHANNEL_2_ID
        ADC_CHANNEL_2 = CHIP_ADC_CHANNEL_2_ID,
    #endif
    #ifdef CHIP_ADC_CHANNEL_3_ID
        ADC_CHANNEL_3 = CHIP_ADC_CHANNEL_3_ID,
    #endif
    #ifdef CHIP_ADC_CHANNEL_4_ID
        ADC_CHANNEL_4 = CHIP_ADC_CHANNEL_4_ID,
    #endif
    #ifdef CHIP_ADC_CHANNEL_5_ID
        ADC_CHANNEL_5 = CHIP_ADC_CHANNEL_5_ID,
    #endif
    #ifdef CHIP_ADC_CHANNEL_6_ID
        ADC_CHANNEL_6 = CHIP_ADC_CHANNEL_6_ID,
    #endif
    #ifdef CHIP_ADC_CHANNEL_7_ID
        ADC_CHANNEL_7 = CHIP_ADC_CHANNEL_7_ID,
    #endif
    #ifdef CHIP_ADC_CHANNEL_8_ID
        ADC_CHANNEL_8 = CHIP_ADC_CHANNEL_8_ID,
    #endif
    #ifdef CHIP_ADC_CHANNEL_VBG_ID
        ADC_CHANNEL_VBG = CHIP_ADC_CHANNEL_VBG_ID,
    #endif
    #ifdef CHIP_ADC_CHANNEL_GND_ID
        ADC_CHANNEL_GND = CHIP_ADC_CHANNEL_GND_ID,
    #endif
} ADCChannel;

#ifdef CHIP_ADC_PRESCALER
typedef enum {
    #ifdef CHIP_ADC_PRESCALER_2_ID
        ADC_PRESCALER_2 = CHIP_ADC_PRESCALER_2_ID,
    #endif
    #ifdef CHIP_ADC_PRESCALER_4_ID
        ADC_PRESCALER_4 = CHIP_ADC_PRESCALER_4_ID,
    #endif
    #ifdef CHIP_ADC_PRESCALER_8_ID
        ADC_PRESCALER_8 = CHIP_ADC_PRESCALER_8_ID,
    #endif
    #ifdef CHIP_ADC_PRESCALER_16_ID
        ADC_PRESCALER_16 = CHIP_ADC_PRESCALER_16_ID,
    #endif
    #ifdef CHIP_ADC_PRESCALER_32_ID
        ADC_PRESCALER_32 = CHIP_ADC_PRESCALER_32_ID,
    #endif
    #ifdef CHIP_ADC_PRESCALER_64_ID
        ADC_PRESCALER_64 = CHIP_ADC_PRESCALER_64_ID,
    #endif
    #ifdef CHIP_ADC_PRESCALER_128_ID
        ADC_PRESCALER_128 = CHIP_ADC_PRESCALER_128_ID,
    #endif
} ADCPrescaler;
#endif

typedef enum {
    #ifdef CHIP_ADC_TRIGGER_FREE_RUNNING_ID
        ADC_TRIGGER_FREE_RUNNING = CHIP_ADC_TRIGGER_FREE_RUNNING_ID,
    #else
        ADC_TRIGGER_FREE_RUNNING,
    #endif

    #ifdef CHIP_ADC_TRIGGER
        ADC_TRIGGER_ANALOG_COMPARATOR = CHIP_ADC_TRIGGER_ANALOG_COMPARATOR_ID,
        ADC_TRIGGER_EXTERNAL_INT_0 = CHIP_ADC_TRIGGER_EXTERNAL_INT_0_ID,
        ADC_TRIGGER_TIMER0_COMPARE_MATCH_A = CHIP_ADC_TRIGGER_TIMER0_COMPARE_MATCH_A_ID,
        ADC_TRIGGER_TIMER0_OVERFLOW = CHIP_ADC_TRIGGER_TIMER0_OVERFLOW_ID,
        ADC_TRIGGER_TIMER1_COMPARE_MATCH_B = CHIP_ADC_TRIGGER_TIMER1_COMPARE_MATCH_B_ID,
        ADC_TRIGGER_TIMER1_OVERFLOW = CHIP_ADC_TRIGGER_TIMER1_OVERFLOW_ID,
        ADC_TRIGGER_TIMER1_CAPTURE_EVENT = CHIP_ADC_TRIGGER_TIMER1_CAPTURE_EVENT_ID,
    #endif

    ADC_TRIGGER_SINGLE_CONVERSION,
} ADCTrigger;

typedef struct {
    ADCReference reference;
    ADCChannel channel;
    #ifdef CHIP_ADC_PRESCALER
        ADCPrescaler prescaler;
    #endif
    bool leftAdjust;
    ADCTrigger trigger;
    ADCCallback callback;
} ADCConfig;

void adcStart(ADCConfig config) __attribute__((always_inline));
void adcStop(void) __attribute__((always_inline));

#endif // #ifdef CHIP_ADC

#endif

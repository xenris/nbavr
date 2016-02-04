#ifndef NBAVR_ADC_H
#define NBAVR_ADC_H

typedef enum {
    ADC_REFERENCE_AREF = 0,
    ADC_REFERENCE_AVCC = _BV(REFS0),
    ADC_REFERENCE_INTERNAL = _BV(REFS1) | _BV(REFS0),
} ADCReference;

typedef enum {
    ADC_0 = 0,
    ADC_1 = _BV(MUX0),
    ADC_2 = _BV(MUX1),
    ADC_3 = _BV(MUX1) | _BV(MUX0),
    ADC_4 = _BV(MUX2),
    ADC_5 = _BV(MUX2) | _BV(MUX0),
    ADC_6 = _BV(MUX2) | _BV(MUX1),
    ADC_7 = _BV(MUX2) | _BV(MUX1) | _BV(MUX0),
    ADC_8 = _BV(MUX3) | _BV(MUX1) | _BV(MUX0),
    ADC_VBG = _BV(MUX3) | _BV(MUX2) | _BV(MUX1),
    ADC_GND = _BV(MUX3) | _BV(MUX2) | _BV(MUX1) | _BV(MUX0),
} ADCChannel;

typedef enum {
    ADC_PRESCALER_2 = 0,
    ADC_PRESCALER_4 = _BV(ADPS1),
    ADC_PRESCALER_8 = _BV(ADPS1) | _BV(ADPS0),
    ADC_PRESCALER_16 = _BV(ADPS2),
    ADC_PRESCALER_32 = _BV(ADPS2) | _BV(ADPS0),
    ADC_PRESCALER_64 = _BV(ADPS2) | _BV(ADPS1),
    ADC_PRESCALER_128 = _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0),
} ADCPrescaler;

typedef enum {
    ADC_RIGHT_ADJUST = 0,
    ADC_LEFT_ADJUST = _BV(ADLAR),
} ADCAdjust;

typedef enum {
    ADC_SINGLE_CONVERSION = 0,
    ADC_FREE_RUNNING = 1,
    ADC_ANALOG_COMPARATOR = 2,
    ADC_EXTERNAL_INT_0 = 3,
    ADC_TIMER0_COMPARE_MATCH_A = 4,
    ADC_TIMER0_OVERFLOW = 5,
    ADC_TIMER1_COMPARE_MATCH_B = 6,
    ADC_TIMER1_OVERFLOW = 7,
    ADC_TIMER1_CAPTURE_EVENT = 8,
} ADCAutoTrigger;

typedef struct {
    ADCReference reference;
    ADCChannel channel;
    ADCPrescaler prescaler;
    ADCAdjust adjust;
    ADCAutoTrigger autoTrigger;
} ADCConfig;

static inline void adcStart(ADCConfig config) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        ADCH; // Read to ensure the data register can be updated.

        ADMUX = (config.reference | config.adjust | config.channel | _BV(ADIF));

        ADCSRB &= ~(_BV(ADTS2) | _BV(ADTS1) | _BV(ADTS0));
        ADCSRB |= (config.autoTrigger - 1);

        uint8_t autoTriggerEnable = (config.autoTrigger != ADC_SINGLE_CONVERSION) ? _BV(ADATE) : 0;

        ADCSRA = (_BV(ADEN) | _BV(ADSC) | autoTriggerEnable | _BV(ADIE) | config.prescaler);
    }
}

static inline void adcDisable() {
    ADCSRA = 0;
    ADMUX = _BV(ADIF); // Clear interrupt flag.
    ADCSRB &= ~(_BV(ADTS2) | _BV(ADTS1) | _BV(ADTS0));
    DIDR0 = 0;
}

static inline uint16_t adcGetValue() {
    return ADC;
}

#endif

#ifndef NBAVR_TIMER2_H
#define NBAVR_TIMER2_H

typedef enum {
    TIMER2_OUTPUT_COMPARE_DISCONNECTED = 0,
    TIMER2_OUTPUT_COMPARE_TOGGLE = 1,
    TIMER2_OUTPUT_COMPARE_CLEAR_ON_COMPARE = 2,
    TIMER2_OUTPUT_COMPARE_SET_ON_COMPARE = 3,
} Timer2OutputCompareMode;

typedef enum {
    TIMER2_NORMAL = 0,
    TIMER2_PWM_PHASE_CORRECT = _BV(WGM20),
    TIMER2_CLEAR_TIMER_ON_COMPARE = _BV(WGM21),
    TIMER2_FAST_PWM = _BV(WGM21) | _BV(WGM20),
    TIMER2_PWM_PHASE_CORRECT_OCRA = _BV(WGM22) | _BV(WGM20),
    TIMER2_FAST_PWM_OCRA = _BV(WGM22) | _BV(WGM21) | _BV(WGM20),
} Timer2WaveformGenerationMode;

typedef enum {
    TIMER2_SOURCE_NONE = 0,
    TIMER2_SOURCE_1 = 1,
    TIMER2_SOURCE_8 = 2,
    TIMER2_SOURCE_64 = 3,
    TIMER2_SOURCE_256 = 4,
    TIMER2_SOURCE_1024 = 5,
    TIMER2_SOURCE_EXTERNAL_FALLING = 6,
    TIMER2_SOURCE_EXTERNAL_RISING = 7,
} Timer2ClockSelect;

typedef struct {
    Timer2OutputCompareMode outputCompareA;
    Timer2OutputCompareMode outputCompareB;
    Timer2WaveformGenerationMode waveformGenerationMode;
    Timer2ClockSelect clockSelect;
    uint8_t timerRegister;
    uint8_t outputCompareRegisterA;
    uint8_t outputCompareRegisterB;
    bool outputCompareMatchAIntEnable;
    bool outputCompareMatchBIntEnable;
    bool overflowIntEnable;
} Timer2Config;

static inline void timer2(Timer2Config config) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {

    uint8_t a = 0;
    uint8_t b = 0;
    uint8_t t = 0;

    a |= config.outputCompareA << COM2A0;
    a |= config.outputCompareB << COM2B0;

    b |= config.waveformGenerationMode & _BV(WGM22);
    a |= config.waveformGenerationMode & (_BV(WGM21) | _BV(WGM20));

    b |= config.clockSelect;

    if(config.outputCompareMatchAIntEnable) {
        t |= _BV(OCIE2A);
    }

    if(config.outputCompareMatchBIntEnable) {
        t |= _BV(OCIE2B);
    }

    if(config.overflowIntEnable) {
        t |= _BV(TOIE2);
    }

    TCCR2A = a;
    TCCR2B = b;
    TCNT2 = config.timerRegister;
    OCR2A = config.outputCompareRegisterA;
    OCR2B = config.outputCompareRegisterB;
    TIMSK2 = t;

    }
}

static inline void timer2OutputCompareModeA(Timer2OutputCompareMode mode) {
    TCCR2A &= ~(_BV(COM2A1) | _BV(COM2A0));
    TCCR2A |= mode << COM2A0;
}

static inline void timer2OutputCompareModeB(Timer2OutputCompareMode mode) {
    TCCR2A &= ~(_BV(COM2B1) | _BV(COM2B0));
    TCCR2A |= mode << COM2B0;
}

static inline void timer2WaveformGenerationMode(Timer2WaveformGenerationMode mode) {
    if(mode & _BV(WGM22)) {
        TCCR2B |= _BV(WGM22);
    } else {
        TCCR2B &= ~_BV(WGM22);
    }

    TCCR2A &= ~(_BV(WGM21) | _BV(WGM20));
    TCCR2A |= (mode & (_BV(WGM21) | _BV(WGM20)));
}

static inline void timer2ClockSelect(Timer2ClockSelect clockSelect) {
    TCCR2B &= ~(_BV(CS22) | _BV(CS21) | _BV(CS20));
    TCCR2B |= clockSelect;
}

static inline void timer2SetTimerRegister(uint8_t v) {
    TCNT2 = v;
}

static inline uint8_t timer2GetTimerRegister() {
    return TCNT2;
}

static inline void timer2SetOutputCompareA(uint8_t v) {
    OCR2A = v;
}

static inline uint8_t timer2GetOutputCompareA() {
    return OCR2A;
}

static inline void timer2SetOutputCompareB(uint8_t v) {
    OCR2B= v;
}

static inline uint8_t timer2GetOutputCompareB() {
    return OCR2B;
}

static inline void timer2OutputCompareMatchAIntEnable(bool b) {
    if(b) {
        TIMSK2 |= _BV(OCIE2A);
    } else {
        TIMSK2 &= ~_BV(OCIE2A);
    }
}

static inline void timer2OutputCompareMatchBIntEnable(bool b) {
    if(b) {
        TIMSK2 |= _BV(OCIE2B);
    } else {
        TIMSK2 &= ~_BV(OCIE2B);
    }
}

static inline void timer2OverflowIntEnable(bool b) {
    if(b) {
        TIMSK2 |= _BV(TOIE2);
    } else {
        TIMSK2 &= ~_BV(TOIE2);
    }
}

static inline bool timer2OutputCompareMatchAFlag() {
    return TIFR2 & _BV(OCF2A);
}

static inline void timer2ClearOutputCompareMatchAFlag() {
    TIFR2 |= _BV(OCF2A);
}

static inline bool timer2OutputCompareMatchBFlag() {
    return TIFR2 & _BV(OCF2B);
}

static inline void timer2ClearOutputCompareMatchBFlag() {
    TIFR2 |= _BV(OCF2B);
}

static inline bool timer2OverflowFlag() {
    return TIFR2 & _BV(TOV2);
}

static inline void timer2ClearOverflowFlag() {
    TIFR2 |= _BV(TOV2);
}

#endif

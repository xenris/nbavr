#ifndef NBAVR_TIMER0_H
#define NBAVR_TIMER0_H

typedef enum {
    TIMER0_OUTPUT_COMPARE_DISCONNECTED = 0,
    TIMER0_OUTPUT_COMPARE_TOGGLE = 1,
    TIMER0_OUTPUT_COMPARE_CLEAR_ON_COMPARE = 2,
    TIMER0_OUTPUT_COMPARE_SET_ON_COMPARE = 3,
} Timer0OutputCompareMode;

typedef enum {
    TIMER0_NORMAL = 0,
    TIMER0_PWM_PHASE_CORRECT = _BV(WGM00),
    TIMER0_CLEAR_TIMER_ON_COMPARE = _BV(WGM01),
    TIMER0_FAST_PWM = _BV(WGM01) | _BV(WGM00),
    TIMER0_PWM_PHASE_CORRECT_OCRA = _BV(WGM02) | _BV(WGM00),
    TIMER0_FAST_PWM_OCRA = _BV(WGM02) | _BV(WGM01) | _BV(WGM00),
} Timer0WaveformGenerationMode;

typedef enum {
    TIMER0_SOURCE_NONE = 0,
    TIMER0_SOURCE_1 = 1,
    TIMER0_SOURCE_8 = 2,
    TIMER0_SOURCE_64 = 3,
    TIMER0_SOURCE_256 = 4,
    TIMER0_SOURCE_1024 = 5,
    TIMER0_SOURCE_EXTERNAL_FALLING = 6,
    TIMER0_SOURCE_EXTERNAL_RISING = 7,
} Timer0ClockSelect;

typedef struct {
    Timer0OutputCompareMode outputCompareA;
    Timer0OutputCompareMode outputCompareB;
    Timer0WaveformGenerationMode waveformGenerationMode;
    Timer0ClockSelect clockSelect;
    uint8_t timerRegister;
    uint8_t outputCompareRegisterA;
    uint8_t outputCompareRegisterB;
    bool outputCompareMatchAIntEnable;
    bool outputCompareMatchBIntEnable;
    bool overflowIntEnable;
} Timer0Config;

inline void timer0(Timer0Config config) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        uint8_t a = 0;
        uint8_t b = 0;
        uint8_t t = 0;

        a |= config.outputCompareA << COM0A0;
        a |= config.outputCompareB << COM0B0;

        b |= config.waveformGenerationMode & _BV(WGM02);
        a |= config.waveformGenerationMode & (_BV(WGM01) | _BV(WGM00));

        b |= config.clockSelect;

        if(config.outputCompareMatchAIntEnable) {
            t |= _BV(OCIE0A);
        }

        if(config.outputCompareMatchBIntEnable) {
            t |= _BV(OCIE0B);
        }

        if(config.overflowIntEnable) {
            t |= _BV(TOIE0);
        }

        TCNT0 = config.timerRegister;
        TCCR0A = a;
        TCCR0B = b;
        OCR0A = config.outputCompareRegisterA;
        OCR0B = config.outputCompareRegisterB;
        TIMSK0 = t;
    }
}

inline void timer0OutputCompareModeA(Timer0OutputCompareMode mode) {
    TCCR0A &= ~(_BV(COM0A1) | _BV(COM0A0));
    TCCR0A |= mode << COM0A0;
}

inline void timer0OutputCompareModeB(Timer0OutputCompareMode mode) {
    TCCR0A &= ~(_BV(COM0B1) | _BV(COM0B0));
    TCCR0A |= mode << COM0B0;
}

inline void timer0WaveformGenerationMode(Timer0WaveformGenerationMode mode) {
    if(mode & _BV(WGM02)) {
        TCCR0B |= _BV(WGM02);
    } else {
        TCCR0B &= ~_BV(WGM02);
    }

    TCCR0A &= ~(_BV(WGM01) | _BV(WGM00));
    TCCR0A |= (mode & (_BV(WGM01) | _BV(WGM00)));
}

inline void timer0ClockSelect(Timer0ClockSelect clockSelect) {
    TCCR0B &= ~(_BV(CS02) | _BV(CS01) | _BV(CS00));
    TCCR0B |= clockSelect;
}

inline void timer0SetTimerRegister(uint8_t v) {
    TCNT0 = v;
}

inline uint8_t timer0GetTimerRegister() {
    return TCNT0;
}

inline void timer0SetOutputCompareA(uint8_t v) {
    OCR0A = v;
}

inline uint8_t timer0GetOutputCompareA() {
    return OCR0A;
}

inline void timer0SetOutputCompareB(uint8_t v) {
    OCR0B = v;
}

inline uint8_t timer0GetOutputCompareB() {
    return OCR0B;
}

inline void timer0OutputCompareMatchAIntEnable(bool b) {
    if(b) {
        TIMSK0 |= _BV(OCIE0A);
    } else {
        TIMSK0 &= ~_BV(OCIE0A);
    }
}

inline void timer0OutputCompareMatchBIntEnable(bool b) {
    if(b) {
        TIMSK0 |= _BV(OCIE0B);
    } else {
        TIMSK0 &= ~_BV(OCIE0B);
    }
}

inline void timer0OverflowIntEnable(bool b) {
    if(b) {
        TIMSK0 |= _BV(TOIE0);
    } else {
        TIMSK0 &= ~_BV(TOIE0);
    }
}

inline bool timer0OutputCompareMatchAFlag() {
    return TIFR0 & _BV(OCF0A);
}

inline void timer0ClearOutputCompareMatchAFlag() {
    TIFR0 |= _BV(OCF0A);
}

inline bool timer0OutputCompareMatchBFlag() {
    return TIFR0 & _BV(OCF0B);
}

inline void timer0ClearOutputCompareMatchBFlag() {
    TIFR0 |= _BV(OCF0B);
}

inline bool timer0OverflowFlag() {
    return TIFR0 & _BV(TOV0);
}

inline void timer0ClearOverflowFlag() {
    TIFR0 |= _BV(TOV0);
}

#endif

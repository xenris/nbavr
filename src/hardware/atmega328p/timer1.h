#ifndef NBAVR_TIMER1_H
#define NBAVR_TIMER1_H

typedef enum {
    TIMER1_OUTPUT_COMPARE_DISCONNECTED = 0,
    TIMER1_OUTPUT_COMPARE_TOGGLE = 1,
    TIMER1_OUTPUT_COMPARE_CLEAR_ON_COMPARE = 2,
    TIMER1_OUTPUT_COMPARE_SET_ON_COMPARE = 3,
} Timer1OutputCompareMode;

typedef enum {
    TIMER1_NORMAL = 0,
    TIMER1_PWM_PHASE_CORRECT_8 = 1,
    TIMER1_PWM_PHASE_CORRECT_9 = 2,
    TIMER1_PWM_PHASE_CORRECT_10 = 3,
    TIMER1_CLEAR_TIMER_ON_COMPARE_OCR1A = 4,
    TIMER1_FAST_PWM_8 = 5,
    TIMER1_FAST_PWM_9 = 6,
    TIMER1_FAST_PWM_10 = 7,
    TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT = 8,
    TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_OCRA = 9,
    TIMER1_PWM_PHASE_CORRECT = 10,
    TIMER1_PWM_PHASE_CORRECT_OCRA = 11,
    TIMER1_CLEAR_TIMER_ON_COMPARE = 12,
    TIMER1_FAST_PWM = 14,
    TIMER1_FAST_PWM_OCRA = 15,
} Timer1WaveformGenerationMode;

typedef enum {
    TIMER1_SOURCE_NONE = 0,
    TIMER1_SOURCE_1 = 1,
    TIMER1_SOURCE_8 = 2,
    TIMER1_SOURCE_64 = 3,
    TIMER1_SOURCE_256 = 4,
    TIMER1_SOURCE_1024 = 5,
    TIMER1_SOURCE_EXTERNAL_FALLING = 6,
    TIMER1_SOURCE_EXTERNAL_RISING = 7,
} Timer1ClockSelect;

typedef struct {
    Timer1OutputCompareMode outputCompareA;
    Timer1OutputCompareMode outputCompareB;
    Timer1WaveformGenerationMode waveformGenerationMode;
    Timer1ClockSelect clockSelect;
    uint16_t timerRegister;
    uint16_t outputCompareRegisterA;
    uint16_t outputCompareRegisterB;
    bool outputCompareMatchAIntEnable;
    bool outputCompareMatchBIntEnable;
    bool overflowIntEnable;
} Timer1Config;

inline void timer1(Timer1Config config) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {

    uint8_t a = 0;
    uint8_t b = 0;
    uint8_t t = 0;

    a |= config.outputCompareA << COM1A0;
    a |= config.outputCompareB << COM1B0;

    b |= config.waveformGenerationMode & _BV(WGM12);
    a |= config.waveformGenerationMode & (_BV(WGM11) | _BV(WGM10));

    b |= config.clockSelect;

    if(config.outputCompareMatchAIntEnable) {
        t |= _BV(OCIE1A);
    }

    if(config.outputCompareMatchBIntEnable) {
        t |= _BV(OCIE1B);
    }

    if(config.overflowIntEnable) {
        t |= _BV(TOIE1);
    }

    TCCR1A = a;
    TCCR1B = b;
    TCNT1 = config.timerRegister;
    OCR1A = config.outputCompareRegisterA;
    OCR1B = config.outputCompareRegisterB;
    TIMSK1 = t;

    }
}

inline void timer1OutputCompareModeA(Timer1OutputCompareMode mode) {
    TCCR1A &= ~(_BV(COM1A1) | _BV(COM1A0));
    TCCR1A |= mode << COM1A0;
}

inline void timer1OutputCompareModeB(Timer1OutputCompareMode mode) {
    TCCR1A &= ~(_BV(COM1B1) | _BV(COM1B0));
    TCCR1A |= mode << COM1B0;
}

inline void timer1WaveformGenerationMode(Timer1WaveformGenerationMode mode) {
    if(mode & _BV(WGM12)) {
        TCCR1B |= _BV(WGM12);
    } else {
        TCCR1B &= ~_BV(WGM12);
    }

    TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
    TCCR1A |= (mode & (_BV(WGM11) | _BV(WGM10)));
}

inline void timer1ClockSelect(Timer1ClockSelect clockSelect) {
    TCCR1B &= ~(_BV(CS12) | _BV(CS11) | _BV(CS10));
    TCCR1B |= clockSelect;
}

inline void timer1SetTimerRegister(uint16_t v) {
    TCNT1 = v;
}

inline uint16_t timer1GetTimerRegister() {
    return TCNT1;
}

inline void timer1SetOutputCompareA(uint16_t v) {
    OCR1A = v;
}

inline uint16_t timer1GetOutputCompareA() {
    return OCR1A;
}

inline void timer1SetOutputCompareB(uint16_t v) {
    OCR1B = v;
}

inline uint16_t timer1GetOutputCompareB() {
    return OCR1B;
}

inline void timer1OutputCompareMatchAIntEnable(bool b) {
    if(b) {
        TIMSK1 |= _BV(OCIE1A);
    } else {
        TIMSK1 &= ~_BV(OCIE1A);
    }
}

inline void timer1OutputCompareMatchBIntEnable(bool b) {
    if(b) {
        TIMSK1 |= _BV(OCIE1B);
    } else {
        TIMSK1 &= ~_BV(OCIE1B);
    }
}

inline void timer1OverflowIntEnable(bool b) {
    if(b) {
        TIMSK1 |= _BV(TOIE1);
    } else {
        TIMSK1 &= ~_BV(TOIE1);
    }
}

inline bool timer1OutputCompareMatchAFlag() {
    return TIFR1 & _BV(OCF1A);
}

inline void timer1ClearOutputCompareMatchAFlag() {
    TIFR1 |= _BV(OCF1A);
}

inline bool timer1OutputCompareMatchBFlag() {
    return TIFR1 & _BV(OCF1B);
}

inline void timer1ClearOutputCompareMatchBFlag() {
    TIFR1 |= _BV(OCF1B);
}

inline bool timer1OverflowFlag() {
    return TIFR1 & _BV(TOV1);
}

inline void timer1ClearOverflowFlag() {
    TIFR1 |= _BV(TOV1);
}

#endif

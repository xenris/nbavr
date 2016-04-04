#if TIMER_N(_OUTPUT_A)
static TimerCallback mOutputAIntCallback;
#endif
#if TIMER_N(_OUTPUT_B)
static TimerCallback mOutputBIntCallback;
#endif
static TimerCallback mOverflowIntCallback;

void timerN()(TimerN(Config) config) {
    atomic {
        // Non-volatile register access for better optimisation.
        #if TIMER_N(_WAVEFORM_BIT_COUNT) > 0
        uint8_t* waveformBit0Reg = (uint8_t*)&TIMER_N(_WAVEFORM_BIT_0_REG);
        uint8_t* waveformBit1Reg = (uint8_t*)&TIMER_N(_WAVEFORM_BIT_1_REG);
        #endif
        #if TIMER_N(_WAVEFORM_BIT_COUNT) > 2
        uint8_t* waveformBit2Reg = (uint8_t*)&TIMER_N(_WAVEFORM_BIT_2_REG);
        #endif
        #if TIMER_N(_WAVEFORM_BIT_COUNT) > 3
        uint8_t* waveformBit3Reg = (uint8_t*)&TIMER_N(_WAVEFORM_BIT_3_REG);
        #endif
        uint8_t* clockBit0Reg = (uint8_t*)&TIMER_N(_CLOCK_BIT_0_REG);
        uint8_t* clockBit1Reg = (uint8_t*)&TIMER_N(_CLOCK_BIT_1_REG);
        uint8_t* clockBit2Reg = (uint8_t*)&TIMER_N(_CLOCK_BIT_2_REG);
        uint8_t* timerCounterReg = (uint8_t*)&TIMER_N(_TIMER_COUNTER_REG);
        #if TIMER_N(_OUTPUT_A)
        uint8_t* outputAReg = (uint8_t*)&TIMER_N(_OUTPUT_A_REG);
        uint8_t* outputAIntEnableReg = (uint8_t*)&TIMER_N(_OUTPUT_A_INT_ENABLE_REG);
        uint8_t* outputAIntFlagReg = (uint8_t*)&TIMER_N(_OUTPUT_A_INT_FLAG_REG);
        #endif
        #if TIMER_N(_OUTPUT_B)
        uint8_t* outputBReg = (uint8_t*)&TIMER_N(_OUTPUT_B_REG);
        uint8_t* outputBIntEnableReg = (uint8_t*)&TIMER_N(_OUTPUT_B_INT_ENABLE_REG);
        uint8_t* outputBIntFlagReg = (uint8_t*)&TIMER_N(_OUTPUT_B_INT_FLAG_REG);
        #endif
        uint8_t* overflowIntEnableReg = (uint8_t*)&TIMER_N(_OVERFLOW_INT_ENABLE_REG);
        uint8_t* overflowIntFlagReg = (uint8_t*)&TIMER_N(_OVERFLOW_INT_FLAG_REG);

        #if TIMER_N(_WAVEFORM_BIT_COUNT) > 0
        uint8_t waveformBit0 = TIMER_N(_WAVEFORM_BIT_0);
        uint8_t waveformBit1 = TIMER_N(_WAVEFORM_BIT_1);
        #endif
        #if TIMER_N(_WAVEFORM_BIT_COUNT) > 2
        uint8_t waveformBit2 = TIMER_N(_WAVEFORM_BIT_2);
        #endif
        #if TIMER_N(_WAVEFORM_BIT_COUNT) > 3
        uint8_t waveformBit3 = TIMER_N(_WAVEFORM_BIT_3);
        #endif
        uint8_t clockBit0 = TIMER_N(_CLOCK_BIT_0);
        uint8_t clockBit1 = TIMER_N(_CLOCK_BIT_1);
        uint8_t clockBit2 = TIMER_N(_CLOCK_BIT_2);
        #if TIMER_N(_OUTPUT_A)
        uint8_t outputAIntEnableBit = TIMER_N(_OUTPUT_A_INT_ENABLE_BIT);
        uint8_t outputAIntFlagBit = TIMER_N(_OUTPUT_A_INT_FLAG_BIT);
        #endif
        #if TIMER_N(_OUTPUT_B)
        uint8_t outputBIntEnableBit = TIMER_N(_OUTPUT_B_INT_ENABLE_BIT);
        uint8_t outputBIntFlagBit = TIMER_N(_OUTPUT_B_INT_FLAG_BIT);
        #endif
        uint8_t overflowIntEnableBit = TIMER_N(_OVERFLOW_INT_ENABLE_BIT);
        uint8_t overflowIntFlagBit = TIMER_N(_OVERFLOW_INT_FLAG_BIT);

        // Setup wave mode.
        #if TIMER_N(_WAVEFORM_BIT_COUNT) > 0
        setBit(waveformBit0Reg, waveformBit0, config.waveform & 0x01);
        setBit(waveformBit1Reg, waveformBit1, config.waveform & 0x02);
        #endif
        #if TIMER_N(_WAVEFORM_BIT_COUNT) > 2
        setBit(waveformBit2Reg, waveformBit2, config.waveform & 0x04);
        #endif
        #if TIMER_N(_WAVEFORM_BIT_COUNT) > 3
        setBit(waveformBit3Reg, waveformBit3, config.waveform & 0x08);
        #endif

        // Setup clock select.
        setBit(clockBit0Reg, clockBit0, config.clock & 0x01);
        setBit(clockBit1Reg, clockBit1, config.clock & 0x02);
        setBit(clockBit2Reg, clockBit2, config.clock & 0x04);

        // Load timer register.
        *timerCounterReg = config.timerRegister;

        // Setup output compares.
        #if TIMER_N(_OUTPUT_A)
        setBit(outputAIntEnableReg, outputAIntEnableBit, config.outputAIntEnable);
        setBit(outputAIntFlagReg, outputAIntFlagBit, true);
        *outputAReg = config.outputARegister;
        mOutputAIntCallback = config.outputAIntCallback;
        #endif

        #if TIMER_N(_OUTPUT_B)
        setBit(outputBIntEnableReg, outputBIntEnableBit, config.outputBIntEnable);
        setBit(outputBIntFlagReg, outputBIntFlagBit, true);
        *outputBReg = config.outputBRegister;
        mOutputBIntCallback = config.outputBIntCallback;
        #endif

        // Setup overflow int.
        setBit(overflowIntEnableReg, overflowIntEnableBit, config.overflowIntEnable);
        setBit(overflowIntFlagReg, overflowIntFlagBit, true);
        mOverflowIntCallback = config.overflowIntCallback;
    }
}

void timerN(SetTimerRegister)(TIMER_N(_TYPE) v) {
    TIMER_N(_TIMER_COUNTER_REG) = v;
}

TIMER_N(_TYPE) timerN(GetTimerRegister)(void) {
    return TIMER_N(_TIMER_COUNTER_REG);
}

#if TIMER_N(_OUTPUT_A)
void timerN(SetOutputCompareA)(TIMER_N(_TYPE) v) {
    TIMER_N(_OUTPUT_A_REG) = v;
}

TIMER_N(_TYPE) timerN(GetOutputCompareA)(void) {
    return TIMER_N(_OUTPUT_A_REG);
}

void timerN(OutputCompareMatchAIntEnable)(bool b) {
    if(b) {
        TIMER_N(_OUTPUT_A_INT_ENABLE_REG) |= _BV(TIMER_N(_OUTPUT_A_INT_ENABLE_BIT));
    } else {
        TIMER_N(_OUTPUT_A_INT_ENABLE_REG) &= ~_BV(TIMER_N(_OUTPUT_A_INT_ENABLE_BIT));
    }
}

bool timerN(OutputCompareAMatchFlag)(void) {
    return TIMER_N(_OUTPUT_A_INT_FLAG_REG) & _BV(TIMER_N(_OUTPUT_A_INT_FLAG_BIT));
}

void timerN(ClearOutputCompareAMatchFlag)(void) {
    TIMER_N(_OUTPUT_A_INT_FLAG_REG) |= _BV(TIMER_N(_OUTPUT_A_INT_FLAG_BIT));
}
#endif

#if TIMER_N(_OUTPUT_B)
void timerN(SetOutputCompareB)(TIMER_N(_TYPE) v) {
    TIMER_N(_OUTPUT_B_REG) = v;
}

TIMER_N(_TYPE) timerN(GetOutputCompareB)(void) {
    return TIMER_N(_OUTPUT_B_REG);
}

void timerN(OutputCompareMatchBIntEnable)(bool b) {
    if(b) {
        TIMER_N(_OUTPUT_B_INT_ENABLE_REG) |= _BV(TIMER_N(_OUTPUT_B_INT_ENABLE_BIT));
    } else {
        TIMER_N(_OUTPUT_B_INT_ENABLE_REG) &= ~_BV(TIMER_N(_OUTPUT_B_INT_ENABLE_BIT));
    }
}

bool timerN(OutputCompareBMatchFlag)(void) {
    return TIMER_N(_OUTPUT_B_INT_FLAG_REG) & _BV(TIMER_N(_OUTPUT_B_INT_FLAG_BIT));
}

void timerN(ClearOutputCompareBMatchFlag)(void) {
    TIMER_N(_OUTPUT_B_INT_FLAG_REG) |= _BV(TIMER_N(_OUTPUT_B_INT_FLAG_BIT));
}
#endif

void timerN(OverflowIntEnable)(bool b) {
    if(b) {
        TIMER_N(_OVERFLOW_INT_ENABLE_REG) |= _BV(TIMER_N(_OVERFLOW_INT_ENABLE_BIT));
    } else {
        TIMER_N(_OVERFLOW_INT_ENABLE_REG) &= ~_BV(TIMER_N(_OVERFLOW_INT_ENABLE_BIT));
    }
}

bool timerN(OverflowFlag)(void) {
    return TIMER_N(_OVERFLOW_INT_FLAG_REG) & _BV(TIMER_N(_OVERFLOW_INT_FLAG_BIT));
}

void timerN(ClearOverflowFlag)(void) {
    TIMER_N(_OVERFLOW_INT_FLAG_REG) |= _BV(TIMER_N(_OVERFLOW_INT_FLAG_BIT));
}

#if TIMER_N(_OUTPUT_A)
ISR(TIMER_N(_OUTPUT_A_INT_VECTOR)) {
    if(mOutputAIntCallback != NULL) {
        mOutputAIntCallback();
    }
}
#endif

#if TIMER_N(_OUTPUT_B)
ISR(TIMER_N(_OUTPUT_B_INT_VECTOR)) {
    if(mOutputBIntCallback != NULL) {
        mOutputBIntCallback();
    }
}
#endif

ISR(TIMER_N(_OVERFLOW_INT_VECTOR)) {
    if(mOverflowIntCallback != NULL) {
        mOverflowIntCallback();
    }
}

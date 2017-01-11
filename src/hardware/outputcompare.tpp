#define FUNC(A,B) CONCAT(A,OUTPUTCOMPARE_ID,B)

force_inline void FUNC(outputCompare,Set)(TIMERCOUNTER_N(_TYPE) v) const {
    TIMERCOUNTER_N(_OUTPUTCOMPARE_A_REG) = v;
}

force_inline TIMERCOUNTER_N(_TYPE) FUNC(outputCompare,Get)() const {
    return TIMERCOUNTER_N(_OUTPUTCOMPARE_A_REG);
}

force_inline void FUNC(outputCompare,IntEnable)(bool b) const {
    if(b) {
        TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_ENABLE_REG) |= _BV(TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_ENABLE_BIT));
    } else {
        TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_ENABLE_REG) &= ~_BV(TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_ENABLE_BIT));
    }
}

force_inline bool FUNC(outputCompare,IntFlag)() const {
    return TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_FLAG_REG) & _BV(TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_FLAG_BIT));
}

force_inline void FUNC(outputCompare,IntFlagClear)() const {
    TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_FLAG_REG) |= _BV(TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_FLAG_BIT));
}

#undef FUNC

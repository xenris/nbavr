#include "nbavr.hpp"

//int 0,1,2,3,4,5,6,7
//pcint 0,1,2
//wdt
//timer0 a,b,ov
//timer1 cap,a,b,c,ov
//timer2 a,b,ov
//timer3 cap,a,b,c,ov
//timer4 cap,a,b,c,ov
//timer5 cap,a,b,c,ov
//spi,stc
//usart0 rx,dr,tx
//usart1 rx,dr,tx
//usart2 rx,dr,tx
//usart3 rx,dr,tx
//adc
//ee
//analog comp
//twi
//spm mem

jmp_buf _longJmp;

#define MAKE_INTERRUPT_HANDLER_0(name,NAME) \
    void (*_##name##Interrupt)(void*); \
    void* _##name##InterruptData; \
    ISR(CHIP_##NAME##_INT_VECTOR) { \
        if(_##name##Interrupt != nullptr) { \
            _##name##Interrupt(_##name##InterruptData); \
        } \
    }

#define MAKE_INTERRUPT_HANDLER_1(name,NAME,id) \
    void (*_##name##id##Interrupt)(void*); \
    void* _##name##id##InterruptData; \
    ISR(CHIP_##NAME##_##id##_INT_VECTOR) { \
        if(_##name##id##Interrupt != nullptr) { \
            _##name##id##Interrupt(_##name##id##InterruptData); \
        } \
    }

#define MAKE_INTERRUPT_HANDLER_2(name1, name2, NAME1, NAME2, id) \
    void (*_##name1##id##name2##Interrupt)(void*); \
    void* _##name1##id##name2##InterruptData; \
    ISR(CHIP_##NAME1##_##id##_##NAME2##_INT_VECTOR) { \
        if(_##name1##id##name2##Interrupt != nullptr) { \
            _##name1##id##name2##Interrupt(_##name1##id##name2##InterruptData); \
        } \
    }

#ifdef CHIP_EXINT_0
    MAKE_INTERRUPT_HANDLER_1(exInt, EXINT, 0);
#endif

#ifdef CHIP_EXINT_1
    MAKE_INTERRUPT_HANDLER_1(exInt, EXINT, 1);
#endif

#ifdef CHIP_EXINT_2
    MAKE_INTERRUPT_HANDLER_1(exInt, EXINT, 2);
#endif

#ifdef CHIP_EXINT_3
    MAKE_INTERRUPT_HANDLER_1(exInt, EXINT, 3);
#endif

#ifdef CHIP_EXINT_4
    MAKE_INTERRUPT_HANDLER_1(exInt, EXINT, 4);
#endif

#ifdef CHIP_EXINT_5
    MAKE_INTERRUPT_HANDLER_1(exInt, EXINT, 5);
#endif

#ifdef CHIP_EXINT_6
    MAKE_INTERRUPT_HANDLER_1(exInt, EXINT, 6);
#endif

#ifdef CHIP_EXINT_7
    MAKE_INTERRUPT_HANDLER_1(exInt, EXINT, 7);
#endif

#ifdef CHIP_PCINT_0
    MAKE_INTERRUPT_HANDLER_1(pcInt, PCINT, 0);
#endif

#ifdef CHIP_PCINT_1
    MAKE_INTERRUPT_HANDLER_1(pcInt, PCINT, 1);
#endif

#ifdef CHIP_PCINT_2
    MAKE_INTERRUPT_HANDLER_1(pcInt, PCINT, 2);
#endif

// TODO WDT

#ifdef CHIP_TIMERCOUNTER_0
    #ifdef CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_A
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareA, TIMERCOUNTER, OUTPUTCOMPARE_A, 0);
    #endif

    #ifdef CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_B
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareB, TIMERCOUNTER, OUTPUTCOMPARE_B, 0);
    #endif

    #ifdef CHIP_TIMERCOUNTER_0_OUTPUTCOMPARE_C
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareC, TIMERCOUNTER, OUTPUTCOMPARE_C, 0);
    #endif

    MAKE_INTERRUPT_HANDLER_2(timerCounter, Overflow, TIMERCOUNTER, OVERFLOW, 0);
#endif

#ifdef CHIP_TIMERCOUNTER_1
    #ifdef CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_A
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareA, TIMERCOUNTER, OUTPUTCOMPARE_A, 1);
    #endif

    #ifdef CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_B
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareB, TIMERCOUNTER, OUTPUTCOMPARE_B, 1);
    #endif

    #ifdef CHIP_TIMERCOUNTER_1_OUTPUTCOMPARE_C
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareC, TIMERCOUNTER, OUTPUTCOMPARE_C, 1);
    #endif

    MAKE_INTERRUPT_HANDLER_2(timerCounter, Overflow, TIMERCOUNTER, OVERFLOW, 1);
#endif

#ifdef CHIP_TIMERCOUNTER_2
    #ifdef CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_A
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareA, TIMERCOUNTER, OUTPUTCOMPARE_A, 2);
    #endif

    #ifdef CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_B
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareB, TIMERCOUNTER, OUTPUTCOMPARE_B, 2);
    #endif

    #ifdef CHIP_TIMERCOUNTER_2_OUTPUTCOMPARE_C
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareC, TIMERCOUNTER, OUTPUTCOMPARE_C, 2);
    #endif

    MAKE_INTERRUPT_HANDLER_2(timerCounter, Overflow, TIMERCOUNTER, OVERFLOW, 2);
#endif

#ifdef CHIP_TIMERCOUNTER_3
    #ifdef CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_A
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareA, TIMERCOUNTER, OUTPUTCOMPARE_A, 3);
    #endif

    #ifdef CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_B
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareB, TIMERCOUNTER, OUTPUTCOMPARE_B, 3);
    #endif

    #ifdef CHIP_TIMERCOUNTER_3_OUTPUTCOMPARE_C
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareC, TIMERCOUNTER, OUTPUTCOMPARE_C, 3);
    #endif

    MAKE_INTERRUPT_HANDLER_2(timerCounter, Overflow, TIMERCOUNTER, OVERFLOW, 3);
#endif

#ifdef CHIP_TIMERCOUNTER_4
    #ifdef CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_A
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareA, TIMERCOUNTER, OUTPUTCOMPARE_A, 4);
    #endif

    #ifdef CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_B
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareB, TIMERCOUNTER, OUTPUTCOMPARE_B, 4);
    #endif

    #ifdef CHIP_TIMERCOUNTER_4_OUTPUTCOMPARE_C
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareC, TIMERCOUNTER, OUTPUTCOMPARE_C, 4);
    #endif

    MAKE_INTERRUPT_HANDLER_2(timerCounter, Overflow, TIMERCOUNTER, OVERFLOW, 4);
#endif

#ifdef CHIP_TIMERCOUNTER_5
    #ifdef CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_A
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareA, TIMERCOUNTER, OUTPUTCOMPARE_A, 5);
    #endif

    #ifdef CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_B
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareB, TIMERCOUNTER, OUTPUTCOMPARE_B, 5);
    #endif

    #ifdef CHIP_TIMERCOUNTER_5_OUTPUTCOMPARE_C
        MAKE_INTERRUPT_HANDLER_2(timerCounter, OutputCompareC, TIMERCOUNTER, OUTPUTCOMPARE_C, 5);
    #endif

    MAKE_INTERRUPT_HANDLER_2(timerCounter, Overflow, TIMERCOUNTER, OVERFLOW, 5);
#endif

//TODO spi,stc

#ifdef CHIP_USART_0
    MAKE_INTERRUPT_HANDLER_2(usart, RxComplete, USART, RX_COMPLETE, 0);
    MAKE_INTERRUPT_HANDLER_2(usart, TxComplete, USART, TX_COMPLETE, 0);
    MAKE_INTERRUPT_HANDLER_2(usart, DataRegisterEmpty, USART, DATA_REG_EMPTY, 0);
#endif

#ifdef CHIP_USART_1
    MAKE_INTERRUPT_HANDLER_2(usart, RxComplete, USART, RX_COMPLETE, 1);
    MAKE_INTERRUPT_HANDLER_2(usart, TxComplete, USART, TX_COMPLETE, 1);
    MAKE_INTERRUPT_HANDLER_2(usart, DataRegisterEmpty, USART, DATA_REG_EMPTY, 1);
#endif

#ifdef CHIP_USART_2
    MAKE_INTERRUPT_HANDLER_2(usart, RxComplete, USART, RX_COMPLETE, 2);
    MAKE_INTERRUPT_HANDLER_2(usart, TxComplete, USART, TX_COMPLETE, 2);
    MAKE_INTERRUPT_HANDLER_2(usart, DataRegisterEmpty, USART, DATA_REG_EMPTY, 2);
#endif

#ifdef CHIP_USART_3
    MAKE_INTERRUPT_HANDLER_2(usart, RxComplete, USART, RX_COMPLETE, 3);
    MAKE_INTERRUPT_HANDLER_2(usart, TxComplete, USART, TX_COMPLETE, 3);
    MAKE_INTERRUPT_HANDLER_2(usart, DataRegisterEmpty, USART, DATA_REG_EMPTY, 3);
#endif

#ifdef CHIP_ADC
    MAKE_INTERRUPT_HANDLER_0(adc, ADC);
#endif

//TODO ee
//TODO analog comp
//TODO twi
//TODO spm mem

ISR(VECT(default)) {
}

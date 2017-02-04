#ifndef NBAVR_EXINT_HPP
#define NBAVR_EXINT_HPP

#ifdef CHIP_EXINT_0
#define ID 0
#include "exint.tpp"
#undef ID
#endif

#ifdef CHIP_EXINT_1
#define ID 1
#include "exint.tpp"
#undef ID
#endif

#ifdef CHIP_EXINT_2
#define ID 2
#include "exint.tpp"
#undef ID
#endif

#ifdef CHIP_EXINT_3
#define ID 3
#include "exint.tpp"
#undef ID
#endif

#ifdef CHIP_EXINT_4
#define ID 4
#include "exint.tpp"
#undef ID
#endif

#ifdef CHIP_EXINT_5
#define ID 5
#include "exint.tpp"
#undef ID
#endif

#ifdef CHIP_EXINT_6
#define ID 6
#include "exint.tpp"
#undef ID
#endif

#ifdef CHIP_EXINT_7
#define ID 7
#include "exint.tpp"
#undef ID
#endif







/*
template <int ENABLE_REG,
    int TRIGGER_BIT_0_REG,
    int TRIGGER_BIT_1_REG,
    int FLAG_REG,
    int ENABLE_BIT,
    int TRIGGER_BIT_0_BIT,
    int TRIGGER_BIT_1_BIT,
    int FLAG_BIT,
    void (**INTERRUPT_P)(void*),
    void** INTERRUPT_DATA_P>
struct ExInt {
    enum class Trigger : uint8_t {
        Low = CHIP_EXINT_N_TRIGGER_LOW_ID,
        Change = CHIP_EXINT_N_TRIGGER_CHANGE_ID,
        Falling = CHIP_EXINT_N_TRIGGER_FALLING_ID,
        Rising = CHIP_EXINT_N_TRIGGER_RISING_ID,
    };

    static force_inline void enable(Trigger trigger, void (*interrupt)(void*), void* data) {
        atomic {
            enable_(trigger, interrupt, data);
        }
    }

    static force_inline void enable_(Trigger trigger, void (*interrupt)(void*), void* data) {
        // Register callback.
        *INTERRUPT_P = interrupt;
        *INTERRUPT_DATA_P = data;

        // Configure trigger.
        setBit_(TRIGGER_BIT_0_REG, TRIGGER_BIT_0_BIT, (uint8_t)trigger & 0x01);
        setBit_(TRIGGER_BIT_1_REG, TRIGGER_BIT_1_BIT, (uint8_t)trigger & 0x02);

        // Enable interrupt.
        setBit_(ENABLE_REG, ENABLE_BIT, true);

        // Clear interrupt flag.
        setBit_(FLAG_REG, FLAG_BIT, true);
    }

    static force_inline void disable() {
        atomic {
            disable_();
        }
    }

    static force_inline void disable_() {
        *INTERRUPT_P = nullptr;
        *INTERRUPT_DATA_P = nullptr;

        setBit(ENABLE_REG, ENABLE_BIT, false);

        setBit_(FLAG_REG, FLAG_BIT, true);
    }
};

#define MAKE_EXINT_CLASS(ID) \
        typedef ExInt< \
                (int)CHIP_EXINT_##ID##_ENABLE_REG, \
                (int)CHIP_EXINT_##ID##_TRIGGER_BIT_0_REG, \
                (int)CHIP_EXINT_##ID##_TRIGGER_BIT_1_REG, \
                (int)CHIP_EXINT_##ID##_FLAG_REG, \
                (int)CHIP_EXINT_##ID##_ENABLE_BIT, \
                (int)CHIP_EXINT_##ID##_TRIGGER_BIT_0_BIT, \
                (int)CHIP_EXINT_##ID##_TRIGGER_BIT_1_BIT, \
                (int)CHIP_EXINT_##ID##_FLAG_BIT, \
                &_exInt##ID##Interrupt, \
                &_exInt##ID##InterruptData \
                > ExInt##ID;

#ifdef CHIP_EXINT_0
MAKE_EXINT_CLASS(0)
#endif

#ifdef CHIP_EXINT_1
MAKE_EXINT_CLASS(1)
#endif

#ifdef CHIP_EXINT_2
MAKE_EXINT_CLASS(2)
#endif

#ifdef CHIP_EXINT_3
MAKE_EXINT_CLASS(3)
#endif

#ifdef CHIP_EXINT_4
MAKE_EXINT_CLASS(4)
#endif

#ifdef CHIP_EXINT_5
MAKE_EXINT_CLASS(5)
#endif

#ifdef CHIP_EXINT_6
MAKE_EXINT_CLASS(6)
#endif

#ifdef CHIP_EXINT_7
MAKE_EXINT_CLASS(7)
#endif
*/
#endif

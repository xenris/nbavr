class PcInt {
    volatile uint8_t* const _enableRegister;
    volatile uint8_t* const _maskRegister;
    volatile uint8_t* const _flagRegister;
    const uint8_t _enableBit;
    const uint8_t _flagBit;
    void (*&_interruptP)(void*);
    void*& _interruptDataP;

public:
    PcInt(
        volatile uint8_t* const enableRegister,
        volatile uint8_t* const maskRegister,
        volatile uint8_t* const flagRegister,
        const uint8_t enableBit,
        const uint8_t flagBit,
        void (*&interruptP)(void*),
        void*& interruptDataP)
    :
    _enableRegister(enableRegister),
    _maskRegister(maskRegister),
    _flagRegister(flagRegister),
    _enableBit(enableBit),
    _flagBit(flagBit),
    _interruptP(interruptP),
    _interruptDataP(interruptDataP) {
    }

    force_inline void enable(uint8_t mask, void (*interrupt)(void*), void* data) {
        atomic {
            enable_(mask, interrupt, data);
        }
    }

    force_inline void enable_(uint8_t mask, void (*interrupt)(void*), void* data) {
        // Register callback.
        _interruptP = interrupt;
        _interruptDataP = data;

        // Configure trigger.
        *_maskRegister = mask;

        // Enable interrupt.
        setBit_(_enableRegister, _enableBit, true);

        // Clear interrupt flag.
        setBit_(_flagRegister, _flagBit, true);
    }

    force_inline void disable() {
        atomic {
            disable_();
        }
    }

    force_inline void disable_() {
        _interruptP = nullptr;
        _interruptDataP = nullptr;

        *_maskRegister = 0;

        setBit_(_enableRegister, _enableBit, false);

        setBit_(_flagRegister, _flagBit, true);
    }
};

#define MAKE_PCINT_CLASS(ID) \
    struct PcInt##ID : PcInt { \
        PcInt##ID() \
            : PcInt( \
                CHIP_PCINT_##ID##_ENABLE_REG, \
                CHIP_PCINT_##ID##_MASK_REG, \
                CHIP_PCINT_##ID##_FLAG_REG, \
                CHIP_PCINT_##ID##_ENABLE_BIT, \
                CHIP_PCINT_##ID##_FLAG_BIT, \
                _pcInt##ID##Interrupt, \
                _pcInt##ID##InterruptData \
                ) { \
        } \
    };

#ifdef CHIP_PCINT_0
MAKE_PCINT_CLASS(0)
#endif

#ifdef CHIP_PCINT_1
MAKE_PCINT_CLASS(1)
#endif

#ifdef CHIP_PCINT_2
MAKE_PCINT_CLASS(2)
#endif

class ExInt {
    volatile uint8_t& _enableRegister;
    volatile uint8_t& _triggerBit0Register;
    volatile uint8_t& _triggerBit1Register;
    volatile uint8_t& _flagRegister;
    const uint8_t _enableBit;
    const uint8_t _triggerBit0Bit;
    const uint8_t _triggerBit1Bit;
    const uint8_t _flagBit;
    void (*&_interruptP)(void*);
    void*& _interruptDataP;

public:
    enum class Trigger : uint8_t {
        Low = CHIP_EXINT_N_TRIGGER_LOW_ID,
        Change = CHIP_EXINT_N_TRIGGER_CHANGE_ID,
        Falling = CHIP_EXINT_N_TRIGGER_FALLING_ID,
        Rising = CHIP_EXINT_N_TRIGGER_RISING_ID,
    };

    ExInt(
        volatile uint8_t& enableRegister,
        volatile uint8_t& triggerBit0Register,
        volatile uint8_t& triggerBit1Register,
        volatile uint8_t& flagRegister,
        const uint8_t enableBit,
        const uint8_t triggerBit0Bit,
        const uint8_t triggerBit1Bit,
        const uint8_t flagBit,
        void (*&interruptP)(void*),
        void*& interruptDataP)
    :
    _enableRegister(enableRegister),
    _triggerBit0Register(triggerBit0Register),
    _triggerBit1Register(triggerBit1Register),
    _flagRegister(flagRegister),
    _enableBit(enableBit),
    _triggerBit0Bit(triggerBit0Bit),
    _triggerBit1Bit(triggerBit1Bit),
    _flagBit(flagBit),
    _interruptP(interruptP),
    _interruptDataP(interruptDataP) {
    }

    force_inline void enable(Trigger trigger, void (*interrupt)(void*), void* data) {
        atomic {
            enable_(trigger, interrupt, data);
        }
    }

    force_inline void enable_(Trigger trigger, void (*interrupt)(void*), void* data) {
        // Register callback.
        _interruptP = interrupt;
        _interruptDataP = data;

        // Configure trigger.
        setBit_(_triggerBit0Register, _triggerBit0Bit, (uint8_t)trigger & 0x01);
        setBit_(_triggerBit1Register, _triggerBit1Bit, (uint8_t)trigger & 0x02);

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

        setBit(_enableRegister, _enableBit, false);

        setBit_(_flagRegister, _flagBit, true);
    }
};

#define MAKE_EXINT_CLASS(ID) \
    struct ExInt##ID : ExInt { \
        ExInt##ID() \
            : ExInt( \
                CHIP_EXINT_##ID##_ENABLE_REG, \
                CHIP_EXINT_##ID##_TRIGGER_BIT_0_REG, \
                CHIP_EXINT_##ID##_TRIGGER_BIT_1_REG, \
                CHIP_EXINT_##ID##_FLAG_REG, \
                CHIP_EXINT_##ID##_ENABLE_BIT, \
                CHIP_EXINT_##ID##_TRIGGER_BIT_0_BIT, \
                CHIP_EXINT_##ID##_TRIGGER_BIT_1_BIT, \
                CHIP_EXINT_##ID##_FLAG_BIT, \
                _exInt##ID##Interrupt, \
                _exInt##ID##InterruptData \
                ) { \
        } \
    };

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

// TODO Possibly make a parent Usart class like Pin and Port.
//  This will remove the need for templates, but may not be
//  possible with the variations in usarts.

#define usartN(A) CONCAT(usart,USART_ID,A)
#define _usartN(A) CONCAT(_usart,USART_ID,A)
#define UsartN(A) CONCAT(Usart,USART_ID,A)
#define USART_N(A) CONCAT(CHIP_USART_,USART_ID,A)

struct UsartN() {
    enum class Mode : uint8_t {
        Asynchronous = USART_N(_MODE_ASYNCHRONOUS_ID),
        Synchronous = USART_N(_MODE_SYNCHRONOUS_ID),
        #if USART_N(_MODE_MASTER_SPI_ID)
        MasterSpi = USART_N(_MODE_MASTER_SPI_ID),
        #endif
    };

    enum class Parity : uint8_t {
        Disabled = USART_N(_PARITY_DISABLE_ID),
        Even = USART_N(_PARITY_EVEN_ID),
        Odd = USART_N(_PARITY_ODD_ID),
    };

    enum class StopBits : uint8_t {
        Bits1 = USART_N(_STOP_BITS_1_ID),
        Bits2 = USART_N(_STOP_BITS_2_ID),
    };

    enum class CharacterSize : uint8_t {
        Size5 = USART_N(_CHARACTER_SIZE_5_ID),
        Size6 = USART_N(_CHARACTER_SIZE_6_ID),
        Size7 = USART_N(_CHARACTER_SIZE_7_ID),
        Size8 = USART_N(_CHARACTER_SIZE_8_ID),
        Size9 = USART_N(_CHARACTER_SIZE_9_ID),
    };

    enum class ClockPolarity : uint8_t {
        TxRisingRxFalling = USART_N(_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID),
        TxFallingRxRising = USART_N(_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID),
    };

    struct Config {
        bool receiverEnable = false;
        bool transmitterEnable = false;
        bool multiprocessorCummunicationMode = false;
        bool rxCompleteIntEnable = false;
        bool txCompleteIntEnable = false;
        bool dataRegisterEmptyIntEnable = false;
        void (*rxCompleteInterrupt)(void*) = nullptr;
        void* rxCompleteInterruptData = nullptr;
        void (*txCompleteInterrupt)(void*) = nullptr;
        void* txCompleteInterruptData = nullptr;
        void (*dataRegisterEmptyInterrupt)(void*) = nullptr;
        void* dataRegisterEmptyInterruptData = nullptr;
        Mode mode = Mode::Asynchronous;
        Parity parity = Parity::Disabled;
        StopBits stopBits = StopBits::Bits1;
        CharacterSize characterSize = CharacterSize::Size8;
        ClockPolarity clockPolarity = ClockPolarity::TxRisingRxFalling;
        uint16_t baud = 0;
        bool use2X = false;
    };

    force_inline void apply(Config config) {
        atomic {
            setBit_(USART_N(_DOUBLE_SPEED_REG), USART_N(_DOUBLE_SPEED_BIT), config.use2X);

            setBit_(USART_N(_MULTI_PROCESSOR_COMMUNICATION_REG), USART_N(_MULTI_PROCESSOR_COMMUNICATION_BIT), config.multiprocessorCummunicationMode);

            setBit_(USART_N(_RX_COMPLETE_INT_ENABLE_REG), USART_N(_RX_COMPLETE_INT_ENABLE_BIT), config.rxCompleteIntEnable);
            setBit_(USART_N(_TX_COMPLETE_INT_ENABLE_REG), USART_N(_TX_COMPLETE_INT_ENABLE_BIT), config.txCompleteIntEnable);
            setBit_(USART_N(_DATA_REG_EMPTY_INT_ENABLE_REG), USART_N(_DATA_REG_EMPTY_INT_ENABLE_BIT), config.dataRegisterEmptyIntEnable);

            setBit_(USART_N(_RX_ENABLE_REG), USART_N(_RX_ENABLE_BIT), config.receiverEnable);
            setBit_(USART_N(_TX_ENABLE_REG), USART_N(_TX_ENABLE_BIT), config.transmitterEnable);

            setBit_(USART_N(_CHARACTER_SIZE_BIT_0_REG), USART_N(_CHARACTER_SIZE_BIT_0_BIT), (uint8_t)config.characterSize & 0x01);
            setBit_(USART_N(_CHARACTER_SIZE_BIT_1_REG), USART_N(_CHARACTER_SIZE_BIT_1_BIT), (uint8_t)config.characterSize & 0x02);
            setBit_(USART_N(_CHARACTER_SIZE_BIT_2_REG), USART_N(_CHARACTER_SIZE_BIT_2_BIT), (uint8_t)config.characterSize & 0x04);

            setBit_(USART_N(_MODE_BIT_0_REG), USART_N(_MODE_BIT_0_BIT), (uint8_t)config.mode & 0x01);
            #if USART_N(_MODE_BIT_COUNT) > 1
            setBit_(USART_N(_MODE_BIT_1_REG), USART_N(_MODE_BIT_1_BIT), (uint8_t)config.mode & 0x02);
            #endif

            setBit_(USART_N(_PARITY_BIT_0_REG), USART_N(_PARITY_BIT_0_BIT), (uint8_t)config.parity & 0x01);
            setBit_(USART_N(_PARITY_BIT_1_REG), USART_N(_PARITY_BIT_1_BIT), (uint8_t)config.parity & 0x02);

            setBit_(USART_N(_STOP_BITS_REG), USART_N(_STOP_BITS_BIT), config.stopBits == StopBits::Bits2);

            setBit_(USART_N(_CLOCK_POLARITY_REG), USART_N(_CLOCK_POLARITY_BIT), config.clockPolarity == ClockPolarity::TxFallingRxRising);

            setBit_(USART_N(_FRAME_ERROR_REG), USART_N(_FRAME_ERROR_BIT), false);
            setBit_(USART_N(_DATA_OVERRUN_REG), USART_N(_DATA_OVERRUN_BIT), false);
            setBit_(USART_N(_PARITY_ERROR_REG), USART_N(_PARITY_ERROR_BIT), false);

            #if USART_N(_USART_REG_SELECT)
            setBit_(USART_N(_USART_REG_SELECT_REG), USART_N(_USART_REG_SELECT_BIT), true);
            _MemoryBarrier();
            #endif

            USART_N(_BAUD_RATE_REG_HIGH) = config.baud >> 8;
            USART_N(_BAUD_RATE_REG_LOW) = config.baud;

            _usartN(RxCompleteInterrupt) = config.rxCompleteInterrupt;
            _usartN(RxCompleteInterruptData) = config.rxCompleteInterruptData;

            _usartN(TxCompleteInterrupt) = config.txCompleteInterrupt;
            _usartN(TxCompleteInterruptData) = config.txCompleteInterruptData;

            _usartN(DataRegisterEmptyInterrupt) = config.dataRegisterEmptyInterrupt;
            _usartN(DataRegisterEmptyInterruptData) = config.dataRegisterEmptyInterruptData;
        }
    }

    force_inline void push(uint8_t b) {
        USART_N(_DATA_REG) = b;
    }

    force_inline void push9(uint16_t b) {
        if(b & 0x0100) {
            USART_N(_TX_DATA_BIT_8_REG) |= _BV(USART_N(_TX_DATA_BIT_8_BIT));
        } else {
            USART_N(_TX_DATA_BIT_8_REG) &= ~_BV(USART_N(_TX_DATA_BIT_8_BIT));
        }

        USART_N(_DATA_REG) = b;
    }

    force_inline uint8_t pop() {
        return USART_N(_DATA_REG);
    }

    force_inline uint16_t pop9() {
        uint8_t bit8 = USART_N(_RX_DATA_BIT_8_REG) & _BV(USART_N(_RX_DATA_BIT_8_BIT));
        uint8_t result = USART_N(_DATA_REG);

        if(bit8) {
            result |= 0x0100;
        }

        return result;
    }

    force_inline bool frameError() {
        bool result = USART_N(_FRAME_ERROR_REG) & _BV(USART_N(_FRAME_ERROR_BIT));

        USART_N(_FRAME_ERROR_REG) &= ~_BV(USART_N(_FRAME_ERROR_BIT));

        return result;
    }

    force_inline bool dataOverRun() {
        bool result = USART_N(_DATA_OVERRUN_REG) & _BV(USART_N(_DATA_OVERRUN_BIT));

        USART_N(_DATA_OVERRUN_REG) &= ~_BV(USART_N(_DATA_OVERRUN_BIT));

        return result;
    }

    force_inline bool parityError() {
        bool result = USART_N(_PARITY_ERROR_REG) & _BV(USART_N(_PARITY_ERROR_BIT));

        USART_N(_PARITY_ERROR_REG) &= ~_BV(USART_N(_PARITY_ERROR_BIT));

        return result;
    }

    force_inline void rxCompleteInterruptEnable(bool b) {
        if(b) {
            USART_N(_RX_COMPLETE_INT_ENABLE_REG) |= _BV(USART_N(_RX_COMPLETE_INT_ENABLE_BIT));
        } else {
            USART_N(_RX_COMPLETE_INT_ENABLE_REG) &= ~_BV(USART_N(_RX_COMPLETE_INT_ENABLE_BIT));
        }
    }

    force_inline void txCompleteInterruptEnable(bool b) {
        if(b) {
            USART_N(_TX_COMPLETE_INT_ENABLE_REG) |= _BV(USART_N(_TX_COMPLETE_INT_ENABLE_BIT));
        } else {
            USART_N(_TX_COMPLETE_INT_ENABLE_REG) &= ~_BV(USART_N(_TX_COMPLETE_INT_ENABLE_BIT));
        }
    }

    force_inline void dataRegisterEmptyInterruptEnable(bool b) {
        if(b) {
            USART_N(_DATA_REG_EMPTY_INT_ENABLE_REG) |= _BV(USART_N(_DATA_REG_EMPTY_INT_ENABLE_BIT));
        } else {
            USART_N(_DATA_REG_EMPTY_INT_ENABLE_REG) &= ~_BV(USART_N(_DATA_REG_EMPTY_INT_ENABLE_BIT));
        }
    }

    force_inline void receiverEnable(bool b) {
        if(b) {
            USART_N(_RX_ENABLE_REG) |= _BV(USART_N(_RX_ENABLE_BIT));
        } else {
            USART_N(_RX_ENABLE_REG) &= ~_BV(USART_N(_RX_ENABLE_BIT));
        }
    }

    force_inline void transmitterEnable(bool b) {
        if(b) {
            USART_N(_TX_ENABLE_REG) |= _BV(USART_N(_TX_ENABLE_BIT));
        } else {
            USART_N(_TX_ENABLE_REG) &= ~_BV(USART_N(_TX_ENABLE_BIT));
        }
    }
};

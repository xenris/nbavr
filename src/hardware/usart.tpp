#define UsartN CONCAT(Usart,ID)

#define MODE_ASYNCHRONOUS_ID CONCAT(CHIP_USART_, ID, _MODE_ASYNCHRONOUS_ID)
#define MODE_SYNCHRONOUS_ID CONCAT(CHIP_USART_, ID, _MODE_SYNCHRONOUS_ID)
#define MODE_MASTER_SPI_ID CONCAT(CHIP_USART_, ID, _MODE_MASTER_SPI_ID)

#define MODE_BIT_COUNT CONCAT(CHIP_USART_, ID, _MODE_BIT_COUNT)

#define MODE_BIT_0_REG CONCAT(CHIP_USART_, ID, _MODE_BIT_0_REG)
#define MODE_BIT_0_BIT CONCAT(CHIP_USART_, ID, _MODE_BIT_0_BIT)
#define MODE_BIT_1_REG CONCAT(CHIP_USART_, ID, _MODE_BIT_1_REG)
#define MODE_BIT_1_BIT CONCAT(CHIP_USART_, ID, _MODE_BIT_1_BIT)

#define PARITY_DISABLE_ID CONCAT(CHIP_USART_, ID, _PARITY_DISABLE_ID)
#define PARITY_EVEN_ID CONCAT(CHIP_USART_, ID, _PARITY_EVEN_ID)
#define PARITY_ODD_ID CONCAT(CHIP_USART_, ID, _PARITY_ODD_ID)

#define PARITY_BIT_0_REG CONCAT(CHIP_USART_, ID, _PARITY_BIT_0_REG)
#define PARITY_BIT_0_BIT CONCAT(CHIP_USART_, ID, _PARITY_BIT_0_BIT)
#define PARITY_BIT_1_REG CONCAT(CHIP_USART_, ID, _PARITY_BIT_1_REG)
#define PARITY_BIT_1_BIT CONCAT(CHIP_USART_, ID, _PARITY_BIT_1_BIT)

#define PARITY_ERROR_REG CONCAT(CHIP_USART_, ID, _PARITY_ERROR_REG)
#define PARITY_ERROR_BIT CONCAT(CHIP_USART_, ID, _PARITY_ERROR_BIT)

#define STOP_BITS_1_ID CONCAT(CHIP_USART_, ID, _STOP_BITS_1_ID)
#define STOP_BITS_2_ID CONCAT(CHIP_USART_, ID, _STOP_BITS_2_ID)

#define STOP_BITS_REG CONCAT(CHIP_USART_, ID, _STOP_BITS_REG)
#define STOP_BITS_BIT CONCAT(CHIP_USART_, ID, _STOP_BITS_BIT)

#define CHARACTER_SIZE_5_ID CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_5_ID)
#define CHARACTER_SIZE_6_ID CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_6_ID)
#define CHARACTER_SIZE_7_ID CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_7_ID)
#define CHARACTER_SIZE_8_ID CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_8_ID)
#define CHARACTER_SIZE_9_ID CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_9_ID)

#define CHARACTER_SIZE_BIT_0_REG CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_BIT_0_REG)
#define CHARACTER_SIZE_BIT_1_REG CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_BIT_1_REG)
#define CHARACTER_SIZE_BIT_2_REG CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_BIT_2_REG)

#define CHARACTER_SIZE_BIT_0_BIT CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_BIT_0_BIT)
#define CHARACTER_SIZE_BIT_1_BIT CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_BIT_1_BIT)
#define CHARACTER_SIZE_BIT_2_BIT CONCAT(CHIP_USART_, ID, _CHARACTER_SIZE_BIT_2_BIT)

#define CLOCK_POLARITY_TX_RISING_RX_FALLING_ID CONCAT(CHIP_USART_, ID, _CLOCK_POLARITY_TX_RISING_RX_FALLING_ID)
#define CLOCK_POLARITY_TX_FALLING_RX_RISING_ID CONCAT(CHIP_USART_, ID, _CLOCK_POLARITY_TX_FALLING_RX_RISING_ID)

#define CLOCK_POLARITY_REG CONCAT(CHIP_USART_, ID, _CLOCK_POLARITY_REG)
#define CLOCK_POLARITY_BIT CONCAT(CHIP_USART_, ID, _CLOCK_POLARITY_BIT)

#define DATA_REG CONCAT(CHIP_USART_, ID, _DATA_REG)
#define TX_DATA_BIT_8_REG CONCAT(CHIP_USART_, ID, _TX_DATA_BIT_8_REG)
#define TX_DATA_BIT_8_BIT CONCAT(CHIP_USART_, ID, _TX_DATA_BIT_8_BIT)
#define RX_DATA_BIT_8_REG CONCAT(CHIP_USART_, ID, _RX_DATA_BIT_8_REG)
#define RX_DATA_BIT_8_BIT CONCAT(CHIP_USART_, ID, _RX_DATA_BIT_8_BIT)

#define BAUD_RATE_REG_HIGH CONCAT(CHIP_USART_, ID, _BAUD_RATE_REG_HIGH)
#define BAUD_RATE_REG_LOW CONCAT(CHIP_USART_, ID, _BAUD_RATE_REG_LOW)

#define DOUBLE_SPEED_REG CONCAT(CHIP_USART_, ID, _DOUBLE_SPEED_REG)
#define DOUBLE_SPEED_BIT CONCAT(CHIP_USART_, ID, _DOUBLE_SPEED_BIT)

#define MULTI_PROCESSOR_COMMUNICATION_REG CONCAT(CHIP_USART_, ID, _MULTI_PROCESSOR_COMMUNICATION_REG)
#define MULTI_PROCESSOR_COMMUNICATION_BIT CONCAT(CHIP_USART_, ID, _MULTI_PROCESSOR_COMMUNICATION_BIT)

#define RX_COMPLETE_INT_ENABLE_REG CONCAT(CHIP_USART_, ID, _RX_COMPLETE_INT_ENABLE_REG)
#define RX_COMPLETE_INT_ENABLE_BIT CONCAT(CHIP_USART_, ID, _RX_COMPLETE_INT_ENABLE_BIT)
#define TX_COMPLETE_INT_ENABLE_REG CONCAT(CHIP_USART_, ID, _TX_COMPLETE_INT_ENABLE_REG)
#define TX_COMPLETE_INT_ENABLE_BIT CONCAT(CHIP_USART_, ID, _TX_COMPLETE_INT_ENABLE_BIT)
#define DATA_REG_EMPTY_INT_ENABLE_REG CONCAT(CHIP_USART_, ID, _DATA_REG_EMPTY_INT_ENABLE_REG)
#define DATA_REG_EMPTY_INT_ENABLE_BIT CONCAT(CHIP_USART_, ID, _DATA_REG_EMPTY_INT_ENABLE_BIT)

#define RX_ENABLE_REG CONCAT(CHIP_USART_, ID, _RX_ENABLE_REG)
#define RX_ENABLE_BIT CONCAT(CHIP_USART_, ID, _RX_ENABLE_BIT)
#define TX_ENABLE_REG CONCAT(CHIP_USART_, ID, _TX_ENABLE_REG)
#define TX_ENABLE_BIT CONCAT(CHIP_USART_, ID, _TX_ENABLE_BIT)

#define FRAME_ERROR_REG CONCAT(CHIP_USART_, ID, _FRAME_ERROR_REG)
#define FRAME_ERROR_BIT CONCAT(CHIP_USART_, ID, _FRAME_ERROR_BIT)

#define DATA_OVERRUN_REG CONCAT(CHIP_USART_, ID, _DATA_OVERRUN_REG)
#define DATA_OVERRUN_BIT CONCAT(CHIP_USART_, ID, _DATA_OVERRUN_BIT)

#define USART_REG_SELECT_REG CONCAT(CHIP_USART_, ID, _USART_REG_SELECT_REG)
#define USART_REG_SELECT_BIT CONCAT(CHIP_USART_, ID, _USART_REG_SELECT_BIT)

#define RX_COMPLETE_INTERRUPT CONCAT(_usart, ID, RxCompleteInterrupt)
#define RX_COMPLETE_INTERRUPT_DATA CONCAT(_usart, ID, RxCompleteInterruptData)
#define TX_COMPLETE_INTERRUPT CONCAT(_usart, ID, TxCompleteInterrupt)
#define TX_COMPLETE_INTERRUPT_DATA CONCAT(_usart, ID, TxCompleteInterruptData)
#define DATA_REGISTER_EMPTY_INTERRUPT CONCAT(_usart, ID, DataRegisterEmptyInterrupt)
#define DATA_REGISTER_EMPTY_INTERRUPT_DATA CONCAT(_usart, ID, DataRegisterEmptyInterruptData)

struct UsartN {
    UsartN() = delete;

    static constexpr HardwareType getHardwareType() {
        return HardwareType::Usart;
    }

    enum class Mode : uint8_t {
        Asynchronous = MODE_ASYNCHRONOUS_ID,
        Synchronous = MODE_SYNCHRONOUS_ID,
        #if MODE_MASTER_SPI_ID
        MasterSpi = MODE_MASTER_SPI_ID,
        #endif
    };

    enum class Parity : uint8_t {
        Disabled = PARITY_DISABLE_ID,
        Even = PARITY_EVEN_ID,
        Odd = PARITY_ODD_ID,
    };

    enum class StopBits : uint8_t {
        Bits1 = STOP_BITS_1_ID,
        Bits2 = STOP_BITS_2_ID,
    };

    enum class CharacterSize : uint8_t {
        Size5 = CHARACTER_SIZE_5_ID,
        Size6 = CHARACTER_SIZE_6_ID,
        Size7 = CHARACTER_SIZE_7_ID,
        Size8 = CHARACTER_SIZE_8_ID,
        Size9 = CHARACTER_SIZE_9_ID,
    };

    enum class ClockPolarity : uint8_t {
        TxRisingRxFalling = CLOCK_POLARITY_TX_RISING_RX_FALLING_ID,
        TxFallingRxRising = CLOCK_POLARITY_TX_FALLING_RX_RISING_ID,
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

    static force_inline void apply(Config config) {
        atomic {
            setBit_(DOUBLE_SPEED_REG, DOUBLE_SPEED_BIT, config.use2X);

            setBit_(MULTI_PROCESSOR_COMMUNICATION_REG, MULTI_PROCESSOR_COMMUNICATION_BIT, config.multiprocessorCummunicationMode);

            setBit_(RX_COMPLETE_INT_ENABLE_REG, RX_COMPLETE_INT_ENABLE_BIT, config.rxCompleteIntEnable);
            setBit_(TX_COMPLETE_INT_ENABLE_REG, TX_COMPLETE_INT_ENABLE_BIT, config.txCompleteIntEnable);
            setBit_(DATA_REG_EMPTY_INT_ENABLE_REG, DATA_REG_EMPTY_INT_ENABLE_BIT, config.dataRegisterEmptyIntEnable);

            setBit_(RX_ENABLE_REG, RX_ENABLE_BIT, config.receiverEnable);
            setBit_(TX_ENABLE_REG, TX_ENABLE_BIT, config.transmitterEnable);

            setBit_(CHARACTER_SIZE_BIT_0_REG, CHARACTER_SIZE_BIT_0_BIT, uint8_t(config.characterSize) & 0x01);
            setBit_(CHARACTER_SIZE_BIT_1_REG, CHARACTER_SIZE_BIT_1_BIT, uint8_t(config.characterSize) & 0x02);
            setBit_(CHARACTER_SIZE_BIT_2_REG, CHARACTER_SIZE_BIT_2_BIT, uint8_t(config.characterSize) & 0x04);

            setBit_(MODE_BIT_0_REG, MODE_BIT_0_BIT, uint8_t(config.mode) & 0x01);
            #if MODE_BIT_COUNT > 1
            setBit_(MODE_BIT_1_REG, MODE_BIT_1_BIT, uint8_t(config.mode) & 0x02);
            #endif

            setBit_(PARITY_BIT_0_REG, PARITY_BIT_0_BIT, uint8_t(config.parity) & 0x01);
            setBit_(PARITY_BIT_1_REG, PARITY_BIT_1_BIT, uint8_t(config.parity) & 0x02);

            setBit_(STOP_BITS_REG, STOP_BITS_BIT, config.stopBits == StopBits::Bits2);

            setBit_(CLOCK_POLARITY_REG, CLOCK_POLARITY_BIT, config.clockPolarity == ClockPolarity::TxFallingRxRising);

            setBit_(FRAME_ERROR_REG, FRAME_ERROR_BIT, false);
            setBit_(DATA_OVERRUN_REG, DATA_OVERRUN_BIT, false);
            setBit_(PARITY_ERROR_REG, PARITY_ERROR_BIT, false);

            #if USART_REG_SELECT
            setBit_(USART_REG_SELECT_REG, USART_REG_SELECT_BIT, true);
            _MemoryBarrier();
            #endif

            *BAUD_RATE_REG_HIGH = config.baud >> 8;
            *BAUD_RATE_REG_LOW = config.baud;

            RX_COMPLETE_INTERRUPT = config.rxCompleteInterrupt;
            RX_COMPLETE_INTERRUPT_DATA = config.rxCompleteInterruptData;

            TX_COMPLETE_INTERRUPT = config.txCompleteInterrupt;
            TX_COMPLETE_INTERRUPT_DATA = config.txCompleteInterruptData;

            DATA_REGISTER_EMPTY_INTERRUPT = config.dataRegisterEmptyInterrupt;
            DATA_REGISTER_EMPTY_INTERRUPT_DATA = config.dataRegisterEmptyInterruptData;
        }
    }

    static force_inline void push(uint8_t b) {
        *DATA_REG = b;
    }

    static force_inline void push9(uint16_t b) {
        if(b & 0x0100) {
            *TX_DATA_BIT_8_REG |= _BV(TX_DATA_BIT_8_BIT);
        } else {
            *TX_DATA_BIT_8_REG &= ~_BV(TX_DATA_BIT_8_BIT);
        }

        *DATA_REG = b;
    }

    static force_inline uint8_t pop() {
        return *DATA_REG;
    }

    static force_inline uint16_t pop9() {
        uint8_t bit8 = *RX_DATA_BIT_8_REG & _BV(RX_DATA_BIT_8_BIT);
        uint8_t result = *DATA_REG;

        if(bit8) {
            result |= 0x0100;
        }

        return result;
    }

    static force_inline bool frameError() {
        bool result = *FRAME_ERROR_REG & _BV(FRAME_ERROR_BIT);

        *FRAME_ERROR_REG &= ~_BV(FRAME_ERROR_BIT);

        return result;
    }

    static force_inline bool dataOverRun() {
        bool result = *DATA_OVERRUN_REG & _BV(DATA_OVERRUN_BIT);

        *DATA_OVERRUN_REG &= ~_BV(DATA_OVERRUN_BIT);

        return result;
    }

    static force_inline bool parityError() {
        bool result = *PARITY_ERROR_REG & _BV(PARITY_ERROR_BIT);

        *PARITY_ERROR_REG &= ~_BV(PARITY_ERROR_BIT);

        return result;
    }

    static force_inline void rxCompleteInterruptEnable(bool b) {
        if(b) {
            *RX_COMPLETE_INT_ENABLE_REG |= _BV(RX_COMPLETE_INT_ENABLE_BIT);
        } else {
            *RX_COMPLETE_INT_ENABLE_REG &= ~_BV(RX_COMPLETE_INT_ENABLE_BIT);
        }
    }

    static force_inline void txCompleteInterruptEnable(bool b) {
        if(b) {
            *TX_COMPLETE_INT_ENABLE_REG |= _BV(TX_COMPLETE_INT_ENABLE_BIT);
        } else {
            *TX_COMPLETE_INT_ENABLE_REG &= ~_BV(TX_COMPLETE_INT_ENABLE_BIT);
        }
    }

    static force_inline void dataRegisterEmptyInterruptEnable(bool b) {
        if(b) {
            *DATA_REG_EMPTY_INT_ENABLE_REG |= _BV(DATA_REG_EMPTY_INT_ENABLE_BIT);
        } else {
            *DATA_REG_EMPTY_INT_ENABLE_REG &= ~_BV(DATA_REG_EMPTY_INT_ENABLE_BIT);
        }
    }

    static force_inline void receiverEnable(bool b) {
        if(b) {
            *RX_ENABLE_REG |= _BV(RX_ENABLE_BIT);
        } else {
            *RX_ENABLE_REG &= ~_BV(RX_ENABLE_BIT);
        }
    }

    static force_inline void transmitterEnable(bool b) {
        if(b) {
            *TX_ENABLE_REG |= _BV(TX_ENABLE_BIT);
        } else {
            *TX_ENABLE_REG &= ~_BV(TX_ENABLE_BIT);
        }
    }
};

#undef UsartN

#undef MODE_ASYNCHRONOUS_ID
#undef MODE_SYNCHRONOUS_ID
#undef MODE_MASTER_SPI_ID

#undef MODE_BIT_0_REG
#undef MODE_BIT_0_BIT
#undef MODE_BIT_1_REG
#undef MODE_BIT_1_BIT

#undef PARITY_DISABLE_ID
#undef PARITY_EVEN_ID
#undef PARITY_ODD_ID

#undef PARITY_BIT_0_REG
#undef PARITY_BIT_0_BIT
#undef PARITY_BIT_1_REG
#undef PARITY_BIT_1_BIT

#undef PARITY_ERROR_REG
#undef PARITY_ERROR_BIT

#undef STOP_BITS_1_ID
#undef STOP_BITS_2_ID

#undef STOP_BITS_REG
#undef STOP_BITS_BIT

#undef CHARACTER_SIZE_5_ID
#undef CHARACTER_SIZE_6_ID
#undef CHARACTER_SIZE_7_ID
#undef CHARACTER_SIZE_8_ID
#undef CHARACTER_SIZE_9_ID

#undef CHARACTER_SIZE_BIT_0_REG
#undef CHARACTER_SIZE_BIT_1_REG
#undef CHARACTER_SIZE_BIT_2_REG

#undef CHARACTER_SIZE_BIT_0_BIT
#undef CHARACTER_SIZE_BIT_1_BIT
#undef CHARACTER_SIZE_BIT_2_BIT

#undef CLOCK_POLARITY_TX_RISING_RX_FALLING_ID
#undef CLOCK_POLARITY_TX_FALLING_RX_RISING_ID

#undef CLOCK_POLARITY_REG
#undef CLOCK_POLARITY_BIT

#undef DATA_REG
#undef TX_DATA_BIT_8_REG
#undef TX_DATA_BIT_8_BIT
#undef RX_DATA_BIT_8_REG
#undef RX_DATA_BIT_8_BIT

#undef BAUD_RATE_REG_HIGH
#undef BAUD_RATE_REG_LOW

#undef DOUBLE_SPEED_REG
#undef DOUBLE_SPEED_BIT

#undef MULTI_PROCESSOR_COMMUNICATION_REG
#undef MULTI_PROCESSOR_COMMUNICATION_BIT

#undef RX_COMPLETE_INT_ENABLE_REG
#undef RX_COMPLETE_INT_ENABLE_BIT
#undef TX_COMPLETE_INT_ENABLE_REG
#undef TX_COMPLETE_INT_ENABLE_BIT
#undef DATA_REG_EMPTY_INT_ENABLE_REG
#undef DATA_REG_EMPTY_INT_ENABLE_BIT

#undef RX_ENABLE_REG
#undef RX_ENABLE_BIT
#undef TX_ENABLE_REG
#undef TX_ENABLE_BIT

#undef FRAME_ERROR_REG
#undef FRAME_ERROR_BIT

#undef DATA_OVERRUN_REG
#undef DATA_OVERRUN_BIT

#undef USART_REG_SELECT_REG
#undef USART_REG_SELECT_BIT

#undef RX_COMPLETE_INTERRUPT
#undef RX_COMPLETE_INTERRUPT_DATA
#undef TX_COMPLETE_INTERRUPT
#undef TX_COMPLETE_INTERRUPT_DATA
#undef DATA_REGISTER_EMPTY_INTERRUPT
#undef DATA_REGISTER_EMPTY_INTERRUPT_DATA

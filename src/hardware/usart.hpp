/// # USARTs

/// N is the usart id (1, 2, etc).

/// ## Example

/// ```c++
/// // TODO
/// ```

#ifndef NBAVR_USART_HPP

#ifndef N
    // USART id.
    #define N 0
#endif

#if N < CHIP_USART_COUNT
    // If this hardware exists.
    #if CONCAT(CHIP_USART_, N)

//--------------------------------------------------------

#define UsartN CONCAT(Usart,N)
#define C(X) CONCAT(CHIP_USART_, N, _, X)
#define _C(X) UNDERLINE(USART, N, X)

MAKE_CALLBACK_HEADER(USART, N, RX);
MAKE_CALLBACK_HEADER(USART, N, TX);
MAKE_CALLBACK_HEADER(USART, N, DE);

/// #### macro INCLUDE_USART_CALLBACK(N, X)
/// Include this to use Usart callbacks.<br>
/// N is the Usart id, and X is one of RX (receive complete), TX (transmit
/// complete), or DE (data register empty).
#define INCLUDE_USART_CALLBACK(N, X) MAKE_CALLBACK(USART, N, X)

/// ## class UsartN
struct UsartN {
    UsartN() = delete;

    /// #### enum Mode
    /// * Asynchronous
    /// * Synchronous
    /// * MasterSpi
    enum class Mode : uint8_t {
        Asynchronous = C(MODE_ASYNCHRONOUS_ID),
        Synchronous = C(MODE_SYNCHRONOUS_ID),
        #if C(MODE_MASTER_SPI_ID)
        MasterSpi = C(MODE_MASTER_SPI_ID),
        #endif
    };

    /// #### enum Parity
    /// * Disabled
    /// * Even
    /// * Odd
    enum class Parity : uint8_t {
        Disabled = C(PARITY_DISABLE_ID),
        Even = C(PARITY_EVEN_ID),
        Odd = C(PARITY_ODD_ID),
    };

    /// #### enum StopBits
    /// * Bits1
    /// * Bits2
    enum class StopBits : uint8_t {
        Bits1 = C(STOP_BITS_1_ID),
        Bits2 = C(STOP_BITS_2_ID),
    };

    /// #### enum CharacterSize
    /// * Size5
    /// * Size6
    /// * Size7
    /// * Size8
    /// * Size9
    enum class CharacterSize : uint8_t {
        Size5 = C(CHARACTER_SIZE_5_ID),
        Size6 = C(CHARACTER_SIZE_6_ID),
        Size7 = C(CHARACTER_SIZE_7_ID),
        Size8 = C(CHARACTER_SIZE_8_ID),
        Size9 = C(CHARACTER_SIZE_9_ID),
    };

    /// #### enum Polarity
    /// * TxRisingRxFalling
    /// * TxFallingRxRising
    enum class Polarity : uint8_t {
        TxRisingRxFalling = C(CLOCK_POLARITY_TX_RISING_RX_FALLING_ID),
        TxFallingRxRising = C(CLOCK_POLARITY_TX_FALLING_RX_RISING_ID),
    };

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::Usart;
    }

    /// #### static void mode(Mode m)
    /// Set USART mode.
    static force_inline void mode(Mode m) {
        #if DEFINED(C(USART_REG_SELECT_BIT))
            setBit_(C(USART_REG_SELECT_REG), C(USART_REG_SELECT_BIT), true);
        #endif

        setBit_(C(MODE_BIT_0_REG), C(MODE_BIT_0_BIT), uint8_t(m) & 0x01);

        #if DEFINED(C(MODE_BIT_1_BIT))
            setBit_(C(MODE_BIT_1_REG), C(MODE_BIT_1_BIT), uint8_t(m) & 0x02);
        #endif
    }

    /// #### static void parity(Parity p)
    /// Set USART parity.
    static force_inline void parity(Parity p) {
        #if DEFINED(C(USART_REG_SELECT_BIT))
            setBit_(C(USART_REG_SELECT_REG), C(USART_REG_SELECT_BIT), true);
        #endif

        setBit_(C(PARITY_BIT_0_REG), C(PARITY_BIT_0_BIT), uint8_t(p) & 0x01);
        setBit_(C(PARITY_BIT_1_REG), C(PARITY_BIT_1_BIT), uint8_t(p) & 0x02);
    }

    /// #### static void stopBits(StopBits b)
    /// Set number of stop bits.
    static force_inline void stopBits(StopBits b) {
        #if DEFINED(C(USART_REG_SELECT_BIT))
            setBit_(C(USART_REG_SELECT_REG), C(USART_REG_SELECT_BIT), true);
        #endif

        setBit_(C(STOP_BITS_REG), C(STOP_BITS_BIT), bool(b));
    }

    /// #### static void characterSize(CharacterSize s)
    /// Set USART character size.
    static force_inline void characterSize(CharacterSize s) {
        #if DEFINED(C(USART_REG_SELECT_BIT))
            setBit_(C(USART_REG_SELECT_REG), C(USART_REG_SELECT_BIT), true);
        #endif

        setBit_(C(CHARACTER_SIZE_BIT_0_REG), C(CHARACTER_SIZE_BIT_0_BIT), uint8_t(s) & 0x01);
        setBit_(C(CHARACTER_SIZE_BIT_1_REG), C(CHARACTER_SIZE_BIT_1_BIT), uint8_t(s) & 0x02);
        setBit_(C(CHARACTER_SIZE_BIT_2_REG), C(CHARACTER_SIZE_BIT_2_BIT), uint8_t(s) & 0x04);
    }

    /// #### static void polarity(Polarity p)
    /// Set USART clock polarity.
    static force_inline void polarity(Polarity p) {
        #if DEFINED(C(USART_REG_SELECT_BIT))
            setBit_(C(USART_REG_SELECT_REG), C(USART_REG_SELECT_BIT), true);
        #endif

        setBit_(C(CLOCK_POLARITY_REG), C(CLOCK_POLARITY_BIT), p == Polarity::TxFallingRxRising);
    }

    /// #### static void baud(uint16_t b)
    /// Set USART baud rate.
    static force_inline void baud(uint16_t b) {
        b &= 0x0fff;

        #if C(BAUD_RATE_REG_SPLIT)
            *C(BAUD_RATE_REG_HIGH) = b >> 8;
            *C(BAUD_RATE_REG_LOW) = b;
        #else
            *C(BAUD_RATE_REG) = b;
        #endif
    }

    /// #### static void use2X(bool u)
    /// Enable/disable baud rate 2x speed.
    static force_inline void use2X(bool u) {
        setBit_(C(DOUBLE_SPEED_REG), C(DOUBLE_SPEED_BIT), u);
    }

    /// #### static void receiverEnable(bool e)
    /// Enable/disable receiver.
    static force_inline void receiverEnable(bool e) {
        setBit_(C(RX_ENABLE_REG), C(RX_ENABLE_BIT), e);
    }

    /// #### static void transmitterEnable(bool e)
    /// Enable/disable transmitter.
    static force_inline void transmitterEnable(bool e) {
        setBit_(C(TX_ENABLE_REG), C(TX_ENABLE_BIT), e);
    }

    /// #### static void multiprocessorCummunicationMode(bool e)
    /// Enable/disable multiprocessor cummunication mode.
    static force_inline void multiprocessorCummunicationMode(bool e) {
        setBit_(C(MULTI_PROCESSOR_COMMUNICATION_REG), C(MULTI_PROCESSOR_COMMUNICATION_BIT), e);
    }

    /// #### static void rxCompleteIntEnable(bool e)
    /// Enable/disable receive complete interrupt.
    static force_inline void rxCompleteIntEnable(bool e) {
        setBit_(C(RX_COMPLETE_INT_ENABLE_REG), C(RX_COMPLETE_INT_ENABLE_BIT), e);
    }

    /// #### static void txCompleteIntEnable(bool e)
    /// Enable/disable transmit complete interrupt.
    static force_inline void txCompleteIntEnable(bool e) {
        setBit_(C(TX_COMPLETE_INT_ENABLE_REG), C(TX_COMPLETE_INT_ENABLE_BIT), e);
    }

    /// #### static void dataRegisterEmptyIntEnable(bool e)
    /// Enable/disable data register empty interrupt.
    static force_inline void dataRegisterEmptyIntEnable(bool e) {
        setBit_(C(DATA_REG_EMPTY_INT_ENABLE_REG), C(DATA_REG_EMPTY_INT_ENABLE_BIT), e);
    }

    /// #### static void rxCompleteCallback(callback_t callback, void\* data)
    /// Set callback for receive complete interrupt.
    static force_inline void rxCompleteCallback(callback_t callback, void* data) {
        _C(RX_Callback) = callback;
        _C(RX_CallbackData) = data;
    }

    /// #### static void txCompleteCallback(callback_t callback, void\* data)
    /// Set callback for transmit complete interrupt.
    static force_inline void txCompleteCallback(callback_t callback, void* data) {
        _C(TX_Callback) = callback;
        _C(TX_CallbackData) = data;
    }

    /// #### static void dataRegisterEmptyCallback(callback_t callback, void\* data)
    /// Set callback for data register empty interrupt.
    static force_inline void dataRegisterEmptyCallback(callback_t callback, void* data) {
        _C(DE_Callback) = callback;
        _C(DE_CallbackData) = data;
    }

    /// #### static void push(uint8_t b)
    /// Send a byte.
    static force_inline void push(uint8_t b) {
        *C(DATA_REG) = b;
    }

    /// #### static void push9(uint16_t b)
    /// Send a 9 bit byte.
    static force_inline void push9(uint16_t b) {
        setBit_(C(TX_DATA_BIT_8_REG), C(TX_DATA_BIT_8_BIT), b & 0x0100);

        *C(DATA_REG) = b;
    }

    /// #### static uint8_t pop()
    /// Get the last received byte.
    static force_inline uint8_t pop() {
        return *C(DATA_REG);
    }

    /// #### static uint16_t pop9()
    /// Get the last received 9 bit byte.
    static force_inline uint16_t pop9() {
        uint16_t result = *C(DATA_REG);

        if(*C(RX_DATA_BIT_8_REG) & bv(C(RX_DATA_BIT_8_BIT))) {
            result |= 0x0100;
        }

        return result;
    }

    /// #### static bool frameError()
    /// Returns true if there was a frame error.
    static force_inline bool frameError() {
        return *C(FRAME_ERROR_REG) & bv(C(FRAME_ERROR_BIT));
    }

    /// #### static void frameErrorClear()
    /// Clear the frame error flag.
    static force_inline void frameErrorClear() {
        setBit_(C(FRAME_ERROR_REG), C(FRAME_ERROR_BIT), false);
    }

    /// #### static bool dataOverRun()
    /// Returns true if there was a data over run.
    static force_inline bool dataOverRun() {
        return *C(DATA_OVERRUN_REG) & bv(C(DATA_OVERRUN_BIT));
    }

    /// #### static void dataOverRunClear()
    /// Clear the data over run flag.
    static force_inline void dataOverRunClear() {
        setBit_(C(DATA_OVERRUN_REG), C(DATA_OVERRUN_BIT), false);
    }

    /// #### static bool parityError()
    /// Returns true if there was a parity error.
    static force_inline bool parityError() {
        return *C(PARITY_ERROR_REG) & bv(C(PARITY_ERROR_BIT));
    }

    /// #### static void parityErrorClear()
    /// Clear the parity error flag.
    static force_inline void parityErrorClear() {
        setBit_(C(PARITY_ERROR_REG), C(PARITY_ERROR_BIT), false);
    }
};

#undef UsartN
#undef C
#undef _C

//--------------------------------------------------------

    #endif // CONCAT(CHIP_USART_, N)

    #include "incn.hpp"

    #include "usart.hpp"

#else // N < CHIP_USART_COUNT

    #undef N

    #define NBAVR_USART_HPP

#endif // N < CHIP_USART_COUNT

#endif

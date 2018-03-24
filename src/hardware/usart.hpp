/// # USARTs

/// N is the usart id (1, 2, etc).

/// ## Example

/// ```c++
/// // TODO
/// ```

#ifndef NBOS_USART_HPP

#include "callbacks.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "type.hpp"
#include "system.hpp"

/// #### macro INCLUDE_USART_CALLBACK(N, X)
/// Include this to use Usart callbacks.<br>
/// N is the Usart id, and X is one of RX (receive complete), TX (transmit
/// complete), or DE (data register empty).
#define INCLUDE_USART_CALLBACK(N, X) MAKE_CALLBACK(USART, N, X)

#include "loopi"

#ifdef _I
    #define N _I
    #define UsartN CAT(Usart,N)
    #define USART_N(A) CAT(CHIP_USART_, N, _, A)
    #define _USART_N(A) UNDERLINE(USART, N, A)

    #if CAT(CHIP_USART_, N)

//------------------------------------------------------------------

namespace nbos::hw {

MAKE_CALLBACK_HEADER(USART, N, RX);
MAKE_CALLBACK_HEADER(USART, N, TX);
MAKE_CALLBACK_HEADER(USART, N, DE);

/// ## class UsartN
struct UsartN {
    UsartN() = delete;
    UsartN& operator=(const UsartN&) = delete;
    UsartN(const UsartN&) = delete;

    #if DEFINED(USART_N(MODE_BIT_0_BIT))
        /// #### enum Mode
        /// * asynchronous
        /// * synchronous
        /// * masterSpi
        enum class Mode : uint8_t {
            asynchronous = USART_N(MODE_ASYNCHRONOUS_ID),
            synchronous = USART_N(MODE_SYNCHRONOUS_ID),
            #if USART_N(MODE_MASTER_SPI_ID)
            masterSpi = USART_N(MODE_MASTER_SPI_ID),
            #endif
        };
    #endif

    #if DEFINED(USART_N(PARITY_BIT_0_BIT))
        /// #### enum Parity
        /// * disabled
        /// * even
        /// * odd
        enum class Parity : uint8_t {
            disabled = USART_N(PARITY_DISABLE_ID),
            even = USART_N(PARITY_EVEN_ID),
            odd = USART_N(PARITY_ODD_ID),
        };
    #endif

    #if DEFINED(USART_N(STOP_BITS_BIT_0_BIT))
        /// #### enum StopBits
        /// * bits1
        /// * bits2
        enum class StopBits : uint8_t {
            bits1 = USART_N(STOP_BITS_1_ID),
            bits2 = USART_N(STOP_BITS_2_ID),
        };
    #endif

    #if DEFINED(USART_N(CHARACTER_SIZE_BIT_0_BIT))
        /// #### enum CharacterSize
        /// * size5
        /// * size6
        /// * size7
        /// * size8
        /// * size9
        enum class CharacterSize : uint8_t {
            size5 = USART_N(CHARACTER_SIZE_5_ID),
            size6 = USART_N(CHARACTER_SIZE_6_ID),
            size7 = USART_N(CHARACTER_SIZE_7_ID),
            size8 = USART_N(CHARACTER_SIZE_8_ID),
            size9 = USART_N(CHARACTER_SIZE_9_ID),
        };
    #endif

    #if DEFINED(USART_N(POLARITY_BIT_0_BIT))
        /// #### enum Polarity
        /// * txRisingRxFalling
        /// * txFallingRxRising
        enum class Polarity : uint8_t {
            txRisingRxFalling = USART_N(POLARITY_TX_RISING_RX_FALLING_ID),
            txFallingRxRising = USART_N(POLARITY_TX_FALLING_RX_RISING_ID),
        };
    #endif

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::usart;
    }

    #if DEFINED(USART_N(MODE_BIT_0_BIT))
        /// #### static void mode(Mode m)
        /// Set USART mode.
        static force_inline void mode(Mode m) {
            // #if DEFINED(USART_N(USART_REG_SELECT_BIT))
            //     setBit_(REG(USART_N(USART_REG_SELECT_REG)), USART_N(USART_REG_SELECT_BIT), true);
            // #endif

            setBit_(REG(USART_N(MODE_BIT_0_REG)), USART_N(MODE_BIT_0_BIT), uint8_t(m) & 0x01);

            #if DEFINED(USART_N(MODE_BIT_1_BIT))
                setBit_(REG(USART_N(MODE_BIT_1_REG)), USART_N(MODE_BIT_1_BIT), uint8_t(m) & 0x02);
            #endif

            #if DEFINED(USART_N(MODE_BIT_2_BIT))
                setBit_(REG(USART_N(MODE_BIT_2_REG)), USART_N(MODE_BIT_2_BIT), uint8_t(m) & 0x04);
            #endif
        }
    #endif

    #if DEFINED(USART_N(PARITY_BIT_0_BIT))
        /// #### static void parity(Parity p)
        /// Set USART parity.
        static force_inline void parity(Parity p) {
            setBit_(REG(USART_N(PARITY_BIT_0_REG)), USART_N(PARITY_BIT_0_BIT), uint8_t(p) & 0x01);

            #if DEFINED(USART_N(PARITY_BIT_1_BIT))
                setBit_(REG(USART_N(PARITY_BIT_1_REG)), USART_N(PARITY_BIT_1_BIT), uint8_t(p) & 0x02);
            #endif

            #if DEFINED(USART_N(PARITY_BIT_2_BIT))
                setBit_(REG(USART_N(PARITY_BIT_2_REG)), USART_N(PARITY_BIT_2_BIT), uint8_t(p) & 0x04);
            #endif
        }
    #endif

    #if DEFINED(USART_N(STOP_BITS_BIT_0_BIT))
        /// #### static void stopBits(StopBits b)
        /// Set number of stop bits.
        static force_inline void stopBits(StopBits b) {
            // #if DEFINED(USART_N(USART_REG_SELECT_BIT))
            //     setBit_(REG(USART_N(USART_REG_SELECT_REG)), USART_N(USART_REG_SELECT_BIT), true);
            // #endif

            setBit_(REG(USART_N(STOP_BITS_BIT_0_REG)), USART_N(STOP_BITS_BIT_0_BIT), uint8_t(b) & 0x01);

            #if DEFINED(USART_N(STOP_BITS_BIT_1_BIT))
                setBit_(REG(USART_N(STOP_BITS_BIT_1_REG)), USART_N(STOP_BITS_BIT_1_BIT), uint8_t(b) & 0x02);
            #endif
        }
    #endif

    #if DEFINED(USART_N(CHARACTER_SIZE_BIT_0_BIT))
        /// #### static void characterSize(CharacterSize s)
        /// Set USART character size.
        static force_inline void characterSize(CharacterSize s) {
            setBit_(REG(USART_N(CHARACTER_SIZE_BIT_0_REG)), USART_N(CHARACTER_SIZE_BIT_0_BIT), uint8_t(s) & 0x01);

            #if DEFINED(USART_N(CHARACTER_SIZE_BIT_1_BIT))
                setBit_(REG(USART_N(CHARACTER_SIZE_BIT_1_REG)), USART_N(CHARACTER_SIZE_BIT_1_BIT), uint8_t(s) & 0x02);
            #endif

            #if DEFINED(USART_N(CHARACTER_SIZE_BIT_2_BIT))
                setBit_(REG(USART_N(CHARACTER_SIZE_BIT_2_REG)), USART_N(CHARACTER_SIZE_BIT_2_BIT), uint8_t(s) & 0x04);
            #endif

            #if DEFINED(USART_N(CHARACTER_SIZE_BIT_3_BIT))
                setBit_(REG(USART_N(CHARACTER_SIZE_BIT_3_REG)), USART_N(CHARACTER_SIZE_BIT_3_BIT), uint8_t(s) & 0x08);
            #endif
        }
    #endif

    #if DEFINED(USART_N(POLARITY_BIT_0_BIT))
        /// #### static void polarity(Polarity p)
        /// Set USART clock polarity.
        static force_inline void polarity(Polarity p) {
            setBit_(REG(USART_N(POLARITY_BIT_0_REG)), USART_N(POLARITY_BIT_0_BIT), uint8_t(p) & 0x01);

            #if DEFINED(USART_N(POLARITY_BIT_1_BIT))
                setBit_(REG(USART_N(POLARITY_BIT_1_REG)), USART_N(POLARITY_BIT_1_BIT), uint8_t(p) & 0x02);
            #endif
        }
    #endif

    /// #### static void baud(uint16_t b)
    /// Set USART baud rate.
    static force_inline void baud(uint16_t b) {
        b &= 0x0fff;

        #if CAT(USART_N(BAUD_RATE_REG), _ADDR)
            *REG(USART_N(BAUD_RATE_REG)) = b;
        #else
            *REG(USART_N(BAUD_RATE_REG_HIGH)) = b >> 8;
            *REG(USART_N(BAUD_RATE_REG_LOW)) = b;
        #endif
    }

    #if DEFINED(USART_N(DOUBLE_SPEED_BIT_0_BIT))
        /// #### static void use2X(bool u)
        /// Enable/disable baud rate 2x speed.
        static force_inline void use2X(bool u) {
            setBit_(REG(USART_N(DOUBLE_SPEED_BIT_0_REG)), USART_N(DOUBLE_SPEED_BIT_0_BIT), u);
        }
    #endif

    #if DEFINED(USART_N(RX_ENABLE_BIT_0_BIT))
        /// #### static void receiverEnable(bool e)
        /// Enable/disable receiver.
        static force_inline void receiverEnable(bool e) {
            setBit_(REG(USART_N(RX_ENABLE_BIT_0_REG)), USART_N(RX_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(TX_ENABLE_BIT_0_BIT))
        /// #### static void transmitterEnable(bool e)
        /// Enable/disable transmitter.
        static force_inline void transmitterEnable(bool e) {
            setBit_(REG(USART_N(TX_ENABLE_BIT_0_REG)), USART_N(TX_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT))
        /// #### static void multiprocessorCummunicationMode(bool e)
        /// Enable/disable multiprocessor cummunication mode.
        static force_inline void multiprocessorCummunicationMode(bool e) {
            setBit_(REG(USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT_0_REG)), USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(RX_COMPLETE_INT_ENABLE_BIT_0_BIT))
        /// #### static void rxCompleteIntEnable(bool e)
        /// Enable/disable receive complete interrupt.
        static force_inline void rxCompleteIntEnable(bool e) {
            setBit_(REG(USART_N(RX_COMPLETE_INT_ENABLE_BIT_0_REG)), USART_N(RX_COMPLETE_INT_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(TX_COMPLETE_INT_ENABLE_BIT_0_BIT))
        /// #### static void txCompleteIntEnable(bool e)
        /// Enable/disable transmit complete interrupt.
        static force_inline void txCompleteIntEnable(bool e) {
            setBit_(REG(USART_N(TX_COMPLETE_INT_ENABLE_BIT_0_REG)), USART_N(TX_COMPLETE_INT_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT))
        /// #### static void dataRegisterEmptyIntEnable(bool e)
        /// Enable/disable data register empty interrupt.
        static force_inline void dataRegisterEmptyIntEnable(bool e) {
            setBit_(REG(USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT_0_REG)), USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT), e);
        }
    #endif

    /// #### static void rxCompleteCallback(callback_t callback, void\* data)
    /// Set callback for receive complete interrupt.
    static force_inline void rxCompleteCallback(callback_t callback, void* data) {
        _USART_N(RX_Callback) = callback;
        _USART_N(RX_CallbackData) = data;
    }

    /// #### static void txCompleteCallback(callback_t callback, void\* data)
    /// Set callback for transmit complete interrupt.
    static force_inline void txCompleteCallback(callback_t callback, void* data) {
        _USART_N(TX_Callback) = callback;
        _USART_N(TX_CallbackData) = data;
    }

    /// #### static void dataRegisterEmptyCallback(callback_t callback, void\* data)
    /// Set callback for data register empty interrupt.
    static force_inline void dataRegisterEmptyCallback(callback_t callback, void* data) {
        _USART_N(DE_Callback) = callback;
        _USART_N(DE_CallbackData) = data;
    }

    /// #### static void push(uint8_t b)
    /// Send a byte.
    static force_inline void push(uint8_t b) {
        *REG(USART_N(DATA_REG)) = b;
    }

    #if DEFINED(USART_N(TX_DATA_BIT_8_BIT))
        /// #### static void push9(uint16_t b)
        /// Send a 9 bit byte.
        static force_inline void push9(uint16_t b) {
            setBit_(REG(USART_N(TX_DATA_BIT_8_REG)), USART_N(TX_DATA_BIT_8_BIT), b & 0x0100);

            *REG(USART_N(DATA_REG)) = b;
        }
    #endif

    /// #### static uint8_t pop()
    /// Get the last received byte.
    static force_inline uint8_t pop() {
        return *REG(USART_N(DATA_REG));
    }

    #if DEFINED(USART_N(RX_DATA_BIT_8_BIT))
        /// #### static uint16_t pop9()
        /// Get the last received 9 bit byte.
        static force_inline uint16_t pop9() {
            uint16_t result = *REG(USART_N(DATA_REG));

            if(*REG(USART_N(RX_DATA_BIT_8_REG)) & bv(USART_N(RX_DATA_BIT_8_BIT))) {
                result |= 0x0100;
            }

            return result;
        }
    #endif

    #if DEFINED(USART_N(FRAME_ERROR_BIT_0_BIT))
        /// #### static bool frameError()
        /// Returns true if there was a frame error.
        static force_inline bool frameError() {
            return *REG(USART_N(FRAME_ERROR_BIT_0_REG)) & bv(USART_N(FRAME_ERROR_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USART_N(FRAME_ERROR_BIT_0_BIT))
        /// #### static void frameErrorClear()
        /// Clear the frame error flag.
        static force_inline void frameErrorClear() {
            setBit_(REG(USART_N(FRAME_ERROR_BIT_0_REG)), USART_N(FRAME_ERROR_BIT_0_BIT), false);
        }
    #endif

    #if DEFINED(USART_N(DATA_OVERRUN_BIT_0_BIT))
        /// #### static bool dataOverRun()
        /// Returns true if there was a data over run.
        static force_inline bool dataOverRun() {
            return *REG(USART_N(DATA_OVERRUN_BIT_0_REG)) & bv(USART_N(DATA_OVERRUN_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USART_N(DATA_OVERRUN_BIT_0_BIT))
        /// #### static void dataOverRunClear()
        /// Clear the data over run flag.
        static force_inline void dataOverRunClear() {
            setBit_(REG(USART_N(DATA_OVERRUN_BIT_0_REG)), USART_N(DATA_OVERRUN_BIT_0_BIT), false);
        }
    #endif

    #if DEFINED(USART_N(PARITY_ERROR_BIT_0_BIT))
        /// #### static bool parityError()
        /// Returns true if there was a parity error.
        static force_inline bool parityError() {
            return *REG(USART_N(PARITY_ERROR_BIT_0_REG)) & bv(USART_N(PARITY_ERROR_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USART_N(PARITY_ERROR_BIT_0_BIT))
        /// #### static void parityErrorClear()
        /// Clear the parity error flag.
        static force_inline void parityErrorClear() {
            setBit_(REG(USART_N(PARITY_ERROR_BIT_0_REG)), USART_N(PARITY_ERROR_BIT_0_BIT), false);
        }
    #endif
};

} // nbos::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef UsartN
    #undef USART_N
    #undef _USART_N

    #include "usart.hpp"
#else
    #define NBOS_USART_HPP
#endif

#endif

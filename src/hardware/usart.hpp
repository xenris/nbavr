/// [[Index]]

/// # {{Universal Synchronous Asynchronous Receiver Transmitters}}

/// ```c++
/// using Usart = nbos::hw::Usart0;
///
/// const auto f = [](void*) {
///     Usart::push('?')
/// };
///
/// Usart::baud(103);
/// Usart::use2X(false);
///
/// Usart::transmitterEnable(true);
/// Usart::dataRegisterEmptyIntEnable(true);
/// Usart::dataRegisterEmptyCallback((callback_t)f);
/// ```

#ifndef NBOS_USART_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define UsartN CAT(Usart,N)
    #define USART_N(A) CAT(CHIP_USART_, N, _, A)

    #if CAT(CHIP_USART_, N)

//------------------------------------------------------------------

namespace nbos::hw {

/// ## class {{UsartN}}
struct UsartN {
    UsartN() = delete;
    UsartN& operator=(const UsartN&) = delete;
    UsartN(const UsartN&) = delete;

    #if DEFINED(USART_N(MODE_BIT_0_BIT))
        /// #### enum {{UsartN::Mode}}
        /// * asynchronous
        /// * synchronous
        /// * masterSpi
        enum class Mode {
            asynchronous = USART_N(MODE_ASYNCHRONOUS_ID),
            synchronous = USART_N(MODE_SYNCHRONOUS_ID),
            #if USART_N(MODE_MASTER_SPI_ID)
            masterSpi = USART_N(MODE_MASTER_SPI_ID),
            #endif
        };
    #endif

    #if DEFINED(USART_N(PARITY_BIT_0_BIT))
        /// #### enum {{UsartN::Parity}}
        /// * disabled
        /// * even
        /// * odd
        enum class Parity {
            disabled = USART_N(PARITY_DISABLE_ID),
            even = USART_N(PARITY_EVEN_ID),
            odd = USART_N(PARITY_ODD_ID),
        };
    #endif

    #if DEFINED(USART_N(STOP_BITS_BIT_0_BIT))
        /// #### enum {{UsartN::StopBits}}
        /// * bits1
        /// * bits2
        enum class StopBits {
            bits1 = USART_N(STOP_BITS_1_ID),
            bits2 = USART_N(STOP_BITS_2_ID),
        };
    #endif

    #if DEFINED(USART_N(CHARACTER_SIZE_BIT_0_BIT))
        /// #### enum {{UsartN::CharacterSize}}
        /// * size5
        /// * size6
        /// * size7
        /// * size8
        /// * size9
        enum class CharacterSize {
            size5 = USART_N(CHARACTER_SIZE_5_ID),
            size6 = USART_N(CHARACTER_SIZE_6_ID),
            size7 = USART_N(CHARACTER_SIZE_7_ID),
            size8 = USART_N(CHARACTER_SIZE_8_ID),
            size9 = USART_N(CHARACTER_SIZE_9_ID),
        };
    #endif

    #if DEFINED(USART_N(POLARITY_BIT_0_BIT))
        /// #### enum {{UsartN::Polarity}}
        /// * txRisingRxFalling
        /// * txFallingRxRising
        enum class Polarity {
            txRisingRxFalling = USART_N(POLARITY_TX_RISING_RX_FALLING_ID),
            txFallingRxRising = USART_N(POLARITY_TX_FALLING_RX_RISING_ID),
        };
    #endif

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::usart;
    }

    #if DEFINED(USART_N(MODE_BIT_0_BIT))
        /// #### static void mode([[UsartN::Mode]] m)
        static force_inline void mode(Mode m) {
            // #if DEFINED(USART_N(USART_REG_SELECT_BIT))
            //     setBit_(REG(USART_N(USART_REG_SELECT_REG)), USART_N(USART_REG_SELECT_BIT), true);
            // #endif

            setBit_(REG(USART_N(MODE_BIT_0_REG)), USART_N(MODE_BIT_0_BIT), Int(m) & 0x01);

            #if DEFINED(USART_N(MODE_BIT_1_BIT))
                setBit_(REG(USART_N(MODE_BIT_1_REG)), USART_N(MODE_BIT_1_BIT), Int(m) & 0x02);
            #endif

            #if DEFINED(USART_N(MODE_BIT_2_BIT))
                setBit_(REG(USART_N(MODE_BIT_2_REG)), USART_N(MODE_BIT_2_BIT), Int(m) & 0x04);
            #endif
        }
    #endif

    #if DEFINED(USART_N(PARITY_BIT_0_BIT))
        /// #### static void parity([[UsartN::Parity]] p)
        static force_inline void parity(Parity p) {
            setBit_(REG(USART_N(PARITY_BIT_0_REG)), USART_N(PARITY_BIT_0_BIT), Int(p) & 0x01);

            #if DEFINED(USART_N(PARITY_BIT_1_BIT))
                setBit_(REG(USART_N(PARITY_BIT_1_REG)), USART_N(PARITY_BIT_1_BIT), Int(p) & 0x02);
            #endif

            #if DEFINED(USART_N(PARITY_BIT_2_BIT))
                setBit_(REG(USART_N(PARITY_BIT_2_REG)), USART_N(PARITY_BIT_2_BIT), Int(p) & 0x04);
            #endif
        }
    #endif

    #if DEFINED(USART_N(STOP_BITS_BIT_0_BIT))
        /// #### static void stopBits([[UsartN::StopBits]] b)
        static force_inline void stopBits(StopBits b) {
            // #if DEFINED(USART_N(USART_REG_SELECT_BIT))
            //     setBit_(REG(USART_N(USART_REG_SELECT_REG)), USART_N(USART_REG_SELECT_BIT), true);
            // #endif

            setBit_(REG(USART_N(STOP_BITS_BIT_0_REG)), USART_N(STOP_BITS_BIT_0_BIT), Int(b) & 0x01);

            #if DEFINED(USART_N(STOP_BITS_BIT_1_BIT))
                setBit_(REG(USART_N(STOP_BITS_BIT_1_REG)), USART_N(STOP_BITS_BIT_1_BIT), Int(b) & 0x02);
            #endif
        }
    #endif

    #if DEFINED(USART_N(CHARACTER_SIZE_BIT_0_BIT))
        /// #### static void characterSize([[UsartN::CharacterSize]] s)
        static force_inline void characterSize(CharacterSize s) {
            setBit_(REG(USART_N(CHARACTER_SIZE_BIT_0_REG)), USART_N(CHARACTER_SIZE_BIT_0_BIT), Int(s) & 0x01);

            #if DEFINED(USART_N(CHARACTER_SIZE_BIT_1_BIT))
                setBit_(REG(USART_N(CHARACTER_SIZE_BIT_1_REG)), USART_N(CHARACTER_SIZE_BIT_1_BIT), Int(s) & 0x02);
            #endif

            #if DEFINED(USART_N(CHARACTER_SIZE_BIT_2_BIT))
                setBit_(REG(USART_N(CHARACTER_SIZE_BIT_2_REG)), USART_N(CHARACTER_SIZE_BIT_2_BIT), Int(s) & 0x04);
            #endif

            #if DEFINED(USART_N(CHARACTER_SIZE_BIT_3_BIT))
                setBit_(REG(USART_N(CHARACTER_SIZE_BIT_3_REG)), USART_N(CHARACTER_SIZE_BIT_3_BIT), Int(s) & 0x08);
            #endif
        }
    #endif

    #if DEFINED(USART_N(POLARITY_BIT_0_BIT))
        /// #### static void polarity([[UsartN::Polarity]] p)
        static force_inline void polarity(Polarity p) {
            setBit_(REG(USART_N(POLARITY_BIT_0_REG)), USART_N(POLARITY_BIT_0_BIT), Int(p) & 0x01);

            #if DEFINED(USART_N(POLARITY_BIT_1_BIT))
                setBit_(REG(USART_N(POLARITY_BIT_1_REG)), USART_N(POLARITY_BIT_1_BIT), Int(p) & 0x02);
            #endif
        }
    #endif

    /// #### static void baud(Word16 b)
    static force_inline void baud(Word16 b) {
        b &= 0x0fff;

        #if CAT(USART_N(BAUD_RATE_REG), _ADDR)
            *REG(USART_N(BAUD_RATE_REG)) = b;
        #else
            *REG(USART_N(BAUD_RATE_REG_HIGH)) = Word8(b >> 8);
            *REG(USART_N(BAUD_RATE_REG_LOW)) = Word8(b);
        #endif
    }

    #if DEFINED(USART_N(DOUBLE_SPEED_BIT_0_BIT))
        /// #### static void use2X(Bool u)
        static force_inline void use2X(Bool u) {
            setBit_(REG(USART_N(DOUBLE_SPEED_BIT_0_REG)), USART_N(DOUBLE_SPEED_BIT_0_BIT), u);
        }
    #endif

    #if DEFINED(USART_N(RX_ENABLE_BIT_0_BIT))
        /// #### static void receiverEnable(Bool e)
        static force_inline void receiverEnable(Bool e) {
            setBit_(REG(USART_N(RX_ENABLE_BIT_0_REG)), USART_N(RX_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(TX_ENABLE_BIT_0_BIT))
        /// #### static void transmitterEnable(Bool e)
        static force_inline void transmitterEnable(Bool e) {
            setBit_(REG(USART_N(TX_ENABLE_BIT_0_REG)), USART_N(TX_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT))
        /// #### static void multiprocessorCummunicationMode(Bool e)
        static force_inline void multiprocessorCummunicationMode(Bool e) {
            setBit_(REG(USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT_0_REG)), USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(RX_COMPLETE_INT_ENABLE_BIT_0_BIT))
        /// #### static void rxCompleteIntEnable(Bool e)
        static force_inline void rxCompleteIntEnable(Bool e) {
            setBit_(REG(USART_N(RX_COMPLETE_INT_ENABLE_BIT_0_REG)), USART_N(RX_COMPLETE_INT_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(TX_COMPLETE_INT_ENABLE_BIT_0_BIT))
        /// #### static void txCompleteIntEnable(Bool e)
        static force_inline void txCompleteIntEnable(Bool e) {
            setBit_(REG(USART_N(TX_COMPLETE_INT_ENABLE_BIT_0_REG)), USART_N(TX_COMPLETE_INT_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT))
        /// #### static void dataRegisterEmptyIntEnable(Bool e)
        static force_inline void dataRegisterEmptyIntEnable(Bool e) {
            setBit_(REG(USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT_0_REG)), USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT), e);
        }
    #endif

    /// #### static void setRxCallback([[Callback]]<T\> function, T\* data)
    template <class T>
    static force_inline void setRxCallback(Callback<T> function, T* data = nullptr) {
        rxCallback((Callback<void>)function, data);
    }

    /// #### static void callRxCallback()
    static force_inline void callRxCallback() {
        rxCallback();
    }

    /// #### static void setTxCallback([[Callback]]<T\> function, T\* data)
    template <class T>
    static force_inline void setTxCallback(Callback<T> function, T* data = nullptr) {
        txCallback((Callback<void>)function, data);
    }

    /// #### static void callTxCallback()
    static force_inline void callTxCallback() {
        txCallback();
    }

    /// #### static void setDeCallback([[Callback]]<T\> function, T\* data)
    template <class T>
    static force_inline void setDeCallback(Callback<T> function, T* data = nullptr) {
        deCallback((Callback<void>)function, data);
    }

    /// #### static void callDeCallback()
    static force_inline void callDeCallback() {
        deCallback();
    }

    /// #### static void push(Word8 b)
    static force_inline void push(Word8 b) {
        *REG(USART_N(DATA_REG)) = b;
    }

    #if DEFINED(USART_N(TX_DATA_BIT_8_BIT))
        /// #### static void push9(Word16 b)
        static force_inline void push9(Word16 b) {
            setBit_(REG(USART_N(TX_DATA_BIT_8_REG)), USART_N(TX_DATA_BIT_8_BIT), Bool(b & 0x0100));

            *REG(USART_N(DATA_REG)) = Word8(b);
        }
    #endif

    /// #### static Word8 pop()
    static force_inline Word8 pop() {
        return *REG(USART_N(DATA_REG));
    }

    #if DEFINED(USART_N(RX_DATA_BIT_8_BIT))
        /// #### static Word16 pop9()
        static force_inline Word16 pop9() {
            Word16 result = Word16(*REG(USART_N(DATA_REG)));

            if(Bool(*REG(USART_N(RX_DATA_BIT_8_REG)) & bv(USART_N(RX_DATA_BIT_8_BIT)))) {
                result |= 0x0100;
            }

            return result;
        }
    #endif

    #if DEFINED(USART_N(FRAME_ERROR_BIT_0_BIT))
        /// #### static Bool frameError()
        static force_inline Bool frameError() {
            return Bool(*REG(USART_N(FRAME_ERROR_BIT_0_REG)) & bv(USART_N(FRAME_ERROR_BIT_0_BIT)));
        }
    #endif

    #if DEFINED(USART_N(FRAME_ERROR_BIT_0_BIT))
        /// #### static void frameErrorClear()
        static force_inline void frameErrorClear() {
            setBit_(REG(USART_N(FRAME_ERROR_BIT_0_REG)), USART_N(FRAME_ERROR_BIT_0_BIT), false);
        }
    #endif

    #if DEFINED(USART_N(DATA_OVERRUN_BIT_0_BIT))
        /// #### static Bool dataOverRun()
        static force_inline Bool dataOverRun() {
            return Bool(*REG(USART_N(DATA_OVERRUN_BIT_0_REG)) & bv(USART_N(DATA_OVERRUN_BIT_0_BIT)));
        }
    #endif

    #if DEFINED(USART_N(DATA_OVERRUN_BIT_0_BIT))
        /// #### static void dataOverRunClear()
        static force_inline void dataOverRunClear() {
            setBit_(REG(USART_N(DATA_OVERRUN_BIT_0_REG)), USART_N(DATA_OVERRUN_BIT_0_BIT), false);
        }
    #endif

    #if DEFINED(USART_N(PARITY_ERROR_BIT_0_BIT))
        /// #### static Bool parityError()
        static force_inline Bool parityError() {
            return Bool(*REG(USART_N(PARITY_ERROR_BIT_0_REG)) & bv(USART_N(PARITY_ERROR_BIT_0_BIT)));
        }
    #endif

    #if DEFINED(USART_N(PARITY_ERROR_BIT_0_BIT))
        /// #### static void parityErrorClear()
        static force_inline void parityErrorClear() {
            setBit_(REG(USART_N(PARITY_ERROR_BIT_0_REG)), USART_N(PARITY_ERROR_BIT_0_BIT), false);
        }
    #endif

private:

    static force_inline void rxCallback(Callback<void> function = nullptr, void* data = nullptr) {
        static Callback<void> f = nullptr;
        static void* d = nullptr;

        if(function == nullptr) {
            if(f != nullptr) {
                f(d);
            }
        } else {
            f = function;
            d = data;
        }
    }

    static force_inline void txCallback(Callback<void> function = nullptr, void* data = nullptr) {
        static Callback<void> f = nullptr;
        static void* d = nullptr;

        if(function == nullptr) {
            if(f != nullptr) {
                f(d);
            }
        } else {
            f = function;
            d = data;
        }
    }

    static force_inline void deCallback(Callback<void> function = nullptr, void* data = nullptr) {
        static Callback<void> f = nullptr;
        static void* d = nullptr;

        if(function == nullptr) {
            if(f != nullptr) {
                f(d);
            }
        } else {
            f = function;
            d = data;
        }
    }
};

ISR(USART_N(RX_INT_VECTOR)) {
    UsartN::callRxCallback();
}

ISR(USART_N(TX_INT_VECTOR)) {
    UsartN::callTxCallback();
}

ISR(USART_N(DE_INT_VECTOR)) {
    UsartN::callDeCallback();
}

} // nbos::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef UsartN
    #undef USART_N

    #include "usart.hpp"
#else
    #define NBOS_USART_HPP
#endif

#endif

/// [[Index]]

/// # {{Universal Synchronous Asynchronous Receiver Transmitters}}

/// ```c++
/// using Usart = nblib::hw::Usart0;
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

#ifndef NBLIB_USART_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"
#include "math.hpp"
#include "primitive.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define UsartN CAT(Usart,N)
    #define USART_N(A) CAT(CHIP_USART_, N, _, A)

    #if CAT(CHIP_USART_, N)

//------------------------------------------------------------------

namespace nblib::hw {

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
            #if DEFINED(USART_N(MODE_ASYNCHRONOUS_ID))
                asynchronous = USART_N(MODE_ASYNCHRONOUS_ID),
            #endif

            #if DEFINED(USART_N(MODE_SYNCHRONOUS_ID))
                synchronous = USART_N(MODE_SYNCHRONOUS_ID),
            #endif

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
            #if DEFINED(USART_N(PARITY_DISABLE_ID))
                disabled = USART_N(PARITY_DISABLE_ID),
            #endif

            #if DEFINED(USART_N(PARITY_EVEN_ID))
                even = USART_N(PARITY_EVEN_ID),
            #endif

            #if DEFINED(USART_N(PARITY_ODD_ID))
                odd = USART_N(PARITY_ODD_ID),
            #endif
        };
    #endif

    #if DEFINED(USART_N(STOP_BITS_BIT_0_BIT))
        /// #### enum {{UsartN::StopBits}}
        /// * bits1
        /// * bits2
        enum class StopBits {
            #if DEFINED(USART_N(STOP_BITS_1_ID))
                bits1 = USART_N(STOP_BITS_1_ID),
            #endif

            #if DEFINED(USART_N(STOP_BITS_2_ID))
                bits2 = USART_N(STOP_BITS_2_ID),
            #endif
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
            #if DEFINED(USART_N(CHARACTER_SIZE_5_ID))
                size5 = USART_N(CHARACTER_SIZE_5_ID),
            #endif

            #if DEFINED(USART_N(CHARACTER_SIZE_6_ID))
                size6 = USART_N(CHARACTER_SIZE_6_ID),
            #endif

            #if DEFINED(USART_N(CHARACTER_SIZE_7_ID))
                size7 = USART_N(CHARACTER_SIZE_7_ID),
            #endif

            #if DEFINED(USART_N(CHARACTER_SIZE_8_ID))
                size8 = USART_N(CHARACTER_SIZE_8_ID),
            #endif

            #if DEFINED(USART_N(CHARACTER_SIZE_9_ID))
                size9 = USART_N(CHARACTER_SIZE_9_ID),
            #endif
        };
    #endif

    #if DEFINED(USART_N(POLARITY_BIT_0_BIT))
        /// #### enum {{UsartN::Polarity}}
        /// * txRisingRxFalling
        /// * txFallingRxRising
        enum class Polarity {
            #if DEFINED(USART_N(POLARITY_TX_RISING_RX_FALLING_ID))
                txRisingRxFalling = USART_N(POLARITY_TX_RISING_RX_FALLING_ID),
            #endif

            #if DEFINED(USART_N(POLARITY_TX_FALLING_RX_RISING_ID))
                txFallingRxRising = USART_N(POLARITY_TX_FALLING_RX_RISING_ID),
            #endif
        };
    #endif

    #if DEFINED(USART_N(BAUD_MODE_BIT_0_BIT))
        /// #### enum {{UsartN::BaudMode}}
        /// * normal
        /// * doubleSpeed
        /// * genericAuto
        /// * linAuto
        enum class BaudMode {
            #if DEFINED(USART_N(BAUD_MODE_NORMAL_ID))
                normal = USART_N(BAUD_MODE_NORMAL_ID),
            #endif

            #if DEFINED(USART_N(BAUD_MODE_NORMAL_ID))
                doubleSpeed = USART_N(BAUD_MODE_DOUBLE_ID),
            #endif

            #if DEFINED(USART_N(BAUD_MODE_NORMAL_ID))
                genericAuto = USART_N(BAUD_MODE_GENAUTO_ID),
            #endif

            #if DEFINED(USART_N(BAUD_MODE_NORMAL_ID))
                linAuto = USART_N(BAUD_MODE_LINAUTO_ID),
            #endif
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

            setBit_(REG(USART_N(MODE_BIT_0_REG)), USART_N(MODE_BIT_0_BIT), int(m) & 0x01);

            #if DEFINED(USART_N(MODE_BIT_1_BIT))
                setBit_(REG(USART_N(MODE_BIT_1_REG)), USART_N(MODE_BIT_1_BIT), int(m) & 0x02);
            #endif

            #if DEFINED(USART_N(MODE_BIT_2_BIT))
                setBit_(REG(USART_N(MODE_BIT_2_REG)), USART_N(MODE_BIT_2_BIT), int(m) & 0x04);
            #endif
        }
    #endif

    #if DEFINED(USART_N(PARITY_BIT_0_BIT))
        /// #### static void parity([[UsartN::Parity]] p)
        static force_inline void parity(Parity p) {
            setBit_(REG(USART_N(PARITY_BIT_0_REG)), USART_N(PARITY_BIT_0_BIT), int(p) & 0x01);

            #if DEFINED(USART_N(PARITY_BIT_1_BIT))
                setBit_(REG(USART_N(PARITY_BIT_1_REG)), USART_N(PARITY_BIT_1_BIT), int(p) & 0x02);
            #endif

            #if DEFINED(USART_N(PARITY_BIT_2_BIT))
                setBit_(REG(USART_N(PARITY_BIT_2_REG)), USART_N(PARITY_BIT_2_BIT), int(p) & 0x04);
            #endif
        }
    #endif

    #if DEFINED(USART_N(STOP_BITS_BIT_0_BIT))
        /// #### static void stopBits([[UsartN::StopBits]] b)
        static force_inline void stopBits(StopBits b) {
            // #if DEFINED(USART_N(USART_REG_SELECT_BIT))
            //     setBit_(REG(USART_N(USART_REG_SELECT_REG)), USART_N(USART_REG_SELECT_BIT), true);
            // #endif

            setBit_(REG(USART_N(STOP_BITS_BIT_0_REG)), USART_N(STOP_BITS_BIT_0_BIT), int(b) & 0x01);

            #if DEFINED(USART_N(STOP_BITS_BIT_1_BIT))
                setBit_(REG(USART_N(STOP_BITS_BIT_1_REG)), USART_N(STOP_BITS_BIT_1_BIT), int(b) & 0x02);
            #endif
        }
    #endif

    #if DEFINED(USART_N(CHARACTER_SIZE_BIT_0_BIT))
        /// #### static void characterSize([[UsartN::CharacterSize]] s)
        static force_inline void characterSize(CharacterSize s) {
            setBit_(REG(USART_N(CHARACTER_SIZE_BIT_0_REG)), USART_N(CHARACTER_SIZE_BIT_0_BIT), int(s) & 0x01);

            #if DEFINED(USART_N(CHARACTER_SIZE_BIT_1_BIT))
                setBit_(REG(USART_N(CHARACTER_SIZE_BIT_1_REG)), USART_N(CHARACTER_SIZE_BIT_1_BIT), int(s) & 0x02);
            #endif

            #if DEFINED(USART_N(CHARACTER_SIZE_BIT_2_BIT))
                setBit_(REG(USART_N(CHARACTER_SIZE_BIT_2_REG)), USART_N(CHARACTER_SIZE_BIT_2_BIT), int(s) & 0x04);
            #endif

            #if DEFINED(USART_N(CHARACTER_SIZE_BIT_3_BIT))
                setBit_(REG(USART_N(CHARACTER_SIZE_BIT_3_REG)), USART_N(CHARACTER_SIZE_BIT_3_BIT), int(s) & 0x08);
            #endif
        }
    #endif

    #if DEFINED(USART_N(POLARITY_BIT_0_BIT))
        /// #### static void polarity([[UsartN::Polarity]] p)
        static force_inline void polarity(Polarity p) {
            setBit_(REG(USART_N(POLARITY_BIT_0_REG)), USART_N(POLARITY_BIT_0_BIT), int(p) & 0x01);

            #if DEFINED(USART_N(POLARITY_BIT_1_BIT))
                setBit_(REG(USART_N(POLARITY_BIT_1_REG)), USART_N(POLARITY_BIT_1_BIT), int(p) & 0x02);
            #endif
        }
    #endif

    #if REG_ADDR(USART_N(BAUD_RATE_REG)) || REG_ADDR(USART_N(BAUD_RATE_REG_HIGH))
        /// #### static void baud(uint16_t b)
        static force_inline void baud(uint16_t b) {
            b &= 0x0fff;

            #if CAT(USART_N(BAUD_RATE_REG), _ADDR)
                setReg_(REG(USART_N(BAUD_RATE_REG)), b);
            #else
                setReg_(REG(USART_N(BAUD_RATE_REG_HIGH)), uint8_t(b >> 8));
                setReg_(REG(USART_N(BAUD_RATE_REG_LOW)), uint8_t(b));
            #endif
        }
    #endif

    #if DEFINED(USART_N(DOUBLE_SPEED_BIT_0_BIT))
        /// #### static void use2X(bool u)
        static force_inline void use2X(bool u) {
            // FIXME Other bits in this register need to always be written as zero.
            setBit_(REG(USART_N(DOUBLE_SPEED_BIT_0_REG)), uint8_t(0x03), USART_N(DOUBLE_SPEED_BIT_0_BIT), u);
        }
    #endif

    #if REG_ADDR(USART_N(BAUD_MODE_BIT_0_REG))
        /// #### static void baudMode(bool u)
        static force_inline void baudMode(BaudMode m) {
            setBit_(REG(USART_N(BAUD_MODE_BIT_0_REG)), USART_N(BAUD_MODE_BIT_0_BIT), int(m) & 0x01);

            #if REG_ADDR(USART_N(BAUD_MODE_BIT_1_REG))
                setBit_(REG(USART_N(BAUD_MODE_BIT_1_REG)), USART_N(BAUD_MODE_BIT_1_BIT), int(m) & 0x02);
            #endif
        }
    #endif

    /// #### static void setBaudRate<cpuFreq, baudRate>()
    /// Set the baud and 2x registers from the given CPU frequency and baud rate.
    template <uint64_t cpuFreq, uint64_t baudRate>
    static force_inline void setBaudRate() {
        const uint16_t ubrr1x = uint16_t(float(cpuFreq) / (float(baudRate) * 16) - 1 + 0.5);
        const uint16_t ubrr2x = uint16_t(float(cpuFreq) / (float(baudRate) * 8) - 1 + 0.5);

        const uint64_t baudTrue1x = cpuFreq / uint64_t((ubrr1x + 1) * 16);
        const uint64_t baudTrue2x = cpuFreq / uint64_t((ubrr2x + 1) * 8);

        const float ubrr1xError = (float(baudTrue1x) / float(baudRate)) - 1;
        const float ubrr2xError = (float(baudTrue2x) / float(baudRate)) - 1;

        const bool use2x = abs(ubrr2xError) < abs(ubrr1xError);

        #if DEFINED(USART_N(DOUBLE_SPEED_BIT_0_BIT))
            use2X(use2x);
            baud(use2x ? ubrr2x : ubrr1x);
        #else
            baud(ubrr1x);
            (void)use2x;
            (void)ubrr2x;
        #endif
    }

    #if DEFINED(USART_N(ENABLE_ALTERNATE_PINS_BIT_0_BIT))
        /// #### static void enableAlternatePins(bool)
        static force_inline void enableAlternatePins(bool e) {
            setBit_(REG(USART_N(ENABLE_ALTERNATE_PINS_BIT_0_REG)), USART_N(ENABLE_ALTERNATE_PINS_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(RX_ENABLE_BIT_0_BIT))
        /// #### static void receiverEnable(bool e)
        static force_inline void receiverEnable(bool e) {
            setBit_(REG(USART_N(RX_ENABLE_BIT_0_REG)), USART_N(RX_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(TX_ENABLE_BIT_0_BIT))
        /// #### static void transmitterEnable(bool e)
        static force_inline void transmitterEnable(bool e) {
            setBit_(REG(USART_N(TX_ENABLE_BIT_0_REG)), USART_N(TX_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT))
        /// #### static void multiprocessorCummunicationMode(bool e)
        static force_inline void multiprocessorCummunicationMode(bool e) {
            // FIXME Other bits in this register need to always be written as zero.
            // TODO Create an access mask value which is applied when setting registers.
            setBit_(REG(USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT_0_REG)), uint8_t(0x03), USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(RX_COMPLETE_INT_ENABLE_BIT_0_BIT))
        /// #### static void rxCompleteIntEnable(bool e)
        static force_inline void rxCompleteIntEnable(bool e) {
            setBit_(REG(USART_N(RX_COMPLETE_INT_ENABLE_BIT_0_REG)), USART_N(RX_COMPLETE_INT_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(TX_COMPLETE_INT_ENABLE_BIT_0_BIT))
        /// #### static void txCompleteIntEnable(bool e)
        static force_inline void txCompleteIntEnable(bool e) {
            setBit_(REG(USART_N(TX_COMPLETE_INT_ENABLE_BIT_0_REG)), USART_N(TX_COMPLETE_INT_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT))
        /// #### static void dataRegisterEmptyIntEnable(bool e)
        static force_inline void dataRegisterEmptyIntEnable(bool e) {
            setBit_(REG(USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT_0_REG)), USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(USART_N(RX_COMPLETE_INT_FLAG_BIT_0_BIT))
        /// #### static bool rxCompleteIntFlag()
        static force_inline bool rxCompleteIntFlag() {
            return getBit(REG(USART_N(RX_COMPLETE_INT_FLAG_BIT_0_REG)), USART_N(RX_COMPLETE_INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USART_N(TX_COMPLETE_INT_FLAG_BIT_0_BIT))
        /// #### static bool txCompleteIntFlag()
        static force_inline bool txCompleteIntFlag() {
            return getBit(REG(USART_N(TX_COMPLETE_INT_FLAG_BIT_0_REG)), USART_N(TX_COMPLETE_INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USART_N(DATA_REG_EMPTY_INT_FLAG_BIT_0_BIT))
        /// #### static bool dataRegisterEmptyIntFlag()
        static force_inline bool dataRegisterEmptyIntFlag() {
            return getBit(REG(USART_N(DATA_REG_EMPTY_INT_FLAG_BIT_0_REG)), USART_N(DATA_REG_EMPTY_INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USART_N(RX_COMPLETE_INT_FLAG_BIT_0_BIT))
        /// #### static void rxCompleteIntFlagClear()
        static force_inline void rxCompleteIntFlagClear() {
            clearFlagBit(REG(USART_N(RX_COMPLETE_INT_FLAG_BIT_0_REG)), USART_N(RX_COMPLETE_INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USART_N(TX_COMPLETE_INT_FLAG_BIT_0_BIT))
        /// #### static void txCompleteIntFlagClear()
        static force_inline void txCompleteIntFlagClear() {
            clearFlagBit(REG(USART_N(TX_COMPLETE_INT_FLAG_BIT_0_REG)), USART_N(TX_COMPLETE_INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USART_N(DATA_REG_EMPTY_INT_FLAG_BIT_0_BIT))
        /// #### static void dataRegisterEmptyIntFlagClear()
        static force_inline void dataRegisterEmptyIntFlagClear() {
            clearFlagBit(REG(USART_N(DATA_REG_EMPTY_INT_FLAG_BIT_0_REG)), USART_N(DATA_REG_EMPTY_INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if REG_ADDR(USART_N(DATA_REG))
        /// #### static void push(uint8_t b)
        static force_inline void push(uint8_t b) {
            setReg_(REG(USART_N(DATA_REG)), b);
        }
    #endif

    #if DEFINED(USART_N(TX_DATA_BIT_8_BIT))
        /// #### static void push9(uint16_t b)
        static force_inline void push9(uint16_t b) {
            setBit_(REG(USART_N(TX_DATA_BIT_8_REG)), USART_N(TX_DATA_BIT_8_BIT), bool(b & 0x0100));

            setReg_(REG(USART_N(DATA_REG)), uint8_t(b));
        }
    #endif

    #if REG_ADDR(USART_N(DATA_REG))
        /// #### static uint8_t pop()
        static force_inline uint8_t pop() {
            return getReg_(REG(USART_N(DATA_REG)));
        }
    #endif

    #if DEFINED(USART_N(RX_DATA_BIT_8_BIT))
        /// #### static uint16_t pop9()
        static force_inline uint16_t pop9() {
            uint16_t result = uint16_t(getReg_(REG(USART_N(DATA_REG))));

            if(getBit_(REG(USART_N(RX_DATA_BIT_8_REG)), USART_N(RX_DATA_BIT_8_BIT))) {
                result |= 0x0100;
            }

            return result;
        }
    #endif

    #if REG_ADDR(USART_N(RX_DATA_REG))
        /// #### static uint8_t rxData()
        static force_inline uint8_t rxData() {
            return getReg_(REG(USART_N(RX_DATA_REG)));
        }
    #endif

    #if REG_ADDR(USART_N(RX_DATA9_REG))
        /// #### static uint16_t rxData9()
        static force_inline uint16_t rxData9() {
            return getReg_(REG(USART_N(RX_DATA9_REG))) & 0x01FF;
        }
    #endif

    #if REG_ADDR(USART_N(TX_DATA_REG))
        /// #### static void txData(uint8_t)
        static force_inline void txData(uint8_t b) {
            setReg_(REG(USART_N(TX_DATA_REG)), b);
        }
    #endif

    #if REG_ADDR(USART_N(TX_DATA9_REG))
        /// #### static void txData9(uint16_t)
        static force_inline void txData9(uint16_t w) {
            setReg_(REG(USART_N(TX_DATA9_REG)), w);
        }
    #endif

    #if DEFINED(USART_N(FRAME_ERROR_BIT_0_BIT))
        /// #### static bool frameError()
        static force_inline bool frameError() {
            return getBit_(REG(USART_N(FRAME_ERROR_BIT_0_REG)), USART_N(FRAME_ERROR_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USART_N(DATA_OVERRUN_BIT_0_BIT))
        /// #### static bool dataOverRun()
        static force_inline bool dataOverRun() {
            return getBit_(REG(USART_N(DATA_OVERRUN_BIT_0_REG)), USART_N(DATA_OVERRUN_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USART_N(PARITY_ERROR_BIT_0_BIT))
        /// #### static bool parityError()
        static force_inline bool parityError() {
            return getBit_(REG(USART_N(PARITY_ERROR_BIT_0_REG)), USART_N(PARITY_ERROR_BIT_0_BIT));
        }
    #endif
};

#ifdef TEST

TEST(UsartN, getHardwareType) {
    ASSERT_EQ(UsartN::getHardwareType(), HardwareType::usart);
}

#if DEFINED(USART_N(MODE_BIT_0_BIT))
    TEST(UsartN, mode) {
        TEST_REG_WRITE(UsartN::mode(UsartN::Mode::asynchronous));
        TEST_REG_WRITE(UsartN::mode(UsartN::Mode::synchronous));

        #if USART_N(MODE_MASTER_SPI_ID)
            TEST_REG_WRITE(UsartN::mode(UsartN::Mode::masterSpi));
        #endif
    }
#endif

#if DEFINED(USART_N(PARITY_BIT_0_BIT))
    TEST(UsartN, parity) {
        TEST_REG_WRITE(UsartN::parity(UsartN::Parity::disabled));
        TEST_REG_WRITE(UsartN::parity(UsartN::Parity::even));
        TEST_REG_WRITE(UsartN::parity(UsartN::Parity::odd));
    }
#endif

#if DEFINED(USART_N(STOP_BITS_BIT_0_BIT))
    TEST(UsartN, stopBits) {
        TEST_REG_WRITE(UsartN::stopBits(UsartN::StopBits::bits1));
        TEST_REG_WRITE(UsartN::stopBits(UsartN::StopBits::bits2));
    }
#endif

#if DEFINED(USART_N(CHARACTER_SIZE_BIT_0_BIT))
    TEST(UsartN, characterSize) {
        TEST_REG_WRITE(UsartN::characterSize(UsartN::CharacterSize::size5));
        TEST_REG_WRITE(UsartN::characterSize(UsartN::CharacterSize::size6));
        TEST_REG_WRITE(UsartN::characterSize(UsartN::CharacterSize::size7));
        TEST_REG_WRITE(UsartN::characterSize(UsartN::CharacterSize::size8));
        #if DEFINED(USART_N(CHARACTER_SIZE_9_ID))
            TEST_REG_WRITE(UsartN::characterSize(UsartN::CharacterSize::size9));
        #endif
    }
#endif

#if DEFINED(USART_N(POLARITY_BIT_0_BIT))
    TEST(UsartN, polarity) {
        TEST_REG_WRITE(UsartN::polarity(UsartN::Polarity::txRisingRxFalling));
        TEST_REG_WRITE(UsartN::polarity(UsartN::Polarity::txFallingRxRising));
    }
#endif

#if REG_ADDR(USART_N(BAUD_RATE_REG)) || REG_ADDR(USART_N(BAUD_RATE_REG_HIGH))
    TEST(UsartN, baud) {
        TEST_REG_WRITE(UsartN::baud(0x1234));
    }
#endif

#if DEFINED(USART_N(DOUBLE_SPEED_BIT_0_BIT))
    TEST(UsartN, use2X) {
        TEST_REG_WRITE(UsartN::use2X(true));
        TEST_REG_WRITE(UsartN::use2X(false));
    }
#endif

#if DEFINED(USART_N(ENABLE_ALTERNATE_PINS_BIT_0_BIT))
    TEST(UsartN, enableAlternatePins) {
        TEST_REG_WRITE(UsartN::enableAlternatePins(true));
        TEST_REG_WRITE(UsartN::enableAlternatePins(false));
    }
#endif

#if DEFINED(USART_N(RX_ENABLE_BIT_0_BIT))
    TEST(UsartN, receiverEnable) {
        TEST_REG_WRITE(UsartN::receiverEnable(true));
        TEST_REG_WRITE(UsartN::receiverEnable(false));
    }
#endif

#if DEFINED(USART_N(TX_ENABLE_BIT_0_BIT))
    TEST(UsartN, transmitterEnable) {
        TEST_REG_WRITE(UsartN::transmitterEnable(true));
        TEST_REG_WRITE(UsartN::transmitterEnable(false));
    }
#endif

#if DEFINED(USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT_0_BIT))
    TEST(UsartN, multiprocessorCummunicationMode) {
        TEST_REG_WRITE(UsartN::multiprocessorCummunicationMode(true));
        TEST_REG_WRITE(UsartN::multiprocessorCummunicationMode(false));
    }
#endif

#if DEFINED(USART_N(RX_COMPLETE_INT_ENABLE_BIT_0_BIT))
    TEST(UsartN, rxCompleteIntEnable) {
        TEST_REG_WRITE(UsartN::rxCompleteIntEnable(true));
        TEST_REG_WRITE(UsartN::rxCompleteIntEnable(false));
    }
#endif

#if DEFINED(USART_N(TX_COMPLETE_INT_ENABLE_BIT_0_BIT))
    TEST(UsartN, txCompleteIntEnable) {
        TEST_REG_WRITE(UsartN::txCompleteIntEnable(true));
        TEST_REG_WRITE(UsartN::txCompleteIntEnable(false));
    }
#endif

#if DEFINED(USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT_0_BIT))
    TEST(UsartN, dataRegisterEmptyIntEnable) {
        TEST_REG_WRITE(UsartN::dataRegisterEmptyIntEnable(true));
        TEST_REG_WRITE(UsartN::dataRegisterEmptyIntEnable(false));
    }
#endif

#if REG_ADDR(USART_N(DATA_REG))
    TEST(UsartN, push) {
        TEST_REG_WRITE(UsartN::push(0x12));
    }
#endif

#if DEFINED(USART_N(TX_DATA_BIT_8_BIT))
    TEST(UsartN, push9) {
        TEST_REG_WRITE(UsartN::push9(0x1234));
    }
#endif

#if REG_ADDR(USART_N(DATA_REG))
    TEST(UsartN, pop) {
        TEST_REG_READ_WRITE(UsartN::pop());
    }
#endif

#if DEFINED(USART_N(RX_DATA_BIT_8_BIT))
    TEST(UsartN, pop9) {
        TEST_REG_READ_WRITE(UsartN::pop9());
    }
#endif

#if DEFINED(USART_N(FRAME_ERROR_BIT_0_BIT))
    TEST(UsartN, frameError) {
        TEST_REG_READ_WRITE(UsartN::frameError());
    }
#endif

#if DEFINED(USART_N(DATA_OVERRUN_BIT_0_BIT))
    TEST(UsartN, dataOverRun) {
        TEST_REG_READ_WRITE(UsartN::dataOverRun());
    }
#endif

#if DEFINED(USART_N(PARITY_ERROR_BIT_0_BIT))
    TEST(UsartN, parityError) {
        TEST_REG_READ_WRITE(UsartN::parityError());
    }
#endif

#endif // TEST

} // nblib::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef UsartN
    #undef USART_N

    #include "usart.hpp"
#else
    #define NBLIB_USART_HPP
#endif

#endif

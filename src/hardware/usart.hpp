/// [[Index]]

/// # {{Universal Synchronous Asynchronous Receiver Transmitters}}

#ifndef NBLIB_USART_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "../macros.hpp"
#include "system.hpp"
#include "../math.hpp"
#include "../primitive.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define UsartN CAT(Usart,N)
    #define USART_N(A) CAT(CHIP_USART_, N, _, A)

    #if DEFINED(CAT(CHIP_USART_, N))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{UsartN}}
struct UsartN {
    UsartN() = delete;
    UsartN& operator=(const UsartN&) = delete;
    UsartN(const UsartN&) = delete;

    #if REG_DEFINED(USART_N(MODE_REG))
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

    #if REG_DEFINED(USART_N(PARITY_REG))
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

    #if REG_DEFINED(USART_N(STOP_BITS_REG))
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

    #if REG_DEFINED(USART_N(CHARACTER_SIZE_REG))
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

    #if REG_DEFINED(USART_N(POLARITY_REG))
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

    #if REG_DEFINED(USART_N(BAUD_MODE_REG))
        /// #### enum {{UsartN::BaudMode}}
        /// * normal
        /// * doubleSpeed
        /// * genericAuto
        /// * linAuto
        enum class BaudMode {
            #if DEFINED(USART_N(BAUD_MODE_NORMAL_ID))
                normal = USART_N(BAUD_MODE_NORMAL_ID),
            #endif

            #if DEFINED(USART_N(BAUD_MODE_DOUBLE_ID))
                doubleSpeed = USART_N(BAUD_MODE_DOUBLE_ID),
            #endif

            #if DEFINED(USART_N(BAUD_MODE_GENAUTO_ID))
                genericAuto = USART_N(BAUD_MODE_GENAUTO_ID),
            #endif

            #if DEFINED(USART_N(BAUD_MODE_LINAUTO_ID))
                linAuto = USART_N(BAUD_MODE_LINAUTO_ID),
            #endif
        };
    #endif

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::usart;
    }

    #if REG_DEFINED(USART_N(MODE_REG))
        /// #### static void mode([[UsartN::Mode]] m)
        static force_inline void mode(Mode m) {
            USART_N(MODE_REG)::setBits(USART_N(MODE_MASK), m);
        }
    #endif

    #if REG_DEFINED(USART_N(PARITY_REG))
        /// #### static void parity([[UsartN::Parity]] p)
        static force_inline void parity(Parity p) {
            USART_N(PARITY_REG)::setBits(USART_N(PARITY_MASK), p);
        }
    #endif

    #if REG_DEFINED(USART_N(STOP_BITS_REG))
        /// #### static void stopBits([[UsartN::StopBits]] b)
        static force_inline void stopBits(StopBits b) {
            USART_N(STOP_BITS_REG)::setBits(USART_N(STOP_BITS_MASK), b);
        }
    #endif

    #if REG_DEFINED(USART_N(CHARACTER_SIZE_REG))
        /// #### static void characterSize([[UsartN::CharacterSize]] s)
        static force_inline void characterSize(CharacterSize s) {
            USART_N(CHARACTER_SIZE_REG)::setBits(USART_N(CHARACTER_SIZE_MASK), s);

            #if REG_DEFINED(USART_N(CHARACTER_SIZE_REG_EXTRA))
                USART_N(CHARACTER_SIZE_REG_EXTRA)::setBits(USART_N(CHARACTER_SIZE_MASK_EXTRA), uint(s) >> 8);
            #endif
        }
    #endif

    #if REG_DEFINED(USART_N(POLARITY_REG))
        /// #### static void polarity([[UsartN::Polarity]] p)
        static force_inline void polarity(Polarity p) {
            USART_N(POLARITY_REG)::setBits(USART_N(POLARITY_MASK), p);
        }
    #endif

    #if REG_DEFINED(USART_N(BAUD_REG)) || REG_DEFINED(USART_N(BAUD_REG_LOW))
        /// #### static void baud(uint16_t b)
        static force_inline void baud(uint16_t b) {

            #if REG_DEFINED(USART_N(BAUD_REG))
                USART_N(BAUD_REG)::setReg(b);
            #else
                USART_N(BAUD_REG_HIGH)::setReg(uint8_t(b >> 8));
                USART_N(BAUD_REG_LOW)::setReg(uint8_t(b));
            #endif
        }
    #endif

    #if REG_DEFINED(USART_N(BAUD_MODE_REG))
        /// #### static void baudMode(bool u)
        static force_inline void baudMode(BaudMode m) {
            USART_N(BAUD_MODE_REG)::setBits(USART_N(BAUD_MODE_MASK), m);
        }
    #endif

    /// #### static void setBaudRate<cpuFreq, baudRate>()
    /// Set the baud and 2x registers from the given CPU frequency and baud rate.
    // template <uint64_t cpuFreq, uint64_t baudRate>
    // static force_inline void setBaudRate() {
    //     const uint16_t ubrr1x = uint16_t(float(cpuFreq) / (float(baudRate) * 16) - 1 + 0.5);
    //     const uint16_t ubrr2x = uint16_t(float(cpuFreq) / (float(baudRate) * 8) - 1 + 0.5);

    //     const uint64_t baudTrue1x = cpuFreq / uint64_t((ubrr1x + 1) * 16);
    //     const uint64_t baudTrue2x = cpuFreq / uint64_t((ubrr2x + 1) * 8);

    //     const float ubrr1xError = (float(baudTrue1x) / float(baudRate)) - 1;
    //     const float ubrr2xError = (float(baudTrue2x) / float(baudRate)) - 1;

    //     const bool use2x = abs(ubrr2xError) < abs(ubrr1xError);

    //     #if DEFINED(USART_N(DOUBLE_SPEED_BIT_0_BIT))
    //         use2X(use2x);
    //         baud(use2x ? ubrr2x : ubrr1x);
    //     #else
    //         baud(ubrr1x);
    //         (void)use2x;
    //         (void)ubrr2x;
    //     #endif
    // }

    #if REG_DEFINED(USART_N(ENABLE_ALTERNATE_PINS_REG))
        /// #### static void enableAlternatePins(bool)
        static force_inline void enableAlternatePins(bool e) {
            USART_N(ENABLE_ALTERNATE_PINS_REG)::setBit(USART_N(ENABLE_ALTERNATE_PINS_BIT), e);
        }
    #endif

    #if REG_DEFINED(USART_N(RX_ENABLE_REG))
        /// #### static void receiverEnable(bool e)
        static force_inline void receiverEnable(bool e) {
            USART_N(RX_ENABLE_REG)::setBit(USART_N(RX_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(USART_N(TX_ENABLE_REG))
        /// #### static void transmitterEnable(bool e)
        static force_inline void transmitterEnable(bool e) {
            USART_N(TX_ENABLE_REG)::setBit(USART_N(TX_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(USART_N(MULTI_PROCESSOR_COMMUNICATION_REG))
        /// #### static void multiprocessorCummunicationMode(bool e)
        static force_inline void multiprocessorCummunicationMode(bool e) {
            USART_N(MULTI_PROCESSOR_COMMUNICATION_REG)::setBit(USART_N(MULTI_PROCESSOR_COMMUNICATION_BIT), e);
        }
    #endif

    #if REG_DEFINED(USART_N(RX_COMPLETE_INT_ENABLE_REG))
        /// #### static void rxCompleteIntEnable(bool e)
        static force_inline void rxCompleteIntEnable(bool e) {
            USART_N(RX_COMPLETE_INT_ENABLE_REG)::setBit(USART_N(RX_COMPLETE_INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(USART_N(TX_COMPLETE_INT_ENABLE_REG))
        /// #### static void txCompleteIntEnable(bool e)
        static force_inline void txCompleteIntEnable(bool e) {
            USART_N(TX_COMPLETE_INT_ENABLE_REG)::setBit(USART_N(TX_COMPLETE_INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(USART_N(DATA_REG_EMPTY_INT_ENABLE_REG))
        /// #### static void dataRegisterEmptyIntEnable(bool e)
        static force_inline void dataRegisterEmptyIntEnable(bool e) {
            USART_N(DATA_REG_EMPTY_INT_ENABLE_REG)::setBit(USART_N(DATA_REG_EMPTY_INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(USART_N(RX_COMPLETE_INT_FLAG_REG))
        /// #### static bool rxCompleteIntFlag()
        static force_inline bool rxCompleteIntFlag() {
            return USART_N(RX_COMPLETE_INT_FLAG_REG)::getBit(USART_N(RX_COMPLETE_INT_FLAG_BIT));
        }

        /// #### static void rxCompleteIntFlagClear()
        static force_inline void rxCompleteIntFlagClear() {
            USART_N(RX_COMPLETE_INT_FLAG_REG)::setBit(USART_N(RX_COMPLETE_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(USART_N(TX_COMPLETE_INT_FLAG_REG))
        /// #### static bool txCompleteIntFlag()
        static force_inline bool txCompleteIntFlag() {
            return USART_N(TX_COMPLETE_INT_FLAG_REG)::getBit(USART_N(TX_COMPLETE_INT_FLAG_BIT));
        }

        /// #### static void txCompleteIntFlagClear()
        static force_inline void txCompleteIntFlagClear() {
            USART_N(TX_COMPLETE_INT_FLAG_REG)::setBit(USART_N(TX_COMPLETE_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(USART_N(DATA_REG_EMPTY_INT_FLAG_REG))
        /// #### static bool dataRegisterEmptyIntFlag()
        static force_inline bool dataRegisterEmptyIntFlag() {
            return USART_N(DATA_REG_EMPTY_INT_FLAG_REG)::getBit(USART_N(DATA_REG_EMPTY_INT_FLAG_BIT));
        }

        /// #### static void dataRegisterEmptyIntFlagClear()
        static force_inline void dataRegisterEmptyIntFlagClear() {
            USART_N(DATA_REG_EMPTY_INT_FLAG_REG)::setBit(USART_N(DATA_REG_EMPTY_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(USART_N(TX_DATA_REG))
        /// #### static void tx(uint8_t b)
        static force_inline void tx(uint8_t b) {
            USART_N(TX_DATA_REG)::setReg(b);
        }
    #endif

    #if REG_DEFINED(USART_N(TX_DATA_9_REG))
        /// #### static void tx9(bool b)
        static force_inline void tx9(bool b) {
            USART_N(TX_DATA_9_REG)::setBit(USART_N(TX_DATA_9_BIT), b);
        }
    #endif

    #if REG_DEFINED(USART_N(RX_DATA_REG))
        /// #### static uint8_t rx()
        static force_inline uint8_t rx() {
            return USART_N(RX_DATA_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(USART_N(RX_DATA_9_REG))
        /// #### static bool rx9()
        static force_inline bool rx9() {
            return USART_N(RX_DATA_9_REG)::getBit(USART_N(RX_DATA_9_BIT));
        }
    #endif

    #if REG_DEFINED(USART_N(FRAME_ERROR_REG))
        /// #### static bool frameError()
        static force_inline bool frameError() {
            return USART_N(FRAME_ERROR_REG)::getBit(USART_N(FRAME_ERROR_BIT));
        }
    #endif

    #if REG_DEFINED(USART_N(DATA_OVERRUN_REG))
        /// #### static bool dataOverRun()
        static force_inline bool dataOverRun() {
            return USART_N(DATA_OVERRUN_REG)::getBit(USART_N(DATA_OVERRUN_BIT));
        }
    #endif

    #if REG_DEFINED(USART_N(PARITY_ERROR_REG))
        /// #### static bool parityError()
        static force_inline bool parityError() {
            return USART_N(PARITY_ERROR_REG)::getBit(USART_N(PARITY_ERROR_BIT));
        }
    #endif
};

#ifdef TEST

TEST(UsartN, getHardwareType) {
    ASSERT_EQ(UsartN::getHardwareType(), HardwareType::usart);
}

#if REG_DEFINED(USART_N(MODE_REG))
    TEST(UsartN, mode) {
        TEST_REG_WRITE(UsartN::mode(UsartN::Mode::asynchronous));
        TEST_REG_WRITE(UsartN::mode(UsartN::Mode::synchronous));

        #if USART_N(MODE_MASTER_SPI_ID)
            TEST_REG_WRITE(UsartN::mode(UsartN::Mode::masterSpi));
        #endif
    }
#endif

#if REG_DEFINED(USART_N(PARITY_REG))
    TEST(UsartN, parity) {
        TEST_REG_WRITE(UsartN::parity(UsartN::Parity::disabled));
        TEST_REG_WRITE(UsartN::parity(UsartN::Parity::even));
        TEST_REG_WRITE(UsartN::parity(UsartN::Parity::odd));
    }
#endif

#if REG_DEFINED(USART_N(STOP_BITS_REG))
    TEST(UsartN, stopBits) {
        TEST_REG_WRITE(UsartN::stopBits(UsartN::StopBits::bits1));
        TEST_REG_WRITE(UsartN::stopBits(UsartN::StopBits::bits2));
    }
#endif

#if REG_DEFINED(USART_N(CHARACTER_SIZE_REG))
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

#if REG_DEFINED(USART_N(POLARITY_REG))
    TEST(UsartN, polarity) {
        TEST_REG_WRITE(UsartN::polarity(UsartN::Polarity::txRisingRxFalling));
        TEST_REG_WRITE(UsartN::polarity(UsartN::Polarity::txFallingRxRising));
    }
#endif

#if REG_DEFINED(USART_N(BAUD_REG)) || REG_DEFINED(USART_N(BAUD_REG_LOW))
    TEST(UsartN, baud) {
        TEST_REG_WRITE(UsartN::baud(0x1234));
    }
#endif

#if REG_DEFINED(USART_N(BAUD_MODE_REG))
    TEST(UsartN, baudMode) {
        #if DEFINED(USART_N(BAUD_MODE_NORMAL_ID))
            TEST_REG_WRITE(UsartN::baudMode(UsartN::BaudMode::normal));
        #endif

        #if DEFINED(USART_N(BAUD_MODE_DOUBLE_ID))
            TEST_REG_WRITE(UsartN::baudMode(UsartN::BaudMode::doubleSpeed));
        #endif

        #if DEFINED(USART_N(BAUD_MODE_GENAUTO_ID))
            TEST_REG_WRITE(UsartN::baudMode(UsartN::BaudMode::genericAuto));
        #endif

        #if DEFINED(USART_N(BAUD_MODE_LINAUTO_ID))
            TEST_REG_WRITE(UsartN::baudMode(UsartN::BaudMode::linAuto));
        #endif
    }
#endif

#if REG_DEFINED(USART_N(ENABLE_ALTERNATE_PINS_REG))
    TEST(UsartN, enableAlternatePins) {
        TEST_REG_WRITE(UsartN::enableAlternatePins(true));
        TEST_REG_WRITE(UsartN::enableAlternatePins(false));
    }
#endif

#if REG_DEFINED(USART_N(RX_ENABLE_REG))
    TEST(UsartN, receiverEnable) {
        TEST_REG_WRITE(UsartN::receiverEnable(true));
        TEST_REG_WRITE(UsartN::receiverEnable(false));
    }
#endif

#if REG_DEFINED(USART_N(TX_ENABLE_REG))
    TEST(UsartN, transmitterEnable) {
        TEST_REG_WRITE(UsartN::transmitterEnable(true));
        TEST_REG_WRITE(UsartN::transmitterEnable(false));
    }
#endif

#if REG_DEFINED(USART_N(MULTI_PROCESSOR_COMMUNICATION_REG))
    TEST(UsartN, multiprocessorCummunicationMode) {
        TEST_REG_WRITE(UsartN::multiprocessorCummunicationMode(true));
        TEST_REG_WRITE(UsartN::multiprocessorCummunicationMode(false));
    }
#endif

#if REG_DEFINED(USART_N(RX_COMPLETE_INT_ENABLE_REG))
    TEST(UsartN, rxCompleteIntEnable) {
        TEST_REG_WRITE(UsartN::rxCompleteIntEnable(true));
        TEST_REG_WRITE(UsartN::rxCompleteIntEnable(false));
    }
#endif

#if REG_DEFINED(USART_N(TX_COMPLETE_INT_ENABLE_REG))
    TEST(UsartN, txCompleteIntEnable) {
        TEST_REG_WRITE(UsartN::txCompleteIntEnable(true));
        TEST_REG_WRITE(UsartN::txCompleteIntEnable(false));
    }
#endif

#if REG_DEFINED(USART_N(DATA_REG_EMPTY_INT_ENABLE_REG))
    TEST(UsartN, dataRegisterEmptyIntEnable) {
        TEST_REG_WRITE(UsartN::dataRegisterEmptyIntEnable(true));
        TEST_REG_WRITE(UsartN::dataRegisterEmptyIntEnable(false));
    }
#endif

#if REG_DEFINED(USART_N(TX_DATA_REG))
    TEST(UsartN, tx) {
        TEST_REG_WRITE(UsartN::tx(0x12));
    }
#endif

#if REG_DEFINED(USART_N(TX_DATA_9_REG))
    TEST(UsartN, tx9) {
        TEST_REG_WRITE(UsartN::tx9(true));
        TEST_REG_WRITE(UsartN::tx9(false));
    }
#endif

#if REG_DEFINED(USART_N(RX_DATA_REG))
    TEST(UsartN, rx) {
        TEST_REG_READ_WRITE(UsartN::rx());
    }
#endif

#if REG_DEFINED(USART_N(RX_DATA_9_REG))
    TEST(UsartN, rx9) {
        TEST_REG_READ_WRITE(UsartN::rx9());
    }
#endif

#if REG_DEFINED(USART_N(FRAME_ERROR_REG))
    TEST(UsartN, frameError) {
        TEST_REG_READ_WRITE(UsartN::frameError());
    }
#endif

#if REG_DEFINED(USART_N(DATA_OVERRUN_REG))
    TEST(UsartN, dataOverRun) {
        TEST_REG_READ_WRITE(UsartN::dataOverRun());
    }
#endif

#if REG_DEFINED(USART_N(PARITY_ERROR_REG))
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

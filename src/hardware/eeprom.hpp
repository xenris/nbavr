/// [[Index]]

/// # {{Eeprom}}

#ifndef NBLIB_EEPROM_HPP

#include "chip.hpp"
#include "hardwaretype.hpp"
#include "isr.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define EepromN CAT(Eeprom, N)
    #define EEPROM_N(A) CAT(CHIP_EEPROM_, N, _, A)

    #if DEFINED(CAT(CHIP_EEPROM_, N))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{EepromN}}
struct EepromN {
    EepromN() = delete;

    /// #### enum {{AdcN::Mode}}
    /// * eraseWrite
    /// * eraseOnly
    /// * writeOnly
    enum class Mode {
        eraseWrite = EEPROM_N(PROGRAMMING_MODE_ERASE_WRITE_ID),
        eraseOnly = EEPROM_N(PROGRAMMING_MODE_ERASE_ONLY_ID),
        writeOnly = EEPROM_N(PROGRAMMING_MODE_WRITE_ONLY_ID),
    };

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::eeprom;
    }

    #if REG_DEFINED(EEPROM_N(PROGRAMMING_MODE_REG))
        /// #### static void mode([[AdcN::Mode]] m)
        static force_inline void mode(Mode m) {
            EEPROM_N(PROGRAMMING_MODE_REG)::setBits(EEPROM_N(PROGRAMMING_MODE_MASK), m);
        }
    #endif

    #if REG_DEFINED(EEPROM_N(ADDRESS_REG))
        /// #### static void address(uint16_t a)
        static force_inline void address(uint16_t a) {
            EEPROM_N(ADDRESS_REG)::setReg(a);
        }
    #endif

    #if REG_DEFINED(EEPROM_N(DATA_REG))
        /// #### static void data(uint8_t d)
        static force_inline void data(uint8_t d) {
            EEPROM_N(DATA_REG)::setReg(d);
        }

        /// #### static uint8_t data()
        static force_inline uint8_t data() {
            return EEPROM_N(DATA_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(EEPROM_N(MASTER_WRITE_ENABLE_REG))
        /// #### static void masterWriteEnable()
        /// Enable the Eeprom write.
        static force_inline void masterWriteEnable() {
            EEPROM_N(MASTER_WRITE_ENABLE_REG)::setBit(EEPROM_N(MASTER_WRITE_ENABLE_BIT), true);
        }
    #endif

    #if REG_DEFINED(EEPROM_N(WRITE_ENABLE_REG))
        /// #### static void writeEnable()
        /// Start an Eeprom write.
        static force_inline void writeEnable() {
            EEPROM_N(WRITE_ENABLE_REG)::setBit(EEPROM_N(WRITE_ENABLE_BIT), true);
        }
    #endif

    #if REG_DEFINED(EEPROM_N(WRITE_ENABLE_REG))
        /// #### static bool writeEnabled()
        /// Returns true if Eeprom is currently writing.
        static force_inline bool writeEnabled() {
            return EEPROM_N(WRITE_ENABLE_REG)::getBit(EEPROM_N(WRITE_ENABLE_BIT));
        }
    #endif

    #if REG_DEFINED(EEPROM_N(READ_ENABLE_REG))
        /// #### static void readEnable()
        /// Start an Eeprom read.
        static force_inline void readEnable() {
            EEPROM_N(READ_ENABLE_REG)::setBit(EEPROM_N(READ_ENABLE_BIT), true);
        }
    #endif

    #if REG_DEFINED(EEPROM_N(READY_INT_ENABLE_REG))
        /// #### static void intEnable(bool e)
        static force_inline void intEnable(bool e) {
            EEPROM_N(READY_INT_ENABLE_REG)::setBit(EEPROM_N(READY_INT_ENABLE_BIT), e);
        }
    #endif
};

#ifdef TEST

TEST(EepromN, getHardwareType) {
    ASSERT_EQ(EepromN::getHardwareType(), HardwareType::eeprom);
}

TEST(EepromN, mode) {
    TEST_REG_WRITE(EepromN::mode(EepromN::Mode::eraseWrite));
    TEST_REG_WRITE(EepromN::mode(EepromN::Mode::eraseOnly));
    TEST_REG_WRITE(EepromN::mode(EepromN::Mode::writeOnly));
}

TEST(EepromN, address) {
    TEST_REG_WRITE(EepromN::address(0x1234));
}

TEST(EepromN, data) {
    TEST_REG_WRITE(EepromN::data(0x12));
    TEST_REG_READ_WRITE(EepromN::data());
}

TEST(EepromN, masterWriteEnable) {
    TEST_REG_WRITE(EepromN::masterWriteEnable());
}

TEST(EepromN, writeEnable) {
    TEST_REG_WRITE(EepromN::writeEnable());
}

TEST(EepromN, writeEnabled) {
    TEST_REG_READ_WRITE(EepromN::writeEnabled());
}

TEST(EepromN, readEnable) {
    TEST_REG_WRITE(EepromN::readEnable());
}

TEST(EepromN, intEnable) {
    TEST_REG_WRITE(EepromN::intEnable(true));
    TEST_REG_WRITE(EepromN::intEnable(false));
}

#endif

} // nblib::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef EepromN
    #undef EEPROM_N

    #include "eeprom.hpp"
#else
    #define NBLIB_EEPROM_HPP
#endif

#endif

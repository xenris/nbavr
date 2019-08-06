/// [[Index]]

/// # {{Eeprom}}

/// ```c++
/// atomic {
///     nblib::hw::Eeprom0::address(0x00);
///     nblib::hw::Eeprom0::data(0x01);
///     nblib::hw::Eeprom0::masterWriteEnable();
///     nblib::hw::Eeprom0::writeEnable();
/// }
///
/// while(nblib::hw::Eeprom0::writeEnabled());
///
/// nblib::hw::Eeprom0::address(0x00);
/// nblib::hw::Eeprom0::readEnable();
///
/// uint8_t n = nblib::hw::Eeprom0::data();
/// ```

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

    #if CAT(CHIP_EEPROM_, N)

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

    /// #### static void mode([[AdcN::Mode]] m)
    static force_inline void mode(Mode m) {
        setBit_(REG(EEPROM_N(PROGRAMMING_MODE_BIT_0_REG)), EEPROM_N(PROGRAMMING_MODE_BIT_0_BIT), int(m) & 0x01);
        setBit_(REG(EEPROM_N(PROGRAMMING_MODE_BIT_1_REG)), EEPROM_N(PROGRAMMING_MODE_BIT_1_BIT), int(m) & 0x02);
    }

    /// #### static void address(uint16_t a)
    static force_inline void address(uint16_t a) {
        setReg(REG(EEPROM_N(ADDRESS_REG)), a);
    }

    /// #### static void data(uint8_t d)
    static force_inline void data(uint8_t d) {
        setReg_(REG(EEPROM_N(DATA_REG)), d);
    }

    /// #### static uint8_t data()
    static force_inline uint8_t data() {
        return getReg_(REG(EEPROM_N(DATA_REG)));
    }

    /// #### static void masterWriteEnable()
    /// Enable the Eeprom write.
    static force_inline void masterWriteEnable() {
        setBit_(REG(EEPROM_N(MASTER_WRITE_ENABLE_REG)), EEPROM_N(MASTER_WRITE_ENABLE_BIT), true);
    }

    /// #### static void writeEnable()
    /// Start an Eeprom write.
    static force_inline void writeEnable() {
        setBit_(REG(EEPROM_N(WRITE_ENABLE_REG)), EEPROM_N(WRITE_ENABLE_BIT), true);
    }

    /// #### static bool writeEnabled()
    /// Returns true if Eeprom is currently writing.
    static force_inline bool writeEnabled() {
        return getBit_(REG(EEPROM_N(WRITE_ENABLE_REG)), EEPROM_N(WRITE_ENABLE_BIT));
    }

    /// #### static void readEnable()
    /// Start an Eeprom read.
    static force_inline void readEnable() {
        setBit_(REG(EEPROM_N(READ_ENABLE_REG)), EEPROM_N(READ_ENABLE_BIT), true);
    }

    /// #### static void setCallback([[Callback]]<T\> function, T\* data)
    template <class T>
    static force_inline void setCallback(Callback<T> function, T* data = nullptr) {
        callback((Callback<void>)function, data);
    }

    /// #### static void callCallback()
    static force_inline void callCallback() {
        callback();
    }

    /// #### static void intEnable(bool e)
    static force_inline void intEnable(bool e) {
        setBit_(REG(EEPROM_N(READY_INT_ENABLE_REG)), EEPROM_N(READY_INT_ENABLE_BIT), e);
    }

private:

    static force_inline void callback(Callback<void> function = nullptr, void* data = nullptr) {
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

ISR(EEPROM_N(EE_READY_INT_VECTOR)) {
    EepromN::callCallback();
}

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

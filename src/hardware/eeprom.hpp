/// [[Index]]

/// # {{Eeprom}}

/// ```c++
/// atomic([]() {
///     nbos::hw::Eeprom0::address(0x00);
///     nbos::hw::Eeprom0::data(0x01);
///     nbos::hw::Eeprom0::masterWriteEnable();
///     nbos::hw::Eeprom0::writeEnable();
/// });
///
/// while(nbos::hw::Eeprom0::writeEnabled());
///
/// nbos::hw::Eeprom0::address(0x00);
/// nbos::hw::Eeprom0::readEnable();
///
/// uint8_t n = nbos::hw::Eeprom0::data();
/// ```

#ifndef NBOS_EEPROM_HPP

#include "chip.hpp"
#include "hardwaretype.hpp"
#include "isr.hpp"
#include "macros.hpp"
#include "type.hpp"
#include "system.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define EepromN CAT(Eeprom, N)
    #define EEPROM_N(A) CAT(CHIP_EEPROM_, N, _, A)

    #if CAT(CHIP_EEPROM_, N)

//------------------------------------------------------------------

namespace nbos::hw {

/// ## class {{EepromN}}
struct EepromN {
    EepromN() = delete;

    /// #### enum {{AdcN::Mode}}
    /// * eraseWrite
    /// * eraseOnly
    /// * writeOnly
    enum class Mode : uint8_t {
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
        setBit_(REG(EEPROM_N(PROGRAMMING_MODE_BIT_0_REG)), EEPROM_N(PROGRAMMING_MODE_BIT_0_BIT), uint8_t(m) & 0x01);
        setBit_(REG(EEPROM_N(PROGRAMMING_MODE_BIT_1_REG)), EEPROM_N(PROGRAMMING_MODE_BIT_1_BIT), uint8_t(m) & 0x02);
    }

    /// #### static void address(uint16_t a)
    static force_inline void address(uint16_t a) {
        *REG(EEPROM_N(ADDRESS_REG)) = a;
    }

    /// #### static void data(uint8_t d)
    static force_inline void data(uint8_t d) {
        *REG(EEPROM_N(DATA_REG)) = d;
    }

    /// #### static uint8_t data()
    static force_inline uint8_t data() {
        return *REG(EEPROM_N(DATA_REG));
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
        return *REG(EEPROM_N(WRITE_ENABLE_REG)) & bv(EEPROM_N(WRITE_ENABLE_BIT));
    }

    /// #### static void readEnable()
    /// Start an Eeprom read.
    static force_inline void readEnable() {
        setBit_(REG(EEPROM_N(READ_ENABLE_REG)), EEPROM_N(READ_ENABLE_BIT), true);
    }

    /// #### static void callback([[callback_t]] callback, void\* data)
    static force_inline void callback(callback_t callback = nullptr, void* data = nullptr) {
        static callback_t f = nullptr;
        static void* d = nullptr;

        if(callback == nullptr) {
            if(f != nullptr) {
                f(d);
            }
        } else {
            f = callback;
            d = data;
        }
    }

    /// #### static void intEnable(bool e)
    static force_inline void intEnable(bool e) {
        setBit_(REG(EEPROM_N(READY_INT_ENABLE_REG)), EEPROM_N(READY_INT_ENABLE_BIT), e);
    }
};

ISR(EEPROM_N(EE_READY_INT_VECTOR)) {
    EepromN::callback();
}

} // nbos::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef EepromN
    #undef EEPROM_N

    #include "eeprom.hpp"
#else
    #define NBOS_EEPROM_HPP
#endif

#endif

/// # EEPROM

#ifndef NBOS_EEPROM_HPP

#include "callbacks.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "type.hpp"
#include "util.hpp"

#define N _I
#define EepromN CAT(Eeprom, N)
#define EEPROM_N(A) CAT(CHIP_EEPROM_, N, _, A)
#define _EEPROM_N(A) UNDERLINE(EEPROM, N, A)

/// #### macro INCLUDE_EEPROM_CALLBACK()
/// Include this to use Eeprom callbacks.
#define INCLUDE_EEPROM_CALLBACK(N) MAKE_CALLBACK(EEPROM, N)

#include "loopi"

#ifdef _I
    #if CAT(CHIP_EEPROM_, N)

//------------------------------------------------------------------

MAKE_CALLBACK_HEADER(EEPROM, N);

/// ## class Eeprom
struct Eeprom {
    Eeprom() = delete;

    /// #### enum Mode
    /// * EraseWrite
    /// * EraseOnly
    /// * WriteOnly
    enum class Mode : uint8_t {
        EraseWrite = EEPROM_N(PROGRAMMING_MODE_ERASE_WRITE_ID),
        EraseOnly = EEPROM_N(PROGRAMMING_MODE_ERASE_ONLY_ID),
        WriteOnly = EEPROM_N(PROGRAMMING_MODE_WRITE_ONLY_ID),
    };

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::eeprom;
    }

    /// #### static void mode(Mode m)
    /// Set the programming mode.
    static force_inline void mode(Mode m) {
        setBit_(REG(EEPROM_N(PROGRAMMING_MODE_BIT_0_REG)), EEPROM_N(PROGRAMMING_MODE_BIT_0_BIT), uint8_t(m) & 0x01);
        setBit_(REG(EEPROM_N(PROGRAMMING_MODE_BIT_1_REG)), EEPROM_N(PROGRAMMING_MODE_BIT_1_BIT), uint8_t(m) & 0x02);
    }

    /// #### static void address(uint16_t a)
    /// Set the eeprom memory address to access.
    static force_inline void address(uint16_t a) {
        *REG(EEPROM_N(ADDRESS_REG)) = a;
    }

    /// #### static void data(uint8_t d)
    /// Set the data to write.
    static force_inline void data(uint8_t d) {
        *REG(EEPROM_N(DATA_REG)) = d;
    }

    /// #### static uint8_t data()
    /// Returns the data read or written.
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

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback and data for when the Eeprom is ready.
    static force_inline void callback(callback_t callback, void* data) {
        _EEPROM_N(Callback) = callback;
        _EEPROM_N(CallbackData) = data;
    }

    /// #### static void intEnable(bool e)
    /// Enable/disable the Eeprom ready interrupt.
    static force_inline void intEnable(bool e) {
        setBit_(REG(EEPROM_N(READY_INT_ENABLE_REG)), EEPROM_N(READY_INT_ENABLE_BIT), e);
    }
};

//--------------------------------------------------------

    #endif

    #include "eeprom.hpp"
#else
    #define NBOS_EEPROM_HPP
#endif

#undef N
#undef EepromN
#undef EEPROM_N
#undef _EEPROM_N

#endif

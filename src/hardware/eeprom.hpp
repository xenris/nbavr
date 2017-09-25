/// # EEPROM

#ifndef NBAVR_EEPROM_HPP
#define NBAVR_EEPROM_HPP

#ifdef CHIP_EEPROM

MAKE_CALLBACK_HEADER(EEPROM_EE_READY);

/// #### macro INCLUDE_EEPROM_CALLBACK()
/// Include this to use Eeprom callbacks.
#define INCLUDE_EEPROM_CALLBACK() MAKE_CALLBACK(EEPROM_EE_READY)

/// ## class Eeprom
struct Eeprom {
    Eeprom() = delete;

    /// #### enum Mode
    /// * EraseWrite
    /// * EraseOnly
    /// * WriteOnly
    enum class Mode : uint8_t {
        EraseWrite = CHIP_EEPROM_PROGRAMMING_MODE_ERASE_WRITE_ID,
        EraseOnly = CHIP_EEPROM_PROGRAMMING_MODE_ERASE_ONLY_ID,
        WriteOnly = CHIP_EEPROM_PROGRAMMING_MODE_WRITE_ONLY_ID,
    };

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::Eeprom;
    }

    /// #### static void mode(Mode m)
    /// Set the programming mode.
    static force_inline void mode(Mode m) {
        setBit_(CHIP_EEPROM_PROGRAMMING_MODE_BIT_0_REG, CHIP_EEPROM_PROGRAMMING_MODE_BIT_0_BIT, uint8_t(m) & 0x01);
        setBit_(CHIP_EEPROM_PROGRAMMING_MODE_BIT_1_REG, CHIP_EEPROM_PROGRAMMING_MODE_BIT_1_BIT, uint8_t(m) & 0x02);
    }

    /// #### static void address(uint16_t a)
    /// Set the eeprom memory address to access.
    static force_inline void address(uint16_t a) {
        *CHIP_EEPROM_ADDRESS_REG = a;
    }

    /// #### static void data(uint8_t d)
    /// Set the data to write.
    static force_inline void data(uint8_t d) {
        *CHIP_EEPROM_DATA_REG = d;
    }

    /// #### static uint8_t data()
    /// Returns the data read or written.
    static force_inline uint8_t data() {
        return *CHIP_EEPROM_DATA_REG;
    }

    /// #### static void masterWriteEnable()
    /// Enable the Eeprom write.
    static force_inline void masterWriteEnable() {
        setBit_(CHIP_EEPROM_MASTER_WRITE_ENABLE_REG, CHIP_EEPROM_MASTER_WRITE_ENABLE_BIT, true);
    }

    /// #### static void writeEnable()
    /// Start an Eeprom write.
    static force_inline void writeEnable() {
        setBit_(CHIP_EEPROM_WRITE_ENABLE_REG, CHIP_EEPROM_WRITE_ENABLE_BIT, true);
    }

    /// #### static bool writeEnabled()
    /// Returns true if Eeprom is currently writing.
    static force_inline bool writeEnabled() {
        return *CHIP_EEPROM_WRITE_ENABLE_REG & bv(CHIP_EEPROM_WRITE_ENABLE_BIT);
    }

    /// #### static void readEnable()
    /// Start an Eeprom read.
    static force_inline void readEnable() {
        setBit_(CHIP_EEPROM_READ_ENABLE_REG, CHIP_EEPROM_READ_ENABLE_BIT, true);
    }

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback and data for when the Eeprom is ready.
    static force_inline void callback(callback_t callback, void* data) {
        _EEPROM_EE_READY_Callback_ = callback;
        _EEPROM_EE_READY_CallbackData_ = data;
    }

    /// #### static void intEnable(bool e)
    /// Enable/disable the Eeprom ready interrupt.
    static force_inline void intEnable(bool e) {
        setBit_(CHIP_EEPROM_READY_INT_ENABLE_REG, CHIP_EEPROM_READY_INT_ENABLE_BIT, e);
    }
};

#endif // #ifdef CHIP_EEPROM

#endif

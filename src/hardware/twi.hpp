/// # Two Wire Serial Interface
///
/// ## Example
///
/// TODO

#ifndef NBAVR_TWI_HPP
#define NBAVR_TWI_HPP

#ifdef CHIP_TWI

MAKE_CALLBACK_HEADER(TWI);

/// #### macro INCLUDE_TWI_CALLBACK()
/// Include this to use Twi callbacks.
#define INCLUDE_TWI_CALLBACK() MAKE_CALLBACK(TWI)

/// ## class Twi
struct Twi {
    Twi() = delete;

    ///
    /// #### enum Prescaler
    /// * Div1
    /// * Div4
    /// * Div16
    /// * Div64
    enum class Prescaler : uint8_t {
        Div1 = CHIP_TWI_PRESCALER_1_ID,
        Div4 = CHIP_TWI_PRESCALER_4_ID,
        Div16 = CHIP_TWI_PRESCALER_16_ID,
        Div64 = CHIP_TWI_PRESCALER_64_ID,
    };

    ///
    /// #### enum Status
    /// * StartTransmitted
    /// * RepeatedStartTransmitted
    /// * SLAWTransmittedAck
    /// * SLAWTransmittedNack
    /// * DataTransmittedAck
    /// * DataTransmittedNack
    /// * ArbitrationLost
    /// * SLARTransmittedAck
    /// * SLARTransmittedNack
    /// * DataReceivedAck
    /// * DataReceivedNack
    /// * OwnSLAWReceivedAck
    /// * ArbitrationLostOwnSLAWAck
    /// * GeneralCallAddressReceivedAck
    /// * ArbitrationLostGeneralCallAddressReceivedAck
    /// * PrevAddressedOwnSLAWDataReceivedAck
    /// * PrevAddressedOwnSLAWDataReceivedNack
    /// * PrevAddressedGeneralCallDataReceivedAck
    /// * PrevAddressedGeneralCallDataReceivedNack
    /// * StopOrRepeatedStartWhileAddressedAsSlave
    /// * OwnSLARReceivedAck
    /// * ArbitrationLostOwnSLARAck
    /// * DataInTWDRTransmittedAck
    /// * DataInTWDRTransmittedNack
    /// * LastDataTransmittedAck
    /// * NoState
    /// * BusError
    enum class Status : uint8_t {
        StartTransmitted = 0x08,
        RepeatedStartTransmitted = 0x10,
        SLAWTransmittedAck = 0x18,
        SLAWTransmittedNack = 0x20,
        DataTransmittedAck = 0x28,
        DataTransmittedNack = 0x30,
        ArbitrationLost = 0x38,
        SLARTransmittedAck = 0x40,
        SLARTransmittedNack = 0x48,
        DataReceivedAck = 0x50,
        DataReceivedNack = 0x58,
        OwnSLAWReceivedAck = 0x60,
        ArbitrationLostOwnSLAWAck = 0x68,
        GeneralCallAddressReceivedAck = 0x70,
        ArbitrationLostGeneralCallAddressReceivedAck = 0x78,
        PrevAddressedOwnSLAWDataReceivedAck = 0x80,
        PrevAddressedOwnSLAWDataReceivedNack = 0x88,
        PrevAddressedGeneralCallDataReceivedAck = 0x90,
        PrevAddressedGeneralCallDataReceivedNack = 0x98,
        StopOrRepeatedStartWhileAddressedAsSlave = 0xA0,
        OwnSLARReceivedAck = 0xA8,
        ArbitrationLostOwnSLARAck = 0xB0,
        DataInTWDRTransmittedAck = 0xB8,
        DataInTWDRTransmittedNack = 0xC0,
        LastDataTransmittedAck = 0xC8,
        NoState = 0xF8,
        BusError = 0x00,
    };

    ///
    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::Twi;
    }

    ///
    /// #### static void enable(bool)
    /// Enable/disable the two wire serial interface.
    static force_inline void enable(bool e) {
        setBit_(CHIP_TWI_ENABLE_REG, CHIP_TWI_ENABLE_BIT, e);
    }

    ///
    /// #### static void baud(uint16_t)
    /// Set USART baud rate.
    static force_inline void bitRate(uint8_t b) {
        *CHIP_TWI_BIT_RATE_REG = b;
    }

    ///
    /// #### static bool intFlag()
    /// Returns true if the interrupt flag is set.
    static force_inline bool intFlag() {
        return *CHIP_TWI_INT_FLAG_REG & bv(CHIP_TWI_INT_FLAG_BIT);
    }

    ///
    /// #### static void intFlagClear()
    /// Clear the interrupt flag.
    static force_inline void intFlagClear() {
        setBit_(CHIP_TWI_INT_FLAG_REG, CHIP_TWI_INT_FLAG_BIT, true);
    }

    ///
    /// #### static void enableAcknowledge(bool e)
    /// Enable/disable acknowledge pulse.
    static force_inline void enableAcknowledge(bool e) {
        setBit_(CHIP_TWI_ENABLE_ACK_REG, CHIP_TWI_ENABLE_ACK_BIT, e);
    }

    /// #### static void startCondition(bool e)
    /// Enable/disable start condition.
    static force_inline void startCondition(bool e) {
        setBit_(CHIP_TWI_START_CONDITION_REG, CHIP_TWI_START_CONDITION_BIT, e);
    }

    ///
    /// #### static bool startCondition()
    /// Returns true if start condition is set.
    static force_inline bool startCondition() {
        return *CHIP_TWI_START_CONDITION_REG & bv(CHIP_TWI_START_CONDITION_BIT);
    }

    ///
    /// #### static void stopCondition(bool e)
    /// Enable/disable stop condition.
    static force_inline void stopCondition(bool e) {
        setBit_(CHIP_TWI_STOP_CONDITION_REG, CHIP_TWI_STOP_CONDITION_BIT, e);
    }

    ///
    /// #### static bool stopCondition()
    /// Returns true if stop condition is set.
    static force_inline bool stopCondition() {
        return *CHIP_TWI_STOP_CONDITION_REG & bv(CHIP_TWI_STOP_CONDITION_BIT);
    }

    ///
    /// #### static bool writeCollisionFlag()
    /// Returns true if the write collision flag is set.
    static force_inline bool writeCollisionFlag() {
        return *CHIP_TWI_WRITE_COLLISION_FLAG_REG & bv(CHIP_TWI_WRITE_COLLISION_FLAG_BIT);
    }

    ///
    /// #### static void writeCollisionFlagClear()
    /// Clear the write collision flag.
    static force_inline void writeCollisionFlagClear() {
        setBit_(CHIP_TWI_WRITE_COLLISION_FLAG_REG, CHIP_TWI_WRITE_COLLISION_FLAG_BIT, true);
    }

    ///
    /// #### static void intEnable(bool e)
    /// Enable/disable the Twi interrupt.
    static force_inline void intEnable(bool e) {
        setBit_(CHIP_TWI_INT_ENABLE_REG, CHIP_TWI_INT_ENABLE_BIT, e);
    }

    ///
    /// #### static void callback(void (\*)(void\*), void\*)
    /// Set the callback and data for Twi interrupts.
    static force_inline void callback(void (*func)(void*), void* data) {
        _TWI_Callback_ = func;
        _TWI_CallbackData_ = data;
    }

    ///
    /// #### static Status status()
    /// Get the Twi status.
    static force_inline Status status() {
        return Status(*CHIP_TWI_STATUS_REG & 0xF8);
    }

    ///
    /// #### static void prescaler(Prescaler)
    /// Set the prescaler.
    static force_inline void prescaler(Prescaler pre) {
        setBit_(CHIP_TWI_PRESCALER_BIT_0_REG, CHIP_TWI_PRESCALER_BIT_0_BIT, uint8_t(pre) & 0x01);
        setBit_(CHIP_TWI_PRESCALER_BIT_1_REG, CHIP_TWI_PRESCALER_BIT_1_BIT, uint8_t(pre) & 0x02);
    }

    ///
    /// #### static void push(uint8_t)
    /// Send a byte.
    static force_inline void push(uint8_t b) {
        *CHIP_TWI_DATA_REG = b;
    }

    ///
    /// #### static uint8_t pop()
    /// Get the last received byte.
    static force_inline uint8_t pop() {
        return *CHIP_TWI_DATA_REG;
    }

    ///
    /// #### static void slaveAddress(uint8_t)
    /// Set the address for transmitting and receiving as a slave.
    static force_inline void slaveAddress(uint8_t b) {
        *CHIP_TWI_SLAVE_ADDRESS_REG = b & 0xfe;
    }

    ///
    /// #### static void slaveAddressMask(uint8_t)
    /// Set the slave address mask.
    static force_inline void slaveAddressMask(uint8_t b) {
        *CHIP_TWI_SLAVE_ADDRESS_MASK_REG = b & 0xfe;
    }

    ///
    /// #### static void generalCallRecognitionEnable(bool e)
    /// Enable/disable the recognition of a Twi general call.
    static force_inline void generalCallRecognitionEnable(bool e) {
        setBit_(CHIP_TWI_GEN_CALL_REC_ENABLE_REG, CHIP_TWI_GEN_CALL_REC_ENABLE_BIT, e);
    }
};

#endif // #ifdef CHIP_TWI

#endif

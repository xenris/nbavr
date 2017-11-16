/// # Two Wire Serial Interface

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
        BusError = 0x00,
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
    };

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::Twi;
    }

    /// #### static void enable(bool e)
    /// Enable/disable the Twi.
    static force_inline void enable(bool e) {
        setBit_(CHIP_TWI_ENABLE_REG, CHIP_TWI_ENABLE_BIT, e);
    }

    /// #### static void sendStart(bool intEnable = true)
    /// Send a start condition.
    static force_inline void sendStart(bool intEnable = true) {
        const uint8_t enable = bv(CHIP_TWI_ENABLE_BIT);
        const uint8_t start = bv(CHIP_TWI_START_CONDITION_BIT);
        const uint8_t flagClear = bv(CHIP_TWI_INT_FLAG_BIT);
        const uint8_t interrupt = intEnable ? bv(CHIP_TWI_INT_ENABLE_BIT) : 0;

        *CHIP_TWI_CONTROL_REG = enable | start | flagClear | interrupt;
    }

    /// #### static void sendStop(bool intEnable = true)
    /// Send stop condition.
    static force_inline void sendStop() {
        const uint8_t enable = bv(CHIP_TWI_ENABLE_BIT);
        const uint8_t stop = bv(CHIP_TWI_STOP_CONDITION_BIT);
        const uint8_t flagClear = bv(CHIP_TWI_INT_FLAG_BIT);

        *CHIP_TWI_CONTROL_REG = enable | stop | flagClear;
    }

    /// #### static void sendAck(bool intEnable = true)
    /// Send acknowledge condition.
    static force_inline void sendAck(bool intEnable = true) {
        const uint8_t enable = bv(CHIP_TWI_ENABLE_BIT);
        const uint8_t ack = bv(CHIP_TWI_ENABLE_ACK_BIT);
        const uint8_t flagClear = bv(CHIP_TWI_INT_FLAG_BIT);
        const uint8_t interrupt = intEnable ? bv(CHIP_TWI_INT_ENABLE_BIT) : 0;

        *CHIP_TWI_CONTROL_REG = enable | ack | flagClear | interrupt;
    }

    /// #### static void sendNack(bool intEnable = true)
    /// Send not acknowledge condition.
    static force_inline void sendNack(bool intEnable = true) {
        const uint8_t enable = bv(CHIP_TWI_ENABLE_BIT);
        const uint8_t flagClear = bv(CHIP_TWI_INT_FLAG_BIT);
        const uint8_t interrupt = intEnable ? bv(CHIP_TWI_INT_ENABLE_BIT) : 0;

        *CHIP_TWI_CONTROL_REG = enable | flagClear | interrupt;
    }

    /// #### static void bitRate(uint8_t b)
    /// Set Twi bitRate.
    static force_inline void bitRate(uint8_t b) {
        *CHIP_TWI_BIT_RATE_REG = b;
    }

    /// #### static bool intFlag()
    /// Returns true if the interrupt flag is set.
    static force_inline bool intFlag() {
        return *CHIP_TWI_INT_FLAG_REG & bv(CHIP_TWI_INT_FLAG_BIT);
    }

    /// #### static bool active()
    /// Returns true if the twi hardware is busy.
    static force_inline bool active() {
        if(*CHIP_TWI_CONTROL_REG | bv(CHIP_TWI_ENABLE_BIT)) {
            return *CHIP_TWI_CONTROL_REG & (bv(CHIP_TWI_START_CONDITION_BIT) | bv(CHIP_TWI_STOP_CONDITION_BIT));
        } else {
            return false;
        }
    }

    /// #### static bool writeCollisionFlag()
    /// Returns true if the write collision flag is set.
    static force_inline bool writeCollisionFlag() {
        return *CHIP_TWI_WRITE_COLLISION_FLAG_REG & bv(CHIP_TWI_WRITE_COLLISION_FLAG_BIT);
    }

    /// #### static void writeCollisionFlagClear()
    /// Clear the write collision flag.
    static force_inline void writeCollisionFlagClear() {
        setBit_(CHIP_TWI_WRITE_COLLISION_FLAG_REG, CHIP_TWI_WRITE_COLLISION_FLAG_BIT, true);
    }

    /// #### static void intEnable(bool e)
    /// Enable/disable the Twi interrupt.
    static force_inline void intEnable(bool e) {
        setBit_(CHIP_TWI_INT_ENABLE_REG, CHIP_TWI_INT_ENABLE_BIT, e);
    }

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback and data for Twi interrupts.
    static force_inline void callback(callback_t callback, void* data) {
        _TWI_Callback_ = callback;
        _TWI_CallbackData_ = data;
    }

    /// #### static Status status()
    /// Get the Twi status.
    static force_inline Status status() {
        return Status(*CHIP_TWI_STATUS_REG & 0xF8);
    }

    /// #### static void prescaler(Prescaler p)
    /// Set the prescaler.
    static force_inline void prescaler(Prescaler p) {
        setBit_(CHIP_TWI_PRESCALER_BIT_0_REG, CHIP_TWI_PRESCALER_BIT_0_BIT, uint8_t(p) & 0x01);
        setBit_(CHIP_TWI_PRESCALER_BIT_1_REG, CHIP_TWI_PRESCALER_BIT_1_BIT, uint8_t(p) & 0x02);
    }

    /// #### static void push(uint8_t b)
    /// Put byte in data buffer.
    static force_inline void push(uint8_t b) {
        *CHIP_TWI_DATA_REG = b;
    }

    /// #### static uint8_t pop()
    /// Get byte from data buffer.
    static force_inline uint8_t pop() {
        return *CHIP_TWI_DATA_REG;
    }

    /// #### static void slaveAddress(uint8_t b)
    /// Set the address for transmitting and receiving as a slave.
    static force_inline void slaveAddress(uint8_t b) {
        *CHIP_TWI_SLAVE_ADDRESS_REG = b & 0xfe;
    }

    /// #### static void slaveAddressMask(uint8_t b)
    /// Set the slave address mask.
    static force_inline void slaveAddressMask(uint8_t b) {
        *CHIP_TWI_SLAVE_ADDRESS_MASK_REG = b & 0xfe;
    }

    /// #### static void generalCallRecognitionEnable(bool e)
    /// Enable/disable the recognition of a Twi general call.
    static force_inline void generalCallRecognitionEnable(bool e) {
        setBit_(CHIP_TWI_GEN_CALL_REC_ENABLE_REG, CHIP_TWI_GEN_CALL_REC_ENABLE_BIT, e);
    }
};

#endif // #ifdef CHIP_TWI

#endif

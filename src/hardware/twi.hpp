/// # Two Wire Serial Interface

#ifndef NBOS_TWI_HPP

#include "callbacks.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "type.hpp"
#include "util.hpp"

#define N _I
#define TwiN CAT(Twi, N)
#define TWI_N(A) CAT(CHIP_TWI_, N, _, A)
#define _TWI_N(A) UNDERLINE(TWI, N, A)

/// #### macro INCLUDE_TWI_CALLBACK(N)
/// Include this to use Twi callbacks.
#define INCLUDE_TWI_CALLBACK(N) MAKE_CALLBACK(TWI, N)

#include "loopi"

#ifdef _I
    #if CAT(CHIP_TWI_, N)

//------------------------------------------------------------------

MAKE_CALLBACK_HEADER(TWI, N);

/// ## class TwiN
struct TwiN {
    TwiN() = delete;
    TwiN& operator=(const TwiN&) = delete;
    TwiN(const TwiN&) = delete;

    /// #### enum Prescaler
    /// * Div1
    /// * Div4
    /// * Div16
    /// * Div64
    enum class Prescaler : uint8_t {
        Div1 = TWI_N(PRESCALER_1_ID),
        Div4 = TWI_N(PRESCALER_4_ID),
        Div16 = TWI_N(PRESCALER_16_ID),
        Div64 = TWI_N(PRESCALER_64_ID),
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
        return HardwareType::twi;
    }

    /// #### static void enable(bool e)
    /// Enable/disable the Twi.
    static force_inline void enable(bool e) {
        setBit_(REG(TWI_N(ENABLE_REG)), TWI_N(ENABLE_BIT), e);
    }

    /// #### static void sendStart(bool intEnable = true)
    /// Send a start condition.
    static force_inline void sendStart(bool intEnable = true) {
        const uint8_t enable = bv(TWI_N(ENABLE_BIT));
        const uint8_t start = bv(TWI_N(START_CONDITION_BIT));
        const uint8_t flagClear = bv(TWI_N(INT_FLAG_BIT));
        const uint8_t interrupt = intEnable ? bv(TWI_N(INT_ENABLE_BIT)) : 0;

        *REG(TWI_N(CONTROL_REG)) = enable | start | flagClear | interrupt;
    }

    /// #### static void sendStop(bool intEnable = true)
    /// Send stop condition.
    static force_inline void sendStop() {
        const uint8_t enable = bv(TWI_N(ENABLE_BIT));
        const uint8_t stop = bv(TWI_N(STOP_CONDITION_BIT));
        const uint8_t flagClear = bv(TWI_N(INT_FLAG_BIT));

        *REG(TWI_N(CONTROL_REG)) = enable | stop | flagClear;
    }

    /// #### static void sendAck(bool intEnable = true)
    /// Send acknowledge condition.
    static force_inline void sendAck(bool intEnable = true) {
        const uint8_t enable = bv(TWI_N(ENABLE_BIT));
        const uint8_t ack = bv(TWI_N(ENABLE_ACK_BIT));
        const uint8_t flagClear = bv(TWI_N(INT_FLAG_BIT));
        const uint8_t interrupt = intEnable ? bv(TWI_N(INT_ENABLE_BIT)) : 0;

        *REG(TWI_N(CONTROL_REG)) = enable | ack | flagClear | interrupt;
    }

    /// #### static void sendNack(bool intEnable = true)
    /// Send not acknowledge condition.
    static force_inline void sendNack(bool intEnable = true) {
        const uint8_t enable = bv(TWI_N(ENABLE_BIT));
        const uint8_t flagClear = bv(TWI_N(INT_FLAG_BIT));
        const uint8_t interrupt = intEnable ? bv(TWI_N(INT_ENABLE_BIT)) : 0;

        *REG(TWI_N(CONTROL_REG)) = enable | flagClear | interrupt;
    }

    /// #### static void bitRate(uint8_t b)
    /// Set Twi bitRate.
    static force_inline void bitRate(uint8_t b) {
        *REG(TWI_N(BIT_RATE_REG)) = b;
    }

    /// #### static bool intFlag()
    /// Returns true if the interrupt flag is set.
    static force_inline bool intFlag() {
        return *REG(TWI_N(INT_FLAG_REG)) & bv(TWI_N(INT_FLAG_BIT));
    }

    /// #### static bool active()
    /// Returns true if the twi hardware is busy.
    static force_inline bool active() {
        if(*REG(TWI_N(CONTROL_REG)) | bv(TWI_N(ENABLE_BIT))) {
            return *REG(TWI_N(CONTROL_REG)) & (bv(TWI_N(START_CONDITION_BIT)) | bv(TWI_N(STOP_CONDITION_BIT)));
        } else {
            return false;
        }
    }

    /// #### static bool writeCollisionFlag()
    /// Returns true if the write collision flag is set.
    static force_inline bool writeCollisionFlag() {
        return *REG(TWI_N(WRITE_COLLISION_FLAG_REG)) & bv(TWI_N(WRITE_COLLISION_FLAG_BIT));
    }

    /// #### static void writeCollisionFlagClear()
    /// Clear the write collision flag.
    static force_inline void writeCollisionFlagClear() {
        setBit_(REG(TWI_N(WRITE_COLLISION_FLAG_REG)), TWI_N(WRITE_COLLISION_FLAG_BIT), true);
    }

    /// #### static void intEnable(bool e)
    /// Enable/disable the Twi interrupt.
    static force_inline void intEnable(bool e) {
        setBit_(REG(TWI_N(INT_ENABLE_REG)), TWI_N(INT_ENABLE_BIT), e);
    }

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback and data for Twi interrupts.
    static force_inline void callback(callback_t callback, void* data) {
        _TWI_N(Callback) = callback;
        _TWI_N(CallbackData) = data;
    }

    /// #### static Status status()
    /// Get the Twi status.
    static force_inline Status status() {
        return Status(*REG(TWI_N(STATUS_REG)) & 0xF8);
    }

    /// #### static void prescaler(Prescaler p)
    /// Set the prescaler.
    static force_inline void prescaler(Prescaler p) {
        setBit_(REG(TWI_N(PRESCALER_BIT_0_REG)), TWI_N(PRESCALER_BIT_0_BIT), uint8_t(p) & 0x01);
        setBit_(REG(TWI_N(PRESCALER_BIT_1_REG)), TWI_N(PRESCALER_BIT_1_BIT), uint8_t(p) & 0x02);
    }

    /// #### static void push(uint8_t b)
    /// Put byte in data buffer.
    static force_inline void push(uint8_t b) {
        *REG(TWI_N(DATA_REG)) = b;
    }

    /// #### static uint8_t pop()
    /// Get byte from data buffer.
    static force_inline uint8_t pop() {
        return *REG(TWI_N(DATA_REG));
    }

    /// #### static void slaveAddress(uint8_t b)
    /// Set the address for transmitting and receiving as a slave.
    static force_inline void slaveAddress(uint8_t b) {
        *REG(TWI_N(SLAVE_ADDRESS_REG)) = b & 0xfe;
    }

    /// #### static void slaveAddressMask(uint8_t b)
    /// Set the slave address mask.
    static force_inline void slaveAddressMask(uint8_t b) {
        *REG(TWI_N(SLAVE_ADDRESS_MASK_REG)) = b & 0xfe;
    }

    /// #### static void generalCallRecognitionEnable(bool e)
    /// Enable/disable the recognition of a Twi general call.
    static force_inline void generalCallRecognitionEnable(bool e) {
        setBit_(REG(TWI_N(GEN_CALL_REC_ENABLE_REG)), TWI_N(GEN_CALL_REC_ENABLE_BIT), e);
    }
};

//--------------------------------------------------------

    #endif

    #include "twi.hpp"
#else
    #define NBOS_TWI_HPP
#endif

#undef N
#undef TwiN
#undef TWI_N
#undef _TWI_N

#endif

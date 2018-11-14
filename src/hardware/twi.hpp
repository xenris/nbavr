/// [[Index]]

/// # {{Two Wire Serial Interfaces}}

#ifndef NBOS_TWI_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define TwiN CAT(Twi, N)
    #define TWI_N(A) CAT(CHIP_TWI_, N, _, A)
    #define _TWI_N(A) UNDERLINE(TWI, N, A)

    #if CAT(CHIP_TWI_, N)

//------------------------------------------------------------------

namespace nbos::hw {

/// ## class {{TwiN}}
struct TwiN {
    TwiN() = delete;
    TwiN& operator=(const TwiN&) = delete;
    TwiN(const TwiN&) = delete;

    /// #### enum {{TwiN::Prescaler}}
    /// * div1
    /// * div4
    /// * div16
    /// * div64
    enum class Prescaler {
        div1 = TWI_N(PRESCALER_1_ID),
        div4 = TWI_N(PRESCALER_4_ID),
        div16 = TWI_N(PRESCALER_16_ID),
        div64 = TWI_N(PRESCALER_64_ID),
    };

    /// #### enum {{TwiN::Status}}
    /// * startTransmitted
    /// * repeatedStartTransmitted
    /// * slawTransmittedAck
    /// * slawTransmittedNack
    /// * dataTransmittedAck
    /// * dataTransmittedNack
    /// * arbitrationLost
    /// * slarTransmittedAck
    /// * slarTransmittedNack
    /// * dataReceivedAck
    /// * dataReceivedNack
    /// * ownSlawReceivedAck
    /// * arbitrationLostOwnSlawAck
    /// * generalCallAddressReceivedAck
    /// * arbitrationLostGeneralCallAddressReceivedAck
    /// * prevAddressedOwnSlawDataReceivedAck
    /// * prevAddressedOwnSlawDataReceivedNack
    /// * prevAddressedGeneralCallDataReceivedAck
    /// * prevAddressedGeneralCallDataReceivedNack
    /// * stopOrRepeatedStartWhileAddressedAsSlave
    /// * ownSlarReceivedAck
    /// * arbitrationLostOwnSlarAck
    /// * dataInTwdrTransmittedAck
    /// * dataInTwdrTransmittedNack
    /// * lastDataTransmittedAck
    /// * noState
    /// * busError
    enum class Status {
        busError = 0x00,
        startTransmitted = 0x08,
        repeatedStartTransmitted = 0x10,
        slawTransmittedAck = 0x18,
        slawTransmittedNack = 0x20,
        dataTransmittedAck = 0x28,
        dataTransmittedNack = 0x30,
        arbitrationLost = 0x38,
        slarTransmittedAck = 0x40,
        slarTransmittedNack = 0x48,
        dataReceivedAck = 0x50,
        dataReceivedNack = 0x58,
        ownSlawReceivedAck = 0x60,
        arbitrationLostOwnSlawAck = 0x68,
        generalCallAddressReceivedAck = 0x70,
        arbitrationLostGeneralCallAddressReceivedAck = 0x78,
        prevAddressedOwnSlawDataReceivedAck = 0x80,
        prevAddressedOwnSlawDataReceivedNack = 0x88,
        prevAddressedGeneralCallDataReceivedAck = 0x90,
        prevAddressedGeneralCallDataReceivedNack = 0x98,
        stopOrRepeatedStartWhileAddressedAsSlave = 0xA0,
        ownSlarReceivedAck = 0xA8,
        arbitrationLostOwnSLARAck = 0xB0,
        dataInTwdrTransmittedAck = 0xB8,
        dataInTwdrTransmittedNack = 0xC0,
        lastDataTransmittedAck = 0xC8,
        noState = 0xF8,
    };

    /// #### static [[HardwareType]] getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::twi;
    }

    /// #### static void enable(Bool e)
    /// Enable/disable the Twi.
    static force_inline void enable(Bool e) {
        setBit_(REG(TWI_N(ENABLE_REG)), TWI_N(ENABLE_BIT), e);
    }

    /// #### static void sendStart(Bool intEnable = true)
    /// Send a start condition.
    static force_inline void sendStart(Bool intEnable = true) {
        const Word8 enable = bv(TWI_N(ENABLE_BIT));
        const Word8 start = bv(TWI_N(START_CONDITION_BIT));
        const Word8 flagClear = bv(TWI_N(INT_FLAG_BIT));
        const Word8 interrupt = intEnable ? bv(TWI_N(INT_ENABLE_BIT)) : 0;

        *REG(TWI_N(CONTROL_REG)) = enable | start | flagClear | interrupt;
    }

    /// #### static void sendStop(Bool intEnable = true)
    /// Send stop condition.
    static force_inline void sendStop() {
        const Word8 enable = bv(TWI_N(ENABLE_BIT));
        const Word8 stop = bv(TWI_N(STOP_CONDITION_BIT));
        const Word8 flagClear = bv(TWI_N(INT_FLAG_BIT));

        *REG(TWI_N(CONTROL_REG)) = enable | stop | flagClear;
    }

    /// #### static void sendAck(Bool intEnable = true)
    /// Send acknowledge condition.
    static force_inline void sendAck(Bool intEnable = true) {
        const Word8 enable = bv(TWI_N(ENABLE_BIT));
        const Word8 ack = bv(TWI_N(ENABLE_ACK_BIT));
        const Word8 flagClear = bv(TWI_N(INT_FLAG_BIT));
        const Word8 interrupt = intEnable ? bv(TWI_N(INT_ENABLE_BIT)) : 0;

        *REG(TWI_N(CONTROL_REG)) = enable | ack | flagClear | interrupt;
    }

    /// #### static void sendNack(Bool intEnable = true)
    /// Send not acknowledge condition.
    static force_inline void sendNack(Bool intEnable = true) {
        const Word8 enable = bv(TWI_N(ENABLE_BIT));
        const Word8 flagClear = bv(TWI_N(INT_FLAG_BIT));
        const Word8 interrupt = intEnable ? bv(TWI_N(INT_ENABLE_BIT)) : 0;

        *REG(TWI_N(CONTROL_REG)) = enable | flagClear | interrupt;
    }

    /// #### static void bitRate(Word8 b)
    /// Set Twi bitRate.
    static force_inline void bitRate(Word8 b) {
        *REG(TWI_N(BIT_RATE_REG)) = b;
    }

    /// #### static Bool intFlag()
    /// Returns true if the interrupt flag is set.
    static force_inline Bool intFlag() {
        return Bool(*REG(TWI_N(INT_FLAG_REG)) & bv(TWI_N(INT_FLAG_BIT)));
    }

    /// #### static Bool active()
    /// Returns true if the twi hardware is busy.
    static force_inline Bool active() {
        if(Bool(*REG(TWI_N(CONTROL_REG)) | bv(TWI_N(ENABLE_BIT)))) {
            return Bool(*REG(TWI_N(CONTROL_REG)) & (bv(TWI_N(START_CONDITION_BIT)) | bv(TWI_N(STOP_CONDITION_BIT))));
        } else {
            return false;
        }
    }

    /// #### static Bool writeCollisionFlag()
    /// Returns true if the write collision flag is set.
    static force_inline Bool writeCollisionFlag() {
        return Bool(*REG(TWI_N(WRITE_COLLISION_FLAG_REG)) & bv(TWI_N(WRITE_COLLISION_FLAG_BIT)));
    }

    /// #### static void writeCollisionFlagClear()
    /// Clear the write collision flag.
    static force_inline void writeCollisionFlagClear() {
        setBit_(REG(TWI_N(WRITE_COLLISION_FLAG_REG)), TWI_N(WRITE_COLLISION_FLAG_BIT), true);
    }

    /// #### static void intEnable(Bool e)
    /// Enable/disable the Twi interrupt.
    static force_inline void intEnable(Bool e) {
        setBit_(REG(TWI_N(INT_ENABLE_REG)), TWI_N(INT_ENABLE_BIT), e);
    }

    /// #### static void setCallback([[Callback]]<T\> function, T\* data)
    /// Set the callback for Twi interrupts.
    template <class T>
    static force_inline void setCallback(Callback<T> function, T* data = nullptr) {
        callback((Callback<void>)function, data);
    }

    /// #### static void callCallback()
    static force_inline void callCallback() {
        callback();
    }

    /// #### static [[TwiN::Status]] status()
    /// Get the Twi status.
    static force_inline Status status() {
        return Status(Int(*REG(TWI_N(STATUS_REG)) & 0xF8));
    }

    /// #### static void prescaler([[TwiN::Prescaler]] p)
    /// Set the prescaler.
    static force_inline void prescaler(Prescaler p) {
        setBit_(REG(TWI_N(PRESCALER_BIT_0_REG)), TWI_N(PRESCALER_BIT_0_BIT), Int(p) & 0x01);
        setBit_(REG(TWI_N(PRESCALER_BIT_1_REG)), TWI_N(PRESCALER_BIT_1_BIT), Int(p) & 0x02);
    }

    /// #### static void push(Word8 b)
    /// Put byte in data buffer.
    static force_inline void push(Word8 b) {
        *REG(TWI_N(DATA_REG)) = b;
    }

    /// #### static Word8 pop()
    /// Get byte from data buffer.
    static force_inline Word8 pop() {
        return *REG(TWI_N(DATA_REG));
    }

    /// #### static void slaveAddress(Word8 b)
    /// Set the address for transmitting and receiving as a slave.
    static force_inline void slaveAddress(Word8 b) {
        *REG(TWI_N(SLAVE_ADDRESS_REG)) = b & 0xfe;
    }

    /// #### static void slaveAddressMask(Word8 b)
    /// Set the slave address mask.
    static force_inline void slaveAddressMask(Word8 b) {
        *REG(TWI_N(SLAVE_ADDRESS_MASK_REG)) = b & 0xfe;
    }

    /// #### static void generalCallRecognitionEnable(Bool e)
    /// Enable/disable the recognition of a Twi general call.
    static force_inline void generalCallRecognitionEnable(Bool e) {
        setBit_(REG(TWI_N(GEN_CALL_REC_ENABLE_REG)), TWI_N(GEN_CALL_REC_ENABLE_BIT), e);
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

ISR(TWI_N(INT_VECTOR)) {
    TwiN::callCallback();
}

} // nbos::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef TwiN
    #undef TWI_N
    #undef _TWI_N

    #include "twi.hpp"
#else
    #define NBOS_TWI_HPP
#endif

#endif

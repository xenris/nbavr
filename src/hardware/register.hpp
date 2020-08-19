#ifndef NBLIB_REGISTER_HPP
#define NBLIB_REGISTER_HPP

#include "../primitive.hpp"
#include "../macros.hpp"
#include "chip.hpp"

// TODO Move block() macro out of system.hpp.
// Possibly also move atomic and nonatomic into their own files.

// TODO Move bv(T) somewhere else better.
/// #### T bv(T n)
/// Equivalent to "1 << n", but with correct types applied.
template <class T>
force_inline T bv(T n) {
    static_assert(isInteger<T>(), "bv requires an integer");

    return T(T(1) << n);
}

#ifndef SANITISE_ADDR_FOR_TEST
    #define SANITISE_ADDR_FOR_TEST(ADDR) ADDR
#endif

namespace nblib {

#define SYSTEM(A) CAT(CHIP_SYSTEM_, A)

/// #### enum {{Ccp}}
/// * selfProgram
/// * ioReg
enum class Ccp {
    #if DEFINED(SYSTEM(ALLOW_CONFIG_CHANGE_SELF_PROGRAM_ID))
        selfProgram = SYSTEM(ALLOW_CONFIG_CHANGE_SELF_PROGRAM_ID),
    #endif

    #if DEFINED(SYSTEM(ALLOW_CONFIG_CHANGE_IO_REG_ID))
        ioReg = SYSTEM(ALLOW_CONFIG_CHANGE_IO_REG_ID),
    #endif

    none,
};

// "writeZero" specifies bits which should be set to zero during a
// read-modify-write operation. These bits can still be written and
// read normally when accessed directly.
// Use cases:
//   * flag bits which are cleared when set to 1
//   * read only bits
//   * bits which have different read and write meanings
// TODO Possibly use cbi and sbi if address is valid.
template <class T, size_t addr, T writeZero = 0x00, Ccp ccp = Ccp::none>
struct Register {
    using Type = T;

    static_assert(isUnsigned<T>(), "Register type needs to be an unsigned integer");

    Register() = delete;

    Register& operator=(const Register&) = delete;

    Register(const Register&) = delete;

    static force_inline void allowConfigChange() {
        #if REG_DEFINED(SYSTEM(ALLOW_CONFIG_CHANGE_REG))
            if(ccp != Ccp::none) {
                asm volatile("" ::: "memory");
                SYSTEM(ALLOW_CONFIG_CHANGE_REG)::setReg(ccp);
                asm volatile("" ::: "memory");
            }
        #endif
    }

    static T* ptr() {
        return (T*)SANITISE_ADDR_FOR_TEST(addr);
    }

    /// #### static force_inline void setBit\(int bit, bool value\)
    /// Set a single bit to 0 or 1, leaving all other bits the same.<br>
    /// Handles writeZero bits.<br>
    /// Performs "config change" action if enabled.
    static force_inline void setBit(int bit, bool value) {
        // All in one line otherwise order with allowConfigChange() is wrong in generated code.
        const T r = value ? T((*ptr() & ~writeZero) | bv<T>(T(bit))) : T((*ptr() & ~writeZero) & ~bv<T>(T(bit)));

        allowConfigChange();

        *ptr() = r;

        if(writeZero || (ccp != Ccp::none)) {
            asm volatile("" ::: "memory");
        }
    }

    /// #### static force_inline bool getBit\(int bit\)
    /// Get a single bit as a boolean value.
    static force_inline bool getBit(int bit) {
        return bool(*ptr() & bv<T>(T(bit)));
    }

    /// #### static void setBits\(T mask, U value\)
    /// Set some bits, indicated by the mask, to the given value.<br>
    /// Handles writeZero bits.<br>
    /// Performs "config change" action if enabled.
    template <class U>
    static force_inline void setBits(T mask, U value) {
        // All in one line as order with allowConfigChange() is wrong in generated code.
        const T r = T(((*ptr() & ~mask & ~writeZero) | (T(value) & mask)));

        allowConfigChange();

        *ptr() = r;

        if(writeZero || (ccp != Ccp::none)) {
            asm volatile("" ::: "memory");
        }
    }

    /// #### static T getBits\(T mask\)
    /// Get some bits, indicated by the mask.<br>
    // template <class U>
    static force_inline T getBits(T mask) {
        return *ptr() & mask;
    }

    /// #### static void setReg\(U value\)
    /// Set entire register to the given value.<br>
    /// Performs "config change" action if enabled.
    template <class U = T>
    static force_inline void setReg(U value) {
        allowConfigChange();

        *ptr() = T(value);

        asm volatile("" ::: "memory");
    }

    /// #### static U getReg\(\)
    /// Get the value in this register.
    template <class U = T>
    static force_inline U getReg() {
        return U(*ptr());
    }
};

#undef SYSTEM

#ifdef TEST

TEST(Register, setBit) {
    constexpr size_t addr = 11;

    using Reg = Register<uint8_t, addr, 0x10>;

    register_memory[addr] = 0x00;

    Reg::setBit(0, true);
    ASSERT_EQ(register_memory[addr], 0x01);

    Reg::setBit(0, false);
    ASSERT_EQ(register_memory[addr], 0x00);

    register_memory[addr] = 0x10;

    Reg::setBit(0, true);
    ASSERT_EQ(register_memory[addr], 0x01);

    Reg::setBit(0, false);
    ASSERT_EQ(register_memory[addr], 0x00);

    register_memory[addr] = 0x20;

    Reg::setBit(0, true);
    ASSERT_EQ(register_memory[addr], 0x21);

    Reg::setBit(0, false);
    ASSERT_EQ(register_memory[addr], 0x20);

    register_memory[addr] = 0x00;

    Reg::setBit(4, true);
    ASSERT_EQ(register_memory[addr], 0x10);

    Reg::setBit(4, false);
    ASSERT_EQ(register_memory[addr], 0x00);
}

TEST(Register, getBit) {
    constexpr size_t addr = 11;

    using Reg = Register<uint8_t, addr, 0x10>;

    register_memory[addr] = 0x01;

    ASSERT_EQ(Reg::getBit(0), true);
    ASSERT_EQ(register_memory[addr], 0x01);

    ASSERT_EQ(Reg::getBit(1), false);
    ASSERT_EQ(register_memory[addr], 0x01);

    ASSERT_EQ(Reg::getBit(4), false);
    ASSERT_EQ(register_memory[addr], 0x01);

    register_memory[addr] = 0x10;

    ASSERT_EQ(Reg::getBit(4), true);
    ASSERT_EQ(register_memory[addr], 0x10);
}

TEST(Register, setBits) {
    constexpr size_t addr = 11;

    using Reg = Register<uint8_t, addr, 0x10>;

    register_memory[addr] = 0x00;

    Reg::setBits(0x06, 0x02);
    ASSERT_EQ(register_memory[addr], 0x02);

    Reg::setBits(0x06, 0x36);
    ASSERT_EQ(register_memory[addr], 0x06);

    register_memory[addr] = 0x3F;

    Reg::setBits(0x06, 0x00);
    ASSERT_EQ(register_memory[addr], 0x29);
}

TEST(Register, getBits) {
    constexpr size_t addr = 11;

    using Reg = Register<uint8_t, addr, 0x10>;

    register_memory[addr] = 0x01;

    ASSERT_EQ(Reg::getBits(0x06), 0x00);
    ASSERT_EQ(register_memory[addr], 0x01);

    register_memory[addr] = 0x02;

    ASSERT_EQ(Reg::getBits(0x06), 0x02);
    ASSERT_EQ(register_memory[addr], 0x02);

    register_memory[addr] = 0x98;

    ASSERT_EQ(Reg::getBits(0x06), 0x00); // FIXME Failed
    ASSERT_EQ(register_memory[addr], 0x98);

    ASSERT_EQ(Reg::getBits(0x18), 0x18);
    ASSERT_EQ(register_memory[addr], 0x98);
}

// TODO setReg getReg tests

#endif

} // nblib

#endif

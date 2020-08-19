/// [[Index]]

/// # {{Voltage Voltage}}

/// ```c++
/// ```

#ifndef NBLIB_VREF_HPP

#include "chip.hpp"
#include "register.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define VrefN CAT(Vref,N)
    #define VREF_N(A) CAT(CHIP_VREF_, N, _, A)

    #if DEFINED(CAT(CHIP_VREF_, N))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{VrefN}}
struct VrefN {
    VrefN() = delete;
    VrefN& operator=(const VrefN&) = delete;
    VrefN(const VrefN&) = delete;

    /// #### enum {{VrefN::Voltage}}
    /// * v0_55
    /// * v1_1
    /// * v1_5
    /// * v2_5
    /// * v4_3
    enum class Voltage {
        #if DEFINED(VREF_N(VOLTAGE_0_55_V_ID))
            v0_55 = VREF_N(VOLTAGE_0_55_V_ID),
        #endif

        #if DEFINED(VREF_N(VOLTAGE_1_1_V_ID))
            v1_1 = VREF_N(VOLTAGE_1_1_V_ID),
        #endif

        #if DEFINED(VREF_N(VOLTAGE_1_5_V_ID))
            v1_5 = VREF_N(VOLTAGE_1_5_V_ID),
        #endif

        #if DEFINED(VREF_N(VOLTAGE_2_5_V_ID))
            v2_5 = VREF_N(VOLTAGE_2_5_V_ID),
        #endif

        #if DEFINED(VREF_N(VOLTAGE_4_3_V_ID))
            v4_3 = VREF_N(VOLTAGE_4_3_V_ID),
        #endif
    };

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::vref;
    }

    /// #### static void voltage([[VrefN::Voltage]])
    static force_inline void voltage(Voltage r) {
        VREF_N(VOLTAGE_REG)::setBits(VREF_N(VOLTAGE_MASK), r);
    }
};

#ifdef TEST

TEST(VrefN, getHardwareType) {
    ASSERT_EQ(VrefN::getHardwareType(), HardwareType::vref);
}

TEST(VrefN, voltage) {
    #if DEFINED(VREF_N(VOLTAGE_0_55_V_ID))
        TEST_REG_WRITE(VrefN::voltage(VrefN::Voltage::v0_55));
    #endif

    #if DEFINED(VREF_N(VOLTAGE_1_1_V_ID))
        TEST_REG_WRITE(VrefN::voltage(VrefN::Voltage::v1_1));
    #endif

    #if DEFINED(VREF_N(VOLTAGE_1_5_V_ID))
        TEST_REG_WRITE(VrefN::voltage(VrefN::Voltage::v2_5));
    #endif

    #if DEFINED(VREF_N(VOLTAGE_2_5_V_ID))
        TEST_REG_WRITE(VrefN::voltage(VrefN::Voltage::v4_3));
    #endif

    #if DEFINED(VREF_N(VOLTAGE_4_3_V_ID))
        TEST_REG_WRITE(VrefN::voltage(VrefN::Voltage::v1_5));
    #endif
}

#endif // TEST

} // nblib::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef VrefN
    #undef VREF_N

    #include "vref.hpp"
#else
    #define NBLIB_VREF_HPP
#endif

#endif

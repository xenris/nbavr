/// # Output Compares

/// ## Example
/// ```c++
/// // TODO
/// ```

/// X is the output compare id (A, B, etc).<br>
/// T is the type of the output compare's register, either uint8_t or uint16_t.<br>

#define OutputCompareX CONCAT(OutputCompare, ID)
#define CC(X) CONCAT(C(OUTPUTCOMPARE), _, ID, _, X)
#define _CC(X) CONCAT(_C(OUTPUTCOMPARE), ID, _, X, _)

/// ## class OutputCompareX
struct OutputCompareX {
    /// #### type Pin
    /// The IO pin which relates to this output compare.
    #if DEFINED(CC(MODE_TOGGLE_ID))
        using Pin = CC(PIN);
    #endif

    /// #### enum Mode
    /// * Disconnected
    /// * Toggle
    /// * Clear
    /// * Set
    #if DEFINED(CC(MODE_TOGGLE_ID))
    enum class Mode : uint8_t {
        Disconnected = CC(MODE_DISCONNECTED_ID),
        Toggle = CC(MODE_TOGGLE_ID),
        Clear = CC(MODE_CLEAR_ID),
        Set = CC(MODE_SET_ID),
    };
    #endif

    /// #### static void value(T v)
    /// Set the compare register of output compare X.
    static force_inline void value(C(TYPE) v) {
        *CC(REG) = v;
    }

    /// #### static T value()
    /// Get the compare register of output compare X.
    static force_inline C(TYPE) value() {
        return *CC(REG);
    }

    /// #### static void mode(Mode m)
    /// Set the mode of output compare X.
    #if DEFINED(CC(MODE_TOGGLE_ID))
    static force_inline void mode(Mode m) {
        setBit_(CC(MODE_BIT_0_REG), CC(MODE_BIT_0_BIT), uint8_t(m) & 0x01);
        setBit_(CC(MODE_BIT_1_REG), CC(MODE_BIT_1_BIT), uint8_t(m) & 0x02);
    }
    #endif

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback and data for output compare X interrupt.
    #if CC(MODE_BIT_1_BIT)
    static force_inline void callback(callback_t callback, void* data) {
        _CC(Callback) = callback;
        _CC(CallbackData) = data;
    }
    #endif

    /// #### static void intEnable(bool b)
    /// Enable/disable the output compare X interrupt.
    #if CC(MODE_BIT_1_BIT)
    static force_inline void intEnable(bool b) {
        if(b) {
            *CC(INT_ENABLE_REG) |= bv(CC(INT_ENABLE_BIT));
        } else {
            *CC(INT_ENABLE_REG) &= ~bv(CC(INT_ENABLE_BIT));
        }
    }

    static force_inline bool intEnabled() {
        return *CC(INT_ENABLE_REG) & bv(CC(INT_ENABLE_BIT));
    }
    #endif

    /// #### static bool intFlag()
    /// Returns true if the output compare X interrupt flag is set.
    #if CC(MODE_BIT_1_BIT)
    static force_inline bool intFlag() {
        return *CC(INT_FLAG_REG) & bv(CC(INT_FLAG_BIT));
    }
    #endif

    /// #### static void intFlagClear()
    /// Clear the output compare X interrupt flag.
    #if CC(MODE_BIT_1_BIT)
    static force_inline void intFlagClear() {
        *CC(INT_FLAG_REG) |= bv(CC(INT_FLAG_BIT));
    }
    #endif
};

#undef OutputCompareX
#undef CC
#undef _CC

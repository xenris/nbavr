/// # Timer Output

/// ## Example
/// ```c++
/// // TODO
/// ```

/// X is the output id (A, B, etc).<br>
/// T is the type of the output's register, either uint8_t or uint16_t.<br>

#define OutputX CAT(Output, ID)
#define OUTPUT_X(X) CAT(TIMER_N(OUTPUT), _, ID, _, X)
#define _OUTPUT_X(X) CAT(_TIMER_N(OUTPUT), ID, _, X, _)

/// ## class OutputX
struct OutputX {
    /// #### type Pin
    /// The IO pin which relates to this output.
    #if DEFINED(OUTPUT_X(MODE_TOGGLE_ID))
        using Pin = OUTPUT_X(PIN);
    #endif

    /// #### enum Mode
    /// * Disconnected
    /// * Toggle
    /// * Clear
    /// * Set
    #if DEFINED(OUTPUT_X(MODE_TOGGLE_ID))
    enum class Mode : uint8_t {
        Disconnected = OUTPUT_X(MODE_DISCONNECTED_ID),
        Toggle = OUTPUT_X(MODE_TOGGLE_ID),
        Clear = OUTPUT_X(MODE_CLEAR_ID),
        Set = OUTPUT_X(MODE_SET_ID),
    };
    #endif

    /// #### static void value(T v)
    /// Set the register of output X.
    static force_inline void value(REGTYPE(OUTPUT_X(REG)) v) {
        *REG(OUTPUT_X(REG)) = v;
    }

    /// #### static T value()
    /// Get the register of output X.
    static force_inline REGTYPE(OUTPUT_X(REG)) value() {
        return *REG(OUTPUT_X(REG));
    }

    /// #### static void mode(Mode m)
    /// Set the mode of output X.
    #if DEFINED(OUTPUT_X(MODE_TOGGLE_ID))
    static force_inline void mode(Mode m) {
        setBit_(REG(OUTPUT_X(MODE_BIT_0_REG)), OUTPUT_X(MODE_BIT_0_BIT), uint8_t(m) & 0x01);
        setBit_(REG(OUTPUT_X(MODE_BIT_1_REG)), OUTPUT_X(MODE_BIT_1_BIT), uint8_t(m) & 0x02);
    }
    #endif

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback and data for output X interrupt.
    #if OUTPUT_X(MODE_BIT_1_BIT)
    static force_inline void callback(callback_t callback, void* data) {
        _OUTPUT_X(Callback) = callback;
        _OUTPUT_X(CallbackData) = data;
    }
    #endif

    /// #### static void intEnable(bool b)
    /// Enable/disable the output X interrupt.
    #if OUTPUT_X(MODE_BIT_1_BIT)
    static force_inline void intEnable(bool b) {
        if(b) {
            *REG(OUTPUT_X(INT_ENABLE_REG)) |= bv(OUTPUT_X(INT_ENABLE_BIT));
        } else {
            *REG(OUTPUT_X(INT_ENABLE_REG)) &= ~bv(OUTPUT_X(INT_ENABLE_BIT));
        }
    }

    static force_inline bool intEnabled() {
        return *REG(OUTPUT_X(INT_ENABLE_REG)) & bv(OUTPUT_X(INT_ENABLE_BIT));
    }
    #endif

    /// #### static bool intFlag()
    /// Returns true if the output X interrupt flag is set.
    #if OUTPUT_X(MODE_BIT_1_BIT)
    static force_inline bool intFlag() {
        return *REG(OUTPUT_X(INT_FLAG_REG)) & bv(OUTPUT_X(INT_FLAG_BIT));
    }
    #endif

    /// #### static void intFlagClear()
    /// Clear the output X interrupt flag.
    #if OUTPUT_X(MODE_BIT_1_BIT)
    static force_inline void intFlagClear() {
        *REG(OUTPUT_X(INT_FLAG_REG)) |= bv(OUTPUT_X(INT_FLAG_BIT));
    }
    #endif
};

#undef OutputX
#undef OUTPUT_X
#undef _OUTPUT_X

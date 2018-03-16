/// # Timer Input

/// ## class Input
struct Input {
    /// #### type Pin
    /// The IO pin which relates to this input.
    using Pin = TIMER_N(INPUT_PIN);

    /// #### enum Edge
    /// * rising
    /// * falling
    enum class Edge : uint8_t {
        rising = TIMER_N(INPUT_EDGE_RISING_ID),
        falling = TIMER_N(INPUT_EDGE_FALLING_ID),
    };

    /// #### static void value(T v)
    /// Set the input register.
    static force_inline void value(REGTYPE(TIMER_N(INPUT_REG)) v) {
        *REG(TIMER_N(INPUT_REG)) = v;
    }

    /// #### static T value()
    /// Get the input register.
    static force_inline REGTYPE(TIMER_N(INPUT_REG)) value() {
        return *REG(TIMER_N(INPUT_REG));
    }

    /// #### static void edge(Edge e)
    /// Set the trigger edge.
    static force_inline void edge(Edge e) {
        setBit_(REG(TIMER_N(INPUT_EDGE_SELECT_REG)), TIMER_N(INPUT_EDGE_SELECT_BIT), uint8_t(e) & 0x01);
    }

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback and data for int input interrupt.
    static force_inline void callback(callback_t callback, void* data) {
        _TIMER_N(INPUT_Callback) = callback;
        _TIMER_N(INPUT_CallbackData) = data;
    }

    /// #### static void intEnable(bool b)
    /// Enable/disable the input interrupt.
    static force_inline void intEnable(bool b) {
        if(b) {
            *REG(TIMER_N(INPUT_INT_ENABLE_REG)) |= bv(TIMER_N(INPUT_INT_ENABLE_BIT));
        } else {
            *REG(TIMER_N(INPUT_INT_ENABLE_REG)) &= ~bv(TIMER_N(INPUT_INT_ENABLE_BIT));
        }
    }

    static force_inline bool intEnabled() {
        return *REG(TIMER_N(INPUT_INT_ENABLE_REG)) & bv(TIMER_N(INPUT_INT_ENABLE_BIT));
    }

    /// #### static bool intFlag()
    /// Returns true if the input interrupt flag is set.
    static force_inline bool intFlag() {
        return *REG(TIMER_N(INPUT_INT_FLAG_REG)) & bv(TIMER_N(INPUT_INT_FLAG_BIT));
    }

    /// #### static void intFlagClear()
    /// Clear the input interrupt flag.
    static force_inline void intFlagClear() {
        *REG(TIMER_N(INPUT_INT_FLAG_REG)) |= bv(TIMER_N(INPUT_INT_FLAG_BIT));
    }
};

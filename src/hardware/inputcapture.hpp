/// # Input Capture

/// ## class InputCapture
struct InputCapture {
    /// #### type Pin
    /// The IO pin which relates to this input capture.
    using Pin = C(INPUTCAPTURE_PIN);

    /// #### enum Edge
    /// * Rising
    /// * Falling
    enum class Edge : uint8_t {
        Rising = C(INPUTCAPTURE_EDGE_RISING_ID),
        Falling = C(INPUTCAPTURE_EDGE_FALLING_ID),
    };

    /// #### static void value(uint16_t v)
    /// Set the input capture register.
    static force_inline void value(uint16_t v) {
        *C(INPUTCAPTURE_REG) = v;
    }

    /// #### static uint16_t value()
    /// Get the input capture register.
    static force_inline uint16_t value() {
        return *C(INPUTCAPTURE_REG);
    }

    /// #### static void edge(Edge e)
    /// Set the trigger edge.
    static force_inline void edge(Edge e) {
        setBit_(C(INPUTCAPTURE_EDGE_REG), C(INPUTCAPTURE_EDGE_BIT), uint8_t(e) & 0x01);
    }

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback and data for int input capture interrupt.
    static force_inline void callback(callback_t callback, void* data) {
        _C(INPUTCAPTURE_Callback) = callback;
        _C(INPUTCAPTURE_CallbackData) = data;
    }

    /// #### static void intEnable(bool b)
    /// Enable/disable the input capture interrupt.
    static force_inline void intEnable(bool b) {
        if(b) {
            *C(INPUTCAPTURE_INT_ENABLE_REG) |= bv(C(INPUTCAPTURE_INT_ENABLE_BIT));
        } else {
            *C(INPUTCAPTURE_INT_ENABLE_REG) &= ~bv(C(INPUTCAPTURE_INT_ENABLE_BIT));
        }
    }

    static force_inline bool intEnabled() {
        return *C(INPUTCAPTURE_INT_ENABLE_REG) & bv(C(INPUTCAPTURE_INT_ENABLE_BIT));
    }

    /// #### static bool intFlag()
    /// Returns true if the input capture interrupt flag is set.
    static force_inline bool intFlag() {
        return *C(INPUTCAPTURE_INT_FLAG_REG) & bv(C(INPUTCAPTURE_INT_FLAG_BIT));
    }

    /// #### static void intFlagClear()
    /// Clear the input capture interrupt flag.
    static force_inline void intFlagClear() {
        *C(INPUTCAPTURE_INT_FLAG_REG) |= bv(C(INPUTCAPTURE_INT_FLAG_BIT));
    }
};

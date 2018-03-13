#ifndef NBOS_RANDOM_HPP
#define NBOS_RANDOM_HPP

/// # Random

/// ## Example

/// ```c++
/// nbos::Random random;

/// int16_t i = random.next<int16_t>();
/// float f = random.next<float>();
/// ```

/// ## class Random
class Random {
    uint32_t _next;

public:

    /// #### Random()
    /// Constructor with seed defaulting to 1.
    Random() : _next(1) {
    }

    /// #### Random(uint32_t seed)
    /// Constructor with user defined seed.
    Random(uint32_t seed) : _next(seed) {
    }

    /// #### T next()
    /// Get the next random value.
    template<class T>
    T next() {
        _next = _next * 1103515245 + 12345;

        uint32_t result = (_next / 65536) % 32768;

        if constexpr (is_floating<T>::value) {
            return T(result) / T(32768);
        } else {
            return T(result);
        }
    }
};

#endif

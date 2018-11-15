/// [[Index]]

/// # {{Random}}

/// ## Example

/// ```c++
/// nbos::Random random;

/// int i = random.next<int>();
/// float f = random.next<float>();
/// ```

#ifndef NBOS_RANDOM_HPP
#define NBOS_RANDOM_HPP

#include "type.hpp"

namespace nbos {

/// ## class Random
class Random {
    uint32_t _next;

public:

    /// #### Random()
    /// Constructor with seed defaulting to 0.
    Random() : _next(0) {
    }

    /// #### Random(uint32_t seed)
    /// Constructor with user defined seed.
    Random(uint32_t seed) : _next(seed) {
    }

    /// #### T next<class T>()
    /// Get the next random value.<br>
    /// Floating point between 0 and 1 inclusive.<br>
    /// Other types between 0 and 32768 inclusive.<br>
    /// Algorithm based on the POSIX.1-2001 example.
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

} // nbos

#endif

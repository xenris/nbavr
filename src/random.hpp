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

#include "safe.hpp"

namespace nbos {

/// ## class Random
class Random {
    Word32 _next;

public:

    /// #### Random()
    /// Constructor with seed defaulting to 0.
    Random() : _next(0) {
    }

    /// #### Random(Word32 seed)
    /// Constructor with user defined seed.
    Random(Word32 seed) : _next(seed) {
    }

    /// #### T next<class T>()
    /// Get the next random value.<br>
    /// Floating point between 0 and 1 inclusive.<br>
    /// Other types between 0 and 32768 inclusive.<br>
    /// Algorithm based on the POSIX.1-2001 example.
    template<class T>
    T next() {
        _next = _next * 1103515245 + 12345;

        Word32 result = (_next / 65536) % 32768;

        if constexpr (IsFloating<T>::value) {
            return T(result) / T(32768);
        } else {
            return T(result);
        }
    }
};

#ifdef TEST

TEST(Random, Limits) {
    Random r;

    // Technically not guaranteed to be true, just very likely.
    EXPECT_TRUE(r.next<Float>() != r.next<Float>());

    for(Int i = 0; i < 1000; i++) {
        const Float n = r.next<Float>();

        EXPECT_LE(n, 1);
        EXPECT_GE(n, 0);
    }
}

#endif // TEST

} // nbos

#endif

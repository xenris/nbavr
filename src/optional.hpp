#ifndef NBOS_OPTIONAL_HPP
#define NBOS_OPTIONAL_HPP

#include "safe.hpp"

/// ## class {{Optional}}<class T\>
/// Class who's value can be either something or nothing.
///
/// ```c++
/// Optional<Int32> o;
///
/// Bool b = o; // b = false
///
/// o = 5;
///
/// b = o; // b = true
///
/// Int32 a = *b; // a = 5
/// Int32 x = b; // x = 1 (a.k.a. true)
///
/// o = {};
///
/// b = o; // b = false
/// ```
template <class T>
class Optional {
    primitive_bool hasValue;
    T value;

public:

    /// #### Optional()
    /// Constructor for "nothing"
    Optional() {
        hasValue = false;
    }

    /// #### Optional(T value)
    /// Constructor for "something"
    Optional(const T& v) {
        hasValue = true;
        value = v;
    }

    template <class U>
    Optional(const U& v) {
        hasValue = true;
        value = v;
    }

    /// #### operator primitive_bool()
    /// True if "something", false if "nothing".
    operator primitive_bool() const {
        return hasValue;
    }

    /// #### T operator *()
    /// Returns the stored value.
    T& operator *() {
        return value;
    }

    const T& operator *() const {
        return value;
    }

    /// #### T\* operator ->()
    /// Pointer access to the stored value.
    T* operator ->() {
        return &value;
    }

    const T* operator ->() const {
        return &value;
    }
};

#ifdef TEST

TEST(Optional, General) {
    Optional<Int> a;

    EXPECT_FALSE(a);

    a = 5;

    EXPECT_TRUE(a);
    EXPECT_EQ(*a, 5);

    a = {};

    EXPECT_FALSE(a);
}

#endif

#endif

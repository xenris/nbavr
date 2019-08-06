#ifndef NBLIB_OPTIONAL_HPP
#define NBLIB_OPTIONAL_HPP

/// ## class {{Optional}}<class T\>
/// Class who's value can be either something or nothing.
///
/// ```c++
/// Optional<int> o;
///
/// bool b = o; // b = false
///
/// o = 5;
///
/// b = o; // b = true
///
/// int a = *b; // a = 5
/// int x = b; // x = 1 (a.k.a. true)
///
/// o = {};
///
/// b = o; // b = false
/// ```
template <class T>
class Optional {
    bool _hasValue;
    T _value;

public:

    /// #### Optional()
    /// Constructor for "nothing"
    Optional() {
        _hasValue = false;
    }

    /// #### Optional(T value)
    /// Constructor for "something"
    Optional(const T& v) {
        _hasValue = true;
        _value = v;
    }

    template <class U>
    Optional(const U& v) {
        _hasValue = true;
        _value = v;
    }

    /// #### operator bool()
    /// True if "something", false if "nothing".
    explicit operator bool() const {
        return _hasValue;
    }

    /// #### bool hasValue()
    /// True if "something", false if "nothing".
    bool hasValue() const {
        return _hasValue;
    }

    /// #### T operator *()
    /// Returns the stored value.
    T& operator *() {
        return _value;
    }

    const T& operator *() const {
        return _value;
    }

    /// #### T\* operator -\>()
    /// Pointer access to the stored value.
    T* operator ->() {
        return &_value;
    }

    const T* operator ->() const {
        return &_value;
    }

    /// #### T value()
    /// Returns the stored value.
    T& value() {
        return _value;
    }

    const T& value() const {
        return _value;
    }

    /// #### T valueOr(T t)
    /// Returns the stored value if there is one, otherwise returns t.
    T valueOr(T t) {
        return _hasValue ? _value : t;
    }
};

#ifdef TEST

TEST(Optional, General) {
    Optional<int> a;

    EXPECT_FALSE(a);

    a = 5;

    EXPECT_TRUE(a);
    EXPECT_EQ(*a, 5);

    a = {};

    EXPECT_FALSE(a);
}

#endif

#endif

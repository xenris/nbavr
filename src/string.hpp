#ifndef NBOS_STRING_HPP
#define NBOS_STRING_HPP

#include "safe.hpp"

template <Int maxLength = -1>
class String;

template <>
class String<-1> {
    Char* _buffer;
    Int _maxLength;
    Int _length;

public:

    constexpr String(Char* buffer, Int maxLength) : _buffer(buffer), _maxLength(maxLength), _length(0) {
    }

    // FIXME Casting a constant string to a variable string.
    constexpr String(const primitive_signed_char* buffer) : _buffer((Char*)buffer), _maxLength(length(buffer)), _length(_maxLength) {
    }

    constexpr String(const Char* buffer) : _buffer((Char*)buffer), _maxLength(length((const primitive_signed_char*)buffer)), _length(_maxLength) {
    }

    constexpr Bool operator ==(const String<>& other) {
        if(_length != other._length) {
            return false;
        }

        for(Int i = 0; i < _length; i++) {
            if(_buffer[i] != other[i]) {
                return false;
            }
        }

        return true;
    }

    constexpr Bool operator !=(const String<>& other) {
        if(_length != other._length) {
            return true;
        }

        for(Int i = 0; i < _length; i++) {
            if(_buffer[i] != other[i]) {
                return true;
            }
        }

        return false;
    }

    constexpr Char& operator [](Int i) {
        return _buffer[i];
    }

    constexpr const Char& operator [](Int i) const {
        return _buffer[i];
    }

    constexpr Char& get(Int i) {
        return _buffer[i];
    }

    constexpr const Char& get(Int i) const {
        return _buffer[i];
    }

    constexpr Bool operator <(const String& other) const {
        for(Int i = 0; i < _length; i++) {
            if(_buffer[i] < other[i]) {
                return true;
            }

            if(_buffer[i] > other[i]) {
                return false;
            }
        }

        return false;
    }

    constexpr Bool operator <=(const String<>& other) const {
        for(Int i = 0; i < _length; i++) {
            if(_buffer[i] < other[i]) {
                return true;
            }

            if(_buffer[i] > other[i]) {
                return false;
            }
        }

        return true;
    }

    constexpr Bool operator >(const String<>& other) const {
        for(Int i = 0; i < _length; i++) {
            if(_buffer[i] < other[i]) {
                return false;
            }

            if(_buffer[i] > other[i]) {
                return true;
            }
        }

        return false;
    }

    constexpr Bool operator >=(const String<>& other) const {
        for(Int i = 0; i < _length; i++) {
            if(_buffer[i] < other[i]) {
                return false;
            }

            if(_buffer[i] > other[i]) {
                return true;
            }
        }

        return true;
    }

    /// #### Char\* begin()
    constexpr Char* begin() {
        return &_buffer[0];
    }

    constexpr const Char* begin() const {
        return &_buffer[0];
    }

    /// #### const Char\* end()
    constexpr const Char* end() const {
        return &_buffer[_length];
    }

    constexpr Char* operator *() {
        return _buffer;
    }

    constexpr const Char* operator *() const {
        return _buffer;
    }

    static constexpr Int length(const primitive_signed_char* s) {
        Int i = 0;

        while(s[i] != '\0') {
            i++;

            if(i == 0) {
                break;
            }
        }

        return i;
    }
};

template <Int maxLength>
class String : public String<> {
    Char _buffer[maxLength];

public:

    explicit String() : String<>(_buffer, maxLength) {
    }

    explicit String(const primitive_signed_char* s) : String<>(_buffer, maxLength) {
        Int i = 0;

        while(s[i] != '\0') {
            _buffer[i] = s[i];
        }
    }
};

#endif

#ifndef NBOS_STRING_HPP
#define NBOS_STRING_HPP

#include "primitive.hpp"

template <int maxLength = -1>
class String;

template <>
class String<-1> {
    char* _buffer;
    int _maxLength;
    int _length;

public:

    constexpr String(char* buffer, int maxLength) : _buffer(buffer), _maxLength(maxLength), _length(0) {
    }

    // FIXME Casting a constant string to a variable string.
    constexpr String(const char* buffer) : _buffer((char*)buffer), _maxLength(length(buffer)), _length(_maxLength) {
    }

    // constexpr String(const char* buffer) : _buffer((char*)buffer), _maxLength(length((const char*)buffer)), _length(_maxLength) {
    // }

    constexpr bool operator ==(const String<>& other) {
        if(_length != other._length) {
            return false;
        }

        for(int i = 0; i < _length; i++) {
            if(_buffer[i] != other[i]) {
                return false;
            }
        }

        return true;
    }

    constexpr bool operator !=(const String<>& other) {
        if(_length != other._length) {
            return true;
        }

        for(int i = 0; i < _length; i++) {
            if(_buffer[i] != other[i]) {
                return true;
            }
        }

        return false;
    }

    constexpr char& operator [](int i) {
        return _buffer[i];
    }

    constexpr const char& operator [](int i) const {
        return _buffer[i];
    }

    constexpr char& get(int i) {
        return _buffer[i];
    }

    constexpr const char& get(int i) const {
        return _buffer[i];
    }

    constexpr bool operator <(const String& other) const {
        for(int i = 0; i < _length; i++) {
            if(_buffer[i] < other[i]) {
                return true;
            }

            if(_buffer[i] > other[i]) {
                return false;
            }
        }

        return false;
    }

    constexpr bool operator <=(const String<>& other) const {
        for(int i = 0; i < _length; i++) {
            if(_buffer[i] < other[i]) {
                return true;
            }

            if(_buffer[i] > other[i]) {
                return false;
            }
        }

        return true;
    }

    constexpr bool operator >(const String<>& other) const {
        for(int i = 0; i < _length; i++) {
            if(_buffer[i] < other[i]) {
                return false;
            }

            if(_buffer[i] > other[i]) {
                return true;
            }
        }

        return false;
    }

    constexpr bool operator >=(const String<>& other) const {
        for(int i = 0; i < _length; i++) {
            if(_buffer[i] < other[i]) {
                return false;
            }

            if(_buffer[i] > other[i]) {
                return true;
            }
        }

        return true;
    }

    /// #### char\* begin()
    constexpr char* begin() {
        return &_buffer[0];
    }

    constexpr const char* begin() const {
        return &_buffer[0];
    }

    /// #### const char\* end()
    constexpr const char* end() const {
        return &_buffer[_length];
    }

    constexpr char* operator *() {
        return _buffer;
    }

    constexpr const char* operator *() const {
        return _buffer;
    }

    static constexpr int length(const char* s) {
        int i = 0;

        while(s[i] != '\0') {
            i++;

            if(i == 0) {
                break;
            }
        }

        return i;
    }
};

template <int maxLength>
class String : public String<> {
    char _buffer[uint(maxLength)];

public:

    explicit String() : String<>(_buffer, maxLength) {
    }

    explicit String(const char* s) : String<>(_buffer, maxLength) {
        int i = 0;

        while(s[i] != '\0') {
            _buffer[i] = s[i];
        }
    }
};

#endif

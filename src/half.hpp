#ifndef NBAVR_HALF_HPP
#define NBAVR_HALF_HPP

// #include "stream.hpp"
// #include "print.hpp"

// seeeeeffffffffff
// 1 5 10

class half {
    uint16_t _n;

public:
    constexpr half(float n) : _n(encode(n)) {
    }

    constexpr half() : _n(0) {
    }

    void operator=(float n) {
        _n = encode(n);
    }

    void operator=(const half n) {
        _n = n._n;
    }

    half operator+(const half other) const {
        if(isNan() || other.isNan()) {
            return nan();
        }

        if(isZero()) {
            return other;
        } else if(other.isZero()) {
            return *this;
        }

        int16_t ts = (_n >> 15) & 0x1;
        int16_t os = (other._n >> 15) & 0x1;
        int16_t ns = 0;

        if(isInf() && other.isInf()) {
            if(ts != os) {
                return nan();
            } else {
                return *this;
            }
        } else if(isInf()) {
            return *this;
        } else if(other.isInf()) {
            return other;
        }

        int16_t te = ((_n >> 10) & 0x1f) - 15;
        int16_t oe = ((other._n >> 10) & 0x1f) - 15;
        int16_t ne = 0;

        int16_t tf = 0x400 | (_n & 0x3ff);
        int16_t of = 0x400 | (other._n & 0x3ff);
        int16_t nf = 0;

        if(te >= oe) {
            ne = te;
            of >>= te - oe;
        } else {
            ne = oe;
            of >>= oe - te;
        }

        // Add as two's compliment.
        nf = (ts ? (0 - tf) : tf) + (os ? (0 - of) : of);


        if(nf < 0) {
            nf = 0 - nf;
            ns = 1;
        }

        if(nf & 0x800) {
            nf >>= 1;
            ne += 1;
        } else if(nf != 0) {
            while(!(nf & 0x400)) {
                nf <<= 1;
                ne -= 1;
            }
        } else {
            return zero(ns);
        }

        return fromBits((ns << 15) | ((ne + 15) << 10) | (nf & 0x3ff));
    }

    half operator-(const half other) const {
        if(isNan() || other.isNan()) {
            return nan();
        }

        if(isZero()) {
            return -other;
        } else if(other.isZero()) {
            return *this;
        }

        int16_t ts = (_n >> 15) & 0x1;
        int16_t os = (other._n >> 15) & 0x1;
        int16_t ns = 0;

        if(isInf() && other.isInf()) {
            if(ts == os) {
                return nan();
            } else {
                return *this;
            }
        } else if(isInf()) {
            return *this;
        } else if(other.isInf()) {
            return -other;
        }

        int16_t te = ((_n >> 10) & 0x1f) - 15;
        int16_t oe = ((other._n >> 10) & 0x1f) - 15;
        int16_t ne = 0;

        int16_t tf = 0x400 | (_n & 0x3ff);
        int16_t of = 0x400 | (other._n & 0x3ff);
        int16_t nf = 0;

        if(te >= oe) {
            ne = te;
            of >>= te - oe;
        } else {
            ne = oe;
            of >>= oe - te;
        }

        // Subtract as two's compliment.
        nf = (ts ? (0 - tf) : tf) - (os ? (0 - of) : of);


        if(nf < 0) {
            nf = 0 - nf;
            ns = 1;
        }

        if(nf & 0x800) {
            nf >>= 1;
            ne += 1;
        } else if(nf != 0) {
            while(!(nf & 0x400)) {
                nf <<= 1;
                ne -= 1;
            }
        } else {
            return zero(ns);
        }

        return fromBits((ns << 15) | ((ne + 15) << 10) | (nf & 0x3ff));
    }

    half operator*(const half other) const {
        if(isNan() || other.isNan()) {
            return nan();
        }

        int16_t ts = (_n >> 15) & 0x1;
        int16_t os = (other._n >> 15) & 0x1;
        int16_t ns = ts ^ os;

        if(isInf() || other.isInf()) {
            return inf(ns);
        } else if(isZero() || other.isZero()) {
            return zero(ns);
        } else {
            int16_t te = ((_n >> 10) & 0x1f) - 15;
            int16_t oe = ((other._n >> 10) & 0x1f) - 15;
            int16_t ne = te + oe;

            if(ne < -14) {
                return zero(ns);
            } else if(ne > 15) {
                return inf(ns);
            } else {
                int32_t tf = 0x400 | (_n & 0x3ff);
                int32_t of = 0x400 | (other._n & 0x3ff);
                int32_t nf = (tf * of) / 0x400;

                while(nf >= 0x800) {
                    nf >>= 1;
                    ne += 1;
                }

                return fromBits((ns << 15) | ((ne + 15) << 10) | (nf & 0x3ff));
            }
        }
    }

    half operator/(const half other) const {
        if(isNan() || other.isNan()) {
            return nan();
        }

        int16_t ts = (_n >> 15) & 0x1;
        int16_t os = (other._n >> 15) & 0x1;
        int16_t ns = ts ^ os;

        if(isInf()) {
            if(other.isInf()) {
                return nan();
            } else {
                return inf(ns);
            }
        } else if(isZero()) {
            if(other.isZero()) {
                return nan();
            } else {
                return zero(ns);
            }
        } else {
            int16_t te = ((_n >> 10) & 0x1f) - 15;
            int16_t oe = ((other._n >> 10) & 0x1f) - 15;
            int16_t ne = te - oe;

            if(ne < -14) {
                return zero(ns);
            } else if(ne > 15) {
                return inf(ns);
            } else {
                int32_t tf = 0x400 | (_n & 0x3ff);
                int32_t of = 0x400 | (other._n & 0x3ff);
                int32_t nf = (tf * 0x400) / of;

                return fromBits((ns << 15) | ((ne + 15) << 10) | (nf & 0x3ff));
            }
        }
    }

    half operator-() const {
        return fromBits(_n ^ (1 << 15));
    }

    bool operator==(const half other) {
        return _n == other._n;
    }

    half operator+=(const half other) {
        return *this;
    }

    operator float() {
        int16_t hs = (_n >> 15) & 0x1;
        int16_t he = ((_n >> 10) & 0x1f) - 15;
        int16_t hf = _n & 0x3ff;

        int32_t fs = hs;
        int32_t fe = (he > 15) ? 0xff : ((he < -14) ? 0 : (he + 127));
        int32_t ff = hf << 13;

        union {
            uint32_t i;
            float f;
        } u;

        u.i = (fs << 31) | (fe << 23) | ff;

        return u.f;
    }

private:
    constexpr uint16_t encode(float n) {
        union {
            uint32_t i;
            float f;
        } u = {};

        u.f = n;

        int32_t fs = (u.i >> 31) & 0x1;
        int32_t fe = ((u.i >> 23) & 0xff) - 127;
        int32_t ff = u.i & 0x7fffff;

        int16_t hs = fs;

        // +-inf, nan, or +-zero.
        if(fe == 128) {
            if(ff == 0) {
                // +-inf
                return (hs << 15) | (0x1f << 10);
            } else {
                // nan
                return (0x1f << 10) | 1;
            }
        } else if(fe == -126) {
            // +-zero
            return (hs << 15);
        }

        // Out of half's range, or normal.
        if(fe < -14) {
            // +-zero
            return (hs << 15);
        } else if(fe > 15) {
            // +-inf
            return (hs << 15) | (0x1f << 10);
        } else {
            // normal
            int16_t he = fe + 15;
            int16_t hf = ff >> 13;
            return (hs << 15) | (he << 10) | hf;
        }
    }

    bool isNan() const {
        int16_t e = (_n >> 10) & 0x1f;
        int16_t f = _n & 0x3ff;

        return (e == 0x1f) && (f != 0);
    }

    bool isZero() const {
        int16_t e = (_n >> 10) & 0x1f;
        int16_t f = _n & 0x3ff;

        return (e == 0x00) && (f == 0);
    }

    bool isInf() const {
        int16_t e = (_n >> 10) & 0x1f;
        int16_t f = _n & 0x3ff;

        return (e == 0x1f) && (f == 0);
    }

    bool isPositive() const {
        int16_t s = (_n >> 15) & 0x1;

        return s == 0;
    }

    static half nan() {
        return fromBits((0x1f << 10) | 1);
    }

    static half zero(int16_t neg) {
        return fromBits(neg << 15);
    }

    static half inf(int16_t neg) {
        return fromBits((neg << 15) | (0x1f << 10));
    }

    static half fromBits(uint16_t bits) {
        half result;
        result._n = bits;
        return result;
    }
};

#endif

#ifndef NBAVR_EXTERNAL_HPP
#define NBAVR_EXTERNAL_HPP

namespace ext {
    extern "C" char* dtostre(double, char*, unsigned char, unsigned char);
    extern "C" double floor(double) __attribute__((__const__));
    extern "C" double log10(double) __attribute__((__const__));
    extern "C" double modf(double, double*)  __attribute__((__const__));
    extern "C" float modff(float, float*)  __attribute__((__const__));
    extern "C" double pow(double, double)  __attribute__((__const__));
    extern "C" double round(double)  __attribute__((__const__));
}

#endif

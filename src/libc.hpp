#ifndef NBOS_LIBC_HPP
#define NBOS_LIBC_HPP

#include "primitive.hpp"

namespace libc {
    extern "C" primitive_signed_char* dtostre(primitive_double, primitive_signed_char*, primitive_unsigned_char, primitive_unsigned_char);
}

#endif

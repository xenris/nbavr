#ifndef NBAVR_TIMERCOUNTER_HPP
#define NBAVR_TIMERCOUNTER_HPP

#ifdef CHIP_TIMERCOUNTER_0
#define ID 0
#include "timercounter.tpp"
#undef ID
#endif

#ifdef CHIP_TIMERCOUNTER_1
#define ID 1
#include "timercounter.tpp"
#undef ID
#endif

#ifdef CHIP_TIMERCOUNTER_2
#define ID 2
#include "timercounter.tpp"
#undef ID
#endif

#endif

#ifndef NBAVR_USART_HPP
#define NBAVR_USART_HPP

#ifdef CHIP_USART_0
#define ID 0
#include "usart.tpp"
#undef ID
#endif

#ifdef CHIP_USART_1
#define ID 1
#include "usart.tpp"
#undef ID
#endif

#ifdef CHIP_USART_2
#define ID 2
#include "usart.tpp"
#undef ID
#endif

#ifdef CHIP_USART_3
#define ID 3
#include "usart.tpp"
#undef ID
#endif

#endif

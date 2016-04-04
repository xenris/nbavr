#ifndef NBAVR_USART0_H
#define NBAVR_USART0_H

#include "chip.h"

#ifdef CHIP_USART_0

#define USART_ID 0
#include "usartn.h"
#undef USART_ID

#endif // CHIP_USART_0

#endif

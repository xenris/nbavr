#ifndef NBAVR_CHIP_H
#define NBAVR_CHIP_H

#if defined(__AVR_ATmega328__)
    #include "chips/atmega328.h"
#endif

#if defined(__AVR_ATmega328P__)
    #include "chips/atmega328p.h"
#endif

#if defined(__AVR_ATmega8__)
    #include "chips/atmega8.h"
#endif

/*#if defined(__AVR_XXX__)*/
/*    #include "chips/xxx.h"*/
/*#endif*/

#ifndef NBAVR_CHIP_DEFINED
    #error The hardware has not been defined for this chip
#endif

#endif

#ifndef CONFIG_H
#define CONFIG_H

#define F_CPU 16000000UL
#define BAUD 9600

// ISRs can't be optimised out by the linker, so these provide a way to
//  manually add or remove them.

//#define INCLUDE_SERIAL
//#define INCLUDE_MILLIS
//#define INCLUDE_TWI

#endif

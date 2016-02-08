#ifndef NBAVR_YIELD_H
#define NBAVR_YIELD_H

// Function to yield from a task.
// Acts like return, but will work from anywhere within a task.

#include "state.h"

void yield(void);

#endif

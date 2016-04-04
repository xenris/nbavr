#ifndef NBAVR_YIELD_H
#define NBAVR_YIELD_H

// Function to yield from a task.
// Acts like return, but will work from anywhere within a task.

#include <util/atomic.h>
#include <stddef.h>

#include "kernel.h"

void yield(void);

#endif

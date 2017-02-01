#ifndef NBAVR_HPP
#define NBAVR_HPP

#include <setjmp.h>
#include <stddef.h>
#include <stdint.h>

#include "hardware.hpp"
#include "stream.hpp"
#include "array.hpp"
#include "clock.hpp"
#include "print.hpp"
#include "task.hpp"

#include "tasks/lcd.hpp"
#include "tasks/serial.hpp"
#include "tasks/servo.hpp"
#include "tasks/twi.hpp"

#define LONG_JUMP_HALT 1
#define LONG_JUMP_YIELD 2

extern jmp_buf _longJmp;

inline void resumeFromYield() {
    longjmp(_longJmp, LONG_JUMP_YIELD);
}

inline void resumeFromHalt() {
    longjmp(_longJmp, LONG_JUMP_HALT);
}

template <uint8_t S>
inline void nbavr(Clock& clock, Task* (&tasks)[S]) {
    // Disable interrupts.
    cli();

    // Enable watchdog timer with the shortest timeout.
    _wdt_enable();

    // If a task halts or yields, the cpu will jump back here.
    int jmp = setjmp(_longJmp);

    // Index of current task.
    // Static to prevent being reinitialised when a task yields or halts.
    static uint8_t taskI = 0;

    // If a task halted or yielded go to the next task.
    if(jmp) {
        taskI++;
    }

    while(true) {
        while(taskI < S) {
            _wdt_reset();

            sei();

            tasks[taskI]->step(clock);

            taskI++;
        }

        taskI = 0;
        // TODO Sleep the cpu if all tasks are asleep.
    }
}

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" force_inline int __cxa_guard_acquire(__guard *) __attribute__((used));
extern "C" force_inline void __cxa_guard_release (__guard *) __attribute__((used));
extern "C" force_inline void __cxa_guard_abort (__guard *) __attribute__((used));
extern "C" force_inline void __cxa_pure_virtual(void) __attribute__((used));

int __cxa_guard_acquire(__guard *g) {
    return !*(char *)(g);
}

void __cxa_guard_release(__guard *g) {
    *(char *)g = 1;
}

void __cxa_pure_virtual(void) {
}

void __cxa_guard_abort (__guard *) {
}

#endif

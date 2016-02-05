#include "main.h"

#define MICROS_PER_TICK ((64 * 256) / (F_CPU / 1000000))

int main(void) {
    static Task* tasks[] = {&task1, &task2, &ledTask, &serialTask};

    Timer0Config clockConfig = {
        .clockSelect = TIMER0_SOURCE_64,
        .overflowIntEnable = true,
    };

    timer0(clockConfig);

    clockInit(MICROS_PER_TICK);

    taskManagerRun(tasks, sizeof(tasks) / sizeof(Task*));

    return 0;
}

ISR(TIMER0_OVF_vect) {
    clockTick();
}

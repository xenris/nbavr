#include "main.h"

#define MICROS_PER_TICK ((64 * 256) / (F_CPU / 1000000))

int main(void) {
    static Stream stream = streamInit(20);

    static Stream* streamA[] = {&stream};

    helloTask.outputStreams = streamA;
    helloTask.outputStreamCount = 1;

    serialTask.inputStreams = streamA;
    serialTask.inputStreamCount = 1;

    static Task* tasks[] = {&helloTask, &ledTask, &serialTask};

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

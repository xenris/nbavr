#include "main.h"

#define MICROS_PER_TICK ((64 * 256) / (F_CPU / 1000000))

int main(void) {
    static Stream task1SerialStream = streamInit(50);
    static Stream task2Task1Stream = streamInit(10);
    static Stream serialLedStream = streamInit(10);

    static Stream* task1SerialStreamA[] = {&task1SerialStream};
    static Stream* task2Task1StreamA[] = {&task2Task1Stream};
    static Stream* serialLedStreamA[] = {&serialLedStream};

    task1.inputStreams = task2Task1StreamA;
    task1.inputStreamCount = 1;
    task1.outputStreams = task1SerialStreamA;
    task1.outputStreamCount = 1;

    task2.outputStreams = task2Task1StreamA;
    task2.outputStreamCount = 1;

    ledTask.inputStreams = serialLedStreamA;
    ledTask.inputStreamCount = 1;

    serialTask.inputStreams = task1SerialStreamA;
    serialTask.inputStreamCount = 1;
    serialTask.outputStreams = serialLedStreamA;
    serialTask.outputStreamCount = 1;

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

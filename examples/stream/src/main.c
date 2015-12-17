#include "main.h"

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

    taskManagerRun(tasks, sizeof(tasks) / sizeof(Task*));

    return 0;
}

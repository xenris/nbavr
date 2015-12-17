#include "main.h"

int main(void) {
    static Stream stream = streamInit(20);

    static Stream* streamA[] = {&stream};

    helloTask.outputStreams = streamA;
    helloTask.outputStreamCount = 1;

    serialTask.inputStreams = streamA;
    serialTask.inputStreamCount = 1;

    static Task* tasks[] = {&helloTask, &ledTask, &serialTask};

    taskManagerRun(tasks, sizeof(tasks) / sizeof(Task*));

    return 0;
}

#include "main.h"

int main(void) {
    static Stream lightSerialStream = streamInit(20);
    static Stream lightTwiStream = streamInit(2 * sizeof(TWIAction));

    lightSensorTask.outputStreams = (Stream*[]){&lightSerialStream, &lightTwiStream};
    lightSensorTask.outputStreamCount = 2;

    twiTask.inputStreams = (Stream*[]){&lightTwiStream};
    twiTask.inputStreamCount = 1;

    serialTask.inputStreams = (Stream*[]){&lightSerialStream};
    serialTask.inputStreamCount = 1;

    static Task* tasks[] = {&lightSensorTask, &twiTask, &serialTask};

    taskManagerRun(tasks, sizeof(tasks) / sizeof(Task*));

    return 0;
}

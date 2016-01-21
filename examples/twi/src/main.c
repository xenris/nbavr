#include "main.h"

#define MICROS_PER_TICK ((64 * 256) / (F_CPU / 1000000))

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

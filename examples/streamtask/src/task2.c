#include "task2.h"

bool task2(void* data, uint32_t millis) {
    Task2Data* task2Data = data;

    if(!task2Data->initialised) {
        task2Data->outputStream = getOutputStream("stream");
        task2Data->delay = 4100;
        task2Data->initialised = true;
    }

    if(millis >= task2Data->delay) {
        outputStreamPush(task2Data->outputStream, task2Data->count);
        task2Data->delay = millis + 4100;
        task2Data->count += 25;
    }

    return true;
}

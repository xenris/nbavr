#include "task1.h"

bool task1(void* data, uint32_t millis) {
    Task1Data* task1Data = data;

    if(!task1Data->initialised) {
        task1Data->inputStream = getInputStream("stream");
        task1Data->printStream = getOutputStream("serial");
        task1Data->initialised = true;
    }

    if(millis >= task1Data->delay) {
        print(task1Data->printStream, "Task1 running (%i)\n", task1Data->count);
        task1Data->delay = millis + 1000;
        task1Data->count++;
    }

    uint8_t b;

    if(inputStreamPop(task1Data->inputStream, &b)) {
        print(task1Data->printStream, "Task1 received byte 0x%x\n", b);
    }

    return true;
}

#include "main.h"

typedef struct {
    bool initialised;
    uint16_t count;
    uint32_t delay;
    OutputStream* outputStream;
} HelloData;

typedef struct {
    bool initialised;
    uint32_t delay;
} LEDData;

bool helloTask(void* data, uint32_t millis);
bool ledTask(void* data, uint32_t millis);

int main(void) {
    TaskManager* taskManager = taskManagerInit(10);

    const char* serialTaskId = serialInit(taskManager);

    taskManagerAddTask(taskManager, helloTask, sizeof(HelloData), "helloTask", PRIORITY_LOW);
    taskManagerAddTask(taskManager, ledTask, sizeof(LEDData), "ledTask", PRIORITY_LOW);

    taskManagerAddStream(taskManager, "helloTask", serialTaskId, "helloStream", 25);

    taskManagerRun(taskManager);

    return 0;
}

bool helloTask(void* data, uint32_t millis) {
    HelloData* helloData = data;

    if(!helloData->initialised) {
        helloData->initialised = true;
        helloData->outputStream = getOutputStream("helloStream");
    } else if(millis >= helloData->delay) {
        print(helloData->outputStream, "hello! (%i)\n", helloData->count);
        helloData->delay = millis + 1000;
        helloData->count++;
    }

    return true;
}

bool ledTask(void* data, uint32_t millis) {
    LEDData* ledData = data;

    if(!ledData->initialised) {
        pinDirection(PinB5, Output);
        ledData->initialised = true;
    } else if(millis >= ledData->delay) {
        pinToggle(PinB5);
        ledData->delay = millis + 1000;
    }

    return true;
}

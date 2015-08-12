#include "main.h"

typedef struct {
    uint16_t count;
    uint32_t delay;
} HelloData;

typedef struct {
    bool initialised;
    uint32_t delay;
} LEDData;

bool helloTask(void* data, uint32_t millis);
bool ledTask(void* data, uint32_t millis);

int main(void) {
    TaskManager* taskManager = taskManagerInit(10);

    serialInit(taskManager);
    serialStdioInit();

    taskManagerAddTask(taskManager, helloTask, sizeof(HelloData), "helloTask", PRIORITY_LOW);
    taskManagerAddTask(taskManager, ledTask, sizeof(LEDData), "ledTask", PRIORITY_LOW);

    taskManagerRun(taskManager);

    return 0;
}

bool helloTask(void* data, uint32_t millis) {
    HelloData* helloData = data;

    if(millis >= helloData->delay) {
        printf("hello! (%i)\n", helloData->count);
        helloData->delay = millis + 1000;
        helloData->count++;
    }

    return true;
}

bool ledTask(void* data, uint32_t millis) {
    LEDData* ledData = data;

    if(!ledData->initialised) {
        DDRB |= _BV(5);
        ledData->initialised = true;
    } else if(millis >= ledData->delay) {
        PORTB ^= _BV(5);
        ledData->delay = millis + 1000;
    }

    return true;
}

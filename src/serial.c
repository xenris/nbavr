#include "serial.h"

typedef struct {
    bool initialised;
    OutputStream** outputStreams;
    InputStream** inputStreams;

    uint8_t currentInputStream;
    uint8_t currentOutputStream;
} SerialData;

bool serialTask(void* data, uint32_t millis);

const char* serialInit(TaskManager* taskManager) {
    enableUsart();

    const char* serialTaskId = "serialTask";

    taskManagerAddTask(taskManager, serialTask, sizeof(SerialData), serialTaskId, PRIORITY_DRIVER);

    return serialTaskId;
}

bool serialTask(void* data, uint32_t millis) {
    SerialData* serialData = data;
    (void)millis;

    if(!serialData->initialised) {
        serialData->initialised = true;
        serialData->outputStreams = getOutputStreams();
        serialData->inputStreams = getInputStreams();
    }

    if(usartDataRegisterEmpty()) {
        InputStream* inputStream = serialData->inputStreams[serialData->currentInputStream];
        uint8_t data;

        if((inputStream != NULL) && inputStreamPop(inputStream, &data)) {
            usartPush(data);
        } else {
            serialData->currentInputStream = (serialData->currentInputStream + 1) % 6;
        }
    }

    if(usartReceiveComplete()) {
        const uint8_t data = usartPop();

        for(uint8_t i = 0; i < 6; i++) {
            OutputStream* outputStream = serialData->outputStreams[i];

            if(outputStream != NULL) {
                outputStreamPush(outputStream, data);
            }
        }
    }

    return true;
}

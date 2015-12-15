#include "main.h"

int main(void) {
    TaskManager* taskManager = taskManagerInit(10);

    const char* serialTaskId = serialInit(taskManager);

    taskManagerAddTask(taskManager, task1, sizeof(Task1Data), "task1", PRIORITY_LOW);
    taskManagerAddTask(taskManager, task2, sizeof(Task2Data), "task2", PRIORITY_LOW);
    taskManagerAddTask(taskManager, ledTask, sizeof(LEDData), "ledTask", PRIORITY_LOW);

    taskManagerAddStream(taskManager, "task1", serialTaskId, "serial", 50);
    taskManagerAddStream(taskManager, "task2", "task1", "stream", 10);
    taskManagerAddStream(taskManager, serialTaskId, "ledTask", "serial", 10);

    taskManagerRun(taskManager);

    return 0;
}

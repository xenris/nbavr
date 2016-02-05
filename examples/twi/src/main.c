#include "main.h"

int main(void) {
    static Task* tasks[] = {&lightSensorTask, &twiTask, &serialTask, NULL};

    taskManagerRun(tasks);

    return 0;
}

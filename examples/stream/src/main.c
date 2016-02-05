#include "main.h"

int main(void) {
    static Task* tasks[] = {&task1, &task2, &ledTask, &serialTask, NULL};

    taskManagerRun(tasks);

    return 0;
}

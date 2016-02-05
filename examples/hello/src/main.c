#include "main.h"

int main(void) {
    static Task* tasks[] = {&helloTask, &ledTask, &serialTask, NULL};

    taskManagerRun(tasks);

    return 0;
}

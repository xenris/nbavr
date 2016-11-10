#include "main.h"

void main(void) {
    Task* tasks[] = {&task1, &task2, &ledTask, &serialTask, NULL};

    nbavr(tasks);
}

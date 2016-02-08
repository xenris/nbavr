#include "main.h"

int main(void) {
    Task* tasks[] = {&task1, &task2, &ledTask, &serialTask, NULL};

    nbavr(tasks);

    return 0;
}

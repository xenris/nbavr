#include "main.h"

int main(void) {
    Task* tasks[] = {&helloTask, &ledTask, &serialTask, NULL};

    nbavr(tasks);

    return 0;
}

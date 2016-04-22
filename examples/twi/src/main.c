#include "main.h"

void main(void) {
    Task* tasks[] = {&lightSensorTask, &twiTask, &serialTask, NULL};

    nbavr(tasks);
}

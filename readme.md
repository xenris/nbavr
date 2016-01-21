# nbavr

Non-blocking AVR.

Created by Henry Shepperd (hshepperd@gmail.com)

## Aim
A set of libraries written in C for AVR microprocessors which are guaranteed to never block.

A simple and reliable real time OS, with the ability to recover tasks if they freeze up.

To be reliable.

To be efficient.

To be an alternative to the Arduino system.

## Features
* Nonpreemptive multithreading.
* Prevents system hangs.
* Easy to use library for AVR hardware.
* Written in C.

## Status
Beta

The code is stable, but I am still in the process of making some fairly big changes and (hopefully) improvements to the api.

End user documentation is quite limited. This readme and the example projects are all the available documentation.

## Overview
nbavr is fairly similar to the Arduino system. You have setup and loop functions which provide you with the base program flow, as well as a bunch of libraries to make doing things easier and more reliable. The difference with nbavr is that you can have many tasks running at the same time (sequentially, not parallel) each with their own setup and loop functions. Each task also has a crash function which is called in the event that the task ever freezes up. This allows the task to try to recover before being reset. All other tasks continue running normally.

## TaskManager (real time os)
* The task manager provides nonpreemptive multitasking, which means all tasks share the same stack and each task step has to return before the next task can start. This has the advantage that less RAM is required, and that every task is atomic relative to each other. The disadvantage is that a single task can take up a large chunk of time (up to 16ms) before the task manager will step in and allow another task to run.

```c
// Run a group of tasks.
// This function never returns.
// No more tasks can be started after this is called.
void taskManagerRun(Task** tasks, uint8_t taskCount)
```

```c
// A group of tasks is declared like this:
static Task* tasks[] = {&task1, &task2, &task3};
```

## Tasks
* Tasks have setup, loop, and crash functions which provide program flow.
* 1. First setup is called.
* 2. Then loop is called repeatedly.
* 3. If setup or loop take too long crash is called before going back to step 1.
* Each task has a priority. PRIORITY_MEDIUM is the default.
* Each task has a set of input and output streams for communicating with other tasks.

```c
// Task declaration.
// All elements are optional. (Although, .dataSize is required if .data is specified.)
Task task = {
    .data = ..., // Pointer to the memory block this task is using.
    .dataSize = ..., // Size of the memory block in bytes.
    .setup = ..., // Function called once at task start and after crash.
    .loop = ..., // Function called repetedly after setup is called.
    .crash = ..., // Function called when the task manager detects that the task has halted.
    .priority = ..., // PRIORITY_LOW/MEDIUM/HIGH/DRIVER.
    .inputStreams = ..., // Array of input streams.
    .inputStreamCount = ..., // Number of input streams.
    .outputStreams = ..., // Array of output streams.
    .outputStreamCount = ..., // Number of output streams.
};
```

```c
// The function required for .setup, .loop and .crash.
typedef void (*TaskFunction)(Task* task);
```

## Task halt handling
* The task manager monitors each task using the hardware watchdog and will reset a task if it is taking too long, allowing all the other tasks to continue running, while giving the crashed task the chance to recover.
* In the event that there is an unrecoverable halt (can only happen if someone does something silly like disabling interrupts and then going into an infinite loop) the AVR will be hardware reset and resetWasWatchdog() will return true until the task manager is started or resetClearStatus() is called.
* Each task gets a maximum of 16ms each iteration before the task manager assumes the task has halted.
* If a task continuously keeps halting it will consume 16ms each time which will cause the other tasks to slow down.

## Streams
* First in first out (fifo) buffer.
* Used for communication between tasks
* Because tasks run atomically to each other you can be sure that under normal circumstances a stream will contain a complete message. (Abnormal circumstances include the message being bigger than the stream's buffer, or having the task halt before it finishes writing its message.)

```c
// To create a new stream of 20 bytes.
static Stream stream = streamInit(20);
```

```c
// A selection of functions for working with streams.
bool streamPush(Stream* stream, uint8_t n);
bool streamPop(Stream* stream, uint8_t* n);
bool streamPeek(Stream* stream, uint8_t* n);
int16_t streamUsed(Stream* stream);
int16_t streamUnused(Stream* stream);
bool streamHasOverflowed(Stream* stream);
bool streamEmpty(Stream* stream);
bool streamHasData(Stream* stream);
```

```c
// To join tasks via a stream.
static Stream stream = streamInit(20);
static Stream* streamA[] = {&stream};

task1.outputStreams = streamA;
task1.outputStreamCount = 1;

task2.inputStreams = streamA;
task2.inputStreamCount = 1;
```

## Recommended tools
* git
* avr-gcc
* avr-binutils
* avr-libc
* avrdude
* tup
* bash
* a terminal
* picocom

## Building
Running build.sh will compile the library and all the examples.

## Running the examples

### Method 1
1. Clone nbavr.
2. Check that Tuprules.tup and build.sh are correct for your setup.
3. Run "build.sh -u hello" to compile and upload hello to a device.

### Method 2
1. Copy one of the examples to somewhere convenient.
2. Clone nbavr into lib/nbavr/.
3. Check that Tuprules.tup and build.sh are correct for your setup.
4. Run "build.sh -u" to compile and upload to a device.

## Communicating over serial
picocom --imap lfcrlf --omap crlf /dev/ttyACM1

Change the serial port to suit your system.

## Interrupts and hardware used by nbavr
The task manager uses the watchdog timer to monitor tasks.

## Devices tested
* atmega328p

## Contributors
If you add, fix, or improve something in this library feel free to add your name here.
* Henry Shepperd

## Warranty
No.

## License
Feel free to use any of this code however you like, except for evil.

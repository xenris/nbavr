# nbavr

Non-blocking AVR.

Created by Henry Shepperd (hshepperd@gmail.com)

## Aim
A set of libraries for AVR microprocessors which are assured to never block.

Plus a simple and reliable real time OS which provides the ability to run independent tasks atomically (in terms of both time and memory), and has the ability to reset tasks if they happen to crash/halt.

## Status
Beta

The code is stable, but I am in the process of making some fairly big changes and (hopefully) improvements to the api.

## TaskManager (real time os)
* The task manager is nonpreemptive, which means all tasks share the same stack and each task step has to return before the next task can start. This has the advantage that less RAM is required, and that every task is atomic relative to each other.
* The task manager also monitors each task and will reset a task if it is taking too long, allowing all the other tasks to continue running, while giving the crashed task the chance to recover.
* The task manager doesn't manage memory allocated with m/calloc, so if a task calls m/calloc and then crashes a memory leak will occur. On an 8 bit microprocessor it is much more reliable to only use static memory anyway, so don't use m/calloc.

```c
// Run a group of tasks.
// This function never returns.
// No more tasks can be started after this is called.
void taskManagerRun(Task** tasks, uint8_t taskCount)
```

```c
// A group of tasks is declared like this:
static Task* tasks[] = {&helloTask, &ledTask, &serialTask};
```

## Tasks
* If a task takes too long to return it will be reset by the task manager (memory cleared and setup called).
* millis is the number of milliseconds passed since the task manager was started.

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
    .state = ..., // Ignore. (Used by the task manager to keep track of task state.)
    .inputStreams = ..., // Array of input streams.
    .inputStreamCount = ..., // Number of input streams.
    .outputStreams = ..., // Array of output streams.
    .outputStreamCount = ..., // Number of output streams.
};
```

```c
// The function required for .setup, .loop and .crash.
typedef void (*TaskFunction)(Task* task, uint32_t millis);
```

## Streams
* First in first out (fifo) buffer.
* Used for communication between tasks
* Because tasks run atomically you can be sure that under normal circumstances a stream will contain a complete message. (Abnormal circumstances include the message being bigger than the stream's buffer, or having the task halt/crash before it finishes writing its message.)

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
4. Run build.sh -u to compile and upload to a device.

## Communicating over serial
picocom --imap lfcrlf --omap crlf /dev/ttyACM1

Change the serial port to suit your system.

## Interrupts and hardware used
The task manager uses the 8bit timer/counter0 with the overflow interrupt to run.

## Devices tested
* atmega328p

## Contributors
(If you add, fix, or improve something in this library feel free to add your name here.)
* Henry Shepperd

## Warranty
No.

## License
Feel free to use any of this code however you like, except for evil.

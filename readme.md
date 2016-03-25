# nbavr

Non-blocking AVR.

Created by Henry Shepperd (hshepperd@gmail.com)

An alternative to the Arduino system.

## Aim
* To be reliable.
* To be efficient.
* To be simple.
* To work with most 8-bit AVR microprocessors.

## Features
* Written in C.
* Real time operating system.
* Non-preemptive miltitasking.
* Prevents system lockups.
* All functions are non-block.

## Status
Beta

The code is stable and most of the API is set, but some things may change, and more things will be added.

## Documentation
Documentation is limited, but there should be enough to get started.

See this readme, [reference](reference.md), and the [examples](examples/).

## Overview
nbavr is fairly similar to the Arduino system. You have setup and loop functions which provide you with the base program flow, as well as a bunch of libraries to make doing things easier and more reliable. The difference with nbavr is that you can have many tasks running at the same time each with their own setup and loop functions. Each task also has a crash function which is called in the event that the task ever locks up. After crash is called the task's setup will be called before resuming the loop. All other tasks continue running normally.

## TaskManager (real time os)
* The task manager provides nonpreemptive multitasking, which means all tasks share the same stack and each task step has to return before the next task can start. This has the advantage that less RAM is required, and that every task is atomic relative to each other. The disadvantage is that a single task can take up a large chunk of time (up to 16ms) before the task manager will stop and reset it to allow the other tasks to run.

## Tasks
* Tasks have setup, loop, and crash functions which provide program flow.
* 1. First setup is called.
* 2. Then loop is called repeatedly.
* 3. If setup or loop take too long crash is called before going back to step 1.
* Each task has a priority. PRIORITY_MEDIUM is the default.

## Task halt handling
* The task manager monitors each task using the hardware watchdog and will reset a task if it is taking too long, allowing all the other tasks to continue running, while giving the crashed task the chance to recover.
* In the event that there is an unrecoverable halt (can only happen if someone does something silly like disabling global interrupts before going into an infinite loop) the AVR will be hardware reset and resetWasWatchdog() will return true until the task manager is started or resetClearStatus() is called.
* Each task gets a maximum of 16ms each iteration before the task manager assumes the task has halted.
* If a task continuously keeps halting it will consume 16ms each time which will take run time away from the other tasks.

## Streams
* First in first out (fifo) byte buffer.
* Can be used for communication between tasks.
* Because tasks run atomically to each other you can be sure that under normal circumstances a stream will contain a complete message. (Abnormal circumstances include the message being bigger than the stream's buffer, or having the task halt/crash before it finishes writing its message.)

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
The watchdog timer is used to monitor tasks, resetting them if they halt.
Timer/Counter1 is used for the millisecond clock and microsecond interrupts.

## Devices tested
* atmega328p

## Contributors
If you add, fix, or improve something in this library feel free to add your name here.
* Henry Shepperd

## Warranty
No.

## License
Feel free to use any of this code however you like, except for evil.

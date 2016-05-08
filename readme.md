# nbavr

Non-blocking AVR.

Created by Henry Shepperd (hshepperd@gmail.com)

## About
A c library for 8-bit Atmel microprocessors.

## Aims
* Reliable.
* Efficient.
* Simple.
* Light weight.
* All non-blocking functions.
* Non-preemptive multitasking.
* Prevent system and task lockups.
* Compatible with as many AVR chips as possible.
* High level hardware abstraction with low overhead.

## Status
Beta

The code is stable and most of the API is set, but some things may change, and more things will be added.

## Documentation
Documentation is limited, but there should be enough to get started.

See this readme, [reference](reference.md), the [examples](examples/), and the [project template](https://github.com/xenris/nbavr-project-template).

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

## Building the library
Change build.config to suit your environment, then run build.sh.

## Running the examples
1. Change build.config and tup.config to suit your environment.
1. Run "build.sh -u hello" to compile and upload hello to a device.

## Creating a new project
See [nbavr-project-template](https://github.com/xenris/nbavr-project-template).

## Serial Communication
picocom --imap lfcrlf --omap crlf /dev/ttyACM0

(Change the serial port to suit your environment.)

## Interrupts and hardware used by nbavr
The watchdog timer is used do a full reset of the microcontroller if it gets completely locked up.
Timer/Counter1 is used to provide the system clock and microsecond interrupts.

## Devices tested
* atmega328p
* atmega8

## Contributors
If you add, fix, or improve something in this library feel free to add your name here.
* Henry Shepperd

## Warranty
No.

## License
You may use any of this code however you like, except for evil.

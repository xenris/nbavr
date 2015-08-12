# Examples

## Recommended parts

* git
* avr-gcc
* avr-binutils
* avr-libc
* avrdude
* tup
* bash
* a terminal
* picocom

## Setup

1. Copy one of the examples to somewhere convenient.
2. Clone nbavr into the lib/nbavr/ directory.
3. Remove the underscore from Tupfile_
4. Read build.sh and change it to suit your setup.
5. Read Tupfile and lib/nbavr/Tupfile and change them to suit your setup.
6. Start monitoring serial output from another terminal (picocom /dev/ttyACM1).
7. Run build.sh -u to compile and upload to a device.

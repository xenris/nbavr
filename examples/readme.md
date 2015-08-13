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

## Building the examples

### Method 1
1. Clone nbavr.
2. Look in Tuprules.tup in nbavr's root directory.
3. Run "tup init", then "tup" to compile the library and all of its examples.
4. Look in examples/[example]/gen/ for the hex file.

### Method 2
1. Copy one of the examples to somewhere convenient.
2. Clone nbavr into lib/nbavr/.
3. Look at build.sh and Tuprules.tup in the example's root directory.
4. Run build.sh -u to compile and upload to a device.

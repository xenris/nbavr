#!/bin/sh

# "build.sh" to build the library and its examples.
# "build.sh -u hellotask" to also upload the example "hellotask".

mcu=m328p
port=/dev/ttyACM0
programmer=stk500v2

set -e

if [ ! -d ".tup" ]; then
    tup init
fi

tup

if [ "${1}" == "-u" ]; then
    exampledir="examples/${2}"

    if [ -d $exampledir ] && [ "${2}" != "" ]; then
        hexfile="$exampledir/gen/firmware.hex"

        avrdude -p $mcu -P $port -c $programmer -e -U flash:w:$hexfile
    else
        echo "Example ${2} not found"
        echo "Try one of:"
        for e in examples/*/ ; do
            basename $e
        done
    fi
fi

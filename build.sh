#!/bin/sh

# "build.sh" to build the library and its tests.
# "build.sh -u hello" to also upload the test "hello".

set -e

source ./build.config

tup

if [ "${1}" == "-u" ]; then
    testdir="tests/${2}"

    if [ -d $testdir ] && [ "${2}" != "" ]; then
        elf="$testdir/gen/firmware.elf"

        avr-size $elf -C --mcu=$mcu

        pkill picocom && sleep 1 || true

        avrdude -p $mcu -P $port -c $programmer -e -U flash:w:$elf
    else
        echo "Example ${2} not found"
        echo "Try one of:"
        for e in tests/*/ ; do
            basename $e
        done
    fi
fi

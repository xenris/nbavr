#!/bin/sh

# "build.sh" to build the library and its examples.
# "build.sh -u hello" to also upload the example "hello".

set -e

source ./build.config

tup

if [ "${1}" == "-u" ]; then
    exampledir="examples/${2}"

    if [ -d $exampledir ] && [ "${2}" != "" ]; then
        pkill picocom && sleep 1 || true

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

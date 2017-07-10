#!/bin/sh

set -e

cd test/

cflags="-Wall -Os -fmax-errors=3"
includes="-I ../src/"
libs="-lgtest -lgtest_main"

if [ "$#" -eq 0 ]
then
    declare -a tests=($(find . -name "test_*.cpp" | sed 's:./test_\(.*\)\.cpp:\1:'))
else
    declare -a tests=("$@")
fi

for test in "${tests[@]}"
do
    echo "###### $test #######"

    g++ $includes $cflags $libs "test_${test}.cpp" -o test_exe

    ./test_exe

    rm test_exe
done

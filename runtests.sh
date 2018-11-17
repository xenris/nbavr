#!/bin/sh

cd test/

cflags="-Werror -Wall -fmax-errors=3 -std=c++17"
includes="-I ../src/"
libs="-lgtest -lgtest_main"

if [ "$#" -eq 0 ] ; then
    declare -a chips=($(basename -a -s .hpp $(find ../src/hardware/chips/ -name '*.hpp')))
else
    declare -a chips=("$@")
fi

for chip in "${chips[@]}" ; do
    echo "############ $chip ############"

    g++ $includes $cflags $libs "-D__${chip}__" "-DRECORD_ID=\"${chip}\"" "test.cpp" -o test_exe

    error=$?

    if [ "$error" -eq 0 ] ; then
        ./test_exe

        error=$?

        rm -f test_exe
    fi

    if [ "$error" -eq 0 ] ; then
        echo -e "\e[32m^^^^^^^^^^^^ $chip ^^^^^^^^^^^^\e[0m"
    else
        echo -e "\e[31m^^^^^^^^^^^^ $chip ^^^^^^^^^^^^\e[0m"

        exit -1
    fi
done

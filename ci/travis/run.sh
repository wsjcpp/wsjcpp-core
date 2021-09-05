#!/bin/bash

check_ret() {
    if [ $1 -ne 0 ]; then
        echo ""
        echo "!!! FAIL: $2"
        echo "********************************************************************************"
        echo ""
        exit $1
    else
        echo ""
        echo "*** SUCCESS: $2"
        echo "********************************************************************************"
        echo ""
    fi
}

rm -rf tmp
./build_simple.sh
check_ret $? "build"

cd ./unit-tests.wsjcpp
rm -rf tmp
check_ret $? "cd tests"
./build_simple.sh
check_ret $? "build tests"
./run_unit-tests.sh
check_ret $? "run unit-tests"

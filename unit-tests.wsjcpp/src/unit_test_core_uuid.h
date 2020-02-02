#ifndef UNIT_TEST_CORE_UUID_H
#define UNIT_TEST_CORE_UUID_H

#include <wsjcpp_unit_tests.h>

class UnitTestCoreUuid : public WSJCppUnitTestBase {
    public:
        UnitTestCoreUuid();
        virtual void init();
        virtual bool run();
};

#endif // UNIT_TEST_CORE_UUID_H
#ifndef UNIT_TEST_IP_V4_H
#define UNIT_TEST_IP_V4_H

#include <unit_tests.h>

class UnitTestIPv4 : public UnitTestBase {
    public:
        UnitTestIPv4();
        virtual void init();
        virtual bool run();
};

#endif // UNIT_TEST_IP_V4_H
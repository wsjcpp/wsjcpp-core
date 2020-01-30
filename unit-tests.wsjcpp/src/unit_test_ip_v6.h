#ifndef UNIT_TEST_IP_V6_H
#define UNIT_TEST_IP_V6_H

#include <wsjcpp_unit_tests.h>

class UnitTestIPv6 : public UnitTestBase {
    public:
        UnitTestIPv6();
        virtual void init();
        virtual bool run();
};

#endif // UNIT_TEST_IP_V6_H
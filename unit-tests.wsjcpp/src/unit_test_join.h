#ifndef UNIT_TEST_JOIN_H
#define UNIT_TEST_JOIN_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestJoin : public WsjcppUnitTestBase {
    public:
        UnitTestJoin();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_JOIN_H


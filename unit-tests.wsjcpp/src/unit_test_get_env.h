#ifndef UNIT_TEST_GET_ENV_H
#define UNIT_TEST_GET_ENV_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestGetEnv : public WsjcppUnitTestBase {
    public:
        UnitTestGetEnv();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_GET_ENV_H


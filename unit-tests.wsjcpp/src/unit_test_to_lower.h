#ifndef UNIT_TEST_TO_LOWER_H
#define UNIT_TEST_TO_LOWER_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestToLower : public WsjcppUnitTestBase {
    public:
        UnitTestToLower();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_TO_LOWER_H


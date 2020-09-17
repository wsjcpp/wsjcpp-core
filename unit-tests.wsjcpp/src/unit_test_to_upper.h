#ifndef UNIT_TEST_TO_UPPER_H
#define UNIT_TEST_TO_UPPER_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestToUpper : public WsjcppUnitTestBase {
    public:
        UnitTestToUpper();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_TO_UPPER_H


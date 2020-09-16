#ifndef UNIT_TEST_SPLIT_H
#define UNIT_TEST_SPLIT_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestSplit : public WsjcppUnitTestBase {
    public:
        UnitTestSplit();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_SPLIT_H


#ifndef UNIT_TEST_REPLACE_ALL_H
#define UNIT_TEST_REPLACE_ALL_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestReplaceAll : public WsjcppUnitTestBase {
    public:
        UnitTestReplaceAll();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_REPLACE_ALL_H


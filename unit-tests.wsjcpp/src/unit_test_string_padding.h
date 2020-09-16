#ifndef UNIT_TEST_STRING_PADDING_H
#define UNIT_TEST_STRING_PADDING_H

#include <wsjcpp_unit_tests.h>

class UnitTestStringPadding : public WsjcppUnitTestBase {
    public:
        UnitTestStringPadding();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_STRING_PADDING_H

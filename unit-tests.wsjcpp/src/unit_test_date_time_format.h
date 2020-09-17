#ifndef UNIT_TEST_DATE_TIME_FORMAT_H
#define UNIT_TEST_DATE_TIME_FORMAT_H

#include <wsjcpp_unit_tests.h>

class UnitTestDateTimeFormat : public WsjcppUnitTestBase {
    public:
        UnitTestDateTimeFormat();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_DATE_TIME_FORMAT_H


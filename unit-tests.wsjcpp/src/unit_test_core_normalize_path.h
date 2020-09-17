#ifndef UNIT_TEST_CORE_NORMALIZE_PATH_H
#define UNIT_TEST_CORE_NORMALIZE_PATH_H

#include <wsjcpp_unit_tests.h>

class UnitTestCoreNormalizePath : public WsjcppUnitTestBase {
    public:
        UnitTestCoreNormalizePath();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_CORE_NORMALIZE_PATH_H
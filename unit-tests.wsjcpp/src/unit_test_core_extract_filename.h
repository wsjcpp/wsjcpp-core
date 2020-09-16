#ifndef UNIT_TEST_CORE_EXCTRACT_FILENAME_H
#define UNIT_TEST_CORE_EXCTRACT_FILENAME_H

#include <wsjcpp_unit_tests.h>

class UnitTestCoreExtractFilename : public WsjcppUnitTestBase {
    public:
        UnitTestCoreExtractFilename();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_CORE_EXCTRACT_FILENAME_H
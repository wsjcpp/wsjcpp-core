#ifndef UNIT_TEST_CREATE_EMPTY_FILE_H
#define UNIT_TEST_CREATE_EMPTY_FILE_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestCreateEmptyFile : public WsjcppUnitTestBase {
    public:
        UnitTestCreateEmptyFile();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_CREATE_EMPTY_FILE_H


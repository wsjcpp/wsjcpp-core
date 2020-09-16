#ifndef UNIT_TEST_LIST_OF_DIRS_H
#define UNIT_TEST_LIST_OF_DIRS_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestListOfDirs : public WsjcppUnitTestBase {
    public:
        UnitTestListOfDirs();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_LIST_OF_DIRS_H


#ifndef UNIT_TEST_READ_FILE_TO_BUFFER_H
#define UNIT_TEST_READ_FILE_TO_BUFFER_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestReadFileToBuffer : public WsjcppUnitTestBase {
    public:
        UnitTestReadFileToBuffer();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_READ_FILE_TO_BUFFER_H


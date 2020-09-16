#ifndef UNIT_TEST_FILE_PERMISSIONS_H
#define UNIT_TEST_FILE_PERMISSIONS_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestFilePermissions : public WsjcppUnitTestBase {
    public:
        UnitTestFilePermissions();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_FILE_PERMISSIONS_H


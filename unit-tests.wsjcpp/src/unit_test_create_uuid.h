#ifndef UNIT_TEST_CREATE_UUID_H
#define UNIT_TEST_CREATE_UUID_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestCreateUuid : public WsjcppUnitTestBase {
    public:
        UnitTestCreateUuid();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_CREATE_UUID_H


#ifndef UNIT_TEST_TEST_RESOURCES_H
#define UNIT_TEST_TEST_RESOURCES_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestTestResources : public WsjcppUnitTestBase {
    public:
        UnitTestTestResources();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_TEST_RESOURCES_H


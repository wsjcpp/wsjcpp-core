#ifndef UNIT_TEST_ENCODE_URI_COMPONENT_H
#define UNIT_TEST_ENCODE_URI_COMPONENT_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestEncodeUriComponent : public WsjcppUnitTestBase {
    public:
        UnitTestEncodeUriComponent();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_ENCODE_URI_COMPONENT_H


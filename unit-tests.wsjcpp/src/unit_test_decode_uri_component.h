#ifndef UNIT_TEST_DECODE_URI_COMPONENT_H
#define UNIT_TEST_DECODE_URI_COMPONENT_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestDecodeUriComponent : public WsjcppUnitTestBase {
    public:
        UnitTestDecodeUriComponent();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_DECODE_URI_COMPONENT_H


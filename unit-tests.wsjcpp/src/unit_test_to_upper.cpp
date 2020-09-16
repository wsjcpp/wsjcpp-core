#include "unit_test_to_upper.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestToUpper)

UnitTestToUpper::UnitTestToUpper()
    : WsjcppUnitTestBase("UnitTestToUpper") {
}

// ---------------------------------------------------------------------

bool UnitTestToUpper::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestToUpper::executeTest() {
    compare("str1", "ABC_DEF", WsjcppCore::toUpper("abc_def"));
}

// ---------------------------------------------------------------------

bool UnitTestToUpper::doAfterTest() {
    // nothing
    return true;
}
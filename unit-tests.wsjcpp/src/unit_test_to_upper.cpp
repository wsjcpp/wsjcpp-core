#include "unit_test_to_upper.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestToUpper)

UnitTestToUpper::UnitTestToUpper()
    : WsjcppUnitTestBase("UnitTestToUpper") {
}

// ---------------------------------------------------------------------

void UnitTestToUpper::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestToUpper::run() {
    bool bTestSuccess = true;
    compareS(bTestSuccess, "str1", "ABC_DEF", WsjcppCore::toUpper("abc_def"));
    return bTestSuccess;
}


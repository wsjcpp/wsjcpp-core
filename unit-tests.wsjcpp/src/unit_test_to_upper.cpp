#include "unit_test_to_upper.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestToUpper)

UnitTestToUpper::UnitTestToUpper()
    : UnitTestBase("UnitTestToUpper") {
}

// ---------------------------------------------------------------------

void UnitTestToUpper::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestToUpper::run() {
    bool bTestSuccess = true;
    compareS(bTestSuccess, "str1", "ABC_DEF", WSJCppCore::toUpper("abc_def"));
    return bTestSuccess;
}


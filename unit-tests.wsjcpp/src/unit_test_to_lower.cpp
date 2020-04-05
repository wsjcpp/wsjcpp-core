#include "unit_test_to_lower.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestToLower)

UnitTestToLower::UnitTestToLower()
    : WsjcppUnitTestBase("UnitTestToLower") {
}

// ---------------------------------------------------------------------

void UnitTestToLower::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestToLower::run() {
    bool bTestSuccess = true;
    compareS(bTestSuccess, "str1", "abc_def", WsjcppCore::toLower("ABC_DEF"));
    return bTestSuccess;
}


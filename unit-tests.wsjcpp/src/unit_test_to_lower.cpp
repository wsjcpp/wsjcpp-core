#include "unit_test_to_lower.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestToLower)

UnitTestToLower::UnitTestToLower()
    : WSJCppUnitTestBase("UnitTestToLower") {
}

// ---------------------------------------------------------------------

void UnitTestToLower::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestToLower::run() {
    bool bTestSuccess = true;
    compareS(bTestSuccess, "str1", "abc_def", WSJCppCore::toLower("ABC_DEF"));
    return bTestSuccess;
}


#include "unit_test_to_lower.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestToLower)

UnitTestToLower::UnitTestToLower()
    : WsjcppUnitTestBase("UnitTestToLower") {
}

// ---------------------------------------------------------------------

bool UnitTestToLower::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestToLower::executeTest() {
    compareS("str1", "abc_def", WsjcppCore::toLower("ABC_DEF"));
}

// ---------------------------------------------------------------------

bool UnitTestToLower::doAfterTest() {
    // nothing
    return true;
}
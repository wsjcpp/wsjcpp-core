
#include "unit_test_string_padding.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// UnitTestStringPadding

REGISTRY_WSJCPP_UNIT_TEST(UnitTestStringPadding)

UnitTestStringPadding::UnitTestStringPadding()
    : WsjcppUnitTestBase("UnitTestStringPadding") {
}

// ---------------------------------------------------------------------

bool UnitTestStringPadding::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestStringPadding::executeTest() {
    std::string sIn = "some";
    std::string sResult = WsjcppCore::doPadLeft(sIn, '_', 6);
    compare("pad left", sResult, "__some");
    std::string sResult2 = WsjcppCore::doPadRight(sIn, '_', 6);
    compare("pad left", sResult2, "some__");
}

// ---------------------------------------------------------------------

bool UnitTestStringPadding::doAfterTest() {
    // nothing
    return true;
}



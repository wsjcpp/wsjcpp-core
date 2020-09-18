#include "unit_test_join.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestJoin)

UnitTestJoin::UnitTestJoin()
    : WsjcppUnitTestBase("UnitTestJoin") {
}

// ---------------------------------------------------------------------

bool UnitTestJoin::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestJoin::executeTest() {
    std::vector<std::string> vTest;
    vTest.push_back("");
    vTest.push_back("1");
    vTest.push_back("2");
    vTest.push_back("abc");
    std::string sRet = WsjcppCore::join(vTest, ", ");
    compare("join", sRet, ", 1, 2, abc");
}

// ---------------------------------------------------------------------

bool UnitTestJoin::doAfterTest() {
    // nothing
    return true;
}
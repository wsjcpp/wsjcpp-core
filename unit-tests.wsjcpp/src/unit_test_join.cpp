#include "unit_test_join.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestJoin)

UnitTestJoin::UnitTestJoin()
    : WSJCppUnitTestBase("UnitTestJoin") {
}

// ---------------------------------------------------------------------

void UnitTestJoin::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestJoin::run() {
    bool bTestSuccess = true;
    std::vector<std::string> vTest;
    vTest.push_back("");
    vTest.push_back("1");
    vTest.push_back("2");
    vTest.push_back("abc");
    std::string sRet = WSJCppCore::join(vTest, ", ");
    compareS(bTestSuccess, "join", sRet, ", 1, 2, abc");
    return bTestSuccess;
}


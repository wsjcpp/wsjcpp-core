#include "unit_test_replace_all.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestReplaceAll)

UnitTestReplaceAll::UnitTestReplaceAll()
    : WsjcppUnitTestBase("UnitTestReplaceAll") {
}

// ---------------------------------------------------------------------

bool UnitTestReplaceAll::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestReplaceAll::executeTest() {
    struct LTest {
        LTest(
            const std::string &sStr,
            const std::string &sFrom,
            const std::string &sTo,
            const std::string &sExpectedStr
        ) {
            this->sStr = sStr;
            this->sFrom = sFrom;
            this->sTo = sTo;
            this->sExpectedStr = sExpectedStr;
        };
        std::string sStr;
        std::string sFrom;
        std::string sTo;
        std::string sExpectedStr;
    };
    std::vector<LTest> tests;
    tests.push_back(LTest("Some long string", "o", "00", "S00me l00ng string"));
    tests.push_back(LTest("S00me l00ng string", "00", "o", "Some long string"));
    tests.push_back(LTest("dddng.string", ".", "_", "dddng_string"));

    for (int i = 0; i < tests.size(); i++) {
        LTest test = tests[i];
        std::string sStr = test.sStr;
        WsjcppCore::replaceAll(sStr, test.sFrom, test.sTo);
        compare("test" + std::to_string(i), sStr, test.sExpectedStr);
    }
}

// ---------------------------------------------------------------------

bool UnitTestReplaceAll::doAfterTest() {
    // nothing
    return true;
}
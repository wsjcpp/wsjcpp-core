#include "unit_test_get_env.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestGetEnv)

UnitTestGetEnv::UnitTestGetEnv()
    : WsjcppUnitTestBase("UnitTestGetEnv") {
}

// ---------------------------------------------------------------------

bool UnitTestGetEnv::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestGetEnv::executeTest() {
    struct LTest {
        LTest(const std::string &sName, bool bExpectedResult, const std::string &sExpectedValue) {
            this->sName = sName;
            this->sExpectedValue = sExpectedValue;
            this->bExpectedResult = bExpectedResult;
        };
        std::string sName;
        bool bExpectedResult;
        std::string sExpectedValue;
    };

    std::vector<LTest> tests;
    tests.push_back(LTest("TESTENVVALUE1", true, "testvalue1"));
    tests.push_back(LTest("TESTENVVALUE1_", false, ""));
    tests.push_back(LTest("TEST_ENV_VALUE2", true, "test some value2"));
    tests.push_back(LTest("TEST_ENV_VALUE3", true, "932749387"));

    for (int i = 0; i < tests.size(); i++) {
        LTest test = tests[i];
        std::string sValue;
        bool bResult = WsjcppCore::getEnv(test.sName, sValue);
        std::string testBaseName = "test#" + std::to_string(i) + " (" + test.sName + ")";
        compare(testBaseName + "-result", bResult, test.bExpectedResult);
        compare(testBaseName + "-value", sValue, test.sExpectedValue);
    }
}

// ---------------------------------------------------------------------

bool UnitTestGetEnv::doAfterTest() {
    // nothing
    return true;
}
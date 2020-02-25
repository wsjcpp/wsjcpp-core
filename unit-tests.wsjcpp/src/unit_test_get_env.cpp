#include "unit_test_get_env.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestGetEnv)

UnitTestGetEnv::UnitTestGetEnv()
    : WSJCppUnitTestBase("UnitTestGetEnv") {
}

// ---------------------------------------------------------------------

void UnitTestGetEnv::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestGetEnv::run() {
    bool bTestSuccess = true;
    
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
        bool bResult = WSJCppCore::getEnv(test.sName, sValue);
        std::string testBaseName = "test#" + std::to_string(i) + " (" + test.sName + ")";
        compareB(bTestSuccess,  testBaseName + "-result", bResult, test.bExpectedResult);
        compareS(bTestSuccess, testBaseName + "-value", sValue, test.sExpectedValue);
    }
    return bTestSuccess;
}

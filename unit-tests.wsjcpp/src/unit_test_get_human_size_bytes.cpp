#include "unit_test_get_human_size_bytes.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestgetHumanSizeBytes)

UnitTestgetHumanSizeBytes::UnitTestgetHumanSizeBytes()
    : WsjcppUnitTestBase("UnitTestgetHumanSizeBytes") {
}

// ---------------------------------------------------------------------

bool UnitTestgetHumanSizeBytes::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestgetHumanSizeBytes::executeTest() {
    struct LTest {
        LTest(
            long nValue,
            const std::string &sExpectedStr
        ) {
            this->nValue = nValue;
            this->sExpectedStr = sExpectedStr;
        };
        long nValue;
        std::string sExpectedStr;
    };
    std::vector<LTest> tests;
    tests.push_back(LTest(0, "0B"));
    tests.push_back(LTest(30, "30B"));
    tests.push_back(LTest(999, "999B"));
    tests.push_back(LTest(1000, "1KB"));
    tests.push_back(LTest(1400, "1KB"));
    tests.push_back(LTest(1600, "2KB"));
    tests.push_back(LTest(100600, "101KB"));
    tests.push_back(LTest(10123, "10KB"));
    tests.push_back(LTest(10499, "10KB"));
    tests.push_back(LTest(10999, "11KB"));
    tests.push_back(LTest(100999, "101KB"));
    tests.push_back(LTest(1000999, "1MB"));
    tests.push_back(LTest(1001999, "1MB"));
    tests.push_back(LTest(1999999, "2MB"));
    tests.push_back(LTest(1401999, "1MB"));
    tests.push_back(LTest(1501999, "2MB"));
    tests.push_back(LTest(201001999, "201MB"));
    tests.push_back(LTest(2000501999, "2GB"));
    tests.push_back(LTest(2300501999, "2GB"));
    tests.push_back(LTest(2500501999, "3GB"));

    for (int i = 0; i < tests.size(); i++) {
        long nValue = tests[i].nValue;
        std::string sExpectedStr = tests[i].sExpectedStr;
        std::string sGotStr = WsjcppCore::getHumanSizeBytes(nValue);
        compareS("value=" + std::to_string(nValue), sGotStr, sExpectedStr);
    }
}

// ---------------------------------------------------------------------

bool UnitTestgetHumanSizeBytes::doAfterTest() {
    // nothing
    return true;
}
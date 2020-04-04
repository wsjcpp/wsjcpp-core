#include "unit_test_uint2_hex_string.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestUint2HexString)

UnitTestUint2HexString::UnitTestUint2HexString()
    : WsjcppUnitTestBase("UnitTestUint2HexString") {
}

// ---------------------------------------------------------------------

void UnitTestUint2HexString::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestUint2HexString::run() {
    bool bTestSuccess = true;

    struct LTest {
        LTest(
            unsigned int nNumber,
            const std::string &sExpectedStr
        ) {
            this->nNumber = nNumber;
            this->sExpectedStr = sExpectedStr;
        };
        unsigned int nNumber;
        std::string sExpectedStr;
    };
    std::vector<LTest> tests;
    tests.push_back(LTest(1, "00000001"));
    tests.push_back(LTest(3000, "00000bb8"));
    tests.push_back(LTest(4123123123, "f5c1ddb3"));

    for (int i = 0; i < tests.size(); i++) {
        LTest test = tests[i];
        std::string sStr = WsjcppCore::uint2hexString(test.nNumber);
        compareS(bTestSuccess, "test" + std::to_string(i), sStr, test.sExpectedStr);
    }

    return bTestSuccess;
}


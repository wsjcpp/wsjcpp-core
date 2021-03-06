#include "unit_test_decode_uri_component.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestDecodeUriComponent)

UnitTestDecodeUriComponent::UnitTestDecodeUriComponent()
    : WsjcppUnitTestBase("UnitTestDecodeUriComponent") {
}

// ---------------------------------------------------------------------

bool UnitTestDecodeUriComponent::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestDecodeUriComponent::executeTest() {
     struct LTest {
        LTest(
            const std::string &sStr,
            const std::string &sExpectedStr
        ) {
            this->sStr = sStr;
            this->sExpectedStr = sExpectedStr;
        };
        std::string sStr;
        std::string sExpectedStr;
    };
    std::vector<LTest> tests;
    tests.push_back(LTest("Some%20long%20string", "Some long string"));
    tests.push_back(LTest("-_.!~*'()%20abc123", "-_.!~*'() abc123"));
    tests.push_back(LTest("%3B%2C%2F%3F%3A%40%26%3D%2B%24%22%23", ";,/?:@&=+$\"#"));

    for (int i = 0; i < tests.size(); i++) {
        LTest test = tests[i];
        std::string sStr = WsjcppCore::decodeUriComponent(test.sStr);
        compare("test" + std::to_string(i), sStr, test.sExpectedStr);
    }
}

// ---------------------------------------------------------------------

bool UnitTestDecodeUriComponent::doAfterTest() {
    // nothing
    return true;
}
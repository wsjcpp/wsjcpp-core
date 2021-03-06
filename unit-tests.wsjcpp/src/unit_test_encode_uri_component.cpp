#include "unit_test_encode_uri_component.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestEncodeUriComponent)

UnitTestEncodeUriComponent::UnitTestEncodeUriComponent()
    : WsjcppUnitTestBase("UnitTestEncodeUriComponent") {
}

// ---------------------------------------------------------------------

bool UnitTestEncodeUriComponent::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestEncodeUriComponent::executeTest() {
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
    tests.push_back(LTest("Some long string", "Some%20long%20string"));
    tests.push_back(LTest("-_.!~*'() abc123", "-_.!~*'()%20abc123"));
    tests.push_back(LTest(";,/?:@&=+$\"#", "%3B%2C%2F%3F%3A%40%26%3D%2B%24%22%23"));

    for (int i = 0; i < tests.size(); i++) {
        LTest test = tests[i];
        std::string sStr = WsjcppCore::encodeUriComponent(test.sStr);
        compare("test" + std::to_string(i), sStr, test.sExpectedStr);
    }
}

// ---------------------------------------------------------------------

bool UnitTestEncodeUriComponent::doAfterTest() {
    // nothing
    return true;
}